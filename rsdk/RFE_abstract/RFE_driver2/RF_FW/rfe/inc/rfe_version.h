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

#ifndef RFE_VERSION_H
#define RFE_VERSION_H

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "rfe_types.h"

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
 * This macro defines whether this firmware has been officially released.
 * In case of an un official release, major, minor and patch indicate the latest
 * officially released version which is the basis for this firmware. The firmware hash
 * can be used to identify the firmware in that case. 
 */
#define RFE_VERSION_FW_VERSION_RELEASED     ( true )

/**
 * This macro defines the major release number.
 */
#define RFE_VERSION_FW_VERSION_MAJOR        ( 0UL )

/**
 * This macro defines the minor release number.
 */
#define RFE_VERSION_FW_VERSION_MINOR        ( 8UL )

/**
 * This macro defines the patch release number.
 */
#define RFE_VERSION_FW_VERSION_PATCH        ( 10UL )

/**
 * This macro defines the firmware hash for identifying unreleased versions.
 */
#define RFE_VERSION_FW_HASH                 ( 0x0000UL )
  
/** 
 * Defines the IC type
 *     SAF85xx: 100
 *     S32R41:  200 
 */
#define RFE_HW_TYPE                         ( 200UL )

/** 
 * Defines the commercial IC variant
 *     xx : 0 (no variant defined, evaluation sample)
 */
#define RFE_HW_VARIANT                      ( 0UL )

/**
 * Default value for Unique ID is set to 0. This is an illegal value for a CRC32
 */
#define RFE_HW_UID_NOTAVAIL                 ( 0UL )

/** 
 * Defines the IC version
 *     ES1          : 1 
 *     ES1.1 (A1MF) : 2 
*/
#define RFE_HW_VERSION                      ( 2UL )

 /** 
 * Defines the firmware variant
 *     1: E2 T0  trim, evaluation sample
 *     2: E2 OTP trim, evaluation sample
 *     3: E2\E5 OTP trim, evaluation sample
 *     4: A1-E5-T2MF
 */
#define RFE_FW_VARIANT                      ( 4UL )

/** 
 * Defines the firmware variant , follows
 *     E2 T0/T1 see above: ( offset 1000000UL )
 *           Supporting Abstract API Validation in rfeSysValFw. 
 *           Firmware based upon rfeFw with RFE_FW_VARIANT  
 *           Contains rfeFw code with additional indirect spi transfers .
 */
#define RFE_FW_VARIANT_SYS_VAL        ( 1000000UL | ( RFE_FW_VARIANT ) )

/** 
 * Defines the firmware variant , follows
 *     E2 T0/T1 see above: ( offset 2000000UL )
 *           Supporting Internal API Validation in rfeIpValFw. 
 *           Firmware based upon rfeValMiniFw  with RFE_FW_VARIANT  
 *           Contains rfeValMiniFw with additional indirect spi transfers and internal API dispatcher
 *              for out of context calls 
 */
#define RFE_FW_VARIANT_IP_VAL        ( 2000000UL | ( RFE_FW_VARIANT ) )

/** 
 * Defines the firmware variant , follows
 *     E2 T0/T1 see above: ( offset 3000000UL )
 *           Firmware based upon PROXY based 'firmware'  with RFE_BUILD_PROXY_VAL_FW  
 */
#define RFE_FW_VARIANT_PROXY_VAL        ( 3000000UL | ( RFE_FW_VARIANT ) )

/** 
 * Defines the firmware variant , follows
 *     E2 T0/T1 see above: ( offset 4000000UL )
 *           Supporting Abstract API Validation in rfeFuSaValFw. 
 *           Firmware based upon rfeFw with RFE_FW_VARIANT  
 *           Contains rfeFw code with additional Validation Hook to support fault injection .
 */
#define RFE_FW_VARIANT_FUSA_VAL        ( 4000000UL | ( RFE_FW_VARIANT ) )

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
 /**
 * \brief  Returns the version struct
 *
 *
 * \returns Returns the current version struct
 *
 *        Note: Do NOT inline this function.
 *  
 */ 
rfe_version_t rfe_get_version( void );

#endif // !RFE_VERSION_H
