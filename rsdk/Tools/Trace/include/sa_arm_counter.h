/*
 * Copyright 2017-2018,2020-2021 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */

#ifndef SA_ARM_COUNTER_H
#define SA_ARM_COUNTER_H

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
typedef enum
{
    STM_INSTANCE_0 = 0,
	STM_INSTANCE_1,
	STM_INSTANCE_2







} stm_instance_t;

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
void STM_Init(stm_instance_t instance);
uint32_t STM_GetValue(void);

#ifdef __cplusplus
}
#endif

#endif /*SA_ARM_COUNTER_H*/

/** @} */
