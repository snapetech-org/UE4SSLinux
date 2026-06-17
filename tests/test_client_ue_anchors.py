#!/usr/bin/env python3
import importlib.util
import unittest
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
SCRIPT_CANDIDATES = (
    ROOT / "scripts" / "summarize-client-ue-anchors.py",
    ROOT / "analysis" / "summarize-client-ue-anchors.py",
)
SCRIPT = next((path for path in SCRIPT_CANDIDATES if path.exists()), SCRIPT_CANDIDATES[0])


spec = importlib.util.spec_from_file_location("summarize_client_ue_anchors", SCRIPT)
ue_anchors = importlib.util.module_from_spec(spec)
assert spec.loader is not None
spec.loader.exec_module(ue_anchors)


class ClientUeAnchorTests(unittest.TestCase):
    def test_not_ready_without_core_groups(self):
        report = ue_anchors.summarize({"hitsByName": {"FNamePool": {"count": 1, "first": {"offset": "0x1"}, "sources": {}}}})

        self.assertFalse(report["readyForObjectDiscovery"])
        self.assertGreater(len(report["nextSteps"]), 0)
        self.assertEqual(report["groups"]["names"]["present"], 1)

    def test_ready_when_core_groups_present(self):
        hits = {
            "FNamePool": {"count": 1, "first": {"offset": "0x1"}, "sources": {}},
            "GUObjectArray": {"count": 1, "first": {"offset": "0x2"}, "sources": {}},
            "GWorld": {"count": 1, "first": {"offset": "0x3"}, "sources": {}},
            "ProcessEvent": {"count": 1, "first": {"offset": "0x4"}, "sources": {}},
        }
        report = ue_anchors.summarize({"hitsByName": hits})

        self.assertTrue(report["readyForObjectDiscovery"])
        self.assertTrue(report["readyForHooks"])

    def test_alias_names_count_for_core_groups(self):
        hits = {
            "sig-core-fnamepool": {"count": 1, "first": {"offset": "0x1"}, "sources": {"scan": 1}},
            "gu-object-array-candidate": {"count": 1, "first": {"offset": "0x2"}, "sources": {"scan": 1}},
            "client-gworld": {"count": 1, "first": {"offset": "0x3"}, "sources": {"scan": 1}},
            "uobject-process-event": {"count": 1, "first": {"offset": "0x4"}, "sources": {"scan": 1}},
        }
        report = ue_anchors.summarize({"hitsByName": hits})

        self.assertTrue(report["readyForObjectDiscovery"])
        self.assertEqual(report["groups"]["names"]["anchors"][0]["matchedNames"], ["sig-core-fnamepool"])
        self.assertEqual(report["groups"]["dispatch"]["anchors"][0]["matchedNames"], ["uobject-process-event"])

    def test_self_test_anchors_do_not_satisfy_real_anchor_groups(self):
        hits = {
            "SelfTestFNamePool": {"count": 1, "first": {"offset": "0x1"}, "sources": {}},
            "SelfTestObjectArray": {"count": 1, "first": {"offset": "0x2"}, "sources": {}},
            "SelfTestUObject": {"count": 1, "first": {"offset": "0x3"}, "sources": {}},
        }
        report = ue_anchors.summarize({"hitsByName": hits})

        self.assertFalse(report["readyForObjectDiscovery"])
        self.assertEqual(report["groups"]["names"]["present"], 0)
        self.assertEqual(report["groups"]["reflection"]["present"], 0)


if __name__ == "__main__":
    unittest.main()
