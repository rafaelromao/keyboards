#include QMK_KEYBOARD_H

#include "combos.h"

// Numpad

const uint16_t PROGMEM l_num_esc_combo[] = {LOW_SPC, KC_F9, KC_F8, COMBO_END};
const uint16_t PROGMEM l_num_sav_combo[] = {LOW_SPC, SF_F6, CT_F5, COMBO_END};
const uint16_t PROGMEM r_num_ent_combo[] = {RAI_BSP, CT_5, SF_6, COMBO_END};

// Lower

const uint16_t PROGMEM l_low_par_combo[] = {TD_OPAR, TD_CPAR, COMBO_END};
const uint16_t PROGMEM r_low_tab_combo[] = {RAI_BSP, KC_8, KC_9, COMBO_END};
const uint16_t PROGMEM r_low_ent_combo[] = {RAI_BSP, KC_5, KC_6, COMBO_END};

// Raise

const uint16_t PROGMEM r_rai_cur_combo[] = {TD_LCRB, TD_RCRB, COMBO_END};
const uint16_t PROGMEM r_rai_plu_combo[] = {TD_EQL, TD_NOT, COMBO_END};
const uint16_t PROGMEM r_rai_ast_combo[] = {TD_LT, TD_GT, COMBO_END};

// Navigation

const uint16_t PROGMEM l_nav_esv_combo[] = {MC_ESC, MC_SAVE, COMBO_END};

// Media

const uint16_t PROGMEM r_med_ent_combo[] = {KC_ENT, KC_TAB, COMBO_END};

// Accents

const uint16_t PROGMEM r_ng_ao_combo[]   = {MC_SQ_A, MC_SQ_E, COMBO_END};
const uint16_t PROGMEM r_ng_cu_combo[]   = {MC_TL_O, MC_SQ_O, COMBO_END};
const uint16_t PROGMEM r_ng_ca_combo[]   = {MC_TL_A, MC_SQ_A, COMBO_END};
const uint16_t PROGMEM r_ng_co_combo[]   = {MC_CR_A, MC_CR_O, COMBO_END};
const uint16_t PROGMEM r_ng_cao_combo[]  = {MC_TL_A, MC_SQ_A, MC_SQ_E, COMBO_END};
const uint16_t PROGMEM r_ng_oes_combo[]  = {MC_CR_O, MC_CR_E, COMBO_END};
const uint16_t PROGMEM r_ng_coes_combo[] = {MC_CR_A, MC_CR_O, MC_CR_E, COMBO_END};

// Macros

const uint16_t PROGMEM r_mac_ref_combo[] = {MC_MODM, SF_MODP, COMBO_END};
const uint16_t PROGMEM r_mac_clo_combo[] = {MC_SWLE, MC_SWRI, COMBO_END};

// Base

const uint16_t PROGMEM l_rom_z_combo[]   = {LCTLT_S, LGUIT_T, COMBO_END};
const uint16_t PROGMEM l_rom_q_combo[]   = {KC_C, LALTT_P, COMBO_END};
const uint16_t PROGMEM l_rom_qu_combo[]  = {LSFTT_N, LCTLT_S, COMBO_END};
const uint16_t PROGMEM l_rom_esc_combo[] = {LOW_SPC, KC_F, KC_D, COMBO_END};
const uint16_t PROGMEM l_rom_und_combo[] = {LOW_SPC, RALTT_B, KC_C, COMBO_END};
const uint16_t PROGMEM l_rom_rai_combo[] = {LOW_SPC, LSFTT_N, COMBO_END};
const uint16_t PROGMEM l_rom_low_combo[] = {LOW_SPC, LCTLT_S, COMBO_END};
const uint16_t PROGMEM l_rom_sav_combo[] = {LOW_SPC, LSFTT_N, LCTLT_S, COMBO_END};
const uint16_t PROGMEM l_rom_usc_combo[] = {RALTT_B, KC_C, COMBO_END};
const uint16_t PROGMEM l_rom_ful_combo[] = {LOW_SPC, LCTLT_S, LGUIT_T, COMBO_END};
const uint16_t PROGMEM l_rom_fin_combo[] = {LOW_SPC, KC_C, LALTT_P, COMBO_END};

const uint16_t PROGMEM r_rom_y_combo[]   = {RGUIT_H, RCTLT_A, COMBO_END};
const uint16_t PROGMEM r_rom_p_combo[]   = {LALTT_M, TD_COMM, COMBO_END};
const uint16_t PROGMEM r_rom_x_combo[]   = {RCTLT_A, RSFTT_E, COMBO_END};
const uint16_t PROGMEM r_rom_tab_combo[] = {RAI_BSP, KC_O, KC_U, COMBO_END};
const uint16_t PROGMEM r_rom_oes_combo[] = {KC_O, KC_U, COMBO_END};
const uint16_t PROGMEM r_rom_cop_combo[] = {RAI_BSP, RGUIT_H, RCTLT_A, COMBO_END};
const uint16_t PROGMEM r_rom_pas_combo[] = {RAI_BSP, LALTT_M, TD_COMM, COMBO_END};
const uint16_t PROGMEM r_rom_ent_combo[] = {RAI_BSP, RCTLT_A, RSFTT_E, COMBO_END};
const uint16_t PROGMEM r_rom_rai_combo[] = {RAI_BSP, RCTLT_A, COMBO_END};
const uint16_t PROGMEM r_rom_low_combo[] = {RAI_BSP, RSFTT_E, COMBO_END};
const uint16_t PROGMEM r_rom_sal_combo[] = {RAI_BSP, TD_COMM, TD_DOT, COMBO_END};
const uint16_t PROGMEM r_rom_sco_combo[] = {TD_COMM, TD_DOT, COMBO_END};
const uint16_t PROGMEM r_rom_sce_combo[] = {LALTT_M, TD_COMM, TD_DOT, COMBO_END};

// Secret

const uint16_t PROGMEM secret_1_combo[] = {SEC_1, SEC_2, SEC_3, SEC_4, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [l_rom_q] = COMBO(l_rom_q_combo, KC_Q),         [l_rom_qu] = COMBO(l_rom_qu_combo, MC_QU),
    [r_rom_y] = COMBO(r_rom_y_combo, KC_Y),         [l_rom_z] = COMBO(l_rom_z_combo, KC_Z),
    [r_rom_x] = COMBO(r_rom_x_combo, KC_X),         [l_num_esc] = COMBO(l_num_esc_combo, KC_ESC),
    [l_nav_esv] = COMBO(l_nav_esv_combo, MC_ESAV),  [l_num_sav] = COMBO(l_num_sav_combo, MC_SAVE),
    [r_num_ent] = COMBO(r_num_ent_combo, KC_ENT),   [l_low_par] = COMBO(l_low_par_combo, TD_PARN),
    [r_low_tab] = COMBO(r_low_tab_combo, KC_TAB),   [r_low_ent] = COMBO(r_low_ent_combo, KC_ENT),
    [r_ng_ao] = COMBO(r_ng_ao_combo, MC_AO),        [r_ng_cu] = COMBO(r_ng_cu_combo, MC_CU),
    [r_ng_ca] = COMBO(r_ng_ca_combo, MC_CA),        [r_ng_co] = COMBO(r_ng_co_combo, MC_CO),
    [r_ng_cao] = COMBO(r_ng_cao_combo, MC_CAO),     [r_ng_oes] = COMBO(r_ng_oes_combo, MC_OES),
    [r_ng_coes] = COMBO(r_ng_coes_combo, MC_COES),  [r_mac_ref] = COMBO(r_mac_ref_combo, MC_REF),
    [r_mac_clo] = COMBO(r_mac_clo_combo, MC_CTAB),  [r_rom_cop] = COMBO(r_rom_cop_combo, MC_COPY),
    [r_rom_sco] = COMBO(r_rom_sco_combo, TD_SCLE),  [l_rom_usc] = COMBO(l_rom_usc_combo, MC_UNDS),
    [l_rom_ful] = COMBO(l_rom_ful_combo, MC_FULL),  [r_rom_p] = COMBO(r_rom_p_combo, KC_P),
    [r_rom_pas] = COMBO(r_rom_pas_combo, MC_PAST),  [l_rom_rai] = COMBO(l_rom_rai_combo, OS_RAI),
    [l_rom_low] = COMBO(l_rom_low_combo, OS_LOW),   [l_rom_sav] = COMBO(l_rom_sav_combo, MC_SAVE),
    [l_rom_esc] = COMBO(l_rom_esc_combo, KC_ESC),   [l_rom_und] = COMBO(l_rom_und_combo, MC_UNDO),
    [r_rom_sce] = COMBO(r_rom_sce_combo, MC_SENT),  [l_rom_fin] = COMBO(l_rom_fin_combo, MC_FIND),
    [r_rom_tab] = COMBO(r_rom_tab_combo, KC_TAB),   [r_rom_oes] = COMBO(r_rom_oes_combo, MC_OESC),
    [r_rom_low] = COMBO(r_rom_low_combo, OS_LOW),   [r_rom_rai] = COMBO(r_rom_rai_combo, OS_RAI),
    [r_rom_ent] = COMBO(r_rom_ent_combo, KC_ENT),   [r_rom_sal] = COMBO(r_rom_sal_combo, MC_SELC),
    [r_rai_plu] = COMBO(r_rai_plu_combo, KC_PLUS),  [r_rai_ast] = COMBO(r_rai_ast_combo, KC_ASTR),
    [r_rai_cur] = COMBO(r_rai_cur_combo, MC_CUR),   [r_med_ent] = COMBO(r_med_ent_combo, TD_EENT),
    [secret_1] = COMBO(secret_1_combo, MC_SECRET_1)};