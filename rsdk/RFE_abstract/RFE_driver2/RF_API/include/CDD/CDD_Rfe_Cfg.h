/*==================================================================================================
* Copyright 2022-2023 NXP
*
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and
* may only be used strictly in accordance with the applicable license terms.  By
* expressly accepting such terms or by downloading, installing, activating and/or
* otherwise using the software, you are agreeing that you have read, and that you
* agree to comply with and are bound by, such license terms.  If you do not agree to
* be bound by the applicable license terms, then you may not retain, install, activate or
* otherwise use the software.
==================================================================================================*/
#ifndef	CDD_RFE_CFG_H
#define	CDD_RFE_CFG_H

#ifdef __cplusplus
extern "C"
{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "Std_Types.h"
#include "Rfe20_PCCfg.h"
#include "rsdk_version.h"

/*==================================================================================================
*                                 SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define CDD_RFE_CFG_VENDOR_ID                        43
#define CDD_RFE_CFG_AR_RELEASE_MAJOR_VERSION         RSDK_AR_MAJOR
#define CDD_RFE_CFG_AR_RELEASE_MINOR_VERSION         RSDK_AR_MINOR
#define CDD_RFE_CFG_AR_RELEASE_REVISION_VERSION      RSDK_AR_REV
#define CDD_RFE_CFG_SW_MAJOR_VERSION                 RSDK_SW_MAJOR
#define CDD_RFE_CFG_SW_MINOR_VERSION                 RSDK_SW_MINOR
#define CDD_RFE_CFG_SW_PATCH_VERSION                 RSDK_SW_PATCH

/** @addtogroup rsdk_rfe_api_const
* @{
* 
*/

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
                               CONFIGURATION PARAMETERS
==================================================================================================*/

/**
 *  The CRC computation can be done only using software method.
 *  This is a fact imposed by :
 *      - the necessity to use a single 32 bits CRC polynomial for all CRC implementation
 *      - the Configurator is based on java implementation is not able to use the same polynomial as the S32R41 hardware has implemented
 **/


/** Pre-processor switch to enable/disable development error detection.                                          */
#ifndef CDD_RFE_DEV_ERROR_DETECT
#define CDD_RFE_DEV_ERROR_DETECT                    STD_OFF
#endif


/** Pre-processor switch to enable/disable version info report.                                                  */
#ifndef CDD_RFE_VERSION_INFO_API
#define CDD_RFE_VERSION_INFO_API		            STD_ON
#endif

/** Pre-processor switch to define single management thread or multiple management threads.
 * If single thread (which is the normal approach) - there are no necessary exclusive areas for the driver      */
#ifndef CDD_RFE_SINGLE_MANAGEMENT_THREADS
#define CDD_RFE_SINGLE_MANAGEMENT_THREADS           STD_ON
#endif

/** Pre-processor switch to define the application behavior - to stop or not after an error is detected.         */
#ifndef CDD_RFE_CFG_HALT_ON_ERROR
#define CDD_RFE_CFG_HALT_ON_ERROR                   STD_OFF
#endif

/**> The Time-Out get for Command Server response                           */
#define CDD_RFE_E_UNRESPONSIVE  1u
/**> FuSa error reported                                                    */
#define CDD_RFE_E_FUSA_ERROR    2u
/**> Error reported by the firmware                                         */
#define CDD_RFE_E_FW_ERROR      3u

#if (CDD_RFE_CFG_HALT_ON_ERROR == STD_ON)
    /**> Global variable to allow exit from \ref CDD_RFE_HALT_ON_ERROR loop         */
    extern volatile bool gsCddRfeLoopExit;
    /** Infinite loop if error detected and the option is to detect development errors. To exit the loop at debug time is possible to use gsCddRfeLoopExit variable */
    #define CDD_RFE_HALT_ON_ERROR   while(gsCddRfeLoopExit != true)   \
                                        {                               \
                                            ;   /* empty loop */        \
                                        }
#else
    #define CDD_RFE_HALT_ON_ERROR
#endif

/** @} */

/*==================================================================================================
*                                       FILE VERSION CHECKS
==================================================================================================*/
#ifndef DISABLE_MCAL_INTERMODULE_ASR_CHECK
     /* Check if CDD_Rfe_Cfg.h source file and Std_Types.h header file are of the same Autosar version */
     #if ( \
          (STD_AR_RELEASE_MAJOR_VERSION != CDD_RFE_CFG_AR_RELEASE_MAJOR_VERSION) || \
          (STD_AR_RELEASE_MINOR_VERSION != CDD_RFE_CFG_AR_RELEASE_MINOR_VERSION)  \
         )
         #error "AutoSar Version Numbers of CDD_Rfe_Cfg.h and Std_Types.h are different"
     #endif
#endif


/*==================================================================================================
                               EXTERNAL VARIABLE
==================================================================================================*/

/*================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif	/* CDD_RFE_CFG_H */
