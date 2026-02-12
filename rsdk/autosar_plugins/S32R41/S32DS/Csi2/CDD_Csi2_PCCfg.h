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

#ifndef CDD_CSI2_PCCFG_H
#define CDD_CSI2_PCCFG_H

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
#define CSI2_PCCFG_VENDOR_ID                     43
#define CSI2_PCCFG_AR_RELEASE_MAJOR_VERSION      RSDK_AR_MAJOR
#define CSI2_PCCFG_AR_RELEASE_MINOR_VERSION      RSDK_AR_MINOR
#define CSI2_PCCFG_AR_RELEASE_REVISION_VERSION   RSDK_AR_REV
#define CSI2_PCCFG_SW_MAJOR_VERSION              RSDK_SW_MAJOR
#define CSI2_PCCFG_SW_MINOR_VERSION              RSDK_SW_MINOR
#define CSI2_PCCFG_SW_PATCH_VERSION              RSDK_SW_PATCH


/*==================================================================================================
                                      FILE VERSION CHECKS
==================================================================================================*/
/* Checks against general AUTOSAR version used */
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and StandardTypes header file are of the same AutoSar version */
    #if ((CSI2_PCCFG_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \\\
         (CSI2_PCCFG_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION)    \\\
        )
        #error "AutoSar Version Numbers of CSI2_PCCfg.h and StandardTypes.h are different"
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
var Csi2General = configSet.getChildById("Csi2GeneralConfiguration");
var PinPackage = scriptApi.getProfile().getMcuInfo().getPackage();
var LocalValue = "";
!]
/* Pre-processor switch to enable/disable development error detection for Csi2 API                              */
[!<code>#define CSI2_DEV_ERROR_DETECT               $(Csi2General.getChildById("Csi2DevErrorDetect").getValue()) ? "STD_ON":"STD_OFF"$</code>!]


/* Pre-processor switch to enable/disable execution stop if error detected for Csi2 API                         */
[!<code>#define CSI2_DEV_HALT_ON_ERROR              $(Csi2General.getChildById("Csi2StopAfterErrorReport").getValue()) ? "STD_ON":"STD_OFF"$</code>!]


/* Pre-processor switch to define single Csi2 management thread or multiple Csi2 management threads.
 * If single thread (which is the normal approach) - there are no necessary exclusive areas for the driver      */
[!<code>#define CSI2_SINGLE_MANAGEMENT_THREADS      $(Csi2General.getChildById("Csi2SingleThreadUsed").getValue()) ? "STD_ON":"STD_OFF"$</code>!]


/* Pre-processor switch to enable/disable version info report for Csi2 API                                      */
[!<code>#define CSI2_VERSION_INFO_API               $(Csi2General.getChildById("Csi2VersionInfo").getValue()) ? "STD_ON":"STD_OFF"$</code>!]


/* Pre-processor switch to enable/disable statistics usage for received data for Csi2 API                       */
[!
LocalValue = Csi2General.getChildById("Csi2StatisticDataUsage").getValue();
<code>#define CSI2_STATISTIC_DATA_USAGE           $LocalValue ? "STD_ON":"STD_OFF"$</code>!]


/* Pre-processor switch to enable/disable DC auto compensation for received data on CSI2 API                    */
[!<code>#define CSI2_AUTO_DC_COMPENSATION           $(LocalValue && (Csi2General.getChildById("Csi2DcAutoCompensation").getValue())) ? "STD_ON":"STD_OFF"$</code>!]


/* Pre-processor switch to enable/disable auxiliary data usage for received data on CSI2 API                    */
[!<code>#define CSI2_AUXILIARY_DATA_USAGE           $(Csi2General.getChildById("Csi2AuxiliaryDataUsage").getValue()) ? "STD_ON":"STD_OFF"$</code>!]


/* Pre-processor switch to enable/disable metadata usage for received data on CSI2 API                          */
[!<code>#define CSI2_METADATA_DATA_USAGE            $(Csi2General.getChildById("Csi2MetaDataUsage").getValue()) ? "STD_ON":"STD_OFF"$</code>!]


/* Pre-processor switch to enable/disable single ISR callback for CSI2 API                                      */
[!<code>#define CSI2_SINGLE_CALLBACK_USAGE          $(Csi2General.getChildById("Csi2SingleCallbackUsage").getValue()) ? "STD_ON":"STD_OFF"$</code>!]


/* Pre-processor switch to enable/disable Rx start/stop usage in CSI2 API                                       */
[!<code>#define CSI2_RX_START_STOP_USAGE            $(Csi2General.getChildById("Csi2RxStartStopUsage").getValue()) ? "STD_ON":"STD_OFF"$</code>!]


/* Pre-processor switch to enable/disable power on/off usage in CSI2 API                                        */
[!<code>#define CSI2_POWER_ON_OFF_USAGE             $(Csi2General.getChildById("Csi2PowerOnOffUsage").getValue()) ? "STD_ON":"STD_OFF"$</code>!]


/* Pre-processor switch to enable/disable secondary functions usage in CSI2 API                                 */
[!<code>#define CSI2_SECONDARY_FUNCTIONS_USAGE      $(Csi2General.getChildById("Csi2InterfaceFunctionsUsage").getValue()) ? "STD_ON":"STD_OFF"$</code>!]


/* Pre-processor switch to enable/disable internal frames counter usage in CSI2 API                             */
[!<code>#define CSI2_FRAMES_COUNTER_USED            $(Csi2General.getChildById("Csi2FramesCounterUsage").getValue()) ? "STD_ON":"STD_OFF"$</code>!]


/* Pre-processor switch to enable/disable usage of GPIO in CSI2 API                                             */
[!<code>#define CSI2_GPIO_USED                      $(Csi2General.getChildById("Csi2GPIOUsage").getValue()) ? "STD_ON":"STD_OFF"$</code>!]


/* Pre-processor switch to enable/disable usage of SDMA in CSI2 API                                             */
[!<code>#define CSI2_SDMA_USED                      $(Csi2General.getChildById("Csi2SDMAUsage").getValue()) ? "STD_ON":"STD_OFF"$</code>!]


/* Formal instance id for CSI2 driver, to be used at development time                                           */
#define CSI2_INSTANCE_ID                    0u

/* The type of timer to be used for necessary execution delays                                                  */
#define CSI2_USING_COUNTER_DUMMY            1u
#define CSI2_USING_COUNTER_SYSTEM           2u
#define CSI2_USING_COUNTER_CUSTOM           3u

[!<code>#define CSI2_TIMER_TYPE                     $Csi2General.getChildById("Csi2OsIfTimerUsage").getValue().replace("OSIF","CSI2_USING")$</code>!]


[!<code>$Csi2General.getChildById("Csi2StopAfterErrorReport").getValue() ? "\
/* Infinite loop if error detected and the option is to detect development errors                               */\n\
#define CSI2_HALT_ON_ERROR                  HaltOnError();" :
"/* Nothing to do after error detection                                                                          */\n\
#define CSI2_HALT_ON_ERROR"$</code>!]


[!
    if(PinPackage.match("SAF") == "SAF")
    {
        <code>
/* The usage of CSI2-PHY for SAF85XX                                                                            */
#define CSI2_SAF85XX_PHY_USED               $(Csi2General.getChildById("Csi2PhyUsageSaf85").getValue()) ? "STD_ON":"STD_OFF"$
        </code>
    }

!]


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
