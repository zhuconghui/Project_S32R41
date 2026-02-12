/*
* Copyright 2024 NXP
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
#ifndef RFE_IPC_API_H
#define RFE_IPC_API_H

#if defined(__cplusplus)
extern "C"{
#endif

/**
* @addtogroup rsdk_rfe_ipc_api_interface
* @{
*/

/**********************************************************************************************************************
*                                        INCLUDE FILES
 *********************************************************************************************************************/
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

/**********************************************************************************************************************
*                                      DEFINES AND MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *                              FUNCTIONS PROTOTYPES. Called on Server Side
 *********************************************************************************************************************/
/**
* \brief          Acquire  command response buffer.
* \details        The function must provide  message container used by the transport protocol to communicate between RFE-Fw and Driver.
*                 Used for initial initialization synchronization.
*
*
* \return      *void - pointer to a transport buffer
*/

extern void* rfeIpc_srvRspBuffAcquire(void);

/**
* \brief          Acquire status buffer.
* \details        The function must provide  message container used by the transport protocol to communicate between RFE-Fw and Driver.
*                 Used for initial initialization synchronization.
*
* \return      *void - pointer to a transport buffer
*/
extern void* rfeIpc_srvStsBuffAcquire(void);

/**
* \brief          Transmit status API
* \details        The function is used transmit a status update messages between RFE-Fw and Driver.
*                 It is used in an asynchronous mode
*
* \param[in]    msg      - pointer to message that needs to be transmitted
* \param[in]    msgLen   - message length
*
* \return       int32_t  - status code indicating success (0) or failure (!=0)
*/
extern int32_t rfeIpc_srvStsTx(void* msg, uint32_t msgLen);

/**
* \brief          Transmit response API
* \details        The function must transmit a command response messages between RFE-Fw and Driver
*
* \param[in]    msg      - pointer to message that needs to be transmitted
* \param[in]    msgLen   - message length
*
* \return       int32_t - status code indicating success (0) or failure (!=0)
*/
extern int32_t rfeIpc_srvRspTx(void* msg, uint32_t msgLen);
/**
* \brief          Poll Commands channel API
* \details        The function must poll the command channel used by RFE-Fw to receive commands from Driver
*                 This must be a nonblocking function
*
* \param[out]    *err   - status code indicating success (0) or failure (!=0)
*
* \return        *void    - pointer to the received buffer
*/
extern void* rfeIpc_srvCmdPoll(int32_t *err);



/**********************************************************************************************************************
 *                              FUNCTIONS PROTOTYPES. Called on Client Side
 *********************************************************************************************************************/


/**
* \brief          Acquire cmd buffer.
* \details        The function must provide  message container used by the transport protocol to communicate between customer application and RFE-Fw
*                 Used for initial initialization synchronization.
*
* \return      *void - pointer to a transport buffer
*/
extern void* rfeIpc_clientCmdBuffAquire(void);

/**
* \brief          Transmit command API
* \details        The function must transmit a command messages between Driver and RFE-Fw
*
* \param[in]    msg      - pointer to message that needs to be transmitted
* \param[in]    msgLen   - message length
*
* \return       int32_t  - status code indicating success (0) or failure (!=0)
*/
extern int32_t rfeIpc_clientCmdTx(void* msg, uint32_t msgLen);

/**
* \brief          Poll State channel API
* \details        The function must poll state channel used to update RFE-Fw state for the driver running on application side
*                 This must be a nonblocking function
*
* \return       *void    - pointer to a transport buffer
*/
extern void* rfeIpc_clientStsPoll(int32_t *err);

/**
* \brief          Blocking poll on state channel API
* \details        The function must  poll in blocking manner on state channel. Used to synchronize application and RFE-Fw
*
* \param[out]   *err     - status code indicating success (0) or failure (!=0)
*
* \return       *void    -- pointer to the receive message
*/
extern void* rfeIpc_clientStsWait(int32_t *err);

/**
* \brief          Blocking poll on response channel API
* \details        The function must  poll in blocking manner on response channel. Used to get the command acknowledge from RFE-Fw side
*
* \param[out]   *err     - status code indicating success (0) or failure (!=0)
*
* \return       *void    -- pointer to the receive message
*/
extern void* rfeIpc_clientRspWait(int32_t *err);

/**
 * @}
 */


#if defined(__cplusplus)
}
#endif
#endif // !RFE_IPC_API_H

