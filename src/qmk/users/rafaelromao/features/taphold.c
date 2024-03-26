#include QMK_KEYBOARD_H

#include "taphold.h"

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LOW_SPC:
        case RAI_SPC:
        case RAI_A2:
        case NAV_MAG:
        case NAV_REP:
        case FNA_REP:
        case MED_CAS:
        case RAI_TA2:
        case MED_0:
            return 175;
    }
    return TAPPING_TERM;
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LOW_SPC:
        case RAI_SPC:
        case RAI_A2:
        case NAV_MAG:
        case NAV_REP:
        case FNA_REP:
        case MED_CAS:
        case RAI_TA2:
        case MED_0:
            return 0;
    }
    return QUICK_TAP_TERM;
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
        case SLE_LOC:
            if (record->event.pressed) {
                if (!record->tap.count) {
                    register_code16(KC_SLEP);
                    wait_ms(500);
                    unregister_code16(KC_SLEP);
                    return PROCESS_RECORD_RETURN_FALSE;
                } else {
                    process_shortcuts(MC_LOCK, NULL);
                }
            }
            break;

        case LEA_KCC:
            if (record->event.pressed && !record->tap.count) {
#ifdef LEADER_ENABLE
                leader_start();
                return PROCESS_RECORD_RETURN_FALSE;
#else
                return PROCESS_RECORD_RETURN_TRUE;
#endif
            }
            break;

        case NAV_AT:
            if (record->event.pressed && record->tap.count) {
                tap_code16(KC_AT);
                return PROCESS_RECORD_RETURN_FALSE;
            }
            break;

        case NAV_STI:
            if (record->event.pressed && record->tap.count) {
                process_shortcuts(MC_STIN, NULL);
                return PROCESS_RECORD_RETURN_FALSE;
            }
            break;

        case NAV_COD:
            if (record->event.pressed && record->tap.count) {
                layer_on(_CODING);
                return PROCESS_RECORD_RETURN_FALSE;
            }
            break;

        case COD_AST:
            if (record->event.pressed && record->tap.count) {
                tap_code16(KC_ASTR);
                return PROCESS_RECORD_RETURN_FALSE;
            }
            break;

        case SF_FSYM:
            if (record->event.pressed && record->tap.count) {
                process_shortcuts(MC_FSYM, NULL);
                return PROCESS_RECORD_RETURN_FALSE;
            }
            break;

        case SF_MODM:
            if (record->event.pressed && record->tap.count) {
                process_swapper(MC_MODM, NULL);
                return PROCESS_RECORD_RETURN_FALSE;
            }
            break;
    }
    return PROCESS_RECORD_CONTINUE;
}