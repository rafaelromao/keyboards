#include QMK_KEYBOARD_H

#include "os_toggle.h"

static os_t    os               = {.type = OS_UNSURE};
static uint8_t detect_try_count = 0;

bool is_macos(void) {
    return os.type == OS_MACOS;
}

void try_detect_os(void) {
    if (os.type != OS_UNSURE) {
        return;
    }
    if (os.type == OS_UNSURE && detect_try_count > 10) {
        os.type = OS_WINDOWS;
        return;
    }
    os.type = detected_host_os();
    detect_try_count++;
}

process_record_result_t process_os_toggle(uint16_t keycode, keyrecord_t *record) {
    try_detect_os();
    switch (keycode) {
            // Change OS type

        case TG_OS:
            if (record->event.pressed) {
                if (os.type == OS_MACOS) {
                    os.type = OS_WINDOWS;
                } else {
                    os.type = OS_MACOS;
                }
            }
            return false;
    }

    return PROCESS_RECORD_CONTINUE;
}
