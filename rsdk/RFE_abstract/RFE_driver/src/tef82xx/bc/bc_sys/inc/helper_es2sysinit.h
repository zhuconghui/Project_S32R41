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
@file helper_es2sysinit.h

@version

@brief Barracuda API header file

This is the header file for Barracuda internal APIs. 
Application should avoid calling function described in this header file directly.

*/

#ifndef HELPER_ES2SYSINIT_H
#define HELPER_ES2SYSINIT_H
#ifdef TEF82XX_CFG_ES2 

#include <stdint.h>

#include "bc_types.h"
#include "bc_err.h"

#if defined(__cplusplus)
extern "C"
{
#endif

BC_ERRCODE Helper_ES2_InitDistributeOTPData(void);
BC_ERRCODE Helper_ES2_InitConfigPonLdoGBIAS(void);
BC_ERRCODE Helper_ES2_EnLocLDORelRSTADCSer(SYS_IPList_t *pAppConfig);
BC_ERRCODE Helper_ES2_ConfigSetCCClk(void);
BC_ERRCODE Helper_ES2_InitConfigMCLK(void);
BC_ERRCODE Helper_ES2_InitConfigCAFC(void);
BC_ERRCODE Helper_ES2_InitConfigCAFCFuSa(void);
BC_ERRCODE Helper_ES2_InitGLDOSelfTest(void);
BC_ERRCODE Helper_ES2_InitPowerOnModules(void);
BC_ERRCODE Helper_ES2_ConfigISM(void);

#if defined(__cplusplus)
}
#endif
#endif
#endif //HELPER_ES2SYSINIT_H
