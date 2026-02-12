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
 * rfeSwContinuousWave.c
 */

/*==================================================================================================
 *   Project              : RFE_SW
 *   Platform             : S32R41-TEF82xx
 ==================================================================================================*/

/*==================================================================================================
 *                                        INCLUDE FILES
 ==================================================================================================*/
#include <stddef.h>
#include <string.h>
#include "rfe_sw_cfg_tef82xx.h"
#include "rfe_sw_calib_tef82xx.h"
#include "rfe_sw_cfg_to_tef82xx_map.h"
#include "rfeSwContinuousWave.h"
#include "rfe_sw_driver_state.h"
#include "rfe_blob_access.h"
#include "rfeSwUtils.h"

// BCD LLD
#include "bc_err.h"
#include "bc_types.h"
#include "bc_tx.h"
#include "bc_sys.h"
#include "bc_te.h"
#include "bc_spi.h"
#include "reg_es2_cc.h"

#ifdef __cplusplus
extern "C" {
#endif

/*====================================================================================================================
 *                                          CONSTANTS
 ====================================================================================================================*/

/*====================================================================================================================
 *                                      TYPES
 ====================================================================================================================*/

/*====================================================================================================================
 *                                      DEFINES AND MACROS
 ====================================================================================================================*/

/*====================================================================================================================
 *                                   LOCAL VARIABLES
======================================================================================================================*/

/*====================================================================================================================
 *                                   LOCAL FUNCTION PROTOTYPES
======================================================================================================================*/
static uint8_t FindProfile(rfe_chirpProfileIndex_t profileIndex, rfe_error_t* rfe___error___pointer);

static void EnableTEF82xxTXIPs(rfe_chirpProfileIndex_t profileIndex, rfe_error_t* rfe___error___pointer);

static void Tef82xxIpFunctionalReset(rfe_chirpProfileIndex_t profileIndex, rfe_error_t* rfe___error___pointer);
/*====================================================================================================================
 *                                       LOCAL FUNCTIONS
======================================================================================================================*/
static uint8_t FindProfile(rfe_chirpProfileIndex_t profileIndex, rfe_error_t* rfe___error___pointer)
{
    uint8_t chirpSequenceFound = 0U;
    uint8_t idxSeq, idxProf;
    rfeDriverPersistentMem_t *pDrvState = NULL;
            
    if (*rfe___error___pointer == rfe_error_none_e)
    {
        pDrvState = RfeDrvStateGet();
        for(idxSeq = 0U; idxSeq < rfeCfg_metadata_getChirpSequenceConfigCount(pDrvState->rfeConfig, rfe___error___pointer); idxSeq++)
        {
            for(idxProf = 0U; idxProf < (uint8_t)RFE_MAX_CHIRP_PROFILES; idxProf++)
            {
                if (pDrvState->tef82xxDrvState.radarCycleParams.chirpSequences[idxSeq].profList[idxProf] == (uint8_t)profileIndex)
                {
                    chirpSequenceFound = idxSeq;
                    break;
                }
            }
        }
    }
    return chirpSequenceFound;
}
/*====================================================================================================================*/
static void EnableTEF82xxTXIPs(rfe_chirpProfileIndex_t profileIndex, rfe_error_t* rfe___error___pointer)
{
    BC_ERRCODE               errCode = BC_ERR_NOERROR;
    rfeDriverPersistentMem_t *pDrvState = NULL;
    uint8_t                  feIndex;
    
    if (*rfe___error___pointer == rfe_error_none_e)
    {  
        for( feIndex = 0; feIndex < RfeDrvStateNoFrontendsGet(); feIndex++)
        {
            rfeSwUtils_SelectFe(feIndex);
            pDrvState = RfeDrvStateGet();
            // Disable dynamic power mode
            errCode = rfeSwCfgSetDynPowMode(e_NO_DPM_ACTIVE);
            if ((errCode == BC_ERR_NOERROR) && (((pDrvState->tef82xxDrvState.txChannelEnable[profileIndex] >> (uint8_t)RFE_TX_CHANNEL_0) & 0x01UL) != 0UL))
            {
                errCode = BC_TX_ConfigLocalCtrl(e_SYS_TX1, FALSE, FALSE, FALSE, 0.0f, TRUE, TRUE);
            }
            if ((errCode == BC_ERR_NOERROR) && (((pDrvState->tef82xxDrvState.txChannelEnable[profileIndex] >> (uint8_t)RFE_TX_CHANNEL_1) & 0x01UL) != 0UL))
            {
                errCode = BC_TX_ConfigLocalCtrl(e_SYS_TX2, FALSE, FALSE, FALSE, 0.0f, TRUE, TRUE);
            }
            if ((errCode == BC_ERR_NOERROR) && (((pDrvState->tef82xxDrvState.txChannelEnable[profileIndex] >> (uint8_t)RFE_TX_CHANNEL_2) & 0x01UL) != 0UL))
            {
                errCode = BC_TX_ConfigLocalCtrl(e_SYS_TX3, FALSE, FALSE, FALSE, 0.0f, TRUE, TRUE);
            }
        }
        if (errCode != BC_ERR_NOERROR)
        {
            *rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
        }
    }
}
/*====================================================================================================================*/
static void Tef82xxIpFunctionalReset(rfe_chirpProfileIndex_t profileIndex, rfe_error_t* rfe___error___pointer)
{
	BC_ERRCODE               errCode = BC_ERR_NOERROR;
    uint8_t                  feIndex;
    uint8_t        		     profList[8] = { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U}; // No custom profile list needed, we just use profile provided
    R2M00_IpFunctionalResetControlUnion_t IpFunctionalResetRelease;

	if (*rfe___error___pointer == rfe_error_none_e)
	{
        for(feIndex = 0U; feIndex < RfeDrvStateNoFrontendsGet(); feIndex++)
        {
        	rfeSwUtils_SelectFe(feIndex);
			// Select profile
			errCode = BC_TE_ConfigProfileSequencing((SYS_ProfID_e)profileIndex, profList, TEF82XX_DEFAULT_PROF_STAY_CNT, (BOOL)TEF82XX_DEFAULT_PROF_RESET, TRUE, 0U);
            // Functional Reset
            if (errCode == BC_ERR_NOERROR)
            {
                errCode = BC_SPI_Read(e_SYS_CC, R2M00_IP_FUNCTIONAL_RESET_CONTROL_U16, &IpFunctionalResetRelease.val_u32);
            }
            if (errCode == BC_ERR_NOERROR)
            {
                IpFunctionalResetRelease.bits_st.FnResetChirp = 0U;
                errCode = BC_SPI_WriteCheck(e_SYS_CC, R2M00_IP_FUNCTIONAL_RESET_CONTROL_U16, IpFunctionalResetRelease.val_u32);
            }

            if (errCode  == BC_ERR_NOERROR )
            {
                IpFunctionalResetRelease.bits_st.FnResetChirp = 1U;
                errCode = BC_SPI_WriteCheck(e_SYS_CC, R2M00_IP_FUNCTIONAL_RESET_CONTROL_U16, IpFunctionalResetRelease.val_u32);
            }
            else
            {
                break;
            }
        }
        if (errCode != BC_ERR_NOERROR)
        {
            *rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
        }        
    }
}  
/*====================================================================================================================
 *                                       GLOBAL FUNCTIONS
====================================================================================================================*/
void rfeSwContinuousWave_Start(rfe_chirpProfileIndex_t profileIndex, rfe_error_t* rfe___error___pointer)
{
    uint8_t chirpSequence = 0U;

    // Perform functional IP reset
    Tef82xxIpFunctionalReset(profileIndex, rfe___error___pointer);
    // Select Leader
    rfeSwUtils_SelectFe((uint8_t)rfeFrontEndId_0);
    // Search profile in sequences
    chirpSequence = FindProfile(profileIndex, rfe___error___pointer);
    // Do calibration for sequence that contains selected profile
    rfeSwCalibTef82xxCalibration(chirpSequence, rfe___error___pointer);
    // Enable IP TX transmission
    EnableTEF82xxTXIPs(profileIndex, rfe___error___pointer);
}
/*====================================================================================================================*/
void rfeSwContinuousWave_Stop(rfe_error_t* rfe___error___pointer)
{
    BC_ERRCODE errCode = BC_ERR_NOERROR;
    uint8_t    txIdx;
    uint8_t    feIndex = RfeDrvStateNoFrontendsGet() - 1U;

    if (*rfe___error___pointer == rfe_error_none_e)
    {
        // Start from Follower because we enable DPM 
        for( ; ; )
        {
        	rfeSwUtils_SelectFe(feIndex);
            // Disable all TXs
            for(txIdx = 0; txIdx < (uint8_t)RFE_MAX_TX_CHANNELS; txIdx++)
            {
                if (errCode == BC_ERR_NOERROR)
                {
                    errCode = BC_TX_ConfigLocalCtrl((SYS_IPNum_e)((uint8_t)e_SYS_TX1 + txIdx), FALSE, FALSE, FALSE, 0.0f, FALSE, FALSE);
                }
                else
                {
                    break;
                }
            }
            if (errCode == BC_ERR_NOERROR)
            {
                // Enable dynamic power mode
                errCode = rfeSwCfgSetDynPowMode(e_DPM_ACTIVE);
            }
            else
            {
                break;
            }
            if (feIndex == 0U)
            {
                break;
            }
            feIndex--;
        }
        if (errCode != BC_ERR_NOERROR)
        {
            *rfe___error___pointer = Tef82xxErrToRfeErrorMapper(errCode);
        }        
    }
}
/*====================================================================================================================*/

#ifdef __cplusplus
}
#endif

/*====================================================================================================================
 * EOF
 *====================================================================================================================*/

/** @} */
