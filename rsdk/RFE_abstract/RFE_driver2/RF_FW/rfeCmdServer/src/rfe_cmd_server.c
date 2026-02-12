/*
* Copyright 2022-2023 NXP
*
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and
* may only be used strictly in accordance with the applicable license terms.  By
* expressly accepting such terms or by downloading, installing, activating and/or
* otherwise using the software, you are agreeing that you have read, and that you
* agree to comply with and are bound by, such license terms.  If you do not agree to
* be bound by the applicable license terms, then you may not retain, install, activate or
* otherwise use the software.
*/


/******************************************************************************
 *   Project              : RF_Abstract_2.0
 *   Platform             : S32R41
 *****************************************************************************/

/*
* @page misra_violations MISRA-C:2012 violations
*
* @section rfe_cmd_server_c_REF_1
* Violates MISRA 2012 Advisory Rule 8.7
* #Functions and objects should not be defined with external linkage if they are referenced in only one translation unit
* The functions are API functions, to be called from the main application.
*
* @section rfe_cmd_server_c_REF_2
* Violates MISRA 2012 Required Rule 11.8
* #A cast shall not remove any const or volatile qualification from the type pointed to by a pointer.
* Required cast, to use the required parameters by the called function signature.
*
*/


/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include "rfe_cmd_server.h"
#include "rfe_cmd_interface.h"
#include "rfe_error.h"
#include "rfeCmdServerDisp.h"
#include "rfeSwMainFsm.h"
#include "rfe_debug.h"
#include "rfeHwLink.h"
#include "rfe_ipc_api.h"

#ifdef __cplusplus
extern "C" {
#endif


/*==================================================================================================
 *                                      LOCAL CONSTANTS
 ==================================================================================================*/

/*==================================================================================================
 *                                      LOCAL VARIABLES
 ==================================================================================================*/
// track if an initialization took place
static bool initialized = false;

// base address for state, command and response area
static volatile uint32_t* rfeCmdServer_cmdArea = NULL;
static volatile uint32_t* rfeCmdServer_rspArea = NULL;
static volatile uint32_t* rfeCmdServer_stsArea = NULL;

static uint32_t rfeCmdServer_respAreaShadow[RFE_CMD_IF_CMDRSPLEN];

static uint32_t rfeCmdServer_prevRespCnt;  /* previous cmdCnt value for the trigger mechanism */

static uint32_t rfeCmdServer_cmdreadIdx;   /* Index to byte in command data part for parameter readout  */

/**
 * \brief Track which events shall raise IRQs
 */
static rfe_eventsIRQ_t rfeCmdServer_eventsIRQ = RFE_EVENTS_IRQ_NONE;

/**
 * \brief Track which commands completion shall raise IRQs
 */
static rfe_apiIRQ_t rfeCmdServer_apisIRQ = RFE_API_IRQ_NONE;

/**
 * \brief Track which core is requesting the events IRQs
 */
static rfe_coreId_t rfeCmdServer_targetCoreId = (rfe_coreId_t) rfe_coreId_none_e;


/*==================================================================================================
 *                                      LOCAL FUNCTIONS
 ==================================================================================================*/
static void rfeCmdServer_dispatch(rfeCmdServer_cmdId_t cmdId, rfe_error_t* rfe___error___pointer);
/* Start the preparation for the response for the Command Client                */
static inline void rfeCmdServer_cmdRespStart(rfeCmdServer_cmdId_t cmdID, uint32_t cmdCnt)
{
    rfeCmdServer_respAreaShadow[RFE_CMD_IF_OFF_ID]  = (uint32_t)cmdID | RFE_CMD_IF_RESPONSEBITMASK;
    rfeCmdServer_respAreaShadow[RFE_CMD_IF_OFF_CNT] = (uint32_t)cmdCnt;
    rfeCmdServer_respAreaShadow[RFE_CMD_IF_OFF_LEN] = 4UL;
}
/**
 * \brief Raise an interrupt on core registered by the application
 */
static void rfeCmdServer_raiseInterrupt(uint32_t apiIrq, uint32_t eventIrq)
{
#ifdef RFE_DEBUG
    if (gRfeDebugLevel <= e_rfe_debug_level_handle_cmd)
    {
        RfeDbgPrintMsg("rfeCmdServer_raiseInterrupt: ");
        if ((uint32_t)apiIrq != (uint32_t)0xFFFFFFFFUL)
        {
            RfeDbgPrintMsg("apiIrq %u\n", (uint32_t)apiIrq);
        }
        else
        {
            RfeDbgPrintMsg("eventIrq %u\n", (uint8_t)eventIrq);
        }
    }
#endif
    RfeHwRaiseIRQ(apiIrq, eventIrq);
}

/********************************************************************
*  Dispatcher for the received command, according to the rfeCmdServerDispTab
*  Input  : command ID, error pointer
*/
static void rfeCmdServer_dispatch(rfeCmdServer_cmdId_t cmdId, rfe_error_t* rfe___error___pointer)
{
    rfeCmdServerDispEntry_t* pCmdEntry;

    /* dispatcher table pointer        */
    pCmdEntry = &rfeCmdServerDispTab[cmdId];
    /* only if no error at this point           */
    if (cmdId < RFE_CMD_IF_CMD_COUNT)
    {
        /* command ID in correct interval           */
        if ( (pCmdEntry->cmdDataLen != rfeCmdServer_cmdArea[RFE_CMD_IF_OFF_LEN]) &&
                (pCmdEntry->cmdDataLen != RFE_CMD_SERVER_DISP_VARIABLE_LENGTH) )
        {
            /* the length of the command is not correct             */
            *rfe___error___pointer = rfe_error_cmdInterface_invalidCmdLength_e;
        }
        else
        {
            if (pCmdEntry->handler == RFE_CMD_SERVER_DISP_UNDEF_COMMAND)
            {
                *rfe___error___pointer = rfe_error_cmdServerInternal_undefined_cmd_handler_e;
            }
        }
    }
    if(*rfe___error___pointer == rfe_error_none_e)
    {
        /* prepare command region readout */
        rfeCmdServer_cmdreadIdx = 0UL;

        /* execute function */
        pCmdEntry->handler(rfe___error___pointer);

        /* check for execution error */
        if(*rfe___error___pointer == rfe_error_none_e)
        {
            /* correct execution, check the response length is as expected
             * +4, because first parameter of response is always the error code)                */
            if(((pCmdEntry->respDataLen + 4U) != (uint8_t)rfeCmdServer_respAreaShadow[RFE_CMD_IF_OFF_LEN]) &&
                    (pCmdEntry->respDataLen != RFE_CMD_SERVER_DISP_VARIABLE_LENGTH) )
            {
                *rfe___error___pointer = rfe_error_cmdServerInternal_resplen_wrong_e;
            }
        }
    }
    else
    {
        *rfe___error___pointer = rfe_error_cmdInterface_invalidCmdId_e;
    }
}
/***** rfeCmdServer_dispatch ***********************/


/********************************************************************
*  The handler of the requested command
*  Input  : command ID, error pointer
*/
static void rfeCmdServer_cmdProcess(rfeCmdServer_cmdId_t cmdId, uint32_t cmdCnt, rfe_error_t dropCmdError, rfe_error_t* rfe___error___pointer)
{
    if (dropCmdError == rfe_error_none_e)
    {
        rfeCmdServer_dispatch(cmdId, rfe___error___pointer);
        rfeCmdServer_respAreaShadow[RFE_CMD_IF_OFF_DAT] = (uint32_t)*rfe___error___pointer;
        if(((uint32_t)(*rfe___error___pointer) & RFE_ERROR_RFE_INTERNAL_ERROR_BIT) == 0UL)
        {
            /* Keep the reported error to be sent to the API side
             * but clear the error from Fw side, as this error is reported only for the requested command and not for the Fw itself.  */
            *rfe___error___pointer = rfe_error_none_e;
        }
    }
    else
    {
        rfeCmdServer_respAreaShadow[RFE_CMD_IF_OFF_DAT] = (uint32_t)dropCmdError;
    }

    /* We need to calculate CRC despite of any active errors, to prevent CRC errors         */
    rfeCmdServer_respAreaShadow[RFE_CMD_IF_OFF_CRC] =
                rfeCrc_calBuf(&rfeCmdServer_respAreaShadow[RFE_CMD_IF_OFF_CNT],
                        (RFE_CMD_IF_OFF_DAT * sizeof(uint32_t)) +
                        ((rfeCmdServer_respAreaShadow[RFE_CMD_IF_OFF_LEN] + 3UL) & 0xfffffffcUL));

    rfeCmdServer_rspArea[RFE_CMD_IF_OFF_CNT] = rfeCmdServer_respAreaShadow[RFE_CMD_IF_OFF_CNT];

    if(rfeIpc_srvRspTx(rfeCmdServer_respAreaShadow, RFE_CMD_IF_CMDRSPLEN * 4UL) == 1)
    {
        *rfe___error___pointer = rfe_error_api_unresponsive_e;
    }

    if(*rfe___error___pointer == rfe_error_none_e)
    {
        /* check if this command completion is registered as a source of interrupts */
        if(((uint32_t)rfeCmdServer_apisIRQ & ((uint32_t)1 << (uint8_t)cmdId) ) != 0UL)
        {
            rfeCmdServer_raiseInterrupt(1UL << (uint8_t)cmdId,
                    (uint32_t)RFE_EVENTS_IRQ_STATE_CHANGE + (uint32_t)RFE_EVENTS_IRQ_RADAR_CYCLE_CHANGE + (uint32_t)RFE_EVENTS_IRQ_CHIRP_SEQUENCE_CHANGE);
        }
        rfeCmdServer_prevRespCnt = cmdCnt;              /* mark command as handled / resynchronize */
    }
}


/*==================================================================================================
 *                                      GLOBAL FUNCTIONS
 ==================================================================================================*/
/*==============================================================================*/
/**
 * \Brief Write a SharedData location with information
 *
 * \pre rfeIpc_srvInit() application to initialize transport communication protocol successfully
 *
 * \param [in]          idx                     The sharedData index to write (each index is a unique memory location)
 * \param [in]          value                   The value to write
 * \param [in, out]     rfe___error___pointer   Error handling pointer
 *
 * \post The updated SharedData location is written.
 *
 * \return NIL
 */
/*
* @violates @ref rfe_cmd_server_c_REF_1 #Functions and objects should not be defined with external linkage
*                                           if they are referenced in only one translation unit
*/
void rfeCmdServer_sharedDataWrite(uint32_t idx, uint16_t value, rfe_error_t* rfe___error___pointer)
{
    uint32_t redundantValue;

    if(!initialized)
    {
        /* the connection not initialized (?!)      */
        *rfe___error___pointer = rfe_error_uninitialized_e;
    }
    else
    {
        if(idx < RFE_CMD_IF_SHAREDATACOUNT)
        {
            /* upper 16 bits = inverted value, lower 16 bits = value (create redundancy and allow error detection)  */
            redundantValue = (uint32_t)value;
            redundantValue = ((~redundantValue) << 16U) | redundantValue;
            rfeCmdServer_stsArea[idx] = redundantValue;
            if(rfeIpc_srvStsTx((void*)rfeCmdServer_stsArea, RFE_CMD_IF_SHAREDATACOUNT * 4UL) != 0)
            {
                *rfe___error___pointer = rfe_error_api_unresponsive_e;
            }
            /* check if this event is registered as a source of interrupts */
            if((((uint32_t)rfeCmdServer_eventsIRQ & ((uint32_t)1 << idx)) != 0UL))
            {
                // add 1 to the cmdid/eventId because first IRQ is irq none
                rfeCmdServer_raiseInterrupt(0xFFFFFFFFUL, 1UL << idx);
            }
        }
        else
        {
            *rfe___error___pointer = rfe_error_parameterOutOfRange_e;
        }
    }
}
/*==== rfeCmdServer_sharedDataWrite ================*/


/********************************************************************
*  Write byte array to the response
*  Input  : pointer to the array, array length, error pointer
*/
/*
* @violates @ref rfe_cmd_server_c_REF_1 #Functions and objects should not be defined with external linkage
*                                           if they are referenced in only one translation unit
*/
void rfeCmdServer_cmdRespWriteBuf(void* pInput, uint32_t byteCount, rfe_error_t* rfe___error___pointer)
{
    uint8_t* pData;

    if (!initialized)
    {
        /* the connection not initialized (?!)      */
        *rfe___error___pointer = rfe_error_uninitialized_e;
    }
    else
    {
        /* check to not cross the response boundary     */
        if((rfeCmdServer_respAreaShadow[RFE_CMD_IF_OFF_LEN] + byteCount) <= RFE_CMD_IF_MAXDATLEN)
        {
            pData = (uint8_t*)&rfeCmdServer_respAreaShadow[RFE_CMD_IF_OFF_DAT];
            pData += rfeCmdServer_respAreaShadow[RFE_CMD_IF_OFF_LEN];
            (void)memcpy((void*)pData, pInput, byteCount);
            rfeCmdServer_respAreaShadow[RFE_CMD_IF_OFF_LEN] += byteCount;
        }
        else
        {
            *rfe___error___pointer = rfe_error_cmdServerInternal_cmdbuf_overflow_e;
        }
    }
}
/***** rfeCmdServer_cmdRespWriteBuf ***********************/


/********************************************************************
*  Get the command parameters not transferred yet
*  Input  : error pointer
*/
/*
* @violates @ref rfe_cmd_server_c_REF_1 #Functions and objects should not be defined with external linkage
*                                           if they are referenced in only one translation unit
*/
uint32_t rfeCmdServer_cmdParamGetByteCount(rfe_error_t* rfe___error___pointer)
{
    if (!initialized)
    {
        /* the connection not initialized (?!)      */
        *rfe___error___pointer = rfe_error_uninitialized_e;
    }
    return (rfeCmdServer_cmdArea[RFE_CMD_IF_OFF_LEN ] - rfeCmdServer_cmdreadIdx);
}
/***** rfeCmdServer_cmdParamGetByteCount ***********************/


/********************************************************************
*  Read the command parameters array from the buffer
*  Input  : pointer to a buffer to receive the parameters, array length to transfer, error pointer
*/
/*
* @violates @ref rfe_cmd_server_c_REF_1 #Functions and objects should not be defined with external linkage
*                                           if they are referenced in only one translation unit
*/
void rfeCmdServer_cmdParamReadBuf(void* pOutput, uint32_t byteCount, rfe_error_t* rfe___error___pointer)
{
    volatile uint8_t* pData;

    if (!initialized)
    {
        /* the connection not initialized (?!)      */
        *rfe___error___pointer = rfe_error_uninitialized_e;
    }
    else
    {
        /* check if read is not outside of payload area or command parameters                       */
        if(((rfeCmdServer_cmdreadIdx + byteCount) <= rfeCmdServer_cmdArea[RFE_CMD_IF_OFF_LEN])  &&
             ((rfeCmdServer_cmdreadIdx + byteCount) <= RFE_CMD_IF_MAXDATLEN))
        {
            pData = (volatile uint8_t*)&rfeCmdServer_cmdArea[RFE_CMD_IF_OFF_DAT];
            pData += rfeCmdServer_cmdreadIdx;
            /*
            * @violates @ref rfe_cmd_server_c_REF_2 #A cast shall not remove any const or volatile qualification from
            *                                           the type pointed to by a pointer.
            */
            (void)memcpy(pOutput, (void*)pData, byteCount);
            rfeCmdServer_cmdreadIdx += byteCount;
        }
        else
        {
            /* too much data to be read             */
            *rfe___error___pointer = rfe_error_cmdServerInternal_cmdbuf_overflow_e;
        }
    }
}
/***** rfeCmdServer_cmdParamReadBuf ***********************/


/********************************************************************
*  Synchronize with the other core
*  Input  : error pointer
*  Return : the action result success/not
*/
/*
* @violates @ref rfe_cmd_server_c_REF_1 #Functions and objects should not be defined with external linkage
*                                           if they are referenced in only one translation unit
*/

bool rfeCmdServer_sync(rfe_error_t* rfe___error___pointer)
{
    /* go further only if no errors yet         */
    if((*rfe___error___pointer == rfe_error_none_e))
    {
        /* the address reduced to 32 bits, as physical RAM addresses have only 32 bits              */
        rfeCmdServer_stsArea = (uint32_t*)rfeIpc_srvStsBuffAcquire();
        /* the address reduced to 32 bits, as physical RAM addresses have only 32 bits              */
        rfeCmdServer_rspArea = (uint32_t*)rfeIpc_srvRspBuffAcquire();

        if((rfeCmdServer_stsArea != NULL_PTR) && (rfeCmdServer_rspArea != NULL_PTR))
        {
            /* initialize shared data fields to 0                        */
            for (uint32_t i = 0; i < RFE_CMD_IF_SHAREDATACOUNT; i++)
            {
                rfeCmdServer_stsArea[i] = 0xffff0000UL;
            }


            /* initialize response memory areas */
            rfeCmdServer_rspArea[RFE_CMD_IF_OFF_ID]  = RFE_CMD_IF_RESPONSEBITMASK;
            rfeCmdServer_rspArea[RFE_CMD_IF_OFF_LEN] = 0UL;
            rfeCmdServer_rspArea[RFE_CMD_IF_OFF_DAT] = (uint32_t) rfe_error_none_e;
            rfeCmdServer_rspArea[RFE_CMD_IF_OFF_CRC] = 0UL;
            rfeCmdServer_prevRespCnt = 0UL;
            // sent active state

            /* set the current state : active       */
            initialized = true;
            rfeCmdServer_sharedDataWrite((uint32_t)rfeSwMainFsm_sharedParameter_fw_ready_e, 1U, rfe___error___pointer);

            if(*rfe___error___pointer != rfe_error_none_e)
            {
                initialized = false;
            }
        }
    }
    return initialized;
}
/***** rfeCmdServer_sync ***********************/


/********************************************************************
*  Check for a new command available in the interface buffer
*  Input  : a command ID
*  Return : the availability status
*/
/*
* @violates @ref rfe_cmd_server_c_REF_1 #Functions and objects should not be defined with external linkage
*                                           if they are referenced in only one translation unit
*/
bool rfeCmdServer_cmdAvailable(uint8_t* pCmdId)
{
    bool isAvailable = false;
    int32_t  err = 0;

    rfeCmdServer_cmdArea = (volatile uint32_t*)rfeIpc_srvCmdPoll(&err);

    if((rfeCmdServer_cmdArea != NULL_PTR) && (initialized))
    {
        if(rfeCmdServer_cmdArea[RFE_CMD_IF_OFF_CNT] != rfeCmdServer_prevRespCnt)
        {
            /* only if the connection to the other core is initialized and different commands IDs   */
            isAvailable = true;
        }
    }
    if (pCmdId != NULL)
    {
            /* if a command ID specified in call                                                    */
        if (isAvailable)
        {
            /* if new command available, pass the requested command                             */
            *pCmdId = (uint8_t)rfeCmdServer_cmdArea[RFE_CMD_IF_OFF_ID];
        }
        else
        {
            /* if not available, set it to 0, as rfeCmdServer_cmdId_configure_e has the ID o    */
            *pCmdId = 0U;
        }
    }

    return isAvailable;
}
/***** rfeCmdServer_cmdAvailable ***********************/


/********************************************************************
*  Handle the received command
*  Input : mask for command errors to be dropped, pointer to error
*/
/*
* @violates @ref rfe_cmd_server_c_REF_1 #Functions and objects should not be defined with external linkage
*                                           if they are referenced in only one translation unit
*/
void rfeCmdServer_handlecmd(rfe_error_t dropCmdError, rfe_error_t* rfe___error___pointer)
{
    uint32_t                cmdcnt; /* command trigger count */
    uint32_t                cmdlen; /* count of command parameters */
    uint32_t                bytecount, calculatedCrc, receivedCrc;
    rfeCmdServer_cmdId_t    cmdid;  /* command opcode for dispatcher table*/

    if((*rfe___error___pointer == rfe_error_none_e) && (!initialized))
    {
        *rfe___error___pointer = rfe_error_uninitialized_e;
    }

    if(rfeCmdServer_cmdArea == NULL_PTR)
    {
        *rfe___error___pointer = rfe_error_uninitialized_e;
    }
    if(*rfe___error___pointer == rfe_error_none_e)
    {
            cmdcnt = rfeCmdServer_cmdArea[ RFE_CMD_IF_OFF_CNT ];
            if(rfeCmdServer_prevRespCnt != cmdcnt)                   /* cross check, if a command is present */
            {
                cmdlen = rfeCmdServer_cmdArea[RFE_CMD_IF_OFF_LEN];
                /*
                * @violates @ref rfe_cmd_server_c_REF_2 #A cast shall not remove any const or volatile qualification from
                *                                           the type pointed to by a pointer.
                */
                cmdid  = (rfeCmdServer_cmdId_t)rfeCmdServer_cmdArea[RFE_CMD_IF_OFF_ID];

                /* prepare response buffer                      */
                rfeCmdServer_cmdRespStart(cmdid, cmdcnt);

                /* step 1: check message consistency (length)   */
                if (cmdlen > RFE_CMD_IF_MAXDATLEN)
                {
                    *rfe___error___pointer = rfe_error_cmdInterface_invalidCmdLength_e;
                }

                /* check message consistency: CRC               */
                bytecount = cmdlen + (4UL * RFE_CMD_IF_OFF_DAT);
                /*
                * @violates @ref rfe_cmd_server_c_REF_2 #A cast shall not remove any const or volatile qualification from
                *                                           the type pointed to by a pointer.
                */
                calculatedCrc = rfeCrc_calBuf((uint32_t*)rfeCmdServer_cmdArea, ((bytecount + 3UL) & 0xfffffffcUL));
                receivedCrc   = rfeCmdServer_cmdArea[RFE_CMD_IF_OFF_CRC];
                if ( calculatedCrc != receivedCrc )
                {   /* CRC incorrect => raise error!            */
                    *rfe___error___pointer = rfe_error_cmdInterface_invalidCrc_e;
                }

                /* check, if commandCnt incremented only by 1 (for all commands, but not PING command */
                if(((cmdcnt - rfeCmdServer_prevRespCnt) != 1UL) &&
                     (*rfe___error___pointer == rfe_error_none_e))
                {
                    /* the command counter did not increment in step of 1 and no other error, report thi serror         */
                    *rfe___error___pointer = rfe_error_cmdServerInternal_out_of_seq_e;
                }

                if(*rfe___error___pointer == rfe_error_none_e)  /* check if message integrity error occured previously  */
                {
                    /* step 2: dispatch command */
                    rfeCmdServer_cmdProcess(cmdid, cmdcnt, dropCmdError, rfe___error___pointer);
                }
            }
            else
            {
                *rfe___error___pointer = rfe_error_cmdServerInternal_no_cmd_received_e;
            }
    }
}
/***** rfeCmdServer_handlecmd ***********************/


/********************************************************************
*  Register the required interrupt
*  Input : coreID, API requests and events to be processed
*/
void rfeCmdServer_registerIRQSources(
    rfe_coreId_t                    coreId,
    rfe_eventsIRQ_t                 events,
    rfe_apiIRQ_t                    rfeAPIs
)
{
    rfeCmdServer_eventsIRQ = events;
    rfeCmdServer_apisIRQ = (rfe_apiIRQ_t)((uint32_t)rfeAPIs & RFE_API_IRQ_ALL);
    rfeCmdServer_targetCoreId = coreId;
    RfeHwSetIRQ();
    return;
}
/***** rfeCmdServer_registerIRQSources ***********************/

#ifdef __cplusplus
}
#endif

/*******************************************************************************
 * EOF
 ******************************************************************************/

/** @} */
