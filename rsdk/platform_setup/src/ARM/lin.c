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
/**************************************************************************************************
 @file		lin.c
 @author	NXP

 @brief 	LINFlexD UART mode configuration and test.
**************************************************************************************************/
/**************************************************************************************************
 Include Files
**************************************************************************************************/
#include "lin.h"

#include "rsdk_S32R41.h"


#include <stdio.h>
#include <string.h>
#include <stdarg.h>
/***********************************************************************************************************************
 Constants and Macros
***********************************************************************************************************************/
#define MAX_NUM_CHAR    255
/**************************************************************************************************
 Local Function Prototypes
**************************************************************************************************/
int al_printf(const char *fmt, va_list  args);
void write_string(char *string);

/**************************************************************************************************
 Global Functions
**************************************************************************************************/
/** -----------------------------------------------------------------------------------------------
 @brief     LIN_0 in UART Mode with Baud rate of 115200
 @param[in] None
 @return    Status indicator
-------------------------------------------------------------------------------------------------*/
char lin_init(linClock_t clock)
{
	/* Transition from sleep to init mode */
	LINFLEXD_0.LINCR1.B.SLEEP = 0;
	LINFLEXD_0.LINCR1.B.INIT = 1;

	/* UART, Rx enable, Tx enable, Tx buffer-mode, Rx buffer-mode,
	 * 1 byte buffer, no parity, 8 bit data */
	LINFLEXD_0.UARTCR.B.UART = 1;
	LINFLEXD_0.UARTCR.B.TXEN = 1;
	LINFLEXD_0.UARTCR.B.RXEN = 1;
	LINFLEXD_0.UARTCR.B.WL0 = 1;

	if (clock == LIN_CLK_133)
	{
        /* LINFLEX_0 to use LIN_BAUD_CLK at 133.33 MHz
         * 133.33 MHz / 115200 = 1157.41
         * 1157.41 / 16 = 72.34
         * Hence LINIBRR = 72 and LINFBRR = 5 (5/16 = 0.3125) */
        LINFLEXD_0.LINIBRR.R = 72;
        LINFLEXD_0.LINFBRR.R = 5;
	}
	else if (clock == LIN_CLK_100)
	{
        /* LINFLEX_0 to use LIN_BAUD_CLK at 100 MHz
         * 100 MHz / 115200 = 868.06
         * 868.06 / 16 = 54.25
         * Hence LINIBRR = 54 and LINFBRR = 4 (4/16 = 0.25) */
        LINFLEXD_0.LINIBRR.R = 54;
        LINFLEXD_0.LINFBRR.R = 4;
	}

	/* LINFLEX removed from init mode and disable Rx/Tx interrupts */
	LINFLEXD_0.LINCR1.B.INIT = 0;
	LINFLEXD_0.LINIER.B.DRIE = 0;
	LINFLEXD_0.LINIER.B.DTIE = 0;

	return 0;
}

/** -----------------------------------------------------------------------------------------------
 @brief      Transmit single character in UART mode
 @return     Status indicator
-------------------------------------------------------------------------------------------------*/
void lin_write_char(char value)
{
	LINFLEXD_0.BDRL.B.DATA0 = value;

	while (LINFLEXD_0.UARTSR.B.DTFTFF == 0);
	//LINFLEXD_0.UARTSR.R = 0x00000002; 				// Clear DTF bit only
	LINFLEXD_0.UARTSR.B.DTFTFF = 1;

	if (value == '\n')
	    lin_write_char('\r');

	return;
}

/** -----------------------------------------------------------------------------------------------
 @brief      Read and return single character in UART mode
 @return     The character provided by user
-------------------------------------------------------------------------------------------------*/
char lin_get_char(void)
{
	char new_char;

	while (!LINFLEXD_0.UARTSR.B.DRFRFE);

	new_char = LINFLEXD_0.BDRM.B.DATA4;
	//LINFLEXD_0.UARTSR.R = 0x00000004; 				// Clear DRF bit only
    LINFLEXD_0.UARTSR.B.DRFRFE = 1;

	return new_char;
}

/** ------------------------------------------------------------------------------------------------
 @brief     Variadic function used as printf alias. Similar functionality to printf.

 @param[in]  fmt - string with format specifiers and associated arguments.

 @return     Status indicator.
--------------------------------------------------------------------------------------------------*/
int uart_printf(const char *fmt, ...)
{
   int rv;
   va_list args;
   va_start(args, fmt);
   rv = al_printf(fmt, args);
   va_end(args);

   return rv;
}

/***********************************************************************************************************************
 Local Functions
***********************************************************************************************************************/
int al_printf(const char *fmt, va_list args)
{
    char tx_buffer[MAX_NUM_CHAR];

    vsnprintf(&tx_buffer[0], MAX_NUM_CHAR, fmt, args);
    write_string(&tx_buffer[0]);

    return  0;
}

void write_string(char *string)
{
    char *str_cpy = string;

    while (*str_cpy != 0)
    {
    	lin_write_char(*str_cpy++);
    }
}
