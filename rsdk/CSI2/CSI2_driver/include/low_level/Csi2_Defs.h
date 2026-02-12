/*
 * Copyright 2019-2022 NXP
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef CSI2_DEFS_H
#define CSI2_DEFS_H

/*==================================================================================================
 *                                        INCLUDE FILES
 ==================================================================================================*/
#include "rsdk_status.h"
#if defined(TRACE_ENABLE)
    #include "csi2_driver_platform_trace.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*==================================================================================================
 *                                          CONSTANTS
 ==================================================================================================*/

/*==================================================================================================
 *                                      DEFINES AND MACROS
 ==================================================================================================*/
/* IO definitions (access restrictions to peripheral registers) */
/**
*   IO Type Qualifiers are used
*   \li to specify the access to peripheral variables.
*   \li for automatic generation of peripheral register debug information.
*/
#ifndef __IO
#ifdef __cplusplus
  #define   __I     volatile             /*!< Defines 'read only' permissions                 */
#else
  #define   __I     volatile const       /*!< Defines 'read only' permissions                 */
#endif
#define     __O     volatile             /*!< Defines 'write only' permissions                */
#define     __IO    volatile             /*!< Defines 'read / write' permissions              */
#endif

#define E_OK        RSDK_SUCCESS
#define E_NOT_OK    RSDK_ERROR

// interrupt definitions






#define CSI2_IRQ_RX_BASE_ID_GIC         204         // irq number for CSI2 Rx error interrupt, unit 0
#define CSI2_IRQ_PATH_BASE_ID_GIC       205         // irq number for CSI2 Path error interrupt, unit 0
#define CSI2_IRQ_EVENT_BASE_ID_GIC      206         // irq number for CSI2 events interrupt, unit 0
#define CSI2_IRQ_MAP_GAP                6           // gap between the similar irq numbers














// very specific CSI2 definition for S32R294
#if defined(S32R294)

#define MIPICSI2_DPHY_FREQCFG_HSFREQRNG_MASK                            CSI_DPHY_FREQCFG_HSFREQRNG_MASK
#define MIPICSI2_DPHY_FREQCFG_HSFREQRNG(x)                              CSI_DPHY_FREQCFG_HSFREQRNG(x)

#define MIPICSI2_DPHY_ATB_CB_ATB_VBE_SEL_CB_SEL_VREF_LPRX_RW_1_0_MASK \
                                                    CSI_DPHY_ATB_CB_ATB_VBE_SEL_CB_SEL_VREF_LPRX_RW_1_0_MASK
#define MIPICSI2_DPHY_ATB_CB_ATB_VBE_SEL_CB_SEL_VREF_LPRX_RW_1_0(x) \
                                                    CSI_DPHY_ATB_CB_ATB_VBE_SEL_CB_SEL_VREF_LPRX_RW_1_0(x)

#define MIPICSI2_DPHY_CB_VBE_SEL_CB_SEL_VREFCD_LPRX_RW__1__0___MASK \
                                                    CSI_DPHY_CB_VBE_SEL_CB_SEL_VREFCD_LPRX_RW__1__0___MASK
#define MIPICSI2_DPHY_CB_VBE_SEL_CB_SEL_VREFCD_LPRX_RW__1__0__(x) \
                                                    CSI_DPHY_CB_VBE_SEL_CB_SEL_VREFCD_LPRX_RW__1__0__(x)

#define MIPICSI2_DPHY_CLOCK_LANE_CNTRL_RXCLK_RXHS_PULL_LONG_CHANNEL_IF_RW_MASK \
                                                    CSI_DPHY_CLOCK_LANE_CNTRL_RXCLK_RXHS_PULL_LONG_CHANNEL_IF_RW_MASK
#define MIPICSI2_DPHY_CLOCK_LANE_CNTRL_RXCLK_RXHS_PULL_LONG_CHANNEL_IF_RW(x) \
                                                    CSI_DPHY_CLOCK_LANE_CNTRL_RXCLK_RXHS_PULL_LONG_CHANNEL_IF_RW(x)

#define MIPICSI2_DPHY_DDLOSCFREQ_CFG1_DDL_OSC_FREQ_TARGET_OVR_RW__7__0___MASK \
                                                    CSI_DPHY_DDLOSCFREQ_CFG1_DDL_OSC_FREQ_TARGET_OVR_RW__7__0___MASK
#define MIPICSI2_DPHY_DDLOSCFREQ_CFG1_DDL_OSC_FREQ_TARGET_OVR_RW__7__0__(x) \
                                                    CSI_DPHY_DDLOSCFREQ_CFG1_DDL_OSC_FREQ_TARGET_OVR_RW__7__0__(x)

#define MIPICSI2_DPHY_DDLOSCFREQ_CFG2_DDL_OSC_FREQ_TARGET_OVR_RW__11__8___MASK \
                                                    CSI_DPHY_DDLOSCFREQ_CFG2_DDL_OSC_FREQ_TARGET_OVR_RW__11__8___MASK
#define MIPICSI2_DPHY_DDLOSCFREQ_CFG2_DDL_OSC_FREQ_TARGET_OVR_RW__11__8__(x) \
                                                    CSI_DPHY_DDLOSCFREQ_CFG2_DDL_OSC_FREQ_TARGET_OVR_RW__11__8__(x)

#define MIPICSI2_DPHY_DDLOSCFREQ_OVREN_DDL_OSC_FREQ_TARGET_OVR_EN_RW_MASK \
                                                    CSI_DPHY_DDLOSCFREQ_OVREN_DDL_OSC_FREQ_TARGET_OVR_EN_RW_MASK
#define MIPICSI2_DPHY_DDLOSCFREQ_OVREN_DDL_OSC_FREQ_TARGET_OVR_EN_RW(x) \
                                                    CSI_DPHY_DDLOSCFREQ_OVREN_DDL_OSC_FREQ_TARGET_OVR_EN_RW(x)

#define MIPICSI2_DPHY_FREQCFG_CLKFREQRNG_MASK                       CSI_DPHY_FREQCFG_CLKFREQRNG_MASK
#define MIPICSI2_DPHY_FREQCFG_CLKFREQRNG(x)                         CSI_DPHY_FREQCFG_CLKFREQRNG(x)

#define MIPICSI2_TURNCFG_FORCERXMODE1_MASK                          CSI_TURNCFG_FORCERXMODE1_MASK
#define MIPICSI2_TURNCFG_FORCERXMODE1(x)                            CSI_TURNCFG_FORCERXMODE1(x)

#define MIPICSI2_TURNCFG_FORCERXMODE2_MASK                          CSI_TURNCFG_FORCERXMODE2_MASK
#define MIPICSI2_TURNCFG_FORCERXMODE2(x)                            CSI_TURNCFG_FORCERXMODE2(x)

#define MIPICSI2_TURNCFG_FORCERXMODE3_MASK                          CSI_TURNCFG_FORCERXMODE3_MASK
#define MIPICSI2_TURNCFG_FORCERXMODE3(x)                            CSI_TURNCFG_FORCERXMODE3(x)

#define MIPICSI2_TURNCFG_FORCERXMODE4_MASK                          CSI_TURNCFG_FORCERXMODE4_MASK
#define MIPICSI2_TURNCFG_FORCERXMODE4(x)                            CSI_TURNCFG_FORCERXMODE4(x)

#define MIPICSI2_RX_RXENABLE_CFG_CLK_LANE_EN_MASK                   CSI_RX_RXENABLE_CFG_CLK_LANE_EN_MASK
#define MIPICSI2_RX_RXENABLE_CFG_CLK_LANE_EN(x)                     CSI_RX_RXENABLE_CFG_CLK_LANE_EN(x)
#define MIPICSI2_RX_RXENABLE_CFG_CLK_LANE_EN_SHIFT                  CSI_RX_RXENABLE_CFG_CLK_LANE_EN_SHIFT

#define MIPICSI2_RX_RXENABLE_CFG_DATA_LANE_EN_MASK                  CSI_RX_RXENABLE_CFG_DATA_LANE_EN_MASK
#define MIPICSI2_RX_RXENABLE_CFG_DATA_LANE_EN(x)                    CSI_RX_RXENABLE_CFG_DATA_LANE_EN(x)

#define MIPICSI2_RX_RXENABLE_CFG_FLUSH_CNT_MASK                     CSI_RX_RXENABLE_CFG_FLUSH_CNT_MASK
#define MIPICSI2_RX_RXENABLE_CFG_FLUSH_CNT(x)                       CSI_RX_RXENABLE_CFG_FLUSH_CNT(x)

#define MIPICSI2_DPHY_CALTYPE_CNTRL_NOEXT_BURNIN_RES_CAL_RW_MASK    CSI_DPHY_CALTYPE_CNTRL_NOEXT_BURNIN_RES_CAL_RW_MASK

#define MIPICSI2_RX_VCINTRE_GNSPIE0_MASK                            CSI_RX_VCINTRE_GNSPIE0_MASK
#define MIPICSI2_RX_VCINTRE_GNSPIE0(x)                              CSI_RX_VCINTRE_GNSPIE0(x)

#define MIPICSI2_RX_VCINTRE_FSIE0_MASK                              CSI_RX_VCINTRE_FSIE0_MASK
#define MIPICSI2_RX_VCINTRE_FSIE0(x)                                CSI_RX_VCINTRE_FSIE0(x)

#define MIPICSI2_RX_VCINTRE_FEIE0_MASK                              CSI_RX_VCINTRE_FEIE0_MASK
#define MIPICSI2_RX_VCINTRE_FEIE0(x)                                CSI_RX_VCINTRE_FEIE0(x)

#define MIPICSI2_RX_VCINTRE_GNSPIE1_MASK                            CSI_RX_VCINTRE_GNSPIE1_MASK
#define MIPICSI2_RX_VCINTRE_GNSPIE1(x)                              CSI_RX_VCINTRE_GNSPIE1(x)

#define MIPICSI2_RX_VCINTRE_FSIE1_MASK                              CSI_RX_VCINTRE_FSIE1_MASK
#define MIPICSI2_RX_VCINTRE_FSIE1(x)                                CSI_RX_VCINTRE_FSIE1(x)

#define MIPICSI2_RX_VCINTRE_FEIE1_MASK                              CSI_RX_VCINTRE_FEIE1_MASK
#define MIPICSI2_RX_VCINTRE_FEIE1(x)                                CSI_RX_VCINTRE_FEIE1(x)

#define MIPICSI2_RX_VCINTRE_GNSPIE2_MASK                            CSI_RX_VCINTRE_GNSPIE2_MASK
#define MIPICSI2_RX_VCINTRE_GNSPIE2(x)                              CSI_RX_VCINTRE_GNSPIE2(x)

#define MIPICSI2_RX_VCINTRE_FSIE2_MASK                              CSI_RX_VCINTRE_FSIE2_MASK
#define MIPICSI2_RX_VCINTRE_FSIE2(x)                                CSI_RX_VCINTRE_FSIE2(x)

#define MIPICSI2_RX_VCINTRE_FEIE2_MASK                              CSI_RX_VCINTRE_FEIE2_MASK
#define MIPICSI2_RX_VCINTRE_FEIE2(x)                                CSI_RX_VCINTRE_FEIE2(x)

#define MIPICSI2_RX_VCINTRE_GNSPIE3_MASK                            CSI_RX_VCINTRE_GNSPIE3_MASK
#define MIPICSI2_RX_VCINTRE_GNSPIE3(x)                              CSI_RX_VCINTRE_GNSPIE3(x)

#define MIPICSI2_RX_VCINTRE_FSIE3_MASK                              CSI_RX_VCINTRE_FSIE3_MASK
#define MIPICSI2_RX_VCINTRE_FSIE3(x)                                CSI_RX_VCINTRE_FSIE3(x)

#define MIPICSI2_RX_VCINTRE_FEIE3_MASK                              CSI_RX_VCINTRE_FEIE3_MASK
#define MIPICSI2_RX_VCINTRE_FEIE3(x)                                CSI_RX_VCINTRE_FEIE3(x)

#define MIPICSI2_RX_CHNL_INTRE_LINEDONEIE_MASK                      CSI_RX_CHNL_INTRE_LINEDONEIE_MASK
#define MIPICSI2_RX_CHNL_INTRE_LINEDONEIE(x)                        CSI_RX_CHNL_INTRE_LINEDONEIE(x)

#define MIPICSI2_RX_CHNL_INTRE_LINEDONEIE_MASK                      CSI_RX_CHNL_INTRE_LINEDONEIE_MASK
#define MIPICSI2_RX_CHNL_INTRE_LINEDONEIE(x)                        CSI_RX_CHNL_INTRE_LINEDONEIE(x)

#define MIPICSI2_RX_CHNL_INTRE_BUFFOVFIE_MASK                       CSI_RX_CHNL_INTRE_BUFFOVFIE_MASK
#define MIPICSI2_RX_CHNL_INTRE_BUFFOVFIE(x)                         CSI_RX_CHNL_INTRE_BUFFOVFIE(x)

#define MIPICSI2_RX_LANCS_DSTOP_MASK                                CSI_RX_LANCS_DSTOP_MASK
#define MIPICSI2_DPHY_RSTCFG_RSTZ_MASK                              CSI_DPHY_RSTCFG_RSTZ_MASK
#define MIPICSI2_RX_CHNL_INTRS_BUFFOVF_MASK                         CSI_RX_CHNL_INTRS_BUFFOVF_MASK
#define MIPICSI2_WR_CHNL_INTRS_BUFFOVFAXI_MASK                      CSI_WR_CHNL_INTRS_BUFFOVFAXI_MASK
#define MIPICSI2_WR_CHNL_INTRS_ERRRESP_MASK                         CSI_WR_CHNL_INTRS_ERRRESP_MASK
#define MIPICSI2_CONTROLLER_ERR_STATUS_REGISTER_FIFO_OVERFLOW_ERROR_MASK \
                                                    CSI_CONTROLLER_ERR_STATUS_REGISTER_FIFO_OVERFLOW_ERROR_MASK
#define MIPICSI2_CONTROLLER_ERR_STATUS_REGISTER_EXIT_HS_ERROR_MASK \
                                                    CSI_CONTROLLER_ERR_STATUS_REGISTER_EXIT_HS_ERROR_MASK
#define MIPICSI2_RX_GNSPR_VC_DATAID_MASK                            CSI_RX_GNSPR_VC_DATAID_MASK
#define MIPICSI2_RX_GNSPR_VC_DATAID_SHIFT                           CSI_RX_GNSPR_VC_DATAID_SHIFT
#define MIPICSI2_RX_GNSPR_VC_DATA_MASK                              CSI_RX_GNSPR_VC_DATA_MASK
#define MIPICSI2_RX_GNSPR_VC_DATA_SHIFT                             CSI_RX_GNSPR_VC_DATA_SHIFT
#define MIPICSI2_RX_DATAIDR_VCID_MASK                               CSI_RX_DATAIDR_VCID_MASK
#define MIPICSI2_RX_DATAIDR_VCID_SHIFT                              CSI_RX_DATAIDR_VCID_SHIFT

#endif


/*==================================================================================================
 *                                             ENUMS
 ==================================================================================================*/

/*==================================================================================================
 *                                STRUCTURES AND OTHER TYPEDEFS
 ==================================================================================================*/

/*==================================================================================================
 *                                GLOBAL VARIABLE DECLARATIONS
 ==================================================================================================*/

/*==================================================================================================
 *                                    FUNCTION PROTOTYPES
 ==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /*CSI2_DEFS_H*/
