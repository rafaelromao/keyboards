"""Fast, toolchain-free contracts for the entire keymap and native snapshots."""

import json
import re
import unittest
from native_keymap import ROOT, SNAPSHOT, UNSAFE, hold_taps, layers


class KeymapTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.layers = layers()
        cls.hold_behaviors = hold_taps()
        cls.snapshots = [json.loads(line) for line in SNAPSHOT.read_text().splitlines()]
        cls.records = {record["case"]: record["events"] for record in cls.snapshots}

    def test_every_layer_has_all_36_positions(self):
        self.assertEqual(len(self.layers), 29)
        for name, _, bindings in self.layers:
            with self.subTest(layer=name):
                self.assertEqual(len(bindings), 36)

    def test_every_safe_binding_has_exactly_one_native_tap_snapshot(self):
        expected = set()
        for name, _, bindings in self.layers:
            for position, binding in enumerate(bindings):
                behavior = binding.split()[0].removeprefix("&")
                if behavior not in UNSAFE:
                    expected.add(f"{name}/{position:02d} {binding.strip()}")
                    if behavior in self.hold_behaviors:
                        expected.add(f"{name}/{position:02d} hold {binding.strip()}")
        actual = {name for name in self.records if not name.startswith("behavior/")}
        self.assertEqual(actual, expected)
        self.assertEqual(len(self.records), len(self.snapshots), "duplicate snapshot IDs")

    def test_all_direct_letter_bindings_emit_the_expected_letter_and_case(self):
        checked = 0
        for name, events in self.records.items():
            match = re.search(r" &kp (?:(LS|RS)\(([A-Z])\)|([A-Z]))$", name)
            if not match:
                continue
            modifier, wrapped, plain = match.groups()
            code = ord(wrapped or plain) - ord("A") + 4
            mods = {None: 0, "LS": 2, "RS": 32}[modifier]
            presses = [event[1:4] for event in events if event[0] == "pressed"]
            self.assertEqual(presses, [[7, code, mods]], name)
            checked += 1
        self.assertGreaterEqual(checked, 26)

    def test_none_bindings_are_inert_on_every_layer(self):
        for name, events in self.records.items():
            if name.endswith(" &none"):
                self.assertEqual(events, [], name)

    def test_bootloader_is_never_executed_in_native_tests(self):
        self.assertFalse(any("&bootloader" in name for name in self.records))
        self.assertEqual(sum("&bootloader" in binding for _, _, bindings in self.layers for binding in bindings), 2)

    def test_snapshot_event_schema(self):
        widths = {"pressed": 5, "released": 5, "layer": 4, "mods": 2, "mouse": 3}
        for name, events in self.records.items():
            for event in events:
                self.assertIn(event[0], widths, name)
                self.assertEqual(len(event), widths[event[0]], name)

    def test_combo_positions_and_layer_references_exist(self):
        config = (ROOT / "zmk/definitions/config.dtsi").read_text()
        combos = (ROOT / "zmk/features/combos.dtsi").read_text()
        symbols = dict(re.findall(r"^\s*#define (\w+) ([^\n/]+)", config + "\n" + combos, re.M))

        def expand(name):
            if name.isdecimal():
                return [int(name)]
            self.assertIn(name, symbols)
            return [value for token in symbols[name].split() for value in expand(token)]

        matches = re.findall(r"^\s*COMBO\((\w+),\s*([^,]+),\s*[^,]+,\s*([^\)]+)\)", combos, re.M)
        self.assertGreater(len(matches), 90)
        for name, positions, active_layers in matches:
            keys = [value for token in positions.split() for value in expand(token)]
            indices = [value for token in active_layers.split() for value in expand(token)]
            self.assertGreaterEqual(len(keys), 2, name)
            self.assertEqual(len(keys), len(set(keys)), name)
            self.assertTrue(all(0 <= value < 36 for value in keys), name)
            self.assertTrue(all(0 <= value < len(self.layers) for value in indices), name)


if __name__ == "__main__":
    unittest.main()
