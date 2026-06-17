#!/usr/bin/env python3
import importlib.util
import json
import subprocess
import tempfile
import unittest
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
SCRIPT_CANDIDATES = (
    ROOT / "scripts" / "export-ue-anchor-env.py",
    ROOT / "analysis" / "export-ue-anchor-env.py",
)
SCRIPT = next((path for path in SCRIPT_CANDIDATES if path.exists()), SCRIPT_CANDIDATES[0])


spec = importlib.util.spec_from_file_location("export_ue_anchor_env", SCRIPT)
exporter = importlib.util.module_from_spec(spec)
assert spec.loader is not None
spec.loader.exec_module(exporter)


WINDOWS_LOG = """\
2026-06-16T17:43:39Z pid=312 loader=win-client event=loaded phase=thread exe=C:\\game\\TargetGame-Win64-Shipping.exe native=pe
2026-06-16T17:43:39Z pid=312 loader=win-client event=scan-hit kind=signature name=FNamePool addr=0x140010000 rva=0x10000 allocationBase=0x140000000 module=C:\\game\\TargetGame-Win64-Shipping.exe
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-anchor name=GUObjectArray status=mapped addr=0x140020000 rva=0x20000 allocationBase=0x140000000 module=C:\\game\\TargetGame-Win64-Shipping.exe
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-anchor name=GWorld status=unmapped addr=0x1
"""


WINDOWS_ALIAS_LOG = """\
2026-06-16T17:43:39Z pid=312 loader=win-client event=loaded phase=thread exe=C:\\game\\TargetGame-Win64-Shipping.exe native=pe
2026-06-16T17:43:39Z pid=312 loader=win-client event=scan-hit kind=signature name=sig-core-fnamepool addr=0x140010000 rva=0x10000 allocationBase=0x140000000 module=C:\\game\\TargetGame-Win64-Shipping.exe
2026-06-16T17:43:39Z pid=312 loader=win-client event=scan-hit kind=signature name=gu-object-array-candidate addr=0x140020000 rva=0x20000 allocationBase=0x140000000 module=C:\\game\\TargetGame-Win64-Shipping.exe
"""


WINDOWS_SIGNATURE_ANCHOR_LOG = """\
2026-06-16T17:43:39Z pid=312 loader=win-client event=loaded phase=thread exe=C:\\game\\TargetGame-Win64-Shipping.exe native=pe
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-anchor-signature name=FNamePool status=resolved hit=0x140001000 addr=0x140010000 transform=riprel32+3 rva=0x10000 allocationBase=0x140000000 module=C:\\game\\TargetGame-Win64-Shipping.exe
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-anchor-signature name=GUObjectArray status=resolved hit=0x140002000 addr=0x140020000 transform=riprel32+3 rva=0x20000 allocationBase=0x140000000 module=C:\\game\\TargetGame-Win64-Shipping.exe
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-anchor-signature name=GWorld status=resolved hit=0x140003000 addr=0x140030000 transform=riprel32+3 rva=0x30000 allocationBase=0x140000000 module=C:\\game\\TargetGame-Win64-Shipping.exe
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-anchor-signature name=ProcessEvent status=resolved hit=0x140004000 addr=0x140040000 transform=callrel32 rva=0x40000 allocationBase=0x140000000 module=C:\\game\\TargetGame-Win64-Shipping.exe
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-anchor-signature name=UObject status=resolved hit=0x140005000 addr=0x140050000 transform=hit rva=0x50000 allocationBase=0x140000000 module=C:\\game\\TargetGame-Win64-Shipping.exe
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-anchor-signature name=UFunction status=resolved hit=0x140006000 addr=0x140060000 transform=hit rva=0x60000 allocationBase=0x140000000 module=C:\\game\\TargetGame-Win64-Shipping.exe
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-anchor-signature name=FProperty status=ambiguous hits=2 firstHit=0x140007000 firstAddr=0x140070000 transform=hit
"""


LINUX_LOG = """\
2026-06-16T17:43:39Z pid=112 loader=client event=loaded exe=/game/TargetGame-Linux-Shipping native=elf
2026-06-16T17:43:39Z pid=112 loader=client event=scan-hit kind=string name=ProcessEvent addr=0x7f000100 imageOffset=0x100 fileOffset=0x100 perms=r-xp map=/game/TargetGame-Linux-Shipping
"""


SERVER_LOG = """\
2026-06-16T17:43:39Z pid=100 loader=server event=loaded exe=/home/dune/server/TargetGame/Binaries/Linux/TargetGameServer-Linux-Shipping native=elf
2026-06-16T17:43:39Z pid=100 loader=server event=scan-hit kind=string name=FNamePool addr=0x7f000100 imageOffset=0x100 fileOffset=0x100 perms=r-xp map=/home/dune/server/TargetGame/Binaries/Linux/TargetGameServer-Linux-Shipping
2026-06-16T17:43:39Z pid=100 loader=server event=ue-anchor name=GUObjectArray status=mapped addr=0x7f000200 imageOffset=0x200 fileOffset=0x200 perms=r-xp map=/home/dune/server/TargetGame/Binaries/Linux/TargetGameServer-Linux-Shipping
"""


class ExportUeAnchorEnvTests(unittest.TestCase):
    def test_exports_windows_env_from_scan_and_mapped_anchor_hits(self):
        with tempfile.TemporaryDirectory() as tmp:
            log = Path(tmp) / "win.log"
            log.write_text(WINDOWS_LOG, encoding="utf-8")
            export = exporter.build_export(
                log,
                ["win-client"],
                [],
                [],
                ["FNamePool", "GUObjectArray", "GWorld"],
                "auto",
            )
            text = exporter.env_text(export)

        self.assertEqual(export["envName"], "UE4SSL_WIN_UE_ANCHORS")
        self.assertEqual(export["pointerProbeEnvName"], "UE4SSL_WIN_UE_POINTER_PROBE")
        self.assertEqual(export["layoutProbeEnvName"], "UE4SSL_WIN_UE_LAYOUT_PROBE")
        self.assertEqual(export["uobjectProbeEnvName"], "UE4SSL_WIN_UE_UOBJECT_PROBE")
        self.assertEqual(export["objectArrayProbeEnvName"], "UE4SSL_WIN_UE_OBJECT_ARRAY_PROBE")
        self.assertEqual(export["fnameProbeEnvName"], "UE4SSL_WIN_UE_FNAME_PROBE")
        self.assertEqual(export["entryCount"], 2)
        self.assertIn("FNamePool=0x140010000", text)
        self.assertIn("GUObjectArray=0x140020000", text)
        self.assertIn("UE4SSL_WIN_UE_POINTER_PROBE=true", text)
        self.assertIn("UE4SSL_WIN_UE_LAYOUT_PROBE=true", text)
        self.assertIn("UE4SSL_WIN_UE_UOBJECT_PROBE=true", text)
        self.assertIn("UE4SSL_WIN_UE_OBJECT_ARRAY_PROBE=true", text)
        self.assertIn("UE4SSL_WIN_UE_FNAME_PROBE=true", text)
        self.assertIn("GWorld", export["missing"])

    def test_exports_canonical_env_from_alias_names(self):
        with tempfile.TemporaryDirectory() as tmp:
            log = Path(tmp) / "win.log"
            log.write_text(WINDOWS_ALIAS_LOG, encoding="utf-8")
            export = exporter.build_export(
                log,
                ["win-client"],
                [],
                [],
                ["FNamePool", "GUObjectArray"],
                "auto",
            )
            text = exporter.env_text(export)

        self.assertEqual(export["entryCount"], 2)
        self.assertIn("FNamePool=0x140010000", text)
        self.assertIn("GUObjectArray=0x140020000", text)
        self.assertEqual(export["entries"][0]["matchedName"], "sig-core-fnamepool")

    def test_exports_resolved_signature_anchors_by_default_including_reflection(self):
        with tempfile.TemporaryDirectory() as tmp:
            log = Path(tmp) / "win.log"
            log.write_text(WINDOWS_SIGNATURE_ANCHOR_LOG, encoding="utf-8")
            export = exporter.build_export(log, ["win-client"], [], [], list(exporter.DEFAULT_ANCHORS), "auto")
            text = exporter.env_text(export)

        self.assertEqual(export["entryCount"], 6)
        self.assertIn("FNamePool=0x140010000", text)
        self.assertIn("GUObjectArray=0x140020000", text)
        self.assertIn("GWorld=0x140030000", text)
        self.assertIn("ProcessEvent=0x140040000", text)
        self.assertIn("UObject=0x140050000", text)
        self.assertIn("UFunction=0x140060000", text)
        self.assertNotIn("FProperty=0x140070000", text)
        self.assertIn("FProperty", export["missing"])
        self.assertEqual(export["entries"][0]["kind"], "ue-anchor-signature")

    def test_exports_linux_env(self):
        with tempfile.TemporaryDirectory() as tmp:
            log = Path(tmp) / "linux.log"
            log.write_text(LINUX_LOG, encoding="utf-8")
            export = exporter.build_export(log, ["client"], [], [], ["ProcessEvent"], "linux")

        self.assertEqual(export["envName"], "UE4SSL_CLIENT_UE_ANCHORS")
        self.assertEqual(export["pointerProbeEnvName"], "UE4SSL_CLIENT_UE_POINTER_PROBE")
        self.assertEqual(export["layoutProbeEnvName"], "UE4SSL_CLIENT_UE_LAYOUT_PROBE")
        self.assertEqual(export["uobjectProbeEnvName"], "UE4SSL_CLIENT_UE_UOBJECT_PROBE")
        self.assertEqual(export["objectArrayProbeEnvName"], "UE4SSL_CLIENT_UE_OBJECT_ARRAY_PROBE")
        self.assertEqual(export["fnameProbeEnvName"], "UE4SSL_CLIENT_UE_FNAME_PROBE")
        self.assertEqual(export["entries"][0]["address"], "0x7f000100")

    def test_exports_server_env(self):
        with tempfile.TemporaryDirectory() as tmp:
            log = Path(tmp) / "server.log"
            log.write_text(SERVER_LOG, encoding="utf-8")
            export = exporter.build_export(
                log,
                ["server"],
                [],
                [],
                ["FNamePool", "GUObjectArray"],
                "auto",
            )
            text = exporter.env_text(export)

        self.assertEqual(export["envName"], "UE4SSL_SERVER_UE_ANCHORS")
        self.assertEqual(export["pointerProbeEnvName"], "UE4SSL_SERVER_UE_POINTER_PROBE")
        self.assertEqual(export["layoutProbeEnvName"], "UE4SSL_SERVER_UE_LAYOUT_PROBE")
        self.assertEqual(export["uobjectProbeEnvName"], "UE4SSL_SERVER_UE_UOBJECT_PROBE")
        self.assertEqual(export["objectArrayProbeEnvName"], "UE4SSL_SERVER_UE_OBJECT_ARRAY_PROBE")
        self.assertEqual(export["fnameProbeEnvName"], "UE4SSL_SERVER_UE_FNAME_PROBE")
        self.assertIn("UE4SSL_SERVER_UE_ANCHORS='FNamePool=0x7f000100;GUObjectArray=0x7f000200'", text)
        self.assertIn("UE4SSL_SERVER_UE_OBJECT_ARRAY_PROBE=true", text)
        self.assertIn("UE4SSL_SERVER_UE_FNAME_PROBE=true", text)

    def test_cli_json_output(self):
        with tempfile.TemporaryDirectory() as tmp:
            log = Path(tmp) / "win.log"
            log.write_text(WINDOWS_LOG, encoding="utf-8")
            result = subprocess.run(
                [str(SCRIPT), str(log), "--loader", "win-client", "--name", "FNamePool", "--format", "json"],
                cwd=ROOT,
                text=True,
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
                check=True,
            )

        export = json.loads(result.stdout)
        self.assertEqual(export["schemaVersion"], "ue4sslinux-ue-anchor-env/v1")
        self.assertEqual(export["entryCount"], 1)


if __name__ == "__main__":
    unittest.main()
