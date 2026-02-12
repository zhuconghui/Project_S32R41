/**************************************************************************************************
* Copyright 2023 NXP
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
 *   Project              : S32R41_RFE_FW
 *   Platform             : S32R41
 *****************************************************************************/

/*==================================================================================================
 *                                        INCLUDE FILES
 ==================================================================================================*/
#include "rfeHwLink.h"
#ifdef USING_RTD_DRIVERS
#include "Port.h"
#include "Dio.h"
#include "Dio_Cfg.h"
#include "Spi.h"
#include "Spi_Cfg.h"
#include "Gpt.h"
#include "Gpt_Ipw_PBcfg.h"
#include "Platform.h"
#else
#include "rfeHwStm.h"
#include "rsdk_system_timer_cm7.h"
#include "rfeHwSpi.h"
#endif

#include "Rfe20_PCCfg.h"

#ifdef RFE_DEBUG
#ifdef USING_RTD_DRIVERS
#include "CDD_Uart.h"
#include "Linflexd_Uart_Ip_Irq.h"
#include "Port.h"
#endif
#ifdef USING_RTD_DRIVERS_EXCEPT_UART
#include "lin.h"
#endif
#include "stdio.h"
#include "stdarg.h"
#include "string.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                       LOCAL MACROS
 ==================================================================================================*/ 
#ifdef USING_RTD_DRIVERS
#define STM0_CHANNEL_COUNTER 0U
#define STM0_CHANNEL_DELAY   1U
#define UART_CHANNEL  		 0U
#endif
#define MAX_MSG_LENGTH 700
/*==================================================================================================
 *                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
 ==================================================================================================*/

#define EXT_IRQ_NUM (4)

#define MCU_INT_IRQ_LEADER   (20)
#define MCU_INT_IRQ_FOLLOWER (21)
#define ERROR_N_IRQ_LEADER   (15)
#define ERROR_N_IRQ_FOLLOWER (24)
// 52 -> SIUL_0_EIRQ20 mcuIntChirpStartOut Leader
// 53 -> SIUL_0_EIRQ21 mcuIntChirpStartOut Follower
// 47 -> SIUL_0_EIRQ15 errorN Leader
// 56 -> SIUL_0_EIRQ24 errorN Follower

#define ERROR_N_IRQ_MASK_LEADER (1u << ERROR_N_IRQ_LEADER)
#define MCU_INT_IRQ_MASK_LEADER (1u << MCU_INT_IRQ_LEADER)
#define MCU_INT_IRQ_MASK_FOLLOWER (1u << MCU_INT_IRQ_FOLLOWER)
#define ERROR_N_IRQ_MASK_FOLLOWER (1u << ERROR_N_IRQ_FOLLOWER)

/*==================================================================================================
 *                                      LOCAL VARIABLES
 ==================================================================================================*/
static uint32_t extIrqMasks;

/*==================================================================================================
 *                                      GLOBAL VARIABLES
 ==================================================================================================*/
char gRfeDbgMsg[MAX_MSG_LENGTH];
/*==================================================================================================
 *                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
void SIUL2_IRQHandler(void);
/*==================================================================================================
 *                                   GLOBAL FUNCTION PROTOTYPES
==================================================================================================*/
extern void rfeSwDynamicTables_IQUpdate(void);

/*==================================================================================================
 *                                       LOCAL FUNCTIONS
==================================================================================================*/

/*==================================================================================================
 *                                      GLOBAL FUNCTIONS
 ==================================================================================================*/
#ifdef USING_RTD_DRIVERS
void RfeHwGpioInit(void)
{

    // Initialize pins
    Port_Init(NULL_PTR);
    // Initialize IRQs
    Platform_Init(NULL_PTR);
#ifdef RFE_DEBUG
    Platform_InstallIrqHandler(LINFLEXD0_IRQn, LINFLEXD0_UART_IRQHandler, NULL_PTR);
    Platform_SetIrq(LINFLEXD0_IRQn, true);
#endif

    // Enable SIUL2 IRQ
    Platform_InstallIrqHandler(SIUL2_INT_IRQn, &SIUL2_IRQHandler, NULL_PTR);
    Platform_SetIrq(SIUL2_INT_IRQn, true);
#ifdef RFE_MODE_CASCADED
    extIrqMasks = MCU_INT_IRQ_MASK_FOLLOWER;
#else
    extIrqMasks = MCU_INT_IRQ_MASK_LEADER;
#endif
	IP_SIUL2_0->DISR0 |= extIrqMasks;    // Clear any pending interrupts
	IP_SIUL2_0->DIRER0 |= extIrqMasks;   // Enable the TEF82XX pin interrupt
#ifdef MCU_INT_EDGE_FALLING
	IP_SIUL2_0->IFEER0 |= extIrqMasks;   // Enable the interrupt for falling direction
#else
	IP_SIUL2_0->IREER0 |= extIrqMasks;   // SIUL2 Interrupt Rising-Edge Event Enable
#endif
}

void SIUL2_IRQHandler(void)
{
    uint32_t reg = IP_SIUL2_0->DISR0;

    // Clear INT
    IP_SIUL2_0->DISR0 = reg;
    // Call IQ updater
		rfeSwDynamicTables_IQUpdate();
}

void RfeHwGpioSet(uint32_t frontendId, TEF82XX_ExtPinID_e HostPinID, uint8_t pinState)
{
    pinState = (pinState > 0) ? 1 : 0;

    switch(HostPinID)
    {
    case e_CHIRPSTART_IN_PAD:
    	if (frontendId == 0U)
    	{
    		Dio_WriteChannel(DioConf_DioChannel_chirpStartIn_Leader, (Dio_LevelType)pinState);
    	}
    	else
    	{
    		// not connected
    	}
		break;
    case e_ERRORRESET:
    	if (frontendId == 0U)
    	{
    		Dio_WriteChannel(DioConf_DioChannel_errorReset_Leader, (Dio_LevelType)pinState);
    	}
    	else
    	{
    		// not connected
    	}
		break;
    case e_TX1_I_PS:
    	if (frontendId == 0U)
    	{
    		Dio_WriteChannel(DioConf_DioChannel_tx1IPs_Leader, (Dio_LevelType)pinState);
    	}
    	else
    	{
    		Dio_WriteChannel(DioConf_DioChannel_tx1IPs_Follower, (Dio_LevelType)pinState);
    	}
    	break;
    case e_TX2_I_PS:
    	if (frontendId == 0U)
    	{
    		Dio_WriteChannel(DioConf_DioChannel_tx2IPs_Leader, (Dio_LevelType)pinState);
    	}
    	else
    	{
    		Dio_WriteChannel(DioConf_DioChannel_tx2IPs_Follower, (Dio_LevelType)pinState);
    	}
		break;
    case e_TX3_I_PS:
    	if (frontendId == 0U)
    	{
    		Dio_WriteChannel(DioConf_DioChannel_tx3IPs_Leader, (Dio_LevelType)pinState);
    	}
    	else
    	{
    		Dio_WriteChannel(DioConf_DioChannel_tx3IPs_Follower, (Dio_LevelType)pinState);
    	}
		break;
    case e_TX1_Q_PS:
    	if (frontendId == 0U)
    	{
    		Dio_WriteChannel(DioConf_DioChannel_tx1QPs_Leader, (Dio_LevelType)pinState);
    	}
    	else
    	{
    		Dio_WriteChannel(DioConf_DioChannel_tx1QPs_Follower, (Dio_LevelType)pinState);
    	}
		break;
    case e_TX2_Q_PS:
    	if (frontendId == 0U)
    	{
    		Dio_WriteChannel(DioConf_DioChannel_tx2QPs_Leader, (Dio_LevelType)pinState);
    	}
    	else
    	{
    		Dio_WriteChannel(DioConf_DioChannel_tx2QPs_Follower, (Dio_LevelType)pinState);
    	}
    	break;
    case e_TX3_Q_PS:
    	if (frontendId == 0U)
    	{
    		Dio_WriteChannel(DioConf_DioChannel_tx3QPs_Leader, (Dio_LevelType)pinState);
    	}
    	else
    	{
    		Dio_WriteChannel(DioConf_DioChannel_tx3QPs_Follower, (Dio_LevelType)pinState);
    	}
    	break;
    case e_HRESET:
    	if (frontendId == 0U)
    	{
    		Dio_WriteChannel(DioConf_DioChannel_hReset_Leader, (Dio_LevelType)pinState);
    	}
    	else
    	{
    		// not connected
    	}
		break;
    default:
    	break;
    }
}

/*===================================================================================================================*/

void RfeHwGpioGet(uint32_t frontendId, TEF82XX_ExtPinID_e HostPinID, uint8_t *pinState)
{
    switch(HostPinID)
    {
    case e_MCUINT_CHIRPSTART_OUT_PAD:
    	if (frontendId == 0U)
    	{
    		*pinState = Dio_ReadChannel(DioConf_DioChannel_mcuIntChirpStartOut_Leader);
    	}
    	else
    	{
    		*pinState = Dio_ReadChannel(DioConf_DioChannel_mcuIntChirpStartOut_Follower);
    	}
		break;
    case e_ERRORN:
    	if (frontendId == 0U)
    	{
    		*pinState = Dio_ReadChannel(DioConf_DioChannel_errorN_Leader);
    	}
    	else
    	{
    		*pinState = Dio_ReadChannel(DioConf_DioChannel_errorN_Follower);
    	}
		break;
    default:
    	*pinState = 0;
    	break;
    }
}
#endif

//-------------------------------- TIMERS ----------------------------------------------------------
void RfeHwTimersInit(rfe_error_t* rfe___error___pointer)
{
	if(*rfe___error___pointer == rfe_error_none_e)
	{
#ifdef USING_RTD_DRIVERS
	    // Initialize the Gpt driver
	    Gpt_Init(NULL_PTR);
	    //Gpt_StartTimer(0U, 0U);
#else
		// STM for TEF82xx LLD
		// Use for system hart beat of 25ns
		// RfeHwStmInit() return always RSDK_SUCCESS, the return value will not be checked
		RfeHwStmInit();

		// CM_7 Core system timer init used for delays and timeouts
		if(RsdkSysTimerCm7Init() != RSDK_SUCCESS)
		{
			*rfe___error___pointer = rfe_error_sys_timer_cm7_init;
		}
#endif
	}
}

uint32_t RfeHwHeartBeatTimerGetValue(rfe_error_t* rfe___error___pointer)
{
	if(*rfe___error___pointer == rfe_error_none_e)
	{
#ifdef USING_RTD_DRIVERS
		return (uint32_t)Stm_Ip_GetCounterValue(STM_0_ChannelConfig_PB[STM0_CHANNEL_COUNTER].hwChannel);
#else
		return RfeHwStmTimerGetValue();
#endif
	}
	return 0l;
}

void RfeHwDelayUs(uint32_t us)
{
#ifdef USING_RTD_DRIVERS
	uint32_t ns25Units = us * 40;

	Gpt_StartTimer(STM0_CHANNEL_DELAY, ns25Units);
	while(Gpt_GetTimeElapsed(STM0_CHANNEL_DELAY) < ns25Units) ;
	Gpt_StopTimer(STM0_CHANNEL_DELAY);
#else
	RsdkSysTimerCm7DelayUs(us);
#endif
}

//-------------------------------- SPI ----------------------------------------------------------
void RfeHwSpiInitialize(uint32_t frontEndId, rfe_error_t* rfe___error___pointer)
{
#ifndef USING_RTD_DRIVERS
	uint32_t status;
#endif
	if(*rfe___error___pointer == rfe_error_none_e)
	{
#ifdef USING_RTD_DRIVERS
		if (frontEndId == 0)
		{
			Spi_Init(NULL_PTR);
		}
#else
		status = RfeHwSpiInit(frontEndId);
		if (status == SPI_ERR_WRG_UNIT_ID)
		{
			*rfe___error___pointer = (rfe_error_sys_spi_wrg_unit_id | (frontEndId << 8));
		}
#endif
	}
}

#ifdef USING_RTD_DRIVERS
uint32_t RfeHwSpiTransfer(uint32_t frontEndId, uint8_t *pTxData, uint8_t *pRxData, uint16_t length)
{
	Std_ReturnType status;

	status = Spi_SetupEB( (Spi_ChannelType)frontEndId, (const Spi_DataBufferType *)pTxData, (Spi_DataBufferType *)pRxData, (Spi_NumberOfDataType)length);
	if ((Std_ReturnType)E_OK == status)
	{
		status = Spi_SyncTransmit((Spi_SequenceType)frontEndId);
	}
	return (uint32_t) status;
}
#endif

#ifdef RFE_DEBUG
//-------------------------------- UART ----------------------------------------------------------
void RfeInitDebug(rfe_error_t* rfe___error___pointer)
{
	if(*rfe___error___pointer == rfe_error_none_e)
	{
#ifndef USING_RTD_DRIVERS_EXCEPT_UART
	    // Initialize IRQs
	    Platform_Init(NULL_PTR);
	    Platform_InstallIrqHandler(LINFLEXD0_IRQn, LINFLEXD0_UART_IRQHandler, NULL_PTR);
	    // Initializes UART driver
	    Uart_Init(NULL_PTR);
#else
		// Lin UART
		lin_init(LIN_CLK_100);
#endif
	}
}

void RfeDbgPrintMsg(const char *fmt, ...)
{
	va_list args;
	uint32 varRemainingBytes;

	va_start(args, fmt);
    vsprintf(gRfeDbgMsg, fmt, args);

#ifndef USING_RTD_DRIVERS_EXCEPT_UART // TODO update this once RSDK-9855 is solved
    (void)Uart_SyncSend(UART_CHANNEL, (const uint8 *)gRfeDbgMsg, strlen(gRfeDbgMsg),1);
    while(Uart_GetStatus(UART_CHANNEL, &varRemainingBytes, UART_SEND) == UART_STATUS_OPERATION_ONGOING);
    (void)Uart_SyncSend(UART_CHANNEL, (const uint8 *)"\r", 1,1);
   while(Uart_GetStatus(UART_CHANNEL, &varRemainingBytes, UART_SEND) == UART_STATUS_OPERATION_ONGOING);
#else
   (void)varRemainingBytes;
    uart_printf(gRfeDbgMsg);
#endif
}
#endif

//-------------------------------- Configure IRQ -------------------------------------------------
void RfeHwSetIRQ(void)
{

}

void RfeHwRaiseIRQ(uint32_t apiIrq, uint32_t eventIrq)
{
    (void)apiIrq;
    (void)eventIrq;
	// TBD
}


#ifdef __cplusplus
}
#endif

/*******************************************************************************
 * EOF
 ******************************************************************************/

/** @} */
