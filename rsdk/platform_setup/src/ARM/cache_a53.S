/**************************************************************************************************
 * 
 * NXP Confidential Proprietary
 *
 * Copyright 2016-2021 NXP 
 * All Rights Reserved
 *
 *****************************************************************************
 *
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 *
 **************************************************************************************************/

.section ".texts","ax"

.align    16
  
/* ------------------------------------------
* Clean+Invalidate from base address till size. 'x0' = addr, 'x1' = size
* No alignment restrictions apply for this address, according to the ARMv8 Architecture Reference Manual
* ------------------------------------------*/

.global FlushAndInvalidateDcacheRange
FlushAndInvalidateDcacheRange:
  mrs x3, CTR_EL0
  ubfx  x3, x3, #16, #4
  mov x2, #4
  lsl x2, x2, x3
  add x1, x0, x1
  sub x3, x2, #1
  bic x0, x0, x3
dflushinvalidate_loop:
  dc  civac, x0
  add x0, x0, x2
  cmp x0, x1
  b.lo    dflushinvalidate_loop
  dsb sy
  ret
  
.global InvalidateDcacheRange
InvalidateDcacheRange:
  mrs x3, CTR_EL0
  ubfx  x3, x3, #16, #4
  mov x2, #4
  lsl x2, x2, x3
  add x1, x0, x1
  sub x3, x2, #1
  bic x0, x0, x3
inv_dflush_loop:
  dc  ivac, x0
  add x0, x0, x2
  cmp x0, x1
  b.lo    inv_dflush_loop
  dsb ish
  ret
  
.global FlushDcacheRange
FlushDcacheRange:
  mrs x3, CTR_EL0
  ubfx  x3, x3, #16, #4
  mov x2, #4
  lsl x2, x2, x3
  add x1, x0, x1
  sub x3, x2, #1
  bic x0, x0, x3
dflush_loop:
  dc  cvac, x0
  add x0, x0, x2
  cmp x0, x1
  b.lo    dflush_loop
  dsb sy
  ret
    

