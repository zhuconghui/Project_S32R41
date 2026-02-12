/**************************************************************************************************
* Copyright 2022-2023 NXP
*
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and
* may only be used strictly in accordance with the applicable license terms.  By
* expressly accepting such terms or by downloading, installing, activating and/or
* otherwise using the software, you are agreeing that you have read, and that you
* agree to comply with and are bound by, such license terms.  If you do not agree to
* be bound by the applicable license terms, then you may not retain, install, activate or
* otherwise use the software.
**************************************************************************************************/

#ifndef RFE_CMD_SERVER_DISP_H
#define RFE_CMD_SERVER_DISP_H

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include <stdint.h>
#include <stdbool.h>
#include "rfe_error.h"
#include "rfe_cmd_interface.h"

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/* command handler signature definition for use in command dispatcher table */
typedef void(*rfeCmdServerDispHandler_t)(rfe_error_t* rfe___error___pointer);

/* structure used for the dispatcher table entries */
typedef struct
{
    rfeCmdServerDispHandler_t   handler;        /* the procedure to process the command                         */
    uint8_t                     cmdDataLen;     /* the right amount of data to be provided for the command      */
    uint8_t                     respDataLen;    /* the response data right length                               */
} rfeCmdServerDispEntry_t;

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/* entry to signal an not implemented command within the dispatcher table  */
#define RFE_CMD_SERVER_DISP_UNDEF_COMMAND ((rfeCmdServerDispHandler_t)0UL)

#define RFE_CMD_SERVER_DISP_VARIABLE_LENGTH (255UL)

/**
 * This macro defines the size (in bytes) of a single-parameter update (cmd interface payload).
 */
#define RFE_CMD_SERVER_DISP_UPDATE_PUSH_SINGLE_UPDATE_SIZE                   (8UL)

/**
 * This macro defines the maximum total size (in bytes) of a parameter update (cmd interface payload).
 */
#define RFE_CMD_SERVER_DISP_UPDATE_PUSH_DATA_SIZE_MAX  \
                (RFE_UPDATE_COUNT_MAX * RFE_CMD_SERVER_DISP_UPDATE_PUSH_SINGLE_UPDATE_SIZE)

/**
 * This macro defines the total size for r1FaultPromotedToR2, radarCycleCount, chirpSequenceCount 2 bytes each.
 */
#define RFE_CMD_SERVER_DISP_FUSA_STATISTICS_SIZE                             (6UL)

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
/* forward declare dispatcher table */
extern rfeCmdServerDispEntry_t rfeCmdServerDispTab[ RFE_CMD_IF_CMD_COUNT ];

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
void rfeCmdServerDisp_configure(rfe_error_t* rfe___error___pointer);
void rfeCmdServerDisp_radarCycleStart(rfe_error_t* rfe___error___pointer);
void rfeCmdServerDisp_radarCycleStop(rfe_error_t* rfe___error___pointer);
void rfeCmdServerDisp_getFuSaFaults(rfe_error_t* rfe___error___pointer);
void rfeCmdServerDisp_getFuSaFaultStatistics(rfe_error_t* rfe___error___pointer);
void rfeCmdServerDisp_getBistZeroHourReferenceData(rfe_error_t* rfe___error___pointer);
void rfeCmdServerDisp_getTime(rfe_error_t* rfe___error___pointer);
void rfeCmdServerDisp_getVersion(rfe_error_t* rfe___error___pointer);
void rfeCmdServerDisp_getNextRadarCycleStartTime(rfe_error_t* rfe___error___pointer);
void rfeCmdServerDisp_setNextRadarCycleStartTime(rfe_error_t* rfe___error___pointer);
void rfeCmdServerDisp_monitorRead(rfe_error_t* rfe___error___pointer);
void rfeCmdServerDisp_continuousWaveTransmissionStart(rfe_error_t* rfe___error___pointer);
void rfeCmdServerDisp_continuousWaveTransmissionStop(rfe_error_t* rfe___error___pointer);
void rfeCmdServerDisp_setTestparam(rfe_error_t* rfe___error___pointer);
void rfeCmdServerDisp_updatePush(rfe_error_t* rfe___error___pointer);
void rfeCmdServer_cmdId_setFrontEnd(rfe_error_t* rfe___error___pointer);
void rfeCmdServer_cmdId_getFrontEnd(rfe_error_t* rfe___error___pointer);
void rfeCmdServer_cmdId_getInternalError(rfe_error_t* rfe___error___pointer);

#endif // !RFE_CMD_SERVER_DISP_H

