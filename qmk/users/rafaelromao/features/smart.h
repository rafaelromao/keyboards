#pragma once

#include "rafaelromao.h"

// The state that ZMK keeps in extra layers: caps word / caps line (auto-layer
// CAPSWORD / CAPSLINE), num word (auto-layer on NUMBERS), the one-shot layers
// (&sl ALPHA2 / CCEDIL / NUM_CP), sentence case, the alpha2 alternate repeat
// window (ALT REP 2) and the cancel/reset behaviour.

#define OSL_TIMEOUT 1000       // ZMK &sl release-after-ms
#define SENTENCE_TIMEOUT 1000  // the SENTENCE CASE sticky layer
#define ALTREP2_TIMEOUT 1000   // the ALT REP 2 sticky layer

// Custom one-shot layers (ZMK &sl with quick-release: gone on the next key
// press, or after OSL_TIMEOUT).
void    smart_osl_on(uint8_t layer);
void    smart_osl_off(void);
uint8_t smart_osl_layer(void);

// Caps word (ZMK smart_word) and caps line (smart_line: also survives spaces)
void smart_caps_word_on(void);
void smart_caps_line_on(void);
bool smart_caps_line(void);
bool smart_caps_continues(uint16_t keycode);

// Num word (ZMK smart_num on NUMBERS or its copy)
void smart_num_word_on(uint8_t layer);
void smart_num_word_off(void);

// Sentence case: a one-shot shift that lasts SENTENCE_TIMEOUT
void smart_sentence_shift(void);
bool smart_sentence_pending(void);

// ALT REP 2: set after an accent or "qu", read by the L1 tap
void smart_altrep2_arm(void);
bool smart_altrep2_active(void);
void smart_altrep2_clear(void);

// Handlers that set one-shot mods call this so the press that set them does
// not also consume them.
void smart_oneshot_set(uint8_t mods);
// ...and handlers that hand a pending one-shot on to the next key call this.
void smart_keep_oneshot(void);

// tc_cancel: K_CANCEL to the host and back to the base state
void smart_cancel(void);

// Hooks
void smart_before_press(uint16_t keycode, keyrecord_t *record);
void smart_after_press(uint16_t keycode, keyrecord_t *record, bool intercepted);
void smart_housekeeping(void);
bool process_smart(uint16_t keycode, bool pressed);
