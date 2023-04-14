#include QMK_KEYBOARD_H

#include "custom_shift.h"

extern os_t os;

process_record_result_t process_custom_shift(uint16_t keycode, keyrecord_t *record) {
    bool isOneShotLockedShift = get_oneshot_locked_mods() & MOD_MASK_SHIFT;
    bool isOneShotShift       = isOneShotLockedShift || get_oneshot_mods() & MOD_MASK_SHIFT;
    bool isShifted            = isOneShotShift || get_mods() & MOD_MASK_SHIFT;

    switch (keycode) {
            // Euro sign

        case TD_DLR:
            if (isShifted) {
                if (is_macos()) {
                    tap_code16(LSFT(RALT(KC_2)));
                } else {
                    clear_shift();
                    tap_code16(LCTL(LALT(KC_5)));
                }
                return PROCESS_RECORD_RETURN_FALSE;
            }
            return PROCESS_RECORD_CONTINUE;
    }

    uint16_t key = extract_base_tapping_keycode(keycode);

    switch (key) {
            // Shifted numrow = numpad

        case KC_1 ... KC_0:
            if (isShifted) {
                tap_code(key + 59);
                return PROCESS_RECORD_RETURN_FALSE;
            }
            return PROCESS_RECORD_CONTINUE;
    }

    return PROCESS_RECORD_CONTINUE;
}
