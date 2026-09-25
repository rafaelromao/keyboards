#include "features/vim.h"
#include "features/macros.h"
#include "features/adaptive.h"

#ifdef RR_VIM_ENABLE

enum vim_mode { VIM_MODE_OFF, VIM_MODE_NORMAL, VIM_MODE_VISUAL, VIM_MODE_INSERT, VIM_MODE_REPLACE, VIM_MODE_CMDLINE };

static struct {
    uint8_t  mode;
    bool     change_pending;   // the sticky CHANGE layer is on
    bool     replace_pending;  // the sticky REPLACE: back to NORMAL after one key
    bool     release_after;    // this press spends a sticky layer
    uint16_t sticky_time;
} vim;

static void set_normal(void) {
    layer_on(_VIM_NORMAL);
    layer_off(_VIM_CHANGE);
    vim.mode            = VIM_MODE_NORMAL;
    vim.change_pending  = false;
    vim.replace_pending = false;
}

// NORMAL off, so the base alpha layer types literally (INSERT, REPLACE and
// CMDLINE are all-transparent layers in ZMK).
static void set_literal(uint8_t mode) {
    layer_off(_VIM_NORMAL);
    vim.mode = mode;
}

static void set_visual(void) {
    layer_on(_VIM_NORMAL);
    vim.mode = VIM_MODE_VISUAL;
}

static void set_replace_pending(void) {
    set_literal(VIM_MODE_REPLACE);
    vim.replace_pending = true;
    vim.sticky_time     = timer_read();
}

static void set_change_pending(void) {
    set_literal(VIM_MODE_INSERT);
    layer_on(_VIM_CHANGE);
    vim.change_pending = true;
    vim.sticky_time    = timer_read();
}

void vim_off(void) {
    layer_off(_VIM_NORMAL);
    layer_off(_VIM_CHANGE);
    vim.mode            = VIM_MODE_OFF;
    vim.change_pending  = false;
    vim.replace_pending = false;
}

// vim_mode_on: nothing while a vim layer is on; otherwise NORMAL plus an Esc
// so the editor agrees (ZMK's legacy entry).
static void vim_on(void) {
    if (vim.mode != VIM_MODE_OFF) return;
    set_normal();
    tap_code(KC_ESC);
}

static bool in_command_layers(void) {
    return vim.mode == VIM_MODE_NORMAL || vim.mode == VIM_MODE_VISUAL || vim.change_pending;
}

// key, then insert mode, then the F24 the ^ key reads as "just went home"
static void key_then_insert(uint16_t key, bool sentinel) {
    execute_keycode(key);
    set_literal(VIM_MODE_INSERT);
    if (sentinel) execute_keycode(KC_F24);
}

// The taps of the NORMAL layer mod-taps and of lt_q_vim. With Ctrl held the
// key passes through (Ctrl+O, Ctrl+A, ...).
void vim_modtap_tap(uint8_t tap) {
    uint8_t mods = get_mods() | get_oneshot_mods();
    if (mods & MOD_MASK_CTRL) {
        if (tap == KC_C) {
            execute_keycode(KC_C);
            set_normal();
        } else {
            execute_keycode(tap);
        }
        return;
    }
    switch (tap) {
        case KC_S:
            key_then_insert(KC_S, false);
            break;
        case KC_R:
            if (mods & MOD_MASK_SHIFT) {
                key_then_insert(KC_R, false);
            } else {
                execute_keycode(KC_R);
                set_replace_pending();
            }
            break;
        case KC_C:
            execute_keycode(KC_C);
            if (mods & MOD_MASK_SHIFT || vim.mode == VIM_MODE_VISUAL) {
                set_literal(VIM_MODE_INSERT);
            } else {
                set_change_pending();
            }
            break;
        case KC_I:
            key_then_insert(KC_I, true);
            break;
        case KC_Q:
            execute_keycode(KC_Q);
            set_replace_pending();
            break;
        default:
            execute_keycode(tap);
    }
}

// The symbol tap-holds that move between modes (lm_*_vim layer morphs):
// : / ? open the command line from the command layers, ! from visual,
// = and ~ end visual mode.
void vim_after_symbol(uint16_t keycode) {
    switch (keycode) {
        case KC_COLN:
        case KC_SLSH:
        case KC_QUES:
            if (in_command_layers()) set_literal(VIM_MODE_CMDLINE);
            break;
        case KC_EXLM:
            if (vim.mode == VIM_MODE_VISUAL) set_literal(VIM_MODE_CMDLINE);
            break;
        case KC_EQL:
        case KC_TILD:
            if (vim.mode == VIM_MODE_VISUAL) set_normal();
            break;
    }
}

bool process_vim_kc(uint16_t keycode, bool pressed) {
    if (keycode < VIM_ON || keycode > VIM_ENT) return false;
    if (!pressed) return true;
    uint8_t mods = get_mods() | get_oneshot_mods();
    switch (keycode) {
        case VIM_ON:
            vim_on();
            break;
        case VIM_OFF:
            vim_off();
            break;
        case VIM_O:
        case VIM_A:
        case VIM_I:
        case VIM_S: {
            uint8_t key = (keycode == VIM_O) ? KC_O : (keycode == VIM_A) ? KC_A : (keycode == VIM_I) ? KC_I : KC_S;
            if (mods & MOD_MASK_CTRL) {
                execute_keycode(key);
            } else {
                key_then_insert(key, keycode != VIM_S);
            }
            break;
        }
        case VIM_R:
            vim_modtap_tap(KC_R);
            break;
        case VIM_C:
            vim_modtap_tap(KC_C);
            break;
        case VIM_Q:
            vim_modtap_tap(KC_Q);
            break;
        case VIM_AT:
            execute_keycode(KC_AT);
            set_replace_pending();
            break;
        case VIM_V:
            execute_keycode(KC_V);
            if (vim.mode == VIM_MODE_VISUAL) {
                set_normal();
            } else {
                set_visual();
            }
            break;
        case VIM_SFT_V:
            execute_keycode(S(KC_V));
            if (vim.mode != VIM_MODE_OFF) set_visual();
            break;
        case VIM_CTL_V:
            execute_keycode(C(KC_V));
            if (vim.mode != VIM_MODE_OFF) set_visual();
            break;
        case VIM_X:
        case VIM_D:
        case VIM_Y:
        case VIM_P: {
            uint8_t key = (keycode == VIM_X) ? KC_X : (keycode == VIM_D) ? KC_D : (keycode == VIM_Y) ? KC_Y : KC_P;
            execute_keycode(key);
            set_normal();
            break;
        }
        case VIM_CE:
        case VIM_CI:
        case VIM_CA: {
            uint8_t key = (keycode == VIM_CE) ? KC_E : (keycode == VIM_CI) ? KC_I : KC_A;
            key_then_insert(key, true);
            break;
        }
        case VIM_SFT_J:
            set_normal();
            execute_keycode(S(KC_J));
            break;
        case VIM_ESC:
            if (vim.mode == VIM_MODE_VISUAL || vim.mode == VIM_MODE_INSERT || vim.mode == VIM_MODE_REPLACE || vim.mode == VIM_MODE_CMDLINE) {
                set_normal();
            }
            execute_keycode(KC_ESC);
            break;
        case VIM_ENT:
            if (vim.mode == VIM_MODE_CMDLINE) set_normal();
            execute_keycode(KC_ENT);
            break;
    }
    return true;
}

// The sticky REPLACE and CHANGE layers are spent by the next key press.
process_record_result_t process_vim(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) return PROCESS_RECORD_CONTINUE;
    bool hold = (IS_QK_MOD_TAP(keycode) || IS_QK_LAYER_TAP(keycode)) && !record->tap.count;
    if (hold || IS_QK_MOMENTARY(keycode) || IS_MODIFIER_KEYCODE(keycode & 0xFF)) return PROCESS_RECORD_CONTINUE;
    vim.release_after = vim.replace_pending || vim.change_pending;
    return PROCESS_RECORD_CONTINUE;
}

void vim_after_press(uint16_t keycode, keyrecord_t *record) {
    if (!vim.release_after) return;
    vim.release_after = false;
    if (vim.replace_pending) set_normal();
    if (vim.change_pending) {
        layer_off(_VIM_CHANGE);
        vim.change_pending = false;
    }
}

void vim_housekeeping(void) {
    if ((vim.replace_pending || vim.change_pending) && timer_elapsed(vim.sticky_time) > VIM_STICKY_TIMEOUT) {
        if (vim.replace_pending) set_normal();
        if (vim.change_pending) {
            layer_off(_VIM_CHANGE);
            vim.change_pending = false;
        }
    }
}

#else  // RR_VIM_ENABLE

// Without vim mode the vim keycodes are just the keys they would type.
bool process_vim_kc(uint16_t keycode, bool pressed) {
    if (keycode < VIM_ON || keycode > VIM_ENT) return false;
    if (!pressed) return true;
    switch (keycode) {
        case VIM_ESC:
            execute_keycode(KC_ESC);
            break;
        case VIM_ENT:
            execute_keycode(KC_ENT);
            break;
        case VIM_SFT_V:
            execute_keycode(S(KC_V));
            break;
        case VIM_CTL_V:
            execute_keycode(C(KC_V));
            break;
    }
    return true;
}

#endif
