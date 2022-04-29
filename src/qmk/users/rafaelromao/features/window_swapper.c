#include QMK_KEYBOARD_H

#include "window_swapper.h"

extern os_t os;

static bool swapping = false;

process_record_result_t process_window_swapper(uint16_t keycode, keyrecord_t *record) {
    bool isWindowsOrLinux = os.type == WINDOWS || os.type == LINUX;

    if (swapping && keycode != MC_SWIN) {
        swapping = false;
        if (isWindowsOrLinux) {
            unregister_mods(MOD_LALT);
        } else {
            unregister_mods(MOD_LGUI);
        }
    }

    switch (keycode) {
        // Swap Windows
        case MC_SWIN:
            if (record->event.pressed) {
                if (!swapping) {
                    swapping = true;
                    if (isWindowsOrLinux) {
                        register_mods(MOD_LALT);
                    } else {
                        register_mods(MOD_LGUI);
                    }
                }
                tap_code(KC_TAB);
            }
            return PROCESS_RECORD_RETURN_FALSE;
    }

    return PROCESS_RECORD_CONTINUE;
}