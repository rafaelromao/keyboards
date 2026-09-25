#pragma once

#include "rafaelromao.h"
#include "definitions/process_record.h"

// The smart thumb keys: L0 (ltn_num_spc), L1 (ht_repeat), R0 (msl_sym_a2),
// R1 (ht_shift), and the magic key on the right index (ht_magic). Their
// holds are the native layer/mod; the taps are decided here from the state
// in smart.c the way ZMK's layer variants (CAPSWORD, SENTENCE CASE, SHIFTED
// ALPHA2, ALT REP 2) would have.
process_record_result_t process_thumbs(uint16_t keycode, keyrecord_t *record);
void                    thumbs_magic(void);
