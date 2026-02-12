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
#include "v_es2_ism.h"
#include "v_es2_tx.h"
#include "v_es2_rx.h"
#include "v_es2_cafc.h"
#include "v_es2_otp.h"
#include "v_es2_mclk.h"
#include "v_es2_loi.h"
#include "v_es2_gldo.h"
#include "v_es2_gbias.h"
#include "v_es2_lvds.h"
#include "v_es2_mipi.h"
#include "v_es2_atb.h"
#include "v_es2_adc.h"
#include "v_es2_cc.h"
#else
#include "reg_es2_ism.h"
#include "reg_es2_tx.h"
#include "reg_es2_rx.h"
#include "reg_es2_cafc.h"
#include "reg_es2_otp.h"
#include "reg_es2_mclk.h"
#include "reg_es2_loi.h"
#include "reg_es2_gldo.h"
#include "reg_es2_gbias.h"
#include "reg_es2_lvds.h"
#include "reg_es2_mipi.h"
#include "reg_es2_atb.h"
#include "reg_es2_adc.h"
#include "reg_es2_cc.h"
#endif

#include "bc_spi.h"
#include "hal_es2_ism.h"
#include "hal_es2_cc.h"
#include "bc_types.h"
#include "bc_err.h"
#include "bc_cc.h"
#include "plf.h"
#include "bc_conf.h"

/* Local Function difinition */
static BC_ERRCODE CreatFITMask(uint32_t *pTxFITMask, uint32_t *pRxFITMask, uint32_t *pADCFITMask, uint32_t *pChirpFITMask, uint32_t *pGrp1FITMask, uint32_t *pGrp2FITMask);

/* Functions */
/*Configuration of GPIO Input and Output Mode*/
static BC_ERRCODE ConfigGPIOInputOutputMode(BOOL Direction, uint8_t PinDataPos, SYS_ExtPinID_e HostPinID, uint32_t LoopBackTestValue);
/*Configuration of GPIO Input Mode*/
static BC_ERRCODE ConfigGPIOInputMode(uint8_t PinDataPos, SYS_ExtPinID_e HostPinID, uint32_t LoopBackTestValue);
/*Configuration of GPIO Output Mode*/
static BC_ERRCODE ConfigGPIOOutputMode(uint8_t PinDataPos, SYS_ExtPinID_e HostPinID, uint32_t LoopBackTestValue);

static void Helper_Msk_ES2_RTMSetClrRx1Err(ISM_ErrCmd_e CmdReg, SYS_RXErrors_t *pRxErr, R2M18_RxErrorMaskRegUnion_t *pRxErrorMask);
static void Helper_Msk_ES2_RTMSetClrRx2Err(ISM_ErrCmd_e CmdReg, SYS_RXErrors_t *pRxErr, R2M18_RxErrorMaskRegUnion_t *pRxErrorMask);
static void Helper_Msk_ES2_RTMSetClrRx3Err(ISM_ErrCmd_e CmdReg, SYS_RXErrors_t *pRxErr, R2M18_RxErrorMaskRegUnion_t *pRxErrorMask);
static void Helper_Msk_ES2_RTMSetClrRx4Err(ISM_ErrCmd_e CmdReg, SYS_RXErrors_t *pRxErr, R2M18_RxErrorMaskRegUnion_t *pRxErrorMask);
static BC_ERRCODE Helper_Mon_ES2_RTMSetClrRxErr(SYS_RXErrors_t *pRx1Err, SYS_RXErrors_t *pRx2Err, SYS_RXErrors_t *pRx3Err, SYS_RXErrors_t *pRx4Err);
static BC_ERRCODE Helper_Clr_ES2_RTMSetClrRxErr(SYS_RXErrors_t *pRx1Err, SYS_RXErrors_t *pRx2Err, SYS_RXErrors_t *pRx3Err, SYS_RXErrors_t *pRx4Err);
static BC_ERRCODE Helper_Set_ES2_RTMSetClrRxErr(SYS_RXErrors_t *pRx1Err, SYS_RXErrors_t *pRx2Err, SYS_RXErrors_t *pRx3Err, SYS_RXErrors_t *pRx4Err);
static void Helper_Msk_ES2_RTMSetClrTx1Err(ISM_ErrCmd_e CmdReg, SYS_TXErrors_t *pTxErr, R2M18_TxErrorMaskRegUnion_t *pTxErrorMask);
static void Helper_Msk_ES2_RTMSetClrTx2Err(ISM_ErrCmd_e CmdReg, SYS_TXErrors_t *pTxErr, R2M18_TxErrorMaskRegUnion_t *pTxErrorMask);
static void Helper_Msk_ES2_RTMSetClrTx3Err(ISM_ErrCmd_e CmdReg, SYS_TXErrors_t *pTxErr, R2M18_TxErrorMaskRegUnion_t *pTxErrorMask);
static BC_ERRCODE Helper_Mon_ES2_RTMSetClrTxErr(SYS_TXErrors_t *pTx1Err, SYS_TXErrors_t *pTx2Err, SYS_TXErrors_t *pTx3Err);
static BC_ERRCODE Helper_Clr_ES2_RTMSetClrTxErr(SYS_TXErrors_t *pTx1Err, SYS_TXErrors_t *pTx2Err, SYS_TXErrors_t *pTx3Err);
static BC_ERRCODE Helper_Set_ES2_RTMSetClrTxErr(SYS_TXErrors_t *pTx1Err, SYS_TXErrors_t *pTx2Err, SYS_TXErrors_t *pTx3Err);

static BC_ERRCODE Helper_Mon_ES2_RTMSetClrADCErr(SYS_ADCErrors_t *pADC12Err, SYS_ADCErrors_t *pADC34Err);
static BC_ERRCODE Helper_Msk_ES2_RTMSetClrADCErr(ISM_ErrCmd_e CmdReg, SYS_ADCErrors_t *pADC12Err, SYS_ADCErrors_t *pADC34Err);
static BC_ERRCODE Helper_Set_ES2_RTMSetClrADCErr(SYS_ADCErrors_t *pADC12Err, SYS_ADCErrors_t *pADC34Err);
static BC_ERRCODE Helper_Clr_ES2_RTMSetClrADCErr(SYS_ADCErrors_t *pADC12Err, SYS_ADCErrors_t *pADC34Err);

static BC_ERRCODE Helper_Msk_ES2_RTMSetClrChirpErr(ISM_ErrCmd_e CmdReg, SYS_CAFCErrors_t *pChirpErr);
static BC_ERRCODE Helper_Mon_ES2_RTMSetClrChirpErr(SYS_CAFCErrors_t *pChirpErr);
static BC_ERRCODE Helper_Clr_ES2_RTMSetClrChirpErr(SYS_CAFCErrors_t *pChirpErr);
static BC_ERRCODE Helper_Set_ES2_RTMSetClrChirpErr(SYS_CAFCErrors_t *pChirpErr);

static BC_ERRCODE Helper_Msk_ES2_RTMSetClrSSGAErr(ISM_ErrCmd_e CmdReg, BOOL ATBRegCRCErr, SYS_SerialiserErrors_t *pSerErr, SYS_SSBErrors_t *pSSBErr, SYS_GBIASErrors_t *pGBErr, SYS_GLDOErrors_t *pGLDOErr);
static BC_ERRCODE Helper_Mon_ES2_RTMSetClrSSGAErr(BOOL ATBRegCRCErr, SYS_SerialiserErrors_t *pSerErr, SYS_SSBErrors_t *pSSBErr, SYS_GBIASErrors_t *pGBErr, SYS_GLDOErrors_t *pGLDOErr);
static BC_ERRCODE Helper_Clr_ES2_RTMSetClrSSGAErr(BOOL ATBRegCRCErr, SYS_SerialiserErrors_t *pSerErr, SYS_SSBErrors_t *pSSBErr, SYS_GBIASErrors_t *pGBErr, SYS_GLDOErrors_t *pGLDOErr);
static BC_ERRCODE Helper_Set_ES2_RTMSetClrSSGAErr(BOOL ATBRegCRCErr, SYS_SerialiserErrors_t *pSerErr, SYS_SSBErrors_t *pSSBErr, SYS_GBIASErrors_t *pGBErr, SYS_GLDOErrors_t *pGLDOErr);

static BC_ERRCODE Helper_Msk_ES2_RTMSetClrMCOIErr(ISM_ErrCmd_e CmdReg, BOOL OTPRegCRCErr, BOOL ISMRegCRCErr, SYS_MCLKErrors_t *pMClkErr, SYS_LOIErrors_t *pLOIErr, SYS_CCErrors_t *pCCErr);
static BC_ERRCODE Helper_Mon_ES2_RTMSetClrMCOIErr(BOOL OTPRegCRCErr, SYS_MCLKErrors_t *pMClkErr, SYS_LOIErrors_t *pLOIErr);
static BC_ERRCODE Helper_Set_ES2_RTMSetClrMCOIErr(BOOL OTPRegCRCErr, BOOL ISMRegCRCErr, SYS_MCLKErrors_t *pMClkErr, SYS_LOIErrors_t *pLOIErr, SYS_CCErrors_t *pCCErr);
static BC_ERRCODE Helper_Clr_ES2_RTMSetClrMCOIErr(BOOL OTPRegCRCErr, BOOL ISMRegCRCErr, SYS_MCLKErrors_t *pMClkErr, SYS_LOIErrors_t *pLOIErr, SYS_CCErrors_t *pCCErr);

static BC_ERRCODE Helper_ISM_FIT_ES2(void);
static BC_ERRCODE Helper_ISMGetTxMaskedError(SYS_TXErrors_t *pTx1Err, SYS_TXErrors_t *pTx2Err, SYS_TXErrors_t *pTx3Err, uint32_t *pModuleErr);
static BC_ERRCODE Helper_ISMGetTxRawError(SYS_TXErrors_t *pTx1Err, SYS_TXErrors_t *pTx2Err, SYS_TXErrors_t *pTx3Err, uint32_t *pModuleErr);
static BC_ERRCODE Helper_ISMGetTxFitStatus(SYS_TXErrors_t *pTx1Err, SYS_TXErrors_t *pTx2Err, SYS_TXErrors_t *pTx3Err, uint32_t *pModuleErr);
static BC_ERRCODE Helper_ISMGetRxMaskedError(SYS_RXErrors_t *pRx1Err, SYS_RXErrors_t *pRx2Err, SYS_RXErrors_t *pRx3Err, SYS_RXErrors_t *pRx4Err, uint32_t *pModuleErr);
static BC_ERRCODE Helper_ISMGetRxRawError(SYS_RXErrors_t *pRx1Err, SYS_RXErrors_t *pRx2Err, SYS_RXErrors_t *pRx3Err, SYS_RXErrors_t *pRx4Err, uint32_t *pModuleErr);
static BC_ERRCODE Helper_ISMGetRxFitStatus(SYS_RXErrors_t *pRx1Err, SYS_RXErrors_t *pRx2Err, SYS_RXErrors_t *pRx3Err, SYS_RXErrors_t *pRx4Err, uint32_t *pModuleErr);
static BC_ERRCODE Helper_RTMSetTxErr(SYS_TXErrors_t *pTx1Err, SYS_TXErrors_t *pTx2Err, SYS_TXErrors_t *pTx3Err);
static BC_ERRCODE Helper_RTMResetTxErr(SYS_IPNum_e TXIP, SYS_TXErrors_t *pTxErr);
static BC_ERRCODE Helper_RTMSetRxErr(SYS_RXErrors_t *pRx1Err, SYS_RXErrors_t *pRx2Err, SYS_RXErrors_t *pRx3Err, SYS_RXErrors_t *pRx4Err);
static BC_ERRCODE Helper_RTMResetRxErr(SYS_IPNum_e RXIP, SYS_RXErrors_t *pRxErr);
static uint8_t Helper_RTMValidateMask(BOOL RegErr, uint8_t SetValue, uint8_t FlagMask);
static BC_ERRCODE Helper_RTMSetClrGldo(SYS_IPList_t AppConfig, R2M18_SsbGbSerGldoAtbErrorMonRegUnion_t *pSsbGbSerGldoAtbErrorMon, SYS_GLDOErrors_t *pGLDOErr);
static BC_ERRCODE Helper_RTMSetClrGbias(SYS_IPList_t AppConfig, R2M18_SsbGbSerGldoAtbErrorMonRegUnion_t *pSsbGbSerGldoAtbErrorMon, SYS_GBIASErrors_t *pGBErr);
static BC_ERRCODE Helper_RTMSetClrLvdsMipi(SYS_IPList_t AppConfig, R2M18_SsbGbSerGldoAtbErrorMonRegUnion_t *pSsbGbSerGldoAtbErrorMon, SYS_SerialiserErrors_t *pSerErr);
static BC_ERRCODE Helper_ISMSetForceError(void);
static BC_ERRCODE Helper_ISMSetClrForceResetErr(void);
static BC_ERRCODE Helper_ISMRemoveResetErr(void);
static BC_ERRCODE Helper_ISMCheckFitErr(void);
static ISM_Cal_Status_e Helper_ISMValidateCalibStatus(uint32_t BusyStatus, uint32_t ErrorStatus);
static BC_ERRCODE Helper_TglTstERstChrStErNTx(SYS_ExtPinID_e PinId, BOOL Direction, uint32_t LoopBackTestValue);
static BC_ERRCODE Helper_TglTstTxTxQPs(SYS_ExtPinID_e PinId, BOOL Direction, uint32_t LoopBackTestValue);
static BC_ERRCODE Helper_TglTstAllPinsSet1(uint32_t LoopBackTestValue);
static BC_ERRCODE Helper_TglTstAllPinsSet2(uint32_t LoopBackTestValue);
static BC_ERRCODE CreatTxFITMask(uint32_t *pTxFITMask, SYS_IPList_t *pAppConfig);
static BC_ERRCODE CreatRxFITMask(uint32_t *pRxFITMask, SYS_IPList_t *pAppConfig);
static BC_ERRCODE CreatChirpADCFITMask(uint32_t *pChirpFITMask, uint32_t *pADCFITMask, SYS_IPList_t *pAppConfig);
static BC_ERRCODE CreatGrp1Grp2FITMask(uint32_t *pGrp1FITMask, uint32_t *pGrp2FITMask, SYS_IPList_t *pAppConfig);

static BC_ERRCODE Helper_ISMCheckFitErr(void)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M18_IsmFitTestRegUnion_t IsmFitTestReg;

    /* check the FIT state */
    retVal = BC_SPI_Read(e_SYS_ISM, R2M18_ISM_FIT_TEST_REG_U16, &IsmFitTestReg.val_u32);
    if (retVal == BC_ERR_NOERROR)
    {
        if ((IsmFitTestReg.bits_st.IsmTestCurrentstate != (uint8_t)e_ISM_FIT_COMPLETE) ||
            (IsmFitTestReg.bits_st.IsmTestComplete != (uint8_t)0x1u) ||
            (IsmFitTestReg.bits_st.FitStatusRtm0 != (uint8_t)0x1u) ||
            (IsmFitTestReg.bits_st.FitStatusRtm1 != (uint8_t)0x1u))
        {
            retVal = BC_ERR_ISM_FIT_FAILED;
        }
    }
    return retVal;
}

static BC_ERRCODE Helper_ISMRemoveResetErr(void)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M18_IsmFitTestRegUnion_t IsmFitTestReg;
    BOOL ErrorNHigh;

    /* wait of 10 CLK is enough = 250ns */
    /* check the FIT state */
    retVal = BC_SPI_Read(e_SYS_ISM, R2M18_ISM_FIT_TEST_REG_U16, &IsmFitTestReg.val_u32);
    if (retVal == BC_ERR_NOERROR)
    {
        if (IsmFitTestReg.bits_st.IsmTestCurrentstate == (uint8_t)e_ISM_FIT_RESET_STATE)
        {
            /* Check error n pin it should be high */
            retVal = PLF_HIO_GetIO(e_SYS_ERRORN, &ErrorNHigh);
            if ((retVal != BC_ERR_NOERROR) || (ErrorNHigh != TRUE))
            {
                retVal = BC_ERR_ISM_FIT_RESET_ERROR_FAILED;
            }
        }
        else
        {
            retVal = BC_ERR_ISM_FIT_RESET_STATE_CHANGE_FAILED;
        }
    }
    if (retVal == BC_ERR_NOERROR)
    {
        /* Remove the reset */
        IsmFitTestReg.bits_st.IsmOsmTestResetError = 0x0u; //
        retVal = BC_SPI_Write(e_SYS_ISM, R2M18_ISM_FIT_TEST_REG_U16, IsmFitTestReg.val_u32);
    }
    return retVal;
}

static BC_ERRCODE Helper_ISMSetClrForceResetErr(void)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M18_IsmFitTestRegUnion_t IsmFitTestReg;
    BOOL ErrorNHigh;
    /* wait of 10 CLK is enough = 250ns */
    /* check the FIT state */
    retVal = BC_SPI_Read(e_SYS_ISM, R2M18_ISM_FIT_TEST_REG_U16, &IsmFitTestReg.val_u32);
    if (retVal == BC_ERR_NOERROR)
    {
        if (IsmFitTestReg.bits_st.IsmTestCurrentstate == (uint8_t)e_ISM_FIT_FORCE_STATE)
        {
            /* check error_n pin should be low */
            retVal = PLF_HIO_GetIO(e_SYS_ERRORN, &ErrorNHigh);
            if ((retVal != BC_ERR_NOERROR) || (ErrorNHigh != FALSE))
            {
                retVal = BC_ERR_ISM_FIT_FORCE_ERROR_FAILED;
            }
        }
        else
        {
            retVal = BC_ERR_ISM_FIT_FORCE_STATE_CHANGE_FAILED;
        }
    }

    /* Force error is success now FIT reset error */
    if (retVal == BC_ERR_NOERROR)
    {
        /* remove force error */
        IsmFitTestReg.bits_st.IsmOsmTestForceError = 0x0u;
        retVal = BC_SPI_Write(e_SYS_ISM, R2M18_ISM_FIT_TEST_REG_U16, IsmFitTestReg.val_u32);
    }
    if (retVal == BC_ERR_NOERROR)
    {
        /*  set reset error */
        IsmFitTestReg.bits_st.IsmOsmTestResetError = 0x1u;
        retVal = BC_SPI_Write(e_SYS_ISM, R2M18_ISM_FIT_TEST_REG_U16, IsmFitTestReg.val_u32);
    }
    return retVal;
}

static BC_ERRCODE Helper_ISMSetForceError(void)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M18_IsmFitTestRegUnion_t IsmFitTestReg;
    BOOL ErrorNHigh = FALSE;
    retVal = PLF_HIO_GetIO(e_SYS_ERRORN, &ErrorNHigh);
    if ((retVal == BC_ERR_NOERROR) && (ErrorNHigh == TRUE))
    {
        retVal = BC_SPI_Read(e_SYS_ISM, R2M18_ISM_FIT_TEST_REG_U16, &IsmFitTestReg.val_u32);
    }
    else
    {
        retVal = (retVal == BC_ERR_NOERROR) ? BC_ERR_ISM_FIT_ERROR_N_HIGH : retVal;
    }
    if (retVal == BC_ERR_NOERROR)
    {
        IsmFitTestReg.bits_st.IsmOsmTestForceError = 0x1u; // FIT Start
        IsmFitTestReg.bits_st.IsmOsmTestResetError = 0x0u; //
        retVal = BC_SPI_Write(e_SYS_ISM, R2M18_ISM_FIT_TEST_REG_U16, IsmFitTestReg.val_u32);
    }
    return retVal;
}

static ISM_Cal_Status_e Helper_ISMValidateCalibStatus(uint32_t BusyStatus, uint32_t ErrorStatus)
{
    ISM_Cal_Status_e RetVal;
    if (BusyStatus == TRUE)
    {
        RetVal = e_ISM_CAL_BUSY;
    }
    else
    {
        if (ErrorStatus == TRUE)
        {
            RetVal = e_ISM_CAL_ERROR;
        }
        else
        {
            RetVal = e_ISM_CAL_SUCCESS;
        }
    }
    return RetVal;
}

static BC_ERRCODE Helper_TglTstAllPinsSet1(uint32_t LoopBackTestValue)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;

    // ERRORRESET
    retVal = ConfigGPIOInputOutputMode(TRUE, ERRORRESET_DATA_POS, e_SYS_ERRORRESET, LoopBackTestValue);
    // Error N
    if (retVal == BC_ERR_NOERROR)
    {
        retVal = ConfigGPIOInputOutputMode(FALSE, ERRORN_DATA_POS, e_SYS_ERRORN, LoopBackTestValue);
    }
    // Ready int dir
    if (retVal == BC_ERR_NOERROR)
    {
        retVal = ConfigGPIOInputOutputMode(FALSE, READYINT_DATA_POS, e_SYS_MCUINT_CHIRPSTART_OUT_PAD, LoopBackTestValue);
    }
    // Chirp Start
    if (retVal == BC_ERR_NOERROR)
    {
        retVal = ConfigGPIOInputOutputMode(TRUE, CHIRPSTART_DATA_POS, e_SYS_CHIRPSTART_IN_PAD, LoopBackTestValue);
    }
    // Tx3_Q_PS
    if (retVal == BC_ERR_NOERROR)
    {
        retVal = ConfigGPIOInputOutputMode(TRUE, TX3_Q_PS_DATA_POS, e_SYS_TX3_Q_PS, LoopBackTestValue);
    }
    // Tx2_Q_PS
    if (retVal == BC_ERR_NOERROR)
    {
        retVal = ConfigGPIOInputOutputMode(TRUE, TX2_Q_PS_DATA_POS, e_SYS_TX2_Q_PS, LoopBackTestValue);
    }

    return retVal;
}
static BC_ERRCODE Helper_TglTstAllPinsSet2(uint32_t LoopBackTestValue)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;

    // Tx1_Q_PS
    retVal = ConfigGPIOInputOutputMode(TRUE, TX1_Q_PS_DATA_POS, e_SYS_TX1_Q_PS, LoopBackTestValue);
    // Tx3_I_PS
    if (retVal == BC_ERR_NOERROR)
    {
        retVal = ConfigGPIOInputOutputMode(TRUE, TX3_I_PS_DATA_POS, e_SYS_TX3_I_PS, LoopBackTestValue);
    }
    // Tx2_I_PS
    if (retVal == BC_ERR_NOERROR)
    {
        retVal = ConfigGPIOInputOutputMode(TRUE, TX2_I_PS_DATA_POS, e_SYS_TX2_I_PS, LoopBackTestValue);
    }
    // Tx1_I_PS
    if (retVal == BC_ERR_NOERROR)
    {
        retVal = ConfigGPIOInputOutputMode(TRUE, TX1_I_PS_DATA_POS, e_SYS_TX1_I_PS, LoopBackTestValue);
    }
    return retVal;
}
static BC_ERRCODE Helper_TglTstERstChrStErNTx(SYS_ExtPinID_e PinId, BOOL Direction, uint32_t LoopBackTestValue)
{
    R2M18_LoopBackTestRegUnion_t LoopBackTest;
    LoopBackTest.val_u32 = LoopBackTestValue;
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    if (PinId == e_SYS_ERRORRESET)
    {
        // ERRORRESET
        LoopBackTest.bits_st.ErrorResetDir = Direction;
        retVal = ConfigGPIOInputOutputMode(Direction, ERRORRESET_DATA_POS, PinId, LoopBackTest.val_u32);
    }
    if (PinId == e_SYS_CHIRPSTART_IN_PAD)
    {
        // Chirp Start
        LoopBackTest.bits_st.ChirpStartDir = Direction;
        retVal = ConfigGPIOInputOutputMode(Direction, CHIRPSTART_DATA_POS, PinId, LoopBackTest.val_u32);
    }
    if (PinId == e_SYS_MCUINT_CHIRPSTART_OUT_PAD)
    {
        // Ready int dir
        LoopBackTest.bits_st.ReadyIntDir = Direction;
        retVal = ConfigGPIOInputOutputMode(Direction, READYINT_DATA_POS, PinId, LoopBackTest.val_u32);
    }
    if (PinId == e_SYS_ERRORN)
    {
        // Error N
        LoopBackTest.bits_st.ErrorNDir = Direction;
        retVal = ConfigGPIOInputOutputMode(Direction, ERRORN_DATA_POS, PinId, LoopBackTest.val_u32);
    }
    if (PinId == e_SYS_TX1_I_PS)
    {
        // Tx1_I_PS
        LoopBackTest.bits_st.Tx1IPsDir = Direction;
        retVal = ConfigGPIOInputOutputMode(Direction, TX1_I_PS_DATA_POS, PinId, LoopBackTest.val_u32);
    }
    if (PinId == e_SYS_TX2_I_PS)
    {
        // Tx2_I_PS
        LoopBackTest.bits_st.Tx2IPsDir = Direction;
        retVal = ConfigGPIOInputOutputMode(Direction, TX2_I_PS_DATA_POS, PinId, LoopBackTest.val_u32);
    }
    return retVal;
}
static BC_ERRCODE Helper_TglTstTxTxQPs(SYS_ExtPinID_e PinId, BOOL Direction, uint32_t LoopBackTestValue)
{
    R2M18_LoopBackTestRegUnion_t LoopBackTest;
    LoopBackTest.val_u32 = LoopBackTestValue;
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    if (PinId == e_SYS_TX3_I_PS)
    {
        // Tx3_I_PS
        LoopBackTest.bits_st.Tx3IPsDir = Direction;
        retVal = ConfigGPIOInputOutputMode(Direction, TX3_I_PS_DATA_POS, PinId, LoopBackTest.val_u32);
    }
    if (PinId ==  e_SYS_TX1_Q_PS)
    {
        // Tx1_Q_PS
        LoopBackTest.bits_st.Tx1QPsDir = Direction;
        retVal = ConfigGPIOInputOutputMode(Direction, TX1_Q_PS_DATA_POS, PinId, LoopBackTest.val_u32);
    }
    if (PinId == e_SYS_TX2_Q_PS)
    {
        // Tx2_Q_PS
        LoopBackTest.bits_st.Tx2QPsDir = Direction;
        retVal = ConfigGPIOInputOutputMode(Direction, TX2_Q_PS_DATA_POS, PinId, LoopBackTest.val_u32);
    }
    if (PinId == e_SYS_TX3_Q_PS)
    {
        // Tx3_Q_PS
        LoopBackTest.bits_st.Tx3QPsDir = Direction;
        retVal = ConfigGPIOInputOutputMode(Direction, TX3_Q_PS_DATA_POS, PinId, LoopBackTest.val_u32);
    }
    return retVal;
}

static uint8_t Helper_RTMValidateMask(BOOL RegErr, uint8_t SetValue, uint8_t FlagMask)
{
    uint8_t RetVal;
    if (RegErr == TRUE)
    {
        RetVal = SetValue;
    }
    else
    {
        RetVal = FlagMask;
    }
    return RetVal;
}

static BC_ERRCODE Helper_RTMSetClrLvdsMipi(SYS_IPList_t AppConfig, R2M18_SsbGbSerGldoAtbErrorMonRegUnion_t *pSsbGbSerGldoAtbErrorMon, SYS_SerialiserErrors_t *pSerErr)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M01_MaskCcResetErrorUnion_t LVDSMaskCcResetError;
    R2M02_MaskCcResetErrorUnion_t MIPIMaskCcResetError;

    if (pSerErr != NULL)
    {
        // Serialiser
        pSsbGbSerGldoAtbErrorMon->bits_st.SupplyLowErrorFlag1V8SerMon = (uint8_t)pSerErr->Supply1v8SerLowErr;
        pSsbGbSerGldoAtbErrorMon->bits_st.SupplyLowErrorFlag1V1Csi2Mon = (uint8_t)pSerErr->Supply1v1MIPILowErr;
        pSsbGbSerGldoAtbErrorMon->bits_st.SupplyLowErrorFlag1V1SerMon = (uint8_t)pSerErr->Supply1v1LVDSLowErr;

        if (TRUE == AppConfig.LVDS)
        {
            retVal = BC_SPI_Read(e_SYS_LVDS, R2M01_MASK_CC_RESET_ERROR_U16, &LVDSMaskCcResetError.val_u32);
            if (retVal == BC_ERR_NOERROR)
            {
                /*Mask Reset ERROR for LVDS*/
                LVDSMaskCcResetError.bits_st.MaskRegCrcResetError = (uint8_t)pSerErr->SerRegCRCErr;
                LVDSMaskCcResetError.bits_st.MaskSupply1V1SerLowResetError = (uint8_t)pSerErr->Supply1v1LVDSLowErr;
                LVDSMaskCcResetError.bits_st.MaskSupply1V8LowResetError = (uint8_t)pSerErr->Supply1v8SerLowErr;
                retVal = BC_SPI_WriteCheck(e_SYS_LVDS, R2M01_MASK_CC_RESET_ERROR_U16, LVDSMaskCcResetError.val_u32);
            }
        }
        if ((retVal == BC_ERR_NOERROR) && (TRUE == AppConfig.MIPI))
        {
            retVal = BC_SPI_Read(e_SYS_MIPI, R2M02_MASK_CC_RESET_ERROR_U16, &MIPIMaskCcResetError.val_u32);
            if (retVal == BC_ERR_NOERROR)
            {
                /*Mask Reset ERROR for MIPI*/
                MIPIMaskCcResetError.bits_st.MaskRegCrcResetError = (uint8_t)pSerErr->SerRegCRCErr;
                MIPIMaskCcResetError.bits_st.MaskSupply1V1Csi2LowResetError = (uint8_t)pSerErr->Supply1v1MIPILowErr;
                MIPIMaskCcResetError.bits_st.MaskSupply1V8LowResetError = (uint8_t)pSerErr->Supply1v8SerLowErr;
                retVal = BC_SPI_WriteCheck(e_SYS_MIPI, R2M02_MASK_CC_RESET_ERROR_U16, MIPIMaskCcResetError.val_u32);
            }
        }
    }
    return retVal;
}

static BC_ERRCODE Helper_RTMSetClrGbias(SYS_IPList_t AppConfig, R2M18_SsbGbSerGldoAtbErrorMonRegUnion_t *pSsbGbSerGldoAtbErrorMon, SYS_GBIASErrors_t *pGBErr)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M09_MaskCcResetErrorUnion_t GBIASMaskCcResetError;
    if ((pGBErr != NULL) && (TRUE == AppConfig.GBIAS))
    {
        // Global BIAS
        pSsbGbSerGldoAtbErrorMon->bits_st.SupplyLowErrorFlag1V8GlobalBiasMon = (uint8_t)pGBErr->GBIASSupply1v8LowErr;
        /*CRC monitor is enabled always in hardware*/
        retVal = BC_SPI_Read(e_SYS_GBIAS, R2M09_MASK_CC_RESET_ERROR_U16, &GBIASMaskCcResetError.val_u32);
        if (retVal == BC_ERR_NOERROR)
        {
            /*Mask Reset ERROR for GBIAS*/
            GBIASMaskCcResetError.bits_st.MaskRegCrcResetError = (uint8_t)pGBErr->GBIASRegCRCErr;
            GBIASMaskCcResetError.bits_st.MaskSupplyLowResetError = (uint8_t)pGBErr->GBIASSupply1v8LowErr;
            retVal = BC_SPI_WriteCheck(e_SYS_GBIAS, R2M09_MASK_CC_RESET_ERROR_U16, GBIASMaskCcResetError.val_u32);
        }
    }
    return retVal;
}
static BC_ERRCODE Helper_RTMSetClrGldo(SYS_IPList_t AppConfig, R2M18_SsbGbSerGldoAtbErrorMonRegUnion_t *pSsbGbSerGldoAtbErrorMon, SYS_GLDOErrors_t *pGLDOErr)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M15_MaskCcResetErrorUnion_t GLDOMaskCcResetError;

    retVal = BC_SPI_Read(e_SYS_ISM, R2M18_SSB_GB_SER_GLDO_ATB_ERROR_MON_REG_U16, &pSsbGbSerGldoAtbErrorMon->val_u32);
    if ((pGLDOErr != NULL) && (retVal == BC_ERR_NOERROR) && (TRUE == AppConfig.GLDO))
    {
        // Global LDO
        pSsbGbSerGldoAtbErrorMon->bits_st.SupplyHighErrorFlag1V8GlobalLdoMon = (uint8_t)pGLDOErr->GlDOSupply1v8HighErr;
        pSsbGbSerGldoAtbErrorMon->bits_st.SupplyLowErrorFlag1V8GlobalLdoMon = (uint8_t)pGLDOErr->GlDOSupply1v8LowErr;
        pSsbGbSerGldoAtbErrorMon->bits_st.SupplyHighErrorFlag1V1GlobalLdoMon = (uint8_t)pGLDOErr->GlDOSupply1v1HighErr;
        pSsbGbSerGldoAtbErrorMon->bits_st.SupplyLowErrorFlag1V1GlobalLdoMon = (uint8_t)pGLDOErr->GlDOSupply1v1LowErr;
        /*CRC monitor is enabled always in hardware*/
        /*Mask Reset ERROR for GLDO*/
        retVal = BC_SPI_Read(e_SYS_GLDO, R2M15_MASK_CC_RESET_ERROR_U16, &GLDOMaskCcResetError.val_u32);
        if (retVal == BC_ERR_NOERROR)
        {
            GLDOMaskCcResetError.bits_st.MaskRegCrcResetError = (uint8_t)pGLDOErr->GlDORegCRCErr;
            GLDOMaskCcResetError.bits_st.MaskSupply1V1HighResetError = (uint8_t)pGLDOErr->GlDOSupply1v1HighErr;
            GLDOMaskCcResetError.bits_st.MaskSupply1V1LowResetError = (uint8_t)pGLDOErr->GlDOSupply1v1LowErr;
            retVal = BC_SPI_WriteCheck(e_SYS_GLDO, R2M15_MASK_CC_RESET_ERROR_U16, GLDOMaskCcResetError.val_u32);
        }
    }
    return retVal;
}
static BC_ERRCODE Helper_RTMResetRxErr(SYS_IPNum_e RXIP, SYS_RXErrors_t *pRxErr)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M0D_MaskCcResetErrorUnion_t RXMaskCcResetError;

    if (pRxErr != NULL)
    {
        /* Read reset error for appropriate module */
        retVal = BC_SPI_Read(RXIP, R2M0D_MASK_CC_RESET_ERROR_U16, &RXMaskCcResetError.val_u32);
        if (retVal == BC_ERR_NOERROR)
        {
            RXMaskCcResetError.bits_st.MaskSupply1V8LowResetError = (uint8_t)pRxErr->RxSupply1V8LowErr;
            RXMaskCcResetError.bits_st.MaskSupply1V1LowResetError = (uint8_t)pRxErr->RxSupply1V1LowErr;
            RXMaskCcResetError.bits_st.MaskRegCrcResetError = (uint8_t)pRxErr->RxRegCRCErr;
            retVal = BC_SPI_Write(RXIP, R2M0D_MASK_CC_RESET_ERROR_U16, RXMaskCcResetError.val_u32);
        }
    }
    return retVal;
}
static BC_ERRCODE Helper_RTMSetRxErr(SYS_RXErrors_t *pRx1Err, SYS_RXErrors_t *pRx2Err, SYS_RXErrors_t *pRx3Err, SYS_RXErrors_t *pRx4Err)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M18_RxErrorMonRegUnion_t RxErrorMon;
    retVal = BC_SPI_Read(e_SYS_ISM, R2M18_RX_ERROR_MON_REG_U16, &RxErrorMon.val_u32);
    if ((pRx4Err != NULL) && (retVal == BC_ERR_NOERROR))
    {
        RxErrorMon.bits_st.SupplyLowErrorFlag1V8Rx4Mon = (uint8_t)pRx4Err->RxSupply1V8LowErr;
        RxErrorMon.bits_st.SupplyLowErrorFlag1V1Rx4Mon = (uint8_t)pRx4Err->RxSupply1V1LowErr;
        RxErrorMon.bits_st.LoLevelMaxErrorFlagRx4Mon = (uint8_t)pRx4Err->RxLOLevelMaxErr;
        RxErrorMon.bits_st.LoLevelHighErrorFlagRx4Mon = (uint8_t)pRx4Err->RxLOLevelHighErr;
        RxErrorMon.bits_st.LoLevelLowErrorFlagRx4Mon = (uint8_t)pRx4Err->RxLOLevelLowErr;
        RxErrorMon.bits_st.LoLevelMinErrorFlagRx4Mon = (uint8_t)pRx4Err->RxLOLevelMinErr;
        RxErrorMon.bits_st.BbErrorFlagRx4Mon = (uint8_t)pRx4Err->RxRFConnectionErr;
        /*CRC monitor  is enabled always in hardware*/
    }
    if ((pRx3Err != NULL) && (retVal == BC_ERR_NOERROR))
    {
        RxErrorMon.bits_st.SupplyLowErrorFlag1V8Rx3Mon = (uint8_t)pRx3Err->RxSupply1V8LowErr;
        RxErrorMon.bits_st.SupplyLowErrorFlag1V1Rx3Mon = (uint8_t)pRx3Err->RxSupply1V1LowErr;
        RxErrorMon.bits_st.LoLevelMaxErrorFlagRx3Mon = (uint8_t)pRx3Err->RxLOLevelMaxErr;
        RxErrorMon.bits_st.LoLevelHighErrorFlagRx3Mon = (uint8_t)pRx3Err->RxLOLevelHighErr;
        RxErrorMon.bits_st.LoLevelLowErrorFlagRx3Mon = (uint8_t)pRx3Err->RxLOLevelLowErr;
        RxErrorMon.bits_st.LoLevelMinErrorFlagRx3Mon = (uint8_t)pRx3Err->RxLOLevelMinErr;
        RxErrorMon.bits_st.BbErrorFlagRx3Mon = (uint8_t)pRx3Err->RxRFConnectionErr;
        /*CRC monitor is enabled always in hardware*/
    }
    if ((pRx2Err != NULL) && (retVal == BC_ERR_NOERROR))
    {
        RxErrorMon.bits_st.SupplyLowErrorFlag1V8Rx2Mon = (uint8_t)pRx2Err->RxSupply1V8LowErr;
        RxErrorMon.bits_st.SupplyLowErrorFlag1V1Rx2Mon = (uint8_t)pRx2Err->RxSupply1V1LowErr;
        RxErrorMon.bits_st.LoLevelMaxErrorFlagRx2Mon = (uint8_t)pRx2Err->RxLOLevelMaxErr;
        RxErrorMon.bits_st.LoLevelHighErrorFlagRx2Mon = (uint8_t)pRx2Err->RxLOLevelHighErr;
        RxErrorMon.bits_st.LoLevelLowErrorFlagRx2Mon = (uint8_t)pRx2Err->RxLOLevelLowErr;
        RxErrorMon.bits_st.LoLevelMinErrorFlagRx2Mon = (uint8_t)pRx2Err->RxLOLevelMinErr;
        RxErrorMon.bits_st.BbErrorFlagRx2Mon = (uint8_t)pRx2Err->RxRFConnectionErr;
        /*CRC monitor is enabled always in hardware*/
    }
    if ((pRx1Err != NULL) && (retVal == BC_ERR_NOERROR))
    {
        RxErrorMon.bits_st.SupplyLowErrorFlag1V8Rx1Mon = (uint8_t)pRx1Err->RxSupply1V8LowErr;
        RxErrorMon.bits_st.SupplyLowErrorFlag1V1Rx1Mon = (uint8_t)pRx1Err->RxSupply1V1LowErr;
        RxErrorMon.bits_st.LoLevelMaxErrorFlagRx1Mon = (uint8_t)pRx1Err->RxLOLevelMaxErr;
        RxErrorMon.bits_st.LoLevelHighErrorFlagRx1Mon = (uint8_t)pRx1Err->RxLOLevelHighErr;
        RxErrorMon.bits_st.LoLevelLowErrorFlagRx1Mon = (uint8_t)pRx1Err->RxLOLevelLowErr;
        RxErrorMon.bits_st.LoLevelMinErrorFlagRx1Mon = (uint8_t)pRx1Err->RxLOLevelMinErr;
        RxErrorMon.bits_st.BbErrorFlagRx1Mon = (uint8_t)pRx1Err->RxRFConnectionErr;
        /*CRC monitor is enabled always in hardware*/
    }
    if (retVal == BC_ERR_NOERROR)
    {
        retVal = BC_SPI_WriteCheck(e_SYS_ISM, R2M18_RX_ERROR_MON_REG_U16, RxErrorMon.val_u32);
    }
    return retVal;
}
static BC_ERRCODE Helper_RTMResetTxErr(SYS_IPNum_e TXIP, SYS_TXErrors_t *pTxErr)
{
    R2M11_MaskCcResetErrorUnion_t TXMaskCcResetError;
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    if ((pTxErr != NULL))
    {
        // Mask the Reset Error from CC module to TX
        retVal = BC_SPI_Read(TXIP, R2M11_MASK_CC_RESET_ERROR_U16, &TXMaskCcResetError.val_u32);
        if (retVal == BC_ERR_NOERROR)
        {
            TXMaskCcResetError.bits_st.MaskPrRfResetError = (uint8_t)pTxErr->TxPRErr;
            TXMaskCcResetError.bits_st.MaskPrInlResetError = (uint8_t)pTxErr->TxPRErr;
            TXMaskCcResetError.bits_st.MaskPrCordicResetError = (uint8_t)pTxErr->TxPRErr;
            TXMaskCcResetError.bits_st.MaskRegCrcResetError = (uint8_t)pTxErr->TxRegCRCErr;
            TXMaskCcResetError.bits_st.MaskSupply1V8LowResetError = (uint8_t)pTxErr->TxSupply1v8LowErr;
            TXMaskCcResetError.bits_st.MaskSupply1V1LowResetError = (uint8_t)pTxErr->TxSupply1v1LowErr;
            TXMaskCcResetError.bits_st.MaskTempResetError = (uint8_t)pTxErr->TxTempHighErr;
            retVal = BC_SPI_Write(TXIP, R2M11_MASK_CC_RESET_ERROR_U16, TXMaskCcResetError.val_u32);
        }
    }
    return retVal;
}
static BC_ERRCODE Helper_RTMSetTxErr(SYS_TXErrors_t *pTx1Err, SYS_TXErrors_t *pTx2Err, SYS_TXErrors_t *pTx3Err)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M18_TxErrorMonRegUnion_t TxErrorMon;

    retVal = BC_SPI_Read(e_SYS_ISM, R2M18_TX_ERROR_MON_REG_U16, &TxErrorMon.val_u32);
    if ((pTx3Err != NULL) && (retVal == BC_ERR_NOERROR))
    {
        TxErrorMon.bits_st.PrErrorFlagTx3Mon = (uint8_t)pTx3Err->TxPRErr;
        TxErrorMon.bits_st.SupplyLowErrorFlag1V8Tx3Mon = (uint8_t)pTx3Err->TxSupply1v8LowErr;
        TxErrorMon.bits_st.RfLevelMaxErrorFlagTx3Mon = (uint8_t)pTx3Err->TxRfLevelMaxErr;
        TxErrorMon.bits_st.RfLevelHighErrorFlagTx3Mon = (uint8_t)pTx3Err->TxRfLevelHighErr;
        TxErrorMon.bits_st.RfLevelLowErrorFlagTx3Mon = (uint8_t)pTx3Err->TxRfLevelLowErr;
        TxErrorMon.bits_st.RfLevelMinErrorFlagTx3Mon = (uint8_t)pTx3Err->TxRfLevelMinErr;
        TxErrorMon.bits_st.TempErrorFlagTx3Mon = (uint8_t)pTx3Err->TxTempHighErr;
        TxErrorMon.bits_st.BbErrorFlagTx3Mon = (uint8_t)pTx3Err->TxRFConnectionErr;
        TxErrorMon.bits_st.SupplyLowErrorFlag1V1Tx3Mon = (uint8_t)pTx3Err->TxSupply1v1LowErr;
        /*CRC monitor is enabled always in hardware*/
    }
    if ((pTx2Err != NULL) && (retVal == BC_ERR_NOERROR))
    {
        TxErrorMon.bits_st.PrErrorFlagTx2Mon = (uint8_t)pTx2Err->TxPRErr;
        TxErrorMon.bits_st.SupplyLowErrorFlag1V8Tx2Mon = (uint8_t)pTx2Err->TxSupply1v8LowErr;
        TxErrorMon.bits_st.RfLevelMaxErrorFlagTx2Mon = (uint8_t)pTx2Err->TxRfLevelMaxErr;
        TxErrorMon.bits_st.RfLevelHighErrorFlagTx2Mon = (uint8_t)pTx2Err->TxRfLevelHighErr;
        TxErrorMon.bits_st.RfLevelLowErrorFlagTx2Mon = (uint8_t)pTx2Err->TxRfLevelLowErr;
        TxErrorMon.bits_st.RfLevelMinErrorFlagTx2Mon = (uint8_t)pTx2Err->TxRfLevelMinErr;
        TxErrorMon.bits_st.TempErrorFlagTx2Mon = (uint8_t)pTx2Err->TxTempHighErr;
        TxErrorMon.bits_st.BbErrorFlagTx2Mon = (uint8_t)pTx2Err->TxRFConnectionErr;
        TxErrorMon.bits_st.SupplyLowErrorFlag1V1Tx2Mon = (uint8_t)pTx2Err->TxSupply1v1LowErr;
        /*CRC monitor is enabled always in hardware*/
    }
    if ((pTx1Err != NULL) && (retVal == BC_ERR_NOERROR))
    {
        TxErrorMon.bits_st.PrErrorFlagTx1Mon = (uint8_t)pTx1Err->TxPRErr;
        TxErrorMon.bits_st.SupplyLowErrorFlag1V8Tx1Mon = (uint8_t)pTx1Err->TxSupply1v8LowErr;
        TxErrorMon.bits_st.RfLevelMaxErrorFlagTx1Mon = (uint8_t)pTx1Err->TxRfLevelMaxErr;
        TxErrorMon.bits_st.RfLevelHighErrorFlagTx1Mon = (uint8_t)pTx1Err->TxRfLevelHighErr;
        TxErrorMon.bits_st.RfLevelLowErrorFlagTx1Mon = (uint8_t)pTx1Err->TxRfLevelLowErr;
        TxErrorMon.bits_st.RfLevelMinErrorFlagTx1Mon = (uint8_t)pTx1Err->TxRfLevelMinErr;
        TxErrorMon.bits_st.TempErrorFlagTx1Mon = (uint8_t)pTx1Err->TxTempHighErr;
        TxErrorMon.bits_st.BbErrorFlagTx1Mon = (uint8_t)pTx1Err->TxRFConnectionErr;
        TxErrorMon.bits_st.SupplyLowErrorFlag1V1Tx1Mon = (uint8_t)pTx1Err->TxSupply1v1LowErr;
        /*CRC monitor is enabled always in hardware*/
    }
    if (retVal == BC_ERR_NOERROR)
    {
        retVal = BC_SPI_WriteCheck(e_SYS_ISM, R2M18_TX_ERROR_MON_REG_U16, TxErrorMon.val_u32);
    }
    return retVal;
}
static BC_ERRCODE Helper_ISMGetRxFitStatus(SYS_RXErrors_t *pRx1Err, SYS_RXErrors_t *pRx2Err, SYS_RXErrors_t *pRx3Err, SYS_RXErrors_t *pRx4Err, uint32_t *pModuleErr)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M18_FitStatusRxRegUnion_t FitStatusRx;
    retVal = BC_SPI_Read(e_SYS_ISM, R2M18_FIT_STATUS_RX_REG_U16, &FitStatusRx.val_u32);
    if (retVal == BC_ERR_NOERROR)
    {
        if (pRx4Err != NULL)
        {
            pRx4Err->RxRegCRCErr = (BOOL)FitStatusRx.bits_st.RegCrcErrorFlagRx4FitStatus;
            pRx4Err->RxSupply1V8LowErr = (BOOL)FitStatusRx.bits_st.SupplyLowErrorFlag1V8Rx4FitStatus;
            pRx4Err->RxSupply1V1LowErr = (BOOL)FitStatusRx.bits_st.SupplyLowErrorFlag1V1Rx4FitStatus;
            pRx4Err->RxLOLevelMaxErr = (BOOL)FitStatusRx.bits_st.LoLevelMaxErrorFlagRx4FitStatus;
            pRx4Err->RxLOLevelHighErr = (BOOL)FitStatusRx.bits_st.LoLevelHighErrorFlagRx4FitStatus;
            pRx4Err->RxLOLevelLowErr = (BOOL)FitStatusRx.bits_st.LoLevelLowErrorFlagRx4FitStatus;
            pRx4Err->RxLOLevelMinErr = (BOOL)FitStatusRx.bits_st.LoLevelMinErrorFlagRx4FitStatus;
            pRx4Err->RxRFConnectionErr = (BOOL)FitStatusRx.bits_st.BbErrorFlagRx4FitStatus;
        }
        if (pRx3Err != NULL)
        {
            pRx3Err->RxRegCRCErr = (BOOL)FitStatusRx.bits_st.RegCrcErrorFlagRx3FitStatus;
            pRx3Err->RxSupply1V8LowErr = (BOOL)FitStatusRx.bits_st.SupplyLowErrorFlag1V8Rx3FitStatus;
            pRx3Err->RxSupply1V1LowErr = (BOOL)FitStatusRx.bits_st.SupplyLowErrorFlag1V1Rx3FitStatus;
            pRx3Err->RxLOLevelMaxErr = (BOOL)FitStatusRx.bits_st.LoLevelMaxErrorFlagRx3FitStatus;
            pRx3Err->RxLOLevelHighErr = (BOOL)FitStatusRx.bits_st.LoLevelHighErrorFlagRx3FitStatus;
            pRx3Err->RxLOLevelLowErr = (BOOL)FitStatusRx.bits_st.LoLevelLowErrorFlagRx3FitStatus;
            pRx3Err->RxLOLevelMinErr = (BOOL)FitStatusRx.bits_st.LoLevelMinErrorFlagRx3FitStatus;
            pRx3Err->RxRFConnectionErr = (BOOL)FitStatusRx.bits_st.BbErrorFlagRx3FitStatus;
        }
        if (pRx2Err != NULL)
        {
            pRx2Err->RxRegCRCErr = (BOOL)FitStatusRx.bits_st.RegCrcErrorFlagRx2FitStatus;
            pRx2Err->RxSupply1V8LowErr = (BOOL)FitStatusRx.bits_st.SupplyLowErrorFlag1V8Rx2FitStatus;
            pRx2Err->RxSupply1V1LowErr = (BOOL)FitStatusRx.bits_st.SupplyLowErrorFlag1V1Rx2FitStatus;
            pRx2Err->RxLOLevelMaxErr = (BOOL)FitStatusRx.bits_st.LoLevelMaxErrorFlagRx2FitStatus;
            pRx2Err->RxLOLevelHighErr = (BOOL)FitStatusRx.bits_st.LoLevelHighErrorFlagRx2FitStatus;
            pRx2Err->RxLOLevelLowErr = (BOOL)FitStatusRx.bits_st.LoLevelLowErrorFlagRx2FitStatus;
            pRx2Err->RxLOLevelMinErr = (BOOL)FitStatusRx.bits_st.LoLevelMinErrorFlagRx2FitStatus;
            pRx2Err->RxRFConnectionErr = (BOOL)FitStatusRx.bits_st.BbErrorFlagRx2FitStatus;
        }
        if (pRx1Err != NULL)
        {
            pRx1Err->RxRegCRCErr = (BOOL)FitStatusRx.bits_st.RegCrcErrorFlagRx1FitStatus;
            pRx1Err->RxSupply1V8LowErr = (BOOL)FitStatusRx.bits_st.SupplyLowErrorFlag1V8Rx1FitStatus;
            pRx1Err->RxSupply1V1LowErr = (BOOL)FitStatusRx.bits_st.SupplyLowErrorFlag1V1Rx1FitStatus;
            pRx1Err->RxLOLevelMaxErr = (BOOL)FitStatusRx.bits_st.LoLevelMaxErrorFlagRx1FitStatus;
            pRx1Err->RxLOLevelHighErr = (BOOL)FitStatusRx.bits_st.LoLevelHighErrorFlagRx1FitStatus;
            pRx1Err->RxLOLevelLowErr = (BOOL)FitStatusRx.bits_st.LoLevelLowErrorFlagRx1FitStatus;
            pRx1Err->RxLOLevelMinErr = (BOOL)FitStatusRx.bits_st.LoLevelMinErrorFlagRx1FitStatus;
            pRx1Err->RxRFConnectionErr = (BOOL)FitStatusRx.bits_st.BbErrorFlagRx1FitStatus;
        }
        // Module register Error dump.
        if (pModuleErr != NULL)
        {
            *pModuleErr = FitStatusRx.val_u32;
        }
    }
    return retVal;
}
static BC_ERRCODE Helper_ISMGetRxRawError(SYS_RXErrors_t *pRx1Err, SYS_RXErrors_t *pRx2Err, SYS_RXErrors_t *pRx3Err, SYS_RXErrors_t *pRx4Err, uint32_t *pModuleErr)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M18_RxErrorFlagRawStatusUnion_t RxErrorFlagRaw;
    retVal = BC_SPI_Read(e_SYS_ISM, R2M18_RX_ERROR_FLAG_RAW_STATUS_U16, &RxErrorFlagRaw.val_u32);
    if (retVal == BC_ERR_NOERROR)
    {
        if (pRx4Err != NULL)
        {
            pRx4Err->RxRegCRCErr = (BOOL)RxErrorFlagRaw.bits_st.RegCrcErrorFlagRx4RawStatus;
            pRx4Err->RxSupply1V8LowErr = (BOOL)RxErrorFlagRaw.bits_st.SupplyLowErrorFlag1V8Rx4RawStatus;
            pRx4Err->RxSupply1V1LowErr = (BOOL)RxErrorFlagRaw.bits_st.SupplyLowErrorFlag1V1Rx4RawStatus;
            pRx4Err->RxLOLevelMaxErr = (BOOL)RxErrorFlagRaw.bits_st.LoLevelMaxErrorFlagRx4RawStatus;
            pRx4Err->RxLOLevelHighErr = (BOOL)RxErrorFlagRaw.bits_st.LoLevelHighErrorFlagRx4RawStatus;
            pRx4Err->RxLOLevelLowErr = (BOOL)RxErrorFlagRaw.bits_st.LoLevelLowErrorFlagRx4RawStatus;
            pRx4Err->RxLOLevelMinErr = (BOOL)RxErrorFlagRaw.bits_st.LoLevelMinErrorFlagRx4RawStatus;
            pRx4Err->RxRFConnectionErr = (BOOL)RxErrorFlagRaw.bits_st.BbErrorFlagRx4RawStatus;
        }
        if (pRx3Err != NULL)
        {
            pRx3Err->RxRegCRCErr = (BOOL)RxErrorFlagRaw.bits_st.RegCrcErrorFlagRx3RawStatus;
            pRx3Err->RxSupply1V8LowErr = (BOOL)RxErrorFlagRaw.bits_st.SupplyLowErrorFlag1V8Rx3RawStatus;
            pRx3Err->RxSupply1V1LowErr = (BOOL)RxErrorFlagRaw.bits_st.SupplyLowErrorFlag1V1Rx3RawStatus;
            pRx3Err->RxLOLevelMaxErr = (BOOL)RxErrorFlagRaw.bits_st.LoLevelMaxErrorFlagRx3RawStatus;
            pRx3Err->RxLOLevelHighErr = (BOOL)RxErrorFlagRaw.bits_st.LoLevelHighErrorFlagRx3RawStatus;
            pRx3Err->RxLOLevelLowErr = (BOOL)RxErrorFlagRaw.bits_st.LoLevelLowErrorFlagRx3RawStatus;
            pRx3Err->RxLOLevelMinErr = (BOOL)RxErrorFlagRaw.bits_st.LoLevelMinErrorFlagRx3RawStatus;
            pRx3Err->RxRFConnectionErr = (BOOL)RxErrorFlagRaw.bits_st.BbErrorFlagRx3RawStatus;
        }
        if (pRx2Err != NULL)
        {
            pRx2Err->RxRegCRCErr = (BOOL)RxErrorFlagRaw.bits_st.RegCrcErrorFlagRx2RawStatus;
            pRx2Err->RxSupply1V8LowErr = (BOOL)RxErrorFlagRaw.bits_st.SupplyLowErrorFlag1V8Rx2RawStatus;
            pRx2Err->RxSupply1V1LowErr = (BOOL)RxErrorFlagRaw.bits_st.SupplyLowErrorFlag1V1Rx2RawStatus;
            pRx2Err->RxLOLevelMaxErr = (BOOL)RxErrorFlagRaw.bits_st.LoLevelMaxErrorFlagRx2RawStatus;
            pRx2Err->RxLOLevelHighErr = (BOOL)RxErrorFlagRaw.bits_st.LoLevelHighErrorFlagRx2RawStatus;
            pRx2Err->RxLOLevelLowErr = (BOOL)RxErrorFlagRaw.bits_st.LoLevelLowErrorFlagRx2RawStatus;
            pRx2Err->RxLOLevelMinErr = (BOOL)RxErrorFlagRaw.bits_st.LoLevelMinErrorFlagRx2RawStatus;
            pRx2Err->RxRFConnectionErr = (BOOL)RxErrorFlagRaw.bits_st.BbErrorFlagRx2RawStatus;
        }
        if (pRx1Err != NULL)
        {
            pRx1Err->RxRegCRCErr = (BOOL)RxErrorFlagRaw.bits_st.RegCrcErrorFlagRx1RawStatus;
            pRx1Err->RxSupply1V8LowErr = (BOOL)RxErrorFlagRaw.bits_st.SupplyLowErrorFlag1V8Rx1RawStatus;
            pRx1Err->RxSupply1V1LowErr = (BOOL)RxErrorFlagRaw.bits_st.SupplyLowErrorFlag1V1Rx1RawStatus;
            pRx1Err->RxLOLevelMaxErr = (BOOL)RxErrorFlagRaw.bits_st.LoLevelMaxErrorFlagRx1RawStatus;
            pRx1Err->RxLOLevelHighErr = (BOOL)RxErrorFlagRaw.bits_st.LoLevelHighErrorFlagRx1RawStatus;
            pRx1Err->RxLOLevelLowErr = (BOOL)RxErrorFlagRaw.bits_st.LoLevelLowErrorFlagRx1RawStatus;
            pRx1Err->RxLOLevelMinErr = (BOOL)RxErrorFlagRaw.bits_st.LoLevelMinErrorFlagRx1RawStatus;
            pRx1Err->RxRFConnectionErr = (BOOL)RxErrorFlagRaw.bits_st.BbErrorFlagRx1RawStatus;
        }
        // Module register Error dump.
        if (pModuleErr != NULL)
        {
            *pModuleErr = RxErrorFlagRaw.val_u32;
        }
    }
    return retVal;
}
static BC_ERRCODE Helper_ISMGetRxMaskedError(SYS_RXErrors_t *pRx1Err, SYS_RXErrors_t *pRx2Err, SYS_RXErrors_t *pRx3Err, SYS_RXErrors_t *pRx4Err, uint32_t *pModuleErr)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M18_RxErrorFlagMaskedStatusUnion_t RxErrorFlagMask;
    retVal = BC_SPI_Read(e_SYS_ISM, R2M18_RX_ERROR_FLAG_MASKED_STATUS_U16, &RxErrorFlagMask.val_u32);
    if (retVal == BC_ERR_NOERROR)
    {
        if (pRx4Err != NULL)
        {
            pRx4Err->RxRegCRCErr = (BOOL)RxErrorFlagMask.bits_st.RegCrcErrorFlagRx4MaskedStatus;
            pRx4Err->RxSupply1V8LowErr = (BOOL)RxErrorFlagMask.bits_st.SupplyLowErrorFlag1V8Rx4MaskedStatus;
            pRx4Err->RxSupply1V1LowErr = (BOOL)RxErrorFlagMask.bits_st.SupplyLowErrorFlag1V1Rx4MaskedStatus;
            pRx4Err->RxLOLevelMaxErr = (BOOL)RxErrorFlagMask.bits_st.LoLevelMaxErrorFlagRx4MaskedStatus;
            pRx4Err->RxLOLevelHighErr = (BOOL)RxErrorFlagMask.bits_st.LoLevelHighErrorFlagRx4MaskedStatus;
            pRx4Err->RxLOLevelLowErr = (BOOL)RxErrorFlagMask.bits_st.LoLevelLowErrorFlagRx4MaskedStatus;
            pRx4Err->RxLOLevelMinErr = (BOOL)RxErrorFlagMask.bits_st.LoLevelMinErrorFlagRx4MaskedStatus;
            pRx4Err->RxRFConnectionErr = (BOOL)RxErrorFlagMask.bits_st.BbErrorFlagRx4MaskedStatus;
        }
        if (pRx3Err != NULL)
        {
            pRx3Err->RxRegCRCErr = (BOOL)RxErrorFlagMask.bits_st.RegCrcErrorFlagRx3MaskedStatus;
            pRx3Err->RxSupply1V8LowErr = (BOOL)RxErrorFlagMask.bits_st.SupplyLowErrorFlag1V8Rx3MaskedStatus;
            pRx3Err->RxSupply1V1LowErr = (BOOL)RxErrorFlagMask.bits_st.SupplyLowErrorFlag1V1Rx3MaskedStatus;
            pRx3Err->RxLOLevelMaxErr = (BOOL)RxErrorFlagMask.bits_st.LoLevelMaxErrorFlagRx3MaskedStatus;
            pRx3Err->RxLOLevelHighErr = (BOOL)RxErrorFlagMask.bits_st.LoLevelHighErrorFlagRx3MaskedStatus;
            pRx3Err->RxLOLevelLowErr = (BOOL)RxErrorFlagMask.bits_st.LoLevelLowErrorFlagRx3MaskedStatus;
            pRx3Err->RxLOLevelMinErr = (BOOL)RxErrorFlagMask.bits_st.LoLevelMinErrorFlagRx3MaskedStatus;
            pRx3Err->RxRFConnectionErr = (BOOL)RxErrorFlagMask.bits_st.BbErrorFlagRx3MaskedStatus;
        }
        if (pRx2Err != NULL)
        {
            pRx2Err->RxRegCRCErr = (BOOL)RxErrorFlagMask.bits_st.RegCrcErrorFlagRx2MaskedStatus;
            pRx2Err->RxSupply1V8LowErr = (BOOL)RxErrorFlagMask.bits_st.SupplyLowErrorFlag1V8Rx2MaskedStatus;
            pRx2Err->RxSupply1V1LowErr = (BOOL)RxErrorFlagMask.bits_st.SupplyLowErrorFlag1V1Rx2MaskedStatus;
            pRx2Err->RxLOLevelMaxErr = (BOOL)RxErrorFlagMask.bits_st.LoLevelMaxErrorFlagRx2MaskedStatus;
            pRx2Err->RxLOLevelHighErr = (BOOL)RxErrorFlagMask.bits_st.LoLevelHighErrorFlagRx2MaskedStatus;
            pRx2Err->RxLOLevelLowErr = (BOOL)RxErrorFlagMask.bits_st.LoLevelLowErrorFlagRx2MaskedStatus;
            pRx2Err->RxLOLevelMinErr = (BOOL)RxErrorFlagMask.bits_st.LoLevelMinErrorFlagRx2MaskedStatus;
            pRx2Err->RxRFConnectionErr = (BOOL)RxErrorFlagMask.bits_st.BbErrorFlagRx2MaskedStatus;
        }
        if (pRx1Err != NULL)
        {
            pRx1Err->RxRegCRCErr = (BOOL)RxErrorFlagMask.bits_st.RegCrcErrorFlagRx1MaskedStatus;
            pRx1Err->RxSupply1V8LowErr = (BOOL)RxErrorFlagMask.bits_st.SupplyLowErrorFlag1V8Rx1MaskedStatus;
            pRx1Err->RxSupply1V1LowErr = (BOOL)RxErrorFlagMask.bits_st.SupplyLowErrorFlag1V1Rx1MaskedStatus;
            pRx1Err->RxLOLevelMaxErr = (BOOL)RxErrorFlagMask.bits_st.LoLevelMaxErrorFlagRx1MaskedStatus;
            pRx1Err->RxLOLevelHighErr = (BOOL)RxErrorFlagMask.bits_st.LoLevelHighErrorFlagRx1MaskedStatus;
            pRx1Err->RxLOLevelLowErr = (BOOL)RxErrorFlagMask.bits_st.LoLevelLowErrorFlagRx1MaskedStatus;
            pRx1Err->RxLOLevelMinErr = (BOOL)RxErrorFlagMask.bits_st.LoLevelMinErrorFlagRx1MaskedStatus;
            pRx1Err->RxRFConnectionErr = (BOOL)RxErrorFlagMask.bits_st.BbErrorFlagRx1MaskedStatus;
        }
        // Module register Error dump.
        if (pModuleErr != NULL)
        {
            *pModuleErr = RxErrorFlagMask.val_u32;
        }
    }
    return retVal;
}
static BC_ERRCODE Helper_ISMGetTxFitStatus(SYS_TXErrors_t *pTx1Err, SYS_TXErrors_t *pTx2Err, SYS_TXErrors_t *pTx3Err, uint32_t *pModuleErr)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M18_FitStatusTxRegUnion_t FitStatusTx;
    retVal = BC_SPI_Read(e_SYS_ISM, R2M18_FIT_STATUS_TX_REG_U16, &FitStatusTx.val_u32);
    if (retVal == BC_ERR_NOERROR)
    {
        if (pTx3Err != NULL)
        {
            pTx3Err->TxRegCRCErr = (BOOL)FitStatusTx.bits_st.RegCrcErrorFlagTx3FitStatus;
            pTx3Err->TxPRErr = (BOOL)FitStatusTx.bits_st.PrErrorFlagTx3FitStatus;
            pTx3Err->TxSupply1v8LowErr = (BOOL)FitStatusTx.bits_st.SupplyLowErrorFlag1V8Tx3FitStatus;
            pTx3Err->TxRfLevelMaxErr = (BOOL)FitStatusTx.bits_st.RfLevelMaxErrorFlagTx3FitStatus;
            pTx3Err->TxRfLevelHighErr = (BOOL)FitStatusTx.bits_st.RfLevelHighErrorFlagTx3FitStatus;
            pTx3Err->TxRfLevelLowErr = (BOOL)FitStatusTx.bits_st.RfLevelLowErrorFlagTx3FitStatus;
            pTx3Err->TxRfLevelMinErr = (BOOL)FitStatusTx.bits_st.RfLevelMinErrorFlagTx3FitStatus;
            pTx3Err->TxTempHighErr = (BOOL)FitStatusTx.bits_st.TempErrorFlagTx3FitStatus;
            pTx3Err->TxRFConnectionErr = (BOOL)FitStatusTx.bits_st.BbErrorFlagTx3FitStatus;
            pTx3Err->TxSupply1v1LowErr = (BOOL)FitStatusTx.bits_st.SupplyLowErrorFlag1V1Tx3FitStatus;
        }
        if (pTx2Err != NULL)
        {
            pTx2Err->TxRegCRCErr = (BOOL)FitStatusTx.bits_st.RegCrcErrorFlagTx2FitStatus;
            pTx2Err->TxPRErr = (BOOL)FitStatusTx.bits_st.PrErrorFlagTx2FitStatus;
            pTx2Err->TxSupply1v8LowErr = (BOOL)FitStatusTx.bits_st.SupplyLowErrorFlag1V8Tx2FitStatus;
            pTx2Err->TxRfLevelMaxErr = (BOOL)FitStatusTx.bits_st.RfLevelMaxErrorFlagTx2FitStatus;
            pTx2Err->TxRfLevelHighErr = (BOOL)FitStatusTx.bits_st.RfLevelHighErrorFlagTx2FitStatus;
            pTx2Err->TxRfLevelLowErr = (BOOL)FitStatusTx.bits_st.RfLevelLowErrorFlagTx2FitStatus;
            pTx2Err->TxRfLevelMinErr = (BOOL)FitStatusTx.bits_st.RfLevelMinErrorFlagTx2FitStatus;
            pTx2Err->TxTempHighErr = (BOOL)FitStatusTx.bits_st.TempErrorFlagTx2FitStatus;
            pTx2Err->TxRFConnectionErr = (BOOL)FitStatusTx.bits_st.BbErrorFlagTx2FitStatus;
            pTx2Err->TxSupply1v1LowErr = (BOOL)FitStatusTx.bits_st.SupplyLowErrorFlag1V1Tx2FitStatus;
        }
        if (pTx1Err != NULL)
        {
            pTx1Err->TxRegCRCErr = (BOOL)FitStatusTx.bits_st.RegCrcErrorFlagTx1FitStatus;
            pTx1Err->TxPRErr = (BOOL)FitStatusTx.bits_st.PrErrorFlagTx1FitStatus;
            pTx1Err->TxSupply1v8LowErr = (BOOL)FitStatusTx.bits_st.SupplyLowErrorFlag1V8Tx1FitStatus;
            pTx1Err->TxRfLevelMaxErr = (BOOL)FitStatusTx.bits_st.RfLevelMaxErrorFlagTx1FitStatus;
            pTx1Err->TxRfLevelHighErr = (BOOL)FitStatusTx.bits_st.RfLevelHighErrorFlagTx1FitStatus;
            pTx1Err->TxRfLevelLowErr = (BOOL)FitStatusTx.bits_st.RfLevelLowErrorFlagTx1FitStatus;
            pTx1Err->TxRfLevelMinErr = (BOOL)FitStatusTx.bits_st.RfLevelMinErrorFlagTx1FitStatus;
            pTx1Err->TxTempHighErr = (BOOL)FitStatusTx.bits_st.TempErrorFlagTx1FitStatus;
            pTx1Err->TxRFConnectionErr = (BOOL)FitStatusTx.bits_st.BbErrorFlagTx1FitStatus;
            pTx1Err->TxSupply1v1LowErr = (BOOL)FitStatusTx.bits_st.SupplyLowErrorFlag1V1Tx1FitStatus;
        }
        // Module register Error dump.
        if (pModuleErr != NULL)
        {
            *pModuleErr = FitStatusTx.val_u32;
        }
    }
    return retVal;
}

static BC_ERRCODE Helper_ISMGetTxRawError(SYS_TXErrors_t *pTx1Err, SYS_TXErrors_t *pTx2Err, SYS_TXErrors_t *pTx3Err, uint32_t *pModuleErr)
{
    R2M18_TxErrorFlagRawStatusUnion_t TxErrorFlagRaw;
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    retVal = BC_SPI_Read(e_SYS_ISM, R2M18_TX_ERROR_FLAG_RAW_STATUS_U16, &TxErrorFlagRaw.val_u32);
    if (retVal == BC_ERR_NOERROR)
    {
        if (pTx3Err != NULL)
        {
            pTx3Err->TxRegCRCErr = (BOOL)TxErrorFlagRaw.bits_st.RegCrcErrorFlagTx3RawStatus;
            pTx3Err->TxPRErr = (BOOL)TxErrorFlagRaw.bits_st.PrErrorFlagTx3RawStatus;
            pTx3Err->TxSupply1v8LowErr = (BOOL)TxErrorFlagRaw.bits_st.SupplyLowErrorFlag1V8Tx3RawStatus;
            pTx3Err->TxRfLevelMaxErr = (BOOL)TxErrorFlagRaw.bits_st.RfLevelMaxErrorFlagTx3RawStatus;
            pTx3Err->TxRfLevelHighErr = (BOOL)TxErrorFlagRaw.bits_st.RfLevelHighErrorFlagTx3RawStatus;
            pTx3Err->TxRfLevelLowErr = (BOOL)TxErrorFlagRaw.bits_st.RfLevelLowErrorFlagTx3RawStatus;
            pTx3Err->TxRfLevelMinErr = (BOOL)TxErrorFlagRaw.bits_st.RfLevelMinErrorFlagTx3RawStatus;
            pTx3Err->TxTempHighErr = (BOOL)TxErrorFlagRaw.bits_st.TempErrorFlagTx3RawStatus;
            pTx3Err->TxRFConnectionErr = (BOOL)TxErrorFlagRaw.bits_st.BbErrorFlagTx3RawStatus;
            pTx3Err->TxSupply1v1LowErr = (BOOL)TxErrorFlagRaw.bits_st.SupplyLowErrorFlag1V1Tx3RawStatus;
        }
        if (pTx2Err != NULL)
        {
            pTx2Err->TxRegCRCErr = (BOOL)TxErrorFlagRaw.bits_st.RegCrcErrorFlagTx2RawStatus;
            pTx2Err->TxPRErr = (BOOL)TxErrorFlagRaw.bits_st.PrErrorFlagTx2RawStatus;
            pTx2Err->TxSupply1v8LowErr = (BOOL)TxErrorFlagRaw.bits_st.SupplyLowErrorFlag1V8Tx2RawStatus;
            pTx2Err->TxRfLevelMaxErr = (BOOL)TxErrorFlagRaw.bits_st.RfLevelMaxErrorFlagTx2RawStatus;
            pTx2Err->TxRfLevelHighErr = (BOOL)TxErrorFlagRaw.bits_st.RfLevelHighErrorFlagTx2RawStatus;
            pTx2Err->TxRfLevelLowErr = (BOOL)TxErrorFlagRaw.bits_st.RfLevelLowErrorFlagTx2RawStatus;
            pTx2Err->TxRfLevelMinErr = (BOOL)TxErrorFlagRaw.bits_st.RfLevelMinErrorFlagTx2RawStatus;
            pTx2Err->TxTempHighErr = (BOOL)TxErrorFlagRaw.bits_st.TempErrorFlagTx2RawStatus;
            pTx2Err->TxRFConnectionErr = (BOOL)TxErrorFlagRaw.bits_st.BbErrorFlagTx2RawStatus;
            pTx2Err->TxSupply1v1LowErr = (BOOL)TxErrorFlagRaw.bits_st.SupplyLowErrorFlag1V1Tx2RawStatus;
        }
        if (pTx1Err != NULL)
        {
            pTx1Err->TxRegCRCErr = (BOOL)TxErrorFlagRaw.bits_st.RegCrcErrorFlagTx1RawStatus;
            pTx1Err->TxPRErr = (BOOL)TxErrorFlagRaw.bits_st.PrErrorFlagTx1RawStatus;
            pTx1Err->TxSupply1v8LowErr = (BOOL)TxErrorFlagRaw.bits_st.SupplyLowErrorFlag1V8Tx1RawStatus;
            pTx1Err->TxRfLevelMaxErr = (BOOL)TxErrorFlagRaw.bits_st.RfLevelMaxErrorFlagTx1RawStatus;
            pTx1Err->TxRfLevelHighErr = (BOOL)TxErrorFlagRaw.bits_st.RfLevelHighErrorFlagTx1RawStatus;
            pTx1Err->TxRfLevelLowErr = (BOOL)TxErrorFlagRaw.bits_st.RfLevelLowErrorFlagTx1RawStatus;
            pTx1Err->TxRfLevelMinErr = (BOOL)TxErrorFlagRaw.bits_st.RfLevelMinErrorFlagTx1RawStatus;
            pTx1Err->TxTempHighErr = (BOOL)TxErrorFlagRaw.bits_st.TempErrorFlagTx1RawStatus;
            pTx1Err->TxRFConnectionErr = (BOOL)TxErrorFlagRaw.bits_st.BbErrorFlagTx1RawStatus;
            pTx1Err->TxSupply1v1LowErr = (BOOL)TxErrorFlagRaw.bits_st.SupplyLowErrorFlag1V1Tx1RawStatus;
        }
        // Module register Error dump.
        if (pModuleErr != NULL)
        {
            *pModuleErr = TxErrorFlagRaw.val_u32;
        }
    }
    return retVal;
}

static BC_ERRCODE Helper_ISMGetTxMaskedError(SYS_TXErrors_t *pTx1Err, SYS_TXErrors_t *pTx2Err, SYS_TXErrors_t *pTx3Err, uint32_t *pModuleErr)
{
    R2M18_TxErrorFlagMaskedStatusUnion_t TxErrorFlagMask;
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    retVal = BC_SPI_Read(e_SYS_ISM, R2M18_TX_ERROR_FLAG_MASKED_STATUS_U16, &TxErrorFlagMask.val_u32);
    if (retVal == BC_ERR_NOERROR)
    {
        if (pTx3Err != NULL)
        {
            pTx3Err->TxRegCRCErr = (BOOL)TxErrorFlagMask.bits_st.RegCrcErrorFlagTx3MaskedStatus;
            pTx3Err->TxPRErr = (BOOL)TxErrorFlagMask.bits_st.PrErrorFlagTx3MaskedStatus;
            pTx3Err->TxSupply1v8LowErr = (BOOL)TxErrorFlagMask.bits_st.SupplyLowErrorFlag1V8Tx3MaskedStatus;
            pTx3Err->TxRfLevelMaxErr = (BOOL)TxErrorFlagMask.bits_st.RfLevelMaxErrorFlagTx3MaskedStatus;
            pTx3Err->TxRfLevelHighErr = (BOOL)TxErrorFlagMask.bits_st.RfLevelHighErrorFlagTx3MaskedStatus;
            pTx3Err->TxRfLevelLowErr = (BOOL)TxErrorFlagMask.bits_st.RfLevelLowErrorFlagTx3MaskedStatus;
            pTx3Err->TxRfLevelMinErr = (BOOL)TxErrorFlagMask.bits_st.RfLevelMinErrorFlagTx3MaskedStatus;
            pTx3Err->TxTempHighErr = (BOOL)TxErrorFlagMask.bits_st.TempErrorFlagTx3MaskedStatus;
            pTx3Err->TxRFConnectionErr = (BOOL)TxErrorFlagMask.bits_st.BbErrorFlagTx3MaskedStatus;
            pTx3Err->TxSupply1v1LowErr = (BOOL)TxErrorFlagMask.bits_st.SupplyLowErrorFlag1V1Tx3MaskedStatus;
        }
        if (pTx2Err != NULL)
        {
            pTx2Err->TxRegCRCErr = (BOOL)TxErrorFlagMask.bits_st.RegCrcErrorFlagTx2MaskedStatus;
            pTx2Err->TxPRErr = (BOOL)TxErrorFlagMask.bits_st.PrErrorFlagTx2MaskedStatus;
            pTx2Err->TxSupply1v8LowErr = (BOOL)TxErrorFlagMask.bits_st.SupplyLowErrorFlag1V8Tx2MaskedStatus;
            pTx2Err->TxRfLevelMaxErr = (BOOL)TxErrorFlagMask.bits_st.RfLevelMaxErrorFlagTx2MaskedStatus;
            pTx2Err->TxRfLevelHighErr = (BOOL)TxErrorFlagMask.bits_st.RfLevelHighErrorFlagTx2MaskedStatus;
            pTx2Err->TxRfLevelLowErr = (BOOL)TxErrorFlagMask.bits_st.RfLevelLowErrorFlagTx2MaskedStatus;
            pTx2Err->TxRfLevelMinErr = (BOOL)TxErrorFlagMask.bits_st.RfLevelMinErrorFlagTx2MaskedStatus;
            pTx2Err->TxTempHighErr = (BOOL)TxErrorFlagMask.bits_st.TempErrorFlagTx2MaskedStatus;
            pTx2Err->TxRFConnectionErr = (BOOL)TxErrorFlagMask.bits_st.BbErrorFlagTx2MaskedStatus;
            pTx2Err->TxSupply1v1LowErr = (BOOL)TxErrorFlagMask.bits_st.SupplyLowErrorFlag1V1Tx2MaskedStatus;
        }
        if (pTx1Err != NULL)
        {
            pTx1Err->TxRegCRCErr = (BOOL)TxErrorFlagMask.bits_st.RegCrcErrorFlagTx1MaskedStatus;
            pTx1Err->TxPRErr = (BOOL)TxErrorFlagMask.bits_st.PrErrorFlagTx1MaskedStatus;
            pTx1Err->TxSupply1v8LowErr = (BOOL)TxErrorFlagMask.bits_st.SupplyLowErrorFlag1V8Tx1MaskedStatus;
            pTx1Err->TxRfLevelMaxErr = (BOOL)TxErrorFlagMask.bits_st.RfLevelMaxErrorFlagTx1MaskedStatus;
            pTx1Err->TxRfLevelHighErr = (BOOL)TxErrorFlagMask.bits_st.RfLevelHighErrorFlagTx1MaskedStatus;
            pTx1Err->TxRfLevelLowErr = (BOOL)TxErrorFlagMask.bits_st.RfLevelLowErrorFlagTx1MaskedStatus;
            pTx1Err->TxRfLevelMinErr = (BOOL)TxErrorFlagMask.bits_st.RfLevelMinErrorFlagTx1MaskedStatus;
            pTx1Err->TxTempHighErr = (BOOL)TxErrorFlagMask.bits_st.TempErrorFlagTx1MaskedStatus;
            pTx1Err->TxRFConnectionErr = (BOOL)TxErrorFlagMask.bits_st.BbErrorFlagTx1MaskedStatus;
            pTx1Err->TxSupply1v1LowErr = (BOOL)TxErrorFlagMask.bits_st.SupplyLowErrorFlag1V1Tx1MaskedStatus;
        }
        // Module register Error dump.
        if (pModuleErr != NULL)
        {
            *pModuleErr = TxErrorFlagMask.val_u32;
        }
    }
    return retVal;
}

// This API reports the master ISM errors status.
BC_ERRCODE HAL_ES2_ISM_GetMasterErrStatus(BOOL RawErr, SYS_MasterErrors_t *pMasterErr, uint32_t *pModuleErr)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M18_MasterErrorFlagMaskedStatusUnion_t MasterErrorFlagMask;
    R2M18_MasterErrorFlagRawStatusUnion_t MasterErrorFlagRaw;

    if ((pMasterErr == NULL) && (pModuleErr == NULL))
    {
        retVal = BC_ERR_ISM_PTR_ADDR_NULL;
    }
    else
    { // Only for RAW Error for all IP blocks
        if (RawErr == TRUE)
        {
            retVal = BC_SPI_Read(e_SYS_ISM, R2M18_MASTER_ERROR_FLAG_RAW_STATUS_U16, &MasterErrorFlagRaw.val_u32);
            if (retVal == BC_ERR_NOERROR)
            {
                if (pMasterErr != NULL)
                {
                    pMasterErr->RegCRCError = (BOOL)MasterErrorFlagRaw.bits_st.RegCrcErrorFlagMasterRawStatus;
                    pMasterErr->InterfaceStuckatErr = (BOOL)MasterErrorFlagRaw.bits_st.InterfaceStuckErrorFlagChirpMasterRawStatus;
                    pMasterErr->RxRFConnectionErr = (BOOL)MasterErrorFlagRaw.bits_st.BbErrorFlagRxMasterRawStatus;
                    pMasterErr->RxLOLevelMinErr = (BOOL)MasterErrorFlagRaw.bits_st.LoLevelMinErrorFlagRxMasterRawStatus;
                    pMasterErr->TxPRErr = (BOOL)MasterErrorFlagRaw.bits_st.PrErrorFlagTxMasterRawStatus;
                    pMasterErr->TxRFConnectionErr = (BOOL)MasterErrorFlagRaw.bits_st.BbErrorFlagTxMasterRawStatus;
                    pMasterErr->TxRfLevelMinErr = (BOOL)MasterErrorFlagRaw.bits_st.RfLevelMinErrorFlagTxMasterRawStatus;
                    pMasterErr->LOILeveMinErr = (BOOL)MasterErrorFlagRaw.bits_st.LoiLevelMinErrorFlagInterfaceMasterRawStatus;
                    pMasterErr->LOIConnectionErr = (BOOL)MasterErrorFlagRaw.bits_st.BbErrorFlagInterfaceMasterRawStatus;
                    pMasterErr->MclkDigOutPutFreqErr = (BOOL)MasterErrorFlagRaw.bits_st.DigFreqErrorFlagMcMasterRawStatus;
                    pMasterErr->MclkPllLockErr = (BOOL)MasterErrorFlagRaw.bits_st.PllLockErrorFlagMcMasterRawStatus;
                    pMasterErr->MclkPllLevelErr = (BOOL)MasterErrorFlagRaw.bits_st.PllLevelErrorFlagMcMasterRawStatus;
                    pMasterErr->ADCCalErr = (BOOL)MasterErrorFlagRaw.bits_st.CalErrorFlagPersistentAdcMasterRawStatus;
                    pMasterErr->AAFCDigitalErr = (BOOL)MasterErrorFlagRaw.bits_st.AafcErrorFlagChirpMasterRawStatus;
                    pMasterErr->VCOFreq480Err = (BOOL)MasterErrorFlagRaw.bits_st.VcoFreq480ErrorFlagChirpMasterRawStatus;
                    pMasterErr->ChirpPLLUnlockErr = (BOOL)MasterErrorFlagRaw.bits_st.UnlockErrorFlagChirpMasterRawStatus;
                    pMasterErr->ChirpDigitalLockStepErr = (BOOL)MasterErrorFlagRaw.bits_st.LockStepErrorFlagChirpMasterRawStatus;
                    pMasterErr->GlDOSupply1v8HighErr = (BOOL)MasterErrorFlagRaw.bits_st.SupplyHighErrorFlag1V8GlobalLdoMasterRawStatus;
                    pMasterErr->GlDOSupply1v8LowErr = (BOOL)MasterErrorFlagRaw.bits_st.SupplyLowErrorFlag1V8GlobalLdoMasterRawStatus;
                    pMasterErr->GlDOSupply1v1HighErr = (BOOL)MasterErrorFlagRaw.bits_st.SupplyHighErrorFlag1V1GlobalLdoMasterRawStatus;
                    pMasterErr->GlDOSupply1v1LowErr = (BOOL)MasterErrorFlagRaw.bits_st.SupplyLowErrorFlag1V1GlobalLdoMasterRawStatus;
                    pMasterErr->SupplyLowError = (BOOL)MasterErrorFlagRaw.bits_st.SupplyLowErrorFlagMasterRawStatus;
                    pMasterErr->MclkMSPCErr = (BOOL)MasterErrorFlagRaw.bits_st.MspcErrorFlagMcMasterRawStatus;
                    pMasterErr->MclkXoNoClockErr = (BOOL)MasterErrorFlagRaw.bits_st.McXoNoClockErrorFlagRawStatus;
                    pMasterErr->ChirpLevelMaxErr = (BOOL)MasterErrorFlagRaw.bits_st.LevelMaxErrorFlagChirpMasterRawStatus;
                    pMasterErr->LOILevelMaxErr = (BOOL)MasterErrorFlagRaw.bits_st.LoiLevelMaxErrorFlagInterfaceMasterRawStatus;
                    pMasterErr->RFLevelMaxTxErr = (BOOL)MasterErrorFlagRaw.bits_st.RfLevelMaxErrorFlagTxMasterRawStatus;
                    pMasterErr->LOLevelMaxRxErr = (BOOL)MasterErrorFlagRaw.bits_st.LoLevelMaxErrorFlagRxMasterRawStatus;
                }
                // Module register Error dump.
                if (pModuleErr != NULL)
                {
                    *pModuleErr = MasterErrorFlagRaw.val_u32;
                }
            }
        }
        else // Masked Error for all IP blocks
        {
            retVal = BC_SPI_Read(e_SYS_ISM, R2M18_MASTER_ERROR_FLAG_MASKED_STATUS_U16, &MasterErrorFlagMask.val_u32);
            if (retVal == BC_ERR_NOERROR)
            {
                // Only for RAW Error for all IP blocks
                if (pMasterErr != NULL)
                {
                    pMasterErr->RegCRCError = (BOOL)MasterErrorFlagMask.bits_st.RegCrcErrorFlagMasterMaskedStatus;
                    pMasterErr->InterfaceStuckatErr = (BOOL)MasterErrorFlagMask.bits_st.InterfaceStuckErrorFlagChirpMasterMaskedStatus;
                    pMasterErr->RxRFConnectionErr = (BOOL)MasterErrorFlagMask.bits_st.BbErrorFlagRxMasterMaskedStatus;
                    pMasterErr->RxLOLevelMinErr = (BOOL)MasterErrorFlagMask.bits_st.LoLevelMinErrorFlagRxMasterMaskedStatus;
                    pMasterErr->TxPRErr = (BOOL)MasterErrorFlagMask.bits_st.PrErrorFlagTxMasterMaskedStatus;
                    pMasterErr->TxRFConnectionErr = (BOOL)MasterErrorFlagMask.bits_st.BbErrorFlagTxMasterMaskedStatus;
                    pMasterErr->TxRfLevelMinErr = (BOOL)MasterErrorFlagMask.bits_st.RfLevelMinErrorFlagTxMasterMaskedStatus;
                    pMasterErr->LOILeveMinErr = (BOOL)MasterErrorFlagMask.bits_st.LoiLevelMinErrorFlagInterfaceMasterMaskedStatus;
                    pMasterErr->LOIConnectionErr = (BOOL)MasterErrorFlagMask.bits_st.BbErrorFlagInterfaceMasterMaskedStatus;
                    pMasterErr->MclkDigOutPutFreqErr = (BOOL)MasterErrorFlagMask.bits_st.DigFreqErrorFlagMcMasterMaskedStatus;
                    pMasterErr->MclkPllLockErr = (BOOL)MasterErrorFlagMask.bits_st.PllLockErrorFlagMcMasterMaskedStatus;
                    pMasterErr->MclkPllLevelErr = (BOOL)MasterErrorFlagMask.bits_st.PllLevelErrorFlagMcMasterMaskedStatus;
                    pMasterErr->ADCCalErr = (BOOL)MasterErrorFlagMask.bits_st.CalErrorFlagPersistentAdcMasterMaskedStatus;
                    pMasterErr->AAFCDigitalErr = (BOOL)MasterErrorFlagMask.bits_st.AafcErrorFlagChirpMasterMaskedStatus;
                    pMasterErr->VCOFreq480Err = (BOOL)MasterErrorFlagMask.bits_st.VcoFreq480ErrorFlagChirpMasterMaskedStatus;
                    pMasterErr->ChirpPLLUnlockErr = (BOOL)MasterErrorFlagMask.bits_st.UnlockErrorFlagChirpMasterMaskedStatus;
                    pMasterErr->ChirpDigitalLockStepErr = (BOOL)MasterErrorFlagMask.bits_st.LockStepErrorFlagChirpMasterMaskedStatus;
                    pMasterErr->GlDOSupply1v8HighErr = (BOOL)MasterErrorFlagMask.bits_st.SupplyHighErrorFlag1V8GlobalLdoMasterMaskedStatus;
                    pMasterErr->GlDOSupply1v8LowErr = (BOOL)MasterErrorFlagMask.bits_st.SupplyLowErrorFlag1V8GlobalLdoMasterMaskedStatus;
                    pMasterErr->GlDOSupply1v1HighErr = (BOOL)MasterErrorFlagMask.bits_st.SupplyHighErrorFlag1V1GlobalLdoMasterMaskedStatus;
                    pMasterErr->GlDOSupply1v1LowErr = (BOOL)MasterErrorFlagMask.bits_st.SupplyLowErrorFlag1V1GlobalLdoMasterMaskedStatus;
                    pMasterErr->SupplyLowError = (BOOL)MasterErrorFlagMask.bits_st.SupplyLowErrorFlagMasterMaskedStatus;
                    pMasterErr->MclkMSPCErr = (BOOL)MasterErrorFlagMask.bits_st.MspcErrorFlagMcMasterMaskedStatus;
                    pMasterErr->MclkXoNoClockErr = (BOOL)MasterErrorFlagMask.bits_st.McXoNoClockErrorFlagMaskedStatus;
                    pMasterErr->ChirpLevelMaxErr = (BOOL)MasterErrorFlagMask.bits_st.LevelMaxErrorFlagChirpMasterMaskedStatus;
                    pMasterErr->LOILevelMaxErr = (BOOL)MasterErrorFlagMask.bits_st.LoiLevelMaxErrorFlagInterfaceMasterMaskedStatus;
                    pMasterErr->RFLevelMaxTxErr = (BOOL)MasterErrorFlagMask.bits_st.RfLevelMaxErrorFlagTxMasterMaskedStatus;
                    pMasterErr->LOLevelMaxRxErr = (BOOL)MasterErrorFlagMask.bits_st.LoLevelMaxErrorFlagRxMasterMaskedStatus;
                }
                // Module register Error dump.
                if (pModuleErr != NULL)
                {
                    *pModuleErr = MasterErrorFlagMask.val_u32;
                }
            }
        }
    }
    return retVal;
}

// This API reports all the supply error status of all the modules.
BC_ERRCODE HAL_ES2_ISM_GetSupplyErrStatus(BOOL RawErr, SYS_SupplyErrors_t *pSupplyErr, uint32_t *pModuleErr)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M18_SupplyErrorFlagMaskedStatusUnion_t SupplyErrorFlagMask;
    R2M18_SupplyErrorFlagRawStatusUnion_t SupplyErrorFlagRaw;

    if ((pSupplyErr == NULL) && (pModuleErr == NULL))
    {
        retVal = BC_ERR_ISM_PTR_ADDR_NULL;
    }
    else
    { // Only for RAW Error for all IP blocks
        if (RawErr == TRUE)
        {
            retVal = BC_SPI_Read(e_SYS_ISM, R2M18_SUPPLY_ERROR_FLAG_RAW_STATUS_U16, &SupplyErrorFlagRaw.val_u32);
            if (retVal == BC_ERR_NOERROR)
            {
                if (pSupplyErr != NULL)
                {
                    pSupplyErr->GlDOSupply1v8HighErr = (BOOL)SupplyErrorFlagRaw.bits_st.SupplyHighErrorFlag1V8GlobalLdoSupplyRawStatus;
                    pSupplyErr->GlDOSupply1v8LowErr = (BOOL)SupplyErrorFlagRaw.bits_st.SupplyLowErrorFlag1V8GlobalLdoSupplyRawStatus;
                    pSupplyErr->GlDOSupply1v1HighErr = (BOOL)SupplyErrorFlagRaw.bits_st.SupplyHighErrorFlag1V1GlobalLdoSupplyRawStatus;
                    pSupplyErr->GlDOSupply1v1LowErr = (BOOL)SupplyErrorFlagRaw.bits_st.SupplyLowErrorFlag1V1GlobalLdoSupplyRawStatus;
                    pSupplyErr->ChirpDigSupply1v1LowErrorErr = (BOOL)SupplyErrorFlagRaw.bits_st.SupplyLowErrorFlagDig1V1ChirpSupplyRawStatus;
                    pSupplyErr->ChirpVCOSupply1v8vLowErr = (BOOL)SupplyErrorFlagRaw.bits_st.SupplyLowErrorFlagVco1V8ChirpSupplyRawStatus;
                    pSupplyErr->ChirpPLLSupply1v8vLowErr = (BOOL)SupplyErrorFlagRaw.bits_st.SupplyLowErrorFlagPll1V8ChirpSupplyRawStatus;
                    pSupplyErr->Supply1v8SerLowErr = (BOOL)SupplyErrorFlagRaw.bits_st.SupplyLowErrorFlag1V8SerSupplyRawStatus;
                    pSupplyErr->Supply1v1MIPILowErr = (BOOL)SupplyErrorFlagRaw.bits_st.SupplyLowErrorFlag1V1Csi2SupplyRawStatus;
                    pSupplyErr->Supply1v1LVDSLowErr = (BOOL)SupplyErrorFlagRaw.bits_st.SupplyLowErrorFlag1V1SerSupplyRawStatus;
                    pSupplyErr->GBIASSupply1v8LowErr = (BOOL)SupplyErrorFlagRaw.bits_st.SupplyLowErrorFlag1V8GlobalBiasSupplyRawStatus;
                    pSupplyErr->SSBSupply1v8LowErr = (BOOL)SupplyErrorFlagRaw.bits_st.SupplyLowErrorFlag1V8SsbModSupplyRawStatus;
                    pSupplyErr->LOISupply1v1LowErr = (BOOL)SupplyErrorFlagRaw.bits_st.SupplyLowErrorFlag1V1InterfaceSupplyRawStatus;
                    pSupplyErr->ADC34Supply1v8LowErr = (BOOL)SupplyErrorFlagRaw.bits_st.SupplyLowErrorFlag1V8Adc34SupplyRawStatus;
                    pSupplyErr->ADC12Supply1v8LowErr = (BOOL)SupplyErrorFlagRaw.bits_st.SupplyLowErrorFlag1V8Adc12SupplyRawStatus;
                    pSupplyErr->MclkSupply1v8LowErr = (BOOL)SupplyErrorFlagRaw.bits_st.SupplyLowErrorFlag1V8McSupplyRawStatus;
                    pSupplyErr->Rx4Supply1V1LowErr = (BOOL)SupplyErrorFlagRaw.bits_st.SupplyLowErrorFlag1V1Rx4SupplyRawStatus;
                    pSupplyErr->Rx3Supply1V1LowErr = (BOOL)SupplyErrorFlagRaw.bits_st.SupplyLowErrorFlag1V1Rx3SupplyRawStatus;
                    pSupplyErr->Rx2Supply1V1LowErr = (BOOL)SupplyErrorFlagRaw.bits_st.SupplyLowErrorFlag1V1Rx2SupplyRawStatus;
                    pSupplyErr->Rx1Supply1V1LowErr = (BOOL)SupplyErrorFlagRaw.bits_st.SupplyLowErrorFlag1V1Rx1SupplyRawStatus;
                    pSupplyErr->Rx4Supply1V8LowErr = (BOOL)SupplyErrorFlagRaw.bits_st.SupplyLowErrorFlag1V8Rx4SupplyRawStatus;
                    pSupplyErr->Rx3Supply1V8LowErr = (BOOL)SupplyErrorFlagRaw.bits_st.SupplyLowErrorFlag1V8Rx3SupplyRawStatus;
                    pSupplyErr->Rx2Supply1V8LowErr = (BOOL)SupplyErrorFlagRaw.bits_st.SupplyLowErrorFlag1V8Rx2SupplyRawStatus;
                    pSupplyErr->Rx1Supply1V8LowErr = (BOOL)SupplyErrorFlagRaw.bits_st.SupplyLowErrorFlag1V8Rx1SupplyRawStatus;
                    pSupplyErr->Tx3Supply1v8LowErr = (BOOL)SupplyErrorFlagRaw.bits_st.SupplyLowErrorFlag1V8Tx3SupplyRawStatus;
                    pSupplyErr->Tx2Supply1v8LowErr = (BOOL)SupplyErrorFlagRaw.bits_st.SupplyLowErrorFlag1V8Tx2SupplyRawStatus;
                    pSupplyErr->Tx1Supply1v8LowErr = (BOOL)SupplyErrorFlagRaw.bits_st.SupplyLowErrorFlag1V8Tx1SupplyRawStatus;
                    pSupplyErr->Tx3Supply1v1LowErr = (BOOL)SupplyErrorFlagRaw.bits_st.SupplyLowErrorFlag1V1Tx3SupplyRawStatus;
                    pSupplyErr->Tx2Supply1v1LowErr = (BOOL)SupplyErrorFlagRaw.bits_st.SupplyLowErrorFlag1V1Tx2SupplyRawStatus;
                    pSupplyErr->Tx1Supply1v1LowErr = (BOOL)SupplyErrorFlagRaw.bits_st.SupplyLowErrorFlag1V1Tx1SupplyRawStatus;
                }
                // Module register Error dump.
                if (pModuleErr != NULL)
                {
                    *pModuleErr = SupplyErrorFlagRaw.val_u32;
                }
            }
        }
        else // Masked Error for all IP blocks
        {
            retVal = BC_SPI_Read(e_SYS_ISM, R2M18_SUPPLY_ERROR_FLAG_MASKED_STATUS_U16, &SupplyErrorFlagMask.val_u32);
            if (retVal == BC_ERR_NOERROR)
            {
                // Only for RAW Error for all IP blocks
                if (pSupplyErr != NULL)
                {
                    pSupplyErr->GlDOSupply1v8HighErr = (BOOL)SupplyErrorFlagMask.bits_st.SupplyHighErrorFlag1V8GlobalLdoSupplyMaskedStatus;
                    pSupplyErr->GlDOSupply1v8LowErr = (BOOL)SupplyErrorFlagMask.bits_st.SupplyLowErrorFlag1V8GlobalLdoSupplyMaskedStatus;
                    pSupplyErr->GlDOSupply1v1HighErr = (BOOL)SupplyErrorFlagMask.bits_st.SupplyHighErrorFlag1V1GlobalLdoSupplyMaskedStatus;
                    pSupplyErr->GlDOSupply1v1LowErr = (BOOL)SupplyErrorFlagMask.bits_st.SupplyLowErrorFlag1V1GlobalLdoSupplyMaskedStatus;
                    pSupplyErr->ChirpDigSupply1v1LowErrorErr = (BOOL)SupplyErrorFlagMask.bits_st.SupplyLowErrorFlagDig1V1ChirpSupplyMaskedStatus;
                    pSupplyErr->ChirpVCOSupply1v8vLowErr = (BOOL)SupplyErrorFlagMask.bits_st.SupplyLowErrorFlagVco1V8ChirpSupplyMaskedStatus;
                    pSupplyErr->ChirpPLLSupply1v8vLowErr = (BOOL)SupplyErrorFlagMask.bits_st.SupplyLowErrorFlagPll1V8ChirpSupplyMaskedStatus;
                    pSupplyErr->Supply1v8SerLowErr = (BOOL)SupplyErrorFlagMask.bits_st.SupplyLowErrorFlag1V8SerSupplyMaskedStatus;
                    pSupplyErr->Supply1v1MIPILowErr = (BOOL)SupplyErrorFlagMask.bits_st.SupplyLowErrorFlag1V1Csi2SupplyMaskedStatus;
                    pSupplyErr->Supply1v1LVDSLowErr = (BOOL)SupplyErrorFlagMask.bits_st.SupplyLowErrorFlag1V1SerSupplyMaskedStatus;
                    pSupplyErr->GBIASSupply1v8LowErr = (BOOL)SupplyErrorFlagMask.bits_st.SupplyLowErrorFlag1V8GlobalBiasSupplyMaskedStatus;
                    pSupplyErr->SSBSupply1v8LowErr = (BOOL)SupplyErrorFlagMask.bits_st.SupplyLowErrorFlag1V8SsbModSupplyMaskedStatus;
                    pSupplyErr->LOISupply1v1LowErr = (BOOL)SupplyErrorFlagMask.bits_st.SupplyLowErrorFlag1V1InterfaceSupplyMaskedStatus;
                    pSupplyErr->ADC34Supply1v8LowErr = (BOOL)SupplyErrorFlagMask.bits_st.SupplyLowErrorFlag1V8Adc34SupplyMaskedStatus;
                    pSupplyErr->ADC12Supply1v8LowErr = (BOOL)SupplyErrorFlagMask.bits_st.SupplyLowErrorFlag1V8Adc12SupplyMaskedStatus;
                    pSupplyErr->MclkSupply1v8LowErr = (BOOL)SupplyErrorFlagMask.bits_st.SupplyLowErrorFlag1V8McSupplyMaskedStatus;
                    pSupplyErr->Rx4Supply1V1LowErr = (BOOL)SupplyErrorFlagMask.bits_st.SupplyLowErrorFlag1V1Rx4SupplyMaskedStatus;
                    pSupplyErr->Rx3Supply1V1LowErr = (BOOL)SupplyErrorFlagMask.bits_st.SupplyLowErrorFlag1V1Rx3SupplyMaskedStatus;
                    pSupplyErr->Rx2Supply1V1LowErr = (BOOL)SupplyErrorFlagMask.bits_st.SupplyLowErrorFlag1V1Rx2SupplyMaskedStatus;
                    pSupplyErr->Rx1Supply1V1LowErr = (BOOL)SupplyErrorFlagMask.bits_st.SupplyLowErrorFlag1V1Rx1SupplyMaskedStatus;
                    pSupplyErr->Rx4Supply1V8LowErr = (BOOL)SupplyErrorFlagMask.bits_st.SupplyLowErrorFlag1V8Rx4SupplyMaskedStatus;
                    pSupplyErr->Rx3Supply1V8LowErr = (BOOL)SupplyErrorFlagMask.bits_st.SupplyLowErrorFlag1V8Rx3SupplyMaskedStatus;
                    pSupplyErr->Rx2Supply1V8LowErr = (BOOL)SupplyErrorFlagMask.bits_st.SupplyLowErrorFlag1V8Rx2SupplyMaskedStatus;
                    pSupplyErr->Rx1Supply1V8LowErr = (BOOL)SupplyErrorFlagMask.bits_st.SupplyLowErrorFlag1V8Rx1SupplyMaskedStatus;
                    pSupplyErr->Tx3Supply1v8LowErr = (BOOL)SupplyErrorFlagMask.bits_st.SupplyLowErrorFlag1V8Tx3SupplyMaskedStatus;
                    pSupplyErr->Tx2Supply1v8LowErr = (BOOL)SupplyErrorFlagMask.bits_st.SupplyLowErrorFlag1V8Tx2SupplyMaskedStatus;
                    pSupplyErr->Tx1Supply1v8LowErr = (BOOL)SupplyErrorFlagMask.bits_st.SupplyLowErrorFlag1V8Tx1SupplyMaskedStatus;
                    pSupplyErr->Tx3Supply1v1LowErr = (BOOL)SupplyErrorFlagMask.bits_st.SupplyLowErrorFlag1V1Tx3SupplyMaskedStatus;
                    pSupplyErr->Tx2Supply1v1LowErr = (BOOL)SupplyErrorFlagMask.bits_st.SupplyLowErrorFlag1V1Tx2SupplyMaskedStatus;
                    pSupplyErr->Tx1Supply1v1LowErr = (BOOL)SupplyErrorFlagMask.bits_st.SupplyLowErrorFlag1V1Tx1SupplyMaskedStatus;
                }
                // Module register Error dump.
                if (pModuleErr != NULL)
                {
                    *pModuleErr = SupplyErrorFlagMask.val_u32;
                }
            }
        }
    }
    return retVal;
}

// This API reports status of all the Tx module errors.
BC_ERRCODE HAL_ES2_ISM_GetTxErrStatus(ISM_GetErrCmd_e CmdReg, SYS_TXErrors_t *pTx1Err, SYS_TXErrors_t *pTx2Err, SYS_TXErrors_t *pTx3Err, uint32_t *pModuleErr)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;

    if ((pTx1Err == NULL) && (pTx2Err == NULL) && (pTx3Err == NULL) && (pModuleErr == NULL))
    {
        retVal = BC_ERR_ISM_PTR_ADDR_NULL;
    }
    else
    {
        switch (CmdReg)
        {
        case e_ISM_GET_MASKED_ERR:
            retVal = Helper_ISMGetTxMaskedError(pTx1Err, pTx2Err, pTx3Err, pModuleErr);
            break;
        case e_ISM_GET_RAW_ERR:
            retVal = Helper_ISMGetTxRawError(pTx1Err, pTx2Err, pTx3Err, pModuleErr);
            break;
        case e_ISM_GET_FIT_STATUS:
            retVal = Helper_ISMGetTxFitStatus(pTx1Err, pTx2Err, pTx3Err, pModuleErr);

            break;

        default:
            retVal = BC_ERR_INPUTOUTOFRANGE;
            break;
        }
    }
    return retVal;
}

// This API reports status of all the Rx module errors.
BC_ERRCODE HAL_ES2_ISM_GetRxErrStatus(ISM_GetErrCmd_e CmdReg, SYS_RXErrors_t *pRx1Err, SYS_RXErrors_t *pRx2Err, SYS_RXErrors_t *pRx3Err, SYS_RXErrors_t *pRx4Err, uint32_t *pModuleErr)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;

    if ((pRx1Err == NULL) && (pRx2Err == NULL) && (pRx3Err == NULL) && (pRx4Err == NULL) && (pModuleErr == NULL))
    {
        retVal = BC_ERR_ISM_PTR_ADDR_NULL;
    }
    else
    {
        switch (CmdReg)
        {
        case e_ISM_GET_MASKED_ERR:
            retVal = Helper_ISMGetRxMaskedError(pRx1Err, pRx2Err, pRx3Err, pRx4Err, pModuleErr);
            break;
        case e_ISM_GET_RAW_ERR:
            retVal = Helper_ISMGetRxRawError(pRx1Err, pRx2Err, pRx3Err, pRx4Err, pModuleErr);
            break;
        case e_ISM_GET_FIT_STATUS:
            retVal = Helper_ISMGetRxFitStatus(pRx1Err, pRx2Err, pRx3Err, pRx4Err, pModuleErr);

            break;

        default:
            retVal = BC_ERR_INPUTOUTOFRANGE;
            break;
        }
    }

    return retVal;
}

// This API reports status of all the Chirp module errors.
BC_ERRCODE HAL_ES2_ISM_GetChirpErrStatus(ISM_GetErrCmd_e CmdReg, SYS_CAFCErrors_t *pChirpErr, uint32_t *pModuleErr)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M18_ChirpErrorFlagMaskedStatusUnion_t ChirpErrorFlagMask;
    R2M18_ChirpErrorFlagRawStatusUnion_t ChirpErrorFlagRaw;
    R2M18_FitStatusChirpRegUnion_t FitStatusChirp;

    if ((pChirpErr == NULL) && (pModuleErr == NULL))
    {
        retVal = BC_ERR_ISM_PTR_ADDR_NULL;
    }
    else
    {
        switch (CmdReg)
        {
        case e_ISM_GET_MASKED_ERR:
            retVal = BC_SPI_Read(e_SYS_ISM, R2M18_CHIRP_ERROR_FLAG_MASKED_STATUS_U16, &ChirpErrorFlagMask.val_u32);
            if (retVal == BC_ERR_NOERROR)
            {
                if (pChirpErr != NULL)
                {
                    pChirpErr->CAFCRegCRCErr = (BOOL)ChirpErrorFlagMask.bits_st.RegCrcErrorFlagChirpMaskedStatus;
                    pChirpErr->AAFCCalTimeoutErr = (BOOL)ChirpErrorFlagMask.bits_st.AafcCalTimeoutErrorFlagChirpMaskedStatus;
                    pChirpErr->AAFCDigitalErr = (BOOL)ChirpErrorFlagMask.bits_st.AafcErrorFlagChirpMaskedStatus;
                    pChirpErr->ChirpDigSupply1v1LowErrorErr = (BOOL)ChirpErrorFlagMask.bits_st.SupplyLowErrorFlagDig1V1ChirpMaskedStatus;
                    pChirpErr->ChirpVCOSupply1v8vLowErr = (BOOL)ChirpErrorFlagMask.bits_st.SupplyLowErrorFlagVco1V8ChirpMaskedStatus;
                    pChirpErr->ChirpPLLSupply1v8vLowErr = (BOOL)ChirpErrorFlagMask.bits_st.SupplyLowErrorFlagPll1V8ChirpMaskedStatus;
                    pChirpErr->InterfaceStuckatErr = (BOOL)ChirpErrorFlagMask.bits_st.InterfaceStuckErrorFlagChirpMaskedStatus;
                    pChirpErr->VCOFrequency480Err = (BOOL)ChirpErrorFlagMask.bits_st.VcoFreq480ErrorFlagChirpMaskedStatus;
                    pChirpErr->VCOLevelMaxErr = (BOOL)ChirpErrorFlagMask.bits_st.LevelMaxErrorFlagChirpMaskedStatus;
                    pChirpErr->VCOLevelHighErr = (BOOL)ChirpErrorFlagMask.bits_st.LevelHighErrorFlagChirpMaskedStatus;
                    pChirpErr->VCOLevelLowErr = (BOOL)ChirpErrorFlagMask.bits_st.LevelLowErrorFlagChirpMaskedStatus;
                    pChirpErr->VCOLevelMinErr = (BOOL)ChirpErrorFlagMask.bits_st.LevelMinErrorFlagChirpMaskedStatus;
                    pChirpErr->VtuneHighErr = (BOOL)ChirpErrorFlagMask.bits_st.VtuneHighErrorFlagChirpMaskedStatus;
                    pChirpErr->VtuneLowErr = (BOOL)ChirpErrorFlagMask.bits_st.VtuneLowErrorFlagChirpMaskedStatus;
                    pChirpErr->ChirpTempErr = (BOOL)ChirpErrorFlagMask.bits_st.TempErrorFlagChirpMaskedStatus;
                    pChirpErr->PLLUnlockErr = (BOOL)ChirpErrorFlagMask.bits_st.UnlockErrorFlagChirpMaskedStatus;
                    pChirpErr->ChirpDigitalLockStepErr = (BOOL)ChirpErrorFlagMask.bits_st.LockStepErrorFlagChirpMaskedStatus;
                }

                // Module register Error dump.
                if (pModuleErr != NULL)
                {
                    *pModuleErr = ChirpErrorFlagMask.val_u32;
                }
            }
            break;
        case e_ISM_GET_RAW_ERR:
            retVal = BC_SPI_Read(e_SYS_ISM, R2M18_CHIRP_ERROR_FLAG_RAW_STATUS_U16, &ChirpErrorFlagRaw.val_u32);
            if (retVal == BC_ERR_NOERROR)
            {
                if (pChirpErr != NULL)
                {
                    pChirpErr->CAFCRegCRCErr = (BOOL)ChirpErrorFlagRaw.bits_st.RegCrcErrorFlagChirpRawStatus;
                    pChirpErr->AAFCCalTimeoutErr = (BOOL)ChirpErrorFlagRaw.bits_st.AafcCalTimeoutErrorFlagChirpRawStatus;
                    pChirpErr->AAFCDigitalErr = (BOOL)ChirpErrorFlagRaw.bits_st.AafcErrorFlagChirpRawStatus;
                    pChirpErr->ChirpDigSupply1v1LowErrorErr = (BOOL)ChirpErrorFlagRaw.bits_st.SupplyLowErrorFlagDig1V1ChirpRawStatus;
                    pChirpErr->ChirpVCOSupply1v8vLowErr = (BOOL)ChirpErrorFlagRaw.bits_st.SupplyLowErrorFlagVco1V8ChirpRawStatus;
                    pChirpErr->ChirpPLLSupply1v8vLowErr = (BOOL)ChirpErrorFlagRaw.bits_st.SupplyLowErrorFlagPll1V8ChirpRawStatus;
                    pChirpErr->InterfaceStuckatErr = (BOOL)ChirpErrorFlagRaw.bits_st.InterfaceStuckErrorFlagChirpRawStatus;
                    pChirpErr->VCOFrequency480Err = (BOOL)ChirpErrorFlagRaw.bits_st.VcoFreq480ErrorFlagChirpRawStatus;
                    pChirpErr->VCOLevelMaxErr = (BOOL)ChirpErrorFlagRaw.bits_st.LevelMaxErrorFlagChirpRawStatus;
                    pChirpErr->VCOLevelHighErr = (BOOL)ChirpErrorFlagRaw.bits_st.LevelHighErrorFlagChirpRawStatus;
                    pChirpErr->VCOLevelLowErr = (BOOL)ChirpErrorFlagRaw.bits_st.LevelLowErrorFlagChirpRawStatus;
                    pChirpErr->VCOLevelMinErr = (BOOL)ChirpErrorFlagRaw.bits_st.LevelMinErrorFlagChirpRawStatus;
                    pChirpErr->VtuneHighErr = (BOOL)ChirpErrorFlagRaw.bits_st.VtuneHighErrorFlagChirpRawStatus;
                    pChirpErr->VtuneLowErr = (BOOL)ChirpErrorFlagRaw.bits_st.VtuneLowErrorFlagChirpRawStatus;
                    pChirpErr->ChirpTempErr = (BOOL)ChirpErrorFlagRaw.bits_st.TempErrorFlagChirpRawStatus;
                    pChirpErr->PLLUnlockErr = (BOOL)ChirpErrorFlagRaw.bits_st.UnlockErrorFlagChirpRawStatus;
                    pChirpErr->ChirpDigitalLockStepErr = (BOOL)ChirpErrorFlagRaw.bits_st.LockStepErrorFlagChirpRawStatus;
                }
                // Module register Error dump.
                if (pModuleErr != NULL)
                {
                    *pModuleErr = ChirpErrorFlagRaw.val_u32;
                }
            }
            break;
        case e_ISM_GET_FIT_STATUS:
            retVal = BC_SPI_Read(e_SYS_ISM, R2M18_FIT_STATUS_CHIRP_REG_U16, &FitStatusChirp.val_u32);
            if (retVal == BC_ERR_NOERROR)
            {
                if (pChirpErr != NULL)
                {
                    pChirpErr->CAFCRegCRCErr = (BOOL)FitStatusChirp.bits_st.RegCrcErrorFlagChirpFitStatus;
                    pChirpErr->AAFCCalTimeoutErr = (BOOL)FitStatusChirp.bits_st.AafcCalTimeoutErrorFlagChirpFitStatus;
                    pChirpErr->AAFCDigitalErr = (BOOL)FitStatusChirp.bits_st.AafcErrorFlagChirpFitStatus;
                    pChirpErr->ChirpDigSupply1v1LowErrorErr = (BOOL)FitStatusChirp.bits_st.SupplyLowErrorFlagDig1V1ChirpFitStatus;
                    pChirpErr->ChirpVCOSupply1v8vLowErr = (BOOL)FitStatusChirp.bits_st.SupplyLowErrorFlagVco1V8ChirpFitStatus;
                    pChirpErr->ChirpPLLSupply1v8vLowErr = (BOOL)FitStatusChirp.bits_st.SupplyLowErrorFlagPll1V8ChirpFitStatus;
                    pChirpErr->InterfaceStuckatErr = (BOOL)FitStatusChirp.bits_st.InterfaceStuckErrorFlagChirpFitStatus;
                    pChirpErr->VCOFrequency480Err = (BOOL)FitStatusChirp.bits_st.VcoFreq480ErrorFlagChirpFitStatus;
                    pChirpErr->VCOLevelMaxErr = (BOOL)FitStatusChirp.bits_st.LevelMaxErrorFlagChirpFitStatus;
                    pChirpErr->VCOLevelHighErr = (BOOL)FitStatusChirp.bits_st.LevelHighErrorFlagChirpFitStatus;
                    pChirpErr->VCOLevelLowErr = (BOOL)FitStatusChirp.bits_st.LevelLowErrorFlagChirpFitStatus;
                    pChirpErr->VCOLevelMinErr = (BOOL)FitStatusChirp.bits_st.LevelMinErrorFlagChirpFitStatus;
                    pChirpErr->VtuneHighErr = (BOOL)FitStatusChirp.bits_st.VtuneHighErrorFlagChirpFitStatus;
                    pChirpErr->VtuneLowErr = (BOOL)FitStatusChirp.bits_st.VtuneLowErrorFlagChirpFitStatus;
                    pChirpErr->ChirpTempErr = (BOOL)FitStatusChirp.bits_st.TempErrorFlagChirpFitStatus;
                    pChirpErr->PLLUnlockErr = (BOOL)FitStatusChirp.bits_st.UnlockErrorFlagChirpFitStatus;
                    pChirpErr->ChirpDigitalLockStepErr = (BOOL)FitStatusChirp.bits_st.LockStepErrorFlagChirpFitStatus;
                }
                // Module register Error dump.
                if (pModuleErr != NULL)
                {
                    *pModuleErr = FitStatusChirp.val_u32;
                }
            }
            break;

        default:
            retVal = BC_ERR_INPUTOUTOFRANGE;
            break;
        }
    }
    return retVal;
}

// This API reports status of all error of Master Clock, LO interface, ISM and OTP modules.
BC_ERRCODE HAL_ES2_ISM_GetMClkLOISMOTPErrStatus(ISM_GetErrCmd_e CmdReg, BOOL *pOTPRegCRCErr, BOOL *pISMRegCRCErr, SYS_MCLKErrors_t *pMClkErr, SYS_LOIErrors_t *pLOIErr, SYS_CCErrors_t *pCCErr, uint32_t *pModuleErr)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M18_McLoCcIsmOtpErrorFlagMaskedStatusUnion_t McLoCcIsmOtpErrorFlagMask;

    if ((pOTPRegCRCErr == NULL) && (pISMRegCRCErr == NULL) && (pMClkErr == NULL) && (pLOIErr == NULL) && (pCCErr == NULL) && (pModuleErr == NULL))
    {
        retVal = BC_ERR_ISM_PTR_ADDR_NULL;
    }
    else
    {
        switch (CmdReg)
        {
        case e_ISM_GET_MASKED_ERR:
            retVal = BC_SPI_Read(e_SYS_ISM, R2M18_MC_LO_CC_ISM_OTP_ERROR_FLAG_MASKED_STATUS_U16, &McLoCcIsmOtpErrorFlagMask.val_u32);
            break;
        case e_ISM_GET_RAW_ERR:
            retVal = BC_SPI_Read(e_SYS_ISM, R2M18_MC_LO_CC_ISM_OTP_ERROR_FLAG_RAW_STATUS_U16, &McLoCcIsmOtpErrorFlagMask.val_u32);
            break;
        case e_ISM_GET_FIT_STATUS:
            retVal = BC_SPI_Read(e_SYS_ISM, R2M18_FIT_STATUS_MC_LO_CC_ISM_OTP_REG_U16, &McLoCcIsmOtpErrorFlagMask.val_u32);
            break;
        default:
            retVal = BC_ERR_INPUTOUTOFRANGE;
            break;
        }
        if (retVal == BC_ERR_NOERROR)
        {
            if (pOTPRegCRCErr != NULL)
            {
                *pOTPRegCRCErr = (BOOL)McLoCcIsmOtpErrorFlagMask.bits_st.RegCrcErrorFlagOtpMaskedStatus;
            }
            if (pISMRegCRCErr != NULL)
            {
                *pISMRegCRCErr = (BOOL)McLoCcIsmOtpErrorFlagMask.bits_st.RegCrcErrorFlagIsmMaskedStatus;
            }
            if (pMClkErr != NULL)
            {
                pMClkErr->MclkRegCRCErr = (BOOL)McLoCcIsmOtpErrorFlagMask.bits_st.RegCrcErrorFlagMcMaskedStatus;
                pMClkErr->MclkPllCalErr = (BOOL)McLoCcIsmOtpErrorFlagMask.bits_st.PllFreqCalErrorFlagMcMaskedStatus;
                pMClkErr->MclkPllLevelErr = (BOOL)McLoCcIsmOtpErrorFlagMask.bits_st.PllLevelErrorFlagMcMaskedStatus;
                pMClkErr->MclkPllLockErr = (BOOL)McLoCcIsmOtpErrorFlagMask.bits_st.PllLockErrorFlagMcMaskedStatus;
                pMClkErr->MclkDigOutPutFreqErr = (BOOL)McLoCcIsmOtpErrorFlagMask.bits_st.DigFreqErrorFlagMcMaskedStatus;
                pMClkErr->MclkSupply1v8LowErr = (BOOL)McLoCcIsmOtpErrorFlagMask.bits_st.SupplyLowErrorFlag1V8McMaskedStatus;
                pMClkErr->MclkMSPCErr = (BOOL)McLoCcIsmOtpErrorFlagMask.bits_st.MspcErrorFlagMcMaskedStatus;
                pMClkErr->MclkXoNoClkErr = (BOOL)McLoCcIsmOtpErrorFlagMask.bits_st.XoNoClockErrorFlagMcMaskedStatus;
            }
            if (pLOIErr != NULL)
            {
                pLOIErr->LOIRegCRC_Err = (BOOL)McLoCcIsmOtpErrorFlagMask.bits_st.RegCrcErrorFlagInterfaceMaskedStatus;
                pLOIErr->LOILevelMaxErr = (BOOL)McLoCcIsmOtpErrorFlagMask.bits_st.LoiLevelMaxErrorFlagInterfaceMaskedStatus;
                pLOIErr->LOILeveHighErr = (BOOL)McLoCcIsmOtpErrorFlagMask.bits_st.LoiLevelHighErrorFlagInterfaceMaskedStatus;
                pLOIErr->LOILeveLowErr = (BOOL)McLoCcIsmOtpErrorFlagMask.bits_st.LoiLevelLowErrorFlagInterfaceMaskedStatus;
                pLOIErr->LOILeveMinErr = (BOOL)McLoCcIsmOtpErrorFlagMask.bits_st.LoiLevelMinErrorFlagInterfaceMaskedStatus;
                pLOIErr->LOIInConnectionErr = (BOOL)McLoCcIsmOtpErrorFlagMask.bits_st.BbLoinErrorFlagInterfaceMaskedStatus;
                pLOIErr->LOIOutConnectionErr = (BOOL)McLoCcIsmOtpErrorFlagMask.bits_st.BbLooutErrorFlagInterfaceMaskedStatus;
                pLOIErr->LOISupply1v1LowErr = (BOOL)McLoCcIsmOtpErrorFlagMask.bits_st.SupplyLowErrorFlag1V1InterfaceMaskedStatus;
            }
            if (pCCErr != NULL)
            {
                pCCErr->CCRegCRCErr = (BOOL)McLoCcIsmOtpErrorFlagMask.bits_st.RegCrcErrorFlagCcMaskedStatus;
                pCCErr->SPIRdErr = (BOOL)McLoCcIsmOtpErrorFlagMask.bits_st.RdSpiCrcErrorFlagMaskedStatus;
                pCCErr->SPIWrErr = (BOOL)McLoCcIsmOtpErrorFlagMask.bits_st.WrSpiCrcErrorFlagMaskedStatus;
            }
            // Module register Error dump.
            if (pModuleErr != NULL)
            {
                *pModuleErr = McLoCcIsmOtpErrorFlagMask.val_u32;
            }
        }
    }
    return retVal;
}

// This API reports status of all the errors of  SSB, Serialiser, GBIAS and ATB modules modules.
BC_ERRCODE HAL_ES2_ISM_GetSSBSerGBGLDOATBErr(ISM_GetErrCmd_e CmdReg, BOOL *pATBRegCRCErr, SYS_SerialiserErrors_t *pSerErr, SYS_SSBErrors_t *pSSBErr, SYS_GBIASErrors_t *pGBErr, SYS_GLDOErrors_t *pGLDOErr, uint32_t *pModuleErr)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M18_SsbGbSerGldoAtbErrorFlagMaskedStatusUnion_t SsbGbSerGldoAtbErrorFlagMask;

    if ((pATBRegCRCErr == NULL) && (pSerErr == NULL) && (pSSBErr == NULL) && (pGBErr == NULL) && (pGLDOErr == NULL) && (pModuleErr == NULL))
    {
        retVal = BC_ERR_ISM_PTR_ADDR_NULL;
    }
    else
    {
        switch (CmdReg)
        {
        case e_ISM_GET_MASKED_ERR:
            retVal = BC_SPI_Read(e_SYS_ISM, R2M18_SSB_GB_SER_GLDO_ATB_ERROR_FLAG_MASKED_STATUS_U16, &SsbGbSerGldoAtbErrorFlagMask.val_u32);
            break;
        case e_ISM_GET_RAW_ERR:
            retVal = BC_SPI_Read(e_SYS_ISM, R2M18_SSB_GB_SER_GLDO_ATB_ERROR_FLAG_RAW_STATUS_U16, &SsbGbSerGldoAtbErrorFlagMask.val_u32);
            break;
        case e_ISM_GET_FIT_STATUS:
            retVal = BC_SPI_Read(e_SYS_ISM, R2M18_FIT_STATUS_SSB_GB_SER_GLDO_ATB_REG_U16, &SsbGbSerGldoAtbErrorFlagMask.val_u32);
            break;
        default:
            retVal = BC_ERR_INPUTOUTOFRANGE;
            break;
        }
        if (retVal == BC_ERR_NOERROR)
        {
            if (pATBRegCRCErr != NULL)
            {
                *pATBRegCRCErr = (BOOL)SsbGbSerGldoAtbErrorFlagMask.bits_st.RegCrcErrorFlagAtbMaskedStatus;
            }
            if (pSerErr != NULL)
            {
                pSerErr->SerRegCRCErr = (BOOL)SsbGbSerGldoAtbErrorFlagMask.bits_st.RegCrcErrorFlagSerMaskedStatus;
                pSerErr->Supply1v8SerLowErr = (BOOL)SsbGbSerGldoAtbErrorFlagMask.bits_st.SupplyLowErrorFlag1V8SerMaskedStatus;
                pSerErr->Supply1v1MIPILowErr = (BOOL)SsbGbSerGldoAtbErrorFlagMask.bits_st.SupplyLowErrorFlag1V1Csi2MaskedStatus;
                pSerErr->Supply1v1LVDSLowErr = (BOOL)SsbGbSerGldoAtbErrorFlagMask.bits_st.SupplyLowErrorFlag1V1SerMaskedStatus;
            }
            if (pSSBErr != NULL)
            {
                pSSBErr->SSBRegCRCErr = (BOOL)SsbGbSerGldoAtbErrorFlagMask.bits_st.RegCrcErrorFlagSsbModMaskedStatus;
                pSSBErr->SSBSupply1v8LowErr = (BOOL)SsbGbSerGldoAtbErrorFlagMask.bits_st.SupplyLowErrorFlag1V8SsbModMaskedStatus;
            }
            if (pGBErr != NULL)
            {
                pGBErr->GBIASRegCRCErr = (BOOL)SsbGbSerGldoAtbErrorFlagMask.bits_st.RegCrcErrorFlagGlobalBiasMaskedStatus;
                pGBErr->GBIASSupply1v8LowErr = (BOOL)SsbGbSerGldoAtbErrorFlagMask.bits_st.SupplyLowErrorFlag1V8GlobalBiasMaskedStatus;
            }
            if (pGLDOErr != NULL)
            {
                pGLDOErr->GlDORegCRCErr = (BOOL)SsbGbSerGldoAtbErrorFlagMask.bits_st.RegCrcErrorFlagGlobalLdoMaskedStatus;
                pGLDOErr->GlDOSupply1v8HighErr = (BOOL)SsbGbSerGldoAtbErrorFlagMask.bits_st.SupplyHighErrorFlag1V8GlobalLdoMaskedStatus;
                pGLDOErr->GlDOSupply1v8LowErr = (BOOL)SsbGbSerGldoAtbErrorFlagMask.bits_st.SupplyLowErrorFlag1V8GlobalLdoMaskedStatus;
                pGLDOErr->GlDOSupply1v1HighErr = (BOOL)SsbGbSerGldoAtbErrorFlagMask.bits_st.SupplyHighErrorFlag1V1GlobalLdoMaskedStatus;
                pGLDOErr->GlDOSupply1v1LowErr = (BOOL)SsbGbSerGldoAtbErrorFlagMask.bits_st.SupplyLowErrorFlag1V1GlobalLdoMaskedStatus;
            }
            // Module register Error dump.
            if (pModuleErr != NULL)
            {
                *pModuleErr = SsbGbSerGldoAtbErrorFlagMask.val_u32;
            }
        }
    }
    return retVal;
}

// This API reports status of all the ADC module errors
BC_ERRCODE HAL_ES2_ISM_GetADCErrStatus(ISM_GetErrCmd_e CmdReg, SYS_ADCErrors_t *pADC12Err, SYS_ADCErrors_t *pADC34Err, uint32_t *pModuleErr)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M18_AdcErrorFlagMaskedStatusUnion_t AdcErrorFlagMask;
    R2M18_AdcErrorFlagRawStatusUnion_t AdcErrorFlagRaw;
    R2M18_FitStatusAdcRegUnion_t FitStatusAdc;

    if ((pADC12Err == NULL) && (pADC34Err == NULL) && (pModuleErr == NULL))
    {
        retVal = BC_ERR_ISM_PTR_ADDR_NULL;
    }
    else
    {
        switch (CmdReg)
        {
        case e_ISM_GET_MASKED_ERR:
            retVal = BC_SPI_Read(e_SYS_ISM, R2M18_ADC_ERROR_FLAG_MASKED_STATUS_U16, &AdcErrorFlagMask.val_u32);
            if (retVal == BC_ERR_NOERROR)
            {
                if (pADC12Err != NULL)
                {
                    pADC12Err->ADCRegCrcErr = (BOOL)AdcErrorFlagMask.bits_st.RegCrcErrorFlagAdc12MaskedStatus;
                    pADC12Err->ADCSupply1v8LowErr = (BOOL)AdcErrorFlagMask.bits_st.SupplyLowErrorFlag1V8Adc12MaskedStatus;
                    pADC12Err->ADCn1HardClippingErr = (BOOL)AdcErrorFlagMask.bits_st.HardClippingFlagPersistentAdc2MaskedStatus;
                    pADC12Err->ADCn0HardClippingErr = (BOOL)AdcErrorFlagMask.bits_st.HardClippingFlagPersistentAdc1MaskedStatus;
                    pADC12Err->ADCn1CalErr = (BOOL)AdcErrorFlagMask.bits_st.CalErrorFlagPersistentAdc2MaskedStatus;
                    pADC12Err->ADCn0CalErr = (BOOL)AdcErrorFlagMask.bits_st.CalErrorFlagPersistentAdc1MaskedStatus;
                }
                if (pADC34Err != NULL)
                {
                    pADC34Err->ADCRegCrcErr = (BOOL)AdcErrorFlagMask.bits_st.RegCrcErrorFlagAdc34MaskedStatus;
                    pADC34Err->ADCSupply1v8LowErr = (BOOL)AdcErrorFlagMask.bits_st.SupplyLowErrorFlag1V8Adc34MaskedStatus;
                    pADC34Err->ADCn1HardClippingErr = (BOOL)AdcErrorFlagMask.bits_st.HardClippingFlagPersistentAdc4MaskedStatus;
                    pADC34Err->ADCn0HardClippingErr = (BOOL)AdcErrorFlagMask.bits_st.HardClippingFlagPersistentAdc3MaskedStatus;
                    pADC34Err->ADCn1CalErr = (BOOL)AdcErrorFlagMask.bits_st.CalErrorFlagPersistentAdc4MaskedStatus;
                    pADC34Err->ADCn0CalErr = (BOOL)AdcErrorFlagMask.bits_st.CalErrorFlagPersistentAdc3MaskedStatus;
                }
                // Module register Error dump.
                if (pModuleErr != NULL)
                {
                    *pModuleErr = AdcErrorFlagMask.val_u32;
                }
            }
            break;
        case e_ISM_GET_RAW_ERR:
            retVal = BC_SPI_Read(e_SYS_ISM, R2M18_ADC_ERROR_FLAG_RAW_STATUS_U16, &AdcErrorFlagRaw.val_u32);
            if (retVal == BC_ERR_NOERROR)
            {
                if (pADC12Err != NULL)
                {
                    pADC12Err->ADCRegCrcErr = (BOOL)AdcErrorFlagRaw.bits_st.RegCrcErrorFlagAdc12RawStatus;
                    pADC12Err->ADCSupply1v8LowErr = (BOOL)AdcErrorFlagRaw.bits_st.SupplyLowErrorFlag1V8Adc12RawStatus;
                    pADC12Err->ADCn1HardClippingErr = (BOOL)AdcErrorFlagRaw.bits_st.HardClippingFlagPersistentAdc2RawStatus;
                    pADC12Err->ADCn0HardClippingErr = (BOOL)AdcErrorFlagRaw.bits_st.HardClippingFlagPersistentAdc1RawStatus;
                    pADC12Err->ADCn1CalErr = (BOOL)AdcErrorFlagRaw.bits_st.CalErrorFlagPersistentAdc2RawStatus;
                    pADC12Err->ADCn0CalErr = (BOOL)AdcErrorFlagRaw.bits_st.CalErrorFlagPersistentAdc1RawStatus;
                }
                if (pADC34Err != NULL)
                {
                    pADC34Err->ADCRegCrcErr = (BOOL)AdcErrorFlagRaw.bits_st.RegCrcErrorFlagAdc34RawStatus;
                    pADC34Err->ADCSupply1v8LowErr = (BOOL)AdcErrorFlagRaw.bits_st.SupplyLowErrorFlag1V8Adc34RawStatus;
                    pADC34Err->ADCn1HardClippingErr = (BOOL)AdcErrorFlagRaw.bits_st.HardClippingFlagPersistentAdc4RawStatus;
                    pADC34Err->ADCn0HardClippingErr = (BOOL)AdcErrorFlagRaw.bits_st.HardClippingFlagPersistentAdc3RawStatus;
                    pADC34Err->ADCn1CalErr = (BOOL)AdcErrorFlagRaw.bits_st.CalErrorFlagPersistentAdc4RawStatus;
                    pADC34Err->ADCn0CalErr = (BOOL)AdcErrorFlagRaw.bits_st.CalErrorFlagPersistentAdc3RawStatus;
                }
                // Module register Error dump.
                if (pModuleErr != NULL)
                {
                    *pModuleErr = AdcErrorFlagRaw.val_u32;
                }
            }
            break;
        case e_ISM_GET_FIT_STATUS:
            retVal = BC_SPI_Read(e_SYS_ISM, R2M18_FIT_STATUS_ADC_REG_U16, &FitStatusAdc.val_u32);
            if (retVal == BC_ERR_NOERROR)
            {
                if (pADC12Err != NULL)
                {
                    pADC12Err->ADCRegCrcErr = (BOOL)FitStatusAdc.bits_st.RegCrcErrorFlagAdc12FitStatus;
                    pADC12Err->ADCSupply1v8LowErr = (BOOL)FitStatusAdc.bits_st.SupplyLowErrorFlag1V8Adc12FitStatus;
                    pADC12Err->ADCn1HardClippingErr = (BOOL)FitStatusAdc.bits_st.HardClippingFlagPersistentAdc2FitStatus;
                    pADC12Err->ADCn0HardClippingErr = (BOOL)FitStatusAdc.bits_st.HardClippingFlagPersistentAdc1FitStatus;
                    pADC12Err->ADCn1CalErr = (BOOL)FitStatusAdc.bits_st.CalErrorFlagPersistentAdc2FitStatus;
                    pADC12Err->ADCn0CalErr = (BOOL)FitStatusAdc.bits_st.CalErrorFlagPersistentAdc1FitStatus;
                }
                if (pADC34Err != NULL)
                {
                    pADC34Err->ADCRegCrcErr = (BOOL)FitStatusAdc.bits_st.RegCrcErrorFlagAdc34FitStatus;
                    pADC34Err->ADCSupply1v8LowErr = (BOOL)FitStatusAdc.bits_st.SupplyLowErrorFlag1V8Adc34FitStatus;
                    pADC34Err->ADCn1HardClippingErr = (BOOL)FitStatusAdc.bits_st.HardClippingFlagPersistentAdc4FitStatus;
                    pADC34Err->ADCn0HardClippingErr = (BOOL)FitStatusAdc.bits_st.HardClippingFlagPersistentAdc3FitStatus;
                    pADC34Err->ADCn1CalErr = (BOOL)FitStatusAdc.bits_st.CalErrorFlagPersistentAdc4FitStatus;
                    pADC34Err->ADCn0CalErr = (BOOL)FitStatusAdc.bits_st.CalErrorFlagPersistentAdc3FitStatus;
                }
                // Module register Error dump.
                if (pModuleErr != NULL)
                {
                    *pModuleErr = FitStatusAdc.val_u32;
                }
            }
            break;
        default:
            retVal = BC_ERR_INPUTOUTOFRANGE;
            break;
        }
    }
    return retVal;
}

// This API reports all the register CRC error status of all the modules.
BC_ERRCODE HAL_ES2_ISM_GetRegCRCErrStatus(BOOL RawErr, SYS_RegCRCErrors_t *pRegCRCErr, uint32_t *pModuleErr)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M18_RegCrcErrorFlagMaskedStatusUnion_t CRCErrorFlagMask;
    R2M18_RegCrcErrorFlagRawStatusUnion_t CRCErrorFlagRaw;

    if ((pRegCRCErr == NULL) && (pModuleErr == NULL))
    {
        retVal = BC_ERR_ISM_PTR_ADDR_NULL;
    }
    else
    { // For RAW Error
        if (RawErr == TRUE)
        {
            retVal = BC_SPI_Read(e_SYS_ISM, R2M18_REG_CRC_ERROR_FLAG_RAW_STATUS_U16, &CRCErrorFlagRaw.val_u32);
            if (retVal == BC_ERR_NOERROR)
            {
                if (pRegCRCErr != NULL)
                {
                    pRegCRCErr->ADC34RegCrcErr = (BOOL)CRCErrorFlagRaw.bits_st.RegCrcErrorFlagAdc34RegCrcRawStatus;
                    pRegCRCErr->ADC12RegCrcErr = (BOOL)CRCErrorFlagRaw.bits_st.RegCrcErrorFlagAdc12RegCrcRawStatus;
                    pRegCRCErr->ATBRegCRCErr = (BOOL)CRCErrorFlagRaw.bits_st.RegCrcErrorFlagAtbRegCrcRawStatus;
                    pRegCRCErr->GlDORegCRCErr = (BOOL)CRCErrorFlagRaw.bits_st.RegCrcErrorFlagGlobalLdoRegCrcRawStatus;
                    pRegCRCErr->SerRegCRCErr = (BOOL)CRCErrorFlagRaw.bits_st.RegCrcErrorFlagSerRegCrcRawStatus;
                    pRegCRCErr->GBIASRegCRCErr = (BOOL)CRCErrorFlagRaw.bits_st.RegCrcErrorFlagGlobalBiasRegCrcRawStatus;
                    pRegCRCErr->SSBRegCRCErr = (BOOL)CRCErrorFlagRaw.bits_st.RegCrcErrorFlagSsbModRegCrcRawStatus;
                    pRegCRCErr->OTPRegCRCErr = (BOOL)CRCErrorFlagRaw.bits_st.RegCrcErrorFlagOtpRegCrcRawStatus;
                    pRegCRCErr->ISMRegCRCErr = (BOOL)CRCErrorFlagRaw.bits_st.RegCrcErrorFlagIsmRegCrcRawStatus;
                    pRegCRCErr->CCRegCRCErr = (BOOL)CRCErrorFlagRaw.bits_st.RegCrcErrorFlagCcRegCrcRawStatus;
                    pRegCRCErr->LOIRegCRC_Err = (BOOL)CRCErrorFlagRaw.bits_st.RegCrcErrorFlagInterfaceRegCrcRawStatus;
                    pRegCRCErr->MclkRegCRCErr = (BOOL)CRCErrorFlagRaw.bits_st.RegCrcErrorFlagMcRegCrcRawStatus;
                    pRegCRCErr->CAFCRegCRCErr = (BOOL)CRCErrorFlagRaw.bits_st.RegCrcErrorFlagChirpRegCrcRawStatus;
                    pRegCRCErr->Rx4RegCRCErr = (BOOL)CRCErrorFlagRaw.bits_st.RegCrcErrorFlagRx4RegCrcRawStatus;
                    pRegCRCErr->Rx3RegCRCErr = (BOOL)CRCErrorFlagRaw.bits_st.RegCrcErrorFlagRx3RegCrcRawStatus;
                    pRegCRCErr->Rx2RegCRCErr = (BOOL)CRCErrorFlagRaw.bits_st.RegCrcErrorFlagRx2RegCrcRawStatus;
                    pRegCRCErr->Rx1RegCRCErr = (BOOL)CRCErrorFlagRaw.bits_st.RegCrcErrorFlagRx1RegCrcRawStatus;
                    pRegCRCErr->Tx3RegCRCErr = (BOOL)CRCErrorFlagRaw.bits_st.RegCrcErrorFlagTx3RegCrcRawStatus;
                    pRegCRCErr->Tx2RegCRCErr = (BOOL)CRCErrorFlagRaw.bits_st.RegCrcErrorFlagTx2RegCrcRawStatus;
                    pRegCRCErr->Tx1RegCRCErr = (BOOL)CRCErrorFlagRaw.bits_st.RegCrcErrorFlagTx1RegCrcRawStatus;
                }
                // Module register Error dump.
                if (pModuleErr != NULL)
                {
                    *pModuleErr = CRCErrorFlagRaw.val_u32;
                }
            }
        }
        else // Masked Error for all IP blocks
        {
            retVal = BC_SPI_Read(e_SYS_ISM, R2M18_REG_CRC_ERROR_FLAG_MASKED_STATUS_U16, &CRCErrorFlagMask.val_u32);
            if (retVal == BC_ERR_NOERROR)
            {
                // Only for RAW Error for all IP blocks
                if (pRegCRCErr != NULL)
                {
                    pRegCRCErr->ADC34RegCrcErr = (BOOL)CRCErrorFlagMask.bits_st.RegCrcErrorFlagAdc34RegCrcMaskedStatus;
                    pRegCRCErr->ADC12RegCrcErr = (BOOL)CRCErrorFlagMask.bits_st.RegCrcErrorFlagAdc12RegCrcMaskedStatus;
                    pRegCRCErr->ATBRegCRCErr = (BOOL)CRCErrorFlagMask.bits_st.RegCrcErrorFlagAtbRegCrcMaskedStatus;
                    pRegCRCErr->GlDORegCRCErr = (BOOL)CRCErrorFlagMask.bits_st.RegCrcErrorFlagGlobalLdoRegCrcMaskedStatus;
                    pRegCRCErr->SerRegCRCErr = (BOOL)CRCErrorFlagMask.bits_st.RegCrcErrorFlagSerRegCrcMaskedStatus;
                    pRegCRCErr->GBIASRegCRCErr = (BOOL)CRCErrorFlagMask.bits_st.RegCrcErrorFlagGlobalBiasRegCrcMaskedStatus;
                    pRegCRCErr->SSBRegCRCErr = (BOOL)CRCErrorFlagMask.bits_st.RegCrcErrorFlagSsbModRegCrcMaskedStatus;
                    pRegCRCErr->OTPRegCRCErr = (BOOL)CRCErrorFlagMask.bits_st.RegCrcErrorFlagOtpRegCrcMaskedStatus;
                    pRegCRCErr->ISMRegCRCErr = (BOOL)CRCErrorFlagMask.bits_st.RegCrcErrorFlagIsmRegCrcMaskedStatus;
                    pRegCRCErr->CCRegCRCErr = (BOOL)CRCErrorFlagMask.bits_st.RegCrcErrorFlagCcRegCrcMaskedStatus;
                    pRegCRCErr->LOIRegCRC_Err = (BOOL)CRCErrorFlagMask.bits_st.RegCrcErrorFlagInterfaceRegCrcMaskedStatus;
                    pRegCRCErr->MclkRegCRCErr = (BOOL)CRCErrorFlagMask.bits_st.RegCrcErrorFlagMcRegCrcMaskedStatus;
                    pRegCRCErr->CAFCRegCRCErr = (BOOL)CRCErrorFlagMask.bits_st.RegCrcErrorFlagChirpRegCrcMaskedStatus;
                    pRegCRCErr->Rx4RegCRCErr = (BOOL)CRCErrorFlagMask.bits_st.RegCrcErrorFlagRx4RegCrcMaskedStatus;
                    pRegCRCErr->Rx3RegCRCErr = (BOOL)CRCErrorFlagMask.bits_st.RegCrcErrorFlagRx3RegCrcMaskedStatus;
                    pRegCRCErr->Rx2RegCRCErr = (BOOL)CRCErrorFlagMask.bits_st.RegCrcErrorFlagRx2RegCrcMaskedStatus;
                    pRegCRCErr->Rx1RegCRCErr = (BOOL)CRCErrorFlagMask.bits_st.RegCrcErrorFlagRx1RegCrcMaskedStatus;
                    pRegCRCErr->Tx3RegCRCErr = (BOOL)CRCErrorFlagMask.bits_st.RegCrcErrorFlagTx3RegCrcMaskedStatus;
                    pRegCRCErr->Tx2RegCRCErr = (BOOL)CRCErrorFlagMask.bits_st.RegCrcErrorFlagTx2RegCrcMaskedStatus;
                    pRegCRCErr->Tx1RegCRCErr = (BOOL)CRCErrorFlagMask.bits_st.RegCrcErrorFlagTx1RegCrcMaskedStatus;
                }
                // Module register Error dump.
                if (pModuleErr != NULL)
                {
                    *pModuleErr = CRCErrorFlagMask.val_u32;
                }
            }
        }
    }

    return retVal;
}

BC_ERRCODE HAL_ES2_ISM_SetRFPowDwnMask(SYS_RFPowerDownMask_t *pRFPowerDownMask)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M18_RfPowerdownMaskUnion_t RfPowerdownMask;

    if (pRFPowerDownMask == NULL)
    {
        retVal = BC_ERR_ISM_PTR_ADDR_NULL;
    }
    else
    {
        RfPowerdownMask.val_u32 = 0u;
        RfPowerdownMask.bits_st.LoiLevelMaxErrorFlagInterfaceRfPowerdownMask = pRFPowerDownMask->LOIPowerDownMask;
        RfPowerdownMask.bits_st.LevelMaxErrorFlagChirpRfPowerdownMask = pRFPowerDownMask->VCOPowerDownMask;
        RfPowerdownMask.bits_st.RfLevelMaxErrorFlagTx3RfPowerdownMask = pRFPowerDownMask->Tx3RfPowerDownMask;
        RfPowerdownMask.bits_st.RfLevelMaxErrorFlagTx2RfPowerdownMask = pRFPowerDownMask->Tx2RfPowerDownMask;
        RfPowerdownMask.bits_st.RfLevelMaxErrorFlagTx1RfPowerdownMask = pRFPowerDownMask->Tx1RfPowerDownMask;
        RfPowerdownMask.bits_st.LoLevelMaxErrorFlagRx4RfPowerdownMask = pRFPowerDownMask->Rx4LOPowerDownMask;
        RfPowerdownMask.bits_st.LoLevelMaxErrorFlagRx3RfPowerdownMask = pRFPowerDownMask->Rx3LOPowerDownMask;
        RfPowerdownMask.bits_st.LoLevelMaxErrorFlagRx2RfPowerdownMask = pRFPowerDownMask->Rx2LOPowerDownMask;
        RfPowerdownMask.bits_st.LoLevelMaxErrorFlagRx1RfPowerdownMask = pRFPowerDownMask->Rx1LOPowerDownMask;
        retVal = BC_SPI_WriteCheck(e_SYS_ISM, R2M18_RF_POWERDOWN_MASK_U16, RfPowerdownMask.val_u32);
    }

    return retVal;
}

// This API reports all the RF power down errors modules.
BC_ERRCODE HAL_ES2_ISM_GetRFPowDwnErrStatus(BOOL RawErr, SYS_RFPowerDownErrors_t *pRFPowDwnErr, uint32_t *pModuleErr)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M18_RfPowerdownStatusUnion_t RfPowerdownStatus;
    RfPowerdownStatus.val_u32 = 0u;
    BARRACUDA_IGNORE_PARAM(RawErr);
    if ((pRFPowDwnErr == NULL) && (pModuleErr == NULL))
    {
        retVal = BC_ERR_ISM_PTR_ADDR_NULL;
    }
    else
    {
        retVal = BC_SPI_Read(e_SYS_ISM, R2M18_RF_POWERDOWN_STATUS_U16, &RfPowerdownStatus.val_u32);
        if (retVal == BC_ERR_NOERROR)
        {
            if (pRFPowDwnErr != NULL)
            {
                pRFPowDwnErr->LOILevelMaxErr = (BOOL)RfPowerdownStatus.bits_st.LoiLevelMaxErrorFlagInterfaceRfPowerdownStatus;
                pRFPowDwnErr->VCOLevelMaxErr = (BOOL)RfPowerdownStatus.bits_st.LevelMaxErrorFlagChirpRfPowerdownStatus;
                pRFPowDwnErr->Tx3RfLevelMaxErr = (BOOL)RfPowerdownStatus.bits_st.RfLevelMaxErrorFlagTx3RfPowerdownStatus;
                pRFPowDwnErr->Tx2RfLevelMaxErr = (BOOL)RfPowerdownStatus.bits_st.RfLevelMaxErrorFlagTx2RfPowerdownStatus;
                pRFPowDwnErr->Tx1RfLevelMaxErr = (BOOL)RfPowerdownStatus.bits_st.RfLevelMaxErrorFlagTx1RfPowerdownStatus;
                pRFPowDwnErr->Rx4LOLevelMaxErr = (BOOL)RfPowerdownStatus.bits_st.LoLevelMaxErrorFlagRx4RfPowerdownStatus;
                pRFPowDwnErr->Rx3LOLevelMaxErr = (BOOL)RfPowerdownStatus.bits_st.LoLevelMaxErrorFlagRx3RfPowerdownStatus;
                pRFPowDwnErr->Rx2LOLevelMaxErr = (BOOL)RfPowerdownStatus.bits_st.LoLevelMaxErrorFlagRx2RfPowerdownStatus;
                pRFPowDwnErr->Rx1LOLevelMaxErr = (BOOL)RfPowerdownStatus.bits_st.LoLevelMaxErrorFlagRx1RfPowerdownStatus;
            }
        }
        // Module register Error dump.
        if (pModuleErr != NULL)
        {
            *pModuleErr = RfPowerdownStatus.val_u32;
        }
    }

    return retVal;
}

// This API reports all ISM warnings( status errors).
BC_ERRCODE HAL_ES2_ISM_GetISMWarningStatus(BOOL RawWarning, SYS_StatusErrors_t *pISMWarning, uint32_t *pModuleErr)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M18_StatusMonitoringFlagMaskedStatusUnion_t ISMWarningErrorFlagMask;
    R2M18_StatusMonitoringFlagRawStatusUnion_t ISMWarningErrorFlagRaw;

    if ((pISMWarning == NULL) && (pModuleErr == NULL))
    {
        retVal = BC_ERR_ISM_PTR_ADDR_NULL;
    }
    else
    { // True: warnings reported form Raw warnings register
        if (RawWarning == TRUE)
        {
            retVal = BC_SPI_Read(e_SYS_ISM, R2M18_STATUS_MONITORING_FLAG_RAW_STATUS_U16, &ISMWarningErrorFlagRaw.val_u32);
            if (retVal == BC_ERR_NOERROR)
            {
                // Only for RAW Error
                if (pISMWarning != NULL)
                {
                    pISMWarning->LOILeveHighErr = (BOOL)ISMWarningErrorFlagRaw.bits_st.LoiLevelHighErrorFlagInterfaceWarningRawStatus;
                    pISMWarning->LOILeveLowErr = (BOOL)ISMWarningErrorFlagRaw.bits_st.LoiLevelLowErrorFlagInterfaceWarningRawStatus;
                    pISMWarning->ChirpTempErr = (BOOL)ISMWarningErrorFlagRaw.bits_st.TempErrorFlagChirpWarningRawStatus;
                    pISMWarning->Tx3TempHighErr = (BOOL)ISMWarningErrorFlagRaw.bits_st.TempErrorFlagTx3WarningRawStatus;
                    pISMWarning->Tx2TempHighErr = (BOOL)ISMWarningErrorFlagRaw.bits_st.TempErrorFlagTx2WarningRawStatus;
                    pISMWarning->Tx1TempHighErr = (BOOL)ISMWarningErrorFlagRaw.bits_st.TempErrorFlagTx1WarningRawStatus;

                    pISMWarning->MclkPllCalErr = (BOOL)ISMWarningErrorFlagRaw.bits_st.PllFreqCalErrorFlagMcWarningRawStatus;
                    pISMWarning->Tx3RfLevelHighErr = (BOOL)ISMWarningErrorFlagRaw.bits_st.RfLevelHighErrorFlagTx3WarningRawStatus;
                    pISMWarning->Tx2RfLevelHighErr = (BOOL)ISMWarningErrorFlagRaw.bits_st.RfLevelHighErrorFlagTx2WarningRawStatus;
                    pISMWarning->Tx1RfLevelHighErr = (BOOL)ISMWarningErrorFlagRaw.bits_st.RfLevelHighErrorFlagTx1WarningRawStatus;
                    pISMWarning->Tx3RfLevelLowErr = (BOOL)ISMWarningErrorFlagRaw.bits_st.RfLevelLowErrorFlagTx3WarningRawStatus;
                    pISMWarning->Tx2RfLevelLowErr = (BOOL)ISMWarningErrorFlagRaw.bits_st.RfLevelLowErrorFlagTx2WarningRawStatus;
                    pISMWarning->Tx1RfLevelLowErr = (BOOL)ISMWarningErrorFlagRaw.bits_st.RfLevelLowErrorFlagTx1WarningRawStatus;

                    pISMWarning->Rx4LOLevelHighErr = (BOOL)ISMWarningErrorFlagRaw.bits_st.LoLevelHighErrorFlagRx4WarningRawStatus;
                    pISMWarning->Rx3LOLevelHighErr = (BOOL)ISMWarningErrorFlagRaw.bits_st.LoLevelHighErrorFlagRx3WarningRawStatus;
                    pISMWarning->Rx2LOLevelHighErr = (BOOL)ISMWarningErrorFlagRaw.bits_st.LoLevelHighErrorFlagRx2WarningRawStatus;
                    pISMWarning->Rx1LOLevelHighErr = (BOOL)ISMWarningErrorFlagRaw.bits_st.LoLevelHighErrorFlagRx1WarningRawStatus;
                    pISMWarning->Rx4LOLevelLowErr = (BOOL)ISMWarningErrorFlagRaw.bits_st.LoLevelLowErrorFlagRx4WarningRawStatus;
                    pISMWarning->Rx3LOLevelLowErr = (BOOL)ISMWarningErrorFlagRaw.bits_st.LoLevelLowErrorFlagRx3WarningRawStatus;
                    pISMWarning->Rx2LOLevelLowErr = (BOOL)ISMWarningErrorFlagRaw.bits_st.LoLevelLowErrorFlagRx2WarningRawStatus;
                    pISMWarning->Rx1LOLevelLowErr = (BOOL)ISMWarningErrorFlagRaw.bits_st.LoLevelLowErrorFlagRx1WarningRawStatus;

                    pISMWarning->VtuneHighErr = (BOOL)ISMWarningErrorFlagRaw.bits_st.VtuneHighErrorFlagChirpWarningRawStatus;
                    pISMWarning->VtuneLowErr = (BOOL)ISMWarningErrorFlagRaw.bits_st.VtuneLowErrorFlagChirpWarningRawStatus;
                    pISMWarning->VCOLevelHighErr = (BOOL)ISMWarningErrorFlagRaw.bits_st.LevelHighErrorFlagChirpWarningRawStatus;
                    pISMWarning->VCOLevelLowErr = (BOOL)ISMWarningErrorFlagRaw.bits_st.LevelLowErrorFlagChirpWarningRawStatus;
                }
                // Module register Error dump.
                if (pModuleErr != NULL)
                {
                    *pModuleErr = ISMWarningErrorFlagRaw.val_u32;
                }
            }
        }
        else // Masked Error
        {
            retVal = BC_SPI_Read(e_SYS_ISM, R2M18_STATUS_MONITORING_FLAG_MASKED_STATUS_U16, &ISMWarningErrorFlagMask.val_u32);
            if (retVal == BC_ERR_NOERROR)
            {
                if (pISMWarning != NULL)
                {
                    pISMWarning->LOILeveHighErr = (BOOL)ISMWarningErrorFlagMask.bits_st.LoiLevelHighErrorFlagInterfaceWarningMaskedStatus;
                    pISMWarning->LOILeveLowErr = (BOOL)ISMWarningErrorFlagMask.bits_st.LoiLevelLowErrorFlagInterfaceWarningMaskedStatus;
                    pISMWarning->ChirpTempErr = (BOOL)ISMWarningErrorFlagMask.bits_st.TempErrorFlagChirpWarningMaskedStatus;
                    pISMWarning->Tx3TempHighErr = (BOOL)ISMWarningErrorFlagMask.bits_st.TempErrorFlagTx3WarningMaskedStatus;
                    pISMWarning->Tx2TempHighErr = (BOOL)ISMWarningErrorFlagMask.bits_st.TempErrorFlagTx2WarningMaskedStatus;
                    pISMWarning->Tx1TempHighErr = (BOOL)ISMWarningErrorFlagMask.bits_st.TempErrorFlagTx1WarningMaskedStatus;

                    pISMWarning->MclkPllCalErr = (BOOL)ISMWarningErrorFlagMask.bits_st.PllFreqCalErrorFlagMcWarningMaskedStatus;
                    pISMWarning->Tx3RfLevelHighErr = (BOOL)ISMWarningErrorFlagMask.bits_st.RfLevelHighErrorFlagTx3WarningMaskedStatus;
                    pISMWarning->Tx2RfLevelHighErr = (BOOL)ISMWarningErrorFlagMask.bits_st.RfLevelHighErrorFlagTx2WarningMaskedStatus;
                    pISMWarning->Tx1RfLevelHighErr = (BOOL)ISMWarningErrorFlagMask.bits_st.RfLevelHighErrorFlagTx1WarningMaskedStatus;
                    pISMWarning->Tx3RfLevelLowErr = (BOOL)ISMWarningErrorFlagMask.bits_st.RfLevelLowErrorFlagTx3WarningMaskedStatus;
                    pISMWarning->Tx2RfLevelLowErr = (BOOL)ISMWarningErrorFlagMask.bits_st.RfLevelLowErrorFlagTx2WarningMaskedStatus;
                    pISMWarning->Tx1RfLevelLowErr = (BOOL)ISMWarningErrorFlagMask.bits_st.RfLevelLowErrorFlagTx1WarningMaskedStatus;

                    pISMWarning->Rx4LOLevelHighErr = (BOOL)ISMWarningErrorFlagMask.bits_st.LoLevelHighErrorFlagRx4WarningMaskedStatus;
                    pISMWarning->Rx3LOLevelHighErr = (BOOL)ISMWarningErrorFlagMask.bits_st.LoLevelHighErrorFlagRx3WarningMaskedStatus;
                    pISMWarning->Rx2LOLevelHighErr = (BOOL)ISMWarningErrorFlagMask.bits_st.LoLevelHighErrorFlagRx2WarningMaskedStatus;
                    pISMWarning->Rx1LOLevelHighErr = (BOOL)ISMWarningErrorFlagMask.bits_st.LoLevelHighErrorFlagRx1WarningMaskedStatus;
                    pISMWarning->Rx4LOLevelLowErr = (BOOL)ISMWarningErrorFlagMask.bits_st.LoLevelLowErrorFlagRx4WarningMaskedStatus;
                    pISMWarning->Rx3LOLevelLowErr = (BOOL)ISMWarningErrorFlagMask.bits_st.LoLevelLowErrorFlagRx3WarningMaskedStatus;
                    pISMWarning->Rx2LOLevelLowErr = (BOOL)ISMWarningErrorFlagMask.bits_st.LoLevelLowErrorFlagRx2WarningMaskedStatus;
                    pISMWarning->Rx1LOLevelLowErr = (BOOL)ISMWarningErrorFlagMask.bits_st.LoLevelLowErrorFlagRx1WarningMaskedStatus;

                    pISMWarning->VtuneHighErr = (BOOL)ISMWarningErrorFlagMask.bits_st.VtuneHighErrorFlagChirpWarningMaskedStatus;
                    pISMWarning->VtuneLowErr = (BOOL)ISMWarningErrorFlagMask.bits_st.VtuneLowErrorFlagChirpWarningMaskedStatus;
                    pISMWarning->VCOLevelHighErr = (BOOL)ISMWarningErrorFlagMask.bits_st.LevelHighErrorFlagChirpWarningMaskedStatus;
                    pISMWarning->VCOLevelLowErr = (BOOL)ISMWarningErrorFlagMask.bits_st.LevelLowErrorFlagChirpWarningMaskedStatus;
                }
                // Module register Error dump.
                if (pModuleErr != NULL)
                {
                    *pModuleErr = ISMWarningErrorFlagMask.val_u32;
                }
            }
        }
    }

    return retVal;
}

// This API reports register provide the status of the ISM module .
BC_ERRCODE HAL_ES2_ISM_GetISMErrStatus(SYS_ISMErrorStatus_t *pISMErr, uint32_t *pModuleErr)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M18_IsmErrorStatusUnion_t IsmErrorStatus;

    if ((pISMErr == NULL) && (pModuleErr == NULL))
    {
        retVal = BC_ERR_ISM_PTR_ADDR_NULL;
    }
    else
    {
        retVal = BC_SPI_Read(e_SYS_ISM, R2M18_ISM_ERROR_STATUS_U16, &IsmErrorStatus.val_u32);
        if (retVal == BC_ERR_NOERROR)
        {
            if (pISMErr != NULL)
            {
                pISMErr->SPICRCErr = (BOOL)IsmErrorStatus.bits_st.CrcError;
                pISMErr->Digital1v1SupplyRedErr = (BOOL)IsmErrorStatus.bits_st.SupplyLow1V1DigitalErrorRed;
                pISMErr->FTTIRedErr = (BOOL)IsmErrorStatus.bits_st.FttiErrorRed;
                pISMErr->RTMRedErr = (BOOL)IsmErrorStatus.bits_st.RtmErrorRed;
                pISMErr->Digital1v1SupplyErr = (BOOL)IsmErrorStatus.bits_st.SupplyLow1V1DigitalError;
                pISMErr->FTTIErr = (BOOL)IsmErrorStatus.bits_st.FttiError;
                pISMErr->RTMErr = (BOOL)IsmErrorStatus.bits_st.RtmError;
            }
            // Module register Error dump.
            if (pModuleErr != NULL)
            {
                *pModuleErr = IsmErrorStatus.val_u32;
            }
        }
    }
    return retVal;
}

// This API Mask or Unmask all functional safety errors for all modules.
BC_ERRCODE HAL_ES2_ISM_MaskUnmaskAllErr(BOOL UnMask)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    // Tx
    SYS_TXErrors_t pTx1Err = {FALSE};
    SYS_TXErrors_t pTx2Err = {FALSE};
    SYS_TXErrors_t pTx3Err = {FALSE};
    // Rx
    SYS_RXErrors_t pRx1Err, pRx2Err, pRx3Err, pRx4Err;
    // Chirp
    SYS_CAFCErrors_t pChirpErr;
    // MCLK, CC, ISM and OTP
    SYS_MCLKErrors_t pMClkErr;
    SYS_LOIErrors_t pLOIErr;
    SYS_CCErrors_t pCCErr;
    // Ser, SSB, GB and GLDO.
    SYS_SerialiserErrors_t pSerErr;
    SYS_SSBErrors_t pSSBErr;
    SYS_GBIASErrors_t pGBErr;
    SYS_GLDOErrors_t pGLDOErr;
    // ADC
    SYS_ADCErrors_t pADC12Err = {FALSE};
    SYS_ADCErrors_t pADC34Err = {FALSE};
    ISM_ErrCmd_e RegCmd;
    RegCmd = (UnMask == TRUE) ? e_ISM_ERR_OP_UNMASK_ERR : e_ISM_ERR_OP_MASK_ERR;
    // Tx
    pTx1Err.TxRegCRCErr = TRUE;
    pTx1Err.TxPRErr = TRUE;
    pTx1Err.TxRfLevelMaxErr = TRUE;
    pTx1Err.TxRfLevelHighErr = TRUE;
    pTx1Err.TxRfLevelLowErr = TRUE;
    pTx1Err.TxRfLevelMinErr = TRUE;
    pTx1Err.TxTempHighErr = TRUE;
    pTx1Err.TxRFConnectionErr = TRUE;
    pTx1Err.TxSupply1v8LowErr = TRUE;
    pTx1Err.TxSupply1v1LowErr = TRUE;
    pTx2Err = pTx1Err; // Copying same data to all other two structure variables.
    pTx3Err = pTx1Err;
    retVal = HAL_ES2_ISM_MaskRTMSetClrTxErr(RegCmd, &pTx1Err, &pTx2Err, &pTx3Err);
    if (retVal == BC_ERR_NOERROR)
    {
        pRx1Err.RxRegCRCErr = TRUE;
        pRx1Err.RxRFConnectionErr = TRUE;
        pRx1Err.RxSupply1V1LowErr = TRUE;
        pRx1Err.RxSupply1V8LowErr = TRUE;
        pRx1Err.RxLOLevelMaxErr = TRUE;
        pRx1Err.RxLOLevelHighErr = TRUE;
        pRx1Err.RxLOLevelLowErr = TRUE;
        pRx1Err.RxLOLevelMinErr = TRUE;
        pRx2Err = pRx1Err; // Copying same data to all other three structure variables.
        pRx3Err = pRx1Err;
        pRx4Err = pRx1Err;
        retVal = HAL_ES2_ISM_MaskRTMSetClrRxErr(RegCmd, &pRx1Err, &pRx2Err, &pRx3Err, &pRx4Err);
    }

    if (retVal == BC_ERR_NOERROR)
    {
        pChirpErr.CAFCRegCRCErr = TRUE;
        pChirpErr.AAFCCalTimeoutErr = TRUE;
        pChirpErr.AAFCDigitalErr = TRUE;
        pChirpErr.ChirpDigSupply1v1LowErrorErr = TRUE;
        pChirpErr.ChirpVCOSupply1v8vLowErr = TRUE;
        pChirpErr.ChirpPLLSupply1v8vLowErr = TRUE;
        pChirpErr.InterfaceStuckatErr = TRUE;
        pChirpErr.VCOFrequency480Err = TRUE;
        pChirpErr.VCOLevelMaxErr = TRUE;
        pChirpErr.VCOLevelHighErr = TRUE;
        pChirpErr.VCOLevelLowErr = TRUE;
        pChirpErr.VCOLevelMinErr = TRUE;
        pChirpErr.VtuneHighErr = TRUE;
        pChirpErr.VtuneLowErr = TRUE;
        pChirpErr.ChirpTempErr = TRUE;
        pChirpErr.PLLUnlockErr = TRUE;
        pChirpErr.ChirpDigitalLockStepErr = TRUE;
        retVal = HAL_ES2_ISM_MaskRTMSetClrChirpErr(RegCmd, &pChirpErr);
    }
    if (retVal == BC_ERR_NOERROR)
    {
        pMClkErr.MclkRegCRCErr = TRUE;
        pMClkErr.MclkPllCalErr = TRUE;
        pMClkErr.MclkPllLevelErr = TRUE;
        pMClkErr.MclkPllLockErr = TRUE;
        pMClkErr.MclkDigOutPutFreqErr = TRUE;
        pMClkErr.MclkSupply1v8LowErr = TRUE;
        pMClkErr.MclkMSPCErr = TRUE;
        pMClkErr.ClkinError = TRUE;
        pMClkErr.PllClkError = TRUE;
        pMClkErr.MclkXoNoClkErr = TRUE;

        pLOIErr.LOIRegCRC_Err = TRUE;
        pLOIErr.LOILevelMaxErr = TRUE;
        pLOIErr.LOILeveHighErr = TRUE;
        pLOIErr.LOILeveLowErr = TRUE;
        pLOIErr.LOILeveMinErr = TRUE;
        pLOIErr.LOIInConnectionErr = TRUE;
        pLOIErr.LOIOutConnectionErr = TRUE;
        pLOIErr.LOISupply1v1LowErr = TRUE;

        pCCErr.CCRegCRCErr = TRUE;
        pCCErr.SPIRdErr = TRUE;
        pCCErr.SPIWrErr = TRUE;

        retVal = HAL_ES2_ISM_MaskRTMSetClrMCOIErr(RegCmd, TRUE, TRUE, &pMClkErr, &pLOIErr, &pCCErr); //
    }
    if (retVal == BC_ERR_NOERROR)
    {
        pSerErr.SerRegCRCErr = TRUE;
        pSerErr.Supply1v8SerLowErr = TRUE;
        pSerErr.Supply1v1MIPILowErr = TRUE;
        pSerErr.Supply1v1LVDSLowErr = TRUE;

        pSSBErr.SSBRegCRCErr = TRUE;
        pSSBErr.SSBSupply1v8LowErr = TRUE;

        pGBErr.GBIASRegCRCErr = TRUE;
        pGBErr.GBIASSupply1v8LowErr = TRUE;

        pGLDOErr.GlDORegCRCErr = TRUE;
        pGLDOErr.GlDOSupply1v8HighErr = TRUE;
        pGLDOErr.GlDOSupply1v8LowErr = TRUE;
        pGLDOErr.GlDOSupply1v1HighErr = TRUE;
        pGLDOErr.GlDOSupply1v1LowErr = TRUE;

        retVal = HAL_ES2_ISM_MaskRTMSetClrSSGAErr(RegCmd, TRUE, &pSerErr, &pSSBErr, &pGBErr, &pGLDOErr); //
    }
    if (retVal == BC_ERR_NOERROR)
    {
        pADC12Err.ADCRegCrcErr = TRUE;
        pADC12Err.ADCSupply1v8LowErr = TRUE;
        pADC12Err.ADCn1HardClippingErr = TRUE;
        pADC12Err.ADCn0HardClippingErr = TRUE;
        pADC12Err.ADCn1CalErr = TRUE;
        pADC12Err.ADCn0CalErr = TRUE;
        pADC34Err = pADC12Err; // Copying same data to all other one structure variables.
        retVal = HAL_ES2_ISM_MaskRTMSetClrADCErr(RegCmd, &pADC12Err, &pADC34Err);
    }

    return retVal;
}
static void Helper_Msk_ES2_RTMSetClrTx3Err(ISM_ErrCmd_e CmdReg, SYS_TXErrors_t *pTxErr, R2M18_TxErrorMaskRegUnion_t *pTxErrorMask)
{
    uint8_t SetValue;

    SetValue = (CmdReg == e_ISM_ERR_OP_MASK_ERR) ? 1u : 0u;
    if (pTxErr != NULL)
    {
        pTxErrorMask->bits_st.RegCrcErrorFlagTx3Mask = (pTxErr->TxRegCRCErr == TRUE) ? SetValue : pTxErrorMask->bits_st.RegCrcErrorFlagTx3Mask;
        pTxErrorMask->bits_st.PrErrorFlagTx3Mask = (pTxErr->TxPRErr == TRUE) ? SetValue : pTxErrorMask->bits_st.PrErrorFlagTx3Mask;
        pTxErrorMask->bits_st.SupplyLowErrorFlag1V8Tx3Mask = (pTxErr->TxSupply1v8LowErr == TRUE) ? SetValue : pTxErrorMask->bits_st.SupplyLowErrorFlag1V8Tx3Mask;
        pTxErrorMask->bits_st.RfLevelMaxErrorFlagTx3Mask = (pTxErr->TxRfLevelMaxErr == TRUE) ? SetValue : pTxErrorMask->bits_st.RfLevelMaxErrorFlagTx3Mask;
        pTxErrorMask->bits_st.RfLevelHighErrorFlagTx3Mask = (pTxErr->TxRfLevelHighErr == TRUE) ? SetValue : pTxErrorMask->bits_st.RfLevelHighErrorFlagTx3Mask;
        pTxErrorMask->bits_st.RfLevelLowErrorFlagTx3Mask = (pTxErr->TxRfLevelLowErr == TRUE) ? SetValue : pTxErrorMask->bits_st.RfLevelLowErrorFlagTx3Mask;
        pTxErrorMask->bits_st.RfLevelMinErrorFlagTx3Mask = (pTxErr->TxRfLevelMinErr == TRUE) ? SetValue : pTxErrorMask->bits_st.RfLevelMinErrorFlagTx3Mask;
        pTxErrorMask->bits_st.TempErrorFlagTx3Mask = (pTxErr->TxTempHighErr == TRUE) ? SetValue : pTxErrorMask->bits_st.TempErrorFlagTx3Mask;
        pTxErrorMask->bits_st.BbErrorFlagTx3Mask = (pTxErr->TxRFConnectionErr == TRUE) ? SetValue : pTxErrorMask->bits_st.BbErrorFlagTx3Mask;
        pTxErrorMask->bits_st.SupplyLowErrorFlag1V1Tx3Mask = (pTxErr->TxSupply1v1LowErr == TRUE) ? SetValue : pTxErrorMask->bits_st.SupplyLowErrorFlag1V1Tx3Mask;
    }
}

static void Helper_Msk_ES2_RTMSetClrTx2Err(ISM_ErrCmd_e CmdReg, SYS_TXErrors_t *pTxErr, R2M18_TxErrorMaskRegUnion_t *pTxErrorMask)
{
    uint8_t SetValue;

    SetValue = (CmdReg == e_ISM_ERR_OP_MASK_ERR) ? 1u : 0u;
    if (pTxErr != NULL)
    {
        pTxErrorMask->bits_st.RegCrcErrorFlagTx2Mask = (pTxErr->TxRegCRCErr == TRUE) ? SetValue : pTxErrorMask->bits_st.RegCrcErrorFlagTx2Mask;
        pTxErrorMask->bits_st.PrErrorFlagTx2Mask = (pTxErr->TxPRErr == TRUE) ? SetValue : pTxErrorMask->bits_st.PrErrorFlagTx2Mask;
        pTxErrorMask->bits_st.SupplyLowErrorFlag1V8Tx2Mask = (pTxErr->TxSupply1v8LowErr == TRUE) ? SetValue : pTxErrorMask->bits_st.SupplyLowErrorFlag1V8Tx2Mask;
        pTxErrorMask->bits_st.RfLevelMaxErrorFlagTx2Mask = (pTxErr->TxRfLevelMaxErr == TRUE) ? SetValue : pTxErrorMask->bits_st.RfLevelMaxErrorFlagTx2Mask;
        pTxErrorMask->bits_st.RfLevelHighErrorFlagTx2Mask = (pTxErr->TxRfLevelHighErr == TRUE) ? SetValue : pTxErrorMask->bits_st.RfLevelHighErrorFlagTx2Mask;
        pTxErrorMask->bits_st.RfLevelLowErrorFlagTx2Mask = (pTxErr->TxRfLevelLowErr == TRUE) ? SetValue : pTxErrorMask->bits_st.RfLevelLowErrorFlagTx2Mask;
        pTxErrorMask->bits_st.RfLevelMinErrorFlagTx2Mask = (pTxErr->TxRfLevelMinErr == TRUE) ? SetValue : pTxErrorMask->bits_st.RfLevelMinErrorFlagTx2Mask;
        pTxErrorMask->bits_st.TempErrorFlagTx2Mask = (pTxErr->TxTempHighErr == TRUE) ? SetValue : pTxErrorMask->bits_st.TempErrorFlagTx2Mask;
        pTxErrorMask->bits_st.BbErrorFlagTx2Mask = (pTxErr->TxRFConnectionErr == TRUE) ? SetValue : pTxErrorMask->bits_st.BbErrorFlagTx2Mask;
        pTxErrorMask->bits_st.SupplyLowErrorFlag1V1Tx2Mask = (pTxErr->TxSupply1v1LowErr == TRUE) ? SetValue : pTxErrorMask->bits_st.SupplyLowErrorFlag1V1Tx2Mask;
    }
}

static void Helper_Msk_ES2_RTMSetClrTx1Err(ISM_ErrCmd_e CmdReg, SYS_TXErrors_t *pTxErr, R2M18_TxErrorMaskRegUnion_t *pTxErrorMask)
{
    uint8_t SetValue;
    SetValue = (CmdReg == e_ISM_ERR_OP_MASK_ERR) ? 1u : 0u;
    if (pTxErr != NULL)
    {
        pTxErrorMask->bits_st.RegCrcErrorFlagTx1Mask = (pTxErr->TxRegCRCErr == TRUE) ? SetValue : pTxErrorMask->bits_st.RegCrcErrorFlagTx1Mask;
        pTxErrorMask->bits_st.PrErrorFlagTx1Mask = (pTxErr->TxPRErr == TRUE) ? SetValue : pTxErrorMask->bits_st.PrErrorFlagTx1Mask;
        pTxErrorMask->bits_st.SupplyLowErrorFlag1V8Tx1Mask = (pTxErr->TxSupply1v8LowErr == TRUE) ? SetValue : pTxErrorMask->bits_st.SupplyLowErrorFlag1V8Tx1Mask;
        pTxErrorMask->bits_st.RfLevelMaxErrorFlagTx1Mask = (pTxErr->TxRfLevelMaxErr == TRUE) ? SetValue : pTxErrorMask->bits_st.RfLevelMaxErrorFlagTx1Mask;
        pTxErrorMask->bits_st.RfLevelHighErrorFlagTx1Mask = (pTxErr->TxRfLevelHighErr == TRUE) ? SetValue : pTxErrorMask->bits_st.RfLevelHighErrorFlagTx1Mask;
        pTxErrorMask->bits_st.RfLevelLowErrorFlagTx1Mask = (pTxErr->TxRfLevelLowErr == TRUE) ? SetValue : pTxErrorMask->bits_st.RfLevelLowErrorFlagTx1Mask;
        pTxErrorMask->bits_st.RfLevelMinErrorFlagTx1Mask = (pTxErr->TxRfLevelMinErr == TRUE) ? SetValue : pTxErrorMask->bits_st.RfLevelMinErrorFlagTx1Mask;
        pTxErrorMask->bits_st.TempErrorFlagTx1Mask = (pTxErr->TxTempHighErr == TRUE) ? SetValue : pTxErrorMask->bits_st.TempErrorFlagTx1Mask;
        pTxErrorMask->bits_st.BbErrorFlagTx1Mask = (pTxErr->TxRFConnectionErr == TRUE) ? SetValue : pTxErrorMask->bits_st.BbErrorFlagTx1Mask;
        pTxErrorMask->bits_st.SupplyLowErrorFlag1V1Tx1Mask = (pTxErr->TxSupply1v1LowErr == TRUE) ? SetValue : pTxErrorMask->bits_st.SupplyLowErrorFlag1V1Tx1Mask;
    }
}
static BC_ERRCODE Helper_Mon_ES2_RTMSetClrTxErr(SYS_TXErrors_t *pTx1Err, SYS_TXErrors_t *pTx2Err, SYS_TXErrors_t *pTx3Err)
{
    BC_ERRCODE retVal;
    SYS_IPList_t AppConfig = {FALSE};

    retVal = Helper_RTMSetTxErr(pTx1Err, pTx2Err, pTx3Err);

    if (retVal == BC_ERR_NOERROR)
    {
        retVal = BC_CC_GetAppConfiguration(&AppConfig, NULL);
    }

    if ((TRUE == AppConfig.TX3) && (retVal == BC_ERR_NOERROR))
    {
        retVal = Helper_RTMResetTxErr(e_SYS_TX3, pTx3Err);
    }
    if ((TRUE == AppConfig.TX2) && (retVal == BC_ERR_NOERROR))
    {
        retVal = Helper_RTMResetTxErr(e_SYS_TX2, pTx2Err);
    }
    if ((TRUE == AppConfig.TX1) && (retVal == BC_ERR_NOERROR))
    {
        retVal = Helper_RTMResetTxErr(e_SYS_TX1, pTx1Err);
    }
    return retVal;
}
static BC_ERRCODE Helper_Clr_ES2_RTMSetClrTxErr(SYS_TXErrors_t *pTx1Err, SYS_TXErrors_t *pTx2Err, SYS_TXErrors_t *pTx3Err)
{
    BC_ERRCODE retVal;
    R2M18_TxErrorClrRegUnion_t TxErrorClr;

    TxErrorClr.val_u32 = 0x0; // These are auto clear registers so no need of Read and Write check

    if (pTx3Err != NULL)
    {
        TxErrorClr.bits_st.RegCrcErrorFlagTx3Clr = (uint8_t)pTx3Err->TxRegCRCErr;
        TxErrorClr.bits_st.PrErrorFlagTx3Clr = (uint8_t)pTx3Err->TxPRErr;
        TxErrorClr.bits_st.SupplyLowErrorFlag1V8Tx3Clr = (uint8_t)pTx3Err->TxSupply1v8LowErr;
        TxErrorClr.bits_st.RfLevelMaxErrorFlagTx3Clr = (uint8_t)pTx3Err->TxRfLevelMaxErr;
        TxErrorClr.bits_st.RfLevelHighErrorFlagTx3Clr = (uint8_t)pTx3Err->TxRfLevelHighErr;
        TxErrorClr.bits_st.RfLevelLowErrorFlagTx3Clr = (uint8_t)pTx3Err->TxRfLevelLowErr;
        TxErrorClr.bits_st.RfLevelMinErrorFlagTx3Clr = (uint8_t)pTx3Err->TxRfLevelMinErr;
        TxErrorClr.bits_st.TempErrorFlagTx3Clr = (uint8_t)pTx3Err->TxTempHighErr;
        TxErrorClr.bits_st.BbErrorFlagTx3Clr = (uint8_t)pTx3Err->TxRFConnectionErr;
        TxErrorClr.bits_st.SupplyLowErrorFlag1V1Tx3Clr = (uint8_t)pTx3Err->TxSupply1v1LowErr;
    }
    if (pTx2Err != NULL)
    {
        TxErrorClr.bits_st.RegCrcErrorFlagTx2Clr = (uint8_t)pTx2Err->TxRegCRCErr;
        TxErrorClr.bits_st.PrErrorFlagTx2Clr = (uint8_t)pTx2Err->TxPRErr;
        TxErrorClr.bits_st.SupplyLowErrorFlag1V8Tx2Clr = (uint8_t)pTx2Err->TxSupply1v8LowErr;
        TxErrorClr.bits_st.RfLevelMaxErrorFlagTx2Clr = (uint8_t)pTx2Err->TxRfLevelMaxErr;
        TxErrorClr.bits_st.RfLevelHighErrorFlagTx2Clr = (uint8_t)pTx2Err->TxRfLevelHighErr;
        TxErrorClr.bits_st.RfLevelLowErrorFlagTx2Clr = (uint8_t)pTx2Err->TxRfLevelLowErr;
        TxErrorClr.bits_st.RfLevelMinErrorFlagTx2Clr = (uint8_t)pTx2Err->TxRfLevelMinErr;
        TxErrorClr.bits_st.TempErrorFlagTx2Clr = (uint8_t)pTx2Err->TxTempHighErr;
        TxErrorClr.bits_st.BbErrorFlagTx2Clr = (uint8_t)pTx2Err->TxRFConnectionErr;
        TxErrorClr.bits_st.SupplyLowErrorFlag1V1Tx2Clr = (uint8_t)pTx2Err->TxSupply1v1LowErr;
    }
    if (pTx1Err != NULL)
    {
        TxErrorClr.bits_st.RegCrcErrorFlagTx1Clr = (uint8_t)pTx1Err->TxRegCRCErr;
        TxErrorClr.bits_st.PrErrorFlagTx1Clr = (uint8_t)pTx1Err->TxPRErr;
        TxErrorClr.bits_st.SupplyLowErrorFlag1V8Tx1Clr = (uint8_t)pTx1Err->TxSupply1v8LowErr;
        TxErrorClr.bits_st.RfLevelMaxErrorFlagTx1Clr = (uint8_t)pTx1Err->TxRfLevelMaxErr;
        TxErrorClr.bits_st.RfLevelHighErrorFlagTx1Clr = (uint8_t)pTx1Err->TxRfLevelHighErr;
        TxErrorClr.bits_st.RfLevelLowErrorFlagTx1Clr = (uint8_t)pTx1Err->TxRfLevelLowErr;
        TxErrorClr.bits_st.RfLevelMinErrorFlagTx1Clr = (uint8_t)pTx1Err->TxRfLevelMinErr;
        TxErrorClr.bits_st.TempErrorFlagTx1Clr = (uint8_t)pTx1Err->TxTempHighErr;
        TxErrorClr.bits_st.BbErrorFlagTx1Clr = (uint8_t)pTx1Err->TxRFConnectionErr;
        TxErrorClr.bits_st.SupplyLowErrorFlag1V1Tx1Clr = (uint8_t)pTx1Err->TxSupply1v1LowErr;
    }
    retVal = BC_SPI_Write(e_SYS_ISM, R2M18_TX_ERROR_CLR_REG_U16, TxErrorClr.val_u32);
    return retVal;
}
static BC_ERRCODE Helper_Set_ES2_RTMSetClrTxErr(SYS_TXErrors_t *pTx1Err, SYS_TXErrors_t *pTx2Err, SYS_TXErrors_t *pTx3Err)
{
    BC_ERRCODE retVal;
    R2M18_TxErrorSetRegUnion_t TxErrorSet;
    TxErrorSet.val_u32 = 0x0;

    if (pTx3Err != NULL)
    {
        TxErrorSet.bits_st.RegCrcErrorFlagTx3Set = (uint8_t)pTx3Err->TxRegCRCErr;
        TxErrorSet.bits_st.PrErrorFlagTx3Set = (uint8_t)pTx3Err->TxPRErr;
        TxErrorSet.bits_st.SupplyLowErrorFlag1V8Tx3Set = (uint8_t)pTx3Err->TxSupply1v8LowErr;
        TxErrorSet.bits_st.RfLevelMaxErrorFlagTx3Set = (uint8_t)pTx3Err->TxRfLevelMaxErr;
        TxErrorSet.bits_st.RfLevelHighErrorFlagTx3Set = (uint8_t)pTx3Err->TxRfLevelHighErr;
        TxErrorSet.bits_st.RfLevelLowErrorFlagTx3Set = (uint8_t)pTx3Err->TxRfLevelLowErr;
        TxErrorSet.bits_st.RfLevelMinErrorFlagTx3Set = (uint8_t)pTx3Err->TxRfLevelMinErr;
        TxErrorSet.bits_st.TempErrorFlagTx3Set = (uint8_t)pTx3Err->TxTempHighErr;
        TxErrorSet.bits_st.BbErrorFlagTx3Set = (uint8_t)pTx3Err->TxRFConnectionErr;
        TxErrorSet.bits_st.SupplyLowErrorFlag1V1Tx3Set = (uint8_t)pTx3Err->TxSupply1v1LowErr;
    }
    if (pTx2Err != NULL)
    {
        TxErrorSet.bits_st.RegCrcErrorFlagTx2Set = (uint8_t)pTx2Err->TxRegCRCErr;
        TxErrorSet.bits_st.PrErrorFlagTx2Set = (uint8_t)pTx2Err->TxPRErr;
        TxErrorSet.bits_st.SupplyLowErrorFlag1V8Tx2Set = (uint8_t)pTx2Err->TxSupply1v8LowErr;
        TxErrorSet.bits_st.RfLevelMaxErrorFlagTx2Set = (uint8_t)pTx2Err->TxRfLevelMaxErr;
        TxErrorSet.bits_st.RfLevelHighErrorFlagTx2Set = (uint8_t)pTx2Err->TxRfLevelHighErr;
        TxErrorSet.bits_st.RfLevelLowErrorFlagTx2Set = (uint8_t)pTx2Err->TxRfLevelLowErr;
        TxErrorSet.bits_st.RfLevelMinErrorFlagTx2Set = (uint8_t)pTx2Err->TxRfLevelMinErr;
        TxErrorSet.bits_st.TempErrorFlagTx2Set = (uint8_t)pTx2Err->TxTempHighErr;
        TxErrorSet.bits_st.BbErrorFlagTx2Set = (uint8_t)pTx2Err->TxRFConnectionErr;
        TxErrorSet.bits_st.SupplyLowErrorFlag1V1Tx2Set = (uint8_t)pTx2Err->TxSupply1v1LowErr;
    }
    if (pTx1Err != NULL)
    {
        TxErrorSet.bits_st.RegCrcErrorFlagTx1Set = (uint8_t)pTx1Err->TxRegCRCErr;
        TxErrorSet.bits_st.PrErrorFlagTx1Set = (uint8_t)pTx1Err->TxPRErr;
        TxErrorSet.bits_st.SupplyLowErrorFlag1V8Tx1Set = (uint8_t)pTx1Err->TxSupply1v8LowErr;
        TxErrorSet.bits_st.RfLevelMaxErrorFlagTx1Set = (uint8_t)pTx1Err->TxRfLevelMaxErr;
        TxErrorSet.bits_st.RfLevelHighErrorFlagTx1Set = (uint8_t)pTx1Err->TxRfLevelHighErr;
        TxErrorSet.bits_st.RfLevelLowErrorFlagTx1Set = (uint8_t)pTx1Err->TxRfLevelLowErr;
        TxErrorSet.bits_st.RfLevelMinErrorFlagTx1Set = (uint8_t)pTx1Err->TxRfLevelMinErr;
        TxErrorSet.bits_st.TempErrorFlagTx1Set = (uint8_t)pTx1Err->TxTempHighErr;
        TxErrorSet.bits_st.BbErrorFlagTx1Set = (uint8_t)pTx1Err->TxRFConnectionErr;
        TxErrorSet.bits_st.SupplyLowErrorFlag1V1Tx1Set = (uint8_t)pTx1Err->TxSupply1v1LowErr;
    }
    retVal = BC_SPI_Write(e_SYS_ISM, R2M18_TX_ERROR_SET_REG_U16, TxErrorSet.val_u32);
    return retVal;
}
// This API configs all functional safety errors for all Tx module.
BC_ERRCODE HAL_ES2_ISM_MaskRTMSetClrTxErr(ISM_ErrCmd_e CmdReg, SYS_TXErrors_t *pTx1Err, SYS_TXErrors_t *pTx2Err, SYS_TXErrors_t *pTx3Err)
{
    BC_ERRCODE retVal;
    R2M18_TxErrorMaskRegUnion_t TxErrorMask;

    if ((pTx1Err == NULL) && (pTx2Err == NULL) && (pTx3Err == NULL))
    {
        retVal = BC_ERR_ISM_PTR_ADDR_NULL;
    }
    else
    {
        retVal = BC_ERR_NOERROR;
    }
    switch (CmdReg)
    {
    case e_ISM_ERR_OP_MASK_ERR:
    case e_ISM_ERR_OP_UNMASK_ERR:
        // Tx Mask Error
        if (retVal == BC_ERR_NOERROR)
        {
            retVal = BC_SPI_Read(e_SYS_ISM, R2M18_TX_ERROR_MASK_REG_U16, &TxErrorMask.val_u32);
            if (retVal == BC_ERR_NOERROR)
            {
                Helper_Msk_ES2_RTMSetClrTx1Err(CmdReg, pTx1Err, &TxErrorMask);
                Helper_Msk_ES2_RTMSetClrTx2Err(CmdReg, pTx2Err, &TxErrorMask);
                Helper_Msk_ES2_RTMSetClrTx3Err(CmdReg, pTx3Err, &TxErrorMask);
                retVal = BC_SPI_WriteCheck(e_SYS_ISM, R2M18_TX_ERROR_MASK_REG_U16, TxErrorMask.val_u32);
            }
        }
        break;
    case e_ISM_ERR_OP_MONITOR_ERR:
        // monitor error
        if (retVal == BC_ERR_NOERROR)
        {
            retVal = Helper_Mon_ES2_RTMSetClrTxErr(pTx1Err, pTx2Err, pTx3Err);
        }
        break;
    case e_ISM_ERR_OP_CLEAR_ERR:
        // Tx Error Clear
        if (retVal == BC_ERR_NOERROR)
        {
            retVal = Helper_Clr_ES2_RTMSetClrTxErr(pTx1Err, pTx2Err, pTx3Err);
        }
        break;
    case e_ISM_ERR_OP_SET_ERR:
        // Tx Set Error(These are auto clear registers so no need of  Read and Write check)
        if (retVal == BC_ERR_NOERROR)
        {
            retVal = Helper_Set_ES2_RTMSetClrTxErr(pTx1Err, pTx2Err, pTx3Err);
        }
        break;
    default:
        retVal = BC_ERR_INPUTOUTOFRANGE;
        break;
    }
    return retVal;
}
static void Helper_Msk_ES2_RTMSetClrRx4Err(ISM_ErrCmd_e CmdReg, SYS_RXErrors_t *pRxErr, R2M18_RxErrorMaskRegUnion_t *pRxErrorMask)
{
    uint8_t SetValue = 0u;

    SetValue = (CmdReg == e_ISM_ERR_OP_MASK_ERR) ? 1u : 0u;
    if (pRxErr != NULL)
    {
        pRxErrorMask->bits_st.RegCrcErrorFlagRx4Mask = (pRxErr->RxRegCRCErr == TRUE) ? SetValue : pRxErrorMask->bits_st.RegCrcErrorFlagRx4Mask;
        pRxErrorMask->bits_st.SupplyLowErrorFlag1V8Rx4Mask = (pRxErr->RxSupply1V8LowErr == TRUE) ? SetValue : pRxErrorMask->bits_st.SupplyLowErrorFlag1V8Rx4Mask;
        pRxErrorMask->bits_st.SupplyLowErrorFlag1V1Rx4Mask = (pRxErr->RxSupply1V1LowErr == TRUE) ? SetValue : pRxErrorMask->bits_st.SupplyLowErrorFlag1V1Rx4Mask;
        pRxErrorMask->bits_st.LoLevelMaxErrorFlagRx4Mask = (pRxErr->RxLOLevelMaxErr == TRUE) ? SetValue : pRxErrorMask->bits_st.LoLevelMaxErrorFlagRx4Mask;
        pRxErrorMask->bits_st.LoLevelHighErrorFlagRx4Mask = (pRxErr->RxLOLevelHighErr == TRUE) ? SetValue : pRxErrorMask->bits_st.LoLevelHighErrorFlagRx4Mask;
        pRxErrorMask->bits_st.LoLevelLowErrorFlagRx4Mask = (pRxErr->RxLOLevelLowErr == TRUE) ? SetValue : pRxErrorMask->bits_st.LoLevelLowErrorFlagRx4Mask;
        pRxErrorMask->bits_st.LoLevelMinErrorFlagRx4Mask = (pRxErr->RxLOLevelMinErr == TRUE) ? SetValue : pRxErrorMask->bits_st.LoLevelMinErrorFlagRx4Mask;
        pRxErrorMask->bits_st.BbErrorFlagRx4Mask = (pRxErr->RxRFConnectionErr == TRUE) ? SetValue : pRxErrorMask->bits_st.BbErrorFlagRx4Mask;
    }
}
static void Helper_Msk_ES2_RTMSetClrRx3Err(ISM_ErrCmd_e CmdReg, SYS_RXErrors_t *pRxErr, R2M18_RxErrorMaskRegUnion_t *pRxErrorMask)
{
    uint8_t SetValue = 0u;

    SetValue = (CmdReg == e_ISM_ERR_OP_MASK_ERR) ? 1u : 0u;
    if (pRxErr != NULL)
    {
        pRxErrorMask->bits_st.RegCrcErrorFlagRx3Mask = (pRxErr->RxRegCRCErr == TRUE) ? SetValue : pRxErrorMask->bits_st.RegCrcErrorFlagRx3Mask;
        pRxErrorMask->bits_st.SupplyLowErrorFlag1V8Rx3Mask = (pRxErr->RxSupply1V8LowErr == TRUE) ? SetValue : pRxErrorMask->bits_st.SupplyLowErrorFlag1V8Rx3Mask;
        pRxErrorMask->bits_st.SupplyLowErrorFlag1V1Rx3Mask = (pRxErr->RxSupply1V1LowErr == TRUE) ? SetValue : pRxErrorMask->bits_st.SupplyLowErrorFlag1V1Rx3Mask;
        pRxErrorMask->bits_st.LoLevelMaxErrorFlagRx3Mask = (pRxErr->RxLOLevelMaxErr == TRUE) ? SetValue : pRxErrorMask->bits_st.LoLevelMaxErrorFlagRx3Mask;
        pRxErrorMask->bits_st.LoLevelHighErrorFlagRx3Mask = (pRxErr->RxLOLevelHighErr == TRUE) ? SetValue : pRxErrorMask->bits_st.LoLevelHighErrorFlagRx3Mask;
        pRxErrorMask->bits_st.LoLevelLowErrorFlagRx3Mask = (pRxErr->RxLOLevelLowErr == TRUE) ? SetValue : pRxErrorMask->bits_st.LoLevelLowErrorFlagRx3Mask;
        pRxErrorMask->bits_st.LoLevelMinErrorFlagRx3Mask = (pRxErr->RxLOLevelMinErr == TRUE) ? SetValue : pRxErrorMask->bits_st.LoLevelMinErrorFlagRx3Mask;
        pRxErrorMask->bits_st.BbErrorFlagRx3Mask = (pRxErr->RxRFConnectionErr == TRUE) ? SetValue : pRxErrorMask->bits_st.BbErrorFlagRx3Mask;
    }
}
static void Helper_Msk_ES2_RTMSetClrRx2Err(ISM_ErrCmd_e CmdReg, SYS_RXErrors_t *pRxErr, R2M18_RxErrorMaskRegUnion_t *pRxErrorMask)
{
    uint8_t SetValue = 0u;

    SetValue = (CmdReg == e_ISM_ERR_OP_MASK_ERR) ? 1u : 0u;
    if (pRxErr != NULL)
    {
        pRxErrorMask->bits_st.RegCrcErrorFlagRx2Mask = (pRxErr->RxRegCRCErr == TRUE) ? SetValue : pRxErrorMask->bits_st.RegCrcErrorFlagRx2Mask;
        pRxErrorMask->bits_st.SupplyLowErrorFlag1V8Rx2Mask = (pRxErr->RxSupply1V8LowErr == TRUE) ? SetValue : pRxErrorMask->bits_st.SupplyLowErrorFlag1V8Rx2Mask;
        pRxErrorMask->bits_st.SupplyLowErrorFlag1V1Rx2Mask = (pRxErr->RxSupply1V1LowErr == TRUE) ? SetValue : pRxErrorMask->bits_st.SupplyLowErrorFlag1V1Rx2Mask;
        pRxErrorMask->bits_st.LoLevelMaxErrorFlagRx2Mask = (pRxErr->RxLOLevelMaxErr == TRUE) ? SetValue : pRxErrorMask->bits_st.LoLevelMaxErrorFlagRx2Mask;
        pRxErrorMask->bits_st.LoLevelHighErrorFlagRx2Mask = (pRxErr->RxLOLevelHighErr == TRUE) ? SetValue : pRxErrorMask->bits_st.LoLevelHighErrorFlagRx2Mask;
        pRxErrorMask->bits_st.LoLevelLowErrorFlagRx2Mask = (pRxErr->RxLOLevelLowErr == TRUE) ? SetValue : pRxErrorMask->bits_st.LoLevelLowErrorFlagRx2Mask;
        pRxErrorMask->bits_st.LoLevelMinErrorFlagRx2Mask = (pRxErr->RxLOLevelMinErr == TRUE) ? SetValue : pRxErrorMask->bits_st.LoLevelMinErrorFlagRx2Mask;
        pRxErrorMask->bits_st.BbErrorFlagRx2Mask = (pRxErr->RxRFConnectionErr == TRUE) ? SetValue : pRxErrorMask->bits_st.BbErrorFlagRx2Mask;
    }
}
static void Helper_Msk_ES2_RTMSetClrRx1Err(ISM_ErrCmd_e CmdReg, SYS_RXErrors_t *pRxErr, R2M18_RxErrorMaskRegUnion_t *pRxErrorMask)
{
    uint8_t SetValue = 0u;

    SetValue = (CmdReg == e_ISM_ERR_OP_MASK_ERR) ? 1u : 0u;
    if (pRxErr != NULL)
    {
        pRxErrorMask->bits_st.RegCrcErrorFlagRx1Mask = (pRxErr->RxRegCRCErr == TRUE) ? SetValue : pRxErrorMask->bits_st.RegCrcErrorFlagRx1Mask;
        pRxErrorMask->bits_st.SupplyLowErrorFlag1V8Rx1Mask = (pRxErr->RxSupply1V8LowErr == TRUE) ? SetValue : pRxErrorMask->bits_st.SupplyLowErrorFlag1V8Rx1Mask;
        pRxErrorMask->bits_st.SupplyLowErrorFlag1V1Rx1Mask = (pRxErr->RxSupply1V1LowErr == TRUE) ? SetValue : pRxErrorMask->bits_st.SupplyLowErrorFlag1V1Rx1Mask;
        pRxErrorMask->bits_st.LoLevelMaxErrorFlagRx1Mask = (pRxErr->RxLOLevelMaxErr == TRUE) ? SetValue : pRxErrorMask->bits_st.LoLevelMaxErrorFlagRx1Mask;
        pRxErrorMask->bits_st.LoLevelHighErrorFlagRx1Mask = (pRxErr->RxLOLevelHighErr == TRUE) ? SetValue : pRxErrorMask->bits_st.LoLevelHighErrorFlagRx1Mask;
        pRxErrorMask->bits_st.LoLevelLowErrorFlagRx1Mask = (pRxErr->RxLOLevelLowErr == TRUE) ? SetValue : pRxErrorMask->bits_st.LoLevelLowErrorFlagRx1Mask;
        pRxErrorMask->bits_st.LoLevelMinErrorFlagRx1Mask = (pRxErr->RxLOLevelMinErr == TRUE) ? SetValue : pRxErrorMask->bits_st.LoLevelMinErrorFlagRx1Mask;
        pRxErrorMask->bits_st.BbErrorFlagRx1Mask = (pRxErr->RxRFConnectionErr == TRUE) ? SetValue : pRxErrorMask->bits_st.BbErrorFlagRx1Mask;
    }
}
static BC_ERRCODE Helper_Mon_ES2_RTMSetClrRxErr(SYS_RXErrors_t *pRx1Err, SYS_RXErrors_t *pRx2Err, SYS_RXErrors_t *pRx3Err, SYS_RXErrors_t *pRx4Err)
{
    BC_ERRCODE retVal;
    SYS_IPList_t AppConfig = {FALSE};

    retVal = Helper_RTMSetRxErr(pRx1Err, pRx2Err, pRx3Err, pRx4Err);

    if (retVal == BC_ERR_NOERROR)
    {
        retVal = BC_CC_GetAppConfiguration(&AppConfig, NULL);
    }
    if ((TRUE == AppConfig.RX4) && (retVal == BC_ERR_NOERROR))
    {
        retVal = Helper_RTMResetRxErr(e_SYS_RX4, pRx4Err);
    }
    if ((TRUE == AppConfig.RX3) && (retVal == BC_ERR_NOERROR))
    {
        retVal = Helper_RTMResetRxErr(e_SYS_RX3, pRx3Err);
    }
    if ((TRUE == AppConfig.RX2) && (retVal == BC_ERR_NOERROR))
    {
        retVal = Helper_RTMResetRxErr(e_SYS_RX2, pRx2Err);
    }
    if ((TRUE == AppConfig.RX1) && (retVal == BC_ERR_NOERROR))
    {
        retVal = Helper_RTMResetRxErr(e_SYS_RX1, pRx1Err);
    }
    return retVal;
}

static BC_ERRCODE Helper_Clr_ES2_RTMSetClrRxErr(SYS_RXErrors_t *pRx1Err, SYS_RXErrors_t *pRx2Err, SYS_RXErrors_t *pRx3Err, SYS_RXErrors_t *pRx4Err)
{
    BC_ERRCODE retVal;
    R2M18_RxErrorClrRegUnion_t RxErrorClr;
    RxErrorClr.val_u32 = 0x0;
    if (pRx4Err != NULL)
    {
        RxErrorClr.bits_st.RegCrcErrorFlagRx4Clr = (uint8_t)pRx4Err->RxRegCRCErr;
        RxErrorClr.bits_st.SupplyLowErrorFlag1V8Rx4Clr = (uint8_t)pRx4Err->RxSupply1V8LowErr;
        RxErrorClr.bits_st.SupplyLowErrorFlag1V1Rx4Clr = (uint8_t)pRx4Err->RxSupply1V1LowErr;
        RxErrorClr.bits_st.LoLevelMaxErrorFlagRx4Clr = (uint8_t)pRx4Err->RxLOLevelMaxErr;
        RxErrorClr.bits_st.LoLevelHighErrorFlagRx4Clr = (uint8_t)pRx4Err->RxLOLevelHighErr;
        RxErrorClr.bits_st.LoLevelLowErrorFlagRx4Clr = (uint8_t)pRx4Err->RxLOLevelLowErr;
        RxErrorClr.bits_st.LoLevelMinErrorFlagRx4Clr = (uint8_t)pRx4Err->RxLOLevelMinErr;
        RxErrorClr.bits_st.BbErrorFlagRx4Clr = (uint8_t)pRx4Err->RxRFConnectionErr;
    }
    if (pRx3Err != NULL)
    {
        RxErrorClr.bits_st.RegCrcErrorFlagRx3Clr = (uint8_t)pRx3Err->RxRegCRCErr;
        RxErrorClr.bits_st.SupplyLowErrorFlag1V8Rx3Clr = (uint8_t)pRx3Err->RxSupply1V8LowErr;
        RxErrorClr.bits_st.SupplyLowErrorFlag1V1Rx3Clr = (uint8_t)pRx3Err->RxSupply1V1LowErr;
        RxErrorClr.bits_st.LoLevelMaxErrorFlagRx3Clr = (uint8_t)pRx3Err->RxLOLevelMaxErr;
        RxErrorClr.bits_st.LoLevelHighErrorFlagRx3Clr = (uint8_t)pRx3Err->RxLOLevelHighErr;
        RxErrorClr.bits_st.LoLevelLowErrorFlagRx3Clr = (uint8_t)pRx3Err->RxLOLevelLowErr;
        RxErrorClr.bits_st.LoLevelMinErrorFlagRx3Clr = (uint8_t)pRx3Err->RxLOLevelMinErr;
        RxErrorClr.bits_st.BbErrorFlagRx3Clr = (uint8_t)pRx3Err->RxRFConnectionErr;
    }
    if (pRx2Err != NULL)
    {
        RxErrorClr.bits_st.RegCrcErrorFlagRx2Clr = (uint8_t)pRx2Err->RxRegCRCErr;
        RxErrorClr.bits_st.SupplyLowErrorFlag1V8Rx2Clr = (uint8_t)pRx2Err->RxSupply1V8LowErr;
        RxErrorClr.bits_st.SupplyLowErrorFlag1V1Rx2Clr = (uint8_t)pRx2Err->RxSupply1V1LowErr;
        RxErrorClr.bits_st.LoLevelMaxErrorFlagRx2Clr = (uint8_t)pRx2Err->RxLOLevelMaxErr;
        RxErrorClr.bits_st.LoLevelHighErrorFlagRx2Clr = (uint8_t)pRx2Err->RxLOLevelHighErr;
        RxErrorClr.bits_st.LoLevelLowErrorFlagRx2Clr = (uint8_t)pRx2Err->RxLOLevelLowErr;
        RxErrorClr.bits_st.LoLevelMinErrorFlagRx2Clr = (uint8_t)pRx2Err->RxLOLevelMinErr;
        RxErrorClr.bits_st.BbErrorFlagRx2Clr = (uint8_t)pRx2Err->RxRFConnectionErr;
    }
    if (pRx1Err != NULL)
    {
        RxErrorClr.bits_st.RegCrcErrorFlagRx1Clr = (uint8_t)pRx1Err->RxRegCRCErr;
        RxErrorClr.bits_st.SupplyLowErrorFlag1V8Rx1Clr = (uint8_t)pRx1Err->RxSupply1V8LowErr;
        RxErrorClr.bits_st.SupplyLowErrorFlag1V1Rx1Clr = (uint8_t)pRx1Err->RxSupply1V1LowErr;
        RxErrorClr.bits_st.LoLevelMaxErrorFlagRx1Clr = (uint8_t)pRx1Err->RxLOLevelMaxErr;
        RxErrorClr.bits_st.LoLevelHighErrorFlagRx1Clr = (uint8_t)pRx1Err->RxLOLevelHighErr;
        RxErrorClr.bits_st.LoLevelLowErrorFlagRx1Clr = (uint8_t)pRx1Err->RxLOLevelLowErr;
        RxErrorClr.bits_st.LoLevelMinErrorFlagRx1Clr = (uint8_t)pRx1Err->RxLOLevelMinErr;
        RxErrorClr.bits_st.BbErrorFlagRx1Clr = (uint8_t)pRx1Err->RxRFConnectionErr;
    }
    retVal = BC_SPI_Write(e_SYS_ISM, R2M18_RX_ERROR_CLR_REG_U16, RxErrorClr.val_u32);
    return retVal;
}

static BC_ERRCODE Helper_Set_ES2_RTMSetClrRxErr(SYS_RXErrors_t *pRx1Err, SYS_RXErrors_t *pRx2Err, SYS_RXErrors_t *pRx3Err, SYS_RXErrors_t *pRx4Err)
{
    BC_ERRCODE retVal;
    R2M18_RxErrorSetRegUnion_t RxErrorSet;

    // Rx Set Error(These are auto clear registers so no need of  Read and Write check)
    RxErrorSet.val_u32 = 0x0;
    if (pRx4Err != NULL)
    {
        RxErrorSet.bits_st.RegCrcErrorFlagRx4Set = (uint8_t)pRx4Err->RxRegCRCErr;
        RxErrorSet.bits_st.SupplyLowErrorFlag1V8Rx4Set = (uint8_t)pRx4Err->RxSupply1V8LowErr;
        RxErrorSet.bits_st.SupplyLowErrorFlag1V1Rx4Set = (uint8_t)pRx4Err->RxSupply1V1LowErr;
        RxErrorSet.bits_st.LoLevelMaxErrorFlagRx4Set = (uint8_t)pRx4Err->RxLOLevelMaxErr;
        RxErrorSet.bits_st.LoLevelHighErrorFlagRx4Set = (uint8_t)pRx4Err->RxLOLevelHighErr;
        RxErrorSet.bits_st.LoLevelLowErrorFlagRx4Set = (uint8_t)pRx4Err->RxLOLevelLowErr;
        RxErrorSet.bits_st.LoLevelMinErrorFlagRx4Set = (uint8_t)pRx4Err->RxLOLevelMinErr;
        RxErrorSet.bits_st.BbErrorFlagRx4Set = (uint8_t)pRx4Err->RxRFConnectionErr;
    }
    if (pRx3Err != NULL)
    {
        RxErrorSet.bits_st.RegCrcErrorFlagRx3Set = (uint8_t)pRx3Err->RxRegCRCErr;
        RxErrorSet.bits_st.SupplyLowErrorFlag1V8Rx3Set = (uint8_t)pRx3Err->RxSupply1V8LowErr;
        RxErrorSet.bits_st.SupplyLowErrorFlag1V1Rx3Set = (uint8_t)pRx3Err->RxSupply1V1LowErr;
        RxErrorSet.bits_st.LoLevelMaxErrorFlagRx3Set = (uint8_t)pRx3Err->RxLOLevelMaxErr;
        RxErrorSet.bits_st.LoLevelHighErrorFlagRx3Set = (uint8_t)pRx3Err->RxLOLevelHighErr;
        RxErrorSet.bits_st.LoLevelLowErrorFlagRx3Set = (uint8_t)pRx3Err->RxLOLevelLowErr;
        RxErrorSet.bits_st.LoLevelMinErrorFlagRx3Set = (uint8_t)pRx3Err->RxLOLevelMinErr;
        RxErrorSet.bits_st.BbErrorFlagRx3Set = (uint8_t)pRx3Err->RxRFConnectionErr;
    }
    if (pRx2Err != NULL)
    {
        RxErrorSet.bits_st.RegCrcErrorFlagRx2Set = (uint8_t)pRx2Err->RxRegCRCErr;
        RxErrorSet.bits_st.SupplyLowErrorFlag1V8Rx2Set = (uint8_t)pRx2Err->RxSupply1V8LowErr;
        RxErrorSet.bits_st.SupplyLowErrorFlag1V1Rx2Set = (uint8_t)pRx2Err->RxSupply1V1LowErr;
        RxErrorSet.bits_st.LoLevelMaxErrorFlagRx2Set = (uint8_t)pRx2Err->RxLOLevelMaxErr;
        RxErrorSet.bits_st.LoLevelHighErrorFlagRx2Set = (uint8_t)pRx2Err->RxLOLevelHighErr;
        RxErrorSet.bits_st.LoLevelLowErrorFlagRx2Set = (uint8_t)pRx2Err->RxLOLevelLowErr;
        RxErrorSet.bits_st.LoLevelMinErrorFlagRx2Set = (uint8_t)pRx2Err->RxLOLevelMinErr;
        RxErrorSet.bits_st.BbErrorFlagRx2Set = (uint8_t)pRx2Err->RxRFConnectionErr;
    }
    if (pRx1Err != NULL)
    {
        RxErrorSet.bits_st.RegCrcErrorFlagRx1Set = (uint8_t)pRx1Err->RxRegCRCErr;
        RxErrorSet.bits_st.SupplyLowErrorFlag1V8Rx1Set = (uint8_t)pRx1Err->RxSupply1V8LowErr;
        RxErrorSet.bits_st.SupplyLowErrorFlag1V1Rx1Set = (uint8_t)pRx1Err->RxSupply1V1LowErr;
        RxErrorSet.bits_st.LoLevelMaxErrorFlagRx1Set = (uint8_t)pRx1Err->RxLOLevelMaxErr;
        RxErrorSet.bits_st.LoLevelHighErrorFlagRx1Set = (uint8_t)pRx1Err->RxLOLevelHighErr;
        RxErrorSet.bits_st.LoLevelLowErrorFlagRx1Set = (uint8_t)pRx1Err->RxLOLevelLowErr;
        RxErrorSet.bits_st.LoLevelMinErrorFlagRx1Set = (uint8_t)pRx1Err->RxLOLevelMinErr;
        RxErrorSet.bits_st.BbErrorFlagRx1Set = (uint8_t)pRx1Err->RxRFConnectionErr;
    }
    retVal = BC_SPI_Write(e_SYS_ISM, R2M18_RX_ERROR_SET_REG_U16, RxErrorSet.val_u32);
    return retVal;
}
// This API configs all functional safety errors for all Rx module
BC_ERRCODE HAL_ES2_ISM_MaskRTMSetClrRxErr(ISM_ErrCmd_e CmdReg, SYS_RXErrors_t *pRx1Err, SYS_RXErrors_t *pRx2Err, SYS_RXErrors_t *pRx3Err, SYS_RXErrors_t *pRx4Err)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M18_RxErrorMaskRegUnion_t RxErrorMask;

    if ((pRx1Err == NULL) && (pRx2Err == NULL) && (pRx3Err == NULL) && (pRx4Err == NULL))
    {
        retVal = BC_ERR_ISM_PTR_ADDR_NULL;
    }
    if (retVal == BC_ERR_NOERROR)
    {
        switch (CmdReg)
        {
        case e_ISM_ERR_OP_MASK_ERR:
        case e_ISM_ERR_OP_UNMASK_ERR:
            // Rx Mask Error
            retVal = BC_SPI_Read(e_SYS_ISM, R2M18_RX_ERROR_MASK_REG_U16, &RxErrorMask.val_u32);
            if (retVal == BC_ERR_NOERROR)
            {
                Helper_Msk_ES2_RTMSetClrRx1Err(CmdReg, pRx1Err, &RxErrorMask);
                Helper_Msk_ES2_RTMSetClrRx2Err(CmdReg, pRx2Err, &RxErrorMask);
                Helper_Msk_ES2_RTMSetClrRx3Err(CmdReg, pRx3Err, &RxErrorMask);
                Helper_Msk_ES2_RTMSetClrRx4Err(CmdReg, pRx4Err, &RxErrorMask);
                retVal = BC_SPI_WriteCheck(e_SYS_ISM, R2M18_RX_ERROR_MASK_REG_U16, RxErrorMask.val_u32);
            }
            break;
        case e_ISM_ERR_OP_MONITOR_ERR:
            // Rx monitor error
            retVal = Helper_Mon_ES2_RTMSetClrRxErr(pRx1Err, pRx2Err, pRx3Err, pRx4Err);
            break;
        case e_ISM_ERR_OP_CLEAR_ERR:
            // Rx Error Clear(These are auto clear registers so no need of  Read and Write check)
            retVal = Helper_Clr_ES2_RTMSetClrRxErr(pRx1Err, pRx2Err, pRx3Err, pRx4Err);
            break;
        case e_ISM_ERR_OP_SET_ERR:
            retVal = Helper_Set_ES2_RTMSetClrRxErr(pRx1Err, pRx2Err, pRx3Err, pRx4Err);
            break;
        default:
            retVal = BC_ERR_INPUTOUTOFRANGE;
            break;
        }
    }
    return retVal;
}

// This API configs all functional safety errors for Chirp module.
static BC_ERRCODE Helper_Msk_ES2_RTMSetClrChirpErr(ISM_ErrCmd_e CmdReg, SYS_CAFCErrors_t *pChirpErr)
{
    BC_ERRCODE retVal;
    R2M18_ChirpErrorMaskRegUnion_t ChirpErrorMask;
    uint8_t SetValue = 0u;

    retVal = BC_SPI_Read(e_SYS_ISM, R2M18_CHIRP_ERROR_MASK_REG_U16, &ChirpErrorMask.val_u32);
    if (retVal == BC_ERR_NOERROR)
    {
        if (CmdReg == e_ISM_ERR_OP_MASK_ERR)
        {
            SetValue = 1u; // Used for mask register
        }
        else
        {
            SetValue = 0u; // Used for unmask register
        }
        ChirpErrorMask.bits_st.RegCrcErrorFlagChirpMask = (pChirpErr->CAFCRegCRCErr == TRUE) ? SetValue : ChirpErrorMask.bits_st.RegCrcErrorFlagChirpMask;
        ChirpErrorMask.bits_st.AafcCalTimeoutErrorFlagChirpMask = (pChirpErr->AAFCCalTimeoutErr == TRUE) ? SetValue : ChirpErrorMask.bits_st.AafcCalTimeoutErrorFlagChirpMask;
        ChirpErrorMask.bits_st.AafcErrorFlagChirpMask = (pChirpErr->AAFCDigitalErr == TRUE) ? SetValue : ChirpErrorMask.bits_st.AafcErrorFlagChirpMask;
        ChirpErrorMask.bits_st.SupplyLowErrorFlagDig1V1ChirpMask = (pChirpErr->ChirpDigSupply1v1LowErrorErr == TRUE) ? SetValue : ChirpErrorMask.bits_st.SupplyLowErrorFlagDig1V1ChirpMask;
        ChirpErrorMask.bits_st.SupplyLowErrorFlagVco1V8ChirpMask = (pChirpErr->ChirpVCOSupply1v8vLowErr == TRUE) ? SetValue : ChirpErrorMask.bits_st.SupplyLowErrorFlagVco1V8ChirpMask;
        ChirpErrorMask.bits_st.SupplyLowErrorFlagPll1V8ChirpMask = (pChirpErr->ChirpPLLSupply1v8vLowErr == TRUE) ? SetValue : ChirpErrorMask.bits_st.SupplyLowErrorFlagPll1V8ChirpMask;
        ChirpErrorMask.bits_st.InterfaceStuckErrorFlagChirpMask = (pChirpErr->InterfaceStuckatErr == TRUE) ? SetValue : ChirpErrorMask.bits_st.InterfaceStuckErrorFlagChirpMask;
        ChirpErrorMask.bits_st.VcoFreq480ErrorFlagChirpMask = (pChirpErr->VCOFrequency480Err == TRUE) ? SetValue : ChirpErrorMask.bits_st.VcoFreq480ErrorFlagChirpMask;
        ChirpErrorMask.bits_st.LevelMaxErrorFlagChirpMask = (pChirpErr->VCOLevelMaxErr == TRUE) ? SetValue : ChirpErrorMask.bits_st.LevelMaxErrorFlagChirpMask;
        ChirpErrorMask.bits_st.LevelHighErrorFlagChirpMask = (pChirpErr->VCOLevelHighErr == TRUE) ? SetValue : ChirpErrorMask.bits_st.LevelHighErrorFlagChirpMask;
        ChirpErrorMask.bits_st.LevelLowErrorFlagChirpMask = (pChirpErr->VCOLevelLowErr == TRUE) ? SetValue : ChirpErrorMask.bits_st.LevelLowErrorFlagChirpMask;
        ChirpErrorMask.bits_st.LevelMinErrorFlagChirpMask = (pChirpErr->VCOLevelMinErr == TRUE) ? SetValue : ChirpErrorMask.bits_st.LevelMinErrorFlagChirpMask;
        ChirpErrorMask.bits_st.VtuneHighErrorFlagChirpMask = (pChirpErr->VtuneHighErr == TRUE) ? SetValue : ChirpErrorMask.bits_st.VtuneHighErrorFlagChirpMask;
        ChirpErrorMask.bits_st.VtuneLowErrorFlagChirpMask = (pChirpErr->VtuneLowErr == TRUE) ? SetValue : ChirpErrorMask.bits_st.VtuneLowErrorFlagChirpMask;
        ChirpErrorMask.bits_st.TempErrorFlagChirpMask = (pChirpErr->ChirpTempErr == TRUE) ? SetValue : ChirpErrorMask.bits_st.TempErrorFlagChirpMask;
        ChirpErrorMask.bits_st.UnlockErrorFlagChirpMask = (pChirpErr->PLLUnlockErr == TRUE) ? SetValue : ChirpErrorMask.bits_st.UnlockErrorFlagChirpMask;
        ChirpErrorMask.bits_st.LockStepErrorFlagChirpMask = (pChirpErr->ChirpDigitalLockStepErr == TRUE) ? SetValue : ChirpErrorMask.bits_st.LockStepErrorFlagChirpMask;

        retVal = BC_SPI_WriteCheck(e_SYS_ISM, R2M18_CHIRP_ERROR_MASK_REG_U16, ChirpErrorMask.val_u32);
    }
    return retVal;
}

static BC_ERRCODE Helper_Mon_ES2_RTMSetClrChirpErr(SYS_CAFCErrors_t *pChirpErr)
{
    BC_ERRCODE retVal;
    R2M18_ChirpErrorMonRegUnion_t ChirpErrorMon;
    R2M06_MaskCcResetErrorUnion_t CAFCMaskCcResetError;
    SYS_IPList_t AppConfig = {FALSE};

    retVal = BC_SPI_Read(e_SYS_ISM, R2M18_CHIRP_ERROR_MON_REG_U16, &ChirpErrorMon.val_u32);
    if (retVal == BC_ERR_NOERROR)
    {
        /*CRC monitor is enabled always in hardware*/
        ChirpErrorMon.bits_st.AafcCalTimeoutErrorFlagChirpMon = (uint8_t)pChirpErr->AAFCCalTimeoutErr;
        ChirpErrorMon.bits_st.AafcErrorFlagChirpMon = (uint8_t)pChirpErr->AAFCDigitalErr;
        ChirpErrorMon.bits_st.SupplyLowErrorFlagDig1V1ChirpMon = (uint8_t)pChirpErr->ChirpDigSupply1v1LowErrorErr;
        ChirpErrorMon.bits_st.SupplyLowErrorFlagVco1V8ChirpMon = (uint8_t)pChirpErr->ChirpVCOSupply1v8vLowErr;
        ChirpErrorMon.bits_st.SupplyLowErrorFlagPll1V8ChirpMon = (uint8_t)pChirpErr->ChirpPLLSupply1v8vLowErr;
        ChirpErrorMon.bits_st.InterfaceStuckErrorFlagChirpMon = (uint8_t)pChirpErr->InterfaceStuckatErr;
        ChirpErrorMon.bits_st.VcoFreq480ErrorFlagChirpMon = (uint8_t)pChirpErr->VCOFrequency480Err;
        ChirpErrorMon.bits_st.LevelMaxErrorFlagChirpMon = (uint8_t)pChirpErr->VCOLevelMaxErr;
        ChirpErrorMon.bits_st.LevelHighErrorFlagChirpMon = (uint8_t)pChirpErr->VCOLevelHighErr;
        ChirpErrorMon.bits_st.LevelLowErrorFlagChirpMon = (uint8_t)pChirpErr->VCOLevelLowErr;
        ChirpErrorMon.bits_st.LevelMinErrorFlagChirpMon = (uint8_t)pChirpErr->VCOLevelMinErr;
        ChirpErrorMon.bits_st.VtuneHighErrorFlagChirpMon = (uint8_t)pChirpErr->VtuneHighErr;
        ChirpErrorMon.bits_st.VtuneLowErrorFlagChirpMon = (uint8_t)pChirpErr->VtuneLowErr;
        ChirpErrorMon.bits_st.TempErrorFlagChirpMon = (uint8_t)pChirpErr->ChirpTempErr;
        ChirpErrorMon.bits_st.UnlockErrorFlagChirpMon = (uint8_t)pChirpErr->PLLUnlockErr;
        ChirpErrorMon.bits_st.LockStepErrorFlagChirpMon = (uint8_t)pChirpErr->ChirpDigitalLockStepErr;
        retVal = BC_SPI_WriteCheck(e_SYS_ISM, R2M18_CHIRP_ERROR_MON_REG_U16, ChirpErrorMon.val_u32);
    }
    if (retVal == BC_ERR_NOERROR)
    {
        retVal = BC_CC_GetAppConfiguration(&AppConfig, NULL);
    }
    if ((retVal == BC_ERR_NOERROR) && (TRUE == AppConfig.CAFC))
    {
        retVal = BC_SPI_Read(e_SYS_CAFC, R2M06_MASK_CC_RESET_ERROR_U16, &CAFCMaskCcResetError.val_u32);
        if (retVal == BC_ERR_NOERROR)
        {
            CAFCMaskCcResetError.bits_st.MaskSupplyDigResetError = (uint8_t)pChirpErr->ChirpDigSupply1v1LowErrorErr;
            CAFCMaskCcResetError.bits_st.MaskAfcStuckatTransientResetError = (uint8_t)pChirpErr->ChirpDigitalLockStepErr;
            CAFCMaskCcResetError.bits_st.MaskScStuckatTransientResetError = (uint8_t)pChirpErr->ChirpDigitalLockStepErr;
            CAFCMaskCcResetError.bits_st.MaskTeStuckatTransientResetError = (uint8_t)pChirpErr->ChirpDigitalLockStepErr;
            CAFCMaskCcResetError.bits_st.MaskCombinedStuckatTransientResetError = (uint8_t)pChirpErr->ChirpDigitalLockStepErr;
            CAFCMaskCcResetError.bits_st.MaskAfcRegCrcResetError = (uint8_t)pChirpErr->CAFCRegCRCErr;
            CAFCMaskCcResetError.bits_st.MaskScRegCrcResetError = (uint8_t)pChirpErr->CAFCRegCRCErr;
            CAFCMaskCcResetError.bits_st.MaskTeRegCrcResetError = (uint8_t)pChirpErr->CAFCRegCRCErr;
            CAFCMaskCcResetError.bits_st.MaskMaxTempResetError = (uint8_t)pChirpErr->ChirpTempErr;
            CAFCMaskCcResetError.bits_st.MaskSupplyPllResetError = (uint8_t)pChirpErr->ChirpPLLSupply1v8vLowErr;
            CAFCMaskCcResetError.bits_st.MaskSupplyVcoResetError = (uint8_t)pChirpErr->ChirpVCOSupply1v8vLowErr;
            CAFCMaskCcResetError.bits_st.MaskAafcCalTimeoutResetError = (uint8_t)pChirpErr->AAFCCalTimeoutErr;
            CAFCMaskCcResetError.bits_st.MaskAafcResetError = (uint8_t)pChirpErr->AAFCDigitalErr;
            retVal = BC_SPI_WriteCheck(e_SYS_CAFC, R2M06_MASK_CC_RESET_ERROR_U16, CAFCMaskCcResetError.val_u32);
        }
    }
    return retVal;
}

static BC_ERRCODE Helper_Clr_ES2_RTMSetClrChirpErr(SYS_CAFCErrors_t *pChirpErr)
{
    BC_ERRCODE retVal;
    R2M18_ChirpErrorClrRegUnion_t ChirpErrorClr;

    ChirpErrorClr.val_u32 = 0x0;
    ChirpErrorClr.bits_st.RegCrcErrorFlagChirpClr = (uint8_t)pChirpErr->CAFCRegCRCErr;
    ChirpErrorClr.bits_st.AafcCalTimeoutErrorFlagChirpClr = (uint8_t)pChirpErr->AAFCCalTimeoutErr;
    ChirpErrorClr.bits_st.AafcErrorFlagChirpClr = (uint8_t)pChirpErr->AAFCDigitalErr;
    ChirpErrorClr.bits_st.SupplyLowErrorFlagDig1V1ChirpClr = (uint8_t)pChirpErr->ChirpDigSupply1v1LowErrorErr;
    ChirpErrorClr.bits_st.SupplyLowErrorFlagVco1V8ChirpClr = (uint8_t)pChirpErr->ChirpVCOSupply1v8vLowErr;
    ChirpErrorClr.bits_st.SupplyLowErrorFlagPll1V8ChirpClr = (uint8_t)pChirpErr->ChirpPLLSupply1v8vLowErr;
    ChirpErrorClr.bits_st.InterfaceStuckErrorFlagChirpClr = (uint8_t)pChirpErr->InterfaceStuckatErr;
    ChirpErrorClr.bits_st.VcoFreq480ErrorFlagChirpClr = (uint8_t)pChirpErr->VCOFrequency480Err;
    ChirpErrorClr.bits_st.LevelMaxErrorFlagChirpClr = (uint8_t)pChirpErr->VCOLevelMaxErr;
    ChirpErrorClr.bits_st.LevelHighErrorFlagChirpClr = (uint8_t)pChirpErr->VCOLevelHighErr;
    ChirpErrorClr.bits_st.LevelLowErrorFlagChirpClr = (uint8_t)pChirpErr->VCOLevelLowErr;
    ChirpErrorClr.bits_st.LevelMinErrorFlagChirpClr = (uint8_t)pChirpErr->VCOLevelMinErr;
    ChirpErrorClr.bits_st.VtuneHighErrorFlagChirpClr = (uint8_t)pChirpErr->VtuneHighErr;
    ChirpErrorClr.bits_st.VtuneLowErrorFlagChirpClr = (uint8_t)pChirpErr->VtuneLowErr;
    ChirpErrorClr.bits_st.TempErrorFlagChirpClr = (uint8_t)pChirpErr->ChirpTempErr;
    ChirpErrorClr.bits_st.UnlockErrorFlagChirpClr = (uint8_t)pChirpErr->PLLUnlockErr;
    ChirpErrorClr.bits_st.LockStepErrorFlagChirpClr = (uint8_t)pChirpErr->ChirpDigitalLockStepErr;

    retVal = BC_SPI_Write(e_SYS_ISM, R2M18_CHIRP_ERROR_CLR_REG_U16, ChirpErrorClr.val_u32);
    return retVal;
}

static BC_ERRCODE Helper_Set_ES2_RTMSetClrChirpErr(SYS_CAFCErrors_t *pChirpErr)
{
    BC_ERRCODE retVal;
    R2M18_ChirpErrorSetRegUnion_t ChirpErrorSet;

    ChirpErrorSet.val_u32 = 0x0;
    ChirpErrorSet.bits_st.RegCrcErrorFlagChirpSet = (uint8_t)pChirpErr->CAFCRegCRCErr;
    ChirpErrorSet.bits_st.AafcCalTimeoutErrorFlagChirpSet = (uint8_t)pChirpErr->AAFCCalTimeoutErr;
    ChirpErrorSet.bits_st.AafcErrorFlagChirpSet = (uint8_t)pChirpErr->AAFCDigitalErr;
    ChirpErrorSet.bits_st.SupplyLowErrorFlagDig1V1ChirpSet = (uint8_t)pChirpErr->ChirpDigSupply1v1LowErrorErr;
    ChirpErrorSet.bits_st.SupplyLowErrorFlagVco1V8ChirpSet = (uint8_t)pChirpErr->ChirpVCOSupply1v8vLowErr;
    ChirpErrorSet.bits_st.SupplyLowErrorFlagPll1V8ChirpSet = (uint8_t)pChirpErr->ChirpPLLSupply1v8vLowErr;
    ChirpErrorSet.bits_st.InterfaceStuckErrorFlagChirpSet = (uint8_t)pChirpErr->InterfaceStuckatErr;
    ChirpErrorSet.bits_st.VcoFreq480ErrorFlagChirpSet = (uint8_t)pChirpErr->VCOFrequency480Err;
    ChirpErrorSet.bits_st.LevelMaxErrorFlagChirpSet = (uint8_t)pChirpErr->VCOLevelMaxErr;
    ChirpErrorSet.bits_st.LevelHighErrorFlagChirpSet = (uint8_t)pChirpErr->VCOLevelHighErr;
    ChirpErrorSet.bits_st.LevelLowErrorFlagChirpSet = (uint8_t)pChirpErr->VCOLevelLowErr;
    ChirpErrorSet.bits_st.LevelMinErrorFlagChirpSet = (uint8_t)pChirpErr->VCOLevelMinErr;
    ChirpErrorSet.bits_st.VtuneHighErrorFlagChirpSet = (uint8_t)pChirpErr->VtuneHighErr;
    ChirpErrorSet.bits_st.VtuneLowErrorFlagChirpSet = (uint8_t)pChirpErr->VtuneLowErr;
    ChirpErrorSet.bits_st.TempErrorFlagChirpSet = (uint8_t)pChirpErr->ChirpTempErr;
    ChirpErrorSet.bits_st.UnlockErrorFlagChirpSet = (uint8_t)pChirpErr->PLLUnlockErr;
    ChirpErrorSet.bits_st.LockStepErrorFlagChirpSet = (uint8_t)pChirpErr->ChirpDigitalLockStepErr;

    retVal = BC_SPI_Write(e_SYS_ISM, R2M18_CHIRP_ERROR_SET_REG_U16, ChirpErrorSet.val_u32);
    return retVal;
}

BC_ERRCODE HAL_ES2_ISM_MaskRTMSetClrChirpErr(ISM_ErrCmd_e CmdReg, SYS_CAFCErrors_t *pChirpErr)
{
    BC_ERRCODE retVal;

    if (pChirpErr != NULL)
    {
        switch (CmdReg)
        {
        case e_ISM_ERR_OP_MASK_ERR:
        case e_ISM_ERR_OP_UNMASK_ERR:
            // Chirp Mask Error
            retVal = Helper_Msk_ES2_RTMSetClrChirpErr(CmdReg, pChirpErr);
            break;
        case e_ISM_ERR_OP_MONITOR_ERR:
            // chirp monitor error
            retVal = Helper_Mon_ES2_RTMSetClrChirpErr(pChirpErr);
            break;
        case e_ISM_ERR_OP_CLEAR_ERR:
            // Chirp Error Clear(These are auto clear registers so no need of  Read and Write check)
            retVal = Helper_Clr_ES2_RTMSetClrChirpErr(pChirpErr);
            break;
        case e_ISM_ERR_OP_SET_ERR:
            // chirp Set Error(These are auto clear registers so no need of  Read and Write check)
            retVal = Helper_Set_ES2_RTMSetClrChirpErr(pChirpErr);
            break;
        default:
            retVal = BC_ERR_INPUTOUTOFRANGE;
            break;
        }
    }
    else
    {
        retVal = BC_ERR_ISM_PTR_ADDR_NULL;
    }
    return retVal;
}

static BC_ERRCODE Helper_Msk_ES2_RTMSetClrMCOIErr(ISM_ErrCmd_e CmdReg, BOOL OTPRegCRCErr, BOOL ISMRegCRCErr, SYS_MCLKErrors_t *pMClkErr, SYS_LOIErrors_t *pLOIErr, SYS_CCErrors_t *pCCErr)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;

    R2M18_McLoCcIsmOtpErrorMaskRegUnion_t McLoCcIsmOtpErrorMask;
    uint8_t SetValue = 0u;

    retVal = BC_SPI_Read(e_SYS_ISM, R2M18_MC_LO_CC_ISM_OTP_ERROR_MASK_REG_U16, &McLoCcIsmOtpErrorMask.val_u32);
    if (retVal == BC_ERR_NOERROR)
    {
        SetValue = (CmdReg == e_ISM_ERR_OP_MASK_ERR) ? 1u : 0u;
        McLoCcIsmOtpErrorMask.bits_st.RegCrcErrorFlagOtpMask = Helper_RTMValidateMask(OTPRegCRCErr, SetValue, McLoCcIsmOtpErrorMask.bits_st.RegCrcErrorFlagOtpMask);
        McLoCcIsmOtpErrorMask.bits_st.RegCrcErrorFlagIsmMask = Helper_RTMValidateMask(ISMRegCRCErr, SetValue, McLoCcIsmOtpErrorMask.bits_st.RegCrcErrorFlagIsmMask);
        if (pCCErr != NULL)
        {
            // Central control (CC)
            McLoCcIsmOtpErrorMask.bits_st.RegCrcErrorFlagCcMask = Helper_RTMValidateMask(pCCErr->CCRegCRCErr, SetValue, McLoCcIsmOtpErrorMask.bits_st.RegCrcErrorFlagCcMask);
            McLoCcIsmOtpErrorMask.bits_st.RdSpiCrcErrorFlagMask = Helper_RTMValidateMask(pCCErr->SPIRdErr, SetValue, McLoCcIsmOtpErrorMask.bits_st.RdSpiCrcErrorFlagMask);
            McLoCcIsmOtpErrorMask.bits_st.WrSpiCrcErrorFlagMask = Helper_RTMValidateMask(pCCErr->SPIWrErr, SetValue, McLoCcIsmOtpErrorMask.bits_st.WrSpiCrcErrorFlagMask);
        }
        if (pLOIErr != NULL)
        {
            // LO interface
            McLoCcIsmOtpErrorMask.bits_st.RegCrcErrorFlagInterfaceMask = Helper_RTMValidateMask(pLOIErr->LOIRegCRC_Err, SetValue, McLoCcIsmOtpErrorMask.bits_st.RegCrcErrorFlagInterfaceMask);
            McLoCcIsmOtpErrorMask.bits_st.LoiLevelMaxErrorFlagInterfaceMask = Helper_RTMValidateMask(pLOIErr->LOILevelMaxErr, SetValue, McLoCcIsmOtpErrorMask.bits_st.LoiLevelMaxErrorFlagInterfaceMask);
            McLoCcIsmOtpErrorMask.bits_st.LoiLevelHighErrorFlagInterfaceMask = Helper_RTMValidateMask(pLOIErr->LOILeveHighErr, SetValue, McLoCcIsmOtpErrorMask.bits_st.LoiLevelHighErrorFlagInterfaceMask);
            McLoCcIsmOtpErrorMask.bits_st.LoiLevelLowErrorFlagInterfaceMask = Helper_RTMValidateMask(pLOIErr->LOILeveLowErr, SetValue, McLoCcIsmOtpErrorMask.bits_st.LoiLevelLowErrorFlagInterfaceMask);
            McLoCcIsmOtpErrorMask.bits_st.LoiLevelMinErrorFlagInterfaceMask = Helper_RTMValidateMask(pLOIErr->LOILeveMinErr, SetValue, McLoCcIsmOtpErrorMask.bits_st.LoiLevelMinErrorFlagInterfaceMask);
            McLoCcIsmOtpErrorMask.bits_st.BbLoinErrorFlagInterfaceMask = Helper_RTMValidateMask(pLOIErr->LOIInConnectionErr, SetValue, McLoCcIsmOtpErrorMask.bits_st.BbLoinErrorFlagInterfaceMask);
            McLoCcIsmOtpErrorMask.bits_st.BbLooutErrorFlagInterfaceMask = Helper_RTMValidateMask(pLOIErr->LOIOutConnectionErr, SetValue, McLoCcIsmOtpErrorMask.bits_st.BbLooutErrorFlagInterfaceMask);
            McLoCcIsmOtpErrorMask.bits_st.SupplyLowErrorFlag1V1InterfaceMask = Helper_RTMValidateMask(pLOIErr->LOISupply1v1LowErr, SetValue, McLoCcIsmOtpErrorMask.bits_st.SupplyLowErrorFlag1V1InterfaceMask);
        }
        if (pMClkErr != NULL)
        {
            // Master clock
            McLoCcIsmOtpErrorMask.bits_st.RegCrcErrorFlagMcMask = Helper_RTMValidateMask(pMClkErr->MclkRegCRCErr, SetValue, McLoCcIsmOtpErrorMask.bits_st.RegCrcErrorFlagMcMask);
            McLoCcIsmOtpErrorMask.bits_st.DigFreqErrorFlagMcMask = Helper_RTMValidateMask(pMClkErr->MclkDigOutPutFreqErr, SetValue, McLoCcIsmOtpErrorMask.bits_st.DigFreqErrorFlagMcMask);
            McLoCcIsmOtpErrorMask.bits_st.PllLockErrorFlagMcMask = Helper_RTMValidateMask(pMClkErr->MclkPllLockErr, SetValue, McLoCcIsmOtpErrorMask.bits_st.PllLockErrorFlagMcMask);
            McLoCcIsmOtpErrorMask.bits_st.PllLevelErrorFlagMcMask = Helper_RTMValidateMask(pMClkErr->MclkPllLevelErr, SetValue, McLoCcIsmOtpErrorMask.bits_st.PllLevelErrorFlagMcMask);
            McLoCcIsmOtpErrorMask.bits_st.PllFreqCalErrorFlagMcMask = Helper_RTMValidateMask(pMClkErr->MclkPllCalErr, SetValue, McLoCcIsmOtpErrorMask.bits_st.PllFreqCalErrorFlagMcMask);
            McLoCcIsmOtpErrorMask.bits_st.SupplyLowErrorFlag1V8McMask = Helper_RTMValidateMask(pMClkErr->MclkSupply1v8LowErr, SetValue, McLoCcIsmOtpErrorMask.bits_st.SupplyLowErrorFlag1V8McMask);
            McLoCcIsmOtpErrorMask.bits_st.MspcErrorFlagMcMask = Helper_RTMValidateMask(pMClkErr->MclkMSPCErr, SetValue, McLoCcIsmOtpErrorMask.bits_st.MspcErrorFlagMcMask);
            McLoCcIsmOtpErrorMask.bits_st.XoNoClockErrorFlagMcMask = Helper_RTMValidateMask(pMClkErr->MclkXoNoClkErr, SetValue, McLoCcIsmOtpErrorMask.bits_st.XoNoClockErrorFlagMcMask);
        }
        retVal = BC_SPI_WriteCheck(e_SYS_ISM, R2M18_MC_LO_CC_ISM_OTP_ERROR_MASK_REG_U16, McLoCcIsmOtpErrorMask.val_u32);
    }
    return retVal;
}
static BC_ERRCODE Helper_Mon_ES2_RTMSetClrMCOIErr(BOOL OTPRegCRCErr, SYS_MCLKErrors_t *pMClkErr, SYS_LOIErrors_t *pLOIErr)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;

    R2M18_McLoCcIsmOtpErrorMonRegUnion_t McLoCcIsmOtpErrorMon;
    R2M17_MaskCcResetErrorUnion_t OTPMaskCcResetError;
    R2M0C_MaskCcResetErrorUnion_t MCLKMaskCcResetError;
    R2M0A_MaskCcResetErrorUnion_t LOIMaskCcResetError;
    R2M01_MaskCcResetErrorUnion_t LVDSMaskCcResetError;
    R2M02_MaskCcResetErrorUnion_t MIPIMaskCcResetError;
    SYS_IPList_t AppConfig = {FALSE};

    retVal = BC_SPI_Read(e_SYS_OTP, R2M17_MASK_CC_RESET_ERROR_U16, &OTPMaskCcResetError.val_u32);
    if (retVal == BC_ERR_NOERROR)
    {
        OTPMaskCcResetError.bits_st.MaskRegCrcResetError = (uint8_t)OTPRegCRCErr;
        retVal = BC_SPI_WriteCheck(e_SYS_OTP, R2M17_MASK_CC_RESET_ERROR_U16, OTPMaskCcResetError.val_u32);
    }
    if (retVal == BC_ERR_NOERROR)
    {
        retVal = BC_CC_GetAppConfiguration(&AppConfig, NULL);
    }
    if (pMClkErr != NULL)
    {
        if (BC_ERR_NOERROR == retVal)
        {
            // Master clock
            retVal = BC_SPI_Read(e_SYS_ISM, R2M18_MC_LO_CC_ISM_OTP_ERROR_MON_REG_U16, &McLoCcIsmOtpErrorMon.val_u32);
            if (BC_ERR_NOERROR == retVal)
            {
                McLoCcIsmOtpErrorMon.bits_st.DigFreqErrorFlagMcMon = (uint8_t)pMClkErr->MclkDigOutPutFreqErr;
                McLoCcIsmOtpErrorMon.bits_st.PllLockErrorFlagMcMon = (uint8_t)pMClkErr->MclkPllLockErr;
                McLoCcIsmOtpErrorMon.bits_st.PllLevelErrorFlagMcMon = (uint8_t)pMClkErr->MclkPllLevelErr;
                McLoCcIsmOtpErrorMon.bits_st.PllFreqCalErrorFlagMcMon = (uint8_t)pMClkErr->MclkPllCalErr;
                McLoCcIsmOtpErrorMon.bits_st.SupplyLowErrorFlag1V8McMon = (uint8_t)pMClkErr->MclkSupply1v8LowErr;
                /* XO No clock Error monitor is enabled always in hardware */
                /* MSPC Error monitor is enabled always in hardware */
                /* Rd/Wr Err monitor is enabled always in hardware */
                /* MSPC Error monitor is enabled always in hardware */
                retVal = BC_SPI_WriteCheck(e_SYS_ISM, R2M18_MC_LO_CC_ISM_OTP_ERROR_MON_REG_U16, McLoCcIsmOtpErrorMon.val_u32);
            }
        }
        if (BC_ERR_NOERROR == retVal)
        {
            retVal = BC_SPI_Read(e_SYS_MCLK, R2M0C_MASK_CC_RESET_ERROR_U16, &MCLKMaskCcResetError.val_u32);
            if (BC_ERR_NOERROR == retVal)
            {
                MCLKMaskCcResetError.bits_st.MaskMspcResetError = (uint8_t)pMClkErr->MclkMSPCErr;
                MCLKMaskCcResetError.bits_st.MaskRegCrcResetError = (uint8_t)pMClkErr->MclkRegCRCErr;
                MCLKMaskCcResetError.bits_st.MaskPllVcoRecalibrateResetError = (uint8_t)pMClkErr->MclkPllCalErr;
                MCLKMaskCcResetError.bits_st.MaskPllLevelResetError = (uint8_t)pMClkErr->MclkPllLevelErr;
                MCLKMaskCcResetError.bits_st.MaskPllLockResetError = (uint8_t)pMClkErr->MclkPllLockErr;
                MCLKMaskCcResetError.bits_st.MaskSupplyLowResetError = (uint8_t)pMClkErr->MclkSupply1v8LowErr;
                retVal = BC_SPI_WriteCheck(e_SYS_MCLK, R2M0C_MASK_CC_RESET_ERROR_U16, MCLKMaskCcResetError.val_u32);
            }
        }
        if ((TRUE == AppConfig.LVDS) && (BC_ERR_NOERROR == retVal))
        {
            retVal = BC_SPI_Read(e_SYS_LVDS, R2M01_MASK_CC_RESET_ERROR_U16, &LVDSMaskCcResetError.val_u32);
            if (retVal == BC_ERR_NOERROR)
            {
                LVDSMaskCcResetError.bits_st.MaskFreqCountResetError = (uint8_t)pMClkErr->MclkDigOutPutFreqErr;
                retVal = BC_SPI_WriteCheck(e_SYS_LVDS, R2M01_MASK_CC_RESET_ERROR_U16, LVDSMaskCcResetError.val_u32);
            }
        }
        if ((TRUE == AppConfig.MIPI) && (BC_ERR_NOERROR == retVal))
        {
            retVal = BC_SPI_Read(e_SYS_MIPI, R2M02_MASK_CC_RESET_ERROR_U16, &MIPIMaskCcResetError.val_u32);
            if (retVal == BC_ERR_NOERROR)
            {
                MIPIMaskCcResetError.bits_st.MaskFreqCountResetError = (uint8_t)pMClkErr->MclkDigOutPutFreqErr;
                retVal = BC_SPI_WriteCheck(e_SYS_MIPI, R2M02_MASK_CC_RESET_ERROR_U16, MIPIMaskCcResetError.val_u32);
            }
        }
    }
    if (pLOIErr != NULL)
    {
        // LO interface
        if (retVal == BC_ERR_NOERROR)
        {
            retVal = BC_SPI_Read(e_SYS_ISM, R2M18_MC_LO_CC_ISM_OTP_ERROR_MON_REG_U16, &McLoCcIsmOtpErrorMon.val_u32);
        }
        if (retVal == BC_ERR_NOERROR)
        {
            McLoCcIsmOtpErrorMon.bits_st.LoiLevelMaxErrorFlagInterfaceMon = (uint8_t)pLOIErr->LOILevelMaxErr;
            McLoCcIsmOtpErrorMon.bits_st.LoiLevelHighErrorFlagInterfaceMon = (uint8_t)pLOIErr->LOILeveHighErr;
            McLoCcIsmOtpErrorMon.bits_st.LoiLevelLowErrorFlagInterfaceMon = (uint8_t)pLOIErr->LOILeveLowErr;
            McLoCcIsmOtpErrorMon.bits_st.LoiLevelMinErrorFlagInterfaceMon = (uint8_t)pLOIErr->LOILeveMinErr;
            McLoCcIsmOtpErrorMon.bits_st.BbLoinErrorFlagInterfaceMon = (uint8_t)pLOIErr->LOIInConnectionErr;
            McLoCcIsmOtpErrorMon.bits_st.BbLooutErrorFlagInterfaceMon = (uint8_t)pLOIErr->LOIOutConnectionErr;
            McLoCcIsmOtpErrorMon.bits_st.SupplyLowErrorFlag1V1InterfaceMon = (uint8_t)pLOIErr->LOISupply1v1LowErr;
            /* CRC error monitor for MCLK, LOI, CC, ISM, OTP is not required enabled always in HW*/
            retVal = BC_SPI_WriteCheck(e_SYS_ISM, R2M18_MC_LO_CC_ISM_OTP_ERROR_MON_REG_U16, McLoCcIsmOtpErrorMon.val_u32);
        }

        if (retVal == BC_ERR_NOERROR)
        {
            retVal = BC_SPI_Read(e_SYS_LOI, R2M0A_MASK_CC_RESET_ERROR_U16, &LOIMaskCcResetError.val_u32);
            if (retVal == BC_ERR_NOERROR)
            {
                LOIMaskCcResetError.bits_st.MaskRegCrcResetError = (uint8_t)pLOIErr->LOIRegCRC_Err;
                LOIMaskCcResetError.bits_st.MaskSupplyLowResetError = (uint8_t)pLOIErr->LOISupply1v1LowErr;
                retVal = BC_SPI_Write(e_SYS_LOI, R2M0A_MASK_CC_RESET_ERROR_U16, LOIMaskCcResetError.val_u32);
            }
        }
    }
    return retVal;
}
static BC_ERRCODE Helper_Set_ES2_RTMSetClrMCOIErr(BOOL OTPRegCRCErr, BOOL ISMRegCRCErr, SYS_MCLKErrors_t *pMClkErr, SYS_LOIErrors_t *pLOIErr, SYS_CCErrors_t *pCCErr)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M18_McLoCcIsmOtpErrorSetRegUnion_t McLoCcIsmOtpErrorSet;
    McLoCcIsmOtpErrorSet.val_u32 = 0x0;

    // OTP and ISM
    McLoCcIsmOtpErrorSet.bits_st.RegCrcErrorFlagOtpSet = (uint8_t)OTPRegCRCErr;
    McLoCcIsmOtpErrorSet.bits_st.RegCrcErrorFlagIsmSet = (uint8_t)ISMRegCRCErr;
    if (pCCErr != NULL)
    {
        // Central control (CC)
        McLoCcIsmOtpErrorSet.bits_st.RegCrcErrorFlagCcSet = (uint8_t)pCCErr->CCRegCRCErr;
        McLoCcIsmOtpErrorSet.bits_st.RdSpiCrcErrorFlagSet = (uint8_t)pCCErr->SPIRdErr;
        McLoCcIsmOtpErrorSet.bits_st.WrSpiCrcErrorFlagSet = (uint8_t)pCCErr->SPIWrErr;
    }
    if (pLOIErr != NULL)
    {
        // LO interface
        McLoCcIsmOtpErrorSet.bits_st.RegCrcErrorFlagInterfaceSet = (uint8_t)pLOIErr->LOIRegCRC_Err;
        McLoCcIsmOtpErrorSet.bits_st.LoiLevelMaxErrorFlagInterfaceSet = (uint8_t)pLOIErr->LOILevelMaxErr;
        McLoCcIsmOtpErrorSet.bits_st.LoiLevelHighErrorFlagInterfaceSet = (uint8_t)pLOIErr->LOILeveHighErr;
        McLoCcIsmOtpErrorSet.bits_st.LoiLevelLowErrorFlagInterfaceSet = (uint8_t)pLOIErr->LOILeveLowErr;
        McLoCcIsmOtpErrorSet.bits_st.LoiLevelMinErrorFlagInterfaceSet = (uint8_t)pLOIErr->LOILeveMinErr;
        McLoCcIsmOtpErrorSet.bits_st.BbLoinErrorFlagInterfaceSet = (uint8_t)pLOIErr->LOIInConnectionErr;
        McLoCcIsmOtpErrorSet.bits_st.BbLooutErrorFlagInterfaceSet = (uint8_t)pLOIErr->LOIOutConnectionErr;
        McLoCcIsmOtpErrorSet.bits_st.SupplyLowErrorFlag1V1InterfaceSet = (uint8_t)pLOIErr->LOISupply1v1LowErr;
    }
    if (pMClkErr != NULL)
    {
        // Master clock
        McLoCcIsmOtpErrorSet.bits_st.RegCrcErrorFlagMcSet = (uint8_t)pMClkErr->MclkRegCRCErr;
        McLoCcIsmOtpErrorSet.bits_st.DigFreqErrorFlagMcSet = (uint8_t)pMClkErr->MclkDigOutPutFreqErr;
        McLoCcIsmOtpErrorSet.bits_st.PllLockErrorFlagMcSet = (uint8_t)pMClkErr->MclkPllLockErr;
        McLoCcIsmOtpErrorSet.bits_st.PllLevelErrorFlagMcSet = (uint8_t)pMClkErr->MclkPllLevelErr;
        McLoCcIsmOtpErrorSet.bits_st.PllFreqCalErrorFlagMcSet = (uint8_t)pMClkErr->MclkPllCalErr;
        McLoCcIsmOtpErrorSet.bits_st.SupplyLowErrorFlag1V8McSet = (uint8_t)pMClkErr->MclkSupply1v8LowErr;
        McLoCcIsmOtpErrorSet.bits_st.MspcErrorFlagMcSet = (uint8_t)pMClkErr->MclkMSPCErr;
        McLoCcIsmOtpErrorSet.bits_st.XoNoClockErrorFlagMcSet = (uint8_t)pMClkErr->MclkXoNoClkErr;
    }
    retVal = BC_SPI_Write(e_SYS_ISM, R2M18_MC_LO_CC_ISM_OTP_ERROR_SET_REG_U16, McLoCcIsmOtpErrorSet.val_u32);
    return retVal;
}
static BC_ERRCODE Helper_Clr_ES2_RTMSetClrMCOIErr(BOOL OTPRegCRCErr, BOOL ISMRegCRCErr, SYS_MCLKErrors_t *pMClkErr, SYS_LOIErrors_t *pLOIErr, SYS_CCErrors_t *pCCErr)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M18_McLoCcIsmOtpErrorClrRegUnion_t McLoCcIsmOtpErrorClr;
    McLoCcIsmOtpErrorClr.val_u32 = 0x0;

    // OTP and ISM
    McLoCcIsmOtpErrorClr.bits_st.RegCrcErrorFlagOtpClr = (uint8_t)OTPRegCRCErr;
    McLoCcIsmOtpErrorClr.bits_st.RegCrcErrorFlagIsmClr = (uint8_t)ISMRegCRCErr;
    if (pCCErr != NULL)
    {
        // Central control (CC)
        McLoCcIsmOtpErrorClr.bits_st.RegCrcErrorFlagCcClr = (uint8_t)pCCErr->CCRegCRCErr;
        McLoCcIsmOtpErrorClr.bits_st.RdSpiCrcErrorFlagClr = (uint8_t)pCCErr->SPIRdErr;
        McLoCcIsmOtpErrorClr.bits_st.WrSpiCrcErrorFlagClr = (uint8_t)pCCErr->SPIWrErr;
    }
    if (pLOIErr != NULL)
    {
        // LO interface
        McLoCcIsmOtpErrorClr.bits_st.RegCrcErrorFlagInterfaceClr = (uint8_t)pLOIErr->LOIRegCRC_Err;
        McLoCcIsmOtpErrorClr.bits_st.LoiLevelMaxErrorFlagInterfaceClr = (uint8_t)pLOIErr->LOILevelMaxErr;
        McLoCcIsmOtpErrorClr.bits_st.LoiLevelHighErrorFlagInterfaceClr = (uint8_t)pLOIErr->LOILeveHighErr;
        McLoCcIsmOtpErrorClr.bits_st.LoiLevelLowErrorFlagInterfaceClr = (uint8_t)pLOIErr->LOILeveLowErr;
        McLoCcIsmOtpErrorClr.bits_st.LoiLevelMinErrorFlagInterfaceClr = (uint8_t)pLOIErr->LOILeveMinErr;
        McLoCcIsmOtpErrorClr.bits_st.BbLoinErrorFlagInterfaceClr = (uint8_t)pLOIErr->LOIInConnectionErr;
        McLoCcIsmOtpErrorClr.bits_st.BbLooutErrorFlagInterfaceClr = (uint8_t)pLOIErr->LOIOutConnectionErr;
        McLoCcIsmOtpErrorClr.bits_st.SupplyLowErrorFlag1V1InterfaceClr = (uint8_t)pLOIErr->LOISupply1v1LowErr;
    }
    if (pMClkErr != NULL)
    {
        // Master clock
        McLoCcIsmOtpErrorClr.bits_st.RegCrcErrorFlagMcClr = (uint8_t)pMClkErr->MclkRegCRCErr;
        McLoCcIsmOtpErrorClr.bits_st.DigFreqErrorFlagMcClr = (uint8_t)pMClkErr->MclkDigOutPutFreqErr;
        McLoCcIsmOtpErrorClr.bits_st.PllLockErrorFlagMcClr = (uint8_t)pMClkErr->MclkPllLockErr;
        McLoCcIsmOtpErrorClr.bits_st.PllLevelErrorFlagMcClr = (uint8_t)pMClkErr->MclkPllLevelErr;
        McLoCcIsmOtpErrorClr.bits_st.PllFreqCalErrorFlagMcClr = (uint8_t)pMClkErr->MclkPllCalErr;
        McLoCcIsmOtpErrorClr.bits_st.SupplyLowErrorFlag1V8McClr = (uint8_t)pMClkErr->MclkSupply1v8LowErr;
        McLoCcIsmOtpErrorClr.bits_st.MspcErrorFlagMcClr = (uint8_t)pMClkErr->MclkMSPCErr;
        McLoCcIsmOtpErrorClr.bits_st.XoNoClockErrorFlagMcClr = (uint8_t)pMClkErr->MclkXoNoClkErr;
    }
    retVal = BC_SPI_Write(e_SYS_ISM, R2M18_MC_LO_CC_ISM_OTP_ERROR_CLR_REG_U16, McLoCcIsmOtpErrorClr.val_u32);
    return retVal;
}
// This API configs all functional safety errors for MClk, LO, CC, ISM and OTP.
BC_ERRCODE HAL_ES2_ISM_MaskRTMSetClrMCOIErr(ISM_ErrCmd_e CmdReg, BOOL OTPRegCRCErr, BOOL ISMRegCRCErr, SYS_MCLKErrors_t *pMClkErr, SYS_LOIErrors_t *pLOIErr, SYS_CCErrors_t *pCCErr)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;

    if (((pMClkErr == NULL) && (pLOIErr == NULL) && (pCCErr == NULL)))
    {
        retVal = BC_ERR_ISM_PTR_ADDR_NULL;
    }
    else
    {
        switch (CmdReg)
        {
        case e_ISM_ERR_OP_MASK_ERR:
        case e_ISM_ERR_OP_UNMASK_ERR:
            // MClk, LO,CC,ISM and OTP Mask Error
            retVal = Helper_Msk_ES2_RTMSetClrMCOIErr(CmdReg, OTPRegCRCErr, ISMRegCRCErr, pMClkErr, pLOIErr, pCCErr);
            break;
        case e_ISM_ERR_OP_MONITOR_ERR:
            // MClk, LO,CC,ISM and OTP monitor error
            retVal = Helper_Mon_ES2_RTMSetClrMCOIErr(OTPRegCRCErr, pMClkErr, pLOIErr);
            break;
        case e_ISM_ERR_OP_CLEAR_ERR:
            // MClk, LO,CC,ISM and OTP Error Clear(These are auto clear registers so no need of Read and Write check)
            retVal = Helper_Clr_ES2_RTMSetClrMCOIErr(OTPRegCRCErr, ISMRegCRCErr, pMClkErr, pLOIErr, pCCErr);
            break;
        case e_ISM_ERR_OP_SET_ERR:
            // MClk, LO,CC,ISM and OTP Set Error(These are auto clear registers so no need of Read and Write check)
            retVal = Helper_Set_ES2_RTMSetClrMCOIErr(OTPRegCRCErr, ISMRegCRCErr, pMClkErr, pLOIErr, pCCErr);
            break;
        default:
            retVal = BC_ERR_INPUTOUTOFRANGE;
            break;
        }
    }
    return retVal;
}

// This API configs functional safety errors for SSB, GBIAS, Serialiser GLDO and ATB.
static BC_ERRCODE Helper_Msk_ES2_RTMSetClrSSGAErr(ISM_ErrCmd_e CmdReg, BOOL ATBRegCRCErr, SYS_SerialiserErrors_t *pSerErr, SYS_SSBErrors_t *pSSBErr, SYS_GBIASErrors_t *pGBErr, SYS_GLDOErrors_t *pGLDOErr)
{
    BC_ERRCODE retVal;
    R2M18_SsbGbSerGldoAtbErrorMaskRegUnion_t SsbGbSerGldoAtbErrorMask;
    uint8_t SetValue = 0u;

    retVal = BC_SPI_Read(e_SYS_ISM, R2M18_SSB_GB_SER_GLDO_ATB_ERROR_MASK_REG_U16, &SsbGbSerGldoAtbErrorMask.val_u32);
    if (retVal == BC_ERR_NOERROR)
    {
        SetValue = (CmdReg == e_ISM_ERR_OP_MASK_ERR) ? 1u : 0u; // Used for mask register
        // ATB
        SsbGbSerGldoAtbErrorMask.bits_st.RegCrcErrorFlagAtbMask = (uint8_t)ATBRegCRCErr;
        if (pSerErr != NULL)
        {
            // Serialiser
            SsbGbSerGldoAtbErrorMask.bits_st.RegCrcErrorFlagSerMask = (pSerErr->SerRegCRCErr == TRUE) ? SetValue : SsbGbSerGldoAtbErrorMask.bits_st.RegCrcErrorFlagSerMask;
            SsbGbSerGldoAtbErrorMask.bits_st.SupplyLowErrorFlag1V8SerMask = (pSerErr->Supply1v8SerLowErr == TRUE) ? SetValue : SsbGbSerGldoAtbErrorMask.bits_st.SupplyLowErrorFlag1V8SerMask;
            SsbGbSerGldoAtbErrorMask.bits_st.SupplyLowErrorFlag1V1Csi2Mask = (pSerErr->Supply1v1MIPILowErr == TRUE) ? SetValue : SsbGbSerGldoAtbErrorMask.bits_st.SupplyLowErrorFlag1V1Csi2Mask;
            SsbGbSerGldoAtbErrorMask.bits_st.SupplyLowErrorFlag1V1SerMask = (pSerErr->Supply1v1LVDSLowErr == TRUE) ? SetValue : SsbGbSerGldoAtbErrorMask.bits_st.SupplyLowErrorFlag1V1SerMask;
        }
        if (pSSBErr != NULL)
        {
            // SSB
            SsbGbSerGldoAtbErrorMask.bits_st.RegCrcErrorFlagSsbModMask = (pSSBErr->SSBRegCRCErr == TRUE) ? SetValue : SsbGbSerGldoAtbErrorMask.bits_st.RegCrcErrorFlagSsbModMask;
            SsbGbSerGldoAtbErrorMask.bits_st.SupplyLowErrorFlag1V8SsbModMask = (pSSBErr->SSBSupply1v8LowErr == TRUE) ? SetValue : SsbGbSerGldoAtbErrorMask.bits_st.SupplyLowErrorFlag1V8SsbModMask;
        }
        if (pGBErr != NULL)
        {
            // Global BIAS
            SsbGbSerGldoAtbErrorMask.bits_st.RegCrcErrorFlagGlobalBiasMask = (pGBErr->GBIASRegCRCErr == TRUE) ? SetValue : SsbGbSerGldoAtbErrorMask.bits_st.RegCrcErrorFlagGlobalBiasMask;
            SsbGbSerGldoAtbErrorMask.bits_st.SupplyLowErrorFlag1V8GlobalBiasMask = (pGBErr->GBIASSupply1v8LowErr == TRUE) ? SetValue : SsbGbSerGldoAtbErrorMask.bits_st.SupplyLowErrorFlag1V8GlobalBiasMask;
        }
        if (pGLDOErr != NULL)
        {
            // Global LDO
            SsbGbSerGldoAtbErrorMask.bits_st.RegCrcErrorFlagGlobalLdoMask = (pGLDOErr->GlDORegCRCErr == TRUE) ? SetValue : SsbGbSerGldoAtbErrorMask.bits_st.RegCrcErrorFlagGlobalLdoMask;
            SsbGbSerGldoAtbErrorMask.bits_st.SupplyHighErrorFlag1V8GlobalLdoMask = (pGLDOErr->GlDOSupply1v8HighErr == TRUE) ? SetValue : SsbGbSerGldoAtbErrorMask.bits_st.SupplyHighErrorFlag1V8GlobalLdoMask;
            SsbGbSerGldoAtbErrorMask.bits_st.SupplyLowErrorFlag1V8GlobalLdoMask = (pGLDOErr->GlDOSupply1v8LowErr == TRUE) ? SetValue : SsbGbSerGldoAtbErrorMask.bits_st.RegCrcErrorFlagGlobalBiasMask;
            SsbGbSerGldoAtbErrorMask.bits_st.SupplyHighErrorFlag1V1GlobalLdoMask = (pGLDOErr->GlDOSupply1v1HighErr == TRUE) ? SetValue : SsbGbSerGldoAtbErrorMask.bits_st.SupplyLowErrorFlag1V8GlobalBiasMask;
            SsbGbSerGldoAtbErrorMask.bits_st.SupplyLowErrorFlag1V1GlobalLdoMask = (pGLDOErr->GlDOSupply1v1LowErr == TRUE) ? SetValue : SsbGbSerGldoAtbErrorMask.bits_st.RegCrcErrorFlagGlobalBiasMask;
        }
        retVal = BC_SPI_WriteCheck(e_SYS_ISM, R2M18_SSB_GB_SER_GLDO_ATB_ERROR_MASK_REG_U16, SsbGbSerGldoAtbErrorMask.val_u32);
    }
    return retVal;
}
static BC_ERRCODE Helper_Mon_ES2_RTMSetClrSSGAErr(BOOL ATBRegCRCErr, SYS_SerialiserErrors_t *pSerErr, SYS_SSBErrors_t *pSSBErr, SYS_GBIASErrors_t *pGBErr, SYS_GLDOErrors_t *pGLDOErr)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M18_SsbGbSerGldoAtbErrorMonRegUnion_t SsbGbSerGldoAtbErrorMon;
    R2M16_MaskCcResetErrorUnion_t ATBMaskCcResetError;
    SYS_IPList_t AppConfig;

    retVal = BC_CC_GetAppConfiguration(&AppConfig, NULL);

    if (retVal == BC_ERR_NOERROR)
    {
        retVal = Helper_RTMSetClrGldo(AppConfig, &SsbGbSerGldoAtbErrorMon, pGLDOErr);
    }
    if (retVal == BC_ERR_NOERROR)
    {
        retVal = Helper_RTMSetClrGbias(AppConfig, &SsbGbSerGldoAtbErrorMon, pGBErr);
    }
    if ((retVal == BC_ERR_NOERROR) && (pSSBErr != NULL))
    {
        // SSB
        SsbGbSerGldoAtbErrorMon.bits_st.SupplyLowErrorFlag1V8SsbModMon = (uint8_t)pSSBErr->SSBSupply1v8LowErr;
        /*CRC monitor is enabled always in hardware*/
    }
    if (retVal == BC_ERR_NOERROR)
    {
        retVal = Helper_RTMSetClrLvdsMipi(AppConfig, &SsbGbSerGldoAtbErrorMon, pSerErr);
    }

    if ((retVal == BC_ERR_NOERROR) && (TRUE == AppConfig.ATB))
    {
        /*CRC monitor is enabled always in hardware*/
        retVal = BC_SPI_Read(e_SYS_ATB, R2M16_MASK_CC_RESET_ERROR_U16, &ATBMaskCcResetError.val_u32);
        if (retVal == BC_ERR_NOERROR)
        {
            /*Mask Reset ERROR for ATB*/
            ATBMaskCcResetError.bits_st.MaskRegCrcResetError = (uint8_t)ATBRegCRCErr;
            retVal = BC_SPI_WriteCheck(e_SYS_ATB, R2M16_MASK_CC_RESET_ERROR_U16, ATBMaskCcResetError.val_u32);
        }
    }
    if (retVal == BC_ERR_NOERROR)
    {
        retVal = BC_SPI_WriteCheck(e_SYS_ISM, R2M18_SSB_GB_SER_GLDO_ATB_ERROR_MON_REG_U16, SsbGbSerGldoAtbErrorMon.val_u32);
    }
    return retVal;
}
static BC_ERRCODE Helper_Clr_ES2_RTMSetClrSSGAErr(BOOL ATBRegCRCErr, SYS_SerialiserErrors_t *pSerErr, SYS_SSBErrors_t *pSSBErr, SYS_GBIASErrors_t *pGBErr, SYS_GLDOErrors_t *pGLDOErr)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M18_SsbGbSerGldoAtbErrorClrRegUnion_t SsbGbSerGldoAtbErrorClr;

    SsbGbSerGldoAtbErrorClr.val_u32 = 0x0;

    // ATB
    SsbGbSerGldoAtbErrorClr.bits_st.RegCrcErrorFlagAtbClr = (uint8_t)ATBRegCRCErr;

    if (pSerErr != NULL)
    {
        // Serialiser
        SsbGbSerGldoAtbErrorClr.bits_st.RegCrcErrorFlagSerClr = (uint8_t)pSerErr->SerRegCRCErr;
        SsbGbSerGldoAtbErrorClr.bits_st.SupplyLowErrorFlag1V8SerClr = (uint8_t)pSerErr->Supply1v8SerLowErr;
        SsbGbSerGldoAtbErrorClr.bits_st.SupplyLowErrorFlag1V1Csi2Clr = (uint8_t)pSerErr->Supply1v1MIPILowErr;
        SsbGbSerGldoAtbErrorClr.bits_st.SupplyLowErrorFlag1V1SerClr = (uint8_t)pSerErr->Supply1v1LVDSLowErr;
    }
    if (pSSBErr != NULL)
    {
        // SSB
        SsbGbSerGldoAtbErrorClr.bits_st.RegCrcErrorFlagSsbModClr = (uint8_t)pSSBErr->SSBRegCRCErr;
        SsbGbSerGldoAtbErrorClr.bits_st.SupplyLowErrorFlag1V8SsbModClr = (uint8_t)pSSBErr->SSBSupply1v8LowErr;
    }
    if (pGBErr != NULL)
    {
        // Global BIAS
        SsbGbSerGldoAtbErrorClr.bits_st.RegCrcErrorFlagGlobalBiasClr = (uint8_t)pGBErr->GBIASRegCRCErr;
        SsbGbSerGldoAtbErrorClr.bits_st.SupplyLowErrorFlag1V8GlobalBiasClr = (uint8_t)pGBErr->GBIASSupply1v8LowErr;
    }
    if (pGLDOErr != NULL)
    {
        // Global LDO
        SsbGbSerGldoAtbErrorClr.bits_st.RegCrcErrorFlagGlobalLdoClr = (uint8_t)pGLDOErr->GlDORegCRCErr;
        SsbGbSerGldoAtbErrorClr.bits_st.SupplyHighErrorFlag1V8GlobalLdoClr = (uint8_t)pGLDOErr->GlDOSupply1v8HighErr;
        SsbGbSerGldoAtbErrorClr.bits_st.SupplyLowErrorFlag1V8GlobalLdoClr = (uint8_t)pGLDOErr->GlDOSupply1v8LowErr;
        SsbGbSerGldoAtbErrorClr.bits_st.SupplyHighErrorFlag1V1GlobalLdoClr = (uint8_t)pGLDOErr->GlDOSupply1v1HighErr;
        SsbGbSerGldoAtbErrorClr.bits_st.SupplyLowErrorFlag1V1GlobalLdoClr = (uint8_t)pGLDOErr->GlDOSupply1v1LowErr;
    }
    retVal = BC_SPI_Write(e_SYS_ISM, R2M18_SSB_GB_SER_GLDO_ATB_ERROR_CLR_REG_U16, SsbGbSerGldoAtbErrorClr.val_u32);
    return retVal;
}
static BC_ERRCODE Helper_Set_ES2_RTMSetClrSSGAErr(BOOL ATBRegCRCErr, SYS_SerialiserErrors_t *pSerErr, SYS_SSBErrors_t *pSSBErr, SYS_GBIASErrors_t *pGBErr, SYS_GLDOErrors_t *pGLDOErr)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M18_SsbGbSerGldoAtbErrorSetRegUnion_t SsbGbSerGldoAtbErrorSet;

    SsbGbSerGldoAtbErrorSet.val_u32 = 0x0;

    // ATB
    SsbGbSerGldoAtbErrorSet.bits_st.RegCrcErrorFlagAtbSet = (uint8_t)ATBRegCRCErr;
    if (pSerErr != NULL)
    { // Serialiser
        SsbGbSerGldoAtbErrorSet.bits_st.RegCrcErrorFlagSerSet = (uint8_t)pSerErr->SerRegCRCErr;
        SsbGbSerGldoAtbErrorSet.bits_st.SupplyLowErrorFlag1V8SerSet = (uint8_t)pSerErr->Supply1v8SerLowErr;
        SsbGbSerGldoAtbErrorSet.bits_st.SupplyLowErrorFlag1V1Csi2Set = (uint8_t)pSerErr->Supply1v1MIPILowErr;
        SsbGbSerGldoAtbErrorSet.bits_st.SupplyLowErrorFlag1V1SerSet = (uint8_t)pSerErr->Supply1v1LVDSLowErr;
    }
    if (pSSBErr != NULL)
    {
        // SSB
        SsbGbSerGldoAtbErrorSet.bits_st.RegCrcErrorFlagSsbModSet = (uint8_t)pSSBErr->SSBRegCRCErr;
        SsbGbSerGldoAtbErrorSet.bits_st.SupplyLowErrorFlag1V8SsbModSet = (uint8_t)pSSBErr->SSBSupply1v8LowErr;
    }
    if (pGBErr != NULL)
    {
        // Global BIAS
        SsbGbSerGldoAtbErrorSet.bits_st.RegCrcErrorFlagGlobalBiasSet = (uint8_t)pGBErr->GBIASRegCRCErr;
        SsbGbSerGldoAtbErrorSet.bits_st.SupplyLowErrorFlag1V8GlobalBiasSet = (uint8_t)pGBErr->GBIASSupply1v8LowErr;
    }
    if (pGLDOErr != NULL)
    {
        // Global LDO
        SsbGbSerGldoAtbErrorSet.bits_st.RegCrcErrorFlagGlobalLdoSet = (uint8_t)pGLDOErr->GlDORegCRCErr;
        SsbGbSerGldoAtbErrorSet.bits_st.SupplyHighErrorFlag1V8GlobalLdoSet = (uint8_t)pGLDOErr->GlDOSupply1v8HighErr;
        SsbGbSerGldoAtbErrorSet.bits_st.SupplyLowErrorFlag1V8GlobalLdoSet = (uint8_t)pGLDOErr->GlDOSupply1v8LowErr;
        SsbGbSerGldoAtbErrorSet.bits_st.SupplyHighErrorFlag1V1GlobalLdoSet = (uint8_t)pGLDOErr->GlDOSupply1v1HighErr;
        SsbGbSerGldoAtbErrorSet.bits_st.SupplyLowErrorFlag1V1GlobalLdoSet = (uint8_t)pGLDOErr->GlDOSupply1v1LowErr;
    }
    retVal = BC_SPI_Write(e_SYS_ISM, R2M18_SSB_GB_SER_GLDO_ATB_ERROR_SET_REG_U16, SsbGbSerGldoAtbErrorSet.val_u32);
    return retVal;
}
BC_ERRCODE HAL_ES2_ISM_MaskRTMSetClrSSGAErr(ISM_ErrCmd_e CmdReg, BOOL ATBRegCRCErr, SYS_SerialiserErrors_t *pSerErr, SYS_SSBErrors_t *pSSBErr, SYS_GBIASErrors_t *pGBErr, SYS_GLDOErrors_t *pGLDOErr)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;

    if ((pSerErr == NULL) && (pSSBErr == NULL) && (pGBErr == NULL) && (pGLDOErr == NULL))
    {
        retVal = BC_ERR_ISM_PTR_ADDR_NULL;
    }
    if (retVal == BC_ERR_NOERROR)
    {
        switch (CmdReg)
        {
        case e_ISM_ERR_OP_MASK_ERR:
        case e_ISM_ERR_OP_UNMASK_ERR:
            // SSB, GBIAS, Serialiser GLDO and ATB Mask Error
            retVal = Helper_Msk_ES2_RTMSetClrSSGAErr(CmdReg, ATBRegCRCErr, pSerErr, pSSBErr, pGBErr, pGLDOErr);
            break;
        case e_ISM_ERR_OP_MONITOR_ERR:
            // SSB, GBIAS, Serialiser GLDO and ATB monitor error
            retVal = Helper_Mon_ES2_RTMSetClrSSGAErr(ATBRegCRCErr, pSerErr, pSSBErr, pGBErr, pGLDOErr);
            break;
        case e_ISM_ERR_OP_CLEAR_ERR:
            // SSB, GBIAS, Serialiser GLDO and ATB Error Clear(These are auto clear registers so no need of Read and Write check)
            retVal = Helper_Clr_ES2_RTMSetClrSSGAErr(ATBRegCRCErr, pSerErr, pSSBErr, pGBErr, pGLDOErr);
            break;
        case e_ISM_ERR_OP_SET_ERR:
            // SSB, GBIAS, Serialiser GLDO and ATB Set Error(These are auto clear registers so no need of Read and Write check)
            retVal = Helper_Set_ES2_RTMSetClrSSGAErr(ATBRegCRCErr, pSerErr, pSSBErr, pGBErr, pGLDOErr);
            break;
        default:
            retVal = BC_ERR_INPUTOUTOFRANGE;
            break;
        }
    }
    return retVal;
}

static BC_ERRCODE Helper_Msk_ES2_RTMSetClrADCErr(ISM_ErrCmd_e CmdReg, SYS_ADCErrors_t *pADC12Err, SYS_ADCErrors_t *pADC34Err)
{
    BC_ERRCODE retVal;
    R2M18_AdcErrorMaskRegUnion_t AdcErrorMask;
    uint8_t SetValue = 0u;
    retVal = BC_SPI_Read(e_SYS_ISM, R2M18_ADC_ERROR_MASK_REG_U16, &AdcErrorMask.val_u32);
    if (retVal == BC_ERR_NOERROR)
    {
        SetValue = (CmdReg == e_ISM_ERR_OP_MASK_ERR) ? 1u : 0u;
        if (pADC12Err != NULL)
        {
            // ADC12
            AdcErrorMask.bits_st.RegCrcErrorFlagAdc12Mask = (pADC12Err->ADCRegCrcErr == TRUE) ? SetValue : AdcErrorMask.bits_st.RegCrcErrorFlagAdc12Mask;
            AdcErrorMask.bits_st.SupplyLowErrorFlag1V8Adc12Mask = (pADC12Err->ADCSupply1v8LowErr == TRUE) ? SetValue : AdcErrorMask.bits_st.SupplyLowErrorFlag1V8Adc12Mask;
            AdcErrorMask.bits_st.HardClippingFlagPersistentAdc2Mask = (pADC12Err->ADCn1HardClippingErr == TRUE) ? SetValue : AdcErrorMask.bits_st.HardClippingFlagPersistentAdc2Mask;
            AdcErrorMask.bits_st.HardClippingFlagPersistentAdc1Mask = (pADC12Err->ADCn0HardClippingErr == TRUE) ? SetValue : AdcErrorMask.bits_st.HardClippingFlagPersistentAdc1Mask;
            AdcErrorMask.bits_st.CalErrorFlagPersistentAdc2Mask = (pADC12Err->ADCn1CalErr == TRUE) ? SetValue : AdcErrorMask.bits_st.CalErrorFlagPersistentAdc2Mask;
            AdcErrorMask.bits_st.CalErrorFlagPersistentAdc1Mask = (pADC12Err->ADCn0CalErr == TRUE) ? SetValue : AdcErrorMask.bits_st.CalErrorFlagPersistentAdc1Mask;
        }
        if (pADC34Err != NULL)
        {
            // ADC34
            AdcErrorMask.bits_st.RegCrcErrorFlagAdc34Mask = (pADC34Err->ADCRegCrcErr == TRUE) ? SetValue : AdcErrorMask.bits_st.RegCrcErrorFlagAdc34Mask;
            AdcErrorMask.bits_st.SupplyLowErrorFlag1V8Adc34Mask = (pADC34Err->ADCSupply1v8LowErr == TRUE) ? SetValue : AdcErrorMask.bits_st.SupplyLowErrorFlag1V8Adc34Mask;
            AdcErrorMask.bits_st.HardClippingFlagPersistentAdc4Mask = (pADC34Err->ADCn1HardClippingErr == TRUE) ? SetValue : AdcErrorMask.bits_st.HardClippingFlagPersistentAdc4Mask;
            AdcErrorMask.bits_st.HardClippingFlagPersistentAdc3Mask = (pADC34Err->ADCn0HardClippingErr == TRUE) ? SetValue : AdcErrorMask.bits_st.HardClippingFlagPersistentAdc3Mask;
            AdcErrorMask.bits_st.CalErrorFlagPersistentAdc4Mask = (pADC34Err->ADCn1CalErr == TRUE) ? SetValue : AdcErrorMask.bits_st.CalErrorFlagPersistentAdc4Mask;
            AdcErrorMask.bits_st.CalErrorFlagPersistentAdc3Mask = (pADC34Err->ADCn0CalErr == TRUE) ? SetValue : AdcErrorMask.bits_st.CalErrorFlagPersistentAdc3Mask;
        }

        retVal = BC_SPI_WriteCheck(e_SYS_ISM, R2M18_ADC_ERROR_MASK_REG_U16, AdcErrorMask.val_u32);
    }
    return retVal;
}

static BC_ERRCODE Helper_Mon_ES2_RTMSetClrADCErr(SYS_ADCErrors_t *pADC12Err, SYS_ADCErrors_t *pADC34Err)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M18_AdcErrorMonRegUnion_t AdcErrorMon;
    R2M07_MaskCcResetErrorUnion_t ADC12MaskCcResetError;
    R2M07_MaskCcResetErrorUnion_t ADC34MaskCcResetError;
    SYS_IPList_t AppConfig;

    retVal = BC_CC_GetAppConfiguration(&AppConfig, NULL);
    if (retVal == BC_ERR_NOERROR)
    {
        retVal = BC_SPI_Read(e_SYS_ISM, R2M18_ADC_ERROR_MON_REG_U16, &AdcErrorMon.val_u32);
    }
    // ADC12
    if ((retVal == BC_ERR_NOERROR) && (pADC12Err != NULL) && (TRUE == AppConfig.ADC12))
    {
        AdcErrorMon.bits_st.SupplyLowErrorFlag1V8Adc12Mon = (uint8_t)pADC12Err->ADCSupply1v8LowErr;
        AdcErrorMon.bits_st.HardClippingFlagPersistentAdc2Mon = (uint8_t)pADC12Err->ADCn1HardClippingErr;
        AdcErrorMon.bits_st.HardClippingFlagPersistentAdc1Mon = (uint8_t)pADC12Err->ADCn0HardClippingErr;
        AdcErrorMon.bits_st.CalErrorFlagPersistentAdc2Mon = (uint8_t)pADC12Err->ADCn1CalErr;
        AdcErrorMon.bits_st.CalErrorFlagPersistentAdc1Mon = (uint8_t)pADC12Err->ADCn0CalErr;
        /*CRC monitor is enabled always in hardware*/
        retVal = BC_SPI_Read(e_SYS_ADC12, R2M07_MASK_CC_RESET_ERROR_U16, &ADC12MaskCcResetError.val_u32);
        if (retVal == BC_ERR_NOERROR)
        {
            /*Mask Reset Error Status for ADC12*/
            ADC12MaskCcResetError.bits_st.MaskAdcRegCrcResetError = (uint8_t)pADC12Err->ADCRegCrcErr;
            ADC12MaskCcResetError.bits_st.MaskAdcResetError = (uint8_t)(((pADC12Err->ADCSupply1v8LowErr << 7u) | (pADC12Err->ADCn1CalErr << 5u) | (pADC12Err->ADCn0CalErr << 4u) | (pADC12Err->ADCn1HardClippingErr << 3u) | (pADC12Err->ADCn0HardClippingErr << 2u)) & 0xFFu);
            retVal = BC_SPI_WriteCheck(e_SYS_ADC12, R2M07_MASK_CC_RESET_ERROR_U16, ADC12MaskCcResetError.val_u32);
        }
    }
    if ((retVal == BC_ERR_NOERROR) && (pADC34Err != NULL) && (TRUE == AppConfig.ADC34))
    {
        // ADC34
        AdcErrorMon.bits_st.SupplyLowErrorFlag1V8Adc34Mon = (uint8_t)pADC34Err->ADCSupply1v8LowErr;
        AdcErrorMon.bits_st.HardClippingFlagPersistentAdc4Mon = (uint8_t)pADC34Err->ADCn1HardClippingErr;
        AdcErrorMon.bits_st.HardClippingFlagPersistentAdc3Mon = (uint8_t)pADC34Err->ADCn0HardClippingErr;
        AdcErrorMon.bits_st.CalErrorFlagPersistentAdc4Mon = (uint8_t)pADC34Err->ADCn1CalErr;
        AdcErrorMon.bits_st.CalErrorFlagPersistentAdc3Mon = (uint8_t)pADC34Err->ADCn0CalErr;
        /*CRC monitor is enabled always in hardware*/
        retVal = BC_SPI_Read(e_SYS_ADC34, R2M07_MASK_CC_RESET_ERROR_U16, &ADC34MaskCcResetError.val_u32);
        if (retVal == BC_ERR_NOERROR)
        {
            /*Mask Reset Error Status for ADC34*/
            ADC34MaskCcResetError.bits_st.MaskAdcRegCrcResetError = (uint8_t)pADC34Err->ADCRegCrcErr;
            ADC34MaskCcResetError.bits_st.MaskAdcResetError = (uint8_t)(((pADC34Err->ADCSupply1v8LowErr << 7u) | (pADC34Err->ADCn1CalErr << 5u) | (pADC34Err->ADCn0CalErr << 4u) | (pADC34Err->ADCn1HardClippingErr << 3u) | (pADC34Err->ADCn0HardClippingErr << 2u)) & 0xFFu);
            retVal = BC_SPI_WriteCheck(e_SYS_ADC34, R2M07_MASK_CC_RESET_ERROR_U16, ADC34MaskCcResetError.val_u32);
        }
    }
    if (retVal == BC_ERR_NOERROR)
    {
        retVal = BC_SPI_WriteCheck(e_SYS_ISM, R2M18_ADC_ERROR_MON_REG_U16, AdcErrorMon.val_u32);
    }
    return retVal;
}

static BC_ERRCODE Helper_Clr_ES2_RTMSetClrADCErr(SYS_ADCErrors_t *pADC12Err, SYS_ADCErrors_t *pADC34Err)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M18_AdcErrorClrRegUnion_t AdcErrorClr;

    AdcErrorClr.val_u32 = 0x0;
    if (pADC12Err != NULL)
    {
        // ADC12
        AdcErrorClr.bits_st.RegCrcErrorFlagAdc12Clr = (uint8_t)pADC12Err->ADCRegCrcErr;
        AdcErrorClr.bits_st.SupplyLowErrorFlag1V8Adc12Clr = (uint8_t)pADC12Err->ADCSupply1v8LowErr;
        AdcErrorClr.bits_st.HardClippingFlagPersistentAdc2Clr = (uint8_t)pADC12Err->ADCn1HardClippingErr;
        AdcErrorClr.bits_st.HardClippingFlagPersistentAdc1Clr = (uint8_t)pADC12Err->ADCn0HardClippingErr;
        AdcErrorClr.bits_st.CalErrorFlagPersistentAdc2Clr = (uint8_t)pADC12Err->ADCn1CalErr;
        AdcErrorClr.bits_st.CalErrorFlagPersistentAdc1Clr = (uint8_t)pADC12Err->ADCn0CalErr;
    }
    if (pADC34Err != NULL)
    {
        // ADC34
        AdcErrorClr.bits_st.RegCrcErrorFlagAdc34Clr = (uint8_t)pADC34Err->ADCRegCrcErr;
        AdcErrorClr.bits_st.SupplyLowErrorFlag1V8Adc34Clr = (uint8_t)pADC34Err->ADCSupply1v8LowErr;
        AdcErrorClr.bits_st.HardClippingFlagPersistentAdc4Clr = (uint8_t)pADC34Err->ADCn1HardClippingErr;
        AdcErrorClr.bits_st.HardClippingFlagPersistentAdc3Clr = (uint8_t)pADC34Err->ADCn0HardClippingErr;
        AdcErrorClr.bits_st.CalErrorFlagPersistentAdc4Clr = (uint8_t)pADC34Err->ADCn1CalErr;
        AdcErrorClr.bits_st.CalErrorFlagPersistentAdc3Clr = (uint8_t)pADC34Err->ADCn0CalErr;
    }
    retVal = BC_SPI_Write(e_SYS_ISM, R2M18_ADC_ERROR_CLR_REG_U16, AdcErrorClr.val_u32);
    return retVal;
}

static BC_ERRCODE Helper_Set_ES2_RTMSetClrADCErr(SYS_ADCErrors_t *pADC12Err, SYS_ADCErrors_t *pADC34Err)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M18_AdcErrorSetRegUnion_t AdcErrorSet;

    AdcErrorSet.val_u32 = 0x0;
    if (pADC12Err != NULL)
    {
        // ADC12
        AdcErrorSet.bits_st.RegCrcErrorFlagAdc12Set = (uint8_t)pADC12Err->ADCRegCrcErr;
        AdcErrorSet.bits_st.SupplyLowErrorFlag1V8Adc12Set = (uint8_t)pADC12Err->ADCSupply1v8LowErr;
        AdcErrorSet.bits_st.HardClippingFlagPersistentAdc2Set = (uint8_t)pADC12Err->ADCn1HardClippingErr;
        AdcErrorSet.bits_st.HardClippingFlagPersistentAdc1Set = (uint8_t)pADC12Err->ADCn0HardClippingErr;
        AdcErrorSet.bits_st.CalErrorFlagPersistentAdc2Set = (uint8_t)pADC12Err->ADCn1CalErr;
        AdcErrorSet.bits_st.CalErrorFlagPersistentAdc1Set = (uint8_t)pADC12Err->ADCn0CalErr;
    }
    if (pADC34Err != NULL)
    {
        // ADC34
        AdcErrorSet.bits_st.RegCrcErrorFlagAdc34Set = (uint8_t)pADC34Err->ADCRegCrcErr;
        AdcErrorSet.bits_st.SupplyLowErrorFlag1V8Adc34Set = (uint8_t)pADC34Err->ADCSupply1v8LowErr;
        AdcErrorSet.bits_st.HardClippingFlagPersistentAdc4Set = (uint8_t)pADC34Err->ADCn1HardClippingErr;
        AdcErrorSet.bits_st.HardClippingFlagPersistentAdc3Set = (uint8_t)pADC34Err->ADCn0HardClippingErr;
        AdcErrorSet.bits_st.CalErrorFlagPersistentAdc4Set = (uint8_t)pADC34Err->ADCn1CalErr;
        AdcErrorSet.bits_st.CalErrorFlagPersistentAdc3Set = (uint8_t)pADC34Err->ADCn0CalErr;
    }
    retVal = BC_SPI_Write(e_SYS_ISM, R2M18_ADC_ERROR_SET_REG_U16, AdcErrorSet.val_u32);
    return retVal;
}

// This API configs all functional safety errors for ADC module.
BC_ERRCODE HAL_ES2_ISM_MaskRTMSetClrADCErr(ISM_ErrCmd_e CmdReg, SYS_ADCErrors_t *pADC12Err, SYS_ADCErrors_t *pADC34Err)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;

    if ((pADC12Err == NULL) && (pADC34Err == NULL))
    {
        retVal = BC_ERR_ISM_PTR_ADDR_NULL;
    }
    else
    {
        /*Both should be NULL*/
        switch (CmdReg)
        {
        case e_ISM_ERR_OP_MASK_ERR:
        case e_ISM_ERR_OP_UNMASK_ERR:
            // ADC module Mask Error
            retVal = Helper_Msk_ES2_RTMSetClrADCErr(CmdReg, pADC12Err, pADC34Err);
            break;
        case e_ISM_ERR_OP_MONITOR_ERR:
            // ADC module monitor error
            retVal = Helper_Mon_ES2_RTMSetClrADCErr(pADC12Err, pADC34Err);
            break;
        case e_ISM_ERR_OP_CLEAR_ERR:
            // ADC module Error Clear(These are auto clear registers so no need of Read and Write check)
            retVal = Helper_Clr_ES2_RTMSetClrADCErr(pADC12Err, pADC34Err);
            break;
        case e_ISM_ERR_OP_SET_ERR:
            // ADC module Set Error(These are auto clear registers so no need of Read and Write check)
            retVal = Helper_Set_ES2_RTMSetClrADCErr(pADC12Err, pADC34Err);
            break;
        default:
            retVal = BC_ERR_INPUTOUTOFRANGE;
            break;
        }
    }
    return retVal;
}

// This API resets all ISM error and error counter.
BC_ERRCODE HAL_ES2_ISM_ResetISMErr(BOOL UseGPIOErrorReset, BOOL ResetStatusWDT, BOOL ResetFTTIWDT, BOOL ResetErrCounters)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M18_IsmErrorMcuResetUnion_t IsmErrorMcuReset;

    // Reset the WDT, FTTI WDT and Counters by setting 1 via SPI and GPIO
    // ISM Reset via GPIO pin
    if (UseGPIOErrorReset == TRUE)
    {
        retVal = PLF_HIO_SetIO(e_SYS_ERRORRESET, UseGPIOErrorReset); // GPIOErrorReset
        // solved artf759351. Errorreset needs to be set low after 1 us
        if (retVal == BC_ERR_NOERROR)
        {
            retVal = PLF_TM_Sleep(1u);
            if (retVal == BC_ERR_NOERROR)
            {
                retVal = PLF_HIO_SetIO(e_SYS_ERRORRESET, FALSE);
            }
        }
    }
    else // ISM Reset via SPI register
    {    // This is auto clear register so no need of Read and Write check
        IsmErrorMcuReset.val_u32 = 0x0;
        IsmErrorMcuReset.bits_st.ResetErrorStatusWdt = (uint8_t)ResetStatusWDT;     // WDT Reset status
        IsmErrorMcuReset.bits_st.ResetErrorFttiWdt = (uint8_t)ResetFTTIWDT;         // FTTI WDT Reset
        IsmErrorMcuReset.bits_st.ResetErrorCountMcuSpi = (uint8_t)ResetErrCounters; // Reset counters
        IsmErrorMcuReset.bits_st.ResetErrorMcuSpi = 1u;                             // Always
        retVal = BC_SPI_Write(e_SYS_ISM, R2M18_ISM_ERROR_MCU_RESET_U16, IsmErrorMcuReset.val_u32);
    }
    return retVal;
}

// This API set the status of the startup sequence
BC_ERRCODE HAL_ES2_ISM_SetStartupStatus(ISM_StartupSeq_e SequenceID)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    uint8_t SeqIndex;
    uint8_t OldSeqValue = 0x0u;
    uint8_t NewSeqValue = 0x0u;
    R2M18_McuStartupStatusControlUnion_t McuStartupStatusControl;

    if (SequenceID >= e_ISM_STARTUP_SEQ_INVALID)
    {
        retVal = BC_ERR_INPUTOUTOFRANGE;
    }
    else
    {
        retVal = BC_SPI_Read(e_SYS_ISM, R2M18_MCU_STARTUP_STATUS_CONTROL_U16, &McuStartupStatusControl.val_u32);
        if (retVal == BC_ERR_NOERROR)
        {
            // Startup sequence configuration
            for (SeqIndex = 0; SeqIndex < (uint8_t)SequenceID; SeqIndex++)
            {
                OldSeqValue = (OldSeqValue | (0x1u << SeqIndex));
            }
            NewSeqValue = (OldSeqValue | (0x1u << SeqIndex));
            if ((McuStartupStatusControl.val_u32 & 0xFFu) == OldSeqValue)
            {
                McuStartupStatusControl.val_u32 = NewSeqValue;
                retVal = BC_SPI_WriteCheck(e_SYS_ISM, R2M18_MCU_STARTUP_STATUS_CONTROL_U16, McuStartupStatusControl.val_u32);
            }
            else
            {
                retVal = BC_ERR_ISM_STARTUP_SEQ_CONFIG_FAILED;
            }
        }
    }

    return retVal;
}

// This API set the RTM safety and Power down threshold
BC_ERRCODE HAL_ES2_ISM_SetErrCntThreshold(BOOL EnRTMErrCountReset, RTMSafetyErrCnttThreshold_t *pRTMSafetyErrThreshold, RFPowrDwnErrCntThreshold_t *pPowrDwnErrThreshold)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M18_RtmSafetyErrorControlUnion_t RtmSafetyErrorControl;
    R2M18_RfPowerDownControlUnion_t RfPowerDownControl;

    if ((pRTMSafetyErrThreshold == NULL) && (pPowrDwnErrThreshold == NULL))
    {
        retVal = BC_ERR_ISM_PTR_ADDR_NULL;
    }
    else
    {
        // RTM Safety poll count and max threshold configuration
        if (pRTMSafetyErrThreshold != NULL)
        {
            retVal = BC_SPI_Read(e_SYS_ISM, R2M18_RTM_SAFETY_ERROR_CONTROL_U16, &RtmSafetyErrorControl.val_u32);
            if (retVal == BC_ERR_NOERROR)
            {
                RtmSafetyErrorControl.bits_st.SafetyErrCountResetEn = (uint8_t)EnRTMErrCountReset;
                RtmSafetyErrorControl.bits_st.RtErrorPollCountValue = (uint8_t)pRTMSafetyErrThreshold->PollCount;
                RtmSafetyErrorControl.bits_st.RtmErrorSafetyCountMaxValue = (uint8_t)pRTMSafetyErrThreshold->MaxThresholdVal;
                retVal = BC_SPI_WriteCheck(e_SYS_ISM, R2M18_RTM_SAFETY_ERROR_CONTROL_U16, RtmSafetyErrorControl.val_u32);
            }
        }
        // RF Power down  poll count and max threshold configuration
        if ((retVal == BC_ERR_NOERROR) && (pPowrDwnErrThreshold != NULL))
        {
            retVal = BC_SPI_Read(e_SYS_ISM, R2M18_RF_POWER_DOWN_CONTROL_U16, &RfPowerDownControl.val_u32);
            if (retVal == BC_ERR_NOERROR)
            {
                if ((pPowrDwnErrThreshold->PollCount <= 15u) && (pPowrDwnErrThreshold->MaxThresholdVal <= 15u))
                {
                    RfPowerDownControl.bits_st.RfPowerDownFlagPollCountValue = (uint8_t)pPowrDwnErrThreshold->PollCount;
                    RfPowerDownControl.bits_st.RfPowerDownCountThreshold = (uint8_t)pPowrDwnErrThreshold->MaxThresholdVal;
                    retVal = BC_SPI_WriteCheck(e_SYS_ISM, R2M18_RF_POWER_DOWN_CONTROL_U16, RfPowerDownControl.val_u32);
                }
                else
                {
                    retVal = BC_ERR_INPUTOUTOFRANGE;
                }
            }
        }
    }
    return retVal;
}
static BC_ERRCODE Helper_ISM_FIT_ES2(void)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;

    BOOL ATBRegCRCErr;
    BOOL OTPRegCRCErr;
    BOOL ISMRegCRCErr;
    uint32_t TxFITErr = 0x0;
    uint32_t RxFITErr = 0x0;
    uint32_t ADCFITErr = 0x0;
    uint32_t ChirpFITErr = 0x0;
    uint32_t ModuleGrp1Err = 0x0;
    uint32_t ModuleGrp2Err = 0x0;
    uint32_t TxFITMask = 0x0;
    uint32_t RxFITMask = 0x0;
    uint32_t ADCFITMask = 0x0;
    uint32_t ChirpFITMask = 0x0;
    uint32_t ModuleGrp1FITMask = 0x0;
    uint32_t ModuleGrp2FITMask = 0x0;

    /* This function call the GetAppConfiguration() to find the disabled IPs(only Tx, Rx, CSI2 and LVDS IPs considered)
    This function create the mask for the disabled IPs and reserve bits of FIT status register. */
    retVal = CreatFITMask(&TxFITMask, &RxFITMask, &ADCFITMask, &ChirpFITMask, &ModuleGrp1FITMask, &ModuleGrp2FITMask);

    if (retVal == BC_ERR_NOERROR)
    {
        retVal = HAL_ES2_ISM_GetTxErrStatus(e_ISM_GET_FIT_STATUS, NULL, NULL, NULL, &TxFITErr);
        if (((TxFITErr | TxFITMask) != 0xFFFFFFFFu) && (retVal == BC_ERR_NOERROR))
        {
            retVal = BC_ERR_ISM_FIT_TX_STATUS_FAILED;
        }
    }
    if (retVal == BC_ERR_NOERROR)
    {
        retVal = HAL_ES2_ISM_GetRxErrStatus(e_ISM_GET_FIT_STATUS, NULL, NULL, NULL, NULL, &RxFITErr);
        if (((RxFITErr | RxFITMask) != 0xFFFFFFFFu) && (retVal == BC_ERR_NOERROR))
        {
            retVal = BC_ERR_ISM_FIT_RX_STATUS_FAILED;
        }
    }
    if (retVal == BC_ERR_NOERROR)
    {
        retVal = HAL_ES2_ISM_GetADCErrStatus(e_ISM_GET_FIT_STATUS, NULL, NULL, &ADCFITErr);
        if (((ADCFITErr | ADCFITMask) != 0xFFFFFFFFu) && (retVal == BC_ERR_NOERROR))
        {
            retVal = BC_ERR_ISM_FIT_ADC_STATUS_FAILED;
        }
    }
    if (retVal == BC_ERR_NOERROR)
    {
        retVal = HAL_ES2_ISM_GetChirpErrStatus(e_ISM_GET_FIT_STATUS, NULL, &ChirpFITErr);
        if (((ChirpFITErr | ChirpFITMask) != 0xFFFFFFFFu) && (retVal == BC_ERR_NOERROR))
        {
            retVal = BC_ERR_ISM_FIT_CHIRP_STATUS_FAILED;
        }
    }
    if (retVal == BC_ERR_NOERROR)
    {
        retVal = HAL_ES2_ISM_GetMClkLOISMOTPErrStatus(e_ISM_GET_FIT_STATUS, &OTPRegCRCErr, &ISMRegCRCErr, NULL, NULL, NULL, &ModuleGrp1Err);
        if (((ModuleGrp1Err | ModuleGrp1FITMask) != 0xFFFFFFFFu) && (retVal == BC_ERR_NOERROR))
        {
            retVal = BC_ERR_ISM_FIT_MCLK_LO_ISM_OTP_CC_STATUS_FAILED;
        }
    }
    if (retVal == BC_ERR_NOERROR)
    {
        retVal = HAL_ES2_ISM_GetSSBSerGBGLDOATBErr(e_ISM_GET_FIT_STATUS, &ATBRegCRCErr, NULL, NULL, NULL, NULL, &ModuleGrp2Err);
        if (((ModuleGrp2Err | ModuleGrp2FITMask) != 0xFFFFFFFFu) && (retVal == BC_ERR_NOERROR))
        {
            retVal = BC_ERR_ISM_FIT_SSB_SER_GB_GLDO_ATB_STATUS_FAILED;
        }
    }
    return retVal;
}

// This API perform the hardware Fault Inject Test(FIT).
BC_ERRCODE HAL_ES2_ISM_FIT(void)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    /*
    1.	SPI Reset MCU
    2.	Check the  error n pin it should be high
    3.	Set force error IsmOsmTestForceError = 1.
    4.	Wait for may be 10 clock cycles (not required since SPI write will take almost 32 clocks to happen )
    5.	Check the  error_n pin it should be low and
    6.	Remove force error IsmOsmTestForceError = 0.
    7.	Set reset error IsmOsmTestResetError = 1.
    8.	Check error n pin it should be high
    9.	Remove reset error IsmOsmTestResetError = 0.
    10.	Check ism_test_complete == 3,  IsmTestComplete = 1, and all the  power down and rtm flags
    11.	If FIT is completed check all the enabled fit status registers
    */
    /* SPI MCU reset / can use the Reset pin also ? */
    /* clearing all the error and counters  */
    retVal = HAL_ES2_ISM_ResetISMErr(FALSE, TRUE, TRUE, TRUE);
    if (retVal == BC_ERR_NOERROR)
    {
        retVal = Helper_ISMSetForceError();
    }
    if (retVal == BC_ERR_NOERROR)
    {
        retVal = Helper_ISMSetClrForceResetErr();
    }

    if (retVal == BC_ERR_NOERROR)
    {
        retVal = Helper_ISMRemoveResetErr();
    }
    if (retVal == BC_ERR_NOERROR)
    {
        retVal = Helper_ISMCheckFitErr();
    }
    /* Check all the FIT Status registers */
    if (retVal == BC_ERR_NOERROR)
    {
        retVal = Helper_ISM_FIT_ES2();
    }
    return retVal;
}

// This API to perform interface toggle test on Barracuda pin.
BC_ERRCODE HAL_ES2_ISM_InterfaceToggleTest(SYS_ExtPinID_e PinId, BOOL Direction)
{
    BC_ERRCODE retValTmp, retVal = BC_ERR_NOERROR;
    R2M18_LoopBackTestRegUnion_t LoopBackTest;

    retVal = BC_SPI_Read(e_SYS_ISM, R2M18_LOOP_BACK_TEST_REG_U16, &LoopBackTest.val_u32);
    if (retVal == BC_ERR_NOERROR)
    {
        /* Set GPIO loopback test enable test register to correct input/output states
         * 1 = BC pad is input state, 0 = output state */
        LoopBackTest.bits_st.ErrorResetDir = TRUE;
        LoopBackTest.bits_st.ErrorNDir = FALSE;
        LoopBackTest.bits_st.ReadyIntDir = FALSE;
        LoopBackTest.bits_st.ChirpStartDir = TRUE;
        LoopBackTest.bits_st.Tx1IPsDir = TRUE;
        LoopBackTest.bits_st.Tx1QPsDir = TRUE;
        LoopBackTest.bits_st.Tx2IPsDir = TRUE;
        LoopBackTest.bits_st.Tx2QPsDir = TRUE;
        LoopBackTest.bits_st.Tx3IPsDir = TRUE;
        LoopBackTest.bits_st.Tx3QPsDir = TRUE;

        /* enable Loopback test, this applies also above set IO directions to Baracuda */
        LoopBackTest.bits_st.LoopBackTestEn = 1U;

        switch (PinId)
        {
        case e_SYS_ERRORRESET:
        case e_SYS_CHIRPSTART_IN_PAD:
        case e_SYS_MCUINT_CHIRPSTART_OUT_PAD:
        case e_SYS_ERRORN:
        case e_SYS_TX1_I_PS:
        case e_SYS_TX2_I_PS:
            retVal = Helper_TglTstERstChrStErNTx(PinId, Direction, LoopBackTest.val_u32);
            break;
        case e_SYS_TX3_I_PS:
        case e_SYS_TX1_Q_PS:
        case e_SYS_TX2_Q_PS:
        case e_SYS_TX3_Q_PS:
            retVal = Helper_TglTstTxTxQPs(PinId, Direction, LoopBackTest.val_u32);
            break;
        case e_SYS_ALL_BC_PINS:
            retVal = Helper_TglTstAllPinsSet1(LoopBackTest.val_u32);
            if (retVal == BC_ERR_NOERROR)
            {
                retVal = Helper_TglTstAllPinsSet2(LoopBackTest.val_u32);
            }

            break;
        default:
            retVal = BC_ERR_INPUTOUTOFRANGE;
            break;
        }
       
        /* Disable Loopback test, also in error case. No need to readback the existing register value before clearing LoopBackTestEn since all other bits are don't care once loopback test is disabled */
        LoopBackTest.bits_st.LoopBackTestEn = 0;
        retValTmp = BC_SPI_Write(e_SYS_ISM, R2M18_LOOP_BACK_TEST_REG_U16, LoopBackTest.val_u32);
        if (retValTmp == BC_ERR_NOERROR)
        {
            R2M18_LoopBackTestRegUnion_t LoopBackTestReadBack;
            retValTmp = BC_SPI_Read(e_SYS_ISM, R2M18_LOOP_BACK_TEST_REG_U16, &LoopBackTestReadBack.val_u32);
            if (retValTmp == BC_ERR_NOERROR)
            {
                if (LoopBackTestReadBack.bits_st.LoopBackTestEn != LoopBackTest.bits_st.LoopBackTestEn)
                {
                    retValTmp = BC_ERR_ISM_DISABLE_LB_TOGGLE_TEST_FAILED;
                }
            }
        }
        if (retVal == BC_ERR_NOERROR)
        {
            retVal = retValTmp;
        }
    }
    return retVal;
}

// This API to config the FTTI WDT and Status WDT.
BC_ERRCODE HAL_ES2_ISM_ConfigFTTIWDT(ISM_ConfigWDT_t *pConfigFTTIWDT, ISM_ConfigWDT_t *pConfigStatusWDT)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M18_StatusFttiWdtCntrlUnion_t FttiWdtCntrl;
    R2M18_FttiWdtCountUnion_t FttiWdtCount;
    R2M18_StatusWdtCountUnion_t StatusWdtCount;

    if ((pConfigFTTIWDT == NULL) && (pConfigStatusWDT == NULL))
    {
        retVal = BC_ERR_ISM_PTR_ADDR_NULL;
    }
    else
    { /*FTTI WDT and WDT configuration*/
        retVal = BC_SPI_Read(e_SYS_ISM, R2M18_STATUS_FTTI_WDT_CNTRL_U16, &FttiWdtCntrl.val_u32);
        if (retVal == BC_ERR_NOERROR)
        {
            /*FTTI WDT configuration and checked 4 bit max range for Base counter for status FTTI WDT*/
            if (pConfigFTTIWDT != NULL)
            {
                if (pConfigFTTIWDT->WDTTimePeriod > 0.0f)
                {
                    // set the  watchdog timer interval period value
                    FttiWdtCntrl.bits_st.FttiWdtCountBase = 0x0u; // Default set to 40MHz;
                    // select WDT timer modes continuous(every chirp sequence) or Moonshot
                    FttiWdtCntrl.bits_st.FttiWdtMode = (uint8_t)pConfigFTTIWDT->WDTMode;
                    // Enable or disable FTTI WDT
                    FttiWdtCntrl.bits_st.FttiWdtEn = (uint8_t)pConfigFTTIWDT->EnWDT;
                    // Compute the FttiWdt period
                    FttiWdtCount.bits_st.FttiWdtCountValue = SYS_CONVERT_TIMEUS_TO_40MHZCYCLE(pConfigFTTIWDT->WDTTimePeriod);
                    retVal = BC_SPI_WriteCheck(e_SYS_ISM, R2M18_FTTI_WDT_COUNT_U16, FttiWdtCount.val_u32);
                }
                else
                {
                    retVal = BC_ERR_INPUTOUTOFRANGE;
                }
            }
            /*WDT configuration*/
            if ((retVal == BC_ERR_NOERROR) && (pConfigStatusWDT != NULL))
            {
                if (pConfigStatusWDT->WDTTimePeriod > 0.0f)
                {
                    // set the  watchdog timer interval period value
                    FttiWdtCntrl.bits_st.StatusWdtCountBase = 0x0u; // Default set to 40MHz
                    // select WDT timer modes continuous(every chirp sequence) or Moonshot
                    FttiWdtCntrl.bits_st.StatusWdtMode = (uint8_t)pConfigStatusWDT->WDTMode;
                    // Enable or disable WDT
                    FttiWdtCntrl.bits_st.StatusWdtEn = (uint8_t)pConfigStatusWDT->EnWDT;

                    // Compute the Wdt period
                    StatusWdtCount.bits_st.StatusWdtCountValue = SYS_CONVERT_TIMEUS_TO_40MHZCYCLE(pConfigStatusWDT->WDTTimePeriod);
                    retVal = BC_SPI_WriteCheck(e_SYS_ISM, R2M18_STATUS_WDT_COUNT_U16, StatusWdtCount.val_u32);
                }
                else
                {
                    retVal = BC_ERR_INPUTOUTOFRANGE;
                }
            }
            if (retVal == BC_ERR_NOERROR)
            {
                retVal = BC_SPI_WriteCheck(e_SYS_ISM, R2M18_STATUS_FTTI_WDT_CNTRL_U16, FttiWdtCntrl.val_u32);
            }
        }
    }
    return retVal;
}

/*Configuration of GPIO Input and Output Mode*/
static BC_ERRCODE ConfigGPIOInputOutputMode(BOOL Direction, uint8_t PinDataPos, SYS_ExtPinID_e HostPinID, uint32_t LoopBackTestValue)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;

    // Direction:Input mode
    if (Direction == TRUE)
    { /*Configuration of GPIO Input Mode*/
        retVal = ConfigGPIOInputMode(PinDataPos, HostPinID, LoopBackTestValue);
    } // Direction:Output-Mode
    else
    { /*Configuration of GPIO Output Mode*/
        retVal = ConfigGPIOOutputMode(PinDataPos, HostPinID, LoopBackTestValue);
    }

    return retVal;
}

/*Configuration of GPIO Input Mode*/
static BC_ERRCODE ConfigGPIOInputMode(uint8_t PinDataPos, SYS_ExtPinID_e HostPinID, uint32_t LoopBackTestValue)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M18_LoopBackTestRegUnion_t LoopBackTestReg;
    uint32_t TmpData = 1u;
    uint32_t One32u = 1u;
    uint32_t LoopBackTestData;
    LoopBackTestReg.val_u32 = LoopBackTestValue;
    // set the Direction of data and enable loop back test mode
    retVal = BC_SPI_Write(e_SYS_ISM, R2M18_LOOP_BACK_TEST_REG_U16, LoopBackTestReg.val_u32);

    // Write the a data (1) from host via GPIO.
    //  Read back spi register value for correctness check
    if (retVal == BC_ERR_NOERROR)
    {
        retVal = BC_SPI_Read(e_SYS_ISM, R2M18_LOOP_BACK_TEST_REG_U16, &TmpData);
        if (((TmpData & 0xFFFFF800u) != (LoopBackTestReg.val_u32 & 0xFFFFF800u)) &&
            (retVal != BC_ERR_NOERROR))
        {
            retVal = BC_ERR_SPI_WRTCHECKFAIL;
        }
    }
    if (retVal == BC_ERR_NOERROR)
    {
        retVal = PLF_HIO_SetIO(HostPinID, TRUE);
    }
    // Read the Data from ISM register space.
    if (retVal == BC_ERR_NOERROR)
    {
        retVal = BC_SPI_Read(e_SYS_ISM, R2M18_LOOP_BACK_TEST_REG_U16, &LoopBackTestData);
    }
    // Compare the both result of GPIO input value and ISM register value and it should be same otherwise test failed
    if (retVal == BC_ERR_NOERROR)
    { // GPIO Set value high(TRUE)
        if (((LoopBackTestData >> (uint32_t)PinDataPos) & One32u) != One32u)
        {
            retVal = BC_ERR_ISM_INPUTMODE_TOGGLE_TEST_FAILED;
        }
    }
    // Write the a data (0) from host via GPIO.
    if (retVal == BC_ERR_NOERROR)
    { // Set the pin to Low(FALSE)
        retVal = PLF_HIO_SetIO(HostPinID, FALSE);
    }
    // Read the Data from ISM register space.
    if (retVal == BC_ERR_NOERROR)
    {
        retVal = BC_SPI_Read(e_SYS_ISM, R2M18_LOOP_BACK_TEST_REG_U16, &LoopBackTestData);
    }
    // Compare the both result of GPIO input value and ISM register value and it should be same otherwise test failed
    if (retVal == BC_ERR_NOERROR)
    { // GPIO Set value low (0)
        if (((LoopBackTestData >> (uint32_t)PinDataPos) & One32u) != 0u)
        {
            retVal = BC_ERR_ISM_INPUTMODE_TOGGLE_TEST_FAILED;
            ;
        }
    }

    return retVal;
}

/*Configuration of GPIO Output Mode*/
static BC_ERRCODE ConfigGPIOOutputMode(uint8_t PinDataPos, SYS_ExtPinID_e HostPinID, uint32_t LoopBackTestValue)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M18_LoopBackTestRegUnion_t LoopBackTestReg;
    BOOL GPIOPin_High;
    uint32_t TmpData = 1u;
    uint32_t One32u = 1u;
    LoopBackTestReg.val_u32 = LoopBackTestValue;
    LoopBackTestReg.val_u32 |= (One32u << (uint32_t)PinDataPos); /* set pin state to HIGH */
    retVal = BC_SPI_Write(e_SYS_ISM, R2M18_LOOP_BACK_TEST_REG_U16, LoopBackTestReg.val_u32);
    if (retVal == BC_ERR_NOERROR)
    {
        retVal = BC_SPI_Read(e_SYS_ISM, R2M18_LOOP_BACK_TEST_REG_U16, &TmpData);
        if (((TmpData & 0xFFFFF800u) != (LoopBackTestReg.val_u32 & 0xFFFFF800u)) &&
            (retVal != BC_ERR_NOERROR))
        {
            retVal = BC_ERR_SPI_WRTCHECKFAIL;
        }
    }

    // Read the a data (1) from host via GPIO.
    if (retVal == BC_ERR_NOERROR)
    {
        retVal = PLF_HIO_GetIO(HostPinID, &GPIOPin_High); // Host pin required !!
    }
    // Compare the both result of GPIO input value and ISM register value and it should be same otherwise test failed
    if (retVal == BC_ERR_NOERROR)
    { // GPIO Set value high(TRUE)
        if (TRUE != GPIOPin_High)
        {
            retVal = BC_ERR_ISM_OUTPUTMODE_TOGGLE_TEST_FAILED;
        }
    }
    // Write the a data (0) to ISM data register.
    if (retVal == BC_ERR_NOERROR)
    {
        LoopBackTestReg.val_u32 &= (~(One32u << (uint32_t)PinDataPos));
        retVal = BC_SPI_WriteCheck(e_SYS_ISM, R2M18_LOOP_BACK_TEST_REG_U16, LoopBackTestReg.val_u32);
    }
    // Read the a data (0) from host via GPIO.
    if (retVal == BC_ERR_NOERROR)
    {
        retVal = PLF_HIO_GetIO(HostPinID, &GPIOPin_High);
    }
    // Compare the both result of GPIO input value and ISM register value and it should be same otherwise test failed
    if (retVal == BC_ERR_NOERROR)
    { // GPIO pin data should be 0
        if (FALSE != GPIOPin_High)
        {
            retVal = BC_ERR_ISM_OUTPUTMODE_TOGGLE_TEST_FAILED;
        }
    }

    return retVal;
}

/* Local Functions */
/* This function call the GetAppConfiguration() to find the disabled IPs(only Tx, Rx, CSI2 and LVDS IPs considered).
This function create the mask for the disabled IPs and reserve bits of FIT status register. */
static BC_ERRCODE CreatTxFITMask(uint32_t *pTxFITMask, SYS_IPList_t *pAppConfig)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M18_FitStatusTxRegUnion_t FitStatusTx;
    uint32_t ReadValTX;

    ErrCode = BC_SPI_Read(e_SYS_ISM, R2M18_TX_ERROR_MASK_REG_U16, &ReadValTX);
    if (ErrCode == BC_ERR_NOERROR)
    {
        /* TX no issue for big endian and little endian  since only Reserved0 bit  */
        FitStatusTx.val_u32 = 0u;
        FitStatusTx.bits_st.Reserved0 = 0x01u;
        FitStatusTx.bits_st.Reserved1 = 0x01u;
        if (pAppConfig->PR == FALSE)
        {
            FitStatusTx.bits_st.PrErrorFlagTx1FitStatus = 1u;
            FitStatusTx.bits_st.PrErrorFlagTx2FitStatus = 1u;
            FitStatusTx.bits_st.PrErrorFlagTx3FitStatus = 1u;
        }
        if (pAppConfig->TX1 == FALSE)
        {
            FitStatusTx.bits_st.BbErrorFlagTx1FitStatus = 1u;
            FitStatusTx.bits_st.PrErrorFlagTx1FitStatus = 1u;
            FitStatusTx.bits_st.RegCrcErrorFlagTx1FitStatus = 1u;
            FitStatusTx.bits_st.RfLevelHighErrorFlagTx1FitStatus = 1u;
            FitStatusTx.bits_st.RfLevelLowErrorFlagTx1FitStatus = 1u;
            FitStatusTx.bits_st.RfLevelMaxErrorFlagTx1FitStatus = 1u;
            FitStatusTx.bits_st.RfLevelMinErrorFlagTx1FitStatus = 1u;
            FitStatusTx.bits_st.SupplyLowErrorFlag1V8Tx1FitStatus = 1u;
            FitStatusTx.bits_st.SupplyLowErrorFlag1V1Tx1FitStatus = 1u;
            FitStatusTx.bits_st.TempErrorFlagTx1FitStatus = 1u;
        }
        if (pAppConfig->TX2 == FALSE)
        {
            FitStatusTx.bits_st.BbErrorFlagTx2FitStatus = 1u;
            FitStatusTx.bits_st.PrErrorFlagTx2FitStatus = 1u;
            FitStatusTx.bits_st.RegCrcErrorFlagTx2FitStatus = 1u;
            FitStatusTx.bits_st.RfLevelHighErrorFlagTx2FitStatus = 1u;
            FitStatusTx.bits_st.RfLevelLowErrorFlagTx2FitStatus = 1u;
            FitStatusTx.bits_st.RfLevelMaxErrorFlagTx2FitStatus = 1u;
            FitStatusTx.bits_st.RfLevelMinErrorFlagTx2FitStatus = 1u;
            FitStatusTx.bits_st.SupplyLowErrorFlag1V8Tx2FitStatus = 1u;
            FitStatusTx.bits_st.SupplyLowErrorFlag1V1Tx2FitStatus = 1u;
            FitStatusTx.bits_st.TempErrorFlagTx2FitStatus = 1u;
        }
        if (pAppConfig->TX3 == FALSE)
        {
            FitStatusTx.bits_st.BbErrorFlagTx3FitStatus = 1u;
            FitStatusTx.bits_st.PrErrorFlagTx3FitStatus = 1u;
            FitStatusTx.bits_st.RegCrcErrorFlagTx3FitStatus = 1u;
            FitStatusTx.bits_st.RfLevelHighErrorFlagTx3FitStatus = 1u;
            FitStatusTx.bits_st.RfLevelLowErrorFlagTx3FitStatus = 1u;
            FitStatusTx.bits_st.RfLevelMaxErrorFlagTx3FitStatus = 1u;
            FitStatusTx.bits_st.RfLevelMinErrorFlagTx3FitStatus = 1u;
            FitStatusTx.bits_st.SupplyLowErrorFlag1V8Tx3FitStatus = 1u;
            FitStatusTx.bits_st.SupplyLowErrorFlag1V1Tx3FitStatus = 1u;
            FitStatusTx.bits_st.TempErrorFlagTx3FitStatus = 1u;
        }
        *pTxFITMask = (FitStatusTx.val_u32 | ReadValTX);
    }
    return ErrCode;
}
static BC_ERRCODE CreatRxFITMask(uint32_t *pRxFITMask, SYS_IPList_t *pAppConfig)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M18_FitStatusRxRegUnion_t FitStatusRx;
    uint32_t ReadValRX;

    ErrCode = BC_SPI_Read(e_SYS_ISM, R2M18_RX_ERROR_MASK_REG_U16, &ReadValRX);
    if (ErrCode == BC_ERR_NOERROR)
    {
        /* RX no issue for big endian and little endian  since no Reserved bit  */
        FitStatusRx.val_u32 = 0u;
        if (pAppConfig->RX1 == FALSE)
        {
            FitStatusRx.bits_st.BbErrorFlagRx1FitStatus = 1u;
            FitStatusRx.bits_st.LoLevelHighErrorFlagRx1FitStatus = 1u;
            FitStatusRx.bits_st.LoLevelLowErrorFlagRx1FitStatus = 1u;
            FitStatusRx.bits_st.LoLevelMaxErrorFlagRx1FitStatus = 1u;
            FitStatusRx.bits_st.LoLevelMinErrorFlagRx1FitStatus = 1u;
            FitStatusRx.bits_st.RegCrcErrorFlagRx1FitStatus = 1u;
            FitStatusRx.bits_st.SupplyLowErrorFlag1V1Rx1FitStatus = 1u;
            FitStatusRx.bits_st.SupplyLowErrorFlag1V8Rx1FitStatus = 1u;
        }
        if (pAppConfig->RX2 == FALSE)
        {
            FitStatusRx.bits_st.BbErrorFlagRx2FitStatus = 1u;
            FitStatusRx.bits_st.LoLevelHighErrorFlagRx2FitStatus = 1u;
            FitStatusRx.bits_st.LoLevelLowErrorFlagRx2FitStatus = 1u;
            FitStatusRx.bits_st.LoLevelMaxErrorFlagRx2FitStatus = 1u;
            FitStatusRx.bits_st.LoLevelMinErrorFlagRx2FitStatus = 1u;
            FitStatusRx.bits_st.RegCrcErrorFlagRx2FitStatus = 1u;
            FitStatusRx.bits_st.SupplyLowErrorFlag1V1Rx2FitStatus = 1u;
            FitStatusRx.bits_st.SupplyLowErrorFlag1V8Rx2FitStatus = 1u;
        }
        if (pAppConfig->RX3 == FALSE)
        {
            FitStatusRx.bits_st.BbErrorFlagRx3FitStatus = 1u;
            FitStatusRx.bits_st.LoLevelHighErrorFlagRx3FitStatus = 1u;
            FitStatusRx.bits_st.LoLevelLowErrorFlagRx3FitStatus = 1u;
            FitStatusRx.bits_st.LoLevelMaxErrorFlagRx3FitStatus = 1u;
            FitStatusRx.bits_st.LoLevelMinErrorFlagRx3FitStatus = 1u;
            FitStatusRx.bits_st.RegCrcErrorFlagRx3FitStatus = 1u;
            FitStatusRx.bits_st.SupplyLowErrorFlag1V1Rx3FitStatus = 1u;
            FitStatusRx.bits_st.SupplyLowErrorFlag1V8Rx3FitStatus = 1u;
        }
        if (pAppConfig->RX4 == FALSE)
        {
            FitStatusRx.bits_st.BbErrorFlagRx4FitStatus = 1u;
            FitStatusRx.bits_st.LoLevelHighErrorFlagRx4FitStatus = 1u;
            FitStatusRx.bits_st.LoLevelLowErrorFlagRx4FitStatus = 1u;
            FitStatusRx.bits_st.LoLevelMaxErrorFlagRx4FitStatus = 1u;
            FitStatusRx.bits_st.LoLevelMinErrorFlagRx4FitStatus = 1u;
            FitStatusRx.bits_st.RegCrcErrorFlagRx4FitStatus = 1u;
            FitStatusRx.bits_st.SupplyLowErrorFlag1V1Rx4FitStatus = 1u;
            FitStatusRx.bits_st.SupplyLowErrorFlag1V8Rx4FitStatus = 1u;
        }
        *pRxFITMask = (FitStatusRx.val_u32 | ReadValRX);
    }
    return ErrCode;
}
static BC_ERRCODE CreatChirpADCFITMask(uint32_t *pChirpFITMask, uint32_t *pADCFITMask, SYS_IPList_t *pAppConfig)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M18_FitStatusChirpRegUnion_t FitStatusChirp;
    R2M18_FitStatusAdcRegUnion_t FitStatusAdc;
    uint32_t ReadValChirp;
    uint32_t ReadValADC;

    ErrCode = BC_SPI_Read(e_SYS_ISM, R2M18_CHIRP_ERROR_MASK_REG_U16, &ReadValChirp);
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_SPI_Read(e_SYS_ISM, R2M18_ADC_ERROR_MASK_REG_U16, &ReadValADC);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        /* to solve issue for big endian and little endian  */
        FitStatusChirp.val_u32 = 0xFFFFFFFFu;
        if (pAppConfig->CAFC == TRUE)
        {
            FitStatusChirp.bits_st.RegCrcErrorFlagChirpFitStatus = 0u;
            FitStatusChirp.bits_st.LockStepErrorFlagChirpFitStatus = 0u;
            FitStatusChirp.bits_st.LevelMinErrorFlagChirpFitStatus = 0u;
            FitStatusChirp.bits_st.LevelMaxErrorFlagChirpFitStatus = 0u;
            FitStatusChirp.bits_st.LevelLowErrorFlagChirpFitStatus = 0u;
            FitStatusChirp.bits_st.LevelHighErrorFlagChirpFitStatus = 0u;
            FitStatusChirp.bits_st.InterfaceStuckErrorFlagChirpFitStatus = 0u;
            FitStatusChirp.bits_st.AafcErrorFlagChirpFitStatus = 0u;
            FitStatusChirp.bits_st.AafcCalTimeoutErrorFlagChirpFitStatus = 0u;
            FitStatusChirp.bits_st.VtuneLowErrorFlagChirpFitStatus = 0u;
            FitStatusChirp.bits_st.VtuneHighErrorFlagChirpFitStatus = 0u;
            FitStatusChirp.bits_st.VcoFreq480ErrorFlagChirpFitStatus = 0u;
            FitStatusChirp.bits_st.UnlockErrorFlagChirpFitStatus = 0u;
            FitStatusChirp.bits_st.TempErrorFlagChirpFitStatus = 0u;
            FitStatusChirp.bits_st.SupplyLowErrorFlagVco1V8ChirpFitStatus = 0u;
            FitStatusChirp.bits_st.SupplyLowErrorFlagPll1V8ChirpFitStatus = 0u;
            FitStatusChirp.bits_st.SupplyLowErrorFlagDig1V1ChirpFitStatus = 0u;
        }
        *pChirpFITMask = (FitStatusChirp.val_u32 | ReadValChirp);

        /* ADC no issue for big endian and little endian  since only Reserved0  */
        FitStatusAdc.val_u32 = 0u;
        FitStatusAdc.bits_st.Reserved0 = 0xFFFFFu;
        *pADCFITMask = (FitStatusAdc.val_u32 | ReadValADC);
    }
    return ErrCode;
}
static BC_ERRCODE CreatGrp1Grp2FITMask(uint32_t *pGrp1FITMask, uint32_t *pGrp2FITMask, SYS_IPList_t *pAppConfig)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M18_FitStatusMcLoCcIsmOtpRegUnion_t FitStatusMcLoCcIsmOtp;
    R2M18_FitStatusSsbGbSerGldoAtbRegUnion_t FitStatusSsbGbSerGldoAtb;
    R2M00_IpLevelPonEnableUnion_t IpLevelPonEnable;
    uint32_t ReadValMCLOCCISMOTP;
    uint32_t ReadValSSBGBSERGLDOATB;
    ErrCode = BC_SPI_Read(e_SYS_CC, R2M00_IP_LEVEL_PON_ENABLE_U16, &IpLevelPonEnable.val_u32);
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_SPI_Read(e_SYS_ISM, R2M18_MC_LO_CC_ISM_OTP_ERROR_MASK_REG_U16, &ReadValMCLOCCISMOTP);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_SPI_Read(e_SYS_ISM, R2M18_SSB_GB_SER_GLDO_ATB_ERROR_MASK_REG_U16, &ReadValSSBGBSERGLDOATB);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        /* Below coding is to solve issue for big endian and little endian  */
        FitStatusMcLoCcIsmOtp.val_u32 = 0xFFFFFFFFu;
        FitStatusMcLoCcIsmOtp.bits_st.RegCrcErrorFlagOtpFitStatus = 0u;
        FitStatusMcLoCcIsmOtp.bits_st.RegCrcErrorFlagMcFitStatus = 0u;
        FitStatusMcLoCcIsmOtp.bits_st.RegCrcErrorFlagIsmFitStatus = 0u;
        FitStatusMcLoCcIsmOtp.bits_st.RegCrcErrorFlagInterfaceFitStatus = 0u;
        FitStatusMcLoCcIsmOtp.bits_st.RegCrcErrorFlagCcFitStatus = 0u;
        FitStatusMcLoCcIsmOtp.bits_st.RdSpiCrcErrorFlagFitStatus = 0u;
        FitStatusMcLoCcIsmOtp.bits_st.PllLockErrorFlagMcFitStatus = 0u;
        FitStatusMcLoCcIsmOtp.bits_st.PllLevelErrorFlagMcFitStatus = 0u;
        FitStatusMcLoCcIsmOtp.bits_st.PllFreqCalErrorFlagMcFitStatus = 0u;
        FitStatusMcLoCcIsmOtp.bits_st.MspcErrorFlagMcFitStatus = 0u;
        FitStatusMcLoCcIsmOtp.bits_st.LoiLevelMinErrorFlagInterfaceFitStatus = 0u;
        FitStatusMcLoCcIsmOtp.bits_st.LoiLevelMaxErrorFlagInterfaceFitStatus = 0u;
        FitStatusMcLoCcIsmOtp.bits_st.LoiLevelLowErrorFlagInterfaceFitStatus = 0u;
        FitStatusMcLoCcIsmOtp.bits_st.LoiLevelHighErrorFlagInterfaceFitStatus = 0u;
        FitStatusMcLoCcIsmOtp.bits_st.DigFreqErrorFlagMcFitStatus = 0u;
        if (pAppConfig->LOOUT == TRUE)
        {
            FitStatusMcLoCcIsmOtp.bits_st.BbLooutErrorFlagInterfaceFitStatus = 0u;
        }
        if (pAppConfig->LOIN == TRUE)
        {
            FitStatusMcLoCcIsmOtp.bits_st.BbLoinErrorFlagInterfaceFitStatus = 0u;
        }
        FitStatusMcLoCcIsmOtp.bits_st.WrSpiCrcErrorFlagFitStatus = 0u;
        FitStatusMcLoCcIsmOtp.bits_st.SupplyLowErrorFlag1V8McFitStatus = 0u;
        FitStatusMcLoCcIsmOtp.bits_st.SupplyLowErrorFlag1V1InterfaceFitStatus = 0u;
        FitStatusMcLoCcIsmOtp.bits_st.XoNoClockErrorFlagMcFitStatus = 0u;

        *pGrp1FITMask = (FitStatusMcLoCcIsmOtp.val_u32 | ReadValMCLOCCISMOTP);

        /* Below coding is to solve issue for big endian and little endian  */
        FitStatusSsbGbSerGldoAtb.val_u32 = 0xFFFFFFFFu;
        FitStatusSsbGbSerGldoAtb.bits_st.RegCrcErrorFlagAtbFitStatus = 0u;
        FitStatusSsbGbSerGldoAtb.bits_st.RegCrcErrorFlagGlobalBiasFitStatus = 0u;
        FitStatusSsbGbSerGldoAtb.bits_st.RegCrcErrorFlagGlobalLdoFitStatus = 0u;
        FitStatusSsbGbSerGldoAtb.bits_st.RegCrcErrorFlagSerFitStatus = 0u;
        FitStatusSsbGbSerGldoAtb.bits_st.RegCrcErrorFlagSsbModFitStatus = 0u;
        FitStatusSsbGbSerGldoAtb.bits_st.SupplyHighErrorFlag1V1GlobalLdoFitStatus = 0u;
        FitStatusSsbGbSerGldoAtb.bits_st.SupplyHighErrorFlag1V8GlobalLdoFitStatus = 0u;
        FitStatusSsbGbSerGldoAtb.bits_st.SupplyLowErrorFlag1V1Csi2FitStatus = 0u;
        FitStatusSsbGbSerGldoAtb.bits_st.SupplyLowErrorFlag1V1GlobalLdoFitStatus = 0u;
        FitStatusSsbGbSerGldoAtb.bits_st.SupplyLowErrorFlag1V1SerFitStatus = 0u;
        FitStatusSsbGbSerGldoAtb.bits_st.SupplyLowErrorFlag1V8GlobalBiasFitStatus = 0u;
        FitStatusSsbGbSerGldoAtb.bits_st.SupplyLowErrorFlag1V8GlobalLdoFitStatus = 0u;
        FitStatusSsbGbSerGldoAtb.bits_st.SupplyLowErrorFlag1V8SerFitStatus = 0u;
        FitStatusSsbGbSerGldoAtb.bits_st.SupplyLowErrorFlag1V8SsbModFitStatus = 0u;

        if (IpLevelPonEnable.bits_st.PonAtbEn == 0u)
        {
            FitStatusSsbGbSerGldoAtb.bits_st.RegCrcErrorFlagAtbFitStatus = 1u;
        }
        if (IpLevelPonEnable.bits_st.PonSsbmodEn == 0u)
        {
            FitStatusSsbGbSerGldoAtb.bits_st.RegCrcErrorFlagSsbModFitStatus = 1u;
            FitStatusSsbGbSerGldoAtb.bits_st.SupplyLowErrorFlag1V8SsbModFitStatus = 1u;
        }
        if (pAppConfig->MIPI == FALSE)
        {
            FitStatusSsbGbSerGldoAtb.bits_st.SupplyLowErrorFlag1V1Csi2FitStatus = 1u;
        }
        else
        {
            FitStatusSsbGbSerGldoAtb.bits_st.SupplyLowErrorFlag1V1SerFitStatus = 1u;
        }
        *pGrp2FITMask = (FitStatusSsbGbSerGldoAtb.val_u32 | ReadValSSBGBSERGLDOATB);
    }
    return ErrCode;
}
static BC_ERRCODE CreatFITMask(uint32_t *pTxFITMask, uint32_t *pRxFITMask, uint32_t *pADCFITMask, uint32_t *pChirpFITMask, uint32_t *pGrp1FITMask, uint32_t *pGrp2FITMask)
{
    SYS_IPList_t AppConfig;
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

    // instead of each bit write we can use the defines also.
    // e.g. reserve bit this will the mask 0xf8000000 0x00000000 0xfffff000 0xeec8c0c8 0xfe0098e0 0xffe008ee

    ErrCode = HAL_ES2_CC_GetAppConfiguration(&AppConfig, NULL);

    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = CreatTxFITMask(pTxFITMask, &AppConfig);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = CreatRxFITMask(pRxFITMask, &AppConfig);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = CreatChirpADCFITMask(pChirpFITMask, pADCFITMask, &AppConfig);
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = CreatGrp1Grp2FITMask(pGrp1FITMask, pGrp2FITMask, &AppConfig);
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_ISM_GetCalibrationStatus(SYS_CalibrationStatus_t *pCalibrationStatus, uint32_t *pModuleStatus)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M18_GlobalCalStatusUnion_t GlobalCalStatus;
    if ((pCalibrationStatus == NULL) && (pModuleStatus == NULL))
    {
        ErrCode = BC_ERR_ISM_PTR_ADDR_NULL;
    }
    else
    {
        ErrCode = BC_SPI_Read(e_SYS_ISM, R2M18_GLOBAL_CAL_STATUS_U16, &GlobalCalStatus.val_u32);
        if (ErrCode == BC_ERR_NOERROR)
        {
            if (pCalibrationStatus != NULL)
            {

                pCalibrationStatus->ChirpCalStatus = Helper_ISMValidateCalibStatus(GlobalCalStatus.bits_st.ChirpBusy, GlobalCalStatus.bits_st.ChirpError);
                pCalibrationStatus->LOICalStatus = Helper_ISMValidateCalibStatus(GlobalCalStatus.bits_st.LoiCalBusy, GlobalCalStatus.bits_st.LoiError);
                pCalibrationStatus->Rx4CalStatus = Helper_ISMValidateCalibStatus(GlobalCalStatus.bits_st.Rx3CalBusy, GlobalCalStatus.bits_st.Rx3Error);
                pCalibrationStatus->Rx3CalStatus = Helper_ISMValidateCalibStatus(GlobalCalStatus.bits_st.Rx2CalBusy, GlobalCalStatus.bits_st.Rx2Error);
                pCalibrationStatus->Rx2CalStatus = Helper_ISMValidateCalibStatus(GlobalCalStatus.bits_st.Rx1CalBusy, GlobalCalStatus.bits_st.Rx1Error);
                pCalibrationStatus->Rx1CalStatus = Helper_ISMValidateCalibStatus(GlobalCalStatus.bits_st.Rx0CalBusy, GlobalCalStatus.bits_st.Rx0Error);
                pCalibrationStatus->Tx3CalStatus = Helper_ISMValidateCalibStatus(GlobalCalStatus.bits_st.Tx2CalBusy, GlobalCalStatus.bits_st.Tx2Error);
                pCalibrationStatus->Tx2CalStatus = Helper_ISMValidateCalibStatus(GlobalCalStatus.bits_st.Tx1CalBusy, GlobalCalStatus.bits_st.Tx1Error);
                pCalibrationStatus->Tx1CalStatus = Helper_ISMValidateCalibStatus(GlobalCalStatus.bits_st.Tx0CalBusy, GlobalCalStatus.bits_st.Tx0Error);
                pCalibrationStatus->Tx3SafetyCalStatus = Helper_ISMValidateCalibStatus(GlobalCalStatus.bits_st.Tx2SafetyCalBusy, GlobalCalStatus.bits_st.Tx2SafetyError);
                pCalibrationStatus->Tx2SafetyCalStatus = Helper_ISMValidateCalibStatus(GlobalCalStatus.bits_st.Tx1SafetyCalBusy, GlobalCalStatus.bits_st.Tx1SafetyError);
                pCalibrationStatus->Tx1SafetyCalStatus = Helper_ISMValidateCalibStatus(GlobalCalStatus.bits_st.Tx0SafetyCalBusy, GlobalCalStatus.bits_st.Tx0SafetyError);
            }
            if (pModuleStatus != NULL)
            {
                *pModuleStatus = GlobalCalStatus.val_u32;
            }
        }
    }
    return ErrCode;
}

// This API reads error or warning status
BC_ERRCODE HAL_ES2_ISM_Get1stErrWarnStatus(ISM_GetFirstErrCmd_e CmdReg, ISM_FirstErrWarning_t *pFirstErrWarn)
{
    BC_ERRCODE retVal = BC_ERR_NOERROR;
    R2M18_FirstMaskedErrorInfoRegUnion_t FirstMaskedErrorInfo;
    R2M18_FirstMaskedWarningInfoRegUnion_t FirstMaskedWarningInfo;
    R2M18_FirstMaskedErrorStatusUnion_t FirstMaskedErrorStatus;
    R2M18_FirstMaskedWarningStatusUnion_t FirstMaskedWarningStatus;

    if (pFirstErrWarn != NULL)
    {
        switch (CmdReg)
        {
        case e_ISM_GET_FIRST_MASKED_ERR:
            retVal = BC_SPI_Read(e_SYS_ISM, R2M18_FIRST_MASKED_ERROR_INFO_REG_U16, &FirstMaskedErrorInfo.val_u32);
            if (retVal == BC_ERR_NOERROR)
            {
                pFirstErrWarn->ErrorModuleID = (uint8_t)FirstMaskedErrorInfo.bits_st.ErrorModuleIdFirstMaskedError;
                pFirstErrWarn->ErrInsideAcquisition = (BOOL)FirstMaskedErrorInfo.bits_st.ErrorOccuredInstanceFirstMaskedError;
                pFirstErrWarn->SequenceNum = (uint8_t)FirstMaskedErrorInfo.bits_st.SequenceNumFirstMaskedError;
                pFirstErrWarn->ChirpNum = (uint16_t)FirstMaskedErrorInfo.bits_st.ChirpNumberFirstMaskedError;
                pFirstErrWarn->ProfileNum = (uint8_t)FirstMaskedErrorInfo.bits_st.ProfileNumberFirstMaskedError;
                // Read Error Status
                retVal = BC_SPI_Read(e_SYS_ISM, R2M18_FIRST_MASKED_ERROR_STATUS_U16, &FirstMaskedErrorStatus.val_u32);
                if (retVal == BC_ERR_NOERROR)
                {
                    pFirstErrWarn->FirstErrorStatusDump = (uint32_t)FirstMaskedErrorStatus.val_u32;
                }
            }
            break;
        case e_ISM_GET_FIRST_MASKED_WAR:
            retVal = BC_SPI_Read(e_SYS_ISM, R2M18_FIRST_MASKED_WARNING_INFO_REG_U16, &FirstMaskedWarningInfo.val_u32);
            if (retVal == BC_ERR_NOERROR)
            {
                pFirstErrWarn->ErrorModuleID = (uint8_t)FirstMaskedWarningInfo.bits_st.ErrorModuleIdFirstMaskedWarning;
                pFirstErrWarn->ErrInsideAcquisition = (BOOL)FirstMaskedWarningInfo.bits_st.ErrorOccuredInstanceFirstMaskedWarning;
                pFirstErrWarn->SequenceNum = (uint8_t)FirstMaskedWarningInfo.bits_st.SequenceNumFirstMaskedWarning;
                pFirstErrWarn->ChirpNum = (uint16_t)FirstMaskedWarningInfo.bits_st.ChirpNumberFirstMaskedWarning;
                pFirstErrWarn->ProfileNum = (uint8_t)FirstMaskedWarningInfo.bits_st.ProfileNumberFirstMaskedWarning;
                // Read warning error Status
                retVal = BC_SPI_Read(e_SYS_ISM, R2M18_FIRST_MASKED_WARNING_STATUS_U16, &FirstMaskedWarningStatus.val_u32);
                if (retVal == BC_ERR_NOERROR)
                {
                    pFirstErrWarn->FirstErrorStatusDump = (uint32_t)FirstMaskedWarningStatus.val_u32;
                }
            }
            break;
        default:
            retVal = BC_ERR_INPUTOUTOFRANGE;
            break;
        }
    }
    else
    {
        retVal = BC_ERR_ISM_PTR_ADDR_NULL;
    }
    return retVal;
}

BC_ERRCODE HAL_ES2_ISM_CfgFirstErrWar(ISM_CHIRPSEQ_COUNTER_e ErrorClr, ISM_CHIRPSEQ_COUNTER_e WarningClr)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

    R2M18_FirstMaskedErrorWarningCtrlUnion_t FirstMaskedErrorWarningCtrl;
    if ((WarningClr >= e_ISM_CHIRPSEQ_COUNTER_INVALID) || (ErrorClr >= e_ISM_CHIRPSEQ_COUNTER_INVALID))
    {
        ErrCode = BC_ERR_ISM_INVALID_INPUT;
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        ErrCode = BC_SPI_Read(e_SYS_ISM, R2M18_FIRST_MASKED_ERROR_WARNING_CTRL_U16, &FirstMaskedErrorWarningCtrl.val_u32);
        if (ErrCode == BC_ERR_NOERROR)
        {
            FirstMaskedErrorWarningCtrl.bits_st.FirstMaskedErrorClrCtrl = (uint8_t)ErrorClr;
            FirstMaskedErrorWarningCtrl.bits_st.FirstMaskedWarningClrCtrl = (uint8_t)WarningClr;
            ErrCode = BC_SPI_WriteCheck(e_SYS_ISM, R2M18_FIRST_MASKED_ERROR_WARNING_CTRL_U16, FirstMaskedErrorWarningCtrl.val_u32);
        }
    }

    return ErrCode;
}

BC_ERRCODE HAL_ES2_ISM_ConfigLOIBBDMonitor(BOOL MonitorAlways)
{
     R2M18_McLoCcIsmOtpErrorMonRegUnion_t McLoCcIsmOtpErrorMon;

    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

    // Read current ISM Monitoring settings
    ErrCode = BC_SPI_Read(e_SYS_ISM, R2M18_MC_LO_CC_ISM_OTP_ERROR_MON_REG_U16, &McLoCcIsmOtpErrorMon.val_u32);

    // Write updated settings
    if (BC_ERR_NOERROR == ErrCode)
    {
        //Change monitoring period to always monitor
        McLoCcIsmOtpErrorMon.bits_st.BbLoinErrorFlagInterfaceMon = (uint8_t)MonitorAlways;
        McLoCcIsmOtpErrorMon.bits_st.BbLooutErrorFlagInterfaceMon = (uint8_t)MonitorAlways;
        ErrCode = BC_SPI_WriteCheck(e_SYS_ISM, R2M18_MC_LO_CC_ISM_OTP_ERROR_MON_REG_U16, McLoCcIsmOtpErrorMon.val_u32);
    }

    return ErrCode;
}

#endif
/* File End*/
