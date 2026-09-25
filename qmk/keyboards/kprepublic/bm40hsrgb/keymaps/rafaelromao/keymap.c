#include "rafaelromao.h"

// The shared keymap is the 36-position layout of the ZMK config (3x5 per hand
// plus 3 thumbs per hand). On the BM40 the two hands sit in columns 0-4 and
// 7-11, the thumbs in columns 2-4 and 6-8 of the bottom row, and the 2u key
// and the remaining cells are unused.
//
// Two macro levels on purpose: the blocks expand to comma-separated lists, and
// only a variadic pass-through makes the layout macro see those commas as
// argument separators.
#define LAYOUT_wrapper(...) LAYOUT_planck_mit(__VA_ARGS__)
#define LAYER(name) LAYOUT_wrapper( \
    name##_L1, XXXXXXX, XXXXXXX, name##_R1, \
    name##_L2, XXXXXXX, XXXXXXX, name##_R2, \
    name##_L3, XXXXXXX, XXXXXXX, name##_R3, \
    XXXXXXX, XXXXXXX, name##_L4, XXXXXXX, name##_R4, XXXXXXX, XXXXXXX)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_ALPHA1]     = LAYER(ALPHA1),
#ifdef RR_VIM_ENABLE
    [_VIM_NORMAL] = LAYER(VIM_NORMAL),
    [_VIM_CHANGE] = LAYER(VIM_CHANGE),
#endif
    [_SHORTS]     = LAYER(SHORTS),
    [_TOGS]       = LAYER(TOGS),
#ifdef RR_MEHS_ENABLE
    [_MEHS]       = LAYER(MEHS),
#endif
    [_ALPHA2]     = LAYER(ALPHA2),
    [_NUM]        = LAYER(NUM),
    [_SYM]        = LAYER(SYM),
    [_CCEDIL]     = LAYER(CCEDIL),
    [_NAV]        = LAYER(NAV),
    [_NUM_CP]     = LAYER(NUM_CP),
    [_SYM_CP]     = LAYER(SYM_CP),
    [_MEDIA]      = LAYER(MEDIA),
    [_NAV_CP]     = LAYER(NAV_CP),
    [_TEXT]       = LAYER(TEXT),
    [_FUN]        = LAYER(FUN),
#ifdef RR_MACROS_ENABLE
    [_MACROS]     = LAYER(MACROS),
#endif
};
// clang-format on
