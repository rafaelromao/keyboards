#pragma once

#include QMK_KEYBOARD_H

#include "../definitions/keycodes.h"
#include "../definitions/process_record.h"

process_record_result_t process_repeat_key(uint16_t keycode, const keyrecord_t *record);