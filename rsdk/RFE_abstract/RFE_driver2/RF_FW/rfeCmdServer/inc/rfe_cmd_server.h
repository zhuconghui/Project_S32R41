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


/**********************************************************************************************************************
 *   Project              : S32R41_RFE_FW
 *   Platform             : S32R41
 *********************************************************************************************************************/

#ifndef RFE_CMD_SERVER_H
#define RFE_CMD_SERVER_H

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include <stdint.h>
#include <stdbool.h>
#include "rfe_error.h"
#include "rfe_cmd_interface.h"
#include "typedefs.h"
#include "rfe_types.h"

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

 /**
 * \brief   Synchronize the RFE-Fw command server with the RFE-API command client.
 *
 * \details This function is non-blocking and should be called until it returns success (i.e. true).
 *          The initialization will define the command/response memory window location as provided by the client.
 *
 * \pre    rfeIpc_srvInit() application to initialize transport communication before
 *
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success rfeError_error_none_e is returned
 *
 * \post  In case the function is successful, the command server is ready for interaction with it.
 *
 * \return bool - Returns whether synchronization was successfull.
 */
bool rfeCmdServer_sync(rfe_error_t* rfe___error___pointer);


/**
 * \brief   Check, if a new command is available for handling.
 * \details The function is not single trigger, thus for a single command received, it will continuously report true.
 *          When handling a command, the function will report false, unless a new command was received.
 *          The function is non blocking.
 *
 * \param   [out]   pCmdId  cmdAVailable can return the cmdId of the command to be executed next.
 *                          A zero pointer can be provided, in case the caller does not need this information.
 *                          If no command is available, this value will be written to 0.
 *
 * \return  true       if a new command was received
 *          false      if no new command is available
 */
bool rfeCmdServer_cmdAvailable(uint8_t *pCmdId);


/**
 * \brief Handle a command. If a command is received, it will be checked for integrity and
 *  the appropriate handler will be executed from the dispatcher table (externally defined rfeCmdServerDispTab).
 *
 * \details If no command is received, the function returns immediately ERR_CMDRESP_NO_COMMAND_RECEIVED.
 *          Several errors can occur, the error value being returned if required by the calling client.
 *
 * \pre rfeIpc_srvInit() application to initialize transport communication protocol successfully
 *
 * \param [in]      dropCmdError            error => The command will not be handled, only the result returned
 *                                          no error => The command will be handled = dispatched (normal usage)
 * \param [in, out] rfe___error___pointer   Error handling pointer
 *
 * \post No state change
 *
 * \return NIL
 */
void rfeCmdServer_handlecmd(rfe_error_t dropCmdError, rfe_error_t* rfe___error___pointer);


/**
 * \Brief Read the count of unread bytes left from the received parameter data
 *
 * \pre A command was received
 *
 * \param [in, out]     rfe___error___pointer   Error handling pointer
 *
 * \post No state change
 *
 * \return                    The count of unread bytes in the receive data
 */
uint32_t rfeCmdServer_cmdParamGetByteCount(rfe_error_t* rfe___error___pointer);


/**
 * \Brief Read multiple parameters as provided by command client.
 *
 * \pre A command was received
 *
 * \param [in]			byteCount               The count of bytes to read
 * \param [out]         pOutput					Pointer to the memory location where the read data is written too.
 * \param [in, out]     rfe___error___pointer   Error handling pointer
 *
 * \post the data was read from the parameter buffer
 *
 * \return NIL
 */
void     rfeCmdServer_cmdParamReadBuf(void* pOutput, uint32_t byteCount, rfe_error_t* rfe___error___pointer);


/**
 * \Brief Read a uint8 value from the received parameter buffer.
 *
 * \pre A command was received
 *
 * \param [in, out]     rfe___error___pointer   Error handling pointer
 *
 * \return              The read value
 *
 * \post The command parameter was read
 */
static inline uint8_t rfeCmdServer_cmdParamReadUint8(rfe_error_t* rfe___error___pointer)
{
    uint8_t value = 0U;
    rfeCmdServer_cmdParamReadBuf(&value, sizeof(value), rfe___error___pointer);
    return value;
}


/**
 * \Brief Read a uint16 value from the received parameter buffer.
 *
 * \pre A command was received
 *
 * \param [in, out]     rfe___error___pointer   Error handling parameter
 *
 * \return              The read value
 *
 * \post The command parameter was read
 */
static inline uint16_t rfeCmdServer_cmdParamReadUint16(rfe_error_t* rfe___error___pointer)
{
    uint16_t value = 0U;
    rfeCmdServer_cmdParamReadBuf(&value, sizeof(value), rfe___error___pointer);
    return value;
}

/**
 * \Brief Read a uint32 value from the received parameter buffer.
 *
 * \pre A command was received
 *
 * \param [in, out]     rfe___error___pointer   Error handling parameter
 *
 * \return              The read value
 *
 * \post The command parameter was read
 */
static inline uint32_t rfeCmdServer_cmdParamReadUint32(rfe_error_t* rfe___error___pointer)
{
    uint32_t value = 0UL;
    rfeCmdServer_cmdParamReadBuf(&value, sizeof(value), rfe___error___pointer);
    return value;
}

/**
 * \Brief Read a int8 value from the received parameter buffer.
 *
 * \pre A command was received
 *
 * \param [in, out]     rfe___error___pointer   Error handling parameter
 *
 * \return              The read value
 *
 * \post The command parameter was read
 */
static inline int8_t rfeCmdServer_cmdParamReadInt8(rfe_error_t* rfe___error___pointer)
{
    int8_t value = 0;
    rfeCmdServer_cmdParamReadBuf(&value, sizeof(value), rfe___error___pointer);
    return value;
}

/**
 * \Brief Read a int16 value from the received parameter buffer.
 *
 * \pre A command was received
 *
 * \param [in, out]     rfe___error___pointer   Error handling parameter
 *
 * \return              The read value
 *
 * \post The command parameter was read
 */
static inline int16_t rfeCmdServer_cmdParamReadInt16(rfe_error_t* rfe___error___pointer)
{
    int16_t value = 0;
    rfeCmdServer_cmdParamReadBuf(&value, sizeof(value), rfe___error___pointer);
    return value;
}

/**
 * \Brief Read a int32 value from the received parameter buffer.
 *
 * \pre A command was received
 *
 * \param [in, out]     rfe___error___pointer   Error handling parameter
 *
 * \return              The read value
 *
 * \post The command parameter was read
 */
static inline int32_t rfeCmdServer_cmdParamReadInt32(rfe_error_t* rfe___error___pointer)
{
    int32_t value = 0;
    rfeCmdServer_cmdParamReadBuf(&value, sizeof(value), rfe___error___pointer);
    return value;
}

/**
 * \Brief Read a bool value from the received parameter buffer (a bool is a 8 bit value).
 *
 * \pre A command was received
 *
 * \param [in, out]     rfe___error___pointer   Error handling parameter
 *
 * \return              The read value
 *
 * \post The command parameter was read
 */
static inline bool rfeCmdServer_cmdParamReadBool(rfe_error_t* rfe___error___pointer)
{
    uint8_t value = 0U;
    rfeCmdServer_cmdParamReadBuf(&value, sizeof(value), rfe___error___pointer);
    return ((value == 0U) ? false : true);
}

/**
 * \Brief Read a pointer value from the received parameter buffer.
 *
 * \pre A command was received
 *
 * \param [in, out]     rfe___error___pointer   Error handling parameter
 *
 * \return              The read value
 *
 * \post The command parameter was read
 */
static inline void* rfeCmdServer_cmdParamReadPointer(rfe_error_t* rfe___error___pointer)
{
    void* ptr= (void*)0UL;
    rfeCmdServer_cmdParamReadBuf((void*)&ptr, sizeof(uint32_t), rfe___error___pointer);
    return (void*)ptr;
}

/**
 * \Brief Write response data to the response buffer.
 *
 * \pre A command was received and all Parameters read.
 *
 * \param [out]         pInput                         Pointer to the data to write
 * \param [in]          byteCount					   The count of bytes to write
 * \param [in, out]     rfe___error___pointer   Error handling parameter
 *
 * \post The response data was written
 *
 * \return NIL
 */
void rfeCmdServer_cmdRespWriteBuf(void *pInput, uint32_t byteCount, rfe_error_t* rfe___error___pointer);

/**
 * \Brief Write a uint8 value to the response buffer.
 *
 * \pre A command was received and all Parameters read.
 *
 * \param [in]          value					   	   The value to write
 * \param [in, out]     rfe___error___pointer   Error handling parameter
 *
 * \post The response data was written
 *
 * \return NIL
 */
static inline void rfeCmdServer_cmdRespWriteUint8(uint8_t value, rfe_error_t* rfe___error___pointer)
{
    rfeCmdServer_cmdRespWriteBuf(&value, sizeof(value), rfe___error___pointer);
}

/**
 * \Brief Write a uint16 value to the response buffer.
 *
 * \pre A command was received and all Parameters read.
 *
 * \param [in]          value					   	   The value to write
 * \param [in, out]     rfe___error___pointer   Error handling parameter
 *
 * \post The response data was written
 *
 * \return NIL
 */
static inline void rfeCmdServer_cmdRespWriteUint16(uint16_t value, rfe_error_t* rfe___error___pointer)
{
    rfeCmdServer_cmdRespWriteBuf(&value, sizeof(value), rfe___error___pointer);
}

/**
 * \Brief Write a uint32 value to the response buffer.
 *
 * \pre A command was received and all Parameters read.
 *
 * \param [in]          value					   	   The value to write
 * \param [in, out]     rfe___error___pointer   Error handling parameter
 *
 * \post The response data was written
 *
 * \return NIL
*/
static inline void rfeCmdServer_cmdRespWriteUint32(uint32_t value, rfe_error_t* rfe___error___pointer)
{
    rfeCmdServer_cmdRespWriteBuf(&value, sizeof(value), rfe___error___pointer);
}

/**
 * \Brief Write a float32 value to the response buffer.
 *
 * \pre A command was received and all Parameters read.
 *
 * \param [in]          value					   	   The value to write
 * \param [in, out]     rfe___error___pointer   Error handling parameter
 *
 * \post The response data was written
 *
 * \return NIL
*/
static inline void rfeCmdServer_cmdRespWriteFloat32(float32_t value, rfe_error_t* rfe___error___pointer)
{
    rfeCmdServer_cmdRespWriteBuf(&value, sizeof(value), rfe___error___pointer);
}

/**
 * \Brief Write a int8 value to the response buffer.
 *
 * \pre A command was received and all Parameters read.
 *
 * \param [in]          value					   	   The value to write
 * \param [in, out]     rfe___error___pointer   Error handling parameter
 *
 * \post The response data was written
 *
 * \return NIL
 */
static inline void rfeCmdServer_cmdRespWriteInt8(int8_t value, rfe_error_t* rfe___error___pointer)
{
    rfeCmdServer_cmdRespWriteBuf(&value, sizeof(value), rfe___error___pointer);
}

/**
 * \Brief Write a int16 value to the response buffer.
 *
 * \pre A command was received and all Parameters read.
 *
 * \param [in]          value					   	   The value to write
 * \param [in, out]     rfe___error___pointer   Error handling parameter
 *
 * \post The response data was written
 *
 * \return NIL
 */
static inline void rfeCmdServer_cmdRespWriteInt16(int16_t value, rfe_error_t* rfe___error___pointer)
{
    rfeCmdServer_cmdRespWriteBuf(&value, sizeof(value), rfe___error___pointer);
}


/**
 * \Brief Write a int32 value to the response buffer.
 *
 * \pre A command was received and all Parameters read.
 *
 * \param [in]          value					   	   The value to write
 * \param [in, out]     rfe___error___pointer   Error handling parameter
 *
 * \post The response data was written
 *
 * \return NIL
 */
static inline void rfeCmdServer_cmdRespWriteInt32(int32_t value, rfe_error_t* rfe___error___pointer)
{
    rfeCmdServer_cmdRespWriteBuf(&value, sizeof(value), rfe___error___pointer);
}

/**
 * \Brief Write a bool value to the response buffer (A bool is 8 bit wide).
 *
 * \pre A command was received and all Parameters read.
 *
 * \param [in]          value					   	   The value to write
 * \param [in, out]     rfe___error___pointer   Error handling parameter
 *
 * \post The response data was written
 *
 * \return NIL
 */
static inline void rfeCmdServer_cmdRespWriteBool(bool value, rfe_error_t* rfe___error___pointer)
{
    rfeCmdServer_cmdRespWriteUint8((value ? (uint8_t)1 : (uint8_t)0), rfe___error___pointer);
}


/**
 * \Brief Write a SharedData location with information
 *
 * \pre rfeIpc_srvInit() application to initialize transport communication protocol successfully
 *
 * \param [in]          idx					   	       The sharedData index to write (each index is a unique memory location)
 * \param [in]          value					   	   The value to write
 * \param [in, out]     rfe___error___pointer   Error handling parameter
 *
 * \post The updated SharedData location is written.
 *
 * \return NIL
 */
void rfeCmdServer_sharedDataWrite(uint32_t  idx, uint16_t  value, rfe_error_t* rfe___error___pointer);

/**
 * \brief Register which core will the interrupts and which events and commands will be
 *        sources of interrupts.
 */
void rfeCmdServer_registerIRQSources(
    rfe_coreId_t        coreId,
    rfe_eventsIRQ_t     events,
    rfe_apiIRQ_t        rfeAPIs
);

#endif /* !RFE_CMD_SERVER_H */
