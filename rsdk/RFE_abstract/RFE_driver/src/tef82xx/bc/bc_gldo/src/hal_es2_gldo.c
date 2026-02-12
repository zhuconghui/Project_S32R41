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
#include "bc_types.h"
#include "bc_spi.h"
#include "hal_es2_gldo.h"

#ifdef BUILD_FOR_VAL
#include "v_es2_gldo.h"
#else
#include "reg_es2_gldo.h"
#endif

BC_ERRCODE HAL_ES2_GLDO_SelectGLDOVRef(BOOL EnLowNoise)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;
    R2M15_GldoBgRefConfigUnion_t GldoBgRefConfig;

    ErrCode = BC_SPI_Read(e_SYS_GLDO, R2M15_GLDO_BG_REF_CONFIG_U16, &GldoBgRefConfig.val_u32);
    if (ErrCode == BC_ERR_NOERROR)
    {
        GldoBgRefConfig.bits_st.SelVref = (uint8_t)EnLowNoise;
        ErrCode = BC_SPI_WriteCheck(e_SYS_GLDO, R2M15_GLDO_BG_REF_CONFIG_U16, GldoBgRefConfig.val_u32);
    }

    return ErrCode;
}

BC_ERRCODE HAL_ES2_GLDO_SetSNSThreshold(GLDO_SNSThreshold_e SelectSNSThreshold, GLDO_SNS_CoarseAdjustment_e CoarseAdjustment, uint8_t FineAdjustment)
{
    BC_ERRCODE ErrCode = BC_ERR_NOERROR;

    R2M15_Gldo1V1SnsLowCalRegUnion_t Gldo1V11V8SnsLowHighCalReg;
    R2M15_Gldo1V11V8SnsLowHighThresholdConfigUnion_t Gldo1V11V8SnsLowHighThresholdConfig;
    uint16_t SNSFineSettingReg = 0u;

    ErrCode = BC_SPI_Read(e_SYS_GLDO, R2M15_GLDO1V1_1V8_SNS_LOW_HIGH_THRESHOLD_CONFIG_U16, &Gldo1V11V8SnsLowHighThresholdConfig.val_u32);
    if (ErrCode == BC_ERR_NOERROR)
    {
        if (CoarseAdjustment < e_GLDO_COARSESNS_INVALID)
        {
            switch (SelectSNSThreshold)
            {
            case e_GLDO_SNS_1v1HIGH:
                Gldo1V11V8SnsLowHighThresholdConfig.bits_st.Sns1V1HighThreshSel = (uint8_t)CoarseAdjustment;
                SNSFineSettingReg = R2M15_GLDO1V1_SNS_HIGH_CAL_REG_U16;
                break;

            case e_GLDO_SNS_1v1LOW:
                Gldo1V11V8SnsLowHighThresholdConfig.bits_st.Sns1V1LowThreshSel = (uint8_t)CoarseAdjustment;
                SNSFineSettingReg = R2M15_GLDO1V1_SNS_LOW_CAL_REG_U16;
                break;

            case e_GLDO_SNS_1v8HIGH:
                Gldo1V11V8SnsLowHighThresholdConfig.bits_st.Sns1V8HighThreshSel = (uint8_t)CoarseAdjustment;
                SNSFineSettingReg = R2M15_GLDO1V8_SNS_HIGH_CAL_REG_U16;
                break;
            case e_GLDO_SNS_1v8LOW:
                Gldo1V11V8SnsLowHighThresholdConfig.bits_st.Sns1V8LowThreshSel = (uint8_t)CoarseAdjustment;
                SNSFineSettingReg = R2M15_GLDO1V8_SNS_LOW_CAL_REG_U16;
                break;

            default:
                ErrCode = BC_ERR_INPUTOUTOFRANGE;
                break;
            }
            if (ErrCode == BC_ERR_NOERROR)
            {
                ErrCode = BC_SPI_WriteCheck(e_SYS_GLDO, R2M15_GLDO1V1_1V8_SNS_LOW_HIGH_THRESHOLD_CONFIG_U16, Gldo1V11V8SnsLowHighThresholdConfig.val_u32);
            }
        }
        else
        {
            ErrCode = BC_ERR_INPUTOUTOFRANGE;
        }
    }
    if (ErrCode == BC_ERR_NOERROR)
    {
        if (FineAdjustment < 0x40u)
        {
            ErrCode = BC_SPI_Read(e_SYS_GLDO, SNSFineSettingReg, &Gldo1V11V8SnsLowHighCalReg.val_u32);
            if (ErrCode == BC_ERR_NOERROR)
            {
                Gldo1V11V8SnsLowHighCalReg.bits_st.Gldo1V1SnsLowCal = (uint8_t)FineAdjustment;
                ErrCode = BC_SPI_WriteCheck(e_SYS_GLDO, SNSFineSettingReg, Gldo1V11V8SnsLowHighCalReg.val_u32);
            }
        }
        else
        {
            ErrCode = BC_ERR_INPUTOUTOFRANGE;
        }
    }
    return ErrCode;
}
#endif
