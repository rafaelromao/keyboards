#include QMK_KEYBOARD_H

#include "ngrams_key.h"

extern os_t os;

process_record_result_t process_ngrams_key(uint16_t keycode, keyrecord_t *record) {

    if (record->event.pressed && keycode != NAV_NG) {
        clear_oneshot_layer_state(ONESHOT_PRESSED);
    }

    switch (keycode) {

        case NAV_NG:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    if (IS_LAYER_ON(_NGRAMS)) {
                        clear_oneshot_layer_state(ONESHOT_PRESSED);
                    } else {
                        set_oneshot_layer(_NGRAMS, ONESHOT_START);
                    }
                }
                return PROCESS_RECORD_RETURN_FALSE;
            }
    }

    return PROCESS_RECORD_CONTINUE;
}