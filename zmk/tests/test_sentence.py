"""Keymap wiring regressions; run with python3 -m unittest discover -s zmk/tests.

The module's tests/run.py exercises the actual C behaviors in native ZMK.
"""

import re
import unittest
from pathlib import Path


ROOT = Path(__file__).resolve().parents[2]
KEYMAP = (ROOT / "zmk/definitions/keymap.dtsi").read_text()
SMART = (ROOT / "zmk/features/smart.dtsi").read_text()
SENTENCE = (ROOT / "zmk/features/sentence.dtsi").read_text()


def bindings(layer):
    body = re.search(rf"\b{layer}\s*\{{.*?bindings\s*=\s*<(.*?)>;", KEYMAP, re.S)[1]
    return [entry.strip() for entry in re.findall(r"&([^&]+)", body)]


class SentenceCaseTests(unittest.TestCase):
    def test_no_sentence_layer_or_layer_only_workarounds_remain(self):
        for directory in ("definitions", "features"):
            for path in (ROOT / "zmk" / directory).glob("*"):
                text = path.read_text()
                for obsolete in ("SEN_CASE", "ht_sentence", "ltn_numcp_spc", "ak_space"):
                    self.assertNotIn(obsolete, text, str(path))

    def test_space_uses_the_standalone_behavior(self):
        self.assertIn('#include <behaviors/sentence_case.dtsi>', SENTENCE)
        self.assertRegex(SMART, r"MACRO\(mc_space,\s*&sentence_space\)")
        self.assertNotIn("behavior-adaptive-key", SENTENCE)
        self.assertIn("prior-idle-ms = <ADAPTIVE_KEY_TIMEOUT>;", SENTENCE)
        self.assertIn("release-after-ms = <1000>;", SENTENCE)

    def test_shift_tap_is_guarded_but_media_hold_is_unchanged(self):
        self.assertEqual(bindings("default_layer")[34], "ht_shift MEDIA 0")
        node = re.search(r"ht_shift:.*?\{(.*?)\};", SMART, re.S)[1]
        self.assertRegex(node, r"bindings\s*=\s*<&mo>,\s*<&sentence_shift>;")
        self.assertIn('flavor = "tap-preferred";', node)
        self.assertIn("tapping-term-ms = <QUICK_TAP_TERM>;", node)
        self.assertIn("quick-tap-ms = <0>;", node)
        self.assertRegex(SENTENCE, r"bindings\s*=\s*<&mm_shift>,\s*<&none>;")

    def test_accents_reuse_the_existing_shifted_layer(self):
        self.assertEqual(bindings("default_layer")[33], "sentence_alpha2")
        self.assertRegex(SENTENCE, r"bindings\s*=\s*<&msl_sym_a2 0 0>,\s*<&lt_sft_a2 SYM_CP 0>;")
        self.assertIn("LAYERTAP_TP(lt_sft_a2, &mc_sft_a2)", SMART)

    def test_numbers_use_the_normal_layer_and_num_word(self):
        self.assertEqual(bindings("default_layer")[32], "ltn_num_spc 0 0")
        combos = (ROOT / "zmk/features/combos.dtsi").read_text()
        self.assertRegex(combos, r"COMBO\(cb_numword,\s*LBR LBM,\s*&tc_num_word,")
        self.assertNotIn("cb_numword_sc", combos)

    def test_layer_indices_match_keymap_order(self):
        config = (ROOT / "zmk/definitions/config.dtsi").read_text()
        indices = [int(n) for n in re.findall(r"^#define \w+ (\d+)$", config.split("// Settings")[0], re.M)]
        layers = re.findall(r"display-name =", KEYMAP)
        self.assertEqual(indices, list(range(len(layers))))

    def test_caps_shift_release_fix_is_preserved(self):
        for macro, layer in (("tc_smart_word", "CASE_A1"), ("tc_smart_line", "CPLK_A1")):
            self.assertRegex(SMART, rf"MACRO\({macro},\s*&smart_\w+ {layer} &macro_release &kp LSHFT\)")

    def test_module_is_loaded_before_adaptive_key_observers(self):
        script = (ROOT / "scripts/zmk.sh").read_text()
        self.assertIn('MODULES="$PROJECT_DIR/zmk/modules/zmk-sentence-case;$MODULES"', script)
        module = ROOT / "zmk/modules/zmk-sentence-case"
        for filename in ("zephyr/module.yml", "CMakeLists.txt", "Kconfig"):
            self.assertTrue((module / filename).is_file())


if __name__ == "__main__":
    unittest.main()
