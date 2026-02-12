/*
*  Copyright 2024 NXP
*  NXP Confidential and Proprietary. This software is owned or controlled by NXP and
*  may only be used strictly in accordance with the applicable license terms.  By
*  expressly accepting such terms or by downloading, installing, activating and/or
*  otherwise using the software, you are agreeing that you have read, and that you
*  agree to comply with and are bound by, such license terms.  If you do not agree to
*  be bound by the applicable license terms, then you may not retain, install, activate or
*  otherwise use the software.
*/

#ifndef RFE20_PCCFG_H
#define RFE20_PCCFG_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/
#include "StandardTypes.h"
#include "rsdk_version.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define RFE20_PCCFG_VENDOR_ID                     43
#define RFE20_PCCFG_AR_RELEASE_MAJOR_VERSION      RSDK_AR_MAJOR
#define RFE20_PCCFG_AR_RELEASE_MINOR_VERSION      RSDK_AR_MINOR
#define RFE20_PCCFG_AR_RELEASE_REVISION_VERSION   RSDK_AR_REV
#define RFE20_PCCFG_SW_MAJOR_VERSION              RSDK_SW_MAJOR
#define RFE20_PCCFG_SW_MINOR_VERSION              RSDK_SW_MINOR
#define RFE20_PCCFG_SW_PATCH_VERSION              RSDK_SW_PATCH


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Checks against general AUTOSAR version used */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and StandardTypes header file are of the same AutoSar version */
    #if ((RFE20_PCCFG_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \\\
         (RFE20_PCCFG_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION)    \\\
        )
        #error "AutoSar Version Numbers of RFE20_PCCfg.h and StandardTypes.h are different"
    #endif
#endif


/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
[!
/*  Variable defintions to be used for the code generation  */
var configSet     = this[0];
var Rfe20General = configSet.getChildById("Rfe20GeneralConfiguration");
var PinPackage = scriptApi.getProfile().getMcuInfo().getPackage();
var LocalValue = "";
var hexDigits = "0123456789ABCDEF";

// decimal to hexa conversion, fixed length 8 digits
function dec2hex(val)
{
    var s = "        ", i;
    
    for(i = 0; i < 8; i++)
    {
        s = hexDigits[val & 0xf] + s;
        val >>= 4;
    }
    
    return s;
}
!]

[!<code>
/* Pre-processor switch to enable/disable development error detection for RFE 2.0 API                           */
#define CDD_RFE_DEV_ERROR_DETECT            $(Rfe20General.getChildById("Rfe20DevErrorDetect").getValue()) ? "STD_ON":"STD_OFF"$


/* Pre-processor switch to define single RFE 2.0 management thread or multiple RFE 2.0 management threads.
 * If single thread (which is the normal approach) - there are no necessary exclusive areas for the driver      */
#define CDD_RFE_SINGLE_MANAGEMENT_THREADS   $(Rfe20General.getChildById("Rfe20SingleThreadUsed").getValue()) ? "STD_ON":"STD_OFF"$


/* Pre-processor switch to enable/disable execution stop after an error is detected for RFE 2.0 API             */
#define CDD_RFE_CFG_HALT_ON_ERROR           $(Rfe20General.getChildById("Rfe20StopAfterErrorReport").getValue()) ? "STD_ON":"STD_OFF"$


/* Pre-processor switch to enable/disable version info report for RFE 2.0 API                                   */
#define CDD_RFE_VERSION_INFO_API            $(Rfe20General.getChildById("Rfe20VersionInfo").getValue()) ? "STD_ON":"STD_OFF"$


/* The number of used Front-Ends                                                                                */
</code>
if(Rfe20General.getChildById("Rfe20_RfeMode").getValue() == "CASCADED")
{
<code>#define RFE_NUM_USED_FRONT_ENDS             $Rfe20General.getChildById("Rfe20FeNumber").getValue()$</code>
}
else
{
<code>#define                                     RFE_MODE_STANDALONE</code>
}<code>



/* The memory location to receive the State reported by the Firmware                                            */
#define RFE_CMD_IF_RFE_STATE_ADDRESS        0x$dec2hex(Rfe20General.getChildById("Rfe20FeStateAddress").getValue())$


/* The memory location to receive the pointer to Memory Shared Address                                          */
#define RFE_CMD_IF_BASE_ADDRESS_PTR         0x$dec2hex(Rfe20General.getChildById("Rfe20FePointerAddress").getValue())$


/* The memory buffer start, to be used for API <-> Firmware data transfer                                       */
#define RFE_CMD_CLIENT_BASE_ADDRESS         0x$dec2hex(Rfe20General.getChildById("Rfe20DataTransferBuffer").getValue())$


/* The memory buffer start, for BIST procedure, used only on Firmware side.
   For more details, please check the detailes provided for "BIST Buffer Address" parameter 
   in the Tresos plugin at configuration time.                                                                  */
#define RFE_RFBIST_BUFFERS_ADDRESS          0x$dec2hex(Rfe20General.getChildById("Rfe20BistBuffer").getValue())$

</code>!]

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /* CSI2_PCCFG_H */
