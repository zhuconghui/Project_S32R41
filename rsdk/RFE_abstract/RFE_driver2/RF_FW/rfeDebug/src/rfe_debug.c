/**************************************************************************************************
* Copyright 2023 NXP
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
 *   Project              : S32R41_RFE_FW
 *   Platform             : S32R41
 *****************************************************************************/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "rfe_debug.h"


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#ifdef RFE_DEBUG
rfe_debug_level_t gRfeDebugLevel = e_rfe_debug_level_all;

const char* gStateName[] = {
        "powerOn\0",
        "initChirpSequence\0",
        "recalibration\0",
        "chirpSequence\0",
        "monitorsAndMetadata\0",
        "bist\0",
        "powerOff\0",
        "idle\0",
        "cmdExecutionBuffer\0",
        "configUpdate\0",
        "begin\0",
        "startOffset\0"
};
#endif // RFE_DEBUG

#ifdef GET_TIMINGS
uint32_t stateDurationStartTime;
uint32_t stateDurationEndTime;
timinig_t debugData __attribute__((section(".share_ram_debug")));
#endif // GET_TIMINGS

/*==================================================================================================
*                                GLOBAL FUNCTIONS DECLARATIONS
==================================================================================================*/
#ifdef RFE_DEBUG
void Dummy_funct_for_break_point(void)
{
	return;
}
#endif // RFE_DEBUG



