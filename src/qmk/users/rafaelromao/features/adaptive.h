#pragma once

#include "rafaelromao.h"

// Last-key tracking and the adaptive keys (ZMK urob/zmk-adaptive-key rules
// in src/features/adaptive.dtsi): alternate repeat, alpha2 alternate repeat,
// magic key, reversed magic key and key repeat. A rule only applies while
// the previous key is younger than ADAPTIVE_TIMEOUT.
#define ADAPTIVE_TIMEOUT 2000

// Records a key that was just typed. Takes a 16-bit keycode: the basic key
// and whether it was shifted are what the rules look at.
void adaptive_track(uint16_t keycode);
// True when the previous key was `keycode` (basic key and shift state both
// matching) and is still within ADAPTIVE_TIMEOUT.
bool adaptive_last_is(uint16_t keycode);
// The previous basic key (KC_NO when expired) and whether it was shifted.
uint8_t adaptive_last_key(void);
bool    adaptive_last_shifted(void);

void adaptive_alt_repeat(void);     // alternate_repeat_key
void adaptive_a2_alt_repeat(void);  // a2_alt_repeat
void adaptive_magic(void);          // magic_key / magic_key_c
void adaptive_reversed_magic(void); // reversed_magic / reversed_magic_c
void adaptive_repeat(void);         // &key_repeat
