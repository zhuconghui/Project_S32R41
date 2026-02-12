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
#include "bc_err.h"
#include "bc_conf.h"
#include "bc_types.h"
#include "bc_te.h"
#include "bc_spi.h"
#ifdef BUILD_FOR_VAL
#include "v_es2_te.h"
#include "v_es2_tx.h"
#else
#include "reg_es2_te.h"
#include "reg_es2_tx.h"
#endif
#include "hal_es2_te.h"
#include "hal_es2_cc.h"
#include "plf.h"
#include <math.h>

static BC_ERRCODE Helper_ES2_WriteCheckTxCalEnable(SYS_IPList_t *pSysAppConfig, uint32_t TxCalEnableWrite);
static BC_ERRCODE Helper_ES2_TXPRSafetyCheckDefaults(BOOL EnPRSafetyCheck);
static BC_ERRCODE Helper_ES2_SetCtrl1Reg(SYS_ProfID_e ProfileNum, float32_t DwellTime, uint32_t TxOnDelayFromRefPoint, BOOL TrigPoint, BOOL pBPPhaseCtrlTx[3], BOOL pEnTx[3]);

static BC_ERRCODE Helper_ES2_WriteCheckTxCalEnable(SYS_IPList_t *pSysAppConfig, uint32_t TxCalEnableWrite)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    uint32_t TxCalEnableVal32 = 0u;
    uint8_t Count = 0u;
    
    if (pSysAppConfig->TX1 == TRUE)
    {
        ErrCode = BC_SPI_Read(e_SYS_TX1, R2M11_TX_CAL_ENABLE_U16, &TxCalEnableVal32);
        if (TxCalEnableWrite != TxCalEnableVal32)
        {
            Count = 1u;
        }
        TxCalEnableVal32 = 0u;
    }
    if ((pSysAppConfig->TX2 == TRUE) && (ErrCode == BC_ERR_NOERROR))
    {
        ErrCode = BC_SPI_Read(e_SYS_TX2, R2M11_TX_CAL_ENABLE_U16, &TxCalEnableVal32);
        if (TxCalEnableWrite != TxCalEnableVal32)
        {
            Count = Count + 2u;
        }
        TxCalEnableVal32 = 0u;
    }
    if ((pSysAppConfig->TX3 == TRUE) && (ErrCode == BC_ERR_NOERROR))
    {
        ErrCode = BC_SPI_Read(e_SYS_TX3, R2M11_TX_CAL_ENABLE_U16, &TxCalEnableVal32);
        if (TxCalEnableWrite != TxCalEnableVal32)
        {
            Count = Count + 4u;
        }
    }
    if (BC_ERR_NOERROR == ErrCode)
    {
        if (Count != 0u)
        {
            ErrCode = BC_ERR_TE_TX_CAL_ENABLE_WRITECHECK_BASE + (uint32_t)Count;
        }
    }
    return ErrCode;
}

static BC_ERRCODE Helper_ES2_TXPRSafetyCheckDefaults(BOOL EnPRSafetyCheck)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M11_TxCalEnableUnion_t TxCalEnable;
    SYS_IPList_t SysAppConfig;
    /*
       Because of slowness issue in starting circuitry in TX,  ppd and muxamp are always on which causes power consumption will increase per Tx;
       MuxAmp and ppd are on always only if safety check is triggered during the chirp sequence.
    */
    TxCalEnable.val_u32 = 0u; // EnPpdMon is 0 (reset value)
    TxCalEnable.bits_st.EnMuxAmp = (uint8_t)EnPRSafetyCheck;
    TxCalEnable.bits_st.EnPpdVga = (uint8_t)EnPRSafetyCheck;
    TxCalEnable.bits_st.EnPrppd = (uint8_t)EnPRSafetyCheck;

    ErrCode = HAL_ES2_CC_GetAppConfiguration(&SysAppConfig, NULL);
    if (BC_ERR_NOERROR == ErrCode)
    {
        ErrCode = BC_SPI_Write(e_SYS_TXMC, R2M11_TX_CAL_ENABLE_U16, TxCalEnable.val_u32);
        if (BC_ERR_NOERROR == ErrCode)
        {
            ErrCode = Helper_ES2_WriteCheckTxCalEnable(&SysAppConfig, TxCalEnable.val_u32);
        }
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_TE_StartChirp(void)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M04_ChirpGlobalControlUnion_t GlobalCtrl;

    retVal = BC_SPI_Read(e_SYS_TE, R2M04_CHIRP_GLOBAL_CONTROL_U16, &GlobalCtrl.val_u32);
    if ((BC_ERR_NOERROR == retVal) && (GlobalCtrl.bits_st.ChirpEnable == FALSE))
    {
        /* Enable chirp */
        GlobalCtrl.bits_st.ChirpEnable = (uint8_t)TRUE;
        retVal = BC_SPI_Write(e_SYS_TE, R2M04_CHIRP_GLOBAL_CONTROL_U16, GlobalCtrl.val_u32);
        if (BC_ERR_NOERROR == retVal)
        {
            retVal = BC_SPI_Read(e_SYS_TE, R2M04_CHIRP_GLOBAL_CONTROL_U16, &GlobalCtrl.val_u32);
        }
        if ((BC_ERR_NOERROR == retVal) && (GlobalCtrl.bits_st.ChirpEnable == FALSE))
        {
            retVal = BC_ERR_TE_CHIRP_ENABLE_WRITECHECK_FAILED;
        }
    }

    if (BC_ERR_NOERROR == retVal)
    {
        /* Start chirp */
        GlobalCtrl.bits_st.ChirpStart = (uint8_t)TRUE;
        retVal = BC_SPI_Write(e_SYS_TE, R2M04_CHIRP_GLOBAL_CONTROL_U16, GlobalCtrl.val_u32);
    }
return retVal;
}

BC_ERRCODE HAL_ES2_TE_EnableChirp(BOOL Enable)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M04_ChirpGlobalControlUnion_t GlobalCtrl;

    retVal = BC_SPI_Read(e_SYS_TE, R2M04_CHIRP_GLOBAL_CONTROL_U16, &GlobalCtrl.val_u32);
    if (retVal == BC_ERR_NOERROR)
    {
        /* Enable chirp */
        GlobalCtrl.bits_st.ChirpEnable = Enable;
        retVal = BC_SPI_Write(e_SYS_TE, R2M04_CHIRP_GLOBAL_CONTROL_U16, GlobalCtrl.val_u32);
    }
    return retVal;
}

BC_ERRCODE HAL_ES2_TE_SetChirpTrgMode(TE_ChirpTrgMode_t *pChirpTrgMode)
{
    R2M04_ChirpTriggerModeControlUnion_t TEChirpTriggerModeCtrl;
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    if (pChirpTrgMode != NULL)
    {
        retVal = BC_SPI_Read(e_SYS_TE, R2M04_CHIRP_TRIGGER_MODE_CONTROL_U16, &TEChirpTriggerModeCtrl.val_u32);
        if (BC_ERR_NOERROR == retVal)
        {
            if ((pChirpTrgMode->ChirpTrigMode == e_TE_CH_TRG_SPI_TRIGGER) || (pChirpTrgMode->ChirpTrigMode == e_TE_CH_TRG_EXT_SINGLE_TRG) || (pChirpTrgMode->ChirpTrigMode == e_TE_CH_TRG_EXT_EVERY_CHRIP))
            {
                TEChirpTriggerModeCtrl.bits_st.ChirpTriggerMode = (uint8_t)pChirpTrgMode->ChirpTrigMode;
            }
            else
            {
                retVal = BC_ERR_TE_CHIRPTRGMODE;
            }
        }
        if (BC_ERR_NOERROR == retVal)
        {
            TEChirpTriggerModeCtrl.bits_st.ChirpStartDelay = (uint8_t)pChirpTrgMode->ChirpStartDelay;
            TEChirpTriggerModeCtrl.bits_st.ChirpPowerMode = (uint8_t)pChirpTrgMode->ChirpPowerMode;

            retVal = BC_SPI_WriteCheck(e_SYS_TE, R2M04_CHIRP_TRIGGER_MODE_CONTROL_U16, TEChirpTriggerModeCtrl.val_u32);
        }
    }
    else
    {
        retVal = BC_ERR_TE_INPUTNULL;
    }
    return retVal;
}



BC_ERRCODE HAL_ES2_TE_TXPRSafetyCheckDelay(BOOL EnPRSafetyCheck, float32_t PRSafetyStartDelay)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M04_TxPrDelayControlUnion_t TxPrDelayControl;
    uint32_t tmpSafetyDelay;
    if ((EnPRSafetyCheck == TRUE) && ((PRSafetyStartDelay < TE_DELAY_MIN) || (PRSafetyStartDelay > TE_PRSAFETYSTARTDELAY_MAX)))
    {
        retVal = BC_ERR_TE_PRSAFETYDELAY;
    }
    if (retVal == BC_ERR_NOERROR)
    {
        retVal = BC_SPI_Read(e_SYS_TE, R2M04_TX_PR_DELAY_CONTROL_U16, &TxPrDelayControl.val_u32);
        if (BC_ERR_NOERROR == retVal)
        {
            if (TRUE == EnPRSafetyCheck)
            {
                /* Convert us to 25ns base */
                tmpSafetyDelay = (uint32_t)(lroundf(PRSafetyStartDelay * 1000.0f / 25.0f));
                TxPrDelayControl.bits_st.PrSafetyStartDelay = (uint16_t)tmpSafetyDelay;
            }
            TxPrDelayControl.bits_st.PrSafetyEnable = (uint8_t)EnPRSafetyCheck;
            /*Writing back the values*/
            retVal = BC_SPI_WriteCheck(e_SYS_TE, R2M04_TX_PR_DELAY_CONTROL_U16, TxPrDelayControl.val_u32);
        }
    }
    if (retVal == BC_ERR_NOERROR)
    {
        retVal = Helper_ES2_TXPRSafetyCheckDefaults(EnPRSafetyCheck);
    }

    return retVal;
}

BC_ERRCODE HAL_ES2_TE_SetRxFilterCtrls(BOOL HPFResetReleaseCtrl, BOOL RxActiveCtrl, float32_t HPFResetReleaseDelay, float32_t RxActiveDelay)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    uint32_t tmpActiveDelay;
    uint32_t tmpResetDelay;
    R2M04_RxFilterTimingDelayControlUnion_t RxFilDelayCtrl;
    if ((RxActiveDelay < TE_DELAY_MIN) || (RxActiveDelay > TE_RXACTIVEDELAY_MAX))
    {
        retVal = BC_ERR_TE_RXACTIVEDELAY;
    }
    if ((retVal == BC_ERR_NOERROR) && (((HPFResetReleaseDelay < (RxActiveDelay + 0.125f)) && (RxActiveCtrl == HPFResetReleaseCtrl)) || (HPFResetReleaseDelay > TE_HPFRESETDELAY_MAX)))
    {
        retVal = BC_ERR_TE_HPFRESETDELAY;
    }
    if ((retVal == BC_ERR_NOERROR) && ((RxActiveCtrl == TRUE) && (HPFResetReleaseCtrl == FALSE)))
    {
        retVal = BC_ERR_TE_HPFRESETWRONGTRIGGERPOINT;
    }
    if (retVal == BC_ERR_NOERROR)
    {
        retVal = BC_SPI_Read(e_SYS_TE, R2M04_RX_FILTER_TIMING_DELAY_CONTROL_U16, &RxFilDelayCtrl.val_u32);
        if (BC_ERR_NOERROR == retVal)
        {
            RxFilDelayCtrl.bits_st.RxActiveControl = (uint8_t)RxActiveCtrl;
            RxFilDelayCtrl.bits_st.RxHpfResetControl = (uint8_t)HPFResetReleaseCtrl;

            /* Convert us to 25ns base */
            tmpActiveDelay = (uint32_t)(lroundf(RxActiveDelay * 1000.0f / 25.0f));

            RxFilDelayCtrl.bits_st.RxActiveDelay = (uint8_t)tmpActiveDelay;
            /* Convert us to 25ns base */
            tmpResetDelay = (uint32_t)(lroundf(HPFResetReleaseDelay * 1000.0f / 25.0f));
            RxFilDelayCtrl.bits_st.RxHpfResetDelay = (uint8_t)tmpResetDelay;
            retVal = BC_SPI_WriteCheck(e_SYS_TE, R2M04_RX_FILTER_TIMING_DELAY_CONTROL_U16, RxFilDelayCtrl.val_u32);
        }
    }
    return retVal;
}

BC_ERRCODE HAL_ES2_TE_SetPhaseCtrls(BOOL pEnBPCtrlFromQPSKIO[3], BOOL EnAsyncBPSKSamp, BOOL EnAsyncQPSKSamp, TE_PRPCGenMode_e pFinalPCGenMode[3])
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M04_TxPrChirpControlModesUnion_t PrChirpCtrlModes;

    if ((pEnBPCtrlFromQPSKIO != NULL) && (pFinalPCGenMode != NULL))
    {
        retVal = BC_SPI_Read(e_SYS_TE, R2M04_TX_PR_CHIRP_CONTROL_MODES_U16, &PrChirpCtrlModes.val_u32);
        if (BC_ERR_NOERROR == retVal)
        {
            PrChirpCtrlModes.bits_st.BpskIoAsyncEnable = (uint8_t)EnAsyncBPSKSamp;
            PrChirpCtrlModes.bits_st.QpskIoAsyncEnable = (uint8_t)EnAsyncQPSKSamp;

            PrChirpCtrlModes.bits_st.Tx1PrPhaseBpskControl = (uint8_t)pEnBPCtrlFromQPSKIO[0];
            PrChirpCtrlModes.bits_st.Tx2PrPhaseBpskControl = (uint8_t)pEnBPCtrlFromQPSKIO[1];
            PrChirpCtrlModes.bits_st.Tx3PrPhaseBpskControl = (uint8_t)pEnBPCtrlFromQPSKIO[2];

            /*Final phase code generation related settings - for TX1*/
            switch (pFinalPCGenMode[0])
            {
            case e_TE_PR_NO_CHANGE:
                PrChirpCtrlModes.bits_st.Tx1PrPhaseAddQpskControl = 0u;
                PrChirpCtrlModes.bits_st.Tx1PrPhaseMsbReplaceWithQpskControl = 0u;
                break;

            case e_TE_PR_REPLACE_MSB_WITH_QPSK:
                PrChirpCtrlModes.bits_st.Tx1PrPhaseAddQpskControl = 0u;
                PrChirpCtrlModes.bits_st.Tx1PrPhaseMsbReplaceWithQpskControl = 1u;
                break;

            case e_TE_PR_ADD_QPSK_TO_MSB:
                PrChirpCtrlModes.bits_st.Tx1PrPhaseAddQpskControl = 1u;
                PrChirpCtrlModes.bits_st.Tx1PrPhaseMsbReplaceWithQpskControl = 0u;
                break;

            default:
                retVal = BC_ERR_TE_DDMASETTING;
                break;
            }

            if (BC_ERR_NOERROR == retVal)
            {
                /*Final phase code generation related settings - for TX2*/
                switch (pFinalPCGenMode[1])
                {
                case e_TE_PR_NO_CHANGE:
                    PrChirpCtrlModes.bits_st.Tx2PrPhaseAddQpskControl = 0u;
                    PrChirpCtrlModes.bits_st.Tx2PrPhaseMsbReplaceWithQpskControl = 0u;
                    break;

                case e_TE_PR_REPLACE_MSB_WITH_QPSK:
                    PrChirpCtrlModes.bits_st.Tx2PrPhaseAddQpskControl = 0u;
                    PrChirpCtrlModes.bits_st.Tx2PrPhaseMsbReplaceWithQpskControl = 1u;
                    break;

                case e_TE_PR_ADD_QPSK_TO_MSB:
                    PrChirpCtrlModes.bits_st.Tx2PrPhaseAddQpskControl = 1u;
                    PrChirpCtrlModes.bits_st.Tx2PrPhaseMsbReplaceWithQpskControl = 0u;
                    break;

                default:
                    retVal = BC_ERR_TE_DDMASETTING;
                    break;
                }
            }

            if (BC_ERR_NOERROR == retVal)
            {
                /*Final phase code generation related settings - for TX3 */
                switch (pFinalPCGenMode[2])
                {
                case e_TE_PR_NO_CHANGE:
                    PrChirpCtrlModes.bits_st.Tx3PrPhaseAddQpskControl = 0u;
                    PrChirpCtrlModes.bits_st.Tx3PrPhaseMsbReplaceWithQpskControl = 0u;
                    break;

                case e_TE_PR_REPLACE_MSB_WITH_QPSK:
                    PrChirpCtrlModes.bits_st.Tx3PrPhaseAddQpskControl = 0u;
                    PrChirpCtrlModes.bits_st.Tx3PrPhaseMsbReplaceWithQpskControl = 1u;
                    break;

                case e_TE_PR_ADD_QPSK_TO_MSB:
                    PrChirpCtrlModes.bits_st.Tx3PrPhaseAddQpskControl = 1u;
                    PrChirpCtrlModes.bits_st.Tx3PrPhaseMsbReplaceWithQpskControl = 0u;
                    break;

                default:
                    retVal = BC_ERR_TE_DDMASETTING;
                    break;
                }
            }

            if (BC_ERR_NOERROR == retVal)
            {
                retVal = BC_SPI_WriteCheck(e_SYS_TE, R2M04_TX_PR_CHIRP_CONTROL_MODES_U16, PrChirpCtrlModes.val_u32);
            }
        }
    }
    else
    {
        retVal = BC_ERR_TE_INPUTNULL;
    }
    return retVal;
}

BC_ERRCODE HAL_ES2_TE_LoadProfile(SYS_ProfID_e ChirpProfSel)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M04_ChirpGlobalControlUnion_t ChirpGlblCtrl;
    BOOL ToggleBitFlag = TRUE;

    /* Use chirp_enable as the trigger of loading profiles. 0-1-0 for loading */
    /* In case in chirp_enable is already = 0 we set 1 to save one SPI write, 1-0 */
    retVal = BC_SPI_Read(e_SYS_TE, R2M04_CHIRP_GLOBAL_CONTROL_U16, &ChirpGlblCtrl.val_u32);
    if (BC_ERR_NOERROR == retVal)
    {
        if (ChirpGlblCtrl.bits_st.ChirpEnable == 1u)
        {
            ChirpGlblCtrl.bits_st.ChirpEnable = (uint8_t)FALSE;
            ToggleBitFlag = TRUE;
        }
        else
        {
            ChirpGlblCtrl.bits_st.ChirpEnable = (uint8_t)TRUE;
            ToggleBitFlag = FALSE;
        }
        switch (ChirpProfSel)
        {
        case e_SYS_PROFILE_0:              /*0x00u*/
        case e_SYS_PROFILE_1:              /*0x01u*/
        case e_SYS_PROFILE_2:              /*0x02u*/
        case e_SYS_PROFILE_3:              /*0x03u*/
        case e_SYS_PROFILE_4:              /*0x04u*/
        case e_SYS_PROFILE_5:              /*0x05u*/
        case e_SYS_PROFILE_6:              /*0x06u*/
        case e_SYS_PROFILE_7:              /*0x07u*/
        case e_SYS_PROFILE_8:              /*0x08u*/
        case e_SYS_PROFILES_0_TO_1:        /*0x09u*/
        case e_SYS_PROFILES_0_TO_2:        /*0x0Au*/
        case e_SYS_PROFILES_0_TO_3:        /*0x0Bu*/
        case e_SYS_PROFILES_0_TO_4:        /*0x0Cu*/
        case e_SYS_PROFILES_0_TO_5:        /*0x0Du*/
        case e_SYS_PROFILES_0_TO_6:        /*0x0Eu*/
        case e_SYS_PROFILES_0_TO_7:        /*0x0Fu*/
        case e_SYS_PROFILE_PSRB: /*0x1Eu*/ /*Seed remains default*/
        case e_SYS_PROFILE_LIST:           /*0x1Fu*/
        {
            ChirpGlblCtrl.bits_st.ChirpProfileSelect = (uint8_t)ChirpProfSel;
            retVal = BC_SPI_Write(e_SYS_TE, R2M04_CHIRP_GLOBAL_CONTROL_U16, ChirpGlblCtrl.val_u32);
            break;
        }
        default:
        {
            retVal = BC_ERR_TE_PROFILELIST;
        }
        break;
        }
    }
    if (BC_ERR_NOERROR == retVal)
    {
        ChirpGlblCtrl.bits_st.ChirpEnable = (uint8_t)ToggleBitFlag;
        retVal = BC_SPI_Write(e_SYS_TE, R2M04_CHIRP_GLOBAL_CONTROL_U16, ChirpGlblCtrl.val_u32);
        if ((BC_ERR_NOERROR == retVal) && (ToggleBitFlag == TRUE))
        {
            ChirpGlblCtrl.bits_st.ChirpEnable = (uint8_t)FALSE;
            retVal = BC_SPI_Write(e_SYS_TE, R2M04_CHIRP_GLOBAL_CONTROL_U16, ChirpGlblCtrl.val_u32);
        }
    }
    return retVal;
}

BC_ERRCODE HAL_ES2_TE_WaitForReady(void)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    uint32_t WhileLoopCount = 0u;
    R2M04_ChirpGlobalControlUnion_t GlobalCtrl;
    GlobalCtrl.val_u32 = 0u;
    
    /*Polling method */
    do
    {
        retVal = PLF_TM_Sleep(TE_WAITFORREADY_SLEEP);
        if (retVal == BC_ERR_NOERROR)
        {
            retVal = BC_SPI_Read(e_SYS_TE, R2M04_CHIRP_GLOBAL_CONTROL_U16, &GlobalCtrl.val_u32);
        }
        if (BC_ERR_NOERROR == retVal)
        {
            if (WhileLoopCount >= TE_WAITFORREADY_TIMEOUT)
            {
                retVal = BC_ERR_TE_FREQCNTTIMEOUT;
            }
            else
            {
                WhileLoopCount++;
            }
        }
    } while ((GlobalCtrl.bits_st.ChirpStart == 0x01u) && (retVal == BC_ERR_NOERROR));

    return retVal;
}

static BC_ERRCODE Helper_ES2_SetCtrl1Reg(SYS_ProfID_e ProfileNum, float32_t DwellTime, uint32_t TxOnDelayFromRefPoint, BOOL TrigPoint, BOOL pBPPhaseCtrlTx[3], BOOL pEnTx[3])
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M04_TimingControl1Profile0Union_t Ctr1ProfX;
    uint16_t CtrlReg1Addr;
    uint32_t tmpDwellTime;

    tmpDwellTime = (uint32_t)lroundf(DwellTime * 1000.0f / 25.0f);

    /*Dwell time - allowed values: 0x002 to 0xFFE*/
    if ((tmpDwellTime <= 0x001u) || (tmpDwellTime >= 0xFFFu))
    {
        retVal = BC_ERR_TE_DWELLTIME;
    }
    /*
    tx_bps_and_transmission_en_time_profileX:
    Allowed values 0x002 to Tdwell or Tsettle  ( depends on the enable point)
    Useful values :  less than or equal to Tdwell incase of control point is Tdwell or
    less than safety_monitor_delay incase of control point is Tsettle
    */
    if ((BC_ERR_NOERROR == retVal) && ((TrigPoint == FALSE) && (TxOnDelayFromRefPoint >= tmpDwellTime))) /*Trigger point is start of Tdwell*/
    {
        retVal = BC_ERR_TE_DELAYFROMREFPT;
    }
    if ((BC_ERR_NOERROR == retVal) && (ProfileNum > e_SYS_PROFILE_8))
    {
        retVal = BC_ERR_TE_PROFILELIST;
    }
    if (BC_ERR_NOERROR == retVal)
    {
        CtrlReg1Addr = R2M04_TIMING_CONTROL_1_PROFILE0_U16 + (((uint16_t)ProfileNum - (uint16_t)e_SYS_PROFILE_0) * (R2M04_TIMING_CONTROL_1_PROFILE1_U16 - R2M04_TIMING_CONTROL_1_PROFILE0_U16));
        retVal = BC_SPI_Read(e_SYS_TE, CtrlReg1Addr, &Ctr1ProfX.val_u32);
        if (BC_ERR_NOERROR == retVal)
        {
            Ctr1ProfX.bits_st.TxBpsControlAndTxEnTimeProfile0 = (uint8_t)TrigPoint;
            Ctr1ProfX.bits_st.Tx1BinaryPhaseControlProfile0 = (uint8_t)pBPPhaseCtrlTx[0];
            Ctr1ProfX.bits_st.Tx2BinaryPhaseControlProfile0 = (uint8_t)pBPPhaseCtrlTx[1];
            Ctr1ProfX.bits_st.Tx3BinaryPhaseControlProfile0 = (uint8_t)pBPPhaseCtrlTx[2];
            Ctr1ProfX.bits_st.Tx1TransmissionEnableProfile0 = (uint8_t)pEnTx[0];
            Ctr1ProfX.bits_st.Tx2TransmissionEnableProfile0 = (uint8_t)pEnTx[1];
            Ctr1ProfX.bits_st.Tx3TransmissionEnableProfile0 = (uint8_t)pEnTx[2];
            Ctr1ProfX.bits_st.DwellTimeProfile0 = (uint16_t)tmpDwellTime;
            Ctr1ProfX.bits_st.TxBpsAndTransmissionEnTimeProfile0 = (uint16_t)TxOnDelayFromRefPoint;
            retVal = BC_SPI_WriteCheck(e_SYS_TE, CtrlReg1Addr, Ctr1ProfX.val_u32);
        }
    }

    return retVal;
}

BC_ERRCODE HAL_ES2_TE_UpdateProfTiming(SYS_ProfID_e ProfileNum, float32_t DwellTime, float32_t TxOnDelayFromRefPoint, BOOL TrigPoint, BOOL pBPPhaseCtrlTx[3], BOOL pEnTx[3])
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;

    /* Note that though the following variable has Profile0 in it name.
       As all the 0-8 profiles' control registers are of same type,
       can use the same for all profiles*/

    R2M04_DcPowerOnDelayControlUnion_t DCPowOnDelyCtrl;
    uint32_t tmpTxOnDelayFromRefPoint;
    if ((pBPPhaseCtrlTx == NULL) || (pEnTx == NULL))
    {
        retVal = BC_ERR_TE_INPUTNULL;
    }

    if ((BC_ERR_NOERROR == retVal) && (TrigPoint == TRUE))
    {
        retVal = BC_SPI_Read(e_SYS_TE, R2M04_DC_POWER_ON_DELAY_CONTROL_U16, &DCPowOnDelyCtrl.val_u32);
    }

    if (BC_ERR_NOERROR == retVal)
    {
        tmpTxOnDelayFromRefPoint = (uint32_t)lroundf(TxOnDelayFromRefPoint * 1000.0f / 25.0f);
        /*
        tx_bps_and_transmission_en_time_profileX:
        Allowed values 0x002 to Tdwell or Tsettle  ( depends on the enable point)
        Useful values :  less than or equal to Tdwell incase of control point is Tdwell or
        less than safety_monitor_delay incase of control point is Tsettle
        */
        if ((tmpTxOnDelayFromRefPoint < 2u) ||
            (((TrigPoint == TRUE) && (tmpTxOnDelayFromRefPoint >= DCPowOnDelyCtrl.bits_st.SafetyMonitorDelay) && (DCPowOnDelyCtrl.bits_st.SafetyMonitorDelayStartControl == FALSE)))) /*Trigger point is start of Tsettle*/
        {
            retVal = BC_ERR_TE_DELAYFROMREFPT;
        }
        if (BC_ERR_NOERROR == retVal)
        {
            retVal = Helper_ES2_SetCtrl1Reg(ProfileNum, DwellTime, tmpTxOnDelayFromRefPoint, TrigPoint, pBPPhaseCtrlTx, pEnTx);
        }
    }
    return retVal;
}

BC_ERRCODE HAL_ES2_TE_UpdateProfADC(SYS_ProfID_e ProfileNum, BOOL PDCBWWide, uint16_t NumSamples, float32_t SettleTime, TE_OutputSampRate_e OutSampRate)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;

    /* Note that though the following variables types have Profile0 in their names,
    as all the 0-8 profiles' control registers are of same type, can use the same
    all profiles*/
    R2M04_TimingControl2Profile0Union_t Ctr2ProfX;
    uint16_t CtrlReg2Addr;
    uint32_t tmpSettleTime;

    if (ProfileNum > e_SYS_PROFILE_8)
    {
        retVal = BC_ERR_TE_PROFILELIST;
    }
    if (BC_ERR_NOERROR == retVal)
    {
        CtrlReg2Addr = R2M04_TIMING_CONTROL_2_PROFILE0_U16 + (((uint16_t)ProfileNum - (uint16_t)e_SYS_PROFILE_0) * (R2M04_TIMING_CONTROL_2_PROFILE1_U16 - R2M04_TIMING_CONTROL_2_PROFILE0_U16));
        retVal = BC_SPI_Read(e_SYS_TE, CtrlReg2Addr, &Ctr2ProfX.val_u32);
    }

    if (BC_ERR_NOERROR == retVal)
    {
        tmpSettleTime = (uint32_t)lroundf(SettleTime * 1000.0f / 25.0f);
        /*2. Allowed values 0x001 to 0xFFE*/
        if (!((tmpSettleTime >= 1u) && (tmpSettleTime < 0xFFFu)))
        {
            retVal = BC_ERR_TE_SETTLETIME;
        }
        if (BC_ERR_NOERROR == retVal)
        {
            if ((OutSampRate >= e_TE_OSR_INVALID))
            {
                retVal = BC_ERR_TE_OUTPUTSAMPRATE;
            }
        }

        if (BC_ERR_NOERROR == retVal)
        {
            Ctr2ProfX.bits_st.PdcBwSelProfile0 = (uint8_t)PDCBWWide;
            Ctr2ProfX.bits_st.SettleTimeProfile0 = (uint16_t)tmpSettleTime;
            Ctr2ProfX.bits_st.OutputSampleRateProfile0 = (uint8_t)OutSampRate;

            /* Note This is acctual Raw sample available during the acquisition at 40MSPS */
            Ctr2ProfX.bits_st.AcquisitionDurationProfile0 = NumSamples;
            /*Note: As all the 32-bits are getting updated, no need for initial read; instead directly writing is OK */
            retVal = BC_SPI_WriteCheck(e_SYS_TE, CtrlReg2Addr, Ctr2ProfX.val_u32);
        }
    }
    return retVal;
}

BC_ERRCODE HAL_ES2_TE_UpdateProfChirpPeriod(SYS_ProfID_e ProfileNum, float32_t ChirpPeriod, BOOL pActiveRx[4], BOOL pActiveTx[3])
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    /* Note that though the following variables types have Profile0 in their names,
    as all the 0-8 profiles' control registers are of same type, can use the same for all profiles*/
    R2M04_TimingControl3Profile0Union_t Ctr3ProfX;

    uint16_t CtrlReg3Addr;
    uint32_t tmpChirpPeriod;

    if ((pActiveRx == NULL) || (pActiveTx == NULL))
    {
        retVal = BC_ERR_TE_INPUTNULL;
    }
    if ((BC_ERR_NOERROR == retVal) && (ProfileNum > e_SYS_PROFILE_8))
    {
        retVal = BC_ERR_TE_PROFILELIST;
    }
    if (BC_ERR_NOERROR == retVal)
    {
        /*Converting to 25ns base*/
        tmpChirpPeriod = (uint32_t)lroundf(ChirpPeriod * 1000.0f / 25.0f);
        /* It should be of 22 bits */
        if (tmpChirpPeriod > 0x3FFFFFu)
        {
            retVal = BC_ERR_TE_CHIRPINTERVAL;
        }
        if (BC_ERR_NOERROR == retVal)
        {
            CtrlReg3Addr = R2M04_TIMING_CONTROL_3_PROFILE0_U16 + (((uint16_t)ProfileNum - (uint16_t)e_SYS_PROFILE_0) * (R2M04_TIMING_CONTROL_3_PROFILE1_U16 - R2M04_TIMING_CONTROL_3_PROFILE0_U16));
            retVal = BC_SPI_Read(e_SYS_TE, CtrlReg3Addr, &Ctr3ProfX.val_u32);
            if (BC_ERR_NOERROR == retVal)
            {
                Ctr3ProfX.bits_st.Rx1ActiveProfile0 = (uint8_t)pActiveRx[0];
                Ctr3ProfX.bits_st.Rx2ActiveProfile0 = (uint8_t)pActiveRx[1];
                Ctr3ProfX.bits_st.Rx3ActiveProfile0 = (uint8_t)pActiveRx[2];
                Ctr3ProfX.bits_st.Rx4ActiveProfile0 = (uint8_t)pActiveRx[3];
                Ctr3ProfX.bits_st.Tx1ActiveProfile0 = (uint8_t)pActiveTx[0];
                Ctr3ProfX.bits_st.Tx2ActiveProfile0 = (uint8_t)pActiveTx[1];
                Ctr3ProfX.bits_st.Tx3ActiveProfile0 = (uint8_t)pActiveTx[2];
                Ctr3ProfX.bits_st.ChirpIntervalTimerProfile0 = tmpChirpPeriod;
                retVal = BC_SPI_WriteCheck(e_SYS_TE, CtrlReg3Addr, Ctr3ProfX.val_u32);
            }
        }
    }
    return retVal;
}

BC_ERRCODE HAL_ES2_TE_UpdateProfPRCtrl(SYS_ProfID_e ProfileNum, float32_t pPRPhaseCtrlTx[3], SYS_VCN_e VirtualChNo)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;

    /* Note that though the following variables types have Profile0 in their names,
    as all the 0-8 profiles' control registers are of same type, can use the same for all profiles*/
    R2M04_TimingControl4Profile0Union_t Ctr4ProfX;
    uint16_t CtrlReg4Addr;
    uint32_t tmpPRPhaseCtrlTx1;
    uint32_t tmpPRPhaseCtrlTx2;
    uint32_t tmpPRPhaseCtrlTx3;

    if (pPRPhaseCtrlTx == NULL)
    {
        retVal = BC_ERR_TE_INPUTNULL;
    }
    if ((BC_ERR_NOERROR == retVal) && (ProfileNum > e_SYS_PROFILE_8))
    {
        retVal = BC_ERR_TE_PROFILELIST;
    }
    if (BC_ERR_NOERROR == retVal)
    {
        CtrlReg4Addr = R2M04_TIMING_CONTROL_4_PROFILE0_U16 + (((uint16_t)ProfileNum - (uint16_t)e_SYS_PROFILE_0) * (R2M04_TIMING_CONTROL_4_PROFILE1_U16 - R2M04_TIMING_CONTROL_4_PROFILE0_U16));

        retVal = BC_SPI_Read(e_SYS_TE, CtrlReg4Addr, &Ctr4ProfX.val_u32);
        if (BC_ERR_NOERROR == retVal)
        {
            if (VirtualChNo < e_SYS_VCN_INVALID)
            {
                Ctr4ProfX.bits_st.VirtualChannelProfile0 = (uint8_t)VirtualChNo;
                tmpPRPhaseCtrlTx1 = (uint32_t)lroundf((64.0f * pPRPhaseCtrlTx[0]) / 360.0f);
                tmpPRPhaseCtrlTx2 = (uint32_t)lroundf((64.0f * pPRPhaseCtrlTx[1]) / 360.0f);
                tmpPRPhaseCtrlTx3 = (uint32_t)lroundf((64.0f * pPRPhaseCtrlTx[2]) / 360.0f);
                Ctr4ProfX.bits_st.Tx1PrPhaseControlProfile0 = (uint8_t)(tmpPRPhaseCtrlTx1 & 0x3Fu);
                Ctr4ProfX.bits_st.Tx2PrPhaseControlProfile0 = (uint8_t)(tmpPRPhaseCtrlTx2 & 0x3Fu);
                Ctr4ProfX.bits_st.Tx3PrPhaseControlProfile0 = (uint8_t)(tmpPRPhaseCtrlTx3 & 0x3Fu);
                retVal = BC_SPI_WriteCheck(e_SYS_TE, CtrlReg4Addr, Ctr4ProfX.val_u32);
            }
            else
            {
                retVal = BC_ERR_TE_VIRTUALCHANNEL;
            }
        }
    }

    return retVal;
}

BC_ERRCODE HAL_ES2_TE_ConfigProfile(TE_ConfigProfile_t *pConfigProfile)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    BOOL BPPhaseCtrlTx[3];
    BOOL EnTx[3];
    BOOL ActiveRx[4];
    BOOL ActiveTx[3];
    float32_t PRPhaseCtrlTx[3];

    /*Note: The following condition check on timing parameters:
      ChirpPeriod  >= (Tdwell + Tsettle + Tactive + Tjumpback + Treset)
      will be done in SYS API as that will have access to all the these parameters */

    if (pConfigProfile != NULL)
    {
        BPPhaseCtrlTx[0] = pConfigProfile->BPPhaseCtrlTx1;
        BPPhaseCtrlTx[1] = pConfigProfile->BPPhaseCtrlTx2;
        BPPhaseCtrlTx[2] = pConfigProfile->BPPhaseCtrlTx3;
        EnTx[0] = pConfigProfile->EnTx1;
        EnTx[1] = pConfigProfile->EnTx2;
        EnTx[2] = pConfigProfile->EnTx3;
        retVal = HAL_ES2_TE_UpdateProfTiming(pConfigProfile->ProfileNum, pConfigProfile->DwellTime, pConfigProfile->TxOnDelayFromRefPoint, pConfigProfile->TrigPoint, BPPhaseCtrlTx, EnTx);

        if (retVal == BC_ERR_NOERROR)
        {
            retVal = HAL_ES2_TE_UpdateProfADC(pConfigProfile->ProfileNum, pConfigProfile->PDCBWWide, pConfigProfile->NumSamples, pConfigProfile->SettleTime, pConfigProfile->OutSampRate);
        }

        if (retVal == BC_ERR_NOERROR)
        {
            ActiveRx[0] = pConfigProfile->ActiveRx1;
            ActiveRx[1] = pConfigProfile->ActiveRx2;
            ActiveRx[2] = pConfigProfile->ActiveRx3;
            ActiveRx[3] = pConfigProfile->ActiveRx4;
            ActiveTx[0] = pConfigProfile->ActiveTx1;
            ActiveTx[1] = pConfigProfile->ActiveTx2;
            ActiveTx[2] = pConfigProfile->ActiveTx3;
            retVal = HAL_ES2_TE_UpdateProfChirpPeriod(pConfigProfile->ProfileNum, pConfigProfile->ChirpPeriod, ActiveRx, ActiveTx);
        }

        if (retVal == BC_ERR_NOERROR)
        {
            PRPhaseCtrlTx[0] = pConfigProfile->PRPhaseCtrlTx1;
            PRPhaseCtrlTx[1] = pConfigProfile->PRPhaseCtrlTx2;
            PRPhaseCtrlTx[2] = pConfigProfile->PRPhaseCtrlTx3;
            retVal = HAL_ES2_TE_UpdateProfPRCtrl(pConfigProfile->ProfileNum, PRPhaseCtrlTx, pConfigProfile->VirtualChNo);
        }
    }
    else
    {
        retVal = BC_ERR_TE_INPUTNULL;
    }

    return retVal;
}

BC_ERRCODE HAL_ES2_TE_ConfigStatic(TE_StaticConfig_t *pStaticConfig)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;

    float32_t GDelayFineControl[4];

    if (pStaticConfig != NULL)
    {
        retVal = HAL_ES2_TE_SetDCPowOnDelay(pStaticConfig->DCPowerOnDelay, pStaticConfig->SafetyMontrDelay, pStaticConfig->SafetyMontrActCtrl);

        if (BC_ERR_NOERROR == retVal)
        {
            GDelayFineControl[0] = pStaticConfig->GDelayFineControl1;
            GDelayFineControl[1] = pStaticConfig->GDelayFineControl2;
            GDelayFineControl[2] = pStaticConfig->GDelayFineControl3;
            GDelayFineControl[3] = pStaticConfig->GDelayFineControl4;
            retVal = HAL_ES2_TE_ConfigTXRXDCGrpDelay(pStaticConfig->TXGroupDelay, pStaticConfig->RXGroupDelay, GDelayFineControl);
        }

        if (BC_ERR_NOERROR == retVal)
        {
            retVal = HAL_ES2_TE_SetJumpBackTime(pStaticConfig->JumpBackTime);
        }

        if (BC_ERR_NOERROR == retVal)
        {
            retVal = HAL_ES2_TE_SetChirpSeqInterval(pStaticConfig->SeqInterval);
        }
        // reset value EnFastBiasSwitch nad EnReplicaBiasBypass = 1,
        // reset value of FastBiasSwitchDelay is also correct = 6micro second, if  ReplicaBiasBypassDelay need to be chanegd call the HAL_ES2_TE_SetBiasSwitchCtrl API

        if (BC_ERR_NOERROR == retVal)
        {
            retVal = HAL_ES2_TE_SetChirpSeqCtrl(pStaticConfig->NumSeqInBurst, pStaticConfig->NumChirpInSeq);
        }
    }
    else
    {
        retVal = BC_ERR_TE_INPUTNULL;
    }
    return retVal;
}

BC_ERRCODE HAL_ES2_TE_ConfigProfileSequencing(SYS_ProfID_e ChirpProfSel, uint8_t pProfileList[8], uint8_t ProfileRepeatCount, BOOL EnProfileReset, BOOL EnChirp, uint16_t PRSeed)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M04_ChirpProfilePseudoRandomControlUnion_t ChirpPSRBCtrl;
    R2M04_ChirpGlobalControlUnion_t ChirpGlblCtrl;
    R2M04_ChirpProfileListUnion_t ChirpProfCtrl;

    retVal = BC_SPI_Read(e_SYS_TE, R2M04_CHIRP_GLOBAL_CONTROL_U16, &ChirpGlblCtrl.val_u32);
    if (BC_ERR_NOERROR == retVal)
    {
        if (ChirpProfSel < e_SYS_PROFILE_INVALID)
        {
            ChirpGlblCtrl.bits_st.ChirpProfileSelect = (uint8_t)ChirpProfSel;
        }
        else
        {
            retVal = BC_ERR_TE_PROFILELIST;
        }

        if (ChirpProfSel == e_SYS_PROFILE_PSRB)
        {
            retVal = BC_SPI_Read(e_SYS_TE, R2M04_CHIRP_PROFILE_PSEUDO_RANDOM_CONTROL_U16, &ChirpPSRBCtrl.val_u32);
            if (BC_ERR_NOERROR == retVal)
            {
                ChirpPSRBCtrl.bits_st.ProfilePseudoRandomSeed = PRSeed;
                retVal = BC_SPI_WriteCheck(e_SYS_TE, R2M04_CHIRP_PROFILE_PSEUDO_RANDOM_CONTROL_U16, ChirpPSRBCtrl.val_u32);
            }
        }
        if (ChirpProfSel == e_SYS_PROFILE_LIST)
        {
            if (pProfileList != NULL)
            {
                retVal = BC_SPI_Read(e_SYS_TE, R2M04_CHIRP_PROFILE_LIST_U16, &ChirpProfCtrl.val_u32);
                if (BC_ERR_NOERROR == retVal)
                {
                    /* Note: if profile list value is other than 0-7, then no profile will be selected for that entry */
                    /* So, No check on profile list entry and hence no error code is introduced for the same.*/
                    ChirpProfCtrl.bits_st.ProfileListEntry0 = (pProfileList[0] > 0x07u) ? 0x0Fu : pProfileList[0];
                    ChirpProfCtrl.bits_st.ProfileListEntry1 = (pProfileList[1] > 0x07u) ? 0x0Fu : pProfileList[1];
                    ChirpProfCtrl.bits_st.ProfileListEntry2 = (pProfileList[2] > 0x07u) ? 0x0Fu : pProfileList[2];
                    ChirpProfCtrl.bits_st.ProfileListEntry3 = (pProfileList[3] > 0x07u) ? 0x0Fu : pProfileList[3];
                    ChirpProfCtrl.bits_st.ProfileListEntry4 = (pProfileList[4] > 0x07u) ? 0x0Fu : pProfileList[4];
                    ChirpProfCtrl.bits_st.ProfileListEntry5 = (pProfileList[5] > 0x07u) ? 0x0Fu : pProfileList[5];
                    ChirpProfCtrl.bits_st.ProfileListEntry6 = (pProfileList[6] > 0x07u) ? 0x0Fu : pProfileList[6];
                    ChirpProfCtrl.bits_st.ProfileListEntry7 = (pProfileList[7] > 0x07u) ? 0x0Fu : pProfileList[7];
                    retVal = BC_SPI_WriteCheck(e_SYS_TE, R2M04_CHIRP_PROFILE_LIST_U16, ChirpProfCtrl.val_u32);
                }
            }
            else
            {
                retVal = BC_ERR_TE_INPUTNULL;
            }
        }

        if ((ProfileRepeatCount > 0x0u) && (ProfileRepeatCount < 0x80u))
        {
            ChirpGlblCtrl.bits_st.ProfileRepeatCountVal = ProfileRepeatCount;
        }
        else
        {
            retVal = BC_ERR_TE_PRFREPEATCNT;
        }

        if (BC_ERR_NOERROR == retVal)
        {
            ChirpGlblCtrl.bits_st.ChirpEnable = (uint8_t)EnChirp;
            ChirpGlblCtrl.bits_st.EnableProfileReset = (uint8_t)EnProfileReset;
            retVal = BC_SPI_Write(e_SYS_TE, R2M04_CHIRP_GLOBAL_CONTROL_U16, ChirpGlblCtrl.val_u32);
        }
    }
    return retVal;
}

BC_ERRCODE HAL_ES2_TE_ConfigTXRXDCGrpDelay(float32_t TXDCPowOnGrpDelay, float32_t RXDCPowOnGrpDelay, float32_t pFineControl[4])
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    uint32_t tmpTxDCPOnGrpDelay;
    uint32_t tmpRxDCPOnGrpDelay;
    uint32_t tmpTxRxFineControl[4];

    R2M04_DcPowerOnDelayControlUnion_t DCPowOnDelyCtrl;
    R2M04_TxDcPowerOnGroupDelayControlUnion_t TxGrpDelay;
    R2M04_RxDcPowerOnGroupDelayControlUnion_t RxGrpDelay;
    R2M04_TxRxDcPowerOnDelayFineControlUnion_t TxRxFineCtrl;
    if (pFineControl == NULL)
    {
        retVal = BC_ERR_TE_INPUTNULL;
    }

    if ((BC_ERR_NOERROR == retVal) && ((TXDCPowOnGrpDelay >= 0.025f) && (RXDCPowOnGrpDelay >= 0.025f)))
    {
        retVal = BC_SPI_Read(e_SYS_TE, R2M04_DC_POWER_ON_DELAY_CONTROL_U16, &DCPowOnDelyCtrl.val_u32);
        if (BC_ERR_NOERROR == retVal)
        {
            /* Convert us to 25ns base */
            tmpTxDCPOnGrpDelay = (uint32_t)(lroundf(TXDCPowOnGrpDelay * 1000.0f / 25.0f));
            tmpRxDCPOnGrpDelay = (uint32_t)(lroundf(RXDCPowOnGrpDelay * 1000.0f / 25.0f));

            /*Checking whether these group delays are individually non-zero and lesser than DC power on delay or not*/
            if (!((tmpTxDCPOnGrpDelay < (uint32_t)DCPowOnDelyCtrl.bits_st.DcPoweronDelay) &&
                  (tmpRxDCPOnGrpDelay < (uint32_t)DCPowOnDelyCtrl.bits_st.DcPoweronDelay)))
            {
                retVal = BC_ERR_TE_TXRXGRPDELAY; /*Either TX or RX group delay is greater than DC power on delay */
            }
        }

        if (BC_ERR_NOERROR == retVal)
        {
            /*Tx group delay related*/
            retVal = BC_SPI_Read(e_SYS_TE, R2M04_TX_DC_POWER_ON_GROUP_DELAY_CONTROL_U16, &TxGrpDelay.val_u32);
            if (BC_ERR_NOERROR == retVal)
            {
                TxGrpDelay.bits_st.TxGroupDelayFromChirpStart = (uint16_t)tmpTxDCPOnGrpDelay;
                retVal = BC_SPI_WriteCheck(e_SYS_TE, R2M04_TX_DC_POWER_ON_GROUP_DELAY_CONTROL_U16, TxGrpDelay.val_u32);
            }
        }

        /* Rx group delay related */
        if (BC_ERR_NOERROR == retVal)
        {
            retVal = BC_SPI_Read(e_SYS_TE, R2M04_RX_DC_POWER_ON_GROUP_DELAY_CONTROL_U16, &RxGrpDelay.val_u32);
            if (BC_ERR_NOERROR == retVal)
            {
                RxGrpDelay.bits_st.RxGroupDelayFromChirpStart = (uint16_t)tmpRxDCPOnGrpDelay;
                retVal = BC_SPI_WriteCheck(e_SYS_TE, R2M04_RX_DC_POWER_ON_GROUP_DELAY_CONTROL_U16, RxGrpDelay.val_u32);
            }
        }

        if (BC_ERR_NOERROR == retVal)
        {
            /*Read modified write is not needed, since all bits are modified.*/
            /* Convert us to 25ns base */
            tmpTxRxFineControl[0] = (uint32_t)(lroundf(pFineControl[0] * 1000.0f / 25.0f));
            tmpTxRxFineControl[1] = (uint32_t)(lroundf(pFineControl[1] * 1000.0f / 25.0f));
            tmpTxRxFineControl[2] = (uint32_t)(lroundf(pFineControl[2] * 1000.0f / 25.0f));
            tmpTxRxFineControl[3] = (uint32_t)(lroundf(pFineControl[3] * 1000.0f / 25.0f));

            if ((tmpTxRxFineControl[0] < 0x100u) && (tmpTxRxFineControl[1] < 0x100u) &&
                (tmpTxRxFineControl[2] < 0x100u) && (tmpTxRxFineControl[3] < 0x100u))
            {

                TxRxFineCtrl.bits_st.TxRxDcPowerOnDelayFineControlSet = ((tmpTxRxFineControl[0]) |
                                                                         (tmpTxRxFineControl[1] << 8u) |
                                                                         (tmpTxRxFineControl[2] << 16u) |
                                                                         (tmpTxRxFineControl[3] << 24u));
                retVal = BC_SPI_WriteCheck(e_SYS_TE, R2M04_TX_RX_DC_POWER_ON_DELAY_FINE_CONTROL_U16, TxRxFineCtrl.val_u32);
            }
            else
            {
                retVal = BC_ERR_TE_FINEGRPDELAY;
            }
        }
    }
    else
    {
        if (BC_ERR_NOERROR == retVal)
        {
            retVal = BC_ERR_TE_TXRXGRPDELAY;
        }
    }
    return retVal;
}
BC_ERRCODE HAL_ES2_TE_SetJumpBackTime(float32_t JumpBackTime)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M04_JumpbackPeriodControlUnion_t JumpBackPeriod;
    uint32_t tmpJumpBack;

    /*Reading the register*/
    retVal = BC_SPI_Read(e_SYS_TE, R2M04_JUMPBACK_PERIOD_CONTROL_U16, &JumpBackPeriod.val_u32);
    if (BC_ERR_NOERROR == retVal)
    {
        /* Convert us to 25ns base */
        tmpJumpBack = (uint32_t)(lroundf(JumpBackTime * 1000.0f / 25.0f));

        /*Allowed values: 0x01 to 0xFE */
        if ((tmpJumpBack >= 1u) && (tmpJumpBack < 0xFFu))
        {
            JumpBackPeriod.bits_st.JumpBackTime = (uint8_t)tmpJumpBack;
            /* Writing back to the register */
            retVal = BC_SPI_WriteCheck(e_SYS_TE, R2M04_JUMPBACK_PERIOD_CONTROL_U16, JumpBackPeriod.val_u32);
        }
        else
        {
            retVal = BC_ERR_TE_JUMPBACK;
        }
    }
    return retVal;
}

BC_ERRCODE HAL_ES2_TE_SetDCPowOnDelay(float32_t DCPowerOnDelay, float32_t SafetyMontrDelay, BOOL SafetyMontrActCtrl)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M04_DcPowerOnDelayControlUnion_t DCPowOnDelyCtrl;
    uint32_t tmpSafetyDelay, tmpPowerOnDelay;
    /**Minimum allowed Power on Delay is 10us*/
    if ((DCPowerOnDelay < TE_DCPOWERONDELAY_MIN) || (DCPowerOnDelay > TE_DCPOWERONDELAY_MAX))
    {
        retVal = BC_ERR_TE_DCPOWONDELAY;
    }
    if ((retVal == BC_ERR_NOERROR) && ((SafetyMontrDelay < 0.0f) || ((SafetyMontrDelay < TE_DELAY_MIN) && (SafetyMontrActCtrl == FALSE)) || (SafetyMontrDelay > TE_SAFETYMONDELAY_MAX)))
    {
        retVal = BC_ERR_TE_DCSAFETYDELAY;
    }

    if (retVal == BC_ERR_NOERROR)
    {
        retVal = BC_SPI_Read(e_SYS_TE, R2M04_DC_POWER_ON_DELAY_CONTROL_U16, &DCPowOnDelyCtrl.val_u32);
        if (BC_ERR_NOERROR == retVal)
        {
            DCPowOnDelyCtrl.bits_st.SafetyMonitorDelayStartControl = (uint8_t)SafetyMontrActCtrl;

            /* Convert us to 25ns base */
            tmpSafetyDelay = (uint32_t)(lroundf(SafetyMontrDelay * 1000.0f / 25.0f));

            /* Safety monitor delay value should be less than 0xFFF*/
            DCPowOnDelyCtrl.bits_st.SafetyMonitorDelay = (uint16_t)tmpSafetyDelay;
            /* Convert us to 25ns base */
            tmpPowerOnDelay = (uint32_t)(lroundf(DCPowerOnDelay * 1000.0f / 25.0f));
            DCPowOnDelyCtrl.bits_st.DcPoweronDelay = (uint16_t)tmpPowerOnDelay;
            /*Writing back the values*/
            retVal = BC_SPI_WriteCheck(e_SYS_TE, R2M04_DC_POWER_ON_DELAY_CONTROL_U16, DCPowOnDelyCtrl.val_u32);
            /*Note At this stage no need to check the retVal*/
        }
    }
    return retVal;
}

BC_ERRCODE HAL_ES2_TE_SetChirpSeqCtrl(uint32_t NumSeqInBurst, uint16_t NumChirpInSeq)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M04_ChirpSequenceControlUnion_t ChirpSeqCtrl;
    R2M04_ChirpSequenceBurstControlUnion_t ChirpSequenceBurstControl;

    /* Allowed values for NumSeqInBurst is 0x01 to 0xFFFFFFFE
     *  Allowed values for NumChirpInSeq is 0x01 to 0xFFFE
     */
    if (((NumSeqInBurst >= 1u) && (NumSeqInBurst < 0xFFFFFFFFu)) && (NumChirpInSeq >= 1u) && (NumChirpInSeq < 0xFFFFu))
    {
        ChirpSequenceBurstControl.bits_st.NoOfSequence = NumSeqInBurst;
        /* Writing back to the register */
        retVal = BC_SPI_WriteCheck(e_SYS_TE, R2M04_CHIRP_SEQUENCE_BURST_CONTROL_U16, ChirpSequenceBurstControl.val_u32);
        if (BC_ERR_NOERROR == retVal)
        {
            ChirpSeqCtrl.val_u32 = 0u;
            ChirpSeqCtrl.bits_st.NoOfChirpInASequence = NumChirpInSeq;
            /* Writing back to the register */
            retVal = BC_SPI_WriteCheck(e_SYS_TE, R2M04_CHIRP_SEQUENCE_CONTROL_U16, ChirpSeqCtrl.val_u32);
        }
    }
    else
    {
        retVal = BC_ERR_TE_CHIRPSEQUENCE;
    }
    return retVal;
}

BC_ERRCODE HAL_ES2_TE_SetBiasSwitchCtrl(BOOL EnFastBiasSwitch, float32_t FastBiasSwitchDelay, BOOL EnReplicaBiasBypass, float32_t ReplicaBiasBypassDelay)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M04_ChirpBiasSwitchControlUnion_t CBiasSwitchCtrl;
    uint32_t tmpFBSDelay;
    uint32_t tmpRBBDelay;

    retVal = BC_SPI_Read(e_SYS_TE, R2M04_CHIRP_BIAS_SWITCH_CONTROL_U16, &CBiasSwitchCtrl.val_u32);
    if (BC_ERR_NOERROR == retVal)
    {

        CBiasSwitchCtrl.bits_st.ChirpFastBiasSwitchEnable = (uint8_t)EnFastBiasSwitch;
        CBiasSwitchCtrl.bits_st.ChirpReplicaBiasEnBypass = (uint8_t)EnReplicaBiasBypass;

        /* Convert us to 25ns base */
        tmpFBSDelay = (uint32_t)(lroundf(FastBiasSwitchDelay * 1000.0f / 25.0f));    /* 10-bit value*/
        tmpRBBDelay = (uint32_t)(lroundf(ReplicaBiasBypassDelay * 1000.0f / 25.0f)); /* 10-bit value */

        if ((tmpFBSDelay < 0x400u) && (tmpRBBDelay < 0x400u))
        {
            CBiasSwitchCtrl.bits_st.ChirpFastBiasSwitchDelay = (uint16_t)tmpFBSDelay;
            CBiasSwitchCtrl.bits_st.ChirpReplicaBiasEnBypassDelay = (uint16_t)tmpRBBDelay;
            retVal = BC_SPI_WriteCheck(e_SYS_TE, R2M04_CHIRP_BIAS_SWITCH_CONTROL_U16, CBiasSwitchCtrl.val_u32);
        }
        else
        {
            retVal = BC_ERR_TE_BIASDELAY;
        }
    }
    return retVal;
}

BC_ERRCODE HAL_ES2_TE_SetChirpSeqInterval(float32_t SeqInterval)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    uint64_t tmpSeqInterval;
    R2M04_ChirpSequenceIntervalControlUnion_t CSeqInterval;

    retVal = BC_SPI_Read(e_SYS_TE, R2M04_CHIRP_SEQUENCE_INTERVAL_CONTROL_U16, &CSeqInterval.val_u32);
    if (BC_ERR_NOERROR == retVal)
    {
        /* Convert us to 25ns base */
        tmpSeqInterval = (uint64_t)lroundf(SeqInterval * 1000.0f / 25.0f);

        /*Allowed values : 0x00000001 to 0xFFFFFFFEu */
        if ((tmpSeqInterval >= 1u) && (tmpSeqInterval < 0xFFFFFFFFu))
        {
            CSeqInterval.bits_st.ChirpSequenceInterval = (uint32_t)tmpSeqInterval;
            retVal = BC_SPI_WriteCheck(e_SYS_TE, R2M04_CHIRP_SEQUENCE_INTERVAL_CONTROL_U16, CSeqInterval.val_u32);
        }
        else
        {
            retVal = BC_ERR_TE_CHIRPSEQINTERVAL;
        }
    }
    return retVal;
}

BC_ERRCODE HAL_ES2_TE_SetPRDDMACtrls(BOOL pUseDDMA[3], TE_DDMAMod_e DDMAMode, float32_t pDDMAInitPhase[3], float32_t pDDMAPhaseUpdate[3])
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M04_TxPrDdmaInitPhaseUnion_t TxPrDDMAInitPhase;
    R2M04_TxPrDdmaControlUnion_t TxPrDDMACtrl;
    R2M04_TxPrChirpControlModesUnion_t PrChirpCtrlModes;
    uint16_t tmpInitPhase[3];
    uint16_t tmpPhaseStep[3];

    if ((pDDMAInitPhase == NULL) || (pDDMAPhaseUpdate == NULL) || (pUseDDMA == NULL))
    {
        retVal = BC_ERR_TE_INPUTNULL;
    }
    else
    {
        if ((pDDMAInitPhase[0u] < 0.0f) || (pDDMAInitPhase[1u] < 0.0f) || (pDDMAInitPhase[2u] < 0.0f) ||
            (pDDMAPhaseUpdate[0u] < 0.0f) || (pDDMAPhaseUpdate[1u] < 0.0f) || (pDDMAPhaseUpdate[2u] < 0.0f) || (DDMAMode >= e_TE_DDMA_INVALID))
        {
            retVal = (DDMAMode >= e_TE_DDMA_INVALID) ? BC_ERR_TE_DDMAMODE : BC_ERR_TE_PHASEOUTOFRANGE;
        }
    }
    if (retVal == BC_ERR_NOERROR)
    {
        retVal = BC_SPI_Read(e_SYS_TE, R2M04_TX_PR_DDMA_CONTROL_U16, &TxPrDDMACtrl.val_u32);
        if (BC_ERR_NOERROR == retVal)
        {
            /*Setting the DDMA Mode. Note that this DDMA mode is common for the TXs that choose DDMA (pUseDDMA).
            All the DDMA mode e_TE_DDMA_DISABLED, e_TE_DDMA_FUN_MODE, e_TE_DDMA_TEST_MODE, e_TE_DDMA_TEST_NOCHIRP are allowed*/
            TxPrDDMACtrl.bits_st.DdmaModeControl = (uint8_t)DDMAMode;

            /* Moving to (within 10), higher 6-MSB bits*/
            tmpPhaseStep[0] = (uint16_t)(lroundf(pDDMAPhaseUpdate[0] / 0.3515625f));
            tmpPhaseStep[1] = (uint16_t)(lroundf(pDDMAPhaseUpdate[1] / 0.3515625f));
            tmpPhaseStep[2] = (uint16_t)(lroundf(pDDMAPhaseUpdate[2] / 0.3515625f));
            TxPrDDMACtrl.bits_st.Tx1PrDdmaStepPhase = (uint16_t)(tmpPhaseStep[0] & 0x3FFu);
            TxPrDDMACtrl.bits_st.Tx2PrDdmaStepPhase = (uint16_t)(tmpPhaseStep[1] & 0x3FFu);
            TxPrDDMACtrl.bits_st.Tx3PrDdmaStepPhase = (uint16_t)(tmpPhaseStep[2] & 0x3FFu);
            retVal = BC_SPI_WriteCheck(e_SYS_TE, R2M04_TX_PR_DDMA_CONTROL_U16, TxPrDDMACtrl.val_u32);
        }

        if (BC_ERR_NOERROR == retVal)
        {
            retVal = BC_SPI_Read(e_SYS_TE, R2M04_TX_PR_DDMA_INIT_PHASE_U16, &TxPrDDMAInitPhase.val_u32);
            if (BC_ERR_NOERROR == retVal)
            {
                /* Moving to (within 10), higher 6-MSB bits are integer and lower 4 bits are fractional.*/
                tmpInitPhase[0] = (uint16_t)(lroundf((pDDMAInitPhase[0]) / 0.3515625f));
                tmpInitPhase[1] = (uint16_t)(lroundf((pDDMAInitPhase[1]) / 0.3515625f));
                tmpInitPhase[2] = (uint16_t)(lroundf((pDDMAInitPhase[2]) / 0.3515625f));
                TxPrDDMAInitPhase.bits_st.Tx1PrDdmaInitPhase = (uint16_t)(tmpInitPhase[0] & 0x3FFu);
                TxPrDDMAInitPhase.bits_st.Tx2PrDdmaInitPhase = (uint16_t)(tmpInitPhase[1] & 0x3FFu);
                TxPrDDMAInitPhase.bits_st.Tx3PrDdmaInitPhase = (uint16_t)(tmpInitPhase[2] & 0x3FFu);
                retVal = BC_SPI_WriteCheck(e_SYS_TE, R2M04_TX_PR_DDMA_INIT_PHASE_U16, TxPrDDMAInitPhase.val_u32);
            }
        }

        if (BC_ERR_NOERROR == retVal)
        {
            retVal = BC_SPI_Read(e_SYS_TE, R2M04_TX_PR_CHIRP_CONTROL_MODES_U16, &PrChirpCtrlModes.val_u32);
            if (BC_ERR_NOERROR == retVal)
            {
                /*Enabling DDMA mode for TXs based on the setting*/
                PrChirpCtrlModes.bits_st.Tx1PrPhaseControl = (uint8_t)pUseDDMA[0];
                PrChirpCtrlModes.bits_st.Tx2PrPhaseControl = (uint8_t)pUseDDMA[1];
                PrChirpCtrlModes.bits_st.Tx3PrPhaseControl = (uint8_t)pUseDDMA[2];
                PrChirpCtrlModes.bits_st.ResetDdma = 1u;
                retVal = BC_SPI_Write(e_SYS_TE, R2M04_TX_PR_CHIRP_CONTROL_MODES_U16, PrChirpCtrlModes.val_u32);
            }
        }
    }
    return retVal;
}

BC_ERRCODE HAL_ES2_TE_ResetTxPRDDMA(void)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M04_TxPrChirpControlModesUnion_t PrChirpCtrlModes;
    retVal = BC_SPI_Read(e_SYS_TE, R2M04_TX_PR_CHIRP_CONTROL_MODES_U16, &PrChirpCtrlModes.val_u32);
    if (BC_ERR_NOERROR == retVal)
    {
        /*Reset DDMA mode*/
        PrChirpCtrlModes.bits_st.ResetDdma = 1u;
        retVal = BC_SPI_Write(e_SYS_TE, R2M04_TX_PR_CHIRP_CONTROL_MODES_U16, PrChirpCtrlModes.val_u32);
    }
    return retVal;
}

#endif
