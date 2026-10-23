"""Keymap wiring regressions; run with python3 -m unittest discover -s zmk/tests."""

import re
import unittest
from pathlib import Path


ROOT = Path(__file__).resolve().parents[2]
KEYMAP = (ROOT / "zmk/definitions/keymap.dtsi").read_text()


def bindings(layer):
    body = re.search(rf"\b{layer}\s*\{{.*?bindings\s*=\s*<(.*?)>;", KEYMAP, re.S)[1]
    return [entry.strip() for entry in re.findall(r"&([^&]+)", body)]


class SentenceCaseTests(unittest.TestCase):
    def test_shift_tap_is_inert_but_hold_still_opens_media(self):
        # A transparent R1 resolved to ht_shift on the base, which arms a
        # sticky LSHFT on top of the sentence layer's implicit LS() shift.
        # Keep the hold, but the tap must emit no keycode; &none for the whole
        # position would disable the Media hold too.
        self.assertEqual(bindings("sentence_case_layer")[34], "ht_sentence MEDIA 0")
        self.assertEqual(bindings("default_layer")[34], "ht_shift MEDIA 0")

    def test_sentence_hold_tap_emits_no_keycode_on_tap(self):
        smart = (ROOT / "zmk/features/smart.dtsi").read_text()
        node = re.search(r"ht_sentence:.*?\{(.*?)\};", smart, re.S)[1]
        self.assertRegex(node, r"bindings\s*=\s*<&mo>,\s*<&none>;")
        self.assertIn('flavor = "tap-preferred";', node)
        self.assertIn("tapping-term-ms = <QUICK_TAP_TERM>;", node)
        self.assertIn("quick-tap-ms = <0>;", node)

    def test_caps_shift_release_fix_is_preserved(self):
        smart = (ROOT / "zmk/features/smart.dtsi").read_text()
        for macro, layer in (("tc_smart_word", "CASE_A1"), ("tc_smart_line", "CPLK_A1")):
            self.assertRegex(smart, rf"MACRO\({macro},\s*&smart_\w+ {layer} &macro_release &kp LSHFT\)")

    def test_sentence_numbers_still_use_the_higher_copy_layer(self):
        self.assertEqual(bindings("sentence_case_layer")[32], "ltn_numcp_spc NUM_CP 0")


if __name__ == "__main__":
    unittest.main()
