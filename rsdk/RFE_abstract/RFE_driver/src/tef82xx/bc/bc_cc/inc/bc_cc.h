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
@file bc_cc.h

@version

@brief Barracuda API header file

This is the header file for Barracuda APIs. All exported API can be found in
this file.

<TotalNumAPI>16
*/

#ifndef BC_CC_H
#define BC_CC_H


#include <stdint.h>

#include "bc_types.h"
#include "bc_err.h"

#if defined(__cplusplus)
extern "C"
{
#endif

/**
@brief 

RSNum:2547538 

# Description
 
This API is normally the first API that should be called during application.
An API will let the user choose "Application Configuration" (explained below), and store this configuration statically in this API. This information will be used in SPI read write APIs to prevent writing to PON-disabled IPs by user, this will also help e.g. FIT test to not check PON-disabled IPs. 
 
# Application Configuration
 
"Application Configuration" means the set of all IPs that will be used(powered on, out of reset and out of clock reset) through out the whole Radar application. E.g. when a Radar use case uses TX1, TX2 and RX1,2,3,4. Then TX1, TX2,RX1,2,3,4 (of course also MCLK, CAFC, TE, etc.) is this use case's "Application Configuration".
For some IP, e.g. SSB, it might not be used in init phase, but maybe used later. In this case, it must still be put into "Application Configuration" from the very beginning.

@param[in] pAppConfig Application configuration as described above
 
@return BC_ERRCODE
*/
 
BC_ERRCODE BC_CC_SetAppConfiguration(SYS_IPList_t *pAppConfig);


/**
@brief API for setting the Application Configuration for Master Slave device. 

RSNum:2547538 

# Description
This API is normally the first API that should be called during application.
An API will let the user choose "Application Configuration" (explained below), and store this configuration statically in this API. This information will be used in SPI read write APIs to prevent writing to PON-disabled IPs by user, this will also help e.g. FIT test to not check PON-disabled IPs. 
# Application Configuration
"Application Configuration" means the set of all IPs that will be used(powered on, out of reset and out of clock reset) throughout the whole Radar application. E.g. when a Radar use case uses TX1, TX2 and RX1,2,3,4. Then TX1, TX2,RX1,2,3,4 (of course also MCLK, CAFC, TE, etc.) is this use case's "Application Configuration".
For some IP, e.g. SSB, it might not be used in init phase, but maybe used later. In this case, it must still be put into "Application Configuration" from the very beginning.
 
## Note
1. This API is only required for Cascade use case, for standalone use case use BC_CC_SetAppConfiguration.
2. To get the App configuration application can still use the BC_CC_GetAppConfiguration, this will return the current selected device(Master/Slave1-3) app configuration  

@param[in] pAppConfig Application configuration as described above
@param[in] TargetDevice The Barracuda device
 
@return BC_ERRCODE
*/
BC_ERRCODE BC_CC_SetAppConfigMS(SYS_IPList_t *pAppConfig, PLF_SPITarget_e TargetDevice);


/**
@brief This API sets a Barracuda device type for the API internal usage.
 
RSNum:1445685
 
# Description
 
An API will set a Barracuda device as for internal usage of API,specially for App configuration.
This API is needed on for cascade use case. This is used to set the device for the API. 
 
@see  PLF_SYS_SetDevice  
 
E.g. in a cascading system, if a user sets e_PLF_MASTER as target, then all APP configuration is effective only to the master barracuda. Same principle applies to slave barracuda devices.
 
@param[in] TargetDevice The Barracuda device
 
@return BC_ERRCODE
*/
 
BC_ERRCODE BC_CC_SetMSDevice(PLF_SPITarget_e TargetDevice);


/**
@brief 

RSNum:2547538, 1447758, 510549 

# Description
 
An API will return the "Application Configuration" that set by the user. If nothing has been set by the user using BC_SYS_SetAppConfiguration, then this function will return an error.
This function will also be able to return the application configuration in PON mask format (CC, IP_LEVEL_PON_ENABLE), so that this mask can be directly used in PON, Reset, Clk Reset and Functional Reset.
 
@see HAL_ESx_CC_SYS_SetAppConfiguration

@param[out] pAppConfig Application Configuration in struct format, use NULL if this output is not needed.
@param[out] pPONMask Application configuration in PON(uint32_t) mask format, use NULL if this output is not needed.
 
@return BC_ERRCODE
*/
 
BC_ERRCODE BC_CC_GetAppConfiguration(SYS_IPList_t *pAppConfig, uint32_t *pPONMask);


/**
@brief This API set the serialiser interface type.
 
RSNum:1446594
 
# Description
 
An API will have option to select the LVDS or CSI2(MIPI) as serialiser interface.
In Barracuda only one interface is supported LVDS or CSI2,
User can check the supported interface via API BC_CC_GetInterface.
 
@see BC_CC_GetInterface
 
## Note
1.) This API need to be called before the CSI2 or LVDS initialization.
2.) Load OTP should be called before calling this API.
 
@see BC_OTP_LoadOTP
 
@param[in] SerialiserMode selected interface MIPI or LVDS.
 
@return BC_ERRCODE
*/
 
BC_ERRCODE BC_CC_SetInterface(CC_InterfaceType_e SerialiserMode);


/**
@brief This API gets the serialiser interface type.
 
RSNum:1446594
 
# Description
 
An API will have option to get the supported serialiser interface LVDS or CSI2(MIPI).
Related register: RDL_SITE_STATUS
 
## Note
1.) In Barracuda only one interface is supported LVDS or MIPI.
2.) Load OTP should be called before calling this API.
 
@see BC_OTP_LoadOTP
 
@param[out] pSerialiserMode selected interface MIPI or LVDS.
 
@return BC_ERRCODE
 
*/
 
BC_ERRCODE BC_CC_GetInterface(CC_InterfaceType_e *pSerialiserMode);


/**
@brief This API controls power/clock/reset functionality of IPs using central control.
 
RSNum:1456425, 1701374
 
# Description
 
An API will have option to enable/disable clock of selected modules/IPs.
An API will have option to enable/disable static power to selected modules/IPs.
An API will have option to set/release functional reset to selected modules/IPs.
An API will have option to set/release reset to selected modules/IPs.
 
## IPs supported.
-  ISM
-  ATB
-  Global LDO-  SSBMOD-  All Tx-  All Rx-  LO interface-  GBAIS-  ADC-  Chirp-  Serialiser(MIPI/LVDS). 
## Note
1 ISM power can not be controlled.
2 OTP can never be reset through SW or through reset pin. Only power on reset is possible.
 
@param[in] Reg choose command register.
@param[in] pModList list of IPs, True: Enable the command, False: disable the command
 
@return BC_ERRCODE
*/
 
BC_ERRCODE BC_CC_SetPonClkRst(CC_PonClkRst_e Reg, CC_ModList_t *pModList);


/**
@brief This API to set the dynamic power down for ADC, Serialiser, individual Tx/Rx and LO interface .
 
RSNum:1445699, 1445688
 
# Description
An API will set the dynamic power down for ADC, Serialiser, individual Tx/Rx IPs and LO interface.
This API gives option to set the dynamic power for per chirp sequence, pre chirp and always power on(no power down).
This API can be use for system power saving option.
## IPs supported.
- All Tx
- All Rx
- LO interface
- ADC
- Chirp

## Note
1. Power down delay value has to be minimum equal to the chirp reset time duration. If PR Safety check is configured, then the time taken for it need to be added to this delay. 
2. To optimize the API for time use value 0 for  PowDownDelayPerChirp and PowDownDelayPerSequence, for value 0 is special input for these variables and their value will not be updated inside API.
3. Structure member SetADCBGClib can be used to set a trigger for the ADC background check, for the dynamic power-down mode.
4. Structure member SetADCBGClib is enabled only if the delay between two sequences is a minimum of 2 ms.
5. In case the chirp module is wake up from dynamic power mode, to fast bias Chirp PPL either Chirp AAF calibration (BC_CAFC_CalibAAFCInjDAC) should be called or SPI based fast biasing (BC_CAFC_FastBiasChirpPll) should be called.
6. In the case of Chirp triggered Chirp Pll is fast biased internally by the hardware state machine.   
 
 
@see BC_CAFC_CalibAAFCInjDAC
@see BC_CAFC_FastBiasChirpPll

@param[in] pPowDnIPList list of IPs with power down choices.
@param[in] PowDownDelayPerChirp common delay for modules which are configured for per chirp-based power down, if 0 value is used, this setting will be kept untouched inside the API. 
@param[in] PowDownDelayPerSequence common delay for modules which are configured for per sequence-based power down, if 0 value is used, this setting will be kept untouched inside the API.
 
@return BC_ERRCODE
 
*/
 
BC_ERRCODE BC_CC_SetDynPowModeDown(CC_DynPowDnIPList_t *pPowDnIPList, float32_t PowDownDelayPerChirp, float32_t PowDownDelayPerSequence);


/**
@brief This API configure the local LDO for SSBMOD, Serialiser and ADC.
 
RSNum:1456425, 1456420
 
# Description
 
An API will Enable the local LDO for MIPI, LVDS, ADC and SSBMOD.
An API have option to set the voltage of local LDO.
 
## Note
1. Local LDO voltage out value equal to 0, represent disabling the LDO. 
2. With local LDO voltage out value greater than 0x1F, will only enable the LDO without updating the voltage value.
3. VoltOutLVDS is basically the overall serialiser IP LDO voltage, this is also needed for both the serialiser LVDS and MIPI. VoltOutLVDS is enough for LVDS, for MIPI additional VoltOutMIPI is also needed.   
 
@param[in] VoltOutSSBMOD local LDO output voltage of SSBMOD. To disable LDO use 0.
@param[in] VoltOutLVDS local LDO output voltage of serialiser IP(LVDS). To disable LDO use 0.
@param[in] VoltOutMIPI local LDO output voltage of MIPI. To disable LDO use 0.
@param[in] VoltOutADC local LDO output voltage of ACD. To disable LDO use 0.
 
@return BC_ERRCODE
*/
 
BC_ERRCODE BC_CC_EnLDOControl(uint8_t VoltOutSSBMOD, uint8_t VoltOutLVDS, uint8_t VoltOutMIPI, uint8_t VoltOutADC);


/**
@brief This API configure the external PINS/PADS of Barracuda.
 
RSNum:1456439
 
# Description
 
An API will configure the External PINs/PADs from Central Control.
An API will have option to set pin as input or output.
An API will have option to set speed of the pin.
 
## Following external PINs supported by this API
1. All Tx i and q,
2. error Reset
3. error_n
4. ready_int
5. Chirp start
 
 
@param[in] SetOutPort choose port type, True: output mode False: input mode.
@param[in] Speed choose the speed of PIN.
@param[in] PadName PIN which need to be configured.
 
 
@return BC_ERRCODE
 
*/
 
BC_ERRCODE BC_CC_ConfigPad(BOOL SetOutPort, CC_PINSpeed_e Speed, SYS_ExtPinID_e PadName);


/**
@brief This API to configure the MCU(READY_INT) interrupt.
 
RSNum:1456437
 
# Description
 
An API will config the MCU interrupt(previously ready_Int).
An API will have option to select interrupt polarity.
An API will have option to select trigger interrupt Modes (edge , level).
An API will set the interrupt period. Based on the 40Mhz clock one interrupt period is equal to 25ns.
 
@see  HAL_ESx_CC_EnDisClrInt
 
@param[in] Polarity  0: Active low interrupt, 1: Active High interrupt.
@param[in] TriggerMode 0: Level triggered interrupt, 1: Edge triggered interrupt.
@param[in] IntPeriod interrupt period in (IntPeriod*25ns)
 
 
@return BC_ERRCODE
 
*/
 
BC_ERRCODE BC_CC_ConfigMCUInt(BOOL Polarity, BOOL TriggerMode, uint8_t IntPeriod);


/**
@brief This API enable or disable interrupt and clear the generate the interrupt events.
 
RSNum:1456435
 
# Description
 
An API will enable and clear the interrupt events.
Clear interrupt command will directly write to Interrupt Masked register to clear the interrupt.
 
## Interrupt event supported.
- Warning Status- CRC error- RF power down- Real Time safety Monitor- WDT timer- End of Data Transfer- End of Data Acquisition- Chirp Start Out. 
## Note
1. If an interrupt event is not enabled, it will not be available in the interrupt masked status register.
2. Clear interrupt command will clear the interrupt masked status.
 
@see  BC_CC_ConfigMCUInt
 
@param[in] CommandReg enable, disable or clear commands for interrupt event.
@param[in]  pIntEvents interrupt events to be generated.
 
 
@return BC_ERRCODE
 
*/
BC_ERRCODE BC_CC_EnDisClrInt(CC_CmdEnClrInt_e CommandReg, CC_IntEvent_t *pIntEvents);


/**
@brief This API gets the interrupt status.
 
RSNum:1456435
 
# Description
 
An API will get the status of interrupt events.
This API can give the Raw or Masked interrupt status.
 
## Interrupt event supported.
- Warning Status
- CRC error
- RF power down
- Real Time safety Monitor
- WDT timer
- End of Data Transfer
- End of Data Acquisition
- Chirp Start Out.
 
## Note
User should use Raw interrupt status only for debugging purpose.
 
 
@param[in] UseRawInt enable, disable or clear commands for interrupt event.
@param[out] pIntStatus interrupt events to be generated.
 
 
@return BC_ERRCODE
 
*/
BC_ERRCODE BC_CC_GetIntStatus(BOOL UseRawInt, CC_IntEvent_t *pIntStatus);


/**
@brief This API configures signal to be routed through MCUINT_CHIRPSTART_OUT_PAD

RSNum:1456437

# Description

An API will have option select MCU Interrupt out or Chirp Event routed through MCUINT_CHIRPSTART_OUT_PAD.

@see  BC_SYS_SetCSOut

@param[in] CsOutEn  0: MCU Interrupt is routed, 1: Chirp Event is routed.

@return BC_ERRCODE

*/
BC_ERRCODE BC_CC_SwitchMcuIntCSOut(BOOL CsOutEn);


/**
@brief This API get the chip mask version using ModuleID register in CC.

RSNum:2547539

# Description

MaskVersion = 1 for ES1,2 for ES2, 3 for ES3

@param[out] pMaskVersion The Chip Mask version

@return BC_ERRCODE

*/
BC_ERRCODE BC_CC_GetMaskVersion(uint8_t *pMaskVersion);


/**
@brief This API triggers ADC background calibration (manual)
 
RSNum:1456426
 
# Description
An API will trigger ADC background calibration.
 
## Note
1. This API is only supported for ES2 samples.
2. ADC need to be out of power saving mode before trigging the manual ADC calibration .

@see BC_ADC_ConfigBackgroundCal
 
@return BC_ERRCODE
*/
BC_ERRCODE BC_CC_TriggerADCBGCalib(void);



#if defined(__cplusplus)
}
#endif
#endif
