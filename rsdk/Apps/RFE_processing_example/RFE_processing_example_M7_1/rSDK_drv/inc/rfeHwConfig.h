/*==================================================================================================
 *
 * Copyright 2022-2023 NXP
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 *
==================================================================================================*/
    
#ifndef RFE_HW_CONFIG_H
#define RFE_HW_CONFIG_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
==================================================================================================*/
#include "rsdk_S32R41.h"
#include "Rfe20_PCCfg.h"
#include "rfeHwGpio.h"

/*==================================================================================================
*                                            CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                       DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                              ENUMS
==================================================================================================*/

/*==================================================================================================
*                                  STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
typedef struct
{
    volatile struct SPI_tag * spiDevice;
    uint8_t                   spiCs;
    tef82xxSpiPin_t           spiPins;
    tef82xxGpioMscr_t         fePins;
} tef82xxConfig_t;

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
extern const tef82xxConfig_t gsTef82xxConf[RFE_NUM_CONNECTED_FRONT_ENDS];

/*==================================================================================================
*                                       FUNCTION PROTOTYPES
==================================================================================================*/



#ifdef __cplusplus
}
#endif

/** @} */

#endif /* RFE_HW_CONFIG_H */
