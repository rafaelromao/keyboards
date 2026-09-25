#include "rafaelromao.h"
#include "definitions/positions.h"
#include "features/macros.h"

// ---------------------------------------------------------------------------
// Combos (ZMK zmk/features/combos.dtsi)
//
// ZMK matches a combo by key position and by the highest active layer. Here
// the keys are the ALPHA1 keycodes of the positions (positions.h) resolved
// through combo_ref_from_layer(), and each combo carries the layers it is
// allowed on, checked in combo_should_trigger() against the highest active
// layer. A chord that means different things on different layers is several
// entries with the same keys and disjoint layer masks, so every output can be
// a native keycode, tap-hold ones included.
// ---------------------------------------------------------------------------

#define L(x) (1UL << (x))

#ifdef RR_VIM_ENABLE
#    define VIM_CMD (L(_VIM_NORMAL) | L(_VIM_CHANGE))
#    define VIMX(...) X(__VA_ARGS__)
#else
#    define VIM_CMD 0
#    define VIMX(...)
#endif
#ifdef RR_MEHS_ENABLE
#    define MEHS_L L(_MEHS)
#    define MEHX(...) X(__VA_ARGS__)
#else
#    define MEHS_L 0
#    define MEHX(...)
#endif
#ifdef RR_MACROS_ENABLE
#    define MACROS_L L(_MACROS)
#    define MACX(...) X(__VA_ARGS__)
#else
#    define MACROS_L 0
#    define MACX(...)
#endif

// ZMK's ALPHA1_LAYERS (the base plus its flag layers) and VIM_LAYERS_BASE
// (INSERT/REPLACE/CMDLINE, all transparent) are all "ALPHA1 on top" here.
#define ALPHA1_L L(_ALPHA1)
#define ALPHA2_L L(_ALPHA2)
#define CCEDIL_L L(_CCEDIL)
#define NUM_L (L(_NUM) | L(_NUM_CP))
#define SYM_L (L(_SYM) | L(_SYM_CP))
#define NAV_L (L(_NAV) | L(_NAV_CP))
#define TEXT_L L(_TEXT)
#define MEDIA_L L(_MEDIA)
#define FUN_L L(_FUN)
#define SHORTS_L L(_SHORTS)
// ALL_LAYERS: everything but TOGGLES, MEHS, FUNCTIONS, MACROS
#define ALL_L (ALPHA1_L | VIM_CMD | SHORTS_L | ALPHA2_L | NUM_L | SYM_L | CCEDIL_L | NAV_L | MEDIA_L | TEXT_L)
#define WITH_ENTER_L (ALL_L & ~(SHORTS_L | VIM_CMD))
#define WITH_BSPC_L (ALL_L & ~(SHORTS_L | MEDIA_L | TEXT_L | VIM_CMD))
#define WITH_ESC_L (ALPHA1_L | ALPHA2_L | CCEDIL_L | MEHS_L | VIM_CMD)
#define FIXABLE_L (ALPHA1_L | VIM_CMD | MEHS_L | NUM_L | NAV_L | MEDIA_L | FUN_L)

// X(name, layers, output, keys...)
// clang-format off
#define COMBO_LIST \
    /* --- global chords --- */ \
    VIMX(vim_on,        ALPHA1_L | VIM_CMD,           VIM_ON,               P_LTR, P_LTM, P_LTI) \
    X(end_do_ent,       NUM_L,                        MC_END_DO_ENT,        P_LTR, P_LTM, P_LTI) \
    X(bslash_quo,       SYM_L,                        TH(TH_BSLASH_QUO),    P_LTR, P_LTM, P_LTI) \
    X(enter,            WITH_ENTER_L,                 VIM_ENT,              P_RHM, P_RHR, P_R0) \
    X(backspace,        WITH_BSPC_L,                  KC_BSPC,              P_RTM, P_RTR) \
    X(bsp_word,         TEXT_L,                       MC_BSP_WORD,          P_RTM, P_RTR) \
    MACX(vim_off,       MACROS_L,                     VIM_OFF,              P_RTM, P_RTR) \
    VIMX(vim_d,         VIM_CMD,                      VIM_D,                P_RTM, P_RTR) \
    X(f15,              FUN_L,                        KC_F15,               P_RTM, P_RTR) \
    X(esc,              WITH_ESC_L,                   VIM_ESC,              P_LTR, P_LTM) \
    X(braces_new,       NUM_L,                        MC_BRACES_NEW,        P_LTR, P_LTM) \
    X(darrow,           SYM_L,                        TH(TH_DARROW),        P_LTR, P_LTM) \
    X(save_esc,         ALL_L,                        KC_NO,                P_LTR, P_LTM, P_L0) \
    X(toggles_l,        SHORTS_L,                     MO(_TOGS),            P_LHI, P_LHR) \
    X(toggles_r,        SHORTS_L,                     MO(_TOGS),            P_RHI, P_RHR) \
    X(boot_l,           ALL_L,                        QK_BOOT,              P_LTR, P_LBI) \
    X(boot_r,           ALL_L,                        QK_BOOT,              P_RTR, P_RBI) \
    X(cancel,           FIXABLE_L,                    MC_CANCEL,            P_RTI, P_RTM, P_RTR) \
    X(eur,              SYM_L,                        TH(TH_EUR),           P_RTI, P_RTM, P_RTR) \
    /* --- shortcuts with the inner thumbs --- */ \
    X(save,             ALL_L,                        MC_SAVE,              P_LHR, P_LHM, P_L0) \
    X(fullscr,          ALL_L,                        MC_FULLSCR,           P_LHM, P_LHI, P_L0) \
    X(find,             ALL_L,                        MC_FIND,              P_LBM, P_LBI, P_L0) \
    X(undo,             ALL_L,                        MC_UNDO,              P_LBR, P_LBM, P_L0) \
    X(tab,              ALL_L,                        KC_TAB,               P_RTM, P_RTR, P_R0) \
    X(paste,            ALL_L,                        TH(TH_PASTE),         P_RBI, P_RBM, P_R0) \
    X(copy,             ALL_L,                        TH(TH_COPY),          P_RHI, P_RHM, P_R0) \
    X(selall,           ALL_L,                        MC_SELALL,            P_RBM, P_RBR, P_R0) \
    X(selcopy,          ALL_L,                        TH(TH_SELCOPY),       P_RHI, P_RHM, P_RHR, P_R0) \
    X(selpaste,         ALL_L,                        TH(TH_SELPASTE),      P_RBI, P_RBM, P_RBR, P_R0) \
    /* --- navigation with the right thumb --- */ \
    X(left,             ALL_L,                        KC_LEFT,              P_RHI, P_R1) \
    X(down,             ALL_L,                        KC_DOWN,              P_RHM, P_R1) \
    X(up,               ALL_L,                        KC_UP,                P_RHR, P_R1) \
    X(right,            ALL_L,                        LT_RIGHT,             P_RHP, P_R1) \
    X(del,              ALL_L,                        KC_DEL,               P_RBI, P_R1) \
    X(home,             ALL_L,                        KC_HOME,              P_RBM, P_R1) \
    X(end,              ALL_L,                        KC_END,               P_RBR, P_R1) \
    /* --- brackets with the left thumb --- */ \
    X(lbrc,             ALL_L,                        TH(TH_LBRC),          P_LTM, P_L0) \
    X(rbrc,             ALL_L,                        TH(TH_RBRC),          P_LTI, P_L0) \
    X(lpar,             ALL_L,                        TH(TH_LPAR),          P_LHM, P_L0) \
    X(rpar,             ALL_L,                        TH(TH_RPAR),          P_LHI, P_L0) \
    X(lbkt,             ALL_L,                        TH(TH_LBKT),          P_LBM, P_L0) \
    X(rbkt,             ALL_L,                        TH(TH_RBKT),          P_LBI, P_L0) \
    /* --- digits with the right thumb --- */ \
    X(n7,               ALL_L,                        MC_N7,                P_RTI, P_R0) \
    X(n8,               ALL_L,                        MC_N8,                P_RTM, P_R0) \
    X(n9,               ALL_L,                        MC_N9,                P_RTR, P_R0) \
    X(n4,               ALL_L,                        MC_N4,                P_RHI, P_R0) \
    X(n5,               ALL_L,                        MC_N5,                P_RHM, P_R0) \
    X(n6,               ALL_L,                        MC_N6,                P_RHR, P_R0) \
    X(n1,               ALL_L,                        MC_N1,                P_RBI, P_R0) \
    X(n2,               ALL_L,                        MC_N2,                P_RBM, P_R0) \
    X(n3,               ALL_L,                        MC_N3,                P_RBR, P_R0) \
    X(n0,               ALL_L,                        MC_N0,                P_R1, P_R0) \
    /* --- num word, nav mod chords, meh/hyper chords --- */ \
    X(numword,          ALPHA1_L,                     MC_NUMWORD,           P_LBR, P_LBM) \
    X(or,               NUM_L,                        TH(TH_OR),            P_LBR, P_LBM) \
    X(concat,           SYM_L,                        TH(TH_CONCAT),        P_LBR, P_LBM) \
    VIMX(at_at,         VIM_CMD,                      MC_AT_AT,             P_LBR, P_LBM) \
    MEHX(numword_cp_l,  MEHS_L,                       MC_NUMWORD_CP,        P_LBR, P_LBM) \
    X(grv,              ALPHA2_L,                     KC_GRV,               P_LBR, P_LBM) \
    X(ca_nav,           ALPHA1_L | VIM_CMD,           KC_NO,                P_LHR, P_LHM, P_L1) \
    X(gcs_nav,          ALPHA1_L | VIM_CMD,           KC_NO,                P_LBR, P_LHM, P_LHI, P_L1) \
    X(cag_nav,          ALPHA1_L | VIM_CMD,           KC_NO,                P_LHR, P_LHM, P_LBI, P_L1) \
    X(cas_num,          ALPHA1_L,                     KC_NO,                P_LHR, P_LHM, P_LHI, P_L0) \
    X(meh_spc,          ALPHA1_L,                     HT_MEH_SPC,           P_LHR, P_LHM, P_LHI) \
    X(pars_semi,        NUM_L,                        TH(TH_PARS_SEMI),     P_LHR, P_LHM, P_LHI) \
    X(tdqo,             SYM_L,                        TH(TH_TDQO),          P_LHR, P_LHM, P_LHI) \
    MEHX(meh_space,     MEHS_L,                       MEH(KC_SPC),          P_LHR, P_LHM, P_LHI) \
    X(hyp_spc,          ALPHA1_L,                     TH_HYPER_SPC,         P_LBR, P_LBM, P_LBI) \
    X(ltgtlprp,         NUM_L,                        TH(TH_LTGTLPRP),      P_LBR, P_LBM, P_LBI) \
    X(tbti,             SYM_L,                        TH(TH_TBTI),          P_LBR, P_LBM, P_LBI) \
    MEHX(hyper_space,   MEHS_L,                       HYPR(KC_SPC),         P_LBR, P_LBM, P_LBI) \
    X(meh_ent,          ALPHA1_L,                     HT_MEH_ENT,           P_RHI, P_RHM, P_RHR) \
    X(ord_o_a,          NUM_L,                        TH(TH_ORD_O_A),       P_RHI, P_RHM, P_RHR) \
    X(br,               SYM_L,                        TH(TH_BR),            P_RHI, P_RHM, P_RHR) \
    MEHX(meh_enter,     MEHS_L,                       MEH(KC_ENT),          P_RHI, P_RHM, P_RHR) \
    X(dqt0p,            TEXT_L,                       MC_DQT0P,             P_RHI, P_RHM, P_RHR) \
    X(hyp_ent,          ALPHA1_L,                     TH_HYPER_ENT,         P_RBI, P_RBM, P_RBR) \
    X(deg,              NUM_L,                        MC_DEG,               P_RBI, P_RBM, P_RBR) \
    X(us,               SYM_L,                        TH(TH_US),            P_RBI, P_RBM, P_RBR) \
    MEHX(hyper_enter,   MEHS_L,                       HYPR(KC_ENT),         P_RBI, P_RBM, P_RBR) \
    X(text_v,           TEXT_L,                       KC_V,                 P_RBI, P_RBM, P_RBR) \
    X(semi,             ALPHA1_L | NUM_L | VIM_CMD,   TH(TH_SEMI),          P_RBM, P_RBR) \
    X(noteq,            SYM_L,                        TH(TH_NOTEQ),         P_RBM, P_RBR) \
    X(coln,             ALPHA2_L,                     KC_COLN,              P_RBM, P_RBR) \
    X(text_sv,          TEXT_L,                       S(KC_V),              P_RBM, P_RBR) \
    X(nav_numcp,        NAV_L,                        MO(_NUM_CP),          P_RBM, P_RBR) \
    MEHX(numword_cp_r,  MEHS_L,                       MC_NUMWORD_CP,        P_RBM, P_RBR) \
    X(f13,              FUN_L,                        KC_F13,               P_RBM, P_RBR) \
    /* --- the letter chords and what the same chords do on other layers --- */ \
    X(k,                ALPHA1_L,                     KC_K,                 P_LTM, P_LTI) \
    X(braces,           NUM_L,                        TH(TH_BRACES),        P_LTM, P_LTI) \
    X(hcurly,           SYM_L,                        MC_HCURLY,            P_LTM, P_LTI) \
    VIMX(vim_grv,       VIM_CMD,                      KC_GRV,               P_LTM, P_LTI) \
    MEHX(meh_k,         MEHS_L,                       MEH(KC_K),            P_LTM, P_LTI) \
    X(dquo,             ALPHA2_L,                     KC_DQUO,              P_LTM, P_LTI) \
    X(w,                ALPHA1_L,                     HT_W,                 P_LHM, P_LHI) \
    X(pars,             NUM_L,                        TH(TH_PARS),          P_LHM, P_LHI) \
    X(dcurly,           SYM_L,                        MC_DCURLY,            P_LHM, P_LHI) \
    VIMX(vim_m,         VIM_CMD,                      KC_M,                 P_LHM, P_LHI) \
    MEHX(meh_w,         MEHS_L,                       MEH(KC_W),            P_LHM, P_LHI) \
    X(quot,             ALPHA2_L,                     KC_QUOT,              P_LHM, P_LHI) \
    X(v,                ALPHA1_L,                     KC_V,                 P_LBI, P_LBM) \
    X(brackets,         NUM_L,                        TH(TH_BRACKETS),      P_LBI, P_LBM) \
    X(forward,          SYM_L,                        TH(TH_FORWARD),       P_LBI, P_LBM) \
    VIMX(vim_at,        VIM_CMD,                      VIM_AT,               P_LBI, P_LBM) \
    MEHX(meh_v,         MEHS_L,                       MEH(KC_V),            P_LBI, P_LBM) \
    X(tild,             ALPHA2_L,                     KC_TILD,              P_LBI, P_LBM) \
    X(q,                ALPHA1_L,                     HT_Q,                 P_LHR, P_LHM) \
    X(and,              NUM_L,                        TH(TH_AND),           P_LHR, P_LHM) \
    X(sarrow,           SYM_L,                        TH(TH_SARROW),        P_LHR, P_LHM) \
    VIMX(vim_z,         VIM_CMD,                      KC_Z,                 P_LHR, P_LHM) \
    MEHX(meh_q,         MEHS_L,                       MEH(KC_Q),            P_LHR, P_LHM) \
    X(circ,             ALPHA2_L,                     KC_CIRC,              P_LHR, P_LHM) \
    X(reset_zoom,       SHORTS_L,                     MC_RESET_ZOOM,        P_LHR, P_LHM) \
    X(nav_ca,           NAV_L,                        C(KC_LALT),           P_LHR, P_LHM) \
    X(x,                ALPHA1_L,                     KC_X,                 P_RTI, P_RTM) \
    X(g_sft,            NUM_L,                        S(KC_G),              P_RTI, P_RTM) \
    X(pcurly,           SYM_L,                        MC_PCURLY,            P_RTI, P_RTM) \
    VIMX(vim_x,         VIM_CMD,                      VIM_X,                P_RTI, P_RTM) \
    MEHX(meh_x,         MEHS_L,                       MEH(KC_X),            P_RTI, P_RTM) \
    X(mins,             ALPHA2_L,                     KC_MINS,              P_RTI, P_RTM) \
    MACX(macros_vim_on, MACROS_L,                     VIM_ON,               P_RTI, P_RTM) \
    X(up_end_del,       NAV_L,                        KC_NO,                P_RTI, P_RTM) \
    X(hand,             MEDIA_L,                      MC_HAND,              P_RTI, P_RTM) \
    X(f12,              FUN_L,                        KC_F12,               P_RTI, P_RTM) \
    X(z,                ALPHA1_L,                     HT_Z,                 P_RHI, P_RHM) \
    X(j_num,            NUM_L,                        KC_J,                 P_RHI, P_RHM) \
    X(backward,         SYM_L,                        TH(TH_BACKWARD),      P_RHI, P_RHM) \
    VIMX(vim_p,         VIM_CMD,                      VIM_P,                P_RHI, P_RHM) \
    MEHX(meh_z,         MEHS_L,                       MEH(KC_Z),            P_RHI, P_RHM) \
    X(ques,             ALPHA2_L,                     KC_QUES,              P_RHI, P_RHM) \
    X(o_esc,            TEXT_L,                       MC_O_ESC,             P_RHI, P_RHM) \
    X(pgdn,             NAV_L,                        KC_PGDN,              P_RHI, P_RHM) \
    X(btn1,             MEDIA_L,                      MS_BTN1,              P_RHI, P_RHM) \
    X(f11,              FUN_L,                        KC_F11,               P_RHI, P_RHM) \
    X(j,                ALPHA1_L,                     KC_J,                 P_RBI, P_RBM) \
    X(pipe,             NUM_L,                        KC_PIPE,              P_RBI, P_RBM) \
    X(dcolon,           SYM_L,                        TH(TH_DCOLON),        P_RBI, P_RBM) \
    VIMX(vim_v,         VIM_CMD,                      VIM_V,                P_RBI, P_RBM) \
    MEHX(meh_j,         MEHS_L,                       MEH(KC_J),            P_RBI, P_RBM) \
    X(exlm,             ALPHA2_L,                     KC_EXLM,              P_RBI, P_RBM) \
    X(text_cv,          TEXT_L,                       C(KC_V),              P_RBI, P_RBM) \
    X(down_end,         NAV_L,                        KC_NO,                P_RBI, P_RBM) \
    X(f10,              FUN_L,                        KC_F10,               P_RBI, P_RBM) \
    X(y,                ALPHA1_L,                     HT_Y,                 P_RHM, P_RHR) \
    X(k_num,            NUM_L,                        KC_K,                 P_RHM, P_RHR) \
    X(eqeq,             SYM_L,                        TH(TH_EQEQ),          P_RHM, P_RHR) \
    VIMX(vim_y,         VIM_CMD,                      VIM_Y,                P_RHM, P_RHR) \
    MEHX(meh_y,         MEHS_L,                       MEH(KC_Y),            P_RHM, P_RHR) \
    X(agrv,             ALPHA2_L,                     AC_AGRV,              P_RHM, P_RHR) \
    X(sft_o_esc,        TEXT_L,                       MC_SFT_O_ESC,         P_RHM, P_RHR) \
    X(pgup,             NAV_L,                        KC_PGUP,              P_RHM, P_RHR) \
    X(btn2,             MEDIA_L,                      MS_BTN2,              P_RHM, P_RHR) \
    X(f14,              FUN_L,                        KC_F14,               P_RHM, P_RHR) \
    X(comma_num,        NUM_L,                        KC_COMM,              P_RHP, P_R0)
// clang-format on

// The key arrays
#define X(name, layers, output, ...) static const uint16_t PROGMEM cmb_##name[] = {__VA_ARGS__, COMBO_END};
COMBO_LIST
#undef X

// The combos themselves (this file is the introspection unit, so QMK sizes
// key_combos from here)
combo_t key_combos[] = {
#define X(name, layers, output, ...) COMBO(cmb_##name, output),
    COMBO_LIST
#undef X
};

// The allowed layers, parallel to key_combos
static const uint32_t combo_layers[] PROGMEM = {
#define X(name, layers, output, ...) (uint32_t)(layers),
    COMBO_LIST
#undef X
};

// Indices, for the combos handled in code
enum combo_ids {
#define X(name, layers, output, ...) CB_##name,
    COMBO_LIST
#undef X
        CB_COUNT
};

uint8_t combo_ref_from_layer(uint8_t layer) {
    return _ALPHA1;
}

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    uint8_t layer = get_highest_layer(layer_state | default_layer_state);
    return (pgm_read_dword(&combo_layers[combo_index]) >> layer) & 1;
}

// mc_ca_nav and friends: hold some modifiers and a layer for as long as the
// chord is held.
static void chord_mods_layer(bool pressed, uint8_t mods, uint8_t layer) {
    if (pressed) {
        register_mods(mods);
        layer_on(layer);
    } else {
        layer_off(layer);
        unregister_mods(mods);
    }
}

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
        case CB_save_esc:
            if (pressed) {
                execute_keycode(MC_SAVE);
                execute_keycode(VIM_ESC);
            }
            break;
        case CB_ca_nav:
            chord_mods_layer(pressed, MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT), _NAV);
            break;
        case CB_gcs_nav:
            chord_mods_layer(pressed, MOD_BIT(KC_LGUI) | MOD_BIT(KC_LCTL) | MOD_BIT(KC_LSFT), _NAV);
            break;
        case CB_cag_nav:
            chord_mods_layer(pressed, MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT) | MOD_BIT(KC_LGUI), _NAV);
            break;
        case CB_cas_num:
            chord_mods_layer(pressed, MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT) | MOD_BIT(KC_LSFT), _NUM);
            break;
        case CB_up_end_del:
            if (pressed) {
                tap_code(KC_UP);
                tap_code(KC_END);
                tap_code(KC_DEL);
            }
            break;
        case CB_down_end:
            if (pressed) {
                tap_code(KC_DOWN);
                tap_code(KC_END);
            }
            break;
    }
}
