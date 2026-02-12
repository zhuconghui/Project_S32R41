/**************************************************************************************************
 *
 * NXP Confidential Proprietary
 *
 * Copyright 2019-2021 NXP
 * All Rights Reserved
 *
 *****************************************************************************
 *
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 *
 **************************************************************************************************/

#ifndef RSDK_GLUE_IRQ_REGISTER_API_H
#define RSDK_GLUE_IRQ_REGISTER_API_H

/** @addtogroup rsdk_glue_irq_register
 * @{
 * @brief
 * RadarSDK components depend on application provided API for interrupt handlers registration.
 * @details
 * Specifically, the drivers need to register an interrupt handler (for a specific hardware interrupt
 * request, but the other details for this (execution core, interrupt priority) need to be provided 
 * by the application. Below specified function prototypes are to be implemented at application level 
 * and linked in the final executable. RadarSDK provide example implementation for these functions 
 * for various environments. 
 *  See @ref rsdk_sa_multi_rfe.
 */

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define IRQ_REGISTER_SUCCESS (0u)
#define IRQ_REGISTER_ERROR (1u)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
/** @brief Core number identifiers.
*
*/
typedef enum
{
    RSDK_CURRENT_CORE = -1, /**< current processing core */
    RSDK_CORE_0 = 0,        /**< main core (Z4 for S32R274, A53 #0 in cluster 0 for S32R45)*/
    RSDK_CORE_1,
    RSDK_CORE_2,



    RSDK_MAX_COREID
} rsdkCoreId_t;

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/** @brief Definition for IRQ handler
 *
 */
typedef void (*rsdkIrqHandler_t)(void);

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
/** @brief       Application provided function to register interrupt handlers for drivers.
  * @return      IRQ_REGISTER_SUCCESS for success or IRQ_REGISTER_ERROR in case of error.
  */
extern uint32_t RsdkGlueIrqHandlerRegister(rsdkIrqHandler_t pIrqHandler, uint32_t irqNumber, rsdkCoreId_t execCoreId,
                                           uint8_t irqPriority);









#ifdef __cplusplus
}
#endif

#endif /* RSDK_GLUE_IRQ_REGISTER_API_H */

/** @} */
