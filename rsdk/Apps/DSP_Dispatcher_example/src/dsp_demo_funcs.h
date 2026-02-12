/*
 * Copyright 2024 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */

#ifndef DSP_DEMO_FUNCS_H
#define DSP_DEMO_FUNCS_H

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include <stdint.h>
#include <xtensa/tie/xt_bben.h>
#include <xtensa/tie/xt_misc.h>
#include <xtensa/tie/radar24.h>
#include <xtensa/tie/xt_core.h>

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
/**
* @brief	Demonstrates how to get data from the Arm core, process it and send it back using SPT Work Registers
* @details  Writes the value ((uint32_t)argList + 0x10001) to the SPT WR0 register.
*
* @param argList - interpreted as 32-bit integer
*
*/
void RsdkBbe32Func1(uintptr_t argList);
/**
* @brief	Demonstrates how to get parameters directly from the SPT kernel, process them and write back in a Work Register
* @details  Writes the value ( ((uint32_t*)argList)[0] + ((uint32_t*)argList)[1] ) to the SPT WR0 register.
*
* @param argList - interpreted as two 32-bit integers serialized one after the other
*
*/
void RsdkBbe32Func2(uintptr_t argList);

#ifdef __cplusplus
}
#endif

#endif  /*DSP_DEMO_FUNCS_H*/

