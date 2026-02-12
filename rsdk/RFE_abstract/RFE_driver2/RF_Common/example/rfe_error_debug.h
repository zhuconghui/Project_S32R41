/*
 * Copyright 2024 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */

#ifndef _RFE_ERROR_DEBUG_H_
#define _RFE_ERROR_DEBUG_H_

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
* exported functions
*****************************************************************************/

/**
*
*   \brief      Function to print description of encountered FuSa faults
*
*   \details    The function will lookup rfe_fuSaFault_t, and return char pointer to description
*
*   @param[in]  rfe_fuSaFault_t fuSaFaultId - 16-bit fuSaFaultId 
*   @param[out] pointer to string constant
*/
extern const char *RfeDbg_FusaStringGet( rfe_fuSaFault_t fuSaFaultId );

/**
*
*   \brief      Function to return pointer to string with description of the error
*
*   \details    The function will lookup rfe_error_t, and print hex code and description of the fault
*
*   @param[in]  rfe_error_t error - error number to find description for
*   @param[out] pointer to string constant
*/
extern const char *RfeDbg_GetErrString (rfe_error_t error);


#ifdef __cplusplus
}
#endif

#endif //_RFE_ERROR_DEBUG_H_

