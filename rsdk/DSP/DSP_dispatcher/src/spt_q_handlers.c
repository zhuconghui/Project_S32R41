/*
 * Copyright 2018-2024 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include <xtensa/tie/xt_bben.h>
#include <xtensa/tie/radar24.h>
#include "spt_q_handlers.h"

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
int32_t SptCmdQPop(int32_t *const pRawCmd)
{
    bbx_vecNx24 qval = (bbx_vecNx24)0;
    int32_t isDataAvailable = 0;

    //use non-blocking version of the pop instruction, to avoid the case when a spurious interrupt is received,
    //but no data is available in the queue (this would stall the DSP and SPT)
    BBX_LDCQ128NB(isDataAvailable, qval);
    //this instruction places the command queue content in the lower 128 bits of one lvec register group

    if(isDataAvailable != 0)
    {
        //copy lower 128 bits into memory
        BBX_SLV128_I(qval, pRawCmd, 0);
    }

    return isDataAvailable;
}

void SptRespQPush(uint8_t funcID)
{
    BBX_STRQ32((int32_t)funcID);
}

/*================================================================================================*/

#ifdef __cplusplus
}
#endif

/*******************************************************************************
 * EOF
 ******************************************************************************/
