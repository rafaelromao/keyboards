#include QMK_KEYBOARD_H

#include "taphold.h"

static bool may_be_exlm = false;
static uint16_t timer = 0;

process_record_result_t process_unds(uint16_t keycode, keyrecord_t *record) {
    // Fix layer-tap using Underscore
    switch (keycode) {
        case UND_MED:
        case UND_FUN:
        case LA_UNDS:
            if (record->event.pressed) {
                if (record->tap.count > 0) {
                    tap_code16(KC_UNDS);
                    return PROCESS_RECORD_RETURN_FALSE;
                }
            }
    }
    return PROCESS_RECORD_CONTINUE;
}

process_record_result_t process_mistaken_exlm(uint16_t keycode, keyrecord_t *record) {
    // Fix tap-hold mistaking ? to " v" or " t" due to hold on other key press not used for LOW_SPC
    uint16_t key = extract_base_tapping_keycode(keycode);
    if (timer > 0) { 
        // timer > 0 means one of the last two keys was a LOW_SPC
        if (may_be_exlm) { 
            // may_be_exlm means the key before the last key was a LOW_SPC and last two key strokes might have been a ? instead
            if ((key == KC_ENT || key == KC_SPC) && timer_elapsed(timer) < 10 * TAPPING_TERM) {
                // replace the last two keys by an exclamation
                tap_code(KC_BSPC);
                tap_code(KC_BSPC);
                tap_code16(KC_EXLM);
            }
            // whether or not it was a ?, restart the state
            timer = 0;
            may_be_exlm = false;
        } else { 
            // last key was a LOW_SPC
            if ((key == KC_V || key == KC_T) && timer_elapsed(timer) < 10 * TAPPING_TERM) {
                // if next key is a Enter or Space, it can be replaced by an exclamation
                may_be_exlm = true;
            }
        }
    } else {
        // restart or reset the cycle
        if (key == KC_SPC) {
            timer = timer_read();
        } else {
            timer = 0;
        }
        may_be_exlm = false;
    }
    return PROCESS_RECORD_CONTINUE;
}

process_record_result_t process_taphold(uint16_t keycode, keyrecord_t *record) {
    switch (process_unds(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };

    switch (process_mistaken_exlm(keycode, record)) {
        case PROCESS_RECORD_RETURN_TRUE:
            return true;
        case PROCESS_RECORD_RETURN_FALSE:
            return false;
        default:
            break;
    };

    return PROCESS_RECORD_CONTINUE;
}

uint16_t get_tapping_term_result(uint16_t keycode) {
    switch (keycode) {
        case LOW_SPC:
        case RAI_BSP:
            return TAPPING_TERM + 40;
        default:
            return TAPPING_TERM;
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

bool get_hold_on_other_key_press_result(uint16_t keycode) {
    switch (keycode) {
        case RAI_BSP:
            return true;
        default:
            return false;
    }
}