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
#ifdef BUILD_FOR_VAL
#include "v_es2_lvds.h"
#include "v_es2_cc.h"
#else
#include "reg_es2_lvds.h"
#include "reg_es2_cc.h"
#endif
#include "bc_spi.h"
#include "hal_es2_lvds.h"
#include "bc_types.h"
#include "bc_err.h"
#include "plf.h"
#include <math.h>
#include "bc_conf.h"

/* Functions */
static BC_ERRCODE Helper_LVDSRestoreFreqCounter(void);
static BC_ERRCODE Helper_LVDSFuncResetRelease(BOOL ResetRelease);
static BC_ERRCODE Helper_LVDSBasicConfig(LVDS_Config_t *pLVDSConfig);
static BC_ERRCODE Helper_LVDSOptionalConfig(LVDS_OptConfig_t *pLVDSOptConfig);
static BC_ERRCODE Helper_LVDSStartFreqCounter(LVDS_Feq_Dev_e FreqDevVal, float32_t CountPeriod, uint32_t *pCountValue);
static BC_ERRCODE Helper_LVDSFreqCountVal(float32_t *pFrequency, uint32_t *pCountValue);
static BC_ERRCODE Helper_LVDSFreqCounterWait(R2M01_FreqCounterReadValueUnion_t *pFreqCounterReadValue, BC_ERRCODE *pTempRetcode);

/*This API switches the LVDS modes*/
BC_ERRCODE HAL_ES2_LVDS_SwitchMode(BOOL SwitchToCalMode, uint16_t ClockChTxData12x1, uint16_t IdlePattern)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M01_ClockChTxData12X1Union_t ClockChTxDataAndLvdsMode;
    R2M01_IdlePatternUnion_t IdleClockPattern;
    R2M01_MasterIdivCtrlUnion_t MasterIdivCtrl;

    /*Check variable input out of range value*/
    if ((ClockChTxData12x1 <= 0x0fffu) && (IdlePattern <= 0x0fffu))
    {
        /*Assert the functional reset*/
        retVal = Helper_LVDSFuncResetRelease(FALSE);
        if (retVal == BC_ERR_NOERROR)
        {
            /*Switch to Calibration mode*/
            retVal = BC_SPI_Read(e_SYS_LVDS, R2M01_CLOCK_CH_TX_DATA_12X1_U16, &ClockChTxDataAndLvdsMode.val_u32);
        }
        if (retVal == BC_ERR_NOERROR)
        { /*Switch to Calibration mode*/
            ClockChTxDataAndLvdsMode.bits_st.LvdsLaneCalibrationEn = (uint8_t)SwitchToCalMode;
            /*Frame clock pattern(12bit) to be sent in the RAW mode*/
            ClockChTxDataAndLvdsMode.bits_st.Clockchtxdata12X1 = ClockChTxData12x1;
            retVal = BC_SPI_WriteCheck(e_SYS_LVDS, R2M01_CLOCK_CH_TX_DATA_12X1_U16, ClockChTxDataAndLvdsMode.val_u32);
            if (retVal == BC_ERR_NOERROR)
            { /* Idle pattern sent in the RAW mode */
                retVal = BC_SPI_Read(e_SYS_LVDS, R2M01_IDLE_PATTERN_U16, &IdleClockPattern.val_u32);
                if (retVal == BC_ERR_NOERROR)
                {
                    IdleClockPattern.bits_st.Idlepattern = IdlePattern;
                    retVal = BC_SPI_WriteCheck(e_SYS_LVDS, R2M01_IDLE_PATTERN_U16, IdleClockPattern.val_u32);
                }
            }
        }
        if (retVal == BC_ERR_NOERROR)
        {
            retVal = BC_SPI_Read(e_SYS_LVDS, R2M01_MASTER_IDIV_CTRL_U16, &MasterIdivCtrl.val_u32);
            if (retVal == BC_ERR_NOERROR)
            {
                if (SwitchToCalMode == TRUE)
                {

                    MasterIdivCtrl.bits_st.MasterIdivSelRegLut = 1u; // setting this to enable decimation from register
                    MasterIdivCtrl.bits_st.MasterIdivValue = 0u;     // max frequency (480 Mbps)
                }
                else
                {

                    MasterIdivCtrl.bits_st.MasterIdivSelRegLut = 0u; // setting this to enable decimation from LUT -default value
                }
                retVal = BC_SPI_WriteCheck(e_SYS_LVDS, R2M01_MASTER_IDIV_CTRL_U16, MasterIdivCtrl.val_u32);
            }
        }

        /* Release the functional reset*/
        if (retVal == BC_ERR_NOERROR)
        {
            retVal = Helper_LVDSFuncResetRelease(TRUE);
        }
    }
    else
    {
        retVal = BC_ERR_INPUTOUTOFRANGE;
    }
    return retVal;
}

/*This API configures the PDC of LVDS interface*/
BC_ERRCODE HAL_ES2_LVDS_ConfigPDC(BOOL DisPDCFilter, BOOL EnPDCSync, BOOL EnWAProcess, BOOL EnUnsignedOut, uint8_t pDecModeDelays[4])
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M01_PdcConfigRegUnion_t PDCConfigReg;

    /*Configures the PDC of LVDS interface*/
    retVal = BC_SPI_Read(e_SYS_LVDS, R2M01_PDC_CONFIG_REG_U16, &PDCConfigReg.val_u32);
    if (retVal == BC_ERR_NOERROR)
    {
        PDCConfigReg.bits_st.DisablePdcFilter = (uint8_t)DisPDCFilter;    // DisPDCFilter.
        PDCConfigReg.bits_st.EnablePdcReset = (uint8_t)EnPDCSync;         // EnPDCSync.
        PDCConfigReg.bits_st.MaskInputWWa = (uint8_t)EnWAProcess;         // EnWAProcess.
        PDCConfigReg.bits_st.MakeOutputUnsigned = (uint8_t)EnUnsignedOut; // EnUnsignedOut
        if (pDecModeDelays != NULL)
        {
            /*Configure window active delay */
            if ((pDecModeDelays[3u] < 16u) && (pDecModeDelays[2u] < 16u) &&
                (pDecModeDelays[1u] < 16u) && (pDecModeDelays[0u] < 16u))
            {
                PDCConfigReg.bits_st.WaDelayDecimationMode4 = pDecModeDelays[3u];
                PDCConfigReg.bits_st.WaDelayDecimationMode3 = pDecModeDelays[2u];
                PDCConfigReg.bits_st.WaDelayDecimationMode2 = pDecModeDelays[1u];
                PDCConfigReg.bits_st.WaDelayDecimationMode1 = pDecModeDelays[0u];
            }
            else
            {
                retVal = BC_ERR_INPUTOUTOFRANGE;
            }
        }
        /*Assert the functional reset*/
        if (retVal == BC_ERR_NOERROR)
        {
            retVal = Helper_LVDSFuncResetRelease(FALSE);
        }
        if (retVal == BC_ERR_NOERROR)
        {
            retVal = BC_SPI_WriteCheck(e_SYS_LVDS, R2M01_PDC_CONFIG_REG_U16, PDCConfigReg.val_u32);
        }
        /* Release the functional reset*/
        if (retVal == BC_ERR_NOERROR)
        {
            retVal = Helper_LVDSFuncResetRelease(TRUE);
        }
    }
    return retVal;
}

/*This API enables LVDS channels*/
BC_ERRCODE HAL_ES2_LVDS_EnTransmission(BOOL pTxChannels[4])
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M01_LvdsTxControlUnion_t LvdsTxControlChannel;
    uint32_t TxChannel;

    if (pTxChannels != NULL)
    {
        /*Configure Tx LVDS channels */
        retVal = BC_SPI_Read(e_SYS_LVDS, R2M01_LVDS_TX_CONTROL_U16, &LvdsTxControlChannel.val_u32);
        if (retVal == BC_ERR_NOERROR)
        { // Channel0 | Channel2 | Channel2 | Channel3,
            TxChannel = (uint32_t)((uint32_t)(pTxChannels[0u]) | (((uint32_t)pTxChannels[1u]) << 1u) | (((uint32_t)pTxChannels[2u]) << 2u) | (((uint32_t)pTxChannels[3u]) << 3u));
            LvdsTxControlChannel.bits_st.Serialisertxen = (uint8_t)TxChannel;
            retVal = BC_SPI_WriteCheck(e_SYS_LVDS, R2M01_LVDS_TX_CONTROL_U16, LvdsTxControlChannel.val_u32);
        }
    }
    else
    {
        retVal = BC_ERR_LVDS_PTR_ADDR_NULL;
    }
    return retVal;
}

/*This API configures window active control*/
BC_ERRCODE HAL_ES2_LVDS_ChooseWinActiveSel(BOOL SelFromRegField, BOOL EnWA)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M01_WindowActiveSelUnion_t WindowActiveSel;

    /*Assert the functional reset*/
    retVal = Helper_LVDSFuncResetRelease(FALSE);
    if (retVal == BC_ERR_NOERROR)
    {
        /*  window active control */
        retVal = BC_SPI_Read(e_SYS_LVDS, R2M01_WINDOW_ACTIVE_SEL_U16, &WindowActiveSel.val_u32);
        if (retVal == BC_ERR_NOERROR)
        {
            WindowActiveSel.bits_st.WindowActiveSelVal = (uint8_t)SelFromRegField;
            WindowActiveSel.bits_st.WindowActiveRegControl = (uint8_t)EnWA;
            retVal = BC_SPI_WriteCheck(e_SYS_LVDS, R2M01_WINDOW_ACTIVE_SEL_U16, WindowActiveSel.val_u32);
        }
    }
    /* Release the functional reset*/
    if (retVal == BC_ERR_NOERROR)
    {
        retVal = Helper_LVDSFuncResetRelease(TRUE);
    }
    return retVal;
}

/*Basic LVDS configuration*/
BC_ERRCODE HAL_ES2_LVDS_Config(LVDS_Config_t *pLVDSConfig, LVDS_OptConfig_t *pLVDSOptConfig)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M01_LvdsTxControlUnion_t LvdsTxControlChannel;
    uint8_t TxChannel;

    /*Assert the functional reset*/
    retVal = Helper_LVDSFuncResetRelease(FALSE);

    // Basic LVDS configuration
    if (retVal == BC_ERR_NOERROR)
    {
        retVal = Helper_LVDSBasicConfig(pLVDSConfig);
    }

    // LVDS optional configuration
    if (retVal == BC_ERR_NOERROR)
    {
        retVal = Helper_LVDSOptionalConfig(pLVDSOptConfig);
    }

    /*LVDS Tx channel config this at the end of function */
    if ((retVal == BC_ERR_NOERROR))
    {
        retVal = BC_SPI_Read(e_SYS_LVDS, R2M01_LVDS_TX_CONTROL_U16, &LvdsTxControlChannel.val_u32);
        if (retVal == BC_ERR_NOERROR)
        { // Channel0 | Channel2 | Channel2 | Channel3,
            TxChannel = ((uint8_t)(pLVDSConfig->EnCh1) | (((uint8_t)pLVDSConfig->EnCh2) << 1u) | (((uint8_t)pLVDSConfig->EnCh3) << 2u) | (((uint8_t)pLVDSConfig->EnCh4) << 3u));
            LvdsTxControlChannel.bits_st.Serialisertxen = TxChannel;
            retVal = BC_SPI_WriteCheck(e_SYS_LVDS, R2M01_LVDS_TX_CONTROL_U16, LvdsTxControlChannel.val_u32);
        }
    }
    /* Release the functional reset*/
    if (retVal == BC_ERR_NOERROR)
    {
        retVal = Helper_LVDSFuncResetRelease(TRUE);
    }

    return retVal;
}

/*This API measures the serialiser frequency*/
BC_ERRCODE HAL_ES2_LVDS_MeasureFreq(LVDS_Feq_Dev_e FreqDevVal, float32_t CountPeriod, float32_t *pFrequency)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    uint32_t CountValue = 0x0u;

    if ((FreqDevVal < e_LVDS_IGNORE_INVALID) && (pFrequency != NULL))
    {
        /* Start Freq counter */
        retVal = Helper_LVDSStartFreqCounter(FreqDevVal, CountPeriod, &CountValue);

        if (retVal == BC_ERR_NOERROR)
        {
            retVal = Helper_LVDSFreqCountVal(pFrequency, &CountValue);
        }
    }
    else
    {
        if (pFrequency == NULL)
        {
            retVal = BC_ERR_LVDS_PTR_ADDR_NULL;
        }
        if (FreqDevVal >= e_LVDS_IGNORE_INVALID)
        {
            retVal = BC_ERR_LVDS_FREQ_COUNTER_DEVIATION;
        }
    }
    return retVal;
}

/*This API configures the LVDS test mode parameters*/
BC_ERRCODE HAL_ES2_LVDS_ConfigTestMode(BOOL EnTest, LVDS_ConfigTestParms_t *pTestConfig)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M01_AdcTestDataMuxUnion_t AdcTestDataMux;
    R2M01_PrbsControlUnion_t PrbsControl;

    if (pTestConfig != NULL)
    {
        if (pTestConfig->TestMode >= e_LVDS_TESTMODE_INVALID)
        {
            retVal = BC_ERR_LVDS_INVALID_INPUT;
        }
        if (((pTestConfig->TestData > 0x0fffu) || (pTestConfig->PRBSInitialVal > 0x0fffu)) && (retVal == BC_ERR_NOERROR))
        {
            retVal = BC_ERR_INPUTOUTOFRANGE;
        }
        /*Check variable input out of range value(12-bit data)*/
        if (retVal == BC_ERR_NOERROR)
        {
            /*Assert the functional reset*/
            retVal = Helper_LVDSFuncResetRelease(FALSE);
            if (retVal == BC_ERR_NOERROR)
            {
                retVal = BC_SPI_Read(e_SYS_LVDS, R2M01_ADC_TEST_DATA_MUX_U16, &AdcTestDataMux.val_u32);
            }
            if (retVal == BC_ERR_NOERROR)
            {
                retVal = BC_SPI_Read(e_SYS_LVDS, R2M01_PRBS_CONTROL_U16, &PrbsControl.val_u32);
            }
            if (retVal == BC_ERR_NOERROR)
            {
                AdcTestDataMux.bits_st.LvdsTestmodeEn = (uint8_t)EnTest;                              // Enable or disable Test mode
                AdcTestDataMux.bits_st.LvdsTestmodeDataSel = (uint8_t)pTestConfig->TestMode;          // Lvds Test mode Data Select
                AdcTestDataMux.bits_st.LvdsTestmodeSkipPdc = (uint8_t)pTestConfig->SkipPDC;           // Lvds Test mode Skip Pdc
                AdcTestDataMux.bits_st.DelayedTestPattern = (uint8_t)pTestConfig->EnDelayTestPattern; // Delayed Test Pattern
                AdcTestDataMux.bits_st.LvdsTestmodeTestData = (uint16_t)pTestConfig->TestData;        // Lvds Test mode Test Data(12bit)
                retVal = BC_SPI_WriteCheck(e_SYS_LVDS, R2M01_ADC_TEST_DATA_MUX_U16, AdcTestDataMux.val_u32);
                if (retVal == BC_ERR_NOERROR)
                {
                    PrbsControl.bits_st.InvertPrbsPattern = (uint8_t)pTestConfig->EnInvertPRBSPattern; // EnableInvert PRBS Pattern
                    PrbsControl.bits_st.PrbsInitialValue = (uint16_t)pTestConfig->PRBSInitialVal;      // PRBS Initial Val(12Bit)
                    retVal = BC_SPI_WriteCheck(e_SYS_LVDS, R2M01_PRBS_CONTROL_U16, PrbsControl.val_u32);
                }
            }
            /* Release the functional reset*/
            if (retVal == BC_ERR_NOERROR)
            {
                retVal = Helper_LVDSFuncResetRelease(TRUE);
            }
        }
    }
    else
    {
        retVal = BC_ERR_LVDS_PTR_ADDR_NULL;
    }

    return retVal;
}

/*This API initializes LVDS interface with following settings*/
BC_ERRCODE HAL_ES2_LVDS_Init(void)
{
    BC_ERRCODE retVal;
    R2M01_LvdsSerGlobalPadCtrlUnion_t LvdsSerGlobalPadCtrl;
    R2M01_LvdsSerPadCtrl3Union_t LvdsSerPadCtrl3;
    R2M01_LvdsConfigRegUnion_t LvdsBasicConfig;
    R2M01_PdcConfigRegUnion_t LvdsPdcConfig;

    /* assert functional reset */
    retVal = Helper_LVDSFuncResetRelease(FALSE);

    if (retVal == BC_ERR_NOERROR)
    {
        // Global LVDS pads for normal operation and enabled.
        retVal = BC_SPI_Read(e_SYS_LVDS, R2M01_LVDS_SER_GLOBAL_PAD_CTRL_U16, &LvdsSerGlobalPadCtrl.val_u32);
        if (retVal == BC_ERR_NOERROR)
        {
            LvdsSerGlobalPadCtrl.bits_st.LvdsSerGlobalMfioPadEn = 0x0u; // LVDS Pads enabled
            LvdsSerGlobalPadCtrl.bits_st.LvdsSerGlobalPadEpwr = 0x1u;   // LVDS normal operation
            retVal = BC_SPI_WriteCheck(e_SYS_LVDS, R2M01_LVDS_SER_GLOBAL_PAD_CTRL_U16, LvdsSerGlobalPadCtrl.val_u32);
        }
        // Disable the LVDS receiver, Disable both weak pull-up and pull-down and MFIO speed at 85MHz
        if (retVal == BC_ERR_NOERROR)
        {
            retVal = BC_SPI_Read(e_SYS_LVDS, R2M01_LVDS_SER_PAD_CTRL3_U16, &LvdsSerPadCtrl3.val_u32);
            if (retVal == BC_ERR_NOERROR)
            {
                LvdsSerPadCtrl3.bits_st.LvdsCsi2DatavalidMfioEn = 0x0u;   // 0:PAD Enabled,1:PAD disabled
                LvdsSerPadCtrl3.bits_st.LvdsCsi2DatavalidMfioEnzi = 0x1u; // receiver disabled
                LvdsSerPadCtrl3.bits_st.LvdsCsi2DatavalidMfioEpun = 0x1u; // Disable the weak pull-up
                LvdsSerPadCtrl3.bits_st.LvdsCsi2DatavalidMfioEpd = 0x0u;  // Disable the pull down
                LvdsSerPadCtrl3.bits_st.LvdsCsi2DatavalidMfioEhs0 = 0x0u; // Ehs0 = 0 :85MHz speed.
                LvdsSerPadCtrl3.bits_st.LvdsCsi2DatavalidMfioEhs1 = 0x1u; // Ehs1 = 1
                retVal = BC_SPI_WriteCheck(e_SYS_LVDS, R2M01_LVDS_SER_PAD_CTRL3_U16, LvdsSerPadCtrl3.val_u32);
            }
        }
        // Frame clock is free running, No data valid delay, Disabled Packet Header and disable CRC
        if (retVal == BC_ERR_NOERROR)
        {
            retVal = BC_SPI_Read(e_SYS_LVDS, R2M01_LVDS_CONFIG_REG_U16, &LvdsBasicConfig.val_u32);
            if (retVal == BC_ERR_NOERROR)
            {
                LvdsBasicConfig.bits_st.FrameClkGating = 0x0u;         // 0:Free running,1:Gated outside
                LvdsBasicConfig.bits_st.DataValidDelayCtrl = 0x0u;     // 00:No data delay
                LvdsBasicConfig.bits_st.Packeten = 0x0u;               // Disable the packet header
                LvdsBasicConfig.bits_st.AdcDataStreamingModeEn = 0x0u; // 1:ADC data is send outside the valid data window,0:IDLE pattern send outside
                LvdsBasicConfig.bits_st.LvdsCrcControl = 0x0u;         // 1:ADC data will be CRC protected , 0:No CRC Footer
                retVal = BC_SPI_WriteCheck(e_SYS_LVDS, R2M01_LVDS_CONFIG_REG_U16, LvdsBasicConfig.val_u32);
            }
        }
        // Output is unsigned.
        if (retVal == BC_ERR_NOERROR)
        {
            retVal = BC_SPI_Read(e_SYS_LVDS, R2M01_PDC_CONFIG_REG_U16, &LvdsPdcConfig.val_u32);
            if (retVal == BC_ERR_NOERROR)
            {
                LvdsPdcConfig.bits_st.MakeOutputUnsigned = 0x1u; // 1:Unsigned 12 bit , 0:Signed 12 bit
                LvdsPdcConfig.bits_st.EnablePdcReset = 0x1u;     // pdc reset for every chirp
                retVal = BC_SPI_WriteCheck(e_SYS_LVDS, R2M01_PDC_CONFIG_REG_U16, LvdsPdcConfig.val_u32);
            }
        }
    }
    /* release functional reset */
    if (retVal == BC_ERR_NOERROR)
    {
        retVal = Helper_LVDSFuncResetRelease(TRUE);
    }
    return retVal;
}

/*************** Local Functions *******************/
static BC_ERRCODE Helper_LVDSBasicConfig(LVDS_Config_t *pLVDSConfig)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M01_MsbLsbControlUnion_t MsbLsbControl;
    R2M01_TransmitPhaseControlUnion_t TransmitPhaseControl;
    R2M01_LvdsConfigRegUnion_t LvdsBasicConfig;
    // Basic LVDS configuration
    if (pLVDSConfig != NULL)
    {
        /*MSB and LSB control*/
        retVal = BC_SPI_Read(e_SYS_LVDS, R2M01_MSB_LSB_CONTROL_U16, &MsbLsbControl.val_u32);
        if (retVal == BC_ERR_NOERROR)
        {
            MsbLsbControl.bits_st.MsbFirst = (uint8_t)pLVDSConfig->MSBFirst;               // MSB first
            MsbLsbControl.bits_st.PacketEndianness = (uint8_t)pLVDSConfig->PktHdrLSBFirst; // Packet header and footer.
            retVal = BC_SPI_WriteCheck(e_SYS_LVDS, R2M01_MSB_LSB_CONTROL_U16, MsbLsbControl.val_u32);
        }
        /*Transmit Phase Control */
        if (retVal == BC_ERR_NOERROR)
        {
            retVal = BC_SPI_Read(e_SYS_LVDS, R2M01_TRANSMIT_PHASE_CONTROL_U16, &TransmitPhaseControl.val_u32);
            if (retVal == BC_ERR_NOERROR)
            {
                /*Transmit Phase Control */
                TransmitPhaseControl.bits_st.FrameClkPhase = (uint8_t)pLVDSConfig->FrameClkFallEdge;
                TransmitPhaseControl.bits_st.BitClkPhase = (uint8_t)pLVDSConfig->BitClkRiseEdge;
                retVal = BC_SPI_WriteCheck(e_SYS_LVDS, R2M01_TRANSMIT_PHASE_CONTROL_U16, TransmitPhaseControl.val_u32);
            }
        }
        /*LVDS configuration */
        if (retVal == BC_ERR_NOERROR)
        {
            retVal = BC_SPI_Read(e_SYS_LVDS, R2M01_LVDS_CONFIG_REG_U16, &LvdsBasicConfig.val_u32);
            if (retVal == BC_ERR_NOERROR)
            {
                LvdsBasicConfig.bits_st.FrameClkGating = (uint8_t)pLVDSConfig->FrameClkGated;
                LvdsBasicConfig.bits_st.Packeten = (uint8_t)pLVDSConfig->EnPktHdr;
                LvdsBasicConfig.bits_st.LvdsCrcControl = (uint8_t)pLVDSConfig->EnCRCFooter;
                retVal = BC_SPI_WriteCheck(e_SYS_LVDS, R2M01_LVDS_CONFIG_REG_U16, LvdsBasicConfig.val_u32);
            }
        }
    }
    else
    {
        retVal = BC_ERR_LVDS_PTR_ADDR_NULL;
    }
    return retVal;
}
static BC_ERRCODE Helper_LVDSOptionalConfig(LVDS_OptConfig_t *pLVDSOptConfig)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M01_ClockChTxData12X1Union_t ClockChTxDataAndLvdsMode;
    R2M01_IdlePatternUnion_t IdleClockPattern;
    R2M01_LvdsConfigRegUnion_t LvdsBasicConfig;

    if (pLVDSOptConfig != NULL)
    {
        /*Check variable input out of range value*/
        if ((pLVDSOptConfig->FrameClkPattern <= 0x0fffu) && (pLVDSOptConfig->IdlePattern <= 0x0fffu) && (pLVDSOptConfig->DValidDelayCtrl < e_LVDS_DVALID_INVALID))
        {
            /*Frame clock pattern(12bit) to be sent in the RAW mode*/
            retVal = BC_SPI_Read(e_SYS_LVDS, R2M01_CLOCK_CH_TX_DATA_12X1_U16, &ClockChTxDataAndLvdsMode.val_u32);
            if (retVal == BC_ERR_NOERROR)
            {
                ClockChTxDataAndLvdsMode.bits_st.Clockchtxdata12X1 = (uint16_t)pLVDSOptConfig->FrameClkPattern;
                retVal = BC_SPI_WriteCheck(e_SYS_LVDS, R2M01_CLOCK_CH_TX_DATA_12X1_U16, ClockChTxDataAndLvdsMode.val_u32);
            }
            /*Idle pattern sent in the RAW mode */
            if (retVal == BC_ERR_NOERROR)
            {
                retVal = BC_SPI_Read(e_SYS_LVDS, R2M01_IDLE_PATTERN_U16, &IdleClockPattern.val_u32);
                if (retVal == BC_ERR_NOERROR)
                {
                    IdleClockPattern.bits_st.Idlepattern = (uint16_t)pLVDSOptConfig->IdlePattern;
                    retVal = BC_SPI_WriteCheck(e_SYS_LVDS, R2M01_IDLE_PATTERN_U16, IdleClockPattern.val_u32);
                }
            }
            /*LVDS Optional configuration */
            if (retVal == BC_ERR_NOERROR)
            {
                retVal = BC_SPI_Read(e_SYS_LVDS, R2M01_LVDS_CONFIG_REG_U16, &LvdsBasicConfig.val_u32);
                if (retVal == BC_ERR_NOERROR)
                {
                    LvdsBasicConfig.bits_st.DataValidDelayCtrl = (uint8_t)pLVDSOptConfig->DValidDelayCtrl; // Data valid delay control
                    LvdsBasicConfig.bits_st.PacketHeaderFormat = (uint8_t)pLVDSOptConfig->PktHdrFormat;
                    LvdsBasicConfig.bits_st.AdcDataStreamingModeEn = (uint8_t)pLVDSOptConfig->EnADCStreamingMode;
                    retVal = BC_SPI_WriteCheck(e_SYS_LVDS, R2M01_LVDS_CONFIG_REG_U16, LvdsBasicConfig.val_u32);
                }
            }
        }
        else
        {
            retVal = BC_ERR_INPUTOUTOFRANGE;
        }
    }
    return retVal;
}
static BC_ERRCODE Helper_LVDSStartFreqCounter(LVDS_Feq_Dev_e FreqDevVal, float32_t CountPeriod, uint32_t *pCountValue)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;

    R2M01_FreqCounterStartUnion_t FreqCounterStart;
    R2M01_RefCntrInitUnion_t RefCntrInit;

    // Read the reference counter init value and frequency counter
    if (CountPeriod <= 0.0f)
    {
        retVal = BC_ERR_LVDS_COUNT_PERIOD_INVALID;
    }
    else
    {
        *pCountValue = SYS_CONVERT_TIMEUS_TO_40MHZCYCLE(CountPeriod);
    }
    if ((*pCountValue < 0x10000u) && (*pCountValue != 0u) && (CountPeriod <= MIPI_LVDS_MAX_FREQ_COUNT_PERIOD)) // Ref count value less than 16 bit and to avoid divide by zero
    {
        float32_t IdealCount = (LVDS_IDEAL480_DEFAULT_VALUE * CountPeriod);
        RefCntrInit.bits_st.Ideal480CountValue = (uint16_t)IdealCount;
        RefCntrInit.bits_st.RefCountValue = (uint16_t)*pCountValue;
        retVal = BC_SPI_WriteCheck(e_SYS_LVDS, R2M01_REF_CNTR_INIT_U16, RefCntrInit.val_u32);
    }
    else
    {
        retVal = BC_ERR_LVDS_COUNT_PERIOD_INVALID;
    }

    if (retVal == BC_ERR_NOERROR)
    {
        /* Removed SPI read register since all required fields are initialized below */
        FreqCounterStart.val_u32 = 0x0u;                                     // change frequency counter trigger to SPI write to freq_start and Frequency counter Deviation configuration
        FreqCounterStart.bits_st.FreqCounterTriggerSel = 0x0u;               // 0: trigger from writing to this register
        FreqCounterStart.bits_st.FreqCounterDeviation = (uint8_t)FreqDevVal; // Freq counter deviation
        FreqCounterStart.bits_st.FreqStart = 0x0u;
        retVal = BC_SPI_Write(e_SYS_LVDS, R2M01_FREQ_COUNTER_START_U16, FreqCounterStart.val_u32);
        if (retVal == BC_ERR_NOERROR)
        {                                              // No write check since this is auto clear bit
            FreqCounterStart.bits_st.FreqStart = 0x1u; // 1: trigger one measurement.
            retVal = BC_SPI_Write(e_SYS_LVDS, R2M01_FREQ_COUNTER_START_U16, FreqCounterStart.val_u32);
        }
    }
    return retVal;
}
static BC_ERRCODE Helper_LVDSFreqCounterWait(R2M01_FreqCounterReadValueUnion_t *pFreqCounterReadValue, BC_ERRCODE *pTempRetcode)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    uint32_t WhileLoopCount = 0u;

    // Wait till frequency counter is finished
    do
    {
        retVal = PLF_TM_Sleep(LVDS_MEASUREFREQ_SLEEP);
        if (retVal == BC_ERR_NOERROR)
        {
            retVal = BC_SPI_Read(e_SYS_LVDS, R2M01_FREQ_COUNTER_READ_VALUE_U16, &pFreqCounterReadValue->val_u32);
        }
        if ((retVal == BC_ERR_NOERROR) && (WhileLoopCount >= LVDS_WAIT_FOR_READY_TIMEOUT))
        {
            *pTempRetcode = BC_ERR_LVDS_FREQCOUNTTIMEOUT;
        }
        WhileLoopCount++;
        // This is busy wait, so no need to have sleep, only SPI channel will be busy.
    } while ((pFreqCounterReadValue->bits_st.DoneFlag == 0x0u) && (retVal == BC_ERR_NOERROR) && (*pTempRetcode == BC_ERR_NOERROR));

    return retVal;
}

static BC_ERRCODE Helper_LVDSFreqCountVal(float32_t *pFrequency, uint32_t *pCountValue)

{
    BC_ERRCODE TempRetcode = BC_ERR_NOERROR;
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M01_FreqCounterReadValueUnion_t FreqCounterReadValue;
    FreqCounterReadValue.val_u32 = 0u;
    R2M01_RefCntrInitUnion_t RefCntrInit;

    retVal = Helper_LVDSFreqCounterWait(&FreqCounterReadValue, &TempRetcode);
    // Compute the frequency count value and it is based on reference counter init reg value.
    if ((TempRetcode == BC_ERR_NOERROR) && (retVal == BC_ERR_NOERROR) && (FreqCounterReadValue.bits_st.DoneFlag == 0x1u))
    {
        retVal = BC_SPI_Read(e_SYS_LVDS, R2M01_FREQ_COUNTER_READ_VALUE_U16, &FreqCounterReadValue.val_u32);
        if (retVal == BC_ERR_NOERROR)
        {
            // Reference count time default is d'40(40MHz) and frequency in Hz
            *pFrequency = (float32_t)((float32_t)FreqCounterReadValue.bits_st.FreqCountValue / ((float32_t)*pCountValue / 40.0f));
            *pFrequency = (*pFrequency) * ((float32_t)1000000.0f); // Converting frequency from MHz to Hz
        }
    }
    if (retVal == BC_ERR_NOERROR)
    {
        retVal = Helper_LVDSRestoreFreqCounter();
    }
    if (retVal == BC_ERR_NOERROR)
    {
        RefCntrInit.bits_st.Ideal480CountValue = (uint16_t)LVDS_IDEAL480_DEFAULT_VALUE;
        RefCntrInit.bits_st.RefCountValue = LVDS_REFCOUNT_DEFAULT_VALUE;
        retVal = BC_SPI_WriteCheck(e_SYS_LVDS, R2M01_REF_CNTR_INIT_U16, RefCntrInit.val_u32);
    }
    if (retVal == BC_ERR_NOERROR)
    {
        retVal = (TempRetcode == BC_ERR_LVDS_FREQCOUNTTIMEOUT) ? BC_ERR_LVDS_FREQCOUNTTIMEOUT : retVal;
    }
    return retVal;
}
static BC_ERRCODE Helper_LVDSFuncResetRelease(BOOL ResetRelease)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M00_IpFunctionalResetControlUnion_t IpFunctionalReset;
    /* assert functional reset */
    ErrCode = BC_SPI_Read(e_SYS_CC, R2M00_IP_FUNCTIONAL_RESET_CONTROL_U16, &IpFunctionalReset.val_u32);
    if (ErrCode == BC_ERR_NOERROR)
    {
        IpFunctionalReset.bits_st.FnResetSer = (uint8_t)ResetRelease;
        ErrCode = BC_SPI_WriteCheck(e_SYS_CC, R2M00_IP_FUNCTIONAL_RESET_CONTROL_U16, IpFunctionalReset.val_u32);
    }
    return ErrCode;
}
static BC_ERRCODE Helper_LVDSRestoreFreqCounter(void)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M01_FreqCounterStartUnion_t FreqCounterStart;
    R2M01_FreqCounterStartUnion_t FreqCounterStartRead;
    FreqCounterStart.val_u32 = 0x0u;
    // FreqCounterTriggerSel always restored even it is succcess or failure of frequency counter read value.
    FreqCounterStart.bits_st.FreqCounterDeviation = 3u;    // e_LVDS_IGNOR_ZERO_ONE_BITS
    FreqCounterStart.bits_st.FreqCounterTriggerSel = 0x1u; // 1:Restored the Trigger select.
    /*Error code is not returned since it overwrites the timeout error*/
    retVal = BC_SPI_Write(e_SYS_LVDS, R2M01_FREQ_COUNTER_START_U16, FreqCounterStart.val_u32);
    if (retVal == BC_ERR_NOERROR)
    {
        retVal = BC_SPI_Read(e_SYS_LVDS, R2M01_FREQ_COUNTER_START_U16, &FreqCounterStartRead.val_u32);
        if (retVal == BC_ERR_NOERROR)
        {
            // Checking the FreqCounterDeviation and FreqCounterTriggerSel value restored correctly
            if ((FreqCounterStartRead.bits_st.FreqCounterDeviation != FreqCounterStart.bits_st.FreqCounterDeviation) &&
                (FreqCounterStartRead.bits_st.FreqCounterTriggerSel != FreqCounterStart.bits_st.FreqCounterTriggerSel))
            {
                retVal = BC_ERR_LVDS_RESTORE_FREQ_COUNTER;
            }
        }
    }
    return retVal;
}
#endif
/******** End of File *************/
