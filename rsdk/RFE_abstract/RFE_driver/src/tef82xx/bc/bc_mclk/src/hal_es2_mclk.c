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

#ifdef TEF82XX_CFG_ES2
#include "hal_es2_mclk.h"
#ifdef BUILD_FOR_VAL
#include "v_es2_mclk.h"
#include "v_es2_ism.h"
#include "v_es2_cc.h"
#else
#include "reg_es2_mclk.h"
#include "reg_es2_ism.h"
#include "reg_es2_cc.h"
#endif
#include "reg_es2_mipi.h"
#include "bc_spi.h"
#include "bc_conf.h"
#include "bc_cc.h"
#include "plf.h"
#include <math.h>

/* Local defines */
#define MCLK_CHECK_CALIB_LOCAL_ARRAY 3u
#define MCLK_CHECK_CALIB_LOOP_MAX_COUNT 3u

static void Helper_ResetMSPCCtrl3(BOOL EnableManual);
static BC_ERRCODE Helper_CheckMSPCStatus(uint32_t *pMspcCalibCheckStatusVal32);
static BC_ERRCODE Helper_TriggerManulaMSPC(uint32_t *pClockDelaySkewControlVal32, BOOL *pSkewEdge, BOOL *pNeedCalib);
static BC_ERRCODE Helper_UpdateSkewTrigMSPC(uint32_t *pClockDelaySkewCtrlVal32, BOOL *pSkewEdge, BOOL *pNeedCalib, uint8_t CheckCount);
static BC_ERRCODE Helper_CheckMSPCLoop(uint32_t *pClockDelaySkewControlVal32, BOOL *pSkewEdge, BOOL *pNeedCalib);
static void Helper_CheckSkewEdge(BOOL *pSkewEdge, BOOL *pNeedCalib);
static BC_ERRCODE Helper_RestoreSkew(uint32_t *pClockDelaySkewControlVal32, BOOL *pSkewEdge, BOOL *pNeedCalib);
static BC_ERRCODE Helper_MSPCSerialiserFuncReset(void);
static void Helper_UpdateSkewDelay(uint32_t *pClockDelaySkewControlVal32, uint8_t MspcPfdClkinEarly, BOOL *pSkewEdge);
static void Helper_IncreaseSkewDecreaseDelay(uint32_t *pClockDelaySkewControlVal32, BOOL *pSkewEdge);
static void Helper_DecreaseSkewIncreaseDelay(uint32_t *pClockDelaySkewControlVal32, BOOL *pSkewEdge);

/* static functions */

static void Helper_ResetMSPCCtrl3(BOOL EnableManual)
{
    R2M0C_MspcControl3Union_t MspcControl3;
    MspcControl3.val_u32 = 0u;
    if (TRUE == EnableManual)
    {
        MspcControl3.bits_st.MspcCalibMode = 1u;
    }
    (void)BC_SPI_Write(e_SYS_MCLK, R2M0C_MSPC_CONTROL3_U16, MspcControl3.val_u32);
}
static BC_ERRCODE Helper_CheckMSPCStatus(uint32_t *pMspcCalibCheckStatusVal32)
{
    R2M0C_MspcControl3Union_t MspcControl3;
    R2M0C_MspcCalibCheckStatusUnion_t MspcCalibCheckStatus;
    uint32_t WaitTime;
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

    // no need to read register, since the reset value of other bitfields are 0u
    MspcControl3.val_u32 = 0u;
    MspcControl3.bits_st.MspcCalibMode = 1u; // SW based MSPC Calibration
    // 0 to 1 is trigger the MSPC calibration
    MspcControl3.bits_st.MspcPfdStartMeas = 1u;
    MspcControl3.bits_st.MspcCalibCheckCorrectionEnable = 0u;
    ErrCode = BC_SPI_Write(e_SYS_MCLK, R2M0C_MSPC_CONTROL3_U16, MspcControl3.val_u32);
    /* loop time mspc check is finished */
    if (BC_ERR_NOERROR == ErrCode)
    {
        // wait time is calib wait time
        WaitTime = MCLK_MSPC_MEASURE_WAIT_TIME;
        ErrCode = PLF_TM_Sleep(WaitTime);
        if (ErrCode == BC_ERR_NOERROR)
        {
            // Read the MSPC Calibration check status
            ErrCode = BC_SPI_Read(e_SYS_MCLK, R2M0C_MSPC_CALIB_CHECK_STATUS_U16, &MspcCalibCheckStatus.val_u32);
        }
        if (ErrCode == BC_ERR_NOERROR)
        {
            *pMspcCalibCheckStatusVal32 = MspcCalibCheckStatus.val_u32;
        }
        (void)Helper_ResetMSPCCtrl3(TRUE);
    }
    return ErrCode;
}
static void Helper_IncreaseSkewDecreaseDelay(uint32_t *pClockDelaySkewControlVal32, BOOL *pSkewEdge)
{
    R2M0C_ClockDelaySkewControlUnion_t ClockDelaySkewControl;
    ClockDelaySkewControl.val_u32 = *pClockDelaySkewControlVal32;
    uint8_t TmpUintVal;
    if (ClockDelaySkewControl.bits_st.OutputClkSkew < 15u)
    {
        TmpUintVal = (uint8_t)ClockDelaySkewControl.bits_st.OutputClkSkew;
        ClockDelaySkewControl.bits_st.OutputClkSkew = (uint8_t)(TmpUintVal + (uint8_t)1u);
    }
    else
    {
        ClockDelaySkewControl.bits_st.OutputClkSkew = (uint8_t)0u;
        if (ClockDelaySkewControl.bits_st.SetDelayClk40 == 0u)
        {
            ClockDelaySkewControl.bits_st.SetDelayClk40 = 14u;
        }
        else
        {
            TmpUintVal = (uint8_t)ClockDelaySkewControl.bits_st.SetDelayClk40;
            ClockDelaySkewControl.bits_st.SetDelayClk40 = (uint8_t)(TmpUintVal - (uint8_t)1u);
        }
    }
    *pSkewEdge = TRUE;
    *pClockDelaySkewControlVal32 = ClockDelaySkewControl.val_u32;
}
static void Helper_DecreaseSkewIncreaseDelay(uint32_t *pClockDelaySkewControlVal32, BOOL *pSkewEdge)
{
    R2M0C_ClockDelaySkewControlUnion_t ClockDelaySkewControl;
    ClockDelaySkewControl.val_u32 = *pClockDelaySkewControlVal32;
    uint8_t TmpUintVal;
    if (ClockDelaySkewControl.bits_st.OutputClkSkew > 0u)
    {
        TmpUintVal = (uint8_t)ClockDelaySkewControl.bits_st.OutputClkSkew;
        ClockDelaySkewControl.bits_st.OutputClkSkew = (uint8_t)(TmpUintVal - (uint8_t)1u);
    }
    else
    {
        ClockDelaySkewControl.bits_st.OutputClkSkew = (uint8_t)0x0Fu;
        if (ClockDelaySkewControl.bits_st.SetDelayClk40 == 14u)
        {
            ClockDelaySkewControl.bits_st.SetDelayClk40 = 0u;
        }
        else
        {
            TmpUintVal = (uint8_t)ClockDelaySkewControl.bits_st.SetDelayClk40;
            ClockDelaySkewControl.bits_st.SetDelayClk40 = (uint8_t)(TmpUintVal + (uint8_t)1u);
        }
    }
    *pSkewEdge = FALSE;
    *pClockDelaySkewControlVal32 = ClockDelaySkewControl.val_u32;
}
static void Helper_UpdateSkewDelay(uint32_t *pClockDelaySkewControlVal32, uint8_t MspcPfdClkinEarly, BOOL *pSkewEdge)
{
    if (MspcPfdClkinEarly == 0x1u)
    {
        (void)Helper_IncreaseSkewDecreaseDelay(pClockDelaySkewControlVal32, pSkewEdge);
    }
    else
    {
        (void)Helper_DecreaseSkewIncreaseDelay(pClockDelaySkewControlVal32, pSkewEdge);
    }
}

static BC_ERRCODE Helper_TriggerManulaMSPC(uint32_t *pClockDelaySkewControlVal32, BOOL *pSkewEdge, BOOL *pNeedCalib)
{
    R2M0C_MspcCalibCheckStatusUnion_t MspcCalibCheckStatus;
    BC_ERRCODE ErrCode;

    ErrCode = Helper_CheckMSPCStatus(&MspcCalibCheckStatus.val_u32);
    if (BC_ERR_NOERROR == ErrCode)
    {
        if (MspcCalibCheckStatus.bits_st.MspcError == FALSE)
        {
            (void)Helper_UpdateSkewDelay(pClockDelaySkewControlVal32, (uint8_t)MspcCalibCheckStatus.bits_st.MspcPfdClkinEarly, pSkewEdge);
        }
        else
        {
            *pNeedCalib = TRUE;
        }
    }
    return ErrCode;
}
static BC_ERRCODE Helper_UpdateSkewTrigMSPC(uint32_t *pClockDelaySkewCtrlVal32, BOOL *pSkewEdge, BOOL *pNeedCalib, uint8_t CheckCount)
{
    BC_ERRCODE ErrCode;
    uint32_t WaitTime;

    ErrCode = BC_SPI_Write(e_SYS_MCLK, R2M0C_CLOCK_DELAY_SKEW_CONTROL_U16, *pClockDelaySkewCtrlVal32);
    if (ErrCode == BC_ERR_NOERROR)
    {
        WaitTime = MCLK_MSPC_PLLSKEW_WAIT_TIME;
        ErrCode = PLF_TM_Sleep(WaitTime);
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = Helper_TriggerManulaMSPC(pClockDelaySkewCtrlVal32, &pSkewEdge[CheckCount], pNeedCalib);
    }
    return ErrCode;
}
static BC_ERRCODE Helper_CheckMSPCLoop(uint32_t *pClockDelaySkewControlVal32, BOOL *pSkewEdge, BOOL *pNeedCalib)
{
    BC_ERRCODE ErrCode;
    uint32_t ClockDelaySkewControlVal32;
    uint8_t CheckCount = 0u;
    ClockDelaySkewControlVal32 = pClockDelaySkewControlVal32[CheckCount];
    ErrCode = Helper_UpdateSkewTrigMSPC(&ClockDelaySkewControlVal32, &pSkewEdge[0u], pNeedCalib, CheckCount);
    if ((BC_ERR_NOERROR == ErrCode) && (*pNeedCalib == FALSE))
    {
        CheckCount += 1u;
        pClockDelaySkewControlVal32[CheckCount] = ClockDelaySkewControlVal32;
        ErrCode = Helper_UpdateSkewTrigMSPC(&ClockDelaySkewControlVal32, &pSkewEdge[0u], pNeedCalib, CheckCount);
    }
    if ((BC_ERR_NOERROR == ErrCode) && (pSkewEdge[1u] == pSkewEdge[0u]) && (*pNeedCalib == FALSE))
    {
        CheckCount += 1u;
        pClockDelaySkewControlVal32[CheckCount] = ClockDelaySkewControlVal32;
        ErrCode = Helper_UpdateSkewTrigMSPC(&ClockDelaySkewControlVal32, &pSkewEdge[0u], pNeedCalib, CheckCount);
    }
    else
    {
        pSkewEdge[2u] = TRUE;
    }
    return ErrCode;
}
static void Helper_CheckSkewEdge(BOOL *pSkewEdge, BOOL *pNeedCalib)
{
    if (*pNeedCalib == FALSE)
    {
        if ((pSkewEdge[0u] == pSkewEdge[1u]) && (pSkewEdge[0u] == pSkewEdge[2u]))
        {
            *pNeedCalib = TRUE;
        }
    }
    if (*pNeedCalib == FALSE)
    {
        if ((pSkewEdge[0u] == TRUE) && (pSkewEdge[1u] == TRUE))
        {
            *pNeedCalib = TRUE;
        }
    }
}
static BC_ERRCODE Helper_RestoreSkew(uint32_t *pClockDelaySkewControlVal32, BOOL *pSkewEdge, BOOL *pNeedCalib)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    uint32_t WaitTime = MCLK_MSPC_PLLSKEW_WAIT_TIME;
    (void)Helper_CheckSkewEdge(pSkewEdge, pNeedCalib);

    if (*pNeedCalib == FALSE)
    {
        if ((pSkewEdge[2u] == TRUE) && (pSkewEdge[1u] == FALSE) && (pSkewEdge[0u] == FALSE))
        {
            ErrCode = BC_SPI_Write(e_SYS_MCLK, R2M0C_CLOCK_DELAY_SKEW_CONTROL_U16, pClockDelaySkewControlVal32[1u]);
            if (ErrCode == BC_ERR_NOERROR)
            {
                ErrCode = PLF_TM_Sleep(WaitTime);
            }
        }
        if ((pSkewEdge[1u] == TRUE) && (pSkewEdge[0u] == FALSE))
        {
            ErrCode = BC_SPI_Write(e_SYS_MCLK, R2M0C_CLOCK_DELAY_SKEW_CONTROL_U16, pClockDelaySkewControlVal32[0u]);
            if (ErrCode == BC_ERR_NOERROR)
            {
                ErrCode = PLF_TM_Sleep(WaitTime);
            }
        }
    }
    return ErrCode;
}

static BC_ERRCODE Helper_MSPCSerialiserFuncReset(void)
{
    BC_ERRCODE ErrCode;
    R2M00_IpFunctionalResetControlUnion_t IpFunctionalReset;
    uint32_t WhileLoopCount = 0u;
    R2M02_DeviceReadyIndicationRegisterUnion_t DeviceReadyIndicationReg;
    DeviceReadyIndicationReg.val_u32 = 0u;
    SYS_IPList_t AppConfig = {FALSE};
    ErrCode = BC_CC_GetAppConfiguration(&AppConfig, NULL);

    /* Serialiser functional reset */
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_SPI_Read(e_SYS_CC, R2M00_IP_FUNCTIONAL_RESET_CONTROL_U16, &IpFunctionalReset.val_u32);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        IpFunctionalReset.bits_st.FnResetSer = 0u;
        ErrCode = BC_SPI_Write(e_SYS_CC, R2M00_IP_FUNCTIONAL_RESET_CONTROL_U16, IpFunctionalReset.val_u32);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        IpFunctionalReset.bits_st.FnResetSer = 1u;
        ErrCode = BC_SPI_Write(e_SYS_CC, R2M00_IP_FUNCTIONAL_RESET_CONTROL_U16, IpFunctionalReset.val_u32);
    }

    if ((TRUE == AppConfig.MIPI) && (BC_ERR_NOERROR == ErrCode))
    {
        do
        {
            ErrCode = PLF_TM_Sleep(MIPI_CONFIG_SLEEP);
            if (ErrCode == BC_ERR_NOERROR)
            {
                ErrCode = BC_SPI_Read(e_SYS_MIPI, R2M02_DEVICE_READY_INDICATION_REGISTER_U16, &DeviceReadyIndicationReg.val_u32);
            }
            if (BC_ERR_NOERROR == ErrCode)
            {
                if (WhileLoopCount >= MIPI_PLL_READY_TIMEOUT)
                {
                    // on error or timeout,  break timeout loop
                    ErrCode = BC_ERR_MIPI_DEVICE_READY_TIMEOUT;
                }
                else
                {
                    WhileLoopCount++;
                }
            }
        } while ((DeviceReadyIndicationReg.bits_st.DeviceReady != 0x1u) && (ErrCode == BC_ERR_NOERROR));
    }
    return ErrCode;
}

/* Functions */

BC_ERRCODE HAL_ES2_MCLK_AutoCalib(BOOL ExtendedReCal)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

    R2M0C_CalibrationAfcControl5Union_t CalibAfcCtrl5;
    R2M0C_StartCalibrationUnion_t StartCalib;
    R2M0C_CalibrationStatus3Union_t CalibrationStatus3;

    uint32_t CalbrationTimeus;

    if (ExtendedReCal == TRUE)
    {
        /* for Auto calibration don't need to set anything, just use the default setting.
        For recalibration CALIBRATION_AFC_CONTROL5 pll_use_recal_settings need to be set 1, for extended recalibration it should be 0,
        pll_use_recal_settings bit setting internally take care use fine or init setting of calibration registers
        Use the AFC recalibrated */
        /* Read of register is not required, since only two bitfields are present, AfcManual should be set to 0 for auto calibration */
        CalibAfcCtrl5.val_u32 = 0u;
        CalibAfcCtrl5.bits_st.PllUseRecalSettings = (uint8_t)FALSE; // extended recalibration or Recalibration
        ErrCode = BC_SPI_Write(e_SYS_MCLK, R2M0C_CALIBRATION_AFC_CONTROL5_U16, CalibAfcCtrl5.val_u32);
        CalbrationTimeus = MCLK_PLL_CALIBRATION_TIME_US;
    }
    else
    {
        CalbrationTimeus = MCLK_PLL_RECALIBRATION_TIME_US;
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        StartCalib.bits_st.StartCalibrationCtrl = 1u; /*  start calibration */
        StartCalib.bits_st.Reserved0 = 0u;
        ErrCode = BC_SPI_Write(e_SYS_MCLK, R2M0C_START_CALIBRATION_U16, StartCalib.val_u32);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = PLF_TM_Sleep(CalbrationTimeus);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_SPI_Read(e_SYS_MCLK, R2M0C_CALIBRATION_STATUS3_U16, &CalibrationStatus3.val_u32);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        if (CalibrationStatus3.bits_st.PllCalibrationActive == 0x0u)
        {
            if ((CalibrationStatus3.bits_st.VcoRecalibrate == 1u) ||
                (CalibrationStatus3.bits_st.PllLockError == 1u))
            {
                ErrCode = BC_ERR_MCLK_PLL_CALIBRATION_FAILED;
            }
        }
        else
        {
            ErrCode = BC_ERR_MCLK_PLL_CALIBRATION_NOTFINISHED;
        }
    }
    if (ExtendedReCal == TRUE)
    {
        // Error code check is not required, PLL Recal settings needs to be reverted irrespective of calibration status
        CalibAfcCtrl5.val_u32 = 0u;
        CalibAfcCtrl5.bits_st.PllUseRecalSettings = (uint8_t)TRUE; // Full calibration or Recalibration
        (void)BC_SPI_Write(e_SYS_MCLK, R2M0C_CALIBRATION_AFC_CONTROL5_U16, CalibAfcCtrl5.val_u32);
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_MCLK_GetCalibrationStatus(BOOL *pLocked, MCLK_CalibrationStatus_t *pCalibStatus)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M0C_CalibrationStatus1Union_t CalibrationStatus1;
    R2M0C_CalibrationStatus3Union_t CalibrationStatus3;
    /* lock status will be prasent in the next exls V15, use calibration active + VCO callib err etc ....*/
    if ((pLocked != NULL) && (pCalibStatus != NULL))
    {
        *pLocked = FALSE;
        ErrCode = BC_SPI_Read(e_SYS_MCLK, R2M0C_CALIBRATION_STATUS3_U16, &CalibrationStatus3.val_u32);
        if (ErrCode == BC_ERR_NOERROR)
        {
            ErrCode = BC_SPI_Read(e_SYS_MCLK, R2M0C_CALIBRATION_STATUS1_U16, &CalibrationStatus1.val_u32);
            if (ErrCode == BC_ERR_NOERROR)
            {

                pCalibStatus->PllCalibrationActive = (BOOL)CalibrationStatus3.bits_st.PllCalibrationActive;
                pCalibStatus->VcoLevelError = (BOOL)CalibrationStatus3.bits_st.VcoLevelError;
                pCalibStatus->VcoLevelRecalib = (BOOL)CalibrationStatus1.bits_st.VcoLevelRecalib;
                pCalibStatus->VcoFreqRecalib = (BOOL)CalibrationStatus1.bits_st.VcoFreqRecalib;
                pCalibStatus->VcoRecalibrate = (BOOL)CalibrationStatus3.bits_st.VcoRecalibrate;
                pCalibStatus->PLLLockError = (BOOL)CalibrationStatus3.bits_st.PllLockError;
                // For MISRA 10.5 Since MISRA does not allow type casting Boolean to any other data types
                if ((pCalibStatus->PllCalibrationActive == 0x1u) ||
                    (pCalibStatus->VcoLevelError == 0x1u) ||
                    (pCalibStatus->VcoLevelRecalib == 0x1u) ||
                    (pCalibStatus->VcoFreqRecalib == 0x1u) ||
                    (pCalibStatus->VcoRecalibrate == 0x1u) ||
                    (pCalibStatus->PLLLockError == 0x1u))
                {
                    *pLocked = FALSE;
                }
                else
                {
                    *pLocked = TRUE;
                }
            }
        }
    }
    else
    {
        ErrCode = BC_ERR_INPUTOUTOFRANGE;
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_MCLK_SetClkBuffers(BOOL EnChirp480M, BOOL EnSer480600M, BOOL EnADC1200M, BOOL EnSSB600M, BOOL EnADC40M)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M0C_ClockBufferControlUnion_t ClkBufferCtrl; /*## attribute ClockBufferControl_ust */

    ErrCode = BC_SPI_Read(e_SYS_MCLK, R2M0C_CLOCK_BUFFER_CONTROL_U16, &ClkBufferCtrl.val_u32);
    if (BC_ERR_NOERROR == ErrCode)
    {
        ClkBufferCtrl.bits_st.EnClkAdc40 = (uint8_t)EnADC40M;
        ClkBufferCtrl.bits_st.EnClkAdc1200 = (uint8_t)EnADC1200M;
        ClkBufferCtrl.bits_st.EnClkChirp480 = (uint8_t)EnChirp480M;
        ClkBufferCtrl.bits_st.EnClkSer480600 = (uint8_t)EnSer480600M;
        ClkBufferCtrl.bits_st.EnClkSsbmod600 = (uint8_t)EnSSB600M;

        ErrCode = BC_SPI_WriteCheck(e_SYS_MCLK, R2M0C_CLOCK_BUFFER_CONTROL_U16, ClkBufferCtrl.val_u32);
    }

    return ErrCode;
}

BC_ERRCODE HAL_ES2_MCLK_ConfigMSPCTiming(MCLK_MSPCWaitTime_e MSPCTime, MCLK_MSPCSkewWaitTime_e SkewTime, MCLK_MSPCDelayWaitTime_e DelayTime)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M0C_MspcControl2Union_t MspcControl2;

    if ((MSPCTime < e_MCLK_MSPC_WAITTIME_INVALID) && (SkewTime < e_MCLK_MSPC_PLLSKEW_WAITTIME_INVALID) && (DelayTime < e_MCLK_MSPC_DELAY_WAITTIME_INVALID))
    {
        ErrCode = BC_SPI_Read(e_SYS_MCLK, R2M0C_MSPC_CONTROL2_U16, &MspcControl2.val_u32);
        if (BC_ERR_NOERROR == ErrCode)
        {
            if (MSPCTime < e_MCLK_MSPC_WAITTIME_KEEP_CURRENT)
            {
                MspcControl2.bits_st.MspcMeasureWaitTime = (uint8_t)MSPCTime;
            }
            if (SkewTime < e_MCLK_MSPC_PLLSKEW_WAITTIME_KEEP_CURRENT)
            {
                MspcControl2.bits_st.MspcPllSkewWaitTime = (uint8_t)SkewTime;
            }
            if (DelayTime < e_MCLK_MSPC_DELAY_WAITTIME_KEEP_CURRENT)
            {
                MspcControl2.bits_st.MspcSetDelayWaitTime = (uint8_t)DelayTime;
            }
            ErrCode = BC_SPI_WriteCheck(e_SYS_MCLK, R2M0C_MSPC_CONTROL2_U16, MspcControl2.val_u32);
        }
    }
    else
    {
        ErrCode = BC_ERR_INPUTOUTOFRANGE;
    }

    return ErrCode;
}

BC_ERRCODE HAL_ES2_MCLK_StartMSPC(void)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

    R2M0C_MspcControl3Union_t MspcControl3;
    R2M0C_MspcCalibCheckStatusUnion_t MspcCalibCheckStatus;
    uint32_t WaitTime;
    uint32_t WhileLoopCount = 0u;

    // no need to read register, since the reset value of other bitfields are 0u
    MspcControl3.val_u32 = 0u;
    MspcControl3.bits_st.MspcCalibMode = 0u; // HW based MSPC Calibration
    // 0 to 1 is trigger the MSPC calibration
    MspcControl3.bits_st.MspcPfdStartMeas = 1u;
    ErrCode = BC_SPI_Write(e_SYS_MCLK, R2M0C_MSPC_CONTROL3_U16, MspcControl3.val_u32);
    // Read the set calibration wait time
    // In MSPC calibration total state machine one round time.
    // calib wait time + skewWait time, once the skew is set delay time change is very less in nanosecond.
    WaitTime = MCLK_MSPC_CALIB_ONEROUND_WAIT_TIME;

    /* Wait till calibration is finished */
    if (BC_ERR_NOERROR == ErrCode)
    {
        MspcCalibCheckStatus.bits_st.MspcCalibBusy = 0u;
        do
        {
            if (MspcCalibCheckStatus.bits_st.MspcCalibBusy == 0x1u)
            {
                ErrCode = PLF_TM_Sleep(WaitTime);
            }
            if (ErrCode == BC_ERR_NOERROR)
            {
                // Read the MSPC Calibration status
                ErrCode = BC_SPI_Read(e_SYS_MCLK, R2M0C_MSPC_CALIB_CHECK_STATUS_U16, &MspcCalibCheckStatus.val_u32);
            }
            if (ErrCode == BC_ERR_NOERROR)
            {
                if (WhileLoopCount >= MCLK_MSPCTIMEOUT_TIMEOUT)
                {
                    ErrCode = BC_ERR_MCLK_MSPCTIMEOUT;
                }
                else
                {
                    WhileLoopCount++;
                }
            }
        } while ((MspcCalibCheckStatus.bits_st.MspcCalibBusy == 0x1u) && (ErrCode == BC_ERR_NOERROR));
    }

    if (BC_ERR_NOERROR == ErrCode)
    {
        if (MspcCalibCheckStatus.bits_st.MspcError != 0u)
        {
            ErrCode = BC_ERR_MCLK_MSPC_CALIBRATION_ERROR;
        }
    }
    /*This need to be set back Error code is not returned since it overwrites the calibration error*/
    (void)Helper_ResetMSPCCtrl3(FALSE);
    /* Serialiser functional reset */
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = Helper_MSPCSerialiserFuncReset();
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_MCLK_CheckMSPCStatus(BOOL *pNeedCalib)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M0C_ClkselUnion_t AdcClksel;
    R2M0C_ClockDelaySkewControlUnion_t ClockDelaySkewControl;
    uint32_t ClockDelaySkewControlVal32[MCLK_CHECK_CALIB_LOCAL_ARRAY] = {0u, 0u, 0u};
    BOOL SkewEdge[MCLK_CHECK_CALIB_LOCAL_ARRAY] = {FALSE, FALSE, FALSE};

    if (pNeedCalib == NULL)
    {
        ErrCode = BC_ERR_MCLK_PTR_ADDR_NULL;
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_SPI_Read(e_SYS_MCLK, R2M0C_CLKSEL_U16, &AdcClksel.val_u32);
        if (BC_ERR_NOERROR == ErrCode)
        {
            // use Xo clock for CC
            AdcClksel.bits_st.ClkselCc40Calclk = 0x0u;
            ErrCode = BC_SPI_Write(e_SYS_MCLK, R2M0C_CLKSEL_U16, AdcClksel.val_u32);
        }
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        *pNeedCalib = FALSE;
        ErrCode = BC_SPI_Read(e_SYS_MCLK, R2M0C_CLOCK_DELAY_SKEW_CONTROL_U16, &ClockDelaySkewControl.val_u32);
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        (void)Helper_ResetMSPCCtrl3(TRUE);
        ClockDelaySkewControlVal32[0u] = ClockDelaySkewControl.val_u32;
        ErrCode = Helper_CheckMSPCLoop(&ClockDelaySkewControlVal32[0u], &SkewEdge[0u], pNeedCalib);
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = Helper_RestoreSkew(&ClockDelaySkewControlVal32[0u], &SkewEdge[0u], pNeedCalib);
    }
    // use calibrated clock for CC
    if (BC_ERR_NOERROR == ErrCode)
    {
        AdcClksel.bits_st.ClkselCc40Calclk = 0x1u;
        ErrCode = BC_SPI_Write(e_SYS_MCLK, R2M0C_CLKSEL_U16, AdcClksel.val_u32);
    }
    /* Serialiser functional reset */
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = Helper_MSPCSerialiserFuncReset();
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_MCLK_ConfigManualMSPC(uint8_t OutPutClkSkewCode, uint8_t RefClkDelayCode)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M0C_MspcControl3Union_t MspcControl3;
    R2M0C_ClockDelaySkewControlUnion_t ClockDelaySkewControl;
    R2M0C_ClkselUnion_t AdcClksel;
    R2M18_IsmErrorMcuResetUnion_t IsmErrorMcuReset;

    if ((OutPutClkSkewCode < 16u) && (RefClkDelayCode < 16u))
    {
        ErrCode = BC_SPI_Read(e_SYS_MCLK, R2M0C_CLKSEL_U16, &AdcClksel.val_u32);
        if (BC_ERR_NOERROR == ErrCode)
        {
            // use Xo clock for CC
            AdcClksel.bits_st.ClkselCc40Calclk = 0x0u;
            ErrCode = BC_SPI_WriteCheck(e_SYS_MCLK, R2M0C_CLKSEL_U16, AdcClksel.val_u32);
        }
        if (BC_ERR_NOERROR == ErrCode)
        {
            ErrCode = BC_SPI_Read(e_SYS_MCLK, R2M0C_MSPC_CONTROL3_U16, &MspcControl3.val_u32);
        }
        if (BC_ERR_NOERROR == ErrCode)
        {
            MspcControl3.bits_st.MspcCalibMode = 1u; // HW based MSPC Calibration
            ErrCode = BC_SPI_WriteCheck(e_SYS_MCLK, R2M0C_MSPC_CONTROL3_U16, MspcControl3.val_u32);
        }
        if (BC_ERR_NOERROR == ErrCode)
        {
            ErrCode = BC_SPI_Read(e_SYS_MCLK, R2M0C_CLOCK_DELAY_SKEW_CONTROL_U16, &ClockDelaySkewControl.val_u32);
            ClockDelaySkewControl.bits_st.OutputClkSkew = OutPutClkSkewCode;
            ClockDelaySkewControl.bits_st.SetDelayClk40 = RefClkDelayCode;
            if (BC_ERR_NOERROR == ErrCode)
            {
                ErrCode = BC_SPI_WriteCheck(e_SYS_MCLK, R2M0C_CLOCK_DELAY_SKEW_CONTROL_U16, ClockDelaySkewControl.val_u32);
            }
        }
        if (ErrCode == BC_ERR_NOERROR)
        {
            ErrCode = PLF_TM_Sleep(40u);
        }
        // Reset ISM and Local Errors
        if (ErrCode == BC_ERR_NOERROR)
        {
            IsmErrorMcuReset.val_u32 = 0x0;
            IsmErrorMcuReset.bits_st.ResetErrorCountMcuSpi = 1u; // Reset counters
            IsmErrorMcuReset.bits_st.ResetErrorMcuSpi = 1u;      // Always
            ErrCode = BC_SPI_Write(e_SYS_ISM, R2M18_ISM_ERROR_MCU_RESET_U16, IsmErrorMcuReset.val_u32);
        }
        // use calibrated clock for CC
        if (BC_ERR_NOERROR == ErrCode)
        {
            AdcClksel.bits_st.ClkselCc40Calclk = 0x1u;
            ErrCode = BC_SPI_WriteCheck(e_SYS_MCLK, R2M0C_CLKSEL_U16, AdcClksel.val_u32);
        }
    }
    else
    {
        ErrCode = BC_ERR_INPUTOUTOFRANGE;
    }
    return ErrCode;
}

#endif
/* End of File */
