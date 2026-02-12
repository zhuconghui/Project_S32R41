/*************************************************************************************************
 *
 * NXP Confidential Proprietary
 *
 * Copyright 2023 NXP
 * All Rights Reserved
 *
 ******************************************************************************
 *
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 *
 *************************************************************************************************/

/**
*
*
* @brief Platform wrapper for GPIO access functions.
*
*
******************************************************************************/

#include "rsdk_S32R41.h"

#include "rsdk_glue_gpio_api.h"
#include "rsdk_glue_timer_api.h"
#include "rsdk_glue_irq_register_api.h"

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#if !defined(BOARD_X_S32R41_EVB_REV_A) || !defined(BOARD_X_S32R41_EVB_REV_B)
// default board type
#define BOARD_X_S32R41_EVB_REV_B 
#endif
/*==================================================================================================
 *                                       LOCAL MACROS
==================================================================================================*/

/**
* @brief        The real pad implementation.
* @details      This GPIO to pin bindings are platform/board specific and need to be set based on
*               hardware configuration.
*/
#define TEF82XX_MCUINT_CHIRPSTART_OUT_EIRQ  23u     // External interrupt number
#define FE0_ERROR_N_EIRQ                    15u     // External interrupt bit position for FE_0
#define FE1_ERROR_N_EIRQ                    24u     // External interrupt bit position for FE_1

#define NUM_CONNECTED_FRONT_ENDS            2u      // The number of connected front-end to the R41 board

#define ARRAY_SIZE(_x) (sizeof(_x)/sizeof(_x[0]))

/*==================================================================================================
 *                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

typedef enum
{
    IN,
    OUT,
} gpioDirection_t;


typedef SIUL2_GPDO0_tag SIUL2_GPDO_tag;
typedef SIUL2_GPDI0_tag SIUL2_GPDI_tag;

typedef struct
{
    /* MSCR register number */
    int16_t mscrNum;

    /* pointer to the GPDO/GPDI register */
    volatile void * pReg;
    /* pin direction: IN/OUT: if -1 -> pin is not to be configured, read or set */
    gpioDirection_t dir;
} gpio_t;

typedef struct
{
    gpio_t errorReset;
    gpio_t readyInt;
    gpio_t tx1Ps;
    gpio_t tx2Ps;
    gpio_t tx3Ps;
    gpio_t chirpStart;
    gpio_t errorN;
    gpio_t hReset;
} tef810xGpioMscr_t;

typedef struct
{
    gpio_t chirpStartIn;
    gpio_t mcuIntChirpStartOut;
    gpio_t errorN;
    gpio_t errorReset;
    gpio_t tx1IPs;
    gpio_t tx2IPs;
    gpio_t tx3IPs;
    gpio_t tx1QPs;
    gpio_t tx2QPs;
    gpio_t tx3QPs;
    gpio_t hReset;
} tef82xxGpioMscr_t;

/*==================================================================================================
 *                                      LOCAL VARIABLES
==================================================================================================*/
/*
 * Enumeration for the digital signals used by front-ends
 */
const uint32_t tef82xxGpioIds[] = {
    TEF82XX_CHIRPSTART_IN, 
    TEF82XX_MCUINT_CHIRPSTART_OUT, 
    TEF82XX_ERRORN,
    TEF82XX_ERRORRESET, 
    TEF82XX_TX1_I_PS, 
    TEF82XX_TX2_I_PS, 
    TEF82XX_TX3_I_PS,
    TEF82XX_TX1_Q_PS, 
    TEF82XX_TX2_Q_PS, 
    TEF82XX_TX3_Q_PS, 
    TEF82XX_HRESET
};

#define GPDO(x) &(SIUL2_0.GPDO##x)
#define GPDI(x) &(SIUL2_0.GPDI##x)

/*
 * Definitions for the connected front-ends GPIO
 */
static const tef82xxGpioMscr_t gsTef82xxGpios[NUM_CONNECTED_FRONT_ENDS] = {
#if defined(BOARD_X_S32R41_EVB_REV_A)

    { // FE0 - master
        .chirpStartIn =         {18,   GPDO(18), OUT},   // 
        .mcuIntChirpStartOut =  {28,   GPDI(28), IN},    // 
        .errorN =               {47,   GPDI(47), IN},    // 
        .errorReset =           {27,   GPDO(27), OUT},   // 
        .tx1IPs =               {21,   GPDO(21), OUT},   // 
        .tx2IPs =               {23,   GPDO(23), OUT},   // 
        .tx3IPs =               {25,   GPDO(25), OUT},   // 
        .tx1QPs =               {22,   GPDO(22), OUT},   // 
        .tx2QPs =               {24,   GPDO(24), OUT},   // 
        .tx3QPs =               {26,   GPDO(26), OUT},   // 
        .hReset =               {82,   GPDO(82), OUT},   // 
    },
    { // FE1 - slave
        .chirpStartIn =         {-1,    0,       OUT},    // 
        .mcuIntChirpStartOut =  {-1,    0,       IN},    // 
        .errorN =               {56,   GPDI(56), IN},    // 
        .errorReset =           {-255,   GPDO(82), OUT}, //
        .tx1IPs =               {86,   GPDO(86), OUT},   // 
        .tx2IPs =               {84,   GPDO(84), OUT},   // 
        .tx3IPs =               {38,   GPDO(38), OUT},   // 
        .tx1QPs =               {85,   GPDO(85), OUT},   // 
        .tx2QPs =               {83,   GPDO(83), OUT},   // 
        .tx3QPs =               {37,   GPDO(37), OUT},   // 
        .hReset =               {-255,   0,        OUT}, //
    }
#elif defined(BOARD_X_S32R41_EVB_REV_B)
    { // FE0 - master
        .chirpStartIn =         {18,   GPDO(18), OUT},   // 
        .mcuIntChirpStartOut =  {52,   GPDI(52), IN},    // 
        .errorN =               {47,   GPDI(47), IN},    // 
        .errorReset =           {27,   GPDO(27), OUT},   //
        .tx1IPs =               {21,   GPDO(21), OUT},   // 
        .tx2IPs =               {23,   GPDO(23), OUT},   // 
        .tx3IPs =               {25,   GPDO(25), OUT},   // 
        .tx1QPs =               {22,   GPDO(22), OUT},   // 
        .tx2QPs =               {24,   GPDO(24), OUT},   // 
        .tx3QPs =               {26,   GPDO(26), OUT},   // 
        .hReset =               {82,   GPDO(82), OUT},   //
    },
    { // FE1 - slave
        .chirpStartIn =         {-1,   0,        OUT},   // 
        .mcuIntChirpStartOut =  {53,   GPDI(53),  IN},    // 
        .errorN =               {56,   GPDI(56),  IN},    // 
        .errorReset =           {-255,   GPDO(27), OUT},   //
        .tx1IPs =               {86,   GPDO(86), OUT},   // 
        .tx2IPs =               {84,   GPDO(84), OUT},   // 
        .tx3IPs =               {38,   GPDO(38), OUT},   // 
        .tx1QPs =               {85,   GPDO(85), OUT},   // 
        .tx2QPs =               {83,   GPDO(83), OUT},   // 
        .tx3QPs =               {37,   GPDO(37), OUT},   // 
        .hReset =               {-255,   GPDO(82), OUT}, //
    }
#else
#error board not supported
#endif
};

static const uint32_t gsGpioIrqMasks[NUM_CONNECTED_FRONT_ENDS] = {
        1u << FE0_ERROR_N_EIRQ, 1u << FE1_ERROR_N_EIRQ
};

static RfeErrorPinCallback gspFeErrorCallback = NULL;

/*==================================================================================================
 *                                       LOCAL FUNCTIONS
==================================================================================================*/
static gpio_t GpioInfoGet(uint32_t pinId, uint32_t glueId)
{
    gpio_t gpioInfo;

    if(glueId < NUM_CONNECTED_FRONT_ENDS)
    {
        switch (pinId)
        {
        case TEF82XX_CHIRPSTART_IN:
            gpioInfo = gsTef82xxGpios[glueId].chirpStartIn;
            break;
        case TEF82XX_MCUINT_CHIRPSTART_OUT:
            gpioInfo = gsTef82xxGpios[glueId].mcuIntChirpStartOut;
            break;
        case TEF82XX_ERRORN:
            gpioInfo = gsTef82xxGpios[glueId].errorN;
            break;
        case TEF82XX_ERRORRESET:
            gpioInfo = gsTef82xxGpios[glueId].errorReset;
            break;
        case TEF82XX_TX1_I_PS:
            gpioInfo = gsTef82xxGpios[glueId].tx1IPs;
            break;
        case TEF82XX_TX2_I_PS:
            gpioInfo = gsTef82xxGpios[glueId].tx2IPs;
            break;
        case TEF82XX_TX3_I_PS:
            gpioInfo = gsTef82xxGpios[glueId].tx3IPs;
            break;
        case TEF82XX_TX1_Q_PS:
            gpioInfo = gsTef82xxGpios[glueId].tx1QPs;
            break;
        case TEF82XX_TX2_Q_PS:
            gpioInfo = gsTef82xxGpios[glueId].tx2QPs;
            break;
        case TEF82XX_TX3_Q_PS:
            gpioInfo = gsTef82xxGpios[glueId].tx3QPs;
            break;
        case TEF82XX_HRESET:
            gpioInfo = gsTef82xxGpios[glueId].hReset;
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
 *                                       GLOBAL FUNCTIONS
==================================================================================================*/

uint32_t RsdkGlueGPIOInit(void)
{
    gpio_t  gpioInfo;
    uint32_t id, feIdx, gpioIdx, feNum, gpioNum;
    SIUL2_MSCR_tag mscrVal;
    // All values are from the perspective of the MCU
    const uint32_t tef82xxGpioIds[] = {
		TEF82XX_CHIRPSTART_IN,
		TEF82XX_MCUINT_CHIRPSTART_OUT,
		TEF82XX_ERRORN,
		TEF82XX_ERRORRESET,
		TEF82XX_TX1_I_PS,
		TEF82XX_TX2_I_PS,
		TEF82XX_TX3_I_PS,
		TEF82XX_TX1_Q_PS,
		TEF82XX_TX2_Q_PS,
		TEF82XX_TX3_Q_PS,
		TEF82XX_HRESET
    };

    mscrVal.B.OBE = 0;   // output buffer disabled
    mscrVal.B.ODE = 0;   // open drain disabled
    mscrVal.B.IBE = 1;   // input buffer enable
    mscrVal.B.SRE = 0x6; // 110b: Fmax=10 MHz
    mscrVal.B.PUE = 0;   // no pullup
    mscrVal.B.PUS = 0;   // pull down
    mscrVal.B.RCVR = 1;  // single endded receiver
    mscrVal.B.SMC = 0;   // disable output when in safe mode
    mscrVal.B.SSS = 0;   // GPIO

    feNum = ARRAY_SIZE(gsTef82xxGpios);
    gpioNum = ARRAY_SIZE(tef82xxGpioIds);

    for (feIdx = 0; feIdx < feNum; feIdx++)
    {
        for (gpioIdx = 0; gpioIdx < gpioNum; gpioIdx++)
        {
            id = tef82xxGpioIds[gpioIdx];
            gpioInfo = GpioInfoGet(id, feIdx);
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
    }

    return 0;
}

/*===================================================================================================================*/

extern uint32_t RsdkGlueGPIODelete(void)
{
    return RSDK_SUCCESS;
}

/*===================================================================================================================*/

rsdkStatus_t RsdkGlueGPIOSet(uint32_t glueLayerId, uint8_t val)
{
	uint32_t pinId, glueId;
    gpio_t  gpioInfo;
    rsdkStatus_t res = RSDK_SUCCESS;

	val = (val > 0) ? 1 : 0;

    glueId = RSDK_GLUE_ID_GET(glueLayerId);
    pinId = RSDK_PIN_ID_SET_GET(glueLayerId);

	if(glueId < NUM_CONNECTED_FRONT_ENDS)
	{
    	gpioInfo = GpioInfoGet(pinId, glueId);

        /* Check if the GPIO is configured. */
        if (gpioInfo.mscrNum == (-1))
        {
        	/* GPIO used is not configured. Raise appropriate error. */
        	res = RSDK_RFE_GLUE_GPIO_ERROR;
        }
        else if(gpioInfo.mscrNum == (-255))
        {
        	/* Do nothing. */
        }
		else
		{
			if (gpioInfo.pReg != NULL)
			{
				((SIUL2_GPDO_tag *)gpioInfo.pReg)->B.PDO_N = val;
			}
			else
			{
				res = RSDK_RFE_GLUE_GPIO_ERROR;
			}
		}
    }
    else
    {
		res = RSDK_RFE_EXCEDDED_MAX_SUPPORTED_DEVICES;
    }

    return res;
}

/*===================================================================================================================*/

rsdkStatus_t RsdkGlueGPIOGet(uint32_t glueLayerId, uint8_t *val)
{
	uint32_t glueId, pinId;
    gpio_t  gpioInfo;
    rsdkStatus_t res = RSDK_SUCCESS;

    glueId = RSDK_GLUE_ID_GET(glueLayerId);
    pinId = RSDK_PIN_ID_SET_GET(glueLayerId);

	if(glueId < NUM_CONNECTED_FRONT_ENDS)
	{
    	gpioInfo = GpioInfoGet(pinId, glueId);

    	/* Check if the GPIO is configured. */
    	if (gpioInfo.mscrNum == (-1))
    	{
        	/* GPIO used is not configured. Raise appropriate error. */
        	res = RSDK_RFE_GLUE_GPIO_ERROR;
    	}
    	else if(gpioInfo.mscrNum == (-255))
    	{
    		/* Do nothing. */
    	}
    	else
    	{
    	    if (gpioInfo.pReg != NULL)
    	    {
    	        *val = ((SIUL2_GPDI_tag *)gpioInfo.pReg)->B.PDI_N;
    	    }
    	    else
    	    {
    	        *val = 0;
    	        res = RSDK_RFE_GLUE_GPIO_ERROR;
    	    }
    	}
    }
    else
    {
		res = RSDK_RFE_EXCEDDED_MAX_SUPPORTED_DEVICES;
    }


    return res;
}

/*===================================================================================================================*/

uint32_t RsdkGlueExtErrorIntEnable(uint32_t glueLayerId)
{
    uint32_t glueId;
    uint32_t res = 0;
    glueId = RSDK_GLUE_ID_GET(glueLayerId);

    if (glueId < NUM_CONNECTED_FRONT_ENDS)
    {
        SIUL2_0.DISR0.R |= gsGpioIrqMasks[glueId];    // Clear any pending interrupts
        SIUL2_0.DIRER0.R |= gsGpioIrqMasks[glueId];   // Enable the TEF82XX error pin interrupt
        SIUL2_0.IFEER0.R |= gsGpioIrqMasks[glueId];   // Enable the interrupt for falling direction
    }
    else
    {
        res = 1;
    }

    return res;
}

/*===================================================================================================================*/

uint32_t RsdkGlueExtErrorIntDisable(uint32_t glueLayerId)
{
    uint32_t glueId;
    uint32_t res = 0;
    glueId = RSDK_GLUE_ID_GET(glueLayerId);

    if (glueId < NUM_CONNECTED_FRONT_ENDS)
    {
        SIUL2_0.DIRER0.R &= ~(gsGpioIrqMasks[glueId]);   // Disable the TEF82XX error pin interrupt
        SIUL2_0.IFEER0.R &= ~(gsGpioIrqMasks[glueId]);   // Disable the interrupt for falling direction
    }
    else
    {
        res = 1;
    }

    return res;
}
/*===================================================================================================================*/

uint32_t idx = 0;
uint32_t vals[0x100];
/**
* @brief         Handler for external error signal interrupt.
*
* @return        uint32_t - status code indicating success (0) or failure (!=0)
*/
static void RsdkGlueGpioIrqHandler(void)
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
* @param[in]     errorCallback - the application routin to be called if the handler is called
*
* @return        uint32_t - status code indicating success (0) or failure (!=0)
*/
uint32_t RsdkGlueExtErrorConnect(RfeErrorPinCallback errorCallback)
{
    uint32_t rez = 0u;

    if(errorCallback != NULL)
    {
        gspFeErrorCallback = errorCallback;
        RsdkGlueIrqHandlerRegister(&RsdkGlueGpioIrqHandler, 269, RSDK_CURRENT_CORE, 2);
    }
    else
    {
        rez = 1u;
    }

    return rez;
}

/*===================================================================================================================*/

#ifdef __cplusplus
}
#endif
