#/*
#    Copyright 2021, 2023 - 2024 NXP
#    NXP Confidential. This software is owned or controlled by NXP and may only be 
#    used strictly in accordance with the applicable license terms. By expressly 
#    accepting such terms or by downloading, installing, activating and/or otherwise
#    using the software, you are agreeing that you have read, and that you agree to
#    comply with and are bound by, such license terms.  If you do not agree to be 
#    bound by the applicable license terms, then you may not retain, install, 
#    activate or otherwise use the software.
# */
#
#
#/******************************************************************************
# *   Project              : S32R41_RFE_FW
# *   Platform             : S32R41
# *****************************************************************************/


TOOLCHAIN?=gcc

INCLUDES = \
    -I ../../RFE_driver2/RF_Common/inc \
    -I ../../RFE_driver/src/tef82xx/bc/inc \
    -I ../RF_FW/rfeSwMainFsm/inc \
    -I ../RF_FW/api/inc \
    -I ../RF_FW/rfeSwBist/inc \
    -I ../RF_FW/rfeSwFuSaMngr/inc \
    -I ../RF_FW/rfeSwDriverState/inc \
    -I ../RF_FW/rfeSwDeviceStatus/inc \
    -I ../RF_FW/rfeSwCfgMngr/inc \
    -I ../RF_FW/rfeSwInit/inc \
    -I ../RF_FW/rfeSysTick/inc \
    -I ../RF_API/include/CDD \
    -I ../../../api \
	-I ../RF_FW/rfeDebug/inc \
    -I inc

SOURCES = \
    generateRadarCycleSchedule.c \
    ../RF_Common/src/rfe_blob_access.c \
    ../RF_Common/src/rfe_min_max_blob.c \
    ../RF_Common/src/rfe_crc_computation.c \
    ../RF_FW/rfeSwMainFsm/src/rfeSwMainFsm_radarCycleSchedule.c \
	../RF_FW/rfeSwCfgMngr/src/rfe_sw_cfg_to_tef82xx_map.c \
    ../RF_FW/rfeSwDriverState/src/rfe_sw_driver_state.c \
    ../RF_FW/rfeDebug/src/rfe_debug.c \
    src/rfeSwCalibration_duration.c


PLATFORM = -D S32R41

COMPILE_DEFINES = -DRFE_CFG_NOT_USED -DRADAR_CYCLE_SCHEDULE -DBLOB_GENERATOR -DRFE_DEBUG

#uncomment the define below and recompile to get a detailed profile
CFLAGS = #-DNXP_INTERNAL_CALIBRATION_CALCULATION_MODE

generateRadarCycleSchedule.exe: generateRadarCycleSchedule.c ../RF_FW/rfeDebug/src/rfe_debug.c ../RF_Common/src/rfe_blob_access.c ../RF_FW/rfeSwMainFsm/src/rfeSwMainFsm_radarCycleSchedule.c src/rfeSwCalibration_duration.c
	$(TOOLCHAIN) $(PLATFORM) $(COMPILE_DEFINES) -o generateRadarCycleSchedule.exe $(CFLAGS) $(SOURCES) $(INCLUDES)

.PHONY: clean
clean:
	rm -rf generateRadarCycleSchedule.exe
