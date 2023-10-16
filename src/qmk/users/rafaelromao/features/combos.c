#include QMK_KEYBOARD_H

#include "combos.h"

// Numpad

const uint16_t PROGMEM l_num_f10_combo[] = {KC_F2, AL_F1, COMBO_END};
const uint16_t PROGMEM l_num_f11_combo[] = {CT_F5, GU_F4, COMBO_END};
const uint16_t PROGMEM l_num_esc_combo[] = {KC_F9, KC_F8, COMBO_END};
const uint16_t PROGMEM l_num_sav_combo[] = {KC_SPC, SF_F6, CT_F5, COMBO_END};
const uint16_t PROGMEM r_num_ent_combo[] = {RAI_SPC, CT_5, SF_6, COMBO_END};
const uint16_t PROGMEM r_num_bsp_combo[] = {KC_8, KC_9, COMBO_END};
const uint16_t PROGMEM r_num_tab_combo[] = {RAI_SPC, KC_8, KC_9, COMBO_END};
const uint16_t PROGMEM l_num_num_combo[] = {SF_F6, CT_F5, COMBO_END};
const uint16_t PROGMEM r_num_npd_combo[] = {RAI_SPC, MED_0, COMBO_END};
const uint16_t PROGMEM r_num_com_combo[] = {RAI_SPC, SHO_DOT, COMBO_END};

// Lower

const uint16_t PROGMEM l_low_cur_combo[] = {TD_LCRB, TD_RCRB, COMBO_END};
const uint16_t PROGMEM l_low_par_combo[] = {TD_OPAR, TD_CPAR, COMBO_END};
const uint16_t PROGMEM l_low_bra_combo[] = {TD_OBR, TD_CBR, COMBO_END};

const uint16_t PROGMEM r_low_ent_combo[] = {SYM_SPC, KC_5, KC_6, COMBO_END};
const uint16_t PROGMEM r_low_sco_combo[] = {KC_2, KC_3, COMBO_END};
const uint16_t PROGMEM r_low_com_combo[] = {SYM_SPC, SHO_DOT, COMBO_END};

// Raise

const uint16_t PROGMEM l_rai_f10_combo[]  = {KC_F2, KC_F1, COMBO_END};
const uint16_t PROGMEM l_rai_f11_combo[]  = {KC_F4, KC_F5, COMBO_END};
const uint16_t PROGMEM l_rai_f12_combo[]  = {KC_F7, KC_F8, COMBO_END};
const uint16_t PROGMEM l_rai_f13_combo[]  = {KC_F2, KC_F3, COMBO_END};
const uint16_t PROGMEM l_rai_f14_combo[]  = {KC_F5, KC_F6, COMBO_END};
const uint16_t PROGMEM l_rai_f15_combo[]  = {KC_F8, KC_F9, COMBO_END};

const uint16_t PROGMEM r_rai_lt_combo[]   = {TD_EXLM, TD_AND, COMBO_END};
const uint16_t PROGMEM r_rai_gt_combo[]   = {TD_AND, TD_OR, COMBO_END};
const uint16_t PROGMEM r_rai_ltgt_combo[] = {TD_EXLM, TD_AND, TD_OR, COMBO_END};
const uint16_t PROGMEM r_rai_dcol_combo[] = {TD_COLN, TD_EQL, COMBO_END};
const uint16_t PROGMEM r_rai_sar_combo[]  = {TD_MINS, TD_PLUS, COMBO_END};
const uint16_t PROGMEM r_rai_deq_combo[]  = {TD_PLUS, TD_SLSH, COMBO_END};
const uint16_t PROGMEM r_rai_neq_combo[]  = {TD_MINS, TD_PLUS, TD_SLSH, COMBO_END};
const uint16_t PROGMEM r_rai_bsp_combo[]  = {TD_EQL, TD_PERC, COMBO_END};

// Navigation

const uint16_t PROGMEM l_nav_esc_combo[] = {MC_ESC, MC_SAVE, COMBO_END};
const uint16_t PROGMEM r_nav_ent_combo[] = {KC_SPC, KC_DOWN, KC_UP, COMBO_END};
const uint16_t PROGMEM r_nav_bsp_combo[] = {KC_PGDN, KC_PGUP, COMBO_END};
const uint16_t PROGMEM r_nav_cop_combo[] = {KC_SPC, KC_LEFT, KC_DOWN, COMBO_END};
const uint16_t PROGMEM r_nav_pas_combo[] = {KC_SPC, KC_DEL, KC_HOME, COMBO_END};

// Media

const uint16_t PROGMEM r_med_ent_combo[] = {KC_ENT, KC_TAB, COMBO_END};

// Shortcuts

const uint16_t PROGMEM l_sho_bui_combo[] = {MC_RUN, MC_DBUG, COMBO_END};
const uint16_t PROGMEM l_sho_ref_combo[] = {MC_COMP, MC_FIUS, COMBO_END};
const uint16_t PROGMEM r_sho_z0r_combo[] = {MC_MODM, SF_MODP, COMBO_END};
const uint16_t PROGMEM r_sho_clo_combo[] = {MC_SWLE, MC_SWRI, COMBO_END};
const uint16_t PROGMEM r_sho_dyn_combo[] = {MC_SELL, MC_MODM, COMBO_END};
const uint16_t PROGMEM r_sho_joi_combo[] = {MC_COMT, MC_SWLE, COMBO_END};

// Symbols

const uint16_t PROGMEM l_sym_cur_combo[]  = {TD_LCRB, TD_RCRB, COMBO_END};
const uint16_t PROGMEM l_sym_par_combo[]  = {TD_OPAR, TD_CPAR, COMBO_END};
const uint16_t PROGMEM l_sym_bra_combo[]  = {TD_OBR, TD_CBR, COMBO_END};
const uint16_t PROGMEM l_sym_squo_combo[] = {TD_RCRB, TD_HASH, COMBO_END};
const uint16_t PROGMEM l_sym_dquo_combo[] = {TD_CPAR, TD_DQUO, COMBO_END};
const uint16_t PROGMEM l_sym_btic_combo[] = {TD_CBR, TD_QUES, COMBO_END};

const uint16_t PROGMEM r_sym_circ_combo[] = {TD_COLN, TD_EQL, COMBO_END};
const uint16_t PROGMEM r_sym_dol_combo[]  = {TD_MINS, TD_PLUS, COMBO_END};
const uint16_t PROGMEM r_sym_til_combo[]  = {TD_EXLM, TD_AND, COMBO_END};
const uint16_t PROGMEM r_sym_sec_combo[]  = {TD_MINS, TD_PLUS, TD_SLSH, COMBO_END};
const uint16_t PROGMEM r_sym_eur_combo[]  = {TD_PLUS, TD_SLSH, COMBO_END};
const uint16_t PROGMEM r_sym_bsl_combo[]  = {TD_AND, TD_OR, COMBO_END};

// Alpha 2

const uint16_t PROGMEM l_acc_esc_combo[]  = {KC_Q, MC_QU, COMBO_END};
const uint16_t PROGMEM l_acc_ja_combo[]   = {KC_J, MC_SQ_C, COMBO_END};
const uint16_t PROGMEM l_acc_hash_combo[] = {MC_QU, KC_K, COMBO_END};
const uint16_t PROGMEM l_acc_lpa_combo[]  = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM l_acc_rpa_combo[]  = {KC_X, KC_W, COMBO_END};
const uint16_t PROGMEM l_acc_ques_combo[] = {MC_SQ_C, KC_V, COMBO_END};

const uint16_t PROGMEM r_acc_bsp_combo[]  = {MC_SQ_O, MC_SQ_U, COMBO_END};
const uint16_t PROGMEM r_acc_tab_combo[]  = {RAI_A2, MC_SQ_O, MC_SQ_U, COMBO_END};
const uint16_t PROGMEM r_acc_col_combo[]  = {MC_GV_A, MC_SQ_O, COMBO_END};
const uint16_t PROGMEM r_acc_min_combo[]  = {MC_TL_A, MC_SQ_A, COMBO_END};
const uint16_t PROGMEM r_acc_excl_combo[] = {MC_CR_A, MC_CR_O, COMBO_END};
const uint16_t PROGMEM r_acc_eur_combo[]  = {MC_GV_A, MC_SQ_O, MC_SQ_U, COMBO_END};
const uint16_t PROGMEM r_acc_ao_combo[]   = {MC_SQ_A, MC_SQ_E, COMBO_END};
const uint16_t PROGMEM r_acc_oe_combo[]   = {MC_CR_O, MC_CR_E, COMBO_END};
const uint16_t PROGMEM r_acc_cao_combo[]  = {MC_TL_A, MC_SQ_A, MC_SQ_E, COMBO_END};
const uint16_t PROGMEM r_acc_coes_combo[] = {MC_CR_A, MC_CR_O, MC_CR_E, COMBO_END};

// Alpha 1

const uint16_t PROGMEM l_rom_num_combo[] = {LSFTT_N, LCTLT_S, COMBO_END};
const uint16_t PROGMEM l_rom_cap_combo[] = {NAV_REP, LOW_SPC, COMBO_END};
const uint16_t PROGMEM r_rom_npd_combo[] = {RAI_A2, MED_CAS, COMBO_END};

const uint16_t PROGMEM l_rom_k_combo[]   = {KC_M, KC_G, COMBO_END};
const uint16_t PROGMEM l_rom_w_combo[]   = {LCTLT_S, LGUIT_T, COMBO_END};
const uint16_t PROGMEM l_rom_v_combo[]   = {KC_C, LALTT_P, COMBO_END};
const uint16_t PROGMEM l_rom_esc_combo[] = {KC_B, KC_M, COMBO_END};
const uint16_t PROGMEM l_rom_esv_combo[] = {LOW_SPC, KC_B, KC_M, COMBO_END};
const uint16_t PROGMEM l_rom_und_combo[] = {LOW_SPC, RALTT_F, KC_C, COMBO_END};
const uint16_t PROGMEM l_rom_sav_combo[] = {LOW_SPC, LSFTT_N, LCTLT_S, COMBO_END};
const uint16_t PROGMEM l_rom_usc_combo[] = {RALTT_F, KC_C, COMBO_END};
const uint16_t PROGMEM l_rom_ful_combo[] = {LOW_SPC, LCTLT_S, LGUIT_T, COMBO_END};
const uint16_t PROGMEM l_rom_fin_combo[] = {LOW_SPC, KC_C, LALTT_P, COMBO_END};

const uint16_t PROGMEM r_rom_zj_combo[]   = {KC_L, KC_O, COMBO_END};
const uint16_t PROGMEM r_rom_y_combo[]    = {RGUIT_R, RCTLT_A, COMBO_END};
const uint16_t PROGMEM r_rom_pq_combo[]   = {RALTT_H, TD_COMM, COMBO_END};
const uint16_t PROGMEM r_rom_x_combo[]    = {RCTLT_A, RSFTT_E, COMBO_END};
const uint16_t PROGMEM r_rom_d_combo[]    = {RGUIT_R, RCTLT_A, RSFTT_E, COMBO_END};
const uint16_t PROGMEM r_rom_cop_combo[]  = {RAI_A2, RGUIT_R, RCTLT_A, COMBO_END};
const uint16_t PROGMEM r_rom_pas_combo[]  = {RAI_A2, RALTT_H, TD_COMM, COMBO_END};
const uint16_t PROGMEM r_rom_ent_combo[]  = {RAI_A2, RCTLT_A, RSFTT_E, COMBO_END};
const uint16_t PROGMEM r_rom_bsp_combo[]  = {KC_O, KC_U, COMBO_END};
const uint16_t PROGMEM r_rom_tab_combo[]  = {RAI_A2, KC_O, KC_U, COMBO_END};
const uint16_t PROGMEM r_rom_sal_combo[]  = {RAI_A2, TD_COMM, TD_DOT, COMBO_END};
const uint16_t PROGMEM r_rom_sco_combo[]  = {TD_COMM, TD_DOT, COMBO_END};
const uint16_t PROGMEM r_rom_scp_combo[]  = {RAI_A2, RGUIT_R, RCTLT_A, RSFTT_E, COMBO_END};
const uint16_t PROGMEM r_rom_spa_combo[]  = {RAI_A2, RALTT_H, TD_COMM, TD_DOT, COMBO_END};
const uint16_t PROGMEM r_rom_sent_combo[] = {RALTT_H, TD_COMM, TD_DOT, COMBO_END};

// Media

const uint16_t PROGMEM r_med_epa_combo[]  = {KC_MPLY, KC_MPRV, COMBO_END};
const uint16_t PROGMEM r_med_vis_combo[]  = {KC_MPRV, KC_MNXT, COMBO_END};
const uint16_t PROGMEM r_med_oes_combo[]  = {HYPR_R, KC_VOLD, COMBO_END};
const uint16_t PROGMEM r_med_soe_combo[]  = {KC_VOLD, KC_VOLU, COMBO_END};

// Secret

const uint16_t PROGMEM secret_1_combo[] = {SEC_1, SEC_2, SEC_3, SEC_4, COMBO_END};

combo_t key_combos[] = {
    COMBO(l_sym_cur_combo, MC_CURS),   COMBO(l_sym_par_combo, TD_PARN),  COMBO(l_sym_bra_combo, MC_BRAC),
    COMBO(l_sym_squo_combo, MC_SQUO),  COMBO(l_sym_dquo_combo, MC_DQUO), COMBO(l_sym_btic_combo, MC_BTIC),
    COMBO(r_sym_circ_combo, MC_CIRC),  COMBO(r_sym_dol_combo, KC_DLR),   COMBO(r_sym_til_combo, MC_TILD),
    COMBO(r_sym_sec_combo, MC_SEC),    COMBO(r_sym_eur_combo, MC_EUR),   COMBO(r_sym_bsl_combo, KC_BSLS),
    COMBO(r_low_com_combo, KC_COMM),   COMBO(r_num_com_combo, KC_COMM),  COMBO(l_acc_esc_combo, MC_ESCC),
    COMBO(l_acc_ja_combo, MC_JA),      COMBO(l_acc_ques_combo, MC_QUES), COMBO(l_acc_hash_combo, KC_HASH),
    COMBO(l_low_cur_combo, MC_CUR),    COMBO(l_low_bra_combo, MC_BRAC),  COMBO(l_low_par_combo, TD_PARN),
    COMBO(l_nav_esc_combo, MC_ESCC),   COMBO(l_num_esc_combo, MC_ESCC),  COMBO(l_num_f10_combo, KC_F10),
    COMBO(l_num_f11_combo, KC_F11),    COMBO(l_num_num_combo, TO_A1),    COMBO(l_num_sav_combo, MC_SAVE),
    COMBO(l_rai_f10_combo, KC_F10),    COMBO(l_rai_f11_combo, KC_F11),   COMBO(l_rai_f12_combo, KC_F12),
    COMBO(l_rai_f13_combo, KC_F13),    COMBO(l_rai_f14_combo, KC_F14),   COMBO(l_rai_f15_combo, KC_F15),
    COMBO(l_rom_cap_combo, TG_CAPS),   COMBO(l_rom_esc_combo, MC_ESCC),  COMBO(l_rom_esv_combo, MC_ESAV),
    COMBO(l_rom_fin_combo, MC_FIND),   COMBO(l_rom_ful_combo, MC_FULL),  COMBO(l_rom_k_combo, KC_K),
    COMBO(l_rom_num_combo, TG_NUMC),   COMBO(l_rom_sav_combo, MC_SAVE),  COMBO(l_rom_und_combo, MC_UNDO),
    COMBO(l_rom_usc_combo, KC_UNDS),   COMBO(l_rom_v_combo, KC_V),       COMBO(l_rom_w_combo, KC_W),
    COMBO(l_acc_lpa_combo, KC_LPRN),   COMBO(l_acc_rpa_combo, KC_RPRN),  COMBO(l_sho_bui_combo, MC_BUID),
    COMBO(l_sho_ref_combo, MC_REFC),   COMBO(r_acc_ao_combo, MC_AO),     COMBO(r_acc_bsp_combo, KC_BSPC),
    COMBO(r_acc_cao_combo, MC_CAO),    COMBO(r_acc_coes_combo, MC_COES), COMBO(r_acc_col_combo, KC_COLN),
    COMBO(r_acc_eur_combo, MC_EUR),    COMBO(r_acc_excl_combo, MC_EXLM), COMBO(r_acc_min_combo, KC_MINS),
    COMBO(r_acc_oe_combo, MC_OE),      COMBO(r_low_ent_combo, KC_ENT),   COMBO(r_low_sco_combo, TD_SCLE),
    COMBO(r_med_ent_combo, TD_EENT),   COMBO(r_med_epa_combo, MC_EPA),   COMBO(r_med_vis_combo, MC_VIS),
    COMBO(r_med_oes_combo, MC_OESC),   COMBO(r_med_soe_combo, MC_SOES),  COMBO(r_nav_bsp_combo, KC_BSPC),
    COMBO(r_nav_cop_combo, MC_COPY),   COMBO(r_nav_ent_combo, KC_ENT),   COMBO(r_nav_pas_combo, MC_PAST),
    COMBO(r_num_bsp_combo, KC_BSPC),   COMBO(r_num_ent_combo, KC_ENT),   COMBO(r_num_npd_combo, TG_NUM),
    COMBO(r_num_tab_combo, KC_TAB),    COMBO(r_rai_bsp_combo, KC_BSPC),  COMBO(r_rai_deq_combo, MC_DEQ),
    COMBO(r_rai_gt_combo, TD_GT),      COMBO(r_rai_lt_combo, TD_LT),     COMBO(r_rai_ltgt_combo, MC_LTGT),
    COMBO(r_rai_neq_combo, MC_NEQ),    COMBO(r_rai_dcol_combo, TD_DCOL), COMBO(r_rai_sar_combo, TD_SARR),
    COMBO(r_rom_bsp_combo, KC_BSPC),   COMBO(r_rom_cop_combo, MC_COPY),  COMBO(r_rom_d_combo, KC_D),
    COMBO(r_rom_ent_combo, KC_ENT),    COMBO(r_rom_npd_combo, TG_NUM),   COMBO(r_rom_pq_combo, TD_PQ),
    COMBO(r_rom_pas_combo, MC_PAST),   COMBO(r_rom_sal_combo, MC_SELC),  COMBO(r_rom_sco_combo, TD_SCLE),
    COMBO(r_rom_scp_combo, MC_SCOP),   COMBO(r_rom_sent_combo, MC_SENT), COMBO(r_rom_spa_combo, MC_SPAS),
    COMBO(r_rom_tab_combo, KC_TAB),    COMBO(r_acc_tab_combo, KC_TAB),   COMBO(r_rom_zj_combo, TD_ZJ),
    COMBO(r_rom_x_combo, KC_X),        COMBO(r_rom_y_combo, KC_Y),       COMBO(r_sho_clo_combo, MC_CLOS),
    COMBO(r_sho_dyn_combo, TD_MACR),   COMBO(r_sho_joi_combo, MC_JOIN),  COMBO(r_sho_z0r_combo, MC_Z0R),
    COMBO(secret_1_combo, MC_SECRET_1)};

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    switch (combo->keycode) {
        case KC_F13:
        case KC_F14:
        case KC_F15:
            if (layer_state_is(_NUMPAD)) {
                return false;
            }
        case MC_CUR:
        case TD_SARR:
        case TD_DCOL:
        case TD_LT:
        case TD_GT:
        case MC_DEQ:
        case MC_LTGT:
        case MC_NEQ:
            if (layer_state_is(_SYMBOLS)) {
                return false;
            }
    }
    return true;
}