#include QMK_KEYBOARD_H

#include "custom_shift.h"

extern os_t os;

process_record_result_t process_custom_shift(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return PROCESS_RECORD_CONTINUE;
    }

    bool     isOneShotLockedShift = get_oneshot_locked_mods() & MOD_MASK_SHIFT;
    bool     isOneShotShift       = isOneShotLockedShift || get_oneshot_mods() & MOD_MASK_SHIFT;
    bool     isShifted            = isOneShotShift || get_mods() & MOD_MASK_SHIFT;
    uint16_t key                  = extract_base_tapping_keycode(keycode);

    switch (keycode) {
            // Inverted colon and semicolon

        case KC_COLN:
            if (isShifted) {
                clear_shift();
                tap_code(KC_SCLN);
                return PROCESS_RECORD_RETURN_FALSE;
            }
            return PROCESS_RECORD_CONTINUE;

            // Shift+Leader = comma

        case KC_LEAD:
            if (get_mods() & MOD_MASK_SHIFT) {
                unregister_mods(MOD_LSFT);
                tap_code(KC_COMM);
                register_mods(MOD_LSFT);
                return PROCESS_RECORD_RETURN_FALSE;
            }
            return PROCESS_RECORD_CONTINUE;

            //     // Shift+../ = dot

            // case MC_DDS:
            //     if (get_mods() & MOD_MASK_SHIFT) {
            //         unregister_mods(MOD_LSFT);
            //         tap_code(KC_DOT);
            //         register_mods(MOD_LSFT);
            //         return PROCESS_RECORD_RETURN_FALSE;
            //     }
            //     return PROCESS_RECORD_CONTINUE;
    }

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
