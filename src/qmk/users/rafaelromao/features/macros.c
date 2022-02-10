#include QMK_KEYBOARD_H

#include "macros.h"

extern os_t os;

process_record_result_t process_macros(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {

        // Standalone accent characters

        case SS_BTIC:
            if (record->event.pressed) {
                SEND_STRING("` ");
            }
            return PROCESS_RECORD_RETURN_FALSE;
        case SS_DQUO:
            if (record->event.pressed) {
                SEND_STRING("\" ");
            }
            return PROCESS_RECORD_RETURN_FALSE;
        case SS_SQUO:
            if (record->event.pressed) {
                SEND_STRING("' ");
            }
            return PROCESS_RECORD_RETURN_FALSE;
        case SS_CIRC:
            if (record->event.pressed) {
                SEND_STRING("^ ");
            }
            return PROCESS_RECORD_RETURN_FALSE;
        case SS_TILD:
            if (record->event.pressed) {
                SEND_STRING("~ ");
            }
            return PROCESS_RECORD_RETURN_FALSE;
        case SS_DEG:
            if (record->event.pressed) {
                if (os.type == MACOS) {
                    tap_code16(LSFT(RALT(KC_8)));
                } else {
                    tap_code16(LSFT(LCTL(KC_2)));
                }
            }
            return PROCESS_RECORD_RETURN_FALSE;
            
    }

    return PROCESS_RECORD_CONTINUE;
}
