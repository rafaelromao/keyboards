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
                
            
            // N-Grams

            case SS_RS:
                SEND_STRING("rs");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_RE:
                SEND_STRING("re");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_PH:
                SEND_STRING("ph");
                return PROCESS_RECORD_RETURN_FALSE;
            
            case SS_LH:
                SEND_STRING("lh");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_ING:
                SEND_STRING("ing");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_IO:
                SEND_STRING("io");
                return PROCESS_RECORD_RETURN_FALSE;

            case SS_GU:
                SEND_STRING("gu");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_SH:
                SEND_STRING("sh");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_HE:
                SEND_STRING("he");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_TH:
                SEND_STRING("th");
                return PROCESS_RECORD_RETURN_FALSE;
                
            case SS_NH:
                SEND_STRING("nh");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_CH:
                SEND_STRING("ch");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_WH:
                SEND_STRING("wh");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_NDO:
                SEND_STRING("ndo");
                return PROCESS_RECORD_RETURN_FALSE;

            case SS_SR:
                SEND_STRING("sr");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_ER:
                SEND_STRING("er");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_GH:
                SEND_STRING("gh");
                return PROCESS_RECORD_RETURN_FALSE;

            case SS_TAR:
                SEND_STRING("-> ");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_FAR:
                SEND_STRING("=> ");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_DDS:
                SEND_STRING("../");
                return PROCESS_RECORD_RETURN_FALSE;

        }
    }

    return PROCESS_RECORD_CONTINUE;
}