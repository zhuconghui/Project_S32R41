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

#ifndef CMD_HANDLERS_H
#define CMD_HANDLERS_H

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include <stdint.h>
#include <stdbool.h>
#include "dsp_dispatcher_internals.h"

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define DSP_CMD_DIRECT_PARAM_SIZE (12u)    //size in bytes
#define DSP_CMD_INDIRECT_PARAM_SIZE (sizeof(dspCmdArgList_t))
#define DSP_CMD_MAX_PARAM_SIZE ((DSP_CMD_DIRECT_PARAM_SIZE > DSP_CMD_INDIRECT_PARAM_SIZE) ? DSP_CMD_DIRECT_PARAM_SIZE:DSP_CMD_INDIRECT_PARAM_SIZE    )
#define DSP_CMD_ID_SIZE (sizeof(uint8_t))
#define DSP_CMD_ID_OFFSET (sizeof(uint32_t) - DSP_CMD_ID_SIZE)
#define DSP_CMD_MAX_PAYLOAD_SIZE (DSP_CMD_ID_SIZE + DSP_CMD_MAX_PARAM_SIZE)
#define DSP_CMD_MAX_PAYLOAD_SIZE_INT ((DSP_CMD_MAX_PAYLOAD_SIZE+3) / 4)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
typedef enum
{
    DSP_CMD_SRC_SPT,
    DSP_CMD_SRC_CPU,
    //do we need to specify each SPT thread and CPU core?
} dspCmdSrc_t;

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
typedef uintptr_t dspCmdArgList_t;
typedef uint16_t dspCmdResult_t;

typedef dspCmdResult_t (*dspCmdHandler_t)(dspCmdArgList_t arg);

typedef struct
{
    uint8_t        funcID;
    dspCmdHandler_t pCmdHandler;  //pointer to DSP IRAM or SRAM
    dspCmdArgList_t pCmdArg;        //pointer to bitfield or shared memory location (e.g. TCM OR SRAM) where the CPU or SPT writes DSP param list
    dspCmdResult_t cmdStatus;
    uint32_t cmdPayloadBits[DSP_CMD_MAX_PAYLOAD_SIZE_INT]; //reserved storage for command ID and parameters.
                                                           //declared as 32-bit integer to ensure 4-byte alignment
} dspCmdContext_t;


typedef struct {
    uint16_t numJobs;
    dspCmdContext_t job[RSDK_DSPHD_MAX_JOB_LIST_SIZE];
} rsdkDspParsedJobList_t;


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

extern rsdkDspParsedJobList_t gP1ParsedJobList;
extern rsdkDspParsedJobList_t gP4ParsedJobList;
extern rsdkDspParsedJobList_t gP5ParsedJobList;


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
rsdkStatus_t DispatcherCmdParse(uint8_t *const pRawCmd, dspCmdContext_t *const pParsedCmd, rsdkDspFuncPtr_t *funcTable,
                         uint32_t funcTableSize, dspCmdSrc_t cmdSrc);
void         RunDspCmd(dspCmdContext_t *pParsedCmd);

#ifdef __cplusplus
}
#endif

#endif /*CMD_HANDLERS_H*/
