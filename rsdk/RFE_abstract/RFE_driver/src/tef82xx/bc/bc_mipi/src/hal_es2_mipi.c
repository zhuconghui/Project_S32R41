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
#include "hal_es2_mipi.h"
#ifdef BUILD_FOR_VAL
#include "v_es2_mipi.h"
#include "v_es2_cc.h"
#else
#include "reg_es2_mipi.h"
#include "reg_es2_cc.h"
#endif
#include "bc_spi.h"
#include "bc_conf.h"
#include "plf.h"
/* Local defines */

/* Functions */

static BC_ERRCODE Helper_MIPIRestoreFreqCounter(void);
static BC_ERRCODE Helper_MIPIFuncResetRelease(BOOL ResetRelease);
static BC_ERRCODE Helper_MIPIVirtChannelControl(void);
static BC_ERRCODE Helper_MIPITrimDphy(MIPI_DataRate_e DataRate);
static BC_ERRCODE Helper_MIPIDateLaneSetting(uint8_t NLanes);
static BC_ERRCODE Helper_MIPIDeviceReadyCheck(void);
static BC_ERRCODE Helper_MIPIStartFreqCounter(MIPI_FreqCountDeviation_e FreqDeviationValue, float32_t CountPeriod, uint32_t *pCountValue);
static BC_ERRCODE Helper_MIPIFreqCountVal(float32_t *pFrequency, uint32_t *pCountValue);

static BC_ERRCODE Helper_MIPIFreqCounterWait(R2M02_FreqCounterReadValueUnion_t *pFreqCounterReadValue, BC_ERRCODE *pTempRetcode);
BC_ERRCODE HAL_ES2_MIPI_Init(void)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

#if 0
    // these register if reset value is not same as default value, we need to initialize with default values
    R2M02_TrimReg0Union_t TrimReg0;        /*This is already set to correct reset value  */
    R2M02_TrimReg2Union_t TrimReg2;        /*This is already set to correct reset value  */
    R2M02_TrimReg3Union_t TrimReg3;        /*This is already set to correct reset value  */
    R2M02_Csi2TestModeControlRegUnion_t Csi2TestModeControlReg;        /*Reset value is as expected  */
    // This already set in config so no need to set here 
    R2M02_Csi2AdaptConfigReg2Union_t Csi2AdaptConfigReg2;        /* to set csi2delaycnt(based on validation input) and csi2dphyclkdiv*/
    /* Scope of optimization:  init time become critical,
    TrimReg0, TrimReg2, TrimReg3, Csi2AdaptConfigReg2 and Csi2TestModeControlReg registers
    initialization can be removed, as each register require init value is same as reset value */
#endif
    R2M02_PhyTinitCountRegisterUnion_t PhyTinitCountReg; /* This need to be set here since reset value is FFFF*/
    R2M02_PllCountRegisterUnion_t PllCountReg;           /* This need to be set here for fast lock */

    R2M02_PdcConfigRegUnion_t PdcConfigReg;         /* only beacuse of unsigned byte setting */
    R2M02_DataValidPadCtrlUnion_t DataValidPadCtrl; /* This need to set for datavalid enable */

    /* Assert functional reset */
    ErrCode = Helper_MIPIFuncResetRelease(FALSE);

    if (ErrCode == BC_ERR_NOERROR)
    {
        /* PHY_TINIT_COUNT_REGISTER need to be set here since reset value is FFFF*/
        /* Since all 32 bit of PHY_TINIT_COUNT_REGISTER reg are changing we don't need read modified write */
        PhyTinitCountReg.bits_st.TinitTimer = 0x00002000u; // recommended for fast lock after reset release
        ErrCode = BC_SPI_WriteCheck(e_SYS_MIPI, R2M02_PHY_TINIT_COUNT_REGISTER_U16, PhyTinitCountReg.val_u32);
    }

    if (ErrCode == BC_ERR_NOERROR)
    {
        /* PLL_COUNT_REGISTER need to be set here for fast lock reset value is 0x00004E20 */
        /* Since all 32 bit of PLL_COUNT_REGISTER reg are changing we don't need read modified write */
        PllCountReg.bits_st.Reserved0 = 0x0000u; // recommended for fast lock after reset release
        PllCountReg.bits_st.PllCnt = 0x0000u;    // 0x0 is recommended for fast lock
        ErrCode = BC_SPI_WriteCheck(e_SYS_MIPI, R2M02_PLL_COUNT_REGISTER_U16, PllCountReg.val_u32);
    }

    if (ErrCode == BC_ERR_NOERROR)
    {
        /* PDC_CONFIG_REG only beacuse of unsigned out put setting */
        ErrCode = BC_SPI_Read(e_SYS_MIPI, R2M02_PDC_CONFIG_REG_U16, &PdcConfigReg.val_u32);
        if (ErrCode == BC_ERR_NOERROR)
        {
            PdcConfigReg.bits_st.MakeOutputUnsigned = 0x1u;
            PdcConfigReg.bits_st.EnablePdcReset = 0x1u; // pdc reset for every chirp
            ErrCode = BC_SPI_WriteCheck(e_SYS_MIPI, R2M02_PDC_CONFIG_REG_U16, PdcConfigReg.val_u32);
        }
    }

    if (ErrCode == BC_ERR_NOERROR)
    {
        /* DATA_VALID_PAD_CTRL  need to set for datavalid enable etc...*/
        ErrCode = BC_SPI_Read(e_SYS_MIPI, R2M02_DATA_VALID_PAD_CTRL_U16, &DataValidPadCtrl.val_u32);
        if (ErrCode == BC_ERR_NOERROR)
        {
            DataValidPadCtrl.bits_st.LvdsCsi2DatavalidMfioEhs1 = 0x1u; // setting 85Mhz speed
            DataValidPadCtrl.bits_st.LvdsCsi2DatavalidMfioEhs0 = 0x0u; // setting 85Mhz speed
            DataValidPadCtrl.bits_st.LvdsCsi2DatavalidMfioEn = 0x0u;   // Disable Output Driver(Active High), 0: Pad enabled
            ErrCode = BC_SPI_WriteCheck(e_SYS_MIPI, R2M02_DATA_VALID_PAD_CTRL_U16, DataValidPadCtrl.val_u32);
        }
    }
    /* release functional reset */
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = Helper_MIPIFuncResetRelease(TRUE);
    }

    return ErrCode;
}

BC_ERRCODE HAL_ES2_MIPI_Config(uint8_t NLanes, MIPI_DataRate_e DataRate)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

    /* Before config Assert functional reset */
    ErrCode = Helper_MIPIFuncResetRelease(FALSE);

    /* Before config disable the transmission */
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = HAL_ES2_MIPI_EnTransmission(FALSE);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        /* Set Virtual channel controls */
        ErrCode = Helper_MIPIVirtChannelControl();
    }
    /* CSI2_ADAPT_CONFIG_REG2 reg Csi2Delaycnt and Csi2Dphyclkdiv default value are good for all the NLanes so not configuring here */
    if (ErrCode == BC_ERR_NOERROR)
    {
        /* Trim ad Dphy register settings */
        ErrCode = Helper_MIPITrimDphy(DataRate);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        /* Data lane config */
        ErrCode = Helper_MIPIDateLaneSetting(NLanes);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        /* Enable the transmission */
        ErrCode = HAL_ES2_MIPI_EnTransmission(TRUE);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        /* release functional reset */
        ErrCode = Helper_MIPIFuncResetRelease(TRUE);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        /* Check for Device Ready */
        ErrCode = Helper_MIPIDeviceReadyCheck();
    }

    return ErrCode;
}

BC_ERRCODE HAL_ES2_MIPI_ConfigPDC(BOOL DisPDCFilter, BOOL EnPDCSync, BOOL EnWAProcess, BOOL EnUnsignedOut, uint8_t pDecModeDelays[4])
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M02_PdcConfigRegUnion_t PDCConfigReg;

    /*Configures the PDC of MIPI interface*/
    ErrCode = BC_SPI_Read(e_SYS_MIPI, R2M02_PDC_CONFIG_REG_U16, &PDCConfigReg.val_u32);
    if (ErrCode == BC_ERR_NOERROR)
    {
        PDCConfigReg.bits_st.DisablePdcFilter = (uint8_t)DisPDCFilter;    // DisPDCFilter.
        PDCConfigReg.bits_st.EnablePdcReset = (uint8_t)EnPDCSync;         // EnPDCSync.
        PDCConfigReg.bits_st.MaskInputWWa = (uint8_t)EnWAProcess;         // EnWAProcess.
        PDCConfigReg.bits_st.MakeOutputUnsigned = (uint8_t)EnUnsignedOut; // EnUnsignedOut
        /* pDecModeDelays NULL is also valid input for this API */
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
                ErrCode = BC_ERR_INPUTOUTOFRANGE;
            }
        }
        /* Before config Assert functional reset */
        if (ErrCode == BC_ERR_NOERROR)
        {
            ErrCode = Helper_MIPIFuncResetRelease(FALSE);
        }

        if (ErrCode == BC_ERR_NOERROR)
        {
            ErrCode = BC_SPI_WriteCheck(e_SYS_MIPI, R2M02_PDC_CONFIG_REG_U16, PDCConfigReg.val_u32);
        }
        /* release functional reset */
        if (ErrCode == BC_ERR_NOERROR)
        {
            ErrCode = Helper_MIPIFuncResetRelease(TRUE);
        }
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_MIPI_ConfigVC(MIPI_VCNum_t *pSelectVCs, MIPI_VCClearFrame_t *pClearFrameVCs)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M02_VirtualChannelControlUnion_t VChannelControl;

    if ((pSelectVCs != NULL) && (pClearFrameVCs != NULL))
    {
        /* This function needs to be callable at radar-cycle time to avoid incorrect counter updates.
        Therefore the FR assert/release must be removed. It has been proven that this change is robust,
        and can be safely applied.*/

        ErrCode = BC_SPI_Read(e_SYS_MIPI, R2M02_VIRTUAL_CHANNEL_CONTROL_U16, &VChannelControl.val_u32);
        if (ErrCode == BC_ERR_NOERROR)
        {
            /* TRUE to enable the VC */
            VChannelControl.bits_st.Vc0En = (uint8_t)pSelectVCs->SelectVC0;
            /* True: clear VC frame count for each frame, False : clear VC frame counter at the reset.*/
            VChannelControl.bits_st.Vc0FrameNumClr = (uint8_t)pClearFrameVCs->ClearFrameVC0;
            VChannelControl.bits_st.Vc1En = (uint8_t)pSelectVCs->SelectVC1;
            VChannelControl.bits_st.Vc1FrameNumClr = (uint8_t)pClearFrameVCs->ClearFrameVC1;
            VChannelControl.bits_st.Vc2En = (uint8_t)pSelectVCs->SelectVC2;
            VChannelControl.bits_st.Vc2FrameNumClr = (uint8_t)pClearFrameVCs->ClearFrameVC2;
            VChannelControl.bits_st.Vc3En = (uint8_t)pSelectVCs->SelectVC3;
            VChannelControl.bits_st.Vc3FrameNumClr = (uint8_t)pClearFrameVCs->ClearFrameVC3;

            ErrCode = BC_SPI_WriteCheck(e_SYS_MIPI, R2M02_VIRTUAL_CHANNEL_CONTROL_U16, VChannelControl.val_u32);
        }
    }
    else
    {
        ErrCode = BC_ERR_INPUTOUTOFRANGE;
    }

    return ErrCode;
}

BC_ERRCODE HAL_ES2_MIPI_MeasureFreq(MIPI_FreqCountDeviation_e FreqDeviationValue, float32_t CountPeriod, float32_t *pFrequency)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    uint32_t CountValue = 0x0u;

    if ((FreqDeviationValue < e_MIPI_IGNORE_BITS_INVALID) && (pFrequency != NULL))
    {
        retVal = Helper_MIPIStartFreqCounter(FreqDeviationValue, CountPeriod, &CountValue);

        if (retVal == BC_ERR_NOERROR)
        {
            retVal = Helper_MIPIFreqCountVal(pFrequency, &CountValue);
        }
    }
    else
    {
        retVal = BC_ERR_INPUTOUTOFRANGE;
    }
    return retVal;
}

BC_ERRCODE HAL_ES2_MIPI_ConfigADAPT(MIPI_DisableADCChannels_t *pDisADCChannels, BOOL DisADCChanDataSelect, MIPI_ClearChirpNum_e EnChirpNumClearReg, BOOL EnPacketCRCFooter, BOOL EnPacketHeader)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M02_Csi2AdaptConfigReg2Union_t Csi2AdaptConfigReg2;
    R2M02_Csi2AdaptConfigReg3Union_t Csi2AdaptConfigReg3;

    if ((EnChirpNumClearReg < e_MIPI_CHIRPNUM_CLEAR_INVALID) && (pDisADCChannels != NULL))
    {
        /* Before config Assert functional reset */
        ErrCode = Helper_MIPIFuncResetRelease(FALSE);
        if (ErrCode == BC_ERR_NOERROR)
        {
            ErrCode = BC_SPI_Read(e_SYS_MIPI, R2M02_CSI2_ADAPT_CONFIG_REG2_U16, &Csi2AdaptConfigReg2.val_u32);
            if (ErrCode == BC_ERR_NOERROR)
            {
                Csi2AdaptConfigReg2.bits_st.Csi2Crccontrol = (uint8_t)EnPacketCRCFooter; // This NXP packet CRC footer
                Csi2AdaptConfigReg2.bits_st.Csi2Packetenable = (uint8_t)EnPacketHeader;  // This NXP packet header has Chirp count, world count
                ErrCode = BC_SPI_WriteCheck(e_SYS_MIPI, R2M02_CSI2_ADAPT_CONFIG_REG2_U16, Csi2AdaptConfigReg2.val_u32);
            }
        }
        if (ErrCode == BC_ERR_NOERROR)
        {
            ErrCode = BC_SPI_Read(e_SYS_MIPI, R2M02_CSI2_ADAPT_CONFIG_REG3_U16, &Csi2AdaptConfigReg3.val_u32);
            if (ErrCode == BC_ERR_NOERROR)
            {
                Csi2AdaptConfigReg3.bits_st.Adcchanneldisable = ((uint8_t)(((uint8_t)pDisADCChannels->DisableADCChannel4 << 3u) |
                                                                           ((uint8_t)pDisADCChannels->DisableADCChannel3 << 2u) |
                                                                           ((uint8_t)pDisADCChannels->DisableADCChannel2 << 1u) |
                                                                           (uint8_t)pDisADCChannels->DisableADCChannel1));

                /* Data selection for the disabled data channel, 0 or tesmModeTestData */
                Csi2AdaptConfigReg3.bits_st.Channeldisabledatasel = (uint8_t)DisADCChanDataSelect;

                if (EnChirpNumClearReg == e_MIPI_CHIRPNUM_CLEAR_EVERY_SEQUENCE)
                {
                    /* auto clear chirp number for every frame/sequence */
                    Csi2AdaptConfigReg3.bits_st.ChirpNumberClrSel = 0u;
                }
                else
                {
                    /* no clear of chirp number or clear now */
                    Csi2AdaptConfigReg3.bits_st.ChirpNumberClrSel = 1u;
                    Csi2AdaptConfigReg3.bits_st.ChirpNumberClr = (EnChirpNumClearReg == e_MIPI_CHIRPNUM_CLEAR_NOW) ? 1u : 0u;
                }
                ErrCode = BC_SPI_WriteCheck(e_SYS_MIPI, R2M02_CSI2_ADAPT_CONFIG_REG3_U16, Csi2AdaptConfigReg3.val_u32);
            }
        }
        /* release functional reset */
        if (ErrCode == BC_ERR_NOERROR)
        {
            ErrCode = Helper_MIPIFuncResetRelease(TRUE);
        }
    }
    else
    {
        ErrCode = BC_ERR_INPUTOUTOFRANGE;
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_MIPI_EnTransmission(BOOL EnableDataTx)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M02_Csi2TxnCtrlUnion_t Csi2TxnCtrl;

    ErrCode = BC_SPI_Read(e_SYS_MIPI, R2M02_CSI2_TXN_CTRL_U16, &Csi2TxnCtrl.val_u32);
    if (ErrCode == BC_ERR_NOERROR)
    {
        Csi2TxnCtrl.bits_st.Csi2TxnEn = (uint8_t)EnableDataTx;
        ErrCode = BC_SPI_WriteCheck(e_SYS_MIPI, R2M02_CSI2_TXN_CTRL_U16, Csi2TxnCtrl.val_u32);
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_MIPI_EnContinuousClock(BOOL EnableContClock)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M02_Csi2AdaptConfigReg1Union_t Csi2AdaptConfReg1;

    ErrCode = BC_SPI_Read(e_SYS_MIPI, R2M02_CSI2_ADAPT_CONFIG_REG1_U16, &Csi2AdaptConfReg1.val_u32);
    if (ErrCode == BC_ERR_NOERROR)
    {
        if (EnableContClock == TRUE)
        {
            Csi2AdaptConfReg1.bits_st.Csi2Dphyclkmode = 0u;
        }
        else
        {
            Csi2AdaptConfReg1.bits_st.Csi2Dphyclkmode = 1u;
        }
        ErrCode = BC_SPI_WriteCheck(e_SYS_MIPI, R2M02_CSI2_ADAPT_CONFIG_REG1_U16, Csi2AdaptConfReg1.val_u32);
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_MIPI_ConfigTestMode(BOOL EnTest, MIPI_ConfigTestParms_t *pTestParameters)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M02_Csi2TestModeControlRegUnion_t Csi2TestModeCtrlReg;
    R2M02_PrbsControlUnion_t PrbsControl;

    /* Before config Assert functional reset */
    ErrCode = Helper_MIPIFuncResetRelease(FALSE);

    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_SPI_Read(e_SYS_MIPI, R2M02_CSI2_TEST_MODE_CONTROL_REG_U16, &Csi2TestModeCtrlReg.val_u32);
    }
    if ((EnTest == FALSE) && (ErrCode == BC_ERR_NOERROR))
    {
        /* If test mode is disabled no need to set other parameter just change teh disable bit */
        Csi2TestModeCtrlReg.bits_st.Csi2TestmodeEn = (uint8_t)EnTest; // disable Test mode
        ErrCode = BC_SPI_WriteCheck(e_SYS_MIPI, R2M02_CSI2_TEST_MODE_CONTROL_REG_U16, Csi2TestModeCtrlReg.val_u32);
    }
    /* Test mode is enabled so parameter check is required  */
    if ((pTestParameters != NULL) && (EnTest == TRUE) && (ErrCode == BC_ERR_NOERROR))
    {
        /* Common setting of test mode register */
        Csi2TestModeCtrlReg.bits_st.Csi2TestmodeEn = (uint8_t)EnTest;                                  // Enable Test mode
        Csi2TestModeCtrlReg.bits_st.Csi2TestmodeDataSel = (uint8_t)pTestParameters->TestMode;          // MIPI Test mode Data Select
        Csi2TestModeCtrlReg.bits_st.Csi2TestmodeSkipPdc = (uint8_t)pTestParameters->SkipPDC;           // MIPI Test mode Skip Pdc
        Csi2TestModeCtrlReg.bits_st.DelayedTestPattern = (uint8_t)pTestParameters->EnDelayTestPattern; // Delayed Test Pattern
        switch (pTestParameters->TestMode)
        {
        case e_MIPI_TESTMODE_FIXEDDATA:
            /*Check variable input out of range value(12-bit data)*/
            if (pTestParameters->testModeTestData <= 0x0fffu)
            {
                Csi2TestModeCtrlReg.bits_st.Csi2TestmodeTestData = (uint16_t)pTestParameters->testModeTestData; // MIPI Test mode Test Data(12bit)
            }
            else
            {
                ErrCode = BC_ERR_INPUTOUTOFRANGE;
            }
            break;
        case e_MIPI_TESTMODE_SINEWAVE:
        case e_MIPI_TESTMODE_SAWTOOTH:
            break;
        case e_MIPI_TESTMODE_PRBS:
            /*Check variable input out of range value(12-bit data)*/
            if (pTestParameters->testModeTestData <= 0x0fffu)
            {
                ErrCode = BC_SPI_Read(e_SYS_MIPI, R2M02_PRBS_CONTROL_U16, &PrbsControl.val_u32);
                if (ErrCode == BC_ERR_NOERROR)
                {
                    PrbsControl.bits_st.InvertPrbsPattern = (uint8_t)pTestParameters->EnInvertPRBSPattern; // PRBS invert
                    PrbsControl.bits_st.PrbsInitialValue = (uint16_t)pTestParameters->testModeTestData;    // PRBS Initial Val(12Bit)
                    ErrCode = BC_SPI_WriteCheck(e_SYS_MIPI, R2M02_PRBS_CONTROL_U16, PrbsControl.val_u32);
                }
            }
            else
            {
                ErrCode = BC_ERR_INPUTOUTOFRANGE;
            }
            break;
        default:
            ErrCode = BC_ERR_INPUTOUTOFRANGE;
            break;
        }
        if (ErrCode == BC_ERR_NOERROR)
        {
            /* writing  the modified value to MIPI test mode register */
            ErrCode = BC_SPI_WriteCheck(e_SYS_MIPI, R2M02_CSI2_TEST_MODE_CONTROL_REG_U16, Csi2TestModeCtrlReg.val_u32);
        }
    }
    if ((pTestParameters == NULL) && (EnTest == TRUE))
    {
        ErrCode = BC_ERR_INPUTOUTOFRANGE;
    }
    /* release functional reset */
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = Helper_MIPIFuncResetRelease(TRUE);
    }
    return ErrCode;
}

/*************** Local Functions *******************/

static BC_ERRCODE Helper_MIPIFuncResetRelease(BOOL ResetRelease)
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
    /* Wait for the device Ready after Functional Reset release */
    if ((ErrCode == BC_ERR_NOERROR) && (ResetRelease == TRUE))
    {
        ErrCode = Helper_MIPIDeviceReadyCheck();
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_MIPI_ConfigMetaData(MIPI_ConfigMetaData_t *pConfigMetaData)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M02_LpMetadataConfig1Union_t LpMetadataConfig1;
    R2M02_LpMetadataConfig2Union_t LpMetadataConfig2;
    R2M02_LpMetadataUserinfoUnion_t LpMetadataUserinfo;
    if (pConfigMetaData == NULL)
    {
        ErrCode = BC_ERR_MIPI_PTR_ADDR_NULL;
    }
    else
    {
        if (!((pConfigMetaData->MetaData_LP_DataType >= 0x30u) && (pConfigMetaData->MetaData_LP_DataType <= 0x37u)))
        {
            ErrCode = BC_ERR_INPUTOUTOFRANGE;
        }
        if (ErrCode == BC_ERR_NOERROR)
        {
            LpMetadataConfig1.val_u32 = 0u;
            LpMetadataConfig1.bits_st.MetadataLpDatatype = (uint8_t)(pConfigMetaData->MetaData_LP_DataType & 0x3Fu);
            LpMetadataConfig1.bits_st.MetadataLpEn = pConfigMetaData->MetaData_LP_En;
            LpMetadataConfig1.bits_st.MetadataLpUserfieldEn = pConfigMetaData->MetaData_LP_UserFieldEn;
            LpMetadataConfig1.bits_st.MetadataLpVc = (uint8_t)(pConfigMetaData->MetaData_LP_VC & 0x03u);
            ErrCode = BC_SPI_WriteCheck(e_SYS_MIPI, R2M02_LP_METADATA_CONFIG1_U16, LpMetadataConfig1.val_u32);
        }
        if ((pConfigMetaData->MetaData_LP_En == TRUE) && (ErrCode == BC_ERR_NOERROR))
        {
            LpMetadataConfig2.val_u32 = 0u;
            LpMetadataConfig2.bits_st.MetadataLpLength = (pConfigMetaData->MetaData_LP_UserFieldEn == FALSE) ? 0x08u : ((pConfigMetaData->MetaData_LP_Length < 80u) ? 80u : pConfigMetaData->MetaData_LP_Length);
            LpMetadataConfig2.bits_st.MetadataLpStartDly = pConfigMetaData->MetaData_LP_StartDelay;
            ErrCode = BC_SPI_WriteCheck(e_SYS_MIPI, R2M02_LP_METADATA_CONFIG2_U16, LpMetadataConfig2.val_u32);
            if (ErrCode == BC_ERR_NOERROR)
            {
                LpMetadataUserinfo.val_u32 = 0u;
                LpMetadataUserinfo.bits_st.MetadataLpUserinfo = pConfigMetaData->MetaData_LP_UserInfo;
                ErrCode = BC_SPI_WriteCheck(e_SYS_MIPI, R2M02_LP_METADATA_USERINFO_U16, LpMetadataUserinfo.val_u32);
            }
        }
    }
    return ErrCode;
}
static BC_ERRCODE Helper_MIPIVirtChannelControl(void)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    /* Reset value of VIRTUAL_CHANNEL_CONTROL is enable 1 VC but still we are setting this again */
    R2M02_VirtualChannelControlUnion_t VirtualChannelCtrl;
    /* Enabling the one VC channel */
    ErrCode = BC_SPI_Read(e_SYS_MIPI, R2M02_VIRTUAL_CHANNEL_CONTROL_U16, &VirtualChannelCtrl.val_u32);
    if (ErrCode == BC_ERR_NOERROR)
    {
        /* Reset value is enable 1 VC but still we are setting this again */
        VirtualChannelCtrl.bits_st.Vc0En = 0x1u;
        ErrCode = BC_SPI_WriteCheck(e_SYS_MIPI, R2M02_VIRTUAL_CHANNEL_CONTROL_U16, VirtualChannelCtrl.val_u32);
    }
    return ErrCode;
}

static BC_ERRCODE Helper_MIPITrimDphy(MIPI_DataRate_e DataRate)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M02_TrimReg1Union_t TrimReg1;
    TrimReg1.val_u32 = 0u;
    R2M02_DphyDfeDlnRegister0Union_t DphyDfeDlnReg0;
    R2M02_DphyDfeDlnRegister1Union_t DphyDfeDlnReg1;
    R2M02_DphyDfeClnRegister0Union_t DphyDfeClnReg0;
    R2M02_DphyDfeClnRegister1Union_t DphyDfeClnReg1;

    /* No read of TRIM_REG1 register is required since all the 32 bit is changed */
    /* For all data rate following value of TRIM1 is same 0x4DB110XX*/
    /* This is done for indentation free code */
    TrimReg1.bits_st.Rtermctrl = 0x1u;
    TrimReg1.bits_st.TrimHstxLdoPd = 0x0u;
    TrimReg1.bits_st.CdlowTrim = 0x3u;
    TrimReg1.bits_st.CdhighTrim = 0x3u;
    TrimReg1.bits_st.Tstodby4 = 0x0u;
    TrimReg1.bits_st.Plltstcksel = 0x3u;
    TrimReg1.bits_st.Res = 0x0u;
    TrimReg1.bits_st.Bwb = 0x4u;
    TrimReg1.bits_st.PllLockTrim = 0x0u;
    TrimReg1.bits_st.LpEnableSelection = 0x1u;
    TrimReg1.bits_st.RefinSel = 0x0u;
    TrimReg1.bits_st.DlpfRegSel = 0x0u;
    TrimReg1.bits_st.Dlpf = 0x0u;
    switch (DataRate)
    {
    case e_MIPI_DATARATE_120:
        /* R2M02_TRIM_REG1 -: 0x4DB11041 */
        TrimReg1.bits_st.Cntb = 0x1u;
        TrimReg1.bits_st.Cnta = 0x1u;

        /* DLN_REG0 default value -: 0x01028004*/
        DphyDfeDlnReg0.bits_st.DfeDlnHsTrial = 0x01u;
        DphyDfeDlnReg0.bits_st.DfeDlnHsExit = 0x02u;
        DphyDfeDlnReg0.bits_st.DfeDlnHsPrepare = 0x80u;
        DphyDfeDlnReg0.bits_st.DfeDlnHsZeroCnt = 0x04u;

        /* DLN_REG1 default value :- 0x00000803 */
        DphyDfeDlnReg1.bits_st.Reserved0 = 0x0u;
        DphyDfeDlnReg1.bits_st.DfeDlnLpxHsCnt = 0x0u;
        DphyDfeDlnReg1.bits_st.DfeDlnSyncCnt = 0x08u;
        DphyDfeDlnReg1.bits_st.DfeDlnRxCnt = 0x03u;

        /* CLN_REG0 default value :- 0x02024003 */
        DphyDfeClnReg0.bits_st.DfeClnHsTrial = 0x02u;
        DphyDfeClnReg0.bits_st.DfeClnHsExit = 0x02u;
        DphyDfeClnReg0.bits_st.DfeClnPrepare = 0x40u;
        DphyDfeClnReg0.bits_st.DfeClnZero = 0x03u;

        /* CLN_REG1 default value:- 0x00070100 */
        DphyDfeClnReg1.bits_st.Reserved0 = 0x00u;
        DphyDfeClnReg1.bits_st.TclkPost = 0x07;
        DphyDfeClnReg1.bits_st.TclkPre = 0x01u;
        DphyDfeClnReg1.bits_st.DfeClnLpxHsCnt = 0x00u;

        break;
    case e_MIPI_DATARATE_240:
        /* R2M02_TRIM_REG1 default value -: 0x4DB11003 */
        TrimReg1.bits_st.Cntb = 0x0u;
        TrimReg1.bits_st.Cnta = 0x3u;

        /* DLN_REG0 default value -: 0x01038106*/
        DphyDfeDlnReg0.bits_st.DfeDlnHsTrial = 0x01u;
        DphyDfeDlnReg0.bits_st.DfeDlnHsExit = 0x03u;
        DphyDfeDlnReg0.bits_st.DfeDlnHsPrepare = 0x81u;
        DphyDfeDlnReg0.bits_st.DfeDlnHsZeroCnt = 0x06u;

        /* DLN_REG1 default value :- 0x00010A03 */
        DphyDfeDlnReg1.bits_st.Reserved0 = 0x0u;
        DphyDfeDlnReg1.bits_st.DfeDlnLpxHsCnt = 0x01u;
        DphyDfeDlnReg1.bits_st.DfeDlnSyncCnt = 0x0Au;
        DphyDfeDlnReg1.bits_st.DfeDlnRxCnt = 0x03u;

        /* CLN_REG0 default value :- 0x03030106 */
        DphyDfeClnReg0.bits_st.DfeClnHsTrial = 0x03u;
        DphyDfeClnReg0.bits_st.DfeClnHsExit = 0x03u;
        DphyDfeClnReg0.bits_st.DfeClnPrepare = 0x01u;
        DphyDfeClnReg0.bits_st.DfeClnZero = 0x06u;

        /* CLN_REG1 default value :- 0x00080101 */
        DphyDfeClnReg1.bits_st.Reserved0 = 0x00u;
        DphyDfeClnReg1.bits_st.TclkPost = 0x08;
        DphyDfeClnReg1.bits_st.TclkPre = 0x01u;
        DphyDfeClnReg1.bits_st.DfeClnLpxHsCnt = 0x01u;

        break;
    case e_MIPI_DATARATE_480:

        /* R2M02_TRIM_REG1 default value -: 0x4DB11006 */
        TrimReg1.bits_st.Cntb = 0x0u;
        TrimReg1.bits_st.Cnta = 0x6u;

        /* DLN_REG0 default value -: 0x03068309*/
        DphyDfeDlnReg0.bits_st.DfeDlnHsTrial = 0x03u;
        DphyDfeDlnReg0.bits_st.DfeDlnHsExit = 0x06u;
        DphyDfeDlnReg0.bits_st.DfeDlnHsPrepare = 0x83u;
        DphyDfeDlnReg0.bits_st.DfeDlnHsZeroCnt = 0x09u;

        /* DLN_REG1 default value :- 0x00030E04 */
        DphyDfeDlnReg1.bits_st.Reserved0 = 0x0u;
        DphyDfeDlnReg1.bits_st.DfeDlnLpxHsCnt = 0x03u;
        DphyDfeDlnReg1.bits_st.DfeDlnSyncCnt = 0x0Eu;
        DphyDfeDlnReg1.bits_st.DfeDlnRxCnt = 0x04u;

        /* CLN_REG0 default value :- 0x0406030E */
        DphyDfeClnReg0.bits_st.DfeClnHsTrial = 0x04u;
        DphyDfeClnReg0.bits_st.DfeClnHsExit = 0x06u;
        DphyDfeClnReg0.bits_st.DfeClnPrepare = 0x03u;
        DphyDfeClnReg0.bits_st.DfeClnZero = 0x0Eu;

        /* CLN_REG1 default value :- 0x000A0102 */
        DphyDfeClnReg1.bits_st.Reserved0 = 0x00u;
        DphyDfeClnReg1.bits_st.TclkPost = 0x0A;
        DphyDfeClnReg1.bits_st.TclkPre = 0x01u;
        DphyDfeClnReg1.bits_st.DfeClnLpxHsCnt = 0x02u;

        break;
    default:
        /* out of range input */
        ErrCode = BC_ERR_INPUTOUTOFRANGE;
        break;
    }

    /* Writing to TRIM_REG1 */
    /* No read modified for TRIM_REG1 register is required since all the 32 bit is changed */
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_SPI_WriteCheck(e_SYS_MIPI, R2M02_TRIM_REG1_U16, TrimReg1.val_u32);
    }
    /* No read modified for DFE_DLN_REG0 register is required since all the 32 bit is changed */
    /* Writing to DFE_DLN_REG0 */
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_SPI_WriteCheck(e_SYS_MIPI, R2M02_DPHY_DFE_DLN_REGISTER_0_U16, DphyDfeDlnReg0.val_u32);
    }
    /* No read modified for DFE_DLN_REG1 register is required since all the 32 bit is changed */
    /* Writing to DFE_DLN_REG1 */
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_SPI_WriteCheck(e_SYS_MIPI, R2M02_DPHY_DFE_DLN_REGISTER_1_U16, DphyDfeDlnReg1.val_u32);
    }
    /* No read modified for DFE_CLN_REG0 register is required since all the 32 bit is changed */
    /* Writing to DFE_CLN_REG0 */
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_SPI_WriteCheck(e_SYS_MIPI, R2M02_DPHY_DFE_CLN_REGISTER_0_U16, DphyDfeClnReg0.val_u32);
    }
    /* No read modified for DFE_CLN_REG1 register is required since all the 32 bit is changed */
    /* Writing to DFE_CLN_REG1 */
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_SPI_WriteCheck(e_SYS_MIPI, R2M02_DPHY_DFE_CLN_REGISTER_1_U16, DphyDfeClnReg1.val_u32);
    }
    return ErrCode;
}
static BC_ERRCODE Helper_MIPIDateLaneSetting(uint8_t NLanes)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M02_PpiDataLaneSwapRegisterUnion_t PpiDataLaneSwapReg;

    if ((NLanes > 0u) && (NLanes <= 4u))
    {
        /* MIPI Lanes setting*/
        ErrCode = BC_SPI_Read(e_SYS_MIPI, R2M02_PPI_DATA_LANE_SWAP_REGISTER_U16, &PpiDataLaneSwapReg.val_u32);
        if (ErrCode == BC_ERR_NOERROR)
        {
            PpiDataLaneSwapReg.bits_st.NumberOfLanes = (uint8_t)(NLanes - 1u); // when 2'11b : Four Lane Enabled( Lane-0,1,2,3)
            ErrCode = BC_SPI_WriteCheck(e_SYS_MIPI, R2M02_PPI_DATA_LANE_SWAP_REGISTER_U16, PpiDataLaneSwapReg.val_u32);
        }
    }
    else
    {
        ErrCode = BC_ERR_INPUTOUTOFRANGE;
    }
    return ErrCode;
}
static BC_ERRCODE Helper_MIPIDeviceReadyCheck(void)
{
    uint32_t WhileLoopCount = 0u;
    R2M02_DeviceReadyIndicationRegisterUnion_t DeviceReadyIndicationReg;
    DeviceReadyIndicationReg.val_u32 = 0u;
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
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

    return ErrCode;
}
static BC_ERRCODE Helper_MIPIStartFreqCounter(MIPI_FreqCountDeviation_e FreqDeviationValue, float32_t CountPeriod, uint32_t *pCountValue)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M02_RefCntrInitUnion_t RefCntrInit;
    R2M02_FreqCounterStartUnion_t FreqCounterStart;

    // Read the reference counter init value and frequency counter
    if (CountPeriod <= 0.0f)
    {
        retVal = BC_ERR_MIPI_FREQCNT_OUTOFRANGE;
    }
    else
    {
        *pCountValue = SYS_CONVERT_TIMEUS_TO_40MHZCYCLE(CountPeriod);
    }
    if ((*pCountValue < 0x10000u) && (*pCountValue != 0u) && (CountPeriod <= MIPI_LVDS_MAX_FREQ_COUNT_PERIOD)) // Ref count val less than 16 bit and to avoid divide by zero
    {
        float32_t IdealCount = (MIPI_IDEAL480_DEFAULT_VALUE * CountPeriod);
        RefCntrInit.bits_st.Ideal480CountValue = (uint16_t)IdealCount;
        RefCntrInit.bits_st.RefCountValue = (uint16_t)*pCountValue;
        retVal = BC_SPI_WriteCheck(e_SYS_MIPI, R2M02_REF_CNTR_INIT_U16, RefCntrInit.val_u32);
    }
    else
    {
        retVal = BC_ERR_MIPI_FREQCNT_OUTOFRANGE;
    }

    if (retVal == BC_ERR_NOERROR)
    {
        /* Removed SPI read register since all required fields are initialized below */
        FreqCounterStart.val_u32 = 0x0u;                                             /* setting frequency counter trigger */
        FreqCounterStart.bits_st.FreqCounterTriggerSel = 0x0u;                       // 0: trigger from writing to this register
        FreqCounterStart.bits_st.FreqCounterDeviation = (uint8_t)FreqDeviationValue; // Freq counter deviation
        /* Resetting the FreqStart */
        FreqCounterStart.bits_st.FreqStart = 0x0u;
        retVal = BC_SPI_Write(e_SYS_MIPI, R2M02_FREQ_COUNTER_START_U16, FreqCounterStart.val_u32);
        if (retVal == BC_ERR_NOERROR)
        {
            /* Start measurement */
            FreqCounterStart.bits_st.FreqStart = 0x1u;
            /* No write check since this is auto clear bit */
            retVal = BC_SPI_Write(e_SYS_MIPI, R2M02_FREQ_COUNTER_START_U16, FreqCounterStart.val_u32);
        }
    }
    return retVal;
}
static BC_ERRCODE Helper_MIPIFreqCounterWait(R2M02_FreqCounterReadValueUnion_t *pFreqCounterReadValue, BC_ERRCODE *pTempRetcode)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    uint32_t WhileLoopCount = 0u;
    /* Wait till frequency counter is finished */
    do
    {
        retVal = PLF_TM_Sleep(MIPI_MEASUREFREQ_SLEEP);
        if (retVal == BC_ERR_NOERROR)
        {
            retVal = BC_SPI_Read(e_SYS_MIPI, R2M02_FREQ_COUNTER_READ_VALUE_U16, &pFreqCounterReadValue->val_u32);
        }
        if ((retVal == BC_ERR_NOERROR) && (WhileLoopCount >= MIPI_FREQ_COUNT_TIMEOUT))
        {
            // since max CountPeriod is 1.6 miliseconds it okay to time out wait is 100miliseconds
            *pTempRetcode = BC_ERR_MIPI_FREQCOUNTTIMEOUT;
        }
        WhileLoopCount++;
        /* This is busy wait, so no need to have sleep, only SPI channel will be busy */
    } while ((pFreqCounterReadValue->bits_st.DoneFlag == 0x0u) && (retVal == BC_ERR_NOERROR) && (*pTempRetcode == BC_ERR_NOERROR));
    return retVal;
}

static BC_ERRCODE Helper_MIPIFreqCountVal(float32_t *pFrequency, uint32_t *pCountValue)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    BC_ERRCODE TempRetcode = BC_ERR_NOERROR;
    R2M02_FreqCounterReadValueUnion_t FreqCounterReadValue;
    FreqCounterReadValue.val_u32 = 0u;
    R2M02_RefCntrInitUnion_t RefCntrInit;

    retVal = Helper_MIPIFreqCounterWait(&FreqCounterReadValue, &TempRetcode);

    /* Compute the frequency count value and it is based on reference counter init reg value.*/
    if ((TempRetcode == BC_ERR_NOERROR) && (retVal == BC_ERR_NOERROR) && (FreqCounterReadValue.bits_st.DoneFlag == 0x1u))
    {
        retVal = BC_SPI_Read(e_SYS_MIPI, R2M02_FREQ_COUNTER_READ_VALUE_U16, &FreqCounterReadValue.val_u32);
        if (retVal == BC_ERR_NOERROR)
        {
            // Reference count time default is d'40(40MHz).
            *pFrequency = (float32_t)((float32_t)FreqCounterReadValue.bits_st.FreqCountValue / ((float32_t)*pCountValue / 40.0f));
            *pFrequency = (*pFrequency) * ((float32_t)1000000.0f); // Converting frequency from MHz to Hz
        }
    }
    if (retVal == BC_ERR_NOERROR)
    {
        retVal = Helper_MIPIRestoreFreqCounter();
    }
    // Restore REF_CNTR_INIT content to default after measurement is complete
    if (retVal == BC_ERR_NOERROR)
    {
        RefCntrInit.bits_st.Ideal480CountValue = (uint16_t)MIPI_IDEAL480_DEFAULT_VALUE;
        RefCntrInit.bits_st.RefCountValue = MIPI_REFCOUNT_DEFAULT_VALUE;
        retVal = BC_SPI_WriteCheck(e_SYS_MIPI, R2M02_REF_CNTR_INIT_U16, RefCntrInit.val_u32);
    }
    if (retVal == BC_ERR_NOERROR)
    {
        retVal = (TempRetcode == BC_ERR_MIPI_FREQCOUNTTIMEOUT) ? BC_ERR_MIPI_FREQCOUNTTIMEOUT : retVal;
    }
    return retVal;
}
static BC_ERRCODE Helper_MIPIRestoreFreqCounter(void)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M02_FreqCounterStartUnion_t FreqCounterStart;
    R2M02_FreqCounterStartUnion_t FreqCounterStartRead;
    FreqCounterStart.val_u32 = 0x0u;
    // FreqCounterTriggerSel always restored even it is succcess or failure of frequency counter read value
    FreqCounterStart.bits_st.FreqCounterDeviation = 3u;    // e_MIPI_IGNOR_ZERO_ONE_BITS
    FreqCounterStart.bits_st.FreqCounterTriggerSel = 0x1u; // Restored the FreqCounter Trigger Select
    /*Error code is not returned since it overwrites the timeout error*/
    retVal = BC_SPI_Write(e_SYS_MIPI, R2M02_FREQ_COUNTER_START_U16, FreqCounterStart.val_u32);
    if (retVal == BC_ERR_NOERROR)
    {
        retVal = BC_SPI_Read(e_SYS_MIPI, R2M02_FREQ_COUNTER_START_U16, &FreqCounterStartRead.val_u32);
        if (retVal == BC_ERR_NOERROR)
        {
            // Checking the FreqCounterDeviation and FreqCounterTriggerSel value restored correctly
            if ((FreqCounterStartRead.bits_st.FreqCounterDeviation != FreqCounterStart.bits_st.FreqCounterDeviation) &&
                (FreqCounterStartRead.bits_st.FreqCounterTriggerSel != FreqCounterStart.bits_st.FreqCounterTriggerSel))
            {
                retVal = BC_ERR_MIPI_RESTORE_FREQ_COUNTER;
            }
        }
    }
    return retVal;
}
#endif
/******** End of File *************/
