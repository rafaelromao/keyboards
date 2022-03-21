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
            case SS_CK:
                SEND_STRING("ck");
                return PROCESS_RECORD_RETURN_FALSE;

            case SS_CH:
                SEND_STRING("ch");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_SH:
                SEND_STRING("sh");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_HE:
                SEND_STRING("he");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_NH:
                SEND_STRING("nh");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_GH:
                SEND_STRING("gh");
                return PROCESS_RECORD_RETURN_FALSE;

            case SS_WH:
                SEND_STRING("wh");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_SR:
                SEND_STRING("sr");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_ER:
                SEND_STRING("er");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_TH:
                SEND_STRING("th");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_ING:
                SEND_STRING("ing");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_IO:
                SEND_STRING("io");
                return PROCESS_RECORD_RETURN_FALSE;

            // Macro layer macros

            case SS_SPA:
                SEND_STRING(" (");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_OCP:
                SEND_STRING("()");
                tap_code(KC_LEFT);
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_SCU:
                SEND_STRING(" {");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_OCC:
                SEND_STRING("{}");
                tap_code(KC_LEFT);
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_SSQ:
                SEND_STRING(" [");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_OCS:
                SEND_STRING("[]");
                tap_code(KC_LEFT);
                return PROCESS_RECORD_RETURN_FALSE;

            case SS_SAR:
                SEND_STRING("-> ");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_DAR:
                SEND_STRING("=> ");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_DDS:
                SEND_STRING("../");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_IIF:
                SEND_STRING("?:");
                tap_code(KC_LEFT);
                return PROCESS_RECORD_RETURN_FALSE;

            case SS_CWQ:
                SEND_STRING(":wq");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_CQB:
                SEND_STRING(":q!");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_CPS:
                SEND_STRING(":%s/");
                return PROCESS_RECORD_RETURN_FALSE;
        }
    }

    return PROCESS_RECORD_CONTINUE;
}