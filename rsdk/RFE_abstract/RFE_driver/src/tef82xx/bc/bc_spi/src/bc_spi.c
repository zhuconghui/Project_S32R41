/*
 * Copyright 2019-2022 NXP
 * NXP Confidential. This software is owned or controlled by NXP and may only
 * be used strictly in accordance with the applicable license terms. By
 * expressly accepting such terms or by downloading, installing, activating
 * and/or otherwise using the software, you are agreeing that you have read,
 * and that you agree to comply with and are bound by, such license terms. If
 * you do not agree to be bound by the applicable license terms, then you may
 * not retain, install, activate or otherwise use the software.
 */

#include "bc_spi.h"

#include "plf.h"
#ifdef BC_CALCULATE_SPICOUNT
uint32_t gBCWriteCheckCount = 0u;
uint32_t gBCWriteCount = 0u;
uint32_t gBCReadCount = 0u;
#endif
BC_ERRCODE BC_SPI_Write(SYS_IPNum_e ModAddr, uint16_t RegAddr, uint32_t WrData) 
{
    BC_ERRCODE Err = BC_ERR_NOERROR;
    /* Register address has to 32bit aligned */ 
    if ((RegAddr & 0x3u) != 0u)
    {
        Err = BC_ERR_INPUTOUTOFRANGE;
    }
    else
    {
        Err = PLF_SPI_BurstWriteRead(ModAddr, RegAddr, FALSE, FALSE, FALSE, 1u, &WrData, NULL, NULL);
#ifdef BC_CALCULATE_SPICOUNT
       gBCWriteCount++;
#endif       
    }
    
    return Err;
}

BC_ERRCODE BC_SPI_WriteCheck(SYS_IPNum_e ModAddr, uint16_t RegAddr, uint32_t WrData)
{
    BC_ERRCODE Err = BC_ERR_NOERROR;
#ifndef BC_DISABLE_SPI_WRITECHECK
    uint32_t RdTestData = 0x0u;
#endif    
    /* Register address has to 32bit aligned */
    if ((RegAddr & 0x3u) != 0u)
    {
        Err = BC_ERR_INPUTOUTOFRANGE;
    }
    else
    {
        Err = PLF_SPI_BurstWriteRead(ModAddr, RegAddr, FALSE, FALSE, FALSE, 1u, &WrData, NULL, NULL);
#ifndef BC_DISABLE_SPI_WRITECHECK
        if (Err == BC_ERR_NOERROR)
        {
            Err = PLF_SPI_BurstRead(ModAddr, RegAddr, FALSE, 1u, &RdTestData);
            if (Err == BC_ERR_NOERROR)
            {
                if (RdTestData != WrData)
                {
                    Err = BC_ERR_SPI_WRTCHECKFAIL;
                }
                
            }
        }
#endif        
#ifdef BC_CALCULATE_SPICOUNT
       gBCWriteCheckCount++;
#endif
    }
    return Err;
}

BC_ERRCODE BC_SPI_Read(SYS_IPNum_e ModAddr, uint16_t RegAddr, uint32_t *pRdData)
{
    BC_ERRCODE Err = BC_ERR_NOERROR;
    /* Register address has to 32bit aligned */
    if ((RegAddr & 0x3u) != 0u)
    {
        Err = BC_ERR_INPUTOUTOFRANGE;
    }
    else
    {
        Err = PLF_SPI_BurstRead(ModAddr, RegAddr, FALSE, 1u, pRdData);
#ifdef BC_CALCULATE_SPICOUNT
        gBCReadCount++;
#endif
    }

    return Err;
}

BC_ERRCODE BC_SPI_BurstWrite(SYS_IPNum_e ModAddr, uint16_t RegAddr, BOOL RepMode, uint8_t NumWords, uint32_t *pWrData)
{
    BC_ERRCODE Err = BC_ERR_NOERROR;
    /* Register address has to 32bit aligned */
    if ((RegAddr & 0x3u) != 0u)
    {
        Err = BC_ERR_INPUTOUTOFRANGE;
    }
    else
    {
        Err = PLF_SPI_BurstWriteRead(ModAddr, RegAddr, RepMode, FALSE, FALSE, NumWords, pWrData, NULL, NULL);
    }
    
    return Err;
}

BC_ERRCODE BC_SPI_BurstRead(SYS_IPNum_e ModAddr, uint16_t RegAddr, BOOL RepMode, uint8_t NumWords, uint32_t *pRdData)
{
    BC_ERRCODE Err = BC_ERR_NOERROR;
    /* Register address has to 32bit aligned */
    if ((RegAddr & 0x3u) != 0u)
    {
        Err = BC_ERR_INPUTOUTOFRANGE;
    }
    else
    {
        Err = PLF_SPI_BurstRead(ModAddr, RegAddr, RepMode, NumWords, pRdData);
    }

    return Err;
}
/* End of file*/
