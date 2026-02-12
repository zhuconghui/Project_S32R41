/**************************************************************************************************
* Copyright 2024 NXP
**************************************************************************************************
 * NXP Confidential and Proprietary. This software is owned or controlled by NXP and
 * may only be used strictly in accordance with the applicable license terms.  By
 * expressly accepting such terms or by downloading, installing, activating and/or
 * otherwise using the software, you are agreeing that you have read, and that you
 * agree to comply with and are bound by, such license terms.  If you do not agree to
 * be bound by the applicable license terms, then you may not retain, install, activate or
 * otherwise use the software.
**************************************************************************************************/

#ifndef RFE_TEF82XX_VOLTAGE_H_
#define RFE_TEF82XX_VOLTAGE_H_

/******************************************************************************
 *                              INCLUDES
 *****************************************************************************/
#include <stdint.h>

/******************************************************************************
 *                              DEFINES
 *****************************************************************************/

/******************************************************************************
 *                              TYPES
 *****************************************************************************/
/**
*   @addtogroup rsdk_rfe_api_interface
*   @{
*/

/**
* Structure for ADC voltages
*/
typedef struct {
    uint16_t ADC_NODE_1V1_SAFETY_SUPPLY;        /**< ball N3 VDDD_SAFETY_1V1                                */
    uint16_t ADC_NODE_1V1_SUPPLY;               /**< internally generated                                   */
    uint16_t ADC_NODE_1V8_SUPPLY;               /**< ball ADC12=C12 VDDA_ADC12_1V8, ADC34=N12 VDDA_ADC34_1V8*/
} ATB_ADCVoltages_t;

/**
* Structure for ATB voltages
*/
typedef struct {
    uint16_t ATB_NODE_VDDD_SAFETY_1V1;          /**< ball N3 VDDD_SAFETY_1V1                                */
    uint16_t ATB_NODE_VDDA_1V1;                 /**< internally generated                                   */
    uint16_t ATB_NODE_VDDA_1V8;                 /**< ball C12 VDDA_ADC12_1V8                                */
} ATB_ATBVoltages_t;

/**
* Structure for CAFC voltages
*/
typedef struct {
    uint16_t CAFC_NODE_VDD_PLL_1V1_FILTERED;    /**< ball N3 filtered VDDD_SAFETY_1V1                       */
    uint16_t CAFC_NODE_LDO_CPPFD_VDD;           /**< internally generated                                   */
    uint16_t CAFC_NODE_LDO_DIVIDER_VDD;         /**< internally generated                                   */
    uint16_t CAFC_NODE_LDO_VCO_VDD;             /**< internally generated                                   */
    uint16_t CAFC_NODE_VDD_PLL_1V8;             /**< ball B8 VDDA_PLL_26G_1V8                               */
    uint16_t CAFC_NODE_VDD_VCO_1V8;             /**< ball A7 VDDA_VCO_26G_1V8                               */
} ATB_CAFCVoltages_t;

/**
* Structure for GBIAS voltages
*/
typedef struct {
    uint16_t GBIAS_NODE_VDDA_GLOBAL_BIAS_1V8;   /**< ball C6 & B6 & B7 VDDA_BIAS_1V8                        */
} ATB_GBIASVoltages_t;

/**
* Structure for GLDOV voltages
*/
typedef struct {
    uint16_t GLDO_NODE_VDDD_SAFETY_1V1;         /**< ball N3 VDDD_SAFETY_1V1                                */
    uint16_t GLDO_NODE_VDDA_LDO_1V1;            /**< ball B4 VDDA_LDO_1V1                                   */
    uint16_t GLDO_NODE_VDDA_LDO_1V8;            /**< ball C6 & B6 & B7 VDDA_BIAS_1V8                        */
    uint16_t GLDO_NODE_VDDA_LDO_3V3;            /**< ball A1 & B2 VDDA_LDO_3V3                              */
} ATB_GLDOVoltages_t;

/**
* Structure for LOI voltages
*/
typedef struct {
    uint16_t LOI_NODE_VDDD_SAFETY_1V1;          /**< all N3 VDDD_SAFETY_1V1                                 */
    uint16_t LOI_NODE_VDDA_INTERFACE_1V1;       /**< ball H13 VDDA_LOI_1V1                                  */
    uint16_t LOI_NODE_VDDA_1V8;                 /**< ball C6 & B6 & B7 VDDA_BIAS_1V8                        */
} ATB_LOIVoltages_t;

/**
* Structure for MCLK voltages
*/
typedef struct {
    uint16_t MCLK_NODE_VDDD_SAFETY_1V1;         /**< ball N3 VDDD_SAFETY_1V1                                */
    uint16_t MCLK_NODE_VDDA_1V1;                /**< internally generated                                   */
    uint16_t MCLK_NODE_VDDA_1V8;                /**< ball B9 VDDA_MASTERCLK_1V8                             */
} ATB_MCLKVoltages_t;

/**
* Structure for MIPI voltages
*/
typedef struct {
    uint16_t MIPI_NODE_SUPPLY1V1_CSI2;          /**< internally generated                                   */
    uint16_t MIPI_NODE_SUPPLY1V1_SER;           /**< internally generated                                   */
    uint16_t MIPI_NODE_SUPPLY1V8;               /**< ball N9 VDDD_SER_1V8                                   */
    uint16_t MIPI_NODE_SUPPLYIO_1v8_3v3;        /**< ball N8 VDDD_IO_1V8_3V3                                */
    uint16_t MIPI_NODE_SUPPLY_MIPI_3v3;         /**< ball N7 VDDD_IO_LVDS_3V3                               */
} ATB_MIPIVoltages_t;

/**
* Structure for RX voltages
*/
typedef struct {
    uint16_t RX_NODE_VDDD_1V1;                  /**< ball N3 VDDD_SAFETY_1V1                                */
    uint16_t RX_NODE_VDDA_1V1;                  /**< ball RX1=E13 VDDA_RX1_1V1, RX2=F13 VDDA_RX2_1V1, RX3=K13 VDDA_RX3_1V1, RX4=L13 VDDA_RX4_1V1    */
    uint16_t RX_NODE_VDDA_1V8;                  /**< ball RX1=C13 VDDA_RX1_1V8, RX2=G13 VDDA_RX2_1V8, RX3=J13 VDDA_RX3_1V8, RX4=N13 VDDA_RX4_1V8    */
} ATB_RXVoltages_t;

/**
* Structure for SSB voltages
*/
typedef struct {
    uint16_t SSB_NODE_VDDD_1V1;                 /**< ball N3 VDDD_SAFETY_1V1                                */
    uint16_t SSB_NODE_VDDA_1V1;                 /**< internally generated                                   */
    uint16_t SSB_NODE_VDDA_1V8;                 /**< ball N11 VDDA_BIST_1V8                                 */
} ATB_SSBVoltages_t;

/**
* Structure for TX voltages
*/
typedef struct {
    uint16_t TX_NODE_VDDD_1V1_FS;               /**< ball N3 VDDD_SAFETY_1V1                                */
    uint16_t TX_NODE_VDDA_1V1;                  /**< ball M3 VDDA_TX_1V1                                    */
    uint16_t TX_NODE_VDDA_1V8;                  /**< ball TX1=F3&D3 VDDA_TX1_1V8, TX2=H3&G3 VDDA_TX2_1V8, TX3=L3&J3  VDDA_TX3_1V8 VDDA_TX3_1V8      */
} ATB_TXVoltages_t;

/**
* This type defines the container for ATB based voltage read-out (in mV) of all modules.
*/
typedef struct {
    ATB_ADCVoltages_t   ADC12Voltages;
    ATB_ADCVoltages_t   ADC34Voltages;
    ATB_ATBVoltages_t   ATBVoltages;
    ATB_CAFCVoltages_t  CAFCVoltages;
    ATB_GBIASVoltages_t GBIASVoltages;
    ATB_GLDOVoltages_t  GLDOVoltages;
    ATB_LOIVoltages_t   LOIVoltages;
    ATB_MCLKVoltages_t  MCLKVoltages;
    ATB_MIPIVoltages_t  MIPIVoltages;
    ATB_RXVoltages_t    RX1Voltages;
    ATB_RXVoltages_t    RX2Voltages;
    ATB_RXVoltages_t    RX3Voltages;
    ATB_RXVoltages_t    RX4Voltages;
    ATB_SSBVoltages_t   SSBVoltages;
    ATB_TXVoltages_t    TX1Voltages;
    ATB_TXVoltages_t    TX2Voltages;
    ATB_TXVoltages_t    TX3Voltages;
} rfe_tef82xxVoltages_t;

/**
*   @}
*/

#endif // #ifndef RFE_TEF82XX_VOLTAGE_H_
