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

            case SS_IT:
                SEND_STRING("it");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_FOR:
                SEND_STRING("for");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_QU:
                SEND_STRING("qu");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_PH:
                SEND_STRING("ph");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_IS:
                SEND_STRING("is");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_SI:
                SEND_STRING("si");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_LH:
                SEND_STRING("lh");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_IN:
                SEND_STRING("in");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_ON:
                SEND_STRING("on");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_TI:
                SEND_STRING("ti");
                return PROCESS_RECORD_RETURN_FALSE;

            case SS_IF:
                SEND_STRING("if");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_SH:
                SEND_STRING("sh");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_ER:
                SEND_STRING("er");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_AND:
                SEND_STRING("and");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_GH:
                SEND_STRING("gh");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_HE:
                SEND_STRING("he");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_NH:
                SEND_STRING("nh");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_ING:
                SEND_STRING("ing");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_NDO:
                SEND_STRING("ndo");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_CH:
                SEND_STRING("ch");
                return PROCESS_RECORD_RETURN_FALSE;

            case SS_OF:
                SEND_STRING("of");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_TO:
                SEND_STRING("to");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_THE:
                SEND_STRING("the");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_TH:
                SEND_STRING("th");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_AT:
                SEND_STRING("at");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_SPP:
                SEND_STRING(" (");
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
            case SS_WH:
                SEND_STRING("wh");
                return PROCESS_RECORD_RETURN_FALSE;

        }
    }

    return PROCESS_RECORD_CONTINUE;
}