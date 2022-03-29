#include QMK_KEYBOARD_H

#include "custom_shift.h"

extern os_t os;
static bool navigating = false;

process_record_result_t process_custom_shift(uint16_t keycode, keyrecord_t *record) {

    bool isOneShotLockedShift = get_oneshot_locked_mods() & MOD_MASK_SHIFT;
    bool isOneShotShift = isOneShotLockedShift || get_oneshot_mods() & MOD_MASK_SHIFT;
    bool isShifted = isOneShotShift || get_mods() & MOD_MASK_SHIFT;
    uint16_t key = extract_base_tapping_keycode(keycode);

    // Numpad Custom Shifts (make it work even on MacOS)

    switch (key) {
        case KC_P1:
        case KC_P2:
        case KC_P3:
        case KC_P4:
        case KC_P6:
        case KC_P7:
        case KC_P8:
        case KC_P9:
        case KC_P0:
        case KC_PDOT:
            if (isShifted || navigating) {
                clear_locked_and_oneshot_mods();
                if (record->event.pressed) {
                    navigating = true;
                    unregister_mods(MOD_MASK_SHIFT);
                    switch (key) {
                        case KC_P1:
                            tap_code(KC_END);
                            break;
                        case KC_P2:
                            tap_code(KC_DOWN);
                            break;
                        case KC_P3:
                            tap_code(KC_PGDN);
                            break;
                        case KC_P4:
                            tap_code(KC_LEFT);
                            break;
                        case KC_P6:
                            tap_code(KC_RIGHT);
                            break;
                        case KC_P7:
                            tap_code(KC_HOME);
                            break;
                        case KC_P8:
                            tap_code(KC_UP);
                            break;
                        case KC_P9:
                            tap_code(KC_PGUP);
                            break;
                        case KC_P0:
                            tap_code(KC_INS);
                            break;
                        case KC_PDOT:
                            tap_code(KC_DEL);
                            break;
                    }
                    return PROCESS_RECORD_RETURN_FALSE;
                } else {
                    register_mods(MOD_MASK_SHIFT);
                    return PROCESS_RECORD_RETURN_FALSE;
                }
            }
            return PROCESS_RECORD_RETURN_TRUE;

        default:
            // Clear navigating state
            if (navigating) {
                unregister_mods(MOD_MASK_SHIFT);
                navigating = false;
            }
    }

    switch (key) {

        // Shift+Backspace for Delete (when not one-shot)

        case KC_BSPC:
            if (record->event.pressed) {
                if (isShifted && !isOneShotShift) {
                    tap_code(KC_DEL);
                    return PROCESS_RECORD_RETURN_FALSE;
                }
            }
            return PROCESS_RECORD_RETURN_TRUE;
    }

    return PROCESS_RECORD_CONTINUE;
}
