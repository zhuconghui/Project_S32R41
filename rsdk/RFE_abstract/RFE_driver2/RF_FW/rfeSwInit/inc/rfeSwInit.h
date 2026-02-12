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

#ifndef RFE_SW_INIT_H
#define RFE_SW_INIT_H

/******************************************************************************
 *                              INCLUDES
 *****************************************************************************/

#include <stdint.h>
#include "rfe_error.h"

/******************************************************************************
 *                              TYPES
 *****************************************************************************/
/**
 * This enumerated type defines the FE ids.
 */
typedef enum
{
	rfeFrontEndId_0 = 0U,
	rfeFrontEndId_1 = 1U,
	rfeFrontEndId_2 = 2U,
	rfeFrontEndId_3 = 3U,
} rfeFrontendId_t;

/******************************************************************************
 *                              DEFINES
 *****************************************************************************/
#define CALIBRATION_TIMEOUT_RETRIES		3

/*==================================================================================================
 *                                      GLOBAL FUNCTIONS
 ==================================================================================================*/
/**
 * \brief This function initializes RFE
 *
 * \details This function performs all 23 required steps to initialize RFE to a working mode.
 * All steps in this function are  not application dependent.
 *
 * \pre NIL
 *
 * \param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 * \return NIL
 *
 * \post NIL
 */
void rfeSwInit_initialize(rfe_error_t* rfe___error___pointer);

#endif // RFE_SW_INIT_H
