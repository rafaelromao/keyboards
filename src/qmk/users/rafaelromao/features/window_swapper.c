#include QMK_KEYBOARD_H

#include "window_swapper.h"

extern os_t os;

static bool swapping = false;

process_record_result_t process_window_swapper(uint16_t keycode, keyrecord_t *record) {
    bool isMacOS = os.type == MACOS;

    if (swapping && keycode != MC_SWLE && keycode != MC_SWRI) {
        swapping = false;
        unregister_mods(MOD_LSFT);
        if (isMacOS) {
            unregister_mods(MOD_LGUI);
        } else {
            unregister_mods(MOD_LALT);
        }
    }

    switch (keycode) {
        case MC_SWLE:
            register_mods(MOD_LSFT);
            break;
        case MC_SWRI:
            unregister_mods(MOD_LSFT);
            break;
    }

    switch (keycode) {
        case MC_SWLE:
        case MC_SWRI:
            if (record->event.pressed) {
                if (!swapping) {
                    swapping = true;
                    if (isMacOS) {
                        register_mods(MOD_LGUI);
                    } else {
                        register_mods(MOD_LALT);
                    }
                }
                tap_code(KC_TAB);
            }
            return PROCESS_RECORD_RETURN_FALSE;
    }

    return PROCESS_RECORD_CONTINUE;
}
