#pragma once

// Layer order mirrors the ZMK keymap (src/definitions/config.dtsi): the highest
// active layer wins in both firmwares, so the relative order is what matters.
// The *_CP layers are copies that ZMK keeps above NAV/MEDIA for that reason,
// and they are kept here for the same reason. The ZMK index is in the comment.
//
// Layers that only exist in ZMK to carry state (ALT_OS, CAPSWORD, CAPSLINE,
// SENTENCE CASE, SHIFTED/CASE ALPHA2, CASE Ç, ALT REP 2) are flags in QMK,
// see features/smart.h. The vim modes VISUAL/INSERT/REPLACE/CMDLINE are a mode
// variable in features/vim.h; only NORMAL and CHANGE rebind keys.
enum layers {
    _ALPHA1,      // 0  OMARCHY
#ifdef RR_VIM_ENABLE
    _VIM_NORMAL,  // 2  NORMAL
    _VIM_CHANGE,  // 4  CHANGE
#endif
    _SHORTS,      // 10 SHORTCUTS
    _TOGS,        // 11 TOGGLES
#ifdef RR_MEHS_ENABLE
    _MEHS,        // 12 MEHS
#endif
    _ALPHA2,      // 13 ALPHA2
    _NUM,         // 14 NUMBERS
    _SYM,         // 15 SYMBOLS
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
    _LAYER_COUNT
};
