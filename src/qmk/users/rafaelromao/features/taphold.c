#include QMK_KEYBOARD_H

#include "taphold.h"

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LOW_SPC:
        case RAI_BSP:
        case NAV_NG:
        case MED_SFT:
        case MED_ALT:
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
        case KCP_MAC:
        case KCC_MAC:
        case DOT_MAC:
            return 300;
        default:
            return TAPPING_TERM;
    }
}