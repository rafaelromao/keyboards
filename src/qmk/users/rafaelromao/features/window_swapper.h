#pragma once

#include QMK_KEYBOARD_H
#include "../definitions/keycodes.h"
#include "../definitions/process_record.h"
#include "os_toggle.h"
#include "custom_oneshot.h"

process_record_result_t process_window_swapper(uint16_t keycode, keyrecord_t *record);
