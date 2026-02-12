/**************************************************************************************************
*
* Copyright 2019-2021 NXP
* All Rights Reserved
*
**************************************************************************************************
*
* NXP Confidential Proprietary. This software is owned or controlled by NXP and may only be used
* strictly in accordance with the applicable license terms. By expressly accepting
* such terms or by downloading, installing, activating and/or otherwise using the software, you
* are agreeing that you have read, and that you agree to comply with and are bound by, such
* license terms. If you do not agree to be bound by the applicable license terms, then you
* may not retain, install, activate or otherwise use the software.
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
/**************************************************************************************************
@file       gic_cpu_gcc.h
@author     G.Kerr
@date       19 Dec 2019
**************************************************************************************************/
#ifndef GIC_CPU_GCC_H
#define GIC_CPU_GCC_H

#include "cmsis_gcc.h"

/**************************************************************************************************
 GIC CPU Interface Registers - Getters and Setters
**************************************************************************************************/

/*
 * Interrupt Controller System Register Enable register EL1 (ICC_SRE_EL1)
 */

__STATIC_FORCEINLINE void __set_ICC_SRE_EL1(uint64_t x)
{
    __ASM volatile("MSR S3_0_C12_C12_5, %0" : : "r"(x) : "memory");
}

__STATIC_FORCEINLINE uint64_t __get_ICC_SRE_EL1(void)
{
    uint64_t result;
    __ASM volatile("MRS %0, S3_0_C12_C12_5" : "=r"(result) : : "memory");
    return result;
}

/*
 * Interrupt Controller System Register Enable register EL2 (ICC_SRE_EL2)
 */

__STATIC_FORCEINLINE void __set_ICC_SRE_EL2(uint64_t x)
{
    __ASM volatile("MSR S3_4_C12_C9_5, %0" : : "r"(x) : "memory");
}

__STATIC_FORCEINLINE uint64_t __get_ICC_SRE_EL2(void)
{
    uint64_t result;
    __ASM volatile("MRS %0, S3_4_C12_C9_5" : "=r"(result) : : "memory");
    return result;
}

/*
 * Interrupt Controller System Register Enable register EL3 (ICC_SRE_EL3)
 */

__STATIC_FORCEINLINE void __set_ICC_SRE_EL3(uint64_t x)
{
    __ASM volatile("MSR S3_6_C12_C12_5, %0" : : "r"(x) : "memory");
}

__STATIC_FORCEINLINE uint64_t __get_ICC_SRE_EL3(void)
{
    uint64_t result;
    __ASM volatile("MRS %0, S3_6_C12_C12_5" : "=r"(result) : : "memory");
    return result;
}

/*
 * Interrupt Controller Interrupt Group 1 Enable register EL3 (ICC_IGRPEN1_EL3)
 */

__STATIC_FORCEINLINE void __set_ICC_IGRPEN1_EL3(uint64_t x)
{
    __ASM volatile("MSR S3_6_C12_C12_7, %0" : : "r"(x) : "memory");
}

__STATIC_FORCEINLINE uint64_t __get_ICC_IGRPEN1_EL3(void)
{
    uint64_t result;
    __ASM volatile("MRS %0, S3_6_C12_C12_7" : "=r"(result) : : "memory");
    return result;
}

/*
 * Interrupt Controller Interrupt Group 0 Enable register EL1 (ICC_IGRPEN0_EL1)
 */

__STATIC_FORCEINLINE void __set_ICC_IGRPEN0_EL1(uint64_t x)
{
    __ASM volatile("MSR S3_0_C12_C12_6, %0" : : "r"(x) : "memory");
}

__STATIC_FORCEINLINE uint64_t __get_ICC_IGRPEN0_EL1(void)
{
    uint64_t result;
    __ASM volatile("MRS %0, S3_0_C12_C12_6" : "=r"(result) : : "memory");
    return result;
}

/*
 * Interrupt Controller Interrupt Group 1 Enable register EL1 (ICC_IGRPEN1_EL1)
 */

__STATIC_FORCEINLINE void __set_ICC_IGRPEN1_EL1(uint64_t x)
{
    __ASM volatile("MSR S3_0_C12_C12_7, %0" : : "r"(x) : "memory");
}

__STATIC_FORCEINLINE uint64_t __get_ICC_IGRPEN1_EL1(void)
{
    uint64_t result;
    __ASM volatile("MRS %0, S3_0_C12_C12_7" : "=r"(result) : : "memory");
    return result;
}

/*
 * Interrupt Controller Interrupt Priority Mask Register EL1 (ICC_PMR_EL1)
 */

__STATIC_FORCEINLINE void __set_ICC_PMR_EL1(uint64_t x)
{
    __ASM volatile("MSR S3_0_C4_C6_0, %0" : : "r"(x) : "memory");
}

__STATIC_FORCEINLINE uint64_t __get_ICC_PMR_EL1(void)
{
    uint64_t result;
    __ASM volatile("MRS %0, S3_0_C4_C6_0" : "=r"(result) : : "memory");
    return result;
}

/*
 * Interrupt Controller Binary Point Register 0 EL1 (ICC_BPR0_EL1)
 */

__STATIC_FORCEINLINE void __set_ICC_BPR0_EL1(uint64_t x)
{
    __ASM volatile("MSR S3_0_C12_C8_3, %0" : : "r"(x) : "memory");
}

__STATIC_FORCEINLINE uint64_t __get_ICC_BPR0_EL1(void)
{
    uint64_t result;
    __ASM volatile("MRS %0, S3_0_C12_C8_3" : "=r"(result) : : "memory");
    return result;
}

/*
 * Interrupt Controller Binary Point Register 1 EL1 (ICC_BPR1_EL1)
 */

__STATIC_FORCEINLINE void __set_ICC_BPR1_EL1(uint64_t x)
{
    __ASM volatile("MSR S3_0_C12_C12_3, %0" : : "r"(x) : "memory");
}

__STATIC_FORCEINLINE uint64_t __get_ICC_BPR1_EL1(void)
{
    uint64_t result;
    __ASM volatile("MRS %0, S3_0_C12_C12_3" : "=r"(result) : : "memory");
    return result;
}

/*
 * Interrupt Controller Control Register EL1 (ICC_CTLR_EL1)
 */

__STATIC_FORCEINLINE void __set_ICC_CTLR_EL1(uint64_t x)
{
    __ASM volatile("MSR S3_0_C12_C12_4, %0" : : "r"(x) : "memory");
}

__STATIC_FORCEINLINE uint64_t __get_ICC_CTLR_EL1(void)
{
    uint64_t result;
    __ASM volatile("MRS %0, S3_0_C12_C12_4" : "=r"(result) : : "memory");
    return result;
}

/*
 * Interrupt Controller Control Register EL3 (ICC_CTLR_EL3)
 */

__STATIC_FORCEINLINE void __set_ICC_CTLR_EL3(uint64_t x)
{
    __ASM volatile("MSR S3_6_C12_C12_4, %0" : : "r"(x) : "memory");
}

__STATIC_FORCEINLINE uint64_t __get_ICC_CTLR_EL3(void)
{
    uint64_t result;
    __ASM volatile("MRS %0, S3_6_C12_C12_4" : "=r"(result) : : "memory");
    return result;
}

/*
 * Interrupt Controller Interrupt Acknowledge Register 0 EL1 (ICC_IAR0_EL1)
 */

__STATIC_FORCEINLINE void __set_ICC_IAR0_EL1(uint64_t x)
{
    __ASM volatile("MSR S3_0_C12_C8_0, %0" : : "r"(x) : "memory");
}

__STATIC_FORCEINLINE uint64_t __get_ICC_IAR0_EL1(void)
{
    uint64_t result;
    __ASM volatile("MRS %0, S3_0_C12_C8_0" : "=r"(result) : : "memory");
    return result;
}

/*
 * Interrupt Controller Interrupt Acknowledge Register 1 EL1 (ICC_IAR1_EL1)
 */

__STATIC_FORCEINLINE void __set_ICC_IAR1_EL1(uint64_t x)
{
    __ASM volatile("MSR S3_0_C12_C12_0, %0" : : "r"(x) : "memory");
}

__STATIC_FORCEINLINE uint64_t __get_ICC_IAR1_EL1(void)
{
    uint64_t result;
    __ASM volatile("MRS %0, S3_0_C12_C12_0" : "=r"(result) : : "memory");
    return result;
}

/*
 * Interrupt Controller End Of Interrupt Register 0 EL1 (ICC_EOIR0_EL1)
 */

__STATIC_FORCEINLINE void __set_ICC_EOIR0_EL1(uint64_t x)
{
    __ASM volatile("MSR S3_0_C12_C8_1, %0" : : "r"(x) : "memory");
}

__STATIC_FORCEINLINE uint64_t __get_ICC_EOIR0_EL1(void)
{
    uint64_t result;
    __ASM volatile("MRS %0, S3_0_C12_C8_1" : "=r"(result) : : "memory");
    return result;
}

/*
 * Interrupt Controller End Of Interrupt Register 1 EL1 (ICC_EOIR1_EL1)
 */

__STATIC_FORCEINLINE void __set_ICC_EOIR1_EL1(uint64_t x)
{
    __ASM volatile("MSR S3_0_C12_C12_1, %0" : : "r"(x) : "memory");
}

__STATIC_FORCEINLINE uint64_t __get_ICC_EOIR1_EL1(void)
{
    uint64_t result;
    __ASM volatile("MRS %0, S3_0_C12_C12_1" : "=r"(result) : : "memory");
    return result;
}

/*
 * Interrupt Controller Deactivate Interrupt Register EL1 (ICC_DIR_EL1)
 */

__STATIC_FORCEINLINE void __set_ICC_DIR_EL1(uint64_t x)
{
    __ASM volatile("MSR S3_0_C12_C11_1, %0" : : "r"(x) : "memory");
}

__STATIC_FORCEINLINE uint64_t __get_ICC_DIR_EL1(void)
{
    uint64_t result;
    __ASM volatile("MRS %0, S3_0_C12_C11_1" : "=r"(result) : : "memory");
    return result;
}

/**************************************************************************************************
 Related CPU Special Purpose Registers - Getters and Setters
**************************************************************************************************/

/*
 * Secure Configuration Register EL3 (SCR_EL3)
 */

__STATIC_FORCEINLINE void __set_SCR_EL3(uint64_t x)
{
    __ASM volatile("MSR SCR_EL3, %0" : : "r"(x) : "memory");
}

__STATIC_FORCEINLINE uint64_t __get_SCR_EL3(void)
{
    uint64_t result;
    __ASM volatile("MRS %0, SCR_EL3" : "=r"(result) : : "memory");
    return result;
}

/**************************************************************************************************
 GIC CPU Interface System Registers Aliases (For reference)
**************************************************************************************************/
#define ICC_IAR0_EL1 S3_0_C12_C8_0
#define ICC_IAR1_EL1 S3_0_C12_C12_0
#define ICC_EOIR0_EL1 S3_0_C12_C8_1
#define ICC_EOIR1_EL1 S3_0_C12_C12_1
#define ICC_HPPIR0_EL1 S3_0_C12_C8_2
#define ICC_HPPIR1_EL1 S3_0_C12_C12_2
#define ICC_BPR0_EL1 S3_0_C12_C8_3
#define ICC_BPR1_EL1 S3_0_C12_C12_3
#define ICC_DIR_EL1 S3_0_C12_C11_1
#define ICC_PMR_EL1 S3_0_C4_C6_0
#define ICC_RPR_EL1 S3_0_C12_C11_3
#define ICC_CTLR_EL1 S3_0_C12_C12_4
#define ICC_CTLR_EL3 S3_6_C12_C12_4
#define ICC_SRE_EL1 S3_0_C12_C12_5
#define ICC_SRE_EL2 S3_4_C12_C9_5
#define ICC_SRE_EL3 S3_6_C12_C12_5
#define ICC_IGRPEN0_EL1 S3_0_C12_C12_6
#define ICC_IGRPEN1_EL1 S3_0_C12_C12_7
#define ICC_IGRPEN1_EL3 S3_6_C12_C12_7
#define ICC_SEIEN_EL1 S3_0_C12_C13_0
#define ICC_SGI0R_EL1 S3_0_C12_C11_7
#define ICC_SGI1R_EL1 S3_0_C12_C11_5
#define ICC_ASGI1R_EL1 S3_0_C12_C11_6

#endif /* GIC_CPU_GCC_H */
