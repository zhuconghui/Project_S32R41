/*
 * Copyright 2020-2022 NXP
 * NXP Confidential. This software is owned or controlled by NXP and may only
 * be used strictly in accordance with the applicable license terms. By
 * expressly accepting such terms or by downloading, installing, activating
 * and/or otherwise using the software, you are agreeing that you have read,
 * and that you agree to comply with and are bound by, such license terms. If
 * you do not agree to be bound by the applicable license terms, then you may
 * not retain, install, activate or otherwise use the software.
 */

/**
@file helper_es2sys.h

@version

@brief Barracuda HAL (Hardware Abstractiion Layer) ES2 helper file for SYS block

This is helper file for SYS block.
*/

#ifndef HELPER_ES2SYS_H
#define HELPER_ES2SYS_H
#ifdef TEF82XX_CFG_ES2 


#include <stdint.h>

#include "bc_types.h"
#include "bc_err.h"

#if defined(__cplusplus)
extern "C"
{
#endif

BC_ERRCODE Helper_ES2_ChangeFStart(SYS_ProfID_e ProfID, BC_FLOAT StartFreqHz, SYS_SBChangeMode_e Mode, uint8_t *pSubband);
BC_ERRCODE Helper_ES2_CopyProfile(SYS_IPNum_e IPNum, SYS_ProfID_e SrcProfID, SYS_ProfID_e DestProfID);
BC_ERRCODE Helper_ES2_ConfigTXPR(BOOL pUseDDMA[3], TE_DDMAMod_e DDMAMode, float32_t pDDMAInitPhase[3], float32_t pDDMAPhaseUpdate[3], TE_PRPCGenMode_e pFinalPCGenMode[3], BOOL pBPSKSource[3]);
BC_ERRCODE Helper_ES2_MCLKIntegrityCheck(void);
BC_ERRCODE Helper_ES2_TXSensorIntegrityCheck(void);
BC_ERRCODE Helper_ES2_CAFCSensorIntegrityCheck(SYS_ProfID_e ChirpProfSel, uint16_t NumChirp);
BC_ERRCODE Helper_ES2_SetCSOut(TE_CSOutCfg_t *pCSOutCfg);
BC_ERRCODE Helper_ES2_ReadTempSensor(float32_t *pKelvinTX1, float32_t *pKelvinTX2, float32_t *pKelvinTX3, float32_t *pKelvinChirp);
BC_ERRCODE Helper_ES2_RegCRCCheckCtrl(SYS_CRC_Trigger_Event_e CRCTriggerEvent);
BC_ERRCODE Helper_ES2_InitMasterSlaveMode(BOOL EnSlaveMode);
BC_ERRCODE Helper_ES2_AutoSubbandSwitching(BOOL Enable, uint8_t SubbandSteps);
BC_ERRCODE Helper_ES2_SetDevice(PLF_SPITarget_e TargetDevice);
BC_ERRCODE Helper_ES2_InitConfigADC(void);
BC_ERRCODE Helper_ES2_Init(void);
BC_ERRCODE Helper_ES2_ConfigCAFC(SYS_ProfID_e ProfID, SYS_ProfChirpFreq_t *pChirpFreq);
BC_ERRCODE Helper_ES2_RegCRCMCUTrigIntCheck(void);
BC_ERRCODE Helper_ES2_LoiBBDCheck(BOOL CheckLOIN, BOOL NormalSensitivityLOIN, BOOL GroundedLOIN, BOOL NormalSensitivityLOOUT, BOOL GroundedLOOUT);

#if defined(__cplusplus)
}
#endif
#endif
#endif
