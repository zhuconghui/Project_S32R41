/*==================================================================================================
* Project : RTD AUTOSAR 4.4
* Platform : CORTEXM
* Peripheral : SAF85XXM7
* Dependencies : none
*
* Autosar Version : 4.4.0
* Autosar Revision : ASR_REL_4_4_REV_0000
* Autosar Conf.Variant :
* SW Version : 0.9.0
* Build Version : SAF85_S32R41_RTD_0_9_0_D2207_ASR_REL_4_4_REV_0000_20220729
*
* (c) Copyright 2022 NXP Semiconductors
* All Rights Reserved.
*
* NXP Confidential. This software is owned or controlled by NXP and may only be
* used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/
/**
*   @file
*
*   @addtogroup OSIF_DRIVER
*   @{
*/

#ifndef OSIF_ARCHCFG_H
#define OSIF_ARCHCFG_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
                                         INCLUDE FILES
 1) system and project includes
 2) needed interfaces from external units
 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define OSIF_ARCHCFG_VENDOR_ID                    43
#define OSIF_ARCHCFG_AR_RELEASE_MAJOR_VERSION     4
#define OSIF_ARCHCFG_AR_RELEASE_MINOR_VERSION     7
#define OSIF_ARCHCFG_AR_RELEASE_REVISION_VERSION  0
#define OSIF_ARCHCFG_SW_MAJOR_VERSION             1
#define OSIF_ARCHCFG_SW_MINOR_VERSION             0
#define OSIF_ARCHCFG_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/
#define MCAL_ARM_MARCH      (16)  /* for ARM M4 Thumb2      */
#define MCAL_ARM_AARCH32    (32)  /* for ARM ARCH32         */
#define MCAL_ARM_AARCH64    (64)  /* for ARM ARCH64         */
#define MCAL_ARM_RARCH      (52)  /* for ARM R platform     */

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/* ARM_MIXT - is used to specify the ARM architecture MCAL_MARCH, MCAL_RARCH, MCAL_AARCH32, MCAL_AARCH64 */

#define MCAL_PLATFORM_ARM  MCAL_ARM_MARCH
                        
                
            
        
    

 
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
                                       GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* OSIF_ARCHCFG_H */
/** @} */

