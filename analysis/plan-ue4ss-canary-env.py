#!/usr/bin/env python3
import argparse
import importlib.util
import json
import sys
from pathlib import Path


PLATFORMS = ("server", "linux-client", "windows")
MAX_STAGES = ("read-only", "hook-probe", "live-hook", "lua-dispatch")


def import_script(script_name, module_name):
    script = Path(__file__).resolve().parent / script_name
    spec = importlib.util.spec_from_file_location(module_name, script)
    module = importlib.util.module_from_spec(spec)
    if spec.loader is None:
        raise RuntimeError(f"unable to import {script}")
    spec.loader.exec_module(module)
    return module


def load_json(path):
    with path.open("r", encoding="utf-8", errors="replace") as handle:
        return json.load(handle)


def shell_quote(value):
    return "'" + value.replace("'", "'\"'\"'") + "'"


def env_prefix(platform):
    if platform == "server":
        return "UE4SSL_SERVER"
    if platform == "windows":
        return "UE4SSL_WIN"
    return "UE4SSL_CLIENT"


def loader_name(platform):
    if platform == "server":
        return "server"
    if platform == "windows":
        return "win-client"
    return "linux-client"


def readiness_from_args(args):
    if args.readiness_json:
        return load_json(args.readiness_json)
    readiness = import_script("ue4ss-port-readiness.py", "ue4ss_port_readiness")
    log_paths = args.log + args.client_log + args.server_log
    if not log_paths:
        raise ValueError("provide --readiness-json, --log, --client-log, or --server-log")
    summaries = [
        readiness.summarize_log(path, args.loader or [loader_name(args.platform)], args.pid, args.exe_substring)
        for path in log_paths
    ]
    validations = [load_json(path) for path in args.signature_validation_json]
    return readiness.build_report(summaries, validations)


def anchor_export_from_args(args):
    anchor_exporter = import_script("export-ue-anchor-env.py", "export_ue_anchor_env")
    log_paths = args.log + args.client_log + args.server_log
    if not log_paths:
        return None
    platform = {"server": "server", "linux-client": "linux", "windows": "windows"}[args.platform]
    return anchor_exporter.build_export(
        log_paths[0],
        args.loader or [loader_name(args.platform)],
        args.pid,
        args.exe_substring,
        list(anchor_exporter.DEFAULT_ANCHORS),
        platform,
    )


def anchor_lines(anchor_export):
    if not anchor_export:
        return []
    anchor_exporter = import_script("export-ue-anchor-env.py", "export_ue_anchor_env")
    return [
        line
        for line in anchor_exporter.env_text(anchor_export).splitlines()
        if line and not line.startswith("#")
    ]


def unquote_shell_value(value):
    if len(value) >= 2 and value[0] == "'" and value[-1] == "'":
        return value[1:-1].replace("'\"'\"'", "'")
    return value


def set_env(lines, name, value, reason):
    lines.append({"name": name, "value": value, "reason": reason})


def max_stage_index(stage):
    return MAX_STAGES.index(stage)


def stage_allowed(args, stage):
    return max_stage_index(args.max_stage) >= max_stage_index(stage)


def gate(report, name):
    for item in report.get("gates", []):
        if item.get("name") == name:
            return bool(item.get("passed"))
    return False


def choose_stage(report):
    ready = report.get("ready", {})
    if not ready.get("objectDiscovery"):
        return "object-discovery"
    if not ready.get("reflection"):
        return "reflection"
    if not ready.get("hooks"):
        return "hook-probe"
    if not ready.get("luaDispatch"):
        return "lua-dispatch"
    return "complete"


def plan_env(args, report, anchor_export=None):
    prefix = env_prefix(args.platform)
    stage = choose_stage(report)
    ready = report.get("ready", {})
    lines = []
    notes = []

    for line in anchor_lines(anchor_export):
        name, _, value = line.partition("=")
        set_env(lines, name, unquote_shell_value(value), "carry forward explicit UE anchor input")

    if stage in ("object-discovery", "reflection", "hook-probe", "lua-dispatch", "complete"):
        set_env(lines, f"{prefix}_UE_POINTER_PROBE", "true", "validate configured anchors as pointers")
        set_env(lines, f"{prefix}_UE_LAYOUT_PROBE", "true", "bounded slot read from mapped anchor targets")
        set_env(lines, f"{prefix}_UE_UOBJECT_PROBE", "true", "bounded UObjectBase candidate read")
        set_env(lines, f"{prefix}_UE_OBJECT_ARRAY_PROBE", "true", "bounded GUObjectArray walk")
        set_env(lines, f"{prefix}_UE_FNAME_PROBE", "true", "bounded FNamePool decode")

    if stage in ("reflection", "hook-probe", "lua-dispatch", "complete") or (
        gate(report, "ue-reflection-surface") and gate(report, "ue-uobject-probe")
    ):
        set_env(lines, f"{prefix}_UE_REFLECTION_PROBE", "true", "read-only UClass slot probe")
        set_env(lines, f"{prefix}_UE_REFLECTION_FIELD_WALK", "true", "bounded UField chain walk")
        set_env(lines, f"{prefix}_UE_REFLECTION_PROPERTY_PROBE", "true", "bounded FProperty descriptor probe")
        set_env(lines, f"{prefix}_UE_REFLECTION_VALUE_PROBE", "true", "bounded read-only reflected value probe")
        set_env(lines, f"{prefix}_LUA_REFLECTION_SELF_TEST", "true", "prove Lua reflection API against loader/live descriptors")

    if stage in ("hook-probe", "lua-dispatch", "complete"):
        if stage_allowed(args, "hook-probe"):
            set_env(lines, f"{prefix}_HOOK_SELF_TEST", "true", "prove guarded native hook dispatch on loader-owned target")
            set_env(lines, f"{prefix}_UE_PROCESS_EVENT_HOOK_PROBE", "true", "guarded install/restore probe on resolved ProcessEvent")
            set_env(lines, f"{prefix}_UE_PROCESS_EVENT_HOOK_INSTALL", "false", "do not keep hook installed during hook probe")
        else:
            notes.append("ProcessEvent hook probe is next, but --max-stage read-only suppresses code-patching probes.")

    if stage in ("lua-dispatch", "complete"):
        if stage_allowed(args, "live-hook"):
            set_env(lines, f"{prefix}_UE_PROCESS_EVENT_LIVE_HOOK", "true", "install persistent ProcessEvent hook scaffold")
            set_env(lines, f"{prefix}_UE_PROCESS_EVENT_DISPATCH_SELF_TEST", "true", "arm native pre/original/post dispatch")
            set_env(lines, f"{prefix}_UE_PROCESS_EVENT_LIVE_HOOK_LOG_CALLS", "true", "collect bounded live ProcessEvent context and param samples")
            set_env(
                lines,
                f"{prefix}_UE_PROCESS_EVENT_LIVE_HOOK_CALL_LOG_LIMIT",
                str(args.live_call_log_limit),
                "bound live ProcessEvent context sample count",
            )
        else:
            notes.append("Persistent ProcessEvent hook is next, but --max-stage blocks live hook emission.")
        if stage_allowed(args, "lua-dispatch"):
            set_env(lines, f"{prefix}_LUA_SELF_TEST", "true", "prove Lua runtime and UE4SS-shaped API surface")
            set_env(lines, f"{prefix}_LUA_PROCESS_EVENT_SELF_TEST", "true", "prove ProcessEvent-shaped Lua callback bridge")
            set_env(lines, f"{prefix}_UE_PROCESS_EVENT_LIVE_LUA_DISPATCH", "true", "route live ProcessEvent callbacks into Lua")
            set_env(lines, f"{prefix}_MOD_SELF_TEST", "true", "prove native mod lifecycle dispatch")
            set_env(lines, f"{prefix}_LUA_MODS_ENABLED", "true", "load UE4SS-style Lua mod entrypoints")
            set_env(lines, f"{prefix}_LUA_MOD_DISPATCH_SELF_TEST", "true", "prove Lua mod RegisterHook dispatch")
        else:
            notes.append("Lua dispatch is next, but --max-stage blocks Lua/live mod dispatch emission.")

    if stage == "complete":
        notes.append("All readiness gates are already satisfied by the provided evidence.")
    if not ready.get("anchorSignatureResolver") and not gate(report, "ue-names"):
        notes.append("No resolved anchor signatures or core names were found; run an anchor-signature canary first.")

    deduped = []
    seen = set()
    for item in lines:
        if item["name"] in seen:
            continue
        seen.add(item["name"])
        deduped.append(item)
    return {
        "schemaVersion": "ue4sslinux-ue4ss-canary-env-plan/v1",
        "platform": args.platform,
        "loader": loader_name(args.platform),
        "selectedStage": stage,
        "maxStage": args.max_stage,
        "env": deduped,
        "notes": notes,
        "ready": report.get("ready", {}),
    }


def env_text(plan):
    lines = [
        "# UE4SS-port canary env plan",
        f"# Platform: {plan['platform']}",
        f"# Selected stage: {plan['selectedStage']}",
        f"# Max stage: {plan['maxStage']}",
    ]
    for note in plan["notes"]:
        lines.append(f"# Note: {note}")
    for item in plan["env"]:
        lines.append(f"# {item['reason']}")
        lines.append(f"{item['name']}={shell_quote(item['value']) if ';' in item['value'] else item['value']}")
    lines.append("")
    return "\n".join(lines)


def markdown(plan):
    lines = ["# UE4SS Canary Env Plan", ""]
    lines.append(f"- Platform: `{plan['platform']}`")
    lines.append(f"- Loader: `{plan['loader']}`")
    lines.append(f"- Selected stage: `{plan['selectedStage']}`")
    lines.append(f"- Max stage: `{plan['maxStage']}`")
    if plan["notes"]:
        lines.append("")
        lines.append("## Notes")
        lines.append("")
        for note in plan["notes"]:
            lines.append(f"- {note}")
    lines.append("")
    lines.append("## Env")
    lines.append("")
    for item in plan["env"]:
        lines.append(f"- `{item['name']}={item['value']}`: {item['reason']}")
    if not plan["env"]:
        lines.append("- none")
    lines.append("")
    return "\n".join(lines)


def main(argv=None):
    parser = argparse.ArgumentParser(description="Plan the next guarded UE4SS-port canary env from readiness evidence.")
    parser.add_argument("--platform", choices=PLATFORMS, required=True)
    parser.add_argument("--readiness-json", type=Path)
    parser.add_argument("--log", type=Path, action="append", default=[])
    parser.add_argument("--client-log", type=Path, action="append", default=[])
    parser.add_argument("--server-log", type=Path, action="append", default=[])
    parser.add_argument("--loader", action="append", default=[])
    parser.add_argument("--pid", action="append", default=[])
    parser.add_argument("--exe-substring", action="append", default=[])
    parser.add_argument("--signature-validation-json", type=Path, action="append", default=[])
    parser.add_argument("--max-stage", choices=MAX_STAGES, default="read-only")
    parser.add_argument("--live-call-log-limit", type=int, default=8)
    parser.add_argument("--format", choices=("env", "json", "markdown"), default="env")
    args = parser.parse_args(argv)

    try:
        report = readiness_from_args(args)
        anchor_export = anchor_export_from_args(args)
        plan = plan_env(args, report, anchor_export)
    except Exception as exc:
        parser.exit(2, f"{parser.prog}: error: {exc}\n")

    if args.format == "json":
        json.dump(plan, sys.stdout, indent=2, sort_keys=True)
        sys.stdout.write("\n")
    elif args.format == "markdown":
        sys.stdout.write(markdown(plan))
    else:
        sys.stdout.write(env_text(plan))


if __name__ == "__main__":
    main()
