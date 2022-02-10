#pragma once

#include QMK_KEYBOARD_H
#include "../definitions/keycodes.h"
#include "process_record_result.h"
#include "default_mod_key.h"

process_record_result_t process_accentuated_characters(uint16_t keycode, keyrecord_t *record);
