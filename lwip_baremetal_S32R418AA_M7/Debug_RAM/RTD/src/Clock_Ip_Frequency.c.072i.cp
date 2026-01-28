
IPA constant propagation start:
Determining dynamic type for call: Fout_3 = Clock_Ip_PLL_VCO.part.0 (Base_7(D));
  Starting walk at: Fout_3 = Clock_Ip_PLL_VCO.part.0 (Base_7(D));
  instance pointer: Base_7(D)  Outer instance pointer: Base_7(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _17 = Clock_Ip_DFS_OUTPUT (1074528256B, 1, _16);
  Starting walk at: _17 = Clock_Ip_DFS_OUTPUT (1074528256B, 1, _16);
  instance pointer: 1074528256B  Outer instance pointer: 1074528256B offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_16 = Clock_Ip_Get_PERIPHPLL_CLK_Frequency ();
Determining dynamic type for call: _17 = Clock_Ip_DFS_OUTPUT (1074528256B, 0, _16);
  Starting walk at: _17 = Clock_Ip_DFS_OUTPUT (1074528256B, 0, _16);
  instance pointer: 1074528256B  Outer instance pointer: 1074528256B offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_16 = Clock_Ip_Get_PERIPHPLL_CLK_Frequency ();
Determining dynamic type for call: _8 = Clock_Ip_PLL_VCO (1074511872B);
  Starting walk at: _8 = Clock_Ip_PLL_VCO (1074511872B);
  instance pointer: 1074511872B  Outer instance pointer: 1074511872B offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _12 = Clock_Ip_PLL_VCO (1141637120B);
  Starting walk at: _12 = Clock_Ip_PLL_VCO (1141637120B);
  instance pointer: 1141637120B  Outer instance pointer: 1141637120B offset: 0 (bits) vtbl reference: 

IPA structures before propagation:

Jump functions:
  Jump functions of caller  Clock_Ip_PLL_VCO.part.0/149:
    callsite  Clock_Ip_PLL_VCO.part.0/149 -> Clock_Ip_Get_FXOSC_CLK_Frequency/55 : 
  Jump functions of caller  Clock_Ip_SetExternalSignalFrequency/147:
  Jump functions of caller  Clock_Ip_GetFreq/146:
    indirect simple callsite, calling param -1, offset 0, for stmt _6 = _2 ();
  Jump functions of caller  Clock_Ip_SetExternalOscillatorFrequency/145:
  Jump functions of caller  Clock_Ip_DFS_OUTPUT/144:
  Jump functions of caller  Clock_Ip_PLL_VCO/143:
    callsite  Clock_Ip_PLL_VCO/143 -> Clock_Ip_PLL_VCO.part.0/149 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  Clock_Ip_Get_TCLK_CLK_Frequency/142:
    indirect simple callsite, calling param -1, offset 0, for stmt Frequency_12 = _4 ();
  Jump functions of caller  Clock_Ip_Get_TMU_CLK_Frequency/141:
  Jump functions of caller  Clock_Ip_Get_STCU_CLK_Frequency/140:
  Jump functions of caller  Clock_Ip_Get_SPT_CLK_Frequency/139:
    indirect simple callsite, calling param -1, offset 0, for stmt Frequency_10 = _4 ();
  Jump functions of caller  Clock_Ip_Get_SPI_CLK_Frequency/138:
    indirect simple callsite, calling param -1, offset 0, for stmt Frequency_7 = _4 ();
  Jump functions of caller  Clock_Ip_Get_QSPI0_CLK_Frequency/137:
  Jump functions of caller  Clock_Ip_Get_QSPI_1X_CLK_Frequency/136:
    callsite  Clock_Ip_Get_QSPI_1X_CLK_Frequency/136 -> Clock_Ip_Get_QSPI_2X_CLK_Frequency/135 : 
  Jump functions of caller  Clock_Ip_Get_QSPI_2X_CLK_Frequency/135:
    indirect simple callsite, calling param -1, offset 0, for stmt Frequency_12 = _4 ();
  Jump functions of caller  Clock_Ip_Get_NOC_TRACE_CLK_Frequency/134:
    indirect simple callsite, calling param -1, offset 0, for stmt Frequency_7 = _4 ();
  Jump functions of caller  Clock_Ip_Get_MIPICSI2_1_CLK_Frequency/133:
  Jump functions of caller  Clock_Ip_Get_MIPICSI2_0_CLK_Frequency/132:
    indirect simple callsite, calling param -1, offset 0, for stmt Frequency_10 = _4 ();
  Jump functions of caller  Clock_Ip_Get_LINFLEXD_CLK_Frequency/131:
    callsite  Clock_Ip_Get_LINFLEXD_CLK_Frequency/131 -> Clock_Ip_Get_LIN_BAUD_CLK_Frequency/130 : 
  Jump functions of caller  Clock_Ip_Get_LIN_BAUD_CLK_Frequency/130:
    indirect simple callsite, calling param -1, offset 0, for stmt Frequency_7 = _4 ();
  Jump functions of caller  Clock_Ip_Get_LBIST_CLK_Frequency/129:
    indirect simple callsite, calling param -1, offset 0, for stmt Frequency_12 = _4 ();
  Jump functions of caller  Clock_Ip_Get_GMAC1_TX_CLK_Frequency/128:
    indirect simple callsite, calling param -1, offset 0, for stmt Frequency_12 = _4 ();
  Jump functions of caller  Clock_Ip_Get_GMAC1_TS_CLK_Frequency/127:
    indirect simple callsite, calling param -1, offset 0, for stmt Frequency_12 = _4 ();
  Jump functions of caller  Clock_Ip_Get_GMAC1_RX_CLK_Frequency/126:
    indirect simple callsite, calling param -1, offset 0, for stmt Frequency_7 = _4 ();
  Jump functions of caller  Clock_Ip_Get_GMAC0_TX_CLK_Frequency/125:
    indirect simple callsite, calling param -1, offset 0, for stmt Frequency_7 = _4 ();
  Jump functions of caller  Clock_Ip_Get_GMAC0_TS_CLK_Frequency/124:
    indirect simple callsite, calling param -1, offset 0, for stmt Frequency_12 = _4 ();
  Jump functions of caller  Clock_Ip_Get_GMAC0_RX_CLK_Frequency/123:
    indirect simple callsite, calling param -1, offset 0, for stmt Frequency_7 = _4 ();
  Jump functions of caller  Clock_Ip_Get_FTM0_EXT_CLK_Frequency/122:
    indirect simple callsite, calling param -1, offset 0, for stmt Frequency_12 = _4 ();
  Jump functions of caller  Clock_Ip_Get_FCCU_IPS_CLK_Frequency/121:
  Jump functions of caller  Clock_Ip_Get_DSPI_SCK_TST_CLK_Frequency/120:
    indirect simple callsite, calling param -1, offset 0, for stmt Frequency_12 = _4 ();
  Jump functions of caller  Clock_Ip_Get_DAPB_CLK_Frequency/119:
    indirect simple callsite, calling param -1, offset 0, for stmt Frequency_12 = _4 ();
  Jump functions of caller  Clock_Ip_Get_CTU_IPS_CLK_Frequency/118:
  Jump functions of caller  Clock_Ip_Get_MC_CLK_Frequency/117:
    indirect simple callsite, calling param -1, offset 0, for stmt Frequency_7 = _4 ();
  Jump functions of caller  Clock_Ip_Get_CSI_TXCLK_CLK_Frequency/116:
    indirect simple callsite, calling param -1, offset 0, for stmt Frequency_12 = _4 ();
  Jump functions of caller  Clock_Ip_Get_CTE_CLK_Frequency/115:
    indirect simple callsite, calling param -1, offset 0, for stmt Frequency_7 = _4 ();
  Jump functions of caller  Clock_Ip_Get_CSI_CFG_CLK_Frequency/114:
    indirect simple callsite, calling param -1, offset 0, for stmt Frequency_12 = _4 ();
  Jump functions of caller  Clock_Ip_Get_CSI_CLK_Frequency/113:
    indirect simple callsite, calling param -1, offset 0, for stmt Frequency_7 = _4 ();
  Jump functions of caller  Clock_Ip_Get_CLKOUT1_CLK_Frequency/112:
    indirect simple callsite, calling param -1, offset 0, for stmt Frequency_12 = _4 ();
  Jump functions of caller  Clock_Ip_Get_CLKOUT0_CLK_Frequency/111:
    indirect simple callsite, calling param -1, offset 0, for stmt Frequency_12 = _4 ();
  Jump functions of caller  Clock_Ip_Get_CAN_PE_CLK_Frequency/110:
    indirect simple callsite, calling param -1, offset 0, for stmt Frequency_7 = _4 ();
  Jump functions of caller  Clock_Ip_Get_CAN_TS_CLK_Frequency/109:
    indirect simple callsite, calling param -1, offset 0, for stmt Frequency_12 = _4 ();
  Jump functions of caller  Clock_Ip_Get_CAN_CHI_CLK_Frequency/108:
    indirect simple callsite, calling param -1, offset 0, for stmt Frequency_12 = _4 ();
  Jump functions of caller  Clock_Ip_Get_BBE32EP_DSP_CLK_Frequency/107:
    indirect simple callsite, calling param -1, offset 0, for stmt Frequency_9 = _4 ();
  Jump functions of caller  Clock_Ip_Get_GMAC1_INT_CLK_Frequency/106:
    indirect simple callsite, calling param -1, offset 0, for stmt Frequency_7 = _4 ();
  Jump functions of caller  Clock_Ip_Get_GMAC_1_INT_REF_CLK_Frequency/105:
    callsite  Clock_Ip_Get_GMAC_1_INT_REF_CLK_Frequency/105 -> Clock_Ip_Get_PERIPHPLL_PHI5_Frequency/72 : 
  Jump functions of caller  Clock_Ip_Get_GMAC1_REF_DIV_CLK_Frequency/104:
    indirect simple callsite, calling param -1, offset 0, for stmt Frequency_12 = _4 ();
  Jump functions of caller  Clock_Ip_Get_GMAC1_REF_CLK_Frequency/103:
    indirect simple callsite, calling param -1, offset 0, for stmt Frequency_7 = _4 ();
  Jump functions of caller  Clock_Ip_Get_GMAC0_REF_DIV_CLK_Frequency/102:
    indirect simple callsite, calling param -1, offset 0, for stmt Frequency_12 = _4 ();
  Jump functions of caller  Clock_Ip_Get_GMAC0_REF_CLK_Frequency/101:
    indirect simple callsite, calling param -1, offset 0, for stmt Frequency_7 = _4 ();
  Jump functions of caller  Clock_Ip_Get_ACCEL_XBAR_DIV8_CLK_Frequency/100:
    callsite  Clock_Ip_Get_ACCEL_XBAR_DIV8_CLK_Frequency/100 -> Clock_Ip_Get_ACCEL_XBAR_CLK_Frequency/97 : 
  Jump functions of caller  Clock_Ip_Get_ACCEL_XBAR_DIV4_CLK_Frequency/99:
    callsite  Clock_Ip_Get_ACCEL_XBAR_DIV4_CLK_Frequency/99 -> Clock_Ip_Get_ACCEL_XBAR_CLK_Frequency/97 : 
  Jump functions of caller  Clock_Ip_Get_ACCEL_XBAR_DIV2_CLK_Frequency/98:
    callsite  Clock_Ip_Get_ACCEL_XBAR_DIV2_CLK_Frequency/98 -> Clock_Ip_Get_ACCEL_XBAR_CLK_Frequency/97 : 
  Jump functions of caller  Clock_Ip_Get_ACCEL_XBAR_CLK_Frequency/97:
    indirect simple callsite, calling param -1, offset 0, for stmt Frequency_7 = _4 ();
  Jump functions of caller  Clock_Ip_Get_ACCEL_DIV3_CLK_Frequency/96:
    callsite  Clock_Ip_Get_ACCEL_DIV3_CLK_Frequency/96 -> Clock_Ip_Get_ACCEL_CLK_Frequency/95 : 
  Jump functions of caller  Clock_Ip_Get_ACCEL_CLK_Frequency/95:
    indirect simple callsite, calling param -1, offset 0, for stmt Frequency_7 = _4 ();
  Jump functions of caller  Clock_Ip_Get_A53_CORE_DIV10_CLK_Frequency/94:
    callsite  Clock_Ip_Get_A53_CORE_DIV10_CLK_Frequency/94 -> Clock_Ip_Get_A53_CORE_CLK_Frequency/92 : 
  Jump functions of caller  Clock_Ip_Get_A53_CORE_DIV2_CLK_Frequency/93:
    callsite  Clock_Ip_Get_A53_CORE_DIV2_CLK_Frequency/93 -> Clock_Ip_Get_A53_CORE_CLK_Frequency/92 : 
  Jump functions of caller  Clock_Ip_Get_A53_CORE_CLK_Frequency/92:
    indirect simple callsite, calling param -1, offset 0, for stmt Frequency_7 = _4 ();
  Jump functions of caller  Clock_Ip_Get_SYS_DIV8_CLK_Frequency/91:
    callsite  Clock_Ip_Get_SYS_DIV8_CLK_Frequency/91 -> Clock_Ip_Get_SYS_CLK_Frequency/88 : 
  Jump functions of caller  Clock_Ip_Get_SYS_DIV4_CLK_Frequency/90:
    callsite  Clock_Ip_Get_SYS_DIV4_CLK_Frequency/90 -> Clock_Ip_Get_SYS_CLK_Frequency/88 : 
  Jump functions of caller  Clock_Ip_Get_SYS_DIV2_CLK_Frequency/89:
    callsite  Clock_Ip_Get_SYS_DIV2_CLK_Frequency/89 -> Clock_Ip_Get_SYS_CLK_Frequency/88 : 
  Jump functions of caller  Clock_Ip_Get_SYS_CLK_Frequency/88:
    indirect simple callsite, calling param -1, offset 0, for stmt Frequency_7 = _4 ();
  Jump functions of caller  Clock_Ip_Get_gmac_1_ext_ts_Frequency/87:
  Jump functions of caller  Clock_Ip_Get_gmac_1_ext_tx_Frequency/86:
  Jump functions of caller  Clock_Ip_Get_gmac_1_ext_rx_Frequency/85:
  Jump functions of caller  Clock_Ip_Get_gmac_1_ext_ref_Frequency/84:
  Jump functions of caller  Clock_Ip_Get_gmac_0_ext_ts_Frequency/83:
  Jump functions of caller  Clock_Ip_Get_gmac_0_ext_tx_Frequency/82:
  Jump functions of caller  Clock_Ip_Get_gmac_0_ext_rx_Frequency/81:
  Jump functions of caller  Clock_Ip_Get_gmac_0_ext_ref_Frequency/80:
  Jump functions of caller  Clock_Ip_Get_ftm_0_ext_ref_Frequency/79:
  Jump functions of caller  Clock_Ip_Get_PERIPHPLL_DFS2_Frequency/78:
    callsite  Clock_Ip_Get_PERIPHPLL_DFS2_Frequency/78 -> Clock_Ip_DFS_OUTPUT/144 : 
       param 0: CONST: 1074528256B
         value: 0x0, mask: 0xfffffff8
         VR  ~[0, 0]
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Clock_Ip_Get_PERIPHPLL_DFS2_Frequency/78 -> Clock_Ip_Get_PERIPHPLL_CLK_Frequency/57 : 
  Jump functions of caller  Clock_Ip_Get_PERIPHPLL_DFS1_Frequency/77:
    callsite  Clock_Ip_Get_PERIPHPLL_DFS1_Frequency/77 -> Clock_Ip_DFS_OUTPUT/144 : 
       param 0: CONST: 1074528256B
         value: 0x0, mask: 0xfffffff8
         VR  ~[0, 0]
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Clock_Ip_Get_PERIPHPLL_DFS1_Frequency/77 -> Clock_Ip_Get_PERIPHPLL_CLK_Frequency/57 : 
  Jump functions of caller  Clock_Ip_Get_PERIPHPLL_PHI9_Frequency/76:
    callsite  Clock_Ip_Get_PERIPHPLL_PHI9_Frequency/76 -> Clock_Ip_Get_PERIPHPLL_CLK_Frequency/57 : 
  Jump functions of caller  Clock_Ip_Get_PERIPHPLL_PHI8_Frequency/75:
    callsite  Clock_Ip_Get_PERIPHPLL_PHI8_Frequency/75 -> Clock_Ip_Get_PERIPHPLL_CLK_Frequency/57 : 
  Jump functions of caller  Clock_Ip_Get_PERIPHPLL_PHI7_Frequency/74:
    callsite  Clock_Ip_Get_PERIPHPLL_PHI7_Frequency/74 -> Clock_Ip_Get_PERIPHPLL_CLK_Frequency/57 : 
  Jump functions of caller  Clock_Ip_Get_PERIPHPLL_PHI6_Frequency/73:
    callsite  Clock_Ip_Get_PERIPHPLL_PHI6_Frequency/73 -> Clock_Ip_Get_PERIPHPLL_CLK_Frequency/57 : 
  Jump functions of caller  Clock_Ip_Get_PERIPHPLL_PHI5_Frequency/72:
    callsite  Clock_Ip_Get_PERIPHPLL_PHI5_Frequency/72 -> Clock_Ip_Get_PERIPHPLL_CLK_Frequency/57 : 
  Jump functions of caller  Clock_Ip_Get_PERIPHPLL_PHI4_Frequency/71:
    callsite  Clock_Ip_Get_PERIPHPLL_PHI4_Frequency/71 -> Clock_Ip_Get_PERIPHPLL_CLK_Frequency/57 : 
  Jump functions of caller  Clock_Ip_Get_PERIPHPLL_PHI3_Frequency/70:
    callsite  Clock_Ip_Get_PERIPHPLL_PHI3_Frequency/70 -> Clock_Ip_Get_PERIPHPLL_CLK_Frequency/57 : 
  Jump functions of caller  Clock_Ip_Get_PERIPHPLL_PHI2_Frequency/69:
    callsite  Clock_Ip_Get_PERIPHPLL_PHI2_Frequency/69 -> Clock_Ip_Get_PERIPHPLL_CLK_Frequency/57 : 
  Jump functions of caller  Clock_Ip_Get_PERIPHPLL_PHI1_Frequency/68:
    callsite  Clock_Ip_Get_PERIPHPLL_PHI1_Frequency/68 -> Clock_Ip_Get_PERIPHPLL_CLK_Frequency/57 : 
  Jump functions of caller  Clock_Ip_Get_PERIPHPLL_PHI0_Frequency/67:
    callsite  Clock_Ip_Get_PERIPHPLL_PHI0_Frequency/67 -> Clock_Ip_Get_PERIPHPLL_CLK_Frequency/57 : 
  Jump functions of caller  Clock_Ip_Get_COREPLL_PHI9_Frequency/66:
    callsite  Clock_Ip_Get_COREPLL_PHI9_Frequency/66 -> Clock_Ip_Get_COREPLL_CLK_Frequency/56 : 
  Jump functions of caller  Clock_Ip_Get_COREPLL_PHI8_Frequency/65:
    callsite  Clock_Ip_Get_COREPLL_PHI8_Frequency/65 -> Clock_Ip_Get_COREPLL_CLK_Frequency/56 : 
  Jump functions of caller  Clock_Ip_Get_COREPLL_PHI6_Frequency/64:
    callsite  Clock_Ip_Get_COREPLL_PHI6_Frequency/64 -> Clock_Ip_Get_COREPLL_CLK_Frequency/56 : 
  Jump functions of caller  Clock_Ip_Get_COREPLL_PHI5_Frequency/63:
    callsite  Clock_Ip_Get_COREPLL_PHI5_Frequency/63 -> Clock_Ip_Get_COREPLL_CLK_Frequency/56 : 
  Jump functions of caller  Clock_Ip_Get_COREPLL_PHI4_Frequency/62:
    callsite  Clock_Ip_Get_COREPLL_PHI4_Frequency/62 -> Clock_Ip_Get_COREPLL_CLK_Frequency/56 : 
  Jump functions of caller  Clock_Ip_Get_COREPLL_PHI3_Frequency/61:
    callsite  Clock_Ip_Get_COREPLL_PHI3_Frequency/61 -> Clock_Ip_Get_COREPLL_CLK_Frequency/56 : 
  Jump functions of caller  Clock_Ip_Get_COREPLL_PHI2_Frequency/60:
    callsite  Clock_Ip_Get_COREPLL_PHI2_Frequency/60 -> Clock_Ip_Get_COREPLL_CLK_Frequency/56 : 
  Jump functions of caller  Clock_Ip_Get_COREPLL_PHI1_Frequency/59:
    callsite  Clock_Ip_Get_COREPLL_PHI1_Frequency/59 -> Clock_Ip_Get_COREPLL_CLK_Frequency/56 : 
  Jump functions of caller  Clock_Ip_Get_COREPLL_PHI0_Frequency/58:
    callsite  Clock_Ip_Get_COREPLL_PHI0_Frequency/58 -> Clock_Ip_Get_COREPLL_CLK_Frequency/56 : 
  Jump functions of caller  Clock_Ip_Get_PERIPHPLL_CLK_Frequency/57:
    callsite  Clock_Ip_Get_PERIPHPLL_CLK_Frequency/57 -> Clock_Ip_PLL_VCO/143 : 
       param 0: CONST: 1074511872B
         value: 0x0, mask: 0xfffffff8
         VR  ~[0, 0]
  Jump functions of caller  Clock_Ip_Get_COREPLL_CLK_Frequency/56:
    callsite  Clock_Ip_Get_COREPLL_CLK_Frequency/56 -> Clock_Ip_PLL_VCO/143 : 
       param 0: CONST: 1141637120B
         value: 0x0, mask: 0xfffffff8
         VR  ~[0, 0]
  Jump functions of caller  Clock_Ip_Get_FXOSC_CLK_Frequency/55:
  Jump functions of caller  Clock_Ip_Get_FIRC_CLK_Frequency/54:
  Jump functions of caller  Clock_Ip_Get_Zero_Frequency/53:

 Propagating constants:

Not considering Clock_Ip_SetExternalSignalFrequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_GetFreq for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_SetExternalOscillatorFrequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_TCLK_CLK_Frequency for cloning; -fipa-cp-clone disabled.
Function Clock_Ip_Get_TMU_CLK_Frequency/141 is not versionable, reason: not a tree_versionable_function.
Function Clock_Ip_Get_STCU_CLK_Frequency/140 is not versionable, reason: not a tree_versionable_function.
Not considering Clock_Ip_Get_SPT_CLK_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_SPI_CLK_Frequency for cloning; -fipa-cp-clone disabled.
Function Clock_Ip_Get_QSPI0_CLK_Frequency/137 is not versionable, reason: not a tree_versionable_function.
Not considering Clock_Ip_Get_QSPI_1X_CLK_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_QSPI_2X_CLK_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_NOC_TRACE_CLK_Frequency for cloning; -fipa-cp-clone disabled.
Function Clock_Ip_Get_MIPICSI2_1_CLK_Frequency/133 is not versionable, reason: not a tree_versionable_function.
Not considering Clock_Ip_Get_MIPICSI2_0_CLK_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_LINFLEXD_CLK_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_LIN_BAUD_CLK_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_LBIST_CLK_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_GMAC1_TX_CLK_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_GMAC1_TS_CLK_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_GMAC1_RX_CLK_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_GMAC0_TX_CLK_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_GMAC0_TS_CLK_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_GMAC0_RX_CLK_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_FTM0_EXT_CLK_Frequency for cloning; -fipa-cp-clone disabled.
Function Clock_Ip_Get_FCCU_IPS_CLK_Frequency/121 is not versionable, reason: not a tree_versionable_function.
Not considering Clock_Ip_Get_DSPI_SCK_TST_CLK_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_DAPB_CLK_Frequency for cloning; -fipa-cp-clone disabled.
Function Clock_Ip_Get_CTU_IPS_CLK_Frequency/118 is not versionable, reason: not a tree_versionable_function.
Not considering Clock_Ip_Get_MC_CLK_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_CSI_TXCLK_CLK_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_CTE_CLK_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_CSI_CFG_CLK_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_CSI_CLK_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_CLKOUT1_CLK_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_CLKOUT0_CLK_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_CAN_PE_CLK_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_CAN_TS_CLK_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_CAN_CHI_CLK_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_BBE32EP_DSP_CLK_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_GMAC1_INT_CLK_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_GMAC_1_INT_REF_CLK_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_GMAC1_REF_DIV_CLK_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_GMAC1_REF_CLK_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_GMAC0_REF_DIV_CLK_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_GMAC0_REF_CLK_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_ACCEL_XBAR_DIV8_CLK_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_ACCEL_XBAR_DIV4_CLK_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_ACCEL_XBAR_DIV2_CLK_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_ACCEL_XBAR_CLK_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_ACCEL_DIV3_CLK_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_ACCEL_CLK_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_A53_CORE_DIV10_CLK_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_A53_CORE_DIV2_CLK_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_A53_CORE_CLK_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_SYS_DIV8_CLK_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_SYS_DIV4_CLK_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_SYS_DIV2_CLK_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_SYS_CLK_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_gmac_1_ext_ts_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_gmac_1_ext_tx_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_gmac_1_ext_rx_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_gmac_1_ext_ref_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_gmac_0_ext_ts_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_gmac_0_ext_tx_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_gmac_0_ext_rx_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_gmac_0_ext_ref_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_ftm_0_ext_ref_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_PERIPHPLL_DFS2_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_PERIPHPLL_DFS1_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_PERIPHPLL_PHI9_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_PERIPHPLL_PHI8_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_PERIPHPLL_PHI7_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_PERIPHPLL_PHI6_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_PERIPHPLL_PHI5_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_PERIPHPLL_PHI4_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_PERIPHPLL_PHI3_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_PERIPHPLL_PHI2_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_PERIPHPLL_PHI1_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_PERIPHPLL_PHI0_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_COREPLL_PHI9_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_COREPLL_PHI8_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_COREPLL_PHI6_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_COREPLL_PHI5_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_COREPLL_PHI4_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_COREPLL_PHI3_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_COREPLL_PHI2_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_COREPLL_PHI1_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_COREPLL_PHI0_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_PERIPHPLL_CLK_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_COREPLL_CLK_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_FXOSC_CLK_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_FIRC_CLK_Frequency for cloning; -fipa-cp-clone disabled.
Not considering Clock_Ip_Get_Zero_Frequency for cloning; -fipa-cp-clone disabled.

overall_size: 1620, max_new_size: 11001
 - context independent values, size: 4, time_benefit: 1.000000
 - context independent values, size: 25, time_benefit: 1.000000
     Decided to specialize for all known contexts, code not going to grow.

IPA lattices after all propagation:

Lattices:
  Node: Clock_Ip_PLL_VCO.part.0/149:
    param [0]: 1074511872B [loc_time: 3, loc_size: 30, prop_time: 0, prop_size: 0]
               1141637120B [loc_time: 3, loc_size: 32, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffff8
         const struct PLLDIG_Type * ~[0B, 0B]
        AGGS VARIABLE
  Node: Clock_Ip_SetExternalSignalFrequency/147:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Clock_Ip_GetFreq/146:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Clock_Ip_SetExternalOscillatorFrequency/145:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [1]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Clock_Ip_DFS_OUTPUT/144:
    param [0]: 1074528256B [loc_time: 0, loc_size: 0, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffff8
         const struct DFS_Type * [1074528256B, 1074528256B]
        AGGS VARIABLE
    param [1]: 0 [loc_time: 2, loc_size: 27, prop_time: 0, prop_size: 0]
               1 [loc_time: 2, loc_size: 27, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x1, mask = 0x1
         uint32 [0, 1]
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: Clock_Ip_PLL_VCO/143:
    param [0]: 1141637120B [loc_time: 1, loc_size: 9, prop_time: 0, prop_size: 0]
               1074511872B [loc_time: 1, loc_size: 9, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffff8
         const struct PLLDIG_Type * [1074511872B, 1141637120B]
        AGGS VARIABLE
  Node: Clock_Ip_Get_TCLK_CLK_Frequency/142:
  Node: Clock_Ip_Get_TMU_CLK_Frequency/141:
  Node: Clock_Ip_Get_STCU_CLK_Frequency/140:
  Node: Clock_Ip_Get_SPT_CLK_Frequency/139:
  Node: Clock_Ip_Get_SPI_CLK_Frequency/138:
  Node: Clock_Ip_Get_QSPI0_CLK_Frequency/137:
  Node: Clock_Ip_Get_QSPI_1X_CLK_Frequency/136:
  Node: Clock_Ip_Get_QSPI_2X_CLK_Frequency/135:
  Node: Clock_Ip_Get_NOC_TRACE_CLK_Frequency/134:
  Node: Clock_Ip_Get_MIPICSI2_1_CLK_Frequency/133:
  Node: Clock_Ip_Get_MIPICSI2_0_CLK_Frequency/132:
  Node: Clock_Ip_Get_LINFLEXD_CLK_Frequency/131:
  Node: Clock_Ip_Get_LIN_BAUD_CLK_Frequency/130:
  Node: Clock_Ip_Get_LBIST_CLK_Frequency/129:
  Node: Clock_Ip_Get_GMAC1_TX_CLK_Frequency/128:
  Node: Clock_Ip_Get_GMAC1_TS_CLK_Frequency/127:
  Node: Clock_Ip_Get_GMAC1_RX_CLK_Frequency/126:
  Node: Clock_Ip_Get_GMAC0_TX_CLK_Frequency/125:
  Node: Clock_Ip_Get_GMAC0_TS_CLK_Frequency/124:
  Node: Clock_Ip_Get_GMAC0_RX_CLK_Frequency/123:
  Node: Clock_Ip_Get_FTM0_EXT_CLK_Frequency/122:
  Node: Clock_Ip_Get_FCCU_IPS_CLK_Frequency/121:
  Node: Clock_Ip_Get_DSPI_SCK_TST_CLK_Frequency/120:
  Node: Clock_Ip_Get_DAPB_CLK_Frequency/119:
  Node: Clock_Ip_Get_CTU_IPS_CLK_Frequency/118:
  Node: Clock_Ip_Get_MC_CLK_Frequency/117:
  Node: Clock_Ip_Get_CSI_TXCLK_CLK_Frequency/116:
  Node: Clock_Ip_Get_CTE_CLK_Frequency/115:
  Node: Clock_Ip_Get_CSI_CFG_CLK_Frequency/114:
  Node: Clock_Ip_Get_CSI_CLK_Frequency/113:
  Node: Clock_Ip_Get_CLKOUT1_CLK_Frequency/112:
  Node: Clock_Ip_Get_CLKOUT0_CLK_Frequency/111:
  Node: Clock_Ip_Get_CAN_PE_CLK_Frequency/110:
  Node: Clock_Ip_Get_CAN_TS_CLK_Frequency/109:
  Node: Clock_Ip_Get_CAN_CHI_CLK_Frequency/108:
  Node: Clock_Ip_Get_BBE32EP_DSP_CLK_Frequency/107:
  Node: Clock_Ip_Get_GMAC1_INT_CLK_Frequency/106:
  Node: Clock_Ip_Get_GMAC_1_INT_REF_CLK_Frequency/105:
  Node: Clock_Ip_Get_GMAC1_REF_DIV_CLK_Frequency/104:
  Node: Clock_Ip_Get_GMAC1_REF_CLK_Frequency/103:
  Node: Clock_Ip_Get_GMAC0_REF_DIV_CLK_Frequency/102:
  Node: Clock_Ip_Get_GMAC0_REF_CLK_Frequency/101:
  Node: Clock_Ip_Get_ACCEL_XBAR_DIV8_CLK_Frequency/100:
  Node: Clock_Ip_Get_ACCEL_XBAR_DIV4_CLK_Frequency/99:
  Node: Clock_Ip_Get_ACCEL_XBAR_DIV2_CLK_Frequency/98:
  Node: Clock_Ip_Get_ACCEL_XBAR_CLK_Frequency/97:
  Node: Clock_Ip_Get_ACCEL_DIV3_CLK_Frequency/96:
  Node: Clock_Ip_Get_ACCEL_CLK_Frequency/95:
  Node: Clock_Ip_Get_A53_CORE_DIV10_CLK_Frequency/94:
  Node: Clock_Ip_Get_A53_CORE_DIV2_CLK_Frequency/93:
  Node: Clock_Ip_Get_A53_CORE_CLK_Frequency/92:
  Node: Clock_Ip_Get_SYS_DIV8_CLK_Frequency/91:
  Node: Clock_Ip_Get_SYS_DIV4_CLK_Frequency/90:
  Node: Clock_Ip_Get_SYS_DIV2_CLK_Frequency/89:
  Node: Clock_Ip_Get_SYS_CLK_Frequency/88:
  Node: Clock_Ip_Get_gmac_1_ext_ts_Frequency/87:
  Node: Clock_Ip_Get_gmac_1_ext_tx_Frequency/86:
  Node: Clock_Ip_Get_gmac_1_ext_rx_Frequency/85:
  Node: Clock_Ip_Get_gmac_1_ext_ref_Frequency/84:
  Node: Clock_Ip_Get_gmac_0_ext_ts_Frequency/83:
  Node: Clock_Ip_Get_gmac_0_ext_tx_Frequency/82:
  Node: Clock_Ip_Get_gmac_0_ext_rx_Frequency/81:
  Node: Clock_Ip_Get_gmac_0_ext_ref_Frequency/80:
  Node: Clock_Ip_Get_ftm_0_ext_ref_Frequency/79:
  Node: Clock_Ip_Get_PERIPHPLL_DFS2_Frequency/78:
  Node: Clock_Ip_Get_PERIPHPLL_DFS1_Frequency/77:
  Node: Clock_Ip_Get_PERIPHPLL_PHI9_Frequency/76:
  Node: Clock_Ip_Get_PERIPHPLL_PHI8_Frequency/75:
  Node: Clock_Ip_Get_PERIPHPLL_PHI7_Frequency/74:
  Node: Clock_Ip_Get_PERIPHPLL_PHI6_Frequency/73:
  Node: Clock_Ip_Get_PERIPHPLL_PHI5_Frequency/72:
  Node: Clock_Ip_Get_PERIPHPLL_PHI4_Frequency/71:
  Node: Clock_Ip_Get_PERIPHPLL_PHI3_Frequency/70:
  Node: Clock_Ip_Get_PERIPHPLL_PHI2_Frequency/69:
  Node: Clock_Ip_Get_PERIPHPLL_PHI1_Frequency/68:
  Node: Clock_Ip_Get_PERIPHPLL_PHI0_Frequency/67:
  Node: Clock_Ip_Get_COREPLL_PHI9_Frequency/66:
  Node: Clock_Ip_Get_COREPLL_PHI8_Frequency/65:
  Node: Clock_Ip_Get_COREPLL_PHI6_Frequency/64:
  Node: Clock_Ip_Get_COREPLL_PHI5_Frequency/63:
  Node: Clock_Ip_Get_COREPLL_PHI4_Frequency/62:
  Node: Clock_Ip_Get_COREPLL_PHI3_Frequency/61:
  Node: Clock_Ip_Get_COREPLL_PHI2_Frequency/60:
  Node: Clock_Ip_Get_COREPLL_PHI1_Frequency/59:
  Node: Clock_Ip_Get_COREPLL_PHI0_Frequency/58:
  Node: Clock_Ip_Get_PERIPHPLL_CLK_Frequency/57:
  Node: Clock_Ip_Get_COREPLL_CLK_Frequency/56:
  Node: Clock_Ip_Get_FXOSC_CLK_Frequency/55:
  Node: Clock_Ip_Get_FIRC_CLK_Frequency/54:
  Node: Clock_Ip_Get_Zero_Frequency/53:

IPA decision stage:

 - Creating a specialized node of Clock_Ip_DFS_OUTPUT/144 for all known contexts.
    replacing param #0 Base with const 1074528256B
Propagated bits info for function Clock_Ip_DFS_OUTPUT.constprop/151:
 param 0: value = 0x0, mask = 0xfffffff8
 param 1: value = 0x1, mask = 0x1
Propagated bits info for function Clock_Ip_PLL_VCO.part.0/149:
 param 0: value = 0x0, mask = 0xfffffff8
Propagated bits info for function Clock_Ip_DFS_OUTPUT/144:
 param 0: value = 0x0, mask = 0xfffffff8
 param 1: value = 0x1, mask = 0x1
Propagated bits info for function Clock_Ip_PLL_VCO/143:
 param 0: value = 0x0, mask = 0xfffffff8

IPA constant propagation end

Reclaiming functions: Clock_Ip_DFS_OUTPUT/144
Reclaiming variables:
Clearing address taken flags:
Symbol table:

Clock_Ip_DFS_OUTPUT.constprop.0/151 (Clock_Ip_DFS_OUTPUT.constprop) @0660e700
  Type: function definition analyzed
  Visibility:
  References: 
  Referring: 
  Clone of Clock_Ip_DFS_OUTPUT/144
  Availability: local
  Function flags: count:1073741824 (estimated locally) local optimize_size
  Called by: Clock_Ip_Get_PERIPHPLL_DFS2_Frequency/78 (524845004 (estimated locally),0.49 per call) Clock_Ip_Get_PERIPHPLL_DFS1_Frequency/77 (524845004 (estimated locally),0.49 per call) 
  Calls: 
Clock_Ip_PLL_VCO.part.0/149 (Clock_Ip_PLL_VCO.part.0) @066ac540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: Clock_Ip_PLL_VCO/143 (633507680 (estimated locally),0.59 per call) 
  Calls: Clock_Ip_Get_FXOSC_CLK_Frequency/55 (354334802 (estimated locally),0.33 per call) 
Clock_Ip_SetExternalSignalFrequency/147 (Clock_Ip_SetExternalSignalFrequency) @062d87e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Clock_Ip_axExtSignalFreqEntries/5 (read)Clock_Ip_axExtSignalFreqEntries/5 (write)
  Referring: 
  Availability: available
  Function flags: count:122473676 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Clock_Ip_GetFreq/146 (Clock_Ip_GetFreq) @062d8540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Clock_Ip_apfFreqTable/4 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call) 
Clock_Ip_SetExternalOscillatorFrequency/145 (Clock_Ip_SetExternalOscillatorFrequency) @062d82a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Clock_Ip_u32Fxosc/6 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Clock_Ip_DFS_OUTPUT/144 (Clock_Ip_DFS_OUTPUT) @062d8000
  Type: function
  Body removed by symtab_remove_unreachable_nodes
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: not_available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Clock_Ip_PLL_VCO/143 (Clock_Ip_PLL_VCO) @0652eb60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Clock_Ip_Get_COREPLL_CLK_Frequency/56 (524845004 (estimated locally),0.49 per call) Clock_Ip_Get_PERIPHPLL_CLK_Frequency/57 (524845004 (estimated locally),0.49 per call) 
  Calls: Clock_Ip_PLL_VCO.part.0/149 (633507680 (estimated locally),0.59 per call) 
Clock_Ip_Get_TCLK_CLK_Frequency/142 (Clock_Ip_Get_TCLK_CLK_Frequency) @0652e620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_apfFreqTableClkSrc/3 (read)Clock_Ip_u32EnableDivider/0 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call) 
Clock_Ip_Get_TMU_CLK_Frequency/141 (Clock_Ip_Get_TMU_CLK_Frequency) @0652e0e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: Clock_Ip_apfFreqTable/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: 
  Calls: Clock_Ip_Get_CAN_CHI_CLK_Frequency/108 (1073741824 (estimated locally),1.00 per call) 
Clock_Ip_Get_STCU_CLK_Frequency/140 (Clock_Ip_Get_STCU_CLK_Frequency) @0652ed20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: Clock_Ip_apfFreqTable/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: 
  Calls: Clock_Ip_Get_DAPB_CLK_Frequency/119 (1073741824 (estimated locally),1.00 per call) 
Clock_Ip_Get_SPT_CLK_Frequency/139 (Clock_Ip_Get_SPT_CLK_Frequency) @0652ea80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_apfFreqTableClkSrc/3 (read)Clock_Ip_u32EnableGate/1 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call) 
Clock_Ip_Get_SPI_CLK_Frequency/138 (Clock_Ip_Get_SPI_CLK_Frequency) @0652e7e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_apfFreqTableClkSrc/3 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call) 
Clock_Ip_Get_QSPI0_CLK_Frequency/137 (Clock_Ip_Get_QSPI0_CLK_Frequency) @0652e540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: Clock_Ip_apfFreqTable/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: 
  Calls: Clock_Ip_Get_QSPI_2X_CLK_Frequency/135 (1073741824 (estimated locally),1.00 per call) 
Clock_Ip_Get_QSPI_1X_CLK_Frequency/136 (Clock_Ip_Get_QSPI_1X_CLK_Frequency) @0652e2a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: Clock_Ip_apfFreqTable/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Clock_Ip_Get_QSPI_2X_CLK_Frequency/135 (1073741824 (estimated locally),1.00 per call) 
Clock_Ip_Get_QSPI_2X_CLK_Frequency/135 (Clock_Ip_Get_QSPI_2X_CLK_Frequency) @0652e000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_apfFreqTableClkSrc/3 (read)Clock_Ip_u32EnableDivider/0 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: Clock_Ip_Get_QSPI0_CLK_Frequency/137 (1073741824 (estimated locally),1.00 per call) Clock_Ip_Get_QSPI_1X_CLK_Frequency/136 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call) 
Clock_Ip_Get_NOC_TRACE_CLK_Frequency/134 (Clock_Ip_Get_NOC_TRACE_CLK_Frequency) @06525b60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_apfFreqTableClkSrc/3 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call) 
Clock_Ip_Get_MIPICSI2_1_CLK_Frequency/133 (Clock_Ip_Get_MIPICSI2_1_CLK_Frequency) @06525620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: Clock_Ip_apfFreqTable/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: 
  Calls: Clock_Ip_Get_MIPICSI2_0_CLK_Frequency/132 (1073741824 (estimated locally),1.00 per call) 
Clock_Ip_Get_MIPICSI2_0_CLK_Frequency/132 (Clock_Ip_Get_MIPICSI2_0_CLK_Frequency) @065250e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_apfFreqTableClkSrc/3 (read)Clock_Ip_u32EnableGate/1 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: Clock_Ip_Get_MIPICSI2_1_CLK_Frequency/133 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call) 
Clock_Ip_Get_LINFLEXD_CLK_Frequency/131 (Clock_Ip_Get_LINFLEXD_CLK_Frequency) @06525d20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: Clock_Ip_apfFreqTable/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Clock_Ip_Get_LIN_BAUD_CLK_Frequency/130 (1073741824 (estimated locally),1.00 per call) 
Clock_Ip_Get_LIN_BAUD_CLK_Frequency/130 (Clock_Ip_Get_LIN_BAUD_CLK_Frequency) @06525a80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_apfFreqTableClkSrc/3 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: Clock_Ip_Get_LINFLEXD_CLK_Frequency/131 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call) 
Clock_Ip_Get_LBIST_CLK_Frequency/129 (Clock_Ip_Get_LBIST_CLK_Frequency) @065257e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_apfFreqTableClkSrc/3 (read)Clock_Ip_u32EnableDivider/0 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call) 
Clock_Ip_Get_GMAC1_TX_CLK_Frequency/128 (Clock_Ip_Get_GMAC1_TX_CLK_Frequency) @06525540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_apfFreqTableClkSrc/3 (read)Clock_Ip_u32EnableDivider/0 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call) 
Clock_Ip_Get_GMAC1_TS_CLK_Frequency/127 (Clock_Ip_Get_GMAC1_TS_CLK_Frequency) @065252a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_apfFreqTableClkSrc/3 (read)Clock_Ip_u32EnableDivider/0 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call) 
Clock_Ip_Get_GMAC1_RX_CLK_Frequency/126 (Clock_Ip_Get_GMAC1_RX_CLK_Frequency) @06525000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_apfFreqTableClkSrc/3 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call) 
Clock_Ip_Get_GMAC0_TX_CLK_Frequency/125 (Clock_Ip_Get_GMAC0_TX_CLK_Frequency) @0651eb60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_apfFreqTableClkSrc/3 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call) 
Clock_Ip_Get_GMAC0_TS_CLK_Frequency/124 (Clock_Ip_Get_GMAC0_TS_CLK_Frequency) @0651e620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_apfFreqTableClkSrc/3 (read)Clock_Ip_u32EnableDivider/0 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call) 
Clock_Ip_Get_GMAC0_RX_CLK_Frequency/123 (Clock_Ip_Get_GMAC0_RX_CLK_Frequency) @0651e0e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_apfFreqTableClkSrc/3 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call) 
Clock_Ip_Get_FTM0_EXT_CLK_Frequency/122 (Clock_Ip_Get_FTM0_EXT_CLK_Frequency) @0651ed20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_apfFreqTableClkSrc/3 (read)Clock_Ip_u32EnableDivider/0 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call) 
Clock_Ip_Get_FCCU_IPS_CLK_Frequency/121 (Clock_Ip_Get_FCCU_IPS_CLK_Frequency) @0651ea80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: Clock_Ip_apfFreqTable/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: 
  Calls: Clock_Ip_Get_CAN_CHI_CLK_Frequency/108 (1073741824 (estimated locally),1.00 per call) 
Clock_Ip_Get_DSPI_SCK_TST_CLK_Frequency/120 (Clock_Ip_Get_DSPI_SCK_TST_CLK_Frequency) @0651e7e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_apfFreqTableClkSrc/3 (read)Clock_Ip_u32EnableDivider/0 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call) 
Clock_Ip_Get_DAPB_CLK_Frequency/119 (Clock_Ip_Get_DAPB_CLK_Frequency) @0651e540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_apfFreqTableClkSrc/3 (read)Clock_Ip_u32EnableDivider/0 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: Clock_Ip_Get_STCU_CLK_Frequency/140 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call) 
Clock_Ip_Get_CTU_IPS_CLK_Frequency/118 (Clock_Ip_Get_CTU_IPS_CLK_Frequency) @0651e2a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: Clock_Ip_apfFreqTable/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: 
  Calls: Clock_Ip_Get_CAN_CHI_CLK_Frequency/108 (1073741824 (estimated locally),1.00 per call) 
Clock_Ip_Get_MC_CLK_Frequency/117 (Clock_Ip_Get_MC_CLK_Frequency) @0651e000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_apfFreqTableClkSrc/3 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call) 
Clock_Ip_Get_CSI_TXCLK_CLK_Frequency/116 (Clock_Ip_Get_CSI_TXCLK_CLK_Frequency) @06516b60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_apfFreqTableClkSrc/3 (read)Clock_Ip_u32EnableDivider/0 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call) 
Clock_Ip_Get_CTE_CLK_Frequency/115 (Clock_Ip_Get_CTE_CLK_Frequency) @06516620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_apfFreqTableClkSrc/3 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call) 
Clock_Ip_Get_CSI_CFG_CLK_Frequency/114 (Clock_Ip_Get_CSI_CFG_CLK_Frequency) @065160e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_apfFreqTableClkSrc/3 (read)Clock_Ip_u32EnableDivider/0 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call) 
Clock_Ip_Get_CSI_CLK_Frequency/113 (Clock_Ip_Get_CSI_CLK_Frequency) @06516d20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_apfFreqTableClkSrc/3 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call) 
Clock_Ip_Get_CLKOUT1_CLK_Frequency/112 (Clock_Ip_Get_CLKOUT1_CLK_Frequency) @06516a80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_apfFreqTableClkSrc/3 (read)Clock_Ip_u32EnableDivider/0 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call) 
Clock_Ip_Get_CLKOUT0_CLK_Frequency/111 (Clock_Ip_Get_CLKOUT0_CLK_Frequency) @065167e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_apfFreqTableClkSrc/3 (read)Clock_Ip_u32EnableDivider/0 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call) 
Clock_Ip_Get_CAN_PE_CLK_Frequency/110 (Clock_Ip_Get_CAN_PE_CLK_Frequency) @06516540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_apfFreqTableClkSrc/3 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call) 
Clock_Ip_Get_CAN_TS_CLK_Frequency/109 (Clock_Ip_Get_CAN_TS_CLK_Frequency) @065162a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_apfFreqTableClkSrc/3 (read)Clock_Ip_u32EnableDivider/0 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call) 
Clock_Ip_Get_CAN_CHI_CLK_Frequency/108 (Clock_Ip_Get_CAN_CHI_CLK_Frequency) @06516000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_apfFreqTableClkSrc/3 (read)Clock_Ip_u32EnableDivider/0 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body icf_merged optimize_size
  Called by: Clock_Ip_Get_TMU_CLK_Frequency/141 (1073741824 (estimated locally),1.00 per call) Clock_Ip_Get_FCCU_IPS_CLK_Frequency/121 (1073741824 (estimated locally),1.00 per call) Clock_Ip_Get_CTU_IPS_CLK_Frequency/118 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call) 
Clock_Ip_Get_BBE32EP_DSP_CLK_Frequency/107 (Clock_Ip_Get_BBE32EP_DSP_CLK_Frequency) @0650db60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_apfFreqTableClkSrc/3 (read)Clock_Ip_u32EnableGate/1 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call) 
Clock_Ip_Get_GMAC1_INT_CLK_Frequency/106 (Clock_Ip_Get_GMAC1_INT_CLK_Frequency) @0650d620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_apfTableClockGeneration/2 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call) 
Clock_Ip_Get_GMAC_1_INT_REF_CLK_Frequency/105 (Clock_Ip_Get_GMAC_1_INT_REF_CLK_Frequency) @0650d0e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Clock_Ip_Get_PERIPHPLL_PHI5_Frequency/72 (217325345 (estimated locally),0.20 per call) 
Clock_Ip_Get_GMAC1_REF_DIV_CLK_Frequency/104 (Clock_Ip_Get_GMAC1_REF_DIV_CLK_Frequency) @0650dd20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_apfTableClockGeneration/2 (read)Clock_Ip_u32EnableDivider/0 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call) 
Clock_Ip_Get_GMAC1_REF_CLK_Frequency/103 (Clock_Ip_Get_GMAC1_REF_CLK_Frequency) @0650da80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_apfFreqTableClkSrc/3 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call) 
Clock_Ip_Get_GMAC0_REF_DIV_CLK_Frequency/102 (Clock_Ip_Get_GMAC0_REF_DIV_CLK_Frequency) @0650d7e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_apfTableClockGeneration/2 (read)Clock_Ip_u32EnableDivider/0 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call) 
Clock_Ip_Get_GMAC0_REF_CLK_Frequency/101 (Clock_Ip_Get_GMAC0_REF_CLK_Frequency) @0650d540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_apfFreqTableClkSrc/3 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call) 
Clock_Ip_Get_ACCEL_XBAR_DIV8_CLK_Frequency/100 (Clock_Ip_Get_ACCEL_XBAR_DIV8_CLK_Frequency) @0650d2a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Clock_Ip_Get_ACCEL_XBAR_CLK_Frequency/97 (1073741824 (estimated locally),1.00 per call) 
Clock_Ip_Get_ACCEL_XBAR_DIV4_CLK_Frequency/99 (Clock_Ip_Get_ACCEL_XBAR_DIV4_CLK_Frequency) @0650d000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Clock_Ip_Get_ACCEL_XBAR_CLK_Frequency/97 (1073741824 (estimated locally),1.00 per call) 
Clock_Ip_Get_ACCEL_XBAR_DIV2_CLK_Frequency/98 (Clock_Ip_Get_ACCEL_XBAR_DIV2_CLK_Frequency) @0650bb60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: Clock_Ip_apfFreqTable/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Clock_Ip_Get_ACCEL_XBAR_CLK_Frequency/97 (1073741824 (estimated locally),1.00 per call) 
Clock_Ip_Get_ACCEL_XBAR_CLK_Frequency/97 (Clock_Ip_Get_ACCEL_XBAR_CLK_Frequency) @0650b620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_apfFreqTableClkSrc/3 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: Clock_Ip_Get_ACCEL_XBAR_DIV8_CLK_Frequency/100 (1073741824 (estimated locally),1.00 per call) Clock_Ip_Get_ACCEL_XBAR_DIV4_CLK_Frequency/99 (1073741824 (estimated locally),1.00 per call) Clock_Ip_Get_ACCEL_XBAR_DIV2_CLK_Frequency/98 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call) 
Clock_Ip_Get_ACCEL_DIV3_CLK_Frequency/96 (Clock_Ip_Get_ACCEL_DIV3_CLK_Frequency) @0650b0e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: Clock_Ip_apfFreqTable/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Clock_Ip_Get_ACCEL_CLK_Frequency/95 (1073741824 (estimated locally),1.00 per call) 
Clock_Ip_Get_ACCEL_CLK_Frequency/95 (Clock_Ip_Get_ACCEL_CLK_Frequency) @0650bd20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_apfFreqTableClkSrc/3 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: Clock_Ip_Get_ACCEL_DIV3_CLK_Frequency/96 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call) 
Clock_Ip_Get_A53_CORE_DIV10_CLK_Frequency/94 (Clock_Ip_Get_A53_CORE_DIV10_CLK_Frequency) @0650ba80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: Clock_Ip_apfFreqTable/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Clock_Ip_Get_A53_CORE_CLK_Frequency/92 (1073741824 (estimated locally),1.00 per call) 
Clock_Ip_Get_A53_CORE_DIV2_CLK_Frequency/93 (Clock_Ip_Get_A53_CORE_DIV2_CLK_Frequency) @0650b7e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: Clock_Ip_apfFreqTable/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Clock_Ip_Get_A53_CORE_CLK_Frequency/92 (1073741824 (estimated locally),1.00 per call) 
Clock_Ip_Get_A53_CORE_CLK_Frequency/92 (Clock_Ip_Get_A53_CORE_CLK_Frequency) @0650b540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_apfFreqTableClkSrc/3 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: Clock_Ip_Get_A53_CORE_DIV10_CLK_Frequency/94 (1073741824 (estimated locally),1.00 per call) Clock_Ip_Get_A53_CORE_DIV2_CLK_Frequency/93 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call) 
Clock_Ip_Get_SYS_DIV8_CLK_Frequency/91 (Clock_Ip_Get_SYS_DIV8_CLK_Frequency) @0650b2a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Clock_Ip_Get_SYS_CLK_Frequency/88 (1073741824 (estimated locally),1.00 per call) 
Clock_Ip_Get_SYS_DIV4_CLK_Frequency/90 (Clock_Ip_Get_SYS_DIV4_CLK_Frequency) @0650b000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Clock_Ip_Get_SYS_CLK_Frequency/88 (1073741824 (estimated locally),1.00 per call) 
Clock_Ip_Get_SYS_DIV2_CLK_Frequency/89 (Clock_Ip_Get_SYS_DIV2_CLK_Frequency) @06508b60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Clock_Ip_Get_SYS_CLK_Frequency/88 (1073741824 (estimated locally),1.00 per call) 
Clock_Ip_Get_SYS_CLK_Frequency/88 (Clock_Ip_Get_SYS_CLK_Frequency) @06508620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_apfFreqTableClkSrc/3 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: Clock_Ip_Get_SYS_DIV8_CLK_Frequency/91 (1073741824 (estimated locally),1.00 per call) Clock_Ip_Get_SYS_DIV4_CLK_Frequency/90 (1073741824 (estimated locally),1.00 per call) Clock_Ip_Get_SYS_DIV2_CLK_Frequency/89 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
   Indirect call(1073741824 (estimated locally),1.00 per call) 
Clock_Ip_Get_gmac_1_ext_ts_Frequency/87 (Clock_Ip_Get_gmac_1_ext_ts_Frequency) @065080e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_axExtSignalFreqEntries/5 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Clock_Ip_Get_gmac_1_ext_tx_Frequency/86 (Clock_Ip_Get_gmac_1_ext_tx_Frequency) @06508d20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_axExtSignalFreqEntries/5 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Clock_Ip_Get_gmac_1_ext_rx_Frequency/85 (Clock_Ip_Get_gmac_1_ext_rx_Frequency) @06508a80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_axExtSignalFreqEntries/5 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Clock_Ip_Get_gmac_1_ext_ref_Frequency/84 (Clock_Ip_Get_gmac_1_ext_ref_Frequency) @065087e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_axExtSignalFreqEntries/5 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Clock_Ip_Get_gmac_0_ext_ts_Frequency/83 (Clock_Ip_Get_gmac_0_ext_ts_Frequency) @06508540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_axExtSignalFreqEntries/5 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Clock_Ip_Get_gmac_0_ext_tx_Frequency/82 (Clock_Ip_Get_gmac_0_ext_tx_Frequency) @065082a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_axExtSignalFreqEntries/5 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Clock_Ip_Get_gmac_0_ext_rx_Frequency/81 (Clock_Ip_Get_gmac_0_ext_rx_Frequency) @06508000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_axExtSignalFreqEntries/5 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Clock_Ip_Get_gmac_0_ext_ref_Frequency/80 (Clock_Ip_Get_gmac_0_ext_ref_Frequency) @064fbb60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_axExtSignalFreqEntries/5 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Clock_Ip_Get_ftm_0_ext_ref_Frequency/79 (Clock_Ip_Get_ftm_0_ext_ref_Frequency) @064fb620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_axExtSignalFreqEntries/5 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Clock_Ip_Get_PERIPHPLL_DFS2_Frequency/78 (Clock_Ip_Get_PERIPHPLL_DFS2_Frequency) @064fb0e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_u32PeriphDfs2Checksum/52 (read)Clock_Ip_u32PeriphDfs2Checksum/52 (write)Clock_Ip_u32PeriphDfs2Freq/51 (write)Clock_Ip_u32PeriphDfs2Freq/51 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Clock_Ip_DFS_OUTPUT.constprop/151 (524845004 (estimated locally),0.49 per call) Clock_Ip_Get_PERIPHPLL_CLK_Frequency/57 (524845004 (estimated locally),0.49 per call) 
Clock_Ip_Get_PERIPHPLL_DFS1_Frequency/77 (Clock_Ip_Get_PERIPHPLL_DFS1_Frequency) @064fbd20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_u32PeriphDfs1Checksum/50 (read)Clock_Ip_u32PeriphDfs1Checksum/50 (write)Clock_Ip_u32PeriphDfs1Freq/49 (write)Clock_Ip_u32PeriphDfs1Freq/49 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Clock_Ip_DFS_OUTPUT.constprop/151 (524845004 (estimated locally),0.49 per call) Clock_Ip_Get_PERIPHPLL_CLK_Frequency/57 (524845004 (estimated locally),0.49 per call) 
Clock_Ip_Get_PERIPHPLL_PHI9_Frequency/76 (Clock_Ip_Get_PERIPHPLL_PHI9_Frequency) @064fba80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_u32PeriphPhi9Checksum/48 (read)Clock_Ip_u32PeriphPhi9Checksum/48 (write)Clock_Ip_u32EnableDivider/0 (read)Clock_Ip_u32PeriphPhi9Freq/47 (write)Clock_Ip_u32PeriphPhi9Freq/47 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Clock_Ip_Get_PERIPHPLL_CLK_Frequency/57 (524845004 (estimated locally),0.49 per call) 
Clock_Ip_Get_PERIPHPLL_PHI8_Frequency/75 (Clock_Ip_Get_PERIPHPLL_PHI8_Frequency) @064fb7e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_u32PeriphPhi8Checksum/46 (read)Clock_Ip_u32PeriphPhi8Checksum/46 (write)Clock_Ip_u32EnableDivider/0 (read)Clock_Ip_u32PeriphPhi8Freq/45 (write)Clock_Ip_u32PeriphPhi8Freq/45 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Clock_Ip_Get_PERIPHPLL_CLK_Frequency/57 (524845004 (estimated locally),0.49 per call) 
Clock_Ip_Get_PERIPHPLL_PHI7_Frequency/74 (Clock_Ip_Get_PERIPHPLL_PHI7_Frequency) @064fb540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_u32PeriphPhi7Checksum/44 (read)Clock_Ip_u32PeriphPhi7Checksum/44 (write)Clock_Ip_u32EnableDivider/0 (read)Clock_Ip_u32PeriphPhi7Freq/43 (write)Clock_Ip_u32PeriphPhi7Freq/43 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Clock_Ip_Get_PERIPHPLL_CLK_Frequency/57 (524845004 (estimated locally),0.49 per call) 
Clock_Ip_Get_PERIPHPLL_PHI6_Frequency/73 (Clock_Ip_Get_PERIPHPLL_PHI6_Frequency) @064fb2a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_u32PeriphPhi6Checksum/42 (read)Clock_Ip_u32PeriphPhi6Checksum/42 (write)Clock_Ip_u32EnableDivider/0 (read)Clock_Ip_u32PeriphPhi6Freq/41 (write)Clock_Ip_u32PeriphPhi6Freq/41 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Clock_Ip_Get_PERIPHPLL_CLK_Frequency/57 (524845004 (estimated locally),0.49 per call) 
Clock_Ip_Get_PERIPHPLL_PHI5_Frequency/72 (Clock_Ip_Get_PERIPHPLL_PHI5_Frequency) @064fb000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_u32PeriphPhi5Checksum/40 (read)Clock_Ip_u32PeriphPhi5Checksum/40 (write)Clock_Ip_u32EnableDivider/0 (read)Clock_Ip_u32PeriphPhi5Freq/39 (write)Clock_Ip_u32PeriphPhi5Freq/39 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: Clock_Ip_Get_GMAC_1_INT_REF_CLK_Frequency/105 (217325345 (estimated locally),0.20 per call) 
  Calls: Clock_Ip_Get_PERIPHPLL_CLK_Frequency/57 (524845004 (estimated locally),0.49 per call) 
Clock_Ip_Get_PERIPHPLL_PHI4_Frequency/71 (Clock_Ip_Get_PERIPHPLL_PHI4_Frequency) @06456b60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_u32PeriphPhi4Checksum/38 (read)Clock_Ip_u32PeriphPhi4Checksum/38 (write)Clock_Ip_u32EnableDivider/0 (read)Clock_Ip_u32PeriphPhi4Freq/37 (write)Clock_Ip_u32PeriphPhi4Freq/37 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Clock_Ip_Get_PERIPHPLL_CLK_Frequency/57 (524845004 (estimated locally),0.49 per call) 
Clock_Ip_Get_PERIPHPLL_PHI3_Frequency/70 (Clock_Ip_Get_PERIPHPLL_PHI3_Frequency) @06456620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_u32PeriphPhi3Checksum/36 (read)Clock_Ip_u32PeriphPhi3Checksum/36 (write)Clock_Ip_u32EnableDivider/0 (read)Clock_Ip_u32PeriphPhi3Freq/35 (write)Clock_Ip_u32PeriphPhi3Freq/35 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Clock_Ip_Get_PERIPHPLL_CLK_Frequency/57 (524845004 (estimated locally),0.49 per call) 
Clock_Ip_Get_PERIPHPLL_PHI2_Frequency/69 (Clock_Ip_Get_PERIPHPLL_PHI2_Frequency) @064560e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_u32PeriphPhi2Checksum/34 (read)Clock_Ip_u32PeriphPhi2Checksum/34 (write)Clock_Ip_u32EnableDivider/0 (read)Clock_Ip_u32PeriphPhi2Freq/33 (write)Clock_Ip_u32PeriphPhi2Freq/33 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Clock_Ip_Get_PERIPHPLL_CLK_Frequency/57 (524845004 (estimated locally),0.49 per call) 
Clock_Ip_Get_PERIPHPLL_PHI1_Frequency/68 (Clock_Ip_Get_PERIPHPLL_PHI1_Frequency) @06456d20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_u32PeriphPhi1Checksum/32 (read)Clock_Ip_u32PeriphPhi1Checksum/32 (write)Clock_Ip_u32EnableDivider/0 (read)Clock_Ip_u32PeriphPhi1Freq/31 (write)Clock_Ip_u32PeriphPhi1Freq/31 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Clock_Ip_Get_PERIPHPLL_CLK_Frequency/57 (524845004 (estimated locally),0.49 per call) 
Clock_Ip_Get_PERIPHPLL_PHI0_Frequency/67 (Clock_Ip_Get_PERIPHPLL_PHI0_Frequency) @06456a80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_u32PeriphPhi0Checksum/30 (read)Clock_Ip_u32PeriphPhi0Checksum/30 (write)Clock_Ip_u32EnableDivider/0 (read)Clock_Ip_u32PeriphPhi0Freq/29 (write)Clock_Ip_u32PeriphPhi0Freq/29 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Clock_Ip_Get_PERIPHPLL_CLK_Frequency/57 (524845004 (estimated locally),0.49 per call) 
Clock_Ip_Get_COREPLL_PHI9_Frequency/66 (Clock_Ip_Get_COREPLL_PHI9_Frequency) @064567e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_u32CorePhi9Checksum/28 (read)Clock_Ip_u32CorePhi9Checksum/28 (write)Clock_Ip_u32EnableDivider/0 (read)Clock_Ip_u32CorePhi9Freq/27 (write)Clock_Ip_u32CorePhi9Freq/27 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Clock_Ip_Get_COREPLL_CLK_Frequency/56 (524845004 (estimated locally),0.49 per call) 
Clock_Ip_Get_COREPLL_PHI8_Frequency/65 (Clock_Ip_Get_COREPLL_PHI8_Frequency) @06456540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_u32CorePhi8Checksum/26 (read)Clock_Ip_u32CorePhi8Checksum/26 (write)Clock_Ip_u32EnableDivider/0 (read)Clock_Ip_u32CorePhi8Freq/25 (write)Clock_Ip_u32CorePhi8Freq/25 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Clock_Ip_Get_COREPLL_CLK_Frequency/56 (524845004 (estimated locally),0.49 per call) 
Clock_Ip_Get_COREPLL_PHI6_Frequency/64 (Clock_Ip_Get_COREPLL_PHI6_Frequency) @064562a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_u32CorePhi6Checksum/24 (read)Clock_Ip_u32CorePhi6Checksum/24 (write)Clock_Ip_u32EnableDivider/0 (read)Clock_Ip_u32CorePhi6Freq/23 (write)Clock_Ip_u32CorePhi6Freq/23 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Clock_Ip_Get_COREPLL_CLK_Frequency/56 (524845004 (estimated locally),0.49 per call) 
Clock_Ip_Get_COREPLL_PHI5_Frequency/63 (Clock_Ip_Get_COREPLL_PHI5_Frequency) @06456000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_u32CorePhi5Checksum/22 (read)Clock_Ip_u32CorePhi5Checksum/22 (write)Clock_Ip_u32EnableDivider/0 (read)Clock_Ip_u32CorePhi5Freq/21 (write)Clock_Ip_u32CorePhi5Freq/21 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Clock_Ip_Get_COREPLL_CLK_Frequency/56 (524845004 (estimated locally),0.49 per call) 
Clock_Ip_Get_COREPLL_PHI4_Frequency/62 (Clock_Ip_Get_COREPLL_PHI4_Frequency) @06446b60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_u32CorePhi4Checksum/20 (read)Clock_Ip_u32CorePhi4Checksum/20 (write)Clock_Ip_u32EnableDivider/0 (read)Clock_Ip_u32CorePhi4Freq/19 (write)Clock_Ip_u32CorePhi4Freq/19 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Clock_Ip_Get_COREPLL_CLK_Frequency/56 (524845004 (estimated locally),0.49 per call) 
Clock_Ip_Get_COREPLL_PHI3_Frequency/61 (Clock_Ip_Get_COREPLL_PHI3_Frequency) @06446620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_u32CorePhi3Checksum/18 (read)Clock_Ip_u32CorePhi3Checksum/18 (write)Clock_Ip_u32EnableDivider/0 (read)Clock_Ip_u32CorePhi3Freq/17 (write)Clock_Ip_u32CorePhi3Freq/17 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Clock_Ip_Get_COREPLL_CLK_Frequency/56 (524845004 (estimated locally),0.49 per call) 
Clock_Ip_Get_COREPLL_PHI2_Frequency/60 (Clock_Ip_Get_COREPLL_PHI2_Frequency) @064460e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_u32CorePhi2Checksum/16 (read)Clock_Ip_u32CorePhi2Checksum/16 (write)Clock_Ip_u32EnableDivider/0 (read)Clock_Ip_u32CorePhi2Freq/15 (write)Clock_Ip_u32CorePhi2Freq/15 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Clock_Ip_Get_COREPLL_CLK_Frequency/56 (524845004 (estimated locally),0.49 per call) 
Clock_Ip_Get_COREPLL_PHI1_Frequency/59 (Clock_Ip_Get_COREPLL_PHI1_Frequency) @06446d20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_u32CorePhi1Checksum/14 (read)Clock_Ip_u32CorePhi1Checksum/14 (write)Clock_Ip_u32EnableDivider/0 (read)Clock_Ip_u32CorePhi1Freq/13 (write)Clock_Ip_u32CorePhi1Freq/13 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Clock_Ip_Get_COREPLL_CLK_Frequency/56 (524845004 (estimated locally),0.49 per call) 
Clock_Ip_Get_COREPLL_PHI0_Frequency/58 (Clock_Ip_Get_COREPLL_PHI0_Frequency) @06446a80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_u32CorePhi0Checksum/12 (read)Clock_Ip_u32CorePhi0Checksum/12 (write)Clock_Ip_u32EnableDivider/0 (read)Clock_Ip_u32CorePhi0Freq/11 (write)Clock_Ip_u32CorePhi0Freq/11 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Clock_Ip_Get_COREPLL_CLK_Frequency/56 (524845004 (estimated locally),0.49 per call) 
Clock_Ip_Get_PERIPHPLL_CLK_Frequency/57 (Clock_Ip_Get_PERIPHPLL_CLK_Frequency) @064467e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_u32PeriphPllChecksum/10 (read)Clock_Ip_u32PeriphPllChecksum/10 (write)Clock_Ip_u32PeriphPllFreq/9 (write)Clock_Ip_u32PeriphPllFreq/9 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: Clock_Ip_Get_PERIPHPLL_DFS1_Frequency/77 (524845004 (estimated locally),0.49 per call) Clock_Ip_Get_PERIPHPLL_DFS2_Frequency/78 (524845004 (estimated locally),0.49 per call) Clock_Ip_Get_PERIPHPLL_PHI0_Frequency/67 (524845004 (estimated locally),0.49 per call) Clock_Ip_Get_PERIPHPLL_PHI1_Frequency/68 (524845004 (estimated locally),0.49 per call) Clock_Ip_Get_PERIPHPLL_PHI2_Frequency/69 (524845004 (estimated locally),0.49 per call) Clock_Ip_Get_PERIPHPLL_PHI3_Frequency/70 (524845004 (estimated locally),0.49 per call) Clock_Ip_Get_PERIPHPLL_PHI4_Frequency/71 (524845004 (estimated locally),0.49 per call) Clock_Ip_Get_PERIPHPLL_PHI5_Frequency/72 (524845004 (estimated locally),0.49 per call) Clock_Ip_Get_PERIPHPLL_PHI6_Frequency/73 (524845004 (estimated locally),0.49 per call) Clock_Ip_Get_PERIPHPLL_PHI7_Frequency/74 (524845004 (estimated locally),0.49 per call) Clock_Ip_Get_PERIPHPLL_PHI8_Frequency/75 (524845004 (estimated locally),0.49 per call) Clock_Ip_Get_PERIPHPLL_PHI9_Frequency/76 (524845004 (estimated locally),0.49 per call) 
  Calls: Clock_Ip_PLL_VCO/143 (524845004 (estimated locally),0.49 per call) 
Clock_Ip_Get_COREPLL_CLK_Frequency/56 (Clock_Ip_Get_COREPLL_CLK_Frequency) @06446540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_u32CorePllChecksum/8 (read)Clock_Ip_u32CorePllChecksum/8 (write)Clock_Ip_u32CorePllFreq/7 (write)Clock_Ip_u32CorePllFreq/7 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: Clock_Ip_Get_COREPLL_PHI0_Frequency/58 (524845004 (estimated locally),0.49 per call) Clock_Ip_Get_COREPLL_PHI1_Frequency/59 (524845004 (estimated locally),0.49 per call) Clock_Ip_Get_COREPLL_PHI2_Frequency/60 (524845004 (estimated locally),0.49 per call) Clock_Ip_Get_COREPLL_PHI3_Frequency/61 (524845004 (estimated locally),0.49 per call) Clock_Ip_Get_COREPLL_PHI4_Frequency/62 (524845004 (estimated locally),0.49 per call) Clock_Ip_Get_COREPLL_PHI5_Frequency/63 (524845004 (estimated locally),0.49 per call) Clock_Ip_Get_COREPLL_PHI6_Frequency/64 (524845004 (estimated locally),0.49 per call) Clock_Ip_Get_COREPLL_PHI8_Frequency/65 (524845004 (estimated locally),0.49 per call) Clock_Ip_Get_COREPLL_PHI9_Frequency/66 (524845004 (estimated locally),0.49 per call) 
  Calls: Clock_Ip_PLL_VCO/143 (524845004 (estimated locally),0.49 per call) 
Clock_Ip_Get_FXOSC_CLK_Frequency/55 (Clock_Ip_Get_FXOSC_CLK_Frequency) @064462a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: Clock_Ip_u32Fxosc/6 (read)
  Referring: Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: Clock_Ip_PLL_VCO.part.0/149 (354334802 (estimated locally),0.33 per call) 
  Calls: 
Clock_Ip_Get_FIRC_CLK_Frequency/54 (Clock_Ip_Get_FIRC_CLK_Frequency) @06446000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Clock_Ip_Get_Zero_Frequency/53 (Clock_Ip_Get_Zero_Frequency) @06444ee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: Clock_Ip_apfFreqTable/4 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfFreqTableClkSrc/3 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)Clock_Ip_apfTableClockGeneration/2 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Clock_Ip_u32PeriphDfs2Checksum/52 (Clock_Ip_u32PeriphDfs2Checksum) @06445750
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Clock_Ip_Get_PERIPHPLL_DFS2_Frequency/78 (read)Clock_Ip_Get_PERIPHPLL_DFS2_Frequency/78 (write)
  Availability: available
  Varpool flags: initialized
Clock_Ip_u32PeriphDfs2Freq/51 (Clock_Ip_u32PeriphDfs2Freq) @064456c0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Clock_Ip_Get_PERIPHPLL_DFS2_Frequency/78 (write)Clock_Ip_Get_PERIPHPLL_DFS2_Frequency/78 (read)
  Availability: available
  Varpool flags: initialized
Clock_Ip_u32PeriphDfs1Checksum/50 (Clock_Ip_u32PeriphDfs1Checksum) @06445630
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Clock_Ip_Get_PERIPHPLL_DFS1_Frequency/77 (read)Clock_Ip_Get_PERIPHPLL_DFS1_Frequency/77 (write)
  Availability: available
  Varpool flags: initialized
Clock_Ip_u32PeriphDfs1Freq/49 (Clock_Ip_u32PeriphDfs1Freq) @064455a0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Clock_Ip_Get_PERIPHPLL_DFS1_Frequency/77 (write)Clock_Ip_Get_PERIPHPLL_DFS1_Frequency/77 (read)
  Availability: available
  Varpool flags: initialized
Clock_Ip_u32PeriphPhi9Checksum/48 (Clock_Ip_u32PeriphPhi9Checksum) @06445510
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Clock_Ip_Get_PERIPHPLL_PHI9_Frequency/76 (read)Clock_Ip_Get_PERIPHPLL_PHI9_Frequency/76 (write)
  Availability: available
  Varpool flags: initialized
Clock_Ip_u32PeriphPhi9Freq/47 (Clock_Ip_u32PeriphPhi9Freq) @06445480
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Clock_Ip_Get_PERIPHPLL_PHI9_Frequency/76 (write)Clock_Ip_Get_PERIPHPLL_PHI9_Frequency/76 (read)
  Availability: available
  Varpool flags: initialized
Clock_Ip_u32PeriphPhi8Checksum/46 (Clock_Ip_u32PeriphPhi8Checksum) @064453f0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Clock_Ip_Get_PERIPHPLL_PHI8_Frequency/75 (read)Clock_Ip_Get_PERIPHPLL_PHI8_Frequency/75 (write)
  Availability: available
  Varpool flags: initialized
Clock_Ip_u32PeriphPhi8Freq/45 (Clock_Ip_u32PeriphPhi8Freq) @06445360
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Clock_Ip_Get_PERIPHPLL_PHI8_Frequency/75 (write)Clock_Ip_Get_PERIPHPLL_PHI8_Frequency/75 (read)
  Availability: available
  Varpool flags: initialized
Clock_Ip_u32PeriphPhi7Checksum/44 (Clock_Ip_u32PeriphPhi7Checksum) @064452d0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Clock_Ip_Get_PERIPHPLL_PHI7_Frequency/74 (read)Clock_Ip_Get_PERIPHPLL_PHI7_Frequency/74 (write)
  Availability: available
  Varpool flags: initialized
Clock_Ip_u32PeriphPhi7Freq/43 (Clock_Ip_u32PeriphPhi7Freq) @06445240
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Clock_Ip_Get_PERIPHPLL_PHI7_Frequency/74 (write)Clock_Ip_Get_PERIPHPLL_PHI7_Frequency/74 (read)
  Availability: available
  Varpool flags: initialized
Clock_Ip_u32PeriphPhi6Checksum/42 (Clock_Ip_u32PeriphPhi6Checksum) @064451b0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Clock_Ip_Get_PERIPHPLL_PHI6_Frequency/73 (read)Clock_Ip_Get_PERIPHPLL_PHI6_Frequency/73 (write)
  Availability: available
  Varpool flags: initialized
Clock_Ip_u32PeriphPhi6Freq/41 (Clock_Ip_u32PeriphPhi6Freq) @06445120
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Clock_Ip_Get_PERIPHPLL_PHI6_Frequency/73 (write)Clock_Ip_Get_PERIPHPLL_PHI6_Frequency/73 (read)
  Availability: available
  Varpool flags: initialized
Clock_Ip_u32PeriphPhi5Checksum/40 (Clock_Ip_u32PeriphPhi5Checksum) @06445090
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Clock_Ip_Get_PERIPHPLL_PHI5_Frequency/72 (read)Clock_Ip_Get_PERIPHPLL_PHI5_Frequency/72 (write)
  Availability: available
  Varpool flags: initialized
Clock_Ip_u32PeriphPhi5Freq/39 (Clock_Ip_u32PeriphPhi5Freq) @06445000
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Clock_Ip_Get_PERIPHPLL_PHI5_Frequency/72 (write)Clock_Ip_Get_PERIPHPLL_PHI5_Frequency/72 (read)
  Availability: available
  Varpool flags: initialized
Clock_Ip_u32PeriphPhi4Checksum/38 (Clock_Ip_u32PeriphPhi4Checksum) @06440f30
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Clock_Ip_Get_PERIPHPLL_PHI4_Frequency/71 (read)Clock_Ip_Get_PERIPHPLL_PHI4_Frequency/71 (write)
  Availability: available
  Varpool flags: initialized
Clock_Ip_u32PeriphPhi4Freq/37 (Clock_Ip_u32PeriphPhi4Freq) @06440ea0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Clock_Ip_Get_PERIPHPLL_PHI4_Frequency/71 (write)Clock_Ip_Get_PERIPHPLL_PHI4_Frequency/71 (read)
  Availability: available
  Varpool flags: initialized
Clock_Ip_u32PeriphPhi3Checksum/36 (Clock_Ip_u32PeriphPhi3Checksum) @06440e10
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Clock_Ip_Get_PERIPHPLL_PHI3_Frequency/70 (read)Clock_Ip_Get_PERIPHPLL_PHI3_Frequency/70 (write)
  Availability: available
  Varpool flags: initialized
Clock_Ip_u32PeriphPhi3Freq/35 (Clock_Ip_u32PeriphPhi3Freq) @06440d80
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Clock_Ip_Get_PERIPHPLL_PHI3_Frequency/70 (write)Clock_Ip_Get_PERIPHPLL_PHI3_Frequency/70 (read)
  Availability: available
  Varpool flags: initialized
Clock_Ip_u32PeriphPhi2Checksum/34 (Clock_Ip_u32PeriphPhi2Checksum) @06440cf0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Clock_Ip_Get_PERIPHPLL_PHI2_Frequency/69 (read)Clock_Ip_Get_PERIPHPLL_PHI2_Frequency/69 (write)
  Availability: available
  Varpool flags: initialized
Clock_Ip_u32PeriphPhi2Freq/33 (Clock_Ip_u32PeriphPhi2Freq) @06440c60
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Clock_Ip_Get_PERIPHPLL_PHI2_Frequency/69 (write)Clock_Ip_Get_PERIPHPLL_PHI2_Frequency/69 (read)
  Availability: available
  Varpool flags: initialized
Clock_Ip_u32PeriphPhi1Checksum/32 (Clock_Ip_u32PeriphPhi1Checksum) @06440bd0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Clock_Ip_Get_PERIPHPLL_PHI1_Frequency/68 (read)Clock_Ip_Get_PERIPHPLL_PHI1_Frequency/68 (write)
  Availability: available
  Varpool flags: initialized
Clock_Ip_u32PeriphPhi1Freq/31 (Clock_Ip_u32PeriphPhi1Freq) @06440b40
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Clock_Ip_Get_PERIPHPLL_PHI1_Frequency/68 (write)Clock_Ip_Get_PERIPHPLL_PHI1_Frequency/68 (read)
  Availability: available
  Varpool flags: initialized
Clock_Ip_u32PeriphPhi0Checksum/30 (Clock_Ip_u32PeriphPhi0Checksum) @06440ab0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Clock_Ip_Get_PERIPHPLL_PHI0_Frequency/67 (read)Clock_Ip_Get_PERIPHPLL_PHI0_Frequency/67 (write)
  Availability: available
  Varpool flags: initialized
Clock_Ip_u32PeriphPhi0Freq/29 (Clock_Ip_u32PeriphPhi0Freq) @06440a20
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Clock_Ip_Get_PERIPHPLL_PHI0_Frequency/67 (write)Clock_Ip_Get_PERIPHPLL_PHI0_Frequency/67 (read)
  Availability: available
  Varpool flags: initialized
Clock_Ip_u32CorePhi9Checksum/28 (Clock_Ip_u32CorePhi9Checksum) @06440990
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Clock_Ip_Get_COREPLL_PHI9_Frequency/66 (read)Clock_Ip_Get_COREPLL_PHI9_Frequency/66 (write)
  Availability: available
  Varpool flags: initialized
Clock_Ip_u32CorePhi9Freq/27 (Clock_Ip_u32CorePhi9Freq) @06440900
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Clock_Ip_Get_COREPLL_PHI9_Frequency/66 (write)Clock_Ip_Get_COREPLL_PHI9_Frequency/66 (read)
  Availability: available
  Varpool flags: initialized
Clock_Ip_u32CorePhi8Checksum/26 (Clock_Ip_u32CorePhi8Checksum) @06440870
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Clock_Ip_Get_COREPLL_PHI8_Frequency/65 (read)Clock_Ip_Get_COREPLL_PHI8_Frequency/65 (write)
  Availability: available
  Varpool flags: initialized
Clock_Ip_u32CorePhi8Freq/25 (Clock_Ip_u32CorePhi8Freq) @064407e0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Clock_Ip_Get_COREPLL_PHI8_Frequency/65 (write)Clock_Ip_Get_COREPLL_PHI8_Frequency/65 (read)
  Availability: available
  Varpool flags: initialized
Clock_Ip_u32CorePhi6Checksum/24 (Clock_Ip_u32CorePhi6Checksum) @064406c0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Clock_Ip_Get_COREPLL_PHI6_Frequency/64 (read)Clock_Ip_Get_COREPLL_PHI6_Frequency/64 (write)
  Availability: available
  Varpool flags: initialized
Clock_Ip_u32CorePhi6Freq/23 (Clock_Ip_u32CorePhi6Freq) @06440630
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Clock_Ip_Get_COREPLL_PHI6_Frequency/64 (write)Clock_Ip_Get_COREPLL_PHI6_Frequency/64 (read)
  Availability: available
  Varpool flags: initialized
Clock_Ip_u32CorePhi5Checksum/22 (Clock_Ip_u32CorePhi5Checksum) @064405a0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Clock_Ip_Get_COREPLL_PHI5_Frequency/63 (read)Clock_Ip_Get_COREPLL_PHI5_Frequency/63 (write)
  Availability: available
  Varpool flags: initialized
Clock_Ip_u32CorePhi5Freq/21 (Clock_Ip_u32CorePhi5Freq) @06440510
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Clock_Ip_Get_COREPLL_PHI5_Frequency/63 (write)Clock_Ip_Get_COREPLL_PHI5_Frequency/63 (read)
  Availability: available
  Varpool flags: initialized
Clock_Ip_u32CorePhi4Checksum/20 (Clock_Ip_u32CorePhi4Checksum) @06440480
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Clock_Ip_Get_COREPLL_PHI4_Frequency/62 (read)Clock_Ip_Get_COREPLL_PHI4_Frequency/62 (write)
  Availability: available
  Varpool flags: initialized
Clock_Ip_u32CorePhi4Freq/19 (Clock_Ip_u32CorePhi4Freq) @064403f0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Clock_Ip_Get_COREPLL_PHI4_Frequency/62 (write)Clock_Ip_Get_COREPLL_PHI4_Frequency/62 (read)
  Availability: available
  Varpool flags: initialized
Clock_Ip_u32CorePhi3Checksum/18 (Clock_Ip_u32CorePhi3Checksum) @06440360
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Clock_Ip_Get_COREPLL_PHI3_Frequency/61 (read)Clock_Ip_Get_COREPLL_PHI3_Frequency/61 (write)
  Availability: available
  Varpool flags: initialized
Clock_Ip_u32CorePhi3Freq/17 (Clock_Ip_u32CorePhi3Freq) @064402d0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Clock_Ip_Get_COREPLL_PHI3_Frequency/61 (write)Clock_Ip_Get_COREPLL_PHI3_Frequency/61 (read)
  Availability: available
  Varpool flags: initialized
Clock_Ip_u32CorePhi2Checksum/16 (Clock_Ip_u32CorePhi2Checksum) @06440240
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Clock_Ip_Get_COREPLL_PHI2_Frequency/60 (read)Clock_Ip_Get_COREPLL_PHI2_Frequency/60 (write)
  Availability: available
  Varpool flags: initialized
Clock_Ip_u32CorePhi2Freq/15 (Clock_Ip_u32CorePhi2Freq) @064401b0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Clock_Ip_Get_COREPLL_PHI2_Frequency/60 (write)Clock_Ip_Get_COREPLL_PHI2_Frequency/60 (read)
  Availability: available
  Varpool flags: initialized
Clock_Ip_u32CorePhi1Checksum/14 (Clock_Ip_u32CorePhi1Checksum) @06440120
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Clock_Ip_Get_COREPLL_PHI1_Frequency/59 (read)Clock_Ip_Get_COREPLL_PHI1_Frequency/59 (write)
  Availability: available
  Varpool flags: initialized
Clock_Ip_u32CorePhi1Freq/13 (Clock_Ip_u32CorePhi1Freq) @06440090
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Clock_Ip_Get_COREPLL_PHI1_Frequency/59 (write)Clock_Ip_Get_COREPLL_PHI1_Frequency/59 (read)
  Availability: available
  Varpool flags: initialized
Clock_Ip_u32CorePhi0Checksum/12 (Clock_Ip_u32CorePhi0Checksum) @06440000
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Clock_Ip_Get_COREPLL_PHI0_Frequency/58 (read)Clock_Ip_Get_COREPLL_PHI0_Frequency/58 (write)
  Availability: available
  Varpool flags: initialized
Clock_Ip_u32CorePhi0Freq/11 (Clock_Ip_u32CorePhi0Freq) @06589b40
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Clock_Ip_Get_COREPLL_PHI0_Frequency/58 (write)Clock_Ip_Get_COREPLL_PHI0_Frequency/58 (read)
  Availability: available
  Varpool flags: initialized
Clock_Ip_u32PeriphPllChecksum/10 (Clock_Ip_u32PeriphPllChecksum) @06589990
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Clock_Ip_Get_PERIPHPLL_CLK_Frequency/57 (read)Clock_Ip_Get_PERIPHPLL_CLK_Frequency/57 (write)
  Availability: available
  Varpool flags: initialized
Clock_Ip_u32PeriphPllFreq/9 (Clock_Ip_u32PeriphPllFreq) @06589f30
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Clock_Ip_Get_PERIPHPLL_CLK_Frequency/57 (write)Clock_Ip_Get_PERIPHPLL_CLK_Frequency/57 (read)
  Availability: available
  Varpool flags: initialized
Clock_Ip_u32CorePllChecksum/8 (Clock_Ip_u32CorePllChecksum) @06589ea0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Clock_Ip_Get_COREPLL_CLK_Frequency/56 (read)Clock_Ip_Get_COREPLL_CLK_Frequency/56 (write)
  Availability: available
  Varpool flags: initialized
Clock_Ip_u32CorePllFreq/7 (Clock_Ip_u32CorePllFreq) @06589e10
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Clock_Ip_Get_COREPLL_CLK_Frequency/56 (write)Clock_Ip_Get_COREPLL_CLK_Frequency/56 (read)
  Availability: available
  Varpool flags: initialized
Clock_Ip_u32Fxosc/6 (Clock_Ip_u32Fxosc) @06589d80
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Clock_Ip_Get_FXOSC_CLK_Frequency/55 (read)Clock_Ip_SetExternalOscillatorFrequency/145 (write)
  Availability: available
  Varpool flags: initialized
Clock_Ip_axExtSignalFreqEntries/5 (Clock_Ip_axExtSignalFreqEntries) @06589cf0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Clock_Ip_Get_gmac_1_ext_rx_Frequency/85 (read)Clock_Ip_Get_gmac_1_ext_ref_Frequency/84 (read)Clock_Ip_Get_gmac_0_ext_ts_Frequency/83 (read)Clock_Ip_Get_gmac_0_ext_tx_Frequency/82 (read)Clock_Ip_Get_gmac_0_ext_rx_Frequency/81 (read)Clock_Ip_Get_gmac_0_ext_ref_Frequency/80 (read)Clock_Ip_Get_ftm_0_ext_ref_Frequency/79 (read)Clock_Ip_Get_gmac_1_ext_ts_Frequency/87 (read)Clock_Ip_Get_gmac_1_ext_tx_Frequency/86 (read)Clock_Ip_SetExternalSignalFrequency/147 (read)Clock_Ip_SetExternalSignalFrequency/147 (write)
  Availability: available
  Varpool flags: initialized
Clock_Ip_apfFreqTable/4 (Clock_Ip_apfFreqTable) @06589c18
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_FIRC_CLK_Frequency/54 (addr)Clock_Ip_Get_FXOSC_CLK_Frequency/55 (addr)Clock_Ip_Get_COREPLL_CLK_Frequency/56 (addr)Clock_Ip_Get_PERIPHPLL_CLK_Frequency/57 (addr)Clock_Ip_Get_COREPLL_PHI0_Frequency/58 (addr)Clock_Ip_Get_COREPLL_PHI1_Frequency/59 (addr)Clock_Ip_Get_COREPLL_PHI2_Frequency/60 (addr)Clock_Ip_Get_COREPLL_PHI3_Frequency/61 (addr)Clock_Ip_Get_COREPLL_PHI4_Frequency/62 (addr)Clock_Ip_Get_COREPLL_PHI5_Frequency/63 (addr)Clock_Ip_Get_COREPLL_PHI6_Frequency/64 (addr)Clock_Ip_Get_COREPLL_PHI8_Frequency/65 (addr)Clock_Ip_Get_COREPLL_PHI9_Frequency/66 (addr)Clock_Ip_Get_PERIPHPLL_PHI0_Frequency/67 (addr)Clock_Ip_Get_PERIPHPLL_PHI1_Frequency/68 (addr)Clock_Ip_Get_PERIPHPLL_PHI2_Frequency/69 (addr)Clock_Ip_Get_PERIPHPLL_PHI3_Frequency/70 (addr)Clock_Ip_Get_PERIPHPLL_PHI4_Frequency/71 (addr)Clock_Ip_Get_PERIPHPLL_PHI5_Frequency/72 (addr)Clock_Ip_Get_PERIPHPLL_PHI6_Frequency/73 (addr)Clock_Ip_Get_PERIPHPLL_PHI7_Frequency/74 (addr)Clock_Ip_Get_PERIPHPLL_PHI8_Frequency/75 (addr)Clock_Ip_Get_PERIPHPLL_PHI9_Frequency/76 (addr)Clock_Ip_Get_PERIPHPLL_DFS1_Frequency/77 (addr)Clock_Ip_Get_PERIPHPLL_DFS2_Frequency/78 (addr)Clock_Ip_Get_ftm_0_ext_ref_Frequency/79 (addr)Clock_Ip_Get_gmac_0_ext_ref_Frequency/80 (addr)Clock_Ip_Get_gmac_0_ext_rx_Frequency/81 (addr)Clock_Ip_Get_gmac_0_ext_tx_Frequency/82 (addr)Clock_Ip_Get_gmac_0_ext_ts_Frequency/83 (addr)Clock_Ip_Get_gmac_1_ext_ref_Frequency/84 (addr)Clock_Ip_Get_gmac_1_ext_rx_Frequency/85 (addr)Clock_Ip_Get_gmac_1_ext_tx_Frequency/86 (addr)Clock_Ip_Get_gmac_1_ext_ts_Frequency/87 (addr)Clock_Ip_Get_SYS_CLK_Frequency/88 (addr)Clock_Ip_Get_SYS_DIV2_CLK_Frequency/89 (addr)Clock_Ip_Get_SYS_DIV4_CLK_Frequency/90 (addr)Clock_Ip_Get_SYS_DIV8_CLK_Frequency/91 (addr)Clock_Ip_Get_SYS_DIV8_CLK_Frequency/91 (addr)Clock_Ip_Get_A53_CORE_CLK_Frequency/92 (addr)Clock_Ip_Get_A53_CORE_DIV2_CLK_Frequency/93 (addr)Clock_Ip_Get_A53_CORE_DIV10_CLK_Frequency/94 (addr)Clock_Ip_Get_ACCEL_CLK_Frequency/95 (addr)Clock_Ip_Get_ACCEL_DIV3_CLK_Frequency/96 (addr)Clock_Ip_Get_ACCEL_XBAR_CLK_Frequency/97 (addr)Clock_Ip_Get_ACCEL_XBAR_DIV2_CLK_Frequency/98 (addr)Clock_Ip_Get_ACCEL_XBAR_DIV4_CLK_Frequency/99 (addr)Clock_Ip_Get_ACCEL_XBAR_DIV8_CLK_Frequency/100 (addr)Clock_Ip_Get_ACCEL_XBAR_DIV8_CLK_Frequency/100 (addr)Clock_Ip_Get_GMAC0_REF_CLK_Frequency/101 (addr)Clock_Ip_Get_GMAC0_REF_DIV_CLK_Frequency/102 (addr)Clock_Ip_Get_GMAC1_REF_CLK_Frequency/103 (addr)Clock_Ip_Get_GMAC1_REF_DIV_CLK_Frequency/104 (addr)Clock_Ip_Get_GMAC1_INT_CLK_Frequency/106 (addr)Clock_Ip_Get_GMAC_1_INT_REF_CLK_Frequency/105 (addr)Clock_Ip_Get_BBE32EP_DSP_CLK_Frequency/107 (addr)Clock_Ip_Get_CAN_CHI_CLK_Frequency/108 (addr)Clock_Ip_Get_CAN_TS_CLK_Frequency/109 (addr)Clock_Ip_Get_CAN_PE_CLK_Frequency/110 (addr)Clock_Ip_Get_CAN_PE_CLK_Frequency/110 (addr)Clock_Ip_Get_CAN_PE_CLK_Frequency/110 (addr)Clock_Ip_Get_CLKOUT0_CLK_Frequency/111 (addr)Clock_Ip_Get_CLKOUT1_CLK_Frequency/112 (addr)Clock_Ip_Get_A53_CORE_CLK_Frequency/92 (addr)Clock_Ip_Get_A53_CORE_CLK_Frequency/92 (addr)Clock_Ip_Get_SYS_DIV8_CLK_Frequency/91 (addr)Clock_Ip_Get_CSI_CLK_Frequency/113 (addr)Clock_Ip_Get_CSI_CFG_CLK_Frequency/114 (addr)Clock_Ip_Get_CTE_CLK_Frequency/115 (addr)Clock_Ip_Get_CTE_CLK_Frequency/115 (addr)Clock_Ip_Get_CSI_TXCLK_CLK_Frequency/116 (addr)Clock_Ip_Get_MC_CLK_Frequency/117 (addr)Clock_Ip_Get_MC_CLK_Frequency/117 (addr)Clock_Ip_Get_CTU_IPS_CLK_Frequency/118 (addr)Clock_Ip_Get_DAPB_CLK_Frequency/119 (addr)Clock_Ip_Get_SYS_CLK_Frequency/88 (addr)Clock_Ip_Get_SYS_DIV2_CLK_Frequency/89 (addr)Clock_Ip_Get_SYS_CLK_Frequency/88 (addr)Clock_Ip_Get_SYS_CLK_Frequency/88 (addr)Clock_Ip_Get_SYS_CLK_Frequency/88 (addr)Clock_Ip_Get_DSPI_SCK_TST_CLK_Frequency/120 (addr)Clock_Ip_Get_ACCEL_XBAR_DIV8_CLK_Frequency/100 (addr)Clock_Ip_Get_SYS_DIV8_CLK_Frequency/91 (addr)Clock_Ip_Get_SYS_DIV8_CLK_Frequency/91 (addr)Clock_Ip_Get_ACCEL_XBAR_DIV8_CLK_Frequency/100 (addr)Clock_Ip_Get_SYS_DIV8_CLK_Frequency/91 (addr)Clock_Ip_Get_SYS_DIV8_CLK_Frequency/91 (addr)Clock_Ip_Get_ACCEL_XBAR_DIV8_CLK_Frequency/100 (addr)Clock_Ip_Get_SYS_DIV8_CLK_Frequency/91 (addr)Clock_Ip_Get_SYS_DIV8_CLK_Frequency/91 (addr)Clock_Ip_Get_SYS_DIV8_CLK_Frequency/91 (addr)Clock_Ip_Get_FCCU_IPS_CLK_Frequency/121 (addr)Clock_Ip_Get_MC_CLK_Frequency/117 (addr)Clock_Ip_Get_FTM0_EXT_CLK_Frequency/122 (addr)Clock_Ip_Get_GMAC0_RX_CLK_Frequency/123 (addr)Clock_Ip_Get_GMAC0_TS_CLK_Frequency/124 (addr)Clock_Ip_Get_GMAC0_TX_CLK_Frequency/125 (addr)Clock_Ip_Get_GMAC1_RX_CLK_Frequency/126 (addr)Clock_Ip_Get_GMAC1_TS_CLK_Frequency/127 (addr)Clock_Ip_Get_GMAC1_TX_CLK_Frequency/128 (addr)Clock_Ip_Get_SYS_DIV4_CLK_Frequency/90 (addr)Clock_Ip_Get_SYS_DIV4_CLK_Frequency/90 (addr)Clock_Ip_Get_LBIST_CLK_Frequency/129 (addr)Clock_Ip_Get_LBIST_CLK_Frequency/129 (addr)Clock_Ip_Get_LBIST_CLK_Frequency/129 (addr)Clock_Ip_Get_LBIST_CLK_Frequency/129 (addr)Clock_Ip_Get_LBIST_CLK_Frequency/129 (addr)Clock_Ip_Get_LBIST_CLK_Frequency/129 (addr)Clock_Ip_Get_LBIST_CLK_Frequency/129 (addr)Clock_Ip_Get_LBIST_CLK_Frequency/129 (addr)Clock_Ip_Get_LBIST_CLK_Frequency/129 (addr)Clock_Ip_Get_LIN_BAUD_CLK_Frequency/130 (addr)Clock_Ip_Get_LINFLEXD_CLK_Frequency/131 (addr)Clock_Ip_Get_LIN_BAUD_CLK_Frequency/130 (addr)Clock_Ip_Get_LIN_BAUD_CLK_Frequency/130 (addr)Clock_Ip_Get_SYS_CLK_Frequency/88 (addr)Clock_Ip_Get_SYS_CLK_Frequency/88 (addr)Clock_Ip_Get_SYS_CLK_Frequency/88 (addr)Clock_Ip_Get_MIPICSI2_0_CLK_Frequency/132 (addr)Clock_Ip_Get_MIPICSI2_1_CLK_Frequency/133 (addr)Clock_Ip_Get_SYS_DIV8_CLK_Frequency/91 (addr)Clock_Ip_Get_NOC_TRACE_CLK_Frequency/134 (addr)Clock_Ip_Get_FIRC_CLK_Frequency/54 (addr)Clock_Ip_Get_SYS_DIV4_CLK_Frequency/90 (addr)Clock_Ip_Get_ACCEL_XBAR_DIV8_CLK_Frequency/100 (addr)Clock_Ip_Get_QSPI_2X_CLK_Frequency/135 (addr)Clock_Ip_Get_QSPI_1X_CLK_Frequency/136 (addr)Clock_Ip_Get_QSPI0_CLK_Frequency/137 (addr)Clock_Ip_Get_MC_CLK_Frequency/117 (addr)Clock_Ip_Get_ACCEL_XBAR_DIV4_CLK_Frequency/99 (addr)Clock_Ip_Get_SYS_DIV2_CLK_Frequency/89 (addr)Clock_Ip_Get_SYS_DIV8_CLK_Frequency/91 (addr)Clock_Ip_Get_SPI_CLK_Frequency/138 (addr)Clock_Ip_Get_SPI_CLK_Frequency/138 (addr)Clock_Ip_Get_SPI_CLK_Frequency/138 (addr)Clock_Ip_Get_SPI_CLK_Frequency/138 (addr)Clock_Ip_Get_SPI_CLK_Frequency/138 (addr)Clock_Ip_Get_SPT_CLK_Frequency/139 (addr)Clock_Ip_Get_ACCEL_XBAR_CLK_Frequency/97 (addr)Clock_Ip_Get_STCU_CLK_Frequency/140 (addr)Clock_Ip_Get_SYS_DIV2_CLK_Frequency/89 (addr)Clock_Ip_Get_SYS_DIV2_CLK_Frequency/89 (addr)Clock_Ip_Get_ACCEL_XBAR_DIV4_CLK_Frequency/99 (addr)Clock_Ip_Get_SYS_DIV8_CLK_Frequency/91 (addr)Clock_Ip_Get_SYS_DIV8_CLK_Frequency/91 (addr)Clock_Ip_Get_ACCEL_XBAR_DIV8_CLK_Frequency/100 (addr)Clock_Ip_Get_ACCEL_XBAR_DIV8_CLK_Frequency/100 (addr)Clock_Ip_Get_TMU_CLK_Frequency/141 (addr)Clock_Ip_Get_TCLK_CLK_Frequency/142 (addr)Clock_Ip_Get_SYS_DIV8_CLK_Frequency/91 (addr)Clock_Ip_Get_SYS_DIV8_CLK_Frequency/91 (addr)Clock_Ip_Get_ACCEL_XBAR_DIV8_CLK_Frequency/100 (addr)
  Referring: Clock_Ip_GetFreq/146 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known
Clock_Ip_apfFreqTableClkSrc/3 (Clock_Ip_apfFreqTableClkSrc) @06589ab0
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: Clock_Ip_Get_FIRC_CLK_Frequency/54 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_FXOSC_CLK_Frequency/55 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_COREPLL_PHI0_Frequency/58 (addr)Clock_Ip_Get_COREPLL_PHI1_Frequency/59 (addr)Clock_Ip_Get_COREPLL_PHI2_Frequency/60 (addr)Clock_Ip_Get_COREPLL_PHI3_Frequency/61 (addr)Clock_Ip_Get_COREPLL_PHI4_Frequency/62 (addr)Clock_Ip_Get_COREPLL_PHI5_Frequency/63 (addr)Clock_Ip_Get_COREPLL_PHI6_Frequency/64 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_COREPLL_PHI8_Frequency/65 (addr)Clock_Ip_Get_COREPLL_PHI9_Frequency/66 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_PERIPHPLL_PHI8_Frequency/75 (addr)Clock_Ip_Get_PERIPHPLL_PHI9_Frequency/76 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_PERIPHPLL_PHI0_Frequency/67 (addr)Clock_Ip_Get_PERIPHPLL_PHI1_Frequency/68 (addr)Clock_Ip_Get_PERIPHPLL_PHI2_Frequency/69 (addr)Clock_Ip_Get_PERIPHPLL_PHI3_Frequency/70 (addr)Clock_Ip_Get_PERIPHPLL_PHI4_Frequency/71 (addr)Clock_Ip_Get_PERIPHPLL_PHI5_Frequency/72 (addr)Clock_Ip_Get_PERIPHPLL_PHI6_Frequency/73 (addr)Clock_Ip_Get_PERIPHPLL_PHI7_Frequency/74 (addr)Clock_Ip_Get_PERIPHPLL_DFS1_Frequency/77 (addr)Clock_Ip_Get_PERIPHPLL_DFS2_Frequency/78 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_ftm_0_ext_ref_Frequency/79 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_gmac_0_ext_tx_Frequency/82 (addr)Clock_Ip_Get_gmac_0_ext_rx_Frequency/81 (addr)Clock_Ip_Get_gmac_0_ext_ref_Frequency/80 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_gmac_0_ext_ts_Frequency/83 (addr)Clock_Ip_Get_GMAC0_REF_DIV_CLK_Frequency/102 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_GMAC_1_INT_REF_CLK_Frequency/105 (addr)Clock_Ip_Get_GMAC1_REF_DIV_CLK_Frequency/104 (addr)Clock_Ip_Get_gmac_1_ext_ts_Frequency/87 (addr)Clock_Ip_Get_gmac_1_ext_tx_Frequency/86 (addr)Clock_Ip_Get_gmac_1_ext_rx_Frequency/85 (addr)Clock_Ip_Get_gmac_1_ext_ref_Frequency/84 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)
  Referring: Clock_Ip_Get_A53_CORE_CLK_Frequency/92 (read)Clock_Ip_Get_SPT_CLK_Frequency/139 (read)Clock_Ip_Get_SPI_CLK_Frequency/138 (read)Clock_Ip_Get_ACCEL_CLK_Frequency/95 (read)Clock_Ip_Get_QSPI_2X_CLK_Frequency/135 (read)Clock_Ip_Get_NOC_TRACE_CLK_Frequency/134 (read)Clock_Ip_Get_ACCEL_XBAR_CLK_Frequency/97 (read)Clock_Ip_Get_MIPICSI2_0_CLK_Frequency/132 (read)Clock_Ip_Get_LIN_BAUD_CLK_Frequency/130 (read)Clock_Ip_Get_LBIST_CLK_Frequency/129 (read)Clock_Ip_Get_GMAC1_TX_CLK_Frequency/128 (read)Clock_Ip_Get_GMAC1_TS_CLK_Frequency/127 (read)Clock_Ip_Get_GMAC1_RX_CLK_Frequency/126 (read)Clock_Ip_Get_GMAC0_TX_CLK_Frequency/125 (read)Clock_Ip_Get_GMAC0_TS_CLK_Frequency/124 (read)Clock_Ip_Get_GMAC0_RX_CLK_Frequency/123 (read)Clock_Ip_Get_FTM0_EXT_CLK_Frequency/122 (read)Clock_Ip_Get_SYS_CLK_Frequency/88 (read)Clock_Ip_Get_DSPI_SCK_TST_CLK_Frequency/120 (read)Clock_Ip_Get_DAPB_CLK_Frequency/119 (read)Clock_Ip_Get_TCLK_CLK_Frequency/142 (read)Clock_Ip_Get_MC_CLK_Frequency/117 (read)Clock_Ip_Get_CSI_TXCLK_CLK_Frequency/116 (read)Clock_Ip_Get_CTE_CLK_Frequency/115 (read)Clock_Ip_Get_CSI_CFG_CLK_Frequency/114 (read)Clock_Ip_Get_CSI_CLK_Frequency/113 (read)Clock_Ip_Get_CLKOUT1_CLK_Frequency/112 (read)Clock_Ip_Get_CLKOUT0_CLK_Frequency/111 (read)Clock_Ip_Get_CAN_PE_CLK_Frequency/110 (read)Clock_Ip_Get_CAN_TS_CLK_Frequency/109 (read)Clock_Ip_Get_CAN_CHI_CLK_Frequency/108 (read)Clock_Ip_Get_BBE32EP_DSP_CLK_Frequency/107 (read)Clock_Ip_Get_GMAC1_REF_CLK_Frequency/103 (read)Clock_Ip_Get_GMAC0_REF_CLK_Frequency/101 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known
Clock_Ip_apfTableClockGeneration/2 (Clock_Ip_apfTableClockGeneration) @065899d8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: Clock_Ip_Get_FIRC_CLK_Frequency/54 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_FXOSC_CLK_Frequency/55 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_COREPLL_PHI0_Frequency/58 (addr)Clock_Ip_Get_COREPLL_PHI1_Frequency/59 (addr)Clock_Ip_Get_COREPLL_PHI2_Frequency/60 (addr)Clock_Ip_Get_COREPLL_PHI3_Frequency/61 (addr)Clock_Ip_Get_COREPLL_PHI4_Frequency/62 (addr)Clock_Ip_Get_COREPLL_PHI5_Frequency/63 (addr)Clock_Ip_Get_COREPLL_PHI6_Frequency/64 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_COREPLL_PHI8_Frequency/65 (addr)Clock_Ip_Get_COREPLL_PHI9_Frequency/66 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_PERIPHPLL_PHI8_Frequency/75 (addr)Clock_Ip_Get_PERIPHPLL_PHI9_Frequency/76 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_PERIPHPLL_PHI0_Frequency/67 (addr)Clock_Ip_Get_PERIPHPLL_PHI1_Frequency/68 (addr)Clock_Ip_Get_PERIPHPLL_PHI2_Frequency/69 (addr)Clock_Ip_Get_PERIPHPLL_PHI3_Frequency/70 (addr)Clock_Ip_Get_PERIPHPLL_PHI4_Frequency/71 (addr)Clock_Ip_Get_PERIPHPLL_PHI5_Frequency/72 (addr)Clock_Ip_Get_PERIPHPLL_PHI6_Frequency/73 (addr)Clock_Ip_Get_PERIPHPLL_PHI7_Frequency/74 (addr)Clock_Ip_Get_PERIPHPLL_DFS1_Frequency/77 (addr)Clock_Ip_Get_PERIPHPLL_DFS2_Frequency/78 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_ftm_0_ext_ref_Frequency/79 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_gmac_0_ext_tx_Frequency/82 (addr)Clock_Ip_Get_gmac_0_ext_rx_Frequency/81 (addr)Clock_Ip_Get_gmac_0_ext_ref_Frequency/80 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_gmac_0_ext_ts_Frequency/83 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_GMAC_1_INT_REF_CLK_Frequency/105 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_gmac_1_ext_ts_Frequency/87 (addr)Clock_Ip_Get_gmac_1_ext_tx_Frequency/86 (addr)Clock_Ip_Get_gmac_1_ext_rx_Frequency/85 (addr)Clock_Ip_Get_gmac_1_ext_ref_Frequency/84 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)Clock_Ip_Get_Zero_Frequency/53 (addr)
  Referring: Clock_Ip_Get_GMAC0_REF_DIV_CLK_Frequency/102 (read)Clock_Ip_Get_GMAC1_REF_DIV_CLK_Frequency/104 (read)Clock_Ip_Get_GMAC1_INT_CLK_Frequency/106 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known
Clock_Ip_u32EnableGate/1 (Clock_Ip_u32EnableGate) @06589900
  Type: variable definition analyzed alias
  Visibility: prevailing_def_ironly
  References: Clock_Ip_u32EnableDivider/0 (alias)
  Referring: Clock_Ip_Get_MIPICSI2_0_CLK_Frequency/132 (read)Clock_Ip_Get_BBE32EP_DSP_CLK_Frequency/107 (read)Clock_Ip_Get_SPT_CLK_Frequency/139 (read)
  Availability: available
  Varpool flags: read-only const-value-known
Clock_Ip_u32EnableDivider/0 (Clock_Ip_u32EnableDivider) @06589870
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Clock_Ip_u32EnableGate/1 (alias)Clock_Ip_Get_COREPLL_PHI5_Frequency/63 (read)Clock_Ip_Get_COREPLL_PHI6_Frequency/64 (read)Clock_Ip_Get_QSPI_2X_CLK_Frequency/135 (read)Clock_Ip_Get_LBIST_CLK_Frequency/129 (read)Clock_Ip_Get_GMAC1_TX_CLK_Frequency/128 (read)Clock_Ip_Get_GMAC1_TS_CLK_Frequency/127 (read)Clock_Ip_Get_GMAC0_TS_CLK_Frequency/124 (read)Clock_Ip_Get_FTM0_EXT_CLK_Frequency/122 (read)Clock_Ip_Get_COREPLL_PHI3_Frequency/61 (read)Clock_Ip_Get_DSPI_SCK_TST_CLK_Frequency/120 (read)Clock_Ip_Get_DAPB_CLK_Frequency/119 (read)Clock_Ip_Get_COREPLL_PHI0_Frequency/58 (read)Clock_Ip_Get_CSI_TXCLK_CLK_Frequency/116 (read)Clock_Ip_Get_CSI_CFG_CLK_Frequency/114 (read)Clock_Ip_Get_CLKOUT1_CLK_Frequency/112 (read)Clock_Ip_Get_CLKOUT0_CLK_Frequency/111 (read)Clock_Ip_Get_CAN_TS_CLK_Frequency/109 (read)Clock_Ip_Get_CAN_CHI_CLK_Frequency/108 (read)Clock_Ip_Get_GMAC1_REF_DIV_CLK_Frequency/104 (read)Clock_Ip_Get_GMAC0_REF_DIV_CLK_Frequency/102 (read)Clock_Ip_Get_COREPLL_PHI1_Frequency/59 (read)Clock_Ip_Get_COREPLL_PHI2_Frequency/60 (read)Clock_Ip_Get_COREPLL_PHI4_Frequency/62 (read)Clock_Ip_Get_TCLK_CLK_Frequency/142 (read)Clock_Ip_Get_PERIPHPLL_PHI9_Frequency/76 (read)Clock_Ip_Get_PERIPHPLL_PHI8_Frequency/75 (read)Clock_Ip_Get_PERIPHPLL_PHI7_Frequency/74 (read)Clock_Ip_Get_PERIPHPLL_PHI6_Frequency/73 (read)Clock_Ip_Get_PERIPHPLL_PHI5_Frequency/72 (read)Clock_Ip_Get_PERIPHPLL_PHI4_Frequency/71 (read)Clock_Ip_Get_PERIPHPLL_PHI3_Frequency/70 (read)Clock_Ip_Get_PERIPHPLL_PHI2_Frequency/69 (read)Clock_Ip_Get_PERIPHPLL_PHI1_Frequency/68 (read)Clock_Ip_Get_PERIPHPLL_PHI0_Frequency/67 (read)Clock_Ip_Get_COREPLL_PHI9_Frequency/66 (read)Clock_Ip_Get_COREPLL_PHI8_Frequency/65 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known

;; Function Clock_Ip_Get_Zero_Frequency (Clock_Ip_Get_Zero_Frequency, funcdef_no=0, decl_uid=6381, cgraph_uid=1, symbol_order=53)

Modification phase of node Clock_Ip_Get_Zero_Frequency/53
Clock_Ip_Get_Zero_Frequency ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function Clock_Ip_Get_FIRC_CLK_Frequency (Clock_Ip_Get_FIRC_CLK_Frequency, funcdef_no=1, decl_uid=6383, cgraph_uid=2, symbol_order=54)

Modification phase of node Clock_Ip_Get_FIRC_CLK_Frequency/54
Clock_Ip_Get_FIRC_CLK_Frequency ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return 48000000;

}



;; Function Clock_Ip_Get_FXOSC_CLK_Frequency (Clock_Ip_Get_FXOSC_CLK_Frequency, funcdef_no=2, decl_uid=6385, cgraph_uid=3, symbol_order=55)

Modification phase of node Clock_Ip_Get_FXOSC_CLK_Frequency/55
Clock_Ip_Get_FXOSC_CLK_Frequency ()
{
  long unsigned int _1;
  signed int _2;
  long unsigned int iftmp.68_3;
  long unsigned int iftmp.68_5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct FXOSC_Type *)1074282496B].STAT;
  _2 = (signed int) _1;
  if (_2 < 0)
    goto <bb 3>; [41.00%]
  else
    goto <bb 4>; [59.00%]

  <bb 3> [local count: 440234148]:
  iftmp.68_5 = Clock_Ip_u32Fxosc;

  <bb 4> [local count: 1073741824]:
  # iftmp.68_3 = PHI <iftmp.68_5(3), 0(2)>
  # DEBUG Frequency => iftmp.68_3
  # DEBUG BEGIN_STMT
  return iftmp.68_3;

}



;; Function Clock_Ip_Get_ftm_0_ext_ref_Frequency (Clock_Ip_Get_ftm_0_ext_ref_Frequency, funcdef_no=26, decl_uid=6433, cgraph_uid=27, symbol_order=79)

Modification phase of node Clock_Ip_Get_ftm_0_ext_ref_Frequency/79
Clock_Ip_Get_ftm_0_ext_ref_Frequency ()
{
  uint32 _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _2 = Clock_Ip_axExtSignalFreqEntries[0].Frequency;
  return _2;

}



;; Function Clock_Ip_Get_gmac_0_ext_ref_Frequency (Clock_Ip_Get_gmac_0_ext_ref_Frequency, funcdef_no=27, decl_uid=6435, cgraph_uid=28, symbol_order=80)

Modification phase of node Clock_Ip_Get_gmac_0_ext_ref_Frequency/80
Clock_Ip_Get_gmac_0_ext_ref_Frequency ()
{
  uint32 _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _2 = Clock_Ip_axExtSignalFreqEntries[1].Frequency;
  return _2;

}



;; Function Clock_Ip_Get_gmac_0_ext_rx_Frequency (Clock_Ip_Get_gmac_0_ext_rx_Frequency, funcdef_no=28, decl_uid=6437, cgraph_uid=29, symbol_order=81)

Modification phase of node Clock_Ip_Get_gmac_0_ext_rx_Frequency/81
Clock_Ip_Get_gmac_0_ext_rx_Frequency ()
{
  uint32 _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _2 = Clock_Ip_axExtSignalFreqEntries[2].Frequency;
  return _2;

}



;; Function Clock_Ip_Get_gmac_0_ext_tx_Frequency (Clock_Ip_Get_gmac_0_ext_tx_Frequency, funcdef_no=29, decl_uid=6439, cgraph_uid=30, symbol_order=82)

Modification phase of node Clock_Ip_Get_gmac_0_ext_tx_Frequency/82
Clock_Ip_Get_gmac_0_ext_tx_Frequency ()
{
  uint32 _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _2 = Clock_Ip_axExtSignalFreqEntries[3].Frequency;
  return _2;

}



;; Function Clock_Ip_Get_gmac_0_ext_ts_Frequency (Clock_Ip_Get_gmac_0_ext_ts_Frequency, funcdef_no=30, decl_uid=6441, cgraph_uid=31, symbol_order=83)

Modification phase of node Clock_Ip_Get_gmac_0_ext_ts_Frequency/83
Clock_Ip_Get_gmac_0_ext_ts_Frequency ()
{
  uint32 _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _2 = Clock_Ip_axExtSignalFreqEntries[4].Frequency;
  return _2;

}



;; Function Clock_Ip_Get_gmac_1_ext_ref_Frequency (Clock_Ip_Get_gmac_1_ext_ref_Frequency, funcdef_no=31, decl_uid=6443, cgraph_uid=32, symbol_order=84)

Modification phase of node Clock_Ip_Get_gmac_1_ext_ref_Frequency/84
Clock_Ip_Get_gmac_1_ext_ref_Frequency ()
{
  uint32 _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _2 = Clock_Ip_axExtSignalFreqEntries[5].Frequency;
  return _2;

}



;; Function Clock_Ip_Get_gmac_1_ext_rx_Frequency (Clock_Ip_Get_gmac_1_ext_rx_Frequency, funcdef_no=32, decl_uid=6445, cgraph_uid=33, symbol_order=85)

Modification phase of node Clock_Ip_Get_gmac_1_ext_rx_Frequency/85
Clock_Ip_Get_gmac_1_ext_rx_Frequency ()
{
  uint32 _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _2 = Clock_Ip_axExtSignalFreqEntries[6].Frequency;
  return _2;

}



;; Function Clock_Ip_Get_gmac_1_ext_tx_Frequency (Clock_Ip_Get_gmac_1_ext_tx_Frequency, funcdef_no=33, decl_uid=6447, cgraph_uid=34, symbol_order=86)

Modification phase of node Clock_Ip_Get_gmac_1_ext_tx_Frequency/86
Clock_Ip_Get_gmac_1_ext_tx_Frequency ()
{
  uint32 _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _2 = Clock_Ip_axExtSignalFreqEntries[7].Frequency;
  return _2;

}



;; Function Clock_Ip_Get_gmac_1_ext_ts_Frequency (Clock_Ip_Get_gmac_1_ext_ts_Frequency, funcdef_no=34, decl_uid=6449, cgraph_uid=35, symbol_order=87)

Modification phase of node Clock_Ip_Get_gmac_1_ext_ts_Frequency/87
Clock_Ip_Get_gmac_1_ext_ts_Frequency ()
{
  uint32 _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _2 = Clock_Ip_axExtSignalFreqEntries[8].Frequency;
  return _2;

}



;; Function Clock_Ip_Get_SYS_CLK_Frequency (Clock_Ip_Get_SYS_CLK_Frequency, funcdef_no=35, decl_uid=6451, cgraph_uid=36, symbol_order=88)

Modification phase of node Clock_Ip_Get_SYS_CLK_Frequency/88
Clock_Ip_Get_SYS_CLK_Frequency ()
{
  uint32 Frequency;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  uint32 (*<T752>) (void) _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct MC_CGM_0_Type *)1074561024B].MUX_0_CSS;
  _2 = _1 >> 24;
  _3 = _2 & 31;
  _4 = Clock_Ip_apfFreqTableClkSrc[_3];
  Frequency_7 = _4 ();
  # DEBUG Frequency => Frequency_7
  # DEBUG BEGIN_STMT
  return Frequency_7;

}



;; Function Clock_Ip_Get_SYS_DIV2_CLK_Frequency (Clock_Ip_Get_SYS_DIV2_CLK_Frequency, funcdef_no=36, decl_uid=6453, cgraph_uid=37, symbol_order=89)

Modification phase of node Clock_Ip_Get_SYS_DIV2_CLK_Frequency/89
Clock_Ip_Get_SYS_DIV2_CLK_Frequency ()
{
  long unsigned int _1;
  uint32 _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = Clock_Ip_Get_SYS_CLK_Frequency ();
  _4 = _1 >> 1;
  return _4;

}



;; Function Clock_Ip_Get_SYS_DIV4_CLK_Frequency (Clock_Ip_Get_SYS_DIV4_CLK_Frequency, funcdef_no=37, decl_uid=6455, cgraph_uid=38, symbol_order=90)

Modification phase of node Clock_Ip_Get_SYS_DIV4_CLK_Frequency/90
Clock_Ip_Get_SYS_DIV4_CLK_Frequency ()
{
  long unsigned int _1;
  uint32 _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = Clock_Ip_Get_SYS_CLK_Frequency ();
  _4 = _1 >> 2;
  return _4;

}



;; Function Clock_Ip_Get_SYS_DIV8_CLK_Frequency (Clock_Ip_Get_SYS_DIV8_CLK_Frequency, funcdef_no=38, decl_uid=6457, cgraph_uid=39, symbol_order=91)

Modification phase of node Clock_Ip_Get_SYS_DIV8_CLK_Frequency/91
Clock_Ip_Get_SYS_DIV8_CLK_Frequency ()
{
  long unsigned int _1;
  uint32 _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = Clock_Ip_Get_SYS_CLK_Frequency ();
  _4 = _1 >> 3;
  return _4;

}



;; Function Clock_Ip_Get_A53_CORE_CLK_Frequency (Clock_Ip_Get_A53_CORE_CLK_Frequency, funcdef_no=39, decl_uid=6461, cgraph_uid=40, symbol_order=92)

Modification phase of node Clock_Ip_Get_A53_CORE_CLK_Frequency/92
Clock_Ip_Get_A53_CORE_CLK_Frequency ()
{
  uint32 Frequency;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  uint32 (*<T752>) (void) _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct MC_CGM_Type *)1141669888B].MUX_0_CSS;
  _2 = _1 >> 24;
  _3 = _2 & 63;
  _4 = Clock_Ip_apfFreqTableClkSrc[_3];
  Frequency_7 = _4 ();
  # DEBUG Frequency => Frequency_7
  # DEBUG BEGIN_STMT
  return Frequency_7;

}



;; Function Clock_Ip_Get_A53_CORE_DIV2_CLK_Frequency (Clock_Ip_Get_A53_CORE_DIV2_CLK_Frequency, funcdef_no=40, decl_uid=6463, cgraph_uid=41, symbol_order=93)

Modification phase of node Clock_Ip_Get_A53_CORE_DIV2_CLK_Frequency/93
Clock_Ip_Get_A53_CORE_DIV2_CLK_Frequency ()
{
  long unsigned int _1;
  uint32 _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = Clock_Ip_Get_A53_CORE_CLK_Frequency ();
  _4 = _1 >> 1;
  return _4;

}



;; Function Clock_Ip_Get_A53_CORE_DIV10_CLK_Frequency (Clock_Ip_Get_A53_CORE_DIV10_CLK_Frequency, funcdef_no=41, decl_uid=6465, cgraph_uid=42, symbol_order=94)

Modification phase of node Clock_Ip_Get_A53_CORE_DIV10_CLK_Frequency/94
Clock_Ip_Get_A53_CORE_DIV10_CLK_Frequency ()
{
  long unsigned int _1;
  uint32 _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = Clock_Ip_Get_A53_CORE_CLK_Frequency ();
  _4 = _1 / 10;
  return _4;

}



;; Function Clock_Ip_Get_ACCEL_CLK_Frequency (Clock_Ip_Get_ACCEL_CLK_Frequency, funcdef_no=42, decl_uid=6467, cgraph_uid=43, symbol_order=95)

Modification phase of node Clock_Ip_Get_ACCEL_CLK_Frequency/95
Clock_Ip_Get_ACCEL_CLK_Frequency ()
{
  uint32 Frequency;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  uint32 (*<T752>) (void) _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct MC_CGM_Type *)1141669888B].MUX_1_CSS;
  _2 = _1 >> 24;
  _3 = _2 & 63;
  _4 = Clock_Ip_apfFreqTableClkSrc[_3];
  Frequency_7 = _4 ();
  # DEBUG Frequency => Frequency_7
  # DEBUG BEGIN_STMT
  return Frequency_7;

}



;; Function Clock_Ip_Get_ACCEL_DIV3_CLK_Frequency (Clock_Ip_Get_ACCEL_DIV3_CLK_Frequency, funcdef_no=43, decl_uid=6469, cgraph_uid=44, symbol_order=96)

Modification phase of node Clock_Ip_Get_ACCEL_DIV3_CLK_Frequency/96
Clock_Ip_Get_ACCEL_DIV3_CLK_Frequency ()
{
  long unsigned int _1;
  uint32 _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = Clock_Ip_Get_ACCEL_CLK_Frequency ();
  _4 = _1 / 3;
  return _4;

}



;; Function Clock_Ip_Get_ACCEL_XBAR_CLK_Frequency (Clock_Ip_Get_ACCEL_XBAR_CLK_Frequency, funcdef_no=44, decl_uid=6471, cgraph_uid=45, symbol_order=97)

Modification phase of node Clock_Ip_Get_ACCEL_XBAR_CLK_Frequency/97
Clock_Ip_Get_ACCEL_XBAR_CLK_Frequency ()
{
  uint32 Frequency;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  uint32 (*<T752>) (void) _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct MC_CGM_Type *)1141669888B].MUX_2_CSS;
  _2 = _1 >> 24;
  _3 = _2 & 63;
  _4 = Clock_Ip_apfFreqTableClkSrc[_3];
  Frequency_7 = _4 ();
  # DEBUG Frequency => Frequency_7
  # DEBUG BEGIN_STMT
  return Frequency_7;

}



;; Function Clock_Ip_Get_ACCEL_XBAR_DIV2_CLK_Frequency (Clock_Ip_Get_ACCEL_XBAR_DIV2_CLK_Frequency, funcdef_no=45, decl_uid=6473, cgraph_uid=46, symbol_order=98)

Modification phase of node Clock_Ip_Get_ACCEL_XBAR_DIV2_CLK_Frequency/98
Clock_Ip_Get_ACCEL_XBAR_DIV2_CLK_Frequency ()
{
  long unsigned int _1;
  uint32 _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = Clock_Ip_Get_ACCEL_XBAR_CLK_Frequency ();
  _4 = _1 >> 1;
  return _4;

}



;; Function Clock_Ip_Get_ACCEL_XBAR_DIV4_CLK_Frequency (Clock_Ip_Get_ACCEL_XBAR_DIV4_CLK_Frequency, funcdef_no=46, decl_uid=6475, cgraph_uid=47, symbol_order=99)

Modification phase of node Clock_Ip_Get_ACCEL_XBAR_DIV4_CLK_Frequency/99
Clock_Ip_Get_ACCEL_XBAR_DIV4_CLK_Frequency ()
{
  long unsigned int _1;
  uint32 _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = Clock_Ip_Get_ACCEL_XBAR_CLK_Frequency ();
  _4 = _1 >> 2;
  return _4;

}



;; Function Clock_Ip_Get_ACCEL_XBAR_DIV8_CLK_Frequency (Clock_Ip_Get_ACCEL_XBAR_DIV8_CLK_Frequency, funcdef_no=47, decl_uid=6477, cgraph_uid=48, symbol_order=100)

Modification phase of node Clock_Ip_Get_ACCEL_XBAR_DIV8_CLK_Frequency/100
Clock_Ip_Get_ACCEL_XBAR_DIV8_CLK_Frequency ()
{
  long unsigned int _1;
  uint32 _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = Clock_Ip_Get_ACCEL_XBAR_CLK_Frequency ();
  _4 = _1 >> 3;
  return _4;

}



;; Function Clock_Ip_Get_GMAC0_REF_CLK_Frequency (Clock_Ip_Get_GMAC0_REF_CLK_Frequency, funcdef_no=48, decl_uid=6481, cgraph_uid=49, symbol_order=101)

Modification phase of node Clock_Ip_Get_GMAC0_REF_CLK_Frequency/101
Clock_Ip_Get_GMAC0_REF_CLK_Frequency ()
{
  uint32 Frequency;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  uint32 (*<T752>) (void) _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct MC_CGM_Type *)1074774016B].MUX_3_CSS;
  _2 = _1 >> 24;
  _3 = _2 & 63;
  _4 = Clock_Ip_apfFreqTableClkSrc[_3];
  Frequency_7 = _4 ();
  # DEBUG Frequency => Frequency_7
  # DEBUG BEGIN_STMT
  return Frequency_7;

}



;; Function Clock_Ip_Get_GMAC0_REF_DIV_CLK_Frequency (Clock_Ip_Get_GMAC0_REF_DIV_CLK_Frequency, funcdef_no=49, decl_uid=6483, cgraph_uid=50, symbol_order=102)

Modification phase of node Clock_Ip_Get_GMAC0_REF_DIV_CLK_Frequency/102
Clock_Ip_Get_GMAC0_REF_DIV_CLK_Frequency ()
{
  uint32 Frequency;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  uint32 (*<T752>) (void) _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _13;
  long unsigned int _15;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct MC_CGM_Type *)1074774016B].MUX_3_CSS;
  _2 = _1 >> 24;
  _3 = _2 & 63;
  _4 = Clock_Ip_apfTableClockGeneration[_3];
  Frequency_12 = _4 ();
  # DEBUG Frequency => Frequency_12
  # DEBUG BEGIN_STMT
  _5 ={v} MEM[(struct MC_CGM_Type *)1074774016B].MUX_3_DC_0;
  _6 = _5 >> 31;
  _13 = Clock_Ip_u32EnableDivider[_6];
  Frequency_14 = Frequency_12 & _13;
  # DEBUG Frequency => Frequency_14
  # DEBUG BEGIN_STMT
  _7 ={v} MEM[(struct MC_CGM_Type *)1074774016B].MUX_3_DC_0;
  _8 = _7 >> 16;
  _9 = _8 & 255;
  _15 = _9 + 1;
  Frequency_16 = Frequency_14 / _15;
  # DEBUG Frequency => Frequency_16
  # DEBUG BEGIN_STMT
  return Frequency_16;

}



;; Function Clock_Ip_Get_GMAC1_REF_CLK_Frequency (Clock_Ip_Get_GMAC1_REF_CLK_Frequency, funcdef_no=50, decl_uid=6485, cgraph_uid=51, symbol_order=103)

Modification phase of node Clock_Ip_Get_GMAC1_REF_CLK_Frequency/103
Clock_Ip_Get_GMAC1_REF_CLK_Frequency ()
{
  uint32 Frequency;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  uint32 (*<T752>) (void) _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct MC_CGM_2_Type *)1141391360B].MUX_3_CSS;
  _2 = _1 >> 24;
  _3 = _2 & 63;
  _4 = Clock_Ip_apfFreqTableClkSrc[_3];
  Frequency_7 = _4 ();
  # DEBUG Frequency => Frequency_7
  # DEBUG BEGIN_STMT
  return Frequency_7;

}



;; Function Clock_Ip_Get_GMAC1_REF_DIV_CLK_Frequency (Clock_Ip_Get_GMAC1_REF_DIV_CLK_Frequency, funcdef_no=51, decl_uid=6487, cgraph_uid=52, symbol_order=104)

Modification phase of node Clock_Ip_Get_GMAC1_REF_DIV_CLK_Frequency/104
Clock_Ip_Get_GMAC1_REF_DIV_CLK_Frequency ()
{
  uint32 Frequency;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  uint32 (*<T752>) (void) _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _13;
  long unsigned int _15;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct MC_CGM_2_Type *)1141391360B].MUX_3_CSS;
  _2 = _1 >> 24;
  _3 = _2 & 63;
  _4 = Clock_Ip_apfTableClockGeneration[_3];
  Frequency_12 = _4 ();
  # DEBUG Frequency => Frequency_12
  # DEBUG BEGIN_STMT
  _5 ={v} MEM[(struct MC_CGM_2_Type *)1141391360B].MUX_3_DC_0;
  _6 = _5 >> 31;
  _13 = Clock_Ip_u32EnableDivider[_6];
  Frequency_14 = Frequency_12 & _13;
  # DEBUG Frequency => Frequency_14
  # DEBUG BEGIN_STMT
  _7 ={v} MEM[(struct MC_CGM_2_Type *)1141391360B].MUX_3_DC_0;
  _8 = _7 >> 16;
  _9 = _8 & 255;
  _15 = _9 + 1;
  Frequency_16 = Frequency_14 / _15;
  # DEBUG Frequency => Frequency_16
  # DEBUG BEGIN_STMT
  return Frequency_16;

}



;; Function Clock_Ip_Get_GMAC1_INT_CLK_Frequency (Clock_Ip_Get_GMAC1_INT_CLK_Frequency, funcdef_no=53, decl_uid=6491, cgraph_uid=54, symbol_order=106)

Modification phase of node Clock_Ip_Get_GMAC1_INT_CLK_Frequency/106
Clock_Ip_Get_GMAC1_INT_CLK_Frequency ()
{
  uint32 Frequency;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  uint32 (*<T752>) (void) _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct MC_CGM_0_Type *)1074561024B].MUX_6_CSS;
  _2 = _1 >> 24;
  _3 = _2 & 31;
  _4 = Clock_Ip_apfTableClockGeneration[_3];
  Frequency_7 = _4 ();
  # DEBUG Frequency => Frequency_7
  # DEBUG BEGIN_STMT
  return Frequency_7;

}



;; Function Clock_Ip_Get_BBE32EP_DSP_CLK_Frequency (Clock_Ip_Get_BBE32EP_DSP_CLK_Frequency, funcdef_no=54, decl_uid=6493, cgraph_uid=55, symbol_order=107)

Modification phase of node Clock_Ip_Get_BBE32EP_DSP_CLK_Frequency/107
Clock_Ip_Get_BBE32EP_DSP_CLK_Frequency ()
{
  uint32 Frequency;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  uint32 (*<T752>) (void) _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _10;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct MC_CGM_Type *)1141669888B].MUX_1_CSS;
  _2 = _1 >> 24;
  _3 = _2 & 63;
  _4 = Clock_Ip_apfFreqTableClkSrc[_3];
  Frequency_9 = _4 ();
  # DEBUG Frequency => Frequency_9
  # DEBUG BEGIN_STMT
  _5 ={v} MEM[(struct MC_ME_Type *)1074593792B].PRTN1_COFB0_STAT;
  _6 = _5 & 1;
  _10 = Clock_Ip_u32EnableGate[_6];
  Frequency_11 = Frequency_9 & _10;
  # DEBUG Frequency => Frequency_11
  # DEBUG BEGIN_STMT
  return Frequency_11;

}



;; Function Clock_Ip_Get_CAN_CHI_CLK_Frequency (Clock_Ip_Get_CAN_CHI_CLK_Frequency, funcdef_no=55, decl_uid=6495, cgraph_uid=56, symbol_order=108)

Modification phase of node Clock_Ip_Get_CAN_CHI_CLK_Frequency/108
Clock_Ip_Get_CAN_CHI_CLK_Frequency ()
{
  uint32 Frequency;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  uint32 (*<T752>) (void) _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _13;
  long unsigned int _15;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct MC_CGM_0_Type *)1074561024B].MUX_6_CSS;
  _2 = _1 >> 24;
  _3 = _2 & 31;
  _4 = Clock_Ip_apfFreqTableClkSrc[_3];
  Frequency_12 = _4 ();
  # DEBUG Frequency => Frequency_12
  # DEBUG BEGIN_STMT
  _5 ={v} MEM[(struct MC_CGM_0_Type *)1074561024B].MUX_6_DC_1;
  _6 = _5 >> 31;
  _13 = Clock_Ip_u32EnableDivider[_6];
  Frequency_14 = Frequency_12 & _13;
  # DEBUG Frequency => Frequency_14
  # DEBUG BEGIN_STMT
  _7 ={v} MEM[(struct MC_CGM_0_Type *)1074561024B].MUX_6_DC_1;
  _8 = _7 >> 16;
  _9 = _8 & 255;
  _15 = _9 + 1;
  Frequency_16 = Frequency_14 / _15;
  # DEBUG Frequency => Frequency_16
  # DEBUG BEGIN_STMT
  return Frequency_16;

}



;; Function Clock_Ip_Get_CAN_TS_CLK_Frequency (Clock_Ip_Get_CAN_TS_CLK_Frequency, funcdef_no=56, decl_uid=6499, cgraph_uid=57, symbol_order=109)

Modification phase of node Clock_Ip_Get_CAN_TS_CLK_Frequency/109
Clock_Ip_Get_CAN_TS_CLK_Frequency ()
{
  uint32 Frequency;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  uint32 (*<T752>) (void) _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _13;
  long unsigned int _15;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct MC_CGM_0_Type *)1074561024B].MUX_6_CSS;
  _2 = _1 >> 24;
  _3 = _2 & 31;
  _4 = Clock_Ip_apfFreqTableClkSrc[_3];
  Frequency_12 = _4 ();
  # DEBUG Frequency => Frequency_12
  # DEBUG BEGIN_STMT
  _5 ={v} MEM[(struct MC_CGM_0_Type *)1074561024B].MUX_6_DC_0;
  _6 = _5 >> 31;
  _13 = Clock_Ip_u32EnableDivider[_6];
  Frequency_14 = Frequency_12 & _13;
  # DEBUG Frequency => Frequency_14
  # DEBUG BEGIN_STMT
  _7 ={v} MEM[(struct MC_CGM_0_Type *)1074561024B].MUX_6_DC_0;
  _8 = _7 >> 16;
  _9 = _8 & 255;
  _15 = _9 + 1;
  Frequency_16 = Frequency_14 / _15;
  # DEBUG Frequency => Frequency_16
  # DEBUG BEGIN_STMT
  return Frequency_16;

}



;; Function Clock_Ip_Get_CAN_PE_CLK_Frequency (Clock_Ip_Get_CAN_PE_CLK_Frequency, funcdef_no=57, decl_uid=6497, cgraph_uid=58, symbol_order=110)

Modification phase of node Clock_Ip_Get_CAN_PE_CLK_Frequency/110
Clock_Ip_Get_CAN_PE_CLK_Frequency ()
{
  uint32 Frequency;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  uint32 (*<T752>) (void) _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct MC_CGM_0_Type *)1074561024B].MUX_7_CSS;
  _2 = _1 >> 24;
  _3 = _2 & 31;
  _4 = Clock_Ip_apfFreqTableClkSrc[_3];
  Frequency_7 = _4 ();
  # DEBUG Frequency => Frequency_7
  # DEBUG BEGIN_STMT
  return Frequency_7;

}



;; Function Clock_Ip_Get_CLKOUT0_CLK_Frequency (Clock_Ip_Get_CLKOUT0_CLK_Frequency, funcdef_no=58, decl_uid=6501, cgraph_uid=59, symbol_order=111)

Modification phase of node Clock_Ip_Get_CLKOUT0_CLK_Frequency/111
Clock_Ip_Get_CLKOUT0_CLK_Frequency ()
{
  uint32 Frequency;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  uint32 (*<T752>) (void) _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _13;
  long unsigned int _15;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct MC_CGM_0_Type *)1074561024B].MUX_1_CSS;
  _2 = _1 >> 24;
  _3 = _2 & 63;
  _4 = Clock_Ip_apfFreqTableClkSrc[_3];
  Frequency_12 = _4 ();
  # DEBUG Frequency => Frequency_12
  # DEBUG BEGIN_STMT
  _5 ={v} MEM[(struct MC_CGM_0_Type *)1074561024B].MUX_1_DC_0;
  _6 = _5 >> 31;
  _13 = Clock_Ip_u32EnableDivider[_6];
  Frequency_14 = Frequency_12 & _13;
  # DEBUG Frequency => Frequency_14
  # DEBUG BEGIN_STMT
  _7 ={v} MEM[(struct MC_CGM_0_Type *)1074561024B].MUX_1_DC_0;
  _8 = _7 >> 16;
  _9 = _8 & 255;
  _15 = _9 + 1;
  Frequency_16 = Frequency_14 / _15;
  # DEBUG Frequency => Frequency_16
  # DEBUG BEGIN_STMT
  return Frequency_16;

}



;; Function Clock_Ip_Get_CLKOUT1_CLK_Frequency (Clock_Ip_Get_CLKOUT1_CLK_Frequency, funcdef_no=59, decl_uid=6503, cgraph_uid=60, symbol_order=112)

Modification phase of node Clock_Ip_Get_CLKOUT1_CLK_Frequency/112
Clock_Ip_Get_CLKOUT1_CLK_Frequency ()
{
  uint32 Frequency;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  uint32 (*<T752>) (void) _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _13;
  long unsigned int _15;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct MC_CGM_0_Type *)1074561024B].MUX_2_CSS;
  _2 = _1 >> 24;
  _3 = _2 & 63;
  _4 = Clock_Ip_apfFreqTableClkSrc[_3];
  Frequency_12 = _4 ();
  # DEBUG Frequency => Frequency_12
  # DEBUG BEGIN_STMT
  _5 ={v} MEM[(struct MC_CGM_0_Type *)1074561024B].MUX_2_DC_0;
  _6 = _5 >> 31;
  _13 = Clock_Ip_u32EnableDivider[_6];
  Frequency_14 = Frequency_12 & _13;
  # DEBUG Frequency => Frequency_14
  # DEBUG BEGIN_STMT
  _7 ={v} MEM[(struct MC_CGM_0_Type *)1074561024B].MUX_2_DC_0;
  _8 = _7 >> 16;
  _9 = _8 & 255;
  _15 = _9 + 1;
  Frequency_16 = Frequency_14 / _15;
  # DEBUG Frequency => Frequency_16
  # DEBUG BEGIN_STMT
  return Frequency_16;

}



;; Function Clock_Ip_Get_CSI_CLK_Frequency (Clock_Ip_Get_CSI_CLK_Frequency, funcdef_no=60, decl_uid=6505, cgraph_uid=61, symbol_order=113)

Modification phase of node Clock_Ip_Get_CSI_CLK_Frequency/113
Clock_Ip_Get_CSI_CLK_Frequency ()
{
  uint32 Frequency;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  uint32 (*<T752>) (void) _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct MC_CGM_Type *)1141669888B].MUX_4_CSS;
  _2 = _1 >> 24;
  _3 = _2 & 63;
  _4 = Clock_Ip_apfFreqTableClkSrc[_3];
  Frequency_7 = _4 ();
  # DEBUG Frequency => Frequency_7
  # DEBUG BEGIN_STMT
  return Frequency_7;

}



;; Function Clock_Ip_Get_CSI_CFG_CLK_Frequency (Clock_Ip_Get_CSI_CFG_CLK_Frequency, funcdef_no=61, decl_uid=6507, cgraph_uid=62, symbol_order=114)

Modification phase of node Clock_Ip_Get_CSI_CFG_CLK_Frequency/114
Clock_Ip_Get_CSI_CFG_CLK_Frequency ()
{
  uint32 Frequency;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  uint32 (*<T752>) (void) _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _13;
  long unsigned int _15;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct MC_CGM_Type *)1141669888B].MUX_4_CSS;
  _2 = _1 >> 24;
  _3 = _2 & 63;
  _4 = Clock_Ip_apfFreqTableClkSrc[_3];
  Frequency_12 = _4 ();
  # DEBUG Frequency => Frequency_12
  # DEBUG BEGIN_STMT
  _5 ={v} MEM[(struct MC_CGM_Type *)1141669888B].MUX_4_DC_0;
  _6 = _5 >> 31;
  _13 = Clock_Ip_u32EnableDivider[_6];
  Frequency_14 = Frequency_12 & _13;
  # DEBUG Frequency => Frequency_14
  # DEBUG BEGIN_STMT
  _7 ={v} MEM[(struct MC_CGM_Type *)1141669888B].MUX_4_DC_0;
  _8 = _7 >> 16;
  _9 = _8 & 255;
  _15 = _9 + 1;
  Frequency_16 = Frequency_14 / _15;
  # DEBUG Frequency => Frequency_16
  # DEBUG BEGIN_STMT
  return Frequency_16;

}



;; Function Clock_Ip_Get_CTE_CLK_Frequency (Clock_Ip_Get_CTE_CLK_Frequency, funcdef_no=62, decl_uid=6511, cgraph_uid=63, symbol_order=115)

Modification phase of node Clock_Ip_Get_CTE_CLK_Frequency/115
Clock_Ip_Get_CTE_CLK_Frequency ()
{
  uint32 Frequency;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  uint32 (*<T752>) (void) _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct MC_CGM_Type *)1141669888B].MUX_3_CSS;
  _2 = _1 >> 24;
  _3 = _2 & 63;
  _4 = Clock_Ip_apfFreqTableClkSrc[_3];
  Frequency_7 = _4 ();
  # DEBUG Frequency => Frequency_7
  # DEBUG BEGIN_STMT
  return Frequency_7;

}



;; Function Clock_Ip_Get_CSI_TXCLK_CLK_Frequency (Clock_Ip_Get_CSI_TXCLK_CLK_Frequency, funcdef_no=63, decl_uid=6509, cgraph_uid=64, symbol_order=116)

Modification phase of node Clock_Ip_Get_CSI_TXCLK_CLK_Frequency/116
Clock_Ip_Get_CSI_TXCLK_CLK_Frequency ()
{
  uint32 Frequency;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  uint32 (*<T752>) (void) _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _13;
  long unsigned int _15;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct MC_CGM_Type *)1141669888B].MUX_4_CSS;
  _2 = _1 >> 24;
  _3 = _2 & 63;
  _4 = Clock_Ip_apfFreqTableClkSrc[_3];
  Frequency_12 = _4 ();
  # DEBUG Frequency => Frequency_12
  # DEBUG BEGIN_STMT
  _5 ={v} MEM[(struct MC_CGM_Type *)1141669888B].MUX_4_DC_1;
  _6 = _5 >> 31;
  _13 = Clock_Ip_u32EnableDivider[_6];
  Frequency_14 = Frequency_12 & _13;
  # DEBUG Frequency => Frequency_14
  # DEBUG BEGIN_STMT
  _7 ={v} MEM[(struct MC_CGM_Type *)1141669888B].MUX_4_DC_1;
  _8 = _7 >> 16;
  _9 = _8 & 255;
  _15 = _9 + 1;
  Frequency_16 = Frequency_14 / _15;
  # DEBUG Frequency => Frequency_16
  # DEBUG BEGIN_STMT
  return Frequency_16;

}



;; Function Clock_Ip_Get_MC_CLK_Frequency (Clock_Ip_Get_MC_CLK_Frequency, funcdef_no=64, decl_uid=6541, cgraph_uid=65, symbol_order=117)

Modification phase of node Clock_Ip_Get_MC_CLK_Frequency/117
Clock_Ip_Get_MC_CLK_Frequency ()
{
  uint32 Frequency;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  uint32 (*<T752>) (void) _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct MC_CGM_0_Type *)1074561024B].MUX_3_CSS;
  _2 = _1 >> 24;
  _3 = _2 & 31;
  _4 = Clock_Ip_apfFreqTableClkSrc[_3];
  Frequency_7 = _4 ();
  # DEBUG Frequency => Frequency_7
  # DEBUG BEGIN_STMT
  return Frequency_7;

}



;; Function Clock_Ip_Get_CTU_IPS_CLK_Frequency (Clock_Ip_Get_CTU_IPS_CLK_Frequency, funcdef_no=97, decl_uid=6513, cgraph_uid=66, symbol_order=118)

Modification phase of node Clock_Ip_Get_CTU_IPS_CLK_Frequency/118
Clock_Ip_Get_CTU_IPS_CLK_Frequency ()
{
  uint32 retval.164;

  <bb 2> [local count: 1073741824]:
  retval.164_3 = Clock_Ip_Get_CAN_CHI_CLK_Frequency (); [tail call]
  return retval.164_3;

}



;; Function Clock_Ip_Get_DAPB_CLK_Frequency (Clock_Ip_Get_DAPB_CLK_Frequency, funcdef_no=66, decl_uid=6515, cgraph_uid=67, symbol_order=119)

Modification phase of node Clock_Ip_Get_DAPB_CLK_Frequency/119
Clock_Ip_Get_DAPB_CLK_Frequency ()
{
  uint32 Frequency;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  uint32 (*<T752>) (void) _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _13;
  long unsigned int _15;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct MC_CGM_0_Type *)1074561024B].MUX_6_CSS;
  _2 = _1 >> 24;
  _3 = _2 & 31;
  _4 = Clock_Ip_apfFreqTableClkSrc[_3];
  Frequency_12 = _4 ();
  # DEBUG Frequency => Frequency_12
  # DEBUG BEGIN_STMT
  _5 ={v} MEM[(struct MC_CGM_0_Type *)1074561024B].MUX_6_DC_4;
  _6 = _5 >> 31;
  _13 = Clock_Ip_u32EnableDivider[_6];
  Frequency_14 = Frequency_12 & _13;
  # DEBUG Frequency => Frequency_14
  # DEBUG BEGIN_STMT
  _7 ={v} MEM[(struct MC_CGM_0_Type *)1074561024B].MUX_6_DC_4;
  _8 = _7 >> 16;
  _9 = _8 & 255;
  _15 = _9 + 1;
  Frequency_16 = Frequency_14 / _15;
  # DEBUG Frequency => Frequency_16
  # DEBUG BEGIN_STMT
  return Frequency_16;

}



;; Function Clock_Ip_Get_DSPI_SCK_TST_CLK_Frequency (Clock_Ip_Get_DSPI_SCK_TST_CLK_Frequency, funcdef_no=67, decl_uid=6517, cgraph_uid=68, symbol_order=120)

Modification phase of node Clock_Ip_Get_DSPI_SCK_TST_CLK_Frequency/120
Clock_Ip_Get_DSPI_SCK_TST_CLK_Frequency ()
{
  uint32 Frequency;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  uint32 (*<T752>) (void) _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _13;
  long unsigned int _15;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct MC_CGM_0_Type *)1074561024B].MUX_6_CSS;
  _2 = _1 >> 24;
  _3 = _2 & 31;
  _4 = Clock_Ip_apfFreqTableClkSrc[_3];
  Frequency_12 = _4 ();
  # DEBUG Frequency => Frequency_12
  # DEBUG BEGIN_STMT
  _5 ={v} MEM[(struct MC_CGM_0_Type *)1074561024B].MUX_6_DC_3;
  _6 = _5 >> 31;
  _13 = Clock_Ip_u32EnableDivider[_6];
  Frequency_14 = Frequency_12 & _13;
  # DEBUG Frequency => Frequency_14
  # DEBUG BEGIN_STMT
  _7 ={v} MEM[(struct MC_CGM_0_Type *)1074561024B].MUX_6_DC_3;
  _8 = _7 >> 16;
  _9 = _8 & 255;
  _15 = _9 + 1;
  Frequency_16 = Frequency_14 / _15;
  # DEBUG Frequency => Frequency_16
  # DEBUG BEGIN_STMT
  return Frequency_16;

}



;; Function Clock_Ip_Get_FCCU_IPS_CLK_Frequency (Clock_Ip_Get_FCCU_IPS_CLK_Frequency, funcdef_no=99, decl_uid=6519, cgraph_uid=69, symbol_order=121)

Modification phase of node Clock_Ip_Get_FCCU_IPS_CLK_Frequency/121
Clock_Ip_Get_FCCU_IPS_CLK_Frequency ()
{
  uint32 retval.165;

  <bb 2> [local count: 1073741824]:
  retval.165_3 = Clock_Ip_Get_CAN_CHI_CLK_Frequency (); [tail call]
  return retval.165_3;

}



;; Function Clock_Ip_Get_FTM0_EXT_CLK_Frequency (Clock_Ip_Get_FTM0_EXT_CLK_Frequency, funcdef_no=69, decl_uid=6521, cgraph_uid=70, symbol_order=122)

Modification phase of node Clock_Ip_Get_FTM0_EXT_CLK_Frequency/122
Clock_Ip_Get_FTM0_EXT_CLK_Frequency ()
{
  uint32 Frequency;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  uint32 (*<T752>) (void) _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _13;
  long unsigned int _15;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct MC_CGM_Type *)1074774016B].MUX_0_CSS;
  _2 = _1 >> 24;
  _3 = _2 & 63;
  _4 = Clock_Ip_apfFreqTableClkSrc[_3];
  Frequency_12 = _4 ();
  # DEBUG Frequency => Frequency_12
  # DEBUG BEGIN_STMT
  _5 ={v} MEM[(struct MC_CGM_Type *)1074774016B].MUX_0_DC_0;
  _6 = _5 >> 31;
  _13 = Clock_Ip_u32EnableDivider[_6];
  Frequency_14 = Frequency_12 & _13;
  # DEBUG Frequency => Frequency_14
  # DEBUG BEGIN_STMT
  _7 ={v} MEM[(struct MC_CGM_Type *)1074774016B].MUX_0_DC_0;
  _8 = _7 >> 16;
  _9 = _8 & 255;
  _15 = _9 + 1;
  Frequency_16 = Frequency_14 / _15;
  # DEBUG Frequency => Frequency_16
  # DEBUG BEGIN_STMT
  return Frequency_16;

}



;; Function Clock_Ip_Get_GMAC0_RX_CLK_Frequency (Clock_Ip_Get_GMAC0_RX_CLK_Frequency, funcdef_no=70, decl_uid=6523, cgraph_uid=71, symbol_order=123)

Modification phase of node Clock_Ip_Get_GMAC0_RX_CLK_Frequency/123
Clock_Ip_Get_GMAC0_RX_CLK_Frequency ()
{
  uint32 Frequency;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  uint32 (*<T752>) (void) _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct MC_CGM_Type *)1074774016B].MUX_4_CSS;
  _2 = _1 >> 24;
  _3 = _2 & 63;
  _4 = Clock_Ip_apfFreqTableClkSrc[_3];
  Frequency_7 = _4 ();
  # DEBUG Frequency => Frequency_7
  # DEBUG BEGIN_STMT
  return Frequency_7;

}



;; Function Clock_Ip_Get_GMAC0_TS_CLK_Frequency (Clock_Ip_Get_GMAC0_TS_CLK_Frequency, funcdef_no=71, decl_uid=6525, cgraph_uid=72, symbol_order=124)

Modification phase of node Clock_Ip_Get_GMAC0_TS_CLK_Frequency/124
Clock_Ip_Get_GMAC0_TS_CLK_Frequency ()
{
  uint32 Frequency;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  uint32 (*<T752>) (void) _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _13;
  long unsigned int _15;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct MC_CGM_Type *)1074774016B].MUX_1_CSS;
  _2 = _1 >> 24;
  _3 = _2 & 63;
  _4 = Clock_Ip_apfFreqTableClkSrc[_3];
  Frequency_12 = _4 ();
  # DEBUG Frequency => Frequency_12
  # DEBUG BEGIN_STMT
  _5 ={v} MEM[(struct MC_CGM_Type *)1074774016B].MUX_1_DC_0;
  _6 = _5 >> 31;
  _13 = Clock_Ip_u32EnableDivider[_6];
  Frequency_14 = Frequency_12 & _13;
  # DEBUG Frequency => Frequency_14
  # DEBUG BEGIN_STMT
  _7 ={v} MEM[(struct MC_CGM_Type *)1074774016B].MUX_1_DC_0;
  _8 = _7 >> 16;
  _9 = _8 & 255;
  _15 = _9 + 1;
  Frequency_16 = Frequency_14 / _15;
  # DEBUG Frequency => Frequency_16
  # DEBUG BEGIN_STMT
  return Frequency_16;

}



;; Function Clock_Ip_Get_GMAC0_TX_CLK_Frequency (Clock_Ip_Get_GMAC0_TX_CLK_Frequency, funcdef_no=72, decl_uid=6527, cgraph_uid=73, symbol_order=125)

Modification phase of node Clock_Ip_Get_GMAC0_TX_CLK_Frequency/125
Clock_Ip_Get_GMAC0_TX_CLK_Frequency ()
{
  uint32 Frequency;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  uint32 (*<T752>) (void) _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct MC_CGM_Type *)1074774016B].MUX_2_CSS;
  _2 = _1 >> 24;
  _3 = _2 & 63;
  _4 = Clock_Ip_apfFreqTableClkSrc[_3];
  Frequency_7 = _4 ();
  # DEBUG Frequency => Frequency_7
  # DEBUG BEGIN_STMT
  return Frequency_7;

}



;; Function Clock_Ip_Get_GMAC1_RX_CLK_Frequency (Clock_Ip_Get_GMAC1_RX_CLK_Frequency, funcdef_no=73, decl_uid=6529, cgraph_uid=74, symbol_order=126)

Modification phase of node Clock_Ip_Get_GMAC1_RX_CLK_Frequency/126
Clock_Ip_Get_GMAC1_RX_CLK_Frequency ()
{
  uint32 Frequency;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  uint32 (*<T752>) (void) _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct MC_CGM_2_Type *)1141391360B].MUX_4_CSS;
  _2 = _1 >> 24;
  _3 = _2 & 63;
  _4 = Clock_Ip_apfFreqTableClkSrc[_3];
  Frequency_7 = _4 ();
  # DEBUG Frequency => Frequency_7
  # DEBUG BEGIN_STMT
  return Frequency_7;

}



;; Function Clock_Ip_Get_GMAC1_TS_CLK_Frequency (Clock_Ip_Get_GMAC1_TS_CLK_Frequency, funcdef_no=74, decl_uid=6531, cgraph_uid=75, symbol_order=127)

Modification phase of node Clock_Ip_Get_GMAC1_TS_CLK_Frequency/127
Clock_Ip_Get_GMAC1_TS_CLK_Frequency ()
{
  uint32 Frequency;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  uint32 (*<T752>) (void) _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _13;
  long unsigned int _15;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct MC_CGM_2_Type *)1141391360B].MUX_1_CSS;
  _2 = _1 >> 24;
  _3 = _2 & 63;
  _4 = Clock_Ip_apfFreqTableClkSrc[_3];
  Frequency_12 = _4 ();
  # DEBUG Frequency => Frequency_12
  # DEBUG BEGIN_STMT
  _5 ={v} MEM[(struct MC_CGM_2_Type *)1141391360B].MUX_1_DC_0;
  _6 = _5 >> 31;
  _13 = Clock_Ip_u32EnableDivider[_6];
  Frequency_14 = Frequency_12 & _13;
  # DEBUG Frequency => Frequency_14
  # DEBUG BEGIN_STMT
  _7 ={v} MEM[(struct MC_CGM_2_Type *)1141391360B].MUX_1_DC_0;
  _8 = _7 >> 16;
  _9 = _8 & 255;
  _15 = _9 + 1;
  Frequency_16 = Frequency_14 / _15;
  # DEBUG Frequency => Frequency_16
  # DEBUG BEGIN_STMT
  return Frequency_16;

}



;; Function Clock_Ip_Get_GMAC1_TX_CLK_Frequency (Clock_Ip_Get_GMAC1_TX_CLK_Frequency, funcdef_no=75, decl_uid=6533, cgraph_uid=76, symbol_order=128)

Modification phase of node Clock_Ip_Get_GMAC1_TX_CLK_Frequency/128
Clock_Ip_Get_GMAC1_TX_CLK_Frequency ()
{
  uint32 Frequency;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  uint32 (*<T752>) (void) _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _13;
  long unsigned int _15;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct MC_CGM_2_Type *)1141391360B].MUX_2_CSS;
  _2 = _1 >> 24;
  _3 = _2 & 63;
  _4 = Clock_Ip_apfFreqTableClkSrc[_3];
  Frequency_12 = _4 ();
  # DEBUG Frequency => Frequency_12
  # DEBUG BEGIN_STMT
  _5 ={v} MEM[(struct MC_CGM_2_Type *)1141391360B].MUX_2_DC_0;
  _6 = _5 >> 31;
  _13 = Clock_Ip_u32EnableDivider[_6];
  Frequency_14 = Frequency_12 & _13;
  # DEBUG Frequency => Frequency_14
  # DEBUG BEGIN_STMT
  _7 ={v} MEM[(struct MC_CGM_2_Type *)1141391360B].MUX_2_DC_0;
  _8 = _7 >> 16;
  _9 = _8 & 255;
  _15 = _9 + 1;
  Frequency_16 = Frequency_14 / _15;
  # DEBUG Frequency => Frequency_16
  # DEBUG BEGIN_STMT
  return Frequency_16;

}



;; Function Clock_Ip_Get_LBIST_CLK_Frequency (Clock_Ip_Get_LBIST_CLK_Frequency, funcdef_no=76, decl_uid=6535, cgraph_uid=77, symbol_order=129)

Modification phase of node Clock_Ip_Get_LBIST_CLK_Frequency/129
Clock_Ip_Get_LBIST_CLK_Frequency ()
{
  uint32 Frequency;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  uint32 (*<T752>) (void) _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _13;
  long unsigned int _15;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct MC_CGM_Type *)1141669888B].MUX_6_CSS;
  _2 = _1 >> 24;
  _3 = _2 & 15;
  _4 = Clock_Ip_apfFreqTableClkSrc[_3];
  Frequency_12 = _4 ();
  # DEBUG Frequency => Frequency_12
  # DEBUG BEGIN_STMT
  _5 ={v} MEM[(struct MC_CGM_Type *)1141669888B].MUX_6_DC_0;
  _6 = _5 >> 31;
  _13 = Clock_Ip_u32EnableDivider[_6];
  Frequency_14 = Frequency_12 & _13;
  # DEBUG Frequency => Frequency_14
  # DEBUG BEGIN_STMT
  _7 ={v} MEM[(struct MC_CGM_Type *)1141669888B].MUX_6_DC_0;
  _8 = _7 >> 16;
  _9 = _8 & 255;
  _15 = _9 + 1;
  Frequency_16 = Frequency_14 / _15;
  # DEBUG Frequency => Frequency_16
  # DEBUG BEGIN_STMT
  return Frequency_16;

}



;; Function Clock_Ip_Get_LIN_BAUD_CLK_Frequency (Clock_Ip_Get_LIN_BAUD_CLK_Frequency, funcdef_no=77, decl_uid=6537, cgraph_uid=78, symbol_order=130)

Modification phase of node Clock_Ip_Get_LIN_BAUD_CLK_Frequency/130
Clock_Ip_Get_LIN_BAUD_CLK_Frequency ()
{
  uint32 Frequency;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  uint32 (*<T752>) (void) _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct MC_CGM_0_Type *)1074561024B].MUX_8_CSS;
  _2 = _1 >> 24;
  _3 = _2 & 31;
  _4 = Clock_Ip_apfFreqTableClkSrc[_3];
  Frequency_7 = _4 ();
  # DEBUG Frequency => Frequency_7
  # DEBUG BEGIN_STMT
  return Frequency_7;

}



;; Function Clock_Ip_Get_LINFLEXD_CLK_Frequency (Clock_Ip_Get_LINFLEXD_CLK_Frequency, funcdef_no=78, decl_uid=6539, cgraph_uid=79, symbol_order=131)

Modification phase of node Clock_Ip_Get_LINFLEXD_CLK_Frequency/131
Clock_Ip_Get_LINFLEXD_CLK_Frequency ()
{
  long unsigned int _1;
  uint32 _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = Clock_Ip_Get_LIN_BAUD_CLK_Frequency ();
  _4 = _1 >> 1;
  return _4;

}



;; Function Clock_Ip_Get_MIPICSI2_0_CLK_Frequency (Clock_Ip_Get_MIPICSI2_0_CLK_Frequency, funcdef_no=79, decl_uid=6543, cgraph_uid=80, symbol_order=132)

Modification phase of node Clock_Ip_Get_MIPICSI2_0_CLK_Frequency/132
Clock_Ip_Get_MIPICSI2_0_CLK_Frequency ()
{
  uint32 Frequency;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  uint32 (*<T752>) (void) _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _11;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct MC_CGM_Type *)1141669888B].MUX_3_CSS;
  _2 = _1 >> 24;
  _3 = _2 & 63;
  _4 = Clock_Ip_apfFreqTableClkSrc[_3];
  Frequency_10 = _4 ();
  # DEBUG Frequency => Frequency_10
  # DEBUG BEGIN_STMT
  _5 ={v} MEM[(struct MC_ME_Type *)1074593792B].PRTN1_COFB0_STAT;
  _6 = _5 >> 2;
  _7 = _6 & 1;
  _11 = Clock_Ip_u32EnableGate[_7];
  Frequency_12 = Frequency_10 & _11;
  # DEBUG Frequency => Frequency_12
  # DEBUG BEGIN_STMT
  return Frequency_12;

}



;; Function Clock_Ip_Get_MIPICSI2_1_CLK_Frequency (Clock_Ip_Get_MIPICSI2_1_CLK_Frequency, funcdef_no=107, decl_uid=6545, cgraph_uid=81, symbol_order=133)

Modification phase of node Clock_Ip_Get_MIPICSI2_1_CLK_Frequency/133
Clock_Ip_Get_MIPICSI2_1_CLK_Frequency ()
{
  uint32 retval.169;

  <bb 2> [local count: 1073741824]:
  retval.169_3 = Clock_Ip_Get_MIPICSI2_0_CLK_Frequency (); [tail call]
  return retval.169_3;

}



;; Function Clock_Ip_Get_NOC_TRACE_CLK_Frequency (Clock_Ip_Get_NOC_TRACE_CLK_Frequency, funcdef_no=81, decl_uid=6547, cgraph_uid=82, symbol_order=134)

Modification phase of node Clock_Ip_Get_NOC_TRACE_CLK_Frequency/134
Clock_Ip_Get_NOC_TRACE_CLK_Frequency ()
{
  uint32 Frequency;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  uint32 (*<T752>) (void) _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct MC_CGM_Type *)1141669888B].MUX_5_CSS;
  _2 = _1 >> 24;
  _3 = _2 & 31;
  _4 = Clock_Ip_apfFreqTableClkSrc[_3];
  Frequency_7 = _4 ();
  # DEBUG Frequency => Frequency_7
  # DEBUG BEGIN_STMT
  return Frequency_7;

}



;; Function Clock_Ip_Get_QSPI_2X_CLK_Frequency (Clock_Ip_Get_QSPI_2X_CLK_Frequency, funcdef_no=82, decl_uid=6549, cgraph_uid=83, symbol_order=135)

Modification phase of node Clock_Ip_Get_QSPI_2X_CLK_Frequency/135
Clock_Ip_Get_QSPI_2X_CLK_Frequency ()
{
  uint32 Frequency;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  uint32 (*<T752>) (void) _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _13;
  long unsigned int _15;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct MC_CGM_0_Type *)1074561024B].MUX_5_CSS;
  _2 = _1 >> 24;
  _3 = _2 & 31;
  _4 = Clock_Ip_apfFreqTableClkSrc[_3];
  Frequency_12 = _4 ();
  # DEBUG Frequency => Frequency_12
  # DEBUG BEGIN_STMT
  _5 ={v} MEM[(struct MC_CGM_0_Type *)1074561024B].MUX_5_DC_0;
  _6 = _5 >> 31;
  _13 = Clock_Ip_u32EnableDivider[_6];
  Frequency_14 = Frequency_12 & _13;
  # DEBUG Frequency => Frequency_14
  # DEBUG BEGIN_STMT
  _7 ={v} MEM[(struct MC_CGM_0_Type *)1074561024B].MUX_5_DC_0;
  _8 = _7 >> 16;
  _9 = _8 & 255;
  _15 = _9 + 1;
  Frequency_16 = Frequency_14 / _15;
  # DEBUG Frequency => Frequency_16
  # DEBUG BEGIN_STMT
  return Frequency_16;

}



;; Function Clock_Ip_Get_QSPI_1X_CLK_Frequency (Clock_Ip_Get_QSPI_1X_CLK_Frequency, funcdef_no=83, decl_uid=6551, cgraph_uid=84, symbol_order=136)

Modification phase of node Clock_Ip_Get_QSPI_1X_CLK_Frequency/136
Clock_Ip_Get_QSPI_1X_CLK_Frequency ()
{
  long unsigned int _1;
  uint32 _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = Clock_Ip_Get_QSPI_2X_CLK_Frequency ();
  _4 = _1 >> 1;
  return _4;

}



;; Function Clock_Ip_Get_QSPI0_CLK_Frequency (Clock_Ip_Get_QSPI0_CLK_Frequency, funcdef_no=105, decl_uid=6553, cgraph_uid=85, symbol_order=137)

Modification phase of node Clock_Ip_Get_QSPI0_CLK_Frequency/137
Clock_Ip_Get_QSPI0_CLK_Frequency ()
{
  uint32 retval.168;

  <bb 2> [local count: 1073741824]:
  retval.168_3 = Clock_Ip_Get_QSPI_2X_CLK_Frequency (); [tail call]
  return retval.168_3;

}



;; Function Clock_Ip_Get_SPI_CLK_Frequency (Clock_Ip_Get_SPI_CLK_Frequency, funcdef_no=85, decl_uid=6555, cgraph_uid=86, symbol_order=138)

Modification phase of node Clock_Ip_Get_SPI_CLK_Frequency/138
Clock_Ip_Get_SPI_CLK_Frequency ()
{
  uint32 Frequency;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  uint32 (*<T752>) (void) _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct MC_CGM_0_Type *)1074561024B].MUX_4_CSS;
  _2 = _1 >> 24;
  _3 = _2 & 31;
  _4 = Clock_Ip_apfFreqTableClkSrc[_3];
  Frequency_7 = _4 ();
  # DEBUG Frequency => Frequency_7
  # DEBUG BEGIN_STMT
  return Frequency_7;

}



;; Function Clock_Ip_Get_SPT_CLK_Frequency (Clock_Ip_Get_SPT_CLK_Frequency, funcdef_no=86, decl_uid=6557, cgraph_uid=87, symbol_order=139)

Modification phase of node Clock_Ip_Get_SPT_CLK_Frequency/139
Clock_Ip_Get_SPT_CLK_Frequency ()
{
  uint32 Frequency;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  uint32 (*<T752>) (void) _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _11;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct MC_CGM_Type *)1141669888B].MUX_1_CSS;
  _2 = _1 >> 24;
  _3 = _2 & 63;
  _4 = Clock_Ip_apfFreqTableClkSrc[_3];
  Frequency_10 = _4 ();
  # DEBUG Frequency => Frequency_10
  # DEBUG BEGIN_STMT
  _5 ={v} MEM[(struct MC_ME_Type *)1074593792B].PRTN1_COFB0_STAT;
  _6 = _5 >> 1;
  _7 = _6 & 1;
  _11 = Clock_Ip_u32EnableGate[_7];
  Frequency_12 = Frequency_10 & _11;
  # DEBUG Frequency => Frequency_12
  # DEBUG BEGIN_STMT
  return Frequency_12;

}



;; Function Clock_Ip_Get_STCU_CLK_Frequency (Clock_Ip_Get_STCU_CLK_Frequency, funcdef_no=103, decl_uid=6559, cgraph_uid=88, symbol_order=140)

Modification phase of node Clock_Ip_Get_STCU_CLK_Frequency/140
Clock_Ip_Get_STCU_CLK_Frequency ()
{
  uint32 retval.167;

  <bb 2> [local count: 1073741824]:
  retval.167_3 = Clock_Ip_Get_DAPB_CLK_Frequency (); [tail call]
  return retval.167_3;

}



;; Function Clock_Ip_Get_TMU_CLK_Frequency (Clock_Ip_Get_TMU_CLK_Frequency, funcdef_no=101, decl_uid=6563, cgraph_uid=89, symbol_order=141)

Modification phase of node Clock_Ip_Get_TMU_CLK_Frequency/141
Clock_Ip_Get_TMU_CLK_Frequency ()
{
  uint32 retval.166;

  <bb 2> [local count: 1073741824]:
  retval.166_3 = Clock_Ip_Get_CAN_CHI_CLK_Frequency (); [tail call]
  return retval.166_3;

}



;; Function Clock_Ip_Get_TCLK_CLK_Frequency (Clock_Ip_Get_TCLK_CLK_Frequency, funcdef_no=89, decl_uid=6565, cgraph_uid=90, symbol_order=142)

Modification phase of node Clock_Ip_Get_TCLK_CLK_Frequency/142
Clock_Ip_Get_TCLK_CLK_Frequency ()
{
  uint32 Frequency;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  uint32 (*<T752>) (void) _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _13;
  long unsigned int _15;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct MC_CGM_0_Type *)1074561024B].MUX_6_CSS;
  _2 = _1 >> 24;
  _3 = _2 & 31;
  _4 = Clock_Ip_apfFreqTableClkSrc[_3];
  Frequency_12 = _4 ();
  # DEBUG Frequency => Frequency_12
  # DEBUG BEGIN_STMT
  _5 ={v} MEM[(struct MC_CGM_0_Type *)1074561024B].MUX_6_DC_2;
  _6 = _5 >> 31;
  _13 = Clock_Ip_u32EnableDivider[_6];
  Frequency_14 = Frequency_12 & _13;
  # DEBUG Frequency => Frequency_14
  # DEBUG BEGIN_STMT
  _7 ={v} MEM[(struct MC_CGM_0_Type *)1074561024B].MUX_6_DC_2;
  _8 = _7 >> 16;
  _9 = _8 & 255;
  _15 = _9 + 1;
  Frequency_16 = Frequency_14 / _15;
  # DEBUG Frequency => Frequency_16
  # DEBUG BEGIN_STMT
  return Frequency_16;

}



;; Function Clock_Ip_PLL_VCO.part.0 (Clock_Ip_PLL_VCO.part.0, funcdef_no=95, decl_uid=7506, cgraph_uid=97, symbol_order=149)

Modification phase of node Clock_Ip_PLL_VCO.part.0/149
Adjusting mask for param 0 to 0xfffffff8
Adjusting align: 8, misalign: 0
Setting nonnull for 0
Clock_Ip_PLL_VCO.part.0 (const struct PLLDIG_Type * Base)
{
  uint32 Fin;
  uint32 Fout;
  uint32 Rdiv;
  uint32 Mfi;
  uint32 Mfn;
  uint32 Var1;
  uint32 Var2;
  uint32 Var3;
  uint32 Var4;
  uint32 Var5;
  uint32 D.7519;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int iftmp.65_4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _8;
  long unsigned int _10;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int _15;
  long unsigned int iftmp.65_17;
  long unsigned int _19;
  long unsigned int _21;
  long unsigned int _22;
  long unsigned int _25;
  long unsigned int _27;
  long unsigned int _28;

  <bb 8> [local count: 1073741824]:

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _2 ={v} Base_1(D)->PLLCLKMUX;
  _3 = _2 & 1;
  if (_3 == 0)
    goto <bb 4>; [67.00%]
  else
    goto <bb 3>; [33.00%]

  <bb 3> [local count: 354334802]:
  iftmp.65_4 = Clock_Ip_Get_FXOSC_CLK_Frequency ();

  <bb 4> [local count: 1073741824]:
  # iftmp.65_17 = PHI <48000000(2), iftmp.65_4(3)>
  # DEBUG Fin => iftmp.65_17
  # DEBUG BEGIN_STMT
  _5 ={v} Base_1(D)->PLLDV;
  _6 = _5 >> 12;
  Rdiv_7 = _6 & 7;
  # DEBUG Rdiv => Rdiv_7
  # DEBUG BEGIN_STMT
  _8 ={v} Base_1(D)->PLLDV;
  Mfi_9 = _8 & 255;
  # DEBUG Mfi => Mfi_9
  # DEBUG BEGIN_STMT
  if (Base_1(D) == 1074511872B)
    goto <bb 6>; [30.00%]
  else
    goto <bb 5>; [70.00%]

  <bb 5> [local count: 751619278]:
  # DEBUG BEGIN_STMT
  _10 ={v} Base_1(D)->PLLFD;
  Mfn_11 = _10 & 32767;
  # DEBUG Mfn => Mfn_11

  <bb 6> [local count: 1073741824]:
  # Mfn_24 = PHI <0(4), Mfn_11(5)>
  # DEBUG Mfn => Mfn_24
  # DEBUG BEGIN_STMT
  Var1_12 = Mfi_9 / Rdiv_7;
  # DEBUG Var1 => Var1_12
  # DEBUG BEGIN_STMT
  _13 = Mfi_9 % Rdiv_7;
  # DEBUG Var2 => _13
  # DEBUG BEGIN_STMT
  _14 = Rdiv_7 << 14;
  _15 = Rdiv_7 << 11;
  Var3_16 = _14 + _15;
  # DEBUG Var3 => Var3_16
  # DEBUG BEGIN_STMT
  Var4_18 = iftmp.65_17 / Var3_16;
  # DEBUG Var4 => Var4_18
  # DEBUG BEGIN_STMT
  _19 = iftmp.65_17 % Var3_16;
  # DEBUG Var5 => _19
  # DEBUG BEGIN_STMT
  Fout_20 = Var1_12 * iftmp.65_17;
  # DEBUG Fout => Fout_20
  # DEBUG BEGIN_STMT
  _21 = iftmp.65_17 / Rdiv_7;
  _22 = _13 * _21;
  Fout_23 = Fout_20 + _22;
  # DEBUG Fout => Fout_23
  # DEBUG BEGIN_STMT
  _25 = Var4_18 * Mfn_24;
  Fout_26 = Fout_23 + _25;
  # DEBUG Fout => Fout_26
  # DEBUG BEGIN_STMT
  _27 = _19 * Mfn_24;
  _28 = _27 / Var3_16;
  Fout_29 = Fout_26 + _28;
  # DEBUG Fout => Fout_29

  <bb 7> [local count: 1073741824]:
  # Fout_30 = PHI <Fout_29(6)>
  # DEBUG Fout => Fout_30
  # DEBUG BEGIN_STMT
  return Fout_30;

}



;; Function Clock_Ip_Get_COREPLL_CLK_Frequency (Clock_Ip_Get_COREPLL_CLK_Frequency, funcdef_no=3, decl_uid=6387, cgraph_uid=4, symbol_order=56)

Modification phase of node Clock_Ip_Get_COREPLL_CLK_Frequency/56
Clock_Ip_Get_COREPLL_CLK_Frequency ()
{
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int Clock_Ip_u32CorePllChecksum.66_6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  uint32 iftmp.67_15;
  uint32 iftmp.67_21;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLCLKMUX;
  _2 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLDV;
  _3 = _1 ^ _2;
  _4 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLFD;
  _5 = _3 ^ _4;
  Clock_Ip_u32CorePllChecksum.66_6 = Clock_Ip_u32CorePllChecksum;
  if (_5 != Clock_Ip_u32CorePllChecksum.66_6)
    goto <bb 3>; [48.88%]
  else
    goto <bb 4>; [51.12%]

  <bb 3> [local count: 524845004]:
  # DEBUG BEGIN_STMT
  _7 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLCLKMUX;
  _8 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLDV;
  _9 = _7 ^ _8;
  _10 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLFD;
  _11 = _9 ^ _10;
  Clock_Ip_u32CorePllChecksum = _11;
  # DEBUG BEGIN_STMT
  _12 = Clock_Ip_PLL_VCO (1141637120B);
  Clock_Ip_u32CorePllFreq = _12;

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _13 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLSR;
  _14 = _13 & 4;
  if (_14 != 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 5> [local count: 536870913]:
  iftmp.67_21 = Clock_Ip_u32CorePllFreq;

  <bb 6> [local count: 1073741824]:
  # iftmp.67_15 = PHI <iftmp.67_21(5), 0(4)>
  return iftmp.67_15;

}



;; Function Clock_Ip_Get_COREPLL_PHI9_Frequency (Clock_Ip_Get_COREPLL_PHI9_Frequency, funcdef_no=13, decl_uid=6407, cgraph_uid=14, symbol_order=66)

Modification phase of node Clock_Ip_Get_COREPLL_PHI9_Frequency/66
Clock_Ip_Get_COREPLL_PHI9_Frequency ()
{
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int Clock_Ip_u32CorePhi9Checksum.36_10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int _15;
  long unsigned int _16;
  long unsigned int _17;
  long unsigned int _18;
  long unsigned int _19;
  long unsigned int _20;
  long unsigned int _21;
  long unsigned int _22;
  long unsigned int _23;
  long unsigned int _24;
  long unsigned int _25;
  long unsigned int _26;
  long unsigned int _27;
  long unsigned int _32;
  long unsigned int _33;
  uint32 _35;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLCLKMUX;
  _2 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLDV;
  _3 = _1 ^ _2;
  _4 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLFD;
  _5 = _3 ^ _4;
  _6 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLSR;
  _7 = _5 ^ _6;
  _8 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLODIV[9];
  _9 = _7 ^ _8;
  Clock_Ip_u32CorePhi9Checksum.36_10 = Clock_Ip_u32CorePhi9Checksum;
  if (_9 != Clock_Ip_u32CorePhi9Checksum.36_10)
    goto <bb 3>; [48.88%]
  else
    goto <bb 4>; [51.12%]

  <bb 3> [local count: 524845004]:
  # DEBUG BEGIN_STMT
  _11 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLCLKMUX;
  _12 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLDV;
  _13 = _11 ^ _12;
  _14 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLFD;
  _15 = _13 ^ _14;
  _16 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLSR;
  _17 = _15 ^ _16;
  _18 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLODIV[9];
  _19 = _17 ^ _18;
  Clock_Ip_u32CorePhi9Checksum = _19;
  # DEBUG BEGIN_STMT
  _20 = Clock_Ip_Get_COREPLL_CLK_Frequency ();
  # DEBUG BEGIN_STMT
  _21 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLODIV[9];
  _22 = _21 >> 31;
  _32 = Clock_Ip_u32EnableDivider[_22];
  _23 = _20 & _32;
  # DEBUG BEGIN_STMT
  _24 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLODIV[9];
  _25 = _24 >> 16;
  _26 = _25 & 255;
  _33 = _26 + 1;
  _27 = _23 / _33;
  Clock_Ip_u32CorePhi9Freq = _27;

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _35 = Clock_Ip_u32CorePhi9Freq;
  return _35;

}



;; Function Clock_Ip_Get_COREPLL_PHI8_Frequency (Clock_Ip_Get_COREPLL_PHI8_Frequency, funcdef_no=12, decl_uid=6405, cgraph_uid=13, symbol_order=65)

Modification phase of node Clock_Ip_Get_COREPLL_PHI8_Frequency/65
Clock_Ip_Get_COREPLL_PHI8_Frequency ()
{
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int Clock_Ip_u32CorePhi8Checksum.39_10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int _15;
  long unsigned int _16;
  long unsigned int _17;
  long unsigned int _18;
  long unsigned int _19;
  long unsigned int _20;
  long unsigned int _21;
  long unsigned int _22;
  long unsigned int _23;
  long unsigned int _24;
  long unsigned int _25;
  long unsigned int _26;
  long unsigned int _27;
  long unsigned int _32;
  long unsigned int _33;
  uint32 _35;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLCLKMUX;
  _2 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLDV;
  _3 = _1 ^ _2;
  _4 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLFD;
  _5 = _3 ^ _4;
  _6 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLSR;
  _7 = _5 ^ _6;
  _8 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLODIV[8];
  _9 = _7 ^ _8;
  Clock_Ip_u32CorePhi8Checksum.39_10 = Clock_Ip_u32CorePhi8Checksum;
  if (_9 != Clock_Ip_u32CorePhi8Checksum.39_10)
    goto <bb 3>; [48.88%]
  else
    goto <bb 4>; [51.12%]

  <bb 3> [local count: 524845004]:
  # DEBUG BEGIN_STMT
  _11 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLCLKMUX;
  _12 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLDV;
  _13 = _11 ^ _12;
  _14 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLFD;
  _15 = _13 ^ _14;
  _16 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLSR;
  _17 = _15 ^ _16;
  _18 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLODIV[8];
  _19 = _17 ^ _18;
  Clock_Ip_u32CorePhi8Checksum = _19;
  # DEBUG BEGIN_STMT
  _20 = Clock_Ip_Get_COREPLL_CLK_Frequency ();
  # DEBUG BEGIN_STMT
  _21 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLODIV[8];
  _22 = _21 >> 31;
  _32 = Clock_Ip_u32EnableDivider[_22];
  _23 = _20 & _32;
  # DEBUG BEGIN_STMT
  _24 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLODIV[8];
  _25 = _24 >> 16;
  _26 = _25 & 255;
  _33 = _26 + 1;
  _27 = _23 / _33;
  Clock_Ip_u32CorePhi8Freq = _27;

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _35 = Clock_Ip_u32CorePhi8Freq;
  return _35;

}



;; Function Clock_Ip_Get_COREPLL_PHI6_Frequency (Clock_Ip_Get_COREPLL_PHI6_Frequency, funcdef_no=11, decl_uid=6403, cgraph_uid=12, symbol_order=64)

Modification phase of node Clock_Ip_Get_COREPLL_PHI6_Frequency/64
Clock_Ip_Get_COREPLL_PHI6_Frequency ()
{
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int Clock_Ip_u32CorePhi6Checksum.42_10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int _15;
  long unsigned int _16;
  long unsigned int _17;
  long unsigned int _18;
  long unsigned int _19;
  long unsigned int _20;
  long unsigned int _21;
  long unsigned int _22;
  long unsigned int _23;
  long unsigned int _24;
  long unsigned int _25;
  long unsigned int _26;
  long unsigned int _27;
  long unsigned int _32;
  long unsigned int _33;
  uint32 _35;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLCLKMUX;
  _2 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLDV;
  _3 = _1 ^ _2;
  _4 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLFD;
  _5 = _3 ^ _4;
  _6 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLSR;
  _7 = _5 ^ _6;
  _8 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLODIV[6];
  _9 = _7 ^ _8;
  Clock_Ip_u32CorePhi6Checksum.42_10 = Clock_Ip_u32CorePhi6Checksum;
  if (_9 != Clock_Ip_u32CorePhi6Checksum.42_10)
    goto <bb 3>; [48.88%]
  else
    goto <bb 4>; [51.12%]

  <bb 3> [local count: 524845004]:
  # DEBUG BEGIN_STMT
  _11 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLCLKMUX;
  _12 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLDV;
  _13 = _11 ^ _12;
  _14 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLFD;
  _15 = _13 ^ _14;
  _16 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLSR;
  _17 = _15 ^ _16;
  _18 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLODIV[6];
  _19 = _17 ^ _18;
  Clock_Ip_u32CorePhi6Checksum = _19;
  # DEBUG BEGIN_STMT
  _20 = Clock_Ip_Get_COREPLL_CLK_Frequency ();
  # DEBUG BEGIN_STMT
  _21 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLODIV[6];
  _22 = _21 >> 31;
  _32 = Clock_Ip_u32EnableDivider[_22];
  _23 = _20 & _32;
  # DEBUG BEGIN_STMT
  _24 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLODIV[6];
  _25 = _24 >> 16;
  _26 = _25 & 255;
  _33 = _26 + 1;
  _27 = _23 / _33;
  Clock_Ip_u32CorePhi6Freq = _27;

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _35 = Clock_Ip_u32CorePhi6Freq;
  return _35;

}



;; Function Clock_Ip_Get_COREPLL_PHI5_Frequency (Clock_Ip_Get_COREPLL_PHI5_Frequency, funcdef_no=10, decl_uid=6401, cgraph_uid=11, symbol_order=63)

Modification phase of node Clock_Ip_Get_COREPLL_PHI5_Frequency/63
Clock_Ip_Get_COREPLL_PHI5_Frequency ()
{
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int Clock_Ip_u32CorePhi5Checksum.45_10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int _15;
  long unsigned int _16;
  long unsigned int _17;
  long unsigned int _18;
  long unsigned int _19;
  long unsigned int _20;
  long unsigned int _21;
  long unsigned int _22;
  long unsigned int _23;
  long unsigned int _24;
  long unsigned int _25;
  long unsigned int _26;
  long unsigned int _27;
  long unsigned int _32;
  long unsigned int _33;
  uint32 _35;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLCLKMUX;
  _2 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLDV;
  _3 = _1 ^ _2;
  _4 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLFD;
  _5 = _3 ^ _4;
  _6 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLSR;
  _7 = _5 ^ _6;
  _8 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLODIV[5];
  _9 = _7 ^ _8;
  Clock_Ip_u32CorePhi5Checksum.45_10 = Clock_Ip_u32CorePhi5Checksum;
  if (_9 != Clock_Ip_u32CorePhi5Checksum.45_10)
    goto <bb 3>; [48.88%]
  else
    goto <bb 4>; [51.12%]

  <bb 3> [local count: 524845004]:
  # DEBUG BEGIN_STMT
  _11 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLCLKMUX;
  _12 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLDV;
  _13 = _11 ^ _12;
  _14 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLFD;
  _15 = _13 ^ _14;
  _16 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLSR;
  _17 = _15 ^ _16;
  _18 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLODIV[5];
  _19 = _17 ^ _18;
  Clock_Ip_u32CorePhi5Checksum = _19;
  # DEBUG BEGIN_STMT
  _20 = Clock_Ip_Get_COREPLL_CLK_Frequency ();
  # DEBUG BEGIN_STMT
  _21 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLODIV[5];
  _22 = _21 >> 31;
  _32 = Clock_Ip_u32EnableDivider[_22];
  _23 = _20 & _32;
  # DEBUG BEGIN_STMT
  _24 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLODIV[5];
  _25 = _24 >> 16;
  _26 = _25 & 255;
  _33 = _26 + 1;
  _27 = _23 / _33;
  Clock_Ip_u32CorePhi5Freq = _27;

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _35 = Clock_Ip_u32CorePhi5Freq;
  return _35;

}



;; Function Clock_Ip_Get_COREPLL_PHI4_Frequency (Clock_Ip_Get_COREPLL_PHI4_Frequency, funcdef_no=9, decl_uid=6399, cgraph_uid=10, symbol_order=62)

Modification phase of node Clock_Ip_Get_COREPLL_PHI4_Frequency/62
Clock_Ip_Get_COREPLL_PHI4_Frequency ()
{
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int Clock_Ip_u32CorePhi4Checksum.48_10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int _15;
  long unsigned int _16;
  long unsigned int _17;
  long unsigned int _18;
  long unsigned int _19;
  long unsigned int _20;
  long unsigned int _21;
  long unsigned int _22;
  long unsigned int _23;
  long unsigned int _24;
  long unsigned int _25;
  long unsigned int _26;
  long unsigned int _27;
  long unsigned int _32;
  long unsigned int _33;
  uint32 _35;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLCLKMUX;
  _2 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLDV;
  _3 = _1 ^ _2;
  _4 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLFD;
  _5 = _3 ^ _4;
  _6 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLSR;
  _7 = _5 ^ _6;
  _8 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLODIV[4];
  _9 = _7 ^ _8;
  Clock_Ip_u32CorePhi4Checksum.48_10 = Clock_Ip_u32CorePhi4Checksum;
  if (_9 != Clock_Ip_u32CorePhi4Checksum.48_10)
    goto <bb 3>; [48.88%]
  else
    goto <bb 4>; [51.12%]

  <bb 3> [local count: 524845004]:
  # DEBUG BEGIN_STMT
  _11 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLCLKMUX;
  _12 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLDV;
  _13 = _11 ^ _12;
  _14 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLFD;
  _15 = _13 ^ _14;
  _16 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLSR;
  _17 = _15 ^ _16;
  _18 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLODIV[4];
  _19 = _17 ^ _18;
  Clock_Ip_u32CorePhi4Checksum = _19;
  # DEBUG BEGIN_STMT
  _20 = Clock_Ip_Get_COREPLL_CLK_Frequency ();
  # DEBUG BEGIN_STMT
  _21 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLODIV[4];
  _22 = _21 >> 31;
  _32 = Clock_Ip_u32EnableDivider[_22];
  _23 = _20 & _32;
  # DEBUG BEGIN_STMT
  _24 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLODIV[4];
  _25 = _24 >> 16;
  _26 = _25 & 255;
  _33 = _26 + 1;
  _27 = _23 / _33;
  Clock_Ip_u32CorePhi4Freq = _27;

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _35 = Clock_Ip_u32CorePhi4Freq;
  return _35;

}



;; Function Clock_Ip_Get_COREPLL_PHI3_Frequency (Clock_Ip_Get_COREPLL_PHI3_Frequency, funcdef_no=8, decl_uid=6397, cgraph_uid=9, symbol_order=61)

Modification phase of node Clock_Ip_Get_COREPLL_PHI3_Frequency/61
Clock_Ip_Get_COREPLL_PHI3_Frequency ()
{
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int Clock_Ip_u32CorePhi3Checksum.51_10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int _15;
  long unsigned int _16;
  long unsigned int _17;
  long unsigned int _18;
  long unsigned int _19;
  long unsigned int _20;
  long unsigned int _21;
  long unsigned int _22;
  long unsigned int _23;
  long unsigned int _24;
  long unsigned int _25;
  long unsigned int _26;
  long unsigned int _27;
  long unsigned int _32;
  long unsigned int _33;
  uint32 _35;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLCLKMUX;
  _2 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLDV;
  _3 = _1 ^ _2;
  _4 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLFD;
  _5 = _3 ^ _4;
  _6 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLSR;
  _7 = _5 ^ _6;
  _8 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLODIV[3];
  _9 = _7 ^ _8;
  Clock_Ip_u32CorePhi3Checksum.51_10 = Clock_Ip_u32CorePhi3Checksum;
  if (_9 != Clock_Ip_u32CorePhi3Checksum.51_10)
    goto <bb 3>; [48.88%]
  else
    goto <bb 4>; [51.12%]

  <bb 3> [local count: 524845004]:
  # DEBUG BEGIN_STMT
  _11 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLCLKMUX;
  _12 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLDV;
  _13 = _11 ^ _12;
  _14 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLFD;
  _15 = _13 ^ _14;
  _16 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLSR;
  _17 = _15 ^ _16;
  _18 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLODIV[3];
  _19 = _17 ^ _18;
  Clock_Ip_u32CorePhi3Checksum = _19;
  # DEBUG BEGIN_STMT
  _20 = Clock_Ip_Get_COREPLL_CLK_Frequency ();
  # DEBUG BEGIN_STMT
  _21 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLODIV[3];
  _22 = _21 >> 31;
  _32 = Clock_Ip_u32EnableDivider[_22];
  _23 = _20 & _32;
  # DEBUG BEGIN_STMT
  _24 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLODIV[3];
  _25 = _24 >> 16;
  _26 = _25 & 255;
  _33 = _26 + 1;
  _27 = _23 / _33;
  Clock_Ip_u32CorePhi3Freq = _27;

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _35 = Clock_Ip_u32CorePhi3Freq;
  return _35;

}



;; Function Clock_Ip_Get_COREPLL_PHI2_Frequency (Clock_Ip_Get_COREPLL_PHI2_Frequency, funcdef_no=7, decl_uid=6395, cgraph_uid=8, symbol_order=60)

Modification phase of node Clock_Ip_Get_COREPLL_PHI2_Frequency/60
Clock_Ip_Get_COREPLL_PHI2_Frequency ()
{
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int Clock_Ip_u32CorePhi2Checksum.54_10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int _15;
  long unsigned int _16;
  long unsigned int _17;
  long unsigned int _18;
  long unsigned int _19;
  long unsigned int _20;
  long unsigned int _21;
  long unsigned int _22;
  long unsigned int _23;
  long unsigned int _24;
  long unsigned int _25;
  long unsigned int _26;
  long unsigned int _27;
  long unsigned int _32;
  long unsigned int _33;
  uint32 _35;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLCLKMUX;
  _2 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLDV;
  _3 = _1 ^ _2;
  _4 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLFD;
  _5 = _3 ^ _4;
  _6 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLSR;
  _7 = _5 ^ _6;
  _8 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLODIV[2];
  _9 = _7 ^ _8;
  Clock_Ip_u32CorePhi2Checksum.54_10 = Clock_Ip_u32CorePhi2Checksum;
  if (_9 != Clock_Ip_u32CorePhi2Checksum.54_10)
    goto <bb 3>; [48.88%]
  else
    goto <bb 4>; [51.12%]

  <bb 3> [local count: 524845004]:
  # DEBUG BEGIN_STMT
  _11 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLCLKMUX;
  _12 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLDV;
  _13 = _11 ^ _12;
  _14 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLFD;
  _15 = _13 ^ _14;
  _16 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLSR;
  _17 = _15 ^ _16;
  _18 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLODIV[2];
  _19 = _17 ^ _18;
  Clock_Ip_u32CorePhi2Checksum = _19;
  # DEBUG BEGIN_STMT
  _20 = Clock_Ip_Get_COREPLL_CLK_Frequency ();
  # DEBUG BEGIN_STMT
  _21 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLODIV[2];
  _22 = _21 >> 31;
  _32 = Clock_Ip_u32EnableDivider[_22];
  _23 = _20 & _32;
  # DEBUG BEGIN_STMT
  _24 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLODIV[2];
  _25 = _24 >> 16;
  _26 = _25 & 255;
  _33 = _26 + 1;
  _27 = _23 / _33;
  Clock_Ip_u32CorePhi2Freq = _27;

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _35 = Clock_Ip_u32CorePhi2Freq;
  return _35;

}



;; Function Clock_Ip_Get_COREPLL_PHI1_Frequency (Clock_Ip_Get_COREPLL_PHI1_Frequency, funcdef_no=6, decl_uid=6393, cgraph_uid=7, symbol_order=59)

Modification phase of node Clock_Ip_Get_COREPLL_PHI1_Frequency/59
Clock_Ip_Get_COREPLL_PHI1_Frequency ()
{
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int Clock_Ip_u32CorePhi1Checksum.57_10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int _15;
  long unsigned int _16;
  long unsigned int _17;
  long unsigned int _18;
  long unsigned int _19;
  long unsigned int _20;
  long unsigned int _21;
  long unsigned int _22;
  long unsigned int _23;
  long unsigned int _24;
  long unsigned int _25;
  long unsigned int _26;
  long unsigned int _27;
  long unsigned int _32;
  long unsigned int _33;
  uint32 _35;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLCLKMUX;
  _2 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLDV;
  _3 = _1 ^ _2;
  _4 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLFD;
  _5 = _3 ^ _4;
  _6 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLSR;
  _7 = _5 ^ _6;
  _8 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLODIV[1];
  _9 = _7 ^ _8;
  Clock_Ip_u32CorePhi1Checksum.57_10 = Clock_Ip_u32CorePhi1Checksum;
  if (_9 != Clock_Ip_u32CorePhi1Checksum.57_10)
    goto <bb 3>; [48.88%]
  else
    goto <bb 4>; [51.12%]

  <bb 3> [local count: 524845004]:
  # DEBUG BEGIN_STMT
  _11 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLCLKMUX;
  _12 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLDV;
  _13 = _11 ^ _12;
  _14 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLFD;
  _15 = _13 ^ _14;
  _16 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLSR;
  _17 = _15 ^ _16;
  _18 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLODIV[1];
  _19 = _17 ^ _18;
  Clock_Ip_u32CorePhi1Checksum = _19;
  # DEBUG BEGIN_STMT
  _20 = Clock_Ip_Get_COREPLL_CLK_Frequency ();
  # DEBUG BEGIN_STMT
  _21 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLODIV[1];
  _22 = _21 >> 31;
  _32 = Clock_Ip_u32EnableDivider[_22];
  _23 = _20 & _32;
  # DEBUG BEGIN_STMT
  _24 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLODIV[1];
  _25 = _24 >> 16;
  _26 = _25 & 255;
  _33 = _26 + 1;
  _27 = _23 / _33;
  Clock_Ip_u32CorePhi1Freq = _27;

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _35 = Clock_Ip_u32CorePhi1Freq;
  return _35;

}



;; Function Clock_Ip_Get_COREPLL_PHI0_Frequency (Clock_Ip_Get_COREPLL_PHI0_Frequency, funcdef_no=5, decl_uid=6391, cgraph_uid=6, symbol_order=58)

Modification phase of node Clock_Ip_Get_COREPLL_PHI0_Frequency/58
Clock_Ip_Get_COREPLL_PHI0_Frequency ()
{
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int Clock_Ip_u32CorePhi0Checksum.60_10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int _15;
  long unsigned int _16;
  long unsigned int _17;
  long unsigned int _18;
  long unsigned int _19;
  long unsigned int _20;
  long unsigned int _21;
  long unsigned int _22;
  long unsigned int _23;
  long unsigned int _24;
  long unsigned int _25;
  long unsigned int _26;
  long unsigned int _27;
  long unsigned int _32;
  long unsigned int _33;
  uint32 _35;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLCLKMUX;
  _2 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLDV;
  _3 = _1 ^ _2;
  _4 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLFD;
  _5 = _3 ^ _4;
  _6 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLSR;
  _7 = _5 ^ _6;
  _8 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLODIV[0];
  _9 = _7 ^ _8;
  Clock_Ip_u32CorePhi0Checksum.60_10 = Clock_Ip_u32CorePhi0Checksum;
  if (_9 != Clock_Ip_u32CorePhi0Checksum.60_10)
    goto <bb 3>; [48.88%]
  else
    goto <bb 4>; [51.12%]

  <bb 3> [local count: 524845004]:
  # DEBUG BEGIN_STMT
  _11 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLCLKMUX;
  _12 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLDV;
  _13 = _11 ^ _12;
  _14 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLFD;
  _15 = _13 ^ _14;
  _16 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLSR;
  _17 = _15 ^ _16;
  _18 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLODIV[0];
  _19 = _17 ^ _18;
  Clock_Ip_u32CorePhi0Checksum = _19;
  # DEBUG BEGIN_STMT
  _20 = Clock_Ip_Get_COREPLL_CLK_Frequency ();
  # DEBUG BEGIN_STMT
  _21 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLODIV[0];
  _22 = _21 >> 31;
  _32 = Clock_Ip_u32EnableDivider[_22];
  _23 = _20 & _32;
  # DEBUG BEGIN_STMT
  _24 ={v} MEM[(struct PLLDIG_Type *)1141637120B].PLLODIV[0];
  _25 = _24 >> 16;
  _26 = _25 & 255;
  _33 = _26 + 1;
  _27 = _23 / _33;
  Clock_Ip_u32CorePhi0Freq = _27;

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _35 = Clock_Ip_u32CorePhi0Freq;
  return _35;

}



;; Function Clock_Ip_DFS_OUTPUT.constprop (Clock_Ip_DFS_OUTPUT.constprop.0, funcdef_no=108, decl_uid=7562, cgraph_uid=99, symbol_order=151)

Modification phase of node Clock_Ip_DFS_OUTPUT.constprop/151
Adjusting mask for param 1 to 0x1
Setting value range of param 1 [0, 1]
Clock_Ip_DFS_OUTPUT.constprop (uint32 Channel, uint32 Fin)
{
  uint32 Mfi;
  uint32 Mfn;
  uint32 Divider;
  uint32 DividerModulo;
  const struct DFS_Type * Base;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _5;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int iftmp.2_12;
  long unsigned int iftmp.2_13;
  long unsigned int _14;
  long unsigned int _16;
  long unsigned int _17;
  long unsigned int _18;
  long unsigned int _19;
  long unsigned int _20;
  long unsigned int _21;
  long unsigned int _22;
  long unsigned int iftmp.3_23;
  long unsigned int iftmp.3_24;

  <bb 7> [local count: 1073741824]:
  # DEBUG Base => 1074528256B

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 ={v} MEM[(const struct DFS_Type *)1074528256B].DVPORT[Channel_1(D)];
  _3 = _2 >> 8;
  Mfi_4 = _3 & 255;
  # DEBUG Mfi => Mfi_4
  # DEBUG BEGIN_STMT
  _5 ={v} MEM[(const struct DFS_Type *)1074528256B].DVPORT[Channel_1(D)];
  Mfn_6 = _5 & 63;
  # DEBUG Mfn => Mfn_6
  # DEBUG BEGIN_STMT
  _7 = Mfi_4 << 5;
  _8 = Mfi_4 << 2;
  _9 = _7 + _8;
  Divider_10 = Mfn_6 + _9;
  # DEBUG Divider => Divider_10
  # DEBUG BEGIN_STMT
  if (Divider_10 != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  iftmp.2_12 = Fin_11(D) / Divider_10;

  <bb 4> [local count: 1073741824]:
  # iftmp.2_13 = PHI <0(2), iftmp.2_12(3)>
  # DEBUG DividerResult => iftmp.2_13
  # DEBUG BEGIN_STMT
  _14 = Divider_10 * iftmp.2_13;
  DividerModulo_15 = Fin_11(D) - _14;
  # DEBUG DividerModulo => DividerModulo_15
  # DEBUG BEGIN_STMT
  if (Divider_10 != 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 5> [local count: 536870913]:
  _16 = iftmp.2_13 << 4;
  _17 = iftmp.2_13 << 1;
  _18 = _16 + _17;
  _19 = DividerModulo_15 << 4;
  _20 = DividerModulo_15 << 1;
  _21 = _19 + _20;
  _22 = _21 / Divider_10;
  iftmp.3_23 = _18 + _22;

  <bb 6> [local count: 1073741824]:
  # iftmp.3_24 = PHI <0(4), iftmp.3_23(5)>
  return iftmp.3_24;

}



;; Function Clock_Ip_Get_PERIPHPLL_CLK_Frequency (Clock_Ip_Get_PERIPHPLL_CLK_Frequency, funcdef_no=4, decl_uid=6389, cgraph_uid=5, symbol_order=57)

Modification phase of node Clock_Ip_Get_PERIPHPLL_CLK_Frequency/57
Clock_Ip_Get_PERIPHPLL_CLK_Frequency ()
{
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int Clock_Ip_u32PeriphPllChecksum.63_4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  uint32 iftmp.64_11;
  uint32 iftmp.64_17;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLCLKMUX;
  _2 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLDV;
  _3 = _1 ^ _2;
  Clock_Ip_u32PeriphPllChecksum.63_4 = Clock_Ip_u32PeriphPllChecksum;
  if (_3 != Clock_Ip_u32PeriphPllChecksum.63_4)
    goto <bb 3>; [48.88%]
  else
    goto <bb 4>; [51.12%]

  <bb 3> [local count: 524845004]:
  # DEBUG BEGIN_STMT
  _5 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLCLKMUX;
  _6 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLDV;
  _7 = _5 ^ _6;
  Clock_Ip_u32PeriphPllChecksum = _7;
  # DEBUG BEGIN_STMT
  _8 = Clock_Ip_PLL_VCO (1074511872B);
  Clock_Ip_u32PeriphPllFreq = _8;

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _9 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLSR;
  _10 = _9 & 4;
  if (_10 != 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 5> [local count: 536870913]:
  iftmp.64_17 = Clock_Ip_u32PeriphPllFreq;

  <bb 6> [local count: 1073741824]:
  # iftmp.64_11 = PHI <iftmp.64_17(5), 0(4)>
  return iftmp.64_11;

}



;; Function Clock_Ip_Get_PERIPHPLL_PHI9_Frequency (Clock_Ip_Get_PERIPHPLL_PHI9_Frequency, funcdef_no=23, decl_uid=6427, cgraph_uid=24, symbol_order=76)

Modification phase of node Clock_Ip_Get_PERIPHPLL_PHI9_Frequency/76
Clock_Ip_Get_PERIPHPLL_PHI9_Frequency ()
{
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int Clock_Ip_u32PeriphPhi9Checksum.6_8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int _15;
  long unsigned int _16;
  long unsigned int _17;
  long unsigned int _18;
  long unsigned int _19;
  long unsigned int _20;
  long unsigned int _21;
  long unsigned int _22;
  long unsigned int _23;
  long unsigned int _28;
  long unsigned int _29;
  uint32 _31;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLCLKMUX;
  _2 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLDV;
  _3 = _1 ^ _2;
  _4 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLSR;
  _5 = _3 ^ _4;
  _6 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLODIV[9];
  _7 = _5 ^ _6;
  Clock_Ip_u32PeriphPhi9Checksum.6_8 = Clock_Ip_u32PeriphPhi9Checksum;
  if (_7 != Clock_Ip_u32PeriphPhi9Checksum.6_8)
    goto <bb 3>; [48.88%]
  else
    goto <bb 4>; [51.12%]

  <bb 3> [local count: 524845004]:
  # DEBUG BEGIN_STMT
  _9 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLCLKMUX;
  _10 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLDV;
  _11 = _9 ^ _10;
  _12 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLSR;
  _13 = _11 ^ _12;
  _14 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLODIV[9];
  _15 = _13 ^ _14;
  Clock_Ip_u32PeriphPhi9Checksum = _15;
  # DEBUG BEGIN_STMT
  _16 = Clock_Ip_Get_PERIPHPLL_CLK_Frequency ();
  # DEBUG BEGIN_STMT
  _17 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLODIV[9];
  _18 = _17 >> 31;
  _28 = Clock_Ip_u32EnableDivider[_18];
  _19 = _16 & _28;
  # DEBUG BEGIN_STMT
  _20 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLODIV[9];
  _21 = _20 >> 16;
  _22 = _21 & 255;
  _29 = _22 + 1;
  _23 = _19 / _29;
  Clock_Ip_u32PeriphPhi9Freq = _23;

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _31 = Clock_Ip_u32PeriphPhi9Freq;
  return _31;

}



;; Function Clock_Ip_Get_PERIPHPLL_PHI8_Frequency (Clock_Ip_Get_PERIPHPLL_PHI8_Frequency, funcdef_no=22, decl_uid=6425, cgraph_uid=23, symbol_order=75)

Modification phase of node Clock_Ip_Get_PERIPHPLL_PHI8_Frequency/75
Clock_Ip_Get_PERIPHPLL_PHI8_Frequency ()
{
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int Clock_Ip_u32PeriphPhi8Checksum.9_8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int _15;
  long unsigned int _16;
  long unsigned int _17;
  long unsigned int _18;
  long unsigned int _19;
  long unsigned int _20;
  long unsigned int _21;
  long unsigned int _22;
  long unsigned int _23;
  long unsigned int _28;
  long unsigned int _29;
  uint32 _31;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLCLKMUX;
  _2 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLDV;
  _3 = _1 ^ _2;
  _4 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLSR;
  _5 = _3 ^ _4;
  _6 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLODIV[8];
  _7 = _5 ^ _6;
  Clock_Ip_u32PeriphPhi8Checksum.9_8 = Clock_Ip_u32PeriphPhi8Checksum;
  if (_7 != Clock_Ip_u32PeriphPhi8Checksum.9_8)
    goto <bb 3>; [48.88%]
  else
    goto <bb 4>; [51.12%]

  <bb 3> [local count: 524845004]:
  # DEBUG BEGIN_STMT
  _9 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLCLKMUX;
  _10 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLDV;
  _11 = _9 ^ _10;
  _12 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLSR;
  _13 = _11 ^ _12;
  _14 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLODIV[8];
  _15 = _13 ^ _14;
  Clock_Ip_u32PeriphPhi8Checksum = _15;
  # DEBUG BEGIN_STMT
  _16 = Clock_Ip_Get_PERIPHPLL_CLK_Frequency ();
  # DEBUG BEGIN_STMT
  _17 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLODIV[8];
  _18 = _17 >> 31;
  _28 = Clock_Ip_u32EnableDivider[_18];
  _19 = _16 & _28;
  # DEBUG BEGIN_STMT
  _20 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLODIV[8];
  _21 = _20 >> 16;
  _22 = _21 & 255;
  _29 = _22 + 1;
  _23 = _19 / _29;
  Clock_Ip_u32PeriphPhi8Freq = _23;

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _31 = Clock_Ip_u32PeriphPhi8Freq;
  return _31;

}



;; Function Clock_Ip_Get_PERIPHPLL_PHI7_Frequency (Clock_Ip_Get_PERIPHPLL_PHI7_Frequency, funcdef_no=21, decl_uid=6423, cgraph_uid=22, symbol_order=74)

Modification phase of node Clock_Ip_Get_PERIPHPLL_PHI7_Frequency/74
Clock_Ip_Get_PERIPHPLL_PHI7_Frequency ()
{
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int Clock_Ip_u32PeriphPhi7Checksum.12_8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int _15;
  long unsigned int _16;
  long unsigned int _17;
  long unsigned int _18;
  long unsigned int _19;
  long unsigned int _20;
  long unsigned int _21;
  long unsigned int _22;
  long unsigned int _23;
  long unsigned int _28;
  long unsigned int _29;
  uint32 _31;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLCLKMUX;
  _2 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLDV;
  _3 = _1 ^ _2;
  _4 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLSR;
  _5 = _3 ^ _4;
  _6 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLODIV[7];
  _7 = _5 ^ _6;
  Clock_Ip_u32PeriphPhi7Checksum.12_8 = Clock_Ip_u32PeriphPhi7Checksum;
  if (_7 != Clock_Ip_u32PeriphPhi7Checksum.12_8)
    goto <bb 3>; [48.88%]
  else
    goto <bb 4>; [51.12%]

  <bb 3> [local count: 524845004]:
  # DEBUG BEGIN_STMT
  _9 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLCLKMUX;
  _10 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLDV;
  _11 = _9 ^ _10;
  _12 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLSR;
  _13 = _11 ^ _12;
  _14 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLODIV[7];
  _15 = _13 ^ _14;
  Clock_Ip_u32PeriphPhi7Checksum = _15;
  # DEBUG BEGIN_STMT
  _16 = Clock_Ip_Get_PERIPHPLL_CLK_Frequency ();
  # DEBUG BEGIN_STMT
  _17 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLODIV[7];
  _18 = _17 >> 31;
  _28 = Clock_Ip_u32EnableDivider[_18];
  _19 = _16 & _28;
  # DEBUG BEGIN_STMT
  _20 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLODIV[7];
  _21 = _20 >> 16;
  _22 = _21 & 255;
  _29 = _22 + 1;
  _23 = _19 / _29;
  Clock_Ip_u32PeriphPhi7Freq = _23;

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _31 = Clock_Ip_u32PeriphPhi7Freq;
  return _31;

}



;; Function Clock_Ip_Get_PERIPHPLL_PHI6_Frequency (Clock_Ip_Get_PERIPHPLL_PHI6_Frequency, funcdef_no=20, decl_uid=6421, cgraph_uid=21, symbol_order=73)

Modification phase of node Clock_Ip_Get_PERIPHPLL_PHI6_Frequency/73
Clock_Ip_Get_PERIPHPLL_PHI6_Frequency ()
{
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int Clock_Ip_u32PeriphPhi6Checksum.15_8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int _15;
  long unsigned int _16;
  long unsigned int _17;
  long unsigned int _18;
  long unsigned int _19;
  long unsigned int _20;
  long unsigned int _21;
  long unsigned int _22;
  long unsigned int _23;
  long unsigned int _28;
  long unsigned int _29;
  uint32 _31;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLCLKMUX;
  _2 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLDV;
  _3 = _1 ^ _2;
  _4 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLSR;
  _5 = _3 ^ _4;
  _6 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLODIV[6];
  _7 = _5 ^ _6;
  Clock_Ip_u32PeriphPhi6Checksum.15_8 = Clock_Ip_u32PeriphPhi6Checksum;
  if (_7 != Clock_Ip_u32PeriphPhi6Checksum.15_8)
    goto <bb 3>; [48.88%]
  else
    goto <bb 4>; [51.12%]

  <bb 3> [local count: 524845004]:
  # DEBUG BEGIN_STMT
  _9 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLCLKMUX;
  _10 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLDV;
  _11 = _9 ^ _10;
  _12 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLSR;
  _13 = _11 ^ _12;
  _14 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLODIV[6];
  _15 = _13 ^ _14;
  Clock_Ip_u32PeriphPhi6Checksum = _15;
  # DEBUG BEGIN_STMT
  _16 = Clock_Ip_Get_PERIPHPLL_CLK_Frequency ();
  # DEBUG BEGIN_STMT
  _17 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLODIV[6];
  _18 = _17 >> 31;
  _28 = Clock_Ip_u32EnableDivider[_18];
  _19 = _16 & _28;
  # DEBUG BEGIN_STMT
  _20 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLODIV[6];
  _21 = _20 >> 16;
  _22 = _21 & 255;
  _29 = _22 + 1;
  _23 = _19 / _29;
  Clock_Ip_u32PeriphPhi6Freq = _23;

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _31 = Clock_Ip_u32PeriphPhi6Freq;
  return _31;

}



;; Function Clock_Ip_Get_PERIPHPLL_PHI5_Frequency (Clock_Ip_Get_PERIPHPLL_PHI5_Frequency, funcdef_no=19, decl_uid=6419, cgraph_uid=20, symbol_order=72)

Modification phase of node Clock_Ip_Get_PERIPHPLL_PHI5_Frequency/72
Clock_Ip_Get_PERIPHPLL_PHI5_Frequency ()
{
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int Clock_Ip_u32PeriphPhi5Checksum.18_8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int _15;
  long unsigned int _16;
  long unsigned int _17;
  long unsigned int _18;
  long unsigned int _19;
  long unsigned int _20;
  long unsigned int _21;
  long unsigned int _22;
  long unsigned int _23;
  long unsigned int _28;
  long unsigned int _29;
  uint32 _31;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLCLKMUX;
  _2 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLDV;
  _3 = _1 ^ _2;
  _4 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLSR;
  _5 = _3 ^ _4;
  _6 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLODIV[5];
  _7 = _5 ^ _6;
  Clock_Ip_u32PeriphPhi5Checksum.18_8 = Clock_Ip_u32PeriphPhi5Checksum;
  if (_7 != Clock_Ip_u32PeriphPhi5Checksum.18_8)
    goto <bb 3>; [48.88%]
  else
    goto <bb 4>; [51.12%]

  <bb 3> [local count: 524845004]:
  # DEBUG BEGIN_STMT
  _9 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLCLKMUX;
  _10 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLDV;
  _11 = _9 ^ _10;
  _12 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLSR;
  _13 = _11 ^ _12;
  _14 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLODIV[5];
  _15 = _13 ^ _14;
  Clock_Ip_u32PeriphPhi5Checksum = _15;
  # DEBUG BEGIN_STMT
  _16 = Clock_Ip_Get_PERIPHPLL_CLK_Frequency ();
  # DEBUG BEGIN_STMT
  _17 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLODIV[5];
  _18 = _17 >> 31;
  _28 = Clock_Ip_u32EnableDivider[_18];
  _19 = _16 & _28;
  # DEBUG BEGIN_STMT
  _20 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLODIV[5];
  _21 = _20 >> 16;
  _22 = _21 & 255;
  _29 = _22 + 1;
  _23 = _19 / _29;
  Clock_Ip_u32PeriphPhi5Freq = _23;

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _31 = Clock_Ip_u32PeriphPhi5Freq;
  return _31;

}



;; Function Clock_Ip_Get_GMAC_1_INT_REF_CLK_Frequency (Clock_Ip_Get_GMAC_1_INT_REF_CLK_Frequency, funcdef_no=52, decl_uid=6489, cgraph_uid=53, symbol_order=105)

Modification phase of node Clock_Ip_Get_GMAC_1_INT_REF_CLK_Frequency/105
Clock_Ip_Get_GMAC_1_INT_REF_CLK_Frequency ()
{
  uint32 Frequency;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct MC_CGM_0_Type *)1074561024B].MUX_6_CSS;
  _2 = _1 >> 24;
  _3 = _2 & 31;
  if (_3 != 23)
    goto <bb 4>; [79.76%]
  else
    goto <bb 3>; [20.24%]

  <bb 3> [local count: 217325345]:
  # DEBUG BEGIN_STMT
  Frequency_8 = Clock_Ip_Get_PERIPHPLL_PHI5_Frequency ();
  # DEBUG Frequency => Frequency_8

  <bb 4> [local count: 1073741824]:
  # Frequency_4 = PHI <48000000(2), Frequency_8(3)>
  # DEBUG Frequency => Frequency_4
  # DEBUG BEGIN_STMT
  Frequency_9 = Frequency_4 / 10;
  # DEBUG Frequency => Frequency_9
  # DEBUG BEGIN_STMT
  return Frequency_9;

}



;; Function Clock_Ip_Get_PERIPHPLL_PHI4_Frequency (Clock_Ip_Get_PERIPHPLL_PHI4_Frequency, funcdef_no=18, decl_uid=6417, cgraph_uid=19, symbol_order=71)

Modification phase of node Clock_Ip_Get_PERIPHPLL_PHI4_Frequency/71
Clock_Ip_Get_PERIPHPLL_PHI4_Frequency ()
{
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int Clock_Ip_u32PeriphPhi4Checksum.21_8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int _15;
  long unsigned int _16;
  long unsigned int _17;
  long unsigned int _18;
  long unsigned int _19;
  long unsigned int _20;
  long unsigned int _21;
  long unsigned int _22;
  long unsigned int _23;
  long unsigned int _28;
  long unsigned int _29;
  uint32 _31;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLCLKMUX;
  _2 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLDV;
  _3 = _1 ^ _2;
  _4 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLSR;
  _5 = _3 ^ _4;
  _6 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLODIV[4];
  _7 = _5 ^ _6;
  Clock_Ip_u32PeriphPhi4Checksum.21_8 = Clock_Ip_u32PeriphPhi4Checksum;
  if (_7 != Clock_Ip_u32PeriphPhi4Checksum.21_8)
    goto <bb 3>; [48.88%]
  else
    goto <bb 4>; [51.12%]

  <bb 3> [local count: 524845004]:
  # DEBUG BEGIN_STMT
  _9 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLCLKMUX;
  _10 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLDV;
  _11 = _9 ^ _10;
  _12 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLSR;
  _13 = _11 ^ _12;
  _14 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLODIV[4];
  _15 = _13 ^ _14;
  Clock_Ip_u32PeriphPhi4Checksum = _15;
  # DEBUG BEGIN_STMT
  _16 = Clock_Ip_Get_PERIPHPLL_CLK_Frequency ();
  # DEBUG BEGIN_STMT
  _17 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLODIV[4];
  _18 = _17 >> 31;
  _28 = Clock_Ip_u32EnableDivider[_18];
  _19 = _16 & _28;
  # DEBUG BEGIN_STMT
  _20 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLODIV[4];
  _21 = _20 >> 16;
  _22 = _21 & 255;
  _29 = _22 + 1;
  _23 = _19 / _29;
  Clock_Ip_u32PeriphPhi4Freq = _23;

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _31 = Clock_Ip_u32PeriphPhi4Freq;
  return _31;

}



;; Function Clock_Ip_Get_PERIPHPLL_PHI3_Frequency (Clock_Ip_Get_PERIPHPLL_PHI3_Frequency, funcdef_no=17, decl_uid=6415, cgraph_uid=18, symbol_order=70)

Modification phase of node Clock_Ip_Get_PERIPHPLL_PHI3_Frequency/70
Clock_Ip_Get_PERIPHPLL_PHI3_Frequency ()
{
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int Clock_Ip_u32PeriphPhi3Checksum.24_8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int _15;
  long unsigned int _16;
  long unsigned int _17;
  long unsigned int _18;
  long unsigned int _19;
  long unsigned int _20;
  long unsigned int _21;
  long unsigned int _22;
  long unsigned int _23;
  long unsigned int _28;
  long unsigned int _29;
  uint32 _31;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLCLKMUX;
  _2 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLDV;
  _3 = _1 ^ _2;
  _4 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLSR;
  _5 = _3 ^ _4;
  _6 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLODIV[3];
  _7 = _5 ^ _6;
  Clock_Ip_u32PeriphPhi3Checksum.24_8 = Clock_Ip_u32PeriphPhi3Checksum;
  if (_7 != Clock_Ip_u32PeriphPhi3Checksum.24_8)
    goto <bb 3>; [48.88%]
  else
    goto <bb 4>; [51.12%]

  <bb 3> [local count: 524845004]:
  # DEBUG BEGIN_STMT
  _9 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLCLKMUX;
  _10 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLDV;
  _11 = _9 ^ _10;
  _12 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLSR;
  _13 = _11 ^ _12;
  _14 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLODIV[3];
  _15 = _13 ^ _14;
  Clock_Ip_u32PeriphPhi3Checksum = _15;
  # DEBUG BEGIN_STMT
  _16 = Clock_Ip_Get_PERIPHPLL_CLK_Frequency ();
  # DEBUG BEGIN_STMT
  _17 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLODIV[3];
  _18 = _17 >> 31;
  _28 = Clock_Ip_u32EnableDivider[_18];
  _19 = _16 & _28;
  # DEBUG BEGIN_STMT
  _20 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLODIV[3];
  _21 = _20 >> 16;
  _22 = _21 & 255;
  _29 = _22 + 1;
  _23 = _19 / _29;
  Clock_Ip_u32PeriphPhi3Freq = _23;

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _31 = Clock_Ip_u32PeriphPhi3Freq;
  return _31;

}



;; Function Clock_Ip_Get_PERIPHPLL_PHI2_Frequency (Clock_Ip_Get_PERIPHPLL_PHI2_Frequency, funcdef_no=16, decl_uid=6413, cgraph_uid=17, symbol_order=69)

Modification phase of node Clock_Ip_Get_PERIPHPLL_PHI2_Frequency/69
Clock_Ip_Get_PERIPHPLL_PHI2_Frequency ()
{
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int Clock_Ip_u32PeriphPhi2Checksum.27_8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int _15;
  long unsigned int _16;
  long unsigned int _17;
  long unsigned int _18;
  long unsigned int _19;
  long unsigned int _20;
  long unsigned int _21;
  long unsigned int _22;
  long unsigned int _23;
  long unsigned int _28;
  long unsigned int _29;
  uint32 _31;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLCLKMUX;
  _2 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLDV;
  _3 = _1 ^ _2;
  _4 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLSR;
  _5 = _3 ^ _4;
  _6 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLODIV[2];
  _7 = _5 ^ _6;
  Clock_Ip_u32PeriphPhi2Checksum.27_8 = Clock_Ip_u32PeriphPhi2Checksum;
  if (_7 != Clock_Ip_u32PeriphPhi2Checksum.27_8)
    goto <bb 3>; [48.88%]
  else
    goto <bb 4>; [51.12%]

  <bb 3> [local count: 524845004]:
  # DEBUG BEGIN_STMT
  _9 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLCLKMUX;
  _10 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLDV;
  _11 = _9 ^ _10;
  _12 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLSR;
  _13 = _11 ^ _12;
  _14 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLODIV[2];
  _15 = _13 ^ _14;
  Clock_Ip_u32PeriphPhi2Checksum = _15;
  # DEBUG BEGIN_STMT
  _16 = Clock_Ip_Get_PERIPHPLL_CLK_Frequency ();
  # DEBUG BEGIN_STMT
  _17 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLODIV[2];
  _18 = _17 >> 31;
  _28 = Clock_Ip_u32EnableDivider[_18];
  _19 = _16 & _28;
  # DEBUG BEGIN_STMT
  _20 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLODIV[2];
  _21 = _20 >> 16;
  _22 = _21 & 255;
  _29 = _22 + 1;
  _23 = _19 / _29;
  Clock_Ip_u32PeriphPhi2Freq = _23;

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _31 = Clock_Ip_u32PeriphPhi2Freq;
  return _31;

}



;; Function Clock_Ip_Get_PERIPHPLL_PHI1_Frequency (Clock_Ip_Get_PERIPHPLL_PHI1_Frequency, funcdef_no=15, decl_uid=6411, cgraph_uid=16, symbol_order=68)

Modification phase of node Clock_Ip_Get_PERIPHPLL_PHI1_Frequency/68
Clock_Ip_Get_PERIPHPLL_PHI1_Frequency ()
{
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int Clock_Ip_u32PeriphPhi1Checksum.30_8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int _15;
  long unsigned int _16;
  long unsigned int _17;
  long unsigned int _18;
  long unsigned int _19;
  long unsigned int _20;
  long unsigned int _21;
  long unsigned int _22;
  long unsigned int _23;
  long unsigned int _28;
  long unsigned int _29;
  uint32 _31;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLCLKMUX;
  _2 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLDV;
  _3 = _1 ^ _2;
  _4 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLSR;
  _5 = _3 ^ _4;
  _6 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLODIV[1];
  _7 = _5 ^ _6;
  Clock_Ip_u32PeriphPhi1Checksum.30_8 = Clock_Ip_u32PeriphPhi1Checksum;
  if (_7 != Clock_Ip_u32PeriphPhi1Checksum.30_8)
    goto <bb 3>; [48.88%]
  else
    goto <bb 4>; [51.12%]

  <bb 3> [local count: 524845004]:
  # DEBUG BEGIN_STMT
  _9 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLCLKMUX;
  _10 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLDV;
  _11 = _9 ^ _10;
  _12 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLSR;
  _13 = _11 ^ _12;
  _14 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLODIV[1];
  _15 = _13 ^ _14;
  Clock_Ip_u32PeriphPhi1Checksum = _15;
  # DEBUG BEGIN_STMT
  _16 = Clock_Ip_Get_PERIPHPLL_CLK_Frequency ();
  # DEBUG BEGIN_STMT
  _17 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLODIV[1];
  _18 = _17 >> 31;
  _28 = Clock_Ip_u32EnableDivider[_18];
  _19 = _16 & _28;
  # DEBUG BEGIN_STMT
  _20 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLODIV[1];
  _21 = _20 >> 16;
  _22 = _21 & 255;
  _29 = _22 + 1;
  _23 = _19 / _29;
  Clock_Ip_u32PeriphPhi1Freq = _23;

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _31 = Clock_Ip_u32PeriphPhi1Freq;
  return _31;

}



;; Function Clock_Ip_Get_PERIPHPLL_PHI0_Frequency (Clock_Ip_Get_PERIPHPLL_PHI0_Frequency, funcdef_no=14, decl_uid=6409, cgraph_uid=15, symbol_order=67)

Modification phase of node Clock_Ip_Get_PERIPHPLL_PHI0_Frequency/67
Clock_Ip_Get_PERIPHPLL_PHI0_Frequency ()
{
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int Clock_Ip_u32PeriphPhi0Checksum.33_8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int _15;
  long unsigned int _16;
  long unsigned int _17;
  long unsigned int _18;
  long unsigned int _19;
  long unsigned int _20;
  long unsigned int _21;
  long unsigned int _22;
  long unsigned int _23;
  long unsigned int _28;
  long unsigned int _29;
  uint32 _31;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLCLKMUX;
  _2 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLDV;
  _3 = _1 ^ _2;
  _4 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLSR;
  _5 = _3 ^ _4;
  _6 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLODIV[0];
  _7 = _5 ^ _6;
  Clock_Ip_u32PeriphPhi0Checksum.33_8 = Clock_Ip_u32PeriphPhi0Checksum;
  if (_7 != Clock_Ip_u32PeriphPhi0Checksum.33_8)
    goto <bb 3>; [48.88%]
  else
    goto <bb 4>; [51.12%]

  <bb 3> [local count: 524845004]:
  # DEBUG BEGIN_STMT
  _9 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLCLKMUX;
  _10 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLDV;
  _11 = _9 ^ _10;
  _12 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLSR;
  _13 = _11 ^ _12;
  _14 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLODIV[0];
  _15 = _13 ^ _14;
  Clock_Ip_u32PeriphPhi0Checksum = _15;
  # DEBUG BEGIN_STMT
  _16 = Clock_Ip_Get_PERIPHPLL_CLK_Frequency ();
  # DEBUG BEGIN_STMT
  _17 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLODIV[0];
  _18 = _17 >> 31;
  _28 = Clock_Ip_u32EnableDivider[_18];
  _19 = _16 & _28;
  # DEBUG BEGIN_STMT
  _20 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLODIV[0];
  _21 = _20 >> 16;
  _22 = _21 & 255;
  _29 = _22 + 1;
  _23 = _19 / _29;
  Clock_Ip_u32PeriphPhi0Freq = _23;

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _31 = Clock_Ip_u32PeriphPhi0Freq;
  return _31;

}



;; Function Clock_Ip_Get_PERIPHPLL_DFS2_Frequency (Clock_Ip_Get_PERIPHPLL_DFS2_Frequency, funcdef_no=25, decl_uid=6431, cgraph_uid=26, symbol_order=78)

Modification phase of node Clock_Ip_Get_PERIPHPLL_DFS2_Frequency/78
Clock_Ip_Get_PERIPHPLL_DFS2_Frequency ()
{
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int Clock_Ip_u32PeriphDfs2Checksum.0_8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int _15;
  long unsigned int _16;
  long unsigned int _17;
  long unsigned int _18;
  long unsigned int _19;
  uint32 iftmp.1_20;
  uint32 iftmp.1_27;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLCLKMUX;
  _2 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLDV;
  _3 = _1 ^ _2;
  _4 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLSR;
  _5 = _3 ^ _4;
  _6 ={v} MEM[(struct DFS_Type *)1074528256B].DVPORT[1];
  _7 = _5 ^ _6;
  Clock_Ip_u32PeriphDfs2Checksum.0_8 = Clock_Ip_u32PeriphDfs2Checksum;
  if (_7 != Clock_Ip_u32PeriphDfs2Checksum.0_8)
    goto <bb 3>; [48.88%]
  else
    goto <bb 4>; [51.12%]

  <bb 3> [local count: 524845004]:
  # DEBUG BEGIN_STMT
  _9 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLCLKMUX;
  _10 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLDV;
  _11 = _9 ^ _10;
  _12 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLSR;
  _13 = _11 ^ _12;
  _14 ={v} MEM[(struct DFS_Type *)1074528256B].DVPORT[1];
  _15 = _13 ^ _14;
  Clock_Ip_u32PeriphDfs2Checksum = _15;
  # DEBUG BEGIN_STMT
  _16 = Clock_Ip_Get_PERIPHPLL_CLK_Frequency ();
  _17 = Clock_Ip_DFS_OUTPUT (1074528256B, 1, _16);
  Clock_Ip_u32PeriphDfs2Freq = _17;

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _18 ={v} MEM[(struct DFS_Type *)1074528256B].PORTSR;
  _19 = _18 & 2;
  if (_19 != 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 5> [local count: 536870913]:
  iftmp.1_27 = Clock_Ip_u32PeriphDfs2Freq;

  <bb 6> [local count: 1073741824]:
  # iftmp.1_20 = PHI <iftmp.1_27(5), 0(4)>
  return iftmp.1_20;

}



;; Function Clock_Ip_Get_PERIPHPLL_DFS1_Frequency (Clock_Ip_Get_PERIPHPLL_DFS1_Frequency, funcdef_no=24, decl_uid=6429, cgraph_uid=25, symbol_order=77)

Modification phase of node Clock_Ip_Get_PERIPHPLL_DFS1_Frequency/77
Clock_Ip_Get_PERIPHPLL_DFS1_Frequency ()
{
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int Clock_Ip_u32PeriphDfs1Checksum.4_8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int _15;
  long unsigned int _16;
  long unsigned int _17;
  long unsigned int _18;
  long unsigned int _19;
  uint32 iftmp.5_20;
  uint32 iftmp.5_27;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLCLKMUX;
  _2 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLDV;
  _3 = _1 ^ _2;
  _4 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLSR;
  _5 = _3 ^ _4;
  _6 ={v} MEM[(struct DFS_Type *)1074528256B].DVPORT[0];
  _7 = _5 ^ _6;
  Clock_Ip_u32PeriphDfs1Checksum.4_8 = Clock_Ip_u32PeriphDfs1Checksum;
  if (_7 != Clock_Ip_u32PeriphDfs1Checksum.4_8)
    goto <bb 3>; [48.88%]
  else
    goto <bb 4>; [51.12%]

  <bb 3> [local count: 524845004]:
  # DEBUG BEGIN_STMT
  _9 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLCLKMUX;
  _10 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLDV;
  _11 = _9 ^ _10;
  _12 ={v} MEM[(struct PLLDIG_Type *)1074511872B].PLLSR;
  _13 = _11 ^ _12;
  _14 ={v} MEM[(struct DFS_Type *)1074528256B].DVPORT[0];
  _15 = _13 ^ _14;
  Clock_Ip_u32PeriphDfs1Checksum = _15;
  # DEBUG BEGIN_STMT
  _16 = Clock_Ip_Get_PERIPHPLL_CLK_Frequency ();
  _17 = Clock_Ip_DFS_OUTPUT (1074528256B, 0, _16);
  Clock_Ip_u32PeriphDfs1Freq = _17;

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _18 ={v} MEM[(struct DFS_Type *)1074528256B].PORTSR;
  _19 = _18 & 1;
  if (_19 != 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 5> [local count: 536870913]:
  iftmp.5_27 = Clock_Ip_u32PeriphDfs1Freq;

  <bb 6> [local count: 1073741824]:
  # iftmp.5_20 = PHI <iftmp.5_27(5), 0(4)>
  return iftmp.5_20;

}



;; Function Clock_Ip_SetExternalOscillatorFrequency (Clock_Ip_SetExternalOscillatorFrequency, funcdef_no=92, decl_uid=6355, cgraph_uid=93, symbol_order=145)

Modification phase of node Clock_Ip_SetExternalOscillatorFrequency/145
Clock_Ip_SetExternalOscillatorFrequency (Clock_Ip_NameType ExtOscName, uint32 Frequency)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  Clock_Ip_u32Fxosc = Frequency_2(D);
  return;

}



;; Function Clock_Ip_GetFreq (Clock_Ip_GetFreq, funcdef_no=93, decl_uid=6352, cgraph_uid=94, symbol_order=146)

Modification phase of node Clock_Ip_GetFreq/146
Clock_Ip_GetFreq (Clock_Ip_NameType ClockName)
{
  int _1;
  uint32 (*<T752>) (void) _2;
  uint32 _6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = (int) ClockName_3(D);
  _2 = Clock_Ip_apfFreqTable[_1];
  _6 = _2 ();
  return _6;

}



;; Function Clock_Ip_SetExternalSignalFrequency (Clock_Ip_SetExternalSignalFrequency, funcdef_no=94, decl_uid=6350, cgraph_uid=95, symbol_order=147)

Modification phase of node Clock_Ip_SetExternalSignalFrequency/147
Clock_Ip_SetExternalSignalFrequency (Clock_Ip_NameType SignalName, uint32 Frequency)
{
  uint32 Index;
  <unnamed type> _1;

  <bb 2> [local count: 122473676]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG Index => 0
  goto <bb 6>; [100.00%]

  <bb 3> [local count: 1006632962]:
  # DEBUG BEGIN_STMT
  _1 = Clock_Ip_axExtSignalFreqEntries[Index_2].Name;
  if (_1 == SignalName_6(D))
    goto <bb 4>; [5.50%]
  else
    goto <bb 5>; [94.50%]

  <bb 4> [local count: 55364813]:
  # Index_4 = PHI <Index_2(3)>
  # DEBUG BEGIN_STMT
  Clock_Ip_axExtSignalFreqEntries[Index_4].Frequency = Frequency_8(D);
  # DEBUG BEGIN_STMT
  goto <bb 7>; [100.00%]

  <bb 5> [local count: 951268149]:
  # DEBUG BEGIN_STMT
  Index_7 = Index_2 + 1;
  # DEBUG Index => Index_7

  <bb 6> [local count: 1073741824]:
  # Index_2 = PHI <0(2), Index_7(5)>
  # DEBUG Index => Index_2
  # DEBUG BEGIN_STMT
  if (Index_2 != 15)
    goto <bb 3>; [93.75%]
  else
    goto <bb 7>; [6.25%]

  <bb 7> [local count: 122473677]:
  return;

}


