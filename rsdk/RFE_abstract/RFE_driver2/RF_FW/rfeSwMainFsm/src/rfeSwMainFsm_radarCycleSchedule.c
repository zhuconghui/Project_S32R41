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

/******************************************************************************
 *                              INCLUDES
 *****************************************************************************/

#include "rfeSwMainFsm.h"
#include "rfeSwMainFsm_internal.h"
#include "rfe_blob_access.h"
#include "rfe_sw_cfg_to_tef82xx_map.h"
#ifdef RFE_DEBUG
#include "rfe_debug.h"
#endif
#ifdef BLOB_GENERATOR
#include <stdio.h>
#endif
/******************************************************************************
 *                              DEFINES
 *****************************************************************************/
#ifdef BLOB_GENERATOR
#define RfeDbgPrintMsg printf
#endif
/******************************************************************************
 *                              LOCAL VARIABLES
 *****************************************************************************/
rfeSwMainFsm_radarCycleTimingSchedule_t radarCycleTimeSchedule;
uint8_t chirpSequences[RFE_CHIRP_SEQUENCES_PER_RADAR_CYCLE_MAX];
uint8_t chirpSequencesPerRadarCycle;
/******************************************************************************
 *                           LOCAL FUNCTIONS PROTOTYPES
 *****************************************************************************/
#ifdef RFE_DEBUG
static void rfeSwMainFsm_debugPrintCycleTimeSchedule();
#endif
static void rfeSwMainFsm_checkIdleTime(rfe_error_t* rfe___error___pointer);
static void rfeMainFsm_checkStartOffsetDuration(uint8_t chirpSequenceIndex, rfe_error_t* rfe___error___pointer);
static void rfeSwMainFsm_calcSequenceTimingSchedule( const uint8_t *pRfeConfig_arg, uint8_t chirpSequenceIndex, uint32_t chirpSequenceStartTimeOffsetIndex0, uint32_t radarCycleDuration, rfe_error_t* rfe___error___pointer);
/******************************************************************************
 *                           LOCAL FUNCTIONS
 *****************************************************************************/
#ifdef RFE_DEBUG
static void rfeSwMainFsm_debugPrintCycleTimeSchedule()
{
    uint8_t chirpSequenceIndex;
    uint8_t state;

    for(chirpSequenceIndex = 0U; chirpSequenceIndex < chirpSequencesPerRadarCycle; chirpSequenceIndex++)
    {
        RfeDbgPrintMsg("\nSequence %u\n", chirpSequenceIndex);
        for( state = 0U; state < RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_COUNT; state++)
        {
            RfeDbgPrintMsg("%s - %u\n", gStateName[state], radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[chirpSequenceIndex][state]);
        }
    }
}
#endif

static void rfeSwMainFsm_checkIdleTime(rfe_error_t* rfe___error___pointer)
{
    int32_t radarCycleIdleDuration;

    if(*rfe___error___pointer == rfe_error_none_e)
    {
        for(uint8_t chirpSequenceIndex = 0U; chirpSequenceIndex < chirpSequencesPerRadarCycle; chirpSequenceIndex++)
        {
            radarCycleIdleDuration = (int32_t)(radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[chirpSequenceIndex][rfeSwMainFsm_radarCycleState_idle_e] -
                    radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[chirpSequenceIndex][rfeSwMainFsm_radarCycleState_powerOff_e]);

            if(radarCycleIdleDuration < (int32_t)RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_IDLE_DURATION_MIN)
            {
                if(*rfe___error___pointer == rfe_error_none_e)
                {
                    *rfe___error___pointer = rfe_error_api_invalidRadarCycleTimeSchedule_e;
#ifdef RFE_DEBUG
                    RfeDbgPrintMsg("For %u sequence radarCycleIdleDuration=%d", chirpSequenceIndex, radarCycleIdleDuration); 
                    rfeSwMainFsm_debugPrintCycleTimeSchedule();
#endif                            
                }
            }
            else
            {
                // Idle duration okay
            }
#ifdef BLOB_GENERATOR
            if(radarCycleIdleDuration < (int32_t)RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_IDLE_DURATION_MIN_FOR_CMD)
            {
                    RfeDbgPrintMsg("\nWarning: For %u sequence idle duration may not be enough for a stop command!\n", chirpSequenceIndex); 
            }
#endif
        }
    }
}

static void rfeMainFsm_checkStartOffsetDuration(uint8_t chirpSequenceIndex, rfe_error_t* rfe___error___pointer)
{
	int32_t  startOffsetDuration; // start-offset duration can be calculated as negative and error should be triggered

    if(*rfe___error___pointer == rfe_error_none_e)
    {
        radarCycleTimeSchedule.stateEndTimeTicks[(uint32_t)rfeSwMainFsm_radarCycleState_startOffset_e - RFE_SW_MAIN_FSM_RADAR_CYCLE_CHIRP_SEQUENCE_LOOP_STATE_COUNT] =
                radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[chirpSequenceIndex][rfeSwMainFsm_radarCycleState_powerOn_e] -
                (uint32_t)RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_POWER_ON_DURATION;
        //Calculate the startOffset state duration to be added in state machine
        startOffsetDuration = (int32_t)(radarCycleTimeSchedule.stateEndTimeTicks[(uint32_t)rfeSwMainFsm_radarCycleState_startOffset_e - RFE_SW_MAIN_FSM_RADAR_CYCLE_CHIRP_SEQUENCE_LOOP_STATE_COUNT] -
            radarCycleTimeSchedule.stateEndTimeTicks[(uint32_t)rfeSwMainFsm_radarCycleState_begin_e - RFE_SW_MAIN_FSM_RADAR_CYCLE_CHIRP_SEQUENCE_LOOP_STATE_COUNT] );
        if(startOffsetDuration < (int32_t)RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_START_OFFSET_DURATION_MIN)
        {
            if(*rfe___error___pointer == rfe_error_none_e)
            {
                *rfe___error___pointer = rfe_error_api_invalidRadarCycleTimeSchedule_e;
#ifdef RFE_DEBUG
                RfeDbgPrintMsg("For %u sequence startOffsetDuration=%d", chirpSequenceIndex, startOffsetDuration); 
                rfeSwMainFsm_debugPrintCycleTimeSchedule();
#endif                            
            }
        }
        else
        {
            //Start offset Duration is okay
        }
    }
}  

static void rfeSwMainFsm_calcSequenceTimingSchedule( const uint8_t *pRfeConfig_arg, uint8_t chirpSequenceIndex, uint32_t chirpSequenceStartTimeOffsetIndex0, uint32_t radarCycleDuration, rfe_error_t* rfe___error___pointer)
{
    uint32_t chirpSequenceStartTimeOffset;
    uint32_t chirpSequenceDuration;

    if(*rfe___error___pointer == rfe_error_none_e)
    {
        chirpSequenceDuration = rfeSwMainFsm_calcChirpSequenceDuration( pRfeConfig_arg, (rfe_chirpSequenceIndex_t)chirpSequences[chirpSequenceIndex], rfe___error___pointer);
        if(chirpSequenceStartTimeOffsetIndex0 == 0UL)
        {
            if(chirpSequenceIndex == 0U)
            {
                radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[chirpSequenceIndex][rfeSwMainFsm_radarCycleState_powerOn_e] =
                        radarCycleTimeSchedule.stateEndTimeTicks[(uint32_t)rfeSwMainFsm_radarCycleState_begin_e - RFE_SW_MAIN_FSM_RADAR_CYCLE_CHIRP_SEQUENCE_LOOP_STATE_COUNT] +
                        (uint32_t)RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_POWER_ON_DURATION;
                radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[chirpSequenceIndex][rfeSwMainFsm_radarCycleState_initChirpSequence_e] =
                        radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[chirpSequenceIndex][rfeSwMainFsm_radarCycleState_powerOn_e] +
                        (uint32_t)RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_INIT_CHIRP_SEQUENCE_DURATION;
                radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[chirpSequenceIndex][rfeSwMainFsm_radarCycleState_recalibration_e] =
                        radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[chirpSequenceIndex][rfeSwMainFsm_radarCycleState_initChirpSequence_e] + (uint32_t)RFE_SW_CALIBRATION_MAX_PROFILE_INDEPENDENT_DURATION_TICKS;
            }
            else
            {
                chirpSequenceStartTimeOffset = rfeCfg_radarCycle_getChirpSequenceStartTimeOffset( pRfeConfig_arg, chirpSequenceIndex, rfe___error___pointer);
                radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[chirpSequenceIndex][rfeSwMainFsm_radarCycleState_recalibration_e] =
                        chirpSequenceStartTimeOffset - (uint32_t)RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_CHIRP_SEQUENCE_START_DELAY;
                radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[chirpSequenceIndex][rfeSwMainFsm_radarCycleState_initChirpSequence_e] =
                        radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[chirpSequenceIndex][rfeSwMainFsm_radarCycleState_recalibration_e] - (uint32_t)RFE_SW_CALIBRATION_MAX_PROFILE_INDEPENDENT_DURATION_TICKS;
                radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[chirpSequenceIndex][rfeSwMainFsm_radarCycleState_powerOn_e] =
                        radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[chirpSequenceIndex][rfeSwMainFsm_radarCycleState_initChirpSequence_e] -
                        (uint32_t)RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_INIT_CHIRP_SEQUENCE_DURATION;
                radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[chirpSequenceIndex - 1U][rfeSwMainFsm_radarCycleState_cmdExecutionBuffer_e] =
                        radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[chirpSequenceIndex][rfeSwMainFsm_radarCycleState_powerOn_e] -
                        (uint32_t)RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_POWER_ON_DURATION;
                radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[chirpSequenceIndex - 1U][rfeSwMainFsm_radarCycleState_idle_e] =
                        radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[chirpSequenceIndex - 1U][rfeSwMainFsm_radarCycleState_cmdExecutionBuffer_e] -
                        (uint32_t)RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_CMD_EXECUTION_BUFFER_DURATION;
            }
        }
        else //ChirpSequenceStartTimeOffsetIndex0 is not 0UL
        {
            chirpSequenceStartTimeOffset = rfeCfg_radarCycle_getChirpSequenceStartTimeOffset( pRfeConfig_arg, chirpSequenceIndex, rfe___error___pointer);
            radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[chirpSequenceIndex][rfeSwMainFsm_radarCycleState_recalibration_e] =
                    chirpSequenceStartTimeOffset - (uint32_t)RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_CHIRP_SEQUENCE_START_DELAY;
            radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[chirpSequenceIndex][rfeSwMainFsm_radarCycleState_initChirpSequence_e] =
                    radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[chirpSequenceIndex][rfeSwMainFsm_radarCycleState_recalibration_e] - RFE_SW_CALIBRATION_MAX_PROFILE_INDEPENDENT_DURATION_TICKS;
            radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[chirpSequenceIndex][rfeSwMainFsm_radarCycleState_powerOn_e] =
                    radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[chirpSequenceIndex][rfeSwMainFsm_radarCycleState_initChirpSequence_e] -
                    (uint32_t)RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_INIT_CHIRP_SEQUENCE_DURATION;

            if(chirpSequenceIndex == 0U)
            {
                rfeMainFsm_checkStartOffsetDuration(chirpSequenceIndex, rfe___error___pointer);              
            }
            else
            {                    
                radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[chirpSequenceIndex - 1U][rfeSwMainFsm_radarCycleState_cmdExecutionBuffer_e] =
                        radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[chirpSequenceIndex][rfeSwMainFsm_radarCycleState_powerOn_e] -
                        (uint32_t)RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_POWER_ON_DURATION;
                radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[chirpSequenceIndex - 1U][rfeSwMainFsm_radarCycleState_idle_e] =
                        radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[chirpSequenceIndex - 1U][rfeSwMainFsm_radarCycleState_cmdExecutionBuffer_e] -
                        (uint32_t)RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_CMD_EXECUTION_BUFFER_DURATION;
            }
        }

        radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[chirpSequenceIndex][rfeSwMainFsm_radarCycleState_chirpSequence_e] =
                radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[chirpSequenceIndex][rfeSwMainFsm_radarCycleState_recalibration_e] + chirpSequenceDuration;
        radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[chirpSequenceIndex][rfeSwMainFsm_radarCycleState_monitorsAndMetadata_e] =
                radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[chirpSequenceIndex][rfeSwMainFsm_radarCycleState_chirpSequence_e] +
                (uint32_t)RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_MONITORS_AND_METADATA_DURATION;

        if(chirpSequenceIndex == (chirpSequencesPerRadarCycle - 1U))
        {
            radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[chirpSequenceIndex][rfeSwMainFsm_radarCycleState_monitorsAndMetadata_e] =
                                radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[chirpSequenceIndex][rfeSwMainFsm_radarCycleState_chirpSequence_e] +
                                (uint32_t)RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_LAST_MONITORS_AND_METADATA_DURATION;                
            radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[chirpSequenceIndex][rfeSwMainFsm_radarCycleState_bist_e] =
                    radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[chirpSequenceIndex][rfeSwMainFsm_radarCycleState_monitorsAndMetadata_e] +
                    (uint32_t)RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_BIST_DURATION;
            radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[chirpSequenceIndex][rfeSwMainFsm_radarCycleState_idle_e] =
                    radarCycleDuration - (uint32_t)RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_CMD_EXECUTION_BUFFER_DURATION -
                    (uint32_t)RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_CONFIG_UPDATE_DURATION;
            radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[chirpSequenceIndex][rfeSwMainFsm_radarCycleState_cmdExecutionBuffer_e] =
                    radarCycleDuration - (uint32_t)RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_CONFIG_UPDATE_DURATION;
            // Always power off at end of radar cycle
            radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[chirpSequenceIndex][rfeSwMainFsm_radarCycleState_powerOff_e] =
                    radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[chirpSequenceIndex][rfeSwMainFsm_radarCycleState_bist_e] +
                    (uint32_t)RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_POWEROFF_DURATION;
        }
        else
        {
            // Only bist after the last chirp sequence in the radar cycle
            radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[chirpSequenceIndex][rfeSwMainFsm_radarCycleState_bist_e] =
                    radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[chirpSequenceIndex][rfeSwMainFsm_radarCycleState_monitorsAndMetadata_e];
            // Don't schedule power off yet in-between chirp sequence
            radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[chirpSequenceIndex][rfeSwMainFsm_radarCycleState_powerOff_e] =
                    radarCycleTimeSchedule.stateEndTimeTicks_chirpSequenceLoop[chirpSequenceIndex][rfeSwMainFsm_radarCycleState_bist_e];
        }
    }
}
/******************************************************************************
 *                           GLOBAL FUNCTIONS
 *****************************************************************************/
const rfeSwMainFsm_radarCycleTimingSchedule_t* rfeSwMainFsm_calcRadarCycleTimingSchedule( const uint8_t *pRfeConfig_arg, rfe_error_t* rfe___error___pointer)
{
	uint32_t chirpSequenceStartTimeOffsetIndex0;
    uint32_t radarCycleDuration;
    uint8_t  chirpSequenceIndex;

	if(*rfe___error___pointer == rfe_error_none_e)
    {
        radarCycleDuration = rfeCfg_radarCycle_getRadarCycleDuration( pRfeConfig_arg, rfe___error___pointer);
        chirpSequencesPerRadarCycle = rfeCfg_radarCycle_getChirpSequenceCount(pRfeConfig_arg, rfe___error___pointer);
        // Get the Oth Chirp Sequence startTimeOffset
        chirpSequenceStartTimeOffsetIndex0 = rfeCfg_radarCycle_getChirpSequenceStartTimeOffset( pRfeConfig_arg, 0U, rfe___error___pointer);
        // Begin end time is common for both the cases
        radarCycleTimeSchedule.stateEndTimeTicks[(uint32_t)rfeSwMainFsm_radarCycleState_begin_e - RFE_SW_MAIN_FSM_RADAR_CYCLE_CHIRP_SEQUENCE_LOOP_STATE_COUNT] =
                (uint32_t)RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_BEGIN_DURATION;
        // Add the Calculate the StartOffset
        if(chirpSequenceStartTimeOffsetIndex0 == 0UL)
        {
            //In this case the StartTimeOffset state would be 0
            radarCycleTimeSchedule.stateEndTimeTicks[(uint32_t)rfeSwMainFsm_radarCycleState_startOffset_e - RFE_SW_MAIN_FSM_RADAR_CYCLE_CHIRP_SEQUENCE_LOOP_STATE_COUNT] =
                    radarCycleTimeSchedule.stateEndTimeTicks[(uint32_t)rfeSwMainFsm_radarCycleState_begin_e - RFE_SW_MAIN_FSM_RADAR_CYCLE_CHIRP_SEQUENCE_LOOP_STATE_COUNT];
        }

        // Calculate radar cycle state timings for each chirp sequence
        for(chirpSequenceIndex = 0U; chirpSequenceIndex < chirpSequencesPerRadarCycle; chirpSequenceIndex++)
        {
            chirpSequences[chirpSequenceIndex] = (uint8_t)rfeCfg_radarCycle_getChirpSequence(pRfeConfig_arg, chirpSequenceIndex, rfe___error___pointer);                        
            rfeSwMainFsm_calcSequenceTimingSchedule(pRfeConfig_arg, chirpSequenceIndex, chirpSequenceStartTimeOffsetIndex0, radarCycleDuration, rfe___error___pointer);
        }
        rfeSwMainFsm_checkIdleTime(rfe___error___pointer);
        radarCycleTimeSchedule.stateEndTimeTicks[(uint32_t)rfeSwMainFsm_radarCycleState_configUpdate_e - RFE_SW_MAIN_FSM_RADAR_CYCLE_CHIRP_SEQUENCE_LOOP_STATE_COUNT] =
                radarCycleDuration;   
    }

    return &radarCycleTimeSchedule;
}

uint32_t rfeSwMainFsm_calcChirpSequenceDuration(const uint8_t *pRfeConfig_arg, rfe_chirpSequenceIndex_t chirpSequenceConfigIndex, rfe_error_t* rfe___error___pointer)
{
    uint32_t chirpSequenceDuration = (uint32_t)RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_CHIRP_SEQUENCE_START_DELAY + (uint32_t)RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_CHIRP_SEQUENCE_END_DELAY;
    rfe_chirpProfileIndex_t chirpProfileIndex;
    uint8_t chirpSequenceConfigCount = rfeCfg_metadata_getChirpSequenceConfigCount( pRfeConfig_arg, rfe___error___pointer);
    uint8_t chirpProfileCount = rfeCfg_metadata_getChirpProfileCount( pRfeConfig_arg, rfe___error___pointer);
    uint8_t chirpProfileSequenceLength = rfeCfg_chirpSequence_getChirpProfileSequenceLength(pRfeConfig_arg, chirpSequenceConfigIndex, rfe___error___pointer);
    uint16_t chirpCount = rfeCfg_chirpSequence_getChirpCount( pRfeConfig_arg, chirpSequenceConfigIndex, rfe___error___pointer);
    uint16_t sequenceRepetitions;
    uint8_t sequenceRemainder;
    uint32_t chirpIntervalTime;

    if (*rfe___error___pointer == rfe_error_none_e)
    {
        if ((chirpProfileSequenceLength == 0U) || ((uint8_t)chirpSequenceConfigIndex >= chirpSequenceConfigCount))
        {
            *rfe___error___pointer = rfe_error_parameterOutOfRange_e;
        }
    }
    if (*rfe___error___pointer == rfe_error_none_e)
    {
        sequenceRepetitions = chirpCount / (uint16_t)chirpProfileSequenceLength;
        sequenceRemainder = (uint8_t)(chirpCount % (uint16_t)chirpProfileSequenceLength);
        for(uint8_t chirpProfileSequenceIndex = 0U; chirpProfileSequenceIndex < chirpProfileSequenceLength; chirpProfileSequenceIndex++)
        {
            chirpProfileIndex = rfeChirpProfileMapper(rfeCfg_chirpSequence_getChirpProfileSequence(pRfeConfig_arg, chirpSequenceConfigIndex, chirpProfileSequenceIndex, rfe___error___pointer));
            if((uint8_t)chirpProfileIndex >= chirpProfileCount)
            {
                *rfe___error___pointer = rfe_error_parameterOutOfRange_e;
                break;
            }
            else
            {
                chirpIntervalTime = rfeCfg_chirpProfile_getChirpIntervalTimeTicks(pRfeConfig_arg, chirpProfileIndex, rfe___error___pointer);
                chirpSequenceDuration += chirpIntervalTime * (uint32_t)sequenceRepetitions;
                if(chirpProfileSequenceIndex < sequenceRemainder)
                {
                    chirpSequenceDuration += chirpIntervalTime;
                }
            }
        }
    }

    return chirpSequenceDuration;
}
