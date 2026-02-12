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
 *   Project              : RF_Abstract_2.0
 *   Platform             : S32R41
 *****************************************************************************/

#ifndef RFE_ERROR_H
#define RFE_ERROR_H
/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
 * \brief RFE-SW specific assert mechanism.
 *
 * \param condition A boolean condition that should normally be true.
 * \param error The error condition to set in case the condition fails.
 */
#ifdef RFE_ERROR_ENABLE_ASSERT
    #define RFE_ERROR_ASSERT( condition, error )    ( rfe_error_assert( condition, error, RFE_ERROR_ASSERT_FILE_NUMBER, __LINE__, RFE_ERROR_FUNCTION_ARGUMENT ) )
#else
    #define RFE_ERROR_ASSERT( condition, error )    {}
#endif // RFE_ERROR_ENABLE_ASSERT

#endif // !RFE_ERROR_H
