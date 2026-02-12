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
#ifndef RFE_IPC_API_APP_H
#define RFE_IPC_API_APP_H

#if defined(__cplusplus)
extern "C"{
#endif

/**********************************************************************************************************************
*                                        INCLUDE FILES
 *********************************************************************************************************************/
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <rfe_ipc_api.h>

/**********************************************************************************************************************
*                                      DEFINES AND MACROS
 *********************************************************************************************************************/
/*
 * Interprocess communication timeout expressed in number of retries
 */
#define RFE_IPC_TIMEOUT                (100000000UL)

#if RFE_IPC_TIMEOUT_DISABLED != 0
#define DECREMENT_TMO(X)
#else
#define DECREMENT_TMO(X) ((X)--)
#endif
/**********************************************************************************************************************
 *                              FUNCTIONS PROTOTYPES. Called on Server Side
 *********************************************************************************************************************/


/**
* \brief          Initialize interprocess communication API
* \details        The function must check initialization communication channels between customer application and RFE-Fw
*
* @param[in]    none
* @param[out]   none
*
* \return       int32_t - status code indicating success (0) or failure (!=0)
*/
extern int32_t rfeIpc_srvInit(void);

/**
* \brief          Check  interprocess communication initialization state API
* \details        The function must do all necessary step to check IPC initialization state
*
* @param[in]    none
* @param[out]   none
*
* \return       int32_t - status code indicating success (0) or failure (!=0)
*/
extern int32_t rfeIpc_srvInitCheck(void);


/**********************************************************************************************************************
 *                              FUNCTIONS PROTOTYPES. Called on Client Side
 *********************************************************************************************************************/

/**
* \brief          Initialize interprocess communication API
* \details        The function must check initialization communication channels between customer application and RFE-Fw
*
* @param[in]    none
* @param[out]   none
*
* \return       int32_t - status code indicating success (0) or failure (!=0)
*/
extern int32_t rfeIpc_clientInit(void);


#if defined(__cplusplus)
}
#endif

#endif /* RFE_IPC_API_APP_H */

