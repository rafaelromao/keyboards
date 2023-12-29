#include QMK_KEYBOARD_H

#include "taphold.h"

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LOW_SPC:
        case RAI_SPC:
        case RAI_A2:
        case NAV_REP:
        case NAV_PRJ:
        case NAV_CAS:
        case MED_CAS:
        case MED_A1:
        case RAI_TA2:
        case MED_0:
            return 0;
    }
    switch (keycode) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
        case QK_MOMENTARY ... QK_MOMENTARY_MAX:
            return 0;
        default:
            return QUICK_TAP_TERM;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
        case SHO_KCD:
        case SHO_KCI:
        case SHO_DOT:
        case NAV_F12:
        case NAV_AT:
            return 225;
        default:
            return TAPPING_TERM;
    }
}

bool get_combo_must_tap(uint16_t index, combo_t *combo) {
    uint16_t key;
    uint8_t  idx = 0;
    bool     all_mods = false;
    while ((key = pgm_read_word(&combo->keys[idx])) != COMBO_END) {
        switch (key) {
            case QK_MOD_TAP ... QK_MOD_TAP_MAX:
            case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            case QK_MOMENTARY ... QK_MOMENTARY_MAX:
                all_mods = true;
                break;
            default:
                return false;
        }
        idx += 1;
    }
    return all_mods;
}

process_record_result_t process_taphold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LEAD_K:
            if (record->event.pressed && !record->tap.count) {
                leader_start();
                return PROCESS_RECORD_RETURN_FALSE;
            }
            break;

        case NAV_AT:
            if (record->event.pressed && record->tap.count) {
                tap_code16(KC_AT);
                return PROCESS_RECORD_RETURN_FALSE;
            }
            break;

        case NMO_DOC:
            if (record->event.pressed && record->tap.count) {
                process_macros(MC_QDOC, NULL);
                return PROCESS_RECORD_RETURN_FALSE;
            }
            break;

        case NAV_PRJ:
            if (record->event.pressed && record->tap.count) {
                process_macros(MC_PROJ, NULL);
                return PROCESS_RECORD_RETURN_FALSE;
            }
            break;

        case SF_FSYM:
            if (!record->event.pressed && record->tap.count) {
                process_macros(MC_FSYM, NULL);
                return PROCESS_RECORD_RETURN_FALSE;
            }
            break;

        case MED_A1:
            if (record->event.pressed && record->tap.count) {
                layer_move(_ALPHA1);
                return PROCESS_RECORD_RETURN_FALSE;
            }
            break;

        case SF_MODP:
            if (record->event.pressed && record->tap.count) {
                process_swapper(MC_MODP, NULL);
                return PROCESS_RECORD_RETURN_FALSE;
            }
            break;

        case TH_QUOT:
            layer_move(_ALPHA1);
            if (record->tap.count && record->event.pressed) {
                tap_code(KC_QUOT);
                tap_code(KC_SPC);
                return PROCESS_RECORD_RETURN_FALSE;
            }
            if (!record->tap.count && record->event.pressed) {
                tap_code16(KC_DQUO);
                tap_code(KC_SPC);
                return PROCESS_RECORD_RETURN_FALSE;
            }
            break;
    }
    return PROCESS_RECORD_CONTINUE;
}