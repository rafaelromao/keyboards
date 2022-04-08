#pragma once

#include QMK_KEYBOARD_H

#include "../definitions/keycodes.h"
#include "process_record_result.h"
#include "os_toggle.h"
#include "dynamic_macro.h"
#include "custom_oneshot_mods.h"

bool should_send_ctrl(bool isWindowsOrLinux, bool isOneShotShift);
process_record_result_t process_smart_thumb_keys(uint16_t keycode, keyrecord_t *record);
