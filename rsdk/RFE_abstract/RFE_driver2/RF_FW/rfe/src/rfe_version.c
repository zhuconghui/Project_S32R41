/**************************************************************************************************
* Copyright 2022 - 2023 NXP
**************************************************************************************************
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
**************************************************************************************************/

/******************************************************************************
 *   Project              : RF_Abstract_2.0
 *   Platform             : S32R41
 *****************************************************************************/

/*==================================================================================================
 *                                        INCLUDE FILES
 ==================================================================================================*/
#include "rfe_version.h"

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                      GLOBAL FUNCTIONS
 ==================================================================================================*/
 rfe_version_t rfe_get_version( void )
 {
    rfe_version_t version;
    version.hwType            = RFE_HW_TYPE;
    version.hwVariant         = RFE_HW_VARIANT;
    version.hwVersion         = RFE_HW_VERSION;
    version.hwUniqueId        = RFE_HW_UID_NOTAVAIL;
          
#ifdef RFE_BUILD_SYS_VAL_FW
    version.fwVariant         = RFE_FW_VARIANT_SYS_VAL;  
#else
    #ifdef RFE_BUILD_IP_VAL_FW
       version.fwVariant      = RFE_FW_VARIANT_IP_VAL;  
    #else
       #ifdef RFE_BUILD_PROXY_VAL_FW
          version.fwVariant      = RFE_FW_VARIANT_PROXY_VAL;
       #else
            #ifdef RFE_BUILD_FUSA_VAL_FW
               version.fwVariant      = RFE_FW_VARIANT_FUSA_VAL;
            #else
               version.fwVariant      = RFE_FW_VARIANT;
            #endif
       #endif
    #endif    
#endif    

    version.fwVersionReleased = (bool)RFE_VERSION_FW_VERSION_RELEASED;
    version.fwVersionMajor    = (uint8_t)RFE_VERSION_FW_VERSION_MAJOR;
    version.fwVersionMinor    = (uint8_t)RFE_VERSION_FW_VERSION_MINOR;
    version.fwVersionPatch    = (uint8_t)RFE_VERSION_FW_VERSION_PATCH;
    version.fwHash            = RFE_VERSION_FW_HASH;
    
    return version;
 }

#ifdef __cplusplus
}
#endif

/*******************************************************************************
 * EOF
 ******************************************************************************/

/** @} */
