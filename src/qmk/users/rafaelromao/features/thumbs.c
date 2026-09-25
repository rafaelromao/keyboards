#include "features/thumbs.h"
#include "features/smart.h"
#include "features/adaptive.h"
#include "features/macros.h"

static bool meh_held(void) {
    uint8_t mods = get_mods();
    return (mods & MOD_MASK_CTRL) && (mods & MOD_MASK_ALT) && (mods & MOD_MASK_SHIFT);
}

// A held or sticky shift. The sentence-case shift does not count: in ZMK
// that is a layer, not a modifier, and the thumbs behave as on the base layer.
static bool shift_active(void) {
    if (smart_sentence_pending()) return get_mods() & MOD_MASK_SHIFT;
    return (get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT;
}

// ak_space: a space, and after . ? ! a one-shot shift for the next letter
static void tap_space(void) {
    bool sentence = adaptive_last_is(KC_DOT) || adaptive_last_is(KC_QUES) || adaptive_last_is(KC_EXLM);
    if (is_caps_word_on() && !smart_caps_line()) caps_word_off();
    execute_keycode(KC_SPC);
    if (sentence) smart_sentence_shift();
}

// L0 tap. Under caps word (CASE_A1 msk_spc) the space also ends num word.
static void l0_tap(void) {
    if (is_caps_word_on() && !smart_caps_line()) {
        caps_word_off();
        smart_num_word_off();
        execute_keycode(KC_SPC);
        return;
    }
    tap_space();
}

// L1 tap: mm_repeat (shifted: caps line) or, right after an accent, the
// alpha2 alternate repeat.
static void l1_tap(void) {
    if (shift_active()) {
        clear_oneshot_mods();
        smart_caps_line_on();
        return;
    }
    if (smart_altrep2_active()) {
        smart_altrep2_clear();
        adaptive_a2_alt_repeat();
        return;
    }
    adaptive_alt_repeat();
}

// R0 tap: one-shot alpha2 (shifted and caps variants are state), or with Meh
// held a sticky right GUI so the chord becomes Hyper.
static void r0_tap(void) {
    if (meh_held()) {
        smart_oneshot_set(MOD_BIT(KC_RGUI));
        return;
    }
    smart_keep_oneshot();
    smart_osl_on(_ALPHA2);
}

// R1 tap: sticky shift; tapped again, caps word; under caps word, cancel.
static void r1_tap(void) {
    if (is_caps_word_on()) {
        smart_cancel();
        return;
    }
    if (shift_active()) {
        clear_oneshot_mods();
        smart_caps_word_on();
        return;
    }
    // Under sentence case this re-arms the same shift, which then lasts the
    // sticky-shift time, as tapping the sticky shift in ZMK would.
    smart_oneshot_set(MOD_BIT(KC_LSFT));
}

void thumbs_magic(void) {
    adaptive_magic();
}

static bool r0_gui_held;
static bool r0_symcp_held;

process_record_result_t process_thumbs(uint16_t keycode, keyrecord_t *record) {
    bool    pressed = record->event.pressed;
    bool    tapped  = record->tap.count > 0;
    uint8_t tap     = QK_LAYER_TAP_GET_TAP_KEYCODE(keycode);

    if (keycode == R0_KEY && !tapped) {
        // msl_sym_a2 hold: RGUI with Meh held (Hyper), SYM_CP under sentence
        // case (lt_sft_a2), otherwise the native SYM.
        if (pressed) {
            if (meh_held()) {
                register_mods(MOD_BIT(KC_RGUI));
                r0_gui_held = true;
                return PROCESS_RECORD_RETURN_FALSE;
            }
            if (smart_sentence_pending()) {
                layer_on(_SYM_CP);
                r0_symcp_held = true;
                return PROCESS_RECORD_RETURN_FALSE;
            }
            return PROCESS_RECORD_CONTINUE;
        }
        if (r0_gui_held) {
            unregister_mods(MOD_BIT(KC_RGUI));
            r0_gui_held = false;
            return PROCESS_RECORD_RETURN_FALSE;
        }
        if (r0_symcp_held) {
            layer_off(_SYM_CP);
            r0_symcp_held = false;
            return PROCESS_RECORD_RETURN_FALSE;
        }
        return PROCESS_RECORD_CONTINUE;
    }

    if (!tapped) return PROCESS_RECORD_CONTINUE;
    if (!pressed) return PROCESS_RECORD_RETURN_FALSE;

    switch (tap) {
        case ID_SPC_NUM:
            l0_tap();
            break;
        case ID_REP:
            l1_tap();
            break;
        case ID_A2:
            r0_tap();
            break;
        case ID_SHIFT:
            r1_tap();
            break;
    }
    return PROCESS_RECORD_RETURN_FALSE;
}
