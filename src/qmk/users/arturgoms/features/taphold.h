#pragma once

#include QMK_KEYBOARD_H
#include "../definitions/keycodes.h"
#include "tapdance.h"
#include "smart_case.h"
#include "smart_thumb_keys.h"

process_record_result_t process_taphold(uint16_t keycode, keyrecord_t *record);