/**************************************************************************************************
 * 
 * Copyright 2018-2024 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 *
 **************************************************************************************************/

/** This file defines a list (or database..) of function IDs to be used jointly by the BBE32 DSP Executable application
 * and the SPT Kernels calling the DSP.
 *  The RSDK_DSP_REGISTER_FUNC() operator is defined as a preprocessor macro in both toolchains (DSP and Host-CPU/SPT), to construct
 * similar lists of function IDs having integer values starting from 0 (inclusive).
 *  The strings in parentheses must represent DSP function names which are valid during the linking process of the DSP executable. 
 */
#ifdef SAF86XX
RSDK_DSP_REGISTER_FUNC(RsdkBbe32ReordTile16to4Ch)
RSDK_DSP_REGISTER_FUNC(RsdkBbe32TdIm)
RSDK_DSP_REGISTER_FUNC(RsdkBbe32FftInit)
RSDK_DSP_REGISTER_FUNC(RsdkBbe32Fft2Real)
RSDK_DSP_REGISTER_FUNC(RsdkBbe32EncCp4d)
RSDK_DSP_REGISTER_FUNC(AppDspChirpProcDone)
RSDK_DSP_REGISTER_FUNC(RsdkBbe32EncFlxSpt34)
RSDK_DSP_REGISTER_FUNC(RsdkBbe32CmprSptInit)
RSDK_DSP_REGISTER_FUNC(AppDspCsi2TxDmaConfig)
RSDK_DSP_REGISTER_FUNC(AppDspCsi2TxDmaRun)
#else
RSDK_DSP_REGISTER_FUNC(RsdkBbe32Func1)
RSDK_DSP_REGISTER_FUNC(RsdkBbe32Func2)
RSDK_DSP_REGISTER_FUNC(RsdkBbe32CaCfar)
RSDK_DSP_REGISTER_FUNC(RsdkBbe32OsCfar)
#if (defined(S32R41) || defined(SAF85XX))
RSDK_DSP_REGISTER_FUNC(RsdkBbe32LalVectorAdd)
#endif
#endif
