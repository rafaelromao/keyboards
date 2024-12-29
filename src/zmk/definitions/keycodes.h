#pragma once

#include <dt-bindings/zmk/hid_usage.h>
#include <dt-bindings/zmk/hid_usage_pages.h>
#include <dt-bindings/zmk/modifiers.h>

// clang-format off

#define QU_TERM       0x070101
#define AACU_TERM     0x070102
#define EACU_TERM     0x070103
#define IACU_TERM     0x070104
#define OACU_TERM     0x070105
#define UACU_TERM     0x070106
#define ACIR_TERM     0x070107
#define ECIR_TERM     0x070108
#define OCIR_TERM     0x070109
#define ATIL_TERM     0x07010a
#define OTIL_TERM     0x07010b
#define AGRV_TERM     0x07010c
#define SQUO_TERM     0x07010d

#define C_QU_TERM     0x07010e
#define C_AACU_TERM   0x07010f
#define C_EACU_TERM   0x070110
#define C_IACU_TERM   0x070111
#define C_OACU_TERM   0x070112
#define C_UACU_TERM   0x070113
#define C_ACIR_TERM   0x070114
#define C_ECIR_TERM   0x070115
#define C_OCIR_TERM   0x070116
#define C_ATIL_TERM   0x070117
#define C_OTIL_TERM   0x070118
#define C_AGRV_TERM   0x070119
#define C_SQUO_TERM   0x07011a

#define S_QU_TERM     0x07011b
#define S_AACU_TERM   0x07011c
#define S_EACU_TERM   0x07011d
#define S_IACU_TERM   0x07011e
#define S_OACU_TERM   0x070120
#define S_UACU_TERM   0x070121
#define S_ACIR_TERM   0x070122
#define S_ECIR_TERM   0x070123
#define S_OCIR_TERM   0x070124
#define S_ATIL_TERM   0x070125
#define S_OTIL_TERM   0x070126
#define S_AGRV_TERM   0x070127  // This is the last code available

#define CCED_TERM     ACIR_TERM     // Reuse codes that does not conflict
#define C_CCED_TERM   C_ACIR_TERM
#define S_CCED_TERM   S_ACIR_TERM

