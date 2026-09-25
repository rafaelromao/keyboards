#pragma once

#include "rafaelromao.h"

// Key sequences (ZMK macros). Stored in PROGMEM as uint16_t keycode lists,
// terminated by 0, and played with tap_code16: a sequence costs its keycodes
// plus one pointer, where SEND_STRING would cost the string plus the ASCII
// lookup tables. Anything OS-dependent lives in shortcuts.c instead.
enum seq_ids {
    SEQ_SQO,               // ' space
    SEQ_DQO,               // " space
    SEQ_BTI,               // ` space
    SEQ_TILDE,             // ~ space
    SEQ_AND,               // &&
    SEQ_OR,                // ||
    SEQ_BRACES,            // {}
    SEQ_PARS,              // ()
    SEQ_BRACKETS,          // []
    SEQ_US,                // US$
    SEQ_USD,               // USD
    SEQ_BR,                // R$
    SEQ_BRL,               // BRL
    SEQ_EUR,               // EUR
    SEQ_BSLASH_DQO,        // \" space
    SEQ_BSLASH_SQO,        // \' space
    SEQ_END_PARS_SEMI,     // end ();
    SEQ_END_PARS_SEMI_ENT, // end (); enter
    SEQ_TDQO,              // " space, three times
    SEQ_TDQO_ENT,          // same, then enter
    SEQ_TBTI,              // ` space, three times
    SEQ_TBTI_ENT,          // same, then enter
    SEQ_SARROW,            // ->
    SEQ_DARROW,            // =>
    SEQ_FORWARD,           // |>
    SEQ_ENT_FORWARD,       // enter |>
    SEQ_BACKWARD,          // <-
    SEQ_CONCAT,            // <>
    SEQ_DCOLON,            // ::
    SEQ_EQEQ,              // ==
    SEQ_NOTEQ,             // !=
    SEQ_END_LTGTLPRP,      // end <>();
    SEQ_END_LTGTLPRP_ENT,  // end <>(); enter
    SEQ_CARET,             // ^ space F24 (F24 marks "just went home" for the ^ key)
    SEQ_DCURLY,            // ${
    SEQ_HCURLY,            // #{
    SEQ_PCURLY,            // %{
    SEQ_BRACES_NEW,        // end space { enter
    SEQ_END_DO_ENT,        // end space do enter
    SEQ_DEG,               // ° (shift+option+8, macOS)
    SEQ_AT_AT,             // @@
    SEQ_TISL,              // ~/
    SEQ_DS,                // ./
    SEQ_DDS,               // ../
    SEQ_EXIT,              // exit enter
    SEQ_HUGS,              // []'s
    SEQ_OREF,              // [[
    SEQ_OTASK,             // - [ ]
    SEQ_HAHA,              // haha enter
    SEQ_COLPERCSSLASH,     // :%s/
    SEQ_O_ESC,             // o esc
    SEQ_SFT_O_ESC,         // O esc
    SEQ_DQT0P,             // "0p
    SEQ_DQT1P,             // "1p
    SEQ_DQTPLUSP,          // "+p
    SEQ_DQTPLUSY,          // "+y
    SEQ_MACOS,             // MacOS
    SEQ_OMARCHY,           // Omarchy
    SEQ_COUNT
};

void seq_play(uint8_t seq);

// Executes a keycode as a tap: plain and modified keycodes through
// tap_code16, custom keycodes through the feature handlers. Every emitter
// in the userspace goes through this so the last-key tracking stays right.
void execute_keycode(uint16_t keycode);

// MC_N0..MC_N9 (ZMK SHIFT_MEH), MC_SQO, the SEQ-backed macros, MC_SPC_ESC.
bool process_macros(uint16_t keycode, bool pressed);
