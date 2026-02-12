/*
 * Copyright 2016,2019-2022 NXP
 * NXP Confidential. This software is owned or controlled by NXP and may only
 * be used strictly in accordance with the applicable license terms. By
 * expressly accepting such terms or by downloading, installing, activating
 * and/or otherwise using the software, you are agreeing that you have read,
 * and that you agree to comply with and are bound by, such license terms. If
 * you do not agree to be bound by the applicable license terms, then you may
 * not retain, install, activate or otherwise use the software.
 */

/**
@file bc_sysinit.h

@version

@brief Barracuda API header file

This is the header file for Barracuda APIs. All exported API can be found in
this file.

<TotalNumAPI>15
*/

#ifndef BC_SYSINIT_H
#define BC_SYSINIT_H


#include <stdint.h>

#include "bc_types.h"
#include "bc_err.h"

#if defined(__cplusplus)
extern "C"
{
#endif

/**
@brief This API releases HRESET.

RSNum:1456412

# Description
An API will wait for GLDO and 40MHz clock signal to stabilize for 't1' ms and release the HRESET.
HRESET pin set to High and ERROR_RESET pin set to low in this API.

## Note
1. This is BC_SYS_Init support function. This function can't be used with BC_SYS_Init function

@return BC_ERRCODE
*/

BC_ERRCODE BC_SYS_Init_ReleaseHRESET(void);


/**
@brief  API for SPI read/write access check.

RSNum:2483824, 1456416
510424

# Description
An API will write to a scratch register in CC module with a known value and read the same register back. Then it will compare the read-value with the known write value.
After successful SPI access check, API should set the SpiAccessCheckDoneOk bitfield of  MCU_STARTUP_STATUS_CONTROL sequence register.

## Note
1. This is BC_SYS_Init support function. This function can't be used with BC_SYS_Init function, Since this API is writing to the MCU_STARTUP_STATUS_CONTROL sequence register.

@return BC_ERRCODE
*/

BC_ERRCODE BC_SYS_Init_SPIAccessCheck(void);


/**
@brief  This API loads OTP data.

RSNum:1456417

# Description
An API will read the OTP (64 32-bit registers) and store the content in the host memory.
API will calculate the CRC on the read data and compare it with the CRC that is stored in the OTP.

First API for user to call is SetAppConfiguration, then after OTP loading, use GetAppConfig to crosscheck if user desired PON is possible with OTP bits (only when OTP is there), if not return error.


## Note
1. This is BC_SYS_Init support function. This function can't be used with BC_SYS_Init function

@return BC_ERRCODE
*/

BC_ERRCODE BC_SYS_Init_ReadOTPCheckCRC(void);


/**
@brief  This API configures global LDO.

RSNum:1445699

# Description
An API will configure 1V1 and 1V8 GLDOs to low noise reference.
This function will first enable the clock and release the reset for GLDO module. After configuring for low noise reference, it will enable the PON and release the functional reset for the same module, and wait for 't2' us for LDOs to stabilize.
This function will mark the successful operation in (MCU_startup_status_control) ISM module.
# Steps
1- Enable clock to GLDO
2- Release reset to GLDO
3- Set low noise reference for 1v1 and 1v8
4- PON enable GLDO
5- Release functional reset
6- Wait for stabilization
7- Mark it in start-up

## Note
1. This is BC_SYS_Init support function. This function can't be used with BC_SYS_Init function, Since this API is writing to the MCU_STARTUP_STATUS_CONTROL sequence register.

@return BC_ERRCODE
*/

BC_ERRCODE BC_SYS_Init_ConfigGLDO(void);


/**
@brief This API configures global bias.

RSNum:1445699

# Description
An API will configure the global bias values based on OTP entries and enable the GBIAS module.
# Steps
1- Enable clock to GBIAS
2- Release reset to GBIAS
3- Load OTP values
4- PON enable GBIAS
5- Release functional reset
6- Wait for stabilization
7- Mark it in start-up

## Note
1. This is BC_SYS_Init support function. This function can't be used with BC_SYS_Init function, Since this API is writing to the MCU_STARTUP_STATUS_CONTROL sequence register.

@return BC_ERRCODE
*/
BC_ERRCODE BC_SYS_Init_ConfigGBIAS(void);


/**
@brief This API enables and releases reset for desired modules.

RSNum:1456424

# Description
An API will enable clock and release reset for desired modules via CC registers. Please note that the release reset and clock enabling for ADC and serialiser are not done in this API because the local LDO is not enabled yet for these modules at this stage. Instead, the release reset and clock enabling for ADC and serialiser will be done in BC_SYS_Init_EnLocalLDO.

## Note
1. This is BC_SYS_Init support function. This function can't be used with BC_SYS_Init function.

@return BC_ERRCODE
*/

BC_ERRCODE BC_SYS_Init_EnClkRelRstIPs(void);


/**
@brief This API distributes OTP data.

RSNum:1456423

# Description
An API will distribute the OTP data that is captured in the MCU memory to corresponding register bitfields.
A reference table will be available that details all OTP entries and the corresponding module, register and bitfield addresses. Please note that any SSB, ADC, LVDS/MIPI related OTP data will not be distributed here. These OTP data (if there are any) will be distributed in BC_SYS_Init_EnLocalLDO.

## Note
1. This is BC_SYS_Init support function. This function can't be used with BC_SYS_Init function.

@return BC_ERRCODE
*/
BC_ERRCODE BC_SYS_Init_DistributeOTPData(void);


/**
@brief This API enable local LDOs for LVDS, CSI2 and ADC.

RSNum:1445699, 1456420

# Description
An API will enable local LDOs that are located in CC module (LVDS, CSI2, ADC).
SSBMOD LDO will not be enabled at this stage to avoid unnecessary power dissipation. After enabling the local LDO. The main reset is released and the clock is enabled for ADC and serialiser. OTP data related to ADC and serialiser are also distributed in this API.

## Note
1. This is BC_SYS_Init support function. This function can't be used with BC_SYS_Init function, Since this API is writing to the MCU_STARTUP_STATUS_CONTROL sequence register.

@return BC_ERRCODE
*/
BC_ERRCODE BC_SYS_Init_EnLocalLDO(void);


/**
@brief This API initialize and calibrate the Master Clock.

RSNum:1448222, 1445699

# Description

An API will configure and power-up MCLK and wait for PLL(480MHz) bias to stabilize for 550 us.
This function will trigger the initial MCLK calibration by using AAFC(Auto Amplitude Frequency Calibration).
This function check the successful calibration, enable the calibrated clock to CC(Central Control ) and enable the clock buffers towards other modules.
This function will finally check the correctness of clock frequency via one of the data interface (LVDS or MIPI) modules.

## Note
1. This is BC_SYS_Init support function. This function can't be used with BC_SYS_Init function, Since this API is writing to the MCU_STARTUP_STATUS_CONTROL sequence register.


@return BC_ERRCODE
*/

BC_ERRCODE BC_SYS_Init_ConfigMCLK(void);


/**
@brief This API configures CAFC.

RSNum:1445699

# Description
An API will enable local LDO and local biases for CAFC module, configure necessary registers and power-up the CAFC. Then this function will wait for PLL bias to stabilize for 't4' us and enable VCO.

## Note
1. This is BC_SYS_Init support function. This function can't be used with BC_SYS_Init function.

@return BC_ERRCODE
*/

BC_ERRCODE BC_SYS_Init_ConfigCAFC(void);


/**
@brief This API power on all desired modules.

RSNum:1456425

# Description
An API will enable PON for desired modules via CC register.

## Note
1. This is BC_SYS_Init support function. This function can't be used with BC_SYS_Init function.

@return BC_ERRCODE
*/

BC_ERRCODE BC_SYS_Init_PowerOnModules(void);


/**
@brief This API configures ADC.

RSNum:1445699

# Description
An API will enable (locally) PON for ADC, which triggers automatic calibration, wait for 't5' us and confirm the successful calibration.

## Note
1. This is BC_SYS_Init support function. This function can't be used with BC_SYS_Init function.

@return BC_ERRCODE
*/

BC_ERRCODE BC_SYS_Init_ConfigADC(void);


/**
@brief This API configures safety sensors.

RSNum:1456117,
1456361,
1456365,
1456380,
510395,
510526,
510589,
510613,
510418,
510592,
510534,
510521,
510386,
690604,
673724,
673725,
510456,
510498,
510604,
510401,
510580,
510583

# Description
An API will configure and enable all safety monitors and apply all necessary masks.

## Note
1. This is BC_SYS_Init support function. This function can't be used with BC_SYS_Init function, Since this API is writing to the MCU_STARTUP_STATUS_CONTROL sequence register.

@return BC_ERRCODE
*/

BC_ERRCODE BC_SYS_Init_ConfigSafetySensors(void);


/**
@brief  This API initialize data interface.

RSNum:1446594

# Description
An API will initialize the data interface.

## Note
1. This is BC_SYS_Init support function. This function can't be used with BC_SYS_Init function.

@return BC_ERRCODE
*/
BC_ERRCODE BC_SYS_Init_InitDataInterface(void);


/**
@brief  This API checks SNS integrity.

RSNum:1616530,
1616526,
1447610

# Description
An API will check the integrity of Supply Noise Sensors of 1V1 and 1V8 LDOs by error injection and recovery.
This function will use configurable SNS thresholds to inject error and will avoid changing the LDO output amplitude levels

## Note
1. This is BC_SYS_Init support function. This function can't be used with BC_SYS_Init function.

@return BC_ERRCODE
*/

BC_ERRCODE BC_SYS_Init_SNSIntegrityCheck(void);



#if defined(__cplusplus)
}
#endif
#endif
