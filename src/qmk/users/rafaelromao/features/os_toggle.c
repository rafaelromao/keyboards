#include QMK_KEYBOARD_H

#include "os_toggle.h"

os_t os = {.type = MACOS};

process_record_result_t process_os_toggle(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
            // Change OS type

        case TG_MAC:
            if (record->event.pressed) {
                os.type = MACOS;
            }
            return false;

        case TG_WIN:
            if (record->event.pressed) {
                os.type = WINDOWS;
            }
            return false;
    }

    return PROCESS_RECORD_CONTINUE;
}
