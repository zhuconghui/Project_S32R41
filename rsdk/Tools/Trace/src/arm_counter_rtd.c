/*
 * Copyright 2020-2024 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/



#include "S32R41_STM.h"





#include "sa_arm_counter.h"

/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
static volatile STM_Type* STM_trace;

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
*                                       GLOBAL FUNCTIONS
==================================================================================================*/
/**
* @brief        Configures a STM (System Timer Module) instance to start counting.
* @details      Configures necessary registers in order to setup the chosen STM.
*
* @param[in]    instance: index of the STM instance to be used
*
* @return       void
*/
void STM_Init(stm_instance_t instance)
{
	/* Select STM instance to be used for trace */
    switch(instance)
    {
    	case STM_INSTANCE_0:
    		STM_trace = IP_STM_0;
    		break;
    	case STM_INSTANCE_1:
			STM_trace = IP_STM_1;
			break;
    	case STM_INSTANCE_2:
			STM_trace = IP_STM_2;
			break;
    }

    /* Set  TEN=1 (enable) and CPS=0 (clock divider=1) to enable STM */
    STM_trace->CR = 0x1u;

    /* Set STM counter to 0 */
    STM_trace->CNT = 0;
}

/**
* @brief          Get counter from system timer.
* @details        Reads and returns the value of the used STM counter register.
*
* @return         counter value of the STM used.
*
* @pre            STM_Init() must be called first.
*/
uint32_t STM_GetValue(void)
{
    return STM_trace->CNT;
}
