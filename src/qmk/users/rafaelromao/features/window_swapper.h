#pragma once

#include QMK_KEYBOARD_H
#include "../definitions/keycodes.h"
#include "process_record_result.h"
#include "os_toggle.h"

process_record_result_t process_window_swapper(uint16_t keycode, keyrecord_t *record);
