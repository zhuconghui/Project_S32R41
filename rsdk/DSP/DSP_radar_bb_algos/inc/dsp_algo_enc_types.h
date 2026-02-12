/*******************************************************************************
Copyright 2022 NXP.
NXP Confidential. This software is owned or controlled by NXP and may only be
used strictly in accordance with the applicable license terms.  By expressly
accepting such terms or by downloading, installing, activating and/or
otherwise using the software, you are agreeing that you have read, and that
you agree to comply with and are bound by, such license terms.  If you do not
agree to be bound by the applicable license terms, then you may not retain,
install, activate or otherwise use the software.
*******************************************************************************/


/**
 *
 * @file  dsp_algo_enc_types.h
 *
 * @brief Global type declarations
 *
 ******************************************************************************/

#ifndef DSP_ALGO_ENC_TYPES_H
#define DSP_ALGO_ENC_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************************************
* TYPE DEFINITIONS
*******************************************************************************/

/** @brief Compression output mode, all sequential except for mode txps */
typedef enum RSDK_CmprOutMode
{
  e_RSDK_CMPR_OUT_MODE_ONEBUF   = 0,       ///< Single buffer output for mantissa + exponent + fill bits
  e_RSDK_CMPR_OUT_MODE_TWOBUF4  = 1,       ///< Two buffer output, mantissa / 4-bit exponent + no fill bits
  e_RSDK_CMPR_OUT_MODE_TWOBUF8  = 2,       ///< Two buffer output, mantissa / 5-bit exponent + 3-bit fill
  e_RSDK_CMPR_OUT_MODE_CP4DFMTA = 3,       ///< CP4D / CP4D_FMTA mixed output
  e_RSDK_CMPR_OUT_MODE_TXPS     = 4        ///< Transposed output
} RSDK_CmprOutMode_t;

#ifdef __cplusplus
}
#endif
#endif  /* DSP_ALGO_ENC_TYPES_H */
/*******************************************************************************
* END OF FILE
*******************************************************************************/
