#include QMK_KEYBOARD_H

#include "sentence_case.h"

process_record_result_t process_sentence_case(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case NAV_CAN:
            if (record->tap.count == 0) {
                if (record->event.pressed) {
                    disable_oneshot_layer();
                    layer_on(_NAVIGATION);
                } else {
                    layer_off(_NAVIGATION);
                }
            } else {
                if (record->event.pressed) {
                    disable_smart_case();
                    clear_shift();
                    return PROCESS_RECORD_RETURN_FALSE;
                }
            }
            break;

        case LOW_NSE:
            if (record->tap.count == 0) {
                if (record->event.pressed) {
                    disable_oneshot_layer();
                    layer_on(_LOWER);
                } else {
                    layer_off(_LOWER);
                }
            } else {
                if (record->event.pressed) {
                    tap_code(KC_SPC);
                    set_oneshot_layer(_SEN_CASE, ONESHOT_START);
                    reset_oneshot_timer();
                    add_oneshot_mods(MOD_LSFT);
                }
            }
            return PROCESS_RECORD_RETURN_FALSE;

        case MED_OSF:
            if (record->tap.count == 0) {
                if (record->event.pressed) {
                    layer_on(_MEDIA);
                } else {
                    layer_off(_MEDIA);
                }
                return PROCESS_RECORD_RETURN_FALSE;
            }
            break;
    }

    return PROCESS_RECORD_CONTINUE;
}
