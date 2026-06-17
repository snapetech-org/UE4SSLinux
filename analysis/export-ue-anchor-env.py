#!/usr/bin/env python3
import argparse
import importlib.util
import json
import sys
from pathlib import Path


DEFAULT_ANCHORS = (
    "FNamePool",
    "GName",
    "GUObjectArray",
    "GObjectArray",
    "GWorld",
    "ProcessEvent",
    "StaticFindObject",
    "UObject",
    "UFunction",
    "UClass",
    "FProperty",
)


def normalize_anchor_name(value):
    return "".join(ch for ch in str(value).lower() if ch.isalnum())


ANCHOR_ALIASES = {
    "FNamePool": ("fnamepool", "namepool", "globalnamepool"),
    "GName": ("gname", "gnames", "globalnames"),
    "GUObjectArray": ("guobjectarray", "guobjects", "globaluobjectarray"),
    "GObjectArray": ("gobjectarray", "gobjects", "globalobjectarray"),
    "GWorld": ("gworld", "uworldglobal", "globalworld"),
    "ProcessEvent": ("processevent", "uobjectprocessevent", "processinternal"),
    "StaticFindObject": ("staticfindobject", "findobject"),
    "UObject": ("uobject", "uobjectbase"),
    "UFunction": ("ufunction",),
    "UClass": ("uclass",),
    "FProperty": ("fproperty", "uproperty"),
}


def canonical_anchor_name(name):
    normalized = normalize_anchor_name(name)
    if not normalized or normalized.startswith("selftest"):
        return None
    for canonical, aliases in ANCHOR_ALIASES.items():
        if normalized == normalize_anchor_name(canonical) or any(alias in normalized for alias in aliases):
            return canonical
    return name if name in DEFAULT_ANCHORS else None


def import_script(script_name, module_name):
    script = Path(__file__).resolve().parent / script_name
    spec = importlib.util.spec_from_file_location(module_name, script)
    module = importlib.util.module_from_spec(spec)
    if spec.loader is None:
        raise RuntimeError(f"unable to import {script}")
    spec.loader.exec_module(module)
    return module


def infer_env_name(platform, loaders):
    if platform == "server":
        return "UE4SSL_SERVER_UE_ANCHORS"
    if platform == "windows":
        return "UE4SSL_WIN_UE_ANCHORS"
    if platform == "linux":
        return "UE4SSL_CLIENT_UE_ANCHORS"
    if any(loader == "server" for loader in loaders):
        return "UE4SSL_SERVER_UE_ANCHORS"
    if any(loader == "win-client" for loader in loaders):
        return "UE4SSL_WIN_UE_ANCHORS"
    return "UE4SSL_CLIENT_UE_ANCHORS"


def env_prefix(anchor_env_name):
    if anchor_env_name == "UE4SSL_SERVER_UE_ANCHORS":
        return "UE4SSL_SERVER"
    if anchor_env_name.startswith("UE4SSL_WIN_"):
        return "UE4SSL_WIN"
    return "UE4SSL_CLIENT"


def pointer_env_name(anchor_env_name):
    return f"{env_prefix(anchor_env_name)}_UE_POINTER_PROBE"


def layout_env_name(anchor_env_name):
    return f"{env_prefix(anchor_env_name)}_UE_LAYOUT_PROBE"


def uobject_env_name(anchor_env_name):
    return f"{env_prefix(anchor_env_name)}_UE_UOBJECT_PROBE"


def object_array_env_name(anchor_env_name):
    return f"{env_prefix(anchor_env_name)}_UE_OBJECT_ARRAY_PROBE"


def fname_env_name(anchor_env_name):
    return f"{env_prefix(anchor_env_name)}_UE_FNAME_PROBE"


def collect_entries(summary, names):
    entries = []
    seen = set()
    hits = summary.get("hitsByName", {})
    for name in names:
        canonical = canonical_anchor_name(name) or name
        if canonical in seen:
            continue
        seen.add(canonical)
        first = {}
        matched_name = ""
        hit = {}
        for hit_name, data in hits.items():
            if hit_name == canonical or canonical_anchor_name(hit_name) == canonical:
                candidate = data.get("first", {})
                if candidate.get("addr"):
                    first = candidate
                    matched_name = hit_name
                    hit = data
                    break
        if not first:
            continue
        address = first.get("addr", "")
        if not address:
            continue
        entries.append(
            {
                "name": canonical,
                "matchedName": matched_name,
                "address": address,
                "kind": first.get("kind", ""),
                "offset": first.get("offset", ""),
                "imageOffset": first.get("imageOffset", ""),
                "fileOffset": first.get("fileOffset", ""),
                "rva": first.get("rva", ""),
                "source": first.get("source", ""),
                "count": hit.get("count", 0),
            }
        )
    return entries


def build_export(log, loader, pid, exe_substrings, names, platform):
    scan_mod = import_script("summarize-client-loader-scan.py", "summarize_client_loader_scan")
    summary = scan_mod.summarize(
        scan_mod.load_records(log),
        loader_filter=loader,
        pid_filter=pid,
        exe_substrings=exe_substrings,
    )
    entries = collect_entries(summary, names)
    env_name = infer_env_name(platform, summary.get("loaders", []))
    return {
        "schemaVersion": "ue4sslinux-ue-anchor-env/v1",
        "log": str(log),
        "envName": env_name,
        "pointerProbeEnvName": pointer_env_name(env_name),
        "layoutProbeEnvName": layout_env_name(env_name),
        "uobjectProbeEnvName": uobject_env_name(env_name),
        "objectArrayProbeEnvName": object_array_env_name(env_name),
        "fnameProbeEnvName": fname_env_name(env_name),
        "entryCount": len(entries),
        "entries": entries,
        "missing": [
            canonical_anchor_name(name) or name
            for name in names
            if (canonical_anchor_name(name) or name) not in {entry["name"] for entry in entries}
        ],
    }


def shell_quote(value):
    return "'" + value.replace("'", "'\"'\"'") + "'"


def env_text(export):
    value = ";".join(f"{entry['name']}={entry['address']}" for entry in export["entries"])
    lines = []
    lines.append("# Explicit UE anchor validation input")
    lines.append("# Feed this into the matching probe for a second read-only validation launch.")
    lines.append(f"# Entries: {export['entryCount']}")
    if export["missing"]:
        lines.append(f"# Missing: {', '.join(export['missing'])}")
    lines.append(f"{export['envName']}={shell_quote(value)}")
    lines.append(f"{export['pointerProbeEnvName']}=true")
    lines.append(f"{export['layoutProbeEnvName']}=true")
    lines.append(f"{export['uobjectProbeEnvName']}=true")
    lines.append(f"{export['objectArrayProbeEnvName']}=true")
    lines.append(f"{export['fnameProbeEnvName']}=true")
    lines.append("")
    return "\n".join(lines)


def markdown(export):
    lines = ["# UE Anchor Env Export", ""]
    lines.append(f"- Env: `{export['envName']}`")
    lines.append(f"- Pointer probe env: `{export['pointerProbeEnvName']}`")
    lines.append(f"- Layout probe env: `{export['layoutProbeEnvName']}`")
    lines.append(f"- UObject probe env: `{export['uobjectProbeEnvName']}`")
    lines.append(f"- Object-array probe env: `{export['objectArrayProbeEnvName']}`")
    lines.append(f"- FName probe env: `{export['fnameProbeEnvName']}`")
    lines.append(f"- Entries: `{export['entryCount']}`")
    if export["missing"]:
        lines.append(f"- Missing: `{', '.join(export['missing'])}`")
    lines.append("")
    for entry in export["entries"]:
        lines.append(
            f"- `{entry['name']}` addr=`{entry['address']}` kind=`{entry['kind']}` "
            f"offset=`{entry['offset']}` source=`{entry['source']}` matched=`{entry.get('matchedName', '')}`"
        )
    if not export["entries"]:
        lines.append("- none")
    lines.append("")
    return "\n".join(lines)


def main(argv=None):
    parser = argparse.ArgumentParser(description="Export explicit UE anchor validation env from loader scan logs.")
    parser.add_argument("log", type=Path)
    parser.add_argument("--loader", action="append", default=[])
    parser.add_argument("--pid", action="append", default=[])
    parser.add_argument("--exe-substring", action="append", default=[])
    parser.add_argument("--name", action="append", default=[])
    parser.add_argument("--platform", choices=("auto", "linux", "windows", "server"), default="auto")
    parser.add_argument("--format", choices=("env", "json", "markdown"), default="env")
    args = parser.parse_args(argv)

    export = build_export(
        args.log,
        args.loader,
        args.pid,
        args.exe_substring,
        args.name or list(DEFAULT_ANCHORS),
        args.platform,
    )
    if args.format == "json":
        json.dump(export, sys.stdout, indent=2, sort_keys=True)
        sys.stdout.write("\n")
    elif args.format == "markdown":
        sys.stdout.write(markdown(export))
    else:
        sys.stdout.write(env_text(export))


if __name__ == "__main__":
    main()
