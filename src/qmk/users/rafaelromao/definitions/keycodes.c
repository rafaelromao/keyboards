#include QMK_KEYBOARD_H

#include "keycodes.h"

uint16_t extract_tapping_keycode(uint16_t keycode) {
    // Return tapping keycode for tap dances
    switch (keycode) {
        case TD_SCLE:
            return KC_SCLN;
        case TD_LCBR:
            return KC_LCBR;
        case TD_RCBR:
            return KC_RCBR;
        case TD_LPRN:
            return KC_LPRN;
        case TD_RPRN:
            return KC_RPRN;
        case TD_LBRC:
            return KC_LBRC;
        case TD_RBRC:
            return KC_RBRC;
        case TD_DQUO:
            return KC_QUOT;
        case TD_EXLM:
            return KC_EXLM;
        case TD_LT:
            return KC_LT;
        case TD_GT:
            return KC_GT;
        case TD_DOT:
            return KC_DOT;
        case TD_MINS:
            return KC_MINS;
        case TD_COLN:
            return KC_COLN;
        case TD_PERC:
            return KC_PERC;
        case TD_QUES:
            return KC_QUES;
        case TD_SLSH:
            return KC_SLSH;
        case TD_EQL:
            return KC_EQL;
        case TD_PLUS:
            return KC_PLUS;
        case TD_TIL:
            return KC_TILD;
        case TD_CIRC:
            return KC_CIRC;
        case TD_HASH:
            return KC_HASH;
        default:
            break;
    }
    // Return tapping keycode for custom layer taps
    switch (keycode) {
        case NAV_AT:
            return KC_AT;
        default:
            break;
    }
    // Return tapping keycode for basic mod taps
    switch (keycode) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            return keycode &= 0xff;
    }
    // Return tapping keycode for basic keycode
    return keycode;
}

bool is_string_macro_keycode(uint16_t keycode) {
    return keycode > STR_MACRO_START && keycode < STR_MACRO_END;
}

bool is_shift_macro_keycode(uint16_t keycode) {
    return keycode > SFT_MACRO_START && keycode < SFT_MACRO_END;
}