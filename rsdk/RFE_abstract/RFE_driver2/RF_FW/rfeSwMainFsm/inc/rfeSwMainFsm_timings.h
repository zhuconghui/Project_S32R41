/*
    Copyright 2021-2022 NXP
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

#ifndef RFE_SW_MAIN_FSM_TIMINGS_H
#define RFE_SW_MAIN_FSM_TIMINGS_H


/******************************************************************************
 *                              INCLUDES
 *****************************************************************************/

#include "rfe_types.h"


/******************************************************************************
 *                              TYPES
 *****************************************************************************/

/**
 * These macros define MainFsm state durations in sys ticks of 25ns tick duration
 */
#ifdef RFE_DEBUG

#define RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_BEGIN_DURATION                                ( 5UL * RFE_TIME_TICKS_PER_US )
#define RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_START_OFFSET_DURATION_MIN                     ( 0UL * RFE_TIME_TICKS_PER_US)
#define RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_POWER_ON_DURATION                             ( 1UL * RFE_TIME_TICKS_PER_US )

#define RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_FIRST_INIT_CHIRP_SEQUENCE_DURATION            ( 17100UL )
#define RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_INIT_CHIRP_SEQUENCE_DURATION                  ( 57000UL )

#define RFE_SW_FIRST_CALIBRATION_MAX_PROFILE_INDEPENDENT_DURATION_TICKS                 ( 260000UL )
#define RFE_SW_CALIBRATION_MAX_PROFILE_INDEPENDENT_DURATION_TICKS                       ( 165000UL )

#define RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_CHIRP_SEQUENCE_START_DELAY                    ( 0UL )
#define RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_CHIRP_SEQUENCE_END_DELAY                      ( 0UL )

#define RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_MONITORS_AND_METADATA_DURATION                ( 23000UL )
#define RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_LAST_MONITORS_AND_METADATA_DURATION           ( 56000UL )

#define RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_BIST_DURATION                                 ( 341500UL )

#define RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_POWEROFF_DURATION                             ( 1UL * RFE_TIME_TICKS_PER_US )
#define RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_CMD_EXECUTION_BUFFER_DURATION                 ( 20UL * RFE_TIME_TICKS_PER_US )
#define RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_CONFIG_UPDATE_DURATION                        ( 500UL * RFE_TIME_TICKS_PER_US )

#define RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_IDLE_DURATION_MIN                             ( 0UL * RFE_TIME_TICKS_PER_US )
#define RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_IDLE_DURATION_MIN_FOR_CMD                     ( 50UL * RFE_TIME_TICKS_PER_US )

#else

#define RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_BEGIN_DURATION                                ( 5UL * RFE_TIME_TICKS_PER_US )
#define RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_START_OFFSET_DURATION_MIN                     ( 0UL * RFE_TIME_TICKS_PER_US)
#define RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_POWER_ON_DURATION                             ( 1UL * RFE_TIME_TICKS_PER_US )

#define RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_FIRST_INIT_CHIRP_SEQUENCE_DURATION            ( 17100UL )
#define RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_INIT_CHIRP_SEQUENCE_DURATION                  ( 57000UL )

#define RFE_SW_FIRST_CALIBRATION_MAX_PROFILE_INDEPENDENT_DURATION_TICKS                 ( 260000UL )
#define RFE_SW_CALIBRATION_MAX_PROFILE_INDEPENDENT_DURATION_TICKS                       ( 165000UL )

#define RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_CHIRP_SEQUENCE_START_DELAY                    ( 0UL )
#define RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_CHIRP_SEQUENCE_END_DELAY                      ( 0UL )

#define RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_MONITORS_AND_METADATA_DURATION                ( 23000UL )
#define RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_LAST_MONITORS_AND_METADATA_DURATION           ( 56000UL )

#define RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_BIST_DURATION                                 ( 341500UL )

#define RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_POWEROFF_DURATION                             ( 1UL * RFE_TIME_TICKS_PER_US )
#define RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_CMD_EXECUTION_BUFFER_DURATION                 ( 20UL * RFE_TIME_TICKS_PER_US )
#define RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_CONFIG_UPDATE_DURATION                        ( 500UL * RFE_TIME_TICKS_PER_US )

#define RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_IDLE_DURATION_MIN                             ( 0UL * RFE_TIME_TICKS_PER_US )
#define RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_IDLE_DURATION_MIN_FOR_CMD                     ( 50UL * RFE_TIME_TICKS_PER_US )
#endif


/******************************************************************************
 *                              FUNCTIONS
 *****************************************************************************/



#endif // !RFE_SW_MAIN_FSM_TIMINGS_H

