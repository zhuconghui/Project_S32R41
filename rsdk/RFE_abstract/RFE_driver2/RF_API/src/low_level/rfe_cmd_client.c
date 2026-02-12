/**************************************************************************************************
 *
 * NXP Confidential Proprietary
 *
 * Copyright 2022-2023 NXP
 *
 *****************************************************************************
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

/******************************************************************************
 *   Project              : RFE_abstract 2.0
 *   Platform             : S32R41
 *****************************************************************************/


/* RF_Abstract 2.0  Communication Protocol and Messages Structure
 *
 * Communication Protocol  require the existence of  the following communication channels
 *   - Command Channel. Producer channel
 *   - Response Channel. Consumer channel
 *   - State Channel. Consumer channel
 * Command Channel.Messages Structure
 *   | +---------------------------+ |
 *   | |                           | |
 *   | | +-----------------------+ | |
 *   | | |Command                | | |
 *   | | |(256 bytes)            | | |
 *   | | |                       | | |
 *   | | |Offset 0:   CNT/Trigger| | | <- CNT is used as sequence counter and to be able to detect a new command (trigger)
 *   | | |Offset 4:   Command ID | | | <- This identifies the command that should be remotely executed
 *   | | |Offset 8:   Param Len  | | | <- This is the length of the parameters following this value in unit of Bytes
 *   | | |Offset 12:  Parameters | | | <- Parameters belonging to the commands are placed here
 *   | | |Offset 252: CRC        | | | <- Overall package CRC
 *   | | +-----------------------+ | |
 *
 * Response Channel.Messages Structure
 *   | +---------------------------+ |
 *   | |                           | |
 *   | | +-----------------------+ | |
 *   | | |Response buffer        | | | <- uint32 pointer rfeCmdClient_rspArea will point to this address
 *   | | |BASEADDRESS+256        | | |
 *   | | |(256 Bytes)            | | |
 *   | | |                       | | |
 *   | | |Offset 0:   CNT/Trigger| | | <- CNT is used as sequence counter and to be able to detect a new response
 *   | | |Offset 4:   Response ID| | | <- This identifies the command that should be remotely executed
 *   | | |Offset 8:   ReturnLen  | | | <- This is the length of the return values following this value in unit of Bytes
 *   | | |Offset 12:  Return vals| | | <- return values belonging to the commands are placed here
 *   | | |Offset 252: CRC        | | | <- Overall package CRC
 *   | | +-----------------------+ | |
 *
 * State Channel.Messages Structure
 *   | +---------------------------+ |
 *   | | SharedData buffer         | | <- Addressible via rfeCmdClient_cmdArea[RFE_CMD_IF_OFF_SHAREDATA + index]
 *   | | BASEADDRESS+512           | |    (index is the sharedData value to access (0..7)
 *   | | (32 Bytes)                | |
 *   | | Offset  0: SharedData[0]  | | <- rfe state
 *   | | Offset  4: SharedData[1]  | | <- radarCycleCount
 *   | | Offset  8: SharedData[2]  | | <- chirpSequenceCount
 *   | | Offset 12: SharedData[3]  | | <- FirmwareReady
 *   | | Offset 16: SharedData[4]  | | <- reserved
 *   | | Offset 20: SharedData[5]  | | <- reserved
 *   | | Offset 24: SharedData[6]  | | <- reserved
 *   | | Offset 28: SharedData[7]  | | <- reserved
 *   | +---------------------------+ |
 *   |                               |
 *   +-------------------------------+
 *
 */


/*
* @page misra_violations MISRA-C:2012 violations
*
* @section rfe_cmd_client_c_REF_1
* Violates MISRA 2012 Advisory Rule 10.5
* #The value of an expression should not be cast to an inappropriate essential type.
* Necessary cast as the 32 bits value must be interpreted as an enumerated error.
*
* @section rfe_cmd_client_c_REF_2
* Violates MISRA 2012 Required Rule 11.6,
* #A cast shall not be performed between pointer to void and an arithmetic type.
* Necessary cast, as the value must be used into a 32 bits value.
*
* @section rfe_cmd_client_c_REF_3
* Violates MISRA 2012 Required Rule 11.8
* #A cast shall not remove any const or volatile qualification from the type pointed to by a pointer.
* Necessary cast as the standard function prototype doesn't specify a const value.
*
*/


/**********************************************************************************************************************
 *                                                         INCLUDES
 *********************************************************************************************************************/
#include <string.h>
#include "rfe_cmd_client.h"
#include "rfe_types.h"
#include "rfe_error.h"
#include "Rfe20_PCCfg.h"
#include "rfe_ipc_api.h"

/**********************************************************************************************************************
 *                                                 DEFINITIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *                                                 LOCAL VARIABLES
 *********************************************************************************************************************/
/* The memory regions below are shadow versions of the memory regions defined above.
 * If we would not work with shadow copies, then another core could corrupt the
 * shared memory regions just before the CRC is calculated. This would result in a
 * correct CRC on wrong data and not be detected as fault.
 */
/*structures aligned to word to make sure that rfeCmdClient_stsAreaShadow  is updated
 * with a word granularity.
 */
static uint32_t rfeCmdClient_cmdAreaShadow [RFE_CMD_IF_CMDRSPLEN]     __attribute__((aligned(4)));
static uint32_t rfeCmdClient_respAreaShadow[RFE_CMD_IF_CMDRSPLEN]     __attribute__((aligned(4)));
static uint32_t rfeCmdClient_stsAreaShadow[RFE_CMD_IF_SHAREDATACOUNT] __attribute__((aligned(4)));


/* Index for the response buffer to track read position */
static uint32_t rfeCmdClient_readIdx;

/* Below variable is TRUE, when command interface is initialized successfully */
static bool rfeSwCmd_initialized = false;


/**********************************************************************************************************************
 *                                                 VARIABLES
 *********************************************************************************************************************/

/* Define memory regions for command and response window. They get initialized using the rfeCmdClient_sync function
 * There are defined as volatile. A more explicit way to ensure writes is inline assembly based writes. For now
 * we stick to volatile to ensure portability for testing purposes.
 */
static volatile uint32_t*  rfeCmdClient_cmdArea;
static volatile uint32_t*  rfeCmdClient_rspArea;
static volatile uint32_t*  rfeCmdClient_stsArea;

/* command bitmask, indicates which RFE API response trigger a interrupt */
static rfe_apiIRQ_t rfeCmdClient_rfeAPIsInterruptEnabled = RFE_API_IRQ_NONE;

/* command wait callback function */
static rfe_apiWaitForInterrupt_f rfeCmdClient_apiWaitForInterruptFunction = (rfe_apiWaitForInterrupt_f)NULL;

/**********************************************************************************************************************
 *                                                 LOCAL FUNCTIONS
 *********************************************************************************************************************/
/*-----------------------------------------------------------------------------*/
/* Synchronize the command client with the command server:
 * The command client notifies the command server about the location of the command response buffer in shared
 * memory (parameter pcmdIfBase). The data is exchanged using 2 32-bit memory locations at the address defined
 * by RFE_CMD_IF_RFE_STATE_ADDRESS and RFE_CMD_IF_BASE_ADDRESS_PTR
 */
static bool rfeCmdClient_sync(void* pcmdIfBase, volatile rfe_error_t* rfe___error___pointer)
{
    (void)pcmdIfBase;                                               // not used parameter

    bool       synced    = false;                                   // synchronization status
    uint32_t   rfeState  =  0;
    int32_t    local_err = 0;
    void       *buff     = NULL_PTR;


    rfeCmdClient_cmdArea = rfeIpc_clientCmdBuffAquire();
    if(rfeCmdClient_cmdArea == NULL_PTR)
    {
        *rfe___error___pointer = rfe_error_api_unresponsive_e;
    }
    else
    {
        buff = rfeIpc_clientStsWait(&local_err);

        if((local_err != 0) || (buff == NULL_PTR))
        {
            *rfe___error___pointer = rfe_error_api_unresponsive_e;
        }
        else
        {
            /*added word granularity copy to avoid non atomic status read */
            uint32_t  *pMsg = (uint32_t*) buff;
            for(uint32_t i= 0; i < RFE_CMD_IF_SHAREDATACOUNT; i++)
            {
                rfeCmdClient_stsAreaShadow[i] = pMsg[i];
            }

             rfeCmdClient_stsArea = (volatile uint32_t*)&rfeCmdClient_stsAreaShadow[0];
            rfeSwCmd_initialized = true;
            rfeState = rfeCmdClient_sharedDataRead((uint32_t)rfeCmdClient_sharedParameter_fw_ready_e, rfe___error___pointer);
        }
    }


    if(rfeCmdClient_stsArea != NULL_PTR)
    {

        if (rfeState == 0UL)
        { /* synchronization not successful (RFE-Fw command server is not running yet) */
            synced = false;
        }
        else
        { /* synchronization successful     */
            rfeSwCmd_initialized = true;
            synced = true;
        }
    }
    return synced;
}
/*---- rfeCmdClient_sync --------------*/


/*-----------------------------------------------------------------------------*/
/* Read a value from shared command response memory */
static uint32_t rfeCmdClient_readResp(uint32_t offset)
{
    return rfeCmdClient_rspArea[offset];
}
/*---- rfeCmdClient_readResp --------------*/


/*-----------------------------------------------------------------------------*/
/* write command shadow memory to shared memory (called my rfeCmdClient_Call).
 * This call is blocking. A timeout has to be added (but with interrupt extension
 * will solve this too. */
static int32_t rfeCmdClient_commitCmd(uint32_t cmdCnt, uint8_t cmdId)
{
    uint32_t rspCnt, useCallback;
    int32_t local_err = 0;

    /* Calculate and add CRC value to shadow area CRC field                         */
    uint32_t len = (sizeof(uint32_t) * RFE_CMD_IF_OFF_DAT) + rfeCmdClient_cmdAreaShadow[RFE_CMD_IF_OFF_LEN];
    len = (len + 3UL) & 0xfffffffcUL;                  /* message length must be multiple of 4     */
    rfeCmdClient_cmdAreaShadow[RFE_CMD_IF_OFF_CRC] = rfeCrc_calBuf((void*)rfeCmdClient_cmdAreaShadow, len);

    local_err = rfeIpc_clientCmdTx(rfeCmdClient_cmdAreaShadow, RFE_CMD_IF_CMDRSPLEN*4UL);
    if(local_err == 0)
    {
        // define if the command requires callback/interrupt usage
        useCallback = (uint32_t)rfeCmdClient_rfeAPIsInterruptEnabled & (1UL << cmdId);
        /* Wait for the response from RFE-Fw                                            */
        if(((rfe_apiWaitForInterrupt_f)NULL != rfeCmdClient_apiWaitForInterruptFunction) && (useCallback != 0UL))
        {
            rfeCmdClient_apiWaitForInterruptFunction();
        }

        rfeCmdClient_rspArea = (volatile uint32_t*) rfeIpc_clientRspWait(&local_err);
        rspCnt = rfeCmdClient_readResp(RFE_CMD_IF_OFF_CNT);
        if((local_err == 0) && (rspCnt != cmdCnt))
        {
            local_err = 1;
        }
    }
    return local_err;
}
/*---- rfeCmdClient_commitCmd --------------*/


/*-----------------------------------------------------------------------------*/
/* Copy response area to local memory for parsing */
static void rfeCmdClient_cmdRespStart(void)
{
    rfeCmdClient_readIdx = 0UL;             /* set the read index to 0          */
    /* copy the received answer to the shadow area                              */
    /*
    * @violates @ref rfe_cmd_client_c_REF_3 #A cast shall not remove any const or volatile qualification from
    *                                       the type pointed to by a pointer.
    */
    (void)memcpy((void*)rfeCmdClient_respAreaShadow, (void*)rfeCmdClient_rspArea, RFE_CMD_IF_CMDRSPLEN * sizeof(uint32_t));
}
/*---- rfeCmdClient_cmdRespStart --------------*/


/**********************************************************************************************************************
 *                                                  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/*=============================================================================*/
/**
* \brief This function checks whether RFE-Fw is not busy.
*
* \details If RFE-Fw is busy, an error is set to the error pointer.
*
* \pre NIL
*
* \param [in,out]  rfe___error___pointer - Error handling parameter:
*                  On success *rfe___error___pointer is not changed,
*                  On failure *rfe___error___pointer == rfe_error_api_busy_e,
*                  or it get the error from reading the shared memory space
*
* \return NIL
*
* \post NIL
*
* \ingroup NIL
*/
void rfeCmdClient_checkNotBusy(volatile rfe_error_t* rfe___error___pointer)
{
   uint16_t state = rfeCmdClient_sharedDataRead((uint32_t)rfeCmdClient_sharedParameter_state_e,
                                                   rfe___error___pointer);

   if(*rfe___error___pointer == rfe_error_none_e)
   {
       if (state == (uint16_t)rfe_state_busy_e)
       {
           *rfe___error___pointer = rfe_error_api_busy_e;
       }
   }
}
/*==== rfeCmdClient_checkNotBusy ==============*/


/*============================================================================-*/
/* initialize command client */
void rfeCmdClient_init(void* pCmdIfBase, volatile rfe_error_t* rfe___error___pointer)
{
    bool synced;

    synced = rfeCmdClient_sync(pCmdIfBase, rfe___error___pointer); /* get the synch status         */
    if (synced)
    {
        /* synchronized, set the necessary variables to the default values                  */
        /* read cmdcount (trigger count) into command area shadow from shared memory        */
        rfeCmdClient_cmdAreaShadow[RFE_CMD_IF_OFF_CNT] = rfeCmdClient_cmdArea[RFE_CMD_IF_OFF_CNT];

        *rfe___error___pointer = rfe_error_none_e;
    }
    else
    {
        /* not synchronized yet                                                             */
        *rfe___error___pointer = rfe_error_api_unresponsive_e;
    }
}
/*==== rfeCmdClient_init ==============*/


/*==============================================================================*/
/* Start the command parameters, setting the length of the command to 0         */
void rfeCmdClient_cmdParamStart(void)
{
    rfeCmdClient_cmdAreaShadow[RFE_CMD_IF_OFF_LEN] = 0UL;
}
/*==== rfeCmdClient_cmdParamStart ==============*/


/*==============================================================================*/
uint16_t rfeCmdClient_sharedDataRead(uint32_t  idx, volatile rfe_error_t* rfe___error___pointer)
{
    uint16_t upper, lower, retValue = 0U;
    uint32_t RedundantValue;

    if (!rfeSwCmd_initialized)
    {
        /* if the CmdClient was not successfully initialized (by a call to rfeCmdClient_init()), return the error   */
        *rfe___error___pointer = rfe_error_api_unsynchronized_e;
    }
    else
    {
        if (idx < RFE_CMD_IF_SHAREDATACOUNT)
        {

            /*last state will be read*/
            void* buff     = NULL_PTR;
            int32_t err    = 0;
            buff = rfeIpc_clientStsPoll( &err);
            if((buff != NULL_PTR) && (err == 0))
            {
                    uint32_t  *pMsg = (uint32_t*) buff;
                    /*added word granularity copy to avoid non atomic  status read */
                    /*best practice to avoid this is to add a mutex to protect status read and writes*/
                    for(uint32_t i= 0; i < RFE_CMD_IF_SHAREDATACOUNT; i++)
                    {
                        rfeCmdClient_stsAreaShadow[i] = pMsg[i];
                    }
                    rfeCmdClient_stsArea = (volatile uint32_t*)&rfeCmdClient_stsAreaShadow[0];
            }

            RedundantValue = rfeCmdClient_stsArea[idx]; /* keep the redundant value    */
            upper = (uint16_t)((RedundantValue >> 16u) & 0x0000ffffUL);
            lower = (uint16_t)(RedundantValue & 0x0000ffffUL);
            /* In each of the 32 bit value, the least significant 16 bits represent the actual value while
             * remaining 16 bits are invert of first 16 bits. This is the data redundancy technique used.           */
            if ((uint16_t)0xffff == (upper ^ lower))
            {
                retValue = lower;
            }
            else
            {
                *rfe___error___pointer = rfe_error_sharedData_redundancyCheckFailed_e;
            }
        }
        else
        {
            *rfe___error___pointer = rfe_error_sharedData_invalidIndex_e;
        }
    }
    return retValue;
}
/*==== rfeCmdClient_sharedDataRead ==============*/


/*==============================================================================*/
/* Add a predefined buffer to the current constructed command                   */
void rfeCmdClient_cmdParamAddBuffer(const void *pInput, uint32_t byteCount, volatile rfe_error_t* rfe___error___pointer)
{
    uint32_t    cmdLen;
    uint8_t    *pData;

    cmdLen = rfeCmdClient_cmdAreaShadow[RFE_CMD_IF_OFF_LEN];
    if ((cmdLen + byteCount) <= RFE_CMD_IF_MAXDATLEN)
    {
        /* the total command length is under the maximum                        */
        pData  = (uint8_t*)(&rfeCmdClient_cmdAreaShadow[RFE_CMD_IF_OFF_DAT]);
        pData += cmdLen;

        (void)memcpy((void*)pData, pInput, byteCount);
        cmdLen += byteCount;
        rfeCmdClient_cmdAreaShadow[RFE_CMD_IF_OFF_LEN] = cmdLen;
    }
    else
    {
        /* the total command will be over the maximum allowed length            */
        *rfe___error___pointer = rfe_error_cmdInterface_invalidCmdLength_e;
    }
}
/*==== rfeCmdClient_cmdParamAddBuffer ==============*/


/*==============================================================================*/
/*  Read a specified number of bytes from the current response buffer           */
void rfeCmdClient_cmdRespGetBuf(void* pOutput, uint32_t byteCount, volatile rfe_error_t* rfe___error___pointer)
{
    uint8_t *pData;

    if (((rfeCmdClient_readIdx + byteCount) <= rfeCmdClient_respAreaShadow[RFE_CMD_IF_OFF_LEN]) &&
         ((rfeCmdClient_readIdx + byteCount) <= RFE_CMD_IF_MAXDATLEN))
    {
        pData  = (void*)(&rfeCmdClient_respAreaShadow[RFE_CMD_IF_OFF_DAT]);
        pData += rfeCmdClient_readIdx;

        (void)memcpy(pOutput, (void*)pData, byteCount);
        rfeCmdClient_readIdx += byteCount;
    }
    else
    {
        *rfe___error___pointer = rfe_error_cmdInterface_invalidRspLength_e;
    }
}
/*==== rfeCmdClient_cmdRespGetBuf ==============*/


/*==============================================================================*/
void rfeCmdClient_call(rfeCmdServer_cmdId_t cmdId, volatile rfe_error_t* rfe___error___pointer)
{
    uint32_t    cmdCnt;                 /* count of bytes in command buffer                 */
    uint32_t    calculatedCrc, len, err2_raw;

    /* check if the CmdClient was already successfully initialized (by a call to rfeCmdClient_init())               */
    if (!rfeSwCmd_initialized)
    {
        *rfe___error___pointer = rfe_error_api_unsynchronized_e;
    }
    else
    {
        /* populate command shadow structure (command len and data is populated already)                            */
        cmdCnt     = rfeCmdClient_cmdAreaShadow[RFE_CMD_IF_OFF_CNT] + 1UL;
        rfeCmdClient_cmdAreaShadow[RFE_CMD_IF_OFF_ID]  = (uint32_t)cmdId;
        rfeCmdClient_cmdAreaShadow[RFE_CMD_IF_OFF_CNT] = cmdCnt;

        /* trigger the command towards RFE-Fw                                                                       */
        if(rfeCmdClient_commitCmd(cmdCnt, (uint8_t)cmdId) == 0)
        {
            /* create copy of shared memory response structure to the shadow memory                                     */
            rfeCmdClient_cmdRespStart();

            /* Check, if the received respID is a response and matches the previously sent cmdId                        */
            if(rfeCmdClient_respAreaShadow[RFE_CMD_IF_OFF_ID] == ((uint32_t)cmdId | RFE_CMD_IF_RESPONSEBITMASK))
            {
                rfeCmdClient_readIdx = 0UL;                 /* nothing read until now from the response buffer          */

                /* check CRC of response package                                                                        */
                len = (sizeof(uint32_t) * RFE_CMD_IF_OFF_DAT) + rfeCmdClient_respAreaShadow[RFE_CMD_IF_OFF_LEN];
                len = (len + sizeof(uint32_t) - 1UL) & 0xfffffffcUL; /* ceiling round of length to a multiple of 4 bytes */
                calculatedCrc = rfeCrc_calBuf(&rfeCmdClient_respAreaShadow[RFE_CMD_IF_OFF_CNT], len);

                // check the CRC and set the correct error
                if(calculatedCrc != rfeCmdClient_respAreaShadow[RFE_CMD_IF_OFF_CRC])
                {
                    /* CRC of response package is not correct, raise an error                                           */
                    *rfe___error___pointer = rfe_error_cmdInterface_invalidCrc_e;
                }
                else
                {
                    /* parse error code from response as the CRC was correct                                            */
                    err2_raw = rfeCmdClient_cmdRespGetUint32(rfe___error___pointer);
                    /* no error when processing the response, so return the error reported by RFE-Fw (or success)       */
                    /*
                    * @violates @ref rfe_cmd_client_c_REF_1 #The value of an expression should not be cast to
                    *                                       an inappropriate essential type.
                    */
                    *rfe___error___pointer = (rfe_error_t)err2_raw;
                }
            }
            else
            {
                /* The response is not belonging to the sent command                                                    */
                *rfe___error___pointer = rfe_error_cmdInterface_invalidResponse_e;
            }
        }
        else
        {
            *rfe___error___pointer = rfe_error_api_unresponsive_e;
        }
    }
}
/*==== rfeCmdClient_call ==============*/


/*==============================================================================*/
/**
* \brief   Adds a pointer value as parameter to a remote function.
*
* \details Note: The pointer is transported as 32 bit pointer as the SRAM for R41 is placed below 0x100000000.
*          Only physical pointer is used and this is for further compatibility.
*          The function is not blocking.
*
* \pre   Function rfeCmdClient_cmdParamStart() was called.
*
* \param [in] value                                The value that should be added as parameter.
* \param [in, out]     rfe___error___pointer       Error handling parameter:
*                                                  - #rfe_error_none_e = The parameter was added successfully.
*                                                  - #rfe_error_rfeFuSaFault_e  = Too many parameters added to
*                                                      the buffer or this function was called without calling
*                                                      rfeCmdClient_cmdParamStart() as first step of command
*                                                      call preparation.
*
* \post  Other required parameters can be added or the function can be called using the function rfeCmdClient_call().
*
* \ingroup Parameter
*/
void rfeCmdClient_cmdParamAddPointer(void* pValue, volatile rfe_error_t* rfe___error___pointer)
{
    /* This piece of code respects MISRA, but could have issues if run on a 64 bits MSB processor   */
    rfeCmdClient_cmdParamAddBuffer(pValue, sizeof(uint32_t), rfe___error___pointer);
}
/*==== rfeCmdClient_cmdParamAddPointer ==============*/


/*==============================================================================*/
/**
* \brief   Reads an uint8 value from the response buffer.
*
* \details This function is not blocking.
*
* \pre   Function rfeCmdClient_cmdCall() was called without error returned and the remote function added responses.
*
* \param [in, out]     rfe___error___pointer       Error handling parameter:
*                                                  - #rfe_error_none_e = The parameter was added successfully.
*                                                  - #rfe_error_rfeFuSaFault_e  = Read length error.
*
* \post  Other response values can be read.
*
* \return The value read from the response buffer.
*
* \ingroup Responses
*/
uint8_t rfeCmdClient_cmdRespGetUint8(volatile rfe_error_t* rfe___error___pointer)
{
   uint8_t value = 0u;
   rfeCmdClient_cmdRespGetBuf((void*)&value, sizeof(uint8_t), rfe___error___pointer);
   return value;
}
/*==== rfeCmdClient_cmdRespGetUint8 ==============*/


/*==============================================================================*/
/**
* \brief   Reads an uint16 value from the response buffer.
*
* \details This function is not blocking.
*
* \pre   Function rfeCmdClient_cmdCall() was called without error returned and the remote function added responses.
*
* \param [in, out]     rfe___error___pointer       Error handling parameter:
*                                                  - #rfe_error_none_e = The parameter was added successfully.
*                                                  - #rfe_error_rfeFuSaFault_e  = Read length error.
*
* \post  Other response values can be read.
*
* \return The value read from the response buffer.
*
* \ingroup Responses
*/
uint16_t rfeCmdClient_cmdRespGetUint16(volatile rfe_error_t* rfe___error___pointer)
{
   uint16_t value = 0u;
   rfeCmdClient_cmdRespGetBuf((void*)&value, sizeof(uint16_t), rfe___error___pointer);
   return value;
}
/*==== rfeCmdClient_cmdRespGetUint16 ==============*/


/*==============================================================================*/
/**
* \brief   Reads an uint32 value from the response buffer.
*
* \details This function is not blocking.
*
* \pre   Function rfeCmdClient_cmdCall() was called without error returned and the remote function added responses.
*
* \param [in, out]     rfe___error___pointer       Error handling parameter:
*                                                  - #rfe_error_none_e = The parameter was added successfully.
*                                                  - #rfe_error_rfeFuSaFault_e  = Read length error.
*
* \post  Other response values can be read.
*
* \return The value read from the response buffer.
*
* \ingroup Responses
*/
uint32_t rfeCmdClient_cmdRespGetUint32(volatile rfe_error_t* rfe___error___pointer)
{
   uint32_t value = 0UL;
   rfeCmdClient_cmdRespGetBuf((void*)&value, sizeof(uint32_t), rfe___error___pointer);
   return value;
}
/*==== rfeCmdClient_cmdRespGetUint32 ==============*/


/*==============================================================================*/
/**
* \brief   Reads an int8 value from the response buffer.
*
* \details This function is not blocking.
*
* \pre   Function rfeCmdClient_cmdCall() was called without error returned and the remote function added responses.
*
* \param [in, out]     rfe___error___pointer       Error handling parameter:
*                                                  - #rfe_error_none_e = The parameter was added successfully.
*                                                  - #rfe_error_rfeFuSaFault_e  = Read length error.
*
* \post  Other response values can be read.
*
* \return The value read from the response buffer.
*
* \ingroup Responses
*/
int8_t rfeCmdClient_cmdRespGetInt8(volatile rfe_error_t* rfe___error___pointer)
{
   int8_t value = 0;
   rfeCmdClient_cmdRespGetBuf((void*)&value, sizeof(int8_t), rfe___error___pointer);
   return value;
}
/*==== rfeCmdClient_cmdRespGetInt8 ==============*/


/*==============================================================================*/
/**
* \brief   Reads an int16 value from the response buffer.
*
* \details This function is not blocking.
*
* \pre   Function rfeCmdClient_cmdCall() was called without error returned and the remote function added responses.
*
* \param [in, out]     rfe___error___pointer       Error handling parameter:
*                                                  - #rfe_error_none_e = The parameter was added successfully.
*                                                  - #rfe_error_rfeFuSaFault_e  = Read length error.
*
* \post  Other response values can be read.
*
* \return The value read from the response buffer.
*
* \ingroup Responses
*/
int16_t  rfeCmdClient_cmdRespGetInt16(volatile rfe_error_t* rfe___error___pointer)
{
   int16_t value = 0;
   rfeCmdClient_cmdRespGetBuf((void*)&value, sizeof(int16_t), rfe___error___pointer);
   return value;
}
/*==== rfeCmdClient_cmdRespGetInt16 ==============*/


/*==============================================================================*/
/**
* \brief   Reads an int32 value from the response buffer.
*
* \details This function is not blocking.
*
* \pre   Function rfeCmdClient_cmdCall() was called without error returned and the remote function added responses.
*
* \param [in, out]     rfe___error___pointer       Error handling parameter:
*                                                  - #rfe_error_none_e = The parameter was added successfully.
*                                                  - #rfe_error_rfeFuSaFault_e  = Read length error.
*
* \post  Other response values can be read.
*
* \return The value read from the response buffer.
*
* \ingroup Responses
*/
int32_t rfeCmdClient_cmdRespGetInt32(volatile rfe_error_t* rfe___error___pointer)
{
   int32_t value = 0;
   rfeCmdClient_cmdRespGetBuf((void*)&value, sizeof(int32_t), rfe___error___pointer);
   return value;
}
/*==== rfeCmdClient_cmdRespGetInt32 ==============*/


/*==============================================================================*/
/**
* \brief   Reads a bool value from the response buffer
*
* \details Note: a bool is read as 8 bit value. A 0 will translate to false, any other value to true.
*          The function is not blocking.
*
* \pre   Function rfeCmdClient_cmdCall() was called without error returned and the remote function added responses.
*
* \param [in, out]     rfe___error___pointer       Error handling parameter:
*                                                  - #rfe_error_none_e = The parameter was added successfully.
*                                                  - #rfe_error_rfeFuSaFault_e  = Read length error.
*
* \post  Other response values can be read.
*
* \return The value read from the response buffer.
*
* \ingroup Responses
*/
bool rfeCmdClient_cmdRespGetBool(volatile rfe_error_t* rfe___error___pointer)
{
   uint8_t v = 0U;
   rfeCmdClient_cmdRespGetBuf( ( void* )&v, sizeof(uint8_t), rfe___error___pointer);
   return ((v == 0UL) ? false : true );
}


/*==============================================================================*/
/**
 * \brief Return the length of the last received answer from the Fw.
 * \details This is the only function which can inform the application about the length of the last received response.
 *
 * \pre rfe_sync() was called successfully
 *
 *
 * \return  Returns the read value from the sharedData.
 *
 */
uint16_t rfeCmdClient_getCurrentRespLen(void)
{
    return (uint16_t)rfeCmdClient_respAreaShadow[RFE_CMD_IF_OFF_LEN];
}


/*==============================================================================*/
/**
 * \brief   Configure Fw interrupt parameters
 *          The function align the internal API driver parameters to the application request
 *
 * \param [in]          rfeAPIs                         Bitmask of API functions that will trigger an interrupt.
 * \param [in]          apiWaitForInterrupt             Callback to be used if at least one API functions will trigger interrupt.
 */
void rfeCmdClient_configureInterrupt(rfe_apiIRQ_t rfeAPIs, rfe_apiWaitForInterrupt_f apiWaitForInterrupt)
{
    // keep the API mask
    rfeCmdClient_rfeAPIsInterruptEnabled = rfeAPIs;

    // keep the specified callback pointer only if at least one API will generate interrupt
    if(rfeAPIs != RFE_API_IRQ_NONE)
    {
        rfeCmdClient_apiWaitForInterruptFunction = apiWaitForInterrupt;
    }
    else
    {
        rfeCmdClient_apiWaitForInterruptFunction = NULL;
    }
}
