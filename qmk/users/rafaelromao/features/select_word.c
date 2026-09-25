#include "features/select_word.h"
#include "features/adaptive.h"
#include "features/shortcuts.h"

// Word motions: Option on macOS, Ctrl elsewhere.
static uint16_t word_mod(uint16_t key) {
    return shortcuts_is_mac() ? A(key) : C(key);
}

bool process_select(uint16_t keycode, bool pressed) {
    switch (keycode) {
        case MC_SEL_HOME:
            if (pressed) tap_code16(S(KC_HOME));
            return true;
        case MC_SEL_WORD:
            // First press: to the start of the word, to its end, then a shifted
            // word-left held for as long as the key is. Pressed again right
            // after: the shifted word-left alone, one more word.
            if (pressed) {
                if (!adaptive_last_is(S(KC_LEFT))) {
                    tap_code16(word_mod(KC_LEFT));
                    tap_code16(word_mod(KC_RGHT));
                }
                register_code16(S(word_mod(KC_LEFT)));
            } else {
                unregister_code16(S(word_mod(KC_LEFT)));
                adaptive_track(S(KC_LEFT));
            }
            return true;
        case MC_SEL_LINE:
            // First press: home, home, shift+end. Pressed again right after:
            // shift+down, shift+end, one more line.
            if (pressed) {
                if (adaptive_last_is(S(KC_END))) {
                    tap_code16(S(KC_DOWN));
                } else {
                    tap_code(KC_HOME);
                    tap_code(KC_HOME);
                }
                tap_code16(S(KC_END));
                adaptive_track(S(KC_END));
            }
            return true;
    }
    return false;
}
