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

/*==================================================================================================
 *                                       INCLUDES
 ==================================================================================================*/
#include <stddef.h>
#include <stdbool.h>
#include <string.h>

#include "plf.h"
#include "rfe_sw_driver_state.h"

// Hw devices
#include "rfeHwLink.h"

/*==================================================================================================
 *                                        DEFINES
==================================================================================================*/
#define CPU_LITTLE_ENDIAN (0x01U)

#define TEF_HAL_NO_ERROR           0U
#define TEF_HAL_SPI_CRC_FAILED     1U
#define TEF_HAL_INPUT_OUT_OF_RANGE 2U
#define TEF_HAL_CALL_FAILED        3U
#define TEF_HAL_ERROR_PIN_ACTIVE   4U

#define TX_CRC_CNTRL_SIGN (0x7500)

// CRC8 defines
#define CRC_SEED 0xFFu
#define CRC_XOR 0xFFu

/*==================================================================================================
 *                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
enum
{
    SPI_CMD_FLG_CRC_NE = 0x00U,
    SPI_CMD_FLG_CRC_E = 0x01U
};

enum
{
    SPI_CMD_FLG_CURRENT = 0x00U,
    SPI_CMD_FLG_STORED = 0x01U
};

enum
{
    SPI_CMD_FLG_SEQ = 0x00U,
    SPI_CMD_FLG_REPT = 0x01U
};

enum
{
    SPI_CMD_FLG_READ = 0x00U,
    SPI_CMD_FLG_WRITE = 0x01U
};

/*==================================================================================================
 *                                      LOCAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
 *                                       LOCAL MACROS
==================================================================================================*/

/*==================================================================================================
 *                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
 *                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
 *                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
 *                                LOCAL FUNCTIONS PROTOTYPES
==================================================================================================*/

/*==================================================================================================
 *                                     INTERNAL FUNCTIONS
 ==================================================================================================*/
/*
    Calculates the SAE-J1850 Cyclic Redundancy Check byte (CRC)

    CRC result width        ::  8 bits
    Polynomial              ::  1Dh (x8+ x4+ x3+ x2+ x0)
    Initial value           ::  FFh
    Input data reflected    ::  No
    Result data reflected   ::  No
    XOR value               ::  FFh
    check                   ::  4Bh
    Magic check             ::  C4h

    Check value indicates that if the implementation is given the ASCII values "123456789" then it should return the value 0x4B.
    Magic Check - Compute the checksum over data plus checksum and XOR that with 0xFF. The result for should always be 0xC4.

    Note: The 0x11D constant used in the routine is derived from
    the mandated CRC division polynomial of: x^8+x^4+X^3+X^2+1, which
    corresponds to bit positions 8,4,3,2 and 0. Those bit
    positions form the binary number: 100011101 which is $11D.
    $1D could be used instead because we are only generating an 8-bit CRC.

*/
// CRC polynomial x^8 + x^4 + x^3 + x^2 + x^0 was used to generate the LUT

/*====================================================================================================================*/

static uint8_t TefHalCrc8Lut(uint8_t const *const values, uint16_t const valsNum)
{
    static uint8_t const sCrcLut[] = {
        0x00, 0x1D, 0x3A, 0x27, 0x74, 0x69, 0x4E, 0x53, 0xE8, 0xF5, 0xD2, 0xCF, 0x9C, 0x81, 0xA6, 0xBB, 0xCD, 0xD0,
        0xF7, 0xEA, 0xB9, 0xA4, 0x83, 0x9E, 0x25, 0x38, 0x1F, 0x02, 0x51, 0x4C, 0x6B, 0x76, 0x87, 0x9A, 0xBD, 0xA0,
        0xF3, 0xEE, 0xC9, 0xD4, 0x6F, 0x72, 0x55, 0x48, 0x1B, 0x06, 0x21, 0x3C, 0x4A, 0x57, 0x70, 0x6D, 0x3E, 0x23,
        0x04, 0x19, 0xA2, 0xBF, 0x98, 0x85, 0xD6, 0xCB, 0xEC, 0xF1, 0x13, 0x0E, 0x29, 0x34, 0x67, 0x7A, 0x5D, 0x40,
        0xFB, 0xE6, 0xC1, 0xDC, 0x8F, 0x92, 0xB5, 0xA8, 0xDE, 0xC3, 0xE4, 0xF9, 0xAA, 0xB7, 0x90, 0x8D, 0x36, 0x2B,
        0x0C, 0x11, 0x42, 0x5F, 0x78, 0x65, 0x94, 0x89, 0xAE, 0xB3, 0xE0, 0xFD, 0xDA, 0xC7, 0x7C, 0x61, 0x46, 0x5B,
        0x08, 0x15, 0x32, 0x2F, 0x59, 0x44, 0x63, 0x7E, 0x2D, 0x30, 0x17, 0x0A, 0xB1, 0xAC, 0x8B, 0x96, 0xC5, 0xD8,
        0xFF, 0xE2, 0x26, 0x3B, 0x1C, 0x01, 0x52, 0x4F, 0x68, 0x75, 0xCE, 0xD3, 0xF4, 0xE9, 0xBA, 0xA7, 0x80, 0x9D,
        0xEB, 0xF6, 0xD1, 0xCC, 0x9F, 0x82, 0xA5, 0xB8, 0x03, 0x1E, 0x39, 0x24, 0x77, 0x6A, 0x4D, 0x50, 0xA1, 0xBC,
        0x9B, 0x86, 0xD5, 0xC8, 0xEF, 0xF2, 0x49, 0x54, 0x73, 0x6E, 0x3D, 0x20, 0x07, 0x1A, 0x6C, 0x71, 0x56, 0x4B,
        0x18, 0x05, 0x22, 0x3F, 0x84, 0x99, 0xBE, 0xA3, 0xF0, 0xED, 0xCA, 0xD7, 0x35, 0x28, 0x0F, 0x12, 0x41, 0x5C,
        0x7B, 0x66, 0xDD, 0xC0, 0xE7, 0xFA, 0xA9, 0xB4, 0x93, 0x8E, 0xF8, 0xE5, 0xC2, 0xDF, 0x8C, 0x91, 0xB6, 0xAB,
        0x10, 0x0D, 0x2A, 0x37, 0x64, 0x79, 0x5E, 0x43, 0xB2, 0xAF, 0x88, 0x95, 0xC6, 0xDB, 0xFC, 0xE1, 0x5A, 0x47,
        0x60, 0x7D, 0x2E, 0x33, 0x14, 0x09, 0x7F, 0x62, 0x45, 0x58, 0x0B, 0x16, 0x31, 0x2C, 0x97, 0x8A, 0xAD, 0xB0,
        0xE3, 0xFE, 0xD9, 0xC4};
    uint8_t  remainderValue = CRC_SEED;
    uint16_t valIdx;
    for (valIdx = 0; valIdx < valsNum; valIdx++)
    {
        remainderValue ^= values[valIdx];
        remainderValue = sCrcLut[remainderValue];
    }
    return remainderValue ^ CRC_XOR;
}

/*====================================================================================================================*/

static uint32_t checkSpiRxCRC(uint8_t loopbackMode, uint8_t len)
{
    uint8_t                   rv = TEF_HAL_NO_ERROR;
    rfeDriverPersistentMem_t *pDrvState = RfeDrvStateGet();
    uint8_t                   cal_crcval;
    uint16_t                  crc_cal_buff_length = 3U;
    uint8_t                   read_offset;

    if (loopbackMode == 1u)
    {
        read_offset = 0u;  //CRC considers first byte, in loopback mode
    }
    else
    {
        read_offset = 1u;  //CRC ignores first byte, in NON-loopback mode
    }
    crc_cal_buff_length += ((uint16_t)len * (uint16_t)sizeof(uint32_t));
    cal_crcval = TefHalCrc8Lut(&pDrvState->rxBuff[read_offset], crc_cal_buff_length); /*ignore first byte of MISO*/

    if (cal_crcval != pDrvState->rxBuff[crc_cal_buff_length + read_offset])
    {
        rv = TEF_HAL_SPI_CRC_FAILED;
    }
    return rv;
}

static void TefHalPopulateMC13(uint8_t mod_addr, uint32_t cmd, uint16_t reg_addr, uint8_t *arr)
{
    if (arr != NULL)
    {
        arr[0u] = mod_addr;
        arr[1u] = (uint8_t)(((cmd & 0x0Fu) << 0x04u) | (((uint32_t)reg_addr & 0x0F00u) >> 0x08u));
        arr[2u] = (uint8_t)((uint32_t)reg_addr & 0xFFu);
    }
}

static PLF_ERRCODE HalToPlfStatus(uint32_t status)
{
    PLF_ERRCODE plfStatus;

    switch (status)
    {
        case TEF_HAL_NO_ERROR:
            plfStatus = PLF_NOERROR;
            break;
        case TEF_HAL_INPUT_OUT_OF_RANGE:
            plfStatus = PLF_INPUTOUTOFRANGE;
            break;
        case TEF_HAL_CALL_FAILED:
            plfStatus = PLF_GLUE_SPI_ERROR;
            break;
        case TEF_HAL_SPI_CRC_FAILED:
            plfStatus = PLF_SPIWRTRDCRCERROR;
            break;
        case TEF_HAL_ERROR_PIN_ACTIVE:
            plfStatus = PLF_ERRORN_PIN_ACTIVE;
            break;
        default:
            plfStatus = PLF_UNMAPPED_ERROR;
            break;
    }

    return plfStatus;
}

/*====================================================================================================================*/

static uint32_t TefHalSPICmdBuild(bool write, bool SR_Mode, bool CS_Mode, uint32_t *cmd)
{
    uint32_t rval = TEF_HAL_NO_ERROR;
    uint32_t f_cm2_CS, f_cm1_SR, f_cm3_CE, f_cm0_RW;

    if (cmd == NULL)
    {
        rval = TEF_HAL_INPUT_OUT_OF_RANGE;
    }


    if (rval == TEF_HAL_NO_ERROR)
    {
        *cmd = 0x00;
        f_cm2_CS = (CS_Mode == (bool)true) ? (uint32_t)SPI_CMD_FLG_STORED : (uint32_t)SPI_CMD_FLG_CURRENT;
        f_cm1_SR = (SR_Mode == (bool)true) ? (uint32_t)SPI_CMD_FLG_REPT : (uint32_t)SPI_CMD_FLG_SEQ;
        f_cm0_RW = (write == (bool)true) ? (uint32_t)SPI_CMD_FLG_WRITE : (uint32_t)SPI_CMD_FLG_READ;
        f_cm3_CE = (uint32_t)SPI_CMD_FLG_CRC_NE; /*RX CRC*/

        if (write == false) /*read access*/
        {
            f_cm3_CE = (uint32_t)SPI_CMD_FLG_CRC_E; /*RX CRC*/
        }

        *cmd = TX_CRC_CNTRL_SIGN;

        *cmd |= ((f_cm3_CE << 0x03U) | (f_cm2_CS << 0x02U) | (f_cm1_SR << 0x01U) | f_cm0_RW);
    }

    return rval;
}

static uint32_t TefHalSpiTransfer(uint8_t mod_addr, uint32_t cmd, uint16_t reg_addr, const uint32_t *tx_buff,
                           uint32_t *rx_buff, uint8_t len, uint32_t *ret_cmd)
{
    uint32_t                  status;
    uint32_t                  rv = TEF_HAL_NO_ERROR;
    rfeDriverPersistentMem_t *pDrvState = RfeDrvStateGet();

    uint16_t copy_loop = 0U;
    uint8_t  txEnCrc = 0, rxEnCrc = 0, loopbackMode = 0u;
    uint16_t tot_len;

    /*3 for header, 1 for crc*/
    if ((tx_buff != NULL) && ((3U + (sizeof(uint32_t) * (uint16_t)len) + 1U) > RFE_SPI_TX_BUFF_SIZE))
    {
        rv = TEF_HAL_INPUT_OUT_OF_RANGE;
    }
    if ((1U + ((sizeof(uint32_t) * (uint16_t)len) + 3U)) > RFE_SPI_RX_BUFF_SIZE)
    {
        rv = TEF_HAL_INPUT_OUT_OF_RANGE;
    }
    if ((tx_buff != NULL) && ((cmd & 0x01u) == 0u))
    {
        /*tx_buff says we want to send something, but cmd (see SPI_CMD_FLG_WRITE) says we want to receive*/
        rv = TEF_HAL_INPUT_OUT_OF_RANGE;
    }

    if (rv == TEF_HAL_NO_ERROR)
    {
        tot_len = 0x00;

        if ((cmd & 0xFF00u) == 0x7500u) /*see TX_CRC_CNTRL_SIGN */
        {
            txEnCrc = 1u;
        }

        if ((tx_buff == NULL) && ((cmd & 0x0008u) == 0x0008u)) /*when reading, is CRC on MISO enabled?*/
        {
            rxEnCrc = 1u;
        }

        if ((mod_addr & 0x80U) == 0x80U)
        {
            loopbackMode = 1u;
        }

        TefHalPopulateMC13(mod_addr, cmd, reg_addr, &pDrvState->txBuff[0x00]);
        tot_len += 3u; /*"control" header part on MOSI (MC1-3)*/

        if (tx_buff != NULL) /*SPI write*/
        {
            /*take care of MD part on MOSI*/
            for (copy_loop = 0; copy_loop < len; copy_loop++)
            {
                const uint8_t *p_txbuff = (const uint8_t *)&tx_buff[copy_loop];
#if defined(CPU_LITTLE_ENDIAN)
                pDrvState->txBuff[tot_len + 3U] = p_txbuff[0];
                pDrvState->txBuff[tot_len + 2U] = p_txbuff[1];
                pDrvState->txBuff[tot_len + 1U] = p_txbuff[2];
                pDrvState->txBuff[tot_len] = p_txbuff[3];
#else
                pDrvState->txBuff[tot_len] = p_txbuff[0];
                pDrvState->txBuff[tot_len + 1U] = p_txbuff[1];
                pDrvState->txBuff[tot_len + 2U] = p_txbuff[2];
                pDrvState->txBuff[tot_len + 3U] = p_txbuff[3];
#endif

                tot_len += 4u;
            }
        }
        else /*SPI read*/
        {
            /*take care of MC4-5 part on MOSI and subsequent bytes*/
            (void)memset((void *)&pDrvState->txBuff[tot_len], 0,
                         (uint32_t)len * sizeof(uint32_t));  //MDs and dummies, MC4-5 will be (re)written below

            pDrvState->txBuff[3 + 0] = 0;                   //MC4 Burst length (upper bits)
            pDrvState->txBuff[3 + 1] = (len - (uint8_t)1);  //MC5 Burst length (lower bits)
            tot_len += ((uint16_t)len * (uint16_t)sizeof(uint32_t));

            tot_len += 1u; /*+1 is for MCRC (ES3) / M7 (ES2)*/

            if (rxEnCrc == 1u)
            {
                tot_len += 1u; /*final dummy byte (ES3)*/
            }
        }

        if (tx_buff != NULL) /*SPI write*/
        {
            tot_len += 1u; /*CRC byte on ES3 / M7 on ES2*/
        }

        if (txEnCrc == 1u)
        {
            uint8_t cal_crcval = 0u;

            if (tx_buff != NULL)
            {
                /*SPI write*/
                cal_crcval = TefHalCrc8Lut(&pDrvState->txBuff[0], tot_len - 1u);
                pDrvState->txBuff[tot_len - 1u] = cal_crcval;
            }
            else
            {
                /*SPI read*/
                cal_crcval = TefHalCrc8Lut((void *)&pDrvState->txBuff[0], 7);
                pDrvState->txBuff[3 + 4] = cal_crcval;
            }
        }

        status = RfeHwSpiTransfer(pDrvState->frontendId, pDrvState->txBuff, pDrvState->rxBuff, tot_len);
        if (status != 0U)
        {
            rv = TEF_HAL_CALL_FAILED;
        }

        if (rv == TEF_HAL_NO_ERROR)
        {
            if (loopbackMode == 1u)
            {
                /*loopback mode, MISO identical to MOSI, "control" header part on MISO has 3 bytes (MC1-3)*/
                tot_len = 3U;
            }
            else
            {
                /*non LB mode, first byte is LB7:0, "control" header part on MISO has 4 bytes (LB+SC1-3)*/
                tot_len = 4U;
            }

            //return received control info
            if (ret_cmd != NULL)
            {
                uint8_t *p_ret_cmd = (uint8_t *)&ret_cmd[0];
#if defined(CPU_LITTLE_ENDIAN)
                p_ret_cmd[3] = pDrvState->rxBuff[0];
                p_ret_cmd[2] = pDrvState->rxBuff[1];
                p_ret_cmd[1] = pDrvState->rxBuff[2];
                p_ret_cmd[0] = pDrvState->rxBuff[3];
#else
                p_ret_cmd[0] = pDrvState->rxBuff[0];
                p_ret_cmd[1] = pDrvState->rxBuff[1];
                p_ret_cmd[2] = pDrvState->rxBuff[2];
                p_ret_cmd[3] = pDrvState->rxBuff[3];
#endif
                if (loopbackMode == 1u)
                {
#if defined(CPU_LITTLE_ENDIAN)
                    p_ret_cmd[0] = 0;
#else
                    p_ret_cmd[3] = 0;  //tot_len is 3 ("control" header part on MISO has 3 bytes) in loopback mode
#endif
                }
            }
            if (rx_buff != NULL)
            {
                if (rxEnCrc == 1u)
                {
                    rv = checkSpiRxCRC(loopbackMode, len);
                }

                for (copy_loop = 0; copy_loop < len; copy_loop++)
                {
                    uint8_t *p_rxbuff = (uint8_t *)&rx_buff[copy_loop];
#if defined(CPU_LITTLE_ENDIAN)
                    p_rxbuff[3] = pDrvState->rxBuff[tot_len];
                    p_rxbuff[2] = pDrvState->rxBuff[tot_len + 1U];
                    p_rxbuff[1] = pDrvState->rxBuff[tot_len + 2U];
                    p_rxbuff[0] = pDrvState->rxBuff[tot_len + 3U];
#else
                    p_rxbuff[0] = pDrvState->rxBuff[tot_len];
                    p_rxbuff[1] = pDrvState->rxBuff[tot_len + 1U];
                    p_rxbuff[2] = pDrvState->rxBuff[tot_len + 2U];
                    p_rxbuff[3] = pDrvState->rxBuff[tot_len + 3U];
#endif

                    tot_len += 4u;
                }
            }
        }
    }
    return (rv);
}

/*====================================================================================================================*/
//glue_reg_BurstRead
static uint32_t TefHalBurstRead(uint8_t ModuleAddress, uint16_t RegAddress, uint32_t *ReadData, uint8_t NumWords, bool SR_Mode,
                         uint32_t *ReturnedData)
{
    uint32_t cmd, rval;

    rval = TefHalSPICmdBuild(false, SR_Mode, false, &cmd);

    if (rval == TEF_HAL_NO_ERROR)
    {
        rval = TefHalSpiTransfer(ModuleAddress, cmd, RegAddress, NULL, ReadData, NumWords, ReturnedData);
    }

    return rval;
}

/*====================================================================================================================*/
// PLF_SPI_BurstWriteRead
static uint32_t TefHalBurstWriteRead(uint8_t ModuleAddress, uint16_t RegAddress, uint32_t *WriteData, uint32_t *ReadData,
                              uint8_t NumWords, bool CS_Mode, bool SR_Mode, bool LoopBack, uint32_t *ReturnedData)
{
    uint8_t  copyModuleAddress = ModuleAddress;
    uint32_t cmd, rval;

    rval = TefHalSPICmdBuild(true, SR_Mode, CS_Mode, &cmd);

    if (LoopBack == (bool)true)
    {
        copyModuleAddress = (0x80U | ModuleAddress);
    }

    if (rval == TEF_HAL_NO_ERROR)
    {
        rval = TefHalSpiTransfer(copyModuleAddress, cmd, RegAddress, WriteData, ReadData, NumWords, ReturnedData);
    }

    return rval;
}
/*==================================================================================================
 *                                      PUBLIC FUNCTIONS
 ==================================================================================================*/

PLF_ERRCODE PLF_HIO_SetIO(SYS_ExtPinID_e HostPinID, BOOL SetHigh)
{
    PLF_ERRCODE               plfStatus = PLF_NOERROR;
    rfeDriverPersistentMem_t *pDrvState = RfeDrvStateGet();
    uint8_t                   pinState;

    pinState = (SetHigh != FALSE) ? 1u : 0u;

    if (HostPinID < e_SYS_PINID_INVALID)
    {
        RfeHwGpioSet(pDrvState->frontendId, (TEF82XX_ExtPinID_e)HostPinID, pinState);
    }
    else
    {
        plfStatus = PLF_INVALID_GPIO_TARGET;
    }
    return plfStatus;
}

PLF_ERRCODE PLF_HIO_GetIO(SYS_ExtPinID_e HostPinID, BOOL *pHigh)
{
    PLF_ERRCODE               plfStatus = PLF_NOERROR;
    rfeDriverPersistentMem_t *pDrvState = RfeDrvStateGet();
    uint8_t                   pinState = 0u;

    if (HostPinID < e_SYS_PINID_INVALID)
    {
    	RfeHwGpioGet(pDrvState->frontendId, (TEF82XX_ExtPinID_e)HostPinID, &pinState);
    }
    else
    {
        plfStatus = PLF_INVALID_GPIO_TARGET;
    }

    if (plfStatus == PLF_NOERROR)
    {
        *pHigh = (pinState == 1U) ? TRUE : FALSE;
    }
    return plfStatus;
}

PLF_ERRCODE PLF_SPI_BurstWriteRead(SYS_IPNum_e ModAddr, uint16_t RegAddr, BOOL RepMode, BOOL ReadMode, BOOL Loopback,
                                   uint8_t NumWords, uint32_t *pWrData, uint32_t *pRdData, uint32_t *pRetData)
{
    PLF_ERRCODE plfStatus = PLF_NOERROR;
    uint32_t    halRet;

    halRet = TefHalBurstWriteRead((uint8_t)ModAddr, RegAddr, pWrData, pRdData, NumWords, (bool)ReadMode, (bool)RepMode, (bool)Loopback,
                                  pRetData);

    plfStatus = HalToPlfStatus(halRet);

    return plfStatus;
}

PLF_ERRCODE PLF_SPI_BurstRead(SYS_IPNum_e ModAddr, uint16_t RegAddr, BOOL RepMode, uint8_t NumWords, uint32_t *pRdData)
{
    PLF_ERRCODE plfStatus = PLF_NOERROR;
    uint32_t    halRet;

    halRet = TefHalBurstRead((uint8_t)ModAddr, RegAddr, pRdData, NumWords, (bool)RepMode, pRdData);

    plfStatus = HalToPlfStatus(halRet);

    return plfStatus;
}

PLF_ERRCODE PLF_TM_Sleep(uint32_t USec)
{
    PLF_ERRCODE plfStatus = PLF_NOERROR;
    RfeHwDelayUs(USec);
    return plfStatus;
}

PLF_ERRCODE PLF_SYS_SetTarget(PLF_SPITarget_e TargetDevice)
{
    (void)TargetDevice;
	// This function should set the right chip select pin for the target SPI device
	// This is not applicable for RSDK
	return PLF_NOERROR;
}
