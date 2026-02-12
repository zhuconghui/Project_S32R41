/*
 * Copyright 2018-2021 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/



/* Set of macros used map the DSP command fields onto the "DSP" instruction bits.
 * The SPT Assembler requires grouping them in 4 x 32-bit values*/
#define RSDK_DSP_CMD_BITS_31_0(params, fid, crc)    ( ((params & 0x0000FFFF) << 16) | ((fid & 0x000000FF) << 8) | (crc & 0x000000FF))
#define RSDK_DSP_CMD_BITS_63_32(params)             (params)
#define RSDK_DSP_CMD_BITS_95_64(params)             (params)
#define RSDK_DSP_CMD_BITS_120_96(cmdFormat, params) ( ((cmdFormat & 0x03) << 16) | (params & 0x0000FFFF))


