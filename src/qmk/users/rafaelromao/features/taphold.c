#include QMK_KEYBOARD_H

#include "taphold.h"

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LOW_SPC:
        case RAI_BSP:
        case NAV_ACT:
        case MED_CAS:
        case MED_0:
            return false;
    }
    switch (keycode) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
        case QK_MOMENTARY ... QK_MOMENTARY_MAX:
            return true;
        default:
            return false;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
        case KCR_MAC:
        case KCI_MAC:
        case DOT_MAC:
            return 300;
        default:
            return TAPPING_TERM;
    }
}

process_record_result_t process_taphold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SF_SE:
            if (!record->event.pressed && record->tap.count > 0) {
                process_macros(MC_SEEV, NULL);
                return PROCESS_RECORD_RETURN_FALSE;
            }
            break;
    }
    return PROCESS_RECORD_CONTINUE;
}