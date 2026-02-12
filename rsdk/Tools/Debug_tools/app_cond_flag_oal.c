/*
 * Copyright 2018,2021-2022 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */

#ifndef USING_PLATFORM_SDK
/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "app_cond_flag.h"
#include "debug_tools.h"

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
void AppCondFlagInit(rsdkAppCondFlag_t *apFlag){
    int lRet = -1;

    apFlag->mValue = 0;
    lRet = OAL_InitializeSemaphore(apFlag);
    if(lRet)
    {
        DbgPrintMsg("AppSemInit failed!");
        HALT_HERE;
    }
    else
    {
//        DbgPrintMsg("AppSemInit completed!");
    }
}

void AppCondFlagSignal(rsdkAppCondFlag_t *apFlag){
    int lRet = -1;

    lRet = OAL_GiveSemaphore(apFlag);
    if(lRet)
    {
        DbgPrintMsg("AppSemGive failed!");
        HALT_HERE;
    }
    else
    {
//        DbgPrintMsg("AppSemGive completed!");
    }
}

void AppCondFlagWait(rsdkAppCondFlag_t *apFlag){
    int lRet = -1;

    lRet = OAL_TakeSemaphore(apFlag);
    if(lRet)
    {
        DbgPrintMsg("AppSemTake failed!");
        HALT_HERE;
    }
    else
    {
//        DbgPrintMsg("AppSemTake completed!");
    }
}

void AppCondFlagDestroy(rsdkAppCondFlag_t *apFlag){
    int lRet = -1;
    
    lRet = OAL_DestroySemaphore(apFlag);
    if(lRet)
    {
        DbgPrintMsg("AppSemDestroy failed!");
        HALT_HERE;
    }
    else
    {
//        DbgPrintMsg("AppSemDestroy completed!");
    }
}


#ifdef __cplusplus
}
#endif

#endif //USING_PLATFORM_SDK
