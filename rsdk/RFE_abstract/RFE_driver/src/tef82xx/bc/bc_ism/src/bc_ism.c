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
@file bc_ism.c

@version

@brief Barracuda API code file

This is the code file for Barracuda APIs. All exported API code can be found in
this file.

*/


#include <stdint.h>

#include "bc_types.h"
#include "bc_err.h"

#include "bc_ism.h"

#ifdef TEF82XX_CFG_ES2 
#include "hal_es2_ism.h"
#endif

#if defined(__cplusplus)
extern "C"
{
#endif

BC_ERRCODE BC_ISM_GetMasterErrStatus(BOOL RawErr, SYS_MasterErrors_t *pMasterErr, uint32_t *pModuleErr)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_ISM_GetMasterErrStatus(RawErr, pMasterErr, pModuleErr);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_ISM_GetSupplyErrStatus(BOOL RawErr, SYS_SupplyErrors_t *pSupplyErr, uint32_t *pModuleErr)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_ISM_GetSupplyErrStatus(RawErr, pSupplyErr, pModuleErr);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_ISM_GetTxErrStatus(ISM_GetErrCmd_e CmdReg, SYS_TXErrors_t *pTx1Err, SYS_TXErrors_t *pTx2Err, SYS_TXErrors_t *pTx3Err, uint32_t *pModuleErr)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_ISM_GetTxErrStatus(CmdReg, pTx1Err, pTx2Err, pTx3Err, pModuleErr);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_ISM_GetRxErrStatus(ISM_GetErrCmd_e CmdReg, SYS_RXErrors_t *pRx1Err, SYS_RXErrors_t *pRx2Err, SYS_RXErrors_t *pRx3Err, SYS_RXErrors_t *pRx4Err, uint32_t *pModuleErr)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_ISM_GetRxErrStatus(CmdReg, pRx1Err, pRx2Err, pRx3Err, pRx4Err, pModuleErr);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_ISM_GetChirpErrStatus(ISM_GetErrCmd_e CmdReg, SYS_CAFCErrors_t *pChirpErr, uint32_t *pModuleErr)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_ISM_GetChirpErrStatus(CmdReg, pChirpErr, pModuleErr);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_ISM_GetMClkLOISMOTPErrStatus(ISM_GetErrCmd_e CmdReg, BOOL *pOTPRegCRCErr, BOOL *pISMRegCRCErr, SYS_MCLKErrors_t *pMClkErr, SYS_LOIErrors_t *pLOIErr, SYS_CCErrors_t *pCCErr, uint32_t *pModuleErr)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_ISM_GetMClkLOISMOTPErrStatus(CmdReg, pOTPRegCRCErr, pISMRegCRCErr, pMClkErr, pLOIErr, pCCErr, pModuleErr);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_ISM_GetSSBSerGBGLDOATBErr(ISM_GetErrCmd_e CmdReg, BOOL *pATBRegCRCErr, SYS_SerialiserErrors_t *pSerErr, SYS_SSBErrors_t *pSSBErr, SYS_GBIASErrors_t *pGBErr, SYS_GLDOErrors_t *pGLDOErr, uint32_t *pModuleErr)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_ISM_GetSSBSerGBGLDOATBErr(CmdReg, pATBRegCRCErr, pSerErr, pSSBErr, pGBErr, pGLDOErr, pModuleErr);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_ISM_GetADCErrStatus(ISM_GetErrCmd_e CmdReg, SYS_ADCErrors_t *pADC12Err, SYS_ADCErrors_t *pADC34Err, uint32_t *pModuleErr)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_ISM_GetADCErrStatus(CmdReg, pADC12Err, pADC34Err, pModuleErr);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_ISM_GetRegCRCErrStatus(BOOL RawErr, SYS_RegCRCErrors_t *pRegCRCErr, uint32_t *pModuleErr)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_ISM_GetRegCRCErrStatus(RawErr, pRegCRCErr, pModuleErr);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_ISM_GetRFPowDwnErrStatus(BOOL RawErr, SYS_RFPowerDownErrors_t *pRFPowDwnErr, uint32_t *pModuleErr)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_ISM_GetRFPowDwnErrStatus(RawErr, pRFPowDwnErr, pModuleErr);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_ISM_GetISMWarningStatus(BOOL RawWarning, SYS_StatusErrors_t *pISMWarning, uint32_t *pModuleErr)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_ISM_GetISMWarningStatus(RawWarning, pISMWarning, pModuleErr);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_ISM_GetISMErrStatus(SYS_ISMErrorStatus_t *pISMErr, uint32_t *pModuleErr)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_ISM_GetISMErrStatus(pISMErr, pModuleErr);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_ISM_MaskUnmaskAllErr(BOOL UnMask)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_ISM_MaskUnmaskAllErr(UnMask);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_ISM_MaskRTMSetClrTxErr(ISM_ErrCmd_e CmdReg, SYS_TXErrors_t *pTx1Err, SYS_TXErrors_t *pTx2Err, SYS_TXErrors_t *pTx3Err)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_ISM_MaskRTMSetClrTxErr(CmdReg, pTx1Err, pTx2Err, pTx3Err);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_ISM_MaskRTMSetClrRxErr(ISM_ErrCmd_e CmdReg, SYS_RXErrors_t *pRx1Err, SYS_RXErrors_t *pRx2Err, SYS_RXErrors_t *pRx3Err, SYS_RXErrors_t *pRx4Err)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_ISM_MaskRTMSetClrRxErr(CmdReg, pRx1Err, pRx2Err, pRx3Err, pRx4Err);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_ISM_MaskRTMSetClrChirpErr(ISM_ErrCmd_e CmdReg, SYS_CAFCErrors_t *pChirpErr)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_ISM_MaskRTMSetClrChirpErr(CmdReg, pChirpErr);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_ISM_MaskRTMSetClrMCOIErr(ISM_ErrCmd_e CmdReg, BOOL OTPRegCRCErr, BOOL ISMRegCRCErr, SYS_MCLKErrors_t *pMClkErr, SYS_LOIErrors_t *pLOIErr, SYS_CCErrors_t *pCCErr)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_ISM_MaskRTMSetClrMCOIErr(CmdReg, OTPRegCRCErr, ISMRegCRCErr, pMClkErr, pLOIErr, pCCErr);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_ISM_MaskRTMSetClrSSGAErr(ISM_ErrCmd_e CmdReg, BOOL ATBRegCRCErr, SYS_SerialiserErrors_t *pSerErr, SYS_SSBErrors_t *pSSBErr, SYS_GBIASErrors_t *pGBErr, SYS_GLDOErrors_t *pGLDOErr)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_ISM_MaskRTMSetClrSSGAErr(CmdReg, ATBRegCRCErr, pSerErr, pSSBErr, pGBErr, pGLDOErr);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_ISM_MaskRTMSetClrADCErr(ISM_ErrCmd_e CmdReg, SYS_ADCErrors_t *pADC12Err, SYS_ADCErrors_t *pADC34Err)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_ISM_MaskRTMSetClrADCErr(CmdReg, pADC12Err, pADC34Err);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_ISM_ResetISMErr(BOOL UseGPIOErrorReset, BOOL ResetStatusWDT, BOOL ResetFTTIWDT, BOOL ResetErrCounters)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_ISM_ResetISMErr(UseGPIOErrorReset, ResetStatusWDT, ResetFTTIWDT, ResetErrCounters);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_ISM_SetStartupStatus(ISM_StartupSeq_e SequenceID)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_ISM_SetStartupStatus(SequenceID);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_ISM_SetErrCntThreshold(BOOL EnRTMErrCountReset, RTMSafetyErrCnttThreshold_t *pRTMSafetyErrThreshold, RFPowrDwnErrCntThreshold_t *pPowrDwnErrThreshold)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_ISM_SetErrCntThreshold(EnRTMErrCountReset, pRTMSafetyErrThreshold, pPowrDwnErrThreshold);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_ISM_FIT(void)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_ISM_FIT();
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_ISM_InterfaceToggleTest(SYS_ExtPinID_e PinId, BOOL Direction)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_ISM_InterfaceToggleTest(PinId, Direction);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_ISM_ConfigFTTIWDT(ISM_ConfigWDT_t *pConfigFTTIWDT, ISM_ConfigWDT_t *pConfigStatusWDT)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_ISM_ConfigFTTIWDT(pConfigFTTIWDT, pConfigStatusWDT);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_ISM_GetCalibrationStatus(SYS_CalibrationStatus_t *pCalibrationStatus, uint32_t *pModuleStatus)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_ISM_GetCalibrationStatus(pCalibrationStatus, pModuleStatus);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_ISM_SetRFPowDwnMask(SYS_RFPowerDownMask_t *pRFPowerDownMask)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_ISM_SetRFPowDwnMask(pRFPowerDownMask);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_ISM_Get1stErrWarnStatus(ISM_GetFirstErrCmd_e CmdReg, ISM_FirstErrWarning_t *pFirstErrWarn)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_ISM_Get1stErrWarnStatus(CmdReg, pFirstErrWarn);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_ISM_CfgFirstErrWar(ISM_CHIRPSEQ_COUNTER_e ErrorClr, ISM_CHIRPSEQ_COUNTER_e WarningClr)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_ISM_CfgFirstErrWar(ErrorClr, WarningClr);
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}


BC_ERRCODE BC_ISM_ConfigLOIBBDMonitor(BOOL MonitorAlways)
{
    BC_ERRCODE ErrCode;

    #ifdef TEF82XX_CFG_ES2
        ErrCode = HAL_ES2_ISM_ConfigLOIBBDMonitor( MonitorAlways );
    #else
        ErrCode = BC_ERR_FUNCNOTEXIST;
    #endif

    return ErrCode;
}



#if defined(__cplusplus)
}
#endif
