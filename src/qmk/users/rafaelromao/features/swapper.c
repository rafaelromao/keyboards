#include QMK_KEYBOARD_H

#include "swapper.h"

extern os_t os;

static bool swapping = false;
static bool tabbing  = false;

process_record_result_t process_swapper(uint16_t keycode, keyrecord_t *record) {
    if (record != NULL && record->event.pressed) {
        return PROCESS_RECORD_CONTINUE;
    }

    bool isMacOS              = os.type == MACOS;
    bool isOneShotLockedShift = get_oneshot_locked_mods() & MOD_MASK_SHIFT;
    bool isOneShotShift       = isOneShotLockedShift || get_oneshot_mods() & MOD_MASK_SHIFT;
    bool isShifted            = isOneShotShift || get_mods() & MOD_MASK_SHIFT;

    // Finish swapping

    if (swapping && keycode != MC_SWLE && keycode != MC_SWRI && keycode != MC_MODP && keycode != MC_MODM) {
        clear_mods();
        swapping = false;
        tabbing  = false;
    }

    // Start back and forth in windows or tabs

    switch (keycode) {
        case MC_SWLE:
            register_mods(MOD_LSFT); // Back in windows or tabs
            break;
        case MC_SWRI:
            unregister_mods(MOD_LSFT); // Forth in windows or tabs
            break;
    }

    // Continue back and forth in windows or tabs

    switch (keycode) {
        case MC_SWLE:
        case MC_SWRI:
            if (!swapping) {
                swapping = true;
                if (isMacOS) {
                    if (isShifted) {
                        tabbing = true;
                        register_mods(MOD_LCTL); // Tab in Mac
                    } else {
                        register_mods(MOD_LGUI); // Window in Mac
                    }
                } else {
                    if (isShifted) {
                        tabbing = true;
                        register_mods(MOD_LCTL); // Tab in Windows
                    } else {
                        register_mods(MOD_LALT); // Window in Windows
                    }
                }
            }
            tap_code(KC_TAB); // Action key
            return PROCESS_RECORD_RETURN_FALSE;
    }

    // Start back and forth in history or zoom

    switch (keycode) {
        case MC_MODP:
        case MC_MODM:
            if (!swapping) {
                swapping = true;
                if (isMacOS) {
                    if (isShifted) {
                        tabbing = true;
                        clear_shift();
                        register_mods(MOD_LGUI); // History Mac
                    } else {
                        register_mods(MOD_LGUI); // Zoom Mac
                    }
                } else {
                    if (isShifted) {
                        tabbing = true;
                        clear_shift();
                        register_mods(MOD_LALT); // History Windows
                    } else {
                        register_mods(MOD_LCTL); // Zoom Windows
                    }
                }
            }
            // Action keys
            switch (keycode) {
                case MC_MODM:
                    if (isMacOS) {
                        if (tabbing) {
                            tap_code(KC_LBRC); // History - Mac
                        } else {
                            tap_code(KC_MINS); // Zoom - Mac
                        }
                    } else {
                        if (tabbing) {
                            tap_code(KC_LEFT); // History - Windows
                        } else {
                            tap_code(KC_MINS); // Zoom - Windows
                        }
                    }
                    return PROCESS_RECORD_RETURN_FALSE;

                case MC_MODP:
                    if (isMacOS) {
                        if (tabbing) {
                            tap_code(KC_RBRC); // History + Mac
                        } else {
                            tap_code16(KC_EQL); // Zoom + Mac
                        }
                    } else {
                        if (tabbing) {
                            tap_code(KC_RIGHT); // History + Windows
                        } else {
                            tap_code16(KC_EQL); // Zoom + Windows
                        }
                    }
                    return PROCESS_RECORD_RETURN_FALSE;
            }
    }

    return PROCESS_RECORD_CONTINUE;
}
