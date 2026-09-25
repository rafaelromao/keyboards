#pragma once

// ---------------------------------------------------------------------------
// Tap ids
//
// Layer-taps and mod-taps whose tap is not a plain key carry an id in the tap
// byte and are resolved in features/taphold.c and features/thumbs.c. The id
// must be a basic keycode the tapping engine treats as tap-capable
// (0x00-0xE7); these are keys this layout never sends. The ZMK name of each
// key is in the comment.
// ---------------------------------------------------------------------------
#define ID_SPC_NUM  KC_INT1  // ltn_num_spc: L0 tap = sentence-aware space, Meh -> GUI
#define ID_REP      KC_INT2  // ht_repeat:   L1 tap = alternate repeat, shifted -> caps line
#define ID_A2       KC_INT3  // msl_sym_a2:  R0 tap = one-shot alpha2 (shifted / caps variants)
#define ID_SHIFT    KC_INT4  // ht_shift:    R1 tap = sticky shift, again -> caps word, in caps -> cancel
#define ID_MAGIC    KC_INT5  // ht_magic:    RBI tap = magic key
#define ID_STICKY   KC_INT6  // hsk:         FUN mods, tap = one-shot mod
#define ID_MOD_NUM  KC_INT7  // mod_num:     NAV mods, tap = one-shot mod + one-shot NUM_CP
#define ID_EMOJI    KC_INT8  // lt_emoji
#define ID_ZOOM_OUT KC_INT9  // lt_zoom_out
#define ID_CAM      KC_LNG1  // lt_cam
#define ID_SYSTEM   KC_LNG2  // lt_system
#define ID_N0       KC_LNG3  // lt_n0: tap = mc_n0

// ---------------------------------------------------------------------------
// Tap/hold symbol keys (ZMK th_*): LT(0, id), id = TH_BASE + index into the
// table in features/taphold.c. Both tap and hold are intercepted, so layer 0
// is never actually toggled by them.
// ---------------------------------------------------------------------------
#define TH_BASE 0xA0
#define TH(n) LT(0, TH_BASE + (n))
#define IS_TH(kc) (((kc) & 0xFF00) == (LT(0, 0) & 0xFF00) && ((kc) & 0xFF) >= TH_BASE)
#define TH_INDEX(kc) (((kc) & 0xFF) - TH_BASE)

enum taphold_ids {
    TH_SEMI,        // th_semi:       ; / end ;
    TH_COMMA,       // th_comma:      , / right ,
    TH_DOT,         // th_dot:        . (shift: Meh .) / right .
    TH_SQO,         // th_sqo:        ' / end '
    TH_DQO,         // th_dqo:        " / end "
    TH_BTI,         // th_bti:        ` / end `
    TH_AND,         // th_and:        && / right space &&
    TH_OR,          // th_or:         || / right space ||
    TH_LBRC,        // th_lbrc:       { / end space {
    TH_RBRC,        // th_rbrc:       } / end space }
    TH_BRACES,      // th_braces:     {} / end {}
    TH_LPAR,        // th_lpar:       ( / end (
    TH_RPAR,        // th_rpar:       ) / end )
    TH_PARS,        // th_pars:       () / end ()
    TH_LBKT,        // th_lbkt:       [ / right [
    TH_RBKT,        // th_rbkt:       ] / right ]
    TH_BRACKETS,    // th_brackets:   [] / end []
    TH_US,          // th_us:         US$ / USD
    TH_BR,          // th_br:         R$ / BRL
    TH_EUR,         // th_eur:        euro / EUR
    TH_BSLASH_QUO,  // th_bslash_quo: \" / \'
    TH_PARS_SEMI,   // th_pars_semi:  end (); / end (); enter
    TH_TDQO,        // th_tdqo:       """ / """ enter
    TH_TBTI,        // th_tbti:       ``` / ``` enter
    TH_SARROW,      // th_sarrow:     -> / right space ->
    TH_DARROW,      // th_darrow:     => / right space =>
    TH_FORWARD,     // th_forward:    |> / end space enter |>
    TH_BACKWARD,    // th_backward:   <- / right enter |>  (as in ZMK)
    TH_CONCAT,      // th_concat:     <> / right space <>
    TH_DCOLON,      // th_dcolon:     :: / right space ::
    TH_PERC,        // th_perc:       % / end space %
    TH_LT,          // th_lt:         < / right space <
    TH_GT,          // th_gt:         > / right space >
    TH_PLUS,        // th_plus:       + / right space +
    TH_MINUS,       // th_minus:      - / right space -
    TH_STAR,        // th_star:       * / right space *
    TH_QMARK,       // th_qmark:      ? / end ?
    TH_EQEQ,        // th_eqeq:       == / right space ==
    TH_NOTEQ,       // th_noteq:      != / right space !=
    TH_ORD_O_A,     // th_ord_o_a:    º / ª
    TH_LTGTLPRP,    // th_end_ltgtlprp: end <>(); / end <>(); enter
    TH_SLASH,       // th_slash:      / / right space /
    TH_COLON,       // th_colon_vim:  : / end :
    TH_EXCL,        // th_excl:       ! / end !
    TH_EQL,         // th_eql:        = / end space =
    TH_CARET_Z,     // th_caret_z:    ^ (0 right after F24) / 0
    TH_END_ENT,     // th_end_ent_vim: enter / end enter
    TH_COPY,        // th_copy:       copy / shift copy
    TH_SELCOPY,     // th_selcopy:    select all + copy / shifted
    TH_PASTE,       // th_paste:      paste / shift paste
    TH_SELPASTE,    // th_selpaste:   select all + paste / shifted
    TH_HOME_TAB,    // th_home_tab:   tab / home tab
    TH_SHIFT_TAB,   // th_shift_tab:  tab / shift tab
    TH_VOL,         // &mt C_MUTE C_VOL_DN: volume down / mute
    TH_COUNT
};

// The two chords whose hold is a real Hyper: only the tap is intercepted.
#define TH_HYPER_SPC HYPR_T(KC_SPC)  // th_hyper_space
#define TH_HYPER_ENT HYPR_T(KC_ENT)  // th_hyper_enter

// ---------------------------------------------------------------------------
// Custom keycodes
// ---------------------------------------------------------------------------
enum custom_keycodes {
    // OS-morphed shortcuts, in the order of os_shortcuts[] (features/shortcuts.c)
    MC_OS_FIRST = SAFE_RANGE,
    MC_FULLSCR = MC_OS_FIRST,
    MC_FIND,
    MC_SELALL,
    MC_UNDO,
    MC_COPY,
    MC_SHIFT_COPY,
    MC_SELCOPY,
    MC_SHIFT_SELCOPY,
    MC_PASTE,
    MC_SHIFT_PASTE,
    MC_SELPASTE,
    MC_SHIFT_SELPASTE,
    MC_SAVE,
    MC_COMMENT,
    MC_LOCK,
    MC_REFRESH,
    MC_CLOSE,
    MC_REOPEN,
    MC_NEW,
    MC_ZOOM_OUT,
    MC_ZOOM_IN,
    MC_RESET_ZOOM,
    MC_LAUNCHER,
    MC_TABS,
    MC_FILES,
    MC_SCREENSHOT,
    MC_EMOJI,
    MC_CALC,
    MC_NOTES,
    MC_TERM,
    MC_BROWSER,
    MC_EDITOR,
    MC_AI,
    MC_ACTIVITIES,
    MC_SYSTEM,
    MC_CONTAINERS,
    MC_PREV_WORD,
    MC_NEXT_WORD,
    MC_DEL_WORD,
    MC_BSP_WORD,
    MC_OS_LAST = MC_BSP_WORD,

    // OS mode
    MC_OS_MAC,        // lock_on ALT_OS
    MC_OS_LINUX,      // lock_off ALT_OS
    MC_OS_NAME,    // lm_os: types MacOS / Omarchy

    // Smart layers and thumbs (features/smart.c, features/thumbs.c)
    MC_CANCEL,     // tc_cancel
    MC_NUMWORD,    // tc_num_word
    MC_NUMWORD_CP, // tc_num_word_cp
    OSL_A2,        // &sl ALPHA2 (caps variant under caps word)
    MC_REPEAT,     // &key_repeat (' on the shifted alpha2)
    MC_RMAGIC,     // reversed_magic (and its caps variant)

    // Digits (mc_n0..9): shifted -> keypad digit, Meh -> Meh + keypad digit
    MC_N0, MC_N1, MC_N2, MC_N3, MC_N4, MC_N5, MC_N6, MC_N7, MC_N8, MC_N9,

    // Accents (features/accents.c); shifted and caps variants come from state
    AC_FIRST,
    AC_AGRV = AC_FIRST,  // à
    AC_AACU,             // á
    AC_ATIL,             // ã
    AC_ACIR,             // â
    AC_EACU,             // é
    AC_ECIR,             // ê
    AC_IACU,             // í
    AC_OACU,             // ó
    AC_OTIL,             // õ
    AC_OCIR,             // ô
    AC_UACU,             // ú
    AC_LAST = AC_UACU,
    MC_CED,              // ç, then the ç extension one-shot
    MC_QU,               // qu
    MC_AOTIL,            // ão
    MC_OTILES,           // ões
    MC_SQO,              // ' (dead-key safe: quote + space)

    // Select (features/select_word.c)
    MC_SEL_HOME,
    MC_SEL_WORD,
    MC_SEL_LINE,

    // Sequence-backed macros (features/macros.c), in the order of macro_seqs[]
    SEQ_FIRST,
    MC_TILDE = SEQ_FIRST,  // ~ (dead-key safe)
    MC_DCURLY,             // ${
    MC_HCURLY,             // #{
    MC_PCURLY,             // %{
    MC_BRACES_NEW,         // end, space, {, enter
    MC_END_DO_ENT,         // end, space, do, enter
    MC_DEG,                // ° (mac option chord, as in ZMK)
    MC_AT_AT,              // @@
    MC_TISL,               // ~/
    MC_DS,                 // ./
    MC_DDS,                // ../
    MC_EXIT,               // exit, enter
    MC_HUGS,               // []'s
    MC_OREF,               // [[
    MC_OTASK,              // - [ ]
    MC_HAHA,               // haha, enter
    MC_COLPERCSSLASH,      // :%s/
    MC_O_ESC,              // o, esc
    MC_SFT_O_ESC,          // O, esc
    MC_DQT0P,              // "0p
    MC_DQT1P,              // "1p
    MC_DQTPLUSP,           // "+p
    MC_DQTPLUSY,           // "+y
    SEQ_LAST = MC_DQTPLUSY,
    MC_SPC_ESC,            // i, space held until release, esc

    // Vim mode (features/vim.c); plain keys when vim is off
    VIM_ON,
    VIM_OFF,
    VIM_O, VIM_A, VIM_I, VIM_S,   // key + insert
    VIM_R,                        // r + sticky replace; shifted: R + insert
    VIM_C,                        // c + insert + sticky change
    VIM_Q, VIM_AT,                // key + sticky replace
    VIM_V, VIM_SFT_V, VIM_CTL_V,  // visual toggles
    VIM_X, VIM_D, VIM_Y, VIM_P,   // visual -> normal
    VIM_CE, VIM_CI, VIM_CA,       // change-layer targets
    VIM_SFT_J,                    // visual -> normal + J
    VIM_ESC, VIM_ENT,             // lm_esc_vim / lm_ent_vim

    CUSTOM_KEYCODE_END
};

// ---------------------------------------------------------------------------
// Aliases used by the keymap blocks
// ---------------------------------------------------------------------------
// Thumbs (ZMK: ht_repeat NAV, ltn_num_spc, msl_sym_a2, ht_shift MEDIA)
#define L1_KEY LT(_NAV, ID_REP)
#define L0_KEY LT(_NUM, ID_SPC_NUM)
#define R0_KEY LT(_SYM, ID_A2)
#define R1_KEY LT(_MEDIA, ID_SHIFT)
#define MAGIC_KEY LGUI_T(ID_MAGIC)  // ht_magic LGUI

// Home-row mods (every mod is a left mod on both hands, as in ZMK)
#define HRM_N LCTL_T(KC_N)
#define HRM_S LALT_T(KC_S)
#define HRM_T LSFT_T(KC_T)
#define HRM_F LSG_T(KC_F)
#define HRM_C LSG_T(KC_C)
#define HRM_P LGUI_T(KC_P)
#define HRM_R LSFT_T(KC_R)
#define HRM_A LALT_T(KC_A)
#define HRM_E LCTL_T(KC_E)
#define LT_D LT(_SHORTS, KC_D)
#define LT_I LT(_SHORTS, KC_I)

// Vim normal layer keys whose tap gets the vim meaning (resolved by layer)
#define VLT_Q   LT(_SHORTS, KC_Q)  // lt_q_vim SHORTS
#define VMT_I   LGUI_T(KC_I)       // mt_i_vim LGUI
#define VLT_SPC LT(_NUM, KC_SPC)   // lt_spc_vim NUM: plain space

// FUN sticky mods (hsk) and NAV one-shot mod + numbers (mod_num)
#define HSK_CTL LCTL_T(ID_STICKY)
#define HSK_ALT LALT_T(ID_STICKY)
#define HSK_SFT LSFT_T(ID_STICKY)
#define HSK_SG  LSG_T(ID_STICKY)
#define HSK_GUI LGUI_T(ID_STICKY)
#define MN_CTL  LCTL_T(ID_MOD_NUM)
#define MN_ALT  LALT_T(ID_MOD_NUM)
#define MN_SFT  LSFT_T(ID_MOD_NUM)
#define MN_SG   LSG_T(ID_MOD_NUM)
#define MN_GUI  LGUI_T(ID_MOD_NUM)

// Layer-taps with a custom tap
#define LT_EMOJI    LT(_TOGS, ID_EMOJI)     // lt_emoji TOGS
#define LT_ZOOM_OUT LT(_TOGS, ID_ZOOM_OUT)  // lt_zoom_out TOGS
#define LT_CAM      LT(_TEXT, ID_CAM)       // lt_cam TEXT
#define LT_SYSTEM   LT(_TEXT, ID_SYSTEM)    // lt_system TEXT
#define LT_N0       LT(_MEDIA, ID_N0)       // lt_n0 MEDIA
#define LT_COMMA    LT(_FUN, KC_COMM)       // lt_comma FUN

// Keys that reach the MACROS layer, plain keys when that layer is cut
#ifdef RR_MACROS_ENABLE
#    define LT_MACROS_SPC LT(_MACROS, KC_SPC)  // &lt MACROS SPACE
#    define LT_UNDER      LT(_MACROS, KC_UNDS) // &lt MACROS UNDER
#    define LT_RIGHT      LT(_MACROS, KC_RGHT) // lt_right MACROS (combo)
#else
#    define LT_MACROS_SPC KC_SPC
#    define LT_UNDER      KC_UNDS
#    define LT_RIGHT      KC_RGHT
#endif
#ifdef RR_MEHS_ENABLE
#    define TG_MEHS TG(_MEHS)
#else
#    define TG_MEHS XXXXXXX
#endif

// Hold-preferred layer-taps (hlt): hold wins on another key press
#define HLT_SYM_SPC    LT(_SYM, KC_SPC)
#define HLT_NUMCP_SPC  LT(_NUM_CP, KC_SPC)
#define HLT_SYMCP_SPC  LT(_SYM_CP, KC_SPC)

// Combo chords with a two-mod hold (COMBO_MUST_TAP in ZMK, hold-preferred)
#define HT_W LSA_T(KC_W)
#define HT_Q LCA_T(KC_Q)
#define HT_Z LSA_T(KC_Z)
#define HT_Y LCA_T(KC_Y)
#define HT_MEH_SPC MEH_T(KC_SPC)  // tap Meh+Space, hold Meh
#define HT_MEH_ENT MEH_T(KC_ENT)  // tap Meh+Enter, hold Meh

// MEHS layer mod-taps: tap Meh+key (resolved by layer in taphold.c), hold GUI
#define MEH_MT(kc) LGUI_T(kc)

// Plain shortcuts that are the same on every OS
#define MC_SWAPPER LALT(KC_TAB)
#define MC_HAND    LCA(KC_H)
#define MC_MIC     LCA(KC_D)
#define MC_CAM     LCA(KC_E)
#define MC_SLEEP   KC_SLEP
