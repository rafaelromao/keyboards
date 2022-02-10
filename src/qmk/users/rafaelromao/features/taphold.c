#include QMK_KEYBOARD_H

#include "taphold.h"

process_record_result_t process_taphold(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {
        // Fix layer-tap using Underscore
        case UND_MED:
        case UND_FUN:
        case LG_UNDS:
        case LA_UNDS:
        case LC_UNDS:
            if (record->event.pressed) {
                if (record->tap.count > 0) {
                    tap_code16(KC_UNDS);
                    return PROCESS_RECORD_RETURN_FALSE;
                }
            }
    }

    return PROCESS_RECORD_CONTINUE;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LOW_SPC:
        case RAI_BSP:
            return TAPPING_TERM + 40;
        default:
            return TAPPING_TERM;
    }
}

bool get_hold_on_other_key_press_result(uint16_t keycode) {
    switch (keycode) {
        case LOW_SPC:
        case RAI_BSP:
            return true;
        default:
            return false;
    }
}

bool get_tapping_force_hold_result(uint16_t keycode) {
    switch (keycode) {
        case LOW_SPC:
        case RAI_BSP:
            return false;
    }
    switch (keycode) {
        case QK_MOD_TAP...QK_MOD_TAP_MAX:
        case QK_LAYER_TAP...QK_LAYER_TAP_MAX:
        case QK_MOMENTARY...QK_MOMENTARY_MAX:
            return true;
        default:
            return false;
    }
}
