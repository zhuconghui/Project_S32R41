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
* @reg_es2_cafc.h
*/
#ifndef REG_ES2_CAFC_H
#define REG_ES2_CAFC_H
#include <stdint.h>
/**
* R2M06_CP_CONTROL_U16
* RegisterName: MOD06_CP_CONTROL
* AccessMode: RW
* AddressRange: 0x0000 - 0x0004
* ResetValue: 0x0FF00000
*/
#define R2M06_CP_CONTROL_U16 (uint16_t)0x0000
/**
* R2M06_VCO_CONTROL_U16
* RegisterName: MOD06_VCO_CONTROL
* AccessMode: RW
* AddressRange: 0x0004 - 0x0008
* ResetValue: 0x00000000
*/
#define R2M06_VCO_CONTROL_U16 (uint16_t)0x0004
/**
* R2M06_VCO_BUFFER_LDO_CONTROL_U16
* RegisterName: MOD06_VCO_BUFFER_LDO_CONTROL
* AccessMode: RW
* AddressRange: 0x0008 - 0x000C
* ResetValue: 0x0000000F
*/
#define R2M06_VCO_BUFFER_LDO_CONTROL_U16 (uint16_t)0x0008
/**
* R2M06_CPPFD_LDO_CONTROL_U16
* RegisterName: MOD06_CPPFD_LDO_CONTROL
* AccessMode: RW
* AddressRange: 0x000C - 0x0010
* ResetValue: 0x0000000F
*/
#define R2M06_CPPFD_LDO_CONTROL_U16 (uint16_t)0x000C
/**
* R2M06_DIVIDER_LDO_CONTROL_U16
* RegisterName: MOD06_DIVIDER_LDO_CONTROL
* AccessMode: RW
* AddressRange: 0x0010 - 0x0014
* ResetValue: 0x0000000F
*/
#define R2M06_DIVIDER_LDO_CONTROL_U16 (uint16_t)0x0010
/**
* R2M06_LDO_EN_CONTROL_U16
* RegisterName: MOD06_LDO_EN_CONTROL
* AccessMode: RW
* AddressRange: 0x0014 - 0x0018
* ResetValue: 0x00000000
*/
#define R2M06_LDO_EN_CONTROL_U16 (uint16_t)0x0014
/**
* R2M06_BIAS_BLOCK_CONTROL_U16
* RegisterName: MOD06_BIAS_BLOCK_CONTROL
* AccessMode: RW
* AddressRange: 0x0018 - 0x001C
* ResetValue: 0x00000000
*/
#define R2M06_BIAS_BLOCK_CONTROL_U16 (uint16_t)0x0018
/**
* R2M06_BUFFER_CONTROL_U16
* RegisterName: MOD06_BUFFER_CONTROL
* AccessMode: RW
* AddressRange: 0x001C - 0x0020
* ResetValue: 0x00000110
*/
#define R2M06_BUFFER_CONTROL_U16 (uint16_t)0x001C
/**
* R2M06_PLL_FAST_RESET_INJ_EN_CONTROL_U16
* RegisterName: MOD06_PLL_FAST_RESET_INJ_EN_CONTROL
* AccessMode: RW
* AddressRange: 0x0020 - 0x0024
* ResetValue: 0x00000011
*/
#define R2M06_PLL_FAST_RESET_INJ_EN_CONTROL_U16 (uint16_t)0x0020
/**
* R2M06_PLL_FAST_RESET_TIMING_CONTROL_U16
* RegisterName: MOD06_PLL_FAST_RESET_TIMING_CONTROL
* AccessMode: RW
* AddressRange: 0x0024 - 0x0028
* ResetValue: 0x00000014
*/
#define R2M06_PLL_FAST_RESET_TIMING_CONTROL_U16 (uint16_t)0x0024
/**
* R2M06_CP_FAST_RESET_SLICE_CONTROL_U16
* RegisterName: MOD06_CP_FAST_RESET_SLICE_CONTROL
* AccessMode: RW
* AddressRange: 0x0028 - 0x002C
* ResetValue: 0x00000000
*/
#define R2M06_CP_FAST_RESET_SLICE_CONTROL_U16 (uint16_t)0x0028
/**
* R2M06_PLL_LPF_CAP_GS_SEL_CONTROL_U16
* RegisterName: MOD06_PLL_LPF_CAP_GS_SEL_CONTROL
* AccessMode: RW
* AddressRange: 0x002C - 0x0030
* ResetValue: 0x00000000
*/
#define R2M06_PLL_LPF_CAP_GS_SEL_CONTROL_U16 (uint16_t)0x002C
/**
* R2M06_PLL_DAC_INJ_ACQ_CONTROL_U16
* RegisterName: MOD06_PLL_DAC_INJ_ACQ_CONTROL
* AccessMode: RW
* AddressRange: 0x0030 - 0x0034
* ResetValue: 0x00000000
*/
#define R2M06_PLL_DAC_INJ_ACQ_CONTROL_U16 (uint16_t)0x0030
/**
* R2M06_PLL_DAC_INJ_RST_CONTROL_U16
* RegisterName: MOD06_PLL_DAC_INJ_RST_CONTROL
* AccessMode: RW
* AddressRange: 0x0034 - 0x0038
* ResetValue: 0x00000000
*/
#define R2M06_PLL_DAC_INJ_RST_CONTROL_U16 (uint16_t)0x0034
/**
* R2M06_PLL_DAC_INJ_IBIAS_CONTROL_U16
* RegisterName: MOD06_PLL_DAC_INJ_IBIAS_CONTROL
* AccessMode: RW
* AddressRange: 0x0038 - 0x003C
* ResetValue: 0x00000020
*/
#define R2M06_PLL_DAC_INJ_IBIAS_CONTROL_U16 (uint16_t)0x0038
/**
* R2M06_CP_PLLBW_CFG0_U16
* RegisterName: MOD06_CP_PLLBW_CFG0
* AccessMode: RW
* AddressRange: 0x0050 - 0x0054
* ResetValue: 0x00300001
*/
#define R2M06_CP_PLLBW_CFG0_U16 (uint16_t)0x0050
/**
* R2M06_PLL_LPF_C1_PLLBW_CFG0_U16
* RegisterName: MOD06_PLL_LPF_C1_PLLBW_CFG0
* AccessMode: RW
* AddressRange: 0x0054 - 0x0058
* ResetValue: 0x00000000
*/
#define R2M06_PLL_LPF_C1_PLLBW_CFG0_U16 (uint16_t)0x0054
/**
* R2M06_PLL_LPF_C2_PLLBW_CFG0_U16
* RegisterName: MOD06_PLL_LPF_C2_PLLBW_CFG0
* AccessMode: RW
* AddressRange: 0x0058 - 0x005C
* ResetValue: 0x00000000
*/
#define R2M06_PLL_LPF_C2_PLLBW_CFG0_U16 (uint16_t)0x0058
/**
* R2M06_PLL_LPF_C3_PLLBW_CFG0_U16
* RegisterName: MOD06_PLL_LPF_C3_PLLBW_CFG0
* AccessMode: RW
* AddressRange: 0x005C - 0x0060
* ResetValue: 0x00000000
*/
#define R2M06_PLL_LPF_C3_PLLBW_CFG0_U16 (uint16_t)0x005C
/**
* R2M06_PLL_LPF_RES_PLLBW_CFG0_U16
* RegisterName: MOD06_PLL_LPF_RES_PLLBW_CFG0
* AccessMode: RW
* AddressRange: 0x0060 - 0x0064
* ResetValue: 0x00001616
*/
#define R2M06_PLL_LPF_RES_PLLBW_CFG0_U16 (uint16_t)0x0060
/**
* R2M06_CP_PLLBW_CFG1_U16
* RegisterName: MOD06_CP_PLLBW_CFG1
* AccessMode: RW
* AddressRange: 0x0070 - 0x0074
* ResetValue: 0x00300001
*/
#define R2M06_CP_PLLBW_CFG1_U16 (uint16_t)0x0070
/**
* R2M06_PLL_LPF_C1_PLLBW_CFG1_U16
* RegisterName: MOD06_PLL_LPF_C1_PLLBW_CFG1
* AccessMode: RW
* AddressRange: 0x0074 - 0x0078
* ResetValue: 0x00000000
*/
#define R2M06_PLL_LPF_C1_PLLBW_CFG1_U16 (uint16_t)0x0074
/**
* R2M06_PLL_LPF_C2_PLLBW_CFG1_U16
* RegisterName: MOD06_PLL_LPF_C2_PLLBW_CFG1
* AccessMode: RW
* AddressRange: 0x0078 - 0x007C
* ResetValue: 0x00000000
*/
#define R2M06_PLL_LPF_C2_PLLBW_CFG1_U16 (uint16_t)0x0078
/**
* R2M06_PLL_LPF_C3_PLLBW_CFG1_U16
* RegisterName: MOD06_PLL_LPF_C3_PLLBW_CFG1
* AccessMode: RW
* AddressRange: 0x007C - 0x0080
* ResetValue: 0x00000000
*/
#define R2M06_PLL_LPF_C3_PLLBW_CFG1_U16 (uint16_t)0x007C
/**
* R2M06_PLL_LPF_RES_PLLBW_CFG1_U16
* RegisterName: MOD06_PLL_LPF_RES_PLLBW_CFG1
* AccessMode: RW
* AddressRange: 0x0080 - 0x0084
* ResetValue: 0x00001616
*/
#define R2M06_PLL_LPF_RES_PLLBW_CFG1_U16 (uint16_t)0x0080
/**
* R2M06_CP_PLLBW_CFG2_U16
* RegisterName: MOD06_CP_PLLBW_CFG2
* AccessMode: RW
* AddressRange: 0x0090 - 0x0094
* ResetValue: 0x00300001
*/
#define R2M06_CP_PLLBW_CFG2_U16 (uint16_t)0x0090
/**
* R2M06_PLL_LPF_C1_PLLBW_CFG2_U16
* RegisterName: MOD06_PLL_LPF_C1_PLLBW_CFG2
* AccessMode: RW
* AddressRange: 0x0094 - 0x0098
* ResetValue: 0x00000000
*/
#define R2M06_PLL_LPF_C1_PLLBW_CFG2_U16 (uint16_t)0x0094
/**
* R2M06_PLL_LPF_C2_PLLBW_CFG2_U16
* RegisterName: MOD06_PLL_LPF_C2_PLLBW_CFG2
* AccessMode: RW
* AddressRange: 0x0098 - 0x009C
* ResetValue: 0x00000000
*/
#define R2M06_PLL_LPF_C2_PLLBW_CFG2_U16 (uint16_t)0x0098
/**
* R2M06_PLL_LPF_C3_PLLBW_CFG2_U16
* RegisterName: MOD06_PLL_LPF_C3_PLLBW_CFG2
* AccessMode: RW
* AddressRange: 0x009C - 0x00A0
* ResetValue: 0x00000000
*/
#define R2M06_PLL_LPF_C3_PLLBW_CFG2_U16 (uint16_t)0x009C
/**
* R2M06_PLL_LPF_RES_PLLBW_CFG2_U16
* RegisterName: MOD06_PLL_LPF_RES_PLLBW_CFG2
* AccessMode: RW
* AddressRange: 0x00A0 - 0x00A4
* ResetValue: 0x00001616
*/
#define R2M06_PLL_LPF_RES_PLLBW_CFG2_U16 (uint16_t)0x00A0
/**
* R2M06_CP_PLLBW_CFG3_U16
* RegisterName: MOD06_CP_PLLBW_CFG3
* AccessMode: RW
* AddressRange: 0x00B0 - 0x00B4
* ResetValue: 0x00300001
*/
#define R2M06_CP_PLLBW_CFG3_U16 (uint16_t)0x00B0
/**
* R2M06_PLL_LPF_C1_PLLBW_CFG3_U16
* RegisterName: MOD06_PLL_LPF_C1_PLLBW_CFG3
* AccessMode: RW
* AddressRange: 0x00B4 - 0x00B8
* ResetValue: 0x00000000
*/
#define R2M06_PLL_LPF_C1_PLLBW_CFG3_U16 (uint16_t)0x00B4
/**
* R2M06_PLL_LPF_C2_PLLBW_CFG3_U16
* RegisterName: MOD06_PLL_LPF_C2_PLLBW_CFG3
* AccessMode: RW
* AddressRange: 0x00B8 - 0x00BC
* ResetValue: 0x00000000
*/
#define R2M06_PLL_LPF_C2_PLLBW_CFG3_U16 (uint16_t)0x00B8
/**
* R2M06_PLL_LPF_C3_PLLBW_CFG3_U16
* RegisterName: MOD06_PLL_LPF_C3_PLLBW_CFG3
* AccessMode: RW
* AddressRange: 0x00BC - 0x00C0
* ResetValue: 0x00000000
*/
#define R2M06_PLL_LPF_C3_PLLBW_CFG3_U16 (uint16_t)0x00BC
/**
* R2M06_PLL_LPF_RES_PLLBW_CFG3_U16
* RegisterName: MOD06_PLL_LPF_RES_PLLBW_CFG3
* AccessMode: RW
* AddressRange: 0x00C0 - 0x00C4
* ResetValue: 0x00001616
*/
#define R2M06_PLL_LPF_RES_PLLBW_CFG3_U16 (uint16_t)0x00C0
/**
* R2M06_CP_PLLBW_CFG_HIGH_1G_U16
* RegisterName: MOD06_CP_PLLBW_CFG_HIGH_1G
* AccessMode: RW
* AddressRange: 0x00D0 - 0x00D4
* ResetValue: 0x003D0001
*/
#define R2M06_CP_PLLBW_CFG_HIGH_1G_U16 (uint16_t)0x00D0
/**
* R2M06_PLL_LPF_CAP_PLLBW_CFG_HIGH_1G_U16
* RegisterName: MOD06_PLL_LPF_CAP_PLLBW_CFG_HIGH_1G
* AccessMode: RW
* AddressRange: 0x00D4 - 0x00D8
* ResetValue: 0x00403F12
*/
#define R2M06_PLL_LPF_CAP_PLLBW_CFG_HIGH_1G_U16 (uint16_t)0x00D4
/**
* R2M06_CP_PLLBW_CFG_HIGH_2G_U16
* RegisterName: MOD06_CP_PLLBW_CFG_HIGH_2G
* AccessMode: RW
* AddressRange: 0x00D8 - 0x00DC
* ResetValue: 0x00190001
*/
#define R2M06_CP_PLLBW_CFG_HIGH_2G_U16 (uint16_t)0x00D8
/**
* R2M06_PLL_LPF_CAP_PLLBW_CFG_HIGH_2G_U16
* RegisterName: MOD06_PLL_LPF_CAP_PLLBW_CFG_HIGH_2G
* AccessMode: RW
* AddressRange: 0x00DC - 0x00E0
* ResetValue: 0x00403F11
*/
#define R2M06_PLL_LPF_CAP_PLLBW_CFG_HIGH_2G_U16 (uint16_t)0x00DC
/**
* R2M06_CP_PLLBW_CFG_HIGH_4G_U16
* RegisterName: MOD06_CP_PLLBW_CFG_HIGH_4G
* AccessMode: RW
* AddressRange: 0x00E0 - 0x00E4
* ResetValue: 0x00150001
*/
#define R2M06_CP_PLLBW_CFG_HIGH_4G_U16 (uint16_t)0x00E0
/**
* R2M06_PLL_LPF_CAP_PLLBW_CFG_HIGH_4G_U16
* RegisterName: MOD06_PLL_LPF_CAP_PLLBW_CFG_HIGH_4G
* AccessMode: RW
* AddressRange: 0x00E4 - 0x00E8
* ResetValue: 0x00413F12
*/
#define R2M06_PLL_LPF_CAP_PLLBW_CFG_HIGH_4G_U16 (uint16_t)0x00E4
/**
* R2M06_PLL_LPF_RES_PLLBW_CFG_HIGH_U16
* RegisterName: MOD06_PLL_LPF_RES_PLLBW_CFG_HIGH
* AccessMode: RW
* AddressRange: 0x00E8 - 0x00EC
* ResetValue: 0x2B594A52
*/
#define R2M06_PLL_LPF_RES_PLLBW_CFG_HIGH_U16 (uint16_t)0x00E8
/**
* R2M06_VCO_REG_PROFILE0_U16
* RegisterName: MOD06_VCO_REG_PROFILE0
* AccessMode: RW
* AddressRange: 0x0100 - 0x0104
* ResetValue: 0x000F0000
*/
#define R2M06_VCO_REG_PROFILE0_U16 (uint16_t)0x0100
/**
* R2M06_LPF_INJ_ACQ_RST_PROFILE0_U16
* RegisterName: MOD06_LPF_INJ_ACQ_RST_PROFILE0
* AccessMode: RW
* AddressRange: 0x0104 - 0x0108
* ResetValue: 0x00000000
*/
#define R2M06_LPF_INJ_ACQ_RST_PROFILE0_U16 (uint16_t)0x0104
/**
* R2M06_VCO_REG_PROFILE1_U16
* RegisterName: MOD06_VCO_REG_PROFILE1
* AccessMode: RW
* AddressRange: 0x0110 - 0x0114
* ResetValue: 0x000F0000
*/
#define R2M06_VCO_REG_PROFILE1_U16 (uint16_t)0x0110
/**
* R2M06_LPF_INJ_ACQ_RST_PROFILE1_U16
* RegisterName: MOD06_LPF_INJ_ACQ_RST_PROFILE1
* AccessMode: RW
* AddressRange: 0x0114 - 0x0118
* ResetValue: 0x00000000
*/
#define R2M06_LPF_INJ_ACQ_RST_PROFILE1_U16 (uint16_t)0x0114
/**
* R2M06_VCO_REG_PROFILE2_U16
* RegisterName: MOD06_VCO_REG_PROFILE2
* AccessMode: RW
* AddressRange: 0x0120 - 0x0124
* ResetValue: 0x000F0000
*/
#define R2M06_VCO_REG_PROFILE2_U16 (uint16_t)0x0120
/**
* R2M06_LPF_INJ_ACQ_RST_PROFILE2_U16
* RegisterName: MOD06_LPF_INJ_ACQ_RST_PROFILE2
* AccessMode: RW
* AddressRange: 0x0124 - 0x0128
* ResetValue: 0x00000000
*/
#define R2M06_LPF_INJ_ACQ_RST_PROFILE2_U16 (uint16_t)0x0124
/**
* R2M06_VCO_REG_PROFILE3_U16
* RegisterName: MOD06_VCO_REG_PROFILE3
* AccessMode: RW
* AddressRange: 0x0130 - 0x0134
* ResetValue: 0x000F0000
*/
#define R2M06_VCO_REG_PROFILE3_U16 (uint16_t)0x0130
/**
* R2M06_LPF_INJ_ACQ_RST_PROFILE3_U16
* RegisterName: MOD06_LPF_INJ_ACQ_RST_PROFILE3
* AccessMode: RW
* AddressRange: 0x0134 - 0x0138
* ResetValue: 0x00000000
*/
#define R2M06_LPF_INJ_ACQ_RST_PROFILE3_U16 (uint16_t)0x0134
/**
* R2M06_VCO_REG_PROFILE4_U16
* RegisterName: MOD06_VCO_REG_PROFILE4
* AccessMode: RW
* AddressRange: 0x0140 - 0x0144
* ResetValue: 0x000F0000
*/
#define R2M06_VCO_REG_PROFILE4_U16 (uint16_t)0x0140
/**
* R2M06_LPF_INJ_ACQ_RST_PROFILE4_U16
* RegisterName: MOD06_LPF_INJ_ACQ_RST_PROFILE4
* AccessMode: RW
* AddressRange: 0x0144 - 0x0148
* ResetValue: 0x00000000
*/
#define R2M06_LPF_INJ_ACQ_RST_PROFILE4_U16 (uint16_t)0x0144
/**
* R2M06_VCO_REG_PROFILE5_U16
* RegisterName: MOD06_VCO_REG_PROFILE5
* AccessMode: RW
* AddressRange: 0x0150 - 0x0154
* ResetValue: 0x000F0000
*/
#define R2M06_VCO_REG_PROFILE5_U16 (uint16_t)0x0150
/**
* R2M06_LPF_INJ_ACQ_RST_PROFILE5_U16
* RegisterName: MOD06_LPF_INJ_ACQ_RST_PROFILE5
* AccessMode: RW
* AddressRange: 0x0154 - 0x0158
* ResetValue: 0x00000000
*/
#define R2M06_LPF_INJ_ACQ_RST_PROFILE5_U16 (uint16_t)0x0154
/**
* R2M06_VCO_REG_PROFILE6_U16
* RegisterName: MOD06_VCO_REG_PROFILE6
* AccessMode: RW
* AddressRange: 0x0160 - 0x0164
* ResetValue: 0x000F0000
*/
#define R2M06_VCO_REG_PROFILE6_U16 (uint16_t)0x0160
/**
* R2M06_LPF_INJ_ACQ_RST_PROFILE6_U16
* RegisterName: MOD06_LPF_INJ_ACQ_RST_PROFILE6
* AccessMode: RW
* AddressRange: 0x0164 - 0x0168
* ResetValue: 0x00000000
*/
#define R2M06_LPF_INJ_ACQ_RST_PROFILE6_U16 (uint16_t)0x0164
/**
* R2M06_VCO_REG_PROFILE7_U16
* RegisterName: MOD06_VCO_REG_PROFILE7
* AccessMode: RW
* AddressRange: 0x0170 - 0x0174
* ResetValue: 0x000F0000
*/
#define R2M06_VCO_REG_PROFILE7_U16 (uint16_t)0x0170
/**
* R2M06_LPF_INJ_ACQ_RST_PROFILE7_U16
* RegisterName: MOD06_LPF_INJ_ACQ_RST_PROFILE7
* AccessMode: RW
* AddressRange: 0x0174 - 0x0178
* ResetValue: 0x00000000
*/
#define R2M06_LPF_INJ_ACQ_RST_PROFILE7_U16 (uint16_t)0x0174
/**
* R2M06_VCO_REG_PROFILE8_U16
* RegisterName: MOD06_VCO_REG_PROFILE8
* AccessMode: RW
* AddressRange: 0x0180 - 0x0184
* ResetValue: 0x000F0000
*/
#define R2M06_VCO_REG_PROFILE8_U16 (uint16_t)0x0180
/**
* R2M06_LPF_INJ_ACQ_RST_PROFILE8_U16
* RegisterName: MOD06_LPF_INJ_ACQ_RST_PROFILE8
* AccessMode: RW
* AddressRange: 0x0184 - 0x0188
* ResetValue: 0x00000000
*/
#define R2M06_LPF_INJ_ACQ_RST_PROFILE8_U16 (uint16_t)0x0184
/**
* R2M06_LPF_INJ_ACQ_RST_COMMON_U16
* RegisterName: MOD06_LPF_INJ_ACQ_RST_COMMON
* AccessMode: RW
* AddressRange: 0x0200 - 0x0204
* ResetValue: 0x00000000
*/
#define R2M06_LPF_INJ_ACQ_RST_COMMON_U16 (uint16_t)0x0200
/**
* R2M06_CHIRP_CALIBRATION_AAC_CONTROL1_U16
* RegisterName: MOD06_CHIRP_CALIBRATION_AAC_CONTROL1
* AccessMode: RW
* AddressRange: 0x0220 - 0x0224
* ResetValue: 0x0023350A
*/
#define R2M06_CHIRP_CALIBRATION_AAC_CONTROL1_U16 (uint16_t)0x0220
/**
* R2M06_CHIRP_CALIBRATION_AAC_CONTROL2_U16
* RegisterName: MOD06_CHIRP_CALIBRATION_AAC_CONTROL2
* AccessMode: RW
* AddressRange: 0x0224 - 0x0228
* ResetValue: 0x00034007
*/
#define R2M06_CHIRP_CALIBRATION_AAC_CONTROL2_U16 (uint16_t)0x0224
/**
* R2M06_CHIRP_CALIBRATION_AFC_CONTROL1_U16
* RegisterName: MOD06_CHIRP_CALIBRATION_AFC_CONTROL1
* AccessMode: RW
* AddressRange: 0x0228 - 0x022C
* ResetValue: 0x05104000
*/
#define R2M06_CHIRP_CALIBRATION_AFC_CONTROL1_U16 (uint16_t)0x0228
/**
* R2M06_CHIRP_CALIBRATION_AFC_CONTROL2_U16
* RegisterName: MOD06_CHIRP_CALIBRATION_AFC_CONTROL2
* AccessMode: RW
* AddressRange: 0x022C - 0x0230
* ResetValue: 0x00667372
*/
#define R2M06_CHIRP_CALIBRATION_AFC_CONTROL2_U16 (uint16_t)0x022C
/**
* R2M06_DIVIDE_FORCE_CONTROL_U16
* RegisterName: MOD06_DIVIDE_FORCE_CONTROL
* AccessMode: RW
* AddressRange: 0x0240 - 0x0244
* ResetValue: 0x00000120
*/
#define R2M06_DIVIDE_FORCE_CONTROL_U16 (uint16_t)0x0240
/**
* R2M06_LPF_ENABLE_SETTINGS_U16
* RegisterName: MOD06_LPF_ENABLE_SETTINGS
* AccessMode: RW
* AddressRange: 0x0244 - 0x0248
* ResetValue: 0x17610017
*/
#define R2M06_LPF_ENABLE_SETTINGS_U16 (uint16_t)0x0244
/**
* R2M06_VCO_ENABLE_SETTINGS_U16
* RegisterName: MOD06_VCO_ENABLE_SETTINGS
* AccessMode: RW
* AddressRange: 0x0248 - 0x024C
* ResetValue: 0x00000000
*/
#define R2M06_VCO_ENABLE_SETTINGS_U16 (uint16_t)0x0248
/**
* R2M06_FUNCSAFE_MON_VTUNE_CONTROL_U16
* RegisterName: MOD06_FUNCSAFE_MON_VTUNE_CONTROL
* AccessMode: RW
* AddressRange: 0x024C - 0x0250
* ResetValue: 0x00000000
*/
#define R2M06_FUNCSAFE_MON_VTUNE_CONTROL_U16 (uint16_t)0x024C
/**
* R2M06_FUNCSAFE_MON_UNLOCK_CONTROL_U16
* RegisterName: MOD06_FUNCSAFE_MON_UNLOCK_CONTROL
* AccessMode: RW
* AddressRange: 0x0250 - 0x0254
* ResetValue: 0x00100400
*/
#define R2M06_FUNCSAFE_MON_UNLOCK_CONTROL_U16 (uint16_t)0x0250
/**
* R2M06_FUNCSAFE_MON_LEVEL_SETTINGS_U16
* RegisterName: MOD06_FUNCSAFE_MON_LEVEL_SETTINGS
* AccessMode: RW
* AddressRange: 0x0254 - 0x0258
* ResetValue: 0x3530150C
*/
#define R2M06_FUNCSAFE_MON_LEVEL_SETTINGS_U16 (uint16_t)0x0254
/**
* R2M06_FUNCSAFE_MON_TEMP_THRESHOLD_U16
* RegisterName: MOD06_FUNCSAFE_MON_TEMP_THRESHOLD
* AccessMode: RW
* AddressRange: 0x0258 - 0x025C
* ResetValue: 0x00000000
*/
#define R2M06_FUNCSAFE_MON_TEMP_THRESHOLD_U16 (uint16_t)0x0258
/**
* R2M06_ATB_TRIM_U16
* RegisterName: MOD06_ATB_TRIM
* AccessMode: RW
* AddressRange: 0x0260 - 0x0264
* ResetValue: 0x0000002B
*/
#define R2M06_ATB_TRIM_U16 (uint16_t)0x0260
/**
* R2M06_FILTER_PAR_TRIM_U16
* RegisterName: MOD06_FILTER_PAR_TRIM
* AccessMode: RW
* AddressRange: 0x0264 - 0x0268
* ResetValue: 0x00011616
*/
#define R2M06_FILTER_PAR_TRIM_U16 (uint16_t)0x0264
/**
* R2M06_VCO_CURRENT_TRIM_U16
* RegisterName: MOD06_VCO_CURRENT_TRIM
* AccessMode: RW
* AddressRange: 0x0268 - 0x026C
* ResetValue: 0x0000000F
*/
#define R2M06_VCO_CURRENT_TRIM_U16 (uint16_t)0x0268
/**
* R2M06_FUNCSAFE_MON_LEVEL_SETTINGS_EN_U16
* RegisterName: MOD06_FUNCSAFE_MON_LEVEL_SETTINGS_EN
* AccessMode: RW
* AddressRange: 0x026C - 0x0270
* ResetValue: 0x00000000
*/
#define R2M06_FUNCSAFE_MON_LEVEL_SETTINGS_EN_U16 (uint16_t)0x026C
/**
* R2M06_SUBBAND_AMP_CORRECTION_MODE_SEL_U16
* RegisterName: MOD06_SUBBAND_AMP_CORRECTION_MODE_SEL
* AccessMode: RW
* AddressRange: 0x0270 - 0x0274
* ResetValue: 0x00000000
*/
#define R2M06_SUBBAND_AMP_CORRECTION_MODE_SEL_U16 (uint16_t)0x0270
/**
* R2M06_OTP_TRIM_SUBBAND_CORRECTION_1G_U16
* RegisterName: MOD06_OTP_TRIM_SUBBAND_CORRECTION_1G
* AccessMode: RW
* AddressRange: 0x0274 - 0x0278
* ResetValue: 0x00000000
*/
#define R2M06_OTP_TRIM_SUBBAND_CORRECTION_1G_U16 (uint16_t)0x0274
/**
* R2M06_OTP_TRIM_SUBBAND_CORRECTION_2G_U16
* RegisterName: MOD06_OTP_TRIM_SUBBAND_CORRECTION_2G
* AccessMode: RW
* AddressRange: 0x0278 - 0x027C
* ResetValue: 0x00000000
*/
#define R2M06_OTP_TRIM_SUBBAND_CORRECTION_2G_U16 (uint16_t)0x0278
/**
* R2M06_OTP_TRIM_SUBBAND_CORRECTION_4G_U16
* RegisterName: MOD06_OTP_TRIM_SUBBAND_CORRECTION_4G
* AccessMode: RW
* AddressRange: 0x027C - 0x0280
* ResetValue: 0x00000000
*/
#define R2M06_OTP_TRIM_SUBBAND_CORRECTION_4G_U16 (uint16_t)0x027C
/**
* R2M06_HIGH_PLLBW_SWITCH_CONTROL_U16
* RegisterName: MOD06_HIGH_PLLBW_SWITCH_CONTROL
* AccessMode: RW
* AddressRange: 0x0280 - 0x0284
* ResetValue: 0x01901906
*/
#define R2M06_HIGH_PLLBW_SWITCH_CONTROL_U16 (uint16_t)0x0280
/**
* R2M06_ADDITIONAL_HW_SETTINGS_U16
* RegisterName: MOD06_ADDITIONAL_HW_SETTINGS
* AccessMode: RW
* AddressRange: 0x0298 - 0x029C
* ResetValue: 0x00010000
*/
#define R2M06_ADDITIONAL_HW_SETTINGS_U16 (uint16_t)0x0298
/**
* R2M06_CONTROL_SPARE_U16
* RegisterName: MOD06_CONTROL_SPARE
* AccessMode: RW
* AddressRange: 0x029C - 0x02A0
* ResetValue: 0x00000000
*/
#define R2M06_CONTROL_SPARE_U16 (uint16_t)0x029C
/**
* R2M06_TS_SETTINGS_U16
* RegisterName: MOD06_TS_SETTINGS
* AccessMode: RW
* AddressRange: 0x02A0 - 0x02A4
* ResetValue: 0x00000000
*/
#define R2M06_TS_SETTINGS_U16 (uint16_t)0x02A0
/**
* R2M06_RMS_CONTROL_U16
* RegisterName: MOD06_RMS_CONTROL
* AccessMode: RW
* AddressRange: 0x02A4 - 0x02A8
* ResetValue: 0x10000000
*/
#define R2M06_RMS_CONTROL_U16 (uint16_t)0x02A4
/**
* R2M06_REF_CNTR_INIT_U16
* RegisterName: MOD06_REF_CNTR_INIT
* AccessMode: RW
* AddressRange: 0x02B0 - 0x02B4
* ResetValue: 0x01E00028
*/
#define R2M06_REF_CNTR_INIT_U16 (uint16_t)0x02B0
/**
* R2M06_FREQ_COUNTER_START_U16
* RegisterName: MOD06_FREQ_COUNTER_START
* AccessMode: RW
* AddressRange: 0x02B4 - 0x02B8
* ResetValue: 0x00000130
*/
#define R2M06_FREQ_COUNTER_START_U16 (uint16_t)0x02B4
/**
* R2M06_FREQ_COUNTER_READ_VALUE_U16
* RegisterName: MOD06_FREQ_COUNTER_READ_VALUE
* AccessMode: R
* AddressRange: 0x02B8 - 0x02BC
* ResetValue: 0x00000000
*/
#define R2M06_FREQ_COUNTER_READ_VALUE_U16 (uint16_t)0x02B8
/**
* R2M06_REF_COUNTER_READ_VALUE_U16
* RegisterName: MOD06_REF_COUNTER_READ_VALUE
* AccessMode: R
* AddressRange: 0x02BC - 0x02C0
* ResetValue: 0x00000000
*/
#define R2M06_REF_COUNTER_READ_VALUE_U16 (uint16_t)0x02BC
/**
* R2M06_LOOP_FILTER_COUNTER_INIT_U16
* RegisterName: MOD06_LOOP_FILTER_COUNTER_INIT
* AccessMode: RW
* AddressRange: 0x02C0 - 0x02C4
* ResetValue: 0x00000000
*/
#define R2M06_LOOP_FILTER_COUNTER_INIT_U16 (uint16_t)0x02C0
/**
* R2M06_LOOP_FILTER_COUNTER_READ_VALUE_U16
* RegisterName: MOD06_LOOP_FILTER_COUNTER_READ_VALUE
* AccessMode: R
* AddressRange: 0x02C4 - 0x02C8
* ResetValue: 0x00000000
*/
#define R2M06_LOOP_FILTER_COUNTER_READ_VALUE_U16 (uint16_t)0x02C4
/**
* R2M06_DIVIDE_FREQ_COUNTER_START_U16
* RegisterName: MOD06_DIVIDE_FREQ_COUNTER_START
* AccessMode: RW
* AddressRange: 0x02D0 - 0x02D4
* ResetValue: 0x00000100
*/
#define R2M06_DIVIDE_FREQ_COUNTER_START_U16 (uint16_t)0x02D0
/**
* R2M06_DIVIDE_FREQ_COUNTER_READ_VALUE_U16
* RegisterName: MOD06_DIVIDE_FREQ_COUNTER_READ_VALUE
* AccessMode: R
* AddressRange: 0x02D4 - 0x02D8
* ResetValue: 0x00000000
*/
#define R2M06_DIVIDE_FREQ_COUNTER_READ_VALUE_U16 (uint16_t)0x02D4
/**
* R2M06_KVCO_DVDT_CONFIG_CONTROL_U16
* RegisterName: MOD06_KVCO_DVDT_CONFIG_CONTROL
* AccessMode: RW
* AddressRange: 0x02DC - 0x02E0
* ResetValue: 0x0C6F0011
*/
#define R2M06_KVCO_DVDT_CONFIG_CONTROL_U16 (uint16_t)0x02DC
/**
* R2M06_KVCO_DVDT_DELAY_CONTROL_U16
* RegisterName: MOD06_KVCO_DVDT_DELAY_CONTROL
* AccessMode: RW
* AddressRange: 0x02E0 - 0x02E4
* ResetValue: 0x32032028
*/
#define R2M06_KVCO_DVDT_DELAY_CONTROL_U16 (uint16_t)0x02E0
/**
* R2M06_KVCO_COUNT_STATUS_U16
* RegisterName: MOD06_KVCO_COUNT_STATUS
* AccessMode: R
* AddressRange: 0x02E4 - 0x02E8
* ResetValue: 0x00000000
*/
#define R2M06_KVCO_COUNT_STATUS_U16 (uint16_t)0x02E4
/**
* R2M06_AAFC_LOCK_DVDT_COUNT_STATUS_U16
* RegisterName: MOD06_AAFC_LOCK_DVDT_COUNT_STATUS
* AccessMode: R
* AddressRange: 0x02E8 - 0x02EC
* ResetValue: 0x00000000
*/
#define R2M06_AAFC_LOCK_DVDT_COUNT_STATUS_U16 (uint16_t)0x02E8
/**
* R2M06_CHIRP_CALIBRATION_STATUS_U16
* RegisterName: MOD06_CHIRP_CALIBRATION_STATUS
* AccessMode: R
* AddressRange: 0x0310 - 0x0314
* ResetValue: 0x00000000
*/
#define R2M06_CHIRP_CALIBRATION_STATUS_U16 (uint16_t)0x0310
/**
* R2M06_CHIRP_CALIBRATION_SW_CONTROL_U16
* RegisterName: MOD06_CHIRP_CALIBRATION_SW_CONTROL
* AccessMode: RW
* AddressRange: 0x03A0 - 0x03A4
* ResetValue: 0x01001030
*/
#define R2M06_CHIRP_CALIBRATION_SW_CONTROL_U16 (uint16_t)0x03A0
/**
* R2M06_CHIRP_CALIBRATION_TIMEOUT_DELAY_U16
* RegisterName: MOD06_CHIRP_CALIBRATION_TIMEOUT_DELAY
* AccessMode: RW
* AddressRange: 0x03A4 - 0x03A8
* ResetValue: 0x00001F40
*/
#define R2M06_CHIRP_CALIBRATION_TIMEOUT_DELAY_U16 (uint16_t)0x03A4
/**
* R2M06_ATB1_U16
* RegisterName: MOD06_ATB1
* AccessMode: RW
* AddressRange: 0x0C04 - 0x0C08
* ResetValue: 0x000000FF
*/
#define R2M06_ATB1_U16 (uint16_t)0x0C04
/**
* R2M06_DFT_IDAC_CONTROL_U16
* RegisterName: MOD06_DFT_IDAC_CONTROL
* AccessMode: RW
* AddressRange: 0x0C08 - 0x0C0C
* ResetValue: 0x00000000
*/
#define R2M06_DFT_IDAC_CONTROL_U16 (uint16_t)0x0C08
/**
* R2M06_MASK_CC_RESET_ERROR_U16
* RegisterName: MOD06_MASK_CC_RESET_ERROR
* AccessMode: RW
* AddressRange: 0x0E04 - 0x0E08
* ResetValue: 0x00E00000
*/
#define R2M06_MASK_CC_RESET_ERROR_U16 (uint16_t)0x0E04
/**
* R2M06_MASK_CC_ERROR_FLAG_U16
* RegisterName: MOD06_MASK_CC_ERROR_FLAG
* AccessMode: RW
* AddressRange: 0x0E08 - 0x0E0C
* ResetValue: 0x00000000
*/
#define R2M06_MASK_CC_ERROR_FLAG_U16 (uint16_t)0x0E08
/**
* R2M06_CRC_ERROR_STATUS1_U16
* RegisterName: MOD06_CRC_ERROR_STATUS1
* AccessMode: R
* AddressRange: 0x0F40 - 0x0F44
* ResetValue: 0x00000000
*/
#define R2M06_CRC_ERROR_STATUS1_U16 (uint16_t)0x0F40
/**
* R2M06_CRC_ERROR_STATUS2_U16
* RegisterName: MOD06_CRC_ERROR_STATUS2
* AccessMode: R
* AddressRange: 0x0F44 - 0x0F48
* ResetValue: 0x00000000
*/
#define R2M06_CRC_ERROR_STATUS2_U16 (uint16_t)0x0F44
/**
* R2M06_CRC_ERROR_STATUS3_U16
* RegisterName: MOD06_CRC_ERROR_STATUS3
* AccessMode: R
* AddressRange: 0x0F48 - 0x0F4C
* ResetValue: 0x00000000
*/
#define R2M06_CRC_ERROR_STATUS3_U16 (uint16_t)0x0F48
/**
* R2M06_CRC_ERROR_STATUS4_U16
* RegisterName: MOD06_CRC_ERROR_STATUS4
* AccessMode: R
* AddressRange: 0x0F4C - 0x0F50
* ResetValue: 0x00000000
*/
#define R2M06_CRC_ERROR_STATUS4_U16 (uint16_t)0x0F4C
/**
* R2M06_CRC_ERROR_STATUS5_U16
* RegisterName: MOD06_CRC_ERROR_STATUS5
* AccessMode: R
* AddressRange: 0x0F50 - 0x0F54
* ResetValue: 0x00000000
*/
#define R2M06_CRC_ERROR_STATUS5_U16 (uint16_t)0x0F50
/**
* R2M06_MODULE_ID_U16
* RegisterName: MOD06_MODULE_ID
* AccessMode: R
* AddressRange: 0x0FFC - 0x1000
* ResetValue: 0x00065001
*/
#define R2M06_MODULE_ID_U16 (uint16_t)0x0FFC

 #ifndef HOST_CPU_BIG_ENDIAN
/**
* R2M06_CpControlBits_t
* RegisterName: CP_CONTROL
* Charge pump settings
* Address: 0x000
* ResetValue: 0x0FF00000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctl_cp_force_up_spi
	* Description: Force the Charge Pump up
	* 1 :  Increase CP current
	* 0 :  No action
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlCpForceUpSpi : 1;        /*## attribute CtlCpForceUpSpi */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_cp_force_dn_spi
	* Description: Force the Charge Pump down
	* 1 : Decrease CP current
	* 0 :  No action
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlCpForceDnSpi : 1;        /*## attribute CtlCpForceDnSpi */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_cp_en_spi
	* Description: Enable charge pump
	* 1 :  Enable CP
	* 0 :  Disable CP
	*
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlCpEnSpi : 1;        /*## attribute CtlCpEnSpi */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: ctl_cp_replica_bias_en_spi
	* Description: Enable charge pump replica bias circuit (improve linearity)
	* 1 :  Enable CP replica bias
	* 0 :  Disable CP replica bias
	*
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlCpReplicaBiasEnSpi : 1;        /*## attribute CtlCpReplicaBiasEnSpi */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: ctl_cp_replica_bias_en_mux_ctrl
	* Description: Controls the replica bias enabling based on the digital statemachine or local value from ctl_cp_replica_bias_en_spi field
	*
	* 0 :  Controlled by statemachine i.e ctl_cp_replica_bias_en_spi is driven after the delay from timing engine statemachine
	* 1 :  ctl_cp_replica_bias_en_spi value is driven directly from the local spi field
	*
	* In the application context, the value should be set 0.
	*
	* Note: The actual enable of the replica bias happens after a delay which is controlled by CHIRP_BIAS_SWITCH_CONTROL in timing engine if this field is set as 0
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlCpReplicaBiasEnMuxCtrl : 1;        /*## attribute CtlCpReplicaBiasEnMuxCtrl */
	/**
	* BitsName: Reserved_4
	* Description: not used
	*/
	uint32_t Reserved4 : 3;        /*## attribute Reserved4 */
	/**
	* BitsName: ctl_cp_slice_en_1_spi
	* Description:
	* This control is applicable only when fast reset/gear switching is enabled. During reset time of the chirp, this slice setting is applied
	*
	* Enable cp slices (enable two slices 300uA). Every bit corresponds to one slice. This is selected when pll_cp_slice_ctrl output is 1'b1. The value in this field corresponds to the value during the reset of the chirp
	* NOTE: reset value pointing to all slices enabled (all ones)
	* Read/Write: RW
	* Bits: [27:20]
	* ResetValue: 0b11111111
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlCpSliceEn1Spi : 8;        /*## attribute CtlCpSliceEn1Spi */
	/**
	* BitsName: Reserved_5
	* Description: not used
	*/
	uint32_t Reserved5 : 4;        /*## attribute Reserved5 */
}R2M06_CpControlBits_t;
/**
* R2M06_VcoControlBits_t
* RegisterName: VCO_CONTROL
* Vco control settings
* Address: 0x004
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_sel_vco_1g_5g_spi
	* Description: selecting current source connected either to 1G or 2/4G VCO
	* 0 :  1GHz VCO selected
	* 1 :  4GHz  VCO selected
	*
	* - for 2GHz Bandwidth set ctl_vco_bandwidth_spi_profile*=0
	* - for 4GHz Bandwidth set ctl_vco_bandwidth_spi_profile*=1
	* Read/Write: RW
	* Bits: [1]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CtlSelVco1G5GSpi : 1;        /*## attribute CtlSelVco1G5GSpi */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 1;        /*## attribute Reserved2 */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 1;        /*## attribute Reserved3 */
	/**
	* BitsName: Reserved_4
	* Description: not used
	*/
	uint32_t Reserved4 : 3;        /*## attribute Reserved4 */
	/**
	* BitsName: Reserved_5
	* Description: not used
	*/
	uint32_t Reserved5 : 7;        /*## attribute Reserved5 */
	/**
	* BitsName: Reserved_6
	* Description: not used
	*/
	uint32_t Reserved6 : 5;        /*## attribute Reserved6 */
	/**
	* BitsName: Reserved_7
	* Description: not used
	*/
	uint32_t Reserved7 : 4;        /*## attribute Reserved7 */
	/**
	* BitsName: Reserved_8
	* Description: not used
	*/
	uint32_t Reserved8 : 1;        /*## attribute Reserved8 */
	/**
	* BitsName: Reserved_9
	* Description: not used
	*/
	uint32_t Reserved9 : 7;        /*## attribute Reserved9 */
}R2M06_VcoControlBits_t;
/**
* R2M06_VcoBufferLdoControlBits_t
* RegisterName: VCO_BUFFER_LDO_CONTROL
* Vco buffer ldo controls
* Address: 0x008
* ResetValue: 0x0000000F
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctl_ldo_vco_sel_vout_spi
	* Description: Select vout of VCO LDO. Value comes from OTP
	* Read/Write: RW
	* Bits: [4:0]
	* ResetValue: 0b01111
	* Source: OTP
	* FuSa: No
	*/
	uint32_t CtlLdoVcoSelVoutSpi : 5;        /*## attribute CtlLdoVcoSelVoutSpi */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 27;        /*## attribute Reserved0 */
}R2M06_VcoBufferLdoControlBits_t;
/**
* R2M06_CppfdLdoControlBits_t
* RegisterName: CPPFD_LDO_CONTROL
* Charge pump LDO settings
* Address: 0x00C
* ResetValue: 0x0000000F
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctl_ldo_cppfd_sel_vout_spi
	* Description: Select vout PFDCP LDO
	* Read/Write: RW
	* Bits: [4:0]
	* ResetValue: 0b01111
	* Source: OTP
	* FuSa: No
	*/
	uint32_t CtlLdoCppfdSelVoutSpi : 5;        /*## attribute CtlLdoCppfdSelVoutSpi */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 27;        /*## attribute Reserved0 */
}R2M06_CppfdLdoControlBits_t;
/**
* R2M06_DividerLdoControlBits_t
* RegisterName: DIVIDER_LDO_CONTROL
* Divider LDO settings
* Address: 0x010
* ResetValue: 0x0000000F
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctl_ldo_divider_sel_vout_spi
	* Description: Select vout  Divider LDO
	* Read/Write: RW
	* Bits: [4:0]
	* ResetValue: 0b01111
	* Source: OTP
	* FuSa: No
	*/
	uint32_t CtlLdoDividerSelVoutSpi : 5;        /*## attribute CtlLdoDividerSelVoutSpi */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 27;        /*## attribute Reserved0 */
}R2M06_DividerLdoControlBits_t;
/**
* R2M06_LdoEnControlBits_t
* RegisterName: LDO_EN_CONTROL
* Charge pump Phase Frequency Detector control settings
* Address: 0x014
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctl_ldo_cppfd_en_spi
	* Description: Enable PFDCP LDO
	* 1 :  Enable LDO
	* 0 :  Disable LDO
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlLdoCppfdEnSpi : 1;        /*## attribute CtlLdoCppfdEnSpi */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_ldo_divider_en_spi
	* Description: Enable Divider LDO
	* 1 :  Enable Divider LDO
	* 0 :  Disable Divider LDO
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlLdoDividerEnSpi : 1;        /*## attribute CtlLdoDividerEnSpi */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_ldo_vco_en_spi
	* Description: Enable VCO LDO
	* 1 :  Enable LDO
	* 0 :  Disable LDO
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlLdoVcoEnSpi : 1;        /*## attribute CtlLdoVcoEnSpi */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 23;        /*## attribute Reserved2 */
}R2M06_LdoEnControlBits_t;
/**
* R2M06_BiasBlockControlBits_t
* RegisterName: BIAS_BLOCK_CONTROL
* Bias settings
* Address: 0x018
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctl_ibias_div_350u_en_spi
	* Description: Enable current of the dividers
	* 1 :  Enable divider current
	* 0 :  Disable  divider current
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIbiasDiv350UEnSpi : 1;        /*## attribute CtlIbiasDiv350UEnSpi */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_ibias_bist_dac_200u_en_spi
	* Description: Enable current rms detector
	* 1 :  Enable rms detector
	* 0 :  Disable rms detector
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIbiasBistDac200UEnSpi : 1;        /*## attribute CtlIbiasBistDac200UEnSpi */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_ibias_cp_opamp_100u_en_spi
	* Description: Enable current of the CP opamp
	* 1 :  Enable current
	* 0 :  Disable current
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIbiasCpOpamp100UEnSpi : 1;        /*## attribute CtlIbiasCpOpamp100UEnSpi */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: ctl_ibias_idac_opamp_en_spi
	* Description: Enable current of the idac_opamp
	* 1 :  Enable idac_opamp
	* 0 :  Disable idac_opamp
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIbiasIdacOpampEnSpi : 1;        /*## attribute CtlIbiasIdacOpampEnSpi */
	/**
	* BitsName: ctl_ibias_idac_injpdac_en_spi
	* Description: Enable current of the idac injpdac
	* 1 :  Enable idac injpdac
	* 0 :  Disable idac injpdac
	* Read/Write: RW
	* Bits: [13]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIbiasIdacInjpdacEnSpi : 1;        /*## attribute CtlIbiasIdacInjpdacEnSpi */
	/**
	* BitsName: ctl_ibias_idac_injndac_en_spi
	* Description: Enable current of the idac injndac
	* 1 :  Enable idac injndac
	* 0 :  Disable idac injndac
	* Read/Write: RW
	* Bits: [14]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIbiasIdacInjndacEnSpi : 1;        /*## attribute CtlIbiasIdacInjndacEnSpi */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 1;        /*## attribute Reserved3 */
	/**
	* BitsName: ctl_ibias_rst_buffer_en_spi
	* Description: Enable current of the reset buffer
	* 1 :  Enable reset buffer
	* 0 :  Disable reset buffer
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIbiasRstBufferEnSpi : 1;        /*## attribute CtlIbiasRstBufferEnSpi */
	/**
	* BitsName: Reserved_4
	* Description: not used
	*/
	uint32_t Reserved4 : 3;        /*## attribute Reserved4 */
	/**
	* BitsName: ctl_ibias_ld_10u_en_spi
	* Description: Enable current of the Lock detector
	* 1 :  Enable lock detector
	* 0 :  Disable lock detector
	* Read/Write: RW
	* Bits: [20]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIbiasLd10UEnSpi : 1;        /*## attribute CtlIbiasLd10UEnSpi */
	/**
	* BitsName: Reserved_5
	* Description: not used
	*/
	uint32_t Reserved5 : 3;        /*## attribute Reserved5 */
	/**
	* BitsName: ctl_ibias_vam_100u_en_spi
	* Description: Enable current of the VCO amplitude monitor
	* 1 :  Enable vco amplitude monitor
	* 0 :  Disable vco amplitude monitor
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIbiasVam100UEnSpi : 1;        /*## attribute CtlIbiasVam100UEnSpi */
	/**
	* BitsName: Reserved_6
	* Description: not used
	*/
	uint32_t Reserved6 : 3;        /*## attribute Reserved6 */
	/**
	* BitsName: ctl_ibias_tvn_20u_en_spi
	* Description: Enable current of the Tuning Voltage Monitor
	* 1 :  Enable tune current
	* 0 :  Disable tune current
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIbiasTvn20UEnSpi : 1;        /*## attribute CtlIbiasTvn20UEnSpi */
	/**
	* BitsName: Reserved_7
	* Description: not used
	*/
	uint32_t Reserved7 : 2;        /*## attribute Reserved7 */
	/**
	* BitsName: ctl_ibias_en_spi
	* Description: Enable all the biasing block
	* 1 :  Enable Bias
	* 0 :  Disable Bias
	* Read/Write: RW
	* Bits: [31]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIbiasEnSpi : 1;        /*## attribute CtlIbiasEnSpi */
}R2M06_BiasBlockControlBits_t;
/**
* R2M06_BufferControlBits_t
* RegisterName: BUFFER_CONTROL
* REF Buffer settings
* Address: 0x01C
* ResetValue: 0x00000110
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctl_buffer_480meg_pol_spi
	* Description: Select signal polarity 480MHz buffer (in case it is balanced 0 degrees or 180 degrees)
	* 1 :  180 degree
	* 0 :  0 degree (reset value for costumers)
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlBuffer480MegPolSpi : 1;        /*## attribute CtlBuffer480MegPolSpi */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_buffer_480meg_bal_spi
	* Description: Select balanced or unbalanced signal 480MHz buffer (used for debugging)
	* 1 :  balanced (reset value for costumers)
	* 0 :  unbalanced
	*
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlBuffer480MegBalSpi : 1;        /*## attribute CtlBuffer480MegBalSpi */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_buffer_480meg_en_spi
	* Description: Enable 480MHz buffer
	* 1 :  Enable 480MHz buffer
	* 0 :  Disable 480MHz buffer
	*
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlBuffer480MegEnSpi : 1;        /*## attribute CtlBuffer480MegEnSpi */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 23;        /*## attribute Reserved2 */
}R2M06_BufferControlBits_t;
/**
* R2M06_PllFastResetInjEnControlBits_t
* RegisterName: PLL_FAST_RESET_INJ_EN_CONTROL
* This register is used to control the settings for fast reset alias gear switching. Please refer Chirp_Afc_Information Tab
* Address: 0x020
* ResetValue: 0x00000011
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: pll_inj_dis
	* Description: Disable fast reset current injection
	*
	* 1 : Disable fast reset current injection
	* 0 : Enable fast reset current injection
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllInjDis : 1;        /*## attribute PllInjDis */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: pll_gs_dis
	* Description: Disable fast reset gear-switching
	*
	* 1 : Disable fast reset gear switching
	* 0 : Enable fast reset  gear switching
	*
	* NOTE: reset value pointing to gear-switching disabled, this setting will overrule other controls by: gs forced to 0, selectors forced to gs, lpf controls pll_lpf_c?_a|b_ctrl* not affected
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllGsDis : 1;        /*## attribute PllGsDis */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 27;        /*## attribute Reserved1 */
}R2M06_PllFastResetInjEnControlBits_t;
/**
* R2M06_PllFastResetTimingControlBits_t
* RegisterName: PLL_FAST_RESET_TIMING_CONTROL
* This register is used to control the settings for fast reset alias gear switching (gs). This register settings are applicable only when pll_gs_dis = 0 in the register PLL_FAST_RESET_INJ_EN_CONTROL. The fast reset is also called fast return. Please refer Chirp_Afc_Information Tab
* Address: 0x024
* ResetValue: 0x00000014
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 8;        /*## attribute Reserved0 */
	/**
	* BitsName: pll_gs_delay
	* Description: gs signal is generated either at the start of jump back timer or at the expiry of the jump back timer i.e at the chirp reset state. This field defines the delay of the gs signal generation from the above points.
	*
	* The selection of the start point is defined by the bit31 in the same register
	*
	* The delay is represented in cycles of 480MHz clock.
	* Supported values from 0 to 1 us
	*
	* Read/Write: RW
	* Bits: [16:8]
	* ResetValue: 0b000000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllGsDelay : 9;        /*## attribute PllGsDelay */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: pll_gs_sync_up_ctrl
	* Description: Controls the gs generation after synchronizing with PLL CP Mirror UP  pulse.
	* 1'b0 : Pass the gs synchronized with PLL UP pulse
	* 1'b1 : Pass the inverted  gs synchronized with PLL UP pulse (for debug)
	* Read/Write: RW
	* Bits: [20]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllGsSyncUpCtrl : 1;        /*## attribute PllGsSyncUpCtrl */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: pll_gs_sync_down_ctrl
	* Description: Controls the gs generation after synchronizing with PLL CP Mirror DN  pulse.
	* 1'b0 : Pass the gs synchronized with PLL DN pulse
	* 1'b1 : Pass the inverted  gs synchronized with PLL DN pulse (for debug)
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllGsSyncDownCtrl : 1;        /*## attribute PllGsSyncDownCtrl */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: pll_gs_ctrl
	* Description: Controls the gs signal generation
	* 2'b00 :  gs driven Low - gs disabled, pll bandwidth low
	* 2'b01 :  gs driven High - gs disabled, pll bandwidth high
	* 2'b10 :  Pass the generated gs signal - gs enabled, pll bandwidth low acq, high in reset
	* 2'b11 :  Pass the generated gs after Invert - gs enabled, pll bandwidth high acq, low in reset
	* Read/Write: RW
	* Bits: [29:28]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllGsCtrl : 2;        /*## attribute PllGsCtrl */
	/**
	* BitsName: Reserved_4
	* Description: not used
	*/
	uint32_t Reserved4 : 1;        /*## attribute Reserved4 */
	/**
	* BitsName: pll_gs_start_ctrl
	* Description: Pll gs pulse generation start point
	*
	* 0 : Start of Jump back timer
	* 1 : End of Jump back timer i.e start of reset
	* Read/Write: RW
	* Bits: [31]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllGsStartCtrl : 1;        /*## attribute PllGsStartCtrl */
}R2M06_PllFastResetTimingControlBits_t;
/**
* R2M06_CpFastResetSliceControlBits_t
* RegisterName: CP_FAST_RESET_SLICE_CONTROL
* This register is used to control the timing for the cp slices in the gear switch enabled mode. This register settings are applicable only when pll_gs_dis = 0 in the register PLL_FAST_RESET_INJ_EN_CONTROL. The fast reset is also called fast return. Please refer Chirp_Afc_Information Tab
* Address: 0x028
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: pll_cp_slice_ctrl
	* Description: Slice enabling timing control with gear switching functionality. Possible to drive directly from timing engine or to use sync block within PLL that observes UP or DN pulses of the PFD.
	*
	* pll_cp_slice_ctrl = control for gs of cp slices
	* The final slice value (ctl_cp_slice_en_spi) driven based on gs selector bit  i.e ctl_cp_slice_en_0 or ctl_cp_slice_en_1 is selected based on the way gs signal is configured using the following settings
	*
	* 2'b00 :  gs signal from timing engine directly used as selector (default)
	* 2'b01 :  gs synchronized with PLL UP pulse used as selector
	* 2'b10 :  gs synchronized with PLL DN pulse used as selector
	* 2'b11 :  same functionality as 2'b00
	*
	* NOTE: reset value pointing to gs signal used as a selector
	* Read/Write: RW
	* Bits: [1:0]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllCpSliceCtrl : 2;        /*## attribute PllCpSliceCtrl */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 30;        /*## attribute Reserved0 */
}R2M06_CpFastResetSliceControlBits_t;
/**
* R2M06_PllLpfCapGsSelControlBits_t
* RegisterName: PLL_LPF_CAP_GS_SEL_CONTROL
* This register is used to control the settings for lpf capacitors (C1,C2,C3) in the gear switch enabled mode. This register settings are applicable only when pll_gs_dis = 0 in the register PLL_FAST_RESET_INJ_EN_CONTROL. The fast reset is also called fast return. Please refer Chirp_Afc_Information Tab
* Address: 0x02C
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: pll_lpf_cap_gs_sel_ctrl
	* Description: LPF Capacitance enabling timing control with gear switching functionality. Possible to drive directly from timing engine or to use sync block within PLL that observes UP or DN pulses of the PFD.
	*
	* The third stage of gs signal generation
	*
	* 2'b00 :  gs signal is used directly from timing engine (default)
	* 2'b01 :  gs synchronized with PLL UP pulse is used as selector
	* 2'b10 :  gs synchronized with PLL DN pulse is used as selector
	* 2'b11 :  same functionality as 2'b00
	*
	* NOTE: reset value pointing to gs signal as a selector
	* Read/Write: RW
	* Bits: [1:0]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfCapGsSelCtrl : 2;        /*## attribute PllLpfCapGsSelCtrl */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 30;        /*## attribute Reserved0 */
}R2M06_PllLpfCapGsSelControlBits_t;
/**
* R2M06_PllDacInjAcqControlBits_t
* RegisterName: PLL_DAC_INJ_ACQ_CONTROL
* This register is used to control the settings of the dac injection current settings (profiles) during the acquisition.  This register settings are applicable only when pll_inj_dis = 0 in the register PLL_FAST_RESET_INJ_EN_CONTROL. The fast reset is also called fast return. Please refer Chirp_Afc_Information Tab
* Address: 0x030
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: pll_dac_inj_acq_delay
	* Description: The dac_inj_acq signal is generated during the acquisition period and stays high during the tsettle + tacq.
	* This field defines the delay of the dac_inj_acq signal from the start point tsettle.
	*
	* The delay is represented in cycles of 480MHz clock.
	* Supported values from 0 to 1 us
	* NOTE: reset value pointing to no injection delay, pll_dac_inj_acq_delay = 0;
	* Read/Write: RW
	* Bits: [8:0]
	* ResetValue: 0b000000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllDacInjAcqDelay : 9;        /*## attribute PllDacInjAcqDelay */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: pll_dac_inj_acq_ctrl
	* Description:
	* Controls the dac_inj_acq signal generation
	* 2'b00 : dac_inj_acq driven Low - timing engine not used (static case, injection current continuously disabled)
	* 2'b01 : dac_inj_acq driven High - timing engine not used (static case,  injection current continuously enabled)
	* 2'b10 : Pass the generated dac_inj_acq signal from timing engine
	* 2'b11 : Pass the generated dac_inj_acq inverted signal from timing engine
	* Read/Write: RW
	* Bits: [13:12]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllDacInjAcqCtrl : 2;        /*## attribute PllDacInjAcqCtrl */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: pll_fr_idac_polarity
	* Description: IDAC polarity
	*
	* 0: Negative polarity - idac sourcing in acq, sinking in rst (vtune rising in acq, falling in rst)
	* 1: Positive polarity - idac sinking in acq, sourcing in rst (vtune falling in acq, rising in rst)
	* debug and flexibility purposes
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllFrIdacPolarity : 1;        /*## attribute PllFrIdacPolarity */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 15;        /*## attribute Reserved2 */
}R2M06_PllDacInjAcqControlBits_t;
/**
* R2M06_PllDacInjRstControlBits_t
* RegisterName: PLL_DAC_INJ_RST_CONTROL
* This register is used to control the settings of the dac injection current during the reset. This register settings are applicable only when pll_inj_dis = 0 in the register PLL_FAST_RESET_INJ_EN_CONTROL. The fast reset is also called fast return. Please refer Chirp_Afc_Information Tab
* Address: 0x034
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: pll_dac_inj_rst_delay
	* Description: The dac_inj_rst signal is generated either at the start of jump back timer or at the expiry of the jump back timer i.e at the chirp reset state. This field defines the delay of the dac_inj_rst signal generation from the above points (Only valid if directly driven from timing engine)
	*
	* The selection of the start point is defined by the bit31 in the same register
	*
	* The delay is represented in cycles of 480MHz clock.
	* Supported values from 0 to 1 us
	* NOTE: reset value pointing to no delay, pll_dac_inj_rst_delay = 0
	* Read/Write: RW
	* Bits: [8:0]
	* ResetValue: 0b000000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllDacInjRstDelay : 9;        /*## attribute PllDacInjRstDelay */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: pll_dac_inj_rst_sync_up_ctrl
	* Description: Controls polarity of PLL UP sinc signal
	* 1'b0 : Pass the PLL UP signal synchronized dac_inj_rst
	* 1'b1 : Pass the PLL UP signal synchronized dac_inj_rst after invert
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllDacInjRstSyncUpCtrl : 1;        /*## attribute PllDacInjRstSyncUpCtrl */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: pll_dac_inj_rst_sync_down_ctrl
	* Description: Controls polarity of PLL DN sinc signal
	* 1'b0 : Pass the PLL DN signal synchronized dac_inj_rst
	* 1'b1 : Pass the PLL DN signal synchronized dac_inj_rst after invert
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllDacInjRstSyncDownCtrl : 1;        /*## attribute PllDacInjRstSyncDownCtrl */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: pll_dac_inj_rst_ctrl
	* Description: dac_inj_rst timing engine signal generation control (timing engine mux)
	* Select how timing engine will be used for injection dac during reset:
	* 2'b00 : dac_inj_rst driven Low - timing engine not used (static case,  injection current continuously disabled)
	* 2'b01 : dac_inj_rst driven High - timing engine not used (static case,  injection current continuously enabled)
	* 2'b10 : Pass the generated dac_inj_rst signal from timing engine
	* 2'b11 : Pass the generated dac_inj_rst inverted signal from timing engine
	* Read/Write: RW
	* Bits: [21:20]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllDacInjRstCtrl : 2;        /*## attribute PllDacInjRstCtrl */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 2;        /*## attribute Reserved3 */
	/**
	* BitsName: pll_dac_inj_rst_output_ctrl
	* Description: This control defines if the timing of injection DAC during reset is controlled by timing engine directly or that is synchronized to internal PLL UP or DN pulse
	*
	* 2'b00 :  dac_inj_rst signal is used directly from timing engine (default)
	* 2'b01 :  dac_inj_rst signal synchronized with PLL UP pulse
	* 2'b10 :  dac_inj_rst synchronized with PLL DN pulse
	* 2'b11 :  same functionality as 2'b00
	*
	* NOTE: reset value pointing to second stage control (timing engine mux)
	* Read/Write: RW
	* Bits: [25:24]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllDacInjRstOutputCtrl : 2;        /*## attribute PllDacInjRstOutputCtrl */
	/**
	* BitsName: Reserved_4
	* Description: not used
	*/
	uint32_t Reserved4 : 5;        /*## attribute Reserved4 */
	/**
	* BitsName: pll_dac_inj_rst_start_ctrl
	* Description: dac_inj_rst pulse generation start point
	*
	* 0 : Start of Jump back timer
	* 1 : End of Jump back timer i.e start of reset
	* Read/Write: RW
	* Bits: [31]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllDacInjRstStartCtrl : 1;        /*## attribute PllDacInjRstStartCtrl */
}R2M06_PllDacInjRstControlBits_t;
/**
* R2M06_PllDacInjIbiasControlBits_t
* RegisterName: PLL_DAC_INJ_IBIAS_CONTROL
* This register is used to control the ibias current ramp up during the end of the acqusition phase to enable the fast settling of the charge pump with slice change during reset. Applicable only for fast return/fast reset is enabled
* Address: 0x038
* ResetValue: 0x00000020
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: pll_dac_inj_ibias_ramp_num_steps
	* Description: The number of ibias current ramp steps required to reach ibias threshold before the reset.
	* The ibias current is incremented from 0, in number of steps during the end of the acquisition to reach the threshold before the reset starts. This enables the fast settling of the CP slice switch. The programmed steps are with 25 ns resolution i.e Ibias_ramp = pll_dac_inj_ibias_ramp_num_steps * ibias_step. Actually ibias step is the ibias current step in ua(TBD).
	* Ideally 32 steps (0.8 us) required to reach the ibias threshold
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00100000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllDacInjIbiasRampNumSteps : 8;        /*## attribute PllDacInjIbiasRampNumSteps */
	/**
	* BitsName: pll_dac_inj_ibias_ramp_en
	* Description: Control to enable the fast settling of charge pump by enabling the ibias current ramp during the end of the acquisition phase
	* 1'b0 : Disable the ibias current ramp
	* 1'b1 : Enable the ibias current ramp
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllDacInjIbiasRampEn : 1;        /*## attribute PllDacInjIbiasRampEn */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 23;        /*## attribute Reserved0 */
}R2M06_PllDacInjIbiasControlBits_t;
/**
* R2M06_CpPllbwCfg0Bits_t
* RegisterName: CP_PLLBW_CFG0
* Chargepump profile settings
* Address: 0x050
* ResetValue: 0x00300001
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctl_cp_slice_en_0_pllbw_cfg0
	* Description: Enable cp slices (each slice output level is controlled by ctl_ibias_cp_150u_spi setting ). Every bit corresponds to one slice. This register is valid when pll_cp_slice_ctrl output is 0 (corresponds to the acquisition of the chirp, Tsettling+Tacq)
	* NOTE: reset value pointing to single slice enabled
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00000001
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlCpSliceEn0PllbwCfg0 : 8;        /*## attribute CtlCpSliceEn0PllbwCfg0 */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 8;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_ibias_cp_150u_spi_pllbw_cfg0
	* Description: Program current of the CP
	*
	* This is current that goes into CP, programmable between 0 and ~197u
	* current=ctl_ibias_cp_150u_spi x 3.125u
	* Read/Write: RW
	* Bits: [21:16]
	* ResetValue: 0b110000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIbiasCp150USpiPllbwCfg0 : 6;        /*## attribute CtlIbiasCp150USpiPllbwCfg0 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_cp_ioffset_updn_spi_pllbw_cfg0
	* Description: Direction of the charge pump offset
	* 1 :  Pmos inject current
	* 0 :  Nmos substract current
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlCpIoffsetUpdnSpiPllbwCfg0 : 1;        /*## attribute CtlCpIoffsetUpdnSpiPllbwCfg0 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: ctl_cp_ioffset_set_spi_pllbw_cfg0
	* Description: charge pump offset, bit wise programming, polarity given by 'ctl_cp_ioffset_updn_spi_profile*':
	* [7]=+35%; [6]=+30% ;[5]=+25%; [4]=+20%; [3]=+15%;[2]=+10%; [1]=+5%; [0]=0%
	* Read/Write: RW
	* Bits: [30:28]
	* ResetValue: 0b000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlCpIoffsetSetSpiPllbwCfg0 : 3;        /*## attribute CtlCpIoffsetSetSpiPllbwCfg0 */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 1;        /*## attribute Reserved3 */
}R2M06_CpPllbwCfg0Bits_t;
/**
* R2M06_PllLpfC1PllbwCfg0Bits_t
* RegisterName: PLL_LPF_C1_PLLBW_CFG0
* This register controls LPF C1 (Cap) bank
* Address: 0x054
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: pll_lpf_c1_acq_ctrl_pllbw_cfg0
	* Description: LPF C1 setting during acq (low BW)
	*
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC1AcqCtrlPllbwCfg0 : 8;        /*## attribute PllLpfC1AcqCtrlPllbwCfg0 */
	/**
	* BitsName: pll_lpf_c1_rst_ctrl_pllbw_cfg0
	* Description: LPF C1 setting during rst (high BW)
	* Read/Write: RW
	* Bits: [15:8]
	* ResetValue: 0b00000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC1RstCtrlPllbwCfg0 : 8;        /*## attribute PllLpfC1RstCtrlPllbwCfg0 */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 16;        /*## attribute Reserved0 */
}R2M06_PllLpfC1PllbwCfg0Bits_t;
/**
* R2M06_PllLpfC2PllbwCfg0Bits_t
* RegisterName: PLL_LPF_C2_PLLBW_CFG0
* This register controls LPF C2 (Cap) bank
* Address: 0x058
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: pll_lpf_c2_acq_ctrl_pllbw_cfg0
	* Description: LPF C2 setting during acq (low BW)
	*
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC2AcqCtrlPllbwCfg0 : 8;        /*## attribute PllLpfC2AcqCtrlPllbwCfg0 */
	/**
	* BitsName: pll_lpf_c2_rst_ctrl_pllbw_cfg0
	* Description: LPF C2 setting during rst (high BW)
	* Read/Write: RW
	* Bits: [15:8]
	* ResetValue: 0b00000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC2RstCtrlPllbwCfg0 : 8;        /*## attribute PllLpfC2RstCtrlPllbwCfg0 */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 16;        /*## attribute Reserved0 */
}R2M06_PllLpfC2PllbwCfg0Bits_t;
/**
* R2M06_PllLpfC3PllbwCfg0Bits_t
* RegisterName: PLL_LPF_C3_PLLBW_CFG0
* This register controls LPF C3 (Cap) bank
* Address: 0x05C
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: pll_lpf_c3_acq_ctrl_pllbw_cfg0
	* Description: LPF C3 setting during acq (low BW)
	*
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC3AcqCtrlPllbwCfg0 : 8;        /*## attribute PllLpfC3AcqCtrlPllbwCfg0 */
	/**
	* BitsName: pll_lpf_c3_rst_ctrl_pllbw_cfg0
	* Description: LPF C3 setting during rst (high BW)
	* Read/Write: RW
	* Bits: [15:8]
	* ResetValue: 0b00000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC3RstCtrlPllbwCfg0 : 8;        /*## attribute PllLpfC3RstCtrlPllbwCfg0 */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 16;        /*## attribute Reserved0 */
}R2M06_PllLpfC3PllbwCfg0Bits_t;
/**
* R2M06_PllLpfResPllbwCfg0Bits_t
* RegisterName: PLL_LPF_RES_PLLBW_CFG0
* settings for FILTER
* Address: 0x060
* ResetValue: 0x00001616
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctl_lpf_r1_spi_pllbw_cfg0
	* Description: Select loop filter res. R1
	* Read/Write: RW
	* Bits: [4:0]
	* ResetValue: 0b10110
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlLpfR1SpiPllbwCfg0 : 5;        /*## attribute CtlLpfR1SpiPllbwCfg0 */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 5;        /*## attribute Reserved1 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 19;        /*## attribute Reserved2 */
}R2M06_PllLpfResPllbwCfg0Bits_t;
/**
* R2M06_CpPllbwCfg1Bits_t
* RegisterName: CP_PLLBW_CFG1
* Chargepump profile settings
* Address: 0x070
* ResetValue: 0x00300001
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctl_cp_slice_en_0_pllbw_cfg1
	* Description: Enable cp slices (one slice is equal to ctl_ibias_cp_150u_spi setting ).. Every bit corresponds to one slice. This is selected when pll_cp_slice_ctrl output is 0.  The value in this field corresponds to the value during the acquisition of the chirp
	* NOTE: reset value pointing to one slice enabled (single one)
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00000001
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlCpSliceEn0PllbwCfg1 : 8;        /*## attribute CtlCpSliceEn0PllbwCfg1 */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 8;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_ibias_cp_150u_spi_pllbw_cfg1
	* Description: Program current of the CP
	*
	* This is current that goes into CP, programmable between 0 and ~197u
	* current=ctl_ibias_cp_150u_spi x 3.125u
	* Read/Write: RW
	* Bits: [21:16]
	* ResetValue: 0b110000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIbiasCp150USpiPllbwCfg1 : 6;        /*## attribute CtlIbiasCp150USpiPllbwCfg1 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_cp_ioffset_updn_spi_pllbw_cfg1
	* Description: Direction of the charge pump offset
	* 1 :  Pmos inject current
	* 0 :  Nmos substract current
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlCpIoffsetUpdnSpiPllbwCfg1 : 1;        /*## attribute CtlCpIoffsetUpdnSpiPllbwCfg1 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: ctl_cp_ioffset_set_spi_pllbw_cfg1
	* Description: charge pump offset, bit wise programming, polarity given by 'ctl_cp_ioffset_updn_spi_profile*':
	* [7]=+35%; [6]=+30% ;[5]=+25%; [4]=+20%; [3]=+15%;[2]=+10%; [1]=+5%; [0]=0%
	* Read/Write: RW
	* Bits: [30:28]
	* ResetValue: 0b000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlCpIoffsetSetSpiPllbwCfg1 : 3;        /*## attribute CtlCpIoffsetSetSpiPllbwCfg1 */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 1;        /*## attribute Reserved3 */
}R2M06_CpPllbwCfg1Bits_t;
/**
* R2M06_PllLpfC1PllbwCfg1Bits_t
* RegisterName: PLL_LPF_C1_PLLBW_CFG1
* This register controls LPF C1 (Cap) bank
* Address: 0x074
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: pll_lpf_c1_acq_ctrl_pllbw_cfg1
	* Description: LPF C1 setting during acq (low BW)
	*
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC1AcqCtrlPllbwCfg1 : 8;        /*## attribute PllLpfC1AcqCtrlPllbwCfg1 */
	/**
	* BitsName: pll_lpf_c1_rst_ctrl_pllbw_cfg1
	* Description: LPF C1 setting during rst (high BW)
	* Read/Write: RW
	* Bits: [15:8]
	* ResetValue: 0b00000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC1RstCtrlPllbwCfg1 : 8;        /*## attribute PllLpfC1RstCtrlPllbwCfg1 */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 16;        /*## attribute Reserved0 */
}R2M06_PllLpfC1PllbwCfg1Bits_t;
/**
* R2M06_PllLpfC2PllbwCfg1Bits_t
* RegisterName: PLL_LPF_C2_PLLBW_CFG1
* This register controls LPF C2 (Cap) bank
* Address: 0x078
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: pll_lpf_c2_acq_ctrl_pllbw_cfg1
	* Description: LPF C2 setting during acq (low BW)
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC2AcqCtrlPllbwCfg1 : 8;        /*## attribute PllLpfC2AcqCtrlPllbwCfg1 */
	/**
	* BitsName: pll_lpf_c2_rst_ctrl_pllbw_cfg1
	* Description: LPF C2 setting during rst (high BW)
	* Read/Write: RW
	* Bits: [15:8]
	* ResetValue: 0b00000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC2RstCtrlPllbwCfg1 : 8;        /*## attribute PllLpfC2RstCtrlPllbwCfg1 */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 16;        /*## attribute Reserved0 */
}R2M06_PllLpfC2PllbwCfg1Bits_t;
/**
* R2M06_PllLpfC3PllbwCfg1Bits_t
* RegisterName: PLL_LPF_C3_PLLBW_CFG1
* This register controls LPF C3 (Cap) bank
* Address: 0x07C
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: pll_lpf_c3_acq_ctrl_pllbw_cfg1
	* Description: LPF C3 setting during acq (low BW)
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC3AcqCtrlPllbwCfg1 : 8;        /*## attribute PllLpfC3AcqCtrlPllbwCfg1 */
	/**
	* BitsName: pll_lpf_c3_rst_ctrl_pllbw_cfg1
	* Description: LPF C3 setting during rst (high BW)
	* Read/Write: RW
	* Bits: [15:8]
	* ResetValue: 0b00000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC3RstCtrlPllbwCfg1 : 8;        /*## attribute PllLpfC3RstCtrlPllbwCfg1 */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 16;        /*## attribute Reserved0 */
}R2M06_PllLpfC3PllbwCfg1Bits_t;
/**
* R2M06_PllLpfResPllbwCfg1Bits_t
* RegisterName: PLL_LPF_RES_PLLBW_CFG1
* settings for FILTER
* Address: 0x080
* ResetValue: 0x00001616
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctl_lpf_r1_spi_pllbw_cfg1
	* Description: Select loop filter res. R1
	* Read/Write: RW
	* Bits: [4:0]
	* ResetValue: 0b10110
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlLpfR1SpiPllbwCfg1 : 5;        /*## attribute CtlLpfR1SpiPllbwCfg1 */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 5;        /*## attribute Reserved1 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 19;        /*## attribute Reserved2 */
}R2M06_PllLpfResPllbwCfg1Bits_t;
/**
* R2M06_CpPllbwCfg2Bits_t
* RegisterName: CP_PLLBW_CFG2
* Chargepump profile settings
* Address: 0x090
* ResetValue: 0x00300001
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctl_cp_slice_en_0_pllbw_cfg2
	* Description: Enable cp slices (one slice is equal to ctl_ibias_cp_150u_spi setting ).. Every bit corresponds to one slice. This is selected when pll_cp_slice_ctrl output is 0.  The value in this field corresponds to the value during the acquisition of the chirp
	* NOTE: reset value pointing to one slice enabled (single one)
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00000001
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlCpSliceEn0PllbwCfg2 : 8;        /*## attribute CtlCpSliceEn0PllbwCfg2 */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 8;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_ibias_cp_150u_spi_pllbw_cfg2
	* Description: Program current of the CP
	*
	* This is current that goes into CP, programmable between 0 and ~197u
	* current=ctl_ibias_cp_150u_spi x 3.125u
	* Read/Write: RW
	* Bits: [21:16]
	* ResetValue: 0b110000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIbiasCp150USpiPllbwCfg2 : 6;        /*## attribute CtlIbiasCp150USpiPllbwCfg2 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_cp_ioffset_updn_spi_pllbw_cfg2
	* Description: Direction of the charge pump offset
	* 1 :  Pmos inject current
	* 0 :  Nmos substract current
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlCpIoffsetUpdnSpiPllbwCfg2 : 1;        /*## attribute CtlCpIoffsetUpdnSpiPllbwCfg2 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: ctl_cp_ioffset_set_spi_pllbw_cfg2
	* Description: charge pump offset, bit wise programming, polarity given by 'ctl_cp_ioffset_updn_spi_profile*':
	* [7]=+35%; [6]=+30% ;[5]=+25%; [4]=+20%; [3]=+15%;[2]=+10%; [1]=+5%; [0]=0%
	* Read/Write: RW
	* Bits: [30:28]
	* ResetValue: 0b000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlCpIoffsetSetSpiPllbwCfg2 : 3;        /*## attribute CtlCpIoffsetSetSpiPllbwCfg2 */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 1;        /*## attribute Reserved3 */
}R2M06_CpPllbwCfg2Bits_t;
/**
* R2M06_PllLpfC1PllbwCfg2Bits_t
* RegisterName: PLL_LPF_C1_PLLBW_CFG2
* This register controls LPF C1 (Cap) bank
* Address: 0x094
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: pll_lpf_c1_acq_ctrl_pllbw_cfg2
	* Description: LPF C1 setting during acq (low BW)
	*
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC1AcqCtrlPllbwCfg2 : 8;        /*## attribute PllLpfC1AcqCtrlPllbwCfg2 */
	/**
	* BitsName: pll_lpf_c1_rst_ctrl_pllbw_cfg2
	* Description: LPF C1 setting during rst (high BW)
	* Read/Write: RW
	* Bits: [15:8]
	* ResetValue: 0b00000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC1RstCtrlPllbwCfg2 : 8;        /*## attribute PllLpfC1RstCtrlPllbwCfg2 */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 16;        /*## attribute Reserved0 */
}R2M06_PllLpfC1PllbwCfg2Bits_t;
/**
* R2M06_PllLpfC2PllbwCfg2Bits_t
* RegisterName: PLL_LPF_C2_PLLBW_CFG2
* This register controls LPF C2 (Cap) bank
* Address: 0x098
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: pll_lpf_c2_acq_ctrl_pllbw_cfg2
	* Description: LPF C2 setting during acq (low BW)
	*
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC2AcqCtrlPllbwCfg2 : 8;        /*## attribute PllLpfC2AcqCtrlPllbwCfg2 */
	/**
	* BitsName: pll_lpf_c2_rst_ctrl_pllbw_cfg2
	* Description: LPF C2 setting during rst (high BW)
	* Read/Write: RW
	* Bits: [15:8]
	* ResetValue: 0b00000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC2RstCtrlPllbwCfg2 : 8;        /*## attribute PllLpfC2RstCtrlPllbwCfg2 */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 16;        /*## attribute Reserved0 */
}R2M06_PllLpfC2PllbwCfg2Bits_t;
/**
* R2M06_PllLpfC3PllbwCfg2Bits_t
* RegisterName: PLL_LPF_C3_PLLBW_CFG2
* This register controls LPF C3 (Cap) bank
* Address: 0x09C
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: pll_lpf_c3_acq_ctrl_pllbw_cfg2
	* Description: LPF C3 setting during acq (low BW)
	*
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC3AcqCtrlPllbwCfg2 : 8;        /*## attribute PllLpfC3AcqCtrlPllbwCfg2 */
	/**
	* BitsName: pll_lpf_c3_rst_ctrl_pllbw_cfg2
	* Description: LPF C3 setting during rst (high BW)
	* Read/Write: RW
	* Bits: [15:8]
	* ResetValue: 0b00000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC3RstCtrlPllbwCfg2 : 8;        /*## attribute PllLpfC3RstCtrlPllbwCfg2 */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 16;        /*## attribute Reserved0 */
}R2M06_PllLpfC3PllbwCfg2Bits_t;
/**
* R2M06_PllLpfResPllbwCfg2Bits_t
* RegisterName: PLL_LPF_RES_PLLBW_CFG2
* settings for FILTER
* Address: 0x0A0
* ResetValue: 0x00001616
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctl_lpf_r1_spi_pllbw_cfg2
	* Description: Select loop filter res. R1
	* Read/Write: RW
	* Bits: [4:0]
	* ResetValue: 0b10110
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlLpfR1SpiPllbwCfg2 : 5;        /*## attribute CtlLpfR1SpiPllbwCfg2 */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 5;        /*## attribute Reserved1 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 19;        /*## attribute Reserved2 */
}R2M06_PllLpfResPllbwCfg2Bits_t;
/**
* R2M06_CpPllbwCfg3Bits_t
* RegisterName: CP_PLLBW_CFG3
* Chargepump profile settings
* Address: 0x0B0
* ResetValue: 0x00300001
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctl_cp_slice_en_0_pllbw_cfg3
	* Description: Enable cp slices (one slice is equal to ctl_ibias_cp_150u_spi setting ).. Every bit corresponds to one slice. This is selected when pll_cp_slice_ctrl output is 0.  The value in this field corresponds to the value during the acquisition of the chirp
	* NOTE: reset value pointing to one slice enabled (single one)
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00000001
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlCpSliceEn0PllbwCfg3 : 8;        /*## attribute CtlCpSliceEn0PllbwCfg3 */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 8;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_ibias_cp_150u_spi_pllbw_cfg3
	* Description: Program current of the CP
	*
	* This is current that goes into CP, programmable between 0 and ~197u
	* current=ctl_ibias_cp_150u_spi x 3.125u
	* Read/Write: RW
	* Bits: [21:16]
	* ResetValue: 0b110000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIbiasCp150USpiPllbwCfg3 : 6;        /*## attribute CtlIbiasCp150USpiPllbwCfg3 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_cp_ioffset_updn_spi_pllbw_cfg3
	* Description: Direction of the charge pump offset
	* 1 :  Pmos inject current
	* 0 :  Nmos substract current
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlCpIoffsetUpdnSpiPllbwCfg3 : 1;        /*## attribute CtlCpIoffsetUpdnSpiPllbwCfg3 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: ctl_cp_ioffset_set_spi_pllbw_cfg3
	* Description: charge pump offset, bit wise programming, polarity given by 'ctl_cp_ioffset_updn_spi_profile*':
	* [7]=+35%; [6]=+30% ;[5]=+25%; [4]=+20%; [3]=+15%;[2]=+10%; [1]=+5%; [0]=0%
	* Read/Write: RW
	* Bits: [30:28]
	* ResetValue: 0b000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlCpIoffsetSetSpiPllbwCfg3 : 3;        /*## attribute CtlCpIoffsetSetSpiPllbwCfg3 */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 1;        /*## attribute Reserved3 */
}R2M06_CpPllbwCfg3Bits_t;
/**
* R2M06_PllLpfC1PllbwCfg3Bits_t
* RegisterName: PLL_LPF_C1_PLLBW_CFG3
* This register controls LPF C1 (Cap) bank
* Address: 0x0B4
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: pll_lpf_c1_acq_ctrl_pllbw_cfg3
	* Description: LPF C1 setting during acq (low BW)
	*
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC1AcqCtrlPllbwCfg3 : 8;        /*## attribute PllLpfC1AcqCtrlPllbwCfg3 */
	/**
	* BitsName: pll_lpf_c1_rst_ctrl_pllbw_cfg3
	* Description: LPF C1 setting during rst (high BW)
	* Read/Write: RW
	* Bits: [15:8]
	* ResetValue: 0b00000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC1RstCtrlPllbwCfg3 : 8;        /*## attribute PllLpfC1RstCtrlPllbwCfg3 */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 16;        /*## attribute Reserved0 */
}R2M06_PllLpfC1PllbwCfg3Bits_t;
/**
* R2M06_PllLpfC2PllbwCfg3Bits_t
* RegisterName: PLL_LPF_C2_PLLBW_CFG3
* This register controls LPF C2 (Cap) bank
* Address: 0x0B8
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: pll_lpf_c2_acq_ctrl_pllbw_cfg3
	* Description: LPF C2 setting during acq (low BW)
	*
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC2AcqCtrlPllbwCfg3 : 8;        /*## attribute PllLpfC2AcqCtrlPllbwCfg3 */
	/**
	* BitsName: pll_lpf_c2_rst_ctrl_pllbw_cfg3
	* Description: LPF C2 setting during rst (high BW)
	* Read/Write: RW
	* Bits: [15:8]
	* ResetValue: 0b00000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC2RstCtrlPllbwCfg3 : 8;        /*## attribute PllLpfC2RstCtrlPllbwCfg3 */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 16;        /*## attribute Reserved0 */
}R2M06_PllLpfC2PllbwCfg3Bits_t;
/**
* R2M06_PllLpfC3PllbwCfg3Bits_t
* RegisterName: PLL_LPF_C3_PLLBW_CFG3
* This register controls LPF C3 (Cap) bank
* Address: 0x0BC
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: pll_lpf_c3_acq_ctrl_pllbw_cfg3
	* Description: LPF C3 setting during acq (low BW)
	*
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC3AcqCtrlPllbwCfg3 : 8;        /*## attribute PllLpfC3AcqCtrlPllbwCfg3 */
	/**
	* BitsName: pll_lpf_c3_rst_ctrl_pllbw_cfg3
	* Description: LPF C3 setting during rst (high BW)
	* Read/Write: RW
	* Bits: [15:8]
	* ResetValue: 0b00000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC3RstCtrlPllbwCfg3 : 8;        /*## attribute PllLpfC3RstCtrlPllbwCfg3 */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 16;        /*## attribute Reserved0 */
}R2M06_PllLpfC3PllbwCfg3Bits_t;
/**
* R2M06_PllLpfResPllbwCfg3Bits_t
* RegisterName: PLL_LPF_RES_PLLBW_CFG3
* settings for FILTER
* Address: 0x0C0
* ResetValue: 0x00001616
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctl_lpf_r1_spi_pllbw_cfg3
	* Description: Select loop filter res. R1
	* Read/Write: RW
	* Bits: [4:0]
	* ResetValue: 0b10110
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlLpfR1SpiPllbwCfg3 : 5;        /*## attribute CtlLpfR1SpiPllbwCfg3 */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 5;        /*## attribute Reserved1 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 19;        /*## attribute Reserved2 */
}R2M06_PllLpfResPllbwCfg3Bits_t;
/**
* R2M06_CpPllbwCfgHigh1GBits_t
* RegisterName: CP_PLLBW_CFG_HIGH_1G
* Chargepump profile settings. The settings are the same defined for CFG0, CFG1, CFG2, CFG3 except that these values are used to improve the settling time (incase of standby to powerup or huge sub-band jump usecases) with high bandwidth settings and then switch to profile based settings.
* Address: 0x0D0
* ResetValue: 0x003D0001
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctl_cp_slice_en_0_pllbw_cfg_h_1g
	* Description: Enable cp slices (one slice is equal to ctl_ibias_cp_150u_spi setting ).. Every bit corresponds to one slice. This is selected when pll_cp_slice_ctrl output is 0.  The value in this field corresponds to the value during the acquisition of the chirp
	* NOTE: reset value pointing to one slice enabled (single one)
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00000001
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlCpSliceEn0PllbwCfgH1G : 8;        /*## attribute CtlCpSliceEn0PllbwCfgH1G */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 8;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_ibias_cp_150u_spi_pllbw_cfg_h_1g
	* Description: Program current of the CP
	*
	* This is current that goes into CP, programmable between 0 and ~197u
	* current=ctl_ibias_cp_150u_spi x 3.125u
	* Read/Write: RW
	* Bits: [21:16]
	* ResetValue: 0b111101
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIbiasCp150USpiPllbwCfgH1G : 6;        /*## attribute CtlIbiasCp150USpiPllbwCfgH1G */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_cp_ioffset_updn_spi_pllbw_cfg_h_1g
	* Description: Direction of the charge pump offset
	* 1 :  Pmos inject current
	* 0 :  Nmos substract current
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlCpIoffsetUpdnSpiPllbwCfgH1G : 1;        /*## attribute CtlCpIoffsetUpdnSpiPllbwCfgH1G */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: ctl_cp_ioffset_set_spi_pllbw_cfg_h_1g
	* Description: charge pump offset, bit wise programming, polarity given by 'ctl_cp_ioffset_updn_spi_profile*':
	* [7]=+35%; [6]=+30% ;[5]=+25%; [4]=+20%; [3]=+15%;[2]=+10%; [1]=+5%; [0]=0%
	* Read/Write: RW
	* Bits: [30:28]
	* ResetValue: 0b000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlCpIoffsetSetSpiPllbwCfgH1G : 3;        /*## attribute CtlCpIoffsetSetSpiPllbwCfgH1G */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 1;        /*## attribute Reserved3 */
}R2M06_CpPllbwCfgHigh1GBits_t;
/**
* R2M06_PllLpfCapPllbwCfgHigh1GBits_t
* RegisterName: PLL_LPF_CAP_PLLBW_CFG_HIGH_1G
* This register controls LPF (Cap) bank. The settings are the same defined for CFG0, CFG1, CFG2, CFG3 except that these values are used to improve the settling time (incase of standby to powerup or huge sub-band jump usecases) with high bandwidth settings and then switch to profile based settings.
* Address: 0x0D4
* ResetValue: 0x00403F12
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: pll_lpf_c1_high_pllbw_cfg_1g
	* Description: LPF C1 setting for 1GHz(high BW)
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00010010
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC1HighPllbwCfg1G : 8;        /*## attribute PllLpfC1HighPllbwCfg1G */
	/**
	* BitsName: pll_lpf_c2_high_pllbw_cfg_1g
	* Description: LPF C2 setting for 1GHz(high BW)
	* Read/Write: RW
	* Bits: [15:8]
	* ResetValue: 0b00111111
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC2HighPllbwCfg1G : 8;        /*## attribute PllLpfC2HighPllbwCfg1G */
	/**
	* BitsName: pll_lpf_c3_high_pllbw_cfg_1g
	* Description: LPF C3 setting for 1GHz(high BW)
	* Read/Write: RW
	* Bits: [23:16]
	* ResetValue: 0b01000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC3HighPllbwCfg1G : 8;        /*## attribute PllLpfC3HighPllbwCfg1G */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 8;        /*## attribute Reserved0 */
}R2M06_PllLpfCapPllbwCfgHigh1GBits_t;
/**
* R2M06_CpPllbwCfgHigh2GBits_t
* RegisterName: CP_PLLBW_CFG_HIGH_2G
* Chargepump profile settings. The settings are the same defined for CFG0, CFG1, CFG2, CFG3 except that these values are used to improve the settling time (incase of standby to powerup or huge sub-band jump usecases) with high bandwidth settings and then switch to profile based settings.
* Address: 0x0D8
* ResetValue: 0x00190001
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctl_cp_slice_en_0_pllbw_cfg_h_2g
	* Description: Enable cp slices (one slice is equal to ctl_ibias_cp_150u_spi setting ).. Every bit corresponds to one slice. This is selected when pll_cp_slice_ctrl output is 0.  The value in this field corresponds to the value during the acquisition of the chirp
	* NOTE: reset value pointing to one slice enabled (single one)
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00000001
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlCpSliceEn0PllbwCfgH2G : 8;        /*## attribute CtlCpSliceEn0PllbwCfgH2G */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 8;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_ibias_cp_150u_spi_pllbw_cfg_h_2g
	* Description: Program current of the CP
	*
	* This is current that goes into CP, programmable between 0 and ~197u
	* current=ctl_ibias_cp_150u_spi x 3.125u
	* Read/Write: RW
	* Bits: [21:16]
	* ResetValue: 0b011001
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIbiasCp150USpiPllbwCfgH2G : 6;        /*## attribute CtlIbiasCp150USpiPllbwCfgH2G */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_cp_ioffset_updn_spi_pllbw_cfg_h_2g
	* Description: Direction of the charge pump offset
	* 1 :  Pmos inject current
	* 0 :  Nmos substract current
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlCpIoffsetUpdnSpiPllbwCfgH2G : 1;        /*## attribute CtlCpIoffsetUpdnSpiPllbwCfgH2G */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: ctl_cp_ioffset_set_spi_pllbw_cfg_h_2g
	* Description: charge pump offset, bit wise programming, polarity given by 'ctl_cp_ioffset_updn_spi_profile*':
	* [7]=+35%; [6]=+30% ;[5]=+25%; [4]=+20%; [3]=+15%;[2]=+10%; [1]=+5%; [0]=0%
	* Read/Write: RW
	* Bits: [30:28]
	* ResetValue: 0b000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlCpIoffsetSetSpiPllbwCfgH2G : 3;        /*## attribute CtlCpIoffsetSetSpiPllbwCfgH2G */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 1;        /*## attribute Reserved3 */
}R2M06_CpPllbwCfgHigh2GBits_t;
/**
* R2M06_PllLpfCapPllbwCfgHigh2GBits_t
* RegisterName: PLL_LPF_CAP_PLLBW_CFG_HIGH_2G
* This register controls LPF (Cap) bank. The settings are the same defined for CFG0, CFG1, CFG2, CFG3 except that these values are used to improve the settling time (incase of standby to powerup or huge sub-band jump usecases) with high bandwidth settings and then switch to profile based settings.
* Address: 0x0DC
* ResetValue: 0x00403F11
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: pll_lpf_c1_high_pllbw_cfg_2g
	* Description: LPF C1 setting for 2GHz(high BW)
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00010001
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC1HighPllbwCfg2G : 8;        /*## attribute PllLpfC1HighPllbwCfg2G */
	/**
	* BitsName: pll_lpf_c2_high_pllbw_cfg_2g
	* Description: LPF C2 setting for 2GHz(high BW)
	* Read/Write: RW
	* Bits: [15:8]
	* ResetValue: 0b00111111
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC2HighPllbwCfg2G : 8;        /*## attribute PllLpfC2HighPllbwCfg2G */
	/**
	* BitsName: pll_lpf_c3_high_pllbw_cfg_2g
	* Description: LPF C3 setting for 2GHz(high BW)
	* Read/Write: RW
	* Bits: [23:16]
	* ResetValue: 0b01000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC3HighPllbwCfg2G : 8;        /*## attribute PllLpfC3HighPllbwCfg2G */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 8;        /*## attribute Reserved0 */
}R2M06_PllLpfCapPllbwCfgHigh2GBits_t;
/**
* R2M06_CpPllbwCfgHigh4GBits_t
* RegisterName: CP_PLLBW_CFG_HIGH_4G
* Chargepump profile settings. The settings are the same defined for CFG0, CFG1, CFG2, CFG3 except that these values are used to improve the settling time (incase of standby to powerup or huge sub-band jump usecases) with high bandwidth settings and then switch to profile based settings.
* Address: 0x0E0
* ResetValue: 0x00150001
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctl_cp_slice_en_0_pllbw_cfg_h_4g
	* Description: Enable cp slices (one slice is equal to ctl_ibias_cp_150u_spi setting ).. Every bit corresponds to one slice. This is selected when pll_cp_slice_ctrl output is 0.  The value in this field corresponds to the value during the acquisition of the chirp
	* NOTE: reset value pointing to one slice enabled (single one)
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00000001
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlCpSliceEn0PllbwCfgH4G : 8;        /*## attribute CtlCpSliceEn0PllbwCfgH4G */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 8;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_ibias_cp_150u_spi_pllbw_cfg_h_4g
	* Description: Program current of the CP
	*
	* This is current that goes into CP, programmable between 0 and ~197u
	* current=ctl_ibias_cp_150u_spi x 3.125u
	* Read/Write: RW
	* Bits: [21:16]
	* ResetValue: 0b010101
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIbiasCp150USpiPllbwCfgH4G : 6;        /*## attribute CtlIbiasCp150USpiPllbwCfgH4G */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_cp_ioffset_updn_spi_pllbw_cfg_h_4g
	* Description: Direction of the charge pump offset
	* 1 :  Pmos inject current
	* 0 :  Nmos substract current
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlCpIoffsetUpdnSpiPllbwCfgH4G : 1;        /*## attribute CtlCpIoffsetUpdnSpiPllbwCfgH4G */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: ctl_cp_ioffset_set_spi_pllbw_cfg_h_4g
	* Description: charge pump offset, bit wise programming, polarity given by 'ctl_cp_ioffset_updn_spi_profile*':
	* [7]=+35%; [6]=+30% ;[5]=+25%; [4]=+20%; [3]=+15%;[2]=+10%; [1]=+5%; [0]=0%
	* Read/Write: RW
	* Bits: [30:28]
	* ResetValue: 0b000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlCpIoffsetSetSpiPllbwCfgH4G : 3;        /*## attribute CtlCpIoffsetSetSpiPllbwCfgH4G */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 1;        /*## attribute Reserved3 */
}R2M06_CpPllbwCfgHigh4GBits_t;
/**
* R2M06_PllLpfCapPllbwCfgHigh4GBits_t
* RegisterName: PLL_LPF_CAP_PLLBW_CFG_HIGH_4G
* This register controls LPF (Cap) bank. The settings are the same defined for CFG0, CFG1, CFG2, CFG3 except that these values are used to improve the settling time (incase of standby to powerup or huge sub-band jump usecases) with high bandwidth settings and then switch to profile based settings.
* Address: 0x0E4
* ResetValue: 0x00413F12
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: pll_lpf_c1_high_pllbw_cfg_4g
	* Description: LPF C1 setting for 4GHz(high BW)
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00010010
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC1HighPllbwCfg4G : 8;        /*## attribute PllLpfC1HighPllbwCfg4G */
	/**
	* BitsName: pll_lpf_c2_high_pllbw_cfg_4g
	* Description: LPF C2 setting for 4GHz(high BW)
	* Read/Write: RW
	* Bits: [15:8]
	* ResetValue: 0b00111111
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC2HighPllbwCfg4G : 8;        /*## attribute PllLpfC2HighPllbwCfg4G */
	/**
	* BitsName: pll_lpf_c3_high_pllbw_cfg_4g
	* Description: LPF C3 setting for 4GHz(high BW)
	* Read/Write: RW
	* Bits: [23:16]
	* ResetValue: 0b01000001
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC3HighPllbwCfg4G : 8;        /*## attribute PllLpfC3HighPllbwCfg4G */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 8;        /*## attribute Reserved0 */
}R2M06_PllLpfCapPllbwCfgHigh4GBits_t;
/**
* R2M06_PllLpfResPllbwCfgHighBits_t
* RegisterName: PLL_LPF_RES_PLLBW_CFG_HIGH
* settings for FILTER. The settings are the same defined for CFG0, CFG1, CFG2, CFG3 except that these values are used to improve the settling time (incase of standby to powerup or huge sub-band jump usecases) with high bandwidth settings and then switch to profile based settings.
* Address: 0x0E8
* ResetValue: 0x2B594A52
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctl_lpf_r1_spi_pllbw_cfg_h_1g
	* Description: Select loop filter res. R1
	* Read/Write: RW
	* Bits: [4:0]
	* ResetValue: 0b10010
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlLpfR1SpiPllbwCfgH1G : 5;        /*## attribute CtlLpfR1SpiPllbwCfgH1G */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 5;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_lpf_r1_spi_pllbw_cfg_h_2g
	* Description: Select loop filter res.R1
	* Read/Write: RW
	* Bits: [14:10]
	* ResetValue: 0b10010
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlLpfR1SpiPllbwCfgH2G : 5;        /*## attribute CtlLpfR1SpiPllbwCfgH2G */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 5;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_lpf_r1_spi_pllbw_cfg_h_4g
	* Description: Select loop filter res.R1
	* Read/Write: RW
	* Bits: [24:20]
	* ResetValue: 0b10101
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlLpfR1SpiPllbwCfgH4G : 5;        /*## attribute CtlLpfR1SpiPllbwCfgH4G */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 5;        /*## attribute Reserved2 */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 2;        /*## attribute Reserved3 */
}R2M06_PllLpfResPllbwCfgHighBits_t;
/**
* R2M06_VcoRegProfile0Bits_t
* RegisterName: VCO_REG_PROFILE0
* Vco control settings
* Address: 0x100
* ResetValue: 0x000F0000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctl_vco_coarse_tuning_9g_spi_profile0
	* Description: Select sub-band for 9 GHz coarse bank.
	*
	* 1g : [6:0] is used
	* 4g : [5:0] is used and MSB is not used
	* Read/Write: RW
	* Bits: [6:0]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoCoarseTuning9GSpiProfile0 : 7;        /*## attribute CtlVcoCoarseTuning9GSpiProfile0 */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 9;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_vco_ivco_fine_spi_profile0
	* Description: Select current VCO
	* Read/Write: RW
	* Bits: [21:16]
	* ResetValue: 0b001111
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoIvcoFineSpiProfile0 : 6;        /*## attribute CtlVcoIvcoFineSpiProfile0 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_vco_bandwidth_spi_profile0
	* Description: Select VCO bandwidth:
	* 0: narrow bandwidth (2 GHz)
	* 1: large bandwidth (4 GHz)
	*
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoBandwidthSpiProfile0 : 1;        /*## attribute CtlVcoBandwidthSpiProfile0 */
	/**
	* BitsName: pllbw_cfg_selection_profile0
	* Description: These bits select the register settings required for the PLLBW. Based on the selection, the settings from the following registers are applied.
	*
	* CP_REG_PLLBW_CFG*, PLL_LPF_C1_PLLBW_CFG*, PLL_LPF_C2_PLLBW_CFG*,
	*
	* x00: PLLBW_CFG0 related settings are applied
	* x01: PLLBW_CFG1 related settings are applied
	* x10: PLLBW_CFG2 related settings are applied
	* x11: PLLBW_CFG3 related settings are applied
	*
	*
	* Read/Write: RW
	* Bits: [27:25]
	* ResetValue: 0b000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t PllbwCfgSelectionProfile0 : 3;        /*## attribute PllbwCfgSelectionProfile0 */
	/**
	* BitsName: ctl_vco_coarse_tuning_fast_bias_en_spi_profile0
	* Description: 0 -long time constant on coarse tuning settling  for normal operation
	* 1- short time constant coarse tuning settling (automatically used inside design during AAFC and subband switching)
	*
	* Note: ctl_vco_coarse_tuning_fast_bias_en_spi_override option is provided to overrule based on the validation results
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoCoarseTuningFastBiasEnSpiProfile0 : 1;        /*## attribute CtlVcoCoarseTuningFastBiasEnSpiProfile0 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 1;        /*## attribute Reserved3 */
}R2M06_VcoRegProfile0Bits_t;
/**
* R2M06_LpfInjAcqRstProfile0Bits_t
* RegisterName: LPF_INJ_ACQ_RST_PROFILE0
* This register controls the LPF injection current during Acquisition
* Address: 0x104
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctl_idac_inj_acq_c1_spi_profile0
	* Description: Injection current for acquisition. Source Level control for LPF C1 bank
	* Read/Write: RW
	* Bits: [6:0]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC1SpiProfile0 : 7;        /*## attribute CtlIdacInjAcqC1SpiProfile0 */
	/**
	* BitsName: ctl_idac_inj_acq_c2_spi_profile0
	* Description: Injection current for acquisition. Source Level control for LPF C2 bank
	* Read/Write: RW
	* Bits: [11:7]
	* ResetValue: 0b00000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC2SpiProfile0 : 5;        /*## attribute CtlIdacInjAcqC2SpiProfile0 */
	/**
	* BitsName: ctl_idac_inj_acq_c3_spi_profile0
	* Description: Injection current for acquisition. Source Level control for LPF C3 bank
	* Read/Write: RW
	* Bits: [13:12]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC3SpiProfile0 : 2;        /*## attribute CtlIdacInjAcqC3SpiProfile0 */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_idac_inj_rst_c1_spi_profile0
	* Description: Injection current for reset. Sink Level control for LPF C1 bank
	* Read/Write: RW
	* Bits: [22:16]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC1SpiProfile0 : 7;        /*## attribute CtlIdacInjRstC1SpiProfile0 */
	/**
	* BitsName: ctl_idac_inj_rst_c2_spi_profile0
	* Description: Injection current for reset. Sink Level control for LPF C2 bank
	* Read/Write: RW
	* Bits: [27:23]
	* ResetValue: 0b00000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC2SpiProfile0 : 5;        /*## attribute CtlIdacInjRstC2SpiProfile0 */
	/**
	* BitsName: ctl_idac_inj_rst_c3_spi_profile0
	* Description: Injection current for reset. Sink Level control for LPF C3 bank
	* Read/Write: RW
	* Bits: [29:28]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC3SpiProfile0 : 2;        /*## attribute CtlIdacInjRstC3SpiProfile0 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
}R2M06_LpfInjAcqRstProfile0Bits_t;
/**
* R2M06_VcoRegProfile1Bits_t
* RegisterName: VCO_REG_PROFILE1
* Vco control settings
* Address: 0x110
* ResetValue: 0x000F0000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctl_vco_coarse_tuning_9g_spi_profile1
	* Description: Select sub-band for 9 GHz coarse bank.
	*
	* 1g : [6:0] is used
	* 5g : [5:0] is used and MSB is not used
	* Read/Write: RW
	* Bits: [6:0]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoCoarseTuning9GSpiProfile1 : 7;        /*## attribute CtlVcoCoarseTuning9GSpiProfile1 */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 9;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_vco_ivco_fine_spi_profile1
	* Description: Select current VCO
	* Read/Write: RW
	* Bits: [21:16]
	* ResetValue: 0b001111
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoIvcoFineSpiProfile1 : 6;        /*## attribute CtlVcoIvcoFineSpiProfile1 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_vco_bandwidth_spi_profile1
	* Description: Select VCO bandwidth:
	* 0: narrow bandwidth (2 GHz)
	* 1: large bandwidth (4 GHz)
	*
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoBandwidthSpiProfile1 : 1;        /*## attribute CtlVcoBandwidthSpiProfile1 */
	/**
	* BitsName: pllbw_cfg_selection_profile1
	* Description: These bits select the register settings required for the PLLBW. Based on the selection, the settings from the following registers are applied.
	*
	* CP_REG_PLLBW_CFG*, PLL_LPF_C1_PLLBW_CFG*, PLL_LPF_C2_PLLBW_CFG*,
	*
	* x00: PLLBW_CFG0 related settings are applied
	* x01: PLLBW_CFG1 related settings are applied
	* x10: PLLBW_CFG2 related settings are applied
	* x11: PLLBW_CFG3 related settings are applied
	*
	* Read/Write: RW
	* Bits: [27:25]
	* ResetValue: 0b000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t PllbwCfgSelectionProfile1 : 3;        /*## attribute PllbwCfgSelectionProfile1 */
	/**
	* BitsName: ctl_vco_coarse_tuning_fast_bias_en_spi_profile1
	* Description: 0 -long time constant on coarse tuning settling  for normal operation
	* 1- short time constant coarse tuning settling (automatically used inside design during AAFC and subband switching)
	*
	* Note: ctl_vco_coarse_tuning_fast_bias_en_spi_override option is provided to overrule based on the validation results
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoCoarseTuningFastBiasEnSpiProfile1 : 1;        /*## attribute CtlVcoCoarseTuningFastBiasEnSpiProfile1 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 1;        /*## attribute Reserved3 */
}R2M06_VcoRegProfile1Bits_t;
/**
* R2M06_LpfInjAcqRstProfile1Bits_t
* RegisterName: LPF_INJ_ACQ_RST_PROFILE1
* This register controls the LPF injection current during Acquisition
* Address: 0x114
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctl_idac_inj_acq_c1_spi_profile1
	* Description: Injection current for acquisition. Source Level control for LPF C1 bank
	* Read/Write: RW
	* Bits: [6:0]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC1SpiProfile1 : 7;        /*## attribute CtlIdacInjAcqC1SpiProfile1 */
	/**
	* BitsName: ctl_idac_inj_acq_c2_spi_profile1
	* Description: Injection current for acquisition. Source Level control for LPF C2 bank
	* Read/Write: RW
	* Bits: [11:7]
	* ResetValue: 0b00000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC2SpiProfile1 : 5;        /*## attribute CtlIdacInjAcqC2SpiProfile1 */
	/**
	* BitsName: ctl_idac_inj_acq_c3_spi_profile1
	* Description: Injection current for acquisition. Source Level control for LPF C3 bank
	* Read/Write: RW
	* Bits: [13:12]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC3SpiProfile1 : 2;        /*## attribute CtlIdacInjAcqC3SpiProfile1 */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_idac_inj_rst_c1_spi_profile1
	* Description: Injection current for reset. Sink Level control for LPF C1 bank
	* Read/Write: RW
	* Bits: [22:16]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC1SpiProfile1 : 7;        /*## attribute CtlIdacInjRstC1SpiProfile1 */
	/**
	* BitsName: ctl_idac_inj_rst_c2_spi_profile1
	* Description: Injection current for reset. Sink Level control for LPF C2 bank
	* Read/Write: RW
	* Bits: [27:23]
	* ResetValue: 0b00000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC2SpiProfile1 : 5;        /*## attribute CtlIdacInjRstC2SpiProfile1 */
	/**
	* BitsName: ctl_idac_inj_rst_c3_spi_profile1
	* Description: Injection current for reset. Sink Level control for LPF C3 bank
	* Read/Write: RW
	* Bits: [29:28]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC3SpiProfile1 : 2;        /*## attribute CtlIdacInjRstC3SpiProfile1 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
}R2M06_LpfInjAcqRstProfile1Bits_t;
/**
* R2M06_VcoRegProfile2Bits_t
* RegisterName: VCO_REG_PROFILE2
* Vco control settings
* Address: 0x120
* ResetValue: 0x000F0000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctl_vco_coarse_tuning_9g_spi_profile2
	* Description: Select sub-band for 9 GHz coarse bank.
	*
	* 1g : [6:0] is used
	* 5g : [5:0] is used and MSB is not used
	* Read/Write: RW
	* Bits: [6:0]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoCoarseTuning9GSpiProfile2 : 7;        /*## attribute CtlVcoCoarseTuning9GSpiProfile2 */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 9;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_vco_ivco_fine_spi_profile2
	* Description: Select current VCO
	* Read/Write: RW
	* Bits: [21:16]
	* ResetValue: 0b001111
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoIvcoFineSpiProfile2 : 6;        /*## attribute CtlVcoIvcoFineSpiProfile2 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_vco_bandwidth_spi_profile2
	* Description: Select VCO bandwidth:
	* 0: narrow bandwidth (2 GHz)
	* 1: large bandwidth (4 GHz)
	*
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoBandwidthSpiProfile2 : 1;        /*## attribute CtlVcoBandwidthSpiProfile2 */
	/**
	* BitsName: pllbw_cfg_selection_profile2
	* Description: These bits select the register settings required for the PLLBW. Based on the selection, the settings from the following registers are applied.
	*
	* CP_REG_PLLBW_CFG*, PLL_LPF_C1_PLLBW_CFG*, PLL_LPF_C2_PLLBW_CFG*,
	*
	*
	*
	* x00: PLLBW_CFG0 related settings are applied
	* x01: PLLBW_CFG1 related settings are applied
	* x10: PLLBW_CFG2 related settings are applied
	* x11: PLLBW_CFG3 related settings are applied
	*
	*
	* Read/Write: RW
	* Bits: [27:25]
	* ResetValue: 0b000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t PllbwCfgSelectionProfile2 : 3;        /*## attribute PllbwCfgSelectionProfile2 */
	/**
	* BitsName: ctl_vco_coarse_tuning_fast_bias_en_spi_profile2
	* Description: 0 -long time constant on coarse tuning settling  for normal operation
	* 1- short time constant coarse tuning settling (automatically used inside design during AAFC and subband switching)
	*
	* Note: ctl_vco_coarse_tuning_fast_bias_en_spi_override option is provided to overrule based on the validation results
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoCoarseTuningFastBiasEnSpiProfile2 : 1;        /*## attribute CtlVcoCoarseTuningFastBiasEnSpiProfile2 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 1;        /*## attribute Reserved3 */
}R2M06_VcoRegProfile2Bits_t;
/**
* R2M06_LpfInjAcqRstProfile2Bits_t
* RegisterName: LPF_INJ_ACQ_RST_PROFILE2
* This register controls the LPF injection current during Acquisition
* Address: 0x124
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctl_idac_inj_acq_c1_spi_profile2
	* Description: Injection current for acquisition. Source Level control for LPF C1 bank
	* Read/Write: RW
	* Bits: [6:0]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC1SpiProfile2 : 7;        /*## attribute CtlIdacInjAcqC1SpiProfile2 */
	/**
	* BitsName: ctl_idac_inj_acq_c2_spi_profile2
	* Description: Injection current for acquisition. Source Level control for LPF C2 bank
	* Read/Write: RW
	* Bits: [11:7]
	* ResetValue: 0b00000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC2SpiProfile2 : 5;        /*## attribute CtlIdacInjAcqC2SpiProfile2 */
	/**
	* BitsName: ctl_idac_inj_acq_c3_spi_profile2
	* Description: Injection current for acquisition. Source Level control for LPF C3 bank
	* Read/Write: RW
	* Bits: [13:12]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC3SpiProfile2 : 2;        /*## attribute CtlIdacInjAcqC3SpiProfile2 */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_idac_inj_rst_c1_spi_profile2
	* Description: Injection current for reset. Sink Level control for LPF C1 bank
	* Read/Write: RW
	* Bits: [22:16]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC1SpiProfile2 : 7;        /*## attribute CtlIdacInjRstC1SpiProfile2 */
	/**
	* BitsName: ctl_idac_inj_rst_c2_spi_profile2
	* Description: Injection current for reset. Sink Level control for LPF C2 bank
	* Read/Write: RW
	* Bits: [27:23]
	* ResetValue: 0b00000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC2SpiProfile2 : 5;        /*## attribute CtlIdacInjRstC2SpiProfile2 */
	/**
	* BitsName: ctl_idac_inj_rst_c3_spi_profile2
	* Description: Injection current for reset. Sink Level control for LPF C3 bank
	* Read/Write: RW
	* Bits: [29:28]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC3SpiProfile2 : 2;        /*## attribute CtlIdacInjRstC3SpiProfile2 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
}R2M06_LpfInjAcqRstProfile2Bits_t;
/**
* R2M06_VcoRegProfile3Bits_t
* RegisterName: VCO_REG_PROFILE3
* Vco control settings
* Address: 0x130
* ResetValue: 0x000F0000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctl_vco_coarse_tuning_9g_spi_profile3
	* Description: Select sub-band for 9 GHz coarse bank.
	*
	* 1g : [6:0] is used
	* 5g : [5:0] is used and MSB is not used
	* Read/Write: RW
	* Bits: [6:0]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoCoarseTuning9GSpiProfile3 : 7;        /*## attribute CtlVcoCoarseTuning9GSpiProfile3 */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 9;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_vco_ivco_fine_spi_profile3
	* Description: Select current VCO
	* Read/Write: RW
	* Bits: [21:16]
	* ResetValue: 0b001111
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoIvcoFineSpiProfile3 : 6;        /*## attribute CtlVcoIvcoFineSpiProfile3 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_vco_bandwidth_spi_profile3
	* Description: Select VCO bandwidth:
	* 0: narrow bandwidth (2 GHz)
	* 1: large bandwidth (4 GHz)
	*
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoBandwidthSpiProfile3 : 1;        /*## attribute CtlVcoBandwidthSpiProfile3 */
	/**
	* BitsName: pllbw_cfg_selection_profile3
	* Description: These bits select the register settings required for the PLLBW. Based on the selection, the settings from the following registers are applied.
	*
	* CP_REG_PLLBW_CFG*, PLL_LPF_C1_PLLBW_CFG*, PLL_LPF_C2_PLLBW_CFG*,
	*
	* x00: PLLBW_CFG0 related settings are applied
	* x01: PLLBW_CFG1 related settings are applied
	* x10: PLLBW_CFG2 related settings are applied
	* x11: PLLBW_CFG3 related settings are applied
	*
	*
	* Read/Write: RW
	* Bits: [27:25]
	* ResetValue: 0b000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t PllbwCfgSelectionProfile3 : 3;        /*## attribute PllbwCfgSelectionProfile3 */
	/**
	* BitsName: ctl_vco_coarse_tuning_fast_bias_en_spi_profile3
	* Description: 0 -long time constant on coarse tuning settling  for normal operation
	* 1- short time constant coarse tuning settling (automatically used inside design during AAFC and subband switching)
	*
	* Note: ctl_vco_coarse_tuning_fast_bias_en_spi_override option is provided to overrule based on the validation results
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoCoarseTuningFastBiasEnSpiProfile3 : 1;        /*## attribute CtlVcoCoarseTuningFastBiasEnSpiProfile3 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 1;        /*## attribute Reserved3 */
}R2M06_VcoRegProfile3Bits_t;
/**
* R2M06_LpfInjAcqRstProfile3Bits_t
* RegisterName: LPF_INJ_ACQ_RST_PROFILE3
* This register controls the LPF injection current during Acquisition
* Address: 0x134
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctl_idac_inj_acq_c1_spi_profile3
	* Description: Injection current for acquisition. Source Level control for LPF C1 bank
	* Read/Write: RW
	* Bits: [6:0]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC1SpiProfile3 : 7;        /*## attribute CtlIdacInjAcqC1SpiProfile3 */
	/**
	* BitsName: ctl_idac_inj_acq_c2_spi_profile3
	* Description: Injection current for acquisition. Source Level control for LPF C2 bank
	* Read/Write: RW
	* Bits: [11:7]
	* ResetValue: 0b00000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC2SpiProfile3 : 5;        /*## attribute CtlIdacInjAcqC2SpiProfile3 */
	/**
	* BitsName: ctl_idac_inj_acq_c3_spi_profile3
	* Description: Injection current for acquisition. Source Level control for LPF C3 bank
	* Read/Write: RW
	* Bits: [13:12]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC3SpiProfile3 : 2;        /*## attribute CtlIdacInjAcqC3SpiProfile3 */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_idac_inj_rst_c1_spi_profile3
	* Description: Injection current for reset. Sink Level control for LPF C1 bank
	* Read/Write: RW
	* Bits: [22:16]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC1SpiProfile3 : 7;        /*## attribute CtlIdacInjRstC1SpiProfile3 */
	/**
	* BitsName: ctl_idac_inj_rst_c2_spi_profile3
	* Description: Injection current for reset. Sink Level control for LPF C2 bank
	* Read/Write: RW
	* Bits: [27:23]
	* ResetValue: 0b00000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC2SpiProfile3 : 5;        /*## attribute CtlIdacInjRstC2SpiProfile3 */
	/**
	* BitsName: ctl_idac_inj_rst_c3_spi_profile3
	* Description: Injection current for reset. Sink Level control for LPF C3 bank
	* Read/Write: RW
	* Bits: [29:28]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC3SpiProfile3 : 2;        /*## attribute CtlIdacInjRstC3SpiProfile3 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
}R2M06_LpfInjAcqRstProfile3Bits_t;
/**
* R2M06_VcoRegProfile4Bits_t
* RegisterName: VCO_REG_PROFILE4
* Vco control settings
* Address: 0x140
* ResetValue: 0x000F0000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctl_vco_coarse_tuning_9g_spi_profile4
	* Description: Select sub-band for 9 GHz coarse bank.
	*
	* 1g : [6:0] is used
	* 5g : [5:0] is used and MSB is not used
	* Read/Write: RW
	* Bits: [6:0]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoCoarseTuning9GSpiProfile4 : 7;        /*## attribute CtlVcoCoarseTuning9GSpiProfile4 */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 9;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_vco_ivco_fine_spi_profile4
	* Description: Select current VCO
	* Read/Write: RW
	* Bits: [21:16]
	* ResetValue: 0b001111
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoIvcoFineSpiProfile4 : 6;        /*## attribute CtlVcoIvcoFineSpiProfile4 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_vco_bandwidth_spi_profile4
	* Description: Select VCO bandwidth:
	* 0: narrow bandwidth (2 GHz)
	* 1: large bandwidth (4 GHz)
	*
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoBandwidthSpiProfile4 : 1;        /*## attribute CtlVcoBandwidthSpiProfile4 */
	/**
	* BitsName: pllbw_cfg_selection_profile4
	* Description: These bits select the register settings required for the PLLBW. Based on the selection, the settings from the following registers are applied.
	*
	* CP_REG_PLLBW_CFG*, PLL_LPF_C1_PLLBW_CFG*, PLL_LPF_C2_PLLBW_CFG*,
	*
	*
	*
	* x00: PLLBW_CFG0 related settings are applied
	* x01: PLLBW_CFG1 related settings are applied
	* x10: PLLBW_CFG2 related settings are applied
	* x11: PLLBW_CFG3 related settings are applied
	*
	*
	* Read/Write: RW
	* Bits: [27:25]
	* ResetValue: 0b000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t PllbwCfgSelectionProfile4 : 3;        /*## attribute PllbwCfgSelectionProfile4 */
	/**
	* BitsName: ctl_vco_coarse_tuning_fast_bias_en_spi_profile4
	* Description: 0 -long time constant on coarse tuning settling  for normal operation
	* 1- short time constant coarse tuning settling (automatically used inside design during AAFC and subband switching)
	*
	* Note: ctl_vco_coarse_tuning_fast_bias_en_spi_override option is provided to overrule based on the validation results
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoCoarseTuningFastBiasEnSpiProfile4 : 1;        /*## attribute CtlVcoCoarseTuningFastBiasEnSpiProfile4 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 1;        /*## attribute Reserved3 */
}R2M06_VcoRegProfile4Bits_t;
/**
* R2M06_LpfInjAcqRstProfile4Bits_t
* RegisterName: LPF_INJ_ACQ_RST_PROFILE4
* This register controls the LPF injection current during Acquisition
* Address: 0x144
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctl_idac_inj_acq_c1_spi_profile4
	* Description: Injection current for acquisition. Source Level control for LPF C1 bank
	* Read/Write: RW
	* Bits: [6:0]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC1SpiProfile4 : 7;        /*## attribute CtlIdacInjAcqC1SpiProfile4 */
	/**
	* BitsName: ctl_idac_inj_acq_c2_spi_profile4
	* Description: Injection current for acquisition. Source Level control for LPF C2 bank
	* Read/Write: RW
	* Bits: [11:7]
	* ResetValue: 0b00000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC2SpiProfile4 : 5;        /*## attribute CtlIdacInjAcqC2SpiProfile4 */
	/**
	* BitsName: ctl_idac_inj_acq_c3_spi_profile4
	* Description: Injection current for acquisition. Source Level control for LPF C3 bank
	* Read/Write: RW
	* Bits: [13:12]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC3SpiProfile4 : 2;        /*## attribute CtlIdacInjAcqC3SpiProfile4 */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_idac_inj_rst_c1_spi_profile4
	* Description: Injection current for reset. Sink Level control for LPF C1 bank
	* Read/Write: RW
	* Bits: [22:16]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC1SpiProfile4 : 7;        /*## attribute CtlIdacInjRstC1SpiProfile4 */
	/**
	* BitsName: ctl_idac_inj_rst_c2_spi_profile4
	* Description: Injection current for reset. Sink Level control for LPF C2 bank
	* Read/Write: RW
	* Bits: [27:23]
	* ResetValue: 0b00000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC2SpiProfile4 : 5;        /*## attribute CtlIdacInjRstC2SpiProfile4 */
	/**
	* BitsName: ctl_idac_inj_rst_c3_spi_profile4
	* Description: Injection current for reset. Sink Level control for LPF C3 bank
	* Read/Write: RW
	* Bits: [29:28]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC3SpiProfile4 : 2;        /*## attribute CtlIdacInjRstC3SpiProfile4 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
}R2M06_LpfInjAcqRstProfile4Bits_t;
/**
* R2M06_VcoRegProfile5Bits_t
* RegisterName: VCO_REG_PROFILE5
* Vco control settings
* Address: 0x150
* ResetValue: 0x000F0000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctl_vco_coarse_tuning_9g_spi_profile5
	* Description: Select sub-band for 9 GHz coarse bank.
	*
	* 1g : [6:0] is used
	* 5g : [5:0] is used and MSB is not used
	* Read/Write: RW
	* Bits: [6:0]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoCoarseTuning9GSpiProfile5 : 7;        /*## attribute CtlVcoCoarseTuning9GSpiProfile5 */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 9;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_vco_ivco_fine_spi_profile5
	* Description: Select current VCO
	* Read/Write: RW
	* Bits: [21:16]
	* ResetValue: 0b001111
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoIvcoFineSpiProfile5 : 6;        /*## attribute CtlVcoIvcoFineSpiProfile5 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_vco_bandwidth_spi_profile5
	* Description: Select VCO bandwidth:
	* 0: narrow bandwidth (2 GHz)
	* 1: large bandwidth (4 GHz)
	*
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoBandwidthSpiProfile5 : 1;        /*## attribute CtlVcoBandwidthSpiProfile5 */
	/**
	* BitsName: pllbw_cfg_selection_profile5
	* Description: These bits select the register settings required for the PLLBW. Based on the selection, the settings from the following registers are applied.
	*
	* CP_REG_PLLBW_CFG*, PLL_LPF_C1_PLLBW_CFG*, PLL_LPF_C2_PLLBW_CFG*,
	*
	* x00: PLLBW_CFG0 related settings are applied
	* x01: PLLBW_CFG1 related settings are applied
	* x10: PLLBW_CFG2 related settings are applied
	* x11: PLLBW_CFG3 related settings are applied
	*
	*
	* Read/Write: RW
	* Bits: [27:25]
	* ResetValue: 0b000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t PllbwCfgSelectionProfile5 : 3;        /*## attribute PllbwCfgSelectionProfile5 */
	/**
	* BitsName: ctl_vco_coarse_tuning_fast_bias_en_spi_profile5
	* Description: 0 -long time constant on coarse tuning settling  for normal operation
	* 1- short time constant coarse tuning settling (automatically used inside design during AAFC and subband switching)
	*
	* Note: ctl_vco_coarse_tuning_fast_bias_en_spi_override option is provided to overrule based on the validation results
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoCoarseTuningFastBiasEnSpiProfile5 : 1;        /*## attribute CtlVcoCoarseTuningFastBiasEnSpiProfile5 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 1;        /*## attribute Reserved3 */
}R2M06_VcoRegProfile5Bits_t;
/**
* R2M06_LpfInjAcqRstProfile5Bits_t
* RegisterName: LPF_INJ_ACQ_RST_PROFILE5
* This register controls the LPF injection current during Acquisition
* Address: 0x154
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctl_idac_inj_acq_c1_spi_profile5
	* Description: Injection current for acquisition. Source Level control for LPF C1 bank
	* Read/Write: RW
	* Bits: [6:0]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC1SpiProfile5 : 7;        /*## attribute CtlIdacInjAcqC1SpiProfile5 */
	/**
	* BitsName: ctl_idac_inj_acq_c2_spi_profile5
	* Description: Injection current for acquisition. Source Level control for LPF C2 bank
	* Read/Write: RW
	* Bits: [11:7]
	* ResetValue: 0b00000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC2SpiProfile5 : 5;        /*## attribute CtlIdacInjAcqC2SpiProfile5 */
	/**
	* BitsName: ctl_idac_inj_acq_c3_spi_profile5
	* Description: Injection current for acquisition. Source Level control for LPF C3 bank
	* Read/Write: RW
	* Bits: [13:12]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC3SpiProfile5 : 2;        /*## attribute CtlIdacInjAcqC3SpiProfile5 */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_idac_inj_rst_c1_spi_profile5
	* Description: Injection current for reset. Sink Level control for LPF C1 bank
	* Read/Write: RW
	* Bits: [22:16]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC1SpiProfile5 : 7;        /*## attribute CtlIdacInjRstC1SpiProfile5 */
	/**
	* BitsName: ctl_idac_inj_rst_c2_spi_profile5
	* Description: Injection current for reset. Sink Level control for LPF C2 bank
	* Read/Write: RW
	* Bits: [27:23]
	* ResetValue: 0b00000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC2SpiProfile5 : 5;        /*## attribute CtlIdacInjRstC2SpiProfile5 */
	/**
	* BitsName: ctl_idac_inj_rst_c3_spi_profile5
	* Description: Injection current for reset. Sink Level control for LPF C3 bank
	* Read/Write: RW
	* Bits: [29:28]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC3SpiProfile5 : 2;        /*## attribute CtlIdacInjRstC3SpiProfile5 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
}R2M06_LpfInjAcqRstProfile5Bits_t;
/**
* R2M06_VcoRegProfile6Bits_t
* RegisterName: VCO_REG_PROFILE6
* Vco control settings
* Address: 0x160
* ResetValue: 0x000F0000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctl_vco_coarse_tuning_9g_spi_profile6
	* Description: Select sub-band for 9 GHz coarse bank.
	*
	* 1g : [6:0] is used
	* 5g : [5:0] is used and MSB is not used
	* Read/Write: RW
	* Bits: [6:0]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoCoarseTuning9GSpiProfile6 : 7;        /*## attribute CtlVcoCoarseTuning9GSpiProfile6 */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 9;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_vco_ivco_fine_spi_profile6
	* Description: Select current VCO
	* Read/Write: RW
	* Bits: [21:16]
	* ResetValue: 0b001111
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoIvcoFineSpiProfile6 : 6;        /*## attribute CtlVcoIvcoFineSpiProfile6 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_vco_bandwidth_spi_profile6
	* Description: Select VCO bandwidth:
	* 0: narrow bandwidth (2 GHz)
	* 1: large bandwidth (4 GHz)
	*
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoBandwidthSpiProfile6 : 1;        /*## attribute CtlVcoBandwidthSpiProfile6 */
	/**
	* BitsName: pllbw_cfg_selection_profile6
	* Description: These bits select the register settings required for the PLLBW. Based on the selection, the settings from the following registers are applied.
	*
	* CP_REG_PLLBW_CFG*, PLL_LPF_C1_PLLBW_CFG*, PLL_LPF_C2_PLLBW_CFG*,
	*
	*
	*
	* x00: PLLBW_CFG0 related settings are applied
	* x01: PLLBW_CFG1 related settings are applied
	* x10: PLLBW_CFG2 related settings are applied
	* x11: PLLBW_CFG3 related settings are applied
	*
	*
	* Read/Write: RW
	* Bits: [27:25]
	* ResetValue: 0b000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t PllbwCfgSelectionProfile6 : 3;        /*## attribute PllbwCfgSelectionProfile6 */
	/**
	* BitsName: ctl_vco_coarse_tuning_fast_bias_en_spi_profile6
	* Description: 0 -long time constant on coarse tuning settling  for normal operation
	* 1- short time constant coarse tuning settling (automatically used inside design during AAFC and subband switching)
	*
	* Note: ctl_vco_coarse_tuning_fast_bias_en_spi_override option is provided to overrule based on the validation results
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoCoarseTuningFastBiasEnSpiProfile6 : 1;        /*## attribute CtlVcoCoarseTuningFastBiasEnSpiProfile6 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 1;        /*## attribute Reserved3 */
}R2M06_VcoRegProfile6Bits_t;
/**
* R2M06_LpfInjAcqRstProfile6Bits_t
* RegisterName: LPF_INJ_ACQ_RST_PROFILE6
* This register controls the LPF injection current during Acquisition
* Address: 0x164
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctl_idac_inj_acq_c1_spi_profile6
	* Description: Injection current for acquisition. Source Level control for LPF C1 bank
	* Read/Write: RW
	* Bits: [6:0]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC1SpiProfile6 : 7;        /*## attribute CtlIdacInjAcqC1SpiProfile6 */
	/**
	* BitsName: ctl_idac_inj_acq_c2_spi_profile6
	* Description: Injection current for acquisition. Source Level control for LPF C2 bank
	* Read/Write: RW
	* Bits: [11:7]
	* ResetValue: 0b00000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC2SpiProfile6 : 5;        /*## attribute CtlIdacInjAcqC2SpiProfile6 */
	/**
	* BitsName: ctl_idac_inj_acq_c3_spi_profile6
	* Description: Injection current for acquisition. Source Level control for LPF C3 bank
	* Read/Write: RW
	* Bits: [13:12]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC3SpiProfile6 : 2;        /*## attribute CtlIdacInjAcqC3SpiProfile6 */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_idac_inj_rst_c1_spi_profile6
	* Description: Injection current for reset. Sink Level control for LPF C1 bank
	* Read/Write: RW
	* Bits: [22:16]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC1SpiProfile6 : 7;        /*## attribute CtlIdacInjRstC1SpiProfile6 */
	/**
	* BitsName: ctl_idac_inj_rst_c2_spi_profile6
	* Description: Injection current for reset. Sink Level control for LPF C2 bank
	* Read/Write: RW
	* Bits: [27:23]
	* ResetValue: 0b00000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC2SpiProfile6 : 5;        /*## attribute CtlIdacInjRstC2SpiProfile6 */
	/**
	* BitsName: ctl_idac_inj_rst_c3_spi_profile6
	* Description: Injection current for reset. Sink Level control for LPF C3 bank
	* Read/Write: RW
	* Bits: [29:28]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC3SpiProfile6 : 2;        /*## attribute CtlIdacInjRstC3SpiProfile6 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
}R2M06_LpfInjAcqRstProfile6Bits_t;
/**
* R2M06_VcoRegProfile7Bits_t
* RegisterName: VCO_REG_PROFILE7
* Vco control settings
* Address: 0x170
* ResetValue: 0x000F0000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctl_vco_coarse_tuning_9g_spi_profile7
	* Description: Select sub-band for 9 GHz coarse bank.
	*
	* 1g : [6:0] is used
	* 5g : [5:0] is used and MSB is not used
	* Read/Write: RW
	* Bits: [6:0]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoCoarseTuning9GSpiProfile7 : 7;        /*## attribute CtlVcoCoarseTuning9GSpiProfile7 */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 9;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_vco_ivco_fine_spi_profile7
	* Description: Select current VCO
	* Read/Write: RW
	* Bits: [21:16]
	* ResetValue: 0b001111
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoIvcoFineSpiProfile7 : 6;        /*## attribute CtlVcoIvcoFineSpiProfile7 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_vco_bandwidth_spi_profile7
	* Description: Select VCO bandwidth:
	* 0: narrow bandwidth (2 GHz)
	* 1: large bandwidth (4 GHz)
	*
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoBandwidthSpiProfile7 : 1;        /*## attribute CtlVcoBandwidthSpiProfile7 */
	/**
	* BitsName: pllbw_cfg_selection_profile7
	* Description: These bits select the register settings required for the PLLBW. Based on the selection, the settings from the following registers are applied.
	*
	* CP_REG_PLLBW_CFG*, PLL_LPF_C1_PLLBW_CFG*, PLL_LPF_C2_PLLBW_CFG*,
	*
	* x00: PLLBW_CFG0 related settings are applied
	* x01: PLLBW_CFG1 related settings are applied
	* x10: PLLBW_CFG2 related settings are applied
	* x11: PLLBW_CFG3 related settings are applied
	*
	* Read/Write: RW
	* Bits: [27:25]
	* ResetValue: 0b000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t PllbwCfgSelectionProfile7 : 3;        /*## attribute PllbwCfgSelectionProfile7 */
	/**
	* BitsName: ctl_vco_coarse_tuning_fast_bias_en_spi_profile7
	* Description: 0 -long time constant on coarse tuning settling  for normal operation
	* 1- short time constant coarse tuning settling (automatically used inside design during AAFC and subband switching)
	*
	* Note: ctl_vco_coarse_tuning_fast_bias_en_spi_override option is provided to overrule based on the validation results
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoCoarseTuningFastBiasEnSpiProfile7 : 1;        /*## attribute CtlVcoCoarseTuningFastBiasEnSpiProfile7 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 1;        /*## attribute Reserved3 */
}R2M06_VcoRegProfile7Bits_t;
/**
* R2M06_LpfInjAcqRstProfile7Bits_t
* RegisterName: LPF_INJ_ACQ_RST_PROFILE7
* This register controls the LPF injection current during Acquisition
* Address: 0x174
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctl_idac_inj_acq_c1_spi_profile7
	* Description: Injection current for acquisition. Source Level control for LPF C1 bank
	* Read/Write: RW
	* Bits: [6:0]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC1SpiProfile7 : 7;        /*## attribute CtlIdacInjAcqC1SpiProfile7 */
	/**
	* BitsName: ctl_idac_inj_acq_c2_spi_profile7
	* Description: Injection current for acquisition. Source Level control for LPF C2 bank
	* Read/Write: RW
	* Bits: [11:7]
	* ResetValue: 0b00000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC2SpiProfile7 : 5;        /*## attribute CtlIdacInjAcqC2SpiProfile7 */
	/**
	* BitsName: ctl_idac_inj_acq_c3_spi_profile7
	* Description: Injection current for acquisition. Source Level control for LPF C3 bank
	* Read/Write: RW
	* Bits: [13:12]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC3SpiProfile7 : 2;        /*## attribute CtlIdacInjAcqC3SpiProfile7 */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_idac_inj_rst_c1_spi_profile7
	* Description: Injection current for reset. Sink Level control for LPF C1 bank
	* Read/Write: RW
	* Bits: [22:16]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC1SpiProfile7 : 7;        /*## attribute CtlIdacInjRstC1SpiProfile7 */
	/**
	* BitsName: ctl_idac_inj_rst_c2_spi_profile7
	* Description: Injection current for reset. Sink Level control for LPF C2 bank
	* Read/Write: RW
	* Bits: [27:23]
	* ResetValue: 0b00000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC2SpiProfile7 : 5;        /*## attribute CtlIdacInjRstC2SpiProfile7 */
	/**
	* BitsName: ctl_idac_inj_rst_c3_spi_profile7
	* Description: Injection current for reset. Sink Level control for LPF C3 bank
	* Read/Write: RW
	* Bits: [29:28]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC3SpiProfile7 : 2;        /*## attribute CtlIdacInjRstC3SpiProfile7 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
}R2M06_LpfInjAcqRstProfile7Bits_t;
/**
* R2M06_VcoRegProfile8Bits_t
* RegisterName: VCO_REG_PROFILE8
* Vco control settings
* Address: 0x180
* ResetValue: 0x000F0000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctl_vco_coarse_tuning_9g_spi_profile8
	* Description: Select sub-band for 9 GHz coarse bank.
	*
	* 1g : [6:0] is used
	* 5g : [5:0] is used and MSB is not used
	* Read/Write: RW
	* Bits: [6:0]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoCoarseTuning9GSpiProfile8 : 7;        /*## attribute CtlVcoCoarseTuning9GSpiProfile8 */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 9;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_vco_ivco_fine_spi_profile8
	* Description: Select current VCO
	* Read/Write: RW
	* Bits: [21:16]
	* ResetValue: 0b001111
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoIvcoFineSpiProfile8 : 6;        /*## attribute CtlVcoIvcoFineSpiProfile8 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_vco_bandwidth_spi_profile8
	* Description: Select VCO bandwidth:
	* 0: narrow bandwidth (2 GHz)
	* 1: large bandwidth (4 GHz)
	*
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoBandwidthSpiProfile8 : 1;        /*## attribute CtlVcoBandwidthSpiProfile8 */
	/**
	* BitsName: pllbw_cfg_selection_profile8
	* Description: These bits select the register settings required for the PLLBW. Based on the selection, the settings from the following registers are applied.
	*
	* CP_REG_PLLBW_CFG*, PLL_LPF_C1_PLLBW_CFG*, PLL_LPF_C2_PLLBW_CFG*,
	*
	* x00: PLLBW_CFG0 related settings are applied
	* x01: PLLBW_CFG1 related settings are applied
	* x10: PLLBW_CFG2 related settings are applied
	* x11: PLLBW_CFG3 related settings are applied
	*
	*
	* Read/Write: RW
	* Bits: [27:25]
	* ResetValue: 0b000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t PllbwCfgSelectionProfile8 : 3;        /*## attribute PllbwCfgSelectionProfile8 */
	/**
	* BitsName: ctl_vco_coarse_tuning_fast_bias_en_spi_profile8
	* Description: 0 -long time constant on coarse tuning settling  for normal operation
	* 1- short time constant coarse tuning settling (automatically used inside design during AAFC and subband switching)
	*
	* Note: ctl_vco_coarse_tuning_fast_bias_en_spi_override option is provided to overrule based on the validation results
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoCoarseTuningFastBiasEnSpiProfile8 : 1;        /*## attribute CtlVcoCoarseTuningFastBiasEnSpiProfile8 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 1;        /*## attribute Reserved3 */
}R2M06_VcoRegProfile8Bits_t;
/**
* R2M06_LpfInjAcqRstProfile8Bits_t
* RegisterName: LPF_INJ_ACQ_RST_PROFILE8
* This register controls the LPF injection current during Acquisition
* Address: 0x184
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctl_idac_inj_acq_c1_spi_profile8
	* Description: Injection current for acquisition. Source Level control for LPF C1 bank
	* Read/Write: RW
	* Bits: [6:0]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC1SpiProfile8 : 7;        /*## attribute CtlIdacInjAcqC1SpiProfile8 */
	/**
	* BitsName: ctl_idac_inj_acq_c2_spi_profile8
	* Description: Injection current for acquisition. Source Level control for LPF C2 bank
	* Read/Write: RW
	* Bits: [11:7]
	* ResetValue: 0b00000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC2SpiProfile8 : 5;        /*## attribute CtlIdacInjAcqC2SpiProfile8 */
	/**
	* BitsName: ctl_idac_inj_acq_c3_spi_profile8
	* Description: Injection current for acquisition. Source Level control for LPF C3 bank
	* Read/Write: RW
	* Bits: [13:12]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC3SpiProfile8 : 2;        /*## attribute CtlIdacInjAcqC3SpiProfile8 */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_idac_inj_rst_c1_spi_profile8
	* Description: Injection current for reset. Sink Level control for LPF C1 bank
	* Read/Write: RW
	* Bits: [22:16]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC1SpiProfile8 : 7;        /*## attribute CtlIdacInjRstC1SpiProfile8 */
	/**
	* BitsName: ctl_idac_inj_rst_c2_spi_profile8
	* Description: Injection current for reset. Sink Level control for LPF C2 bank
	* Read/Write: RW
	* Bits: [27:23]
	* ResetValue: 0b00000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC2SpiProfile8 : 5;        /*## attribute CtlIdacInjRstC2SpiProfile8 */
	/**
	* BitsName: ctl_idac_inj_rst_c3_spi_profile8
	* Description: Injection current for reset. Sink Level control for LPF C3 bank
	* Read/Write: RW
	* Bits: [29:28]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC3SpiProfile8 : 2;        /*## attribute CtlIdacInjRstC3SpiProfile8 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
}R2M06_LpfInjAcqRstProfile8Bits_t;
/**
* R2M06_LpfInjAcqRstCommonBits_t
* RegisterName: LPF_INJ_ACQ_RST_COMMON
* This register controls the LPF injection current during Reset
* Address: 0x200
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctl_idac_inj_acq_c1_spi_common
	* Description: Injection current for acquisition. Source Level control for LPF C1 bank
	* Read/Write: RW
	* Bits: [6:0]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC1SpiCommon : 7;        /*## attribute CtlIdacInjAcqC1SpiCommon */
	/**
	* BitsName: ctl_idac_inj_acq_c2_spi_common
	* Description: Injection current for acquisition. Source Level control for LPF C2 bank
	* Read/Write: RW
	* Bits: [11:7]
	* ResetValue: 0b00000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC2SpiCommon : 5;        /*## attribute CtlIdacInjAcqC2SpiCommon */
	/**
	* BitsName: ctl_idac_inj_acq_c3_spi_common
	* Description: Injection current for acquisition. Source Level control for LPF C3 bank
	* Read/Write: RW
	* Bits: [13:12]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC3SpiCommon : 2;        /*## attribute CtlIdacInjAcqC3SpiCommon */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_idac_inj_rst_c1_spi_common
	* Description: Injection current for reset. Sink Level control for LPF C1 bank
	* Read/Write: RW
	* Bits: [22:16]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC1SpiCommon : 7;        /*## attribute CtlIdacInjRstC1SpiCommon */
	/**
	* BitsName: ctl_idac_inj_rst_c2_spi_common
	* Description: Injection current for reset. Sink Level control for LPF C2 bank
	* Read/Write: RW
	* Bits: [27:23]
	* ResetValue: 0b00000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC2SpiCommon : 5;        /*## attribute CtlIdacInjRstC2SpiCommon */
	/**
	* BitsName: ctl_idac_inj_rst_c3_spi_common
	* Description: Injection current for reset. Sink Level control for LPF C3 bank
	* Read/Write: RW
	* Bits: [29:28]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC3SpiCommon : 2;        /*## attribute CtlIdacInjRstC3SpiCommon */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: trigger_to_copy_inj_dac_val
	* Description: Trigger to copy LPF_INJ_ACQ_RST_COMMON register settings to LPF_INJ_ACQ_RST_PROFILE* registers based on the 'store_in_profile*' bits enabled in CHIRP_CALIBRATION_SW_CONTROL register. This bit will be triggered through SPI after computing the idac_injection acquisition and reset C1, C2 & C3 parameters from KVCO_AVG and DVDT on the fly count status and after writing the computed values to LPF_INJ_ACQ_RST_COMMON register through SPI.
	*
	* This is an auto clear bit.
	*
	* Note :  Based on this trigger since the hardware internally updates the profile register settings, it will also trigger the CRC calculation for the new register values in the profile registers.
	* Read/Write: W
	* Bits: [31]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t TriggerToCopyInjDacVal : 1;        /*## attribute TriggerToCopyInjDacVal */
}R2M06_LpfInjAcqRstCommonBits_t;
/**
* R2M06_ChirpCalibrationAacControl1Bits_t
* RegisterName: CHIRP_CALIBRATION_AAC_CONTROL1
* Automatic amplitude calibration settings
*
* Address: 0x220
* ResetValue: 0x0023350A
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: aac_ictrl_min
	* Description: Minimum value for VCO current
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b001010
	* Source: Application
	* FuSa: No
	*/
	uint32_t AacIctrlMin : 6;        /*## attribute AacIctrlMin */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
	/**
	* BitsName: aac_ictrl_init_override_value
	* Description: Initial value for VCO current with override option
	* Read/Write: RW
	* Bits: [13:8]
	* ResetValue: 0b110101
	* Source: Application
	* FuSa: No
	*/
	uint32_t AacIctrlInitOverrideValue : 6;        /*## attribute AacIctrlInitOverrideValue */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: aac_ictrl_init_override
	* Description: override the Initial value for VCO current with 'aac_ictrl_init_override' value programmed
	* Read/Write: RW
	* Bits: [15]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t AacIctrlInitOverride : 1;        /*## attribute AacIctrlInitOverride */
	/**
	* BitsName: aac_ades_in
	* Description: amplitude control desired value
	*
	* desired amplitude = 10^(((level_lo_max_spi - 63)*0.29)/20)*0.9 = 109.8mV * pow(10,((0.29/20*aac_ades_in))
	* Read/Write: RW
	* Bits: [21:16]
	* ResetValue: 0b100011
	* Source: Application
	* FuSa: No
	*/
	uint32_t AacAdesIn : 6;        /*## attribute AacAdesIn */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 10;        /*## attribute Reserved2 */
}R2M06_ChirpCalibrationAacControl1Bits_t;
/**
* R2M06_ChirpCalibrationAacControl2Bits_t
* RegisterName: CHIRP_CALIBRATION_AAC_CONTROL2
* Automatic amplitude calibration settings
*
* Address: 0x224
* ResetValue: 0x00034007
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: aac_lock_ctrl
	* Description: Amplitude loop lock control criteria
	* This control decides the number of stable amplitude iterations to generate the final aac_lock.
	* The vco_amplitude is equal to desired value, then the stable_flag =1. Number of such adjacent stable flag condition is defined by this control.
	*
	* aac_lock_control=0 => Number of consecutive stable states check = 4
	* aac_lock_control=1 => Number of consecutive stable states check = 6
	* aac_lock_control=2 => Number of consecutive stable states check = 8
	* aac_lock_control=3 => Number of consecutive stable states check = 10
	* aac_lock_control=4 => Number of consecutive stable states check = 12
	* aac_lock_control=5 => Number of consecutive stable states check = 14
	* aac_lock_control=6 => Number of consecutive stable states check = 16
	* aac_lock_control=7 => Number of consecutive stable states check = 18
	*
	*
	* Note: The optimal value for aac_lock_control = 7
	*
	*
	* Read/Write: RW
	* Bits: [2:0]
	* ResetValue: 0b111
	* Source: Application
	* FuSa: No
	*/
	uint32_t AacLockCtrl : 3;        /*## attribute AacLockCtrl */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 9;        /*## attribute Reserved0 */
	/**
	* BitsName: aac_ki
	* Description: amplitude control loop gain (aac_Ki) value
	*
	* Lowering the aac_ki will speed down the settling time of the AAC-loop.
	* too_large amplitude of vco determines +1 or -1 times the ki-gain (aac_ki) of the integrator (aac_sum)
	* When aac_ki is equal to 7 (max-value), then the AAC-loop_gain will be 1
	* When aac_ki is equal to 6, then the actual AAC-loop_gain will be 1/2
	* When aac_ki is equal to 5, then the actual AAC-loop_gain will be 1/4
	* When aac_ki is equal to 4, then the actual AAC-loop_gain will be 1/8
	* When aac_ki is equal to 3, then the actual AAC-loop_gain will be 1/16
	* aac_ki=2 or 1 or 0 not used
	* Note: Please note the optimal of aac_ki=7 i.e loop gain of 1
	* Read/Write: RW
	* Bits: [14:12]
	* ResetValue: 0b100
	* Source: Application
	* FuSa: No
	*/
	uint32_t AacKi : 3;        /*## attribute AacKi */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: aac_fref_sel
	* Description: One cycle of amplitude increment/decrement time with analog response. This is represented by fref_aac. Note: 1 us is the minimal response time from analog for any amplitude change. The values other than specified here are possible but these are optimal settings considering the calibration time
	*
	* Fref_aac=Txo*N_aac, Note: Txo = 25ns
	*
	* Aac_fref_sel = 0 => Number of vco divided clock counted in 40MHz = 8, Amplitude loop iteration time represented in real time =  0.2 us
	* Aac_fref_sel = 1 => Number of vco divided clock counted in 40mHz = 16, Amplitude loop iteration time represented in real time = 0.4 us
	* Aac_fref_sel = 2 => Number of vco divided clock counted in 40mHz = 32, Amplitude loop iteration time represented in real time = 0.8 us
	* Aac_fref_sel = 3 => Number of vco divided clock counted in 40mHz = 64, Amplitude loop iteration time represented in real time = 1.6 us
	* Aac_fref_sel = 4 => Number of vco divided clock counted in 40mHz = 128	, Amplitude loop iteration time represented in real time = 3.2 us
	* Aac_fref_sel = 5 => Number of vco divided clock counted in 40mHz = 256	, Amplitude loop iteration time represented in real time = 6.4 us
	*
	*
	*
	*
	* Note: Please note the optimal value for Aac_fref_sel = 3
	*
	*
	* Read/Write: RW
	* Bits: [18:16]
	* ResetValue: 0b011
	* Source: Application
	* FuSa: No
	*/
	uint32_t AacFrefSel : 3;        /*## attribute AacFrefSel */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 13;        /*## attribute Reserved2 */
}R2M06_ChirpCalibrationAacControl2Bits_t;
/**
* R2M06_ChirpCalibrationAfcControl1Bits_t
* RegisterName: CHIRP_CALIBRATION_AFC_CONTROL1
* Automatic frequency calibration settings1
*
*
* Address: 0x228
* ResetValue: 0x05104000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: afc_fsel_min
	* Description: Minimal value of the sub-band
	* Read/Write: RW
	* Bits: [6:0]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t AfcFselMin : 7;        /*## attribute AfcFselMin */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: afc_fsel_init_override_value
	* Description: Initial value for the sub-band 1g/2g.
	* For 5g mode, this value should be 'd32
	*
	*
	* Read/Write: RW
	* Bits: [14:8]
	* ResetValue: 0b1000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t AfcFselInitOverrideValue : 7;        /*## attribute AfcFselInitOverrideValue */
	/**
	* BitsName: afc_fsel_init_override
	* Description: override the Initial value for the sub-band with 'afc_fsel_init_override_value' programmed
	* Read/Write: RW
	* Bits: [15]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t AfcFselInitOverride : 1;        /*## attribute AfcFselInitOverride */
	/**
	* BitsName: afc_mdes
	* Description: frequency loop desired Mvalue.
	* Desired Mvalue is the number of clock cycles of vco divide frequency counted for a reference duration for a given start frequency
	* Afc_mdes = (Start_freq * TFref_afc) / Divider_value
	* Note: Divider_value = 3*2*N, Where N is the ctl_div_force  subfield of DIVIDE_FORCE_REGISTER = 32. TFref_afc is the time selected in the afc_fref_sel in the CHIRP_CALIBRATION_AFC_CONTROL2 register
	*
	* Note: Incase of HW based mdes calculation, the value is always DIVIDE_FORCE_REGISTER = 32. For SW based mdes calculation, this is programmable in the register. But default value is recommended
	*
	* Read/Write: RW
	* Bits: [27:16]
	* ResetValue: 0b010100010000
	* Source: Application
	* FuSa: No
	*/
	uint32_t AfcMdes : 12;        /*## attribute AfcMdes */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 4;        /*## attribute Reserved1 */
}R2M06_ChirpCalibrationAfcControl1Bits_t;
/**
* R2M06_ChirpCalibrationAfcControl2Bits_t
* RegisterName: CHIRP_CALIBRATION_AFC_CONTROL2
* Automatic frequency calibration settings2
*
* Address: 0x22C
* ResetValue: 0x00667372
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: afc_lock_ctrl1
	* Description: frequency loop1 lock control criterium 1
	* This is first frequency loop.
	* This control decides the number of stable sub-band iterations to generate the final afc_lock.
	* The count is equal to desired value(mdes), then the stable_flag =1. Number of such adjacent stable flag condition is defined by this control.
	*
	* afc_lock_ctrl1 = 0 => Number of consecutive stable states check = 1
	* afc_lock_ctrl1 = 1 => Number of consecutive stable states check = 2
	* afc_lock_ctrl1 = 2 => Number of consecutive stable states check = 3
	* afc_lock_ctrl1 = 3 => Number of consecutive stable states check = 4
	* afc_lock_ctrl1 = 4 => Number of consecutive stable states check = 5
	* afc_lock_ctrl1 = 5 => Number of consecutive stable states check = 6
	* afc_lock_ctrl1 = 6 => Number of consecutive stable states check = 7
	* afc_lock_ctrl1 = 7 => Number of consecutive stable states check = 8
	*
	*
	* Note: The optimal value for afc_lock_ctrl1 = 7
	*
	*
	*
	*
	*
	* Read/Write: RW
	* Bits: [2:0]
	* ResetValue: 0b010
	* Source: Application
	* FuSa: No
	*/
	uint32_t AfcLockCtrl1 : 3;        /*## attribute AfcLockCtrl1 */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: afc_lock_ctrl2
	* Description: frequency loop2 lock control criterium 2
	* This is final frequency loop after amplitude calibration.
	* This control decides the number of stable sub-band iterations to generate the final afc_lock.
	* The count is equal to desired value(mdes), then the stable_flag =1. Number of such adjacent stable flag condition is defined by this control.
	*
	*
	* afc_lock_ctrl2 = 0 => Number of consecutive stable states check = 1
	* afc_lock_ctrl2 = 1 => Number of consecutive stable states check = 2
	* afc_lock_ctrl2 = 2 => Number of consecutive stable states check = 3
	* afc_lock_ctrl2 = 3 => Number of consecutive stable states check = 4
	* afc_lock_ctrl2 = 4 => Number of consecutive stable states check = 5
	* afc_lock_ctrl2 = 5 => Number of consecutive stable states check = 6
	* afc_lock_ctrl2 = 6 => Number of consecutive stable states check = 7
	* afc_lock_ctrl2 = 7 => Number of consecutive stable states check = 8
	*
	*
	* Note: The optimal value for afc_lock_ctrl2 = 7
	*
	*
	* Read/Write: RW
	* Bits: [6:4]
	* ResetValue: 0b111
	* Source: Application
	* FuSa: No
	*/
	uint32_t AfcLockCtrl2 : 3;        /*## attribute AfcLockCtrl2 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: afc_step_limit
	* Description:
	* frequency loop integrator step limiter which determines the sub-band increment/decrement step size. Note: Only mentioned sub-sets are needed
	* afc_mdif_lim = -2  => afc_step_limit =  0, sub-band limit check = (afc_mdif <=  -2)
	* afc_mdif_lim =  2  => afc_step_limit =  0, sub-band limit check = (afc_mdif >     1)
	* afc_mdif_lim = -4  => afc_step_limit =  1, sub-band limit check = (afc_mdif <=  -4)
	* afc_mdif_lim =  4  => afc_step_limit =  1, sub-band limit check = (afc_mdif >     3)
	* afc_mdif_lim = -8  => afc_step_limit =  2, sub-band limit check = (afc_mdif <=  -8) (4G Mode)
	* afc_mdif_lim =  8  => afc_step_limit =  2, sub-band limit check = (afc_mdif >     7)
	* afc_mdif_lim = -16 => afc_step_limit = 3, sub-band limit check = (afc_mdif <= -16) (1G/2G Mode)
	* afc_mdif_lim =  16 => afc_step_limit = 3, sub-band limit check = (afc_mdif >    15)
	* afc_mdif_lim = -32 => afc_step_limit = 4, sub-band limit check = (afc_mdif <= -32)
	* afc_mdif_lim =  32 => afc_step_limit = 4, sub-band limit check = (afc_mdif >    31)
	* afc_mdif_lim = -64 => afc_step_limit = 5, sub-band limit check = (afc_mdif <= -64)
	* afc_mdif_lim =  64 => afc_step_limit = 5, sub-band limit check = (afc_mdif >    63)
	*
	* Note: Optimal value of afc_step_limit = 2 or 3 for 4G and 1G/2G Mode respectively. To be validated
	* Read/Write: RW
	* Bits: [10:8]
	* ResetValue: 0b011
	* Source: Application
	* FuSa: No
	*/
	uint32_t AfcStepLimit : 3;        /*## attribute AfcStepLimit */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 1;        /*## attribute Reserved2 */
	/**
	* BitsName: afc_ki_ctrl1
	* Description: Frequency control loop gain (afc_Ki) value for the first (coarse) AFC loop
	*
	* Lowering the afc_ki will speed down the settling time of the AFC-loop.
	* The difference between the actual count and the desired value is multiplied by this gain.
	* When afc_ki_ctrl1 is equal to 7 (max-value), then the AFC-loop_gain will be 1/2
	* When afc_ki_ctrl1 is equal to 6, then the actual AFC-loop_gain will be 1/4
	* When afc_ki_ctrl1 is equal to 5, then the actual AFC-loop_gain will be 1/8
	* When afc_ki_ctrl1 is equal to 4, then the actual AFC-loop_gain will be 1/16
	* When afc_ki_ctrl1 is equal to 3, then the actual AFC-loop_gain will be 1/32
	* afc_ki_ctrl1 = 2 or 1 or 0 not used
	*
	* Note1: Set to default of afc_ki_ctrl1=7 i.e loop gain of 1/2
	* Note2: For 1g/2g mode, afc_ki_ctrl1 = 3'b111 is recommended. But to be validated
	* Note3: For 4g mode, afc_ki_ctrl1 = 3'b110  is recommended. But to be validated
	* Read/Write: RW
	* Bits: [14:12]
	* ResetValue: 0b111
	* Source: Application
	* FuSa: No
	*/
	uint32_t AfcKiCtrl1 : 3;        /*## attribute AfcKiCtrl1 */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 1;        /*## attribute Reserved3 */
	/**
	* BitsName: afc_ki_ctrl2
	* Description: Frequency control loop gain (afc_Ki) value for the second (Fine) AFC loop
	*
	* Lowering the afc_ki will speed down the settling time of the AFC-loop.
	* The difference between the actual count and the desired value is multiplied by this gain.
	* When afc_ki_ctrl2 is equal to 7 (max-value), then the AFC-loop_gain will be 1/2
	* When afc_ki_ctrl2 is equal to 6, then the actual AFC-loop_gain will be 1/4
	* When afc_ki_ctrl2 is equal to 5, then the actual AFC-loop_gain will be 1/8
	* When afc_ki_ctrl2 is equal to 4, then the actual AFC-loop_gain will be 1/16
	* When afc_ki_ctrl2 is equal to 3, then the actual AFC-loop_gain will be 1/32
	* afc_ki_ctrl2 = 2 or 1 or 0 not used
	*
	* Note1: Set to default (optimal) of afc_ki_ctrl2 = 6 i.e loop gain of 1/4
	* Note2: For 1g/2g mode, afc_ki_ctrl2 = 3'b110 is recommended. But to be validated
	* Note3: For 4g mode, afc_ki_ctrl2 = 3'b101  is recommended. But to be validated
	* Read/Write: RW
	* Bits: [18:16]
	* ResetValue: 0b110
	* Source: Application
	* FuSa: No
	*/
	uint32_t AfcKiCtrl2 : 3;        /*## attribute AfcKiCtrl2 */
	/**
	* BitsName: Reserved_4
	* Description: not used
	*/
	uint32_t Reserved4 : 1;        /*## attribute Reserved4 */
	/**
	* BitsName: afc_fref_sel
	* Description: The frequency iteration time for each sub-band
	* Fref_afc=Txo*N_afc, Note: Txo = 25ns Note: The values other than specified here are possible but these are optimal settings considering the calibration time
	*
	* afc_fref_sel = 0	=> Number of vco divided clock counted in 40MHz = 2, Frequency loop iteration time represented in real time = 0.05 us
	* afc_fref_sel = 1	=> Number of vco divided clock counted in 40MHz = 4, Frequency loop iteration time represented in real time = 0.1 us
	* afc_fref_sel = 2	=> Number of vco divided clock counted in 40MHz = 8, Frequency loop iteration time represented in real time = 0.2 us
	* afc_fref_sel = 3	=> Number of vco divided clock counted in 40MHz = 16, Frequency loop iteration time represented in real time = 0.4 us
	* afc_fref_sel = 4	=> Number of vco divided clock counted in 40MHz = 32, Frequency loop iteration time represented in real time = 0.8 us
	* afc_fref_sel = 5	=> Number of vco divided clock counted in 40MHz = 64, Frequency loop iteration time represented in real time = 1.6 us
	* afc_fref_sel = 6	=> Number of vco divided clock counted in 40MHz = 128,	 Frequency loop iteration time represented in real time = 3.2 us
	* afc_fref_sel = 7	=> Number of vco divided clock counted in 40MHz = 256, Frequency loop iteration time represented in real time = 6.4 us
	*
	*
	* Note: The optimal value for afc_fref_sel = 6
	*
	*
	*
	*
	*
	*
	* Read/Write: RW
	* Bits: [23:20]
	* ResetValue: 0b0110
	* Source: Application
	* FuSa: No
	*/
	uint32_t AfcFrefSel : 4;        /*## attribute AfcFrefSel */
	/**
	* BitsName: Reserved_5
	* Description: not used
	*/
	uint32_t Reserved5 : 8;        /*## attribute Reserved5 */
}R2M06_ChirpCalibrationAfcControl2Bits_t;
/**
* R2M06_DivideForceControlBits_t
* RegisterName: DIVIDE_FORCE_CONTROL
* PLL divider settings
* Address: 0x240
* ResetValue: 0x00000120
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctl_div_force
	* Description: defines the PLL loop back divider (26-28[dec] are allowed settings). Requires 'ctl_force_divider' to be set (otherwise the divider is under control of sweep engine)
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b100000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlDivForce : 6;        /*## attribute CtlDivForce */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_force_divider
	* Description: enables forcing a PLL loop back divider. If set, divider is programmed to the setting of 'ctl_div_force' (see field ). In order to make the initial frequency defined at startup (before application programs), this bit is forced with fixed divider. This should be set to '0' in the application mode.
	* 1 :  Enable pll loop back divider
	* 0 :  Disable pll loop back divider
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlForceDivider : 1;        /*## attribute CtlForceDivider */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 23;        /*## attribute Reserved1 */
}R2M06_DivideForceControlBits_t;
/**
* R2M06_LpfEnableSettingsBits_t
* RegisterName: LPF_ENABLE_SETTINGS
* Loop filter settings
* Address: 0x244
* ResetValue: 0x17610017
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctl_lpf_prog_force_voltage_spi
	* Description: Program the force vtune voltage (start/edge frequency)
	* Read/Write: RW
	* Bits: [6:0]
	* ResetValue: 0b0010111
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlLpfProgForceVoltageSpi : 7;        /*## attribute CtlLpfProgForceVoltageSpi */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_lpf_force_vtune_en_spi
	* Description: Enable the force vtune circuit
	* 1 :  Enable force vtune circuit
	* 0 :  Disable  force vtune circuit
	*
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlLpfForceVtuneEnSpi : 1;        /*## attribute CtlLpfForceVtuneEnSpi */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_lpf_ext_en_spi
	* Description: Enable external VCO tune voltage.
	* 1 :  Enable external vco tune voltage
	* 0 :  Disable external vco tune voltage
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlLpfExtEnSpi : 1;        /*## attribute CtlLpfExtEnSpi */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: ctl_lpf_int_en_spi
	* Description:
	* Enable internal loop filter (connection between CP and VCO)
	* 1 :  Enable loop filter
	* 0 :  Disable loop filter
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlLpfIntEnSpi : 1;        /*## attribute CtlLpfIntEnSpi */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: ctl_lpf_vtune_monitor_en_spi
	* Description: Enable the vtune monitor
	* 1 :  Enable vtune monitor
	* 0 :  Disable  vtune monitor
	* Read/Write: RW
	* Bits: [20]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlLpfVtuneMonitorEnSpi : 1;        /*## attribute CtlLpfVtuneMonitorEnSpi */
	/**
	* BitsName: ctl_lpf_fr_buffer_en_spi
	* Description:
	* Enable lpf fast reset buffer
	* 1 :  Enable buffer
	* 0 :  Disable buffer
	* Read/Write: RW
	* Bits: [21]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlLpfFrBufferEnSpi : 1;        /*## attribute CtlLpfFrBufferEnSpi */
	/**
	* BitsName: ctl_lpf_fr_cmp_en_spi
	* Description:
	* Enable comparator
	* 1 :  Enable comparator
	* 0 :  Disable comparator
	* Read/Write: RW
	* Bits: [22]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlLpfFrCmpEnSpi : 1;        /*## attribute CtlLpfFrCmpEnSpi */
	/**
	* BitsName: Reserved_4
	* Description: not used
	*/
	uint32_t Reserved4 : 1;        /*## attribute Reserved4 */
	/**
	* BitsName: ctl_lpf_prog_force_voltage_cf_spi
	* Description: Program the force vtune voltage for center frequency (cf)
	* Read/Write: RW
	* Bits: [30:24]
	* ResetValue: 0b0010111
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlLpfProgForceVoltageCfSpi : 7;        /*## attribute CtlLpfProgForceVoltageCfSpi */
	/**
	* BitsName: Reserved_5
	* Description: not used
	*/
	uint32_t Reserved5 : 1;        /*## attribute Reserved5 */
}R2M06_LpfEnableSettingsBits_t;
/**
* R2M06_VcoEnableSettingsBits_t
* RegisterName: VCO_ENABLE_SETTINGS
* Loop filter settings only for internal use
* Address: 0x248
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctl_vco_en_spi
	* Description: Enable VCO
	* 1 :  Enable VCO
	* 0 :  Disable VCO
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoEnSpi : 1;        /*## attribute CtlVcoEnSpi */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 11;        /*## attribute Reserved0 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 19;        /*## attribute Reserved2 */
}R2M06_VcoEnableSettingsBits_t;
/**
* R2M06_FuncsafeMonVtuneControlBits_t
* RegisterName: FUNCSAFE_MON_VTUNE_CONTROL
* Functional safety monitor related to vtune settings
* Address: 0x24C
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: ctl_vtune_vco_low_spi
	* Description: tuning voltage monitor low threshold: V_thresh =  V_thresh = 50mV + ctl_vtune_vco_low * 12.5mV
	* Read/Write: RW
	* Bits: [3:0]
	* ResetValue: 0b0000
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t CtlVtuneVcoLowSpi : 4;        /*## attribute CtlVtuneVcoLowSpi */
	/**
	* BitsName: ctl_vtune_vco_high_spi
	* Description: tuning voltage monitor high threshold: V_thresh = 850mV + ctl_vtune_vco_high * 12.5mV
	* Read/Write: RW
	* Bits: [7:4]
	* ResetValue: 0b0000
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t CtlVtuneVcoHighSpi : 4;        /*## attribute CtlVtuneVcoHighSpi */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 24;        /*## attribute Reserved0 */
}R2M06_FuncsafeMonVtuneControlBits_t;
/**
* R2M06_FuncsafeMonUnlockControlBits_t
* RegisterName: FUNCSAFE_MON_UNLOCK_CONTROL
* Functional safety monitor related to unlock settings
* Address: 0x250
* ResetValue: 0x00100400
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 6;        /*## attribute Reserved0 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_ld_window_offset_spi
	* Description: Lock detector window offset
	*
	* Read/Write: RW
	* Bits: [13:8]
	* ResetValue: 0b000100
	* Source: Application
	* FuSa: Y
	*/
	uint32_t CtlLdWindowOffsetSpi : 6;        /*## attribute CtlLdWindowOffsetSpi */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: ctl_ld_pol_spi
	* Description: Lock detector polarity
	* 1: Negative polarity
	* 0: Positive polarity
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t CtlLdPolSpi : 1;        /*## attribute CtlLdPolSpi */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: ctl_ld_en_spi
	* Description: Enable Lock detector
	* 1: Enable lock detector
	* 0: Disable lock detector
	* Read/Write: RW
	* Bits: [20]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: Y
	*/
	uint32_t CtlLdEnSpi : 1;        /*## attribute CtlLdEnSpi */
	/**
	* BitsName: Reserved_4
	* Description: not used
	*/
	uint32_t Reserved4 : 11;        /*## attribute Reserved4 */
}R2M06_FuncsafeMonUnlockControlBits_t;
/**
* R2M06_FuncsafeMonLevelSettingsBits_t
* RegisterName: FUNCSAFE_MON_LEVEL_SETTINGS
* Functional safety monitor related to vco level settings
* Address: 0x254
* ResetValue: 0x3530150C
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: ctl_level_vco_min_spi
	* Description:
	* Low trigger level for FSM (the most low threshold voltage):
	*
	* V_thresh_min =10^(((ctl_level_vco_min_spi - 63)*0.29)/20)*0.9 = 109.8mV * pow(10,((0.29/20* ctl_level_vco_min_spi))
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b001100
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t CtlLevelVcoMinSpi : 6;        /*## attribute CtlLevelVcoMinSpi */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_level_vco_low_spi
	* Description: Low trigger level for Gain Control:
	*
	* V_thresh_low =10^(((ctl_level_vco_low_spi - 63)*0.29)/20)*0.9 = 109.8mV * pow(10,((0.29/20* ctl_level_vco_low_spi))
	* Read/Write: RW
	* Bits: [13:8]
	* ResetValue: 0b010101
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t CtlLevelVcoLowSpi : 6;        /*## attribute CtlLevelVcoLowSpi */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_level_vco_high_spi
	* Description: High trigger level for Gain Control:
	*
	* V_thresh_high =10^(((ctl_level_vco_high_spi - 63)*0.29)/20)*0.9 = 109.8mV * pow(10,((0.29/20* ctl_level_vco_high_spi))
	* Read/Write: RW
	* Bits: [21:16]
	* ResetValue: 0b110000
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t CtlLevelVcoHighSpi : 6;        /*## attribute CtlLevelVcoHighSpi */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: ctl_level_vco_max_spi
	* Description: High trigger level for Reliability (the most high threshold voltage):
	*
	*
	* V_thresh_max =10^(((ctl_level_vco_max_spi - 63)*0.29)/20)*0.9 = 109.8mV * pow(10,((0.29/20* ctl_level_vco_max_spi))
	* Read/Write: RW
	* Bits: [29:24]
	* ResetValue: 0b110101
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t CtlLevelVcoMaxSpi : 6;        /*## attribute CtlLevelVcoMaxSpi */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 2;        /*## attribute Reserved3 */
}R2M06_FuncsafeMonLevelSettingsBits_t;
/**
* R2M06_FuncsafeMonTempThresholdBits_t
* RegisterName: FUNCSAFE_MON_TEMP_THRESHOLD
* Over-temperature detection threshold control. Untrimmed range 94..165 degree Celcius
* Address: 0x258
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: ts_threshold_sel_spi
	* Description: Set the maximum temperature threshold values
	* Read/Write: RW
	* Bits: [6:0]
	* ResetValue: 0b0000000
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t TsThresholdSelSpi : 7;        /*## attribute TsThresholdSelSpi */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 25;        /*## attribute Reserved0 */
}R2M06_FuncsafeMonTempThresholdBits_t;
/**
* R2M06_AtbTrimBits_t
* RegisterName: ATB_TRIM
* Trim settings for ATB
* Address: 0x260
* ResetValue: 0x0000002B
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: set_trim_r_n_spi
	* Description: Trim bits. debug/test feature: trimming of local I/V conversion for ATB tests, only lower 5 bits are used
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b101011
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t SetTrimRNSpi : 6;        /*## attribute SetTrimRNSpi */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 26;        /*## attribute Reserved0 */
}R2M06_AtbTrimBits_t;
/**
* R2M06_FilterParTrimBits_t
* RegisterName: FILTER_PAR_TRIM
* Trim settings for FILTER from OTP
* Address: 0x264
* ResetValue: 0x00011616
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctl_lpf_r1_spi
	* Description: Select loop filter res. R1
	* Read/Write: RW
	* Bits: [4:0]
	* ResetValue: 0b10110
	* Source: OTP
	* FuSa: No
	*/
	uint32_t CtlLpfR1Spi : 5;        /*## attribute CtlLpfR1Spi */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 5;        /*## attribute Reserved1 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: cp_r1_r2_settings_to_profile
	* Description: R2 IS NOT USED IN THE DESIGN
	* copy the R1 and R2 settings from this register to all profile registers PLL_LPF_RES_SETTINGS_PROFILE*
	*
	* 1 : copy the settings to all profile registers PLL_LPF_RES_SETTINGS_PROFILE*
	* 0 : Do not copy the settings and profile registers to be programmed
	*
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t CpR1R2SettingsToProfile : 1;        /*## attribute CpR1R2SettingsToProfile */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 15;        /*## attribute Reserved3 */
}R2M06_FilterParTrimBits_t;
/**
* R2M06_VcoCurrentTrimBits_t
* RegisterName: VCO_CURRENT_TRIM
* Trim settings for VCO current
* Address: 0x268
* ResetValue: 0x0000000F
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctl_vco_r_ibias_set_spi
	* Description: Select resistor used for VCO current generation
	* Read/Write: RW
	* Bits: [4:0]
	* ResetValue: 0b01111
	* Source: OTP
	* FuSa: No
	*/
	uint32_t CtlVcoRIbiasSetSpi : 5;        /*## attribute CtlVcoRIbiasSetSpi */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 27;        /*## attribute Reserved0 */
}R2M06_VcoCurrentTrimBits_t;
/**
* R2M06_FuncsafeMonLevelSettingsEnBits_t
* RegisterName: FUNCSAFE_MON_LEVEL_SETTINGS_EN
* Functional safety monitor related to vco level settings
* Address: 0x26C
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: ctl_level_vco_amp_monitor_en_spi
	* Description: Enable the amplitude monitor
	* 1: Enable amplitude monitor
	* 0: Disable amplitude monitor
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t CtlLevelVcoAmpMonitorEnSpi : 1;        /*## attribute CtlLevelVcoAmpMonitorEnSpi */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 31;        /*## attribute Reserved0 */
}R2M06_FuncsafeMonLevelSettingsEnBits_t;
/**
* R2M06_SubbandAmpCorrectionModeSelBits_t
* RegisterName: SUBBAND_AMP_CORRECTION_MODE_SEL
* The register to control the sub-band and amplitude correction in the special cases. This register is not used in the normal mode.
*
* The monitors inside the chirp indicate when such a sub-band correction is required. If the correction mode is enabled in this register, the necessary change setting are applied from this register + SUBBAND_CORRECTION_OTP_SETTING* registers
*
*
* Note: vtune status registers in the chirp and ISM will be set when such sub-band change request is triggered by the chirp vtune monitors
*
*
* Example Application case:
* When a profile dynamically demands a frequency which is outside the currently selected sub-band, the following settings can be used to switch the sub-band and accordingly the amplitude also can be adjusted. The trigger for such sub-band change is indicated by the tune monitors within chirp.
*
* Address: 0x270
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: subband_correction_enable
	* Description: sub-band correction enable bit
	*
	* 0 :  No sub-band correction
	* 1 :  sub-band correction is enabled
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t SubbandCorrectionEnable : 1;        /*## attribute SubbandCorrectionEnable */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: subband_increment
	* Description: when vtune_high status monitor is triggered, the subband is incremented by the programmed value
	*
	* subband increment value programmable between 0x0 to 0xF. This value gets added to the existing subband after the OTP correction value coming from OTP_TRIM_SUBBAND_CORRECTION_*
	*
	*
	* Read/Write: RW
	* Bits: [9:4]
	* ResetValue: 0b000000
	* Source: Application
	* FuSa: Y
	*/
	uint32_t SubbandIncrement : 6;        /*## attribute SubbandIncrement */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: subband_decrement
	* Description: when vtune_low status monitor is triggered, the subband is decremented by the programmed value
	*
	* subband decrement value programmable between 0x0 to 0xF. This value gets subtracted with the existing subband after the OTP correction value coming from OTP_TRIM_SUBBAND_CORRECTION_*
	*
	*
	* Read/Write: RW
	* Bits: [17:12]
	* ResetValue: 0b000000
	* Source: Application
	* FuSa: Y
	*/
	uint32_t SubbandDecrement : 6;        /*## attribute SubbandDecrement */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 2;        /*## attribute Reserved3 */
	/**
	* BitsName: Reserved_4
	* Description: not used
	*/
	uint32_t Reserved4 : 4;        /*## attribute Reserved4 */
	/**
	* BitsName: Reserved_5
	* Description: not used
	*/
	uint32_t Reserved5 : 4;        /*## attribute Reserved5 */
	/**
	* BitsName: ctl_vco_coarse_tuning_fast_bias_en_spi_override
	* Description: Override the short time constant by keeping the switch open
	*
	* 0 - No override. The value of ctl_vco_coarse_tuning_fast_bias_en_spi_profile* from register vco_reg_profile* is taken
	* 1 - Override.  ctl_vco_coarse_tuning_fast_bias_en_spi = 0
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t CtlVcoCoarseTuningFastBiasEnSpiOverride : 1;        /*## attribute CtlVcoCoarseTuningFastBiasEnSpiOverride */
	/**
	* BitsName: Reserved_6
	* Description: not used
	*/
	uint32_t Reserved6 : 2;        /*## attribute Reserved6 */
	/**
	* BitsName: amplitude_incr_decr_sel
	* Description: nan
	* Read/Write: RW
	* Bits: [31]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t AmplitudeIncrDecrSel : 1;        /*## attribute AmplitudeIncrDecrSel */
}R2M06_SubbandAmpCorrectionModeSelBits_t;
/**
* R2M06_OtpTrimSubbandCorrection1GBits_t
* RegisterName: OTP_TRIM_SUBBAND_CORRECTION_1G
* The register to control the sub-band in the special cases like non-linear behaviour of the vco wrt specific sub-band. This register is not used in the normal mode. If used, it is used with SUBBAND_AMP_CORRECTION_MODE_SEL register
*
* OTP additional correction settings for certain special sub-bands in 1G mode
* Address: 0x274
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: vco_1g_skip_16
	* Description: sub-band 16 should be skipped by the delta mentioned in this field
	* Read/Write: RW
	* Bits: [2:0]
	* ResetValue: 0b000
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t Vco1GSkip16 : 3;        /*## attribute Vco1GSkip16 */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: vco_1g_skip_32
	* Description: sub-band 32 should be skipped by the delta mentioned in this field
	* Read/Write: RW
	* Bits: [6:4]
	* ResetValue: 0b000
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t Vco1GSkip32 : 3;        /*## attribute Vco1GSkip32 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: vco_1g_skip_48
	* Description: sub-band 48 should be skipped by the delta mentioned in this field
	* Read/Write: RW
	* Bits: [11:8]
	* ResetValue: 0b0000
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t Vco1GSkip48 : 4;        /*## attribute Vco1GSkip48 */
	/**
	* BitsName: vco_1g_skip_64
	* Description: sub-band 64 should be skipped by the delta mentioned in this field
	* Read/Write: RW
	* Bits: [17:12]
	* ResetValue: 0b000000
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t Vco1GSkip64 : 6;        /*## attribute Vco1GSkip64 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: vco_1g_skip_80
	* Description: sub-band 80 should be skipped by the delta mentioned in this field
	* Read/Write: RW
	* Bits: [23:20]
	* ResetValue: 0b0000
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t Vco1GSkip80 : 4;        /*## attribute Vco1GSkip80 */
	/**
	* BitsName: vco_1g_skip_96
	* Description: sub-band 96 should be skipped by the delta mentioned in this field
	* Read/Write: RW
	* Bits: [26:24]
	* ResetValue: 0b000
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t Vco1GSkip96 : 3;        /*## attribute Vco1GSkip96 */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 1;        /*## attribute Reserved3 */
	/**
	* BitsName: vco_1g_skip_112
	* Description: sub-band 112 should be skipped by the delta mentioned in this field
	* Read/Write: RW
	* Bits: [30:28]
	* ResetValue: 0b000
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t Vco1GSkip112 : 3;        /*## attribute Vco1GSkip112 */
	/**
	* BitsName: Reserved_4
	* Description: not used
	*/
	uint32_t Reserved4 : 1;        /*## attribute Reserved4 */
}R2M06_OtpTrimSubbandCorrection1GBits_t;
/**
* R2M06_OtpTrimSubbandCorrection2GBits_t
* RegisterName: OTP_TRIM_SUBBAND_CORRECTION_2G
* The register to control the sub-band in the special cases like non-linear behaviour of the vco wrt specific sub-band. This register is not used in the normal mode. If used, it is used with SUBBAND_AMP_CORRECTION_MODE_SEL register
*
* OTP additional correction settings for certain special sub-bands in 2G mode
* Address: 0x278
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: vco_2g_skip_16
	* Description: sub-band 16 should be skipped by the delta mentioned in this field
	* Read/Write: RW
	* Bits: [2:0]
	* ResetValue: 0b000
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t Vco2GSkip16 : 3;        /*## attribute Vco2GSkip16 */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: vco_2g_skip_32
	* Description: sub-band 32 should be skipped by the delta mentioned in this field
	* Read/Write: RW
	* Bits: [6:4]
	* ResetValue: 0b000
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t Vco2GSkip32 : 3;        /*## attribute Vco2GSkip32 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: vco_2g_skip_48
	* Description: sub-band 48 should be skipped by the delta mentioned in this field
	* Read/Write: RW
	* Bits: [11:8]
	* ResetValue: 0b0000
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t Vco2GSkip48 : 4;        /*## attribute Vco2GSkip48 */
	/**
	* BitsName: vco_2g_skip_64
	* Description: sub-band 64 should be skipped by the delta mentioned in this field
	* Read/Write: RW
	* Bits: [17:12]
	* ResetValue: 0b000000
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t Vco2GSkip64 : 6;        /*## attribute Vco2GSkip64 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: vco_2g_skip_80
	* Description: sub-band 80 should be skipped by the delta mentioned in this field
	* Read/Write: RW
	* Bits: [23:20]
	* ResetValue: 0b0000
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t Vco2GSkip80 : 4;        /*## attribute Vco2GSkip80 */
	/**
	* BitsName: vco_2g_skip_96
	* Description: sub-band 96 should be skipped by the delta mentioned in this field
	* Read/Write: RW
	* Bits: [26:24]
	* ResetValue: 0b000
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t Vco2GSkip96 : 3;        /*## attribute Vco2GSkip96 */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 1;        /*## attribute Reserved3 */
	/**
	* BitsName: vco_2g_skip_112
	* Description: sub-band 112 should be skipped by the delta mentioned in this field
	* Read/Write: RW
	* Bits: [30:28]
	* ResetValue: 0b000
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t Vco2GSkip112 : 3;        /*## attribute Vco2GSkip112 */
	/**
	* BitsName: Reserved_4
	* Description: not used
	*/
	uint32_t Reserved4 : 1;        /*## attribute Reserved4 */
}R2M06_OtpTrimSubbandCorrection2GBits_t;
/**
* R2M06_OtpTrimSubbandCorrection4GBits_t
* RegisterName: OTP_TRIM_SUBBAND_CORRECTION_4G
* The register to control the sub-band in the special cases like non-linear behaviour of the vco wrt specific sub-band. This register is not used in the normal mode. If used, it is used with SUBBAND_AMP_CORRECTION_MODE_SEL register
*
* OTP additional correction settings for certain special sub-bands in 4G mode
* Address: 0x27C
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: vco_4g_skip_16
	* Description: sub-band 16 should be skipped by the delta mentioned in this field
	* Read/Write: RW
	* Bits: [2:0]
	* ResetValue: 0b000
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t Vco4GSkip16 : 3;        /*## attribute Vco4GSkip16 */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: vco_4g_skip_32
	* Description: sub-band 32 should be skipped by the delta mentioned in this field
	* Read/Write: RW
	* Bits: [6:4]
	* ResetValue: 0b000
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t Vco4GSkip32 : 3;        /*## attribute Vco4GSkip32 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: vco_4g_skip_48
	* Description: sub-band 48 should be skipped by the delta mentioned in this field
	* Read/Write: RW
	* Bits: [11:8]
	* ResetValue: 0b0000
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t Vco4GSkip48 : 4;        /*## attribute Vco4GSkip48 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 20;        /*## attribute Reserved2 */
}R2M06_OtpTrimSubbandCorrection4GBits_t;
/**
* R2M06_HighPllbwSwitchControlBits_t
* RegisterName: HIGH_PLLBW_SWITCH_CONTROL
* This register controls switching from high pll bw configuration to profile bw configuration to avoid larger settling time. Usually this is useful during standby mode to poweron mode switching or large sub-band switching between adjacent chirps. The registers CP_PLLBW_CFG_HIGH,  PLL_LPF_C1_PLLBW_CFG_HIGH, PLL_LPF_C2_PLLBW_CFG_HIGH, PLL_LPF_C3_PLLBW_CFG_HIGH, PLL_LPF_RES_PLLBW_CFG_HIGH are the registers which will override the profile register values derived from CP_PLLBW_CFG*,  PLL_LPF_C1_PLLBW_CFG*, PLL_LPF_C2_PLLBW_CFG*, PLL_LPF_C3_PLLBW_CFG*, PLL_LPF_RES_PLLBW_CFG*
* Address: 0x280
* ResetValue: 0x01901906
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: high_pllbw_to_prof_bw_switch_enable
	* Description: Enable high pll bw switch feature overriding the profile info for shorter period (defined by high_pllbw_to_prof_bw_switch_time bits)
	* 1: Enable high pll bw switch at the start of the tdwell overriding the profile info
	* 0:  Disable high pll bw switch at the start of the tdwell and use only the profile info
	* Note: Once enabled, this is applicable for all chirps; in order to perform this for selective chirps, dynamically this bit has to be programmed during the Idle time of each chirp
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t HighPllbwToProfBwSwitchEnable : 1;        /*## attribute HighPllbwToProfBwSwitchEnable */
	/**
	* BitsName: high_pllbw_to_prof_bw_seq_start_switch_enable
	* Description: Enable high pll bw switch feature overriding the profile info for shorter period during dc power on delay
	* 1: Enable high pll bw switch at the start of the dc power on time overriding the profile info
	* 0:  Disable high pll bw switch at the start of the dc power on time and use only the profile info
	* Read/Write: RW
	* Bits: [1]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t HighPllbwToProfBwSeqStartSwitchEnable : 1;        /*## attribute HighPllbwToProfBwSeqStartSwitchEnable */
	/**
	* BitsName: high_pllbw_switch_enable_cw_mode
	* Description: Enable high pll bw switch feature overriding during the CW mode with the  profile_load_for_calib bit. Duration for   high pll bw switch feature overriding will be based on the 'high_pllbw_to_prof_bw_seq_start_switch_time' programmed. Also high pll bw switch feature overriding will be enable when the Chirp_AFC -> keep_middle_frequency_in_cw_mode bit toggles. Chirp start should be applied only after the high_pllbw_to_prof_bw_seq_start_switch_time once the high pll bw switch in cw mode is triggered either by keep_middle_frequency_in_cw_mode bt or by profile_load_for_calib bit
	* 1: Enable high pll bw switch during cw mode
	* 0:  Disable high pll bw switch during cw mode
	* Read/Write: RW
	* Bits: [2]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t HighPllbwSwitchEnableCwMode : 1;        /*## attribute HighPllbwSwitchEnableCwMode */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: high_pllbw_to_prof_bw_switch_time
	* Description: The time during which high pll bw is effective before switching to the profile info
	*
	* The counter is operating with 40MHz clock. The high pll bw is loaded at the start of the dwell/start of the chirp and after this counter expiry, the profile info is loaded, default delay value is 10 us.
	* Read/Write: RW
	* Bits: [12:4]
	* ResetValue: 0b110010000
	* Source: Application
	* FuSa: No
	*/
	uint32_t HighPllbwToProfBwSwitchTime : 9;        /*## attribute HighPllbwToProfBwSwitchTime */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: high_pllbw_to_prof_bw_seq_start_switch_time
	* Description: The time during which high pll bw is effective before switching to the profile info
	*
	* The counter is operating with 40MHz clock. The high pll bw is loaded at the start of the dc power on delay/start of the sequence and after this counter expiry, the profile info is loaded.
	* default delay value is 10 us
	* Read/Write: RW
	* Bits: [27:16]
	* ResetValue: 0b000110010000
	* Source: Application
	* FuSa: No
	*/
	uint32_t HighPllbwToProfBwSeqStartSwitchTime : 12;        /*## attribute HighPllbwToProfBwSeqStartSwitchTime */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 4;        /*## attribute Reserved2 */
}R2M06_HighPllbwSwitchControlBits_t;
/**
* R2M06_AdditionalHwSettingsBits_t
* RegisterName: ADDITIONAL_HW_SETTINGS
* Additional hardware settings
* Address: 0x298
* ResetValue: 0x00010000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctl_ibias_TS_100u_en
	* Description: Bias enable for the temperature sensor
	* 1: Enable bias of temp sensor
	* 0: Disable bias of temp sensor
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIbiasTs100UEn : 1;        /*## attribute CtlIbiasTs100UEn */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_ibias_speed_up
	* Description: This control bit from chirp_afc is used for closing the analog switch to fast bias the vco.
	*
	* 0 : Switch is open
	* 1 : Switch is closed
	*
	*
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIbiasSpeedUp : 1;        /*## attribute CtlIbiasSpeedUp */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_ibias_speed_up_mux_ctrl
	* Description: This field controls the final value of the ctl_ibias_speed_up
	*
	* 0 : ctl_ibias_speed_up is driven after a delay from digital statemachine
	* 1 : ctl_ibias_speed_up is driven directly  from local spi field
	*
	* In the Application context, this bit should be set to 0. In CW mode, 1 will be chosen to override the timing engine based functionality
	*
	*
	* In the chirping mode, the same functionality is controlled from timing engine through the register CHIRP_FAST_BIAS_SWITCH_CONTROL.
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIbiasSpeedUpMuxCtrl : 1;        /*## attribute CtlIbiasSpeedUpMuxCtrl */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: ld_polarity_from_sweep_control
	* Description: This bit controls the polarity of the lock detector based on the sweep control settings automatically.
	* 1: Sweep control module drives the polarity bit of the lock detector based on the chirp profile (active up/downchirp)
	* 0 (Reset Value):  The polarity of the lock detector is controlled by the bit in the ctl_ld_pol_spi bit in the register funcsafe_mon_unlock_vco
	*
	* Note: If this bit is set to '1', ctl_ld_pol_spi bit in the register funcsafe_mon_unlock_vco should be set to '0' to override the software based polarity setting
	*
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t LdPolarityFromSweepControl : 1;        /*## attribute LdPolarityFromSweepControl */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: enable_hard_func_reset_per_frame
	* Description: This bit controls the selection of the hardware functional reset based on the chirp fast switch.
	* 1: Enable hardware functional reset at every  every sequence start and release after the chirp_fast_bias_switch_delay timer (field in CHIRP_BIAS_SWITCH_CONTROL register in timing engine) expires (chirp_dynamic_power_control reg in timing engine).
	*
	* - In Normal/Powerdwn per sequence mode, this functional reset is asserted at the start of every sequence .
	* 0: Disable  hardware functional reset. No hardware functional reset will be issued.
	*
	* This bit should be enabled when the Chirp is powerdown per frame/sequence basis. Also enable Sweep_control -> SWEEP_DIV_RST_CONTROL -> sweep_div_rst_enable_frame bit along with this bit
	*
	* Chirp powerdown per sequence is considered as the default mode and the reset values are given accordingly
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t EnableHardFuncResetPerFrame : 1;        /*## attribute EnableHardFuncResetPerFrame */
	/**
	* BitsName: enable_hard_func_reset_per_chirp
	* Description: This bit controls the selection of the hardware functional reset based on the chirp fast switch.
	* 1: Enable hardware functional reset at every chirp dwell start and release after the chirp_fast_bias_switch_delay timer (field in CHIRP_BIAS_SWITCH_CONTROL register in timing engine) expires (chirp_dynamic_power_control reg in timing engine).
	*
	* - If Chirp is in per chirp powerdown and chirp_powermode bit is set, this functional reset is asserted at the start of every chirp and If Chirp is in per seq powerdown and chirp_powermode bit is set functional reset is asserted at the start of every sequence .
	*
	* 0: Disable  hardware functional reset. No hardware functional reset will be issued.
	*
	* This bit should be enabled when the Chirp is powerdown per chirp basis. Also enable Sweep_control -> SWEEP_DIV_RST_CONTROL -> sweep_div_rst_enable_frame bit along with this bit
	*
	* Chirp powerdown per sequence is considered as the default mode and the reset values need to be changed
	* Read/Write: RW
	* Bits: [17]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t EnableHardFuncResetPerChirp : 1;        /*## attribute EnableHardFuncResetPerChirp */
	/**
	* BitsName: Reserved_4
	* Description: not used
	*/
	uint32_t Reserved4 : 2;        /*## attribute Reserved4 */
	/**
	* BitsName: idac_polarity_from_sweep_control
	* Description: This bit controls the polarity of the dac injection current based on the sweep control settings automatically.
	* 1: Sweep control module drives the polarity bit of the dac injection is based on the chirp profile. The polarity is latched at the start of the chirp (at profile load). Based on active upchirp (polarity 0) or active downchirp (polarity 1), the polarity value is determined
	* 0 (Reset Value):  The polarity of the dac injection is controlled by the bit  pll_fr_idac_polarity in the register PLL_DAC_INJ_ACQ
	*
	* Note: If this bit is set to '1', pll_fr_idac_polarity bit in the register PLL_DAC_INJ_ACQ should be set to '0' to override the software based polarity setting
	*
	* Read/Write: RW
	* Bits: [20]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t IdacPolarityFromSweepControl : 1;        /*## attribute IdacPolarityFromSweepControl */
	/**
	* BitsName: Reserved_5
	* Description: not used
	*/
	uint32_t Reserved5 : 3;        /*## attribute Reserved5 */
	/**
	* BitsName: idac_polarity_from_sweep_control_invert
	* Description: This bit controls the polarity of the dac injection current based on the sweep control settings automatically.
	* 1: Invert the sweep control polarity latched at the chirp start (at profile_load point)
	* 0 (Reset Value):  Use the polarity latched from sweep control as is
	*
	* Note: This field is applicable only when idac_polarity_from_sweep_control is set to 1'b1
	*
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t IdacPolarityFromSweepControlInvert : 1;        /*## attribute IdacPolarityFromSweepControlInvert */
	/**
	* BitsName: Reserved_6
	* Description: not used
	*/
	uint32_t Reserved6 : 7;        /*## attribute Reserved6 */
}R2M06_AdditionalHwSettingsBits_t;
/**
* R2M06_ControlSpareBits_t
* RegisterName: CONTROL_SPARE
* DAC timing mode control and bits for future use
* Address: 0x29C
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 4;        /*## attribute Reserved1 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 1;        /*## attribute Reserved2 */
	/**
	* BitsName: ctl_ts_in_pd_en
	* Description: enable for temperature sensor readout during powerdown
	* Read/Write: RW
	* Bits: [7]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CtlTsInPdEn : 1;        /*## attribute CtlTsInPdEn */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 24;        /*## attribute Reserved3 */
}R2M06_ControlSpareBits_t;
/**
* R2M06_TsSettingsBits_t
* RegisterName: TS_SETTINGS
* Functional safety monitor related to vco temperature sensor settings
* Address: 0x2A0
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: ts_buf_chopper_spi
	* Description: Temperature sensor buffer chopper control
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t TsBufChopperSpi : 1;        /*## attribute TsBufChopperSpi */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: ts_swap_cur_dvbe
	* Description: Controls the dvbe current swapper of the temperature sensor core
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t TsSwapCurDvbe : 1;        /*## attribute TsSwapCurDvbe */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 27;        /*## attribute Reserved1 */
}R2M06_TsSettingsBits_t;
/**
* R2M06_RmsControlBits_t
* RegisterName: RMS_CONTROL
* Lo rms detector calibration settings
* Address: 0x2A4
* ResetValue: 0x10000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 6;        /*## attribute Reserved0 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 1;        /*## attribute Reserved2 */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: chirp_meas_in_out_spi
	* Description: Select input or output of power detector.
	* 0=input
	* 1=output.
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ChirpMeasInOutSpi : 1;        /*## attribute ChirpMeasInOutSpi */
	/**
	* BitsName: Reserved_4
	* Description: not used
	*/
	uint32_t Reserved4 : 3;        /*## attribute Reserved4 */
	/**
	* BitsName: Reserved_5
	* Description: not used
	*/
	uint32_t Reserved5 : 1;        /*## attribute Reserved5 */
	/**
	* BitsName: Reserved_6
	* Description: not used
	*/
	uint32_t Reserved6 : 3;        /*## attribute Reserved6 */
	/**
	* BitsName: Reserved_7
	* Description: not used
	*/
	uint32_t Reserved7 : 1;        /*## attribute Reserved7 */
	/**
	* BitsName: Reserved_8
	* Description: not used
	*/
	uint32_t Reserved8 : 3;        /*## attribute Reserved8 */
	/**
	* BitsName: chirp_rms_en_spi
	* Description: Enable the rms detector
	* 1: Enable rms detector
	* 0: Disable rms detector
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ChirpRmsEnSpi : 1;        /*## attribute ChirpRmsEnSpi */
	/**
	* BitsName: Reserved_9
	* Description: not used
	*/
	uint32_t Reserved9 : 3;        /*## attribute Reserved9 */
	/**
	* BitsName: chirp_sel_rms_spi
	* Description: The control used to select the rns detector for 1g vco or 4g vco or buffer
	* 000 = All coupler off
	* 001 = select rms dector 1G
	* 010 = select rms dector 4G (this control should not be used if 4g mode is disabled by otp)
	* 100 = select rms dector buffer
	* Others = Reserved
	*
	* Note:
	* a. If ctl_sel_vco_1g_5g_spi_profile* / ctl_sel_vco_1g_5g_spi = 0 (1g mode), chirp_sel_rms_spi =1 is selected always.
	* b. If ctl_sel_vco_1g_5g_spi_profile* / ctl_sel_vco_1g_5g_spi is not equal to 0, the value programmed in this field passed directly
	* Read/Write: RW
	* Bits: [30:28]
	* ResetValue: 0b001
	* Source: Application
	* FuSa: No
	*/
	uint32_t ChirpSelRmsSpi : 3;        /*## attribute ChirpSelRmsSpi */
	/**
	* BitsName: Reserved_10
	* Description: not used
	*/
	uint32_t Reserved10 : 1;        /*## attribute Reserved10 */
}R2M06_RmsControlBits_t;
/**
* R2M06_RefCntrInitBits_t
* RegisterName: REF_CNTR_INIT
* Reference count value for 480Mhz frequency measurement
* Address: 0x2B0
* ResetValue: 0x01E00028
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: ref_count_value
	* Description: value for the reference count time (40 MHz= 25 ns base time) default is d'40. This is used as reference count in both spi triggered mode and window_active triggered mode
	* Read/Write: RW
	* Bits: [15:0]
	* ResetValue: 0b0000000000101000
	* Source: Application
	* FuSa: Y
	*/
	uint32_t RefCountValue : 16;        /*## attribute RefCountValue */
	/**
	* BitsName: ideal_480_count_value
	* Description: This is applicable when the freq counter trigger is based on window_active (for func safety). The correct value to be programmed which is compared against the freq counter read value in the hardware. The value is restricted to 16 bits (as against 18 bit in the freq read counter value) as this triggered one time during active period of the window active and the bit width is sufficient to cover the frequency counting considering the variation of the chirp period
	* Read/Write: RW
	* Bits: [31:16]
	* ResetValue: 0b0000000111100000
	* Source: Application
	* FuSa: Y
	*/
	uint32_t Ideal480CountValue : 16;        /*## attribute Ideal480CountValue */
}R2M06_RefCntrInitBits_t;
/**
* R2M06_FreqCounterStartBits_t
* RegisterName: FREQ_COUNTER_START
* 480Mhz frequency measurement trigger
* Address: 0x2B4
* ResetValue: 0x00000130
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: freq_start
	* Description: Start the freq. count
	* 0 = idle
	* 1 = start
	*
	* Read/Write: W
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t FreqStart : 1;        /*## attribute FreqStart */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: num_lsbbits_ignored
	* Description: Number of lsb bits to be ignored while comparing the final freq counter read value. This is required incase of frequency counter trigger is based on window_active  for functional safety. The hardware then compares the value measured by frequency counter against ideal_480_count_value ignoring the lsb bits.
	* 0001: Zeroth bit is ignored from comparison
	* 0011: Zeroth & first bits are ignored from comparison
	* 0111: Zeroth & first & second bits are ignored from comparison
	* 1111: Zeroth & first & second & third bits are ignored from comparison
	*
	* Read/Write: RW
	* Bits: [7:4]
	* ResetValue: 0b0011
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t NumLsbbitsIgnored : 4;        /*## attribute NumLsbbitsIgnored */
	/**
	* BitsName: enable_func_safety_freq_mea
	* Description: By default, the frequency counter is triggered based on safety_monitor_active posedge to measure the frequency deviation if any and to report to the ISM for every chirp. If this bit is disabled, then the bit 0 of this register is required to be written to trigger the frequency counter
	* 1: trigger is based on safety_monitor_active
	* 0: Trigger is based on the spi write on bit 0 i.e freq_start
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t EnableFuncSafetyFreqMea : 1;        /*## attribute EnableFuncSafetyFreqMea */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 23;        /*## attribute Reserved1 */
}R2M06_FreqCounterStartBits_t;
/**
* R2M06_FreqCounterReadValueBits_t
* RegisterName: FREQ_COUNTER_READ_VALUE
* Actual frequency measurement value
* Address: 0x2B8
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: freq_count_value
	* Description: Freq value computed. Actual value need to be assessed based on  the ref_cntr_init value
	* e.g ref_cntr_int = d'40 then freq value = freq count value in MHz
	* e.g ref_cntr_int = d'400 (40*10) then freq value = freq count value/10 ) in MHz
	*
	*
	* Read/Write: R
	* Bits: [17:0]
	* ResetValue: 0b000000000000000000
	* Source: Application
	* FuSa: Y
	*/
	uint32_t FreqCountValue : 18;        /*## attribute FreqCountValue */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
	/**
	* BitsName: done_flag
	* Description: Indicates that a freq count value is valid. Write to freq counter start clear this bit
	* Read/Write: R
	* Bits: [20]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t DoneFlag : 1;        /*## attribute DoneFlag */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 10;        /*## attribute Reserved1 */
	/**
	* BitsName: xor_parity_freq_counter
	* Description: This is simple xor of all the bits in the frequency counter read value. This bit can be used by MCU to check against stuckat fault error
	* 1: Odd parity (Number of ones in the register value is odd)
	* 0: Even parity (Number of ones in the register value is even)
	* Read/Write: R
	* Bits: [31]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t XorParityFreqCounter : 1;        /*## attribute XorParityFreqCounter */
}R2M06_FreqCounterReadValueBits_t;
/**
* R2M06_RefCounterReadValueBits_t
* RegisterName: REF_COUNTER_READ_VALUE
* Reference count value
* Address: 0x2BC
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: counter_read_value
	* Description: Reference count value
	* Read/Write: R
	* Bits: [15:0]
	* ResetValue: 0b0000000000000000
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t CounterReadValue : 16;        /*## attribute CounterReadValue */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 16;        /*## attribute Reserved0 */
}R2M06_RefCounterReadValueBits_t;
/**
* R2M06_LoopFilterCounterInitBits_t
* RegisterName: LOOP_FILTER_COUNTER_INIT
* Loop filter settings
* Address: 0x2C0
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: reset_counter
	* Description: 1: Reset the counter to '0', and clear the overflow, done flag.
	*   a. Actually the real start for the counter is based on the internally generated start pulse when too_low signal toggling from 1 to 0. The counter stop condition is generated based on too_high toggling from 0 to 1. This is with polarity bit (bit20 in the same register) set to 0
	* b. Actually the real start for the counter is based on the internally generated start pulse when too_high signal toggling from 1 to 0. The counter stop condition is generated based on too_low toggling from 0 to 1. This is with polarity bit (bit20 in the same register) set to 1
	*
	*
	*
	* 0: Retain the prev value. Still the counter starts based on the conditions described but the values reflected with the previous counter value in consideration
	* Read/Write: W
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ResetCounter : 1;        /*## attribute ResetCounter */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 7;        /*## attribute Reserved0 */
	/**
	* BitsName: override_reset_counter
	* Description: If this bit is set, the flag is cleared on every start condition which is generated internally based on too_low. This is to provide the user a flexibility of continuous monitoring of the counter without a need to reset manually (assumption: the counter operates on defined intervals i.e too_low and too_high conidtion happens in defined intervals)
	* 1: override reset counter by auto clear
	* 0: Manually reset_counter to be cleared by writing to bit 0 of this register
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t OverrideResetCounter : 1;        /*## attribute OverrideResetCounter */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 7;        /*## attribute Reserved1 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 1;        /*## attribute Reserved2 */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: loop_filter_polarity
	* Description: The field controls the polarity and thereby counter start condition. Please refer reset_counter description
	*
	* 0: Positive polarity
	* 1 : Negative polarity
	* Read/Write: RW
	* Bits: [20]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LoopFilterPolarity : 1;        /*## attribute LoopFilterPolarity */
	/**
	* BitsName: Reserved_4
	* Description: not used
	*/
	uint32_t Reserved4 : 11;        /*## attribute Reserved4 */
}R2M06_LoopFilterCounterInitBits_t;
/**
* R2M06_LoopFilterCounterReadValueBits_t
* RegisterName: LOOP_FILTER_COUNTER_READ_VALUE
* Loop filter counter status
* Address: 0x2C4
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: loop_filter_counter_value
	* Description: Counter value read. Actual value need to be assessed based on  the frequency programmed (clk_ref)
	*
	*
	* Read/Write: R
	* Bits: [17:0]
	* ResetValue: 0b000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LoopFilterCounterValue : 18;        /*## attribute LoopFilterCounterValue */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
	/**
	* BitsName: loop_filter_counter_done_flag
	* Description: Indicates that count value is valid. Gets cleared when reset_counter value is written as '1'
	* 1: Done flag is set
	* 0: Done flag not set
	* Read/Write: R
	* Bits: [20]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LoopFilterCounterDoneFlag : 1;        /*## attribute LoopFilterCounterDoneFlag */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 1;        /*## attribute Reserved2 */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 6;        /*## attribute Reserved3 */
	/**
	* BitsName: Reserved_4
	* Description: not used
	*/
	uint32_t Reserved4 : 1;        /*## attribute Reserved4 */
}R2M06_LoopFilterCounterReadValueBits_t;
/**
* R2M06_DivideFreqCounterStartBits_t
* RegisterName: DIVIDE_FREQ_COUNTER_START
* Trigger for divider output frequency measurement
* Address: 0x2D0
* ResetValue: 0x00000100
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: divide_freq_start
	* Description: Start the freq. count
	* 0 = idle, 1 = start
	*
	* Read/Write: W
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t DivideFreqStart : 1;        /*## attribute DivideFreqStart */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 4;        /*## attribute Reserved1 */
	/**
	* BitsName: enable_func_safety_divide_freq_mea
	* Description: By default, the frequency counter is triggered based on safety_monitor_active posedge to measure the frequency deviation if any and to report to the ISM for every chirp. If this bit is disabled, then the bit 0 of this register is required to be written to trigger the frequency counter
	* 1: Trigger based on the safety_monitor_active signal
	* 0: Trigger based on the spi write of bit 0 of this reqister i.e freq_start
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t EnableFuncSafetyDivideFreqMea : 1;        /*## attribute EnableFuncSafetyDivideFreqMea */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 23;        /*## attribute Reserved2 */
}R2M06_DivideFreqCounterStartBits_t;
/**
* R2M06_DivideFreqCounterReadValueBits_t
* RegisterName: DIVIDE_FREQ_COUNTER_READ_VALUE
* Divider output frequency measured value
* Address: 0x2D4
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: divide_freq_count_value
	* Description: Based on the divider value (in the sweep control Div_update_rf_profile* field), the following ref_cntr_init value is fixed in the hardware/design.
	*
	*   240_REF_CNTR_INIT_VALUE = 18'h000F0; div by 2
	*   160_ REF_CNTR_INIT_VALUE = 18'h000A0; div by 3
	*   120_ REF_CNTR_INIT_VALUE = 18'h00078; div by 4
	*   96_ REF_CNTR_INIT_VALUE = 18'h00060;  div by 5
	*   80_ REF_CNTR_INIT_VALUE = 18'h00050; div by 6
	* Note: Still the deviations bits are programmable in in the sweep control freq_deviation_bits_profile* field)
	* Read/Write: R
	* Bits: [17:0]
	* ResetValue: 0b000000000000000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t DivideFreqCountValue : 18;        /*## attribute DivideFreqCountValue */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
	/**
	* BitsName: divide_freq_done_flag
	* Description: Indicates that a freq count value is valid. Write to freq counter start clear this bit
	* 1: counting done
	* 0: couting not done yet
	* Read/Write: R
	* Bits: [20]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t DivideFreqDoneFlag : 1;        /*## attribute DivideFreqDoneFlag */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 10;        /*## attribute Reserved1 */
	/**
	* BitsName: xor_parity_divide_freq_counter
	* Description: This is simple xor of all the bits in the frequency counter read value. This bit can be used by MCU to check against stuckat fault error
	* 1: Odd parity (Number of ones in the register value is odd)
	* 0: Even parity (Number of ones in the register value is even)
	* Read/Write: R
	* Bits: [31]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t XorParityDivideFreqCounter : 1;        /*## attribute XorParityDivideFreqCounter */
}R2M06_DivideFreqCounterReadValueBits_t;
/**
* R2M06_KvcoDvdtConfigControlBits_t
* RegisterName: KVCO_DVDT_CONFIG_CONTROL
* KVCO & DVDT Configuration register
* Address: 0x2DC
* ResetValue: 0x0C6F0011
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctl_lpf_prog_force_voltage_low_spi
	* Description: low voltage forced during kvco_avg measurements
	* Read/Write: RW
	* Bits: [6:0]
	* ResetValue: 0b0010001
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlLpfProgForceVoltageLowSpi : 7;        /*## attribute CtlLpfProgForceVoltageLowSpi */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 9;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_lpf_prog_force_voltage_high_spi
	* Description: high voltage forced during kvco_avg measurements
	* Read/Write: RW
	* Bits: [22:16]
	* ResetValue: 0b1101111
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlLpfProgForceVoltageHighSpi : 7;        /*## attribute CtlLpfProgForceVoltageHighSpi */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_lpf_prog_force_voltage_dvdt_spi
	* Description:  voltage forced during dvdt measurements
	* Read/Write: RW
	* Bits: [30:24]
	* ResetValue: 0b0001100
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlLpfProgForceVoltageDvdtSpi : 7;        /*## attribute CtlLpfProgForceVoltageDvdtSpi */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 1;        /*## attribute Reserved2 */
}R2M06_KvcoDvdtConfigControlBits_t;
/**
* R2M06_KvcoDvdtDelayControlBits_t
* RegisterName: KVCO_DVDT_DELAY_CONTROL
* Delay configuration for both kvco nd dvdt mesaurements
* Address: 0x2E0
* ResetValue: 0x32032028
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: kvco_settling_delay
	* Description: kvco setting time before dvdt measurement starts
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00101000
	* Source: Application
	* FuSa: No
	*/
	uint32_t KvcoSettlingDelay : 8;        /*## attribute KvcoSettlingDelay */
	/**
	* BitsName: ref_cntr_init_kvco
	* Description: the reference counter value used for kvco
	* Read/Write: RW
	* Bits: [19:8]
	* ResetValue: 0b001100100000
	* Source: Application
	* FuSa: No
	*/
	uint32_t RefCntrInitKvco : 12;        /*## attribute RefCntrInitKvco */
	/**
	* BitsName: vtune_force_time_dvdt
	* Description: Time for which vtune is forced during dvdt
	* Read/Write: RW
	* Bits: [31:20]
	* ResetValue: 0b001100100000
	* Source: Application
	* FuSa: No
	*/
	uint32_t VtuneForceTimeDvdt : 12;        /*## attribute VtuneForceTimeDvdt */
}R2M06_KvcoDvdtDelayControlBits_t;
/**
* R2M06_KvcoCountStatusBits_t
* RegisterName: KVCO_COUNT_STATUS
* kvco frequency count read value
* Address: 0x2E4
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: cnt_low_kvco_avg_onfly
	* Description: frequency count value when the ctl_lpf_prog_force_voltage_low_spi    is set
	* Read/Write: R
	* Bits: [15:0]
	* ResetValue: 0b0000000000000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CntLowKvcoAvgOnfly : 16;        /*## attribute CntLowKvcoAvgOnfly */
	/**
	* BitsName: cnt_high_kvco_avg_onfly
	* Description: frequency count value when the ctl_lpf_prog_force_voltage_lhigh_spi    is set
	* Read/Write: R
	* Bits: [31:16]
	* ResetValue: 0b0000000000000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CntHighKvcoAvgOnfly : 16;        /*## attribute CntHighKvcoAvgOnfly */
}R2M06_KvcoCountStatusBits_t;
/**
* R2M06_AafcLockDvdtCountStatusBits_t
* RegisterName: AAFC_LOCK_DVDT_COUNT_STATUS
* dvdt frequency count read value and aafc lock and error status
* Address: 0x2E8
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: dvdt_cnt_c1_onfly
	* Description: frequency count value to calculate the chirp slope (dvdt) when the ctl_lpf_prog_force_voltage_ldvdt_spi    is set
	* Read/Write: R
	* Bits: [11:0]
	* ResetValue: 0b000000000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t DvdtCntC1Onfly : 12;        /*## attribute DvdtCntC1Onfly */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
	/**
	* BitsName: done_flag_kvco
	* Description: error status for kvco
	* 1 - count done
	* 0 - count error
	* Read/Write: R
	* Bits: [14]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t DoneFlagKvco : 1;        /*## attribute DoneFlagKvco */
	/**
	* BitsName: done_flag_dvdt
	* Description: error status for dvdt
	* 1 -  count done
	* 0 - count error
	* Read/Write: R
	* Bits: [15]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t DoneFlagDvdt : 1;        /*## attribute DoneFlagDvdt */
	/**
	* BitsName: aafc_lock
	* Description: lock status for afc or aac
	* 1 - lock
	* 0 - No lock
	* Read/Write: R
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t AafcLock : 1;        /*## attribute AafcLock */
	/**
	* BitsName: aac_lock
	* Description: lock status for aac
	* 1 - lock
	* 0 - No lock
	* Read/Write: R
	* Bits: [17]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t AacLock : 1;        /*## attribute AacLock */
	/**
	* BitsName: afc_lock
	* Description: lock status for afc
	* 1 - lock
	* 0 - No lock
	* Read/Write: R
	* Bits: [18]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t AfcLock : 1;        /*## attribute AfcLock */
	/**
	* BitsName: aafc_error
	* Description: error status for afc or aac
	* 1 - error
	* 0 - No error
	* Read/Write: R
	* Bits: [19]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t AafcError : 1;        /*## attribute AafcError */
	/**
	* BitsName: aac_error
	* Description: error status for aac
	* 1 - error
	* 0 - No error
	* Read/Write: R
	* Bits: [20]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t AacError : 1;        /*## attribute AacError */
	/**
	* BitsName: afc_error
	* Description: error status for afc
	* 1 - error
	* 0 - No error
	* Read/Write: R
	* Bits: [21]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t AfcError : 1;        /*## attribute AfcError */
	/**
	* BitsName: kvco_dvdt_error
	* Description: error status for kvco or dvdt
	* 1 - error
	* 0 - No error
	* Read/Write: R
	* Bits: [22]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t KvcoDvdtError : 1;        /*## attribute KvcoDvdtError */
	/**
	* BitsName: aafc_kvco_dvdt_busy
	* Description: busy status for aafc, kvco and dvdt
	* 1 - busy
	* 0- not busy
	* Read/Write: R
	* Bits: [23]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t AafcKvcoDvdtBusy : 1;        /*## attribute AafcKvcoDvdtBusy */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 8;        /*## attribute Reserved1 */
}R2M06_AafcLockDvdtCountStatusBits_t;
/**
* R2M06_ChirpCalibrationStatusBits_t
* RegisterName: CHIRP_CALIBRATION_STATUS
* Calibration status2
* Address: 0x310
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: afc_fsel_out
	* Description: vco coarse frequency tuning (subband number)
	* Read/Write: R
	* Bits: [6:0]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t AfcFselOut : 7;        /*## attribute AfcFselOut */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: afc_m
	* Description: frequency loop actual Mvalue
	* Read/Write: R
	* Bits: [19:8]
	* ResetValue: 0b000000000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t AfcM : 12;        /*## attribute AfcM */
	/**
	* BitsName: aac_ireg_ctrl
	* Description: VCO current value (ivco_fine)
	* Read/Write: R
	* Bits: [25:20]
	* ResetValue: 0b000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t AacIregCtrl : 6;        /*## attribute AacIregCtrl */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 6;        /*## attribute Reserved1 */
}R2M06_ChirpCalibrationStatusBits_t;
/**
* R2M06_ChirpCalibrationSwControlBits_t
* RegisterName: CHIRP_CALIBRATION_SW_CONTROL
* AAFC calibration setting in the manual mode. These settings are applicable only in the non-chirping mode for debug purpose and CW mode
* Address: 0x3A0
* ResetValue: 0x01001030
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: start_chirp_calibration
	* Description: start calibration by manual trigger
	*
	* 0 : No operation
	* 1 : Start AAFC calibration
	* Read/Write: W
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t StartChirpCalibration : 1;        /*## attribute StartChirpCalibration */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: kvco_dvdt_enable
	* Description: Enable for bothe kvco and dvdt measureemnts
	* 00 - Both are disabled
	* 01 - KVCO enabled
	* 10 - DVDT enabled
	* 11 - Both are enabled
	* Read/Write: RW
	* Bits: [5:4]
	* ResetValue: 0b11
	* Source: Reset
	* FuSa: No
	*/
	uint32_t KvcoDvdtEnable : 2;        /*## attribute KvcoDvdtEnable */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: use_profile_for_calibration
	* Description: profile number that will be used for CW (non-chirping) mode calibration
	* Read/Write: RW
	* Bits: [11:8]
	* ResetValue: 0b0000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t UseProfileForCalibration : 4;        /*## attribute UseProfileForCalibration */
	/**
	* BitsName: store_in_profile0
	* Description: calibration , kvco & dvdt results to be stored in profile 0 registers
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t StoreInProfile0 : 1;        /*## attribute StoreInProfile0 */
	/**
	* BitsName: store_in_profile1
	* Description: calibration , kvco & dvdt results to be stored in profile 1 registers
	* Read/Write: RW
	* Bits: [13]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t StoreInProfile1 : 1;        /*## attribute StoreInProfile1 */
	/**
	* BitsName: store_in_profile2
	* Description: calibration , kvco & dvdt results to be stored in profile 2 registers
	* Read/Write: RW
	* Bits: [14]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t StoreInProfile2 : 1;        /*## attribute StoreInProfile2 */
	/**
	* BitsName: store_in_profile3
	* Description: calibration , kvco & dvdt results to be stored in profile 3 registers
	* Read/Write: RW
	* Bits: [15]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t StoreInProfile3 : 1;        /*## attribute StoreInProfile3 */
	/**
	* BitsName: store_in_profile4
	* Description: calibration , kvco & dvdt results to be stored in profile 4 registers
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t StoreInProfile4 : 1;        /*## attribute StoreInProfile4 */
	/**
	* BitsName: store_in_profile5
	* Description: calibration , kvco & dvdt results to be stored in profile 5 registers
	* Read/Write: RW
	* Bits: [17]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t StoreInProfile5 : 1;        /*## attribute StoreInProfile5 */
	/**
	* BitsName: store_in_profile6
	* Description: calibration , kvco & dvdt results to be stored in profile 6 registers
	* Read/Write: RW
	* Bits: [18]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t StoreInProfile6 : 1;        /*## attribute StoreInProfile6 */
	/**
	* BitsName: store_in_profile7
	* Description: calibration , kvco & dvdtresults to be stored in profile 7 registers
	* Read/Write: RW
	* Bits: [19]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t StoreInProfile7 : 1;        /*## attribute StoreInProfile7 */
	/**
	* BitsName: store_in_profile8
	* Description: calibration , kvco & dvdt results to be stored in profile 8 registers
	* Read/Write: RW
	* Bits: [20]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t StoreInProfile8 : 1;        /*## attribute StoreInProfile8 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: en_profile_for_calibration
	* Description: profile enable bit for CW (non-chirping) mode calibration
	* Note:
	* timing_engine -> CHIRP_GLOBAL_CONTROL -> chirp_enable is used for loading the profile during the chirping mode
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t EnProfileForCalibration : 1;        /*## attribute EnProfileForCalibration */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: profile_load_for_calibration
	* Description: Software based profile load for loading the profile information in Chirp TX and RX for Calibration. If en_profile_for_calibration bit is 1, use_profile_for_caibration is selected in the profile sequencer to generate the active profile value. This is an auto clear bit. once it is triggered the use_profile_for_calibration  will be active till the chirp start
	* Read/Write: W
	* Bits: [28]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ProfileLoadForCalibration : 1;        /*## attribute ProfileLoadForCalibration */
	/**
	* BitsName: Reserved_4
	* Description: not used
	*/
	uint32_t Reserved4 : 3;        /*## attribute Reserved4 */
}R2M06_ChirpCalibrationSwControlBits_t;
/**
* R2M06_ChirpCalibrationTimeoutDelayBits_t
* RegisterName: CHIRP_CALIBRATION_TIMEOUT_DELAY
* AAFC calibration setting in the manual mode. These settings are applicable only in the non-chirping mode for debug purpose and CW mode
* Address: 0x3A4
* ResetValue: 0x00001F40
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: chirp_aafc_calibration_timeout_counter
	* Description: The timeout counter is used only when the chirp is in cw mode and chirp aafc calibration is triggered. If the calibration fails, the safety flag is asserted towards ISM
	* Read/Write: RW
	* Bits: [13:0]
	* ResetValue: 0b01111101000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ChirpAafcCalibrationTimeoutCounter : 14;        /*## attribute ChirpAafcCalibrationTimeoutCounter */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 10;        /*## attribute Reserved0 */
	/**
	* BitsName: abort_chirp_calibration
	* Description: Abort the AAFC calibration
	*
	* 0 : No operation
	* 1 : Abort the calibration. This bit is auto cleared
	* Read/Write: W
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t AbortChirpCalibration : 1;        /*## attribute AbortChirpCalibration */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 7;        /*## attribute Reserved1 */
}R2M06_ChirpCalibrationTimeoutDelayBits_t;
/**
* R2M06_Atb1Bits_t
* RegisterName: ATB1
* ATB1 bus settings.
* Address: 0xC04
* ResetValue: 0x000000FF
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: atb1_set
	* Description: 8'h01 :  level_vco_min (Functional Safety VCO amplitude monitor min threshold)
	* 8'h02:   level_vco_low (Functional Safety VCO amplitude monitor low threshold)
	* 8'h03:   level_vco_high(Functional Safety VCO amplitude monitor high threshold)
	* 8'h04:   level_vco_max(Functional Safety VCO amplitude monitor max threshold)
	* 8'h05:   rms_det_ref(RMS detector reference voltage)
	* 8'h06:   rms_det (RMS detector output voltage)
	* 8'h07:   temp_sns_buffer(Temperature sensor buffer output)
	* 8'h08:   temp_sns_comp(Functional Safety Temperature Monitor comparator input (unbuffered temperature sensor output))
	* 8'h09:   vco_ibias (Reference currents for  enabled by ctl_vco_pbusp_i100u_test_en)
	* 8'h0A:  vco_ind_cnt_tap_1g  (1g VCO center voltage)
	* 8'h0B:  vco_ind_cnt_tap_5g (5g VCO center voltage)
	* 8'h0C:   vtune_level_high (Functional Safety VCO tuning voltage monitor high threshold can be tuned by ctl_vtune_vco_high_spi)
	* 8'h0D:   vtune_level_low (Functional Safety VCO tuning voltage monitorlow threshold. can be tuned by ctl_vtune_vco_low_spi)
	* 8'h0E:   ldo_divider_vdd (Analog divider 1.1V supply: Locally divided 3/11 (300mV typ); can be tuned by ctl_ldo_divider_sel_vout_spi)
	* 8'h0F:   ldo_cppfd_vdd (Analog Charge Pump/Phase Detector 1.1V supply:Locally divided 3/11 (300mV typ); can be tuned by ctl_ldo_cppfd_sel_vout_spi)
	* 8'h10:   ldo_vco_vdd (Analog VCO 1.1V supply: Locally divided 3/11 ( 300mV typ); can be tuned by ctl_ldo_vco_sel_vout_spi)
	* 8'h11:   vdd_pll_1v8 (PLL analog 1.8V supply; Locally divided 1/6 (300mV typ))
	* 8'h12:   vdd_vco_1v8 (VCO analog 1.8V supply; Loacally divided 1/6 ( 300mV typ))
	* 8'h13:   ibias_cp_150u (Charge Pump current;: 150uA (typ); locally I/V converted trim-able resistor (4k); )
	* 8'h14:   ibias_ref_100u (BG Reference current;:100uA (typ); locally I/V converted trim-able resistor (4k); )
	* 8'h15:   vdd_pll_1v1 (Analog PLL 1.1V supply: Locally divided 3/11 (300mV typ))
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b11111111
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Atb1Set : 8;        /*## attribute Atb1Set */
	/**
	* BitsName: atb1_en
	* Description: Enable DC Test Bus
	* 1: Enable testbus
	* 0: Disable testbus
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Atb1En : 1;        /*## attribute Atb1En */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 23;        /*## attribute Reserved0 */
}R2M06_Atb1Bits_t;
/**
* R2M06_DftIdacControlBits_t
* RegisterName: DFT_IDAC_CONTROL
* Kept for future use
* Address: 0xC08
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 1;        /*## attribute Reserved2 */
	/**
	* BitsName: ctl_idac_trim_en_spi
	* Description: IDAC Trim Enable bit
	* Read/Write: RW
	* Bits: [3]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CtlIdacTrimEnSpi : 1;        /*## attribute CtlIdacTrimEnSpi */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 28;        /*## attribute Reserved3 */
}R2M06_DftIdacControlBits_t;
/**
* R2M06_MaskCcResetErrorBits_t
* RegisterName: MASK_CC_RESET_ERROR
* This register is kept for validation and not to be used in the functional context. This register is used to mask the reset errors
* Address: 0xE04
* ResetValue: 0x00E00000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: mask_level_reset_error
	* Description: If set to '1', masks the reset_error generated by the central control towards the sensor.
	* 1:  mask level reset error
	* 0:  do not mask level reset error
	*
	* Note: There is only one level_reset_error towards analog.
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskLevelResetError : 1;        /*## attribute MaskLevelResetError */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: mask_vtune_reset_error
	* Description: If set to '1', masks the reset_error generated by the central control towards the sensor.
	* 1:  mask vtune reset error
	* 0:  do not mask vtune reset error
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskVtuneResetError : 1;        /*## attribute MaskVtuneResetError */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: mask_unlock_reset_error
	* Description: If set to '1', masks the reset_error generated by the central control towards the sensor.
	* 1:  mask unlock reset error
	* 0:  do not mask unlock reset error
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskUnlockResetError : 1;        /*## attribute MaskUnlockResetError */
	/**
	* BitsName: mask_aafc_reset_error
	* Description: If set to '1', masks the reset_error generated by the central control towards the sensor.
	* 1:  mask aafc reset error
	* 0:  do not mask aafc reset error
	* Read/Write: RW
	* Bits: [9]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskAafcResetError : 1;        /*## attribute MaskAafcResetError */
	/**
	* BitsName: mask_aafc_cal_timeout_reset_error
	* Description: If set to '1', masks the reset_error generated by the central control towards the sensor.
	* 1:  mask aafc cal timeout reset error
	* 0:  do not mask aafc cal timeout reset error
	* Read/Write: RW
	* Bits: [10]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskAafcCalTimeoutResetError : 1;        /*## attribute MaskAafcCalTimeoutResetError */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 1;        /*## attribute Reserved2 */
	/**
	* BitsName: mask_supply_vco_reset_error
	* Description: If set to '1', masks the reset_error generated by the central control towards the sensor.
	* 1:  mask vco supply reset error
	* 0:  do not mask vco supply reset error
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskSupplyVcoResetError : 1;        /*## attribute MaskSupplyVcoResetError */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: mask_supply_pll_reset_error
	* Description: If set to '1', masks the reset_error generated by the central control towards the sensor.
	* 1:  mask pll supply reset error
	* 0:  do not mask pll supply reset error
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskSupplyPllResetError : 1;        /*## attribute MaskSupplyPllResetError */
	/**
	* BitsName: Reserved_4
	* Description: not used
	*/
	uint32_t Reserved4 : 3;        /*## attribute Reserved4 */
	/**
	* BitsName: mask_max_temp_reset_error
	* Description: If set to '1', masks the reset_error generated by the central control towards the sensor
	* 1:  mask temp reset error
	* 0:  do not mask temp reset error
	* Read/Write: RW
	* Bits: [20]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskMaxTempResetError : 1;        /*## attribute MaskMaxTempResetError */
	/**
	* BitsName: mask_te_reg_crc_reset_error
	* Description: If set to '1', masks the reset_error generated by the central control towards the sensor
	* 1:  mask crc reset error at timing engine
	* 0:  do not mask crc reset error
	* Read/Write: RW
	* Bits: [21]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskTeRegCrcResetError : 1;        /*## attribute MaskTeRegCrcResetError */
	/**
	* BitsName: mask_sc_reg_crc_reset_error
	* Description: If set to '1', masks the reset_error generated by the central control towards the sensor
	* 1:  mask crc reset error  at sweep control
	* 0:  do not mask crc reset error
	* Read/Write: RW
	* Bits: [22]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskScRegCrcResetError : 1;        /*## attribute MaskScRegCrcResetError */
	/**
	* BitsName: mask_afc_reg_crc_reset_error
	* Description: If set to '1', masks the reset_error generated by the central control towards the sensor
	* 1:  mask crc reset error  at chirp_afc
	* 0:  do not mask crc reset error
	* Read/Write: RW
	* Bits: [23]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskAfcRegCrcResetError : 1;        /*## attribute MaskAfcRegCrcResetError */
	/**
	* BitsName: mask_combined_stuckat_transient_reset_error
	* Description: If set to '1', masks the force_error generated by the central control towards the sensor
	* 1:  mask stuckat/transient combined reset error
	* 0:  do not mask stuckat/transient reset error
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskCombinedStuckatTransientResetError : 1;        /*## attribute MaskCombinedStuckatTransientResetError */
	/**
	* BitsName: mask_te_stuckat_transient_reset_error
	* Description: If set to '1', masks the reset_error generated by the central control towards the sensor
	* 1:  mask stuckat/transient reset error at timing engine
	* 0:  do not mask stuckat/transient reset error
	* Read/Write: RW
	* Bits: [25]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskTeStuckatTransientResetError : 1;        /*## attribute MaskTeStuckatTransientResetError */
	/**
	* BitsName: mask_sc_stuckat_transient_reset_error
	* Description: If set to '1', masks the force_error generated by the central control towards the sensor
	* 1:  mask stuckat/transient reset error at sweep control
	* 0:  do not mask stuckat/transient reset error
	* Read/Write: RW
	* Bits: [26]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskScStuckatTransientResetError : 1;        /*## attribute MaskScStuckatTransientResetError */
	/**
	* BitsName: mask_afc_stuckat_transient_reset_error
	* Description: If set to '1', masks the reset_error generated by the central control towards the sensor
	* 1:  mask stuckat/transient reset error at chirp_afc
	* 0:  do not mask stuckat/transient  reset error
	* Read/Write: RW
	* Bits: [27]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskAfcStuckatTransientResetError : 1;        /*## attribute MaskAfcStuckatTransientResetError */
	/**
	* BitsName: mask_supply_dig_reset_error
	* Description: If set to '1', masks the reset_error generated by the central control towards the sensor
	* 1:  mask digital supply reset error
	* 0:  do not mask vco supply reset error
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskSupplyDigResetError : 1;        /*## attribute MaskSupplyDigResetError */
	/**
	* BitsName: Reserved_5
	* Description: not used
	*/
	uint32_t Reserved5 : 1;        /*## attribute Reserved5 */
	/**
	* BitsName: mask_divide_freq_reset_error
	* Description: mask sweep control divide freq reset error
	* 1:  mask sweep control divide freq reset error
	* 0:  do not mask sweep control divide freq reset error
	*
	* Read/Write: RW
	* Bits: [30]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskDivideFreqResetError : 1;        /*## attribute MaskDivideFreqResetError */
	/**
	* BitsName: mask_vco_freq_480_reset_error
	* Description: mask vco 480 freq reset error
	* 1:  mask vco supply reset error
	* 0:  do not mask vco supply reset error
	* Read/Write: RW
	* Bits: [31]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskVcoFreq480ResetError : 1;        /*## attribute MaskVcoFreq480ResetError */
}R2M06_MaskCcResetErrorBits_t;
/**
* R2M06_MaskCcErrorFlagBits_t
* RegisterName: MASK_CC_ERROR_FLAG
* This register is kept for validation and not to be used in the functional context. This register is used to mask the flags from the sensor going to the central control
* Address: 0xE08
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 1;        /*## attribute Reserved2 */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 1;        /*## attribute Reserved3 */
	/**
	* BitsName: Reserved_4
	* Description: not used
	*/
	uint32_t Reserved4 : 1;        /*## attribute Reserved4 */
	/**
	* BitsName: Reserved_5
	* Description: not used
	*/
	uint32_t Reserved5 : 3;        /*## attribute Reserved5 */
	/**
	* BitsName: Reserved_6
	* Description: not used
	*/
	uint32_t Reserved6 : 1;        /*## attribute Reserved6 */
	/**
	* BitsName: Reserved_7
	* Description: not used
	*/
	uint32_t Reserved7 : 1;        /*## attribute Reserved7 */
	/**
	* BitsName: Reserved_8
	* Description: not used
	*/
	uint32_t Reserved8 : 1;        /*## attribute Reserved8 */
	/**
	* BitsName: Reserved_9
	* Description: not used
	*/
	uint32_t Reserved9 : 1;        /*## attribute Reserved9 */
	/**
	* BitsName: Reserved_10
	* Description: not used
	*/
	uint32_t Reserved10 : 1;        /*## attribute Reserved10 */
	/**
	* BitsName: Reserved_11
	* Description: not used
	*/
	uint32_t Reserved11 : 3;        /*## attribute Reserved11 */
	/**
	* BitsName: Reserved_12
	* Description: not used
	*/
	uint32_t Reserved12 : 1;        /*## attribute Reserved12 */
	/**
	* BitsName: Reserved_13
	* Description: not used
	*/
	uint32_t Reserved13 : 3;        /*## attribute Reserved13 */
	/**
	* BitsName: Reserved_14
	* Description: not used
	*/
	uint32_t Reserved14 : 1;        /*## attribute Reserved14 */
	/**
	* BitsName: Reserved_15
	* Description: not used
	*/
	uint32_t Reserved15 : 1;        /*## attribute Reserved15 */
	/**
	* BitsName: Reserved_16
	* Description: not used
	*/
	uint32_t Reserved16 : 1;        /*## attribute Reserved16 */
	/**
	* BitsName: Reserved_17
	* Description: not used
	*/
	uint32_t Reserved17 : 1;        /*## attribute Reserved17 */
	/**
	* BitsName: Reserved_18
	* Description: not used
	*/
	uint32_t Reserved18 : 1;        /*## attribute Reserved18 */
	/**
	* BitsName: mask_te_stuckat_transient_error_flag
	* Description: If set to '1', the *_error_flag from the IP  is masked and will not be forwarded to central control
	* 1:  mask the stuckat/transient error at timing_engine
	* 0:  do not mask stuckat/transient  error
	* Read/Write: RW
	* Bits: [25]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskTeStuckatTransientErrorFlag : 1;        /*## attribute MaskTeStuckatTransientErrorFlag */
	/**
	* BitsName: Reserved_19
	* Description: not used
	*/
	uint32_t Reserved19 : 1;        /*## attribute Reserved19 */
	/**
	* BitsName: Reserved_20
	* Description: not used
	*/
	uint32_t Reserved20 : 1;        /*## attribute Reserved20 */
	/**
	* BitsName: Reserved_21
	* Description: not used
	*/
	uint32_t Reserved21 : 1;        /*## attribute Reserved21 */
	/**
	* BitsName: Reserved_22
	* Description: not used
	*/
	uint32_t Reserved22 : 1;        /*## attribute Reserved22 */
	/**
	* BitsName: Reserved_23
	* Description: not used
	*/
	uint32_t Reserved23 : 1;        /*## attribute Reserved23 */
	/**
	* BitsName: Reserved_24
	* Description: not used
	*/
	uint32_t Reserved24 : 1;        /*## attribute Reserved24 */
}R2M06_MaskCcErrorFlagBits_t;
/**
* R2M06_CrcErrorStatus1Bits_t
* RegisterName: CRC_ERROR_STATUS1
* Status of the CRC for each register
* Address: 0xF40
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: crc_error_status_reg1
	* Description: Each bit represent the error status of the corresponding register
	*
	* 0 : No error
	* 1 : CRC error
	*
	* Note: The status corresponds the first 32 registers listed i.e registers 31(msb) down to 0(lsb)
	* Read/Write: R
	* Bits: [31:0]
	* ResetValue: 0b00000000000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CrcErrorStatusReg1 : 32;        /*## attribute CrcErrorStatusReg1 */
}R2M06_CrcErrorStatus1Bits_t;
/**
* R2M06_CrcErrorStatus2Bits_t
* RegisterName: CRC_ERROR_STATUS2
* Status of the CRC for each register
* Address: 0xF44
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: crc_error_status_reg2
	* Description: Each bit represent the error status of the corresponding register
	*
	* 0 : No error
	* 1 : CRC error
	*
	* Note: The status corresponds to next 32 registers listed i.e registers 63(msb) down to 32(lsb)
	* Read/Write: R
	* Bits: [31:0]
	* ResetValue: 0b00000000000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CrcErrorStatusReg2 : 32;        /*## attribute CrcErrorStatusReg2 */
}R2M06_CrcErrorStatus2Bits_t;
/**
* R2M06_CrcErrorStatus3Bits_t
* RegisterName: CRC_ERROR_STATUS3
* Status of the CRC for each register
* Address: 0xF48
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: crc_error_status_reg3
	* Description: Each bit represent the error status of the corresponding register
	*
	* 0 : No error
	* 1 : CRC error
	*
	* Note: The status corresponds to next 32 registers listed i.e registers 95(msb) down to 64(lsb)
	* Read/Write: R
	* Bits: [31:0]
	* ResetValue: 0b00000000000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CrcErrorStatusReg3 : 32;        /*## attribute CrcErrorStatusReg3 */
}R2M06_CrcErrorStatus3Bits_t;
/**
* R2M06_CrcErrorStatus4Bits_t
* RegisterName: CRC_ERROR_STATUS4
* Status of the CRC for each register
* Address: 0xF4C
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: crc_error_status_reg4
	* Description: Each bit represent the error status of the corresponding register
	*
	* 0 : No error
	* 1 : CRC error
	*
	* Note: The status corresponds to next 32 registers listed i.e registers 127(msb) down to 96(lsb)
	* Read/Write: R
	* Bits: [31:0]
	* ResetValue: 0b00000000000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CrcErrorStatusReg4 : 32;        /*## attribute CrcErrorStatusReg4 */
}R2M06_CrcErrorStatus4Bits_t;
/**
* R2M06_CrcErrorStatus5Bits_t
* RegisterName: CRC_ERROR_STATUS5
* Status of the CRC for each register
* Address: 0xF50
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: crc_error_status_reg5
	* Description: Each bit represent the error status of the corresponding register
	*
	* 0 : No error
	* 1 : CRC error
	*
	* Note: The status corresponds to last 3 registers listed i.e registers 130(msb) down to 128(lsb) and other bits are not valid
	* Read/Write: R
	* Bits: [31:0]
	* ResetValue: 0b00000000000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CrcErrorStatusReg5 : 32;        /*## attribute CrcErrorStatusReg5 */
}R2M06_CrcErrorStatus5Bits_t;
/**
* R2M06_ModuleIdBits_t
* RegisterName: MODULE_ID
* Module ID register
* Address: 0xFFC
* ResetValue: 0x00065001
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: aperture
	* Description: Aperture. Fixed value of 'h01
	* Read/Write: R
	* Bits: [7:0]
	* ResetValue: 0b00000001
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Aperture : 8;        /*## attribute Aperture */
	/**
	* BitsName: minor_revision
	* Description: Minor revision number i.e. with no software consequences
	* Read/Write: R
	* Bits: [11:8]
	* ResetValue: 0b0000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MinorRevision : 4;        /*## attribute MinorRevision */
	/**
	* BitsName: major_revision
	* Description: Major revision i.e. implies software modifications
	* Read/Write: R
	* Bits: [15:12]
	* ResetValue: 0b0101
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MajorRevision : 4;        /*## attribute MajorRevision */
	/**
	* BitsName: identifier
	* Description: This is the unique identifier of the module
	* Read/Write: R
	* Bits: [31:16]
	* ResetValue: 0b0000000000000110
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Identifier : 16;        /*## attribute Identifier */
}R2M06_ModuleIdBits_t;

 #else
/**
* R2M06_CpControlBits_t
* RegisterName: CP_CONTROL
* Charge pump settings
* Address: 0x000
* ResetValue: 0x0FF00000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 4;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_cp_slice_en_1_spi
	* Description:
	* This control is applicable only when fast reset/gear switching is enabled. During reset time of the chirp, this slice setting is applied
	*
	* Enable cp slices (enable two slices 300uA). Every bit corresponds to one slice. This is selected when pll_cp_slice_ctrl output is 1'b1. The value in this field corresponds to the value during the reset of the chirp
	* NOTE: reset value pointing to all slices enabled (all ones)
	* Read/Write: RW
	* Bits: [27:20]
	* ResetValue: 0b11111111
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlCpSliceEn1Spi : 8;        /*## attribute CtlCpSliceEn1Spi */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_cp_replica_bias_en_mux_ctrl
	* Description: Controls the replica bias enabling based on the digital statemachine or local value from ctl_cp_replica_bias_en_spi field
	*
	* 0 :  Controlled by statemachine i.e ctl_cp_replica_bias_en_spi is driven after the delay from timing engine statemachine
	* 1 :  ctl_cp_replica_bias_en_spi value is driven directly from the local spi field
	*
	* In the application context, the value should be set 0.
	*
	* Note: The actual enable of the replica bias happens after a delay which is controlled by CHIRP_BIAS_SWITCH_CONTROL in timing engine if this field is set as 0
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlCpReplicaBiasEnMuxCtrl : 1;        /*## attribute CtlCpReplicaBiasEnMuxCtrl */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: ctl_cp_replica_bias_en_spi
	* Description: Enable charge pump replica bias circuit (improve linearity)
	* 1 :  Enable CP replica bias
	* 0 :  Disable CP replica bias
	*
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlCpReplicaBiasEnSpi : 1;        /*## attribute CtlCpReplicaBiasEnSpi */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: ctl_cp_en_spi
	* Description: Enable charge pump
	* 1 :  Enable CP
	* 0 :  Disable CP
	*
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlCpEnSpi : 1;        /*## attribute CtlCpEnSpi */
	/**
	* BitsName: Reserved_4
	* Description: not used
	*/
	uint32_t Reserved4 : 3;        /*## attribute Reserved4 */
	/**
	* BitsName: ctl_cp_force_dn_spi
	* Description: Force the Charge Pump down
	* 1 : Decrease CP current
	* 0 :  No action
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlCpForceDnSpi : 1;        /*## attribute CtlCpForceDnSpi */
	/**
	* BitsName: Reserved_5
	* Description: not used
	*/
	uint32_t Reserved5 : 3;        /*## attribute Reserved5 */
	/**
	* BitsName: ctl_cp_force_up_spi
	* Description: Force the Charge Pump up
	* 1 :  Increase CP current
	* 0 :  No action
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlCpForceUpSpi : 1;        /*## attribute CtlCpForceUpSpi */
}R2M06_CpControlBits_t;
/**
* R2M06_VcoControlBits_t
* RegisterName: VCO_CONTROL
* Vco control settings
* Address: 0x004
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 7;        /*## attribute Reserved0 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 4;        /*## attribute Reserved2 */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 5;        /*## attribute Reserved3 */
	/**
	* BitsName: Reserved_4
	* Description: not used
	*/
	uint32_t Reserved4 : 7;        /*## attribute Reserved4 */
	/**
	* BitsName: Reserved_5
	* Description: not used
	*/
	uint32_t Reserved5 : 3;        /*## attribute Reserved5 */
	/**
	* BitsName: Reserved_6
	* Description: not used
	*/
	uint32_t Reserved6 : 1;        /*## attribute Reserved6 */
	/**
	* BitsName: Reserved_7
	* Description: not used
	*/
	uint32_t Reserved7 : 1;        /*## attribute Reserved7 */
	/**
	* BitsName: Reserved_8
	* Description: not used
	*/
	uint32_t Reserved8 : 1;        /*## attribute Reserved8 */
	/**
	* BitsName: ctl_sel_vco_1g_5g_spi
	* Description: selecting current source connected either to 1G or 2/4G VCO
	* 0 :  1GHz VCO selected
	* 1 :  4GHz  VCO selected
	*
	* - for 2GHz Bandwidth set ctl_vco_bandwidth_spi_profile*=0
	* - for 4GHz Bandwidth set ctl_vco_bandwidth_spi_profile*=1
	* Read/Write: RW
	* Bits: [1]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CtlSelVco1G5GSpi : 1;        /*## attribute CtlSelVco1G5GSpi */
	/**
	* BitsName: Reserved_9
	* Description: not used
	*/
	uint32_t Reserved9 : 1;        /*## attribute Reserved9 */
}R2M06_VcoControlBits_t;
/**
* R2M06_VcoBufferLdoControlBits_t
* RegisterName: VCO_BUFFER_LDO_CONTROL
* Vco buffer ldo controls
* Address: 0x008
* ResetValue: 0x0000000F
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 27;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_ldo_vco_sel_vout_spi
	* Description: Select vout of VCO LDO. Value comes from OTP
	* Read/Write: RW
	* Bits: [4:0]
	* ResetValue: 0b01111
	* Source: OTP
	* FuSa: No
	*/
	uint32_t CtlLdoVcoSelVoutSpi : 5;        /*## attribute CtlLdoVcoSelVoutSpi */
}R2M06_VcoBufferLdoControlBits_t;
/**
* R2M06_CppfdLdoControlBits_t
* RegisterName: CPPFD_LDO_CONTROL
* Charge pump LDO settings
* Address: 0x00C
* ResetValue: 0x0000000F
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 27;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_ldo_cppfd_sel_vout_spi
	* Description: Select vout PFDCP LDO
	* Read/Write: RW
	* Bits: [4:0]
	* ResetValue: 0b01111
	* Source: OTP
	* FuSa: No
	*/
	uint32_t CtlLdoCppfdSelVoutSpi : 5;        /*## attribute CtlLdoCppfdSelVoutSpi */
}R2M06_CppfdLdoControlBits_t;
/**
* R2M06_DividerLdoControlBits_t
* RegisterName: DIVIDER_LDO_CONTROL
* Divider LDO settings
* Address: 0x010
* ResetValue: 0x0000000F
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 27;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_ldo_divider_sel_vout_spi
	* Description: Select vout  Divider LDO
	* Read/Write: RW
	* Bits: [4:0]
	* ResetValue: 0b01111
	* Source: OTP
	* FuSa: No
	*/
	uint32_t CtlLdoDividerSelVoutSpi : 5;        /*## attribute CtlLdoDividerSelVoutSpi */
}R2M06_DividerLdoControlBits_t;
/**
* R2M06_LdoEnControlBits_t
* RegisterName: LDO_EN_CONTROL
* Charge pump Phase Frequency Detector control settings
* Address: 0x014
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 23;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_ldo_vco_en_spi
	* Description: Enable VCO LDO
	* 1 :  Enable LDO
	* 0 :  Disable LDO
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlLdoVcoEnSpi : 1;        /*## attribute CtlLdoVcoEnSpi */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_ldo_divider_en_spi
	* Description: Enable Divider LDO
	* 1 :  Enable Divider LDO
	* 0 :  Disable Divider LDO
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlLdoDividerEnSpi : 1;        /*## attribute CtlLdoDividerEnSpi */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: ctl_ldo_cppfd_en_spi
	* Description: Enable PFDCP LDO
	* 1 :  Enable LDO
	* 0 :  Disable LDO
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlLdoCppfdEnSpi : 1;        /*## attribute CtlLdoCppfdEnSpi */
}R2M06_LdoEnControlBits_t;
/**
* R2M06_BiasBlockControlBits_t
* RegisterName: BIAS_BLOCK_CONTROL
* Bias settings
* Address: 0x018
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: ctl_ibias_en_spi
	* Description: Enable all the biasing block
	* 1 :  Enable Bias
	* 0 :  Disable Bias
	* Read/Write: RW
	* Bits: [31]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIbiasEnSpi : 1;        /*## attribute CtlIbiasEnSpi */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_ibias_tvn_20u_en_spi
	* Description: Enable current of the Tuning Voltage Monitor
	* 1 :  Enable tune current
	* 0 :  Disable tune current
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIbiasTvn20UEnSpi : 1;        /*## attribute CtlIbiasTvn20UEnSpi */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_ibias_vam_100u_en_spi
	* Description: Enable current of the VCO amplitude monitor
	* 1 :  Enable vco amplitude monitor
	* 0 :  Disable vco amplitude monitor
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIbiasVam100UEnSpi : 1;        /*## attribute CtlIbiasVam100UEnSpi */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: ctl_ibias_ld_10u_en_spi
	* Description: Enable current of the Lock detector
	* 1 :  Enable lock detector
	* 0 :  Disable lock detector
	* Read/Write: RW
	* Bits: [20]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIbiasLd10UEnSpi : 1;        /*## attribute CtlIbiasLd10UEnSpi */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: ctl_ibias_rst_buffer_en_spi
	* Description: Enable current of the reset buffer
	* 1 :  Enable reset buffer
	* 0 :  Disable reset buffer
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIbiasRstBufferEnSpi : 1;        /*## attribute CtlIbiasRstBufferEnSpi */
	/**
	* BitsName: Reserved_4
	* Description: not used
	*/
	uint32_t Reserved4 : 1;        /*## attribute Reserved4 */
	/**
	* BitsName: ctl_ibias_idac_injndac_en_spi
	* Description: Enable current of the idac injndac
	* 1 :  Enable idac injndac
	* 0 :  Disable idac injndac
	* Read/Write: RW
	* Bits: [14]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIbiasIdacInjndacEnSpi : 1;        /*## attribute CtlIbiasIdacInjndacEnSpi */
	/**
	* BitsName: ctl_ibias_idac_injpdac_en_spi
	* Description: Enable current of the idac injpdac
	* 1 :  Enable idac injpdac
	* 0 :  Disable idac injpdac
	* Read/Write: RW
	* Bits: [13]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIbiasIdacInjpdacEnSpi : 1;        /*## attribute CtlIbiasIdacInjpdacEnSpi */
	/**
	* BitsName: ctl_ibias_idac_opamp_en_spi
	* Description: Enable current of the idac_opamp
	* 1 :  Enable idac_opamp
	* 0 :  Disable idac_opamp
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIbiasIdacOpampEnSpi : 1;        /*## attribute CtlIbiasIdacOpampEnSpi */
	/**
	* BitsName: Reserved_5
	* Description: not used
	*/
	uint32_t Reserved5 : 3;        /*## attribute Reserved5 */
	/**
	* BitsName: ctl_ibias_cp_opamp_100u_en_spi
	* Description: Enable current of the CP opamp
	* 1 :  Enable current
	* 0 :  Disable current
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIbiasCpOpamp100UEnSpi : 1;        /*## attribute CtlIbiasCpOpamp100UEnSpi */
	/**
	* BitsName: Reserved_6
	* Description: not used
	*/
	uint32_t Reserved6 : 3;        /*## attribute Reserved6 */
	/**
	* BitsName: ctl_ibias_bist_dac_200u_en_spi
	* Description: Enable current rms detector
	* 1 :  Enable rms detector
	* 0 :  Disable rms detector
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIbiasBistDac200UEnSpi : 1;        /*## attribute CtlIbiasBistDac200UEnSpi */
	/**
	* BitsName: Reserved_7
	* Description: not used
	*/
	uint32_t Reserved7 : 3;        /*## attribute Reserved7 */
	/**
	* BitsName: ctl_ibias_div_350u_en_spi
	* Description: Enable current of the dividers
	* 1 :  Enable divider current
	* 0 :  Disable  divider current
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIbiasDiv350UEnSpi : 1;        /*## attribute CtlIbiasDiv350UEnSpi */
}R2M06_BiasBlockControlBits_t;
/**
* R2M06_BufferControlBits_t
* RegisterName: BUFFER_CONTROL
* REF Buffer settings
* Address: 0x01C
* ResetValue: 0x00000110
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 23;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_buffer_480meg_en_spi
	* Description: Enable 480MHz buffer
	* 1 :  Enable 480MHz buffer
	* 0 :  Disable 480MHz buffer
	*
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlBuffer480MegEnSpi : 1;        /*## attribute CtlBuffer480MegEnSpi */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_buffer_480meg_bal_spi
	* Description: Select balanced or unbalanced signal 480MHz buffer (used for debugging)
	* 1 :  balanced (reset value for costumers)
	* 0 :  unbalanced
	*
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlBuffer480MegBalSpi : 1;        /*## attribute CtlBuffer480MegBalSpi */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: ctl_buffer_480meg_pol_spi
	* Description: Select signal polarity 480MHz buffer (in case it is balanced 0 degrees or 180 degrees)
	* 1 :  180 degree
	* 0 :  0 degree (reset value for costumers)
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlBuffer480MegPolSpi : 1;        /*## attribute CtlBuffer480MegPolSpi */
}R2M06_BufferControlBits_t;
/**
* R2M06_PllFastResetInjEnControlBits_t
* RegisterName: PLL_FAST_RESET_INJ_EN_CONTROL
* This register is used to control the settings for fast reset alias gear switching. Please refer Chirp_Afc_Information Tab
* Address: 0x020
* ResetValue: 0x00000011
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 27;        /*## attribute Reserved0 */
	/**
	* BitsName: pll_gs_dis
	* Description: Disable fast reset gear-switching
	*
	* 1 : Disable fast reset gear switching
	* 0 : Enable fast reset  gear switching
	*
	* NOTE: reset value pointing to gear-switching disabled, this setting will overrule other controls by: gs forced to 0, selectors forced to gs, lpf controls pll_lpf_c?_a|b_ctrl* not affected
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllGsDis : 1;        /*## attribute PllGsDis */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: pll_inj_dis
	* Description: Disable fast reset current injection
	*
	* 1 : Disable fast reset current injection
	* 0 : Enable fast reset current injection
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllInjDis : 1;        /*## attribute PllInjDis */
}R2M06_PllFastResetInjEnControlBits_t;
/**
* R2M06_PllFastResetTimingControlBits_t
* RegisterName: PLL_FAST_RESET_TIMING_CONTROL
* This register is used to control the settings for fast reset alias gear switching (gs). This register settings are applicable only when pll_gs_dis = 0 in the register PLL_FAST_RESET_INJ_EN_CONTROL. The fast reset is also called fast return. Please refer Chirp_Afc_Information Tab
* Address: 0x024
* ResetValue: 0x00000014
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: pll_gs_start_ctrl
	* Description: Pll gs pulse generation start point
	*
	* 0 : Start of Jump back timer
	* 1 : End of Jump back timer i.e start of reset
	* Read/Write: RW
	* Bits: [31]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllGsStartCtrl : 1;        /*## attribute PllGsStartCtrl */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: pll_gs_ctrl
	* Description: Controls the gs signal generation
	* 2'b00 :  gs driven Low - gs disabled, pll bandwidth low
	* 2'b01 :  gs driven High - gs disabled, pll bandwidth high
	* 2'b10 :  Pass the generated gs signal - gs enabled, pll bandwidth low acq, high in reset
	* 2'b11 :  Pass the generated gs after Invert - gs enabled, pll bandwidth high acq, low in reset
	* Read/Write: RW
	* Bits: [29:28]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllGsCtrl : 2;        /*## attribute PllGsCtrl */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: pll_gs_sync_down_ctrl
	* Description: Controls the gs generation after synchronizing with PLL CP Mirror DN  pulse.
	* 1'b0 : Pass the gs synchronized with PLL DN pulse
	* 1'b1 : Pass the inverted  gs synchronized with PLL DN pulse (for debug)
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllGsSyncDownCtrl : 1;        /*## attribute PllGsSyncDownCtrl */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: pll_gs_sync_up_ctrl
	* Description: Controls the gs generation after synchronizing with PLL CP Mirror UP  pulse.
	* 1'b0 : Pass the gs synchronized with PLL UP pulse
	* 1'b1 : Pass the inverted  gs synchronized with PLL UP pulse (for debug)
	* Read/Write: RW
	* Bits: [20]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllGsSyncUpCtrl : 1;        /*## attribute PllGsSyncUpCtrl */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: pll_gs_delay
	* Description: gs signal is generated either at the start of jump back timer or at the expiry of the jump back timer i.e at the chirp reset state. This field defines the delay of the gs signal generation from the above points.
	*
	* The selection of the start point is defined by the bit31 in the same register
	*
	* The delay is represented in cycles of 480MHz clock.
	* Supported values from 0 to 1 us
	*
	* Read/Write: RW
	* Bits: [16:8]
	* ResetValue: 0b000000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllGsDelay : 9;        /*## attribute PllGsDelay */
	/**
	* BitsName: Reserved_4
	* Description: not used
	*/
	uint32_t Reserved4 : 8;        /*## attribute Reserved4 */
}R2M06_PllFastResetTimingControlBits_t;
/**
* R2M06_CpFastResetSliceControlBits_t
* RegisterName: CP_FAST_RESET_SLICE_CONTROL
* This register is used to control the timing for the cp slices in the gear switch enabled mode. This register settings are applicable only when pll_gs_dis = 0 in the register PLL_FAST_RESET_INJ_EN_CONTROL. The fast reset is also called fast return. Please refer Chirp_Afc_Information Tab
* Address: 0x028
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 30;        /*## attribute Reserved0 */
	/**
	* BitsName: pll_cp_slice_ctrl
	* Description: Slice enabling timing control with gear switching functionality. Possible to drive directly from timing engine or to use sync block within PLL that observes UP or DN pulses of the PFD.
	*
	* pll_cp_slice_ctrl = control for gs of cp slices
	* The final slice value (ctl_cp_slice_en_spi) driven based on gs selector bit  i.e ctl_cp_slice_en_0 or ctl_cp_slice_en_1 is selected based on the way gs signal is configured using the following settings
	*
	* 2'b00 :  gs signal from timing engine directly used as selector (default)
	* 2'b01 :  gs synchronized with PLL UP pulse used as selector
	* 2'b10 :  gs synchronized with PLL DN pulse used as selector
	* 2'b11 :  same functionality as 2'b00
	*
	* NOTE: reset value pointing to gs signal used as a selector
	* Read/Write: RW
	* Bits: [1:0]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllCpSliceCtrl : 2;        /*## attribute PllCpSliceCtrl */
}R2M06_CpFastResetSliceControlBits_t;
/**
* R2M06_PllLpfCapGsSelControlBits_t
* RegisterName: PLL_LPF_CAP_GS_SEL_CONTROL
* This register is used to control the settings for lpf capacitors (C1,C2,C3) in the gear switch enabled mode. This register settings are applicable only when pll_gs_dis = 0 in the register PLL_FAST_RESET_INJ_EN_CONTROL. The fast reset is also called fast return. Please refer Chirp_Afc_Information Tab
* Address: 0x02C
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 30;        /*## attribute Reserved0 */
	/**
	* BitsName: pll_lpf_cap_gs_sel_ctrl
	* Description: LPF Capacitance enabling timing control with gear switching functionality. Possible to drive directly from timing engine or to use sync block within PLL that observes UP or DN pulses of the PFD.
	*
	* The third stage of gs signal generation
	*
	* 2'b00 :  gs signal is used directly from timing engine (default)
	* 2'b01 :  gs synchronized with PLL UP pulse is used as selector
	* 2'b10 :  gs synchronized with PLL DN pulse is used as selector
	* 2'b11 :  same functionality as 2'b00
	*
	* NOTE: reset value pointing to gs signal as a selector
	* Read/Write: RW
	* Bits: [1:0]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfCapGsSelCtrl : 2;        /*## attribute PllLpfCapGsSelCtrl */
}R2M06_PllLpfCapGsSelControlBits_t;
/**
* R2M06_PllDacInjAcqControlBits_t
* RegisterName: PLL_DAC_INJ_ACQ_CONTROL
* This register is used to control the settings of the dac injection current settings (profiles) during the acquisition.  This register settings are applicable only when pll_inj_dis = 0 in the register PLL_FAST_RESET_INJ_EN_CONTROL. The fast reset is also called fast return. Please refer Chirp_Afc_Information Tab
* Address: 0x030
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 15;        /*## attribute Reserved0 */
	/**
	* BitsName: pll_fr_idac_polarity
	* Description: IDAC polarity
	*
	* 0: Negative polarity - idac sourcing in acq, sinking in rst (vtune rising in acq, falling in rst)
	* 1: Positive polarity - idac sinking in acq, sourcing in rst (vtune falling in acq, rising in rst)
	* debug and flexibility purposes
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllFrIdacPolarity : 1;        /*## attribute PllFrIdacPolarity */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: pll_dac_inj_acq_ctrl
	* Description:
	* Controls the dac_inj_acq signal generation
	* 2'b00 : dac_inj_acq driven Low - timing engine not used (static case, injection current continuously disabled)
	* 2'b01 : dac_inj_acq driven High - timing engine not used (static case,  injection current continuously enabled)
	* 2'b10 : Pass the generated dac_inj_acq signal from timing engine
	* 2'b11 : Pass the generated dac_inj_acq inverted signal from timing engine
	* Read/Write: RW
	* Bits: [13:12]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllDacInjAcqCtrl : 2;        /*## attribute PllDacInjAcqCtrl */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: pll_dac_inj_acq_delay
	* Description: The dac_inj_acq signal is generated during the acquisition period and stays high during the tsettle + tacq.
	* This field defines the delay of the dac_inj_acq signal from the start point tsettle.
	*
	* The delay is represented in cycles of 480MHz clock.
	* Supported values from 0 to 1 us
	* NOTE: reset value pointing to no injection delay, pll_dac_inj_acq_delay = 0;
	* Read/Write: RW
	* Bits: [8:0]
	* ResetValue: 0b000000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllDacInjAcqDelay : 9;        /*## attribute PllDacInjAcqDelay */
}R2M06_PllDacInjAcqControlBits_t;
/**
* R2M06_PllDacInjRstControlBits_t
* RegisterName: PLL_DAC_INJ_RST_CONTROL
* This register is used to control the settings of the dac injection current during the reset. This register settings are applicable only when pll_inj_dis = 0 in the register PLL_FAST_RESET_INJ_EN_CONTROL. The fast reset is also called fast return. Please refer Chirp_Afc_Information Tab
* Address: 0x034
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: pll_dac_inj_rst_start_ctrl
	* Description: dac_inj_rst pulse generation start point
	*
	* 0 : Start of Jump back timer
	* 1 : End of Jump back timer i.e start of reset
	* Read/Write: RW
	* Bits: [31]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllDacInjRstStartCtrl : 1;        /*## attribute PllDacInjRstStartCtrl */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 5;        /*## attribute Reserved0 */
	/**
	* BitsName: pll_dac_inj_rst_output_ctrl
	* Description: This control defines if the timing of injection DAC during reset is controlled by timing engine directly or that is synchronized to internal PLL UP or DN pulse
	*
	* 2'b00 :  dac_inj_rst signal is used directly from timing engine (default)
	* 2'b01 :  dac_inj_rst signal synchronized with PLL UP pulse
	* 2'b10 :  dac_inj_rst synchronized with PLL DN pulse
	* 2'b11 :  same functionality as 2'b00
	*
	* NOTE: reset value pointing to second stage control (timing engine mux)
	* Read/Write: RW
	* Bits: [25:24]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllDacInjRstOutputCtrl : 2;        /*## attribute PllDacInjRstOutputCtrl */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: pll_dac_inj_rst_ctrl
	* Description: dac_inj_rst timing engine signal generation control (timing engine mux)
	* Select how timing engine will be used for injection dac during reset:
	* 2'b00 : dac_inj_rst driven Low - timing engine not used (static case,  injection current continuously disabled)
	* 2'b01 : dac_inj_rst driven High - timing engine not used (static case,  injection current continuously enabled)
	* 2'b10 : Pass the generated dac_inj_rst signal from timing engine
	* 2'b11 : Pass the generated dac_inj_rst inverted signal from timing engine
	* Read/Write: RW
	* Bits: [21:20]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllDacInjRstCtrl : 2;        /*## attribute PllDacInjRstCtrl */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: pll_dac_inj_rst_sync_down_ctrl
	* Description: Controls polarity of PLL DN sinc signal
	* 1'b0 : Pass the PLL DN signal synchronized dac_inj_rst
	* 1'b1 : Pass the PLL DN signal synchronized dac_inj_rst after invert
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllDacInjRstSyncDownCtrl : 1;        /*## attribute PllDacInjRstSyncDownCtrl */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: pll_dac_inj_rst_sync_up_ctrl
	* Description: Controls polarity of PLL UP sinc signal
	* 1'b0 : Pass the PLL UP signal synchronized dac_inj_rst
	* 1'b1 : Pass the PLL UP signal synchronized dac_inj_rst after invert
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllDacInjRstSyncUpCtrl : 1;        /*## attribute PllDacInjRstSyncUpCtrl */
	/**
	* BitsName: Reserved_4
	* Description: not used
	*/
	uint32_t Reserved4 : 3;        /*## attribute Reserved4 */
	/**
	* BitsName: pll_dac_inj_rst_delay
	* Description: The dac_inj_rst signal is generated either at the start of jump back timer or at the expiry of the jump back timer i.e at the chirp reset state. This field defines the delay of the dac_inj_rst signal generation from the above points (Only valid if directly driven from timing engine)
	*
	* The selection of the start point is defined by the bit31 in the same register
	*
	* The delay is represented in cycles of 480MHz clock.
	* Supported values from 0 to 1 us
	* NOTE: reset value pointing to no delay, pll_dac_inj_rst_delay = 0
	* Read/Write: RW
	* Bits: [8:0]
	* ResetValue: 0b000000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllDacInjRstDelay : 9;        /*## attribute PllDacInjRstDelay */
}R2M06_PllDacInjRstControlBits_t;
/**
* R2M06_PllDacInjIbiasControlBits_t
* RegisterName: PLL_DAC_INJ_IBIAS_CONTROL
* This register is used to control the ibias current ramp up during the end of the acqusition phase to enable the fast settling of the charge pump with slice change during reset. Applicable only for fast return/fast reset is enabled
* Address: 0x038
* ResetValue: 0x00000020
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 23;        /*## attribute Reserved0 */
	/**
	* BitsName: pll_dac_inj_ibias_ramp_en
	* Description: Control to enable the fast settling of charge pump by enabling the ibias current ramp during the end of the acquisition phase
	* 1'b0 : Disable the ibias current ramp
	* 1'b1 : Enable the ibias current ramp
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllDacInjIbiasRampEn : 1;        /*## attribute PllDacInjIbiasRampEn */
	/**
	* BitsName: pll_dac_inj_ibias_ramp_num_steps
	* Description: The number of ibias current ramp steps required to reach ibias threshold before the reset.
	* The ibias current is incremented from 0, in number of steps during the end of the acquisition to reach the threshold before the reset starts. This enables the fast settling of the CP slice switch. The programmed steps are with 25 ns resolution i.e Ibias_ramp = pll_dac_inj_ibias_ramp_num_steps * ibias_step. Actually ibias step is the ibias current step in ua(TBD).
	* Ideally 32 steps (0.8 us) required to reach the ibias threshold
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00100000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllDacInjIbiasRampNumSteps : 8;        /*## attribute PllDacInjIbiasRampNumSteps */
}R2M06_PllDacInjIbiasControlBits_t;
/**
* R2M06_CpPllbwCfg0Bits_t
* RegisterName: CP_PLLBW_CFG0
* Chargepump profile settings
* Address: 0x050
* ResetValue: 0x00300001
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_cp_ioffset_set_spi_pllbw_cfg0
	* Description: charge pump offset, bit wise programming, polarity given by 'ctl_cp_ioffset_updn_spi_profile*':
	* [7]=+35%; [6]=+30% ;[5]=+25%; [4]=+20%; [3]=+15%;[2]=+10%; [1]=+5%; [0]=0%
	* Read/Write: RW
	* Bits: [30:28]
	* ResetValue: 0b000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlCpIoffsetSetSpiPllbwCfg0 : 3;        /*## attribute CtlCpIoffsetSetSpiPllbwCfg0 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_cp_ioffset_updn_spi_pllbw_cfg0
	* Description: Direction of the charge pump offset
	* 1 :  Pmos inject current
	* 0 :  Nmos substract current
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlCpIoffsetUpdnSpiPllbwCfg0 : 1;        /*## attribute CtlCpIoffsetUpdnSpiPllbwCfg0 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: ctl_ibias_cp_150u_spi_pllbw_cfg0
	* Description: Program current of the CP
	*
	* This is current that goes into CP, programmable between 0 and ~197u
	* current=ctl_ibias_cp_150u_spi x 3.125u
	* Read/Write: RW
	* Bits: [21:16]
	* ResetValue: 0b110000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIbiasCp150USpiPllbwCfg0 : 6;        /*## attribute CtlIbiasCp150USpiPllbwCfg0 */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 8;        /*## attribute Reserved3 */
	/**
	* BitsName: ctl_cp_slice_en_0_pllbw_cfg0
	* Description: Enable cp slices (each slice output level is controlled by ctl_ibias_cp_150u_spi setting ). Every bit corresponds to one slice. This register is valid when pll_cp_slice_ctrl output is 0 (corresponds to the acquisition of the chirp, Tsettling+Tacq)
	* NOTE: reset value pointing to single slice enabled
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00000001
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlCpSliceEn0PllbwCfg0 : 8;        /*## attribute CtlCpSliceEn0PllbwCfg0 */
}R2M06_CpPllbwCfg0Bits_t;
/**
* R2M06_PllLpfC1PllbwCfg0Bits_t
* RegisterName: PLL_LPF_C1_PLLBW_CFG0
* This register controls LPF C1 (Cap) bank
* Address: 0x054
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 16;        /*## attribute Reserved0 */
	/**
	* BitsName: pll_lpf_c1_rst_ctrl_pllbw_cfg0
	* Description: LPF C1 setting during rst (high BW)
	* Read/Write: RW
	* Bits: [15:8]
	* ResetValue: 0b00000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC1RstCtrlPllbwCfg0 : 8;        /*## attribute PllLpfC1RstCtrlPllbwCfg0 */
	/**
	* BitsName: pll_lpf_c1_acq_ctrl_pllbw_cfg0
	* Description: LPF C1 setting during acq (low BW)
	*
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC1AcqCtrlPllbwCfg0 : 8;        /*## attribute PllLpfC1AcqCtrlPllbwCfg0 */
}R2M06_PllLpfC1PllbwCfg0Bits_t;
/**
* R2M06_PllLpfC2PllbwCfg0Bits_t
* RegisterName: PLL_LPF_C2_PLLBW_CFG0
* This register controls LPF C2 (Cap) bank
* Address: 0x058
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 16;        /*## attribute Reserved0 */
	/**
	* BitsName: pll_lpf_c2_rst_ctrl_pllbw_cfg0
	* Description: LPF C2 setting during rst (high BW)
	* Read/Write: RW
	* Bits: [15:8]
	* ResetValue: 0b00000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC2RstCtrlPllbwCfg0 : 8;        /*## attribute PllLpfC2RstCtrlPllbwCfg0 */
	/**
	* BitsName: pll_lpf_c2_acq_ctrl_pllbw_cfg0
	* Description: LPF C2 setting during acq (low BW)
	*
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC2AcqCtrlPllbwCfg0 : 8;        /*## attribute PllLpfC2AcqCtrlPllbwCfg0 */
}R2M06_PllLpfC2PllbwCfg0Bits_t;
/**
* R2M06_PllLpfC3PllbwCfg0Bits_t
* RegisterName: PLL_LPF_C3_PLLBW_CFG0
* This register controls LPF C3 (Cap) bank
* Address: 0x05C
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 16;        /*## attribute Reserved0 */
	/**
	* BitsName: pll_lpf_c3_rst_ctrl_pllbw_cfg0
	* Description: LPF C3 setting during rst (high BW)
	* Read/Write: RW
	* Bits: [15:8]
	* ResetValue: 0b00000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC3RstCtrlPllbwCfg0 : 8;        /*## attribute PllLpfC3RstCtrlPllbwCfg0 */
	/**
	* BitsName: pll_lpf_c3_acq_ctrl_pllbw_cfg0
	* Description: LPF C3 setting during acq (low BW)
	*
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC3AcqCtrlPllbwCfg0 : 8;        /*## attribute PllLpfC3AcqCtrlPllbwCfg0 */
}R2M06_PllLpfC3PllbwCfg0Bits_t;
/**
* R2M06_PllLpfResPllbwCfg0Bits_t
* RegisterName: PLL_LPF_RES_PLLBW_CFG0
* settings for FILTER
* Address: 0x060
* ResetValue: 0x00001616
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 19;        /*## attribute Reserved0 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 5;        /*## attribute Reserved1 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: ctl_lpf_r1_spi_pllbw_cfg0
	* Description: Select loop filter res. R1
	* Read/Write: RW
	* Bits: [4:0]
	* ResetValue: 0b10110
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlLpfR1SpiPllbwCfg0 : 5;        /*## attribute CtlLpfR1SpiPllbwCfg0 */
}R2M06_PllLpfResPllbwCfg0Bits_t;
/**
* R2M06_CpPllbwCfg1Bits_t
* RegisterName: CP_PLLBW_CFG1
* Chargepump profile settings
* Address: 0x070
* ResetValue: 0x00300001
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_cp_ioffset_set_spi_pllbw_cfg1
	* Description: charge pump offset, bit wise programming, polarity given by 'ctl_cp_ioffset_updn_spi_profile*':
	* [7]=+35%; [6]=+30% ;[5]=+25%; [4]=+20%; [3]=+15%;[2]=+10%; [1]=+5%; [0]=0%
	* Read/Write: RW
	* Bits: [30:28]
	* ResetValue: 0b000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlCpIoffsetSetSpiPllbwCfg1 : 3;        /*## attribute CtlCpIoffsetSetSpiPllbwCfg1 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_cp_ioffset_updn_spi_pllbw_cfg1
	* Description: Direction of the charge pump offset
	* 1 :  Pmos inject current
	* 0 :  Nmos substract current
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlCpIoffsetUpdnSpiPllbwCfg1 : 1;        /*## attribute CtlCpIoffsetUpdnSpiPllbwCfg1 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: ctl_ibias_cp_150u_spi_pllbw_cfg1
	* Description: Program current of the CP
	*
	* This is current that goes into CP, programmable between 0 and ~197u
	* current=ctl_ibias_cp_150u_spi x 3.125u
	* Read/Write: RW
	* Bits: [21:16]
	* ResetValue: 0b110000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIbiasCp150USpiPllbwCfg1 : 6;        /*## attribute CtlIbiasCp150USpiPllbwCfg1 */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 8;        /*## attribute Reserved3 */
	/**
	* BitsName: ctl_cp_slice_en_0_pllbw_cfg1
	* Description: Enable cp slices (one slice is equal to ctl_ibias_cp_150u_spi setting ).. Every bit corresponds to one slice. This is selected when pll_cp_slice_ctrl output is 0.  The value in this field corresponds to the value during the acquisition of the chirp
	* NOTE: reset value pointing to one slice enabled (single one)
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00000001
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlCpSliceEn0PllbwCfg1 : 8;        /*## attribute CtlCpSliceEn0PllbwCfg1 */
}R2M06_CpPllbwCfg1Bits_t;
/**
* R2M06_PllLpfC1PllbwCfg1Bits_t
* RegisterName: PLL_LPF_C1_PLLBW_CFG1
* This register controls LPF C1 (Cap) bank
* Address: 0x074
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 16;        /*## attribute Reserved0 */
	/**
	* BitsName: pll_lpf_c1_rst_ctrl_pllbw_cfg1
	* Description: LPF C1 setting during rst (high BW)
	* Read/Write: RW
	* Bits: [15:8]
	* ResetValue: 0b00000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC1RstCtrlPllbwCfg1 : 8;        /*## attribute PllLpfC1RstCtrlPllbwCfg1 */
	/**
	* BitsName: pll_lpf_c1_acq_ctrl_pllbw_cfg1
	* Description: LPF C1 setting during acq (low BW)
	*
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC1AcqCtrlPllbwCfg1 : 8;        /*## attribute PllLpfC1AcqCtrlPllbwCfg1 */
}R2M06_PllLpfC1PllbwCfg1Bits_t;
/**
* R2M06_PllLpfC2PllbwCfg1Bits_t
* RegisterName: PLL_LPF_C2_PLLBW_CFG1
* This register controls LPF C2 (Cap) bank
* Address: 0x078
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 16;        /*## attribute Reserved0 */
	/**
	* BitsName: pll_lpf_c2_rst_ctrl_pllbw_cfg1
	* Description: LPF C2 setting during rst (high BW)
	* Read/Write: RW
	* Bits: [15:8]
	* ResetValue: 0b00000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC2RstCtrlPllbwCfg1 : 8;        /*## attribute PllLpfC2RstCtrlPllbwCfg1 */
	/**
	* BitsName: pll_lpf_c2_acq_ctrl_pllbw_cfg1
	* Description: LPF C2 setting during acq (low BW)
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC2AcqCtrlPllbwCfg1 : 8;        /*## attribute PllLpfC2AcqCtrlPllbwCfg1 */
}R2M06_PllLpfC2PllbwCfg1Bits_t;
/**
* R2M06_PllLpfC3PllbwCfg1Bits_t
* RegisterName: PLL_LPF_C3_PLLBW_CFG1
* This register controls LPF C3 (Cap) bank
* Address: 0x07C
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 16;        /*## attribute Reserved0 */
	/**
	* BitsName: pll_lpf_c3_rst_ctrl_pllbw_cfg1
	* Description: LPF C3 setting during rst (high BW)
	* Read/Write: RW
	* Bits: [15:8]
	* ResetValue: 0b00000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC3RstCtrlPllbwCfg1 : 8;        /*## attribute PllLpfC3RstCtrlPllbwCfg1 */
	/**
	* BitsName: pll_lpf_c3_acq_ctrl_pllbw_cfg1
	* Description: LPF C3 setting during acq (low BW)
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC3AcqCtrlPllbwCfg1 : 8;        /*## attribute PllLpfC3AcqCtrlPllbwCfg1 */
}R2M06_PllLpfC3PllbwCfg1Bits_t;
/**
* R2M06_PllLpfResPllbwCfg1Bits_t
* RegisterName: PLL_LPF_RES_PLLBW_CFG1
* settings for FILTER
* Address: 0x080
* ResetValue: 0x00001616
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 19;        /*## attribute Reserved0 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 5;        /*## attribute Reserved1 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: ctl_lpf_r1_spi_pllbw_cfg1
	* Description: Select loop filter res. R1
	* Read/Write: RW
	* Bits: [4:0]
	* ResetValue: 0b10110
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlLpfR1SpiPllbwCfg1 : 5;        /*## attribute CtlLpfR1SpiPllbwCfg1 */
}R2M06_PllLpfResPllbwCfg1Bits_t;
/**
* R2M06_CpPllbwCfg2Bits_t
* RegisterName: CP_PLLBW_CFG2
* Chargepump profile settings
* Address: 0x090
* ResetValue: 0x00300001
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_cp_ioffset_set_spi_pllbw_cfg2
	* Description: charge pump offset, bit wise programming, polarity given by 'ctl_cp_ioffset_updn_spi_profile*':
	* [7]=+35%; [6]=+30% ;[5]=+25%; [4]=+20%; [3]=+15%;[2]=+10%; [1]=+5%; [0]=0%
	* Read/Write: RW
	* Bits: [30:28]
	* ResetValue: 0b000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlCpIoffsetSetSpiPllbwCfg2 : 3;        /*## attribute CtlCpIoffsetSetSpiPllbwCfg2 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_cp_ioffset_updn_spi_pllbw_cfg2
	* Description: Direction of the charge pump offset
	* 1 :  Pmos inject current
	* 0 :  Nmos substract current
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlCpIoffsetUpdnSpiPllbwCfg2 : 1;        /*## attribute CtlCpIoffsetUpdnSpiPllbwCfg2 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: ctl_ibias_cp_150u_spi_pllbw_cfg2
	* Description: Program current of the CP
	*
	* This is current that goes into CP, programmable between 0 and ~197u
	* current=ctl_ibias_cp_150u_spi x 3.125u
	* Read/Write: RW
	* Bits: [21:16]
	* ResetValue: 0b110000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIbiasCp150USpiPllbwCfg2 : 6;        /*## attribute CtlIbiasCp150USpiPllbwCfg2 */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 8;        /*## attribute Reserved3 */
	/**
	* BitsName: ctl_cp_slice_en_0_pllbw_cfg2
	* Description: Enable cp slices (one slice is equal to ctl_ibias_cp_150u_spi setting ).. Every bit corresponds to one slice. This is selected when pll_cp_slice_ctrl output is 0.  The value in this field corresponds to the value during the acquisition of the chirp
	* NOTE: reset value pointing to one slice enabled (single one)
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00000001
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlCpSliceEn0PllbwCfg2 : 8;        /*## attribute CtlCpSliceEn0PllbwCfg2 */
}R2M06_CpPllbwCfg2Bits_t;
/**
* R2M06_PllLpfC1PllbwCfg2Bits_t
* RegisterName: PLL_LPF_C1_PLLBW_CFG2
* This register controls LPF C1 (Cap) bank
* Address: 0x094
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 16;        /*## attribute Reserved0 */
	/**
	* BitsName: pll_lpf_c1_rst_ctrl_pllbw_cfg2
	* Description: LPF C1 setting during rst (high BW)
	* Read/Write: RW
	* Bits: [15:8]
	* ResetValue: 0b00000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC1RstCtrlPllbwCfg2 : 8;        /*## attribute PllLpfC1RstCtrlPllbwCfg2 */
	/**
	* BitsName: pll_lpf_c1_acq_ctrl_pllbw_cfg2
	* Description: LPF C1 setting during acq (low BW)
	*
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC1AcqCtrlPllbwCfg2 : 8;        /*## attribute PllLpfC1AcqCtrlPllbwCfg2 */
}R2M06_PllLpfC1PllbwCfg2Bits_t;
/**
* R2M06_PllLpfC2PllbwCfg2Bits_t
* RegisterName: PLL_LPF_C2_PLLBW_CFG2
* This register controls LPF C2 (Cap) bank
* Address: 0x098
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 16;        /*## attribute Reserved0 */
	/**
	* BitsName: pll_lpf_c2_rst_ctrl_pllbw_cfg2
	* Description: LPF C2 setting during rst (high BW)
	* Read/Write: RW
	* Bits: [15:8]
	* ResetValue: 0b00000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC2RstCtrlPllbwCfg2 : 8;        /*## attribute PllLpfC2RstCtrlPllbwCfg2 */
	/**
	* BitsName: pll_lpf_c2_acq_ctrl_pllbw_cfg2
	* Description: LPF C2 setting during acq (low BW)
	*
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC2AcqCtrlPllbwCfg2 : 8;        /*## attribute PllLpfC2AcqCtrlPllbwCfg2 */
}R2M06_PllLpfC2PllbwCfg2Bits_t;
/**
* R2M06_PllLpfC3PllbwCfg2Bits_t
* RegisterName: PLL_LPF_C3_PLLBW_CFG2
* This register controls LPF C3 (Cap) bank
* Address: 0x09C
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 16;        /*## attribute Reserved0 */
	/**
	* BitsName: pll_lpf_c3_rst_ctrl_pllbw_cfg2
	* Description: LPF C3 setting during rst (high BW)
	* Read/Write: RW
	* Bits: [15:8]
	* ResetValue: 0b00000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC3RstCtrlPllbwCfg2 : 8;        /*## attribute PllLpfC3RstCtrlPllbwCfg2 */
	/**
	* BitsName: pll_lpf_c3_acq_ctrl_pllbw_cfg2
	* Description: LPF C3 setting during acq (low BW)
	*
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC3AcqCtrlPllbwCfg2 : 8;        /*## attribute PllLpfC3AcqCtrlPllbwCfg2 */
}R2M06_PllLpfC3PllbwCfg2Bits_t;
/**
* R2M06_PllLpfResPllbwCfg2Bits_t
* RegisterName: PLL_LPF_RES_PLLBW_CFG2
* settings for FILTER
* Address: 0x0A0
* ResetValue: 0x00001616
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 19;        /*## attribute Reserved0 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 5;        /*## attribute Reserved1 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: ctl_lpf_r1_spi_pllbw_cfg2
	* Description: Select loop filter res. R1
	* Read/Write: RW
	* Bits: [4:0]
	* ResetValue: 0b10110
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlLpfR1SpiPllbwCfg2 : 5;        /*## attribute CtlLpfR1SpiPllbwCfg2 */
}R2M06_PllLpfResPllbwCfg2Bits_t;
/**
* R2M06_CpPllbwCfg3Bits_t
* RegisterName: CP_PLLBW_CFG3
* Chargepump profile settings
* Address: 0x0B0
* ResetValue: 0x00300001
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_cp_ioffset_set_spi_pllbw_cfg3
	* Description: charge pump offset, bit wise programming, polarity given by 'ctl_cp_ioffset_updn_spi_profile*':
	* [7]=+35%; [6]=+30% ;[5]=+25%; [4]=+20%; [3]=+15%;[2]=+10%; [1]=+5%; [0]=0%
	* Read/Write: RW
	* Bits: [30:28]
	* ResetValue: 0b000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlCpIoffsetSetSpiPllbwCfg3 : 3;        /*## attribute CtlCpIoffsetSetSpiPllbwCfg3 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_cp_ioffset_updn_spi_pllbw_cfg3
	* Description: Direction of the charge pump offset
	* 1 :  Pmos inject current
	* 0 :  Nmos substract current
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlCpIoffsetUpdnSpiPllbwCfg3 : 1;        /*## attribute CtlCpIoffsetUpdnSpiPllbwCfg3 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: ctl_ibias_cp_150u_spi_pllbw_cfg3
	* Description: Program current of the CP
	*
	* This is current that goes into CP, programmable between 0 and ~197u
	* current=ctl_ibias_cp_150u_spi x 3.125u
	* Read/Write: RW
	* Bits: [21:16]
	* ResetValue: 0b110000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIbiasCp150USpiPllbwCfg3 : 6;        /*## attribute CtlIbiasCp150USpiPllbwCfg3 */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 8;        /*## attribute Reserved3 */
	/**
	* BitsName: ctl_cp_slice_en_0_pllbw_cfg3
	* Description: Enable cp slices (one slice is equal to ctl_ibias_cp_150u_spi setting ).. Every bit corresponds to one slice. This is selected when pll_cp_slice_ctrl output is 0.  The value in this field corresponds to the value during the acquisition of the chirp
	* NOTE: reset value pointing to one slice enabled (single one)
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00000001
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlCpSliceEn0PllbwCfg3 : 8;        /*## attribute CtlCpSliceEn0PllbwCfg3 */
}R2M06_CpPllbwCfg3Bits_t;
/**
* R2M06_PllLpfC1PllbwCfg3Bits_t
* RegisterName: PLL_LPF_C1_PLLBW_CFG3
* This register controls LPF C1 (Cap) bank
* Address: 0x0B4
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 16;        /*## attribute Reserved0 */
	/**
	* BitsName: pll_lpf_c1_rst_ctrl_pllbw_cfg3
	* Description: LPF C1 setting during rst (high BW)
	* Read/Write: RW
	* Bits: [15:8]
	* ResetValue: 0b00000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC1RstCtrlPllbwCfg3 : 8;        /*## attribute PllLpfC1RstCtrlPllbwCfg3 */
	/**
	* BitsName: pll_lpf_c1_acq_ctrl_pllbw_cfg3
	* Description: LPF C1 setting during acq (low BW)
	*
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC1AcqCtrlPllbwCfg3 : 8;        /*## attribute PllLpfC1AcqCtrlPllbwCfg3 */
}R2M06_PllLpfC1PllbwCfg3Bits_t;
/**
* R2M06_PllLpfC2PllbwCfg3Bits_t
* RegisterName: PLL_LPF_C2_PLLBW_CFG3
* This register controls LPF C2 (Cap) bank
* Address: 0x0B8
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 16;        /*## attribute Reserved0 */
	/**
	* BitsName: pll_lpf_c2_rst_ctrl_pllbw_cfg3
	* Description: LPF C2 setting during rst (high BW)
	* Read/Write: RW
	* Bits: [15:8]
	* ResetValue: 0b00000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC2RstCtrlPllbwCfg3 : 8;        /*## attribute PllLpfC2RstCtrlPllbwCfg3 */
	/**
	* BitsName: pll_lpf_c2_acq_ctrl_pllbw_cfg3
	* Description: LPF C2 setting during acq (low BW)
	*
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC2AcqCtrlPllbwCfg3 : 8;        /*## attribute PllLpfC2AcqCtrlPllbwCfg3 */
}R2M06_PllLpfC2PllbwCfg3Bits_t;
/**
* R2M06_PllLpfC3PllbwCfg3Bits_t
* RegisterName: PLL_LPF_C3_PLLBW_CFG3
* This register controls LPF C3 (Cap) bank
* Address: 0x0BC
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 16;        /*## attribute Reserved0 */
	/**
	* BitsName: pll_lpf_c3_rst_ctrl_pllbw_cfg3
	* Description: LPF C3 setting during rst (high BW)
	* Read/Write: RW
	* Bits: [15:8]
	* ResetValue: 0b00000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC3RstCtrlPllbwCfg3 : 8;        /*## attribute PllLpfC3RstCtrlPllbwCfg3 */
	/**
	* BitsName: pll_lpf_c3_acq_ctrl_pllbw_cfg3
	* Description: LPF C3 setting during acq (low BW)
	*
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC3AcqCtrlPllbwCfg3 : 8;        /*## attribute PllLpfC3AcqCtrlPllbwCfg3 */
}R2M06_PllLpfC3PllbwCfg3Bits_t;
/**
* R2M06_PllLpfResPllbwCfg3Bits_t
* RegisterName: PLL_LPF_RES_PLLBW_CFG3
* settings for FILTER
* Address: 0x0C0
* ResetValue: 0x00001616
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 19;        /*## attribute Reserved0 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 5;        /*## attribute Reserved1 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: ctl_lpf_r1_spi_pllbw_cfg3
	* Description: Select loop filter res. R1
	* Read/Write: RW
	* Bits: [4:0]
	* ResetValue: 0b10110
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlLpfR1SpiPllbwCfg3 : 5;        /*## attribute CtlLpfR1SpiPllbwCfg3 */
}R2M06_PllLpfResPllbwCfg3Bits_t;
/**
* R2M06_CpPllbwCfgHigh1GBits_t
* RegisterName: CP_PLLBW_CFG_HIGH_1G
* Chargepump profile settings. The settings are the same defined for CFG0, CFG1, CFG2, CFG3 except that these values are used to improve the settling time (incase of standby to powerup or huge sub-band jump usecases) with high bandwidth settings and then switch to profile based settings.
* Address: 0x0D0
* ResetValue: 0x003D0001
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_cp_ioffset_set_spi_pllbw_cfg_h_1g
	* Description: charge pump offset, bit wise programming, polarity given by 'ctl_cp_ioffset_updn_spi_profile*':
	* [7]=+35%; [6]=+30% ;[5]=+25%; [4]=+20%; [3]=+15%;[2]=+10%; [1]=+5%; [0]=0%
	* Read/Write: RW
	* Bits: [30:28]
	* ResetValue: 0b000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlCpIoffsetSetSpiPllbwCfgH1G : 3;        /*## attribute CtlCpIoffsetSetSpiPllbwCfgH1G */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_cp_ioffset_updn_spi_pllbw_cfg_h_1g
	* Description: Direction of the charge pump offset
	* 1 :  Pmos inject current
	* 0 :  Nmos substract current
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlCpIoffsetUpdnSpiPllbwCfgH1G : 1;        /*## attribute CtlCpIoffsetUpdnSpiPllbwCfgH1G */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: ctl_ibias_cp_150u_spi_pllbw_cfg_h_1g
	* Description: Program current of the CP
	*
	* This is current that goes into CP, programmable between 0 and ~197u
	* current=ctl_ibias_cp_150u_spi x 3.125u
	* Read/Write: RW
	* Bits: [21:16]
	* ResetValue: 0b111101
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIbiasCp150USpiPllbwCfgH1G : 6;        /*## attribute CtlIbiasCp150USpiPllbwCfgH1G */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 8;        /*## attribute Reserved3 */
	/**
	* BitsName: ctl_cp_slice_en_0_pllbw_cfg_h_1g
	* Description: Enable cp slices (one slice is equal to ctl_ibias_cp_150u_spi setting ).. Every bit corresponds to one slice. This is selected when pll_cp_slice_ctrl output is 0.  The value in this field corresponds to the value during the acquisition of the chirp
	* NOTE: reset value pointing to one slice enabled (single one)
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00000001
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlCpSliceEn0PllbwCfgH1G : 8;        /*## attribute CtlCpSliceEn0PllbwCfgH1G */
}R2M06_CpPllbwCfgHigh1GBits_t;
/**
* R2M06_PllLpfCapPllbwCfgHigh1GBits_t
* RegisterName: PLL_LPF_CAP_PLLBW_CFG_HIGH_1G
* This register controls LPF (Cap) bank. The settings are the same defined for CFG0, CFG1, CFG2, CFG3 except that these values are used to improve the settling time (incase of standby to powerup or huge sub-band jump usecases) with high bandwidth settings and then switch to profile based settings.
* Address: 0x0D4
* ResetValue: 0x00403F12
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 8;        /*## attribute Reserved0 */
	/**
	* BitsName: pll_lpf_c3_high_pllbw_cfg_1g
	* Description: LPF C3 setting for 1GHz(high BW)
	* Read/Write: RW
	* Bits: [23:16]
	* ResetValue: 0b01000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC3HighPllbwCfg1G : 8;        /*## attribute PllLpfC3HighPllbwCfg1G */
	/**
	* BitsName: pll_lpf_c2_high_pllbw_cfg_1g
	* Description: LPF C2 setting for 1GHz(high BW)
	* Read/Write: RW
	* Bits: [15:8]
	* ResetValue: 0b00111111
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC2HighPllbwCfg1G : 8;        /*## attribute PllLpfC2HighPllbwCfg1G */
	/**
	* BitsName: pll_lpf_c1_high_pllbw_cfg_1g
	* Description: LPF C1 setting for 1GHz(high BW)
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00010010
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC1HighPllbwCfg1G : 8;        /*## attribute PllLpfC1HighPllbwCfg1G */
}R2M06_PllLpfCapPllbwCfgHigh1GBits_t;
/**
* R2M06_CpPllbwCfgHigh2GBits_t
* RegisterName: CP_PLLBW_CFG_HIGH_2G
* Chargepump profile settings. The settings are the same defined for CFG0, CFG1, CFG2, CFG3 except that these values are used to improve the settling time (incase of standby to powerup or huge sub-band jump usecases) with high bandwidth settings and then switch to profile based settings.
* Address: 0x0D8
* ResetValue: 0x00190001
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_cp_ioffset_set_spi_pllbw_cfg_h_2g
	* Description: charge pump offset, bit wise programming, polarity given by 'ctl_cp_ioffset_updn_spi_profile*':
	* [7]=+35%; [6]=+30% ;[5]=+25%; [4]=+20%; [3]=+15%;[2]=+10%; [1]=+5%; [0]=0%
	* Read/Write: RW
	* Bits: [30:28]
	* ResetValue: 0b000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlCpIoffsetSetSpiPllbwCfgH2G : 3;        /*## attribute CtlCpIoffsetSetSpiPllbwCfgH2G */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_cp_ioffset_updn_spi_pllbw_cfg_h_2g
	* Description: Direction of the charge pump offset
	* 1 :  Pmos inject current
	* 0 :  Nmos substract current
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlCpIoffsetUpdnSpiPllbwCfgH2G : 1;        /*## attribute CtlCpIoffsetUpdnSpiPllbwCfgH2G */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: ctl_ibias_cp_150u_spi_pllbw_cfg_h_2g
	* Description: Program current of the CP
	*
	* This is current that goes into CP, programmable between 0 and ~197u
	* current=ctl_ibias_cp_150u_spi x 3.125u
	* Read/Write: RW
	* Bits: [21:16]
	* ResetValue: 0b011001
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIbiasCp150USpiPllbwCfgH2G : 6;        /*## attribute CtlIbiasCp150USpiPllbwCfgH2G */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 8;        /*## attribute Reserved3 */
	/**
	* BitsName: ctl_cp_slice_en_0_pllbw_cfg_h_2g
	* Description: Enable cp slices (one slice is equal to ctl_ibias_cp_150u_spi setting ).. Every bit corresponds to one slice. This is selected when pll_cp_slice_ctrl output is 0.  The value in this field corresponds to the value during the acquisition of the chirp
	* NOTE: reset value pointing to one slice enabled (single one)
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00000001
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlCpSliceEn0PllbwCfgH2G : 8;        /*## attribute CtlCpSliceEn0PllbwCfgH2G */
}R2M06_CpPllbwCfgHigh2GBits_t;
/**
* R2M06_PllLpfCapPllbwCfgHigh2GBits_t
* RegisterName: PLL_LPF_CAP_PLLBW_CFG_HIGH_2G
* This register controls LPF (Cap) bank. The settings are the same defined for CFG0, CFG1, CFG2, CFG3 except that these values are used to improve the settling time (incase of standby to powerup or huge sub-band jump usecases) with high bandwidth settings and then switch to profile based settings.
* Address: 0x0DC
* ResetValue: 0x00403F11
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 8;        /*## attribute Reserved0 */
	/**
	* BitsName: pll_lpf_c3_high_pllbw_cfg_2g
	* Description: LPF C3 setting for 2GHz(high BW)
	* Read/Write: RW
	* Bits: [23:16]
	* ResetValue: 0b01000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC3HighPllbwCfg2G : 8;        /*## attribute PllLpfC3HighPllbwCfg2G */
	/**
	* BitsName: pll_lpf_c2_high_pllbw_cfg_2g
	* Description: LPF C2 setting for 2GHz(high BW)
	* Read/Write: RW
	* Bits: [15:8]
	* ResetValue: 0b00111111
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC2HighPllbwCfg2G : 8;        /*## attribute PllLpfC2HighPllbwCfg2G */
	/**
	* BitsName: pll_lpf_c1_high_pllbw_cfg_2g
	* Description: LPF C1 setting for 2GHz(high BW)
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00010001
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC1HighPllbwCfg2G : 8;        /*## attribute PllLpfC1HighPllbwCfg2G */
}R2M06_PllLpfCapPllbwCfgHigh2GBits_t;
/**
* R2M06_CpPllbwCfgHigh4GBits_t
* RegisterName: CP_PLLBW_CFG_HIGH_4G
* Chargepump profile settings. The settings are the same defined for CFG0, CFG1, CFG2, CFG3 except that these values are used to improve the settling time (incase of standby to powerup or huge sub-band jump usecases) with high bandwidth settings and then switch to profile based settings.
* Address: 0x0E0
* ResetValue: 0x00150001
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_cp_ioffset_set_spi_pllbw_cfg_h_4g
	* Description: charge pump offset, bit wise programming, polarity given by 'ctl_cp_ioffset_updn_spi_profile*':
	* [7]=+35%; [6]=+30% ;[5]=+25%; [4]=+20%; [3]=+15%;[2]=+10%; [1]=+5%; [0]=0%
	* Read/Write: RW
	* Bits: [30:28]
	* ResetValue: 0b000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlCpIoffsetSetSpiPllbwCfgH4G : 3;        /*## attribute CtlCpIoffsetSetSpiPllbwCfgH4G */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_cp_ioffset_updn_spi_pllbw_cfg_h_4g
	* Description: Direction of the charge pump offset
	* 1 :  Pmos inject current
	* 0 :  Nmos substract current
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlCpIoffsetUpdnSpiPllbwCfgH4G : 1;        /*## attribute CtlCpIoffsetUpdnSpiPllbwCfgH4G */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: ctl_ibias_cp_150u_spi_pllbw_cfg_h_4g
	* Description: Program current of the CP
	*
	* This is current that goes into CP, programmable between 0 and ~197u
	* current=ctl_ibias_cp_150u_spi x 3.125u
	* Read/Write: RW
	* Bits: [21:16]
	* ResetValue: 0b010101
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIbiasCp150USpiPllbwCfgH4G : 6;        /*## attribute CtlIbiasCp150USpiPllbwCfgH4G */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 8;        /*## attribute Reserved3 */
	/**
	* BitsName: ctl_cp_slice_en_0_pllbw_cfg_h_4g
	* Description: Enable cp slices (one slice is equal to ctl_ibias_cp_150u_spi setting ).. Every bit corresponds to one slice. This is selected when pll_cp_slice_ctrl output is 0.  The value in this field corresponds to the value during the acquisition of the chirp
	* NOTE: reset value pointing to one slice enabled (single one)
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00000001
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlCpSliceEn0PllbwCfgH4G : 8;        /*## attribute CtlCpSliceEn0PllbwCfgH4G */
}R2M06_CpPllbwCfgHigh4GBits_t;
/**
* R2M06_PllLpfCapPllbwCfgHigh4GBits_t
* RegisterName: PLL_LPF_CAP_PLLBW_CFG_HIGH_4G
* This register controls LPF (Cap) bank. The settings are the same defined for CFG0, CFG1, CFG2, CFG3 except that these values are used to improve the settling time (incase of standby to powerup or huge sub-band jump usecases) with high bandwidth settings and then switch to profile based settings.
* Address: 0x0E4
* ResetValue: 0x00413F12
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 8;        /*## attribute Reserved0 */
	/**
	* BitsName: pll_lpf_c3_high_pllbw_cfg_4g
	* Description: LPF C3 setting for 4GHz(high BW)
	* Read/Write: RW
	* Bits: [23:16]
	* ResetValue: 0b01000001
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC3HighPllbwCfg4G : 8;        /*## attribute PllLpfC3HighPllbwCfg4G */
	/**
	* BitsName: pll_lpf_c2_high_pllbw_cfg_4g
	* Description: LPF C2 setting for 4GHz(high BW)
	* Read/Write: RW
	* Bits: [15:8]
	* ResetValue: 0b00111111
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC2HighPllbwCfg4G : 8;        /*## attribute PllLpfC2HighPllbwCfg4G */
	/**
	* BitsName: pll_lpf_c1_high_pllbw_cfg_4g
	* Description: LPF C1 setting for 4GHz(high BW)
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00010010
	* Source: Application
	* FuSa: No
	*/
	uint32_t PllLpfC1HighPllbwCfg4G : 8;        /*## attribute PllLpfC1HighPllbwCfg4G */
}R2M06_PllLpfCapPllbwCfgHigh4GBits_t;
/**
* R2M06_PllLpfResPllbwCfgHighBits_t
* RegisterName: PLL_LPF_RES_PLLBW_CFG_HIGH
* settings for FILTER. The settings are the same defined for CFG0, CFG1, CFG2, CFG3 except that these values are used to improve the settling time (incase of standby to powerup or huge sub-band jump usecases) with high bandwidth settings and then switch to profile based settings.
* Address: 0x0E8
* ResetValue: 0x2B594A52
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 5;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_lpf_r1_spi_pllbw_cfg_h_4g
	* Description: Select loop filter res.R1
	* Read/Write: RW
	* Bits: [24:20]
	* ResetValue: 0b10101
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlLpfR1SpiPllbwCfgH4G : 5;        /*## attribute CtlLpfR1SpiPllbwCfgH4G */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 5;        /*## attribute Reserved2 */
	/**
	* BitsName: ctl_lpf_r1_spi_pllbw_cfg_h_2g
	* Description: Select loop filter res.R1
	* Read/Write: RW
	* Bits: [14:10]
	* ResetValue: 0b10010
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlLpfR1SpiPllbwCfgH2G : 5;        /*## attribute CtlLpfR1SpiPllbwCfgH2G */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 5;        /*## attribute Reserved3 */
	/**
	* BitsName: ctl_lpf_r1_spi_pllbw_cfg_h_1g
	* Description: Select loop filter res. R1
	* Read/Write: RW
	* Bits: [4:0]
	* ResetValue: 0b10010
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlLpfR1SpiPllbwCfgH1G : 5;        /*## attribute CtlLpfR1SpiPllbwCfgH1G */
}R2M06_PllLpfResPllbwCfgHighBits_t;
/**
* R2M06_VcoRegProfile0Bits_t
* RegisterName: VCO_REG_PROFILE0
* Vco control settings
* Address: 0x100
* ResetValue: 0x000F0000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_vco_coarse_tuning_fast_bias_en_spi_profile0
	* Description: 0 -long time constant on coarse tuning settling  for normal operation
	* 1- short time constant coarse tuning settling (automatically used inside design during AAFC and subband switching)
	*
	* Note: ctl_vco_coarse_tuning_fast_bias_en_spi_override option is provided to overrule based on the validation results
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoCoarseTuningFastBiasEnSpiProfile0 : 1;        /*## attribute CtlVcoCoarseTuningFastBiasEnSpiProfile0 */
	/**
	* BitsName: pllbw_cfg_selection_profile0
	* Description: These bits select the register settings required for the PLLBW. Based on the selection, the settings from the following registers are applied.
	*
	* CP_REG_PLLBW_CFG*, PLL_LPF_C1_PLLBW_CFG*, PLL_LPF_C2_PLLBW_CFG*,
	*
	* x00: PLLBW_CFG0 related settings are applied
	* x01: PLLBW_CFG1 related settings are applied
	* x10: PLLBW_CFG2 related settings are applied
	* x11: PLLBW_CFG3 related settings are applied
	*
	*
	* Read/Write: RW
	* Bits: [27:25]
	* ResetValue: 0b000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t PllbwCfgSelectionProfile0 : 3;        /*## attribute PllbwCfgSelectionProfile0 */
	/**
	* BitsName: ctl_vco_bandwidth_spi_profile0
	* Description: Select VCO bandwidth:
	* 0: narrow bandwidth (2 GHz)
	* 1: large bandwidth (4 GHz)
	*
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoBandwidthSpiProfile0 : 1;        /*## attribute CtlVcoBandwidthSpiProfile0 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: ctl_vco_ivco_fine_spi_profile0
	* Description: Select current VCO
	* Read/Write: RW
	* Bits: [21:16]
	* ResetValue: 0b001111
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoIvcoFineSpiProfile0 : 6;        /*## attribute CtlVcoIvcoFineSpiProfile0 */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 9;        /*## attribute Reserved3 */
	/**
	* BitsName: ctl_vco_coarse_tuning_9g_spi_profile0
	* Description: Select sub-band for 9 GHz coarse bank.
	*
	* 1g : [6:0] is used
	* 4g : [5:0] is used and MSB is not used
	* Read/Write: RW
	* Bits: [6:0]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoCoarseTuning9GSpiProfile0 : 7;        /*## attribute CtlVcoCoarseTuning9GSpiProfile0 */
}R2M06_VcoRegProfile0Bits_t;
/**
* R2M06_LpfInjAcqRstProfile0Bits_t
* RegisterName: LPF_INJ_ACQ_RST_PROFILE0
* This register controls the LPF injection current during Acquisition
* Address: 0x104
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_idac_inj_rst_c3_spi_profile0
	* Description: Injection current for reset. Sink Level control for LPF C3 bank
	* Read/Write: RW
	* Bits: [29:28]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC3SpiProfile0 : 2;        /*## attribute CtlIdacInjRstC3SpiProfile0 */
	/**
	* BitsName: ctl_idac_inj_rst_c2_spi_profile0
	* Description: Injection current for reset. Sink Level control for LPF C2 bank
	* Read/Write: RW
	* Bits: [27:23]
	* ResetValue: 0b00000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC2SpiProfile0 : 5;        /*## attribute CtlIdacInjRstC2SpiProfile0 */
	/**
	* BitsName: ctl_idac_inj_rst_c1_spi_profile0
	* Description: Injection current for reset. Sink Level control for LPF C1 bank
	* Read/Write: RW
	* Bits: [22:16]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC1SpiProfile0 : 7;        /*## attribute CtlIdacInjRstC1SpiProfile0 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_idac_inj_acq_c3_spi_profile0
	* Description: Injection current for acquisition. Source Level control for LPF C3 bank
	* Read/Write: RW
	* Bits: [13:12]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC3SpiProfile0 : 2;        /*## attribute CtlIdacInjAcqC3SpiProfile0 */
	/**
	* BitsName: ctl_idac_inj_acq_c2_spi_profile0
	* Description: Injection current for acquisition. Source Level control for LPF C2 bank
	* Read/Write: RW
	* Bits: [11:7]
	* ResetValue: 0b00000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC2SpiProfile0 : 5;        /*## attribute CtlIdacInjAcqC2SpiProfile0 */
	/**
	* BitsName: ctl_idac_inj_acq_c1_spi_profile0
	* Description: Injection current for acquisition. Source Level control for LPF C1 bank
	* Read/Write: RW
	* Bits: [6:0]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC1SpiProfile0 : 7;        /*## attribute CtlIdacInjAcqC1SpiProfile0 */
}R2M06_LpfInjAcqRstProfile0Bits_t;
/**
* R2M06_VcoRegProfile1Bits_t
* RegisterName: VCO_REG_PROFILE1
* Vco control settings
* Address: 0x110
* ResetValue: 0x000F0000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_vco_coarse_tuning_fast_bias_en_spi_profile1
	* Description: 0 -long time constant on coarse tuning settling  for normal operation
	* 1- short time constant coarse tuning settling (automatically used inside design during AAFC and subband switching)
	*
	* Note: ctl_vco_coarse_tuning_fast_bias_en_spi_override option is provided to overrule based on the validation results
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoCoarseTuningFastBiasEnSpiProfile1 : 1;        /*## attribute CtlVcoCoarseTuningFastBiasEnSpiProfile1 */
	/**
	* BitsName: pllbw_cfg_selection_profile1
	* Description: These bits select the register settings required for the PLLBW. Based on the selection, the settings from the following registers are applied.
	*
	* CP_REG_PLLBW_CFG*, PLL_LPF_C1_PLLBW_CFG*, PLL_LPF_C2_PLLBW_CFG*,
	*
	* x00: PLLBW_CFG0 related settings are applied
	* x01: PLLBW_CFG1 related settings are applied
	* x10: PLLBW_CFG2 related settings are applied
	* x11: PLLBW_CFG3 related settings are applied
	*
	* Read/Write: RW
	* Bits: [27:25]
	* ResetValue: 0b000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t PllbwCfgSelectionProfile1 : 3;        /*## attribute PllbwCfgSelectionProfile1 */
	/**
	* BitsName: ctl_vco_bandwidth_spi_profile1
	* Description: Select VCO bandwidth:
	* 0: narrow bandwidth (2 GHz)
	* 1: large bandwidth (4 GHz)
	*
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoBandwidthSpiProfile1 : 1;        /*## attribute CtlVcoBandwidthSpiProfile1 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: ctl_vco_ivco_fine_spi_profile1
	* Description: Select current VCO
	* Read/Write: RW
	* Bits: [21:16]
	* ResetValue: 0b001111
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoIvcoFineSpiProfile1 : 6;        /*## attribute CtlVcoIvcoFineSpiProfile1 */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 9;        /*## attribute Reserved3 */
	/**
	* BitsName: ctl_vco_coarse_tuning_9g_spi_profile1
	* Description: Select sub-band for 9 GHz coarse bank.
	*
	* 1g : [6:0] is used
	* 5g : [5:0] is used and MSB is not used
	* Read/Write: RW
	* Bits: [6:0]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoCoarseTuning9GSpiProfile1 : 7;        /*## attribute CtlVcoCoarseTuning9GSpiProfile1 */
}R2M06_VcoRegProfile1Bits_t;
/**
* R2M06_LpfInjAcqRstProfile1Bits_t
* RegisterName: LPF_INJ_ACQ_RST_PROFILE1
* This register controls the LPF injection current during Acquisition
* Address: 0x114
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_idac_inj_rst_c3_spi_profile1
	* Description: Injection current for reset. Sink Level control for LPF C3 bank
	* Read/Write: RW
	* Bits: [29:28]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC3SpiProfile1 : 2;        /*## attribute CtlIdacInjRstC3SpiProfile1 */
	/**
	* BitsName: ctl_idac_inj_rst_c2_spi_profile1
	* Description: Injection current for reset. Sink Level control for LPF C2 bank
	* Read/Write: RW
	* Bits: [27:23]
	* ResetValue: 0b00000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC2SpiProfile1 : 5;        /*## attribute CtlIdacInjRstC2SpiProfile1 */
	/**
	* BitsName: ctl_idac_inj_rst_c1_spi_profile1
	* Description: Injection current for reset. Sink Level control for LPF C1 bank
	* Read/Write: RW
	* Bits: [22:16]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC1SpiProfile1 : 7;        /*## attribute CtlIdacInjRstC1SpiProfile1 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_idac_inj_acq_c3_spi_profile1
	* Description: Injection current for acquisition. Source Level control for LPF C3 bank
	* Read/Write: RW
	* Bits: [13:12]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC3SpiProfile1 : 2;        /*## attribute CtlIdacInjAcqC3SpiProfile1 */
	/**
	* BitsName: ctl_idac_inj_acq_c2_spi_profile1
	* Description: Injection current for acquisition. Source Level control for LPF C2 bank
	* Read/Write: RW
	* Bits: [11:7]
	* ResetValue: 0b00000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC2SpiProfile1 : 5;        /*## attribute CtlIdacInjAcqC2SpiProfile1 */
	/**
	* BitsName: ctl_idac_inj_acq_c1_spi_profile1
	* Description: Injection current for acquisition. Source Level control for LPF C1 bank
	* Read/Write: RW
	* Bits: [6:0]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC1SpiProfile1 : 7;        /*## attribute CtlIdacInjAcqC1SpiProfile1 */
}R2M06_LpfInjAcqRstProfile1Bits_t;
/**
* R2M06_VcoRegProfile2Bits_t
* RegisterName: VCO_REG_PROFILE2
* Vco control settings
* Address: 0x120
* ResetValue: 0x000F0000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_vco_coarse_tuning_fast_bias_en_spi_profile2
	* Description: 0 -long time constant on coarse tuning settling  for normal operation
	* 1- short time constant coarse tuning settling (automatically used inside design during AAFC and subband switching)
	*
	* Note: ctl_vco_coarse_tuning_fast_bias_en_spi_override option is provided to overrule based on the validation results
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoCoarseTuningFastBiasEnSpiProfile2 : 1;        /*## attribute CtlVcoCoarseTuningFastBiasEnSpiProfile2 */
	/**
	* BitsName: pllbw_cfg_selection_profile2
	* Description: These bits select the register settings required for the PLLBW. Based on the selection, the settings from the following registers are applied.
	*
	* CP_REG_PLLBW_CFG*, PLL_LPF_C1_PLLBW_CFG*, PLL_LPF_C2_PLLBW_CFG*,
	*
	*
	*
	* x00: PLLBW_CFG0 related settings are applied
	* x01: PLLBW_CFG1 related settings are applied
	* x10: PLLBW_CFG2 related settings are applied
	* x11: PLLBW_CFG3 related settings are applied
	*
	*
	* Read/Write: RW
	* Bits: [27:25]
	* ResetValue: 0b000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t PllbwCfgSelectionProfile2 : 3;        /*## attribute PllbwCfgSelectionProfile2 */
	/**
	* BitsName: ctl_vco_bandwidth_spi_profile2
	* Description: Select VCO bandwidth:
	* 0: narrow bandwidth (2 GHz)
	* 1: large bandwidth (4 GHz)
	*
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoBandwidthSpiProfile2 : 1;        /*## attribute CtlVcoBandwidthSpiProfile2 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: ctl_vco_ivco_fine_spi_profile2
	* Description: Select current VCO
	* Read/Write: RW
	* Bits: [21:16]
	* ResetValue: 0b001111
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoIvcoFineSpiProfile2 : 6;        /*## attribute CtlVcoIvcoFineSpiProfile2 */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 9;        /*## attribute Reserved3 */
	/**
	* BitsName: ctl_vco_coarse_tuning_9g_spi_profile2
	* Description: Select sub-band for 9 GHz coarse bank.
	*
	* 1g : [6:0] is used
	* 5g : [5:0] is used and MSB is not used
	* Read/Write: RW
	* Bits: [6:0]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoCoarseTuning9GSpiProfile2 : 7;        /*## attribute CtlVcoCoarseTuning9GSpiProfile2 */
}R2M06_VcoRegProfile2Bits_t;
/**
* R2M06_LpfInjAcqRstProfile2Bits_t
* RegisterName: LPF_INJ_ACQ_RST_PROFILE2
* This register controls the LPF injection current during Acquisition
* Address: 0x124
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_idac_inj_rst_c3_spi_profile2
	* Description: Injection current for reset. Sink Level control for LPF C3 bank
	* Read/Write: RW
	* Bits: [29:28]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC3SpiProfile2 : 2;        /*## attribute CtlIdacInjRstC3SpiProfile2 */
	/**
	* BitsName: ctl_idac_inj_rst_c2_spi_profile2
	* Description: Injection current for reset. Sink Level control for LPF C2 bank
	* Read/Write: RW
	* Bits: [27:23]
	* ResetValue: 0b00000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC2SpiProfile2 : 5;        /*## attribute CtlIdacInjRstC2SpiProfile2 */
	/**
	* BitsName: ctl_idac_inj_rst_c1_spi_profile2
	* Description: Injection current for reset. Sink Level control for LPF C1 bank
	* Read/Write: RW
	* Bits: [22:16]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC1SpiProfile2 : 7;        /*## attribute CtlIdacInjRstC1SpiProfile2 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_idac_inj_acq_c3_spi_profile2
	* Description: Injection current for acquisition. Source Level control for LPF C3 bank
	* Read/Write: RW
	* Bits: [13:12]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC3SpiProfile2 : 2;        /*## attribute CtlIdacInjAcqC3SpiProfile2 */
	/**
	* BitsName: ctl_idac_inj_acq_c2_spi_profile2
	* Description: Injection current for acquisition. Source Level control for LPF C2 bank
	* Read/Write: RW
	* Bits: [11:7]
	* ResetValue: 0b00000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC2SpiProfile2 : 5;        /*## attribute CtlIdacInjAcqC2SpiProfile2 */
	/**
	* BitsName: ctl_idac_inj_acq_c1_spi_profile2
	* Description: Injection current for acquisition. Source Level control for LPF C1 bank
	* Read/Write: RW
	* Bits: [6:0]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC1SpiProfile2 : 7;        /*## attribute CtlIdacInjAcqC1SpiProfile2 */
}R2M06_LpfInjAcqRstProfile2Bits_t;
/**
* R2M06_VcoRegProfile3Bits_t
* RegisterName: VCO_REG_PROFILE3
* Vco control settings
* Address: 0x130
* ResetValue: 0x000F0000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_vco_coarse_tuning_fast_bias_en_spi_profile3
	* Description: 0 -long time constant on coarse tuning settling  for normal operation
	* 1- short time constant coarse tuning settling (automatically used inside design during AAFC and subband switching)
	*
	* Note: ctl_vco_coarse_tuning_fast_bias_en_spi_override option is provided to overrule based on the validation results
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoCoarseTuningFastBiasEnSpiProfile3 : 1;        /*## attribute CtlVcoCoarseTuningFastBiasEnSpiProfile3 */
	/**
	* BitsName: pllbw_cfg_selection_profile3
	* Description: These bits select the register settings required for the PLLBW. Based on the selection, the settings from the following registers are applied.
	*
	* CP_REG_PLLBW_CFG*, PLL_LPF_C1_PLLBW_CFG*, PLL_LPF_C2_PLLBW_CFG*,
	*
	* x00: PLLBW_CFG0 related settings are applied
	* x01: PLLBW_CFG1 related settings are applied
	* x10: PLLBW_CFG2 related settings are applied
	* x11: PLLBW_CFG3 related settings are applied
	*
	*
	* Read/Write: RW
	* Bits: [27:25]
	* ResetValue: 0b000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t PllbwCfgSelectionProfile3 : 3;        /*## attribute PllbwCfgSelectionProfile3 */
	/**
	* BitsName: ctl_vco_bandwidth_spi_profile3
	* Description: Select VCO bandwidth:
	* 0: narrow bandwidth (2 GHz)
	* 1: large bandwidth (4 GHz)
	*
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoBandwidthSpiProfile3 : 1;        /*## attribute CtlVcoBandwidthSpiProfile3 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: ctl_vco_ivco_fine_spi_profile3
	* Description: Select current VCO
	* Read/Write: RW
	* Bits: [21:16]
	* ResetValue: 0b001111
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoIvcoFineSpiProfile3 : 6;        /*## attribute CtlVcoIvcoFineSpiProfile3 */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 9;        /*## attribute Reserved3 */
	/**
	* BitsName: ctl_vco_coarse_tuning_9g_spi_profile3
	* Description: Select sub-band for 9 GHz coarse bank.
	*
	* 1g : [6:0] is used
	* 5g : [5:0] is used and MSB is not used
	* Read/Write: RW
	* Bits: [6:0]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoCoarseTuning9GSpiProfile3 : 7;        /*## attribute CtlVcoCoarseTuning9GSpiProfile3 */
}R2M06_VcoRegProfile3Bits_t;
/**
* R2M06_LpfInjAcqRstProfile3Bits_t
* RegisterName: LPF_INJ_ACQ_RST_PROFILE3
* This register controls the LPF injection current during Acquisition
* Address: 0x134
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_idac_inj_rst_c3_spi_profile3
	* Description: Injection current for reset. Sink Level control for LPF C3 bank
	* Read/Write: RW
	* Bits: [29:28]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC3SpiProfile3 : 2;        /*## attribute CtlIdacInjRstC3SpiProfile3 */
	/**
	* BitsName: ctl_idac_inj_rst_c2_spi_profile3
	* Description: Injection current for reset. Sink Level control for LPF C2 bank
	* Read/Write: RW
	* Bits: [27:23]
	* ResetValue: 0b00000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC2SpiProfile3 : 5;        /*## attribute CtlIdacInjRstC2SpiProfile3 */
	/**
	* BitsName: ctl_idac_inj_rst_c1_spi_profile3
	* Description: Injection current for reset. Sink Level control for LPF C1 bank
	* Read/Write: RW
	* Bits: [22:16]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC1SpiProfile3 : 7;        /*## attribute CtlIdacInjRstC1SpiProfile3 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_idac_inj_acq_c3_spi_profile3
	* Description: Injection current for acquisition. Source Level control for LPF C3 bank
	* Read/Write: RW
	* Bits: [13:12]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC3SpiProfile3 : 2;        /*## attribute CtlIdacInjAcqC3SpiProfile3 */
	/**
	* BitsName: ctl_idac_inj_acq_c2_spi_profile3
	* Description: Injection current for acquisition. Source Level control for LPF C2 bank
	* Read/Write: RW
	* Bits: [11:7]
	* ResetValue: 0b00000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC2SpiProfile3 : 5;        /*## attribute CtlIdacInjAcqC2SpiProfile3 */
	/**
	* BitsName: ctl_idac_inj_acq_c1_spi_profile3
	* Description: Injection current for acquisition. Source Level control for LPF C1 bank
	* Read/Write: RW
	* Bits: [6:0]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC1SpiProfile3 : 7;        /*## attribute CtlIdacInjAcqC1SpiProfile3 */
}R2M06_LpfInjAcqRstProfile3Bits_t;
/**
* R2M06_VcoRegProfile4Bits_t
* RegisterName: VCO_REG_PROFILE4
* Vco control settings
* Address: 0x140
* ResetValue: 0x000F0000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_vco_coarse_tuning_fast_bias_en_spi_profile4
	* Description: 0 -long time constant on coarse tuning settling  for normal operation
	* 1- short time constant coarse tuning settling (automatically used inside design during AAFC and subband switching)
	*
	* Note: ctl_vco_coarse_tuning_fast_bias_en_spi_override option is provided to overrule based on the validation results
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoCoarseTuningFastBiasEnSpiProfile4 : 1;        /*## attribute CtlVcoCoarseTuningFastBiasEnSpiProfile4 */
	/**
	* BitsName: pllbw_cfg_selection_profile4
	* Description: These bits select the register settings required for the PLLBW. Based on the selection, the settings from the following registers are applied.
	*
	* CP_REG_PLLBW_CFG*, PLL_LPF_C1_PLLBW_CFG*, PLL_LPF_C2_PLLBW_CFG*,
	*
	*
	*
	* x00: PLLBW_CFG0 related settings are applied
	* x01: PLLBW_CFG1 related settings are applied
	* x10: PLLBW_CFG2 related settings are applied
	* x11: PLLBW_CFG3 related settings are applied
	*
	*
	* Read/Write: RW
	* Bits: [27:25]
	* ResetValue: 0b000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t PllbwCfgSelectionProfile4 : 3;        /*## attribute PllbwCfgSelectionProfile4 */
	/**
	* BitsName: ctl_vco_bandwidth_spi_profile4
	* Description: Select VCO bandwidth:
	* 0: narrow bandwidth (2 GHz)
	* 1: large bandwidth (4 GHz)
	*
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoBandwidthSpiProfile4 : 1;        /*## attribute CtlVcoBandwidthSpiProfile4 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: ctl_vco_ivco_fine_spi_profile4
	* Description: Select current VCO
	* Read/Write: RW
	* Bits: [21:16]
	* ResetValue: 0b001111
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoIvcoFineSpiProfile4 : 6;        /*## attribute CtlVcoIvcoFineSpiProfile4 */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 9;        /*## attribute Reserved3 */
	/**
	* BitsName: ctl_vco_coarse_tuning_9g_spi_profile4
	* Description: Select sub-band for 9 GHz coarse bank.
	*
	* 1g : [6:0] is used
	* 5g : [5:0] is used and MSB is not used
	* Read/Write: RW
	* Bits: [6:0]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoCoarseTuning9GSpiProfile4 : 7;        /*## attribute CtlVcoCoarseTuning9GSpiProfile4 */
}R2M06_VcoRegProfile4Bits_t;
/**
* R2M06_LpfInjAcqRstProfile4Bits_t
* RegisterName: LPF_INJ_ACQ_RST_PROFILE4
* This register controls the LPF injection current during Acquisition
* Address: 0x144
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_idac_inj_rst_c3_spi_profile4
	* Description: Injection current for reset. Sink Level control for LPF C3 bank
	* Read/Write: RW
	* Bits: [29:28]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC3SpiProfile4 : 2;        /*## attribute CtlIdacInjRstC3SpiProfile4 */
	/**
	* BitsName: ctl_idac_inj_rst_c2_spi_profile4
	* Description: Injection current for reset. Sink Level control for LPF C2 bank
	* Read/Write: RW
	* Bits: [27:23]
	* ResetValue: 0b00000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC2SpiProfile4 : 5;        /*## attribute CtlIdacInjRstC2SpiProfile4 */
	/**
	* BitsName: ctl_idac_inj_rst_c1_spi_profile4
	* Description: Injection current for reset. Sink Level control for LPF C1 bank
	* Read/Write: RW
	* Bits: [22:16]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC1SpiProfile4 : 7;        /*## attribute CtlIdacInjRstC1SpiProfile4 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_idac_inj_acq_c3_spi_profile4
	* Description: Injection current for acquisition. Source Level control for LPF C3 bank
	* Read/Write: RW
	* Bits: [13:12]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC3SpiProfile4 : 2;        /*## attribute CtlIdacInjAcqC3SpiProfile4 */
	/**
	* BitsName: ctl_idac_inj_acq_c2_spi_profile4
	* Description: Injection current for acquisition. Source Level control for LPF C2 bank
	* Read/Write: RW
	* Bits: [11:7]
	* ResetValue: 0b00000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC2SpiProfile4 : 5;        /*## attribute CtlIdacInjAcqC2SpiProfile4 */
	/**
	* BitsName: ctl_idac_inj_acq_c1_spi_profile4
	* Description: Injection current for acquisition. Source Level control for LPF C1 bank
	* Read/Write: RW
	* Bits: [6:0]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC1SpiProfile4 : 7;        /*## attribute CtlIdacInjAcqC1SpiProfile4 */
}R2M06_LpfInjAcqRstProfile4Bits_t;
/**
* R2M06_VcoRegProfile5Bits_t
* RegisterName: VCO_REG_PROFILE5
* Vco control settings
* Address: 0x150
* ResetValue: 0x000F0000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_vco_coarse_tuning_fast_bias_en_spi_profile5
	* Description: 0 -long time constant on coarse tuning settling  for normal operation
	* 1- short time constant coarse tuning settling (automatically used inside design during AAFC and subband switching)
	*
	* Note: ctl_vco_coarse_tuning_fast_bias_en_spi_override option is provided to overrule based on the validation results
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoCoarseTuningFastBiasEnSpiProfile5 : 1;        /*## attribute CtlVcoCoarseTuningFastBiasEnSpiProfile5 */
	/**
	* BitsName: pllbw_cfg_selection_profile5
	* Description: These bits select the register settings required for the PLLBW. Based on the selection, the settings from the following registers are applied.
	*
	* CP_REG_PLLBW_CFG*, PLL_LPF_C1_PLLBW_CFG*, PLL_LPF_C2_PLLBW_CFG*,
	*
	* x00: PLLBW_CFG0 related settings are applied
	* x01: PLLBW_CFG1 related settings are applied
	* x10: PLLBW_CFG2 related settings are applied
	* x11: PLLBW_CFG3 related settings are applied
	*
	*
	* Read/Write: RW
	* Bits: [27:25]
	* ResetValue: 0b000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t PllbwCfgSelectionProfile5 : 3;        /*## attribute PllbwCfgSelectionProfile5 */
	/**
	* BitsName: ctl_vco_bandwidth_spi_profile5
	* Description: Select VCO bandwidth:
	* 0: narrow bandwidth (2 GHz)
	* 1: large bandwidth (4 GHz)
	*
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoBandwidthSpiProfile5 : 1;        /*## attribute CtlVcoBandwidthSpiProfile5 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: ctl_vco_ivco_fine_spi_profile5
	* Description: Select current VCO
	* Read/Write: RW
	* Bits: [21:16]
	* ResetValue: 0b001111
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoIvcoFineSpiProfile5 : 6;        /*## attribute CtlVcoIvcoFineSpiProfile5 */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 9;        /*## attribute Reserved3 */
	/**
	* BitsName: ctl_vco_coarse_tuning_9g_spi_profile5
	* Description: Select sub-band for 9 GHz coarse bank.
	*
	* 1g : [6:0] is used
	* 5g : [5:0] is used and MSB is not used
	* Read/Write: RW
	* Bits: [6:0]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoCoarseTuning9GSpiProfile5 : 7;        /*## attribute CtlVcoCoarseTuning9GSpiProfile5 */
}R2M06_VcoRegProfile5Bits_t;
/**
* R2M06_LpfInjAcqRstProfile5Bits_t
* RegisterName: LPF_INJ_ACQ_RST_PROFILE5
* This register controls the LPF injection current during Acquisition
* Address: 0x154
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_idac_inj_rst_c3_spi_profile5
	* Description: Injection current for reset. Sink Level control for LPF C3 bank
	* Read/Write: RW
	* Bits: [29:28]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC3SpiProfile5 : 2;        /*## attribute CtlIdacInjRstC3SpiProfile5 */
	/**
	* BitsName: ctl_idac_inj_rst_c2_spi_profile5
	* Description: Injection current for reset. Sink Level control for LPF C2 bank
	* Read/Write: RW
	* Bits: [27:23]
	* ResetValue: 0b00000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC2SpiProfile5 : 5;        /*## attribute CtlIdacInjRstC2SpiProfile5 */
	/**
	* BitsName: ctl_idac_inj_rst_c1_spi_profile5
	* Description: Injection current for reset. Sink Level control for LPF C1 bank
	* Read/Write: RW
	* Bits: [22:16]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC1SpiProfile5 : 7;        /*## attribute CtlIdacInjRstC1SpiProfile5 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_idac_inj_acq_c3_spi_profile5
	* Description: Injection current for acquisition. Source Level control for LPF C3 bank
	* Read/Write: RW
	* Bits: [13:12]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC3SpiProfile5 : 2;        /*## attribute CtlIdacInjAcqC3SpiProfile5 */
	/**
	* BitsName: ctl_idac_inj_acq_c2_spi_profile5
	* Description: Injection current for acquisition. Source Level control for LPF C2 bank
	* Read/Write: RW
	* Bits: [11:7]
	* ResetValue: 0b00000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC2SpiProfile5 : 5;        /*## attribute CtlIdacInjAcqC2SpiProfile5 */
	/**
	* BitsName: ctl_idac_inj_acq_c1_spi_profile5
	* Description: Injection current for acquisition. Source Level control for LPF C1 bank
	* Read/Write: RW
	* Bits: [6:0]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC1SpiProfile5 : 7;        /*## attribute CtlIdacInjAcqC1SpiProfile5 */
}R2M06_LpfInjAcqRstProfile5Bits_t;
/**
* R2M06_VcoRegProfile6Bits_t
* RegisterName: VCO_REG_PROFILE6
* Vco control settings
* Address: 0x160
* ResetValue: 0x000F0000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_vco_coarse_tuning_fast_bias_en_spi_profile6
	* Description: 0 -long time constant on coarse tuning settling  for normal operation
	* 1- short time constant coarse tuning settling (automatically used inside design during AAFC and subband switching)
	*
	* Note: ctl_vco_coarse_tuning_fast_bias_en_spi_override option is provided to overrule based on the validation results
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoCoarseTuningFastBiasEnSpiProfile6 : 1;        /*## attribute CtlVcoCoarseTuningFastBiasEnSpiProfile6 */
	/**
	* BitsName: pllbw_cfg_selection_profile6
	* Description: These bits select the register settings required for the PLLBW. Based on the selection, the settings from the following registers are applied.
	*
	* CP_REG_PLLBW_CFG*, PLL_LPF_C1_PLLBW_CFG*, PLL_LPF_C2_PLLBW_CFG*,
	*
	*
	*
	* x00: PLLBW_CFG0 related settings are applied
	* x01: PLLBW_CFG1 related settings are applied
	* x10: PLLBW_CFG2 related settings are applied
	* x11: PLLBW_CFG3 related settings are applied
	*
	*
	* Read/Write: RW
	* Bits: [27:25]
	* ResetValue: 0b000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t PllbwCfgSelectionProfile6 : 3;        /*## attribute PllbwCfgSelectionProfile6 */
	/**
	* BitsName: ctl_vco_bandwidth_spi_profile6
	* Description: Select VCO bandwidth:
	* 0: narrow bandwidth (2 GHz)
	* 1: large bandwidth (4 GHz)
	*
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoBandwidthSpiProfile6 : 1;        /*## attribute CtlVcoBandwidthSpiProfile6 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: ctl_vco_ivco_fine_spi_profile6
	* Description: Select current VCO
	* Read/Write: RW
	* Bits: [21:16]
	* ResetValue: 0b001111
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoIvcoFineSpiProfile6 : 6;        /*## attribute CtlVcoIvcoFineSpiProfile6 */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 9;        /*## attribute Reserved3 */
	/**
	* BitsName: ctl_vco_coarse_tuning_9g_spi_profile6
	* Description: Select sub-band for 9 GHz coarse bank.
	*
	* 1g : [6:0] is used
	* 5g : [5:0] is used and MSB is not used
	* Read/Write: RW
	* Bits: [6:0]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoCoarseTuning9GSpiProfile6 : 7;        /*## attribute CtlVcoCoarseTuning9GSpiProfile6 */
}R2M06_VcoRegProfile6Bits_t;
/**
* R2M06_LpfInjAcqRstProfile6Bits_t
* RegisterName: LPF_INJ_ACQ_RST_PROFILE6
* This register controls the LPF injection current during Acquisition
* Address: 0x164
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_idac_inj_rst_c3_spi_profile6
	* Description: Injection current for reset. Sink Level control for LPF C3 bank
	* Read/Write: RW
	* Bits: [29:28]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC3SpiProfile6 : 2;        /*## attribute CtlIdacInjRstC3SpiProfile6 */
	/**
	* BitsName: ctl_idac_inj_rst_c2_spi_profile6
	* Description: Injection current for reset. Sink Level control for LPF C2 bank
	* Read/Write: RW
	* Bits: [27:23]
	* ResetValue: 0b00000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC2SpiProfile6 : 5;        /*## attribute CtlIdacInjRstC2SpiProfile6 */
	/**
	* BitsName: ctl_idac_inj_rst_c1_spi_profile6
	* Description: Injection current for reset. Sink Level control for LPF C1 bank
	* Read/Write: RW
	* Bits: [22:16]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC1SpiProfile6 : 7;        /*## attribute CtlIdacInjRstC1SpiProfile6 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_idac_inj_acq_c3_spi_profile6
	* Description: Injection current for acquisition. Source Level control for LPF C3 bank
	* Read/Write: RW
	* Bits: [13:12]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC3SpiProfile6 : 2;        /*## attribute CtlIdacInjAcqC3SpiProfile6 */
	/**
	* BitsName: ctl_idac_inj_acq_c2_spi_profile6
	* Description: Injection current for acquisition. Source Level control for LPF C2 bank
	* Read/Write: RW
	* Bits: [11:7]
	* ResetValue: 0b00000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC2SpiProfile6 : 5;        /*## attribute CtlIdacInjAcqC2SpiProfile6 */
	/**
	* BitsName: ctl_idac_inj_acq_c1_spi_profile6
	* Description: Injection current for acquisition. Source Level control for LPF C1 bank
	* Read/Write: RW
	* Bits: [6:0]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC1SpiProfile6 : 7;        /*## attribute CtlIdacInjAcqC1SpiProfile6 */
}R2M06_LpfInjAcqRstProfile6Bits_t;
/**
* R2M06_VcoRegProfile7Bits_t
* RegisterName: VCO_REG_PROFILE7
* Vco control settings
* Address: 0x170
* ResetValue: 0x000F0000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_vco_coarse_tuning_fast_bias_en_spi_profile7
	* Description: 0 -long time constant on coarse tuning settling  for normal operation
	* 1- short time constant coarse tuning settling (automatically used inside design during AAFC and subband switching)
	*
	* Note: ctl_vco_coarse_tuning_fast_bias_en_spi_override option is provided to overrule based on the validation results
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoCoarseTuningFastBiasEnSpiProfile7 : 1;        /*## attribute CtlVcoCoarseTuningFastBiasEnSpiProfile7 */
	/**
	* BitsName: pllbw_cfg_selection_profile7
	* Description: These bits select the register settings required for the PLLBW. Based on the selection, the settings from the following registers are applied.
	*
	* CP_REG_PLLBW_CFG*, PLL_LPF_C1_PLLBW_CFG*, PLL_LPF_C2_PLLBW_CFG*,
	*
	* x00: PLLBW_CFG0 related settings are applied
	* x01: PLLBW_CFG1 related settings are applied
	* x10: PLLBW_CFG2 related settings are applied
	* x11: PLLBW_CFG3 related settings are applied
	*
	* Read/Write: RW
	* Bits: [27:25]
	* ResetValue: 0b000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t PllbwCfgSelectionProfile7 : 3;        /*## attribute PllbwCfgSelectionProfile7 */
	/**
	* BitsName: ctl_vco_bandwidth_spi_profile7
	* Description: Select VCO bandwidth:
	* 0: narrow bandwidth (2 GHz)
	* 1: large bandwidth (4 GHz)
	*
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoBandwidthSpiProfile7 : 1;        /*## attribute CtlVcoBandwidthSpiProfile7 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: ctl_vco_ivco_fine_spi_profile7
	* Description: Select current VCO
	* Read/Write: RW
	* Bits: [21:16]
	* ResetValue: 0b001111
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoIvcoFineSpiProfile7 : 6;        /*## attribute CtlVcoIvcoFineSpiProfile7 */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 9;        /*## attribute Reserved3 */
	/**
	* BitsName: ctl_vco_coarse_tuning_9g_spi_profile7
	* Description: Select sub-band for 9 GHz coarse bank.
	*
	* 1g : [6:0] is used
	* 5g : [5:0] is used and MSB is not used
	* Read/Write: RW
	* Bits: [6:0]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoCoarseTuning9GSpiProfile7 : 7;        /*## attribute CtlVcoCoarseTuning9GSpiProfile7 */
}R2M06_VcoRegProfile7Bits_t;
/**
* R2M06_LpfInjAcqRstProfile7Bits_t
* RegisterName: LPF_INJ_ACQ_RST_PROFILE7
* This register controls the LPF injection current during Acquisition
* Address: 0x174
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_idac_inj_rst_c3_spi_profile7
	* Description: Injection current for reset. Sink Level control for LPF C3 bank
	* Read/Write: RW
	* Bits: [29:28]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC3SpiProfile7 : 2;        /*## attribute CtlIdacInjRstC3SpiProfile7 */
	/**
	* BitsName: ctl_idac_inj_rst_c2_spi_profile7
	* Description: Injection current for reset. Sink Level control for LPF C2 bank
	* Read/Write: RW
	* Bits: [27:23]
	* ResetValue: 0b00000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC2SpiProfile7 : 5;        /*## attribute CtlIdacInjRstC2SpiProfile7 */
	/**
	* BitsName: ctl_idac_inj_rst_c1_spi_profile7
	* Description: Injection current for reset. Sink Level control for LPF C1 bank
	* Read/Write: RW
	* Bits: [22:16]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC1SpiProfile7 : 7;        /*## attribute CtlIdacInjRstC1SpiProfile7 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_idac_inj_acq_c3_spi_profile7
	* Description: Injection current for acquisition. Source Level control for LPF C3 bank
	* Read/Write: RW
	* Bits: [13:12]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC3SpiProfile7 : 2;        /*## attribute CtlIdacInjAcqC3SpiProfile7 */
	/**
	* BitsName: ctl_idac_inj_acq_c2_spi_profile7
	* Description: Injection current for acquisition. Source Level control for LPF C2 bank
	* Read/Write: RW
	* Bits: [11:7]
	* ResetValue: 0b00000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC2SpiProfile7 : 5;        /*## attribute CtlIdacInjAcqC2SpiProfile7 */
	/**
	* BitsName: ctl_idac_inj_acq_c1_spi_profile7
	* Description: Injection current for acquisition. Source Level control for LPF C1 bank
	* Read/Write: RW
	* Bits: [6:0]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC1SpiProfile7 : 7;        /*## attribute CtlIdacInjAcqC1SpiProfile7 */
}R2M06_LpfInjAcqRstProfile7Bits_t;
/**
* R2M06_VcoRegProfile8Bits_t
* RegisterName: VCO_REG_PROFILE8
* Vco control settings
* Address: 0x180
* ResetValue: 0x000F0000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_vco_coarse_tuning_fast_bias_en_spi_profile8
	* Description: 0 -long time constant on coarse tuning settling  for normal operation
	* 1- short time constant coarse tuning settling (automatically used inside design during AAFC and subband switching)
	*
	* Note: ctl_vco_coarse_tuning_fast_bias_en_spi_override option is provided to overrule based on the validation results
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoCoarseTuningFastBiasEnSpiProfile8 : 1;        /*## attribute CtlVcoCoarseTuningFastBiasEnSpiProfile8 */
	/**
	* BitsName: pllbw_cfg_selection_profile8
	* Description: These bits select the register settings required for the PLLBW. Based on the selection, the settings from the following registers are applied.
	*
	* CP_REG_PLLBW_CFG*, PLL_LPF_C1_PLLBW_CFG*, PLL_LPF_C2_PLLBW_CFG*,
	*
	* x00: PLLBW_CFG0 related settings are applied
	* x01: PLLBW_CFG1 related settings are applied
	* x10: PLLBW_CFG2 related settings are applied
	* x11: PLLBW_CFG3 related settings are applied
	*
	*
	* Read/Write: RW
	* Bits: [27:25]
	* ResetValue: 0b000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t PllbwCfgSelectionProfile8 : 3;        /*## attribute PllbwCfgSelectionProfile8 */
	/**
	* BitsName: ctl_vco_bandwidth_spi_profile8
	* Description: Select VCO bandwidth:
	* 0: narrow bandwidth (2 GHz)
	* 1: large bandwidth (4 GHz)
	*
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoBandwidthSpiProfile8 : 1;        /*## attribute CtlVcoBandwidthSpiProfile8 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: ctl_vco_ivco_fine_spi_profile8
	* Description: Select current VCO
	* Read/Write: RW
	* Bits: [21:16]
	* ResetValue: 0b001111
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoIvcoFineSpiProfile8 : 6;        /*## attribute CtlVcoIvcoFineSpiProfile8 */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 9;        /*## attribute Reserved3 */
	/**
	* BitsName: ctl_vco_coarse_tuning_9g_spi_profile8
	* Description: Select sub-band for 9 GHz coarse bank.
	*
	* 1g : [6:0] is used
	* 5g : [5:0] is used and MSB is not used
	* Read/Write: RW
	* Bits: [6:0]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoCoarseTuning9GSpiProfile8 : 7;        /*## attribute CtlVcoCoarseTuning9GSpiProfile8 */
}R2M06_VcoRegProfile8Bits_t;
/**
* R2M06_LpfInjAcqRstProfile8Bits_t
* RegisterName: LPF_INJ_ACQ_RST_PROFILE8
* This register controls the LPF injection current during Acquisition
* Address: 0x184
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_idac_inj_rst_c3_spi_profile8
	* Description: Injection current for reset. Sink Level control for LPF C3 bank
	* Read/Write: RW
	* Bits: [29:28]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC3SpiProfile8 : 2;        /*## attribute CtlIdacInjRstC3SpiProfile8 */
	/**
	* BitsName: ctl_idac_inj_rst_c2_spi_profile8
	* Description: Injection current for reset. Sink Level control for LPF C2 bank
	* Read/Write: RW
	* Bits: [27:23]
	* ResetValue: 0b00000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC2SpiProfile8 : 5;        /*## attribute CtlIdacInjRstC2SpiProfile8 */
	/**
	* BitsName: ctl_idac_inj_rst_c1_spi_profile8
	* Description: Injection current for reset. Sink Level control for LPF C1 bank
	* Read/Write: RW
	* Bits: [22:16]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC1SpiProfile8 : 7;        /*## attribute CtlIdacInjRstC1SpiProfile8 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_idac_inj_acq_c3_spi_profile8
	* Description: Injection current for acquisition. Source Level control for LPF C3 bank
	* Read/Write: RW
	* Bits: [13:12]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC3SpiProfile8 : 2;        /*## attribute CtlIdacInjAcqC3SpiProfile8 */
	/**
	* BitsName: ctl_idac_inj_acq_c2_spi_profile8
	* Description: Injection current for acquisition. Source Level control for LPF C2 bank
	* Read/Write: RW
	* Bits: [11:7]
	* ResetValue: 0b00000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC2SpiProfile8 : 5;        /*## attribute CtlIdacInjAcqC2SpiProfile8 */
	/**
	* BitsName: ctl_idac_inj_acq_c1_spi_profile8
	* Description: Injection current for acquisition. Source Level control for LPF C1 bank
	* Read/Write: RW
	* Bits: [6:0]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC1SpiProfile8 : 7;        /*## attribute CtlIdacInjAcqC1SpiProfile8 */
}R2M06_LpfInjAcqRstProfile8Bits_t;
/**
* R2M06_LpfInjAcqRstCommonBits_t
* RegisterName: LPF_INJ_ACQ_RST_COMMON
* This register controls the LPF injection current during Reset
* Address: 0x200
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: trigger_to_copy_inj_dac_val
	* Description: Trigger to copy LPF_INJ_ACQ_RST_COMMON register settings to LPF_INJ_ACQ_RST_PROFILE* registers based on the 'store_in_profile*' bits enabled in CHIRP_CALIBRATION_SW_CONTROL register. This bit will be triggered through SPI after computing the idac_injection acquisition and reset C1, C2 & C3 parameters from KVCO_AVG and DVDT on the fly count status and after writing the computed values to LPF_INJ_ACQ_RST_COMMON register through SPI.
	*
	* This is an auto clear bit.
	*
	* Note :  Based on this trigger since the hardware internally updates the profile register settings, it will also trigger the CRC calculation for the new register values in the profile registers.
	* Read/Write: W
	* Bits: [31]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t TriggerToCopyInjDacVal : 1;        /*## attribute TriggerToCopyInjDacVal */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_idac_inj_rst_c3_spi_common
	* Description: Injection current for reset. Sink Level control for LPF C3 bank
	* Read/Write: RW
	* Bits: [29:28]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC3SpiCommon : 2;        /*## attribute CtlIdacInjRstC3SpiCommon */
	/**
	* BitsName: ctl_idac_inj_rst_c2_spi_common
	* Description: Injection current for reset. Sink Level control for LPF C2 bank
	* Read/Write: RW
	* Bits: [27:23]
	* ResetValue: 0b00000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC2SpiCommon : 5;        /*## attribute CtlIdacInjRstC2SpiCommon */
	/**
	* BitsName: ctl_idac_inj_rst_c1_spi_common
	* Description: Injection current for reset. Sink Level control for LPF C1 bank
	* Read/Write: RW
	* Bits: [22:16]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjRstC1SpiCommon : 7;        /*## attribute CtlIdacInjRstC1SpiCommon */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_idac_inj_acq_c3_spi_common
	* Description: Injection current for acquisition. Source Level control for LPF C3 bank
	* Read/Write: RW
	* Bits: [13:12]
	* ResetValue: 0b00
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC3SpiCommon : 2;        /*## attribute CtlIdacInjAcqC3SpiCommon */
	/**
	* BitsName: ctl_idac_inj_acq_c2_spi_common
	* Description: Injection current for acquisition. Source Level control for LPF C2 bank
	* Read/Write: RW
	* Bits: [11:7]
	* ResetValue: 0b00000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC2SpiCommon : 5;        /*## attribute CtlIdacInjAcqC2SpiCommon */
	/**
	* BitsName: ctl_idac_inj_acq_c1_spi_common
	* Description: Injection current for acquisition. Source Level control for LPF C1 bank
	* Read/Write: RW
	* Bits: [6:0]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIdacInjAcqC1SpiCommon : 7;        /*## attribute CtlIdacInjAcqC1SpiCommon */
}R2M06_LpfInjAcqRstCommonBits_t;
/**
* R2M06_ChirpCalibrationAacControl1Bits_t
* RegisterName: CHIRP_CALIBRATION_AAC_CONTROL1
* Automatic amplitude calibration settings
*
* Address: 0x220
* ResetValue: 0x0023350A
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 10;        /*## attribute Reserved0 */
	/**
	* BitsName: aac_ades_in
	* Description: amplitude control desired value
	*
	* desired amplitude = 10^(((level_lo_max_spi - 63)*0.29)/20)*0.9 = 109.8mV * pow(10,((0.29/20*aac_ades_in))
	* Read/Write: RW
	* Bits: [21:16]
	* ResetValue: 0b100011
	* Source: Application
	* FuSa: No
	*/
	uint32_t AacAdesIn : 6;        /*## attribute AacAdesIn */
	/**
	* BitsName: aac_ictrl_init_override
	* Description: override the Initial value for VCO current with 'aac_ictrl_init_override' value programmed
	* Read/Write: RW
	* Bits: [15]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t AacIctrlInitOverride : 1;        /*## attribute AacIctrlInitOverride */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: aac_ictrl_init_override_value
	* Description: Initial value for VCO current with override option
	* Read/Write: RW
	* Bits: [13:8]
	* ResetValue: 0b110101
	* Source: Application
	* FuSa: No
	*/
	uint32_t AacIctrlInitOverrideValue : 6;        /*## attribute AacIctrlInitOverrideValue */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: aac_ictrl_min
	* Description: Minimum value for VCO current
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b001010
	* Source: Application
	* FuSa: No
	*/
	uint32_t AacIctrlMin : 6;        /*## attribute AacIctrlMin */
}R2M06_ChirpCalibrationAacControl1Bits_t;
/**
* R2M06_ChirpCalibrationAacControl2Bits_t
* RegisterName: CHIRP_CALIBRATION_AAC_CONTROL2
* Automatic amplitude calibration settings
*
* Address: 0x224
* ResetValue: 0x00034007
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 13;        /*## attribute Reserved0 */
	/**
	* BitsName: aac_fref_sel
	* Description: One cycle of amplitude increment/decrement time with analog response. This is represented by fref_aac. Note: 1 us is the minimal response time from analog for any amplitude change. The values other than specified here are possible but these are optimal settings considering the calibration time
	*
	* Fref_aac=Txo*N_aac, Note: Txo = 25ns
	*
	* Aac_fref_sel = 0 => Number of vco divided clock counted in 40MHz = 8, Amplitude loop iteration time represented in real time =  0.2 us
	* Aac_fref_sel = 1 => Number of vco divided clock counted in 40mHz = 16, Amplitude loop iteration time represented in real time = 0.4 us
	* Aac_fref_sel = 2 => Number of vco divided clock counted in 40mHz = 32, Amplitude loop iteration time represented in real time = 0.8 us
	* Aac_fref_sel = 3 => Number of vco divided clock counted in 40mHz = 64, Amplitude loop iteration time represented in real time = 1.6 us
	* Aac_fref_sel = 4 => Number of vco divided clock counted in 40mHz = 128	, Amplitude loop iteration time represented in real time = 3.2 us
	* Aac_fref_sel = 5 => Number of vco divided clock counted in 40mHz = 256	, Amplitude loop iteration time represented in real time = 6.4 us
	*
	*
	*
	*
	* Note: Please note the optimal value for Aac_fref_sel = 3
	*
	*
	* Read/Write: RW
	* Bits: [18:16]
	* ResetValue: 0b011
	* Source: Application
	* FuSa: No
	*/
	uint32_t AacFrefSel : 3;        /*## attribute AacFrefSel */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: aac_ki
	* Description: amplitude control loop gain (aac_Ki) value
	*
	* Lowering the aac_ki will speed down the settling time of the AAC-loop.
	* too_large amplitude of vco determines +1 or -1 times the ki-gain (aac_ki) of the integrator (aac_sum)
	* When aac_ki is equal to 7 (max-value), then the AAC-loop_gain will be 1
	* When aac_ki is equal to 6, then the actual AAC-loop_gain will be 1/2
	* When aac_ki is equal to 5, then the actual AAC-loop_gain will be 1/4
	* When aac_ki is equal to 4, then the actual AAC-loop_gain will be 1/8
	* When aac_ki is equal to 3, then the actual AAC-loop_gain will be 1/16
	* aac_ki=2 or 1 or 0 not used
	* Note: Please note the optimal of aac_ki=7 i.e loop gain of 1
	* Read/Write: RW
	* Bits: [14:12]
	* ResetValue: 0b100
	* Source: Application
	* FuSa: No
	*/
	uint32_t AacKi : 3;        /*## attribute AacKi */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 9;        /*## attribute Reserved2 */
	/**
	* BitsName: aac_lock_ctrl
	* Description: Amplitude loop lock control criteria
	* This control decides the number of stable amplitude iterations to generate the final aac_lock.
	* The vco_amplitude is equal to desired value, then the stable_flag =1. Number of such adjacent stable flag condition is defined by this control.
	*
	* aac_lock_control=0 => Number of consecutive stable states check = 4
	* aac_lock_control=1 => Number of consecutive stable states check = 6
	* aac_lock_control=2 => Number of consecutive stable states check = 8
	* aac_lock_control=3 => Number of consecutive stable states check = 10
	* aac_lock_control=4 => Number of consecutive stable states check = 12
	* aac_lock_control=5 => Number of consecutive stable states check = 14
	* aac_lock_control=6 => Number of consecutive stable states check = 16
	* aac_lock_control=7 => Number of consecutive stable states check = 18
	*
	*
	* Note: The optimal value for aac_lock_control = 7
	*
	*
	* Read/Write: RW
	* Bits: [2:0]
	* ResetValue: 0b111
	* Source: Application
	* FuSa: No
	*/
	uint32_t AacLockCtrl : 3;        /*## attribute AacLockCtrl */
}R2M06_ChirpCalibrationAacControl2Bits_t;
/**
* R2M06_ChirpCalibrationAfcControl1Bits_t
* RegisterName: CHIRP_CALIBRATION_AFC_CONTROL1
* Automatic frequency calibration settings1
*
*
* Address: 0x228
* ResetValue: 0x05104000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 4;        /*## attribute Reserved0 */
	/**
	* BitsName: afc_mdes
	* Description: frequency loop desired Mvalue.
	* Desired Mvalue is the number of clock cycles of vco divide frequency counted for a reference duration for a given start frequency
	* Afc_mdes = (Start_freq * TFref_afc) / Divider_value
	* Note: Divider_value = 3*2*N, Where N is the ctl_div_force  subfield of DIVIDE_FORCE_REGISTER = 32. TFref_afc is the time selected in the afc_fref_sel in the CHIRP_CALIBRATION_AFC_CONTROL2 register
	*
	* Note: Incase of HW based mdes calculation, the value is always DIVIDE_FORCE_REGISTER = 32. For SW based mdes calculation, this is programmable in the register. But default value is recommended
	*
	* Read/Write: RW
	* Bits: [27:16]
	* ResetValue: 0b010100010000
	* Source: Application
	* FuSa: No
	*/
	uint32_t AfcMdes : 12;        /*## attribute AfcMdes */
	/**
	* BitsName: afc_fsel_init_override
	* Description: override the Initial value for the sub-band with 'afc_fsel_init_override_value' programmed
	* Read/Write: RW
	* Bits: [15]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t AfcFselInitOverride : 1;        /*## attribute AfcFselInitOverride */
	/**
	* BitsName: afc_fsel_init_override_value
	* Description: Initial value for the sub-band 1g/2g.
	* For 5g mode, this value should be 'd32
	*
	*
	* Read/Write: RW
	* Bits: [14:8]
	* ResetValue: 0b1000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t AfcFselInitOverrideValue : 7;        /*## attribute AfcFselInitOverrideValue */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: afc_fsel_min
	* Description: Minimal value of the sub-band
	* Read/Write: RW
	* Bits: [6:0]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t AfcFselMin : 7;        /*## attribute AfcFselMin */
}R2M06_ChirpCalibrationAfcControl1Bits_t;
/**
* R2M06_ChirpCalibrationAfcControl2Bits_t
* RegisterName: CHIRP_CALIBRATION_AFC_CONTROL2
* Automatic frequency calibration settings2
*
* Address: 0x22C
* ResetValue: 0x00667372
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 8;        /*## attribute Reserved0 */
	/**
	* BitsName: afc_fref_sel
	* Description: The frequency iteration time for each sub-band
	* Fref_afc=Txo*N_afc, Note: Txo = 25ns Note: The values other than specified here are possible but these are optimal settings considering the calibration time
	*
	* afc_fref_sel = 0	=> Number of vco divided clock counted in 40MHz = 2, Frequency loop iteration time represented in real time = 0.05 us
	* afc_fref_sel = 1	=> Number of vco divided clock counted in 40MHz = 4, Frequency loop iteration time represented in real time = 0.1 us
	* afc_fref_sel = 2	=> Number of vco divided clock counted in 40MHz = 8, Frequency loop iteration time represented in real time = 0.2 us
	* afc_fref_sel = 3	=> Number of vco divided clock counted in 40MHz = 16, Frequency loop iteration time represented in real time = 0.4 us
	* afc_fref_sel = 4	=> Number of vco divided clock counted in 40MHz = 32, Frequency loop iteration time represented in real time = 0.8 us
	* afc_fref_sel = 5	=> Number of vco divided clock counted in 40MHz = 64, Frequency loop iteration time represented in real time = 1.6 us
	* afc_fref_sel = 6	=> Number of vco divided clock counted in 40MHz = 128,	 Frequency loop iteration time represented in real time = 3.2 us
	* afc_fref_sel = 7	=> Number of vco divided clock counted in 40MHz = 256, Frequency loop iteration time represented in real time = 6.4 us
	*
	*
	* Note: The optimal value for afc_fref_sel = 6
	*
	*
	*
	*
	*
	*
	* Read/Write: RW
	* Bits: [23:20]
	* ResetValue: 0b0110
	* Source: Application
	* FuSa: No
	*/
	uint32_t AfcFrefSel : 4;        /*## attribute AfcFrefSel */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: afc_ki_ctrl2
	* Description: Frequency control loop gain (afc_Ki) value for the second (Fine) AFC loop
	*
	* Lowering the afc_ki will speed down the settling time of the AFC-loop.
	* The difference between the actual count and the desired value is multiplied by this gain.
	* When afc_ki_ctrl2 is equal to 7 (max-value), then the AFC-loop_gain will be 1/2
	* When afc_ki_ctrl2 is equal to 6, then the actual AFC-loop_gain will be 1/4
	* When afc_ki_ctrl2 is equal to 5, then the actual AFC-loop_gain will be 1/8
	* When afc_ki_ctrl2 is equal to 4, then the actual AFC-loop_gain will be 1/16
	* When afc_ki_ctrl2 is equal to 3, then the actual AFC-loop_gain will be 1/32
	* afc_ki_ctrl2 = 2 or 1 or 0 not used
	*
	* Note1: Set to default (optimal) of afc_ki_ctrl2 = 6 i.e loop gain of 1/4
	* Note2: For 1g/2g mode, afc_ki_ctrl2 = 3'b110 is recommended. But to be validated
	* Note3: For 4g mode, afc_ki_ctrl2 = 3'b101  is recommended. But to be validated
	* Read/Write: RW
	* Bits: [18:16]
	* ResetValue: 0b110
	* Source: Application
	* FuSa: No
	*/
	uint32_t AfcKiCtrl2 : 3;        /*## attribute AfcKiCtrl2 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 1;        /*## attribute Reserved2 */
	/**
	* BitsName: afc_ki_ctrl1
	* Description: Frequency control loop gain (afc_Ki) value for the first (coarse) AFC loop
	*
	* Lowering the afc_ki will speed down the settling time of the AFC-loop.
	* The difference between the actual count and the desired value is multiplied by this gain.
	* When afc_ki_ctrl1 is equal to 7 (max-value), then the AFC-loop_gain will be 1/2
	* When afc_ki_ctrl1 is equal to 6, then the actual AFC-loop_gain will be 1/4
	* When afc_ki_ctrl1 is equal to 5, then the actual AFC-loop_gain will be 1/8
	* When afc_ki_ctrl1 is equal to 4, then the actual AFC-loop_gain will be 1/16
	* When afc_ki_ctrl1 is equal to 3, then the actual AFC-loop_gain will be 1/32
	* afc_ki_ctrl1 = 2 or 1 or 0 not used
	*
	* Note1: Set to default of afc_ki_ctrl1=7 i.e loop gain of 1/2
	* Note2: For 1g/2g mode, afc_ki_ctrl1 = 3'b111 is recommended. But to be validated
	* Note3: For 4g mode, afc_ki_ctrl1 = 3'b110  is recommended. But to be validated
	* Read/Write: RW
	* Bits: [14:12]
	* ResetValue: 0b111
	* Source: Application
	* FuSa: No
	*/
	uint32_t AfcKiCtrl1 : 3;        /*## attribute AfcKiCtrl1 */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 1;        /*## attribute Reserved3 */
	/**
	* BitsName: afc_step_limit
	* Description:
	* frequency loop integrator step limiter which determines the sub-band increment/decrement step size. Note: Only mentioned sub-sets are needed
	* afc_mdif_lim = -2  => afc_step_limit =  0, sub-band limit check = (afc_mdif <=  -2)
	* afc_mdif_lim =  2  => afc_step_limit =  0, sub-band limit check = (afc_mdif >     1)
	* afc_mdif_lim = -4  => afc_step_limit =  1, sub-band limit check = (afc_mdif <=  -4)
	* afc_mdif_lim =  4  => afc_step_limit =  1, sub-band limit check = (afc_mdif >     3)
	* afc_mdif_lim = -8  => afc_step_limit =  2, sub-band limit check = (afc_mdif <=  -8) (4G Mode)
	* afc_mdif_lim =  8  => afc_step_limit =  2, sub-band limit check = (afc_mdif >     7)
	* afc_mdif_lim = -16 => afc_step_limit = 3, sub-band limit check = (afc_mdif <= -16) (1G/2G Mode)
	* afc_mdif_lim =  16 => afc_step_limit = 3, sub-band limit check = (afc_mdif >    15)
	* afc_mdif_lim = -32 => afc_step_limit = 4, sub-band limit check = (afc_mdif <= -32)
	* afc_mdif_lim =  32 => afc_step_limit = 4, sub-band limit check = (afc_mdif >    31)
	* afc_mdif_lim = -64 => afc_step_limit = 5, sub-band limit check = (afc_mdif <= -64)
	* afc_mdif_lim =  64 => afc_step_limit = 5, sub-band limit check = (afc_mdif >    63)
	*
	* Note: Optimal value of afc_step_limit = 2 or 3 for 4G and 1G/2G Mode respectively. To be validated
	* Read/Write: RW
	* Bits: [10:8]
	* ResetValue: 0b011
	* Source: Application
	* FuSa: No
	*/
	uint32_t AfcStepLimit : 3;        /*## attribute AfcStepLimit */
	/**
	* BitsName: Reserved_4
	* Description: not used
	*/
	uint32_t Reserved4 : 1;        /*## attribute Reserved4 */
	/**
	* BitsName: afc_lock_ctrl2
	* Description: frequency loop2 lock control criterium 2
	* This is final frequency loop after amplitude calibration.
	* This control decides the number of stable sub-band iterations to generate the final afc_lock.
	* The count is equal to desired value(mdes), then the stable_flag =1. Number of such adjacent stable flag condition is defined by this control.
	*
	*
	* afc_lock_ctrl2 = 0 => Number of consecutive stable states check = 1
	* afc_lock_ctrl2 = 1 => Number of consecutive stable states check = 2
	* afc_lock_ctrl2 = 2 => Number of consecutive stable states check = 3
	* afc_lock_ctrl2 = 3 => Number of consecutive stable states check = 4
	* afc_lock_ctrl2 = 4 => Number of consecutive stable states check = 5
	* afc_lock_ctrl2 = 5 => Number of consecutive stable states check = 6
	* afc_lock_ctrl2 = 6 => Number of consecutive stable states check = 7
	* afc_lock_ctrl2 = 7 => Number of consecutive stable states check = 8
	*
	*
	* Note: The optimal value for afc_lock_ctrl2 = 7
	*
	*
	* Read/Write: RW
	* Bits: [6:4]
	* ResetValue: 0b111
	* Source: Application
	* FuSa: No
	*/
	uint32_t AfcLockCtrl2 : 3;        /*## attribute AfcLockCtrl2 */
	/**
	* BitsName: Reserved_5
	* Description: not used
	*/
	uint32_t Reserved5 : 1;        /*## attribute Reserved5 */
	/**
	* BitsName: afc_lock_ctrl1
	* Description: frequency loop1 lock control criterium 1
	* This is first frequency loop.
	* This control decides the number of stable sub-band iterations to generate the final afc_lock.
	* The count is equal to desired value(mdes), then the stable_flag =1. Number of such adjacent stable flag condition is defined by this control.
	*
	* afc_lock_ctrl1 = 0 => Number of consecutive stable states check = 1
	* afc_lock_ctrl1 = 1 => Number of consecutive stable states check = 2
	* afc_lock_ctrl1 = 2 => Number of consecutive stable states check = 3
	* afc_lock_ctrl1 = 3 => Number of consecutive stable states check = 4
	* afc_lock_ctrl1 = 4 => Number of consecutive stable states check = 5
	* afc_lock_ctrl1 = 5 => Number of consecutive stable states check = 6
	* afc_lock_ctrl1 = 6 => Number of consecutive stable states check = 7
	* afc_lock_ctrl1 = 7 => Number of consecutive stable states check = 8
	*
	*
	* Note: The optimal value for afc_lock_ctrl1 = 7
	*
	*
	*
	*
	*
	* Read/Write: RW
	* Bits: [2:0]
	* ResetValue: 0b010
	* Source: Application
	* FuSa: No
	*/
	uint32_t AfcLockCtrl1 : 3;        /*## attribute AfcLockCtrl1 */
}R2M06_ChirpCalibrationAfcControl2Bits_t;
/**
* R2M06_DivideForceControlBits_t
* RegisterName: DIVIDE_FORCE_CONTROL
* PLL divider settings
* Address: 0x240
* ResetValue: 0x00000120
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 23;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_force_divider
	* Description: enables forcing a PLL loop back divider. If set, divider is programmed to the setting of 'ctl_div_force' (see field ). In order to make the initial frequency defined at startup (before application programs), this bit is forced with fixed divider. This should be set to '0' in the application mode.
	* 1 :  Enable pll loop back divider
	* 0 :  Disable pll loop back divider
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlForceDivider : 1;        /*## attribute CtlForceDivider */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_div_force
	* Description: defines the PLL loop back divider (26-28[dec] are allowed settings). Requires 'ctl_force_divider' to be set (otherwise the divider is under control of sweep engine)
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b100000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlDivForce : 6;        /*## attribute CtlDivForce */
}R2M06_DivideForceControlBits_t;
/**
* R2M06_LpfEnableSettingsBits_t
* RegisterName: LPF_ENABLE_SETTINGS
* Loop filter settings
* Address: 0x244
* ResetValue: 0x17610017
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_lpf_prog_force_voltage_cf_spi
	* Description: Program the force vtune voltage for center frequency (cf)
	* Read/Write: RW
	* Bits: [30:24]
	* ResetValue: 0b0010111
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlLpfProgForceVoltageCfSpi : 7;        /*## attribute CtlLpfProgForceVoltageCfSpi */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_lpf_fr_cmp_en_spi
	* Description:
	* Enable comparator
	* 1 :  Enable comparator
	* 0 :  Disable comparator
	* Read/Write: RW
	* Bits: [22]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlLpfFrCmpEnSpi : 1;        /*## attribute CtlLpfFrCmpEnSpi */
	/**
	* BitsName: ctl_lpf_fr_buffer_en_spi
	* Description:
	* Enable lpf fast reset buffer
	* 1 :  Enable buffer
	* 0 :  Disable buffer
	* Read/Write: RW
	* Bits: [21]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlLpfFrBufferEnSpi : 1;        /*## attribute CtlLpfFrBufferEnSpi */
	/**
	* BitsName: ctl_lpf_vtune_monitor_en_spi
	* Description: Enable the vtune monitor
	* 1 :  Enable vtune monitor
	* 0 :  Disable  vtune monitor
	* Read/Write: RW
	* Bits: [20]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlLpfVtuneMonitorEnSpi : 1;        /*## attribute CtlLpfVtuneMonitorEnSpi */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: ctl_lpf_int_en_spi
	* Description:
	* Enable internal loop filter (connection between CP and VCO)
	* 1 :  Enable loop filter
	* 0 :  Disable loop filter
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlLpfIntEnSpi : 1;        /*## attribute CtlLpfIntEnSpi */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: ctl_lpf_ext_en_spi
	* Description: Enable external VCO tune voltage.
	* 1 :  Enable external vco tune voltage
	* 0 :  Disable external vco tune voltage
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlLpfExtEnSpi : 1;        /*## attribute CtlLpfExtEnSpi */
	/**
	* BitsName: Reserved_4
	* Description: not used
	*/
	uint32_t Reserved4 : 3;        /*## attribute Reserved4 */
	/**
	* BitsName: ctl_lpf_force_vtune_en_spi
	* Description: Enable the force vtune circuit
	* 1 :  Enable force vtune circuit
	* 0 :  Disable  force vtune circuit
	*
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlLpfForceVtuneEnSpi : 1;        /*## attribute CtlLpfForceVtuneEnSpi */
	/**
	* BitsName: Reserved_5
	* Description: not used
	*/
	uint32_t Reserved5 : 1;        /*## attribute Reserved5 */
	/**
	* BitsName: ctl_lpf_prog_force_voltage_spi
	* Description: Program the force vtune voltage (start/edge frequency)
	* Read/Write: RW
	* Bits: [6:0]
	* ResetValue: 0b0010111
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlLpfProgForceVoltageSpi : 7;        /*## attribute CtlLpfProgForceVoltageSpi */
}R2M06_LpfEnableSettingsBits_t;
/**
* R2M06_VcoEnableSettingsBits_t
* RegisterName: VCO_ENABLE_SETTINGS
* Loop filter settings only for internal use
* Address: 0x248
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 19;        /*## attribute Reserved0 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 11;        /*## attribute Reserved2 */
	/**
	* BitsName: ctl_vco_en_spi
	* Description: Enable VCO
	* 1 :  Enable VCO
	* 0 :  Disable VCO
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlVcoEnSpi : 1;        /*## attribute CtlVcoEnSpi */
}R2M06_VcoEnableSettingsBits_t;
/**
* R2M06_FuncsafeMonVtuneControlBits_t
* RegisterName: FUNCSAFE_MON_VTUNE_CONTROL
* Functional safety monitor related to vtune settings
* Address: 0x24C
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 24;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_vtune_vco_high_spi
	* Description: tuning voltage monitor high threshold: V_thresh = 850mV + ctl_vtune_vco_high * 12.5mV
	* Read/Write: RW
	* Bits: [7:4]
	* ResetValue: 0b0000
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t CtlVtuneVcoHighSpi : 4;        /*## attribute CtlVtuneVcoHighSpi */
	/**
	* BitsName: ctl_vtune_vco_low_spi
	* Description: tuning voltage monitor low threshold: V_thresh =  V_thresh = 50mV + ctl_vtune_vco_low * 12.5mV
	* Read/Write: RW
	* Bits: [3:0]
	* ResetValue: 0b0000
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t CtlVtuneVcoLowSpi : 4;        /*## attribute CtlVtuneVcoLowSpi */
}R2M06_FuncsafeMonVtuneControlBits_t;
/**
* R2M06_FuncsafeMonUnlockControlBits_t
* RegisterName: FUNCSAFE_MON_UNLOCK_CONTROL
* Functional safety monitor related to unlock settings
* Address: 0x250
* ResetValue: 0x00100400
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 11;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_ld_en_spi
	* Description: Enable Lock detector
	* 1: Enable lock detector
	* 0: Disable lock detector
	* Read/Write: RW
	* Bits: [20]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: Y
	*/
	uint32_t CtlLdEnSpi : 1;        /*## attribute CtlLdEnSpi */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_ld_pol_spi
	* Description: Lock detector polarity
	* 1: Negative polarity
	* 0: Positive polarity
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t CtlLdPolSpi : 1;        /*## attribute CtlLdPolSpi */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: ctl_ld_window_offset_spi
	* Description: Lock detector window offset
	*
	* Read/Write: RW
	* Bits: [13:8]
	* ResetValue: 0b000100
	* Source: Application
	* FuSa: Y
	*/
	uint32_t CtlLdWindowOffsetSpi : 6;        /*## attribute CtlLdWindowOffsetSpi */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 2;        /*## attribute Reserved3 */
	/**
	* BitsName: Reserved_4
	* Description: not used
	*/
	uint32_t Reserved4 : 6;        /*## attribute Reserved4 */
}R2M06_FuncsafeMonUnlockControlBits_t;
/**
* R2M06_FuncsafeMonLevelSettingsBits_t
* RegisterName: FUNCSAFE_MON_LEVEL_SETTINGS
* Functional safety monitor related to vco level settings
* Address: 0x254
* ResetValue: 0x3530150C
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_level_vco_max_spi
	* Description: High trigger level for Reliability (the most high threshold voltage):
	*
	*
	* V_thresh_max =10^(((ctl_level_vco_max_spi - 63)*0.29)/20)*0.9 = 109.8mV * pow(10,((0.29/20* ctl_level_vco_max_spi))
	* Read/Write: RW
	* Bits: [29:24]
	* ResetValue: 0b110101
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t CtlLevelVcoMaxSpi : 6;        /*## attribute CtlLevelVcoMaxSpi */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_level_vco_high_spi
	* Description: High trigger level for Gain Control:
	*
	* V_thresh_high =10^(((ctl_level_vco_high_spi - 63)*0.29)/20)*0.9 = 109.8mV * pow(10,((0.29/20* ctl_level_vco_high_spi))
	* Read/Write: RW
	* Bits: [21:16]
	* ResetValue: 0b110000
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t CtlLevelVcoHighSpi : 6;        /*## attribute CtlLevelVcoHighSpi */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: ctl_level_vco_low_spi
	* Description: Low trigger level for Gain Control:
	*
	* V_thresh_low =10^(((ctl_level_vco_low_spi - 63)*0.29)/20)*0.9 = 109.8mV * pow(10,((0.29/20* ctl_level_vco_low_spi))
	* Read/Write: RW
	* Bits: [13:8]
	* ResetValue: 0b010101
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t CtlLevelVcoLowSpi : 6;        /*## attribute CtlLevelVcoLowSpi */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 2;        /*## attribute Reserved3 */
	/**
	* BitsName: ctl_level_vco_min_spi
	* Description:
	* Low trigger level for FSM (the most low threshold voltage):
	*
	* V_thresh_min =10^(((ctl_level_vco_min_spi - 63)*0.29)/20)*0.9 = 109.8mV * pow(10,((0.29/20* ctl_level_vco_min_spi))
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b001100
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t CtlLevelVcoMinSpi : 6;        /*## attribute CtlLevelVcoMinSpi */
}R2M06_FuncsafeMonLevelSettingsBits_t;
/**
* R2M06_FuncsafeMonTempThresholdBits_t
* RegisterName: FUNCSAFE_MON_TEMP_THRESHOLD
* Over-temperature detection threshold control. Untrimmed range 94..165 degree Celcius
* Address: 0x258
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 25;        /*## attribute Reserved0 */
	/**
	* BitsName: ts_threshold_sel_spi
	* Description: Set the maximum temperature threshold values
	* Read/Write: RW
	* Bits: [6:0]
	* ResetValue: 0b0000000
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t TsThresholdSelSpi : 7;        /*## attribute TsThresholdSelSpi */
}R2M06_FuncsafeMonTempThresholdBits_t;
/**
* R2M06_AtbTrimBits_t
* RegisterName: ATB_TRIM
* Trim settings for ATB
* Address: 0x260
* ResetValue: 0x0000002B
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 26;        /*## attribute Reserved0 */
	/**
	* BitsName: set_trim_r_n_spi
	* Description: Trim bits. debug/test feature: trimming of local I/V conversion for ATB tests, only lower 5 bits are used
	* Read/Write: RW
	* Bits: [5:0]
	* ResetValue: 0b101011
	* Source: Fixed
	* FuSa: No
	*/
	uint32_t SetTrimRNSpi : 6;        /*## attribute SetTrimRNSpi */
}R2M06_AtbTrimBits_t;
/**
* R2M06_FilterParTrimBits_t
* RegisterName: FILTER_PAR_TRIM
* Trim settings for FILTER from OTP
* Address: 0x264
* ResetValue: 0x00011616
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 15;        /*## attribute Reserved0 */
	/**
	* BitsName: cp_r1_r2_settings_to_profile
	* Description: R2 IS NOT USED IN THE DESIGN
	* copy the R1 and R2 settings from this register to all profile registers PLL_LPF_RES_SETTINGS_PROFILE*
	*
	* 1 : copy the settings to all profile registers PLL_LPF_RES_SETTINGS_PROFILE*
	* 0 : Do not copy the settings and profile registers to be programmed
	*
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t CpR1R2SettingsToProfile : 1;        /*## attribute CpR1R2SettingsToProfile */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 5;        /*## attribute Reserved2 */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: ctl_lpf_r1_spi
	* Description: Select loop filter res. R1
	* Read/Write: RW
	* Bits: [4:0]
	* ResetValue: 0b10110
	* Source: OTP
	* FuSa: No
	*/
	uint32_t CtlLpfR1Spi : 5;        /*## attribute CtlLpfR1Spi */
}R2M06_FilterParTrimBits_t;
/**
* R2M06_VcoCurrentTrimBits_t
* RegisterName: VCO_CURRENT_TRIM
* Trim settings for VCO current
* Address: 0x268
* ResetValue: 0x0000000F
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 27;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_vco_r_ibias_set_spi
	* Description: Select resistor used for VCO current generation
	* Read/Write: RW
	* Bits: [4:0]
	* ResetValue: 0b01111
	* Source: OTP
	* FuSa: No
	*/
	uint32_t CtlVcoRIbiasSetSpi : 5;        /*## attribute CtlVcoRIbiasSetSpi */
}R2M06_VcoCurrentTrimBits_t;
/**
* R2M06_FuncsafeMonLevelSettingsEnBits_t
* RegisterName: FUNCSAFE_MON_LEVEL_SETTINGS_EN
* Functional safety monitor related to vco level settings
* Address: 0x26C
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 31;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_level_vco_amp_monitor_en_spi
	* Description: Enable the amplitude monitor
	* 1: Enable amplitude monitor
	* 0: Disable amplitude monitor
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t CtlLevelVcoAmpMonitorEnSpi : 1;        /*## attribute CtlLevelVcoAmpMonitorEnSpi */
}R2M06_FuncsafeMonLevelSettingsEnBits_t;
/**
* R2M06_SubbandAmpCorrectionModeSelBits_t
* RegisterName: SUBBAND_AMP_CORRECTION_MODE_SEL
* The register to control the sub-band and amplitude correction in the special cases. This register is not used in the normal mode.
*
* The monitors inside the chirp indicate when such a sub-band correction is required. If the correction mode is enabled in this register, the necessary change setting are applied from this register + SUBBAND_CORRECTION_OTP_SETTING* registers
*
*
* Note: vtune status registers in the chirp and ISM will be set when such sub-band change request is triggered by the chirp vtune monitors
*
*
* Example Application case:
* When a profile dynamically demands a frequency which is outside the currently selected sub-band, the following settings can be used to switch the sub-band and accordingly the amplitude also can be adjusted. The trigger for such sub-band change is indicated by the tune monitors within chirp.
*
* Address: 0x270
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: amplitude_incr_decr_sel
	* Description: nan
	* Read/Write: RW
	* Bits: [31]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t AmplitudeIncrDecrSel : 1;        /*## attribute AmplitudeIncrDecrSel */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 2;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_vco_coarse_tuning_fast_bias_en_spi_override
	* Description: Override the short time constant by keeping the switch open
	*
	* 0 - No override. The value of ctl_vco_coarse_tuning_fast_bias_en_spi_profile* from register vco_reg_profile* is taken
	* 1 - Override.  ctl_vco_coarse_tuning_fast_bias_en_spi = 0
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t CtlVcoCoarseTuningFastBiasEnSpiOverride : 1;        /*## attribute CtlVcoCoarseTuningFastBiasEnSpiOverride */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 4;        /*## attribute Reserved1 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 4;        /*## attribute Reserved2 */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 2;        /*## attribute Reserved3 */
	/**
	* BitsName: subband_decrement
	* Description: when vtune_low status monitor is triggered, the subband is decremented by the programmed value
	*
	* subband decrement value programmable between 0x0 to 0xF. This value gets subtracted with the existing subband after the OTP correction value coming from OTP_TRIM_SUBBAND_CORRECTION_*
	*
	*
	* Read/Write: RW
	* Bits: [17:12]
	* ResetValue: 0b000000
	* Source: Application
	* FuSa: Y
	*/
	uint32_t SubbandDecrement : 6;        /*## attribute SubbandDecrement */
	/**
	* BitsName: Reserved_4
	* Description: not used
	*/
	uint32_t Reserved4 : 2;        /*## attribute Reserved4 */
	/**
	* BitsName: subband_increment
	* Description: when vtune_high status monitor is triggered, the subband is incremented by the programmed value
	*
	* subband increment value programmable between 0x0 to 0xF. This value gets added to the existing subband after the OTP correction value coming from OTP_TRIM_SUBBAND_CORRECTION_*
	*
	*
	* Read/Write: RW
	* Bits: [9:4]
	* ResetValue: 0b000000
	* Source: Application
	* FuSa: Y
	*/
	uint32_t SubbandIncrement : 6;        /*## attribute SubbandIncrement */
	/**
	* BitsName: Reserved_5
	* Description: not used
	*/
	uint32_t Reserved5 : 2;        /*## attribute Reserved5 */
	/**
	* BitsName: Reserved_6
	* Description: not used
	*/
	uint32_t Reserved6 : 1;        /*## attribute Reserved6 */
	/**
	* BitsName: subband_correction_enable
	* Description: sub-band correction enable bit
	*
	* 0 :  No sub-band correction
	* 1 :  sub-band correction is enabled
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t SubbandCorrectionEnable : 1;        /*## attribute SubbandCorrectionEnable */
}R2M06_SubbandAmpCorrectionModeSelBits_t;
/**
* R2M06_OtpTrimSubbandCorrection1GBits_t
* RegisterName: OTP_TRIM_SUBBAND_CORRECTION_1G
* The register to control the sub-band in the special cases like non-linear behaviour of the vco wrt specific sub-band. This register is not used in the normal mode. If used, it is used with SUBBAND_AMP_CORRECTION_MODE_SEL register
*
* OTP additional correction settings for certain special sub-bands in 1G mode
* Address: 0x274
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: vco_1g_skip_112
	* Description: sub-band 112 should be skipped by the delta mentioned in this field
	* Read/Write: RW
	* Bits: [30:28]
	* ResetValue: 0b000
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t Vco1GSkip112 : 3;        /*## attribute Vco1GSkip112 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: vco_1g_skip_96
	* Description: sub-band 96 should be skipped by the delta mentioned in this field
	* Read/Write: RW
	* Bits: [26:24]
	* ResetValue: 0b000
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t Vco1GSkip96 : 3;        /*## attribute Vco1GSkip96 */
	/**
	* BitsName: vco_1g_skip_80
	* Description: sub-band 80 should be skipped by the delta mentioned in this field
	* Read/Write: RW
	* Bits: [23:20]
	* ResetValue: 0b0000
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t Vco1GSkip80 : 4;        /*## attribute Vco1GSkip80 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: vco_1g_skip_64
	* Description: sub-band 64 should be skipped by the delta mentioned in this field
	* Read/Write: RW
	* Bits: [17:12]
	* ResetValue: 0b000000
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t Vco1GSkip64 : 6;        /*## attribute Vco1GSkip64 */
	/**
	* BitsName: vco_1g_skip_48
	* Description: sub-band 48 should be skipped by the delta mentioned in this field
	* Read/Write: RW
	* Bits: [11:8]
	* ResetValue: 0b0000
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t Vco1GSkip48 : 4;        /*## attribute Vco1GSkip48 */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 1;        /*## attribute Reserved3 */
	/**
	* BitsName: vco_1g_skip_32
	* Description: sub-band 32 should be skipped by the delta mentioned in this field
	* Read/Write: RW
	* Bits: [6:4]
	* ResetValue: 0b000
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t Vco1GSkip32 : 3;        /*## attribute Vco1GSkip32 */
	/**
	* BitsName: Reserved_4
	* Description: not used
	*/
	uint32_t Reserved4 : 1;        /*## attribute Reserved4 */
	/**
	* BitsName: vco_1g_skip_16
	* Description: sub-band 16 should be skipped by the delta mentioned in this field
	* Read/Write: RW
	* Bits: [2:0]
	* ResetValue: 0b000
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t Vco1GSkip16 : 3;        /*## attribute Vco1GSkip16 */
}R2M06_OtpTrimSubbandCorrection1GBits_t;
/**
* R2M06_OtpTrimSubbandCorrection2GBits_t
* RegisterName: OTP_TRIM_SUBBAND_CORRECTION_2G
* The register to control the sub-band in the special cases like non-linear behaviour of the vco wrt specific sub-band. This register is not used in the normal mode. If used, it is used with SUBBAND_AMP_CORRECTION_MODE_SEL register
*
* OTP additional correction settings for certain special sub-bands in 2G mode
* Address: 0x278
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: vco_2g_skip_112
	* Description: sub-band 112 should be skipped by the delta mentioned in this field
	* Read/Write: RW
	* Bits: [30:28]
	* ResetValue: 0b000
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t Vco2GSkip112 : 3;        /*## attribute Vco2GSkip112 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: vco_2g_skip_96
	* Description: sub-band 96 should be skipped by the delta mentioned in this field
	* Read/Write: RW
	* Bits: [26:24]
	* ResetValue: 0b000
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t Vco2GSkip96 : 3;        /*## attribute Vco2GSkip96 */
	/**
	* BitsName: vco_2g_skip_80
	* Description: sub-band 80 should be skipped by the delta mentioned in this field
	* Read/Write: RW
	* Bits: [23:20]
	* ResetValue: 0b0000
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t Vco2GSkip80 : 4;        /*## attribute Vco2GSkip80 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: vco_2g_skip_64
	* Description: sub-band 64 should be skipped by the delta mentioned in this field
	* Read/Write: RW
	* Bits: [17:12]
	* ResetValue: 0b000000
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t Vco2GSkip64 : 6;        /*## attribute Vco2GSkip64 */
	/**
	* BitsName: vco_2g_skip_48
	* Description: sub-band 48 should be skipped by the delta mentioned in this field
	* Read/Write: RW
	* Bits: [11:8]
	* ResetValue: 0b0000
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t Vco2GSkip48 : 4;        /*## attribute Vco2GSkip48 */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 1;        /*## attribute Reserved3 */
	/**
	* BitsName: vco_2g_skip_32
	* Description: sub-band 32 should be skipped by the delta mentioned in this field
	* Read/Write: RW
	* Bits: [6:4]
	* ResetValue: 0b000
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t Vco2GSkip32 : 3;        /*## attribute Vco2GSkip32 */
	/**
	* BitsName: Reserved_4
	* Description: not used
	*/
	uint32_t Reserved4 : 1;        /*## attribute Reserved4 */
	/**
	* BitsName: vco_2g_skip_16
	* Description: sub-band 16 should be skipped by the delta mentioned in this field
	* Read/Write: RW
	* Bits: [2:0]
	* ResetValue: 0b000
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t Vco2GSkip16 : 3;        /*## attribute Vco2GSkip16 */
}R2M06_OtpTrimSubbandCorrection2GBits_t;
/**
* R2M06_OtpTrimSubbandCorrection4GBits_t
* RegisterName: OTP_TRIM_SUBBAND_CORRECTION_4G
* The register to control the sub-band in the special cases like non-linear behaviour of the vco wrt specific sub-band. This register is not used in the normal mode. If used, it is used with SUBBAND_AMP_CORRECTION_MODE_SEL register
*
* OTP additional correction settings for certain special sub-bands in 4G mode
* Address: 0x27C
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 20;        /*## attribute Reserved0 */
	/**
	* BitsName: vco_4g_skip_48
	* Description: sub-band 48 should be skipped by the delta mentioned in this field
	* Read/Write: RW
	* Bits: [11:8]
	* ResetValue: 0b0000
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t Vco4GSkip48 : 4;        /*## attribute Vco4GSkip48 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: vco_4g_skip_32
	* Description: sub-band 32 should be skipped by the delta mentioned in this field
	* Read/Write: RW
	* Bits: [6:4]
	* ResetValue: 0b000
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t Vco4GSkip32 : 3;        /*## attribute Vco4GSkip32 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 1;        /*## attribute Reserved2 */
	/**
	* BitsName: vco_4g_skip_16
	* Description: sub-band 16 should be skipped by the delta mentioned in this field
	* Read/Write: RW
	* Bits: [2:0]
	* ResetValue: 0b000
	* Source: OTP
	* FuSa: Y
	*/
	uint32_t Vco4GSkip16 : 3;        /*## attribute Vco4GSkip16 */
}R2M06_OtpTrimSubbandCorrection4GBits_t;
/**
* R2M06_HighPllbwSwitchControlBits_t
* RegisterName: HIGH_PLLBW_SWITCH_CONTROL
* This register controls switching from high pll bw configuration to profile bw configuration to avoid larger settling time. Usually this is useful during standby mode to poweron mode switching or large sub-band switching between adjacent chirps. The registers CP_PLLBW_CFG_HIGH,  PLL_LPF_C1_PLLBW_CFG_HIGH, PLL_LPF_C2_PLLBW_CFG_HIGH, PLL_LPF_C3_PLLBW_CFG_HIGH, PLL_LPF_RES_PLLBW_CFG_HIGH are the registers which will override the profile register values derived from CP_PLLBW_CFG*,  PLL_LPF_C1_PLLBW_CFG*, PLL_LPF_C2_PLLBW_CFG*, PLL_LPF_C3_PLLBW_CFG*, PLL_LPF_RES_PLLBW_CFG*
* Address: 0x280
* ResetValue: 0x01901906
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 4;        /*## attribute Reserved0 */
	/**
	* BitsName: high_pllbw_to_prof_bw_seq_start_switch_time
	* Description: The time during which high pll bw is effective before switching to the profile info
	*
	* The counter is operating with 40MHz clock. The high pll bw is loaded at the start of the dc power on delay/start of the sequence and after this counter expiry, the profile info is loaded.
	* default delay value is 10 us
	* Read/Write: RW
	* Bits: [27:16]
	* ResetValue: 0b000110010000
	* Source: Application
	* FuSa: No
	*/
	uint32_t HighPllbwToProfBwSeqStartSwitchTime : 12;        /*## attribute HighPllbwToProfBwSeqStartSwitchTime */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: high_pllbw_to_prof_bw_switch_time
	* Description: The time during which high pll bw is effective before switching to the profile info
	*
	* The counter is operating with 40MHz clock. The high pll bw is loaded at the start of the dwell/start of the chirp and after this counter expiry, the profile info is loaded, default delay value is 10 us.
	* Read/Write: RW
	* Bits: [12:4]
	* ResetValue: 0b110010000
	* Source: Application
	* FuSa: No
	*/
	uint32_t HighPllbwToProfBwSwitchTime : 9;        /*## attribute HighPllbwToProfBwSwitchTime */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 1;        /*## attribute Reserved2 */
	/**
	* BitsName: high_pllbw_switch_enable_cw_mode
	* Description: Enable high pll bw switch feature overriding during the CW mode with the  profile_load_for_calib bit. Duration for   high pll bw switch feature overriding will be based on the 'high_pllbw_to_prof_bw_seq_start_switch_time' programmed. Also high pll bw switch feature overriding will be enable when the Chirp_AFC -> keep_middle_frequency_in_cw_mode bit toggles. Chirp start should be applied only after the high_pllbw_to_prof_bw_seq_start_switch_time once the high pll bw switch in cw mode is triggered either by keep_middle_frequency_in_cw_mode bt or by profile_load_for_calib bit
	* 1: Enable high pll bw switch during cw mode
	* 0:  Disable high pll bw switch during cw mode
	* Read/Write: RW
	* Bits: [2]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t HighPllbwSwitchEnableCwMode : 1;        /*## attribute HighPllbwSwitchEnableCwMode */
	/**
	* BitsName: high_pllbw_to_prof_bw_seq_start_switch_enable
	* Description: Enable high pll bw switch feature overriding the profile info for shorter period during dc power on delay
	* 1: Enable high pll bw switch at the start of the dc power on time overriding the profile info
	* 0:  Disable high pll bw switch at the start of the dc power on time and use only the profile info
	* Read/Write: RW
	* Bits: [1]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t HighPllbwToProfBwSeqStartSwitchEnable : 1;        /*## attribute HighPllbwToProfBwSeqStartSwitchEnable */
	/**
	* BitsName: high_pllbw_to_prof_bw_switch_enable
	* Description: Enable high pll bw switch feature overriding the profile info for shorter period (defined by high_pllbw_to_prof_bw_switch_time bits)
	* 1: Enable high pll bw switch at the start of the tdwell overriding the profile info
	* 0:  Disable high pll bw switch at the start of the tdwell and use only the profile info
	* Note: Once enabled, this is applicable for all chirps; in order to perform this for selective chirps, dynamically this bit has to be programmed during the Idle time of each chirp
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t HighPllbwToProfBwSwitchEnable : 1;        /*## attribute HighPllbwToProfBwSwitchEnable */
}R2M06_HighPllbwSwitchControlBits_t;
/**
* R2M06_AdditionalHwSettingsBits_t
* RegisterName: ADDITIONAL_HW_SETTINGS
* Additional hardware settings
* Address: 0x298
* ResetValue: 0x00010000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 7;        /*## attribute Reserved0 */
	/**
	* BitsName: idac_polarity_from_sweep_control_invert
	* Description: This bit controls the polarity of the dac injection current based on the sweep control settings automatically.
	* 1: Invert the sweep control polarity latched at the chirp start (at profile_load point)
	* 0 (Reset Value):  Use the polarity latched from sweep control as is
	*
	* Note: This field is applicable only when idac_polarity_from_sweep_control is set to 1'b1
	*
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t IdacPolarityFromSweepControlInvert : 1;        /*## attribute IdacPolarityFromSweepControlInvert */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: idac_polarity_from_sweep_control
	* Description: This bit controls the polarity of the dac injection current based on the sweep control settings automatically.
	* 1: Sweep control module drives the polarity bit of the dac injection is based on the chirp profile. The polarity is latched at the start of the chirp (at profile load). Based on active upchirp (polarity 0) or active downchirp (polarity 1), the polarity value is determined
	* 0 (Reset Value):  The polarity of the dac injection is controlled by the bit  pll_fr_idac_polarity in the register PLL_DAC_INJ_ACQ
	*
	* Note: If this bit is set to '1', pll_fr_idac_polarity bit in the register PLL_DAC_INJ_ACQ should be set to '0' to override the software based polarity setting
	*
	* Read/Write: RW
	* Bits: [20]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t IdacPolarityFromSweepControl : 1;        /*## attribute IdacPolarityFromSweepControl */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 2;        /*## attribute Reserved2 */
	/**
	* BitsName: enable_hard_func_reset_per_chirp
	* Description: This bit controls the selection of the hardware functional reset based on the chirp fast switch.
	* 1: Enable hardware functional reset at every chirp dwell start and release after the chirp_fast_bias_switch_delay timer (field in CHIRP_BIAS_SWITCH_CONTROL register in timing engine) expires (chirp_dynamic_power_control reg in timing engine).
	*
	* - If Chirp is in per chirp powerdown and chirp_powermode bit is set, this functional reset is asserted at the start of every chirp and If Chirp is in per seq powerdown and chirp_powermode bit is set functional reset is asserted at the start of every sequence .
	*
	* 0: Disable  hardware functional reset. No hardware functional reset will be issued.
	*
	* This bit should be enabled when the Chirp is powerdown per chirp basis. Also enable Sweep_control -> SWEEP_DIV_RST_CONTROL -> sweep_div_rst_enable_frame bit along with this bit
	*
	* Chirp powerdown per sequence is considered as the default mode and the reset values need to be changed
	* Read/Write: RW
	* Bits: [17]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t EnableHardFuncResetPerChirp : 1;        /*## attribute EnableHardFuncResetPerChirp */
	/**
	* BitsName: enable_hard_func_reset_per_frame
	* Description: This bit controls the selection of the hardware functional reset based on the chirp fast switch.
	* 1: Enable hardware functional reset at every  every sequence start and release after the chirp_fast_bias_switch_delay timer (field in CHIRP_BIAS_SWITCH_CONTROL register in timing engine) expires (chirp_dynamic_power_control reg in timing engine).
	*
	* - In Normal/Powerdwn per sequence mode, this functional reset is asserted at the start of every sequence .
	* 0: Disable  hardware functional reset. No hardware functional reset will be issued.
	*
	* This bit should be enabled when the Chirp is powerdown per frame/sequence basis. Also enable Sweep_control -> SWEEP_DIV_RST_CONTROL -> sweep_div_rst_enable_frame bit along with this bit
	*
	* Chirp powerdown per sequence is considered as the default mode and the reset values are given accordingly
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t EnableHardFuncResetPerFrame : 1;        /*## attribute EnableHardFuncResetPerFrame */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: ld_polarity_from_sweep_control
	* Description: This bit controls the polarity of the lock detector based on the sweep control settings automatically.
	* 1: Sweep control module drives the polarity bit of the lock detector based on the chirp profile (active up/downchirp)
	* 0 (Reset Value):  The polarity of the lock detector is controlled by the bit in the ctl_ld_pol_spi bit in the register funcsafe_mon_unlock_vco
	*
	* Note: If this bit is set to '1', ctl_ld_pol_spi bit in the register funcsafe_mon_unlock_vco should be set to '0' to override the software based polarity setting
	*
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t LdPolarityFromSweepControl : 1;        /*## attribute LdPolarityFromSweepControl */
	/**
	* BitsName: Reserved_4
	* Description: not used
	*/
	uint32_t Reserved4 : 3;        /*## attribute Reserved4 */
	/**
	* BitsName: ctl_ibias_speed_up_mux_ctrl
	* Description: This field controls the final value of the ctl_ibias_speed_up
	*
	* 0 : ctl_ibias_speed_up is driven after a delay from digital statemachine
	* 1 : ctl_ibias_speed_up is driven directly  from local spi field
	*
	* In the Application context, this bit should be set to 0. In CW mode, 1 will be chosen to override the timing engine based functionality
	*
	*
	* In the chirping mode, the same functionality is controlled from timing engine through the register CHIRP_FAST_BIAS_SWITCH_CONTROL.
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIbiasSpeedUpMuxCtrl : 1;        /*## attribute CtlIbiasSpeedUpMuxCtrl */
	/**
	* BitsName: Reserved_5
	* Description: not used
	*/
	uint32_t Reserved5 : 3;        /*## attribute Reserved5 */
	/**
	* BitsName: ctl_ibias_speed_up
	* Description: This control bit from chirp_afc is used for closing the analog switch to fast bias the vco.
	*
	* 0 : Switch is open
	* 1 : Switch is closed
	*
	*
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIbiasSpeedUp : 1;        /*## attribute CtlIbiasSpeedUp */
	/**
	* BitsName: Reserved_6
	* Description: not used
	*/
	uint32_t Reserved6 : 3;        /*## attribute Reserved6 */
	/**
	* BitsName: ctl_ibias_TS_100u_en
	* Description: Bias enable for the temperature sensor
	* 1: Enable bias of temp sensor
	* 0: Disable bias of temp sensor
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlIbiasTs100UEn : 1;        /*## attribute CtlIbiasTs100UEn */
}R2M06_AdditionalHwSettingsBits_t;
/**
* R2M06_ControlSpareBits_t
* RegisterName: CONTROL_SPARE
* DAC timing mode control and bits for future use
* Address: 0x29C
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 24;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_ts_in_pd_en
	* Description: enable for temperature sensor readout during powerdown
	* Read/Write: RW
	* Bits: [7]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CtlTsInPdEn : 1;        /*## attribute CtlTsInPdEn */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 4;        /*## attribute Reserved2 */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 2;        /*## attribute Reserved3 */
}R2M06_ControlSpareBits_t;
/**
* R2M06_TsSettingsBits_t
* RegisterName: TS_SETTINGS
* Functional safety monitor related to vco temperature sensor settings
* Address: 0x2A0
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 27;        /*## attribute Reserved0 */
	/**
	* BitsName: ts_swap_cur_dvbe
	* Description: Controls the dvbe current swapper of the temperature sensor core
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t TsSwapCurDvbe : 1;        /*## attribute TsSwapCurDvbe */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: ts_buf_chopper_spi
	* Description: Temperature sensor buffer chopper control
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t TsBufChopperSpi : 1;        /*## attribute TsBufChopperSpi */
}R2M06_TsSettingsBits_t;
/**
* R2M06_RmsControlBits_t
* RegisterName: RMS_CONTROL
* Lo rms detector calibration settings
* Address: 0x2A4
* ResetValue: 0x10000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: chirp_sel_rms_spi
	* Description: The control used to select the rns detector for 1g vco or 4g vco or buffer
	* 000 = All coupler off
	* 001 = select rms dector 1G
	* 010 = select rms dector 4G (this control should not be used if 4g mode is disabled by otp)
	* 100 = select rms dector buffer
	* Others = Reserved
	*
	* Note:
	* a. If ctl_sel_vco_1g_5g_spi_profile* / ctl_sel_vco_1g_5g_spi = 0 (1g mode), chirp_sel_rms_spi =1 is selected always.
	* b. If ctl_sel_vco_1g_5g_spi_profile* / ctl_sel_vco_1g_5g_spi is not equal to 0, the value programmed in this field passed directly
	* Read/Write: RW
	* Bits: [30:28]
	* ResetValue: 0b001
	* Source: Application
	* FuSa: No
	*/
	uint32_t ChirpSelRmsSpi : 3;        /*## attribute ChirpSelRmsSpi */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: chirp_rms_en_spi
	* Description: Enable the rms detector
	* 1: Enable rms detector
	* 0: Disable rms detector
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ChirpRmsEnSpi : 1;        /*## attribute ChirpRmsEnSpi */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 1;        /*## attribute Reserved3 */
	/**
	* BitsName: Reserved_4
	* Description: not used
	*/
	uint32_t Reserved4 : 3;        /*## attribute Reserved4 */
	/**
	* BitsName: Reserved_5
	* Description: not used
	*/
	uint32_t Reserved5 : 1;        /*## attribute Reserved5 */
	/**
	* BitsName: Reserved_6
	* Description: not used
	*/
	uint32_t Reserved6 : 3;        /*## attribute Reserved6 */
	/**
	* BitsName: chirp_meas_in_out_spi
	* Description: Select input or output of power detector.
	* 0=input
	* 1=output.
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t ChirpMeasInOutSpi : 1;        /*## attribute ChirpMeasInOutSpi */
	/**
	* BitsName: Reserved_7
	* Description: not used
	*/
	uint32_t Reserved7 : 3;        /*## attribute Reserved7 */
	/**
	* BitsName: Reserved_8
	* Description: not used
	*/
	uint32_t Reserved8 : 1;        /*## attribute Reserved8 */
	/**
	* BitsName: Reserved_9
	* Description: not used
	*/
	uint32_t Reserved9 : 2;        /*## attribute Reserved9 */
	/**
	* BitsName: Reserved_10
	* Description: not used
	*/
	uint32_t Reserved10 : 6;        /*## attribute Reserved10 */
}R2M06_RmsControlBits_t;
/**
* R2M06_RefCntrInitBits_t
* RegisterName: REF_CNTR_INIT
* Reference count value for 480Mhz frequency measurement
* Address: 0x2B0
* ResetValue: 0x01E00028
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: ideal_480_count_value
	* Description: This is applicable when the freq counter trigger is based on window_active (for func safety). The correct value to be programmed which is compared against the freq counter read value in the hardware. The value is restricted to 16 bits (as against 18 bit in the freq read counter value) as this triggered one time during active period of the window active and the bit width is sufficient to cover the frequency counting considering the variation of the chirp period
	* Read/Write: RW
	* Bits: [31:16]
	* ResetValue: 0b0000000111100000
	* Source: Application
	* FuSa: Y
	*/
	uint32_t Ideal480CountValue : 16;        /*## attribute Ideal480CountValue */
	/**
	* BitsName: ref_count_value
	* Description: value for the reference count time (40 MHz= 25 ns base time) default is d'40. This is used as reference count in both spi triggered mode and window_active triggered mode
	* Read/Write: RW
	* Bits: [15:0]
	* ResetValue: 0b0000000000101000
	* Source: Application
	* FuSa: Y
	*/
	uint32_t RefCountValue : 16;        /*## attribute RefCountValue */
}R2M06_RefCntrInitBits_t;
/**
* R2M06_FreqCounterStartBits_t
* RegisterName: FREQ_COUNTER_START
* 480Mhz frequency measurement trigger
* Address: 0x2B4
* ResetValue: 0x00000130
* Read/Write: RW
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 23;        /*## attribute Reserved0 */
	/**
	* BitsName: enable_func_safety_freq_mea
	* Description: By default, the frequency counter is triggered based on safety_monitor_active posedge to measure the frequency deviation if any and to report to the ISM for every chirp. If this bit is disabled, then the bit 0 of this register is required to be written to trigger the frequency counter
	* 1: trigger is based on safety_monitor_active
	* 0: Trigger is based on the spi write on bit 0 i.e freq_start
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t EnableFuncSafetyFreqMea : 1;        /*## attribute EnableFuncSafetyFreqMea */
	/**
	* BitsName: num_lsbbits_ignored
	* Description: Number of lsb bits to be ignored while comparing the final freq counter read value. This is required incase of frequency counter trigger is based on window_active  for functional safety. The hardware then compares the value measured by frequency counter against ideal_480_count_value ignoring the lsb bits.
	* 0001: Zeroth bit is ignored from comparison
	* 0011: Zeroth & first bits are ignored from comparison
	* 0111: Zeroth & first & second bits are ignored from comparison
	* 1111: Zeroth & first & second & third bits are ignored from comparison
	*
	* Read/Write: RW
	* Bits: [7:4]
	* ResetValue: 0b0011
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t NumLsbbitsIgnored : 4;        /*## attribute NumLsbbitsIgnored */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: freq_start
	* Description: Start the freq. count
	* 0 = idle
	* 1 = start
	*
	* Read/Write: W
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t FreqStart : 1;        /*## attribute FreqStart */
}R2M06_FreqCounterStartBits_t;
/**
* R2M06_FreqCounterReadValueBits_t
* RegisterName: FREQ_COUNTER_READ_VALUE
* Actual frequency measurement value
* Address: 0x2B8
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: xor_parity_freq_counter
	* Description: This is simple xor of all the bits in the frequency counter read value. This bit can be used by MCU to check against stuckat fault error
	* 1: Odd parity (Number of ones in the register value is odd)
	* 0: Even parity (Number of ones in the register value is even)
	* Read/Write: R
	* Bits: [31]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t XorParityFreqCounter : 1;        /*## attribute XorParityFreqCounter */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 10;        /*## attribute Reserved0 */
	/**
	* BitsName: done_flag
	* Description: Indicates that a freq count value is valid. Write to freq counter start clear this bit
	* Read/Write: R
	* Bits: [20]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: Y
	*/
	uint32_t DoneFlag : 1;        /*## attribute DoneFlag */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: freq_count_value
	* Description: Freq value computed. Actual value need to be assessed based on  the ref_cntr_init value
	* e.g ref_cntr_int = d'40 then freq value = freq count value in MHz
	* e.g ref_cntr_int = d'400 (40*10) then freq value = freq count value/10 ) in MHz
	*
	*
	* Read/Write: R
	* Bits: [17:0]
	* ResetValue: 0b000000000000000000
	* Source: Application
	* FuSa: Y
	*/
	uint32_t FreqCountValue : 18;        /*## attribute FreqCountValue */
}R2M06_FreqCounterReadValueBits_t;
/**
* R2M06_RefCounterReadValueBits_t
* RegisterName: REF_COUNTER_READ_VALUE
* Reference count value
* Address: 0x2BC
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: Y
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 16;        /*## attribute Reserved0 */
	/**
	* BitsName: counter_read_value
	* Description: Reference count value
	* Read/Write: R
	* Bits: [15:0]
	* ResetValue: 0b0000000000000000
	* Source: Reset
	* FuSa: Y
	*/
	uint32_t CounterReadValue : 16;        /*## attribute CounterReadValue */
}R2M06_RefCounterReadValueBits_t;
/**
* R2M06_LoopFilterCounterInitBits_t
* RegisterName: LOOP_FILTER_COUNTER_INIT
* Loop filter settings
* Address: 0x2C0
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 11;        /*## attribute Reserved0 */
	/**
	* BitsName: loop_filter_polarity
	* Description: The field controls the polarity and thereby counter start condition. Please refer reset_counter description
	*
	* 0: Positive polarity
	* 1 : Negative polarity
	* Read/Write: RW
	* Bits: [20]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LoopFilterPolarity : 1;        /*## attribute LoopFilterPolarity */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 1;        /*## attribute Reserved2 */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 7;        /*## attribute Reserved3 */
	/**
	* BitsName: override_reset_counter
	* Description: If this bit is set, the flag is cleared on every start condition which is generated internally based on too_low. This is to provide the user a flexibility of continuous monitoring of the counter without a need to reset manually (assumption: the counter operates on defined intervals i.e too_low and too_high conidtion happens in defined intervals)
	* 1: override reset counter by auto clear
	* 0: Manually reset_counter to be cleared by writing to bit 0 of this register
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t OverrideResetCounter : 1;        /*## attribute OverrideResetCounter */
	/**
	* BitsName: Reserved_4
	* Description: not used
	*/
	uint32_t Reserved4 : 7;        /*## attribute Reserved4 */
	/**
	* BitsName: reset_counter
	* Description: 1: Reset the counter to '0', and clear the overflow, done flag.
	*   a. Actually the real start for the counter is based on the internally generated start pulse when too_low signal toggling from 1 to 0. The counter stop condition is generated based on too_high toggling from 0 to 1. This is with polarity bit (bit20 in the same register) set to 0
	* b. Actually the real start for the counter is based on the internally generated start pulse when too_high signal toggling from 1 to 0. The counter stop condition is generated based on too_low toggling from 0 to 1. This is with polarity bit (bit20 in the same register) set to 1
	*
	*
	*
	* 0: Retain the prev value. Still the counter starts based on the conditions described but the values reflected with the previous counter value in consideration
	* Read/Write: W
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ResetCounter : 1;        /*## attribute ResetCounter */
}R2M06_LoopFilterCounterInitBits_t;
/**
* R2M06_LoopFilterCounterReadValueBits_t
* RegisterName: LOOP_FILTER_COUNTER_READ_VALUE
* Loop filter counter status
* Address: 0x2C4
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 6;        /*## attribute Reserved1 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 1;        /*## attribute Reserved2 */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 3;        /*## attribute Reserved3 */
	/**
	* BitsName: loop_filter_counter_done_flag
	* Description: Indicates that count value is valid. Gets cleared when reset_counter value is written as '1'
	* 1: Done flag is set
	* 0: Done flag not set
	* Read/Write: R
	* Bits: [20]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LoopFilterCounterDoneFlag : 1;        /*## attribute LoopFilterCounterDoneFlag */
	/**
	* BitsName: Reserved_4
	* Description: not used
	*/
	uint32_t Reserved4 : 2;        /*## attribute Reserved4 */
	/**
	* BitsName: loop_filter_counter_value
	* Description: Counter value read. Actual value need to be assessed based on  the frequency programmed (clk_ref)
	*
	*
	* Read/Write: R
	* Bits: [17:0]
	* ResetValue: 0b000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t LoopFilterCounterValue : 18;        /*## attribute LoopFilterCounterValue */
}R2M06_LoopFilterCounterReadValueBits_t;
/**
* R2M06_DivideFreqCounterStartBits_t
* RegisterName: DIVIDE_FREQ_COUNTER_START
* Trigger for divider output frequency measurement
* Address: 0x2D0
* ResetValue: 0x00000100
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 23;        /*## attribute Reserved0 */
	/**
	* BitsName: enable_func_safety_divide_freq_mea
	* Description: By default, the frequency counter is triggered based on safety_monitor_active posedge to measure the frequency deviation if any and to report to the ISM for every chirp. If this bit is disabled, then the bit 0 of this register is required to be written to trigger the frequency counter
	* 1: Trigger based on the safety_monitor_active signal
	* 0: Trigger based on the spi write of bit 0 of this reqister i.e freq_start
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b1
	* Source: Application
	* FuSa: No
	*/
	uint32_t EnableFuncSafetyDivideFreqMea : 1;        /*## attribute EnableFuncSafetyDivideFreqMea */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 4;        /*## attribute Reserved1 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: divide_freq_start
	* Description: Start the freq. count
	* 0 = idle, 1 = start
	*
	* Read/Write: W
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t DivideFreqStart : 1;        /*## attribute DivideFreqStart */
}R2M06_DivideFreqCounterStartBits_t;
/**
* R2M06_DivideFreqCounterReadValueBits_t
* RegisterName: DIVIDE_FREQ_COUNTER_READ_VALUE
* Divider output frequency measured value
* Address: 0x2D4
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: xor_parity_divide_freq_counter
	* Description: This is simple xor of all the bits in the frequency counter read value. This bit can be used by MCU to check against stuckat fault error
	* 1: Odd parity (Number of ones in the register value is odd)
	* 0: Even parity (Number of ones in the register value is even)
	* Read/Write: R
	* Bits: [31]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t XorParityDivideFreqCounter : 1;        /*## attribute XorParityDivideFreqCounter */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 10;        /*## attribute Reserved0 */
	/**
	* BitsName: divide_freq_done_flag
	* Description: Indicates that a freq count value is valid. Write to freq counter start clear this bit
	* 1: counting done
	* 0: couting not done yet
	* Read/Write: R
	* Bits: [20]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t DivideFreqDoneFlag : 1;        /*## attribute DivideFreqDoneFlag */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: divide_freq_count_value
	* Description: Based on the divider value (in the sweep control Div_update_rf_profile* field), the following ref_cntr_init value is fixed in the hardware/design.
	*
	*   240_REF_CNTR_INIT_VALUE = 18'h000F0; div by 2
	*   160_ REF_CNTR_INIT_VALUE = 18'h000A0; div by 3
	*   120_ REF_CNTR_INIT_VALUE = 18'h00078; div by 4
	*   96_ REF_CNTR_INIT_VALUE = 18'h00060;  div by 5
	*   80_ REF_CNTR_INIT_VALUE = 18'h00050; div by 6
	* Note: Still the deviations bits are programmable in in the sweep control freq_deviation_bits_profile* field)
	* Read/Write: R
	* Bits: [17:0]
	* ResetValue: 0b000000000000000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t DivideFreqCountValue : 18;        /*## attribute DivideFreqCountValue */
}R2M06_DivideFreqCounterReadValueBits_t;
/**
* R2M06_KvcoDvdtConfigControlBits_t
* RegisterName: KVCO_DVDT_CONFIG_CONTROL
* KVCO & DVDT Configuration register
* Address: 0x2DC
* ResetValue: 0x0C6F0011
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_lpf_prog_force_voltage_dvdt_spi
	* Description:  voltage forced during dvdt measurements
	* Read/Write: RW
	* Bits: [30:24]
	* ResetValue: 0b0001100
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlLpfProgForceVoltageDvdtSpi : 7;        /*## attribute CtlLpfProgForceVoltageDvdtSpi */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: ctl_lpf_prog_force_voltage_high_spi
	* Description: high voltage forced during kvco_avg measurements
	* Read/Write: RW
	* Bits: [22:16]
	* ResetValue: 0b1101111
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlLpfProgForceVoltageHighSpi : 7;        /*## attribute CtlLpfProgForceVoltageHighSpi */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 9;        /*## attribute Reserved2 */
	/**
	* BitsName: ctl_lpf_prog_force_voltage_low_spi
	* Description: low voltage forced during kvco_avg measurements
	* Read/Write: RW
	* Bits: [6:0]
	* ResetValue: 0b0010001
	* Source: Application
	* FuSa: No
	*/
	uint32_t CtlLpfProgForceVoltageLowSpi : 7;        /*## attribute CtlLpfProgForceVoltageLowSpi */
}R2M06_KvcoDvdtConfigControlBits_t;
/**
* R2M06_KvcoDvdtDelayControlBits_t
* RegisterName: KVCO_DVDT_DELAY_CONTROL
* Delay configuration for both kvco nd dvdt mesaurements
* Address: 0x2E0
* ResetValue: 0x32032028
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: vtune_force_time_dvdt
	* Description: Time for which vtune is forced during dvdt
	* Read/Write: RW
	* Bits: [31:20]
	* ResetValue: 0b001100100000
	* Source: Application
	* FuSa: No
	*/
	uint32_t VtuneForceTimeDvdt : 12;        /*## attribute VtuneForceTimeDvdt */
	/**
	* BitsName: ref_cntr_init_kvco
	* Description: the reference counter value used for kvco
	* Read/Write: RW
	* Bits: [19:8]
	* ResetValue: 0b001100100000
	* Source: Application
	* FuSa: No
	*/
	uint32_t RefCntrInitKvco : 12;        /*## attribute RefCntrInitKvco */
	/**
	* BitsName: kvco_settling_delay
	* Description: kvco setting time before dvdt measurement starts
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b00101000
	* Source: Application
	* FuSa: No
	*/
	uint32_t KvcoSettlingDelay : 8;        /*## attribute KvcoSettlingDelay */
}R2M06_KvcoDvdtDelayControlBits_t;
/**
* R2M06_KvcoCountStatusBits_t
* RegisterName: KVCO_COUNT_STATUS
* kvco frequency count read value
* Address: 0x2E4
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: cnt_high_kvco_avg_onfly
	* Description: frequency count value when the ctl_lpf_prog_force_voltage_lhigh_spi    is set
	* Read/Write: R
	* Bits: [31:16]
	* ResetValue: 0b0000000000000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CntHighKvcoAvgOnfly : 16;        /*## attribute CntHighKvcoAvgOnfly */
	/**
	* BitsName: cnt_low_kvco_avg_onfly
	* Description: frequency count value when the ctl_lpf_prog_force_voltage_low_spi    is set
	* Read/Write: R
	* Bits: [15:0]
	* ResetValue: 0b0000000000000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t CntLowKvcoAvgOnfly : 16;        /*## attribute CntLowKvcoAvgOnfly */
}R2M06_KvcoCountStatusBits_t;
/**
* R2M06_AafcLockDvdtCountStatusBits_t
* RegisterName: AAFC_LOCK_DVDT_COUNT_STATUS
* dvdt frequency count read value and aafc lock and error status
* Address: 0x2E8
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 8;        /*## attribute Reserved0 */
	/**
	* BitsName: aafc_kvco_dvdt_busy
	* Description: busy status for aafc, kvco and dvdt
	* 1 - busy
	* 0- not busy
	* Read/Write: R
	* Bits: [23]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t AafcKvcoDvdtBusy : 1;        /*## attribute AafcKvcoDvdtBusy */
	/**
	* BitsName: kvco_dvdt_error
	* Description: error status for kvco or dvdt
	* 1 - error
	* 0 - No error
	* Read/Write: R
	* Bits: [22]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t KvcoDvdtError : 1;        /*## attribute KvcoDvdtError */
	/**
	* BitsName: afc_error
	* Description: error status for afc
	* 1 - error
	* 0 - No error
	* Read/Write: R
	* Bits: [21]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t AfcError : 1;        /*## attribute AfcError */
	/**
	* BitsName: aac_error
	* Description: error status for aac
	* 1 - error
	* 0 - No error
	* Read/Write: R
	* Bits: [20]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t AacError : 1;        /*## attribute AacError */
	/**
	* BitsName: aafc_error
	* Description: error status for afc or aac
	* 1 - error
	* 0 - No error
	* Read/Write: R
	* Bits: [19]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t AafcError : 1;        /*## attribute AafcError */
	/**
	* BitsName: afc_lock
	* Description: lock status for afc
	* 1 - lock
	* 0 - No lock
	* Read/Write: R
	* Bits: [18]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t AfcLock : 1;        /*## attribute AfcLock */
	/**
	* BitsName: aac_lock
	* Description: lock status for aac
	* 1 - lock
	* 0 - No lock
	* Read/Write: R
	* Bits: [17]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t AacLock : 1;        /*## attribute AacLock */
	/**
	* BitsName: aafc_lock
	* Description: lock status for afc or aac
	* 1 - lock
	* 0 - No lock
	* Read/Write: R
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t AafcLock : 1;        /*## attribute AafcLock */
	/**
	* BitsName: done_flag_dvdt
	* Description: error status for dvdt
	* 1 -  count done
	* 0 - count error
	* Read/Write: R
	* Bits: [15]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t DoneFlagDvdt : 1;        /*## attribute DoneFlagDvdt */
	/**
	* BitsName: done_flag_kvco
	* Description: error status for kvco
	* 1 - count done
	* 0 - count error
	* Read/Write: R
	* Bits: [14]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t DoneFlagKvco : 1;        /*## attribute DoneFlagKvco */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 2;        /*## attribute Reserved1 */
	/**
	* BitsName: dvdt_cnt_c1_onfly
	* Description: frequency count value to calculate the chirp slope (dvdt) when the ctl_lpf_prog_force_voltage_ldvdt_spi    is set
	* Read/Write: R
	* Bits: [11:0]
	* ResetValue: 0b000000000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t DvdtCntC1Onfly : 12;        /*## attribute DvdtCntC1Onfly */
}R2M06_AafcLockDvdtCountStatusBits_t;
/**
* R2M06_ChirpCalibrationStatusBits_t
* RegisterName: CHIRP_CALIBRATION_STATUS
* Calibration status2
* Address: 0x310
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 6;        /*## attribute Reserved0 */
	/**
	* BitsName: aac_ireg_ctrl
	* Description: VCO current value (ivco_fine)
	* Read/Write: R
	* Bits: [25:20]
	* ResetValue: 0b000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t AacIregCtrl : 6;        /*## attribute AacIregCtrl */
	/**
	* BitsName: afc_m
	* Description: frequency loop actual Mvalue
	* Read/Write: R
	* Bits: [19:8]
	* ResetValue: 0b000000000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t AfcM : 12;        /*## attribute AfcM */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: afc_fsel_out
	* Description: vco coarse frequency tuning (subband number)
	* Read/Write: R
	* Bits: [6:0]
	* ResetValue: 0b0000000
	* Source: Application
	* FuSa: No
	*/
	uint32_t AfcFselOut : 7;        /*## attribute AfcFselOut */
}R2M06_ChirpCalibrationStatusBits_t;
/**
* R2M06_ChirpCalibrationSwControlBits_t
* RegisterName: CHIRP_CALIBRATION_SW_CONTROL
* AAFC calibration setting in the manual mode. These settings are applicable only in the non-chirping mode for debug purpose and CW mode
* Address: 0x3A0
* ResetValue: 0x01001030
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 3;        /*## attribute Reserved0 */
	/**
	* BitsName: profile_load_for_calibration
	* Description: Software based profile load for loading the profile information in Chirp TX and RX for Calibration. If en_profile_for_calibration bit is 1, use_profile_for_caibration is selected in the profile sequencer to generate the active profile value. This is an auto clear bit. once it is triggered the use_profile_for_calibration  will be active till the chirp start
	* Read/Write: W
	* Bits: [28]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ProfileLoadForCalibration : 1;        /*## attribute ProfileLoadForCalibration */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: en_profile_for_calibration
	* Description: profile enable bit for CW (non-chirping) mode calibration
	* Note:
	* timing_engine -> CHIRP_GLOBAL_CONTROL -> chirp_enable is used for loading the profile during the chirping mode
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t EnProfileForCalibration : 1;        /*## attribute EnProfileForCalibration */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: store_in_profile8
	* Description: calibration , kvco & dvdt results to be stored in profile 8 registers
	* Read/Write: RW
	* Bits: [20]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t StoreInProfile8 : 1;        /*## attribute StoreInProfile8 */
	/**
	* BitsName: store_in_profile7
	* Description: calibration , kvco & dvdtresults to be stored in profile 7 registers
	* Read/Write: RW
	* Bits: [19]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t StoreInProfile7 : 1;        /*## attribute StoreInProfile7 */
	/**
	* BitsName: store_in_profile6
	* Description: calibration , kvco & dvdt results to be stored in profile 6 registers
	* Read/Write: RW
	* Bits: [18]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t StoreInProfile6 : 1;        /*## attribute StoreInProfile6 */
	/**
	* BitsName: store_in_profile5
	* Description: calibration , kvco & dvdt results to be stored in profile 5 registers
	* Read/Write: RW
	* Bits: [17]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t StoreInProfile5 : 1;        /*## attribute StoreInProfile5 */
	/**
	* BitsName: store_in_profile4
	* Description: calibration , kvco & dvdt results to be stored in profile 4 registers
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t StoreInProfile4 : 1;        /*## attribute StoreInProfile4 */
	/**
	* BitsName: store_in_profile3
	* Description: calibration , kvco & dvdt results to be stored in profile 3 registers
	* Read/Write: RW
	* Bits: [15]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t StoreInProfile3 : 1;        /*## attribute StoreInProfile3 */
	/**
	* BitsName: store_in_profile2
	* Description: calibration , kvco & dvdt results to be stored in profile 2 registers
	* Read/Write: RW
	* Bits: [14]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t StoreInProfile2 : 1;        /*## attribute StoreInProfile2 */
	/**
	* BitsName: store_in_profile1
	* Description: calibration , kvco & dvdt results to be stored in profile 1 registers
	* Read/Write: RW
	* Bits: [13]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t StoreInProfile1 : 1;        /*## attribute StoreInProfile1 */
	/**
	* BitsName: store_in_profile0
	* Description: calibration , kvco & dvdt results to be stored in profile 0 registers
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t StoreInProfile0 : 1;        /*## attribute StoreInProfile0 */
	/**
	* BitsName: use_profile_for_calibration
	* Description: profile number that will be used for CW (non-chirping) mode calibration
	* Read/Write: RW
	* Bits: [11:8]
	* ResetValue: 0b0000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t UseProfileForCalibration : 4;        /*## attribute UseProfileForCalibration */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 2;        /*## attribute Reserved3 */
	/**
	* BitsName: kvco_dvdt_enable
	* Description: Enable for bothe kvco and dvdt measureemnts
	* 00 - Both are disabled
	* 01 - KVCO enabled
	* 10 - DVDT enabled
	* 11 - Both are enabled
	* Read/Write: RW
	* Bits: [5:4]
	* ResetValue: 0b11
	* Source: Reset
	* FuSa: No
	*/
	uint32_t KvcoDvdtEnable : 2;        /*## attribute KvcoDvdtEnable */
	/**
	* BitsName: Reserved_4
	* Description: not used
	*/
	uint32_t Reserved4 : 3;        /*## attribute Reserved4 */
	/**
	* BitsName: start_chirp_calibration
	* Description: start calibration by manual trigger
	*
	* 0 : No operation
	* 1 : Start AAFC calibration
	* Read/Write: W
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t StartChirpCalibration : 1;        /*## attribute StartChirpCalibration */
}R2M06_ChirpCalibrationSwControlBits_t;
/**
* R2M06_ChirpCalibrationTimeoutDelayBits_t
* RegisterName: CHIRP_CALIBRATION_TIMEOUT_DELAY
* AAFC calibration setting in the manual mode. These settings are applicable only in the non-chirping mode for debug purpose and CW mode
* Address: 0x3A4
* ResetValue: 0x00001F40
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 7;        /*## attribute Reserved0 */
	/**
	* BitsName: abort_chirp_calibration
	* Description: Abort the AAFC calibration
	*
	* 0 : No operation
	* 1 : Abort the calibration. This bit is auto cleared
	* Read/Write: W
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Application
	* FuSa: No
	*/
	uint32_t AbortChirpCalibration : 1;        /*## attribute AbortChirpCalibration */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 10;        /*## attribute Reserved1 */
	/**
	* BitsName: chirp_aafc_calibration_timeout_counter
	* Description: The timeout counter is used only when the chirp is in cw mode and chirp aafc calibration is triggered. If the calibration fails, the safety flag is asserted towards ISM
	* Read/Write: RW
	* Bits: [13:0]
	* ResetValue: 0b01111101000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t ChirpAafcCalibrationTimeoutCounter : 14;        /*## attribute ChirpAafcCalibrationTimeoutCounter */
}R2M06_ChirpCalibrationTimeoutDelayBits_t;
/**
* R2M06_Atb1Bits_t
* RegisterName: ATB1
* ATB1 bus settings.
* Address: 0xC04
* ResetValue: 0x000000FF
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 23;        /*## attribute Reserved0 */
	/**
	* BitsName: atb1_en
	* Description: Enable DC Test Bus
	* 1: Enable testbus
	* 0: Disable testbus
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Atb1En : 1;        /*## attribute Atb1En */
	/**
	* BitsName: atb1_set
	* Description: 8'h01 :  level_vco_min (Functional Safety VCO amplitude monitor min threshold)
	* 8'h02:   level_vco_low (Functional Safety VCO amplitude monitor low threshold)
	* 8'h03:   level_vco_high(Functional Safety VCO amplitude monitor high threshold)
	* 8'h04:   level_vco_max(Functional Safety VCO amplitude monitor max threshold)
	* 8'h05:   rms_det_ref(RMS detector reference voltage)
	* 8'h06:   rms_det (RMS detector output voltage)
	* 8'h07:   temp_sns_buffer(Temperature sensor buffer output)
	* 8'h08:   temp_sns_comp(Functional Safety Temperature Monitor comparator input (unbuffered temperature sensor output))
	* 8'h09:   vco_ibias (Reference currents for  enabled by ctl_vco_pbusp_i100u_test_en)
	* 8'h0A:  vco_ind_cnt_tap_1g  (1g VCO center voltage)
	* 8'h0B:  vco_ind_cnt_tap_5g (5g VCO center voltage)
	* 8'h0C:   vtune_level_high (Functional Safety VCO tuning voltage monitor high threshold can be tuned by ctl_vtune_vco_high_spi)
	* 8'h0D:   vtune_level_low (Functional Safety VCO tuning voltage monitorlow threshold. can be tuned by ctl_vtune_vco_low_spi)
	* 8'h0E:   ldo_divider_vdd (Analog divider 1.1V supply: Locally divided 3/11 (300mV typ); can be tuned by ctl_ldo_divider_sel_vout_spi)
	* 8'h0F:   ldo_cppfd_vdd (Analog Charge Pump/Phase Detector 1.1V supply:Locally divided 3/11 (300mV typ); can be tuned by ctl_ldo_cppfd_sel_vout_spi)
	* 8'h10:   ldo_vco_vdd (Analog VCO 1.1V supply: Locally divided 3/11 ( 300mV typ); can be tuned by ctl_ldo_vco_sel_vout_spi)
	* 8'h11:   vdd_pll_1v8 (PLL analog 1.8V supply; Locally divided 1/6 (300mV typ))
	* 8'h12:   vdd_vco_1v8 (VCO analog 1.8V supply; Loacally divided 1/6 ( 300mV typ))
	* 8'h13:   ibias_cp_150u (Charge Pump current;: 150uA (typ); locally I/V converted trim-able resistor (4k); )
	* 8'h14:   ibias_ref_100u (BG Reference current;:100uA (typ); locally I/V converted trim-able resistor (4k); )
	* 8'h15:   vdd_pll_1v1 (Analog PLL 1.1V supply: Locally divided 3/11 (300mV typ))
	* Read/Write: RW
	* Bits: [7:0]
	* ResetValue: 0b11111111
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Atb1Set : 8;        /*## attribute Atb1Set */
}R2M06_Atb1Bits_t;
/**
* R2M06_DftIdacControlBits_t
* RegisterName: DFT_IDAC_CONTROL
* Kept for future use
* Address: 0xC08
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 28;        /*## attribute Reserved0 */
	/**
	* BitsName: ctl_idac_trim_en_spi
	* Description: IDAC Trim Enable bit
	* Read/Write: RW
	* Bits: [3]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CtlIdacTrimEnSpi : 1;        /*## attribute CtlIdacTrimEnSpi */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 1;        /*## attribute Reserved2 */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 1;        /*## attribute Reserved3 */
}R2M06_DftIdacControlBits_t;
/**
* R2M06_MaskCcResetErrorBits_t
* RegisterName: MASK_CC_RESET_ERROR
* This register is kept for validation and not to be used in the functional context. This register is used to mask the reset errors
* Address: 0xE04
* ResetValue: 0x00E00000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: mask_vco_freq_480_reset_error
	* Description: mask vco 480 freq reset error
	* 1:  mask vco supply reset error
	* 0:  do not mask vco supply reset error
	* Read/Write: RW
	* Bits: [31]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskVcoFreq480ResetError : 1;        /*## attribute MaskVcoFreq480ResetError */
	/**
	* BitsName: mask_divide_freq_reset_error
	* Description: mask sweep control divide freq reset error
	* 1:  mask sweep control divide freq reset error
	* 0:  do not mask sweep control divide freq reset error
	*
	* Read/Write: RW
	* Bits: [30]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskDivideFreqResetError : 1;        /*## attribute MaskDivideFreqResetError */
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: mask_supply_dig_reset_error
	* Description: If set to '1', masks the reset_error generated by the central control towards the sensor
	* 1:  mask digital supply reset error
	* 0:  do not mask vco supply reset error
	* Read/Write: RW
	* Bits: [28]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskSupplyDigResetError : 1;        /*## attribute MaskSupplyDigResetError */
	/**
	* BitsName: mask_afc_stuckat_transient_reset_error
	* Description: If set to '1', masks the reset_error generated by the central control towards the sensor
	* 1:  mask stuckat/transient reset error at chirp_afc
	* 0:  do not mask stuckat/transient  reset error
	* Read/Write: RW
	* Bits: [27]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskAfcStuckatTransientResetError : 1;        /*## attribute MaskAfcStuckatTransientResetError */
	/**
	* BitsName: mask_sc_stuckat_transient_reset_error
	* Description: If set to '1', masks the force_error generated by the central control towards the sensor
	* 1:  mask stuckat/transient reset error at sweep control
	* 0:  do not mask stuckat/transient reset error
	* Read/Write: RW
	* Bits: [26]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskScStuckatTransientResetError : 1;        /*## attribute MaskScStuckatTransientResetError */
	/**
	* BitsName: mask_te_stuckat_transient_reset_error
	* Description: If set to '1', masks the reset_error generated by the central control towards the sensor
	* 1:  mask stuckat/transient reset error at timing engine
	* 0:  do not mask stuckat/transient reset error
	* Read/Write: RW
	* Bits: [25]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskTeStuckatTransientResetError : 1;        /*## attribute MaskTeStuckatTransientResetError */
	/**
	* BitsName: mask_combined_stuckat_transient_reset_error
	* Description: If set to '1', masks the force_error generated by the central control towards the sensor
	* 1:  mask stuckat/transient combined reset error
	* 0:  do not mask stuckat/transient reset error
	* Read/Write: RW
	* Bits: [24]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskCombinedStuckatTransientResetError : 1;        /*## attribute MaskCombinedStuckatTransientResetError */
	/**
	* BitsName: mask_afc_reg_crc_reset_error
	* Description: If set to '1', masks the reset_error generated by the central control towards the sensor
	* 1:  mask crc reset error  at chirp_afc
	* 0:  do not mask crc reset error
	* Read/Write: RW
	* Bits: [23]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskAfcRegCrcResetError : 1;        /*## attribute MaskAfcRegCrcResetError */
	/**
	* BitsName: mask_sc_reg_crc_reset_error
	* Description: If set to '1', masks the reset_error generated by the central control towards the sensor
	* 1:  mask crc reset error  at sweep control
	* 0:  do not mask crc reset error
	* Read/Write: RW
	* Bits: [22]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskScRegCrcResetError : 1;        /*## attribute MaskScRegCrcResetError */
	/**
	* BitsName: mask_te_reg_crc_reset_error
	* Description: If set to '1', masks the reset_error generated by the central control towards the sensor
	* 1:  mask crc reset error at timing engine
	* 0:  do not mask crc reset error
	* Read/Write: RW
	* Bits: [21]
	* ResetValue: 0b1
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskTeRegCrcResetError : 1;        /*## attribute MaskTeRegCrcResetError */
	/**
	* BitsName: mask_max_temp_reset_error
	* Description: If set to '1', masks the reset_error generated by the central control towards the sensor
	* 1:  mask temp reset error
	* 0:  do not mask temp reset error
	* Read/Write: RW
	* Bits: [20]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskMaxTempResetError : 1;        /*## attribute MaskMaxTempResetError */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 3;        /*## attribute Reserved1 */
	/**
	* BitsName: mask_supply_pll_reset_error
	* Description: If set to '1', masks the reset_error generated by the central control towards the sensor.
	* 1:  mask pll supply reset error
	* 0:  do not mask pll supply reset error
	* Read/Write: RW
	* Bits: [16]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskSupplyPllResetError : 1;        /*## attribute MaskSupplyPllResetError */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 3;        /*## attribute Reserved2 */
	/**
	* BitsName: mask_supply_vco_reset_error
	* Description: If set to '1', masks the reset_error generated by the central control towards the sensor.
	* 1:  mask vco supply reset error
	* 0:  do not mask vco supply reset error
	* Read/Write: RW
	* Bits: [12]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskSupplyVcoResetError : 1;        /*## attribute MaskSupplyVcoResetError */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 1;        /*## attribute Reserved3 */
	/**
	* BitsName: mask_aafc_cal_timeout_reset_error
	* Description: If set to '1', masks the reset_error generated by the central control towards the sensor.
	* 1:  mask aafc cal timeout reset error
	* 0:  do not mask aafc cal timeout reset error
	* Read/Write: RW
	* Bits: [10]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskAafcCalTimeoutResetError : 1;        /*## attribute MaskAafcCalTimeoutResetError */
	/**
	* BitsName: mask_aafc_reset_error
	* Description: If set to '1', masks the reset_error generated by the central control towards the sensor.
	* 1:  mask aafc reset error
	* 0:  do not mask aafc reset error
	* Read/Write: RW
	* Bits: [9]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskAafcResetError : 1;        /*## attribute MaskAafcResetError */
	/**
	* BitsName: mask_unlock_reset_error
	* Description: If set to '1', masks the reset_error generated by the central control towards the sensor.
	* 1:  mask unlock reset error
	* 0:  do not mask unlock reset error
	* Read/Write: RW
	* Bits: [8]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskUnlockResetError : 1;        /*## attribute MaskUnlockResetError */
	/**
	* BitsName: Reserved_4
	* Description: not used
	*/
	uint32_t Reserved4 : 3;        /*## attribute Reserved4 */
	/**
	* BitsName: mask_vtune_reset_error
	* Description: If set to '1', masks the reset_error generated by the central control towards the sensor.
	* 1:  mask vtune reset error
	* 0:  do not mask vtune reset error
	* Read/Write: RW
	* Bits: [4]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskVtuneResetError : 1;        /*## attribute MaskVtuneResetError */
	/**
	* BitsName: Reserved_5
	* Description: not used
	*/
	uint32_t Reserved5 : 3;        /*## attribute Reserved5 */
	/**
	* BitsName: mask_level_reset_error
	* Description: If set to '1', masks the reset_error generated by the central control towards the sensor.
	* 1:  mask level reset error
	* 0:  do not mask level reset error
	*
	* Note: There is only one level_reset_error towards analog.
	* Read/Write: RW
	* Bits: [0]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskLevelResetError : 1;        /*## attribute MaskLevelResetError */
}R2M06_MaskCcResetErrorBits_t;
/**
* R2M06_MaskCcErrorFlagBits_t
* RegisterName: MASK_CC_ERROR_FLAG
* This register is kept for validation and not to be used in the functional context. This register is used to mask the flags from the sensor going to the central control
* Address: 0xE08
* ResetValue: 0x00000000
* Read/Write: RW
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: Reserved_0
	* Description: not used
	*/
	uint32_t Reserved0 : 1;        /*## attribute Reserved0 */
	/**
	* BitsName: Reserved_1
	* Description: not used
	*/
	uint32_t Reserved1 : 1;        /*## attribute Reserved1 */
	/**
	* BitsName: Reserved_2
	* Description: not used
	*/
	uint32_t Reserved2 : 1;        /*## attribute Reserved2 */
	/**
	* BitsName: Reserved_3
	* Description: not used
	*/
	uint32_t Reserved3 : 1;        /*## attribute Reserved3 */
	/**
	* BitsName: Reserved_4
	* Description: not used
	*/
	uint32_t Reserved4 : 1;        /*## attribute Reserved4 */
	/**
	* BitsName: Reserved_5
	* Description: not used
	*/
	uint32_t Reserved5 : 1;        /*## attribute Reserved5 */
	/**
	* BitsName: mask_te_stuckat_transient_error_flag
	* Description: If set to '1', the *_error_flag from the IP  is masked and will not be forwarded to central control
	* 1:  mask the stuckat/transient error at timing_engine
	* 0:  do not mask stuckat/transient  error
	* Read/Write: RW
	* Bits: [25]
	* ResetValue: 0b0
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MaskTeStuckatTransientErrorFlag : 1;        /*## attribute MaskTeStuckatTransientErrorFlag */
	/**
	* BitsName: Reserved_6
	* Description: not used
	*/
	uint32_t Reserved6 : 1;        /*## attribute Reserved6 */
	/**
	* BitsName: Reserved_7
	* Description: not used
	*/
	uint32_t Reserved7 : 1;        /*## attribute Reserved7 */
	/**
	* BitsName: Reserved_8
	* Description: not used
	*/
	uint32_t Reserved8 : 1;        /*## attribute Reserved8 */
	/**
	* BitsName: Reserved_9
	* Description: not used
	*/
	uint32_t Reserved9 : 1;        /*## attribute Reserved9 */
	/**
	* BitsName: Reserved_10
	* Description: not used
	*/
	uint32_t Reserved10 : 1;        /*## attribute Reserved10 */
	/**
	* BitsName: Reserved_11
	* Description: not used
	*/
	uint32_t Reserved11 : 3;        /*## attribute Reserved11 */
	/**
	* BitsName: Reserved_12
	* Description: not used
	*/
	uint32_t Reserved12 : 1;        /*## attribute Reserved12 */
	/**
	* BitsName: Reserved_13
	* Description: not used
	*/
	uint32_t Reserved13 : 3;        /*## attribute Reserved13 */
	/**
	* BitsName: Reserved_14
	* Description: not used
	*/
	uint32_t Reserved14 : 1;        /*## attribute Reserved14 */
	/**
	* BitsName: Reserved_15
	* Description: not used
	*/
	uint32_t Reserved15 : 1;        /*## attribute Reserved15 */
	/**
	* BitsName: Reserved_16
	* Description: not used
	*/
	uint32_t Reserved16 : 1;        /*## attribute Reserved16 */
	/**
	* BitsName: Reserved_17
	* Description: not used
	*/
	uint32_t Reserved17 : 1;        /*## attribute Reserved17 */
	/**
	* BitsName: Reserved_18
	* Description: not used
	*/
	uint32_t Reserved18 : 1;        /*## attribute Reserved18 */
	/**
	* BitsName: Reserved_19
	* Description: not used
	*/
	uint32_t Reserved19 : 3;        /*## attribute Reserved19 */
	/**
	* BitsName: Reserved_20
	* Description: not used
	*/
	uint32_t Reserved20 : 1;        /*## attribute Reserved20 */
	/**
	* BitsName: Reserved_21
	* Description: not used
	*/
	uint32_t Reserved21 : 1;        /*## attribute Reserved21 */
	/**
	* BitsName: Reserved_22
	* Description: not used
	*/
	uint32_t Reserved22 : 1;        /*## attribute Reserved22 */
	/**
	* BitsName: Reserved_23
	* Description: not used
	*/
	uint32_t Reserved23 : 1;        /*## attribute Reserved23 */
	/**
	* BitsName: Reserved_24
	* Description: not used
	*/
	uint32_t Reserved24 : 1;        /*## attribute Reserved24 */
}R2M06_MaskCcErrorFlagBits_t;
/**
* R2M06_CrcErrorStatus1Bits_t
* RegisterName: CRC_ERROR_STATUS1
* Status of the CRC for each register
* Address: 0xF40
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: crc_error_status_reg1
	* Description: Each bit represent the error status of the corresponding register
	*
	* 0 : No error
	* 1 : CRC error
	*
	* Note: The status corresponds the first 32 registers listed i.e registers 31(msb) down to 0(lsb)
	* Read/Write: R
	* Bits: [31:0]
	* ResetValue: 0b00000000000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CrcErrorStatusReg1 : 32;        /*## attribute CrcErrorStatusReg1 */
}R2M06_CrcErrorStatus1Bits_t;
/**
* R2M06_CrcErrorStatus2Bits_t
* RegisterName: CRC_ERROR_STATUS2
* Status of the CRC for each register
* Address: 0xF44
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: crc_error_status_reg2
	* Description: Each bit represent the error status of the corresponding register
	*
	* 0 : No error
	* 1 : CRC error
	*
	* Note: The status corresponds to next 32 registers listed i.e registers 63(msb) down to 32(lsb)
	* Read/Write: R
	* Bits: [31:0]
	* ResetValue: 0b00000000000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CrcErrorStatusReg2 : 32;        /*## attribute CrcErrorStatusReg2 */
}R2M06_CrcErrorStatus2Bits_t;
/**
* R2M06_CrcErrorStatus3Bits_t
* RegisterName: CRC_ERROR_STATUS3
* Status of the CRC for each register
* Address: 0xF48
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: crc_error_status_reg3
	* Description: Each bit represent the error status of the corresponding register
	*
	* 0 : No error
	* 1 : CRC error
	*
	* Note: The status corresponds to next 32 registers listed i.e registers 95(msb) down to 64(lsb)
	* Read/Write: R
	* Bits: [31:0]
	* ResetValue: 0b00000000000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CrcErrorStatusReg3 : 32;        /*## attribute CrcErrorStatusReg3 */
}R2M06_CrcErrorStatus3Bits_t;
/**
* R2M06_CrcErrorStatus4Bits_t
* RegisterName: CRC_ERROR_STATUS4
* Status of the CRC for each register
* Address: 0xF4C
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: crc_error_status_reg4
	* Description: Each bit represent the error status of the corresponding register
	*
	* 0 : No error
	* 1 : CRC error
	*
	* Note: The status corresponds to next 32 registers listed i.e registers 127(msb) down to 96(lsb)
	* Read/Write: R
	* Bits: [31:0]
	* ResetValue: 0b00000000000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CrcErrorStatusReg4 : 32;        /*## attribute CrcErrorStatusReg4 */
}R2M06_CrcErrorStatus4Bits_t;
/**
* R2M06_CrcErrorStatus5Bits_t
* RegisterName: CRC_ERROR_STATUS5
* Status of the CRC for each register
* Address: 0xF50
* ResetValue: 0x00000000
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: crc_error_status_reg5
	* Description: Each bit represent the error status of the corresponding register
	*
	* 0 : No error
	* 1 : CRC error
	*
	* Note: The status corresponds to last 3 registers listed i.e registers 130(msb) down to 128(lsb) and other bits are not valid
	* Read/Write: R
	* Bits: [31:0]
	* ResetValue: 0b00000000000000000000000000000000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t CrcErrorStatusReg5 : 32;        /*## attribute CrcErrorStatusReg5 */
}R2M06_CrcErrorStatus5Bits_t;
/**
* R2M06_ModuleIdBits_t
* RegisterName: MODULE_ID
* Module ID register
* Address: 0xFFC
* ResetValue: 0x00065001
* Read/Write: R
* FuSa: No
*/
typedef struct  {
	/**
	* BitsName: identifier
	* Description: This is the unique identifier of the module
	* Read/Write: R
	* Bits: [31:16]
	* ResetValue: 0b0000000000000110
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Identifier : 16;        /*## attribute Identifier */
	/**
	* BitsName: major_revision
	* Description: Major revision i.e. implies software modifications
	* Read/Write: R
	* Bits: [15:12]
	* ResetValue: 0b0101
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MajorRevision : 4;        /*## attribute MajorRevision */
	/**
	* BitsName: minor_revision
	* Description: Minor revision number i.e. with no software consequences
	* Read/Write: R
	* Bits: [11:8]
	* ResetValue: 0b0000
	* Source: Reset
	* FuSa: No
	*/
	uint32_t MinorRevision : 4;        /*## attribute MinorRevision */
	/**
	* BitsName: aperture
	* Description: Aperture. Fixed value of 'h01
	* Read/Write: R
	* Bits: [7:0]
	* ResetValue: 0b00000001
	* Source: Reset
	* FuSa: No
	*/
	uint32_t Aperture : 8;        /*## attribute Aperture */
}R2M06_ModuleIdBits_t;
#endif
/**
* R2M06_CpControlUnion_t
* R2M06_CpControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_CpControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_CpControlUnion_t;

/**
* R2M06_VcoControlUnion_t
* R2M06_VcoControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_VcoControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_VcoControlUnion_t;

/**
* R2M06_VcoBufferLdoControlUnion_t
* R2M06_VcoBufferLdoControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_VcoBufferLdoControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_VcoBufferLdoControlUnion_t;

/**
* R2M06_CppfdLdoControlUnion_t
* R2M06_CppfdLdoControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_CppfdLdoControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_CppfdLdoControlUnion_t;

/**
* R2M06_DividerLdoControlUnion_t
* R2M06_DividerLdoControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_DividerLdoControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_DividerLdoControlUnion_t;

/**
* R2M06_LdoEnControlUnion_t
* R2M06_LdoEnControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_LdoEnControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_LdoEnControlUnion_t;

/**
* R2M06_BiasBlockControlUnion_t
* R2M06_BiasBlockControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_BiasBlockControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_BiasBlockControlUnion_t;

/**
* R2M06_BufferControlUnion_t
* R2M06_BufferControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_BufferControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_BufferControlUnion_t;

/**
* R2M06_PllFastResetInjEnControlUnion_t
* R2M06_PllFastResetInjEnControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_PllFastResetInjEnControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_PllFastResetInjEnControlUnion_t;

/**
* R2M06_PllFastResetTimingControlUnion_t
* R2M06_PllFastResetTimingControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_PllFastResetTimingControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_PllFastResetTimingControlUnion_t;

/**
* R2M06_CpFastResetSliceControlUnion_t
* R2M06_CpFastResetSliceControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_CpFastResetSliceControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_CpFastResetSliceControlUnion_t;

/**
* R2M06_PllLpfCapGsSelControlUnion_t
* R2M06_PllLpfCapGsSelControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_PllLpfCapGsSelControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_PllLpfCapGsSelControlUnion_t;

/**
* R2M06_PllDacInjAcqControlUnion_t
* R2M06_PllDacInjAcqControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_PllDacInjAcqControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_PllDacInjAcqControlUnion_t;

/**
* R2M06_PllDacInjRstControlUnion_t
* R2M06_PllDacInjRstControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_PllDacInjRstControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_PllDacInjRstControlUnion_t;

/**
* R2M06_PllDacInjIbiasControlUnion_t
* R2M06_PllDacInjIbiasControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_PllDacInjIbiasControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_PllDacInjIbiasControlUnion_t;

/**
* R2M06_CpPllbwCfg0Union_t
* R2M06_CpPllbwCfg0Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_CpPllbwCfg0Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_CpPllbwCfg0Union_t;

/**
* R2M06_PllLpfC1PllbwCfg0Union_t
* R2M06_PllLpfC1PllbwCfg0Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_PllLpfC1PllbwCfg0Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_PllLpfC1PllbwCfg0Union_t;

/**
* R2M06_PllLpfC2PllbwCfg0Union_t
* R2M06_PllLpfC2PllbwCfg0Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_PllLpfC2PllbwCfg0Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_PllLpfC2PllbwCfg0Union_t;

/**
* R2M06_PllLpfC3PllbwCfg0Union_t
* R2M06_PllLpfC3PllbwCfg0Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_PllLpfC3PllbwCfg0Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_PllLpfC3PllbwCfg0Union_t;

/**
* R2M06_PllLpfResPllbwCfg0Union_t
* R2M06_PllLpfResPllbwCfg0Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_PllLpfResPllbwCfg0Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_PllLpfResPllbwCfg0Union_t;

/**
* R2M06_CpPllbwCfg1Union_t
* R2M06_CpPllbwCfg1Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_CpPllbwCfg1Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_CpPllbwCfg1Union_t;

/**
* R2M06_PllLpfC1PllbwCfg1Union_t
* R2M06_PllLpfC1PllbwCfg1Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_PllLpfC1PllbwCfg1Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_PllLpfC1PllbwCfg1Union_t;

/**
* R2M06_PllLpfC2PllbwCfg1Union_t
* R2M06_PllLpfC2PllbwCfg1Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_PllLpfC2PllbwCfg1Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_PllLpfC2PllbwCfg1Union_t;

/**
* R2M06_PllLpfC3PllbwCfg1Union_t
* R2M06_PllLpfC3PllbwCfg1Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_PllLpfC3PllbwCfg1Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_PllLpfC3PllbwCfg1Union_t;

/**
* R2M06_PllLpfResPllbwCfg1Union_t
* R2M06_PllLpfResPllbwCfg1Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_PllLpfResPllbwCfg1Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_PllLpfResPllbwCfg1Union_t;

/**
* R2M06_CpPllbwCfg2Union_t
* R2M06_CpPllbwCfg2Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_CpPllbwCfg2Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_CpPllbwCfg2Union_t;

/**
* R2M06_PllLpfC1PllbwCfg2Union_t
* R2M06_PllLpfC1PllbwCfg2Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_PllLpfC1PllbwCfg2Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_PllLpfC1PllbwCfg2Union_t;

/**
* R2M06_PllLpfC2PllbwCfg2Union_t
* R2M06_PllLpfC2PllbwCfg2Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_PllLpfC2PllbwCfg2Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_PllLpfC2PllbwCfg2Union_t;

/**
* R2M06_PllLpfC3PllbwCfg2Union_t
* R2M06_PllLpfC3PllbwCfg2Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_PllLpfC3PllbwCfg2Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_PllLpfC3PllbwCfg2Union_t;

/**
* R2M06_PllLpfResPllbwCfg2Union_t
* R2M06_PllLpfResPllbwCfg2Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_PllLpfResPllbwCfg2Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_PllLpfResPllbwCfg2Union_t;

/**
* R2M06_CpPllbwCfg3Union_t
* R2M06_CpPllbwCfg3Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_CpPllbwCfg3Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_CpPllbwCfg3Union_t;

/**
* R2M06_PllLpfC1PllbwCfg3Union_t
* R2M06_PllLpfC1PllbwCfg3Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_PllLpfC1PllbwCfg3Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_PllLpfC1PllbwCfg3Union_t;

/**
* R2M06_PllLpfC2PllbwCfg3Union_t
* R2M06_PllLpfC2PllbwCfg3Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_PllLpfC2PllbwCfg3Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_PllLpfC2PllbwCfg3Union_t;

/**
* R2M06_PllLpfC3PllbwCfg3Union_t
* R2M06_PllLpfC3PllbwCfg3Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_PllLpfC3PllbwCfg3Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_PllLpfC3PllbwCfg3Union_t;

/**
* R2M06_PllLpfResPllbwCfg3Union_t
* R2M06_PllLpfResPllbwCfg3Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_PllLpfResPllbwCfg3Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_PllLpfResPllbwCfg3Union_t;

/**
* R2M06_CpPllbwCfgHigh1GUnion_t
* R2M06_CpPllbwCfgHigh1GUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_CpPllbwCfgHigh1GBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_CpPllbwCfgHigh1GUnion_t;

/**
* R2M06_PllLpfCapPllbwCfgHigh1GUnion_t
* R2M06_PllLpfCapPllbwCfgHigh1GUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_PllLpfCapPllbwCfgHigh1GBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_PllLpfCapPllbwCfgHigh1GUnion_t;

/**
* R2M06_CpPllbwCfgHigh2GUnion_t
* R2M06_CpPllbwCfgHigh2GUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_CpPllbwCfgHigh2GBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_CpPllbwCfgHigh2GUnion_t;

/**
* R2M06_PllLpfCapPllbwCfgHigh2GUnion_t
* R2M06_PllLpfCapPllbwCfgHigh2GUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_PllLpfCapPllbwCfgHigh2GBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_PllLpfCapPllbwCfgHigh2GUnion_t;

/**
* R2M06_CpPllbwCfgHigh4GUnion_t
* R2M06_CpPllbwCfgHigh4GUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_CpPllbwCfgHigh4GBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_CpPllbwCfgHigh4GUnion_t;

/**
* R2M06_PllLpfCapPllbwCfgHigh4GUnion_t
* R2M06_PllLpfCapPllbwCfgHigh4GUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_PllLpfCapPllbwCfgHigh4GBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_PllLpfCapPllbwCfgHigh4GUnion_t;

/**
* R2M06_PllLpfResPllbwCfgHighUnion_t
* R2M06_PllLpfResPllbwCfgHighUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_PllLpfResPllbwCfgHighBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_PllLpfResPllbwCfgHighUnion_t;

/**
* R2M06_VcoRegProfile0Union_t
* R2M06_VcoRegProfile0Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_VcoRegProfile0Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_VcoRegProfile0Union_t;

/**
* R2M06_LpfInjAcqRstProfile0Union_t
* R2M06_LpfInjAcqRstProfile0Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_LpfInjAcqRstProfile0Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_LpfInjAcqRstProfile0Union_t;

/**
* R2M06_VcoRegProfile1Union_t
* R2M06_VcoRegProfile1Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_VcoRegProfile1Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_VcoRegProfile1Union_t;

/**
* R2M06_LpfInjAcqRstProfile1Union_t
* R2M06_LpfInjAcqRstProfile1Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_LpfInjAcqRstProfile1Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_LpfInjAcqRstProfile1Union_t;

/**
* R2M06_VcoRegProfile2Union_t
* R2M06_VcoRegProfile2Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_VcoRegProfile2Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_VcoRegProfile2Union_t;

/**
* R2M06_LpfInjAcqRstProfile2Union_t
* R2M06_LpfInjAcqRstProfile2Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_LpfInjAcqRstProfile2Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_LpfInjAcqRstProfile2Union_t;

/**
* R2M06_VcoRegProfile3Union_t
* R2M06_VcoRegProfile3Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_VcoRegProfile3Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_VcoRegProfile3Union_t;

/**
* R2M06_LpfInjAcqRstProfile3Union_t
* R2M06_LpfInjAcqRstProfile3Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_LpfInjAcqRstProfile3Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_LpfInjAcqRstProfile3Union_t;

/**
* R2M06_VcoRegProfile4Union_t
* R2M06_VcoRegProfile4Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_VcoRegProfile4Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_VcoRegProfile4Union_t;

/**
* R2M06_LpfInjAcqRstProfile4Union_t
* R2M06_LpfInjAcqRstProfile4Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_LpfInjAcqRstProfile4Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_LpfInjAcqRstProfile4Union_t;

/**
* R2M06_VcoRegProfile5Union_t
* R2M06_VcoRegProfile5Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_VcoRegProfile5Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_VcoRegProfile5Union_t;

/**
* R2M06_LpfInjAcqRstProfile5Union_t
* R2M06_LpfInjAcqRstProfile5Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_LpfInjAcqRstProfile5Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_LpfInjAcqRstProfile5Union_t;

/**
* R2M06_VcoRegProfile6Union_t
* R2M06_VcoRegProfile6Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_VcoRegProfile6Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_VcoRegProfile6Union_t;

/**
* R2M06_LpfInjAcqRstProfile6Union_t
* R2M06_LpfInjAcqRstProfile6Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_LpfInjAcqRstProfile6Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_LpfInjAcqRstProfile6Union_t;

/**
* R2M06_VcoRegProfile7Union_t
* R2M06_VcoRegProfile7Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_VcoRegProfile7Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_VcoRegProfile7Union_t;

/**
* R2M06_LpfInjAcqRstProfile7Union_t
* R2M06_LpfInjAcqRstProfile7Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_LpfInjAcqRstProfile7Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_LpfInjAcqRstProfile7Union_t;

/**
* R2M06_VcoRegProfile8Union_t
* R2M06_VcoRegProfile8Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_VcoRegProfile8Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_VcoRegProfile8Union_t;

/**
* R2M06_LpfInjAcqRstProfile8Union_t
* R2M06_LpfInjAcqRstProfile8Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_LpfInjAcqRstProfile8Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_LpfInjAcqRstProfile8Union_t;

/**
* R2M06_LpfInjAcqRstCommonUnion_t
* R2M06_LpfInjAcqRstCommonUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_LpfInjAcqRstCommonBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_LpfInjAcqRstCommonUnion_t;

/**
* R2M06_ChirpCalibrationAacControl1Union_t
* R2M06_ChirpCalibrationAacControl1Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_ChirpCalibrationAacControl1Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_ChirpCalibrationAacControl1Union_t;

/**
* R2M06_ChirpCalibrationAacControl2Union_t
* R2M06_ChirpCalibrationAacControl2Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_ChirpCalibrationAacControl2Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_ChirpCalibrationAacControl2Union_t;

/**
* R2M06_ChirpCalibrationAfcControl1Union_t
* R2M06_ChirpCalibrationAfcControl1Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_ChirpCalibrationAfcControl1Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_ChirpCalibrationAfcControl1Union_t;

/**
* R2M06_ChirpCalibrationAfcControl2Union_t
* R2M06_ChirpCalibrationAfcControl2Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_ChirpCalibrationAfcControl2Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_ChirpCalibrationAfcControl2Union_t;

/**
* R2M06_DivideForceControlUnion_t
* R2M06_DivideForceControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_DivideForceControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_DivideForceControlUnion_t;

/**
* R2M06_LpfEnableSettingsUnion_t
* R2M06_LpfEnableSettingsUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_LpfEnableSettingsBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_LpfEnableSettingsUnion_t;

/**
* R2M06_VcoEnableSettingsUnion_t
* R2M06_VcoEnableSettingsUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_VcoEnableSettingsBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_VcoEnableSettingsUnion_t;

/**
* R2M06_FuncsafeMonVtuneControlUnion_t
* R2M06_FuncsafeMonVtuneControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_FuncsafeMonVtuneControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_FuncsafeMonVtuneControlUnion_t;

/**
* R2M06_FuncsafeMonUnlockControlUnion_t
* R2M06_FuncsafeMonUnlockControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_FuncsafeMonUnlockControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_FuncsafeMonUnlockControlUnion_t;

/**
* R2M06_FuncsafeMonLevelSettingsUnion_t
* R2M06_FuncsafeMonLevelSettingsUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_FuncsafeMonLevelSettingsBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_FuncsafeMonLevelSettingsUnion_t;

/**
* R2M06_FuncsafeMonTempThresholdUnion_t
* R2M06_FuncsafeMonTempThresholdUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_FuncsafeMonTempThresholdBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_FuncsafeMonTempThresholdUnion_t;

/**
* R2M06_AtbTrimUnion_t
* R2M06_AtbTrimUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_AtbTrimBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_AtbTrimUnion_t;

/**
* R2M06_FilterParTrimUnion_t
* R2M06_FilterParTrimUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_FilterParTrimBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_FilterParTrimUnion_t;

/**
* R2M06_VcoCurrentTrimUnion_t
* R2M06_VcoCurrentTrimUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_VcoCurrentTrimBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_VcoCurrentTrimUnion_t;

/**
* R2M06_FuncsafeMonLevelSettingsEnUnion_t
* R2M06_FuncsafeMonLevelSettingsEnUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_FuncsafeMonLevelSettingsEnBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_FuncsafeMonLevelSettingsEnUnion_t;

/**
* R2M06_SubbandAmpCorrectionModeSelUnion_t
* R2M06_SubbandAmpCorrectionModeSelUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_SubbandAmpCorrectionModeSelBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_SubbandAmpCorrectionModeSelUnion_t;

/**
* R2M06_OtpTrimSubbandCorrection1GUnion_t
* R2M06_OtpTrimSubbandCorrection1GUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_OtpTrimSubbandCorrection1GBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_OtpTrimSubbandCorrection1GUnion_t;

/**
* R2M06_OtpTrimSubbandCorrection2GUnion_t
* R2M06_OtpTrimSubbandCorrection2GUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_OtpTrimSubbandCorrection2GBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_OtpTrimSubbandCorrection2GUnion_t;

/**
* R2M06_OtpTrimSubbandCorrection4GUnion_t
* R2M06_OtpTrimSubbandCorrection4GUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_OtpTrimSubbandCorrection4GBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_OtpTrimSubbandCorrection4GUnion_t;

/**
* R2M06_HighPllbwSwitchControlUnion_t
* R2M06_HighPllbwSwitchControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_HighPllbwSwitchControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_HighPllbwSwitchControlUnion_t;

/**
* R2M06_AdditionalHwSettingsUnion_t
* R2M06_AdditionalHwSettingsUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_AdditionalHwSettingsBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_AdditionalHwSettingsUnion_t;

/**
* R2M06_ControlSpareUnion_t
* R2M06_ControlSpareUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_ControlSpareBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_ControlSpareUnion_t;

/**
* R2M06_TsSettingsUnion_t
* R2M06_TsSettingsUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_TsSettingsBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_TsSettingsUnion_t;

/**
* R2M06_RmsControlUnion_t
* R2M06_RmsControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_RmsControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_RmsControlUnion_t;

/**
* R2M06_RefCntrInitUnion_t
* R2M06_RefCntrInitUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_RefCntrInitBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_RefCntrInitUnion_t;

/**
* R2M06_FreqCounterStartUnion_t
* R2M06_FreqCounterStartUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_FreqCounterStartBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_FreqCounterStartUnion_t;

/**
* R2M06_FreqCounterReadValueUnion_t
* R2M06_FreqCounterReadValueUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_FreqCounterReadValueBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_FreqCounterReadValueUnion_t;

/**
* R2M06_RefCounterReadValueUnion_t
* R2M06_RefCounterReadValueUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_RefCounterReadValueBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_RefCounterReadValueUnion_t;

/**
* R2M06_LoopFilterCounterInitUnion_t
* R2M06_LoopFilterCounterInitUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_LoopFilterCounterInitBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_LoopFilterCounterInitUnion_t;

/**
* R2M06_LoopFilterCounterReadValueUnion_t
* R2M06_LoopFilterCounterReadValueUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_LoopFilterCounterReadValueBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_LoopFilterCounterReadValueUnion_t;

/**
* R2M06_DivideFreqCounterStartUnion_t
* R2M06_DivideFreqCounterStartUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_DivideFreqCounterStartBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_DivideFreqCounterStartUnion_t;

/**
* R2M06_DivideFreqCounterReadValueUnion_t
* R2M06_DivideFreqCounterReadValueUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_DivideFreqCounterReadValueBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_DivideFreqCounterReadValueUnion_t;

/**
* R2M06_KvcoDvdtConfigControlUnion_t
* R2M06_KvcoDvdtConfigControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_KvcoDvdtConfigControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_KvcoDvdtConfigControlUnion_t;

/**
* R2M06_KvcoDvdtDelayControlUnion_t
* R2M06_KvcoDvdtDelayControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_KvcoDvdtDelayControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_KvcoDvdtDelayControlUnion_t;

/**
* R2M06_KvcoCountStatusUnion_t
* R2M06_KvcoCountStatusUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_KvcoCountStatusBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_KvcoCountStatusUnion_t;

/**
* R2M06_AafcLockDvdtCountStatusUnion_t
* R2M06_AafcLockDvdtCountStatusUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_AafcLockDvdtCountStatusBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_AafcLockDvdtCountStatusUnion_t;

/**
* R2M06_ChirpCalibrationStatusUnion_t
* R2M06_ChirpCalibrationStatusUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_ChirpCalibrationStatusBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_ChirpCalibrationStatusUnion_t;

/**
* R2M06_ChirpCalibrationSwControlUnion_t
* R2M06_ChirpCalibrationSwControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_ChirpCalibrationSwControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_ChirpCalibrationSwControlUnion_t;

/**
* R2M06_ChirpCalibrationTimeoutDelayUnion_t
* R2M06_ChirpCalibrationTimeoutDelayUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_ChirpCalibrationTimeoutDelayBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_ChirpCalibrationTimeoutDelayUnion_t;

/**
* R2M06_Atb1Union_t
* R2M06_Atb1Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_Atb1Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_Atb1Union_t;

/**
* R2M06_DftIdacControlUnion_t
* R2M06_DftIdacControlUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_DftIdacControlBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_DftIdacControlUnion_t;

/**
* R2M06_MaskCcResetErrorUnion_t
* R2M06_MaskCcResetErrorUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_MaskCcResetErrorBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_MaskCcResetErrorUnion_t;

/**
* R2M06_MaskCcErrorFlagUnion_t
* R2M06_MaskCcErrorFlagUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_MaskCcErrorFlagBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_MaskCcErrorFlagUnion_t;

/**
* R2M06_CrcErrorStatus1Union_t
* R2M06_CrcErrorStatus1Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_CrcErrorStatus1Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_CrcErrorStatus1Union_t;

/**
* R2M06_CrcErrorStatus2Union_t
* R2M06_CrcErrorStatus2Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_CrcErrorStatus2Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_CrcErrorStatus2Union_t;

/**
* R2M06_CrcErrorStatus3Union_t
* R2M06_CrcErrorStatus3Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_CrcErrorStatus3Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_CrcErrorStatus3Union_t;

/**
* R2M06_CrcErrorStatus4Union_t
* R2M06_CrcErrorStatus4Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_CrcErrorStatus4Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_CrcErrorStatus4Union_t;

/**
* R2M06_CrcErrorStatus5Union_t
* R2M06_CrcErrorStatus5Union_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_CrcErrorStatus5Bits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_CrcErrorStatus5Union_t;

/**
* R2M06_ModuleIdUnion_t
* R2M06_ModuleIdUnion_t
* union used for simple register initialization
*/
typedef union  {
	/**
	* ## attribure bits_st
	*/
	R2M06_ModuleIdBits_t bits_st;        /*## attribute bits_st */
	/**
	* ## attribute val_u32
	*/
	uint32_t val_u32;        /*## attribute val_u32 */
}R2M06_ModuleIdUnion_t;


#endif
