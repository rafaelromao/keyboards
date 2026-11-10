#pragma once

#include "rafaelromao.h"
#include "definitions/process_record.h"

// Resolve the tagged BASE mod-taps using the current host OS. Non-BASE
// mod-taps return PROCESS_RECORD_CONTINUE for the normal tap-hold handler.
process_record_result_t process_base_modtap(uint16_t keycode, keyrecord_t *record);
