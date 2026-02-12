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

#include "helper_sysinit.h"
#ifdef TEF82XX_CFG_ES2
#include "helper_es2sysinit.h"
#endif

BC_ERRCODE Helper_InitConfigPonLdoGBIAS(void)
{
    BC_ERRCODE ErrCode;
#ifdef TEF82XX_CFG_ES2
    ErrCode = Helper_ES2_InitConfigPonLdoGBIAS();
#else
    ErrCode = BC_ERR_FUNCNOTEXIST;
#endif
    return ErrCode;
}

BC_ERRCODE Helper_EnLocLDORelRSTADCSer(SYS_IPList_t *pAppConfig)
{
    BC_ERRCODE ErrCode;
#ifdef TEF82XX_CFG_ES2
    ErrCode = Helper_ES2_EnLocLDORelRSTADCSer(pAppConfig);
#else
    ErrCode = BC_ERR_FUNCNOTEXIST;
#endif
    return ErrCode;
}

BC_ERRCODE Helper_ConfigSetCCClk(void)
{
    BC_ERRCODE ErrCode;
#ifdef TEF82XX_CFG_ES2
    ErrCode = Helper_ES2_ConfigSetCCClk();
#else
    ErrCode = BC_ERR_FUNCNOTEXIST;
#endif
    return ErrCode;
}

BC_ERRCODE Helper_InitConfigMCLK(void)
{
    BC_ERRCODE ErrCode;
#ifdef TEF82XX_CFG_ES2
    ErrCode = Helper_ES2_InitConfigMCLK();
#else
    ErrCode = BC_ERR_FUNCNOTEXIST;
#endif
    return ErrCode;
}

BC_ERRCODE Helper_InitConfigCAFC(void)
{
    BC_ERRCODE ErrCode;
#ifdef TEF82XX_CFG_ES2
    ErrCode = Helper_ES2_InitConfigCAFC();
#else
    ErrCode = BC_ERR_FUNCNOTEXIST;
#endif
    return ErrCode;
}

BC_ERRCODE Helper_InitConfigCAFCFuSa(void)
{
    BC_ERRCODE ErrCode;
#ifdef TEF82XX_CFG_ES2
    ErrCode = Helper_ES2_InitConfigCAFCFuSa();
#else
    ErrCode = BC_ERR_FUNCNOTEXIST;
#endif
    return ErrCode;
}

BC_ERRCODE Helper_ConfigISM(void)
{
    BC_ERRCODE ErrCode;
#ifdef TEF82XX_CFG_ES2
    ErrCode = Helper_ES2_ConfigISM();
#else
    ErrCode = BC_ERR_FUNCNOTEXIST;
#endif
    return ErrCode;
}

BC_ERRCODE Helper_InitGLDOSelfTest(void)
{
    BC_ERRCODE ErrCode;
#ifdef TEF82XX_CFG_ES2
    ErrCode = Helper_ES2_InitGLDOSelfTest();
#else
    ErrCode = BC_ERR_FUNCNOTEXIST;
#endif
    return ErrCode;
}
BC_ERRCODE Helper_InitPowerOnModules(void)
{
    BC_ERRCODE ErrCode;
#ifdef TEF82XX_CFG_ES2
    ErrCode = Helper_ES2_InitPowerOnModules();
#else
    ErrCode = BC_ERR_FUNCNOTEXIST;
#endif
    return ErrCode;
}

BC_ERRCODE Helper_InitDistributeOTPData(void)
{
    BC_ERRCODE ErrCode;
#ifdef TEF82XX_CFG_ES2
    ErrCode = Helper_ES2_InitDistributeOTPData();
#else
    ErrCode = BC_ERR_FUNCNOTEXIST;
#endif
    return ErrCode;
}
/* Endif of file */
