#include QMK_KEYBOARD_H

#include "macros.h"

extern os_t os;

process_record_result_t process_macros(uint16_t keycode, keyrecord_t *record) {

    bool isOneShotLockedShift = get_oneshot_locked_mods() & MOD_MASK_SHIFT;
    bool isOneShotShift = isOneShotLockedShift || get_oneshot_mods() & MOD_MASK_SHIFT;
    bool isShifted = isOneShotShift || get_mods() & MOD_MASK_SHIFT;

    if (record->event.pressed) {
        switch (keycode) {

            // Accent characters

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

            // Degree symbol

            case SS_DEG:
                if (os.type == MACOS) {
                    tap_code16(LSFT(RALT(KC_8)));
                } else {
                    tap_code16(LSFT(LCTL(KC_2)));
                }
                return PROCESS_RECORD_RETURN_FALSE;
                
        }
    }

    return PROCESS_RECORD_CONTINUE;
}