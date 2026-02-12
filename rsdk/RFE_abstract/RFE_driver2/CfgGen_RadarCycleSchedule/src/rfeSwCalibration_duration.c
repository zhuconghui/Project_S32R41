/*
    Copyright 2021, 2023-2024 NXP  
    NXP Confidential. This software is owned or controlled by NXP and may only be 
    used strictly in accordance with the applicable license terms. By expressly 
    accepting such terms or by downloading, installing, activating and/or otherwise
    using the software, you are agreeing that you have read, and that you agree to
    comply with and are bound by, such license terms.  If you do not agree to be 
    bound by the applicable license terms, then you may not retain, install, 
    activate or otherwise use the software.
 */

/******************************************************************************
 *   Project              : S32R41_RFE_FW
 *   Platform             : S32R41
 *****************************************************************************/



/******************************************************************************
 *                              INCLUDES
 *****************************************************************************/

#include "rfe_types.h"
#include "rfe_blob_access.h"
#include "rfeSwCalibration_duration.h"

/******************************************************************************
 *                              TYPES
 *****************************************************************************/

/******************************************************************************
 *                              FUNCTIONS
 *****************************************************************************/

/*Both these are Calculated Per Chirp Sequence*/

static uint32_t profileDependentDuration[RFE_CHIRP_SEQUENCES_PER_RADAR_CYCLE_MAX] = { 0ul }; 
static uint32_t profileIndependentDuration[RFE_CHIRP_SEQUENCES_PER_RADAR_CYCLE_MAX] = { 0ul }; 

#ifdef NXP_INTERNAL_CALIBRATION_CALCULATION_MODE
uint32_t rfeSwCalibration_calcProfileDependentCalibrationDuration(
    uint8_t chirpSequenceIndex,
    rfe_error_t* rfe___error___pointer
)
{
    uint32_t duration = 0ul;  
    if ( rfe_error_none_e != *rfe___error___pointer )
    {
        duration = profileDependentDuration[chirpSequenceIndex];
    }
    return duration;
}

uint32_t rfeSwCalibration_calcProfileIndependentCalibrationDuration(
    uint8_t chirpSequenceIndex,
    rfe_error_t* rfe___error___pointer
)
{
    uint32_t duration = 0ul; 
    if ( rfe_error_none_e != *rfe___error___pointer )
    {
        duration = profileIndependentDuration[chirpSequenceIndex];
    }
    return duration;
}
#endif /* NXP_INTERNAL_CALIBRATION_CALCULATION_MODE */

uint32_t rfeSwCalibration_calcRecalibrationDuration(
    const uint8_t* pRfeConfig,
    uint8_t chirpSequenceIndex,
    rfe_error_t* rfe___error___pointer
)
{
    uint32_t duration = 0ul;
    if ( rfe_error_none_e != *rfe___error___pointer )
    {
        // Find if profile-indepentant calibration is required
        /* rfe_chirpSequencesSelect_t profIndeSeqs = rfeCfg_radarCycle_getRecalibrateProfileIndependent( pRfeConfig,
                                                                                    rfe___error___pointer );
        rfe_chirpSequencesSelect_t sequenceBit = ( rfe_chirpSequencesSelect_t )( 1ul << chirpSequenceIndex );
        bool doProfileIndependent = ( ( profIndeSeqs & sequenceBit ) != 0ul ); */
        
		bool doProfileIndependent = false;
		
        // Count number of selected profiles from profile-dependent selction word
        uint32_t numProfiles = 0ul;
        uint8_t profileCount = rfeCfg_metadata_getChirpProfileCount( pRfeConfig, rfe___error___pointer );
        /* rfe_chirpProfilesSelect_t profileDependent = rfeCfg_radarCycle_getRecalibrateProfileDependent( pRfeConfig,
                                                                                            chirpSequenceIndex,
                                                                                    rfe___error___pointer ); */
        for( rfe_chirpProfileIndex_t idx = rfe_chirpProfileIndex_0_e; idx < profileCount; idx++ )
        {
            // Count profile
            /* bool isDependent = ( profileDependent & ( 1ul << idx ) ) != 0ul; */
			bool isDependent = false;
            rfe_txSelect_t transmissionEnable = rfeCfg_chirpProfile_getTxTransmissionEnable( pRfeConfig, idx,
                                                                                rfe___error___pointer );
            numProfiles += ( isDependent && ( RFE_TX_SELECT_NONE != transmissionEnable ) ) ? 1ul : 0ul;
        }
        
        if ( rfe_error_none_e != *rfe___error___pointer )
        {
            duration = ( doProfileIndependent ) ? RFE_SW_CALIBRATION_MAX_PROFILE_INDEPENDENT_DURATION_TICKS : 0ul;
            profileIndependentDuration[chirpSequenceIndex] = duration; 
            duration += numProfiles * RFE_SW_CALIBRATION_MAX_PROFILE_DEPENDENT_DURATION_TICKS;
            profileDependentDuration[chirpSequenceIndex] = duration - profileIndependentDuration[chirpSequenceIndex];
        }
    }
    return duration;   
}

