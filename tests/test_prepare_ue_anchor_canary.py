#!/usr/bin/env python3
import json
import subprocess
import tempfile
import unittest
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
SCRIPT_CANDIDATES = (
    ROOT / "scripts" / "prepare-ue-anchor-canary.py",
    ROOT / "analysis" / "prepare-ue-anchor-canary.py",
)
SCRIPT = next((path for path in SCRIPT_CANDIDATES if path.exists()), SCRIPT_CANDIDATES[0])


ANCHOR_LOG = """\
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-anchor-signature name=FNamePool status=resolved hit=0x140001000 addr=0x140010000 transform=riprel32+3 rva=0x10000 allocationBase=0x140000000 module=C:\\game\\TargetGame-Win64-Shipping.exe
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-anchor-signature name=GUObjectArray status=resolved hit=0x140002000 addr=0x140020000 transform=riprel32+3 rva=0x20000 allocationBase=0x140000000 module=C:\\game\\TargetGame-Win64-Shipping.exe
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-anchor-signature name=GWorld status=resolved hit=0x140003000 addr=0x140030000 transform=riprel32+3 rva=0x30000 allocationBase=0x140000000 module=C:\\game\\TargetGame-Win64-Shipping.exe
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-anchor-signature name=ProcessEvent status=resolved hit=0x140004000 addr=0x140040000 transform=callrel32 rva=0x40000 allocationBase=0x140000000 module=C:\\game\\TargetGame-Win64-Shipping.exe
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-anchor-signature name=UObject status=resolved hit=0x140005000 addr=0x140050000 transform=hit rva=0x50000 allocationBase=0x140000000 module=C:\\game\\TargetGame-Win64-Shipping.exe
2026-06-16T17:43:39Z pid=312 loader=win-client event=ue-anchor-signature name=UFunction status=resolved hit=0x140006000 addr=0x140060000 transform=hit rva=0x60000 allocationBase=0x140000000 module=C:\\game\\TargetGame-Win64-Shipping.exe
"""


def pe_row(name, xref, pattern):
    return {
        "name": f"{name}@0x{xref + 0x1000:x}#1",
        "category": "ue",
        "source": "test",
        "xrefRva": f"0x{xref:x}",
        "targetRva": f"0x{xref + 0x1000:x}",
        "pattern": pattern,
        "length": len(pattern.split()),
        "fixedBytes": sum(1 for part in pattern.split() if part != "??"),
        "expectedFileOffset": f"0x{xref:x}",
        "matchCount": 1,
        "status": "unique-expected",
        "promotable": True,
        "matches": [{"fileOffset": f"0x{xref:x}", "rva": f"0x{xref:x}", "section": ".text", "expected": True}],
    }


def elf_row(name, xref, pattern):
    return {
        "name": f"{name}@0x{xref + 0x1000:x}#1",
        "category": "ue",
        "source": "test",
        "xrefVaddr": f"0x{xref:x}",
        "targetVaddr": f"0x{xref + 0x1000:x}",
        "pattern": pattern,
        "length": len(pattern.split()),
        "fixedBytes": sum(1 for part in pattern.split() if part != "??"),
        "expectedFileOffset": f"0x{xref:x}",
        "matchCount": 1,
        "status": "unique-expected",
        "promotable": True,
        "matches": [
            {
                "fileOffset": f"0x{xref:x}",
                "imageOffset": f"0x{xref:x}",
                "vaddr": f"0x{xref:x}",
                "expected": True,
            }
        ],
    }


def validation(rows):
    return {
        "scope": "executable",
        "patternCount": len(rows),
        "promotableCount": len(rows),
        "statusCounts": {"unique-expected": len(rows)},
        "categoryCounts": {"ue": len(rows)},
        "patterns": rows,
    }


class PrepareUeAnchorCanaryTests(unittest.TestCase):
    def run_prepare(self, tmp, platform, binary_name, rows, log_text, skip_readiness=True):
        binary = Path(tmp) / binary_name
        log = Path(tmp) / "loader.log"
        validation_json = Path(tmp) / "validation.json"
        output_dir = Path(tmp) / "out"
        binary.write_bytes(b"MZ-test" if platform == "windows" else b"\x7fELF-test")
        log.write_text(log_text, encoding="utf-8")
        validation_json.write_text(json.dumps(validation(rows)), encoding="utf-8")

        command = [
            str(SCRIPT),
            "--platform",
            platform,
            "--binary",
            str(binary),
            "--loader-log",
            str(log),
            "--validation-json",
            str(validation_json),
            "--output-dir",
            str(output_dir),
            "--format",
            "json",
        ]
        if skip_readiness:
            command.append("--skip-readiness")

        result = subprocess.run(
            command,
            cwd=ROOT,
            text=True,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            check=True,
        )
        return json.loads(result.stdout), output_dir

    def test_prepares_windows_anchor_canary_outputs(self):
        rows = [
            pe_row("GUObjectArray", 0x1000, "48 8d 0d ?? ?? ?? ??"),
            pe_row("ProcessEvent", 0x2000, "e8 ?? ?? ?? ??"),
        ]
        with tempfile.TemporaryDirectory() as tmp:
            result, output_dir = self.run_prepare(
                tmp,
                "windows",
                "TargetGame-Win64-Shipping.exe",
                rows,
                ANCHOR_LOG,
                skip_readiness=False,
            )
            signatures = (output_dir / "client-anchor-signatures.txt").read_text(encoding="utf-8")
            env_text = (output_dir / "ue-anchors.env").read_text(encoding="utf-8")
            validation_summary = json.loads((output_dir / "signature-validation.json").read_text(encoding="utf-8"))
            readiness = (output_dir / "ue4ss-readiness.md").read_text(encoding="utf-8")

        self.assertEqual(result["platform"], "windows")
        self.assertEqual(result["manifestEntryCount"], 2)
        self.assertEqual(result["anchorEnvEntryCount"], 6)
        self.assertIn("GUObjectArray@riprel32+3=48 8d 0d ?? ?? ?? ??", signatures)
        self.assertIn("ProcessEvent@callrel32=e8 ?? ?? ?? ??", signatures)
        self.assertIn("UE4SSL_WIN_UE_ANCHORS=", env_text)
        self.assertIn("FNamePool=0x140010000", env_text)
        self.assertEqual(validation_summary["patternCount"], 2)
        self.assertIn("signature-manifest-exact", readiness)

    def test_prepares_linux_server_anchor_canary_outputs(self):
        server_log = ANCHOR_LOG.replace("loader=win-client", "loader=server").replace("rva=", "imageOffset=")
        rows = [
            elf_row("GWorld", 0x1000, "48 8b 0d ?? ?? ?? ??"),
            elf_row("ProcessEvent", 0x2000, "e8 ?? ?? ?? ??"),
        ]
        with tempfile.TemporaryDirectory() as tmp:
            result, output_dir = self.run_prepare(
                tmp,
                "server",
                "TargetGameServer-Linux-Shipping",
                rows,
                server_log,
            )
            signatures = (output_dir / "server-anchor-signatures.txt").read_text(encoding="utf-8")
            env_text = (output_dir / "ue-server-anchors.env").read_text(encoding="utf-8")

        self.assertEqual(result["platform"], "server")
        self.assertIn("GWorld@riprel32+3=48 8b 0d ?? ?? ?? ??", signatures)
        self.assertIn("UE4SSL_SERVER_UE_ANCHORS=", env_text)
        self.assertIn("ProcessEvent=0x140040000", env_text)


if __name__ == "__main__":
    unittest.main()
