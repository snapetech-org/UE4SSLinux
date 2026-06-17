#!/usr/bin/env python3
import argparse
import importlib.util
import json
import sys
from pathlib import Path


ANCHOR_GROUPS = {
    "names": ("FNamePool", "GName"),
    "objects": ("GUObjectArray", "GObjectArray"),
    "world": ("GWorld",),
    "dispatch": ("ProcessEvent", "StaticFindObject"),
    "reflection": ("UObject", "UFunction", "UClass", "FProperty"),
    "cheat": ("CheatManager", "CheatClass", "EnableCheats", "AdminLogin"),
    "brt": ("ServerRequestBaseBackup", "BaseBackupActionPlace", "PerformCanBePlaced", "Fail_InvalidMap"),
    "deep-desert": ("DeepDesert", "DeepDesert_1", "m_DeepDesertGameplay"),
}


def normalize_anchor_name(value):
    return "".join(ch for ch in str(value).lower() if ch.isalnum())


ANCHOR_ALIASES = {
    "FNamePool": ("fnamepool", "fnamepoolanchor", "namepool", "globalnamepool"),
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
    "CheatManager": ("cheatmanager", "dunecheatmanager"),
    "CheatClass": ("cheatclass",),
    "EnableCheats": ("enablecheats",),
    "AdminLogin": ("adminlogin",),
    "ServerRequestBaseBackup": ("serverrequestbasebackup", "requestbasebackup"),
    "BaseBackupActionPlace": ("basebackupactionplace",),
    "PerformCanBePlaced": ("performcanbeplaced", "canbeplaced"),
    "Fail_InvalidMap": ("failinvalidmap", "invalidmap"),
    "DeepDesert": ("deepdesert",),
    "DeepDesert_1": ("deepdesert1",),
    "m_DeepDesertGameplay": ("mdeepdesertgameplay", "deepdesertgameplay"),
}


def canonical_anchor_name(name):
    normalized = normalize_anchor_name(name)
    if not normalized or normalized.startswith("selftest"):
        return None
    for canonical, aliases in ANCHOR_ALIASES.items():
        if normalized == normalize_anchor_name(canonical) or any(alias in normalized for alias in aliases):
            return canonical
    return name if any(name in anchors for anchors in ANCHOR_GROUPS.values()) else None


def matching_hits(hits, anchor):
    rows = []
    for hit_name, data in hits.items():
        if hit_name == anchor or canonical_anchor_name(hit_name) == anchor:
            rows.append((hit_name, data))
    return rows


def merge_sources(rows):
    merged = {}
    for _, data in rows:
        for source, count in data.get("sources", {}).items():
            merged[source] = merged.get(source, 0) + count
    return merged


def import_scan_summary():
    script = Path(__file__).resolve().parent / "summarize-client-loader-scan.py"
    spec = importlib.util.spec_from_file_location("summarize_client_loader_scan", script)
    module = importlib.util.module_from_spec(spec)
    if spec.loader is None:
        raise RuntimeError(f"unable to import {script}")
    spec.loader.exec_module(module)
    return module


def summarize(summary):
    hits = summary["hitsByName"]
    groups = {}
    for group, anchors in ANCHOR_GROUPS.items():
        rows = []
        present = 0
        for anchor in anchors:
            matches = matching_hits(hits, anchor)
            if matches:
                present += 1
                first_name, first_data = matches[0]
                rows.append(
                    {
                        "name": anchor,
                        "matchedNames": [name for name, _ in matches],
                        "present": True,
                        "count": sum(data.get("count", 0) for _, data in matches),
                        "first": first_data.get("first", {}),
                        "sources": merge_sources(matches),
                    }
                )
            else:
                rows.append({"name": anchor, "matchedNames": [], "present": False, "count": 0, "first": {}, "sources": {}})
        groups[group] = {
            "present": present,
            "total": len(anchors),
            "complete": present == len(anchors),
            "anchors": rows,
        }

    required = ("names", "objects", "world", "dispatch")
    ready_for_object_discovery = all(groups[group]["present"] > 0 for group in required)
    ready_for_hooks = ready_for_object_discovery and groups["dispatch"]["present"] > 0
    next_steps = []
    if not groups["names"]["present"]:
        next_steps.append("find FNamePool/GName signature or string xrefs")
    if not groups["objects"]["present"]:
        next_steps.append("find GUObjectArray/GObjectArray signature or string xrefs")
    if not groups["world"]["present"]:
        next_steps.append("find GWorld signature or world-context xrefs")
    if not groups["dispatch"]["present"]:
        next_steps.append("find ProcessEvent/StaticFindObject xrefs")
    if ready_for_object_discovery:
        next_steps.append("add read-only memory readers for FName/GUObject/GWorld layouts")
    if ready_for_hooks:
        next_steps.append("defer hook/trampoline work until read-only layout validation passes")

    return {
        "readyForObjectDiscovery": ready_for_object_discovery,
        "readyForHooks": ready_for_hooks,
        "groups": groups,
        "nextSteps": next_steps,
    }


def markdown(report):
    lines = []
    lines.append("# Client UE Anchor Readiness")
    lines.append("")
    lines.append(f"- Ready for object discovery: `{str(report['readyForObjectDiscovery']).lower()}`")
    lines.append(f"- Ready for hooks: `{str(report['readyForHooks']).lower()}`")
    lines.append("")
    for group, data in report["groups"].items():
        lines.append(f"## {group}")
        lines.append("")
        lines.append(f"- Present: `{data['present']}/{data['total']}`")
        for anchor in data["anchors"]:
            marker = "present" if anchor["present"] else "missing"
            first = anchor["first"].get("offset", "")
            suffix = f" first=`{first}`" if first else ""
            matched = ""
            if anchor.get("matchedNames") and anchor["matchedNames"] != [anchor["name"]]:
                matched = f" matched=`{', '.join(anchor['matchedNames'])}`"
            lines.append(f"- `{anchor['name']}`: `{marker}` count=`{anchor['count']}`{suffix}{matched}")
        lines.append("")
    lines.append("## Next Steps")
    lines.append("")
    for step in report["nextSteps"]:
        lines.append(f"- {step}")
    if not report["nextSteps"]:
        lines.append("- none")
    lines.append("")
    return "\n".join(lines)


def main(argv=None):
    parser = argparse.ArgumentParser(description="Summarize client UE anchor readiness from client loader logs.")
    parser.add_argument("log", type=Path)
    parser.add_argument("--loader", action="append", choices=("client", "win-client", "linux-client", "server"), default=[])
    parser.add_argument("--pid", action="append", default=[])
    parser.add_argument("--exe-substring", action="append", default=[])
    parser.add_argument("--format", choices=("json", "markdown"), default="markdown")
    args = parser.parse_args(argv)

    scan_summary = import_scan_summary()
    summary = scan_summary.summarize(
        scan_summary.load_records(args.log),
        loader_filter=args.loader,
        pid_filter=args.pid,
        exe_substrings=args.exe_substring,
    )
    report = summarize(summary)
    if args.format == "json":
        json.dump(report, sys.stdout, indent=2, sort_keys=True)
        sys.stdout.write("\n")
    else:
        sys.stdout.write(markdown(report))


if __name__ == "__main__":
    main()
