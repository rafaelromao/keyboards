#include QMK_KEYBOARD_H

#include "macros.h"

process_record_result_t process_macro_keycode(uint16_t keycode, bool isOneShotShift, bool isShifted) {
    bool isMacOS = is_macos();

    switch (keycode) {
            // `

        case MC_BTIC:
            tap_code(KC_GRV);
            tap_code(KC_SPC);
            return PROCESS_RECORD_RETURN_FALSE;

            // "

        case MC_DQUO:
            tap_code16(KC_DQUO);
            tap_code(KC_SPC);
            return PROCESS_RECORD_RETURN_FALSE;

            // '

        case MC_SQUO:
            tap_code(KC_QUOT);
            tap_code(KC_SPC);
            return PROCESS_RECORD_RETURN_FALSE;

            // ^

        case MC_CIRC:
            tap_code16(KC_CIRC);
            tap_code(KC_SPC);
            return PROCESS_RECORD_RETURN_FALSE;

            // ~

        case MC_TILD:
            tap_code16(KC_TILD);
            tap_code(KC_SPC);
            return PROCESS_RECORD_RETURN_FALSE;

            // =>

        case MC_DAR:
            tap_code16(KC_EQL);
            tap_code16(KC_GT);
            return PROCESS_RECORD_RETURN_FALSE;

            // ->

        case MC_SAR:
            tap_code16(KC_MINS);
            tap_code16(KC_GT);
            return PROCESS_RECORD_RETURN_FALSE;

            // ==

        case MC_DEQ:
            tap_code16(KC_EQL);
            tap_code16(KC_EQL);
            return PROCESS_RECORD_RETURN_FALSE;

            // !=

        case MC_NEQ:
            tap_code16(KC_EXLM);
            tap_code16(KC_EQL);
            return PROCESS_RECORD_RETURN_FALSE;

            // <=

        case MC_LTE:
            tap_code16(KC_LT);
            tap_code16(KC_EQL);
            return PROCESS_RECORD_RETURN_FALSE;

            // >=

        case MC_GTE:
            tap_code16(KC_GT);
            tap_code16(KC_EQL);
            return PROCESS_RECORD_RETURN_FALSE;

            // ../

        case MC_DDS:
            tap_code(KC_DOT);
            tap_code(KC_DOT);
            tap_code16(KC_SLSH);
            return PROCESS_RECORD_RETURN_FALSE;

            // ~/

        case MC_TISL:
            tap_code16(KC_TILD);
            tap_code(KC_SPC);
            tap_code16(KC_SLSH);
            return PROCESS_RECORD_RETURN_FALSE;

            // °

        case MC_DEG:
            if (isMacOS) {
                tap_code16(LSFT(RALT(KC_8)));
            } else {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_0) SS_TAP(X_KP_1) SS_TAP(X_KP_7) SS_TAP(X_KP_6)));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // §

        case MC_SEC:
            if (isMacOS) {
                SEND_STRING(SS_LALT(SS_TAP(X_6)));
            } else {
                SEND_STRING(SS_RALT(SS_LSFT(SS_TAP(X_S))));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // º

        case MC_ORDO:
            if (isMacOS) {
                tap_code16(RALT(KC_0));
            } else {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_6) SS_TAP(X_KP_7)));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // ª

        case MC_ORDA:
            if (isMacOS) {
                tap_code16(RALT(KC_9));
            } else {
                SEND_STRING(SS_LALT(SS_TAP(X_KP_1) SS_TAP(X_KP_6) SS_TAP(X_KP_6)));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // END ; ENTER

        case MC_SENT:
            tap_code(KC_END);
            tap_code(KC_SCLN);
            tap_code(KC_ENT);
            disable_smart_case();
            return PROCESS_RECORD_RETURN_FALSE;

            // []

        case MC_BRAC:
            tap_code16(KC_LBRC);
            tap_code16(KC_RBRC);
            return PROCESS_RECORD_RETURN_FALSE;

            // {}

        case MC_CURS:
            tap_code16(KC_LCBR);
            tap_code16(KC_RCBR);
            return PROCESS_RECORD_RETURN_FALSE;

            // END { ENTER }

        case MC_CUR:
            SEND_STRING(SS_TAP(X_END) "{}" SS_DELAY(50) SS_TAP(X_LEFT) SS_TAP(X_ENT));
            disable_smart_case();
            return PROCESS_RECORD_RETURN_FALSE;

            // €

        case MC_EUR:
            if (isMacOS) {
                tap_code16(LSFT(RALT(KC_2)));
            } else {
                tap_code16(LCTL(LALT(KC_5)));
            }
            return PROCESS_RECORD_RETURN_FALSE;

            // &&

        case MC_DAND:
            tap_code16(KC_AMPR);
            tap_code16(KC_AMPR);
            return PROCESS_RECORD_RETURN_FALSE;

            // ||

        case MC_DPIP:
            tap_code16(KC_PIPE);
            tap_code16(KC_PIPE);
            return PROCESS_RECORD_RETURN_FALSE;

            // Question Mark with Sentence Case

        case MC_QUES:
            tap_code16(KC_QUES);
            start_sentence_case();
            return PROCESS_RECORD_RETURN_FALSE;

            // Exclamation with Sentence Case

        case MC_EXLM:
            tap_code16(KC_EXLM);
            start_sentence_case();
            return PROCESS_RECORD_RETURN_FALSE;
    }

    return PROCESS_RECORD_CONTINUE;
}

process_record_result_t process_macros(uint16_t keycode, keyrecord_t *record) {
    if (!is_shift_macro_keycode(keycode)) {
        return PROCESS_RECORD_CONTINUE;
    }

    if (record != NULL && !record->event.pressed) {
        return PROCESS_RECORD_CONTINUE;
    }

    bool isOneShotShift       = get_oneshot_mods() & MOD_MASK_SHIFT;
    bool isShifted            = isOneShotShift || get_mods() & MOD_MASK_SHIFT;

    // Macros

    int8_t mods = get_mods();
    if (isShifted) {
        clear_oneshot_shift();
        unregister_mods(mods);
    }
    process_record_result_t result = process_macro_keycode(keycode, isOneShotShift, isShifted);
    if (isShifted) {
        wait_ms(100);
        register_mods(mods);
    }

    return result;
}
