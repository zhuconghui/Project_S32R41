/******************************************************************************
*
*   NXP(TM) and the NXP logo are trademarks of NXP.
*   All other product or service names are the property of their respective owners.
*   (c) Copyright 2016 Freescale Semiconductor Inc.
*   Copyright 2021 -2023 NXP.
*   All Rights Reserved.
*
*   You can use this example for any purpose on any computer system with the
*   following restrictions:
*
*   1. This example is provided  as is , without warranty.
*
*   2. You don't remove this copyright notice from this example or any direct
*      derivation thereof.
*
* Description:    Startup code for OS/S32R41
*
* Notes:
*
******************************************************************************/
#include <Os_prop_autosar_api.h>

#if defined(OS_MULTI_INSTANCE)
#if  (0U == OS_MASTER_CORE)
.globl RESET_CATCH_CORE_0
#elif (1U == OS_MASTER_CORE)
.globl RESET_CATCH_CORE_1
#else
#error Master core is out of range
#endif
#else
.globl RESET_CATCH_CORE
#endif

.globl VTABLE

.section .startup,"ax"

.thumb

VTOR_REG .equ 0xE000ED08

.thumb_func
.align 2
.globl Reset_Handler
Reset_Handler:

DebuggerHeldCoreLoop:
    #if defined(OS_MULTI_INSTANCE)
    #if  (0U == OS_MASTER_CORE)
    ldr  r0, =RESET_CATCH_CORE_0
    #elif (1U == OS_MASTER_CORE)
    ldr  r0, =RESET_CATCH_CORE_1
    #else
    #error Master core is out of range
    #endif
    #else
    ldr  r0, =RESET_CATCH_CORE
    #endif

    ldr  r0, [r0]

    #if defined(OS_MULTI_INSTANCE)
    #if  (0U == OS_MASTER_CORE)
    ldr  r1, =0x5A5A5A5A
    #elif (1U == OS_MASTER_CORE)
    ldr  r1, =0xA5A5A5A5
    #else
    #error Master core is out of range
    #endif
    #else
    ldr  r1, =0x5A5A5A5A
    #endif

    cmp  r0, r1
    beq   DebuggerHeldCoreLoop

    /* Fill the .stack_main section with 0xDEADBEEF */
    ldr  r2, =_Stack_end
    ldr  r4, =_Stack_start
    ldr  r3, =0xDEADBEEF
    cmp  r2, r4
    beq  BypassFillPatternStk
FillPatternStk:
    str   r3, [r2]
    add   r2, r2, #4
    cmp   r2, r4
    bcc   FillPatternStk
BypassFillPatternStk: /* do nothing */

    /* TBD - set SP regs as we run from RAM not after reset */

    /* Init stack pointer */
    ldr  r0, =_Stack_start
    msr  MSP, r0

    /* relocate vector table to RAM */
    ldr  r0, =VTOR_REG
    ldr  r1, =VTABLE
    ldr  r2, =0xFFFFFF80
    and  r1, r2  /* r1 = r1 | r2 */
    str  r1,[r0]

    /* Zero fill the bss segment */
    ldr  r2, =_bss_start
    ldr  r4, =_bss_end

    mov   r3, #0

    cmp r2, r4
    beq   BypassFillZerobss
FillZerobss:
    str   r3, [r2]
    add   r2, r2, #4
    cmp   r2, r4
    bcc   FillZerobss
BypassFillZerobss:

    /* Zero fill the non cacheable bss segment */
    ldr  r2, =OS_NONCACHE_BSS_START
    ldr  r4, =OS_NONCACHE_BSS_END

    mov   r3, #0
    cmp r2, r4
    beq   BypassFillZeroNonCacheBss
FillZeroNonCacheBss:

    str   r3, [r2]
    add   r2, r2, #4
    cmp   r2, r4
    bcc   FillZeroNonCacheBss

BypassFillZeroNonCacheBss:

    /* call system initialization first */
    bl SystemInit

#if defined(MULTICORE)
    .need Core_ID_1_Startup      /*keep the Core_ID_1_Startup function to avoid compiler optimization*/
    mov r0, #0
    bl  OSHWSynch
#endif

    /* call application entry point */
    bl main

    b . /* in case main returns */

.endf Reset_Handler



.align 2
.globl Core_ID_1_Startup
Core_ID_1_Startup:

    /* Fill the .stack2_main section with 0xDEADBEEF */
    ldr  r2, =_Stack2_end
    ldr  r4, =_Stack2_start
    ldr  r3, =0xDEADBEEF
    cmp  r2, r4
    beq  BypassFillPatternStk2
FillPatternStk2:
    str   r3, [r2]
    add   r2, r2, #4
    cmp   r2, r4
    bcc   FillPatternStk2
BypassFillPatternStk2: /* do nothing */

    /* TBD - set SP regs as we run from RAM not after reset */

    /* Init stack pointer */
    /* ldr  SP, =_Stack2_start*/
    ldr  r0, =_Stack2_start
    msr  MSP, r0

    /* relocate vector table to RAM */
    ldr  r0, =VTOR_REG
    ldr  r1, =VTABLE
    ldr  r2, =(1 << 29)
    orr  r1, r2  /* r1 = r1 | r2 */
    str  r1,[r0]

    /* Enable FPU */
#if defined(FPUHARD)
    ldr  r3, =0xE000ED88   /*CPACR reg*/
    ldr  r4, =0x00F00000   /*give access to CP10 and CP11*/
    str  r4, [r3]
#endif

#if defined(MULTICORE)
    mov r0, #0
    bl  OSHWSynch
#endif
    /* call application entry point */
    bl main

    b . /* in case main returns */

.endf Core_ID_1_Startup


.section .stack_main,"aw"
.align 4
#ifdef __STACK_SIZE
Stack_Size .equ __STACK_SIZE
#else
Stack_Size .equ  0x1000
#endif
.space Stack_Size


.section .stack2_main,"aw"
.align 4
#ifdef __STACK_SIZE
Stack2_Size .equ __STACK_SIZE
#else
Stack2_Size .equ  0x1000
#endif
.space Stack2_Size
