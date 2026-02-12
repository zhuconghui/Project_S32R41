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

/******************************************************************************
 *   Project              : S32R41_RFE_FW
 *   Platform             : S32R41
 *****************************************************************************/

#ifndef RFESWPORTDRV_INC_PLF_ERR_H_
#define RFESWPORTDRV_INC_PLF_ERR_H_

/******************************************************************************
 *                              INCLUDES
 *****************************************************************************/
#include <stdint.h>

/******************************************************************************
 *                              DEFINES
 *****************************************************************************/
typedef uint32_t PLF_ERRCODE;


//General no errors
#define PLF_NOERROR                 (0u)


//***** PLF Error Codes (0x54xxx) *****
//Input parameters out of range
#define PLF_INPUTOUTOFRANGE         (0x54001u)

//SPI communication errors
#define PLF_SPIWRTRDCRCERROR            (0x54002u)
#define PLF_SPIWRTCHECKFAIL             (0x54003u)
#define PLF_SPIREADFAIL                 (0x54004u)
#define PLF_SPI_SEQUENTIAL_WRITE_FAIL   (0x54005u)
#define PLF_SPI_WRITE_ACCESS_FAIL       (0x54006u)
#define PLF_INVALID_GPIO_TARGET         (0x54007u)
#define PLF_SPI_WRITE_TIMEOUT           (0x54008u)
#define PLF_SPI_READ_TIMEOUT            (0x54009u)
#define PLF_DATA_TRIG_FAIL              (0x5400Au)
#define PLF_FRAME_LEN_FAIL              (0x5400Bu)
#define PLF_LVDS_CRC_FAIL               (0x5400Cu)
#define PLF_CSI2_CAP_FAIL               (0x5400Du)


#define PLF_UNMAPPED_ERROR				(0x54100u)

//***** RSDK GLUE Error Codes (0x541xx) *****
#define PLF_GLUE_SLEEP_ERROR		(0x54101u)
#define PLF_ERRORN_PIN_ACTIVE		(0x54102u)
#define PLF_GLUE_SPI_ERROR              (0x54103u)
/******************************************************************************
 *                              TYPES
 *****************************************************************************/

/******************************************************************************
 *                              FUNCTIONS
 *****************************************************************************/



#endif /* RFESWPORTDRV_INC_PLF_ERR_H_ */
