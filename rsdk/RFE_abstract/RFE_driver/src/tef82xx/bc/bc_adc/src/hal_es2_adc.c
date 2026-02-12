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
#include "bc_types.h"
#include "bc_err.h"
#include "bc_spi.h"
#include "bc_conf.h"
#include "plf.h"
#include "hal_es2_adc.h"
//Register header
#ifdef BUILD_FOR_VAL
#include "v_es2_adc.h"
#else
#include "reg_es2_adc.h"
#endif

static BC_ERRCODE HelperADCReCalibrate(SYS_IPNum_e ModAddr, uint8_t NumCalibr)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M07_PonUnion_t PowerOn;
    uint8_t CalibCount;

    for (CalibCount = 0; CalibCount < NumCalibr; CalibCount++)
    {
        PowerOn.val_u32 = 0u;
        ErrCode = BC_SPI_Write(ModAddr, R2M07_PON_U16, PowerOn.val_u32);
        if (ErrCode == BC_ERR_NOERROR)
        {
            PowerOn.bits_st.PonLaunch = 1u;
            ErrCode = BC_SPI_WriteCheck(ModAddr, R2M07_PON_U16, PowerOn.val_u32);
        }
        if (ErrCode == BC_ERR_NOERROR)
        {
            ErrCode = PLF_TM_Sleep(ADC_WAIT_FOR_CALIBRATION_READY_US);
            if (ErrCode == BC_ERR_NOERROR)
            {
                ErrCode = HAL_ES2_ADC_CheckCalResult(ModAddr);
                if (ErrCode != BC_ERR_NOERROR)
                {
                    ErrCode = BC_ERR_ADC_CALIBRATIONFAILED;
                }
                else
                {
                    break;
                }
            }
        }
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_ADC_PowerOn(BOOL EnADC12, BOOL EnADC34)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M07_PonUnion_t PowerOn;
    SYS_IPNum_e ADCIpOn = e_SYS_INVALID;
    SYS_IPNum_e ADCIpOff = e_SYS_INVALID;

    if ((EnADC12 == TRUE) && (EnADC34 == TRUE))
    {
        ADCIpOn = e_SYS_ADCMC;
        ADCIpOff = e_SYS_INVALID;
    }
    else if ((EnADC12 == FALSE) && (EnADC34 == FALSE))
    {
        ADCIpOn = e_SYS_INVALID;
        ADCIpOff = e_SYS_ADCMC;
    }
    else if (EnADC12 == TRUE)
    {
        ADCIpOn = e_SYS_ADC12;
        ADCIpOff = e_SYS_ADC34;
    }
    else
    {
        ADCIpOn = e_SYS_ADC34;
        ADCIpOff = e_SYS_ADC12;
    }

    if (ADCIpOn != e_SYS_INVALID)
    {
        PowerOn.val_u32 = 0u;
        PowerOn.bits_st.PonLaunch = (uint8_t)TRUE;
        ErrCode = BC_SPI_Write(ADCIpOn, R2M07_PON_U16, PowerOn.val_u32);
        if (ErrCode == BC_ERR_NOERROR)
        {
            ErrCode = PLF_TM_Sleep(ADC_WAIT_FOR_CALIBRATION_READY_US);
        }
        if ((EnADC12 == TRUE) && (ErrCode == BC_ERR_NOERROR))
        {
            ErrCode = HAL_ES2_ADC_CheckCalResult(e_SYS_ADC12);
            if (ErrCode == BC_ERR_ADC_CALIBRATIONFAILED)
            {
                // Retrying ADC calibration
                ErrCode = HelperADCReCalibrate(e_SYS_ADC12, ADC_RECALBRATION_COUNT);
            }
        }
        if ((EnADC34 == TRUE) && (ErrCode == BC_ERR_NOERROR))
        {
            ErrCode = HAL_ES2_ADC_CheckCalResult(e_SYS_ADC34);
            if (ErrCode == BC_ERR_ADC_CALIBRATIONFAILED)
            {
                // Retrying ADC calibration
                ErrCode = HelperADCReCalibrate(e_SYS_ADC34, ADC_RECALBRATION_COUNT);
            }
        }
    }
    if ((ADCIpOff != e_SYS_INVALID) && (ErrCode == BC_ERR_NOERROR))
    {
        /*After IP turn off read give error*/
        PowerOn.val_u32 = 0;
        ErrCode = BC_SPI_Write(ADCIpOff, R2M07_PON_U16, PowerOn.val_u32);
    }
    return ErrCode;
}

BC_ERRCODE HAL_ES2_ADC_ConfigClippingDet(SYS_IPNum_e ADCNum, ADC_ConfigClippingDet_t *pConfigClippingDet)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M07_CliplevelControlUnion_t CliplevelControl;
    R2M07_ErrorcountThresholdUnion_t ErrorcountThreshold;

    if ((ADCNum >= e_SYS_ADC12) && (ADCNum <= e_SYS_ADC34) && (pConfigClippingDet != NULL) &&
        (pConfigClippingDet->ClipLevelADC0 <= 0xFFFu) && (pConfigClippingDet->ClipLevelADC1 <= 0xFFFu) &&
        (pConfigClippingDet->ErrCntThresholdADC0 <= 0x3FFu) && (pConfigClippingDet->ErrCntThresholdADC1 <= 0x3FFu))
    {
        ErrCode = BC_SPI_Read(ADCNum, R2M07_CLIPLEVEL_CONTROL_U16, &CliplevelControl.val_u32);
        if (ErrCode == BC_ERR_NOERROR)
        {
            CliplevelControl.bits_st.CliplevelAdc0 = pConfigClippingDet->ClipLevelADC0;
            CliplevelControl.bits_st.CliplevelAdc1 = pConfigClippingDet->ClipLevelADC1;
            ErrCode = BC_SPI_WriteCheck(ADCNum, R2M07_CLIPLEVEL_CONTROL_U16, CliplevelControl.val_u32);
        }
        if (ErrCode == BC_ERR_NOERROR)
        {
            ErrCode = BC_SPI_Read(ADCNum, R2M07_ERRORCOUNT_THRESHOLD_U16, &ErrorcountThreshold.val_u32);
            if (ErrCode == BC_ERR_NOERROR)
            {
                ErrorcountThreshold.bits_st.ErrorcountThresholdAdc0 = pConfigClippingDet->ErrCntThresholdADC0;
                ErrorcountThreshold.bits_st.ErrorcountThresholdAdc1 = pConfigClippingDet->ErrCntThresholdADC1;
                ErrCode = BC_SPI_WriteCheck(ADCNum, R2M07_ERRORCOUNT_THRESHOLD_U16, ErrorcountThreshold.val_u32);
            }
        }
    }
    else
    {
        ErrCode = BC_ERR_INPUTOUTOFRANGE;
    }

    return ErrCode;
}

BC_ERRCODE HAL_ES2_ADC_CheckCalResult(SYS_IPNum_e ADCNum)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M07_CalibrationStatusUnion_t CalibrationStatus;
    R2M07_CalMonitorStatusUnion_t CalMonitorStatus;
    uint32_t WhileLoopCount = 0u;
    uint8_t CalibrationLauched = 0u;
    uint8_t CalibrationBusy = 0u;

    if ((ADCNum >= e_SYS_ADC12) && (ADCNum <= e_SYS_ADC34))
    {
        do
        {
            ErrCode = PLF_TM_Sleep(ADC_CHECKCALRESULT_SLEEP);
            if (ErrCode == BC_ERR_NOERROR)
            {
                ErrCode = BC_SPI_Read(ADCNum, R2M07_CALIBRATION_STATUS_U16, &CalibrationStatus.val_u32);
            }
            if (ErrCode == BC_ERR_NOERROR)
            {
                // Check if the calibration is launched successfully and if the calibration is still in progress
                CalibrationLauched = CalibrationStatus.bits_st.CalibrationLaunchedOkay;
                CalibrationBusy = CalibrationStatus.bits_st.CalibrationBusy;
                if (WhileLoopCount > ADC_CALIBRATION_TIMEOUT)
                {
                    ErrCode = BC_ERR_ADC_CALIBRATIONTIMEOUT;
                }
                else
                {
                    WhileLoopCount++;
                }
            }
        } while (((CalibrationLauched == 0u) || (CalibrationBusy == 1u)) && (ErrCode == BC_ERR_NOERROR));

        if (ErrCode == BC_ERR_NOERROR)
        {
            ErrCode = BC_SPI_Read(ADCNum, R2M07_CAL_MONITOR_STATUS_U16, &CalMonitorStatus.val_u32);
            if (ErrCode == BC_ERR_NOERROR)
            {
                // check if calibration is successful
                if (CalMonitorStatus.bits_st.CalMonitorCalibrationOkay != 0x0Fu)
                {
                    ErrCode = BC_ERR_ADC_CALIBRATIONFAILED;
                }
                if (CalMonitorStatus.bits_st.CalMonitorCalibrationCheckDone != 0x01u)
                {
                    ErrCode = BC_ERR_ADC_CALIBRATIONCHECKNOTDONE;
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

BC_ERRCODE HAL_ES2_ADC_ConfigBackgroundCal(SYS_IPNum_e ADCNum, BOOL EnBackgroundCal, ADC_BackGroundCal_t *pBackgroundCalControl)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M07_CalibrationControlUnion_t CalibrationControl;

    if ((ADCNum >= e_SYS_ADC12) && (ADCNum <= e_SYS_ADC34))
    {
        ErrCode = BC_SPI_Read(ADCNum, R2M07_CALIBRATION_CONTROL_U16, &CalibrationControl.val_u32);
        if (ErrCode == BC_ERR_NOERROR)
        {
            CalibrationControl.bits_st.EnablePowersaveBgCalibration = (uint8_t)EnBackgroundCal;
            //if pBackgroundCalControl equals to NULL, keep the default setting of background calibration control
            if (pBackgroundCalControl != NULL)
            {
                if (pBackgroundCalControl->PowerSaveBGCalibrationWeights < 0x10u)
                {
                    CalibrationControl.bits_st.PowersaveBgCalibrationNweights = (uint8_t)pBackgroundCalControl->PowerSaveBGCalibrationWeights;
                    CalibrationControl.bits_st.AutoCalibrateAtPon = (uint8_t)pBackgroundCalControl->AutoCalibrateAtPON;
                    CalibrationControl.bits_st.AutoSyncSequencerAfterCalibration = (uint8_t)pBackgroundCalControl->AutoSyncSequencer;
                    CalibrationControl.bits_st.CalibrateLsbWeights = (uint8_t)pBackgroundCalControl->EnCalibrateLSBWeights;
                    CalibrationControl.bits_st.EnableContinuousBgCalibration = (uint8_t)pBackgroundCalControl->EnContinuousBGCalibration;
                    CalibrationControl.bits_st.EnableInterleavedCalibration = (uint8_t)pBackgroundCalControl->EnInterleavedCalibration;
                }
                else
                {
                    ErrCode = BC_ERR_INPUTOUTOFRANGE;
                }
            }
        }
        if (ErrCode == BC_ERR_NOERROR)
        {
            ErrCode = BC_SPI_WriteCheck(ADCNum, R2M07_CALIBRATION_CONTROL_U16, CalibrationControl.val_u32);
        }
    }
    else
    {
        ErrCode = BC_ERR_INPUTOUTOFRANGE;
    }
    return ErrCode;
}
#endif
