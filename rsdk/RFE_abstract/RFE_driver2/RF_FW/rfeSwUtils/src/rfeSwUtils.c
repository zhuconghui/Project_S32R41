/*
    Copyright 2024 NXP
    NXP Confidential. This software is owned or controlled by NXP and may only be
    used strictly in accordance with the applicable license terms. By expressly
    accepting such terms or by downloading, installing, activating and/or otherwise
    using the software, you are agreeing that you have read, and that you agree to
    comply with and are bound by, such license terms.  If you do not agree to be
    bound by the applicable license terms, then you may not retain, install,
    activate or otherwise use the software.
 */

/*
 * rfeSwUtils.c
 */

/*==================================================================================================
 *   Project              : RFE_SW
 *   Platform             : S32R41-TEF82xx
 ==================================================================================================*/

/*==================================================================================================
 *                                        INCLUDE FILES
 ==================================================================================================*/
#include "rfeSwUtils.h"
#include "rfe_sw_driver_state.h"
#include "rfeDspMath.h"

// TEF82xx LLD
#include "bc_sys.h"

#ifdef __cplusplus
extern "C" {
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*====================================================================================================================
 *                                      TYPES
 ====================================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*====================================================================================================================
 *                                   LOCAL VARIABLES
======================================================================================================================*/

/*====================================================================================================================
 *                                   LOCAL FUNCTION PROTOTYPES
======================================================================================================================*/

/*====================================================================================================================
 *                                   LOCAL FUNCTIONS
======================================================================================================================*/

/*====================================================================================================================
 *									 PUBLIC FUNCTIONS
======================================================================================================================*/
void rfeSwUtils_SelectFe(uint8_t feIdx)
{
    RfeDrvStateFrontendIdSet((uint32_t)feIdx);
    (void) BC_SYS_SetDevice((PLF_SPITarget_e) feIdx);
}
/*====================================================================================================================*/
rfe_error_t rfeSwUtils_SetError(rfe_error_t rfeError, uint8_t feIdx)
{
    uint32_t rfeErrorValue;
    rfeErrorValue = ((uint32_t)rfeError) | (((uint32_t)feIdx) << 8U);
    return (rfe_error_t)rfeErrorValue;
}
/*====================================================================================================================*/
rfe_bistInterval_t rfeSwUtils_BistIntervalMapper(uint8_t interval)
{
    rfe_bistInterval_t bistInterval;

    switch(interval)
    {
        case 0U:
            bistInterval = rfe_bistInterval_everyRadarCycle_e;
            break;
        case 1U:
            bistInterval = rfe_bistInterval_onceIn2RadarCycles_e;
            break;
        case 2U:
            bistInterval = rfe_bistInterval_onceIn4RadarCycles_e;
            break;
        default:
            bistInterval = rfe_bistInterval_none_e;
            break;
    }
    return bistInterval;
}
/*====================================================================================================================*/
rfeSwBist_InjectToneMode_t rfeSwUtils_BistInjectToneMode(uint8_t injectMode)
{
    rfeSwBist_InjectToneMode_t injectModeType;
    switch(injectMode)
    {
        case 0U:
            injectModeType = TEF82XX_both_lna_mixer;
            break;
        case 1U:
            injectModeType = TEF82XX_only_mixer;
            break;
        case 2U:
            injectModeType = TEF82XX_alternate_lna_mixer;
            break;
        default:
            injectModeType = InjectToneMode_Invalid;
            break;
    }    
    return injectModeType;
}
/*====================================================================================================================*/
rfe_effectiveSamplingFrequency_t rfeSwUtils_SamplingFrequency(uint8_t samplingFreq)
{
    rfe_effectiveSamplingFrequency_t samplingFreqType;

    switch(samplingFreq)
    {
        case 0U:
            samplingFreqType = rfe_effectiveSamplingFrequency_40MHz_e;
            break;
        case 1U:
            samplingFreqType = rfe_effectiveSamplingFrequency_20MHz_e;
            break;
        case 2U:
            samplingFreqType = rfe_effectiveSamplingFrequency_10MHz_e;
            break;
        case 3U:
            samplingFreqType = rfe_effectiveSamplingFrequency_5MHz_e;
            break;
        default:
            samplingFreqType = rfe_effectiveSamplingFrequency_40MHz_e;
            break;
    }    
    return samplingFreqType;    
}
/*====================================================================================================================*/
float32_t rfeSwUtils_radians2degrees(float32_t radians)
{
    return (radians * (180.0F / M_PI));
}
/*====================================================================================================================*/
float32_t rfeSwUtils_degrees2radians(float32_t degrees)
{
    return (degrees * (M_PI / 180.0F));
}

#ifdef __cplusplus
}
#endif

/*====================================================================================================================
 * EOF
 *====================================================================================================================*/

/** @} */
