#pragma once

// The 36-position layout of the ZMK keymap (zmk/definitions/keymap.dtsi),
// one block per row and hand, in the order the boards' LAYER() wrappers take
// them: L1 R1 L2 R2 L3 R3 L4 R4. Rows are 5 keys per hand, thumbs 3 per hand
// (L2 L1 L0 | R0 R1 R2, innermost thumbs L0/R0). Every binding mirrors the
// ZMK one; see keycodes.h for the aliases.

// clang-format off

#define XXXXX_5 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define XXXXX_3 XXXXXXX, XXXXXXX, XXXXXXX
#define _____5  _______, _______, _______, _______, _______
#define _____3  _______, _______, _______

// --- ALPHA1 (OMARCHY) ---------------------------------------------------
#define ALPHA1_L1     KC_Q,        KC_B,         KC_M,           KC_G,           KC_K
#define ALPHA1_R1     KC_X,        KC_L,         KC_O,           KC_U,           KC_SCLN
#define ALPHA1_L2     LT_D,        HRM_N,        HRM_S,          HRM_T,          KC_W
#define ALPHA1_R2     KC_Z,        HRM_R,        HRM_A,          HRM_E,          LT_I
#define ALPHA1_L3     KC_Y,        HRM_F,        HRM_C,          HRM_P,          KC_V
#define ALPHA1_R3     KC_J,        MAGIC_KEY,    TH(TH_COMMA),   TH(TH_DOT),     KC_SLSH
#define ALPHA1_L4     MS_BTN2,     L1_KEY,       L0_KEY
#define ALPHA1_R4     R0_KEY,      R1_KEY,       MS_BTN1

// --- VIM NORMAL -----------------------------------------------------------
// The mod-taps here share keycodes with ALPHA1 (HRM_*); taphold.c gives their
// taps the vim meaning when the key was pressed on this layer.
#define VIM_NORMAL_L1 XXXXXXX,     KC_B,         KC_E,           KC_W,           XXXXXXX
#define VIM_NORMAL_R1 XXXXXXX,     KC_G,         VIM_O,          KC_U,           XXXXXXX
#define VIM_NORMAL_L2 VLT_Q,       HRM_N,        HRM_S,          HRM_R,          XXXXXXX
#define VIM_NORMAL_R2 XXXXXXX,     LSFT_T(KC_H), LALT_T(KC_J),   LCTL_T(KC_K),   LT(_SHORTS, KC_L)
#define VIM_NORMAL_L3 XXXXXXX,     HRM_F,        HRM_C,          LGUI_T(KC_T),   XXXXXXX
#define VIM_NORMAL_R3 XXXXXXX,     VMT_I,        VIM_A,          KC_DOT,         XXXXXXX
#define VIM_NORMAL_L4 XXXXXXX,     L1_KEY,       VLT_SPC
#define VIM_NORMAL_R4 R0_KEY,      R1_KEY,       XXXXXXX

// --- VIM CHANGE -----------------------------------------------------------
#define VIM_CHANGE_L1 XXXXXXX,     KC_B,         KC_W,           VIM_CE,         XXXXXXX
#define VIM_CHANGE_R1 XXXXX_5
#define VIM_CHANGE_L2 XXXXX_5
#define VIM_CHANGE_R2 XXXXXXX,     KC_H,         KC_J,           KC_K,           KC_L
#define VIM_CHANGE_L3 XXXXXXX,     KC_F,         KC_C,           KC_T,           XXXXXXX
#define VIM_CHANGE_R3 XXXXXXX,     VIM_CI,       VIM_CA,         XXXXXXX,        XXXXXXX
#define VIM_CHANGE_L4 _____3
#define VIM_CHANGE_R4 _____3

// --- SHORTCUTS ------------------------------------------------------------
#define SHORTS_L1     XXXXXXX,     MC_CALC,      MC_FILES,       MC_BROWSER,     XXXXXXX
#define SHORTS_R1     XXXXXXX,     MC_AI,        MC_EDITOR,      MC_ACTIVITIES,  XXXXXXX
#define SHORTS_L2     XXXXXXX,     LT_ZOOM_OUT,  MC_ZOOM_IN,     MC_NEW,         XXXXXXX
#define SHORTS_R2     XXXXXXX,     XXXXXXX,      MC_CONTAINERS,  LT_EMOJI,       XXXXXXX
#define SHORTS_L3     XXXXXXX,     MC_CLOSE,     MC_REFRESH,     MC_REOPEN,      XXXXXXX
#define SHORTS_R3     XXXXXXX,     MC_SCREENSHOT,MC_NOTES,       MC_TERM,        XXXXXXX
#define SHORTS_L4     XXXXXXX,     MO(_TEXT),    LT(_FUN, KC_SPC)
#define SHORTS_R4     LT_MACROS_SPC, MO(_TEXT),  XXXXXXX

// --- TOGGLES --------------------------------------------------------------
#define TOGS_L1       XXXXX_5
#define TOGS_R1       XXXXXXX,     TG(_NAV),     TG(_FUN),       XXXXXXX,        XXXXXXX
#define TOGS_L2       XXXXX_5
#define TOGS_R2       XXXXXXX,     TG(_NUM),     TG(_MEDIA),     XXXXXXX,        XXXXXXX
#define TOGS_L3       XXXXXXX,     QK_BOOT,      MC_OS_LINUX,       MC_OS_MAC,         XXXXXXX
#define TOGS_R3       XXXXXXX,     TG_MEHS,      XXXXXXX,        QK_BOOT,        XXXXXXX
#define TOGS_L4       XXXXXXX,     KC_CAPS,      KC_NUM
#define TOGS_R4       MC_LOCK,     MC_SLEEP,     XXXXXXX

// --- MEHS -----------------------------------------------------------------
#define MEHS_L1       XXXXXXX,     MEH(KC_B),    MEH(KC_M),      MEH(KC_G),      XXXXXXX
#define MEHS_R1       XXXXXXX,     MEH(KC_L),    MEH(KC_O),      MEH(KC_U),      XXXXXXX
#define MEHS_L2       MEH(KC_D),   MEH(KC_N),    MEH(KC_S),      MEH(KC_T),      XXXXXXX
#define MEHS_R2       XXXXXXX,     MEH(KC_R),    MEH(KC_A),      MEH(KC_E),      MEH(KC_I)
#define MEHS_L3       XXXXXXX,     MEH_MT(KC_F), MEH_MT(KC_C),   MEH_MT(KC_P),   XXXXXXX
#define MEHS_R3       XXXXXXX,     MEH_MT(KC_H), MEH_MT(KC_COMM),MEH_MT(KC_DOT), XXXXXXX
#define MEHS_L4       XXXXXXX,     _______,      MEH_MT(KC_SPC)
#define MEHS_R4       MEH_MT(KC_ENT), _______,   XXXXXXX

// --- ALPHA2 ---------------------------------------------------------------
#define ALPHA2_L1     XXXXXXX,     KC_Q,         MC_QU,          KC_K,           XXXXXXX
#define ALPHA2_R1     XXXXXXX,     AC_OCIR,      AC_OACU,        AC_UACU,        XXXXXXX
#define ALPHA2_L2     KC_Y,        KC_Z,         KC_X,           KC_W,           XXXXXXX
#define ALPHA2_R2     XXXXXXX,     AC_ATIL,      AC_AACU,        AC_EACU,        AC_IACU
#define ALPHA2_L3     XXXXXXX,     KC_J,         MC_CED,         MC_RMAGIC,      XXXXXXX
#define ALPHA2_R3     XXXXXXX,     AC_OTIL,      AC_ACIR,        AC_ECIR,        XXXXXXX
#define ALPHA2_L4     XXXXXXX,     MC_REPEAT,    KC_UNDS
#define ALPHA2_R4     KC_SPC,      MC_SQO,       XXXXXXX

// --- NUMBERS --------------------------------------------------------------
#define NUM_L1        XXXXXXX,     KC_BSLS,      TH(TH_LBRC),    TH(TH_RBRC),    XXXXXXX
#define NUM_R1        XXXXXXX,     MC_N7,        MC_N8,          MC_N9,          XXXXXXX
#define NUM_L2        LT_COMMA,    KC_AMPR,      TH(TH_LPAR),    TH(TH_RPAR),    XXXXXXX
#define NUM_R2        XXXXXXX,     MC_N4,        MC_N5,          MC_N6,          KC_DOT
#define NUM_L3        XXXXXXX,     KC_PIPE,      TH(TH_LBKT),    TH(TH_RBKT),    XXXXXXX
#define NUM_R3        XXXXXXX,     MC_N1,        MC_N2,          MC_N3,          XXXXXXX
#define NUM_L4        XXXXXXX,     _______,      _______
#define NUM_R4        HLT_SYM_SPC, LT_N0,        XXXXXXX

// --- SYMBOLS --------------------------------------------------------------
#define SYM_L1        XXXXXXX,     MC_TILDE,     KC_HASH,        TH(TH_SQO),     XXXXXXX
#define SYM_R1        XXXXXXX,     TH(TH_PERC),  TH(TH_EQL),     TH(TH_COLON),   XXXXXXX
#define SYM_L2        KC_AT,       TH(TH_CARET_Z), KC_DLR,       TH(TH_DQO),     XXXXXXX
#define SYM_R2        XXXXXXX,     TH(TH_QMARK), TH(TH_MINUS),   TH(TH_PLUS),    LT_UNDER
#define SYM_L3        XXXXXXX,     TH(TH_LT),    TH(TH_GT),      TH(TH_BTI),     XXXXXXX
#define SYM_R3        XXXXXXX,     TH(TH_EXCL),  TH(TH_SLASH),   TH(TH_STAR),    XXXXXXX
#define SYM_L4        XXXXXXX,     _______,      HLT_NUMCP_SPC
#define SYM_R4        XXXXXXX,     _______,      XXXXXXX

// --- Ç EXTENSION (one-shot after ç) ----------------------------------------
#define CCEDIL_L1     XXXXX_5
#define CCEDIL_R1     XXXXXXX,     XXXXXXX,      _______,        _______,        XXXXXXX
#define CCEDIL_L2     XXXXXXX,     XXXXXXX,      XXXXXXX,        MC_AOTIL,       XXXXXXX
#define CCEDIL_R2     XXXXXXX,     AC_ATIL,      _______,        XXXXXXX,        XXXXXXX
#define CCEDIL_L3     XXXXXXX,     XXXXXXX,      XXXXXXX,        MC_OTILES,      XXXXXXX
#define CCEDIL_R3     XXXXXXX,     AC_OTIL,      _______,        _______,        XXXXXXX
#define CCEDIL_L4     XXXXXXX,     OSL_A2,       _______
#define CCEDIL_R4     _______,     _______,      XXXXXXX

// --- NAVIGATION -----------------------------------------------------------
#define NAV_L1        XXXXXXX,     MC_SWAPPER,   MC_TABS,        MC_LAUNCHER,    XXXXXXX
#define NAV_R1        XXXXXXX,     KC_TAB,       VIM_ENT,        VIM_ESC,        XXXXXXX
#define NAV_L2        LT_SYSTEM,   MN_CTL,       MN_ALT,         MN_SFT,         XXXXXXX
#define NAV_R2        XXXXXXX,     KC_LEFT,      KC_DOWN,        KC_UP,          KC_RGHT
#define NAV_L3        XXXXXXX,     MN_SG,        MN_SG,          MN_GUI,         XXXXXXX
#define NAV_R3        XXXXXXX,     KC_DEL,       KC_HOME,        KC_END,         XXXXXXX
#define NAV_L4        XXXXXXX,     _______,      MO(_NUM_CP)
#define NAV_R4        HLT_SYMCP_SPC, LT(_MEDIA, KC_INS), XXXXXXX

// --- NUMBERS (copy above NAV) ---------------------------------------------
#define NUM_CP_L1     NUM_L1
#define NUM_CP_R1     NUM_R1
#define NUM_CP_L2     KC_COMM,     KC_AMPR,      TH(TH_LPAR),    TH(TH_RPAR),    XXXXXXX
#define NUM_CP_R2     NUM_R2
#define NUM_CP_L3     NUM_L3
#define NUM_CP_R3     NUM_R3
#define NUM_CP_L4     NUM_L4
#define NUM_CP_R4     HLT_SYMCP_SPC, LT_N0,      XXXXXXX

// --- SYMBOLS (copy above NAV) ---------------------------------------------
#define SYM_CP_L1     SYM_L1
#define SYM_CP_R1     SYM_R1
#define SYM_CP_L2     SYM_L2
#define SYM_CP_R2     XXXXXXX,     TH(TH_QMARK), TH(TH_MINUS),   TH(TH_PLUS),    KC_UNDS
#define SYM_CP_L3     SYM_L3
#define SYM_CP_R3     SYM_R3
#define SYM_CP_L4     XXXXXXX,     _______,      KC_SPC
#define SYM_CP_R4     KC_SPC,      _______,      XXXXXXX

// --- MOUSE / MEDIA --------------------------------------------------------
#define MEDIA_L1      XXXXXXX,     XXXXXXX,      MS_BTN1,        MS_BTN2,        XXXXXXX
#define MEDIA_R1      XXXXXXX,     TH(TH_SHIFT_TAB), TH(TH_END_ENT), VIM_ESC,    XXXXXXX
#define MEDIA_L2      XXXXXXX,     MS_LEFT,      MS_UP,        MS_RGHT,        XXXXXXX
#define MEDIA_R2      XXXXXXX,     MC_MIC,       TH(TH_VOL),     KC_VOLU,        LT_CAM
#define MEDIA_L3      XXXXXXX,     MS_WHLD,      MS_DOWN,        MS_WHLU,        XXXXXXX
#define MEDIA_R3      XXXXXXX,     KC_MPLY,      KC_MPRV,        KC_MNXT,        XXXXXXX
#define MEDIA_L4      XXXXXXX,     MO(_NAV_CP),  KC_SPC
#define MEDIA_R4      XXXXXXX,     _______,      XXXXXXX

// --- NAVIGATION (copy above MEDIA, plain mods) ----------------------------
#define NAV_CP_L1     NAV_L1
#define NAV_CP_R1     NAV_R1
#define NAV_CP_L2     MC_SYSTEM,   KC_LCTL,      KC_LALT,        KC_LSFT,        XXXXXXX
#define NAV_CP_R2     NAV_R2
#define NAV_CP_L3     XXXXXXX,     LSFT(KC_LGUI),LSFT(KC_LGUI),  KC_LGUI,        XXXXXXX
#define NAV_CP_R3     NAV_R3
#define NAV_CP_L4     XXXXXXX,     _______,      _______
#define NAV_CP_R4     _______,     KC_INS,       XXXXXXX

// --- TEXT NAVIGATION ------------------------------------------------------
#define TEXT_L1       XXXXXXX,     MC_SEL_HOME,  MC_SEL_WORD,    MC_SEL_LINE,    _______
#define TEXT_R1       _______,     TH(TH_HOME_TAB), TH(TH_END_ENT), VIM_ESC,     XXXXXXX
#define TEXT_L2       XXXXXXX,     KC_LCTL,      KC_LALT,        KC_LSFT,        _______
#define TEXT_R2       _______,     MC_PREV_WORD, KC_DOWN,        KC_UP,          MC_NEXT_WORD
#define TEXT_L3       XXXXXXX,     LSFT(KC_LGUI),LSFT(KC_LGUI),  KC_LGUI,        _______
#define TEXT_R3       _______,     MC_DEL_WORD,  KC_HOME,        KC_END,         XXXXXXX
#define TEXT_L4       XXXXX_3
#define TEXT_R4       XXXXX_3

// --- FUNCTIONS ------------------------------------------------------------
#define FUN_L1        XXXXXXX,     KC_F13,       KC_F14,         KC_F15,         XXXXXXX
#define FUN_R1        XXXXXXX,     KC_F7,        KC_F8,          KC_F9,          XXXXXXX
#define FUN_L2        XXXXXXX,     HSK_CTL,      HSK_ALT,        HSK_SFT,        XXXXXXX
#define FUN_R2        XXXXXXX,     KC_F4,        KC_F5,          KC_F6,          KC_F12
#define FUN_L3        XXXXXXX,     HSK_SG,       HSK_SG,         HSK_GUI,        XXXXXXX
#define FUN_R3        XXXXXXX,     KC_F1,        KC_F2,          KC_F3,          XXXXXXX
#define FUN_L4        XXXXX_3
#define FUN_R4        KC_F10,      KC_F11,       XXXXXXX

// --- MACROS ---------------------------------------------------------------
#define MACROS_L1     XXXXXXX,     MC_TISL,      MC_DS,          MC_DDS,         XXXXXXX
#define MACROS_R1     XXXXXXX,     MC_COLPERCSSLASH, MC_O_ESC,   MC_SFT_O_ESC,   XXXXXXX
#define MACROS_L2     MC_EXIT,     MC_HUGS,      MC_OREF,        MC_OTASK,       XXXXXXX
#define MACROS_R2     XXXXXXX,     VIM_SFT_V,    MC_DQT0P,       MC_DQT1P,       XXXXXXX
#define MACROS_L3     XXXXXXX,     MC_OS_NAME,   MC_COMMENT,     MC_HAHA,        XXXXXXX
#define MACROS_R3     XXXXXXX,     VIM_CTL_V,    MC_DQTPLUSP,    MC_DQTPLUSY,    XXXXXXX
#define MACROS_L4     XXXXXXX,     XXXXXXX,      MC_SPC_ESC
#define MACROS_R4     XXXXX_3

// clang-format on
