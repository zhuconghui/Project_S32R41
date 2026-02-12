/**************************************************************************************************
* Copyright 2022 - 2024 NXP
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

#ifndef RFE_SW_CFG_TEF82XX_TIMING_REQ_H_
#define RFE_SW_CFG_TEF82XX_TIMING_REQ_H_

/*==================================================================================================
 *                                          INCLUDES
 ==================================================================================================*/

#include <stdint.h>
#include <stdio.h>

#include "rfe_error.h"
#include "bc_types.h"
#include "rfe_sw_driver_state.h"
#include "rfe_sw_cfg_to_tef82xx_map.h"


/*==================================================================================================
 *                          TYPEDEFS (UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/


/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
/**
* @brief     
* @details  
*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
* @brief   Structure to pass the calculated/determined BC_TE_SetRxFilterCtrls parameters.          
* @details HPFResetReleaseCtrl and RxActiveCtrlHPF to determined start reference point of 
*          corresponding delays: false = TDwell(T1) or true = TSettle(T2).
*          HPFResetReleaseDelay_us and RxActiveDelay_us from the reference point for the
*          reset release of the RX HPF filter.    
*/
typedef struct
{
    BOOL      hpfResetReleaseCtrl;
    BOOL      rxActiveCtrl;
    float32_t hpfResetReleaseDelay_us;
    float32_t rxActiveDelay_us;
    
} rfeRxFilterCtrlParams_t;


/*==================================================================================================
 *                                         Functions
 ==================================================================================================*/
/*****************************************************************************
 * @brief   Calculate timings for TE and CAFC based on all related dependencies.
 * @details Depending on below listed inputs, this function will determine and 
 *          calculated the best switching timing required by the TE and CAFC
 *          modules according requirements of RM00227 TEF82xx Reference manual
 *          and RM00228 TEF82xx Register Map. Where applicable, delay start 
 *          reference points are determined. The AN13777 explains this topic 
 *          in a more pragmatic way. Implementation supports NPM and CPM.
 *          Minimum and maximum boundaries of calculated values ore checked 
 *          and/or clipped.
 *          If the used input results in an invalid configuration, and error  
 *     
 *          From pRfeConfig:
 *              Profile definition:
 *              - TDwell_us
 *              - TSettle_us
 *              - From all enabled profiles, find the lowest RX HPF corner frequency
 *          Detected by profile scan: CPM status enabled or disabled.
 *    
 *          Static configuration:
 *              - DCPowerOnDelay_us (applicable for NPM and DPM)
 *      
 *          Timing constrains hidden in the implementation.
 *              - Timing constrain values as described in AN13777.
 *              - Minimum and maximum timing values.
 *   
 *          Output:
 *              The following delay timings are determined/calculated, including control reference points of:
 *              pRfeRxFilterCtrlParams:
 *              - HPFResetReleaseDelay_us
 *              - RxActiveDelay_us
 *              - TXSWAndBPSDelay_us for all enabled profiles.
 *              pStaticConfig:
 *              - RXGroupDelay_us
 *              - TXGroupDelay_us
 *
 * @param [in]      pDrvState  - Pointer to structure containing TEF82xx persistent configuration data.
 * @param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 * @return  NIL
 */
void RfeSwCfgTimingReqCalculateTiming(rfeDriverPersistentMem_t *pDrvState,
		                              rfe_error_t *rfe___error___pointer);

/*****************************************************************************
 * @brief Function gets of the selected profile ID the TX fast switch and BPS control
 *        reference start point
 * @param profileIdx - profile index
 * @param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 * @return boolean  Start reference point T1 (dwell phase) is false or T2 (settle phase) is true
 */
bool RfeSwCfgTimingReqGetTriggerTXSWAndBPSAtTSettle(uint8_t profileIdx,rfe_error_t* rfe___error___pointer);

/*****************************************************************************
 * @brief Function gets of the selected profile ID the delay time before the TX fast
 *        switch and BPS control is enabled. See also getTriggerTXSWAndBPSAtTSettle
 *        that returns reference start point of this delay
 * @param profileIdx - profile index
 * @param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 * @return NIL
 */
float32_t RfeSwCfgTimingReqGetTXSWAndBPSDelay_us(uint8_t profileIdx, rfe_error_t* rfe___error___pointer);

/*****************************************************************************
 * @brief Function gets the TE static configuration data
 * @param [out] -   TE static configuration data
 * @param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 * @return NIL
 */
TE_StaticConfig_t RfeSwCfgTimingReqGetStaticConfig(rfe_error_t* rfe___error___pointer);

/*****************************************************************************
 * @brief Function gets the RX HPF filter data
 * @param [out] -   Pointer to RX HPF filter data
 * @param [in,out]  rfe___error___pointer - Error handling parameter:
 *                  On success #*rfe___error___pointer == rfe_error_none_e is true,
 *                  On failure #*rfe___error___pointer != rfe_error_none_e is true
 *
 * @return delay in us
 */
void RfeSwCfgTimingReqGetRxFilterCtrlParams(rfeRxFilterCtrlParams_t *pRxFilterCtrlParams, rfe_error_t* rfe___error___pointer);

/*****************************************************************************
 * @brief Function gets the maximum Dwell + Settle time and DC Group delay
 * @details Used for IQ pin updates on dynamic tables
 * 
 * @param [out] -   dwellSettleTime - in uS
 * @param [out] -   dcGroupDelay - in uS
 *
 * @return delay in us
 */
void RfeSwCfgTimingReq_GetDynIQUpdatesTiming(float32_t * dwellSettleTimeP, float32_t * dcGroupDelayP);

#endif /* RFE_SW_CFG_TEF82XX_TIMING_REQ_H_ */
