#!/usr/bin/env python3
import json
import subprocess
import tempfile
import unittest
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
SCRIPT_CANDIDATES = (
    ROOT / "scripts" / "plan-ue4ss-canary-env.py",
    ROOT / "analysis" / "plan-ue4ss-canary-env.py",
)
SCRIPT = next((path for path in SCRIPT_CANDIDATES if path.exists()), SCRIPT_CANDIDATES[0])


ANCHOR_LOG = """\
2026-06-16T17:43:39Z pid=312 loader=win-client event=loaded phase=thread exe=C:\\game\\TargetGame-Win64-Shipping.exe native=pe
2026-06-16T17:43:39Z pid=312 loader=win-client event=scan-start strings=0 signatures=4 filters=0 maxHits=2 maxRegionBytes=268435456
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-anchor-signature name=FNamePool status=resolved hit=0x140001000 addr=0x140010000 transform=riprel32+3 rva=0x10000 allocationBase=0x140000000
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-anchor-signature name=GUObjectArray status=resolved hit=0x140002000 addr=0x140020000 transform=riprel32+3 rva=0x20000 allocationBase=0x140000000
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-anchor-signature name=GWorld status=resolved hit=0x140003000 addr=0x140030000 transform=riprel32+3 rva=0x30000 allocationBase=0x140000000
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-anchor-signature name=ProcessEvent status=resolved hit=0x140004000 addr=0x140040000 transform=callrel32 rva=0x40000 allocationBase=0x140000000
2026-06-16T17:43:39Z pid=312 loader=win-client event=scan-finish
"""


def report(ready_overrides=None, passed_gates=None):
    ready = {
        "objectDiscovery": False,
        "reflection": False,
        "hooks": False,
        "luaDispatch": False,
        "anchorSignatureResolver": True,
    }
    ready.update(ready_overrides or {})
    gates = [{"name": name, "passed": True, "evidence": "", "blocker": ""} for name in (passed_gates or [])]
    return {
        "schemaVersion": "ue4sslinux-ue4ss-port-readiness/v1",
        "ready": ready,
        "gates": gates,
    }


class PlanUe4ssCanaryEnvTests(unittest.TestCase):
    def run_plan(self, tmp, readiness, *extra):
        readiness_path = Path(tmp) / "readiness.json"
        readiness_path.write_text(json.dumps(readiness), encoding="utf-8")
        result = subprocess.run(
            [
                str(SCRIPT),
                "--platform",
                "windows",
                "--readiness-json",
                str(readiness_path),
                "--format",
                "json",
                *extra,
            ],
            cwd=ROOT,
            text=True,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            check=True,
        )
        return json.loads(result.stdout)

    def test_read_only_plan_enables_object_discovery_without_hooks(self):
        with tempfile.TemporaryDirectory() as tmp:
            plan = self.run_plan(tmp, report())

        env = {item["name"]: item["value"] for item in plan["env"]}
        self.assertEqual(plan["selectedStage"], "object-discovery")
        self.assertEqual(env["UE4SSL_WIN_UE_POINTER_PROBE"], "true")
        self.assertEqual(env["UE4SSL_WIN_UE_OBJECT_ARRAY_PROBE"], "true")
        self.assertNotIn("UE4SSL_WIN_UE_PROCESS_EVENT_HOOK_PROBE", env)

    def test_reflection_plan_enables_read_only_reflection(self):
        with tempfile.TemporaryDirectory() as tmp:
            plan = self.run_plan(
                tmp,
                report({"objectDiscovery": True}, ["ue-reflection-surface", "ue-uobject-probe"]),
            )

        env = {item["name"]: item["value"] for item in plan["env"]}
        self.assertEqual(plan["selectedStage"], "reflection")
        self.assertEqual(env["UE4SSL_WIN_UE_REFLECTION_PROBE"], "true")
        self.assertEqual(env["UE4SSL_WIN_UE_REFLECTION_VALUE_PROBE"], "true")
        self.assertEqual(env["UE4SSL_WIN_LUA_REFLECTION_SELF_TEST"], "true")

    def test_hook_probe_requires_explicit_max_stage(self):
        readiness = report({"objectDiscovery": True, "reflection": True})
        with tempfile.TemporaryDirectory() as tmp:
            read_only = self.run_plan(tmp, readiness)
            hook_probe = self.run_plan(tmp, readiness, "--max-stage", "hook-probe")

        read_only_env = {item["name"]: item["value"] for item in read_only["env"]}
        hook_env = {item["name"]: item["value"] for item in hook_probe["env"]}
        self.assertEqual(read_only["selectedStage"], "hook-probe")
        self.assertNotIn("UE4SSL_WIN_UE_PROCESS_EVENT_HOOK_PROBE", read_only_env)
        self.assertIn("suppresses code-patching probes", " ".join(read_only["notes"]))
        self.assertEqual(hook_env["UE4SSL_WIN_UE_PROCESS_EVENT_HOOK_PROBE"], "true")
        self.assertEqual(hook_env["UE4SSL_WIN_UE_PROCESS_EVENT_HOOK_INSTALL"], "false")

    def test_live_hook_plan_enables_bounded_call_context_logging(self):
        readiness = report({"objectDiscovery": True, "reflection": True, "hooks": True})
        with tempfile.TemporaryDirectory() as tmp:
            plan = self.run_plan(tmp, readiness, "--max-stage", "live-hook")

        env = {item["name"]: item["value"] for item in plan["env"]}
        self.assertEqual(plan["selectedStage"], "lua-dispatch")
        self.assertEqual(env["UE4SSL_WIN_UE_PROCESS_EVENT_LIVE_HOOK"], "true")
        self.assertEqual(env["UE4SSL_WIN_UE_PROCESS_EVENT_DISPATCH_SELF_TEST"], "true")
        self.assertEqual(env["UE4SSL_WIN_UE_PROCESS_EVENT_LIVE_HOOK_LOG_CALLS"], "true")
        self.assertEqual(env["UE4SSL_WIN_UE_PROCESS_EVENT_LIVE_HOOK_CALL_LOG_LIMIT"], "8")
        self.assertNotIn("UE4SSL_WIN_UE_PROCESS_EVENT_LIVE_LUA_DISPATCH", env)

    def test_live_hook_plan_accepts_custom_call_context_log_limit(self):
        readiness = report({"objectDiscovery": True, "reflection": True, "hooks": True})
        with tempfile.TemporaryDirectory() as tmp:
            plan = self.run_plan(tmp, readiness, "--max-stage", "live-hook", "--live-call-log-limit", "3")

        env = {item["name"]: item["value"] for item in plan["env"]}
        self.assertEqual(env["UE4SSL_WIN_UE_PROCESS_EVENT_LIVE_HOOK_CALL_LOG_LIMIT"], "3")

    def test_builds_anchor_env_from_log(self):
        with tempfile.TemporaryDirectory() as tmp:
            log = Path(tmp) / "anchors.log"
            log.write_text(ANCHOR_LOG, encoding="utf-8")
            result = subprocess.run(
                [
                    str(SCRIPT),
                    "--platform",
                    "windows",
                    "--client-log",
                    str(log),
                    "--loader",
                    "win-client",
                    "--format",
                    "env",
                ],
                cwd=ROOT,
                text=True,
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
                check=True,
            )

        self.assertIn("UE4SSL_WIN_UE_ANCHORS='FNamePool=0x140010000", result.stdout)
        self.assertIn("UE4SSL_WIN_UE_POINTER_PROBE=true", result.stdout)
        self.assertNotIn("UE4SSL_WIN_UE_PROCESS_EVENT_LIVE_HOOK=true", result.stdout)


if __name__ == "__main__":
    unittest.main()
