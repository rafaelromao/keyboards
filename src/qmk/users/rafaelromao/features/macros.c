#include QMK_KEYBOARD_H

#include "macros.h"

extern os_t os;

process_record_result_t process_macros(uint16_t keycode, keyrecord_t *record) {

    bool isOneShotLockedShift = get_oneshot_locked_mods() & MOD_MASK_SHIFT;
    bool isOneShotShift = isOneShotLockedShift || get_oneshot_mods() & MOD_MASK_SHIFT;
    bool isShifted = isOneShotShift || get_mods() & MOD_MASK_SHIFT;

    if (record->event.pressed) {
        switch (keycode) {

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

            case SS_DAND:
                SEND_STRING("&&");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_DPIP:
                SEND_STRING("||");
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_EQU:
                clear_shift();
                tap_code(KC_EQL);
                tap_code(KC_EQL);
                if (isShifted) {
                    tap_code(KC_EQL);
                }
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_NEQ:
                clear_shift();
                tap_code16(KC_EXLM);
                tap_code(KC_EQL);
                if (isShifted) {
                    tap_code(KC_EQL);
                }
                return PROCESS_RECORD_RETURN_FALSE;

            case SS_ARR:
                if (isShifted) {
                    clear_shift();
                    SEND_STRING("=>");
                } else {
                    SEND_STRING("->");
                }
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_DDS:
                SEND_STRING("../");
                return PROCESS_RECORD_RETURN_FALSE;

            case SS_AO:
                clear_shift();
                tap_code16(KC_TILD);
                tap_code(KC_A);
                tap_code(KC_O);
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_CAO:
                clear_shift();
                tap_code16(KC_QUOT);
                tap_code(KC_C);
                tap_code16(KC_TILD);
                tap_code(KC_A);
                tap_code(KC_O);
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_OES:
                clear_shift();
                tap_code16(KC_TILD);
                tap_code(KC_O);
                tap_code(KC_E);
                tap_code(KC_S);
                return PROCESS_RECORD_RETURN_FALSE;
            case SS_COES:
                clear_shift();
                tap_code16(KC_QUOT);
                tap_code(KC_C);
                tap_code16(KC_TILD);
                tap_code(KC_O);
                tap_code(KC_E);
                tap_code(KC_S);
                return PROCESS_RECORD_RETURN_FALSE;
        }
    }

    return PROCESS_RECORD_CONTINUE;
}