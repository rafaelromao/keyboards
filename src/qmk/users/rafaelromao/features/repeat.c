#include QMK_KEYBOARD_H

#include "repeat.h"

// Credits: Precondition

#ifndef SAVE_MEMORY
static uint16_t last_keycode  = KC_NO;
static uint8_t  last_modifier = 0;
#endif

process_record_result_t process_repeat_key(uint16_t keycode, const keyrecord_t *record) {
#ifndef SAVE_MEMORY
    switch (keycode) {
        case REPEAT:
            if (record->event.pressed) {
                register_mods(last_modifier);
                register_code16(last_keycode);
            } else {
                unregister_code16(last_keycode);
                unregister_mods(last_modifier);
            }
            return PROCESS_RECORD_RETURN_FALSE;
        case NAV_REP:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    register_mods(last_modifier);
                    tap_code16(last_keycode);
                    unregister_mods(last_modifier);
                    return PROCESS_RECORD_RETURN_FALSE;
                }
            }
            return PROCESS_RECORD_CONTINUE;
        default:
            if (keycode != REPEAT) {
                uint16_t mod_state         = get_mods();
                uint16_t oneshot_mod_state = get_oneshot_mods();
                // Early return when holding down a pure layer key
                // to retain modifiers
                switch (keycode) {
                    case QK_DEF_LAYER ... QK_DEF_LAYER_MAX:
                    case QK_MOMENTARY ... QK_MOMENTARY_MAX:
                    case QK_LAYER_MOD ... QK_LAYER_MOD_MAX:
                    case QK_ONE_SHOT_LAYER ... QK_ONE_SHOT_LAYER_MAX:
                    case QK_TOGGLE_LAYER ... QK_TOGGLE_LAYER_MAX:
                    case QK_TO ... QK_TO_MAX:
                    case QK_LAYER_TAP_TOGGLE ... QK_LAYER_TAP_TOGGLE_MAX:
                        return PROCESS_RECORD_CONTINUE;
                }
                last_modifier = oneshot_mod_state | mod_state;
                switch (keycode) {
                    case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
                    case QK_MOD_TAP ... QK_MOD_TAP_MAX:
                        if (record->event.pressed) {
                            last_keycode = extract_base_tapping_keycode(keycode);
                        }
                        break;
                    default:
                        if (record->event.pressed) {
                            last_keycode = keycode;
                        }
                        break;
                }
            }
            return PROCESS_RECORD_CONTINUE;
    }
#else
    switch (keycode) {
        case REPEAT:
            if (record->event.pressed) {
                register_code(KC_SPC);
            } else {
                unregister_code(KC_SPC);
            }
            return PROCESS_RECORD_RETURN_FALSE;
        case NAV_REP:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    tap_code(KC_SPC);
                    return PROCESS_RECORD_RETURN_FALSE;
                }
            }
        default:
            return PROCESS_RECORD_CONTINUE;
    }
#endif
}
