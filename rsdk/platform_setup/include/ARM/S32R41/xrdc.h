/******************************************************************************************************************************************
 *
 * Copyright 2021 NXP
 *
 **********************************************************************************************************************
 *
 * NXP Confidential Proprietary. This software is owned or controlled by NXP and may only be used strictly in
 * accordance with the applicable terms. By expressly accepting such terms or by downloading, installing, activating
 * and/or otherwise using the software, you are agreeing that you have read, and that you agree to comply with and are
 * bound by, such license terms. If you do not agree to be bound by the applicable license terms, then you may not
 * retain, install, activate or otherwise use the software.
 *
 * THIS SOFTWARE IS PROVIDED BY NXP "AS IS" AND ANY EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
 * NXP OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
 * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 *
**********************************************************************************************************************/
/**********************************************************************************************************************
 @file      xrdc.h
 @author    NXP
**********************************************************************************************************************/
#ifndef XRDC_H_
#define XRDC_H_

/**********************************************************************************************************************
 Constants and Macros
**********************************************************************************************************************/

/**********************************************************************************************************************
 Constants and Macros
**********************************************************************************************************************/
/* XRDC Domain IDs */
#define XRDC_DID_CM7_0    1
#define XRDC_DID_CM7_1    2

#define XRDC_DID_A53      4

#define XRDC_DID_SPT    6
#define XRDC_DID_BBE    7

/**********************************************************************************************************************
 User-defined Types
**********************************************************************************************************************/
typedef enum
{
    /* CPU cores & GIC */
    XRDC_CM7_0,         // XRDC_0 MDAC: 1 (AXI), 5 (AHB)
    XRDC_CM7_1,         // XRDC_0 MDAC: 2 (AXI), 6 (AHB)
    XRDC_A53,           // XRDC_1 MDAC: 0
    XRDC_EDMA_0,        // XRDC_0 MDAC: 1
    XRDC_HSE,           // XRDC_0 MDAC: 3
    XRDC_GMAC_0,        // XRDC_0 MDAC: 4
    XRDC_DEBUG_ETR,     // XRDC_1 MDAC: 5
    XRDC_MIPI_CSI2_0,   // XRDC_1 MDAC: 1
    XRDC_MIPI_CSI2_1,   // XRDC_1 MDAC: 6
    XRDC_BBE32,         // XRDC_1 MDAC: 2
    XRDC_SPT,           // XRDC_1 MDAC: 3
    XRDC_GMAC_1,        // XRDC_1 MDAC: 2
} xrdcBusMaster_t;


/**********************************************************************************************************************
 Global Function Prototypes
**********************************************************************************************************************/
void xrdc_ConfigureEnable(void);

#endif /* XRDC_H_ */
