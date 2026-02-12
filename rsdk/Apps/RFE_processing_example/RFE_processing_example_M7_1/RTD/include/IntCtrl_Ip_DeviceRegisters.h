/*==================================================================================================
*   Project              : RTD AUTOSAR 4.7
*   Platform             : CORTEXM
*   Peripheral           : 
*   Dependencies         : none
*
*   Autosar Version      : 4.7.0
*   Autosar Revision     : ASR_REL_4_7_REV_0000
*   Autosar Conf.Variant :
*   SW Version           : 2.0.0
*   Build Version        : SAF85xx_SAF86xx_S32R41_RTD_2_0_0_P03_D2404_ASR_REL_4_7_REV_0000_20240405
*
*   Copyright 2021 - 2024 NXP
*
*   NXP Confidential. This software is owned or controlled by NXP and may only be
*   used strictly in accordance with the applicable license terms. By expressly
*   accepting such terms or by downloading, installing, activating and/or otherwise
*   using the software, you are agreeing that you have read, and that you agree to
*   comply with and are bound by, such license terms. If you do not agree to be
*   bound by the applicable license terms, then you may not retain, install,
*   activate or otherwise use the software.
==================================================================================================*/

#ifndef INTCTRL_IP_DEVICE_REGISTERS_H_
#define INTCTRL_IP_DEVICE_REGISTERS_H_

/**
*   @file
*
*   @addtogroup IntCtrl_Ip
*   @{
*/

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include "StandardTypes.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define PLATFORM_INTCTRL_IP_DEVICE_REGISTERS_TYPES_VENDOR_ID                    43
#define PLATFORM_INTCTRL_IP_DEVICE_REGISTERS_SW_MAJOR_VERSION                   2
#define PLATFORM_INTCTRL_IP_DEVICE_REGISTERS_SW_MINOR_VERSION                   0
#define PLATFORM_INTCTRL_IP_DEVICE_REGISTERS_SW_PATCH_VERSION                   0


#if defined(S32G2XX)
    #include "S32G274A_SCB.h"
    #include "S32G274A_NVIC.h"
    #include "S32G274A_MSCM.h"
    
typedef struct {
    __IO uint32_t IntStatusR;  /**< Interrupt Router CPn Interruptx Status Register, array offset: 0x200, index*0x20, index2*0x8 */
    __O  uint32_t IGR;  /**< Interrupt Router CPn Interruptx Generation Register, array offset: 0x204, index*0x20, index2*0x8 */
} MSCM_IRCP_IR_Type;

typedef struct {
    MSCM_IRCP_IR_Type IRCPnIRx[7][4];
} MSCM_IRCPnIRx_Type;

#define MSCM_IRCPnIRx ((volatile MSCM_IRCPnIRx_Type*)&MSCM->IRCP0ISR0) 

#elif defined(S32K3XX)
    #include "S32K344.h"
#elif defined(S32R45)
    #include "S32R45_SCB.h"
    #include "S32R45_NVIC.h"
    #include "S32R45_MSCM.h"
    
typedef struct {
    __IO uint32_t IntStatusR;  /**< Interrupt Router CPn Interruptx Status Register, array offset: 0x200, index*0x20, index2*0x8 */
    __O  uint32_t IGR;  /**< Interrupt Router CPn Interruptx Generation Register, array offset: 0x204, index*0x20, index2*0x8 */
} MSCM_IRCP_IR_Type;

typedef struct {
    MSCM_IRCP_IR_Type IRCPnIRx[7][4];
} MSCM_IRCPnIRx_Type;
#define MSCM_IRCPnIRx ((volatile MSCM_IRCPnIRx_Type*)&MSCM->IRCP0ISR0)
#else
    #error "Unknown platform!"
#endif


#endif /* INTCTRL_IP_DEVICE_REGISTERS_H_ */

/** @} */
