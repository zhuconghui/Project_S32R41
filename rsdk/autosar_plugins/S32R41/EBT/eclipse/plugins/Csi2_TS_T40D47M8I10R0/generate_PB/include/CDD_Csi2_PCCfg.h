/*
 * Copyright 2022-2023 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */

[!VAR "Csi2CfgPath"!]/AUTOSAR/TOP-LEVEL-PACKAGES/Csi2/ELEMENTS/Csi2[!ENDVAR!]    [!// the CODE and ENCODE tag
#ifndef CSI2_PCCFG_H
#define CSI2_PCCFG_H

/**
*   @file
*
*   @internal
*   @addtogroup CSI2
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "StandardTypes.h"
#include "rsdk_version.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CSI2_PCCFG_VENDOR_ID                        43
#define CSI2_PCCFG_AR_RELEASE_MAJOR_VERSION         RSDK_AR_MAJOR
#define CSI2_PCCFG_AR_RELEASE_MINOR_VERSION         RSDK_AR_MINOR
#define CSI2_PCCFG_AR_RELEASE_REVISION_VERSION      RSDK_AR_REV
#define CSI2_PCCFG_SW_MAJOR_VERSION                 RSDK_SW_MAJOR
#define CSI2_PCCFG_SW_MINOR_VERSION                 RSDK_SW_MINOR
#define CSI2_PCCFG_SW_PATCH_VERSION                 RSDK_SW_PATCH

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
    /* Check if header file and StandardTypes header file are of the same AutoSar version */
    #if ((CSI2_PCCFG_AR_RELEASE_MAJOR_VERSION != STD_AR_RELEASE_MAJOR_VERSION) || \
         (CSI2_PCCFG_AR_RELEASE_MINOR_VERSION != STD_AR_RELEASE_MINOR_VERSION)    \
        )
        #error "AutoSar Version Numbers of CSI2_Cfg.h and StandardTypes.h are different"
    #endif
#endif

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/
/* Pre-processor switch to enable/disable development error detection for Csi2 API */
#define CSI2_DEV_ERROR_DETECT                   [!CODE!][!IF "node:value(concat($Csi2CfgPath,'/Csi2General','/Csi2DevErrorDetect'))"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!][!ENDCODE!]

/* Pre-processor switch to enable/disable stop execution after error detection for Csi2 API */
#define CSI2_DEV_HALT_ON_ERROR                  [!CODE!][!IF "node:value(concat($Csi2CfgPath,'/Csi2General','/Csi2StopAfterErrorReport'))"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!][!ENDCODE!]

/* Pre-processor switch to define single Csi2 management thread or multiple Csi2 management threads.
 * If single thread (which is the normal approach) - there are no necessary exclusive areas for the driver    */
#define CSI2_SINGLE_MANAGEMENT_THREADS          [!CODE!][!IF "node:value(concat($Csi2CfgPath,'/Csi2General','/Csi2SingleThreadUsed'))"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!][!ENDCODE!]

/* Pre-processor switch to enable/disable version info report for Csi2 API                      */
#define CSI2_VERSION_INFO_API                   [!CODE!][!IF "node:value(concat($Csi2CfgPath,'/Csi2General','/Csi2VersionInfo'))"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!][!ENDCODE!]

/* Pre-processor switch to enable/disable statistics usage for received data for Csi2 API       */
#define CSI2_STATISTIC_DATA_USAGE               [!CODE!][!IF "node:value(concat($Csi2CfgPath,'/Csi2General','/Csi2StatisticDataUsage'))"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!][!ENDCODE!]

/* Pre-processor switch to enable/disable DC auto compensation for received data on CSI2 API    */
#define CSI2_AUTO_DC_COMPENSATION               [!CODE!][!IF "(node:value(concat($Csi2CfgPath,'/Csi2General','/Csi2DcAutoCompensation'))='true') and (node:value(concat($Csi2CfgPath,'/Csi2General','/Csi2StatisticDataUsage'))='true')"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!][!ENDCODE!]

/* Pre-processor switch to enable/disable auxiliary data usage for received data on CSI2 API    */
#define CSI2_AUXILIARY_DATA_USAGE               [!CODE!][!IF "node:value(concat($Csi2CfgPath,'/Csi2General','/Csi2AuxiliaryDataUsage'))"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!][!ENDCODE!]

/* Pre-processor switch to enable/disable metadata usage for received data on CSI2 API    */
#define CSI2_METADATA_DATA_USAGE                [!CODE!][!IF "node:value(concat($Csi2CfgPath,'/Csi2General','/Csi2MetaDataUsage'))"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!][!ENDCODE!]

/* Pre-processor switch to enable/disable single ISR callback for CSI2 API                      */
#define CSI2_SINGLE_CALLBACK_USAGE              [!CODE!][!IF "node:value(concat($Csi2CfgPath,'/Csi2General','/Csi2SingleCallbackUsage'))"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!][!ENDCODE!]

/* Pre-processor switch to enable/disable Rx start/stop usage in CSI2 API                       */
#define CSI2_RX_START_STOP_USAGE                [!CODE!][!IF "node:value(concat($Csi2CfgPath,'/Csi2General','/Csi2RxStartStopUsage'))"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!][!ENDCODE!]

/* Pre-processor switch to enable/disable power on/off usage in CSI2 API                        */
#define CSI2_POWER_ON_OFF_USAGE                 [!CODE!][!IF "node:value(concat($Csi2CfgPath,'/Csi2General','/Csi2PowerOnOffUsage'))"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!][!ENDCODE!]

/* Pre-processor switch to enable/disable secondary functions usage in CSI2 API                 */
#define CSI2_SECONDARY_FUNCTIONS_USAGE          [!CODE!][!IF "node:value(concat($Csi2CfgPath,'/Csi2General','/Csi2InterfaceFunctionsUsage'))"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!][!ENDCODE!]

/* Pre-processor switch to enable/disable internal frames counter usage in CSI2 API             */
#define CSI2_FRAMES_COUNTER_USED                [!CODE!][!IF "node:value(concat($Csi2CfgPath,'/Csi2General','/Csi2FramesCounterUsage'))"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!][!ENDCODE!]

/* Pre-processor switch to enable/disable usage of GPIO in CSI2 API                             */
#define CSI2_GPIO_USED                          [!CODE!][!IF "node:value(concat($Csi2CfgPath,'/Csi2General','/Csi2GPIOUsage'))"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!][!ENDCODE!]

/* Pre-processor switch to enable/disable usage of SDMA in CSI2 API                             */
#define CSI2_SDMA_USED                          [!CODE!][!IF "node:value(concat($Csi2CfgPath,'/Csi2General','/Csi2SDMAUsage'))"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!][!ENDCODE!]

/* Formal instance id for CSI2 driver, to be used at development time                           */
#define CSI2_INSTANCE_ID                        0u

/* The type of timer to be used for necessary execution delays                                  */
#define CSI2_USING_COUNTER_DUMMY                1u
#define CSI2_USING_COUNTER_SYSTEM               2u
#define CSI2_USING_COUNTER_CUSTOM               3u

#define CSI2_TIMER_TYPE                         [!IF "node:value(concat($Csi2CfgPath,'/Csi2General','/Csi2OsIfTimerUsage')) = 'OSIF_COUNTER_DUMMY'"!]CSI2_USING_COUNTER_DUMMY[!ELSEIF "node:value(concat($Csi2CfgPath,'/Csi2General','/Csi2OsIfTimerUsage')) = 'OSIF_COUNTER_SYSTEM'"!]CSI2_USING_COUNTER_SYSTEM[!ELSE!]CSI2_USING_COUNTER_CUSTOM[!ENDIF!]

[!IF "text:concat(text:grep(node:value(concat('/AUTOSAR/TOP-LEVEL-PACKAGES/Resource/ELEMENTS/Resource','/ResourceGeneral','/ResourceSubderivative')),'saf85[A-Za-z_0-9]*'), 'x') != 'x' "!]/* The usage of CSI2-PHY for SAF85XX                                                            */
#define CSI2_SAF85XX_PHY_USED                   [!IF "node:value(concat($Csi2CfgPath,'/Csi2General','/Csi2PhyUsageSaf85'))"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!][!ENDIF!][!IF "text:concat(text:grep(node:value(concat('/AUTOSAR/TOP-LEVEL-PACKAGES/Resource/ELEMENTS/Resource','/ResourceGeneral','/ResourceSubderivative')),'saf86[A-Za-z_0-9]*'), 'x') != 'x' "!]/* The usage of CSI2-PHY for SAF86XX                                                            */
#define CSI2_SAF86XX_PHY_USED                   [!IF "node:value(concat($Csi2CfgPath,'/Csi2General','/Csi2PhyUsageSaf85'))"!]STD_ON[!ELSE!]STD_OFF[!ENDIF!][!ENDIF!]

[!IF "node:value(concat($Csi2CfgPath,'/Csi2General','/Csi2StopAfterErrorReport'))"!]/* Infinite loop if error detected and the option is to detect development errors */
#define CSI2_HALT_ON_ERROR          HaltOnError();  [!ELSE!]
/* Nothing to do after error detection      */
#define CSI2_HALT_ON_ERROR  [!ENDIF!]

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

/** @} */

#endif /* CSI2_CFG_H */
