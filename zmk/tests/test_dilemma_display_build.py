"""Regression tests for the Dilemma display build entry points."""

import json
import os
from pathlib import Path
import shutil
import subprocess
import tempfile
import unittest


ROOT = Path(__file__).resolve().parents[2]
SHIELD = ROOT / "zmk/keyboards/bastardkb/dilemma/boards/shields/dilemma"


class DilemmaDisplayBuildTests(unittest.TestCase):
    def builds(self, *args):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            (root / "scripts").mkdir()
            shutil.copy(ROOT / "scripts/b.sh", root / "scripts/b.sh")
            stub = root / "scripts/zmk.sh"
            stub.write_text("#!/usr/bin/env python3\nimport json, sys\nprint('BUILD ' + json.dumps(sys.argv[1:]))\n")
            stub.chmod(0o755)
            output = subprocess.check_output(
                ["bash", "scripts/b.sh", *args], cwd=root, text=True,
                env={**os.environ, "ZMK_DONGLE_DISPLAY_MODULE": "/display-module"},
            )
            return [json.loads(line[6:]) for line in output.splitlines() if line.startswith("BUILD ")]

    def test_peripheral_override_uses_fork_and_display_shield(self):
        build, = self.builds("m", "-s", "pl")
        self.assertEqual(build[:2], ["bastardkb/dilemma", "cl"])
        self.assertIn("dongle_display", build)
        self.assertIn("/display-module", build)
        self.assertEqual(build[-2:], ["-s", "pl"])

    def test_complete_build_covers_all_roles_with_relay(self):
        builds = self.builds("m", "-c")
        self.assertEqual([build[1] for build in builds], ["cl", "pr", "pl", "cd"])
        self.assertIn("dongle_display", builds[2])
        self.assertIn("dongle_display_relay", builds[3])
        self.assertIn("/display-module", builds[2])
        self.assertIn("/display-module", builds[3])

    def test_layer_enabled_on_display_peripheral_not_on_headless_central(self):
        left = (SHIELD / "dilemma_peripheral_left.conf").read_text()
        central = (SHIELD / "dilemma_central_dongle.conf").read_text()
        for setting in ("CONFIG_ZMK_DISPLAY=y", "CONFIG_ZMK_DONGLE_DISPLAY_LAYER=y",
                        "CONFIG_ZMK_DONGLE_DISPLAY_STATUS_SYNC=y",
                        "CONFIG_ZMK_DONGLE_DISPLAY_BONGO_CAT=n",
                        "CONFIG_ZMK_DONGLE_DISPLAY_MODIFIERS=n"):
            self.assertIn(setting, left)
        for setting in ("CONFIG_ZMK_DISPLAY=n", "CONFIG_ZMK_BATTERY=n",
                        "CONFIG_ZMK_DONGLE_DISPLAY_STATUS_SYNC=y"):
            self.assertIn(setting, central)


if __name__ == "__main__":
    unittest.main()
