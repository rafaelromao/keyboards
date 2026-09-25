#include "features/macros.h"
#include "features/adaptive.h"
#include "features/smart.h"
#include "features/vim.h"

// clang-format off
static const uint16_t seq_sqo[]               PROGMEM = {KC_QUOT, KC_SPC, 0};
static const uint16_t seq_dqo[]               PROGMEM = {KC_DQUO, KC_SPC, 0};
static const uint16_t seq_bti[]               PROGMEM = {KC_GRV, KC_SPC, 0};
static const uint16_t seq_tilde[]             PROGMEM = {KC_TILD, KC_SPC, 0};
static const uint16_t seq_and[]               PROGMEM = {KC_AMPR, KC_AMPR, 0};
static const uint16_t seq_or[]                PROGMEM = {KC_PIPE, KC_PIPE, 0};
static const uint16_t seq_braces[]            PROGMEM = {KC_LCBR, KC_RCBR, 0};
static const uint16_t seq_pars[]              PROGMEM = {KC_LPRN, KC_RPRN, 0};
static const uint16_t seq_brackets[]          PROGMEM = {KC_LBRC, KC_RBRC, 0};
static const uint16_t seq_us[]                PROGMEM = {S(KC_U), S(KC_S), KC_DLR, 0};
static const uint16_t seq_usd[]               PROGMEM = {S(KC_U), S(KC_S), S(KC_D), 0};
static const uint16_t seq_br[]                PROGMEM = {S(KC_R), KC_DLR, 0};
static const uint16_t seq_brl[]               PROGMEM = {S(KC_B), S(KC_R), S(KC_L), 0};
static const uint16_t seq_eur[]               PROGMEM = {S(KC_E), S(KC_U), S(KC_R), 0};
static const uint16_t seq_bslash_dqo[]        PROGMEM = {KC_BSLS, KC_DQUO, KC_SPC, 0};
static const uint16_t seq_bslash_sqo[]        PROGMEM = {KC_BSLS, KC_QUOT, KC_SPC, 0};
static const uint16_t seq_end_pars_semi[]     PROGMEM = {KC_END, KC_LPRN, KC_RPRN, KC_SCLN, 0};
static const uint16_t seq_end_pars_semi_ent[] PROGMEM = {KC_END, KC_LPRN, KC_RPRN, KC_SCLN, KC_ENT, 0};
static const uint16_t seq_tdqo[]              PROGMEM = {KC_DQUO, KC_SPC, KC_DQUO, KC_SPC, KC_DQUO, KC_SPC, 0};
static const uint16_t seq_tdqo_ent[]          PROGMEM = {KC_DQUO, KC_SPC, KC_DQUO, KC_SPC, KC_DQUO, KC_SPC, KC_ENT, 0};
static const uint16_t seq_tbti[]              PROGMEM = {KC_GRV, KC_SPC, KC_GRV, KC_SPC, KC_GRV, KC_SPC, 0};
static const uint16_t seq_tbti_ent[]          PROGMEM = {KC_GRV, KC_SPC, KC_GRV, KC_SPC, KC_GRV, KC_SPC, KC_ENT, 0};
static const uint16_t seq_sarrow[]            PROGMEM = {KC_MINS, KC_GT, 0};
static const uint16_t seq_darrow[]            PROGMEM = {KC_EQL, KC_GT, 0};
static const uint16_t seq_forward[]           PROGMEM = {KC_PIPE, KC_GT, 0};
static const uint16_t seq_ent_forward[]       PROGMEM = {KC_ENT, KC_PIPE, KC_GT, 0};
static const uint16_t seq_backward[]          PROGMEM = {KC_LT, KC_MINS, 0};
static const uint16_t seq_concat[]            PROGMEM = {KC_LT, KC_GT, 0};
static const uint16_t seq_dcolon[]            PROGMEM = {KC_COLN, KC_COLN, 0};
static const uint16_t seq_eqeq[]              PROGMEM = {KC_EQL, KC_EQL, 0};
static const uint16_t seq_noteq[]             PROGMEM = {KC_EXLM, KC_EQL, 0};
static const uint16_t seq_end_ltgtlprp[]      PROGMEM = {KC_END, KC_LT, KC_GT, KC_LPRN, KC_RPRN, KC_SCLN, 0};
static const uint16_t seq_end_ltgtlprp_ent[]  PROGMEM = {KC_END, KC_LT, KC_GT, KC_LPRN, KC_RPRN, KC_SCLN, KC_ENT, 0};
static const uint16_t seq_caret[]             PROGMEM = {KC_CIRC, KC_SPC, KC_F24, 0};
static const uint16_t seq_dcurly[]            PROGMEM = {KC_DLR, KC_LCBR, 0};
static const uint16_t seq_hcurly[]            PROGMEM = {KC_HASH, KC_LCBR, 0};
static const uint16_t seq_pcurly[]            PROGMEM = {KC_PERC, KC_LCBR, 0};
static const uint16_t seq_braces_new[]        PROGMEM = {KC_END, KC_SPC, KC_LCBR, KC_ENT, 0};
static const uint16_t seq_end_do_ent[]        PROGMEM = {KC_END, KC_SPC, KC_D, KC_O, KC_ENT, 0};
static const uint16_t seq_deg[]               PROGMEM = {LSA(KC_8), 0};
static const uint16_t seq_at_at[]             PROGMEM = {KC_AT, KC_AT, 0};
static const uint16_t seq_tisl[]              PROGMEM = {KC_TILD, KC_SPC, KC_SLSH, 0};
static const uint16_t seq_ds[]                PROGMEM = {KC_DOT, KC_SLSH, 0};
static const uint16_t seq_dds[]               PROGMEM = {KC_DOT, KC_DOT, KC_SLSH, 0};
static const uint16_t seq_exit[]              PROGMEM = {KC_E, KC_X, KC_I, KC_T, KC_ENT, 0};
static const uint16_t seq_hugs[]              PROGMEM = {KC_LBRC, KC_RBRC, KC_QUOT, KC_S, 0};
static const uint16_t seq_oref[]              PROGMEM = {KC_LBRC, KC_LBRC, 0};
static const uint16_t seq_otask[]             PROGMEM = {KC_MINS, KC_SPC, KC_LBRC, KC_SPC, KC_RBRC, KC_SPC, 0};
static const uint16_t seq_haha[]              PROGMEM = {KC_H, KC_A, KC_H, KC_A, KC_ENT, 0};
static const uint16_t seq_colpercsslash[]     PROGMEM = {KC_COLN, KC_PERC, KC_S, KC_SLSH, 0};
static const uint16_t seq_o_esc[]             PROGMEM = {KC_O, KC_ESC, 0};
static const uint16_t seq_sft_o_esc[]         PROGMEM = {S(KC_O), KC_ESC, 0};
static const uint16_t seq_dqt0p[]             PROGMEM = {KC_DQUO, KC_SPC, KC_0, KC_P, 0};
static const uint16_t seq_dqt1p[]             PROGMEM = {KC_DQUO, KC_SPC, KC_1, KC_P, 0};
static const uint16_t seq_dqtplusp[]          PROGMEM = {KC_DQUO, KC_SPC, KC_PLUS, KC_P, 0};
static const uint16_t seq_dqtplusy[]          PROGMEM = {KC_DQUO, KC_SPC, KC_PLUS, KC_Y, 0};
static const uint16_t seq_macos[]             PROGMEM = {S(KC_M), KC_A, KC_C, S(KC_O), S(KC_S), 0};
static const uint16_t seq_omarchy[]           PROGMEM = {S(KC_O), KC_M, KC_A, KC_R, KC_C, KC_H, KC_Y, 0};

static const uint16_t *const seqs[SEQ_COUNT] PROGMEM = {
    [SEQ_SQO] = seq_sqo,
    [SEQ_DQO] = seq_dqo,
    [SEQ_BTI] = seq_bti,
    [SEQ_TILDE] = seq_tilde,
    [SEQ_AND] = seq_and,
    [SEQ_OR] = seq_or,
    [SEQ_BRACES] = seq_braces,
    [SEQ_PARS] = seq_pars,
    [SEQ_BRACKETS] = seq_brackets,
    [SEQ_US] = seq_us,
    [SEQ_USD] = seq_usd,
    [SEQ_BR] = seq_br,
    [SEQ_BRL] = seq_brl,
    [SEQ_EUR] = seq_eur,
    [SEQ_BSLASH_DQO] = seq_bslash_dqo,
    [SEQ_BSLASH_SQO] = seq_bslash_sqo,
    [SEQ_END_PARS_SEMI] = seq_end_pars_semi,
    [SEQ_END_PARS_SEMI_ENT] = seq_end_pars_semi_ent,
    [SEQ_TDQO] = seq_tdqo,
    [SEQ_TDQO_ENT] = seq_tdqo_ent,
    [SEQ_TBTI] = seq_tbti,
    [SEQ_TBTI_ENT] = seq_tbti_ent,
    [SEQ_SARROW] = seq_sarrow,
    [SEQ_DARROW] = seq_darrow,
    [SEQ_FORWARD] = seq_forward,
    [SEQ_ENT_FORWARD] = seq_ent_forward,
    [SEQ_BACKWARD] = seq_backward,
    [SEQ_CONCAT] = seq_concat,
    [SEQ_DCOLON] = seq_dcolon,
    [SEQ_EQEQ] = seq_eqeq,
    [SEQ_NOTEQ] = seq_noteq,
    [SEQ_END_LTGTLPRP] = seq_end_ltgtlprp,
    [SEQ_END_LTGTLPRP_ENT] = seq_end_ltgtlprp_ent,
    [SEQ_CARET] = seq_caret,
    [SEQ_DCURLY] = seq_dcurly,
    [SEQ_HCURLY] = seq_hcurly,
    [SEQ_PCURLY] = seq_pcurly,
    [SEQ_BRACES_NEW] = seq_braces_new,
    [SEQ_END_DO_ENT] = seq_end_do_ent,
    [SEQ_DEG] = seq_deg,
    [SEQ_AT_AT] = seq_at_at,
    [SEQ_TISL] = seq_tisl,
    [SEQ_DS] = seq_ds,
    [SEQ_DDS] = seq_dds,
    [SEQ_EXIT] = seq_exit,
    [SEQ_HUGS] = seq_hugs,
    [SEQ_OREF] = seq_oref,
    [SEQ_OTASK] = seq_otask,
    [SEQ_HAHA] = seq_haha,
    [SEQ_COLPERCSSLASH] = seq_colpercsslash,
    [SEQ_O_ESC] = seq_o_esc,
    [SEQ_SFT_O_ESC] = seq_sft_o_esc,
    [SEQ_DQT0P] = seq_dqt0p,
    [SEQ_DQT1P] = seq_dqt1p,
    [SEQ_DQTPLUSP] = seq_dqtplusp,
    [SEQ_DQTPLUSY] = seq_dqtplusy,
    [SEQ_MACOS] = seq_macos,
    [SEQ_OMARCHY] = seq_omarchy,
};

// MC_TILDE .. MC_DQTPLUSY, in the order of the keycode enum.
static const uint8_t macro_seqs[] PROGMEM = {
    SEQ_TILDE, SEQ_DCURLY, SEQ_HCURLY, SEQ_PCURLY, SEQ_BRACES_NEW, SEQ_END_DO_ENT,
    SEQ_DEG, SEQ_AT_AT, SEQ_TISL, SEQ_DS, SEQ_DDS, SEQ_EXIT, SEQ_HUGS, SEQ_OREF,
    SEQ_OTASK, SEQ_HAHA, SEQ_COLPERCSSLASH, SEQ_O_ESC, SEQ_SFT_O_ESC, SEQ_DQT0P,
    SEQ_DQT1P, SEQ_DQTPLUSP, SEQ_DQTPLUSY,
};
// clang-format on

void seq_play(uint8_t seq) {
    const uint16_t *p = (const uint16_t *)pgm_read_ptr(&seqs[seq]);
    uint16_t        kc;
    while ((kc = pgm_read_word(p++)) != 0) {
        if (is_caps_word_on() && !smart_caps_continues(kc)) caps_word_off();
        tap_code16(kc);
        adaptive_track(kc);
        // ZMK's sticky shift is spent by the first key of a macro.
        clear_oneshot_mods();
    }
}

bool process_custom(uint16_t keycode, bool pressed);

void execute_keycode(uint16_t keycode) {
    if (keycode >= SAFE_RANGE) {
        process_custom(keycode, true);
        process_custom(keycode, false);
    } else {
        tap_code16(keycode);
        adaptive_track(keycode);
    }
}

// mc_n0..mc_n9 (ZMK SHIFT_MEH): plain digit; with shift a keypad digit with
// the shift masked; with Meh (ctrl+alt+shift) the keypad digit with Meh kept.
static void tap_digit(uint8_t n) {
    uint16_t digit  = (n == 0) ? KC_0 : (KC_1 + n - 1);
    uint16_t keypad = (n == 0) ? KC_KP_0 : (KC_KP_1 + n - 1);
    uint8_t  mods   = get_mods() | get_oneshot_mods();
    if (is_caps_word_on()) caps_word_off();
    if (mods & MOD_MASK_SHIFT) {
        bool meh = (mods & MOD_MASK_CTRL) && (mods & MOD_MASK_ALT);
        if (!meh) {
            uint8_t saved = get_mods();
            del_mods(MOD_MASK_SHIFT);
            clear_oneshot_mods();
            tap_code16(keypad);
            set_mods(saved);
        } else {
            tap_code16(keypad);
        }
        adaptive_track(keypad);
    } else {
        tap_code16(digit);
        adaptive_track(digit);
    }
}

bool process_macros(uint16_t keycode, bool pressed) {
    if (keycode >= MC_N0 && keycode <= MC_N9) {
        if (pressed) tap_digit(keycode - MC_N0);
        return true;
    }
    if (keycode >= SEQ_FIRST && keycode <= SEQ_LAST) {
        if (pressed) {
            seq_play(pgm_read_byte(&macro_seqs[keycode - SEQ_FIRST]));
            // lm_tilde_vim: ~ ends visual mode
            if (keycode == MC_TILDE) vim_after_symbol(KC_TILD);
        }
        return true;
    }
    switch (keycode) {
        case MC_SQO:
            if (pressed) seq_play(SEQ_SQO);
            return true;
        case MC_SPC_ESC:
            // i, then space held for as long as the key is, then esc
            if (pressed) {
                tap_code(KC_I);
                register_code(KC_SPC);
            } else {
                unregister_code(KC_SPC);
                tap_code(KC_ESC);
            }
            return true;
    }
    return false;
}
