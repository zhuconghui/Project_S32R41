/*
 * Copyright 2018-2024 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 */

#ifndef RSDK_DSP_DISPATCHER_H
#define RSDK_DSP_DISPATCHER_H

/*==================================================================================================
*                                        INCLUDE FILES
==================================================================================================*/
#include <stdint.h>
#include "rsdk_toolchain_helper.h"
#include "rsdk_status.h"

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/**
  * @anchor   Anchor_RSDK_DSPHD_MSG_BASE_ADDR_sa
  * @brief    Base address used for referencing the DSP Host Driver's message buffer.
  * @details  This symbol should be defined identically in the linker files of both applications running on the DSP and host CPU.
  */
RSDK_DECL_LNK_SYM(RSDK_DSPHD_MSG_BASE_ADDR);

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/** @addtogroup dsp_disp_api_const
* @{
*/

#define RSDK_DSP_SPT_EVT0_INTEN_BIT  (1u << 0u)  /**< Bit used to enable the SPT Event 0 interrupt. Intended to be assigned to dspDispInit_t::sptEvtIntEnBitmap */
#define RSDK_DSP_SPT_EVT1_INTEN_BIT  (1u << 1u)  /**< Bit used to enable the SPT Event 1 interrupt. Intended to be assigned to dspDispInit_t::sptEvtIntEnBitmap */
#define RSDK_DSP_SPT_EVT2_INTEN_BIT  (1u << 2u)  /**< Bit used to enable the SPT Event 2 interrupt. Intended to be assigned to dspDispInit_t::sptEvtIntEnBitmap */
#define RSDK_DSP_SPT_EVT3_INTEN_BIT  (1u << 3u)  /**< Bit used to enable the SPT Event 3 interrupt. Intended to be assigned to dspDispInit_t::sptEvtIntEnBitmap */
#define RSDK_DSP_SPT_EVT4_INTEN_BIT  (1u << 4u)  /**< Bit used to enable the SPT Event 4 interrupt. Intended to be assigned to dspDispInit_t::sptEvtIntEnBitmap */
#define RSDK_DSP_SPT_EVT5_INTEN_BIT  (1u << 5u)  /**< Bit used to enable the SPT Event 5 interrupt. Intended to be assigned to dspDispInit_t::sptEvtIntEnBitmap */
#define RSDK_DSP_SPT_EVT6_INTEN_BIT  (1u << 6u)  /**< Bit used to enable the SPT Event 6 interrupt. Intended to be assigned to dspDispInit_t::sptEvtIntEnBitmap */
#define RSDK_DSP_SPT_EVT7_INTEN_BIT  (1u << 7u)  /**< Bit used to enable the SPT Event 7 interrupt. Intended to be assigned to dspDispInit_t::sptEvtIntEnBitmap */
#define RSDK_DSP_SPT_EVT8_INTEN_BIT  (1u << 8u)  /**< Bit used to enable the SPT Event 8 interrupt. Intended to be assigned to dspDispInit_t::sptEvtIntEnBitmap */
#define RSDK_DSP_SPT_EVT9_INTEN_BIT  (1u << 9u)  /**< Bit used to enable the SPT Event 9 interrupt. Intended to be assigned to dspDispInit_t::sptEvtIntEnBitmap */
#define RSDK_DSP_SPT_EVT10_INTEN_BIT (1u << 10u) /**< Bit used to enable the SPT Event 10 interrupt. Intended to be assigned to dspDispInit_t::sptEvtIntEnBitmap */
#define RSDK_DSP_SPT_EVT11_INTEN_BIT (1u << 11u) /**< Bit used to enable the SPT Event 11 interrupt. Intended to be assigned to dspDispInit_t::sptEvtIntEnBitmap */
#define RSDK_DSP_SPT_EVT12_INTEN_BIT (1u << 12u) /**< Bit used to enable the SPT Event 12 interrupt. Intended to be assigned to dspDispInit_t::sptEvtIntEnBitmap */

/** @}*/
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/** @addtogroup dsp_disp_api_data_type
* @{
*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
* @brief          Alias datatype for specifying generic DSP function pointers.
*/
typedef void *rsdkDspFuncPtr_t;


/**
* @brief Definition of callback function type to be called by the DSP interrupt handlers.
* @details This is offered to the user to customize functionality of the interrupt handlers.
*
* @param[in]    arg   ID of the interrupt
* @return       void
*
* */
typedef void (*rsdkDspIsrCb_t)(uint32_t arg);



/**
* @brief This structure is used to initialize the IPCF communication parameters used between the Dispatcher and the Host Driver
* @details They should be initialized by the user with the corresponding values defined in ipcf_Ip_Cfg.h
*/
typedef struct
{
	uint8_t ipcfInstance;  				/**< IPCF instance ID */
	uint8_t ctrlChanId; 				/**< IPCF Control Channel ID */
	uint8_t asyncChanId; 				/**< IPCF Async Channel ID */
} dspDispCommParams_t;




/**
* @brief This structure is used to initialize the prefetch aggression parameters for HW Data, Hw Instr, Sw
* @details They should be initialized by the user
*/
typedef struct
{
	uint8_t prefetchAggressionData;   	/**< level of prefetch aggression for data ; 0xFu -> most aggressive */
	uint8_t prefetchAggressionInstr; 	/**< level of prefetch aggression for instruction ; 0xFu -> most aggressive*/
	uint8_t prefetchAggressionSW;		/**< level of prefetch aggression for SW ; 0xFu -> most aggressive*/
} dspPrefetchAggrParams_t;


/**
* @brief          Initialization parameters for the Dispatcher.
* @details      This structure is only used by RsdkSptInit(). Must be allocated and initialized by the caller.
*               Its content is not modified by the Dispatcher.
*/
typedef struct {

    rsdkDspIsrCb_t sptEvtIsrCb; /**< Callback function to be called from the SPT Event interrupt handlers.
                                     Receives the event number as argument.
                                     If no callback is required then it can be initialized to NULL. */

    uint16_t sptEvtIntEnBitmap; /**< Allows the user to enable the SPT Event interrupts individually.
                                    Can be set by adding together the #RSDK_DSP_SPT_EVT0_INTEN_BIT.. #RSDK_DSP_SPT_EVT12_INTEN_BIT values*/


    dspDispCommParams_t commParams; /**< Communication parameters used between the Dispatcher and the Host Driver */

    rsdkDspFuncPtr_t pFuncTable; /**< pointer to a table containing pointers to external DSP functions.
                                    The table itself is built starting from a list of function names, using the preprocessor.
                                    The list of function names is shared between the DSP and the host CPU which integrates the DSP image (e.g. A53).
                                    See /Apps/DSP_Dispatcher_example/src/dispatcher_func_list_dsp.h */
    uint32_t funcTableSize;         /**< number of functions registered in the table */

    dspPrefetchAggrParams_t	prefAggrParams;		/**< prefetch aggresivness parameters */

} dspDispInit_t;
/** @}*/


/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/** * @addtogroup dsp_disp_api_func
* @{
*/
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

/**
* @brief    Initialize the DSP Dispatcher to be ready for receiving commands from SPT.
* @details  Initializes the MPU and exceptions table, enables the interrupts (all except the timer interrupt), 
*           sets the handlers, initializes the internal state of the Dispatcher, initializes the prefetch aggressiveness
*
* @param[in] pDispInitInfo: Initialization parameters for the Dispatcher: MPU table, SPT events callbacks, prefetch aggressiveness
*
* @return #RSDK_SUCCESS or a specific error code.
*
* @pre   It should be called right after DSP boot, before running the RsdkDspRunDispatcher().
*
*/
rsdkStatus_t RsdkDspDispatcherInit(dspDispInit_t const *const pDispInitInfo);

/**
* @brief    Runs the Dispatcher scheduling loop
* @details  The Dispatcher runs in an infinite loop: waits for commands from the SPT command queue,
*             parses them and triggers execution of requested DSP algorithms.
*
* @pre   It should be called right after DSP boot, before running the RsdkDspDispatcherRun().
* @post  This function never returns during normal operation, but only if it detects certain errors in execution.
*          In those cases it signals an error code through the SPT "DSP" interrupt before exiting.
*
*/
void RsdkDspDispatcherRun(void);

/** @}*/

#ifdef __cplusplus
}
#endif

#endif /*RSDK_DSP_DISPATCHER_H*/
