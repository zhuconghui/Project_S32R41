/*
* Copyright 2022-2023 NXP
*
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and
* may only be used strictly in accordance with the applicable license terms.  By
* expressly accepting such terms or by downloading, installing, activating and/or
* otherwise using the software, you are agreeing that you have read, and that you
* agree to comply with and are bound by, such license terms.  If you do not agree to
* be bound by the applicable license terms, then you may not retain, install, activate or
* otherwise use the software.
*/


/******************************************************************************
 *   Project              : RF_Abstract_2.0
 *   Platform             : S32R41
 *****************************************************************************/

#ifndef RFE_HWCRC_H
#define RFE_HWCRC_H

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include "rfe_error.h"


/******************************************************************************
 *                              DEFINES AND TYPES
 *****************************************************************************/
/* Configuration defines for CRC hardware computation                           */
#define RFE_HW_CRC_CCIT_POLYNOMIAL			(0UL)	/* 16 bits polynomial : 0b10001000000100001 = 0x11021           */
#define RFE_HW_CRC_32_POLYNOMIAL			(1UL)	/* 32 bits polynomial : 0b100000100110000010001110110110111 =
                                                                0x104c11db7 (IEEE-802)                              */
#define RFE_HW_CRC_8_POLYNOMIAL				(2UL)	/* 8 bits polynomial  : 0b100011101 = 0x11d                     */
#define RFE_HW_CRC_INV						(1UL)	/* Inverts all bits read from the OUTP register                 */
#define RFE_HW_CRC_SWAP						(1UL)	/* Swaps all bits read from the OUTP register                   */
#define RFE_HW_CRC_SWAP_BITWISE				(0UL)	/* Swaps all bits in each byte read from the OUTP register      */
#define RFE_HW_CRC_SWAP_BYTE_WISE			(0UL)	/* Swaps all bytes read from the OUTP register                  */


/******************************************************************************
 *                              FUNCTIONS
 *****************************************************************************/

/*------------------------------------------------------------------------------*/
/**
 * \brief Returns a 32 bit CRC over the input buffer
 *
 * \param pbuf      The buffer with the 32bit input words
 * \param BufLen    The number of input bytes to process
 *
 * \return          The 32 bit CRC result
 */
uint32_t rfeCrc_calBuf(void *pBuf, uint32_t bufLen);

#endif /* RFE_HWCRC_H */
