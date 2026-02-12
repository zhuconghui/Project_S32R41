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
