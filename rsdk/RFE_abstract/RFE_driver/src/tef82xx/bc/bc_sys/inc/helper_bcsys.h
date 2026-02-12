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
@file helper_bcsys.h

@version

@brief Barracuda helper file for SYS block

This is helper file for SYS block.
*/

#ifndef HELPER_BCSYS_H
#define HELPER_BCSYS_H

#include <stdint.h>

#include "bc_types.h"
#include "bc_err.h"

#if defined(__cplusplus)
extern "C"
{
#endif

BC_ERRCODE Helper_ConfigCAFC(SYS_ProfID_e ProfID, SYS_ProfChirpFreq_t *pChirpFreq);
BC_ERRCODE Helper_ConfigSC(SYS_ProfID_e ProfID, SYS_ProfChirpTiming_t *pChirpTiming, SYS_ProfChirpFreq_t *pChirpFreq, SYS_ProfChirpSampleDeci_t *pProfSampleDeci);
BC_ERRCODE Helper_ConfigRX(SYS_ProfID_e ProfID, RX_Gain_Control_e RXGain[4], SYS_RXLPF_CornerFreq_e RXLPF[4], SYS_RXHPF_CornerFreq_e RXHPF[4], SYS_IPList_t *pAppConfig);
BC_ERRCODE Helper_ConfigTE(SYS_ProfID_e ProfID, SYS_ProfChirpTiming_t *pChirpTiming, SYS_ProfChirpSampleDeci_t *pProfSampleDeci, BOOL TXBPS[3], float32_t PhaseRotation[3], BOOL TXFastSW[3], BOOL TXEN[3], BOOL RXEN[4]);
BC_ERRCODE Helper_ChangeFStart(SYS_ProfID_e ProfID, BC_FLOAT StartFreqHz, SYS_SBChangeMode_e Mode, uint8_t *pSubband);
BC_ERRCODE Helper_CopyProfile(SYS_IPNum_e IPNum, SYS_ProfID_e SrcProfID, SYS_ProfID_e DestProfID);
BC_ERRCODE Helper_ConfigTXPR(BOOL pUseDDMA[3], TE_DDMAMod_e DDMAMode, float32_t pDDMAInitPhase[3], float32_t pDDMAPhaseUpdate[3], TE_PRPCGenMode_e pFinalPCGenMode[3], BOOL pBPSKSource[3]);
BC_ERRCODE Helper_MCLKIntegrityCheck(void);
BC_ERRCODE Helper_TXSensorIntegrityCheck(void);
BC_ERRCODE Helper_CAFCSensorIntegrityCheck(SYS_ProfID_e ChirpProfSel, uint16_t NumChirp);
BC_ERRCODE Helper_SetCSOut(TE_CSOutCfg_t *pCSOutCfg);
BC_ERRCODE Helper_ReadTempSensor(float32_t *pKelvinTX1, float32_t *pKelvinTX2, float32_t *pKelvinTX3, float32_t *pKelvinChirp);
BC_ERRCODE Helper_RegCRCCheckCtrl(SYS_CRC_Trigger_Event_e CRCTriggerEvent);
BC_ERRCODE Helper_InitMasterSlaveMode(BOOL EnSlaveMode);
BC_ERRCODE Helper_AutoSubbandSwitching(BOOL Enable, uint8_t SubbandSteps);
BC_ERRCODE Helper_SetDevice(PLF_SPITarget_e TargetDevice);
BC_ERRCODE Helper_InitConfigADC(void);
BC_ERRCODE Helper_Init(void);
BC_ERRCODE Helper_RegCRCMCUTrigIntCheck(void);
BC_ERRCODE Helper_LoiBBDCheck(BOOL CheckLOIN, BOOL NormalSensitivityLOIN, BOOL GroundedLOIN, BOOL NormalSensitivityLOOUT, BOOL GroundedLOOUT);

#if defined(__cplusplus)
}
#endif
#endif
