#include QMK_KEYBOARD_H

#include "macros.h"

extern os_t os;

process_record_result_t process_macros(uint16_t keycode, keyrecord_t *record) {

    if (record->event.pressed) {
        switch (keycode) {

            // Standalone accent characters

            case SS_BTIC:
                tap_code(KC_GRV);
                tap_code(KC_SPC);
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_DQUO:
                tap_code16(KC_DQUO);
                tap_code(KC_SPC);
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_SQUO:
                tap_code(KC_QUOT);
                tap_code(KC_SPC);
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_CIRC:
                tap_code16(KC_CIRC);
                tap_code(KC_SPC);
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_TILD:
                tap_code16(KC_TILD);
                tap_code(KC_SPC);
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