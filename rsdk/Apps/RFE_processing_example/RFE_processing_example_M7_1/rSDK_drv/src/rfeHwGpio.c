/*==================================================================================================
 *
 * Copyright 2023 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 *
==================================================================================================*/

/*==================================================================================================
 *                                        INCLUDE FILES
 ==================================================================================================*/
#include "stddef.h"
#include "rsdk_S32R41.h"
#include "rfeHwGpio.h"
#include "interrupts_cm7.h"
#include "Rfe20_PCCfg.h"
#include "rfeHwConfig.h"

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                       LOCAL MACROS
 ==================================================================================================*/
 
#define TEF82XX_MCUINT_CHIRPSTART_OUT_EIRQ  23u     // External interrupt number
#define FE0_ERROR_N_EIRQ                    15u     // External interrupt bit position for FE_0
#define FE1_ERROR_N_EIRQ                    24u     // External interrupt bit position for FE_1

#define ARRAY_SIZE(_x) (sizeof(_x)/sizeof(_x[0]))

/* SIUL2 MSCR and IMCR helper macros */
#define B_OBE     (1 << 21)
#define B_IBE     (1 << 19)
#define B_SRE(x)  ((x & 7) << 14)
#define B_SSS(x)  (x & 7)
#define B_IMCR(x) (x - 512) // I/O mux sheet gives IMCR index offset by 512

/*==================================================================================================
 *                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
 ==================================================================================================*/
/*
 * Enumeration for the digital signals used by front-ends
 */
const uint32_t tef82xxGpioIds[] = {
	e_SYS_CHIRPSTART_IN_PAD,
	e_SYS_MCUINT_CHIRPSTART_OUT_PAD,
	e_SYS_ERRORN,
	e_SYS_ERRORRESET,
	e_SYS_TX1_I_PS,
	e_SYS_TX2_I_PS,
	e_SYS_TX3_I_PS,
	e_SYS_TX1_Q_PS,
	e_SYS_TX2_Q_PS,
	e_SYS_TX3_Q_PS,
	e_SYS_HRESET
};

/*==================================================================================================
 *                                      LOCAL VARIABLES
 ==================================================================================================*/

static const uint32_t gsGpioIrqMasks[RFE_NUM_CONNECTED_FRONT_ENDS] = {
        1u << FE0_ERROR_N_EIRQ, 1u << FE1_ERROR_N_EIRQ
};

static RfeErrorPinCallback gspFeErrorCallback = NULL;
/*==================================================================================================
 *                                      GLOBAL VARIABLES
 ==================================================================================================*/

/*==================================================================================================
 *                                      LOCAL FUNCTIONS
 ==================================================================================================*/
#ifndef USING_RTD_DRIVERS
static gpio_t GpioInfoGet(uint32_t pinId, uint32_t feId)
{
    gpio_t gpioInfo;

    if(feId < RFE_NUM_USED_FRONT_ENDS)
    {
        switch (pinId)
        {
        case e_SYS_CHIRPSTART_IN_PAD:
            gpioInfo = gsTef82xxConf[feId].fePins.chirpStartIn;
            break;
        case e_SYS_MCUINT_CHIRPSTART_OUT_PAD:
            gpioInfo = gsTef82xxConf[feId].fePins.mcuIntChirpStartOut;
            break;
        case e_SYS_ERRORN:
            gpioInfo = gsTef82xxConf[feId].fePins.errorN;
            break;
        case e_SYS_ERRORRESET:
            gpioInfo = gsTef82xxConf[feId].fePins.errorReset;
            break;
        case e_SYS_TX1_I_PS:
            gpioInfo = gsTef82xxConf[feId].fePins.tx1IPs;
            break;
        case e_SYS_TX2_I_PS:
            gpioInfo = gsTef82xxConf[feId].fePins.tx2IPs;
            break;
        case e_SYS_TX3_I_PS:
            gpioInfo = gsTef82xxConf[feId].fePins.tx3IPs;
            break;
        case e_SYS_TX1_Q_PS:
            gpioInfo = gsTef82xxConf[feId].fePins.tx1QPs;
            break;
        case e_SYS_TX2_Q_PS:
            gpioInfo = gsTef82xxConf[feId].fePins.tx2QPs;
            break;
        case e_SYS_TX3_Q_PS:
            gpioInfo = gsTef82xxConf[feId].fePins.tx3QPs;
            break;
        case e_SYS_HRESET:
            gpioInfo = gsTef82xxConf[feId].fePins.hReset;
            break;
        default:
            gpioInfo = (gpio_t){-1, 0, IN}; // Return negative MSCR
            break;
        }
    }
    else
    {
        gpioInfo = (gpio_t){-1, 0, IN}; // Return negative MSCR
    }
    return gpioInfo;
}

/*==================================================================================================
 *                                      GLOBAL FUNCTIONS
 ==================================================================================================*/

void RfeHwGpioInit(void)
{
    gpio_t  gpioInfo;
    uint32_t id, feId, gpioIdx;
    SIUL2_MSCR_tag mscrVal;

    mscrVal.B.OBE = 0;   // output buffer disabled
    mscrVal.B.ODE = 0;   // open drain disabled
    mscrVal.B.IBE = 1;   // input buffer enable
    mscrVal.B.SRE = 0x6; // 110b: Fmax=10 MHz
    mscrVal.B.PUE = 0;   // no pullup
    mscrVal.B.PUS = 0;   // pull down
    mscrVal.B.RCVR = 1;  // single endded receiver
    mscrVal.B.SMC = 0;   // disable output when in safe mode
    mscrVal.B.SSS = 0;   // GPIO

    for (feId = 0; feId < RFE_NUM_USED_FRONT_ENDS; feId++)
    {
        for (gpioIdx = 0; gpioIdx < ARRAY_SIZE(tef82xxGpioIds); gpioIdx++)
        {
            id = tef82xxGpioIds[gpioIdx];
            gpioInfo = GpioInfoGet(id, feId);
            if (gpioInfo.mscrNum >= 0)
            {
                if (gpioInfo.dir == OUT)
                {
                    mscrVal.B.OBE = 1;   // output buffer enabled
                    mscrVal.B.IBE = 0;   // input buffer disabled
                }
                else
                {
                    mscrVal.B.OBE = 0;   // output buffer disabled
                    mscrVal.B.IBE = 1;   // input buffer enabled
                }
                SIUL2_0.MSCR[gpioInfo.mscrNum].R = mscrVal.R;
            }
        }
		SIUL2_0.MSCR[gsTef82xxConf[feId].spiPins.dspi_sck.mscrNum].R = (B_OBE | B_SRE(7) | B_SSS(gsTef82xxConf[feId].spiPins.dspi_sck.sss));
		SIUL2_0.MSCR[gsTef82xxConf[feId].spiPins.dspi_sout.mscrNum].R = (B_OBE | B_SRE(7) | B_SSS(gsTef82xxConf[feId].spiPins.dspi_sout.sss));
		SIUL2_0.MSCR[gsTef82xxConf[feId].spiPins.dspi_sin.mscrNum].R = B_IBE;
		SIUL2_0.IMCR[B_IMCR(gsTef82xxConf[feId].spiPins.dspi_sin.imcrNum)].R = gsTef82xxConf[feId].spiPins.dspi_sin.sss;
		SIUL2_0.MSCR[gsTef82xxConf[feId].spiPins.dspi_pcs.mscrNum].R = (B_OBE | B_SRE(7) | B_SSS(gsTef82xxConf[feId].spiPins.dspi_pcs.sss));
    }


#ifdef RFE_DEBUG
	/* LIN_0_TX: PD_10 */
	SIUL2_0.MSCR[58].R = (B_OBE | B_SRE(4) | B_SSS(1)); // SSS = 001, SRE = 100, IBE = 0, OBE = 1
	/* LIN_0_RX: PD_11 */
	SIUL2_0.MSCR[59].R = B_IBE; // IBE = 1
	SIUL2_0.IMCR[B_IMCR(608)].R = 2; // SSS = 2
#endif
}

/*===================================================================================================================*/

void RfeHwGpioSet(uint32_t frontendId, SYS_ExtPinID_e HostPinID, uint8_t pinState)
{
    gpio_t  gpioInfo;
    pinState = (pinState > 0) ? 1 : 0;

	gpioInfo = GpioInfoGet(HostPinID, frontendId);

    // Check if the GPIO is connected
    if (gpioInfo.mscrNum >= 0)
    {
        ((SIUL2_GPDO_tag *)gpioInfo.pReg)->B.PDO_N = pinState;
    }
}

/*===================================================================================================================*/

void RfeHwGpioGet(uint32_t frontendId, SYS_ExtPinID_e HostPinID, uint8_t *pinState)
{
    gpio_t  gpioInfo;

	gpioInfo = GpioInfoGet(HostPinID, frontendId);

    // Check if the GPIO is connected
    if (gpioInfo.pReg >= 0)
    {
        *pinState = ((SIUL2_GPDI_tag *)gpioInfo.pReg)->B.PDI_N;
    }
    else
    {
        *pinState = 0;
    }
}
#endif
/*===================================================================================================================*/

void RfeHwExtErrorIntEnable(uint32_t frontendId)
{

	SIUL2_0.DISR0.R |= gsGpioIrqMasks[frontendId];    // Clear any pending interrupts
	SIUL2_0.DIRER0.R |= gsGpioIrqMasks[frontendId];   // Enable the TEF82XX error pin interrupt
	SIUL2_0.IFEER0.R |= gsGpioIrqMasks[frontendId];   // Enable the interrupt for falling direction
}

/*===================================================================================================================*/

void RfeHwExtErrorIntDisable(uint32_t frontendId)
{
	SIUL2_0.DIRER0.R &= ~(gsGpioIrqMasks[frontendId]);   // Disable the TEF82XX error pin interrupt
	SIUL2_0.IFEER0.R &= ~(gsGpioIrqMasks[frontendId]);   // Disable the interrupt for falling direction
}
/*===================================================================================================================*/

/**
* @brief         Handler for external error signal interrupt.
*
* @return        uint32_t - status code indicating success (0) or failure (!=0)
*/
static void RfeHwGpioIrqHandler(void)
{
    uint32_t mask = 0u;
    uint32_t reg = SIUL2_0.DISR0.R;
    SIUL2_0.DISR0.R = reg;
    if((reg & gsGpioIrqMasks[0]) != 0u)
    {
        mask = 1u;
    }
    if((reg & gsGpioIrqMasks[1]) != 0u)
    {
        mask |= 2u;
    }
    if(mask != 0u)
    {
        if(gspFeErrorCallback != NULL)
        {
            gspFeErrorCallback(mask);
        }
    }
}

/*===================================================================================================================*/

/**
* @brief         External error signal interrupt handler activation.
*
* @param[in]     errorCallback - the application routine to be called if the handler is called
*
* @return        uint32_t - status code indicating success (0) or failure (!=0)
*/
uint32_t RfeHwExtErrorConnect(RfeErrorPinCallback errorCallback)
{
    uint32_t returnVal = 0u;

    if(errorCallback != NULL)
    {
        gspFeErrorCallback = errorCallback;
        returnVal = interrupts_cm7_install( SIUL2_INT_IRQn, 2U, (pFunc) &RfeHwGpioIrqHandler, 1); // coreid = 1 means M7_1
    }
    else
    {
    	returnVal = 1u;
    }
    return returnVal;
}


#ifdef __cplusplus
}
#endif

/*******************************************************************************
 * EOF
 ******************************************************************************/

/** @} */
