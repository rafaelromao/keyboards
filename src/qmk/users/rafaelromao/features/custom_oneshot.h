#pragma once

#include QMK_KEYBOARD_H

#include "../definitions/keycodes.h"
#include "../definitions/process_record.h"
#include "os_toggle.h"
#include "macros.h"
#include "smart_case.h"

bool                    should_send_ctrl(bool isWindowsOrLinux, bool isOneShotShift);
process_record_result_t process_custom_oneshot(uint16_t keycode, keyrecord_t *record);
