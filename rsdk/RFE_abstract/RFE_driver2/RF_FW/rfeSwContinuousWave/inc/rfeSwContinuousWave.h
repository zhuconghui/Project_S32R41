/*
    Copyright 2023 NXP
    NXP Confidential. This software is owned or controlled by NXP and may only be
    used strictly in accordance with the applicable license terms. By expressly
    accepting such terms or by downloading, installing, activating and/or otherwise
    using the software, you are agreeing that you have read, and that you agree to
    comply with and are bound by, such license terms.  If you do not agree to be
    bound by the applicable license terms, then you may not retain, install,
    activate or otherwise use the software.
 */

/*
 * rfeSwContinuousWave.h
 *
 */

/*====================================================================================================================
 *   Project              : RFE_SW
 *   Platform             : S32R41-TEF82xx
 ====================================================================================================================*/
#ifndef RFE_SW_CONTINOUS_WAVE_H
#define RFE_SW_CONTINOUS_WAVE_H

/*====================================================================================================================
 *                              INCLUDES
 ====================================================================================================================*/
#include "rfe_error.h"
#include "rfe_types.h"

/*====================================================================================================================
 *                                      DEFINES
 ====================================================================================================================*/

/*====================================================================================================================
 *                                      TYPES
 ====================================================================================================================*/

/*====================================================================================================================
 *                                       GLOBALS
 ====================================================================================================================*/

/*====================================================================================================================
 *                                       FUNCTIONS
====================================================================================================================*/
/**
 * \brief   Start the continuous wave mode testing.
 *
 * \details 
 * 
 * \pre Must be called after config
 *
 * \param [in]      profileIndex - profile used for continuous wave testing.
 * \param [in,out]  rfe___error___pointer - Error handling parameter.
 *
 * \post  
 *
 * \return NIL
 */
void rfeSwContinuousWave_Start(rfe_chirpProfileIndex_t profileIndex, rfe_error_t* rfe___error___pointer);

/**
 * \brief   Start the continuous wave mode testing.
 *
 * \details 
 * 
 * \pre Must be called after continuous wave start.
 *
 * \param [in,out]  rfe___error___pointer - Error handling parameter.
 *
 * \return NIL
 */
void rfeSwContinuousWave_Stop(rfe_error_t* rfe___error___pointer);

#endif // !RFE_SW_CONTINOUS_WAVE_H
