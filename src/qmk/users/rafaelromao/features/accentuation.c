#include QMK_KEYBOARD_H

#include "accentuation.h"

void tap_accent_dead_key(uint16_t keycode) {
    switch (keycode) {
        case SS_GV_A:
            tap_code16(KC_GRV);
            break;
        case SS_CR_A:
        case SS_CR_E:
        case SS_CR_O:
            tap_code16(KC_CIRC);
            break;
        case SS_TL_A:
        case SS_TL_O:
            tap_code16(KC_TILD);
            break;
        case SS_SQ_C:
        case SS_SQ_A:
        case SS_SQ_E:
        case SS_SQ_I:
        case SS_SQ_O:
        case SS_SQ_U:
            tap_code(KC_QUOT);
            break;
    }
}

void tap_accent_tap_key(uint32_t keycode) {
    switch (keycode) {
        case SS_GV_A:
        case SS_CR_A:
        case SS_TL_A:
        case SS_SQ_A:
            tap_code(KC_A);
            break;
        case SS_CR_E:
        case SS_SQ_E:
            tap_code(KC_E);
            break;
        case SS_TL_O:
        case SS_CR_O:
        case SS_SQ_O:
            tap_code(KC_O);
            break;
        case SS_SQ_I:
            tap_code(KC_I);
            break;
        case SS_SQ_U:
            tap_code(KC_U);
            break;
        case SS_SQ_C:
            tap_code(KC_C);
            break;
    }
}

bool is_accentuated_keycode(uint16_t keycode) {
    switch (keycode) {
        case SS_GV_A:
        case SS_CR_A:
        case SS_TL_A:
        case SS_SQ_A:
        case SS_CR_E:
        case SS_SQ_E:
        case SS_SQ_I:
        case SS_TL_O:
        case SS_CR_O:
        case SS_SQ_O:
        case SS_SQ_U:
        case SS_SQ_C:
            return true;
    }
    return false;
}

process_record_result_t process_accentuated_characters(uint16_t keycode, keyrecord_t *record) {

    if (!record->event.pressed) {
        return PROCESS_RECORD_CONTINUE;
    }

    bool isOneShotLockedShift = get_oneshot_locked_mods() & MOD_MASK_SHIFT;
    bool isOneShotShift = isOneShotLockedShift || get_oneshot_mods() & MOD_MASK_SHIFT;
    bool isShifted = isOneShotShift || get_mods() & MOD_MASK_SHIFT;

    // Standalone Accent characters

    switch (keycode) {

        case SS_BTIC:
            clear_shift();
            tap_code(KC_GRV);
            if (!isShifted) {
                tap_code(KC_SPC);
            }
            return PROCESS_RECORD_RETURN_FALSE;
        case SS_DQUO:
            clear_shift();
            tap_code16(KC_DQUO);
            if (!isShifted) {
                tap_code(KC_SPC);
            }
            return PROCESS_RECORD_RETURN_FALSE;
        case SS_SQUO:
            clear_shift();
            tap_code(KC_QUOT);
            if (!isShifted) {
                tap_code(KC_SPC);
            }
            return PROCESS_RECORD_RETURN_FALSE;
        case SS_CIRC:
            clear_shift();
            tap_code16(KC_CIRC);
            if (!isShifted) {
                tap_code(KC_SPC);
            }
            return PROCESS_RECORD_RETURN_FALSE;
        case SS_TILD:
            clear_shift();
            tap_code16(KC_TILD);
            if (!isShifted) {
                tap_code(KC_SPC);
            }
            return PROCESS_RECORD_RETURN_FALSE;

        // Tild combos

        case SS_AO:
            clear_shift();
            tap_code16(KC_TILD);
            tap_code(KC_A);
            tap_code(KC_O);
            return PROCESS_RECORD_RETURN_FALSE;
        case SS_CAO:
            clear_shift();
            tap_code16(KC_QUOT);
            tap_code(KC_C);
            tap_code16(KC_TILD);
            tap_code(KC_A);
            tap_code(KC_O);
            return PROCESS_RECORD_RETURN_FALSE;
        case SS_OES:
            clear_shift();
            tap_code16(KC_TILD);
            tap_code(KC_O);
            tap_code(KC_E);
            tap_code(KC_S);
            return PROCESS_RECORD_RETURN_FALSE;
        case SS_COES:
            clear_shift();
            tap_code16(KC_QUOT);
            tap_code(KC_C);
            tap_code16(KC_TILD);
            tap_code(KC_O);
            tap_code(KC_E);
            tap_code(KC_S);
            return PROCESS_RECORD_RETURN_FALSE;
    }

    // Accentuated characters

    if (!is_accentuated_keycode(keycode)) {
        return PROCESS_RECORD_CONTINUE;
    }

    clear_locked_and_oneshot_mods();

    tap_accent_dead_key(keycode);
    if (isShifted) {
        register_mods(MOD_LSFT);
    }
    tap_accent_tap_key(keycode);
    if (isShifted) {
        unregister_mods(MOD_LSFT);
    }

    return PROCESS_RECORD_RETURN_FALSE;
}