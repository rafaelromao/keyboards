#pragma once

#include QMK_KEYBOARD_H
#include "../definitions/keycodes.h"
#include "tapdance.h"

process_record_result_t process_taphold(uint16_t keycode, keyrecord_t *record);
uint16_t get_tapping_term_result(uint16_t keycode);
bool get_hold_on_other_key_press_result(uint16_t keycode);
bool get_tapping_force_hold_result(uint16_t keycode);
