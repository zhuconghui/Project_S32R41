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
    
#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                          INCLUDE FILES
==================================================================================================*/
#include "rfeHwConfig.h"
#include "Rfe20_PCCfg.h"

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

/*==================================================================================================
*                                  GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

const tef82xxConfig_t gsTef82xxConf[RFE_NUM_CONNECTED_FRONT_ENDS] = {
		{
			(volatile struct SPI_tag *)((volatile void *) &SPI_1),
			0,
			{
				.dspi_sck	= {43, 1, -1},
				.dspi_sout	= {44, 1, -1},
				.dspi_sin	= {45, 1, 541},
				.dspi_pcs	= {46, 1, -1}
			},
			{
				.chirpStartIn        =  {18, GPDO(18), OUT},
				.mcuIntChirpStartOut =	{52, GPDI(52), IN},
				.errorN              =  {47, GPDI(47), IN},
				.errorReset          =  {27, GPDO(27), OUT},
				.tx1IPs              =  {21, GPDO(21), OUT},
				.tx2IPs              =  {23, GPDO(23), OUT},
				.tx3IPs              =  {25, GPDO(25), OUT},
				.tx1QPs              =  {22, GPDO(22), OUT},
				.tx2QPs              =  {24, GPDO(24), OUT},
				.tx3QPs              =  {26, GPDO(26), OUT},
				.hReset              =  {82, GPDO(82), OUT}
			}
		},
		{
			(volatile struct SPI_tag *)((volatile void *) &SPI_2),
			0,
			{
				.dspi_sck	= {48, 2, -1},
				.dspi_sout	= {49, 2, -1},
				.dspi_sin	= {50, 1, 544},
				.dspi_pcs	= {51, 2, -1}
			},
			{
				.chirpStartIn        =  {-1, 0, OUT},
				.mcuIntChirpStartOut =  {53, GPDI(53), IN},
				.errorN              =  {56, GPDI(56), IN},
				.errorReset          =  {-1, 0, OUT},
				.tx1IPs              =  {86, GPDO(86), OUT},
				.tx2IPs              =  {84, GPDO(84), OUT},
				.tx3IPs              =  {38, GPDO(38), OUT},
				.tx1QPs              =  {85, GPDO(85), OUT},
				.tx2QPs              =  {83, GPDO(83), OUT},
				.tx3QPs              =  {37, GPDO(37), OUT},
				.hReset              =  {-1, 0, OUT}
			}
		}
};


#ifdef __cplusplus
}
#endif

