#include QMK_KEYBOARD_H

#include "ngrams_key.h"

extern os_t os;

static ngrams_timer_t ngrams_timer = {
    .timer = 0
};

void disable_ngrams_layer(void) {
    clear_oneshot_layer_state(ONESHOT_PRESSED);
    ngrams_timer.timer = 0;
}

process_record_result_t process_ngrams_key(uint16_t keycode, keyrecord_t *record) {

    if (!record->event.pressed && keycode != NAV_NG && keycode != MED_CAP) {
        disable_ngrams_layer();
    }

    switch (keycode) {

        case NAV_NG:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    if (IS_LAYER_ON(_NGRAMS)) {
                        clear_oneshot_layer_state(ONESHOT_PRESSED);
                    } else {
                        set_oneshot_layer(_NGRAMS, ONESHOT_START);
                        ngrams_timer.timer = timer_read();
                    }
                }
                return PROCESS_RECORD_RETURN_FALSE;
            }
    }

    return PROCESS_RECORD_CONTINUE;
}

bool ngrams_timer_expired(void) {
    return ngrams_timer.timer > 0 && (timer_elapsed(ngrams_timer.timer) > 5 * ONESHOT_TIMEOUT);
}

void check_ngrams_timeout(void) {
    if (ngrams_timer_expired()) {
        disable_ngrams_layer();
    }
}

process_record_result_t process_ngrams(uint16_t keycode, keyrecord_t *record) {

    if (record->event.pressed) {
        switch (keycode) {

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