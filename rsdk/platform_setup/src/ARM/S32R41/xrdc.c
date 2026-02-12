/**************************************************************************************************
 *
 * NXP Confidential Proprietary
 *
 * Copyright 2021-2022 NXP
 * All Rights Reserved
 *
 *****************************************************************************
 *
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
 *
 **************************************************************************************************//**********************************************************************************************************************
 @file      xrdc.c
 @author    NXP
 @brief     Extended Resource Domain Controller (XRDC) configuration for S32R41.
**********************************************************************************************************************/
/**********************************************************************************************************************
 Include Files
**********************************************************************************************************************/
#include "rsdk_S32R41.h"
#include "xrdc.h"

/**********************************************************************************************************************
 Constants and Macros
**********************************************************************************************************************/
#define XRDC_0_BASE_ADDR    0x40018000UL
#define XRDC_1_BASE_ADDR    0x4400C000UL

#define XRDC_0_MRC_NUM      5
#define XRDC_1_MRC_NUM      4

#define XRDC_0_PAC_NUM      3
#define XRDC_1_PAC_NUM      1

#define PDAC_SLOT_0_OFFSET  0x1000

/* General MDAC, MRC and PDAC */
#define VLD_FIELD       31
#define VLD_SET         (0x00000001 << VLD_FIELD)

#define ACP_DID_BITS    3
#define ACP_FULL        7

/* MDAC */
#define MDA_PA_FIELD    4

/**********************************************************************************************************************
 User-defined Types
**********************************************************************************************************************/
typedef enum {
    XRDC_INSTANCE_0,
    XRDC_INSTANCE_1
} xrdcInstanceNum_t;

typedef struct {
    uint8_t num_pac;
    uint8_t num_mrc;
    uint8_t num_masters;
    uint8_t num_dids;

    uint8_t num_mrgd[16];
} xrdcHwCfg_t;

/**********************************************************************************************************************
 External Objects
**********************************************************************************************************************/

/**********************************************************************************************************************
 Global Variables
**********************************************************************************************************************/
/* Allows app core number to be used to find corresponding domain ID
 * Used by ARM core bootloader at src/common/arm_core_boot/ */
uint8_t domainIdLut[] =
{
    XRDC_DID_CM7_0,
    XRDC_DID_CM7_1,

    XRDC_DID_A53
};

/* Below variables not used but kept for posterity */

//xrdcHwCfg_t xrdc_0_hwCfg;
//xrdcHwCfg_t xrdc_1_hwCfg;

/* XRDC_0 has 5 MRCs */
//uint8_t xrdc_0_mrc_mrgd[5] = {8, 4, 8, 4, 8};
/* XRDC_1 has 4 MRCs. Each has 4 MRGDs apart from MRC0(16) */
//uint8_t xrdc_1_mrc_mrgd[4] = {16, 4, 4, 4};

/**********************************************************************************************************************
 Local Function Prototypes
**********************************************************************************************************************/
void xrdc_ConfigureMdac(xrdcBusMaster_t master, uint8_t did);
void xrdc_ConfigureMrc(uint8_t did, uint8_t acp);
void xrdc_ConfigurePac(xrdcInstanceNum_t xrdc, uint16_t perSlot, uint8_t accessPolicy, uint8_t did);

/**********************************************************************************************************************
 Global Functions
**********************************************************************************************************************/
/*--------------------------------------------------------------------------------------------------------------------
 @brief      Enable both XRDC instances.
 @param[in]  None
 @param[out] None
 @return     None
---------------------------------------------------------------------------------------------------------------------*/
void xrdc_ConfigureEnable(void)
{
    /* Configure the MDAC and MRC for M7 cores, allowing full access to all resources */
    xrdc_ConfigureMdac(XRDC_CM7_0, XRDC_DID_CM7_0);
    xrdc_ConfigureMrc(XRDC_DID_CM7_0, ACP_FULL);

    xrdc_ConfigureMdac(XRDC_CM7_1, XRDC_DID_CM7_1);
    xrdc_ConfigureMrc(XRDC_DID_CM7_1, ACP_FULL);

    /* Configure the MDAC and MRC for A53 core, allowing full access to all resources */
    xrdc_ConfigureMdac(XRDC_A53, XRDC_DID_A53);
    xrdc_ConfigureMrc(XRDC_DID_A53, ACP_FULL);

    /* Configure the MDAC and MRC for SPT, allowing full access to all resources */
    xrdc_ConfigureMdac(XRDC_SPT, XRDC_DID_SPT);
    xrdc_ConfigureMrc(XRDC_DID_SPT, ACP_FULL);

    /* Configure the MDAC and MRC for BBE32, allowing full access to all resources */
    xrdc_ConfigureMdac(XRDC_BBE32, XRDC_DID_BBE);
    xrdc_ConfigureMrc(XRDC_DID_BBE, ACP_FULL);

    /* Configure MRC for domain ID = 0 where other masters remain */
    xrdc_ConfigureMrc(0, ACP_FULL);

    /* Global enable of both XRDC instances */
    XRDC_0.CR.B.GVLD = 1;
    XRDC_1.CR.B.GVLD = 1;

    return;
}

/**********************************************************************************************************************
 Local Functions
**********************************************************************************************************************/
/*--------------------------------------------------------------------------------------------------------------------
 @brief     Configure the Master Domain Assignment Controller (MDAC) for the specified master and domain ID
            Sets valid bit and DID = did. For non ARM CPU masters also set bus attribute to privileged.
 @param[in] xrdcBusMaster_t master - enum to identify which master is being configured.
 @param[in] uint8_t did - specify which domain ID to assign to the master
 @return    None
---------------------------------------------------------------------------------------------------------------------*/
void xrdc_ConfigureMdac(xrdcBusMaster_t master, uint8_t did)
{
    switch(master)
    {
        case XRDC_CM7_0:    // XRDC_0 MDAC: 1 (AXI), 5 (AHB)
        {
            /* CM7_0 AXI */
            XRDC_0.MDA_W0_1_DFMT0.R =  VLD_SET | did;
            /* CM7_0 AHB */
            XRDC_0.MDA_W0_5_DFMT0.R =  VLD_SET | did;

            break;
        }

        case XRDC_CM7_1:    // XRDC_0 MDAC: 2 (AXI), 6 (AHB)
        {
            /* CM7_1 AXI */
            XRDC_0.MDA_W0_2_DFMT0.R =  VLD_SET | did;
            /* CM7_1 AHB */
            XRDC_0.MDA_W0_6_DFMT0.R =  VLD_SET | did;

            break;
        }

        case XRDC_A53:    // XRDC_1 MDAC: 0
        {
            XRDC_1.MDA_W0_0_DFMT0.R =  VLD_SET | did;

            break;
        }

        case XRDC_SPT:    // XRDC_1 MDAC: 3
        {
            XRDC_1.MDA_W0_3_DFMT1.R =  VLD_SET | (1 << MDA_PA_FIELD) | did;

            break;
        }

        case XRDC_BBE32:    // XRDC_1 MDAC: 2
        {
            XRDC_1.MDA_W0_2_DFMT1.R =  VLD_SET | (1 << MDA_PA_FIELD) | did;

            break;
        }

        default:
            break;
    }
}

/*--------------------------------------------------------------------------------------------------------------------
 @brief     Configure the Memory Region Controller (MRC) to allow full access for the specified DID
 @param[in] did - Specify which domain ID
 @param[in] did - Specify the MRGD access control policy bits
 @return    None
---------------------------------------------------------------------------------------------------------------------*/
void xrdc_ConfigureMrc(uint8_t did, uint8_t acp)
{
    uint8_t i;

    /* XRDC_0 MRCs */
    for (i = 0; i < XRDC_0_MRC_NUM; i ++)
    {
        /* Can configure multiple regions using the MRGDs but only one is required when enabling full access */

        XRDC_0.MRCN[i].MRGDN[0].XRDC_MRGD_W0.R = 0x00000000;                          /* Start address */
        XRDC_0.MRCN[i].MRGDN[0].XRDC_MRGD_W1.R = 0xFFFFFFFF;                          /* End address */
        XRDC_0.MRCN[i].MRGDN[0].XRDC_MRGD_W2.R |= (acp << (did * ACP_DID_BITS));   /* Access control policy per domain */
        XRDC_0.MRCN[i].MRGDN[0].XRDC_MRGD_W3.R = VLD_SET;                             /* Valid and lock bit */
    }

    /* XRDC_1 MRCs */
    for (i = 0; i < XRDC_1_MRC_NUM; i ++)
    {
        /* Can configure multiple regions using the MRGDs but only one is required when enabling full access */
        XRDC_1.MRGDN[i][0].XRDC_MRGD_W0.R = 0x00000000;                          /* Start address */
        XRDC_1.MRGDN[i][0].XRDC_MRGD_W1.R = 0xFFFFFFFF;                          /* End address */
        XRDC_1.MRGDN[i][0].XRDC_MRGD_W2.R |= (acp << (did * ACP_DID_BITS));   /* Access control policy per domain */
        XRDC_1.MRGDN[i][0].XRDC_MRGD_W3.R = VLD_SET;                             /* Valid and lock bit */
    }
}

/*--------------------------------------------------------------------------------------------------------------------
 @brief     Configure the Peripheral (Domain) Access Controller (PAC/PDAC) to allow full access for the specified DID
            By default the XRDC allows all domains full access to all peripherals.
            This function allows users to restrict specific peripherals.
 @param[in] xrdcInstanceNum_t xrdc - the XRDC module instance
 @param[in] uint16_t perSlot - the peripheral to configure access to. See the memory map spreadsheet.
 @param[in] uint8_t did - specify which domain ID to allow access to the peripheral.
 @return    None
---------------------------------------------------------------------------------------------------------------------*/
void xrdc_ConfigurePac(xrdcInstanceNum_t xrdc, uint16_t perSlot, uint8_t accessPolicy, uint8_t did)
{
    uint32_t *pPdacW0, *pPdacW1;

    if (xrdc == XRDC_INSTANCE_0)
        pPdacW0 = (uint32_t *) XRDC_0_BASE_ADDR + PDAC_SLOT_0_OFFSET;    // Base address of XRDC_0 PDAC group 0 slot 0
    else
        pPdacW0 = (uint32_t *) XRDC_1_BASE_ADDR + PDAC_SLOT_0_OFFSET;    // Base address of XRDC_1 PDAC slot 0

    pPdacW0 += perSlot;     // Add offset to point at specified peripheral slot W0
    pPdacW1 = pPdacW0 + 4;  // Add offset to point at specified peripheral slot W1

    *pPdacW0 |= accessPolicy << (did * ACP_DID_BITS);
    *pPdacW1 = VLD_SET;
}

/*--------------------------------------------------------------------------------------------------------------------
 @brief      Capture the XRDC SoC/HW integration details. These can then be used to inform the driver when performing
             configuration of the system.
 @param[in]  xrdcInstanceNum_t xrdc - the XRDC module instance
 @param[out] xrdcHwCfg_t *pHwInfo - populated with data read from the XRDC integration configuration registers.
 @return     None
---------------------------------------------------------------------------------------------------------------------*/
void xrdc_GetHwInfo(xrdcInstanceNum_t xrdc, xrdcHwCfg_t *pHwInfo)
{
    struct XRDC_0_tag *xrdc_reg;
    uint8_t i;

    if (xrdc == XRDC_INSTANCE_0)
        xrdc_reg = (struct XRDC_0_tag *) XRDC_0_BASE_ADDR;    /* Base address of XRDC_0 */
    else
        xrdc_reg = (struct XRDC_0_tag *) XRDC_1_BASE_ADDR;    /* Base address of XRDC_1 */

    pHwInfo->num_pac = xrdc_reg->HWCFG0.B.NPAC;
    pHwInfo->num_mrc = xrdc_reg->HWCFG0.B.NMRC;
    pHwInfo->num_masters = xrdc_reg->HWCFG0.B.NMSTR;
    pHwInfo->num_dids = xrdc_reg->HWCFG0.B.NDID;

    for (i = 0; i < pHwInfo->num_mrc; i++)
        pHwInfo->num_mrgd[i] = xrdc_reg->MRCFG[i].R;

    return;
}

/**********************************************************************************************************************
 EOF
**********************************************************************************************************************/
