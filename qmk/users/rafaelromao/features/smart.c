#include "features/smart.h"
#include "features/taphold.h"
#include "features/adaptive.h"
#include "features/vim.h"

static struct {
    uint8_t  osl_layer;  // 0 = none (layer 0 is never a one-shot)
    uint16_t osl_time;
    bool     caps_line;
    bool     sentence_shift;
    uint16_t sentence_time;
    bool     altrep2;
    uint16_t altrep2_time;
    uint8_t  num_word_layer;  // 0 = off
    bool     oneshot_set;
    // Layers spent by the key being pressed. They are turned off only after
    // the key is processed: QMK resolves a plain key against the layer state
    // again in process_action, after process_record_user, so switching the
    // layer off early would type the key underneath.
    bool osl_release;
    bool num_word_release;
} st;

// --- one-shot layers ---------------------------------------------------------

void smart_osl_on(uint8_t layer) {
    if (st.osl_layer && st.osl_layer != layer) layer_off(st.osl_layer);
    layer_on(layer);
    st.osl_layer   = layer;
    st.osl_time    = timer_read();
    st.osl_release = false;
}

void smart_osl_off(void) {
    if (st.osl_layer) layer_off(st.osl_layer);
    st.osl_layer = 0;
}

uint8_t smart_osl_layer(void) {
    return st.osl_layer;
}

// --- caps word / caps line -----------------------------------------------------

void smart_caps_word_on(void) {
    st.caps_line = false;
    caps_word_on();
}

void smart_caps_line_on(void) {
    st.caps_line = true;
    caps_word_on();
}

bool smart_caps_line(void) {
    return st.caps_line;
}

// ZMK smart_word continue-list: _ - , backspace delete ' ~ ^ ` left right,
// plus every letter (ignore-alphas) and every modifier (ignore-modifiers).
// smart_line adds the space.
bool smart_caps_continues(uint16_t keycode) {
    switch (keycode) {
        case KC_A ... KC_Z:
        case KC_UNDS:
        case KC_MINS:
        case KC_COMM:
        case KC_BSPC:
        case KC_DEL:
        case KC_QUOT:
        case KC_TILD:
        case KC_CIRC:
        case KC_GRV:
        case KC_LEFT:
        case KC_RGHT:
        case KC_LCTL ... KC_RGUI:
            return true;
        case KC_SPC:
            return st.caps_line;
    }
    return false;
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));
            return true;
    }
    return smart_caps_continues(keycode);
}

void caps_word_set_user(bool active) {
    if (!active) st.caps_line = false;
}

// --- num word ----------------------------------------------------------------------

void smart_num_word_on(uint8_t layer) {
    vim_off();
    layer_on(layer);
    st.num_word_layer   = layer;
    st.num_word_release = false;
}

void smart_num_word_off(void) {
    if (st.num_word_layer) layer_off(st.num_word_layer);
    st.num_word_layer = 0;
}

// ZMK smart_num continue-list (ignore-numbers, then the list).
static bool num_word_continues(uint16_t keycode) {
    switch (keycode) {
        case KC_1 ... KC_0:
        case KC_KP_1 ... KC_KP_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_DOT:
        case KC_COMM:
        case KC_PLUS:
        case KC_MINS:
        case KC_ASTR:
        case KC_SLSH:
        case KC_EQL:
        case KC_AMPR:
        case KC_PIPE:
        case KC_HASH:
        case KC_TILD:
        case KC_CIRC:
        case KC_LEFT:
        case KC_RGHT:
        case KC_HOME:
        case KC_END:
        case KC_LCBR:
        case KC_RCBR:
        case KC_BSLS:
        case KC_DLR:
        case KC_AT:
        case KC_LPRN:
        case KC_RPRN:
        case KC_DQUO:
        case KC_QUOT:
        case KC_LBRC:
        case KC_RBRC:
        case KC_QUES:
        case KC_GRV:
            return true;
    }
    return false;
}

// --- sentence case ---------------------------------------------------------------

void smart_sentence_shift(void) {
    smart_oneshot_set(MOD_BIT(KC_LSFT));
    st.sentence_shift = true;
    st.sentence_time  = timer_read();
}

bool smart_sentence_pending(void) {
    return st.sentence_shift && (get_oneshot_mods() & MOD_MASK_SHIFT);
}

// --- alt rep 2 --------------------------------------------------------------------

void smart_altrep2_arm(void) {
    st.altrep2      = true;
    st.altrep2_time = timer_read();
}

bool smart_altrep2_active(void) {
    return st.altrep2;
}

void smart_altrep2_clear(void) {
    st.altrep2 = false;
}

// --- one-shot mods ----------------------------------------------------------------

void smart_oneshot_set(uint8_t mods) {
    set_oneshot_mods(mods);
    st.oneshot_set = true;
}

void smart_keep_oneshot(void) {
    if (get_oneshot_mods()) st.oneshot_set = true;
}

// --- cancel -----------------------------------------------------------------------

void smart_cancel(void) {
    tap_code(KC_CNCL);
    vim_off();
    smart_num_word_off();
    smart_osl_off();
    layer_off(_NUM);
    layer_off(_NUM_CP);
    layer_off(_ALPHA2);
    layer_off(_CCEDIL);
#ifdef RR_MEHS_ENABLE
    layer_off(_MEHS);
#endif
    caps_word_off();
    st.caps_line      = false;
    st.sentence_shift = false;
    st.altrep2        = false;
}

// --- hooks --------------------------------------------------------------------------

// The key a press stands for, as the ZMK auto-layers would have seen it: the
// symbol of a th_* key, the digit of MC_N*, the tap of a mod/layer-tap.
// KC_NO for holds and for keys that produce no keycode.
static uint16_t logical_keycode(uint16_t keycode, keyrecord_t *record) {
    if (IS_TH(keycode)) return record->tap.count ? taphold_tap_keycode(keycode) : KC_NO;
    if (keycode >= MC_N0 && keycode <= MC_N9) return KC_1 + ((keycode - MC_N0 + 9) % 10);
    if (IS_QK_MOD_TAP(keycode) || IS_QK_LAYER_TAP(keycode)) {
        if (!record->tap.count) return KC_NO;
        uint8_t tap = IS_QK_MOD_TAP(keycode) ? QK_MOD_TAP_GET_TAP_KEYCODE(keycode) : QK_LAYER_TAP_GET_TAP_KEYCODE(keycode);
        return tap >= KC_INT1 ? KC_NO : tap;
    }
    if (IS_QK_MOMENTARY(keycode) || IS_QK_TOGGLE_LAYER(keycode) || IS_QK_ONE_SHOT_MOD(keycode)) return KC_NO;
    if (keycode >= SAFE_RANGE) return keycode;
    return keycode;
}

static bool is_modifier_press(uint16_t keycode, keyrecord_t *record) {
    if (IS_MODIFIER_KEYCODE(keycode & 0xFF) && keycode < QK_MODS_MAX) return true;
    if ((IS_QK_MOD_TAP(keycode) || IS_QK_LAYER_TAP(keycode)) && !record->tap.count) return true;
    return IS_QK_MOMENTARY(keycode) || IS_QK_ONE_SHOT_MOD(keycode);
}

void smart_before_press(uint16_t keycode, keyrecord_t *record) {
    st.oneshot_set = false;
    if (is_modifier_press(keycode, record)) return;

    // ZMK &sl quick-release: the layer goes on the next key press, once that
    // key has been resolved on it (see smart_after_press).
    if (st.osl_layer) st.osl_release = true;

    // The ALT REP 2 window is read by the L1 tap and cleared by anything else.
    if (st.altrep2 && keycode != L1_KEY) st.altrep2 = false;

    if (st.num_word_layer) {
        uint16_t logical = logical_keycode(keycode, record);
        if (logical != KC_NO && !num_word_continues(logical)) st.num_word_release = true;
    }
}

// Runs once the press is through: releases the layers it spent, and the
// one-shot mods. ZMK sticky keys with quick-release are spent by the next key
// press, while QMK keeps one-shot mods until that key is released, which
// would also shift a rolled second key.
void smart_after_press(uint16_t keycode, keyrecord_t *record, bool intercepted) {
    if (st.osl_release) {
        st.osl_release = false;
        smart_osl_off();
    }
    if (st.num_word_release) {
        st.num_word_release = false;
        smart_num_word_off();
    }
    if (st.oneshot_set || is_modifier_press(keycode, record)) return;
    if (get_oneshot_mods()) {
        clear_oneshot_mods();
        st.sentence_shift = false;
    }
}

void smart_housekeeping(void) {
    if (st.osl_layer && timer_elapsed(st.osl_time) > OSL_TIMEOUT) smart_osl_off();
    if (st.altrep2 && timer_elapsed(st.altrep2_time) > ALTREP2_TIMEOUT) st.altrep2 = false;
    if (st.sentence_shift && timer_elapsed(st.sentence_time) > SENTENCE_TIMEOUT) {
        st.sentence_shift = false;
        if (get_oneshot_mods() & MOD_MASK_SHIFT) clear_oneshot_mods();
    }
}

bool process_smart(uint16_t keycode, bool pressed) {
    switch (keycode) {
        case MC_CANCEL:
            if (pressed) smart_cancel();
            return true;
        case MC_NUMWORD:
            if (pressed) smart_num_word_on(_NUM);
            return true;
        case MC_NUMWORD_CP:
            if (pressed) smart_num_word_on(_NUM_CP);
            return true;
        case OSL_A2:
            if (pressed) {
                smart_keep_oneshot();
                smart_osl_on(_ALPHA2);
            }
            return true;
    }
    return false;
}
