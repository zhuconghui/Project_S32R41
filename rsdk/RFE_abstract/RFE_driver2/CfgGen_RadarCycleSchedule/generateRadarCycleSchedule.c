/*
    Copyright 2021, 2023 - 2024 NXP
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


#include "rfe_error.h"
#include "rfeSwMainFsm.h"
#include "rfe_blob_access.h"
#include "rfe_cfg_blob.h"

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>


#ifdef NXP_INTERNAL_CALIBRATION_CALCULATION_MODE
#define btoa(x) ((x)?"enabled":"disabled")
#define BYTE_TO_NUM(byte)  \
  (byte & 0x80 ? '7' :' '), \
  (byte & 0x40 ? '6' :' '), \
  (byte & 0x20 ? '5' :' '), \
  (byte & 0x10 ? '4' :' '), \
  (byte & 0x08 ? '3' :' '), \
  (byte & 0x04 ? '2' :' '), \
  (byte & 0x02 ? '1' :' '), \
  (byte & 0x01 ? '0' :' ') 

#endif


/******************************************************************************
 *                              TYPES
 *****************************************************************************/

uint8_t rfeConfig[RFE_CFG_SIZE_TOTAL];


/******************************************************************************
 *                              FUNCTIONS
 *****************************************************************************/

int main( int argc, char *argv[] )
{
	rfe_error_t rfe_error_val = rfe_error_none_e;
    rfe_error_t* rfe___error___pointer = &rfe_error_val;
    FILE *pFile;
    struct stat buffer; 
    const rfeSwMainFsm_radarCycleTimingSchedule_t *pRadarCycleTimeSchedule;
    uint8_t chirpSequencesPerRadarCycle;
    uint32_t startTime;
    uint32_t endTime;
    const int INPUT_FILE_SIZE = 1000;
    char input_file[INPUT_FILE_SIZE];
    uint8_t fileIndex = 1;
	char outputFile[INPUT_FILE_SIZE];
	char aux_name[INPUT_FILE_SIZE];
	
#ifdef NXP_INTERNAL_CALIBRATION_CALCULATION_MODE
    uint8_t chirpSequenceProfileDependentProfileList = 0ul;
#endif 
	if ( argc > 1 )
	{
		while((argc - fileIndex) > 0)
		{
			strncpy(input_file, argv[fileIndex], INPUT_FILE_SIZE);
		
			if( stat (input_file, &buffer) == 0 )
			{
				pFile = fopen( input_file, "rb" );
				
				fread( rfeConfig, 1ul, RFE_CFG_SIZE_TOTAL, pFile );
				fclose( pFile );
				
				snprintf(aux_name, (strlen(input_file) - 3), input_file);
				snprintf(outputFile, INPUT_FILE_SIZE, "%s.csv", aux_name);
				
				pFile = fopen( outputFile, "w" );
				
				pRadarCycleTimeSchedule = rfeSwMainFsm_calcRadarCycleTimingSchedule( rfeConfig, rfe___error___pointer );
				chirpSequencesPerRadarCycle = rfeCfg_radarCycle_getChirpSequenceCount( rfeConfig, rfe___error___pointer );
				
				fprintf(pFile, "Activity               ,Start (us),  End (us),State\n");
				
				if ( *rfe___error___pointer == rfe_error_none_e )
				{    
					startTime = 0ul;
					endTime = pRadarCycleTimeSchedule->stateEndTimeTicks[rfeSwMainFsm_radarCycleState_begin_e - RFE_SW_MAIN_FSM_RADAR_CYCLE_CHIRP_SEQUENCE_LOOP_STATE_COUNT];
					fprintf(pFile, "Radar Cycle Begin      ,%10.3f,%10.3f,rfe_busy_e\n", ( double ) startTime / RFE_TIME_TICKS_PER_US, ( double ) endTime / RFE_TIME_TICKS_PER_US );

					startTime = endTime; 
					endTime = pRadarCycleTimeSchedule->stateEndTimeTicks[rfeSwMainFsm_radarCycleState_startOffset_e - RFE_SW_MAIN_FSM_RADAR_CYCLE_CHIRP_SEQUENCE_LOOP_STATE_COUNT];
					if( startTime != endTime)
					{
						fprintf(pFile, "Start Offset           ,%10.3f,%10.3f,rfe_busy_e\n", ( double ) startTime / RFE_TIME_TICKS_PER_US, ( double ) endTime / RFE_TIME_TICKS_PER_US);
					}
					
					for ( uint8_t chirpSequenceIndex = 0ul; chirpSequenceIndex < chirpSequencesPerRadarCycle; chirpSequenceIndex++ )
					{
						fprintf(pFile, "\n");
						/* startTime = endTime;
						endTime = pRadarCycleTimeSchedule->stateEndTimeTicks_chirpSequenceLoop[chirpSequenceIndex][rfeSwMainFsm_radarCycleState_powerOnPdc_e];
						if ( startTime != endTime )
						{
							fprintf(pFile, "Power On Pdc %d         ,%10.3f,%10.3f,rfe_busy_e\n", chirpSequenceIndex, ( double ) startTime / RFE_TIME_TICKS_PER_US, ( double ) endTime / RFE_TIME_TICKS_PER_US );
						} */
						
						startTime = endTime;
						endTime = pRadarCycleTimeSchedule->stateEndTimeTicks_chirpSequenceLoop[chirpSequenceIndex][rfeSwMainFsm_radarCycleState_powerOn_e];
						if ( startTime != endTime )
						{
							fprintf(pFile, "Power On Analog %d      ,%10.3f,%10.3f,rfe_busy_e\n", chirpSequenceIndex, ( double ) startTime / RFE_TIME_TICKS_PER_US, ( double ) endTime / RFE_TIME_TICKS_PER_US );
						}
						
						startTime = endTime;
						endTime = pRadarCycleTimeSchedule->stateEndTimeTicks_chirpSequenceLoop[chirpSequenceIndex][rfeSwMainFsm_radarCycleState_initChirpSequence_e];
						if ( startTime != endTime )
						{
							fprintf(pFile, "Chirp Sequence Init %d  ,%10.3f,%10.3f,rfe_busy_e\n", chirpSequenceIndex, ( double ) startTime / RFE_TIME_TICKS_PER_US, ( double ) endTime / RFE_TIME_TICKS_PER_US );
						}
						
						startTime = endTime;
						endTime = pRadarCycleTimeSchedule->stateEndTimeTicks_chirpSequenceLoop[chirpSequenceIndex][rfeSwMainFsm_radarCycleState_recalibration_e];
						if ( startTime != endTime )
						{
							fprintf(pFile, "Recalibration %d        ,%10.3f,%10.3f,rfe_busy_e\n", chirpSequenceIndex, ( double ) startTime / RFE_TIME_TICKS_PER_US, ( double ) endTime / RFE_TIME_TICKS_PER_US );
						}
						
						startTime = endTime;
						endTime = startTime + RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_CHIRP_SEQUENCE_START_DELAY;
						if ( startTime != endTime )
						{
							fprintf(pFile, "Chirp Sequence Start %d ,%10.3f,%10.3f,rfe_busy_e\n", chirpSequenceIndex, ( double ) startTime / RFE_TIME_TICKS_PER_US, ( double ) endTime / RFE_TIME_TICKS_PER_US );
						}
						
						startTime = endTime;
						endTime = pRadarCycleTimeSchedule->stateEndTimeTicks_chirpSequenceLoop[chirpSequenceIndex][rfeSwMainFsm_radarCycleState_chirpSequence_e] - RFE_SW_MAIN_FSM_RADAR_CYCLE_STATE_CHIRP_SEQUENCE_END_DELAY;
						if ( startTime != endTime )
						{
							fprintf(pFile, "Chirp Sequence %d       ,%10.3f,%10.3f,rfe_busy_e\n", chirpSequenceIndex, ( double ) startTime / RFE_TIME_TICKS_PER_US, ( double ) endTime / RFE_TIME_TICKS_PER_US );
						}
						
						startTime = endTime;
						endTime = pRadarCycleTimeSchedule->stateEndTimeTicks_chirpSequenceLoop[chirpSequenceIndex][rfeSwMainFsm_radarCycleState_chirpSequence_e];
						if ( startTime != endTime )
						{
							fprintf(pFile, "Chirp Sequence End %d   ,%10.3f,%10.3f,rfe_busy_e\n", chirpSequenceIndex, ( double ) startTime / RFE_TIME_TICKS_PER_US, ( double ) endTime / RFE_TIME_TICKS_PER_US );
						}
						
						startTime = endTime;
						endTime = pRadarCycleTimeSchedule->stateEndTimeTicks_chirpSequenceLoop[chirpSequenceIndex][rfeSwMainFsm_radarCycleState_monitorsAndMetadata_e];
						if ( startTime != endTime )
						{
							fprintf(pFile, "Monitors and Metadata %d,%10.3f,%10.3f,rfe_busy_e\n", chirpSequenceIndex, ( double ) startTime / RFE_TIME_TICKS_PER_US, ( double ) endTime / RFE_TIME_TICKS_PER_US );
						}
						
						startTime = endTime;
						endTime = pRadarCycleTimeSchedule->stateEndTimeTicks_chirpSequenceLoop[chirpSequenceIndex][rfeSwMainFsm_radarCycleState_bist_e];
						if ( startTime != endTime )
						{
							fprintf(pFile, "BIST                   ,%10.3f,%10.3f,rfe_busy_e\n", ( double ) startTime / RFE_TIME_TICKS_PER_US, ( double ) endTime / RFE_TIME_TICKS_PER_US );
						}
						
						startTime = endTime;
						endTime = pRadarCycleTimeSchedule->stateEndTimeTicks_chirpSequenceLoop[chirpSequenceIndex][rfeSwMainFsm_radarCycleState_powerOff_e]; 
						if ( startTime != endTime )
						{
							fprintf(pFile, "Power Off Analog %d     ,%10.3f,%10.3f,rfe_busy_e\n", chirpSequenceIndex, ( double ) startTime / RFE_TIME_TICKS_PER_US, ( double ) endTime / RFE_TIME_TICKS_PER_US );
						}

						/* startTime = endTime;
						endTime = pRadarCycleTimeSchedule->stateEndTimeTicks_chirpSequenceLoop[chirpSequenceIndex][rfeSwMainFsm_radarCycleState_powerOffPdc_e];
						if ( startTime != endTime )
						{
							fprintf(pFile, "Power Off Pdc %d        ,%10.3f,%10.3f,rfe_busy_e\n", chirpSequenceIndex, ( double ) startTime / RFE_TIME_TICKS_PER_US, ( double ) endTime / RFE_TIME_TICKS_PER_US );
						} */

						startTime = endTime;
						endTime = pRadarCycleTimeSchedule->stateEndTimeTicks_chirpSequenceLoop[chirpSequenceIndex][rfeSwMainFsm_radarCycleState_idle_e];
						if ( startTime != endTime )
						{
							fprintf(pFile, "Radar Cycle Idle %d     ,%10.3f,%10.3f,rfe_radarCycleIdle_e\n", chirpSequenceIndex, ( double ) startTime / RFE_TIME_TICKS_PER_US, ( double ) endTime / RFE_TIME_TICKS_PER_US );
						}
						
						startTime = endTime;
						endTime = pRadarCycleTimeSchedule->stateEndTimeTicks_chirpSequenceLoop[chirpSequenceIndex][rfeSwMainFsm_radarCycleState_cmdExecutionBuffer_e];
						if ( startTime != endTime )
						{
							fprintf(pFile, "Command Buffer %d       ,%10.3f,%10.3f,rfe_busy_e\n", chirpSequenceIndex, ( double ) startTime / RFE_TIME_TICKS_PER_US, ( double ) endTime / RFE_TIME_TICKS_PER_US );
						}
					}
					
					startTime = endTime;
					endTime = pRadarCycleTimeSchedule->stateEndTimeTicks[rfeSwMainFsm_radarCycleState_configUpdate_e - RFE_SW_MAIN_FSM_RADAR_CYCLE_CHIRP_SEQUENCE_LOOP_STATE_COUNT];
					fprintf(pFile, "\nConfig Update          ,%10.3f,%10.3f,rfe_busy_e\n", ( double ) startTime / RFE_TIME_TICKS_PER_US, ( double ) endTime / RFE_TIME_TICKS_PER_US );
					
		#ifdef NXP_INTERNAL_CALIBRATION_CALCULATION_MODE
					fprintf(pFile, "\n Calibration Durations, (enabled or disabled and profile index)                 , Duration (us)\n"); 
					for ( uint8_t chirpSequenceIndex = 0ul; chirpSequenceIndex < RFE_CHIRP_SEQUENCES_PER_RADAR_CYCLE_MAX ; chirpSequenceIndex++ )
					{
						chirpSequenceProfileDependentProfileList = (uint8_t)(rfeCfg_radarCycle_getRecalibrateProfileDependent(rfeConfig, chirpSequenceIndex, rfe___error___pointer));
						fprintf(pFile, "Recalibration %d       ,Profile Dependent Calibration %d (%s %c %c %c %c %c %c %c %c )               , %10.3f\n", chirpSequenceIndex, chirpSequenceIndex, btoa( pRadarCycleTimeSchedule->calibrationDurationTicks[chirpSequenceIndex][rfeSwMainFsm_radarCycleCalibrationType_profileDependent_e] ),
							BYTE_TO_NUM(chirpSequenceProfileDependentProfileList), ( double ) pRadarCycleTimeSchedule->calibrationDurationTicks[chirpSequenceIndex][rfeSwMainFsm_radarCycleCalibrationType_profileDependent_e] / RFE_TIME_TICKS_PER_US );
						fprintf(pFile, "                       ,Profile Independent Calibration %d (%s)       , %10.3f\n", chirpSequenceIndex,  btoa( pRadarCycleTimeSchedule->calibrationDurationTicks[chirpSequenceIndex][rfeSwMainFsm_radarCycleCalibrationType_profileIndependent_e] ),
							( double ) pRadarCycleTimeSchedule->calibrationDurationTicks[chirpSequenceIndex][rfeSwMainFsm_radarCycleCalibrationType_profileIndependent_e] / RFE_TIME_TICKS_PER_US );
					}
		#endif /*NXP_INTERNAL_CALIBRATION_CALCULATION_MODE*/

					printf("Radar cycle schedule .csv file successfully generated.\n" );
				}
				else
				{
					printf("Failed to generate radar cycle schedule! RFE Error %u\n", ( uint32_t ) rfe_error_val );
				}
				
				fclose( pFile );
			}
			else
			{
				printf("Failed to generate radar cycle schedule! File \"%s\" does not exist\n", input_file );
			}
			fileIndex++;
		}
	}
	else
	{
		printf("Error: Minimum 1 argument required for Timing Generation." );
	}
}

