"""Prisma's renamed shields must select their Kconfig and local includes."""
from pathlib import Path
import re
import unittest


SHIELD = Path(__file__).resolve().parents[1] / "keyboards/rafaelromao/prisma/boards/shields/prisma"


class PrismaShieldTest(unittest.TestCase):
    def test_each_overlay_selects_its_own_kconfig(self):
        definitions = (SHIELD / "Kconfig.shield").read_text()
        defaults = (SHIELD / "Kconfig.defconfig").read_text()
        overlays = sorted(SHIELD.glob("*.overlay"))
        self.assertEqual(len(overlays), 4)
        for overlay in overlays:
            symbol = "SHIELD_" + overlay.stem.upper()
            with self.subTest(shield=overlay.stem):
                self.assertIn(f"config {symbol}\n    def_bool $(shields_list_contains,{overlay.stem})", definitions)
                self.assertIn(symbol, defaults)

    def test_all_local_includes_exist_and_old_name_is_gone(self):
        for path in SHIELD.iterdir():
            if not path.is_file():
                continue
            text = path.read_text()
            with self.subTest(file=path.name):
                self.assertNotIn("slim_diamond", text.lower())
                self.assertNotIn("Slim Diamond", text)
                for include in re.findall(r'^#include "([^"]+)"', text, re.M):
                    self.assertTrue((path.parent / include).is_file(), include)


if __name__ == "__main__":
    unittest.main()
