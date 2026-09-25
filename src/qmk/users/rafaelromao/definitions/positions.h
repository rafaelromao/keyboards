#pragma once

// The 36 ZMK key positions (src/definitions/config.dtsi) as the keycodes they
// hold on ALPHA1. Combos are written with these and combo_ref_from_layer()
// always answers ALPHA1, which makes a QMK combo the same physical chord on
// every layer, the way ZMK's position-based combos are.
//
//   LTP LTR LTM LTI LTC | RTC RTI RTM RTR RTP
//   LHP LHR LHM LHI LHC | RHC RHI RHM RHR RHP
//   LBP LBR LBM LBI LBC | RBC RBI RBM RBR RBP
//           L2  L1  L0  | R0  R1  R2

#define P_LTP KC_Q
#define P_LTR KC_B
#define P_LTM KC_M
#define P_LTI KC_G
#define P_LTC KC_K
#define P_RTC KC_X
#define P_RTI KC_L
#define P_RTM KC_O
#define P_RTR KC_U
#define P_RTP KC_SCLN

#define P_LHP LT_D
#define P_LHR HRM_N
#define P_LHM HRM_S
#define P_LHI HRM_T
#define P_LHC KC_W
#define P_RHC KC_Z
#define P_RHI HRM_R
#define P_RHM HRM_A
#define P_RHR HRM_E
#define P_RHP LT_I

#define P_LBP KC_Y
#define P_LBR HRM_F
#define P_LBM HRM_C
#define P_LBI HRM_P
#define P_LBC KC_V
#define P_RBC KC_J
#define P_RBI MAGIC_KEY
#define P_RBM TH(TH_COMMA)
#define P_RBR TH(TH_DOT)
#define P_RBP KC_SLSH

#define P_L2 MS_BTN2
#define P_L1 L1_KEY
#define P_L0 L0_KEY
#define P_R0 R0_KEY
#define P_R1 R1_KEY
#define P_R2 MS_BTN1
