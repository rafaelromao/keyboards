#include QMK_KEYBOARD_H

#include "swapper.h"

swapper_t swapper = {.state = NONE};

bool is_swapper_keycode(uint16_t keycode) {
    switch (keycode) {
        case MC_SWLE:
        case MC_SWRI:
        case MC_MODM:
        case MC_MODP:
        case SF_MODM:
            return true;
        default:
            return false;
    }
}

process_record_result_t process_swapper(uint16_t keycode, keyrecord_t *record) {
    if (record != NULL && record->event.pressed) {
        return PROCESS_RECORD_CONTINUE;
    }

    // Finish swapper
    if (!is_swapper_keycode(keycode)) {
        if (swapper.state != NONE) {
            unregister_mods(get_mods());
            swapper.state = NONE;
        }
        return PROCESS_RECORD_CONTINUE;
    }

    bool isMacOS              = is_macos();
    bool isOneShotLockedShift = get_oneshot_locked_mods() & MOD_MASK_SHIFT;
    bool isOneShotShift       = isOneShotLockedShift || get_oneshot_mods() & MOD_MASK_SHIFT;
    bool isShifted            = isOneShotShift || get_mods() & MOD_MASK_SHIFT;

    // Determine swapper mode
    if (swapper.state == NONE) {
        switch(keycode) {
            case MC_SWLE:
            case MC_SWRI:
                swapper.state = isShifted ? TABBING_START : SWAPPING_START;
                break;
            case MC_MODP:
            case MC_MODM:
                swapper.state = isShifted ? BROWSING_START : ZOOMING_START;
                break;
        }
        unregister_mods(get_mods());
    }

    // Start swapper
    switch (swapper.state) {
        case SWAPPING_START:
            switch (keycode) {
                case MC_SWLE:
                case MC_SWRI:
                    if (isMacOS) {
                        register_mods(MOD_LGUI);
                    } else {
                        register_mods(MOD_LALT);
                    }
                    swapper.state = SWAPPING_CONTINUE;
                    break;
            }
            break;
        case TABBING_START:
            switch (keycode) {
                case MC_SWLE:
                    register_mods(MOD_LSFT);
                    register_mods(MOD_LCTL);
                    swapper.state = TABBING_CONTINUE;
                    break;
                case MC_SWRI:
                    unregister_mods(MOD_LSFT);
                    register_mods(MOD_LCTL);
                    swapper.state = TABBING_CONTINUE;
                    break;
            }
            break;
        case ZOOMING_START:
            switch (keycode) {
                case MC_MODM:
                case MC_MODP:
                    if (isMacOS) {
                        register_mods(MOD_LGUI);
                    } else {
                        register_mods(MOD_LCTL);
                    }
                    swapper.state = ZOOMING_CONTINUE;
                    break;
            }
            break;
        case BROWSING_START:
            switch (keycode) {
                case MC_MODM:
                case MC_MODP:
                    if (isMacOS) {
                        register_mods(MOD_LGUI);
                    } else {
                        register_mods(MOD_LALT);
                    }
                    swapper.state = BROWSING_CONTINUE;
                    break;
            }
            break;
        default:
            break;
    }

    // Check if action was reversed since started
    switch (swapper.state) {
        case SWAPPING_CONTINUE:
        case TABBING_CONTINUE:
            switch (keycode) {
                case MC_SWLE:
                    register_mods(MOD_LSFT);
                    break;
                case MC_SWRI:
                    unregister_mods(MOD_LSFT);
                    break;
            }
        default:
            break;
    }

    // Process swap action
    switch (swapper.state) {
        case SWAPPING_CONTINUE:
        case TABBING_CONTINUE:
            tap_code(KC_TAB);
            break;
        case ZOOMING_CONTINUE:
            switch (keycode) {
                case MC_MODM:
                    tap_code(KC_MINS);
                    break;
                case MC_MODP:
                    tap_code(KC_EQL);
                    break;
            }
            break;
        case BROWSING_CONTINUE:
            switch (keycode) {
                case MC_MODM:
                    if (isMacOS) {
                        tap_code(KC_LBRC);
                    } else {
                        tap_code(KC_LEFT);
                    }
                    break;
                case MC_MODP:
                    if (isMacOS) {
                        tap_code(KC_RBRC);
                    } else {
                        tap_code(KC_RIGHT);
                    }
                    break;
            }
            break;
        default:
            break;
    }

    return PROCESS_RECORD_RETURN_FALSE;
}
