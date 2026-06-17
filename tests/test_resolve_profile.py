#!/usr/bin/env python3
import importlib.util
import subprocess
import unittest
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
SCRIPT = ROOT / "analysis" / "resolve-profile.py"

spec = importlib.util.spec_from_file_location("resolve_profile", SCRIPT)
resolver = importlib.util.module_from_spec(spec)
assert spec.loader is not None
spec.loader.exec_module(resolver)


class ResolveProfileTests(unittest.TestCase):
    def test_dune_windows_resolution(self):
        result = resolver.resolve("dune", "windows")
        self.assertEqual(result["schemaVersion"], "ue4sslinux-profile-resolution/v1")
        self.assertEqual(result["envPrefix"], "UE4SSL_WIN")
        self.assertEqual(result["defaultWindowsProxyDll"], "version.dll")
        self.assertIn("DuneSandbox-Win64-Shipping.exe", result["processFilters"])

    def test_palworld_server_resolution(self):
        result = resolver.resolve("palworld", "linux-server")
        self.assertEqual(result["envPrefix"], "UE4SSL_SERVER")
        self.assertIn("PalServer", result["processFilters"])
        self.assertIn("ue", result["scanPresets"])

    def test_env_output(self):
        result = resolver.resolve("dune", "windows")
        text = resolver.env_text(result)
        self.assertIn("UE4SSL_PROFILE='dune'", text)
        self.assertIn("UE4SSL_WIN_PROXY_DLL='version.dll'", text)
        self.assertIn("UE4SSL_WIN_SCAN_PATH_FILTER=", text)

    def test_cli_missing_profile_fails(self):
        proc = subprocess.run(
            ["python3", str(SCRIPT), "missing", "--platform", "windows"],
            cwd=ROOT,
            text=True,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            check=False,
        )
        self.assertNotEqual(proc.returncode, 0)
        self.assertIn("missing profile", proc.stderr)


if __name__ == "__main__":
    unittest.main()
