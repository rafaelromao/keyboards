#pragma once

// Layer order mirrors the ZMK keymap (zmk/definitions/config.dtsi): the highest
// active layer wins in both firmwares, so the relative order is what matters.
// The *_CP layers are copies that ZMK keeps above NAV/MEDIA for that reason,
// and they are kept here for the same reason. The ZMK index is in the comment.
//
// Layers that only exist in ZMK to carry state (ALT_OS, CAPSWORD, CAPSLINE,
// SENTENCE CASE, SHIFTED/CASE ALPHA2, CASE Ç, ALT REP 2) are flags in QMK,
// see features/smart.h. The vim modes VISUAL/INSERT/REPLACE/CMDLINE are a mode
// variable in features/vim.h; only NORMAL and CHANGE rebind keys.
//
// LT() holds layers 0-15 only. A layer-tap to a layer that may land past 15
// needs a stand-in and an intercepted hold, as TEXT, FUN and MACROS have
// (keycodes.h, high_layer in features/taphold.c).
//
// ALPHA1_CP sits above MEHS and below every layer a base key can turn on, so
// the copy behaves like the base layer (ZMK config.dtsi).
enum layers {
    _ALPHA1,      // 0  OMARCHY
#ifdef RR_VIM_ENABLE
    _VIM_NORMAL,  // 2  NORMAL
    _VIM_CHANGE,  // 4  CHANGE
#endif
#ifdef RR_MEHS_ENABLE
    _MEHS,        // 8  MEHS
    _ALPHA1_CP,   // 9  ALPHA1 CP (the base layout above MEHS)
#endif
    _SHORTS,      // 12 SHORTCUTS
    _TOGS,        // 13 TOGGLES
    _ALPHA2,      // 14 ALPHA2
    _NUM,         // 15 NUMBERS
    _SYM,         // 16 SYMBOLS
    _CCEDIL,      // 17 Ç EXTENSION
    _NAV,         // 22 NAVIGATION
    _NUM_CP,      // 23 NUMBERS (copy above NAV)
    _SYM_CP,      // 24 SYMBOLS (copy above NAV)
    _MEDIA,       // 25 MOUSE
    _NAV_CP,      // 26 NAVIGATION (copy above MEDIA)
    _TEXT,        // 27 TEXT NAVIGATION
    _FUN,         // 28 FUNCTIONS
#ifdef RR_MACROS_ENABLE
    _MACROS,      // 29 MACROS
#endif
    _BASE,        // BASE one-shot (above SHORTCUTS)
    _LAYER_COUNT
};
