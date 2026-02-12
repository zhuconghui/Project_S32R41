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

#ifndef RFESWPORTDRV_INC_PLF_TYPES_H_
#define RFESWPORTDRV_INC_PLF_TYPES_H_

/******************************************************************************
 *                              INCLUDES
 *****************************************************************************/
#include <stdint.h>
#include "bc_types.h"

/******************************************************************************
 *                              DEFINES
 *****************************************************************************/
#define SHM_KEY         0x1234
#define SHM_KEY_TRIGGER 0x4321
#define SPI_REGSTART    0x80010000UL
#define SPI_REGEND      0x8001FFFFUL

#define PLF_ERROR       0x01u
#define PLF_WARN        0x02u
#define PLF_INFO        0x03u
#define PLF_DEBUG       0x04u

/******************************************************************************
 *                              TYPES
 *****************************************************************************/
typedef enum {
    PRINT_NONE = 0x00u,
    PRINT_FILE = 0x01u,
    PRINT_UART = 0x02u,
    PRINT_LAN = 0x03u,
    PRINT_INVALID
} PLF_LOGprintMode;

struct TRIGGER_DATA {
    uint16_t nChirps;
    uint32_t nSamples;
    uint8_t decimation;
    uint8_t En_LongCap;
    uint8_t En_Header;
    uint8_t En_Footer;
};

typedef struct {
    uint32_t clock_polarity : 1;
    uint32_t Header_active : 1;
    uint32_t Footer_active : 1;
    uint32_t frame_clk_mode : 1;
    uint32_t data_packet_format :1;
    uint32_t bcd1_delay_mode : 3;
    uint32_t bcd2_delay_mode : 3;
    uint32_t bcd3_delay_mode : 3;
    uint32_t bcd4_delay_mode : 3;
    uint32_t En_240mbps : 1;
    uint32_t Reserved : 14;
} Nxp_Zynq_Lvds_Config;

typedef struct {
    uint32_t spi_freq_div : 8;
    uint32_t slave_selector : 3;
    uint32_t Bitmode : 1;
    uint32_t spi_clock_always_on : 1;
    uint32_t clk_mode : 1;
    uint32_t Reserved : 18;
} Nxp_Zynq_Spi_Config;

typedef union {
    Nxp_Zynq_Lvds_Config bits_st;
    uint32_t val_u32;
} Nxp_Zynq_Lvds_Config_Union;

typedef union {
    Nxp_Zynq_Spi_Config bits_st;
    uint32_t val_u32;
} Nxp_Zynq_Spi_Config_Union;

typedef enum {
    e_PLF_onchip_Temp = 0x00u,
    e_PLF_3v3_Domain = 0x01u,
    e_PLF_1v8_Domain_1 = 0x02u,
    e_PLF_1v8_Domain_2 = 0x03u,
    e_PLF_1v8_Domain_3 = 0x04u,
    e_PLF_1v1_Domain_1 = 0x05u,
    e_PLF_1v1_Domain_2 = 0x06u,
    e_PLF_ATB1 = 0x07u,
    e_PLF_ATB2 = 0x08u,
    e_PLF_XADCTARGET_INVALID
} PLF_XADCTarget;

typedef enum {
    IRQ_TRIGGER_RISING_EDGE = 0x00u,
    IRQ_TRIGGER_FALING_EDGE = 0x01u,
    IRQ_TRIGGER_INVALID
} PLF_IrqTriggerEnum_e;

typedef enum{
    ONE_UUT = 0x00u,
    TWO_UUT  = 0x01u,
    THREE_UUT = 0x02u,
    FOUR_UUT  = 0x03u,
    UUT_INVALID
}PLF_NumDeviceEnum_e;

/******************************************************************************
 *                              FUNCTIONS
 *****************************************************************************/


#endif /* RFESWPORTDRV_INC_PLF_TYPES_H_ */
