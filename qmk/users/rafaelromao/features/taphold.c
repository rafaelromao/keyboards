#include "features/taphold.h"
#include "features/macros.h"
#include "features/smart.h"
#include "features/adaptive.h"
#include "features/thumbs.h"
#include "features/vim.h"

// ---------------------------------------------------------------------------
// The th_* table
//
// An action is a keycode (tapped with execute_keycode) or SEQ(n), a sequence
// from macros.c. The hold action can be SAME (the tap action again) and is
// preceded by the prefix: ZMK's "hold = append at the end of the line" idiom.
// ---------------------------------------------------------------------------
#define SEQ(n) (0x8000 | (n))
#define SAME 0xFFFF

enum { PFX_NONE, PFX_END, PFX_RIGHT, PFX_END_SPC, PFX_RIGHT_SPC, PFX_HOME };

typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint8_t  prefix;
} taphold_t;

// clang-format off
static const taphold_t taphold_table[TH_COUNT] PROGMEM = {
    [TH_SEMI]       = {KC_SCLN,                  SAME,                        PFX_END},
    [TH_COMMA]      = {KC_COMM,                  SAME,                        PFX_RIGHT},
    [TH_DOT]        = {KC_DOT,                   SAME,                        PFX_RIGHT},
    [TH_SQO]        = {SEQ(SEQ_SQO),             SAME,                        PFX_END},
    [TH_DQO]        = {SEQ(SEQ_DQO),             SAME,                        PFX_END},
    [TH_BTI]        = {SEQ(SEQ_BTI),             SAME,                        PFX_END},
    [TH_AND]        = {SEQ(SEQ_AND),             SAME,                        PFX_RIGHT_SPC},
    [TH_OR]         = {SEQ(SEQ_OR),              SAME,                        PFX_RIGHT_SPC},
    [TH_LBRC]       = {KC_LCBR,                  SAME,                        PFX_END_SPC},
    [TH_RBRC]       = {KC_RCBR,                  SAME,                        PFX_END_SPC},
    [TH_BRACES]     = {SEQ(SEQ_BRACES),          SAME,                        PFX_END},
    [TH_LPAR]       = {KC_LPRN,                  SAME,                        PFX_END},
    [TH_RPAR]       = {KC_RPRN,                  SAME,                        PFX_END},
    [TH_PARS]       = {SEQ(SEQ_PARS),            SAME,                        PFX_END},
    [TH_LBKT]       = {KC_LBRC,                  SAME,                        PFX_RIGHT},
    [TH_RBKT]       = {KC_RBRC,                  SAME,                        PFX_RIGHT},
    [TH_BRACKETS]   = {SEQ(SEQ_BRACKETS),        SAME,                        PFX_END},
    [TH_US]         = {SEQ(SEQ_US),              SEQ(SEQ_USD),                PFX_NONE},
    [TH_BR]         = {SEQ(SEQ_BR),              SEQ(SEQ_BRL),                PFX_NONE},
    [TH_EUR]        = {LSA(KC_2),                SEQ(SEQ_EUR),                PFX_NONE},
    [TH_BSLASH_QUO] = {SEQ(SEQ_BSLASH_DQO),      SEQ(SEQ_BSLASH_SQO),         PFX_NONE},
    [TH_PARS_SEMI]  = {SEQ(SEQ_END_PARS_SEMI),   SEQ(SEQ_END_PARS_SEMI_ENT),  PFX_NONE},
    [TH_TDQO]       = {SEQ(SEQ_TDQO),            SEQ(SEQ_TDQO_ENT),           PFX_NONE},
    [TH_TBTI]       = {SEQ(SEQ_TBTI),            SEQ(SEQ_TBTI_ENT),           PFX_NONE},
    [TH_SARROW]     = {SEQ(SEQ_SARROW),          SAME,                        PFX_RIGHT_SPC},
    [TH_DARROW]     = {SEQ(SEQ_DARROW),          SAME,                        PFX_RIGHT_SPC},
    [TH_FORWARD]    = {SEQ(SEQ_FORWARD),         SEQ(SEQ_ENT_FORWARD),        PFX_END_SPC},
    [TH_BACKWARD]   = {SEQ(SEQ_BACKWARD),        SEQ(SEQ_ENT_FORWARD),        PFX_RIGHT},
    [TH_CONCAT]     = {SEQ(SEQ_CONCAT),          SAME,                        PFX_RIGHT_SPC},
    [TH_DCOLON]     = {SEQ(SEQ_DCOLON),          SAME,                        PFX_RIGHT_SPC},
    [TH_PERC]       = {KC_PERC,                  SAME,                        PFX_END_SPC},
    [TH_LT]         = {KC_LT,                    SAME,                        PFX_RIGHT_SPC},
    [TH_GT]         = {KC_GT,                    SAME,                        PFX_RIGHT_SPC},
    [TH_PLUS]       = {KC_PLUS,                  SAME,                        PFX_RIGHT_SPC},
    [TH_MINUS]      = {KC_MINS,                  SAME,                        PFX_RIGHT_SPC},
    [TH_STAR]       = {KC_ASTR,                  SAME,                        PFX_RIGHT_SPC},
    [TH_QMARK]      = {KC_QUES,                  SAME,                        PFX_END},
    [TH_EQEQ]       = {SEQ(SEQ_EQEQ),            SAME,                        PFX_RIGHT_SPC},
    [TH_NOTEQ]      = {SEQ(SEQ_NOTEQ),           SAME,                        PFX_RIGHT_SPC},
    [TH_ORD_O_A]    = {LALT(KC_0),               LALT(KC_9),                  PFX_NONE},
    [TH_LTGTLPRP]   = {SEQ(SEQ_END_LTGTLPRP),    SEQ(SEQ_END_LTGTLPRP_ENT),   PFX_NONE},
    [TH_SLASH]      = {KC_SLSH,                  SAME,                        PFX_RIGHT_SPC},
    [TH_COLON]      = {KC_COLN,                  SAME,                        PFX_END},
    [TH_EXCL]       = {KC_EXLM,                  SAME,                        PFX_END},
    [TH_EQL]        = {KC_EQL,                   SAME,                        PFX_END_SPC},
    [TH_CARET_Z]    = {SEQ(SEQ_CARET),           KC_0,                        PFX_NONE},
    [TH_END_ENT]    = {VIM_ENT,                  SAME,                        PFX_END},
    [TH_COPY]       = {MC_COPY,                  MC_SHIFT_COPY,               PFX_NONE},
    [TH_SELCOPY]    = {MC_SELCOPY,               MC_SHIFT_SELCOPY,            PFX_NONE},
    [TH_PASTE]      = {MC_PASTE,                 MC_SHIFT_PASTE,              PFX_NONE},
    [TH_SELPASTE]   = {MC_SELPASTE,              MC_SHIFT_SELPASTE,           PFX_NONE},
    [TH_HOME_TAB]   = {KC_TAB,                   SAME,                        PFX_HOME},
    [TH_SHIFT_TAB]  = {KC_TAB,                   S(KC_TAB),                   PFX_NONE},
    [TH_VOL]        = {KC_VOLD,                  KC_MUTE,                     PFX_NONE},
};
// clang-format on

static void run_action(uint16_t action) {
    if (action & 0x8000) {
        seq_play(action & 0xFF);
    } else {
        execute_keycode(action);
    }
}

static void run_prefix(uint8_t prefix) {
    switch (prefix) {
        case PFX_END:
            tap_code(KC_END);
            break;
        case PFX_RIGHT:
            tap_code(KC_RGHT);
            break;
        case PFX_END_SPC:
            tap_code(KC_END);
            tap_code(KC_SPC);
            break;
        case PFX_RIGHT_SPC:
            tap_code(KC_RGHT);
            tap_code(KC_SPC);
            break;
        case PFX_HOME:
            tap_code(KC_HOME);
            break;
    }
}

uint16_t taphold_tap_keycode(uint16_t keycode) {
    if (!IS_TH(keycode)) return keycode;
    uint16_t tap = pgm_read_word(&taphold_table[TH_INDEX(keycode)].tap);
    return (tap & 0x8000) ? KC_NO : tap;
}

// Runs before a th_* key types a plain symbol. The intercept returns false,
// so nothing after process_record_user (caps word, one-shot handling) sees
// the key; this does the part of that which ZMK's auto-layer would have done.
// Sequences apply the same rule key by key in seq_play().
static void before_action(uint16_t action) {
    if ((action & 0x8000) == 0 && is_caps_word_on() && !smart_caps_continues(action)) {
        caps_word_off();
    }
}

static void taphold_tap(uint8_t idx) {
    uint16_t tap    = pgm_read_word(&taphold_table[idx].tap);
    uint16_t symbol = (tap & 0x8000) ? KC_NO : tap;
    switch (idx) {
        case TH_DOT:
            // mm_dot_meh: with shift held, Meh + . (comma/dot Meh chords carry
            // no OS override, by decision); otherwise a plain dot.
            if ((get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT) {
                clear_oneshot_mods();
                tap_code16(MEH(KC_DOT));
                adaptive_track(KC_DOT);
                return;
            }
            break;
        case TH_CARET_Z:
            // vim_home: 0 when the previous key was the F24 that the ^ key
            // itself (and the vim insert transitions) leave behind, else ^.
            if (adaptive_last_is(KC_F24)) {
                execute_keycode(KC_0);
                return;
            }
            break;
    }
    before_action(tap);
    run_action(tap);
    vim_after_symbol(symbol);
}

static void taphold_hold(uint8_t idx) {
    uint16_t hold = pgm_read_word(&taphold_table[idx].hold);
    if (hold == SAME) hold = pgm_read_word(&taphold_table[idx].tap);
    before_action(hold);
    run_prefix(pgm_read_byte(&taphold_table[idx].prefix));
    run_action(hold);
}

// ---------------------------------------------------------------------------
// Per-key tap-hold settings
// ---------------------------------------------------------------------------
static bool is_thumb(uint16_t keycode) {
    switch (keycode) {
        case L0_KEY:
        case L1_KEY:
        case R0_KEY:
        case R1_KEY:
        case MAGIC_KEY:
            return true;
    }
    return false;
}

// ZMK hold-preferred keys: hlt, hsk, the COMBO_MUST_TAP chords.
static bool is_hold_preferred(uint16_t keycode) {
    switch (keycode) {
        case HLT_SYM_SPC:
        case HLT_NUMCP_SPC:
        case HLT_SYMCP_SPC:
        case HT_W:
        case HT_Q:
        case HT_Z:
        case HT_Y:
        case HT_MEH_SPC:
        case HT_MEH_ENT:
        case TH_HYPER_SPC:
        case TH_HYPER_ENT:
            return true;
    }
    return IS_QK_MOD_TAP(keycode) && QK_MOD_TAP_GET_TAP_KEYCODE(keycode) == ID_STICKY;
}

// The mod-taps whose tap changes meaning by layer (Meh chords on MEHS, vim
// transitions on VIM NORMAL). Combo events carry no position.
static uint8_t source_layer(keyrecord_t *record) {
    if (IS_COMBOEVENT(record->event)) return _ALPHA1;
    return layer_switch_get_layer(record->event.key);
}

static bool is_prior_idle_key(uint16_t keycode, keyrecord_t *record) {
    if (IS_TH(keycode)) return true;
    if (!IS_QK_MOD_TAP(keycode)) return false;
    uint8_t layer = source_layer(record);
#ifdef RR_MEHS_ENABLE
    if (layer == _MEHS) return true;
#endif
#ifdef RR_VIM_ENABLE
    if (layer == _VIM_NORMAL) return true;
#endif
    return false;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    return is_thumb(keycode) ? 175 : TAPPING_TERM;
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    return is_thumb(keycode) ? 0 : QUICK_TAP_TERM;
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    return is_hold_preferred(keycode);
}

// ZMK's require-prior-idle counts any preceding key press, so every key is a
// flow-tap key and the term decides which tap-holds it applies to.
bool is_flow_tap_key(uint16_t keycode) {
    return true;
}

uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t *record, uint16_t prev_keycode) {
    return is_prior_idle_key(keycode, record) ? FLOW_TAP_TERM : 0;
}

// ---------------------------------------------------------------------------
// Interception
// ---------------------------------------------------------------------------
static uint8_t modtap_mods(uint16_t keycode) {
    uint8_t mods = QK_MOD_TAP_GET_MODS(keycode);
    return (mods & 0x10) ? ((mods & 0x0F) << 4) : (mods & 0x0F);
}

process_record_result_t process_taphold(uint16_t keycode, keyrecord_t *record) {
    bool pressed = record->event.pressed;
    bool tapped  = record->tap.count > 0;

    // th_* symbol keys: tap and hold both intercepted
    if (IS_TH(keycode)) {
        if (pressed) {
            if (tapped) {
                taphold_tap(TH_INDEX(keycode));
            } else {
                taphold_hold(TH_INDEX(keycode));
            }
        }
        return PROCESS_RECORD_RETURN_FALSE;
    }

    // th_hyper_space / th_hyper_enter: tap intercepted, hold is a real Hyper
    if (keycode == TH_HYPER_SPC || keycode == TH_HYPER_ENT) {
        if (!tapped) return PROCESS_RECORD_CONTINUE;
        if (pressed) execute_keycode(HYPR(QK_MOD_TAP_GET_TAP_KEYCODE(keycode)));
        return PROCESS_RECORD_RETURN_FALSE;
    }

    // ht_meh_spc / ht_meh_ent: tap Meh + key, hold is a real Meh
    if (keycode == HT_MEH_SPC || keycode == HT_MEH_ENT) {
        if (!tapped) return PROCESS_RECORD_CONTINUE;
        if (pressed) execute_keycode(MEH(QK_MOD_TAP_GET_TAP_KEYCODE(keycode)));
        return PROCESS_RECORD_RETURN_FALSE;
    }

    if (IS_QK_MOD_TAP(keycode)) {
        uint8_t tap = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);

        // Layer-dependent taps of otherwise native mod-taps
        if (tapped && tap < KC_INT1) {
            uint8_t layer = source_layer(record);
#ifdef RR_MEHS_ENABLE
            if (layer == _MEHS) {
                if (pressed) execute_keycode(MEH(tap));
                return PROCESS_RECORD_RETURN_FALSE;
            }
#endif
#ifdef RR_VIM_ENABLE
            if (layer == _VIM_NORMAL) {
                if (pressed) vim_modtap_tap(tap);
                return PROCESS_RECORD_RETURN_FALSE;
            }
#endif
            return PROCESS_RECORD_CONTINUE;
        }

        switch (tap) {
            case ID_STICKY:  // hsk: tap = one-shot mod
                if (!tapped) return PROCESS_RECORD_CONTINUE;
                if (pressed) smart_oneshot_set(modtap_mods(keycode));
                return PROCESS_RECORD_RETURN_FALSE;
            case ID_MOD_NUM:  // mod_num: tap = one-shot mod + one-shot NUM_CP
                if (!tapped) return PROCESS_RECORD_CONTINUE;
                if (pressed) {
                    smart_oneshot_set(modtap_mods(keycode));
                    smart_osl_on(_NUM_CP);
                }
                return PROCESS_RECORD_RETURN_FALSE;
            case ID_MAGIC:
                if (!tapped) return PROCESS_RECORD_CONTINUE;
                if (pressed) thumbs_magic();
                return PROCESS_RECORD_RETURN_FALSE;
        }
        return PROCESS_RECORD_CONTINUE;
    }

    if (IS_QK_LAYER_TAP(keycode)) {
        uint8_t tap = QK_LAYER_TAP_GET_TAP_KEYCODE(keycode);
        if (tap < KC_INT1) {
#ifdef RR_VIM_ENABLE
            // lt_q_vim: q + sticky replace, on the vim normal layer only
            if (keycode == VLT_Q && tapped && source_layer(record) == _VIM_NORMAL) {
                if (pressed) vim_modtap_tap(KC_Q);
                return PROCESS_RECORD_RETURN_FALSE;
            }
#endif
            return PROCESS_RECORD_CONTINUE;
        }
        switch (tap) {
            case ID_SPC_NUM:
            case ID_REP:
            case ID_A2:
            case ID_SHIFT:
                return process_thumbs(keycode, record);
            case ID_EMOJI:
            case ID_ZOOM_OUT:
            case ID_CAM:
            case ID_SYSTEM:
            case ID_N0:
                if (!tapped) return PROCESS_RECORD_CONTINUE;
                if (pressed) {
                    switch (tap) {
                        case ID_EMOJI:    execute_keycode(MC_EMOJI); break;
                        case ID_ZOOM_OUT: execute_keycode(MC_ZOOM_OUT); break;
                        case ID_CAM:      execute_keycode(MC_CAM); break;
                        case ID_SYSTEM:   execute_keycode(MC_SYSTEM); break;
                        case ID_N0:       execute_keycode(MC_N0); break;
                    }
                }
                return PROCESS_RECORD_RETURN_FALSE;
        }
    }

    return PROCESS_RECORD_CONTINUE;
}
