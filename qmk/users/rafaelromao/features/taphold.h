#pragma once

#include "rafaelromao.h"
#include "definitions/process_record.h"

// Tap/hold keys with custom actions (ZMK th_*, mt_meh_*, mt_*_vim, hsk,
// mod_num and the lt_* layer-taps), and the per-key tap-hold settings.
process_record_result_t process_taphold(uint16_t keycode, keyrecord_t *record);

// The keycode a th_* key types on tap (its symbol), for the smart layers.
uint16_t taphold_tap_keycode(uint16_t keycode);
