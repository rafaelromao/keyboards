"""Build entry points and hardware roles, without fetching or flashing firmware."""

import json
import os
from pathlib import Path
import shutil
import subprocess
import tempfile
import unittest


ROOT = Path(__file__).resolve().parents[2]
DILEMMA = ROOT / "zmk/keyboards/bastardkb/dilemma/boards/shields/dilemma"


class DongleTests(unittest.TestCase):
    def builds(self, *args):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            (root / "scripts").mkdir()
            shutil.copy(ROOT / "scripts/b.sh", root / "scripts/b.sh")
            stub = root / "scripts/zmk.sh"
            stub.write_text(
                "#!/usr/bin/env python3\n"
                "import json, sys\n"
                "print('BUILD ' + json.dumps(sys.argv[1:]))\n"
            )
            stub.chmod(0o755)
            output = subprocess.check_output(
                ["bash", "scripts/b.sh", *args], cwd=root, text=True,
                env={**os.environ, "ZMK_DONGLE_DISPLAY_MODULE": "/display-module"},
            )
            return [json.loads(line[6:]) for line in output.splitlines() if line.startswith("BUILD ")]

    def test_optional_dilemma_builds_all_three_roles(self):
        builds = self.builds("dilemma-dongle", "-v")
        self.assertEqual([build[:2] for build in builds], [
            ["bastardkb/dilemma", "cd"],
            ["bastardkb/dilemma", "pl"],
            ["bastardkb/dilemma", "pr"],
        ])
        self.assertTrue(all(build[-1] == "-v" for build in builds))
        self.assertIn("dongle_display_relay", builds[0])
        self.assertIn("dongle_display", builds[1])
        self.assertIn("/display-module", builds[0])
        self.assertIn("/display-module", builds[1])
        self.assertNotIn("/display-module", builds[2])

    def test_normal_dilemma_stays_left_central(self):
        builds = self.builds("dilemma")
        self.assertEqual(len(builds), 1)
        self.assertEqual(builds[0][:2], ["bastardkb/dilemma", "cl"])

    def test_complete_dilemma_alias_builds_all_four_shields(self):
        builds = self.builds("m", "-c")
        self.assertEqual([build[:2] for build in builds], [
            ["bastardkb/dilemma", "cl"],
            ["bastardkb/dilemma", "pr"],
            ["bastardkb/dilemma", "pl"],
            ["bastardkb/dilemma", "cd"],
        ])

    def test_peripheral_preserves_small_display_widget_selection(self):
        central = (DILEMMA / "dilemma_central_left.conf").read_text()
        peripheral = (DILEMMA / "dilemma_peripheral_left.conf").read_text()
        for widget in ("BONGO_CAT", "MODIFIERS", "LAYER"):
            setting = f"CONFIG_ZMK_DONGLE_DISPLAY_{widget}=n"
            self.assertIn(setting, central)
            self.assertIn(setting, peripheral)
        self.assertNotIn("CONFIG_ZMK_DONGLE_DISPLAY_STATUS_SCREEN=y", peripheral)

    def test_receiver_has_no_local_battery_or_display(self):
        config = (DILEMMA / "dilemma_central_dongle.conf").read_text()
        for setting in ("ZMK_BATTERY", "ZMK_BATTERY_REPORTING", "BT_BAS", "ZMK_DISPLAY"):
            self.assertIn(f"CONFIG_{setting}=n", config)
        self.assertIn("CONFIG_ZMK_SPLIT_BLE_CENTRAL_PERIPHERALS=2", config)
        self.assertIn("CONFIG_ZMK_SPLIT_BLE_CENTRAL_BATTERY_LEVEL_FETCHING=y", config)

    def test_every_oled_entry_point_uses_the_selected_fork(self):
        for keyboard in ("rommana", "diamond", "choc_diamond", "dilemma"):
            with self.subTest(keyboard=keyboard):
                builds = self.builds(keyboard, "-c")
                screens = [build for build in builds if "dongle_display" in build]
                self.assertTrue(screens)
                self.assertTrue(all("/display-module" in build for build in screens))

    def test_oled_half_is_still_a_sleeping_peripheral(self):
        config = (DILEMMA / "dilemma_peripheral_left.conf").read_text()
        self.assertIn("CONFIG_ZMK_DISPLAY=y", config)
        self.assertIn("CONFIG_ZMK_DONGLE_DISPLAY_STATUS_SYNC=y", config)
        self.assertIn("CONFIG_ZMK_SLEEP=y", config)
        self.assertIn("CONFIG_ZMK_IDLE_TIMEOUT=60000", config)

    def test_trackpad_stays_on_right_and_listener_on_central(self):
        right = (DILEMMA / "dilemma_peripheral_right.overlay").read_text()
        central = (DILEMMA / "dilemma_central_dongle.overlay").read_text()
        left = (DILEMMA / "dilemma_peripheral_left.overlay").read_text()
        self.assertIn('"dilemma_right_i2c.dtsi"', right)
        self.assertIn('"dilemma_glidepoint_listener.dtsi"', central)
        self.assertNotIn('"dilemma_glidepoint_listener.dtsi"', left)


if __name__ == "__main__":
    unittest.main()
