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

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "rfe_error_assert.h"

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
 ==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLES
==================================================================================================*/
#ifdef RFE_ERROR_ENABLE_ASSERT
rfe_error_assertMemoryItem_t rfe_error_assertMemory = { 0UL, 0UL };
#endif
/*==================================================================================================
 *                                      GLOBAL FUNCTIONS
 ==================================================================================================*/
#ifdef RFE_ERROR_ENABLE_ASSERT
void rfe_error_assert(
    bool        condition,
    rfe_error_t error,
    uint16_t    fileNumber,
    uint16_t    lineNumber,
    rfe_error_t* rfe___error___pointer
)
{
    if(*rfe___error___pointer == rfe_error_none_e)
    {
        if ( condition )
        {
            // check condition succeeded
            // no action to take
        }
        else
        {
            // check condition failed
            *rfe___error___pointer = error;
            rfe_error_assertMemory.fileNumber = fileNumber;
            rfe_error_assertMemory.lineNumber = lineNumber;
        }
    }
}
#endif // RFE_ERROR_ENABLE_ASSERT

#ifdef __cplusplus
}
#endif

/*******************************************************************************
 * EOF
 ******************************************************************************/

/** @} */
