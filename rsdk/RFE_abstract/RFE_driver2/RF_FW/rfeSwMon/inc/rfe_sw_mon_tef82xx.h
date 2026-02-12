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

#ifndef RFE_SW_MON_TEF82XX_H_
#define RFE_SW_MON_TEF82XX_H_

/*==================================================================================================
 *                                          INCLUDES
 ==================================================================================================*/
#include "rfe_types.h"
#include "rfe_sw_driver_state.h"
/*==================================================================================================
 *                          TYPEDEFS (UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
// Value to enable temperature measurements by Low level API's 
#define RFE_ENABLE_TEMPERATURE_MEASUREMENT      (1.0f)
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
 *                                         Functions
 ==================================================================================================*/
/**
 * \brief This function performs temperature measurement of TX1,2,3 and Chirp modules
 *
 * \pre NIL
 *
 * \param in		outputValues - 
 *
 * \param [in,out]  rfe___error___pointer - Error handling parameter.
 *
 * \return NIL
 *
 * \post
 * -
 * -
 *
 * \ingroup NIL
 */
void rfeSwMon_getTemperatureMeasurement( rfe_temperature_t *outputValues,  rfe_error_t* rfe___error___pointer );

/**
 * \brief 			Main monitoring function for the TEF82xx frontends
 *
 * \param [in]		measureTemperature    		   - true = measure temperature
 * \param [in]		currentChirpSequenceIndexParam - current Chirp Sequence
 * \param [in,out]  rfe___error___pointer 		   - Error handling parameter.
 *
 * \return NIL
 *
 */
void rfeMon_performFEMonitoring(bool measureTemperature, uint8_t currentChirpSequenceIndexParam, rfe_error_t* rfe___error___pointer);

/**
 * \brief 			Monitoring function for the TEF82xx frontends to be used before start chirping
 *
 * \param [in]		measureTemperature    - true = measure temperature
 * \param [in,out]  rfe___error___pointer - Error handling parameter.
 *
 * \return NIL
 *
 */
void rfeSwMon_monitorDataBeforeChirping(bool measureTemperature, rfe_error_t* rfe___error___pointer);

/**
 * \brief This function get pointer of rfeMonitorValues
 *
 * \return pointer of rfeMonitorValues
 *
 */
rfe_monitorValues_t* rfeMon_getRfeMonitorValues(void);

#endif /* RFE_SW_CFG_TEF82XX_H_ */
