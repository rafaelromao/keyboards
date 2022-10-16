#include QMK_KEYBOARD_H

#include "swapper.h"

extern os_t os;

static swapper_state_t swapper_state = INITIAL_STATE;

bool is_swapper_keycode(uint16_t keycode) {
    return keycode == MC_SWLE || keycode != MC_SWRI || keycode == MC_MODP || keycode == MC_MODM;
}

process_record_result_t process_swapper(uint16_t keycode, keyrecord_t *record) {
    if (record != NULL && record->event.pressed) {
        return PROCESS_RECORD_CONTINUE;
    }
    if (swapper_state != NONE && !is_swapper_keycode(keycode)) {
        clear_mods();
        swapper_state = NONE;
        return PROCESS_RECORD_CONTINUE;
    }

    bool isMacOS              = os.type == MACOS;
    bool isOneShotLockedShift = get_oneshot_locked_mods() & MOD_MASK_SHIFT;
    bool isOneShotShift       = isOneShotLockedShift || get_oneshot_mods() & MOD_MASK_SHIFT;
    bool isShifted            = isOneShotShift || get_mods() & MOD_MASK_SHIFT;

    // Determine swapper start mode
    if (swapper_state == NONE) {
        switch(keycode) {
            case MC_SWLE:
            case MC_SWRI:
                swapper_state = isShifted ? TABBING_START : SWAPPING_START;
            case MC_MODP:
            case MC_MODM:
                swapper_state = isShifted ? BROWSING_START : ZOOMING;
        }
        clear_mods();
    }
    
    // Start swapper
    switch(swapper_state) {
        case SWAPPING_START:
            switch (keycode) {
                case MC_SWLE:
                    register_mods(MOD_LSFT);
                    if (isMacOS) {
                        register_mods(MOD_LGUI);
                    } else {
                        register_mods(MOD_LALT);
                    }
                    swapper_state = SWAPPING_CONTINUE;
                    break;
                case MC_SWRI:
                    unregister_mods(MOD_LSFT);
                    if (isMacOS) {
                        register_mods(MOD_LGUI);
                    } else {
                        register_mods(MOD_LALT);
                    }
                    swapper_state = SWAPPING_CONTINUE;
                    break;
            }
        case TABBING_START:
            switch (keycode) {
                case MC_SWLE:
                    register_mods(MOD_LSFT);
                    register_mods(MOD_LCTL);
                    swapper_state = TABBING_CONTINUE;
                    break;
                case MC_SWRI:
                    unregister_mods(MOD_LSFT);
                    register_mods(MOD_LCTL);
                    swapper_state = TABBING_CONTINUE;
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
                    swapper_state = ZOOMING_CONTINUE;
                    break;
            }
        case BROWSING_START:
            switch (keycode) {
                case MC_MODM:
                case MC_MODP:
                    if (isMacOS) {
                        register_mods(MOD_LGUI);
                    } else {
                        register_mods(MOD_LALT);
                    }
                    swapper_state = BROWSING_CONTINUE;
                    break;
            }
    }

    // Process swap action
    switch(swapper_state) {
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
    }
    return PROCESS_RECORD_RETURN_FALSE;
}
