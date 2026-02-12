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
@file bc_ism.h

@version

@brief Barracuda API header file

This is the header file for Barracuda APIs. All exported API can be found in
this file.

<TotalNumAPI>30
*/

#ifndef BC_ISM_H
#define BC_ISM_H


#include <stdint.h>

#include "bc_types.h"
#include "bc_err.h"

#if defined(__cplusplus)
extern "C"
{
#endif

/**
@brief This API reports the master ISM errors status.
 
RSNum:2547560
 
# Description
 
An API will get the Master error status from ISM.
An API will have option to get the Masked or Raw error.
A consolidated list of functional safety errors.
For Masked errors the status are captured after the masking.
For raw errors the status are captured before the masking.
 
## Note 
1. These errors are consolidated list of errors, some errors are redundant. 
 
@param[in] RawErr True: Errors reported from Raw error register , False: Error reported from masked error register
@param[out] pMasterErr structure of all the master errors, True : error occurred, False :  no error
@param[out] pModuleErr  Master error register dump
 
@return BC_ERRCODE
*/
 
BC_ERRCODE BC_ISM_GetMasterErrStatus(BOOL RawErr, SYS_MasterErrors_t *pMasterErr, uint32_t *pModuleErr);


/**
@brief This API reports all the supply error status of all the modules.
 
RSNum:2483584, 510589, 510604, 510592, 510580, 510583
 
# Description
 
An API will get all the supply error status from ISM.
An API will have option to get the Masked or Raw error.
A consolidated list of all the supply related functional safety errors.
For Masked errors the status are captured after the masking.
For raw errors the status are captured before the masking.
 
## Note 
1. These errors are consolidated list of  all the supply errors, some errors are redundant.
 
@param[in] RawErr  True: Errors reported from Raw error register , False: Error reported from masked error register
@param[out] pSupplyErr structure of all the supply errors, True : error occurred, False :  no error 
@param[out] pModuleErr  Supply error register dump
 
@return BC_ERRCODE
*/
 
BC_ERRCODE BC_ISM_GetSupplyErrStatus(BOOL RawErr, SYS_SupplyErrors_t *pSupplyErr, uint32_t *pModuleErr);


/**
@brief This API reports status of all the Tx module errors.
 
RSNum:2483583, 510498, 510589, 510604, 510329, 510401, 510592, 510580, 510583, 510430
 
# Description
 
An API will get all the Tx error status from ISM.
An API will have option to get the Masked or Raw error.
 
A consolidated list of all the Tx(1-3) functional safety errors.
For Masked errors the status are captured after the masking.
For raw errors the status are captured before the masking.
 
@param[in] CmdReg option to select masked, raw and FIT errors status
@param[out] pTx1Err structure of all the Tx-1 errors, True : error occurred, False :  no error
@param[out] pTx2Err structure of all the Tx-2 errors, True : error occurred, False :  no error
@param[out] pTx3Err structure of all the Tx-3 errors, True : error occurred, False :  no error
@param[out] pModuleErr  Tx(1-3) errors register dump
@return BC_ERRCODE
*/
 
BC_ERRCODE BC_ISM_GetTxErrStatus(ISM_GetErrCmd_e CmdReg, SYS_TXErrors_t *pTx1Err, SYS_TXErrors_t *pTx2Err, SYS_TXErrors_t *pTx3Err, uint32_t *pModuleErr);


/**
@brief This API reports status of all the Rx module errors.
 
RSNum:2483583, 510498, 510589, 510604, 510329, 510401, 510592, 510580, 510583, 510430
 
# Description
 
An API will get all the Rx error status from ISM.
An API will have option to get the Masked or Raw error.
A consolidated list of all the Rx(1-4) functional safety errors.
For Masked errors the status are captured after the masking.
For raw errors the status are captured before the masking.
 
@param[in] CmdReg option to select masked, raw and FIT errors status
@param[out] pRx1Err structure of all the Rx-1 errors, True : error occurred, False :  no error
@param[out] pRx2Err structure of all the Rx-2 errors, True : error occurred, False :  no error
@param[out] pRx3Err structure of all the Rx-3 errors, True : error occurred, False :  no error
@param[out] pRx4Err structure of all the Rx-4 errors, True : error occurred, False :  no error
@param[out] pModuleErr  Rx(1-4) errors register dump
 
@return BC_ERRCODE
*/
BC_ERRCODE BC_ISM_GetRxErrStatus(ISM_GetErrCmd_e CmdReg, SYS_RXErrors_t *pRx1Err, SYS_RXErrors_t *pRx2Err, SYS_RXErrors_t *pRx3Err, SYS_RXErrors_t *pRx4Err, uint32_t *pModuleErr);


/**
@brief This API reports status of all the Chirp module errors.
 
RSNum:2483583, 510498, 510589, 510604, 510329, 510401, 510592, 510580, 510583, 510430
 
# Description
 
An API will get all the Chirp error status from ISM.
An API will have option to get the Masked or Raw error.
A consolidated list of all the Chirp module functional safety errors.
For Masked errors the status are captured after the masking.
For raw errors the status are captured before the masking.
 
@param[in] CmdReg option to select masked, raw and FIT errors status
@param[out] pChirpErr structure of all the Chirp errors, True : error occurred, False :  no error
@param[out] pModuleErr  CHIRP errors register dump
 
@return BC_ERRCODE
*/
 
BC_ERRCODE BC_ISM_GetChirpErrStatus(ISM_GetErrCmd_e CmdReg, SYS_CAFCErrors_t *pChirpErr, uint32_t *pModuleErr);


/**
@brief This API reports status of all error of Master Clock, LO interface, ISM and OTP modules.
 
RSNum:2483583, 510498, 510589, 510604, 510329, 510401, 510592, 510580, 510583, 510430
 
# Description
 
An API will get all error status of Master Clock, LO interface, ISM and OTP modules from ISM.
An API will have option to get the Masked or Raw error.
 
A consolidated list of all the functional safety errors of the modules Master Clock, LO interface, ISM and OTP from ISM.
For Masked errors the status are captured after the masking.
For raw errors the status are captured before the masking.
 
@param[in] CmdReg option to select masked, raw and FIT errors status
@param[out] pOTPRegCRCErr True: register CRC error of OTP IP, False: no error
@param[out] pISMRegCRCErr True: register CRC error of  ISM IP, False: no error
@param[out] pMClkErr structure for Master clock errors, True : error occurred, False :  no error
@param[out] pLOIErr structure for LO interface errors, True : error occurred, False :  no error
@param[out] pCCErr structure for central control Master clock errors, True : error occurred, False :  no error
@param[out] pModuleErr all error of MClk, ISM, OTP, LOI and CC error register dump
 
@return BC_ERRCODE
*/
 
BC_ERRCODE BC_ISM_GetMClkLOISMOTPErrStatus(ISM_GetErrCmd_e CmdReg, BOOL *pOTPRegCRCErr, BOOL *pISMRegCRCErr, SYS_MCLKErrors_t *pMClkErr, SYS_LOIErrors_t *pLOIErr, SYS_CCErrors_t *pCCErr, uint32_t *pModuleErr);


/**
@brief This API reports status of all the errors of  SSB, Serialiser, GBIAS and ATB modules modules.
 
RSNum:2483583, 510498, 510589, 510604, 510329, 510401, 510592, 510580, 510583, 510430
 
# Description
 
An API will get all error status of SSB, Serialiser, GBIAS and ATB modules from ISM.
An API will have option to get the Masked or Raw error.
A consolidated list of all the functional safety errors of the modules SSB, Serialiser, GBIAS and ATB from ISM.
For Masked errors the status are captured after the masking.
For raw errors the status are captured before the masking.
 
@param[in] CmdReg option to select masked, raw and FIT errors status
@param[out]  pATBRegCRCErr  TRUE:  ATB CRC error  FALSE: no error 
@param[out]  pSerErr  structure forMIPI/ LVDS errors, True : error occurred, False :  no error
@param[out]  pSSBErr  structure for SSB errors, True : error occurred, False :  no error
@param[out]  pGBErr  structure for Global Bias errors, True : error occurred, False :  no error
@param[out]  pGLDOErr structure for Global LDO errors, True : error occurred, False :  no error
@param[out] pModuleErr SSB, MIPI, LVDS, GBIAS and ATB modules errors
 
@return BC_ERRCODE
*/
 
BC_ERRCODE BC_ISM_GetSSBSerGBGLDOATBErr(ISM_GetErrCmd_e CmdReg, BOOL *pATBRegCRCErr, SYS_SerialiserErrors_t *pSerErr, SYS_SSBErrors_t *pSSBErr, SYS_GBIASErrors_t *pGBErr, SYS_GLDOErrors_t *pGLDOErr, uint32_t *pModuleErr);


/**
@brief This API reports status of all the ADC module errors.
 
RSNum:2483583, 2483561, 510498, 510589, 510604, 510329, 510401, 510592, 510580, 510583, 510430, 771671
 
# Description
 
An API will get all the ADC error status from ISM.
An API will have option to get the Masked or Raw error.
A consolidated list of all the ADC functional safety errors.
For Masked errors the status are captured after the masking.
For raw errors the status are captured before the masking.
 
@param[in] CmdReg option to select masked, raw and FIT errors status
@param[out] pADC12Err structure of all the errors of ADC-12 , True : error occurred, False :  no error
@param[out] pADC34Err structure of all the  errors of ADC-34 , True : error occurred, False :  no error
@param[out] pModuleErr  ADC errors register dump
 
@return BC_ERRCODE
*/
 
BC_ERRCODE BC_ISM_GetADCErrStatus(ISM_GetErrCmd_e CmdReg, SYS_ADCErrors_t *pADC12Err, SYS_ADCErrors_t *pADC34Err, uint32_t *pModuleErr);


/**
@brief This API reports all the register CRC error status of all the modules.
 
RSNum:2483562, 510383
 
# Description
 
An API will get all the Register CRC error status from ISM.
An API will have option to get the Masked or Raw error.
A consolidated list of all the register CRC functional safety errors.
For Masked errors the status are captured after the masking.
For raw errors the status are captured before the masking.
## Note
1. These errors are consolidated list of  all the register CRC errors, some errors are redundant.
 
@param[in] RawErr True: Errors reported from Raw error register , False: Error reported from masked error register
@param[out] pRegCRCErr structure for all IPs register CRC error, True : error occurred, False :  no error
@param[out] pModuleErr  register dump of register CRC errors of all IPs.
 
@return BC_ERRCODE
*/
 
BC_ERRCODE BC_ISM_GetRegCRCErrStatus(BOOL RawErr, SYS_RegCRCErrors_t *pRegCRCErr, uint32_t *pModuleErr);


/**
@brief This API reports all the RF power down errors modules.
 
RSNum:2547560
 
# Description
An API will get status of error causing the RF power down of module from ISM.
An API will have option to get the Masked or Raw error.
A consolidated list of all modules RF power down functional safety errors.
For Masked errors the status are captured after the masking.
For raw errors the status are captured before the masking.
 
## Note
These errors are consolidated list of  all the reliability errors, some errors are redundant.
 
@param[in] RawErr  True: Errors reported from Raw error register , False: Error reported from masked error register
@param[out] pRFPowDwnErr structure for all  IPs RF power down supply error, True : error occurred, False :  no error
@param[out] pModuleErr  register dump of RF power down errors of all IPs.
 
@return BC_ERRCODE
*/
 
BC_ERRCODE BC_ISM_GetRFPowDwnErrStatus(BOOL RawErr, SYS_RFPowerDownErrors_t *pRFPowDwnErr, uint32_t *pModuleErr);


/**
@brief This API reports all ISM warnings( status errors).
 
RSNum:2547560
 
# Description
 
An API will get status of all the warnings from ISM.
An API will have option to get the Masked or Raw warnings.
A consolidated list of all the functional safety warnings.
For Masked warnings the status are captured after the masking.
For raw warnings the status are captured before the masking.
 
## Note
All the error reported will not asset the error_n pin.
 
@param[in] RawWarning  True: warnings reported from Raw warnings register , False: warnings reported from masked warnings register
@param[out] pISMWarning structure of all ISM warnings. True : warning error occurred, False :  no  warning error 
@param[out] pModuleErr  register dump of warnings from all IPs.
 
@return BC_ERRCODE
*/
 
BC_ERRCODE BC_ISM_GetISMWarningStatus(BOOL RawWarning, SYS_StatusErrors_t *pISMWarning, uint32_t *pModuleErr);


/**
@brief This API reports register provide the status of the ISM module .
 
RSNum:2483585, 510430
 
# Description
 
An API will get the status of the ISM module.
This is a initial indication of the error status of the system.
This will indicate that the error type in the system
startup, Reliability, RTM etc..
 
@param[out] pISMErr structure for the ISM error status.
@param[out] pModuleErr  register dump of ISM error status register
 
@return BC_ERRCODE
*/
 
BC_ERRCODE BC_ISM_GetISMErrStatus(SYS_ISMErrorStatus_t *pISMErr, uint32_t *pModuleErr);


/**
@brief This API Mask or Unmask all functional safety errors for all modules.
 
RSNum:2483080, 510395, 510526, 510589, 510613, 510418, 510592, 510534, 510521, 510386, 690604, 673724, 510456
 
# Description
 
An API will Mask or Unmask all functional safety errors for all modules Tx, Rx, ADC, Chirp, MClk, LO, CC, ISM, OTP, SSB, GBIAS, Serialiser GLDO and ATB.
 
@param[in] UnMask True: unmask all, False: mask all
 
@return BC_ERRCODE
 
*/
BC_ERRCODE BC_ISM_MaskUnmaskAllErr(BOOL UnMask);


/**
@brief This API configs all functional safety errors for all Tx module.
 
RSNum:2483080, 510395, 510526, 510589, 510613, 510418, 510592, 510534, 510521, 510386, 690604, 673724, 510456
 
# Description
 
An API will config all functional safety error registers for the all Tx(1-3) module.
Following operations can performed via this API.
- Unmask errors- Mask errors- Monitoring setup of errors, monitored through out or safety monitoring period only- Clear errors (Clears the independent masked flags)- Set the errors(Set the independent masked flags) 
@param[in] CmdReg operation to be performed on errors
@param[in] pTx1Err structure of all the Tx-1 errors, True: selected for command,  False:  not selected
@param[in] pTx2Err structure of all the Tx-2 errors, True: selected for command,  False:  not selected
@param[in] pTx3Err structure of all the Tx-3 errors, True: selected for command,  False:  not selected
 
@return BC_ERRCODE
 
*/
 
BC_ERRCODE BC_ISM_MaskRTMSetClrTxErr(ISM_ErrCmd_e CmdReg, SYS_TXErrors_t *pTx1Err, SYS_TXErrors_t *pTx2Err, SYS_TXErrors_t *pTx3Err);


/**
@brief This API configs all functional safety errors for all Rx module.
 
RSNum:2483080, 510395, 510526, 510589, 510613, 510418, 510592, 510534, 510521, 510386, 690604, 673724, 510456
 
# Description
 
An API will config all functional safety error registers for the all Rx(1-4) module.
Following operations can performed via this API.
- Unmask errors-  Mask errors- Monitoring setup of errors, monitored through out or safety monitoring period only- Clear errors (Clears the independent masked flags)- Set the errors(Set the independent masked flags) 
@param[in] CmdReg operation to be performed on errors
@param[in] pRx1Err structure of all the Rx-1 errors, True: selected for command,  False:  not selected
@param[in] pRx2Err structure of all the Rx-2 errors, True: selected for command,  False:  not selected
@param[in] pRx3Err structure of all the Rx-3 errors, True: selected for command,  False:  not selected
@param[in] pRx4Err structure of all the Rx-4 errors, True: selected for command,  False:  not selected
 
@return BC_ERRCODE
 
*/
 
BC_ERRCODE BC_ISM_MaskRTMSetClrRxErr(ISM_ErrCmd_e CmdReg, SYS_RXErrors_t *pRx1Err, SYS_RXErrors_t *pRx2Err, SYS_RXErrors_t *pRx3Err, SYS_RXErrors_t *pRx4Err);


/**
@brief This API configs all functional safety errors for Chirp module.
 
RSNum:2483080, 510395, 510526, 510589, 510613, 510418, 510592, 510534, 510521, 510386, 690604, 673724, 510456
 
# Description
 
An API will config all functional safety error registers for the all Chirp module.
Following operations can performed via this API.
- Unmask errors-  Mask errors- Monitoring setup of errors, monitored through out or safety monitoring period only- Clear errors (Clears the independent masked flags)-  Set the errors(Set the independent masked flags) 
@param[in] CmdReg operation to be performed on errors
@param[in] pChirpErr structure of all the Chirp errors, True: selected for command,  False:  not selected
 
@return BC_ERRCODE
*/
 
BC_ERRCODE BC_ISM_MaskRTMSetClrChirpErr(ISM_ErrCmd_e CmdReg, SYS_CAFCErrors_t *pChirpErr);


/**
@brief This API configs all functional safety errors for MClk, LO, CC, ISM and OTP.
 
RSNum:2483080, 510395, 510526, 510589, 510613, 510418, 510592, 510534, 510521, 510386, 690604, 673724, 510456
 
# Description
 
An API will config all functional safety error registers for the MClk, LO, CC, ISM and OTP modules.
 
Following operations can performed via this API.
- Unmask errors- Mask errors- Monitoring setup of errors, monitored through out or safety monitoring period only- Clear errors (Clears the independent masked flags)- Set the errors(Set the independent masked flags) 
## Note
1. MCOIErr stands for MCLK, CC, OTP and ISM (the abbreviation is due to limitation on API name length)
 
@param[in] CmdReg operation to be performed on errors
@param[in] OTPRegCRCErr True: selected for command,  False:  not selected
@param[in] ISMRegCRCErr True: selected for command,  False:  not selected
@param[in] pMClkErr structure for Master clock errors, True: selected for command,  False:  not selected
@param[in] pLOIErr structure for LO interface errors, True: selected for command,  False:  not selected
@param[in] pCCErr structure for central control Master clock errors, True: selected for command,  False:  not selected
 
@return BC_ERRCODE
 
*/
BC_ERRCODE BC_ISM_MaskRTMSetClrMCOIErr(ISM_ErrCmd_e CmdReg, BOOL OTPRegCRCErr, BOOL ISMRegCRCErr, SYS_MCLKErrors_t *pMClkErr, SYS_LOIErrors_t *pLOIErr, SYS_CCErrors_t *pCCErr);


/**
@brief This API configs functional safety errors for SSB, GBIAS, Serialiser GLDO and ATB.
 
RSNum:2483080, 510395, 510526, 510589, 510613, 510418, 510592, 510534, 510521, 510386, 690604, 673724, 510456
 
# Description
 
An API will config all functional safety error registers for the SSB, GBias, MIPI, LVDS, Global LDO  and ATB modules.
 
Following operations can performed via this API.
- Unmask errors- Mask errors- Monitoring setup of errors, monitored through out or safety monitoring period only- Clear errors (Clears the independent masked flags)- Set the errors(Set the independent masked flags) 
## Note
1. SGA means SSB, GBIAS, GLDO and ATB (this is due to API name length limitation)
 
@param[in] CmdReg operation to be performed on errors
@param[in]  ATBRegCRCErr  True: selected for command,  False:  not selected
@param[in]  pSerErr  structure for MIPI/ LVDS errors, True: selected for command, False:  not selected
@param[in]  pSSBErr  structure for SSB errors, True: selected for command, False:  not selected
@param[in]  pGBErr  structure for Global Bias errors, True: selected for command, False:  not selected
@param[in]  pGLDOErr structure for Global LDO errors, True: selected for command, False:  not selected
 
@return BC_ERRCODE
 
*/
 
BC_ERRCODE BC_ISM_MaskRTMSetClrSSGAErr(ISM_ErrCmd_e CmdReg, BOOL ATBRegCRCErr, SYS_SerialiserErrors_t *pSerErr, SYS_SSBErrors_t *pSSBErr, SYS_GBIASErrors_t *pGBErr, SYS_GLDOErrors_t *pGLDOErr);


/**
@brief This API configs all functional safety errors for ADC module.
 
RSNum:2483080, 510395, 510526, 510589, 510613, 510418, 510592, 510534, 510521, 510386, 690604, 673724, 510456
 
# Description
 
An API will config all functional safety error registers for the all ADC module.
Following operations can performed via this API.
- Unmask errors- Mask errors- Monitoring setup of errors, monitored through out or safety monitoring period only- Clear errors (Clears the independent masked flags)- Set the errors(Set the independent masked flags) 
 
@param[in] CmdReg operation to be performed on errors
@param[in] pADC12Err structure of all the errors of ADC-12,  True: selected for command,  False:  not selected
@param[in] pADC34Err structure of all the  errors of ADC-34, True: selected for command,  False:  not selected
 
@return BC_ERRCODE
 
*/
BC_ERRCODE BC_ISM_MaskRTMSetClrADCErr(ISM_ErrCmd_e CmdReg, SYS_ADCErrors_t *pADC12Err, SYS_ADCErrors_t *pADC34Err);


/**
@brief This API resets all ISM error and error counter.
 
RSNum:1447758, 510549
 
# Description
 
An API will reset all ISM errors and error counters.
An API will have option to reset via SPI or GPIO pin.
 
 
@param[in] UseGPIOErrorReset choose the reset via GPIO or reset register
@param[in] ResetStatusWDT reset the WDT status
@param[in] ResetFTTIWDT reset the FTTI WDT
@param[in] ResetErrCounters reset the error counters
 
@return BC_ERRCODE
*/
BC_ERRCODE BC_ISM_ResetISMErr(BOOL UseGPIOErrorReset, BOOL ResetStatusWDT, BOOL ResetFTTIWDT, BOOL ResetErrCounters);


/**
@brief This API set the status of the startup sequence
 
RSNum:2483824, 510424
 
# Description
AN API will set the Startup Sequence in following order.
1. spi_access_check_done_ok
2. main_ldo_config_ok
3. gobal_bias_config_ok
4. local_ldo_config_ok
5. IC_calibration_ok
6. local_bias_config_ok
7. pll4g_config_ok
8. Sensor_configuration_done
 
This API internally check that correct sequence is followed or not.
If user try to set the wrong sequence API will report error.
 
@param[in] SequenceID for which sequence status to be set
 
@return BC_ERRCODE
 
*/
 
BC_ERRCODE BC_ISM_SetStartupStatus(ISM_StartupSeq_e SequenceID);


/**
@brief This API set the RTM safety and Power down threshold
 
RSNum:2574704
 
# Description
 
An API will  set the Real Time Monitor(RTM) safety error register. 
API will have option to reset error count for Chirp Sequence.  
An API will set the threshold for the RTM safety error count.
An API will set the threshold for the Power down error count.
 
 
@param[in] EnRTMErrCountReset chose to reset the RTM error count for each Chirp.
@param[in] pRTMSafetyErrThreshold number of safety error required to assert error_n pin .
@param[in] pPowrDwnErrThreshold number of error required to assert error_n pin and a RF power down is initiation.
 
@return BC_ERRCODE
 
*/
BC_ERRCODE BC_ISM_SetErrCntThreshold(BOOL EnRTMErrCountReset, RTMSafetyErrCnttThreshold_t *pRTMSafetyErrThreshold, RFPowrDwnErrCntThreshold_t *pPowrDwnErrThreshold);


/**
@brief This API perform the hardware Fault Inject Test(FIT).
 
RSNum:1447758, 510549
 
# Description
 
An API will perform the ISM integrity check through Fault Injection Test(FIT).
This API perform hardware FIT.
 
## Note
1. Please note that the FIT covers only the interface connection with hardware and may not cover the complete sensor functionality
 
@return BC_ERRCODE
 
*/
 
BC_ERRCODE BC_ISM_FIT(void);


/**
@brief This API to perform interface toggle test on Barracuda pin.
 
RSNum:1447536, 1447537, 1447542, 1447607, 510407, 690607, 1615681, 510435, 510461
 
# Description
 
An API will perform the interface toggle test for following pins.
1. All Tx i and q,
2. error Reset
3. error_n
4. ready_int
5. Chirp start
6. Do it for all interfaces
 
This API internally check the input and output mode of the external pin and return the test result.
 
## Note
1. To perform the interface for all the Pins in one call, user need to use call the API with pin ID e_SYS_ALL_BC_PINS. ALL pins direction is tested with default functional pin direction.
Default Functional pin direction is set as below:
e_SYS_ERRORRESET is set as Input
e_SYS_ERRORN is set as Output
e_SYS_MCUINT_CHIRPSTART_OUT_PAD is set as Output
e_SYS_CHIRPSTART_IN_PAD is set as Input
e_SYS_TX1_I_PS is set as Input
e_SYS_TX2_I_PS is set as Input
e_SYS_TX3_I_PS is set as Input
e_SYS_TX1_Q_PS is set as Input
e_SYS_TX2_Q_PS is set as Input
e_SYS_TX3_Q_PS is set as Input
2. Host MCU pin direction should be in a right direction before calling different I/O direction test.
3. Pins other than the user selected pin direction are set to functional mode pin direction
4. In case of Chirp Start Pad, interface toggle test can results in the Chirp trigger, if the Chirp_enable bit is set for the device and to prevent this have to disable the chirp_enable before calling this API.
 
@param[in] PinId Pin ID on which interface toggle test need to be perform.
@param[in] Direction Direction used to set the input mode and output mode of external pin for interface toggle test, True:Input Mode, False:Output Mode.
 
@return BC_ERRCODE

*/
BC_ERRCODE BC_ISM_InterfaceToggleTest(SYS_ExtPinID_e PinId, BOOL Direction);


/**
@brief This API to config the FTTI WDT and Status WDT. 
 
RSNum:2547562
 
# Description
 
An API Shall enable/disable the FTTI WDT.
An API will select WDT timer modes continuous(every chirp sequence) or Moonshot.
An API will have option to set the  watchdog timer interval period   value.
 
Setting the FTTI will insure that, if the FIT test is not triggered with in the FTTI watchdog timer interval, a interrupt and error_n pin (safety error) will be asserted.
Status WDT can be used to generate a heart beat interrupt to MCU at regular interval. 
 
@param[in]  pConfigFTTIWDT FTTI WDT Configurations
@param[in]  pConfigStatusWDT status WDT Configurations    
 
@return BC_ERRCODE
 
*/
 
BC_ERRCODE BC_ISM_ConfigFTTIWDT(ISM_ConfigWDT_t *pConfigFTTIWDT, ISM_ConfigWDT_t *pConfigStatusWDT);


/**
@brief This API reports hardware  Calibration status. 
 
RSNum:2483563, 781146
 
# Description
 
This API Shall reports the calibration status BC_ERR_ISM_CAL_BUSY, BC_ERR_ISM_CAL_ERR, BC_ERR_ISM_SUCCESS for the IP CHIRP, LOI, RX4/3/2/1, TX3/2/1 and TX3/2/1 safety calibration.
 
This API call to be done after starting hardware calibration for a particular IP and after waiting for the sufficient time for hardware calibration to complete.
 
## Note
1. This API is only supported in ES2 samples.
2. If the API report e_ISM_CAL_ERROR for TX1, TX2 or TX3 calibration, it can be treated as warning and ignored. 
 
@param[out] pCalibrationStatus reports  calibration status for hardware calibration for all the IP .
@param[out] pModuleStatus pointer to get the raw calibration status of all module from GLOBAL_CAL_STATUS register.
 
@return BC_ERRCODE
 
*/
 
BC_ERRCODE BC_ISM_GetCalibrationStatus(SYS_CalibrationStatus_t *pCalibrationStatus, uint32_t *pModuleStatus);


/**
@brief This API sets power down mask upon Level Max error. 
 
RSNum:2547561
 
# Description
 
This API Shall provide interface to set and clear the mask for power down action due to level max error in the IP
 
IP's available for power down in case of  level max error are LOI, Chirp, Tx3/2/1, Rx4/3/2/1
 
## Note
1. This API is only supported in ES2 samples.
 
@param[in] pRFPowerDownMask If power down mask is set no power down of the IP due to level max error, if power down mask is not set power down of the IP is performed in case of level max error.
 
@return BC_ERRCODE
 
*/
 
BC_ERRCODE BC_ISM_SetRFPowDwnMask(SYS_RFPowerDownMask_t *pRFPowerDownMask);


/**
@brief This API reads error or warning status 
 
RSNum:2547560
 
# Description
 
An API will get the mask first error and warning.
An API will return the module id of the first error module.
An API will return Sequence number at which the error occurred.
An API will return Error occurred instance.
An API will return Chirp number at which the error occurred.
Based on the command API returns the detail of the first error or warning.  
 
## Note
1. This API is only supported in ES2 samples.
 
@param[in]  CmdReg input command choose between error or Warning 
@param[out] pFirstErrWarn Struct returning error or warning status details.
 
@return BC_ERRCODE
 
*/
 
BC_ERRCODE BC_ISM_Get1stErrWarnStatus(ISM_GetFirstErrCmd_e CmdReg, ISM_FirstErrWarning_t *pFirstErrWarn);


/**
@brief This API configures the First error and warning clearing mechanism counter. 
 
RSNum:1456361, 1456380
 
# Description
 
An API will configures the clearing mechanism counter for First Error and warning.
Option available are: 
1. No reset.  
2. Reset of counter at start of the Chirp
3. Reset of counter based on ErrorReset Pin.
4. Reset of counter upon write to the SPI register FIRST_MASKED_ERROR_WARNING_CTRL bit first_masked_error_clr/first_masked_warning_clr  
 
## Note
1. This API is only supported in ES2 samples.
 
@param[in]  ErrorClr Reset counter configuration for Error clearing mechanism
@param[in] WarningClr Reset counter configuration for Warning clearing mechanism
 
@return BC_ERRCODE
 
*/
 
BC_ERRCODE BC_ISM_CfgFirstErrWar(ISM_CHIRPSEQ_COUNTER_e ErrorClr, ISM_CHIRPSEQ_COUNTER_e WarningClr);


/**
@brief This API configures the error monitoring period of LOI BBD. 
 
RSNum:2483080
 
# Description
 
This API will configure the error monitoring period of LOI BBD. Error monitoring can be configured
to always or only during safety monitoring period
 
@param[in]  MonitorAlways Configure monitoring period for LOI BBD. TRUE: Error monitored throughout FALSE:Error monitored only during safety monitoring period.
 
@return BC_ERRCODE
 
*/
 
BC_ERRCODE BC_ISM_ConfigLOIBBDMonitor(BOOL MonitorAlways);



#if defined(__cplusplus)
}
#endif
#endif
