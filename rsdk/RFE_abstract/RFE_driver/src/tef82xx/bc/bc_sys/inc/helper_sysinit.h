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
@file helper_sysinit.h

@version

@brief Barracuda API header file

This is the header file for Barracuda internal APIs. 
Application should avoid calling function described in this header file directly.

*/

#ifndef HELPER_SYSINIT_H
#define HELPER_SYSINIT_H

#include <stdint.h>

#include "bc_types.h"
#include "bc_err.h"

#if defined(__cplusplus)
extern "C"
{
#endif

BC_ERRCODE Helper_InitConfigPonLdoGBIAS(void);
BC_ERRCODE Helper_EnLocLDORelRSTADCSer(SYS_IPList_t *pAppConfig);
BC_ERRCODE Helper_ConfigSetCCClk(void);
BC_ERRCODE Helper_InitConfigMCLK(void);
BC_ERRCODE Helper_InitConfigCAFC(void);
BC_ERRCODE Helper_InitConfigCAFCFuSa(void);
BC_ERRCODE Helper_ConfigISM(void);
BC_ERRCODE Helper_InitGLDOSelfTest(void);
BC_ERRCODE Helper_InitPowerOnModules(void);
BC_ERRCODE Helper_InitDistributeOTPData(void);

#if defined(__cplusplus)
}
#endif
#endif //HELPER_SYSINIT_H
