#pragma once

#include QMK_KEYBOARD_H

#include "os_toggle.h"
#include "default_mod_key.h"

bool process_select_word(uint16_t keycode, keyrecord_t* record, uint16_t sel_keycode);
