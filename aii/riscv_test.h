// See LICENSE for license details.

#ifndef _ENV_PHYSICAL_SINGLE_CORE_H
#define _ENV_PHYSICAL_SINGLE_CORE_H

#include "../encoding.h"

//-----------------------------------------------------------------------
// Begin Macro
//-----------------------------------------------------------------------

#define RVTEST_RV64U
#define RVTEST_RV64UF
#define RVTEST_RV32U
#define RVTEST_RV32UF
#define RVTEST_RV64M
#define RVTEST_RV64S
#define RVTEST_RV32M
#define RVTEST_RV32S

#define RVTEST_CODE_BEGIN                                               \
        .section .text.init;                                            \
        .align  4;                                                      \
        .globl _start;                                                  \
_start:                                                                 \
		li a0, 0;                                                       \
1:

//-----------------------------------------------------------------------
// End Macro
//-----------------------------------------------------------------------

#define RVTEST_CODE_END                                                 \
       li a0, 0x0823;                                                   \
       ecall;

//-----------------------------------------------------------------------
// Pass/Fail Macro
//-----------------------------------------------------------------------

#define RVTEST_PASS                                                     \
       li a0, 0x0400;                                                   \
       li a1, 0x50;                                                     \
       sb a1, (a0);                                                     \
       li a0, 0x0823;                                                   \
       ecall;

#define TESTNUM gp
#define RVTEST_FAIL                                                     \
       li a0, 0x0400;                                                   \
       li a1, 0x46;                                                     \
       sb a1, (a0);                                                     \
       li a0, 0x0823;                                                   \
       ecall;

//-----------------------------------------------------------------------
// Data Section Macro
//-----------------------------------------------------------------------

#define EXTRA_DATA

#define RVTEST_DATA_BEGIN                                               \
        EXTRA_DATA                                                      \
        .align 4; .global begin_signature; begin_signature:

#define RVTEST_DATA_END .align 4; .global end_signature; end_signature:

#endif
