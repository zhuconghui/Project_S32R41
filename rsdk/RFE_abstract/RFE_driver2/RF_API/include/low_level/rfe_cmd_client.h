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

#ifndef RFE_CMD_CLIENT_H
#define RFE_CMD_CLIENT_H

#ifdef __cplusplus
extern "C"
{
#endif

/**********************************************************************************************************************
 *                                                         INCLUDES
 *********************************************************************************************************************/

#include <stdint.h>
#include <stdbool.h>
#include "rfe_error.h"
#include "rfe_cmd_interface.h"
#include "rfe_types.h"

/**
*   @addtogroup rsdk_rfe_const
*   @{
*
*/

/**********************************************************************************************************************
 *                                                         DEFINES
 *********************************************************************************************************************/

/**
 * This macro defines the section value for the dynamic table, that is used in the rfe_updateDynamicTable() API function
 */
#define RFE_CMD_CLIENT_UPDATE_SECTION_DYNAMIC_TABLE     (0xFFFFUL)

/**
 * This macro defines the number of FuSa fault bytes
 */
#define RFE_CMD_CLIENT_FUSA_FAULT_BYTE_COUNT            (12UL)


/**
*   @}
*   @addtogroup rsdk_rfe_interface
*   @{
*
*/

/**********************************************************************************************************************
 *                                                         TYPES
 *********************************************************************************************************************/
/**
 * This structure defines a structured parameter update
 */
typedef struct
{
    uint16_t section;
    uint16_t param;
    uint32_t value;
} rfeCmdClient_update_t;

/**
 * This structure defines a shared parameter type
 */
typedef enum
{
    rfeCmdClient_sharedParameter_state_e,
    rfeCmdClient_sharedParameter_radarCycleCount_e,
    rfeCmdClient_sharedParameter_chirpSequenceCount_e,
    rfeCmdClient_sharedParameter_fw_ready_e,
} rfeCmdClient_sharedParameter_t;


/**********************************************************************************************************************
 *                                                         FUNCTIONS
 *********************************************************************************************************************/

 /**
 * \brief   Initialize the RFE-Fw command client
 *
 * \details The initialization function initializes the command client.
 *          This initialization does mainly align on the shared memory address of the command response interface.
 *          If the RFE-Fw command server is not initialized when calling this function, it returns immediately
 *          the error code rfe_error_api_unresponsive_e.
 *          Calling this function before the RFE-Fw command server is running, will not lead to undefined behavior,
 *          but for correct operation of the command client this function has to be executed once without an error.
 *
 *          Pseudocode for successful initialization independent of RFE-Fw command server state:
 *          <BR>
 *          do
 *          {
 *              rfeCmdClient_init( <a shared memory address>, rfe___error___pointer);
 *          }while(rfe_error_api_unresponsive_e == *rfe___error___pointer);
 *          if ( rfe_error_none_e == *rfe___error___pointer )
 *          {
 *              ... (successfully initialized the RFE-Fw command client. Communication with RFE-Fw is enabled!)
 *          }
 *
 * \pre    ECC protection of shared memory has to be initialized
 *
 * \param [in]          pCmdIfBase              A pointer to the start of the command response memory region.
 *                                              The memory region has to be RFE_CMD_IF_CMDRSPLEN*2*4 bytes long.
 *                                              The memory region has to be uncached.
 * \param [in, out]     rfe___error___pointer   Error handling parameter:
 *                                              - #rfe_error_none_e = No error occured.
 *                                              - #rfe_error_api_unresponsive_e = RFE-Fw command server do not respond.
 *                                              The function has to be called again until success.
 *
 * \post  If the function executed with an error code rfe_error_none_e, the command client is ready to
 *        communicate with RFE-Fw.
 *
 */
void rfeCmdClient_init(void* pCmdIfBase, volatile rfe_error_t* rfe___error___pointer);


 /**
 * \brief   Calls a remote command.
 *
 * \details This function will trigger a command execution on RFE-Fw. Before calling this function,
 *          the parameters of the function have to be added using the command client functions
 *          starting with the function name rfeCmdClient_cmdParamAdd (e.g. rfeCmdClient_cmdParamAddUint8).
 *
 *          rfeCmdClient_call() will return once the RFE-Fw has finished executing the command and written
 *          the response data to shared memory (i.e. blocking in behavior).
 *          In case the function executed successfully, response data can be read using functions starting
 *          with the name rfeCmdClient_cmdRespGet (e.g. rfeCmdClient_cmdRespGetUint8).
 *
 *          The Error code will contain errors from rfe command client layer, rfe command server layer and
 *          the remotely executed API function.
 *
 * \pre    The command interface is initialized successfully using the function rfeCmdClient_init(). The
 *         function rfeCmdClient_cmdParamStart() was called before this function. If the remote function
 *         requires parameters they have to be added too.
 *
 * \param [in]          cmdId                       A command ID matching the command that should be executed
 *                                                  (see rfeCmdServer_cmdId_t definition)
 * \param [in, out]     rfe___error___pointer       Error handling parameter:
 *                                                  - #rfe_error_none_e = No error occurred.
 *                                                  - Any other value  = An error occurred.
 *
 * \post  If successful: The command finished executing on RFE-Fw. In case the function returns response values
 *        they can be read using the rfeCmdClient_cmdRespGet*() functions.
 *
 */
void rfeCmdClient_call(rfeCmdServer_cmdId_t cmdId, volatile rfe_error_t* rfe___error___pointer);


 /**
 * \brief   Starts the preparation for the call of a remote RFE-Fw function.
 *
 * \details When calling functions on RFE-Fw, this function has to be executed as first step to prepare the remote
 *          function call. After calling this function the required parameters can be added to the function call.
 *
 * \pre    The command interface is initialized successfully using the function rfeCmdClient_init().
 *
 * \post  Function parameters can be added and the remote function called using rfeCmdClient_call()
 *
 */
void rfeCmdClient_cmdParamStart(void);


 /**
 * \brief   Adds an arbitrary block of data as parameter to a function.
 *
 * \details Note: This function is non blocking.
 *
 * \pre   Function rfeCmdClient_cmdParamStart() was called.
 *
 * \param [in]          pInput                      A pointer to the buffer containing the data
 *                                                  that should be added as parameter.
 * \param [in]          byteCount                   The count of bytes that should be added from the buffer.
 * \param [in, out]     rfe___error___pointer       Error handling parameter:
 *                                                  - #rfe_error_none_e = The parameter was added successfully.
 *                                                  - #rfe_error_rfeFuSaFault_e  = Too many parameters added to
 *                                                      the buffer or this function was called without calling
 *                                                      rfeCmdClient_cmdParamStart() as first step of command
 *                                                      call preparation.
 *
 * \post  Other required parameters can be added or the function can be called using the function rfeCmdClient_call().
 *
 */
void rfeCmdClient_cmdParamAddBuffer(const void* pInput, uint32_t byteCount,
                                                    volatile rfe_error_t* rfe___error___pointer);


 /**
 * \brief   Adds an uint8_t value as parameter to a remote function.
 *
 * \details Note: This function is non blocking.
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
 */
static inline void rfeCmdClient_cmdParamAddUint8(uint8_t value, volatile rfe_error_t* rfe___error___pointer)
{
    rfeCmdClient_cmdParamAddBuffer(&value, sizeof(uint8_t), rfe___error___pointer );
}


 /**
 * \brief   Adds an uint16_t value as parameter to a remote function.
 *
 * \details Note: This function is non blocking.
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
 */
static inline void rfeCmdClient_cmdParamAddUint16(uint16_t value, volatile rfe_error_t* rfe___error___pointer)
{
    rfeCmdClient_cmdParamAddBuffer(&value, sizeof(uint16_t), rfe___error___pointer );
}


 /**
 * \brief   Adds an uint32_t value as parameter to a remote function.
 *
 * \details Note: This function is non blocking.
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
 */
static inline void rfeCmdClient_cmdParamAddUint32(uint32_t value, volatile rfe_error_t* rfe___error___pointer)
{
    rfeCmdClient_cmdParamAddBuffer(&value, sizeof(uint32_t), rfe___error___pointer );
}


 /**
 * \brief   Adds an int8_t value as parameter to a remote function.
 *
 * \details Note: This function is non blocking.
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
 */
static inline void rfeCmdClient_cmdParamAddInt8(int8_t value, volatile rfe_error_t* rfe___error___pointer)
{
    rfeCmdClient_cmdParamAddBuffer(&value, sizeof(int8_t), rfe___error___pointer );
}


 /**
 * \brief   Adds an int16_t value as parameter to a remote function.
 *
 * \details Note: This function is non blocking.
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
 */
static inline void rfeCmdClient_cmdParamAddInt16(int16_t value, volatile rfe_error_t* rfe___error___pointer)
{
    rfeCmdClient_cmdParamAddBuffer(&value, sizeof(int16_t), rfe___error___pointer );
}


 /**
 * \brief   Adds an int32_t value as parameter to a remote function.
 *
 * \details Note: This function is non blocking.
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
 */
static inline void rfeCmdClient_cmdParamAddInt32(int32_t value, volatile rfe_error_t* rfe___error___pointer)
{
    rfeCmdClient_cmdParamAddBuffer(&value, sizeof(int32_t), rfe___error___pointer );
}


 /**
 * \brief   Adds a bool value as parameter to a remote function.
 *
 * \details Note: A bool value is internally written as 8 bit value with 0 for false and 1 for true.
 *                The function is not blocking.
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
 */
static inline void rfeCmdClient_cmdParamAddBool(bool value, volatile rfe_error_t* rfe___error___pointer)
{
    rfeCmdClient_cmdParamAddUint8((value == true) ? (uint8_t)1 : (uint8_t)0, rfe___error___pointer);
}


 /**
 * \brief   Adds a pointer value as parameter to a remote function.
 *
 * \details Note: The pointer is transported as 32 bit pointer as the SRAM for R41 is placed below 0x100000000.
 *          Only physical pointer is used and this is for further compatibility.
 *          The function is not blocking.
 *
 * \pre   Function rfeCmdClient_cmdParamStart() was called.
 *
 * \param [in] pValue                               The pointer value that should be added as parameter.
 * \param [in, out]     rfe___error___pointer       Error handling parameter:
 *                                                  - #rfe_error_none_e = The parameter was added successfully.
 *                                                  - #rfe_error_rfeFuSaFault_e  = Too many parameters added to
 *                                                      the buffer or this function was called without calling
 *                                                      rfeCmdClient_cmdParamStart() as first step of command
 *                                                      call preparation.
 *
 * \post  Other required parameters can be added or the function can be called using the function rfeCmdClient_call().
 *
 */
void rfeCmdClient_cmdParamAddPointer(void* pValue, volatile rfe_error_t* rfe___error___pointer);


 /**
 * \brief   Reads an arbitrary block of data from the response buffer.
 *
 * \details This function can be used to read an array of data from the response buffer.
 *          The function is not blocking.
 *
 * \pre   Function rfeCmdClient_cmdCall() was called without error returned and the remote function added responses.
 *
 * \param [in] pOutput                              Pointer to the memory where the read data should be written to.
 * \param [in] byteCount                            The count of bytes that should be read from response buffer
 *                                                  and written to *pOutput.
 * \param [in, out]     rfe___error___pointer       Error handling parameter:
 *                                                  - #rfe_error_none_e = The parameter was added successfully.
 *                                                  - #rfe_error_rfeFuSaFault_e  = Read length error.
 *
 * \post  Other response values can be read.
 *
 */
 void rfeCmdClient_cmdRespGetBuf(void* pOutput, uint32_t byteCount, volatile rfe_error_t* rfe___error___pointer);


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
 */
uint8_t rfeCmdClient_cmdRespGetUint8(volatile rfe_error_t* rfe___error___pointer);


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
 */
uint16_t rfeCmdClient_cmdRespGetUint16(volatile rfe_error_t* rfe___error___pointer);


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
 */
uint32_t rfeCmdClient_cmdRespGetUint32(volatile rfe_error_t* rfe___error___pointer);


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
 */
int8_t rfeCmdClient_cmdRespGetInt8(volatile rfe_error_t* rfe___error___pointer);


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
 */
int16_t  rfeCmdClient_cmdRespGetInt16(volatile rfe_error_t* rfe___error___pointer);


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
 */
int32_t rfeCmdClient_cmdRespGetInt32(volatile rfe_error_t* rfe___error___pointer);


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
 */
bool rfeCmdClient_cmdRespGetBool(volatile rfe_error_t* rfe___error___pointer);


/**
 * \brief Reads a SharedData location.
 * \details SharedData is a set of register like values, which is written by RFE-M7-0 and can be read
 *          from the client. The values are 16-bit unsigned integers, but stored as 32 Bit values internally
 *
 * \pre rfe_sync() was called successfully
 *
 * \param [in]          idx                     The sharedData index to be read
 * \param [in, out]     rfe___error___pointer   Error handling parameter
 *
 * \return  Returns the read value from the sharedData.
 *
 */
uint16_t rfeCmdClient_sharedDataRead(uint32_t  idx, volatile rfe_error_t* rfe___error___pointer);

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
uint16_t rfeCmdClient_getCurrentRespLen(void);


/*=============================================================================*/
/**
* \brief This function checks whether RFE-Fw is not busy.
*
* \details If RFE-Fw is busy, an error is set to the error pointer.
*
* \param [in,out]  rfe___error___pointer - Error handling parameter:
*                  On success *rfe___error___pointer is not changed,
*                  On failure *rfe___error___pointer == rfe_error_api_busy_e,
*                  or it get the error from reading the shared memory space
*
*/
void rfeCmdClient_checkNotBusy(volatile rfe_error_t* rfe___error___pointer);

/**
 * \brief   Configure Fw interrupt parameters
 *          The function align the internal API driver parameters to the application request
 *
 * \param [in]          rfeAPIs                         Bitmask of API functions that will trigger an interrupt.
 * \param [in]          apiWaitForInterrupt             Callback to be used if at least one API functions will trigger interrupt.
 */
void rfeCmdClient_configureInterrupt(rfe_apiIRQ_t rfeAPIs, rfe_apiWaitForInterrupt_f apiWaitForInterrupt);

/** @} */

#ifdef __cplusplus
}
#endif


#endif // !RFE_CMD_CLIENT_H
