#include QMK_KEYBOARD_H

#include "repeat.h"

process_record_result_t process_repeat(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case NAV_REP:
            if (record->event.pressed) {
                if (record->tap.count > 0) {
                    keyrecord_t press;
                    press.event.pressed = true;
                    process_repeat_key(QK_REP, &press);
                    keyrecord_t release;
                    release.event.pressed = false;
                    process_repeat_key(QK_REP, &release);
                    return PROCESS_RECORD_RETURN_TRUE;
                }
            }
        default:
            return PROCESS_RECORD_CONTINUE;
    }
}

bool remember_last_key_user(uint16_t keycode, keyrecord_t* record, uint8_t* remembered_mods) {
    switch (keycode) {
        case RAI_ACT:
        case NAV_REP:
            return false;
    }
    return true;
}