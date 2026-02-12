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
 *   Project              : S32R41_RFE_FW
 *   Platform             : S32R41
 *****************************************************************************/

#ifndef RFE_DEBUG_H
#define RFE_DEBUG_H

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#ifdef GET_TIMINGS
// This define may be used for double check timings using a logic analyzer #define GPIO_STATES
#define MAX_TIME_RECORDS (1000U)
#endif // GET_TIMINGS
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#ifdef RFE_DEBUG
typedef enum
{
	e_rfe_debug_level_all 			= 0, 	// all messages
	e_rfe_debug_level_handle_cmd	,
	e_rfe_debug_level_bc 			,
	e_rfe_debug_level_radar_cycle 	,
	e_rfe_debug_level_dyn_tbl 		,
	e_rfe_debug_level_none, 				// no messages
} rfe_debug_level_t;
#endif // RFE_DEBUG

#ifdef GET_TIMINGS
typedef struct
{
    uint32_t stateTime;
    uint8_t  state;
    uint8_t  sequence;
    uint16_t radarCycle;
} time_rec_t;

typedef struct
{
	time_rec_t timingRecords[MAX_TIME_RECORDS];
	uint32_t timeRecordsCount;
} timinig_t;
#endif
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
#ifdef RFE_DEBUG
extern rfe_debug_level_t gRfeDebugLevel;
extern const char* gStateName[];
#endif // RFE_DEBUG

#ifdef GET_TIMINGS
extern uint32_t stateDurationStartTime;
extern uint32_t stateDurationEndTime;
extern timinig_t debugData;
#endif
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#ifdef RFE_DEBUG
void Dummy_funct_for_break_point(void);
#endif // RFE_DEBUG

#ifdef __cplusplus
}
#endif

#endif /* RFE_DEBUG_H */

/** @} */
