/******************************************************************************
*
*  Copyright 2014 Freescale
*  Copyright 2017-2023 NXP
*  NXP Confidential. This software is owned or controlled by NXP and may only
*  be used strictly in accordance with the applicable license terms. By
*  expressly accepting such terms or by downloading, installing, activating
*  and/or otherwise using the software, you are agreeing that you have read,
*  and that you agree to comply with and are bound by, such license terms. If
*  you do not agree to be bound by the applicable license terms, then you may
*  not retain, install, activate or otherwise use the software.
*
* Description:    Startup code for OS/SAF85XX
*
* Notes:
*
******************************************************************************/

.syntax unified
.cpu cortex-m7

.globl VTABLE

.section .startup

.thumb
.thumb_func

.equiv VTOR_REG, 0xE000ED08


.align 4
.globl Reset_Handler
.type Reset_Handler, %function
Reset_Handler:


/* TBD - set SP regs as we run from RAM not after reset */

/* Init stack pointer */
ldr  r0, =_Stack_start
msr  MSP, r0

/* relocate vector table to RAM */
ldr  r0, =VTOR_REG
ldr  r1, =VTABLE
//ldr  r2, =0xFFFFFF80
//and  r1, r2  /* r1 = r1 | r2 */
str  r1,[r0]

//* Zero fill the bss segment */
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

/* call application entry point */
bl main

b . /* in case main returns */

.pool
.size Reset_Handler, . - Reset_Handler





.align 2
.globl Core_ID_1_Startup

Core_ID_1_Startup:

#/* TBD - set SP regs as we run from RAM not after reset */

    #/* ldr  SP, =_Stack2_start*/

    #/* relocate vector table to RAM */
    ldr  r0, =VTOR_REG
    ldr  r1, =VTABLE
    ldr  r2, =(1 << 29)
    orr  r1, r2  /* r1 = r1 | r2 */
    str  r1,[r0]

    /* call application entry point */
    bl main

    b . /* in case main returns */

.align 2

.section .stack_main
.align 3
#ifdef __STACK_SIZE
.set Stack_Size, __STACK_SIZE
#else
.set Stack_Size, 0x4000
#endif
.space Stack_Size


.section .stack2_main
.align 3
#ifdef __STACK_SIZE
.set Stack2_Size, __STACK_SIZE
#else
.set Stack2_Size, 0x1000
#endif
.space Stack2_Size

