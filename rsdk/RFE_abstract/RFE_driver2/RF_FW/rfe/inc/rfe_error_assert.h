/**************************************************************************************************
* Copyright 2022 - 2023 NXP
**************************************************************************************************
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
**************************************************************************************************/

/******************************************************************************
 *   Project              : RF_Abstract_2.0
 *   Platform             : S32R41
 *****************************************************************************/

#ifndef RFE_ERROR_ASSERT_H
#define RFE_ERROR_ASSERT_H

/*==================================================================================================
 *                                        INCLUDE FILES
 ==================================================================================================*/
#include <stdint.h>
#include <stdbool.h>

#include "rfe_error.h"

#ifdef RFE_ERROR_ENABLE_ASSERT
/*==================================================================================================
 *                                        TYPES/ENUMS
 ==================================================================================================*/
typedef struct
{
    uint16_t    fileNumber;
    uint16_t    lineNumber;
} rfe_error_assertMemoryItem_t;

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
extern rfe_error_assertMemoryItem_t rfe_error_assertMemory;

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
/**
 * Implementation for the RFE_ERROR_ASSERT( condition, error ) macro.
 * 
 * \note Do not use this function directly but only through the RFE_ERROR_ASSERT( condition, error ) macro.
 * 
 * \param condition  If the condition is false, the provided error will be set. Additionally, the rfe_error_assertMemory will be updated.
 * \param error      The error to set if the condition is false.
 * \param fileNumber The value to write to rfe_error_assertMemory.fileNumber if the condition is false.
 * \param lineNumber The value to write to rfe_error_assertMemory.lineNumber if the condition is false.
 * \param rfe___error___pointer Error parameter.
 */
void rfe_error_assert(
    bool        condition,
    rfe_error_t error,
    uint16_t    fileNumber,
    uint16_t    lineNumber,
    rfe_error_t* rfe___error___pointer
);

#endif // RFE_ERROR_ENABLE_ASSERT

#endif // !RFE_ERROR_H
