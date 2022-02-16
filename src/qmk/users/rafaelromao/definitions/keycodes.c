#include QMK_KEYBOARD_H

#include "keycodes.h"

uint16_t extract_base_tapping_keycode(uint16_t keycode) {
    // Get the base tapping keycode of a mod- or layer-tap key.
    return keycode &= 0xff;
}