/*
 Copyright 2014 Freescale
 Copyright 2021-2023 NXP
 NXP Confidential. This software is owned or controlled by NXP and may only
 be used strictly in accordance with the applicable license terms. By
 expressly accepting such terms or by downloading, installing, activating
 and/or otherwise using the software, you are agreeing that you have read,
 and that you agree to comply with and are bound by, such license terms. If
 you do not agree to be bound by the applicable license terms, then you may
 not retain, install, activate or otherwise use the software.
*/
.section  .vector,"a",%progbits
.align 2                        
.thumb
.globl VTABLE                    
VTABLE:                             

.long _Stack_start             /* Top of Stack for Initial Stack Pointer */
.long Reset_Handler            /* Reset Handler */
.long OSNmiException           /* NMI Handler */
.long OSHardFaultException     /* Hard Fault Handler */
.long OSReservedException      /* Reserved */
.long OSBusFaultException      /* Bus Fault Handler */
.long OSUsageFaultException    /* Usage Fault Handler */
.long OSReservedException      /* Reserved */
.long OSReservedException      /* Reserved */
.long OSReservedException      /* Reserved */
.long OSReservedException      /* Reserved */
.long OSSVCallException        /* SVCall Handler */
.long OSDebugMonitorException  /* Debug Monitor Handler */
.long OSReservedException      /* Reserved */
.long OSPendSVException        /* PendSV Handler */
.long OSInterruptDispatcher    /* SysTick Handler */

/* External interrupts 16 - 31 */
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher

/* External interrupts 32 - 47 */
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher

/* External interrupts 48 - 63 */
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher

/* External interrupts 64 - 79*/
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher

/* External interrupts 80 - 95 */
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher

/* External interrupts 96 - 111*/
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher

/* External interrupts 112 - 127 */
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher

/* External interrupts 128 - 143 */
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher

/* External interrupts 144 - 159 */
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher

/* External interrupts 160 - 175 */
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher

/* External interrupts 176 - 191 */
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher

/* External interrupts 192 - 207 */
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher

/* External interrupts 208 - 223 */
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher

/* External interrupts 224 - 239 */
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher

/* External interrupts 240 - 255*/
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher
.long OSInterruptDispatcher


.size VTABLE, . - VTABLE
