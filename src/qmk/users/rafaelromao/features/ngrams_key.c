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