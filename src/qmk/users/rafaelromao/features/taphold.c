#include QMK_KEYBOARD_H

#include "taphold.h"

process_record_result_t process_custom_taphold(uint16_t keycode, keyrecord_t *record) {

    bool isOneShotLockedShift = get_oneshot_locked_mods() & MOD_MASK_SHIFT;
    bool isOneShotShift = isOneShotLockedShift || get_oneshot_mods() & MOD_MASK_SHIFT;
    bool isShifted = isOneShotShift || get_mods() & MOD_MASK_SHIFT;

    switch (keycode) {
        case UND_MAC:
        case LA_UNDS:
            if (record->event.pressed) {
                if (record->tap.count > 0) {
                    tap_code16(KC_UNDS);
                    return PROCESS_RECORD_RETURN_FALSE;
                }
            }
        case PER_LOW:
            if (record->event.pressed) {
                if (record->tap.count > 0) {
                    tap_code16(KC_PERC);
                    return PROCESS_RECORD_RETURN_FALSE;
                }
            }
        case BTI_RAI:
            if (record->event.pressed) {
                if (record->tap.count > 0) {
                    clear_shift();
                    tap_code(KC_GRV);
                    if (!isShifted) {
                        tap_code(KC_SPC);
                    }
                    return PROCESS_RECORD_RETURN_FALSE;
                }
            }
    }
    return PROCESS_RECORD_CONTINUE;
}

process_record_result_t process_taphold(uint16_t keycode, keyrecord_t *record) {
    switch (process_custom_taphold(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return PROCESS_RECORD_RETURN_TRUE;
        case PROCESS_RECORD_RETURN_FALSE:
            return PROCESS_RECORD_RETURN_FALSE;
        default:
            break;
    };

    return PROCESS_RECORD_CONTINUE;
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