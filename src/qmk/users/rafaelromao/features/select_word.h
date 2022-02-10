#pragma once

#include QMK_KEYBOARD_H

#include "os_toggle.h"
#include "default_mod_key.h"
#include "process_record_result.h"

process_record_result_t process_select_word(uint16_t keycode, keyrecord_t* record);
