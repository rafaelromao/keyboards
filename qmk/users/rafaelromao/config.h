#pragma once

// --- Optional parts of the layout ---------------------------------------
// These are the pieces that get cut, in this order, if a board runs out of
// flash: MEHS first, then vim mode, then the MACROS layer text macros.
// Comment one out to drop it; the layer enum, the keymaps, the combos and the
// feature code all follow the define.
#define RR_MEHS_ENABLE
#define RR_VIM_ENABLE
#define RR_MACROS_ENABLE

// --- Tap-hold ------------------------------------------------------------
// ZMK: &mt/&lt are tap-preferred, tapping-term 250, quick-tap 175. That is
// QMK's default decision mode, so no PERMISSIVE_HOLD / HOLD_ON_OTHER_KEY_PRESS /
// RETRO_TAPPING globally; the thumb keys and the hold-preferred keys get their
// own values in features/taphold.c.
#define TAPPING_TERM 250
#define TAPPING_TERM_PER_KEY
#define QUICK_TAP_TERM 175
#define QUICK_TAP_TERM_PER_KEY
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
// ZMK require-prior-idle-ms on the symbol tap-holds and the Meh mod-taps.
#define FLOW_TAP_TERM 175

// --- One-shots -----------------------------------------------------------
// ZMK: &sk 1500 ms. The 1000 ms of &sl and the other timers are custom, see
// features/smart.h.
#define ONESHOT_TIMEOUT 1500

// --- Combos --------------------------------------------------------------
#define COMBO_TERM 30
#define COMBO_STRICT_TIMER
#define COMBO_SHOULD_TRIGGER
#define EXTRA_SHORT_COMBOS

// --- Caps word (ZMK smart_word has no idle timeout) ----------------------
#define CAPS_WORD_IDLE_TIMEOUT 0

// --- OS detection --------------------------------------------------------
#define OS_DETECTION_DEBOUNCE 250

// --- Size ----------------------------------------------------------------
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
#define NO_MUSIC_MODE
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
// 16 layers without the two vim layers, 18 with them. QMK defaults to a
// 16-bit layer state, so the vim build has to ask for the wider one.
#ifdef RR_VIM_ENABLE
#    define LAYER_STATE_32BIT
#else
#    define LAYER_STATE_16BIT
#endif
