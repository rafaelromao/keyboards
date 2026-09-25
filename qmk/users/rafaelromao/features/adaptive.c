#include "features/adaptive.h"
#include "features/accents.h"
#include "features/macros.h"
#include "features/smart.h"

static struct {
    uint8_t  key;
    bool     shifted;
    uint16_t time;
} last;

static bool last_valid(void) {
    return last.key != KC_NO && timer_elapsed(last.time) < ADAPTIVE_TIMEOUT;
}

void adaptive_track(uint16_t keycode) {
    if (keycode >= SAFE_RANGE || IS_QK_LAYER_TAP(keycode) || IS_QK_MOD_TAP(keycode)) return;
    uint8_t basic = keycode & 0xFF;
    if (basic == KC_NO || IS_MODIFIER_KEYCODE(basic)) return;
    last.key     = basic;
    last.shifted = (keycode & QK_LSFT) || (keycode & QK_RSFT) || ((get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT) || is_caps_word_on();
    last.time    = timer_read();
}

bool adaptive_last_is(uint16_t keycode) {
    if (!last_valid()) return false;
    bool shifted = (keycode & QK_LSFT) || (keycode & QK_RSFT);
    return last.key == (keycode & 0xFF) && last.shifted == shifted;
}

uint8_t adaptive_last_key(void) {
    return last_valid() ? last.key : KC_NO;
}

bool adaptive_last_shifted(void) {
    return last_valid() && last.shifted;
}

static bool is_vowel(uint8_t key) {
    return key == KC_A || key == KC_E || key == KC_I || key == KC_O || key == KC_U;
}

// Types a letter, shifted when caps word is on (ZMK's RS() variants). Under
// sticky shift or sentence case the pending one-shot shift does it instead.
static void tap_letter(uint8_t key) {
    execute_keycode(is_caps_word_on() ? S(key) : key);
}

void adaptive_repeat(void) {
    uint8_t key = adaptive_last_key();
    if (key == KC_NO) return;
    execute_keycode(adaptive_last_shifted() ? S(key) : key);
}

void adaptive_alt_repeat(void) {
    uint8_t key = adaptive_last_key();
    switch (key) {
        case KC_A:
            tap_letter(KC_H);
            return;
        case KC_I:
            if (adaptive_last_shifted()) {
                seq_play(SEQ_SQO);
                return;
            }
            break;
        case KC_Y:
            tap_letter(KC_D);
            return;
        case KC_H:
            execute_keycode(MC_OTILES);
            return;
        case KC_V:
        case KC_X:
        case KC_J:
            smart_osl_on(_ALPHA2);
            return;
    }
    adaptive_repeat();
}

void adaptive_a2_alt_repeat(void) {
    switch (adaptive_last_key()) {
        case KC_A:
        case KC_E:
        case KC_O:
            tap_letter(KC_X);
            return;
        case KC_I:
            tap_letter(KC_E);
            return;
        case KC_U:
            execute_keycode(AC_ECIR);
            return;
    }
    adaptive_alt_repeat();
}

void adaptive_magic(void) {
    tap_letter(is_vowel(adaptive_last_key()) ? KC_V : KC_H);
}

void adaptive_reversed_magic(void) {
    tap_letter(is_vowel(adaptive_last_key()) ? KC_H : KC_V);
}
