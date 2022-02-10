#pragma once

#include QMK_KEYBOARD_H
#include "../definitions/keycodes.h"
#include "tapdance.h"
#include "process_record_result.h"
#include "default_mod_key.h"

process_record_result_t process_combos(uint16_t keycode, keyrecord_t *record);
