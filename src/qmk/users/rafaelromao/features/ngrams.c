#include QMK_KEYBOARD_H

#include "ngrams.h"

extern os_t os;

ngrams_timer_t ngrams_timer = {.timer = 0};

void disable_ngrams_layer(void) {
    clear_oneshot_layer_state(ONESHOT_PRESSED);
    ngrams_timer.timer = 0;
}

bool ngrams_timer_expired(void) {
    return ngrams_timer.timer > 0 && (timer_elapsed(ngrams_timer.timer) > CUSTOM_ONESHOT_TIMEOUT);
}

void check_ngrams_timeout(void) {
    if (ngrams_timer_expired()) {
        disable_ngrams_layer();
    }
}

process_record_result_t process_ngrams(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed && keycode != NAV_NG && keycode != MED_SFT) {
        disable_ngrams_layer();
    }

    if (record->event.pressed) {
        switch (keycode) {
            case MC_RS:
                SEND_STRING("rs");
                return PROCESS_RECORD_RETURN_FALSE;
            case MC_EY:
                SEND_STRING("ey");
                return PROCESS_RECORD_RETURN_FALSE;
            case MC_PH:
                SEND_STRING("ph");
                return PROCESS_RECORD_RETURN_FALSE;
            case MC_CK:
                SEND_STRING("ck");
                return PROCESS_RECORD_RETURN_FALSE;
            case MC_IO:
                SEND_STRING("io");
                return PROCESS_RECORD_RETURN_FALSE;

            case MC_CH:
                SEND_STRING("ch");
                return PROCESS_RECORD_RETURN_FALSE;
            case MC_SH:
                SEND_STRING("sh");
                return PROCESS_RECORD_RETURN_FALSE;
            case MC_HE:
                SEND_STRING("he");
                return PROCESS_RECORD_RETURN_FALSE;
            case MC_THE:
                SEND_STRING("the");
                return PROCESS_RECORD_RETURN_FALSE;
            case MC_GH:
                SEND_STRING("gh");
                return PROCESS_RECORD_RETURN_FALSE;
            case MC_NH:
                SEND_STRING("nh");
                return PROCESS_RECORD_RETURN_FALSE;

            case MC_WH:
                SEND_STRING("wh");
                return PROCESS_RECORD_RETURN_FALSE;
            case MC_SR:
                SEND_STRING("sr");
                return PROCESS_RECORD_RETURN_FALSE;
            case MC_YE:
                SEND_STRING("ye");
                return PROCESS_RECORD_RETURN_FALSE;
            case MC_TH:
                SEND_STRING("th");
                return PROCESS_RECORD_RETURN_FALSE;
            case MC_LH:
                SEND_STRING("lh");
                return PROCESS_RECORD_RETURN_FALSE;
        }
    }

    return PROCESS_RECORD_CONTINUE;
}
