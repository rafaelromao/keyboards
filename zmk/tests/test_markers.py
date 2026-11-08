"""Check the actual dead-keys property against adaptive-key's exact matching."""

import os
from pathlib import Path
import re
import subprocess
import unittest


ROOT = Path(__file__).resolve().parents[2]


class MarkerTests(unittest.TestCase):
    def test_all_modifier_states_are_dead(self):
        # ZMK packs the eight HID modifier bits above the usage page/id.
        # Keep this host-side preprocessing test independent of a Zephyr checkout.
        source = "#define F23 0x70072\n#define F24 0x70073\n"
        for bit, modifier in enumerate(("LC", "LS", "LA", "LG", "RC", "RS", "RA", "RG")):
            source += f"#define {modifier}(key) ((key) | ({1 << bit} << 24))\n"
        source += '#include "zmk/definitions/helpers.h"\n'
        source += '#include "zmk/features/symbols.dtsi"\n'
        result = subprocess.run(
            [os.environ.get("CC", "cc"), "-E", "-P", "-x", "assembler-with-cpp", "-I", str(ROOT), "-"],
            input=source, text=True, capture_output=True, check=True,
        )
        match = re.search(r"dead-keys\s*=\s*<(.*?)>;", result.stdout, re.S)
        self.assertIsNotNone(match, "missing dead-keys property")
        # Split whitespace-delimited cells, allowing parenthesized expressions.
        cells = []
        depth = 0
        cell = ""
        for char in match[1] + " ":
            if char.isspace() and depth == 0:
                if cell:
                    cells.append(cell)
                    cell = ""
            else:
                cell += char
                depth += (char == "(") - (char == ")")
        dead_keys = {eval(cell, {"__builtins__": {}}, {}) for cell in cells}
        for marker in (0x70072, 0x70073):
            for mods in range(256):
                with self.subTest(marker=marker, mods=mods):
                    self.assertIn(marker | (mods << 24), dead_keys)
        self.assertEqual(len(cells), 512)
        self.assertEqual(len(dead_keys), 512)


if __name__ == "__main__":
    unittest.main()
