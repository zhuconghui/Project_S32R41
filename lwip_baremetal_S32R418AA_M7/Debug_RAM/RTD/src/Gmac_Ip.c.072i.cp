
IPA constant propagation start:
Determining dynamic type for call: Crc_8 = Gmac_Ip_ComputeCRC32 (&Tag32, 2);
  Starting walk at: Crc_8 = Gmac_Ip_ComputeCRC32 (&Tag32, 2);
  instance pointer: &Tag32  Outer instance pointer: Tag32 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: crc_8 = Gmac_Ip_ComputeCRC32 (&tag32, 2);
  Starting walk at: crc_8 = Gmac_Ip_ComputeCRC32 (&tag32, 2);
  instance pointer: &tag32  Outer instance pointer: tag32 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: Crc_6 = Gmac_Ip_ComputeCRC32 (MacAddr_5(D), 6);
  Starting walk at: Crc_6 = Gmac_Ip_ComputeCRC32 (MacAddr_5(D), 6);
  instance pointer: MacAddr_5(D)  Outer instance pointer: MacAddr_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: Crc_6 = Gmac_Ip_ComputeCRC32 (MacAddr_5(D), 6);
  Starting walk at: Crc_6 = Gmac_Ip_ComputeCRC32 (MacAddr_5(D), 6);
  instance pointer: MacAddr_5(D)  Outer instance pointer: MacAddr_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: Gmac_Ip_GetTimestamp (Base_39, Bd_29, _23);
  Starting walk at: Gmac_Ip_GetTimestamp (Base_39, Bd_29, _23);
  instance pointer: Base_39  Outer instance pointer: Base_39 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: Gmac_Ip_GetTimestamp (Base_39, Bd_29, _23);
  Starting walk at: Gmac_Ip_GetTimestamp (Base_39, Bd_29, _23);
  instance pointer: Bd_29  Outer instance pointer: Bd_29 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: Gmac_Ip_GetTimestamp (Base_39, Bd_29, _23);
  Starting walk at: Gmac_Ip_GetTimestamp (Base_39, Bd_29, _23);
  instance pointer: _23  Outer instance pointer: Info_51(D) offset: 32 (bits) vtbl reference: 
Determining dynamic type for call: _15 = Gmac_Ip_RestoreRxCtxtDescr (iftmp.34_28);
  Starting walk at: _15 = Gmac_Ip_RestoreRxCtxtDescr (iftmp.34_28);
  instance pointer: iftmp.34_28  Outer instance pointer: iftmp.34_28 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: Gmac_Ip_ReadTimeStampInfo (Instance_58(D), Ring_59(D), Info_72(D));
  Starting walk at: Gmac_Ip_ReadTimeStampInfo (Instance_58(D), Ring_59(D), Info_72(D));
  instance pointer: Info_72(D)  Outer instance pointer: Info_72(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:CacheStatus_65 = Cache_Ip_InvalidateByAddr (1, 4, _9, _10);
Determining dynamic type for call: Status_9 = Gmac_Ip_InitDMA (Instance_4(D), Config_7(D));
  Starting walk at: Status_9 = Gmac_Ip_InitDMA (Instance_4(D), Config_7(D));
  instance pointer: Config_7(D)  Outer instance pointer: Config_7(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: Gmac_Ip_InitMTL (Instance_4(D), Config_7(D));
  Starting walk at: Gmac_Ip_InitMTL (Instance_4(D), Config_7(D));
  instance pointer: Config_7(D)  Outer instance pointer: Config_7(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:Status_9 = Gmac_Ip_InitDMA (Instance_4(D), Config_7(D));
Determining dynamic type for call: Gmac_Ip_SetMacAddr (Instance_4(D), _2);
  Starting walk at: Gmac_Ip_SetMacAddr (Instance_4(D), _2);
  instance pointer: _2  Outer instance pointer: _2 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:Gmac_Ip_InitMTL (Instance_4(D), Config_7(D));
  Function call may change dynamic type:Status_9 = Gmac_Ip_InitDMA (Instance_4(D), Config_7(D));
Determining dynamic type for call: Gmac_Ip_InitMAC.isra.0 (Base_6, _15);
  Starting walk at: Gmac_Ip_InitMAC.isra.0 (Base_6, _15);
  instance pointer: Base_6  Outer instance pointer: Base_6 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:Gmac_Ip_SetMacAddr (Instance_4(D), _2);
  Function call may change dynamic type:Gmac_Ip_InitMTL (Instance_4(D), Config_7(D));
  Function call may change dynamic type:Status_9 = Gmac_Ip_InitDMA (Instance_4(D), Config_7(D));
Determining dynamic type for call: Gmac_Ip_InitMAC.isra.0 (Base_6, _15);
  Starting walk at: Gmac_Ip_InitMAC.isra.0 (Base_6, _15);
  instance pointer: _15  Outer instance pointer: _15 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:Gmac_Ip_SetMacAddr (Instance_4(D), _2);
  Function call may change dynamic type:Gmac_Ip_InitMTL (Instance_4(D), Config_7(D));
  Function call may change dynamic type:Status_9 = Gmac_Ip_InitDMA (Instance_4(D), Config_7(D));
Determining dynamic type for call: Gmac_Ip_InitStateStructure (Instance_4(D), Config_7(D));
  Starting walk at: Gmac_Ip_InitStateStructure (Instance_4(D), Config_7(D));
  instance pointer: Config_7(D)  Outer instance pointer: Config_7(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:Gmac_Ip_InitMAC.isra.0 (Base_6, _15);
  Function call may change dynamic type:Gmac_Ip_SetMacAddr (Instance_4(D), _2);
  Function call may change dynamic type:Gmac_Ip_InitMTL (Instance_4(D), Config_7(D));
  Function call may change dynamic type:Status_9 = Gmac_Ip_InitDMA (Instance_4(D), Config_7(D));
Determining dynamic type for call: Gmac_Ip_TxTimeAwareShaperInit.isra.0 (Instance_4(D), _16);
  Starting walk at: Gmac_Ip_TxTimeAwareShaperInit.isra.0 (Instance_4(D), _16);
  instance pointer: _16  Outer instance pointer: _16 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:Gmac_Ip_InitStateStructure (Instance_4(D), Config_7(D));
  Function call may change dynamic type:Gmac_Ip_InitMAC.isra.0 (Base_6, _15);
  Function call may change dynamic type:Gmac_Ip_SetMacAddr (Instance_4(D), _2);
  Function call may change dynamic type:Gmac_Ip_InitMTL (Instance_4(D), Config_7(D));
  Function call may change dynamic type:Status_9 = Gmac_Ip_InitDMA (Instance_4(D), Config_7(D));
Determining dynamic type for call: Gmac_Ip_InitTxBD (Instance_16(D), _8, _9);
  Starting walk at: Gmac_Ip_InitTxBD (Instance_16(D), _8, _9);
  instance pointer: _8  Outer instance pointer: _8 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:GMAC_StartTimeOut (&StartTime, &ElapsedTime, &TimeoutTicks, 1000);
  Function call may change dynamic type:_7 = GMAC_TimeoutExpired (&StartTime, &ElapsedTime, TimeoutTicks.0_6);
Determining dynamic type for call: Gmac_Ip_InitTxBD (Instance_16(D), _8, _9);
  Starting walk at: Gmac_Ip_InitTxBD (Instance_16(D), _8, _9);
  instance pointer: _9  Outer instance pointer: _9 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:GMAC_StartTimeOut (&StartTime, &ElapsedTime, &TimeoutTicks, 1000);
  Function call may change dynamic type:_7 = GMAC_TimeoutExpired (&StartTime, &ElapsedTime, TimeoutTicks.0_6);
Determining dynamic type for call: Gmac_Ip_InitRxBD (Instance_16(D), _10, _11);
  Starting walk at: Gmac_Ip_InitRxBD (Instance_16(D), _10, _11);
  instance pointer: _10  Outer instance pointer: _10 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:Gmac_Ip_InitTxBD (Instance_16(D), _8, _9);
  Function call may change dynamic type:GMAC_StartTimeOut (&StartTime, &ElapsedTime, &TimeoutTicks, 1000);
  Function call may change dynamic type:_7 = GMAC_TimeoutExpired (&StartTime, &ElapsedTime, TimeoutTicks.0_6);
Determining dynamic type for call: Gmac_Ip_InitRxBD (Instance_16(D), _10, _11);
  Starting walk at: Gmac_Ip_InitRxBD (Instance_16(D), _10, _11);
  instance pointer: _11  Outer instance pointer: _11 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:Gmac_Ip_InitTxBD (Instance_16(D), _8, _9);
  Function call may change dynamic type:GMAC_StartTimeOut (&StartTime, &ElapsedTime, &TimeoutTicks, 1000);
  Function call may change dynamic type:_7 = GMAC_TimeoutExpired (&StartTime, &ElapsedTime, TimeoutTicks.0_6);

IPA structures before propagation:

Jump functions:
  Jump functions of caller  Gmac_Ip_TxTimeAwareShaperInit.isra.0/100:
  Jump functions of caller  Gmac_Ip_InitMAC.isra.0/99:
  Jump functions of caller  GMAC_SetTxThreshold/98:
  Jump functions of caller  GMAC_SetTxStoreAndForward/97:
  Jump functions of caller  GMAC_SetSchedAlg/96:
  Jump functions of caller  GMAC_RemoveVlanFromHashTable/95:
  Jump functions of caller  GMAC_AddVlanToHashTable/94:
  Jump functions of caller  GMAC_RemoveFromHashTable/93:
  Jump functions of caller  GMAC_AddToHashTable/92:
  Jump functions of caller  GMAC_WriteManagementFrame/91:
  Jump functions of caller  Cache_Ip_InvalidateByAddr/87:
  Jump functions of caller  Cache_Ip_CleanByAddr/86:
  Jump functions of caller  GMAC_SetSpeed/85:
  Jump functions of caller  GMAC_SetPowerState/84:
  Jump functions of caller  GMAC_GetPowerState/83:
  Jump functions of caller  GMAC_EnableRxQueue/82:
  Jump functions of caller  GMAC_SetRxQueueOperationMode/81:
  Jump functions of caller  GMAC_SetRxQueuesDmaChMap/80:
  Jump functions of caller  GMAC_SetTxQueueOperationMode/79:
  Jump functions of caller  GMAC_SetTxQueueCreditBasedShaper/78:
  Jump functions of caller  GMAC_SetTxQueueQuantumWeight/77:
  Jump functions of caller  GMAC_TimeoutExpired/74:
  Jump functions of caller  GMAC_StartTimeOut/73:
  Jump functions of caller  Gmac_Ip_SetTxThreshold/71:
  Jump functions of caller  Gmac_Ip_EnableTxStoreAndForward/70:
  Jump functions of caller  Gmac_Ip_SetTxRingWeight/69:
  Jump functions of caller  Gmac_Ip_SetTxSchedAlgo/68:
  Jump functions of caller  Gmac_Ip_GetSysTime/67:
  Jump functions of caller  Gmac_Ip_SetRateRatioCorr/66:
  Jump functions of caller  Gmac_Ip_SetSysTimeCorr/65:
  Jump functions of caller  Gmac_Ip_InitSysTime/64:
  Jump functions of caller  Gmac_Ip_RemoveVlanTagFromHashTable/63:
    callsite  Gmac_Ip_RemoveVlanTagFromHashTable/63 -> Gmac_Ip_ComputeCRC32/5 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: CONST: 2
         value: 0x2, mask: 0x0
         Unknown VR
  Jump functions of caller  Gmac_Ip_AddVlanTagToHashTable/62:
    callsite  Gmac_Ip_AddVlanTagToHashTable/62 -> Gmac_Ip_ComputeCRC32/5 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: CONST: 2
         value: 0x2, mask: 0x0
         Unknown VR
  Jump functions of caller  Gmac_Ip_SetTxInnerVlanTag/61:
  Jump functions of caller  Gmac_Ip_SetTxOuterVlanTagForReplacement/60:
  Jump functions of caller  Gmac_Ip_SetTxOuterVlanTagForInsertion/59:
  Jump functions of caller  Gmac_Ip_EnableVlan/58:
  Jump functions of caller  Gmac_Ip_SetArpOffloading/57:
  Jump functions of caller  Gmac_Ip_SetAddrPerfectFilter/56:
  Jump functions of caller  Gmac_Ip_RemoveDstAddrFromHashFilter/55:
    callsite  Gmac_Ip_RemoveDstAddrFromHashFilter/55 -> Gmac_Ip_ComputeCRC32/5 : 
       param 0: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 6
         value: 0x6, mask: 0x0
         Unknown VR
  Jump functions of caller  Gmac_Ip_AddDstAddrToHashFilter/54:
    callsite  Gmac_Ip_AddDstAddrToHashFilter/54 -> Gmac_Ip_ComputeCRC32/5 : 
       param 0: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: CONST: 6
         value: 0x6, mask: 0x0
         Unknown VR
  Jump functions of caller  Gmac_Ip_SetHashOrPerfectFilter/53:
  Jump functions of caller  Gmac_Ip_SetMulticastHashFilter/52:
  Jump functions of caller  Gmac_Ip_SetUnicastHashFilter/51:
  Jump functions of caller  Gmac_Ip_SetMulticastForwardAll/50:
  Jump functions of caller  Gmac_Ip_SetBroadcastForwardAll/49:
  Jump functions of caller  Gmac_Ip_GetChInterruptFlags/48:
  Jump functions of caller  Gmac_Ip_GetInterruptFlags/47:
  Jump functions of caller  Gmac_Ip_GetMacAddr/46:
  Jump functions of caller  Gmac_Ip_SetMacAddr/45:
  Jump functions of caller  Gmac_Ip_MDIOWriteMMD/44:
  Jump functions of caller  Gmac_Ip_MDIOReadMMD/43:
  Jump functions of caller  Gmac_Ip_MDIOWrite/42:
  Jump functions of caller  Gmac_Ip_MDIORead/41:
  Jump functions of caller  Gmac_Ip_EnableMDIO/40:
  Jump functions of caller  Gmac_Ip_GetCounter/39:
  Jump functions of caller  Gmac_Ip_GetTransmitStatus/38:
    callsite  Gmac_Ip_GetTransmitStatus/38 -> Gmac_Ip_GetTimestamp/15 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: ANCESTOR: 3, offset 32
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
  Jump functions of caller  Gmac_Ip_IsFrameAvailable/37:
  Jump functions of caller  Gmac_Ip_ProvideRxBuff/36:
    callsite  Gmac_Ip_ProvideRxBuff/36 -> Gmac_Ip_RestoreRxCtxtDescr/16 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  Gmac_Ip_SetRxExternalBuffer/35:
  Jump functions of caller  Gmac_Ip_ReadFrame/34:
    callsite  Gmac_Ip_ReadFrame/34 -> Gmac_Ip_ReadTimeStampInfo/6 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Gmac_Ip_ReadFrame/34 -> Gmac_Ip_GetPayloadType/20 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0x7
         VR  [0, 7]
  Jump functions of caller  Gmac_Ip_SendMultiBufferFrame/33:
  Jump functions of caller  Gmac_Ip_SendFrame/32:
  Jump functions of caller  Gmac_Ip_GetTxMultiBuff/31:
  Jump functions of caller  Gmac_Ip_GetTxBuff/30:
  Jump functions of caller  Gmac_Ip_SetSpeed/29:
  Jump functions of caller  Gmac_Ip_DisableController/28:
    callsite  Gmac_Ip_DisableController/28 -> Gmac_Ip_RestoreRxDescr/18 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  Gmac_Ip_DisableController/28 -> Gmac_Ip_RestoreTxDescr/17 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  Gmac_Ip_DisableController/28 -> Gmac_Ip_CheckMTLEmpty/19 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  Gmac_Ip_DisableController/28 -> Gmac_Ip_CheckMTLEmpty/19 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
  Jump functions of caller  Gmac_Ip_EnableController/27:
  Jump functions of caller  Gmac_Ip_SetPowerState/26:
  Jump functions of caller  Gmac_Ip_GetPowerState/25:
  Jump functions of caller  Gmac_Ip_Deinit/24:
  Jump functions of caller  Gmac_Ip_EnableTimeGateScheduling/23:
    callsite  Gmac_Ip_EnableTimeGateScheduling/23 -> Gmac_Ip_ConfigTimeGateScheduling/9 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  Gmac_Ip_Init/22:
    callsite  Gmac_Ip_Init/22 -> Gmac_Ip_TxTimeAwareShaperInit.isra.0/100 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Gmac_Ip_Init/22 -> Gmac_Ip_InitStateStructure/12 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Gmac_Ip_Init/22 -> Gmac_Ip_InitMAC.isra.0/99 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Gmac_Ip_Init/22 -> Gmac_Ip_SetMacAddr/45 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Gmac_Ip_Init/22 -> Gmac_Ip_InitMTL/10 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Gmac_Ip_Init/22 -> Gmac_Ip_InitDMA/7 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  Gmac_Ip_GetPayloadType/20:
  Jump functions of caller  Gmac_Ip_CheckMTLEmpty/19:
  Jump functions of caller  Gmac_Ip_RestoreRxDescr/18:
  Jump functions of caller  Gmac_Ip_RestoreTxDescr/17:
  Jump functions of caller  Gmac_Ip_RestoreRxCtxtDescr/16:
  Jump functions of caller  Gmac_Ip_GetTimestamp/15:
  Jump functions of caller  Gmac_Ip_InitRxBD/14:
  Jump functions of caller  Gmac_Ip_InitTxBD/13:
  Jump functions of caller  Gmac_Ip_InitStateStructure/12:
  Jump functions of caller  Gmac_Ip_InitMTL/10:
  Jump functions of caller  Gmac_Ip_ConfigTimeGateScheduling/9:
    callsite  Gmac_Ip_ConfigTimeGateScheduling/9 -> Gmac_Ip_WriteGateControlList/8 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: CONST: 5
         value: 0x5, mask: 0x0
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffff
         VR  [0, 65535]
       param 3: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  Gmac_Ip_ConfigTimeGateScheduling/9 -> Gmac_Ip_WriteGateControlList/8 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: CONST: 4
         value: 0x4, mask: 0x0
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  Gmac_Ip_ConfigTimeGateScheduling/9 -> Gmac_Ip_WriteGateControlList/8 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: CONST: 2
         value: 0x2, mask: 0x0
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  Gmac_Ip_ConfigTimeGateScheduling/9 -> Gmac_Ip_WriteGateControlList/8 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: CONST: 3
         value: 0x3, mask: 0x0
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  Gmac_Ip_ConfigTimeGateScheduling/9 -> Gmac_Ip_WriteGateControlList/8 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0x3fffffff
         VR  [0, 999999999]
       param 3: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  Gmac_Ip_ConfigTimeGateScheduling/9 -> Gmac_Ip_WriteGateControlList/8 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0x7
         VR  [0, 4]
       param 3: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  Gmac_Ip_ConfigTimeGateScheduling/9 -> Gmac_Ip_WriteGateControlList/8 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
  Jump functions of caller  Gmac_Ip_WriteGateControlList/8:
  Jump functions of caller  Gmac_Ip_InitDMA/7:
    callsite  Gmac_Ip_InitDMA/7 -> Gmac_Ip_InitRxBD/14 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  Gmac_Ip_InitDMA/7 -> Gmac_Ip_InitTxBD/13 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  Gmac_Ip_ReadTimeStampInfo/6:
  Jump functions of caller  Gmac_Ip_ComputeCRC32/5:

 Propagating constants:

Not considering Gmac_Ip_SetTxThreshold for cloning; -fipa-cp-clone disabled.
Not considering Gmac_Ip_EnableTxStoreAndForward for cloning; -fipa-cp-clone disabled.
Not considering Gmac_Ip_SetTxRingWeight for cloning; -fipa-cp-clone disabled.
Not considering Gmac_Ip_SetTxSchedAlgo for cloning; -fipa-cp-clone disabled.
Not considering Gmac_Ip_GetSysTime for cloning; -fipa-cp-clone disabled.
Not considering Gmac_Ip_SetRateRatioCorr for cloning; -fipa-cp-clone disabled.
Not considering Gmac_Ip_SetSysTimeCorr for cloning; -fipa-cp-clone disabled.
Not considering Gmac_Ip_InitSysTime for cloning; -fipa-cp-clone disabled.
Not considering Gmac_Ip_RemoveVlanTagFromHashTable for cloning; -fipa-cp-clone disabled.
Not considering Gmac_Ip_AddVlanTagToHashTable for cloning; -fipa-cp-clone disabled.
Not considering Gmac_Ip_SetTxInnerVlanTag for cloning; -fipa-cp-clone disabled.
Not considering Gmac_Ip_SetTxOuterVlanTagForReplacement for cloning; -fipa-cp-clone disabled.
Not considering Gmac_Ip_SetTxOuterVlanTagForInsertion for cloning; -fipa-cp-clone disabled.
Not considering Gmac_Ip_EnableVlan for cloning; -fipa-cp-clone disabled.
Not considering Gmac_Ip_SetArpOffloading for cloning; -fipa-cp-clone disabled.
Not considering Gmac_Ip_SetAddrPerfectFilter for cloning; -fipa-cp-clone disabled.
Not considering Gmac_Ip_RemoveDstAddrFromHashFilter for cloning; -fipa-cp-clone disabled.
Not considering Gmac_Ip_AddDstAddrToHashFilter for cloning; -fipa-cp-clone disabled.
Not considering Gmac_Ip_SetHashOrPerfectFilter for cloning; -fipa-cp-clone disabled.
Not considering Gmac_Ip_SetMulticastHashFilter for cloning; -fipa-cp-clone disabled.
Not considering Gmac_Ip_SetUnicastHashFilter for cloning; -fipa-cp-clone disabled.
Not considering Gmac_Ip_SetMulticastForwardAll for cloning; -fipa-cp-clone disabled.
Not considering Gmac_Ip_SetBroadcastForwardAll for cloning; -fipa-cp-clone disabled.
Not considering Gmac_Ip_GetChInterruptFlags for cloning; -fipa-cp-clone disabled.
Not considering Gmac_Ip_GetInterruptFlags for cloning; -fipa-cp-clone disabled.
Not considering Gmac_Ip_GetMacAddr for cloning; -fipa-cp-clone disabled.
Not considering Gmac_Ip_SetMacAddr for cloning; -fipa-cp-clone disabled.
Not considering Gmac_Ip_MDIOWriteMMD for cloning; -fipa-cp-clone disabled.
Not considering Gmac_Ip_MDIOReadMMD for cloning; -fipa-cp-clone disabled.
Not considering Gmac_Ip_MDIOWrite for cloning; -fipa-cp-clone disabled.
Not considering Gmac_Ip_MDIORead for cloning; -fipa-cp-clone disabled.
Not considering Gmac_Ip_EnableMDIO for cloning; -fipa-cp-clone disabled.
Not considering Gmac_Ip_GetCounter for cloning; -fipa-cp-clone disabled.
Not considering Gmac_Ip_GetTransmitStatus for cloning; -fipa-cp-clone disabled.
Not considering Gmac_Ip_IsFrameAvailable for cloning; -fipa-cp-clone disabled.
Not considering Gmac_Ip_ProvideRxBuff for cloning; -fipa-cp-clone disabled.
Not considering Gmac_Ip_SetRxExternalBuffer for cloning; -fipa-cp-clone disabled.
Not considering Gmac_Ip_ReadFrame for cloning; -fipa-cp-clone disabled.
Not considering Gmac_Ip_SendMultiBufferFrame for cloning; -fipa-cp-clone disabled.
Not considering Gmac_Ip_SendFrame for cloning; -fipa-cp-clone disabled.
Not considering Gmac_Ip_GetTxMultiBuff for cloning; -fipa-cp-clone disabled.
Not considering Gmac_Ip_GetTxBuff for cloning; -fipa-cp-clone disabled.
Not considering Gmac_Ip_SetSpeed for cloning; -fipa-cp-clone disabled.
Not considering Gmac_Ip_DisableController for cloning; -fipa-cp-clone disabled.
Not considering Gmac_Ip_EnableController for cloning; -fipa-cp-clone disabled.
Not considering Gmac_Ip_SetPowerState for cloning; -fipa-cp-clone disabled.
Not considering Gmac_Ip_GetPowerState for cloning; -fipa-cp-clone disabled.
Not considering Gmac_Ip_Deinit for cloning; -fipa-cp-clone disabled.
Not considering Gmac_Ip_EnableTimeGateScheduling for cloning; -fipa-cp-clone disabled.
Not considering Gmac_Ip_Init for cloning; -fipa-cp-clone disabled.

overall_size: 1969, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: Gmac_Ip_TxTimeAwareShaperInit.isra.0/100:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: Gmac_Ip_InitMAC.isra.0/99:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: Gmac_Ip_SetTxThreshold/71:
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
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Gmac_Ip_EnableTxStoreAndForward/70:
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
  Node: Gmac_Ip_SetTxRingWeight/69:
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
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Gmac_Ip_SetTxSchedAlgo/68:
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
  Node: Gmac_Ip_GetSysTime/67:
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
  Node: Gmac_Ip_SetRateRatioCorr/66:
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
  Node: Gmac_Ip_SetSysTimeCorr/65:
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
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [3]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Gmac_Ip_InitSysTime/64:
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
  Node: Gmac_Ip_RemoveVlanTagFromHashTable/63:
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
  Node: Gmac_Ip_AddVlanTagToHashTable/62:
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
  Node: Gmac_Ip_SetTxInnerVlanTag/61:
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
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Gmac_Ip_SetTxOuterVlanTagForReplacement/60:
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
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Gmac_Ip_SetTxOuterVlanTagForInsertion/59:
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
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [3]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Gmac_Ip_EnableVlan/58:
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
  Node: Gmac_Ip_SetArpOffloading/57:
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
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Gmac_Ip_SetAddrPerfectFilter/56:
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
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [3]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [4]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Gmac_Ip_RemoveDstAddrFromHashFilter/55:
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
  Node: Gmac_Ip_AddDstAddrToHashFilter/54:
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
  Node: Gmac_Ip_SetHashOrPerfectFilter/53:
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
  Node: Gmac_Ip_SetMulticastHashFilter/52:
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
  Node: Gmac_Ip_SetUnicastHashFilter/51:
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
  Node: Gmac_Ip_SetMulticastForwardAll/50:
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
  Node: Gmac_Ip_SetBroadcastForwardAll/49:
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
  Node: Gmac_Ip_GetChInterruptFlags/48:
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
  Node: Gmac_Ip_GetInterruptFlags/47:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Gmac_Ip_GetMacAddr/46:
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
  Node: Gmac_Ip_SetMacAddr/45:
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
  Node: Gmac_Ip_MDIOWriteMMD/44:
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
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [3]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [4]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [5]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Gmac_Ip_MDIOReadMMD/43:
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
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [3]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [4]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [5]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Gmac_Ip_MDIOWrite/42:
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
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [3]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [4]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Gmac_Ip_MDIORead/41:
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
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [3]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [4]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Gmac_Ip_EnableMDIO/40:
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
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Gmac_Ip_GetCounter/39:
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
  Node: Gmac_Ip_GetTransmitStatus/38:
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
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [3]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Gmac_Ip_IsFrameAvailable/37:
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
  Node: Gmac_Ip_ProvideRxBuff/36:
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
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Gmac_Ip_SetRxExternalBuffer/35:
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
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Gmac_Ip_ReadFrame/34:
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
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [3]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Gmac_Ip_SendMultiBufferFrame/33:
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
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [3]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [4]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Gmac_Ip_SendFrame/32:
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
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [3]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Gmac_Ip_GetTxMultiBuff/31:
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
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [3]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [4]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Gmac_Ip_GetTxBuff/30:
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
    param [2]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
    param [3]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Gmac_Ip_SetSpeed/29:
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
  Node: Gmac_Ip_DisableController/28:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Gmac_Ip_EnableController/27:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Gmac_Ip_SetPowerState/26:
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
  Node: Gmac_Ip_GetPowerState/25:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Gmac_Ip_Deinit/24:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Gmac_Ip_EnableTimeGateScheduling/23:
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
  Node: Gmac_Ip_Init/22:
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
  Node: Gmac_Ip_GetPayloadType/20:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x7
         uint32 [0, 7]
        AGGS VARIABLE
  Node: Gmac_Ip_CheckMTLEmpty/19:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [2]: 1 [loc_time: 157, loc_size: 29, prop_time: 0, prop_size: 0]
               0 [loc_time: 157, loc_size: 29, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         boolean [0, 1]
        AGGS VARIABLE
  Node: Gmac_Ip_RestoreRxDescr/18:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: Gmac_Ip_RestoreTxDescr/17:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: Gmac_Ip_RestoreRxCtxtDescr/16:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: Gmac_Ip_GetTimestamp/15:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct Gmac_Ip_TimestampType * ~[0B, 0B]
        AGGS VARIABLE
  Node: Gmac_Ip_InitRxBD/14:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: Gmac_Ip_InitTxBD/13:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: Gmac_Ip_InitStateStructure/12:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: Gmac_Ip_InitMTL/10:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: Gmac_Ip_ConfigTimeGateScheduling/9:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: Gmac_Ip_WriteGateControlList/8:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
               1 [loc_time: 3, loc_size: 37, prop_time: 0, prop_size: 0]
               0 [loc_time: 3, loc_size: 37, prop_time: 0, prop_size: 0]
               3 [loc_time: 3, loc_size: 37, prop_time: 0, prop_size: 0]
               2 [loc_time: 3, loc_size: 37, prop_time: 0, prop_size: 0]
               4 [loc_time: 3, loc_size: 37, prop_time: 0, prop_size: 0]
               5 [loc_time: 3, loc_size: 37, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [3]: 1 [loc_time: 3, loc_size: 34, prop_time: 0, prop_size: 0]
               0 [loc_time: 3, loc_size: 34, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         boolean [0, 1]
        AGGS VARIABLE
  Node: Gmac_Ip_InitDMA/7:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: Gmac_Ip_ReadTimeStampInfo/6:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [2]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: Gmac_Ip_ComputeCRC32/5:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
    param [1]: 6 [loc_time: 65, loc_size: 19, prop_time: 0, prop_size: 0]
               2 [loc_time: 65, loc_size: 19, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x2, mask = 0x4
         uint8 [2, 6]
        AGGS VARIABLE

IPA decision stage:

Propagated bits info for function Gmac_Ip_GetPayloadType/20:
 param 0: value = 0x0, mask = 0x7
Propagated bits info for function Gmac_Ip_ComputeCRC32/5:
 param 1: value = 0x2, mask = 0x4

IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

Gmac_Ip_TxTimeAwareShaperInit.isra.0/100 (Gmac_Ip_TxTimeAwareShaperInit.isra.0) @0685e700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: Gmac_Ip_TxTimeAwareShaperData/2 (write)Gmac_Ip_TxTimeAwareShaperData/2 (write)Gmac_Ip_TxTimeAwareShaperData/2 (write)Gmac_Ip_TxTimeAwareShaperData/2 (write)Gmac_Ip_TxTimeAwareShaperData/2 (read)Gmac_Ip_TxTimeAwareShaperData/2 (write)Gmac_Ip_TxTimeAwareShaperData/2 (write)Gmac_Ip_TxTimeAwareShaperData/2 (write)Gmac_Ip_TxTimeAwareShaperData/2 (write)Gmac_Ip_TxTimeAwareShaperData/2 (write)
  Referring: 
  Availability: local
  Function flags: count:118111600 (estimated locally) body local optimize_size
  Called by: Gmac_Ip_Init/22 (354334802 (estimated locally),0.33 per call) 
  Calls: 
Gmac_Ip_InitMAC.isra.0/99 (Gmac_Ip_InitMAC.isra.0) @0666c380
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Gmac_Ip_Init/22 (354334802 (estimated locally),0.33 per call) 
  Calls: 
GMAC_SetTxThreshold/98 (GMAC_SetTxThreshold) @066cc540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Gmac_Ip_SetTxThreshold/71 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
GMAC_SetTxStoreAndForward/97 (GMAC_SetTxStoreAndForward) @066cc380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Gmac_Ip_EnableTxStoreAndForward/70 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
GMAC_SetSchedAlg/96 (GMAC_SetSchedAlg) @066cc0e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Gmac_Ip_SetTxSchedAlgo/68 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
GMAC_RemoveVlanFromHashTable/95 (GMAC_RemoveVlanFromHashTable) @066b2b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Gmac_Ip_RemoveVlanTagFromHashTable/63 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
GMAC_AddVlanToHashTable/94 (GMAC_AddVlanToHashTable) @066b29a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Gmac_Ip_AddVlanTagToHashTable/62 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
GMAC_RemoveFromHashTable/93 (GMAC_RemoveFromHashTable) @066b22a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Gmac_Ip_RemoveDstAddrFromHashFilter/55 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
GMAC_AddToHashTable/92 (GMAC_AddToHashTable) @066b2000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Gmac_Ip_AddDstAddrToHashFilter/54 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
GMAC_WriteManagementFrame/91 (GMAC_WriteManagementFrame) @0669c2a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Gmac_Ip_MDIOWriteMMD/44 (1073741824 (estimated locally),1.00 per call) Gmac_Ip_MDIOReadMMD/43 (1073741824 (estimated locally),1.00 per call) Gmac_Ip_MDIOWrite/42 (1073741824 (estimated locally),1.00 per call) Gmac_Ip_MDIORead/41 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
CsrValues.7196/90 (CsrValues) @06697d80
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Gmac_Ip_EnableMDIO/40 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known
Freq.7195/89 (Freq) @06697d38
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Gmac_Ip_EnableMDIO/40 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known
Gmac_aRxExternalBuffLength/88 (Gmac_aRxExternalBuffLength) @06687678
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Gmac_Ip_SetRxExternalBuffer/35 (read)
  Availability: not_available
  Varpool flags: read-only
Cache_Ip_InvalidateByAddr/87 (Cache_Ip_InvalidateByAddr) @0666c700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Gmac_Ip_ReadFrame/34 (242616785 (estimated locally),0.23 per call) 
  Calls: 
Cache_Ip_CleanByAddr/86 (Cache_Ip_CleanByAddr) @0666c2a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Gmac_Ip_SendMultiBufferFrame/33 (344993248 (estimated locally),3.00 per call) Gmac_Ip_SendFrame/32 (781361926 (estimated locally),0.73 per call) 
  Calls: 
GMAC_SetSpeed/85 (GMAC_SetSpeed) @06641700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Gmac_Ip_SetSpeed/29 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
GMAC_SetPowerState/84 (GMAC_SetPowerState) @06641b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Gmac_Ip_SetPowerState/26 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
GMAC_GetPowerState/83 (GMAC_GetPowerState) @066419a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Gmac_Ip_GetPowerState/25 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
GMAC_EnableRxQueue/82 (GMAC_EnableRxQueue) @06615ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Gmac_Ip_InitMTL/10 (955630225 (estimated locally),8.09 per call) 
  Calls: 
GMAC_SetRxQueueOperationMode/81 (GMAC_SetRxQueueOperationMode) @06615e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Gmac_Ip_InitMTL/10 (955630225 (estimated locally),8.09 per call) 
  Calls: 
GMAC_SetRxQueuesDmaChMap/80 (GMAC_SetRxQueuesDmaChMap) @06615d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Gmac_Ip_InitMTL/10 (118111600 (estimated locally),1.00 per call) 
  Calls: 
GMAC_SetTxQueueOperationMode/79 (GMAC_SetTxQueueOperationMode) @06615b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Gmac_Ip_InitMTL/10 (955630218 (estimated locally),8.09 per call) 
  Calls: 
GMAC_SetTxQueueCreditBasedShaper/78 (GMAC_SetTxQueueCreditBasedShaper) @066152a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Gmac_Ip_InitMTL/10 (95191434 (estimated locally),0.81 per call) 
  Calls: 
GMAC_SetTxQueueQuantumWeight/77 (GMAC_SetTxQueueQuantumWeight) @06615000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Gmac_Ip_SetTxRingWeight/69 (445388109 (estimated locally),0.41 per call) Gmac_Ip_InitMTL/10 (95191434 (estimated locally),0.81 per call) Gmac_Ip_InitMTL/10 (107221710 (estimated locally),0.91 per call) 
  Calls: 
Gmac_apxQueueBases/76 (Gmac_apxQueueBases) @066327e0
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Gmac_Ip_DisableController/28 (read)Gmac_Ip_SetTxRingWeight/69 (read)Gmac_Ip_InitMTL/10 (read)Gmac_Ip_InitMTL/10 (read)Gmac_Ip_EnableTxStoreAndForward/70 (read)Gmac_Ip_CheckMTLEmpty/19 (read)Gmac_Ip_CheckMTLEmpty/19 (read)Gmac_Ip_InitMTL/10 (read)Gmac_Ip_InitMTL/10 (read)Gmac_Ip_SetTxThreshold/71 (read)
  Availability: not_available
  Varpool flags: read-only
Gmac_apxChBases/75 (Gmac_apxChBases) @0661ab88
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Gmac_Ip_EnableController/27 (read)Gmac_Ip_DisableController/28 (read)Gmac_Ip_GetTxBuff/30 (read)Gmac_Ip_GetTxMultiBuff/31 (read)Gmac_Ip_SendFrame/32 (read)Gmac_Ip_ProvideRxBuff/36 (read)Gmac_Ip_SendMultiBufferFrame/33 (read)Gmac_Ip_ReadFrame/34 (read)Gmac_Ip_SetRxExternalBuffer/35 (read)Gmac_Ip_GetTransmitStatus/38 (read)Gmac_Ip_InitRxBD/14 (read)Gmac_Ip_RestoreRxDescr/18 (read)Gmac_Ip_ReadTimeStampInfo/6 (read)Gmac_Ip_InitTxBD/13 (read)Gmac_Ip_RestoreTxDescr/17 (read)Gmac_Ip_EnableController/27 (read)Gmac_Ip_DisableController/28 (read)Gmac_Ip_GetChInterruptFlags/48 (read)
  Availability: not_available
  Varpool flags: read-only
GMAC_TimeoutExpired/74 (GMAC_TimeoutExpired) @06615a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Gmac_Ip_SetRateRatioCorr/66 (1014686025 (estimated locally),8.83 per call) Gmac_Ip_SetSysTimeCorr/65 (1014686025 (estimated locally),8.83 per call) Gmac_Ip_InitSysTime/64 (1014686025 (estimated locally),8.83 per call) Gmac_Ip_SetTxOuterVlanTagForInsertion/59 (1014686024 (estimated locally),2.45 per call) Gmac_Ip_EnableTimeGateScheduling/23 (1073741824 (estimated locally),1.54 per call) Gmac_Ip_CheckMTLEmpty/19 (1073741824 (estimated locally),78.04 per call) Gmac_Ip_WriteGateControlList/8 (1014686025 (estimated locally),8.83 per call) Gmac_Ip_InitDMA/7 (1014686025 (estimated locally),8.83 per call) 
  Calls: 
GMAC_StartTimeOut/73 (GMAC_StartTimeOut) @066159a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Gmac_Ip_SetRateRatioCorr/66 (114863532 (estimated locally),1.00 per call) Gmac_Ip_SetSysTimeCorr/65 (114863532 (estimated locally),1.00 per call) Gmac_Ip_InitSysTime/64 (114863532 (estimated locally),1.00 per call) Gmac_Ip_SetTxOuterVlanTagForInsertion/59 (114863532 (estimated locally),0.28 per call) Gmac_Ip_EnableTimeGateScheduling/23 (114863532 (estimated locally),0.16 per call) Gmac_Ip_CheckMTLEmpty/19 (114863532 (estimated locally),8.35 per call) Gmac_Ip_WriteGateControlList/8 (114863532 (estimated locally),1.00 per call) Gmac_Ip_InitDMA/7 (114863532 (estimated locally),1.00 per call) 
  Calls: 
Gmac_apxBases/72 (Gmac_apxBases) @06606cf0
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: Gmac_Ip_MDIOWriteMMD/44 (read)Gmac_Ip_GetSysTime/67 (read)Gmac_Ip_SetMulticastHashFilter/52 (read)Gmac_Ip_SetHashOrPerfectFilter/53 (read)Gmac_Ip_AddDstAddrToHashFilter/54 (read)Gmac_Ip_RemoveDstAddrFromHashFilter/55 (read)Gmac_Ip_WriteGateControlList/8 (read)Gmac_Ip_SetMulticastForwardAll/50 (read)Gmac_Ip_SetUnicastHashFilter/51 (read)Gmac_Ip_GetMacAddr/46 (read)Gmac_Ip_GetInterruptFlags/47 (read)Gmac_Ip_SetBroadcastForwardAll/49 (read)Gmac_Ip_ConfigTimeGateScheduling/9 (read)Gmac_Ip_ConfigTimeGateScheduling/9 (read)Gmac_Ip_EnableMDIO/40 (read)Gmac_Ip_MDIORead/41 (read)Gmac_Ip_MDIOWrite/42 (read)Gmac_Ip_MDIOReadMMD/43 (read)Gmac_Ip_SetMacAddr/45 (read)Gmac_Ip_GetTransmitStatus/38 (read)Gmac_Ip_InitDMA/7 (read)Gmac_Ip_SetAddrPerfectFilter/56 (read)Gmac_Ip_SetArpOffloading/57 (read)Gmac_Ip_EnableVlan/58 (read)Gmac_Ip_SetTxOuterVlanTagForInsertion/59 (read)Gmac_Ip_SetTxOuterVlanTagForReplacement/60 (read)Gmac_Ip_SetTxInnerVlanTag/61 (read)Gmac_Ip_AddVlanTagToHashTable/62 (read)Gmac_Ip_RemoveVlanTagFromHashTable/63 (read)Gmac_Ip_InitSysTime/64 (read)Gmac_Ip_SetSysTimeCorr/65 (read)Gmac_Ip_ReadTimeStampInfo/6 (read)Gmac_Ip_InitMTL/10 (read)Gmac_Ip_EnableTimeGateScheduling/23 (read)Gmac_Ip_Deinit/24 (read)Gmac_Ip_Init/22 (read)Gmac_Ip_GetPowerState/25 (read)Gmac_Ip_GetCounter/39 (read)Gmac_Ip_SetPowerState/26 (read)Gmac_Ip_EnableController/27 (read)Gmac_Ip_SetRateRatioCorr/66 (read)Gmac_Ip_DisableController/28 (read)Gmac_Ip_SetSpeed/29 (read)Gmac_Ip_SetTxSchedAlgo/68 (read)
  Availability: not_available
  Varpool flags: read-only
Gmac_Ip_SetTxThreshold/71 (Gmac_Ip_SetTxThreshold) @06615460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gmac_apxQueueBases/76 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: GMAC_SetTxThreshold/98 (1073741824 (estimated locally),1.00 per call) 
Gmac_Ip_EnableTxStoreAndForward/70 (Gmac_Ip_EnableTxStoreAndForward) @066151c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gmac_apxQueueBases/76 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: GMAC_SetTxStoreAndForward/97 (1073741824 (estimated locally),1.00 per call) 
Gmac_Ip_SetTxRingWeight/69 (Gmac_Ip_SetTxRingWeight) @0660bd20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gmac_apxState/1 (read)Gmac_apxQueueBases/76 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: GMAC_SetTxQueueQuantumWeight/77 (445388109 (estimated locally),0.41 per call) 
Gmac_Ip_SetTxSchedAlgo/68 (Gmac_Ip_SetTxSchedAlgo) @0660b540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gmac_apxBases/72 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: GMAC_SetSchedAlg/96 (1073741824 (estimated locally),1.00 per call) 
Gmac_Ip_GetSysTime/67 (Gmac_Ip_GetSysTime) @0660bee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gmac_apxBases/72 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Gmac_Ip_SetRateRatioCorr/66 (Gmac_Ip_SetRateRatioCorr) @0660bc40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gmac_apxBases/72 (read)
  Referring: 
  Availability: available
  Function flags: count:114863532 (estimated locally) body optimize_size
  Called by: 
  Calls: GMAC_TimeoutExpired/74 (1014686025 (estimated locally),8.83 per call) GMAC_StartTimeOut/73 (114863532 (estimated locally),1.00 per call) 
Gmac_Ip_SetSysTimeCorr/65 (Gmac_Ip_SetSysTimeCorr) @0660b9a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gmac_apxBases/72 (read)
  Referring: 
  Availability: available
  Function flags: count:114863532 (estimated locally) body optimize_size
  Called by: 
  Calls: GMAC_TimeoutExpired/74 (1014686025 (estimated locally),8.83 per call) GMAC_StartTimeOut/73 (114863532 (estimated locally),1.00 per call) 
Gmac_Ip_InitSysTime/64 (Gmac_Ip_InitSysTime) @0660b460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gmac_apxBases/72 (read)
  Referring: 
  Availability: available
  Function flags: count:114863532 (estimated locally) body optimize_size
  Called by: 
  Calls: GMAC_TimeoutExpired/74 (1014686025 (estimated locally),8.83 per call) GMAC_StartTimeOut/73 (114863532 (estimated locally),1.00 per call) 
Gmac_Ip_RemoveVlanTagFromHashTable/63 (Gmac_Ip_RemoveVlanTagFromHashTable) @0660b000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gmac_apxBases/72 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: GMAC_RemoveVlanFromHashTable/95 (1073741824 (estimated locally),1.00 per call) Gmac_Ip_ComputeCRC32/5 (1073741824 (estimated locally),1.00 per call) 
Gmac_Ip_AddVlanTagToHashTable/62 (Gmac_Ip_AddVlanTagToHashTable) @06603a80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gmac_apxBases/72 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: GMAC_AddVlanToHashTable/94 (1073741824 (estimated locally),1.00 per call) Gmac_Ip_ComputeCRC32/5 (1073741824 (estimated locally),1.00 per call) 
Gmac_Ip_SetTxInnerVlanTag/61 (Gmac_Ip_SetTxInnerVlanTag) @06603ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gmac_apxBases/72 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Gmac_Ip_SetTxOuterVlanTagForReplacement/60 (Gmac_Ip_SetTxOuterVlanTagForReplacement) @06603c40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gmac_apxBases/72 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Gmac_Ip_SetTxOuterVlanTagForInsertion/59 (Gmac_Ip_SetTxOuterVlanTagForInsertion) @066039a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gmac_apxBases/72 (read)
  Referring: 
  Availability: available
  Function flags: count:413413328 (estimated locally) body optimize_size
  Called by: 
  Calls: GMAC_TimeoutExpired/74 (1014686024 (estimated locally),2.45 per call) GMAC_StartTimeOut/73 (114863532 (estimated locally),0.28 per call) 
Gmac_Ip_EnableVlan/58 (Gmac_Ip_EnableVlan) @06603620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gmac_apxBases/72 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Gmac_Ip_SetArpOffloading/57 (Gmac_Ip_SetArpOffloading) @065f9620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gmac_apxBases/72 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Gmac_Ip_SetAddrPerfectFilter/56 (Gmac_Ip_SetAddrPerfectFilter) @065f90e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gmac_apxBases/72 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Gmac_Ip_RemoveDstAddrFromHashFilter/55 (Gmac_Ip_RemoveDstAddrFromHashFilter) @065f9a80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gmac_apxBases/72 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: GMAC_RemoveFromHashTable/93 (1073741824 (estimated locally),1.00 per call) Gmac_Ip_ComputeCRC32/5 (1073741824 (estimated locally),1.00 per call) 
Gmac_Ip_AddDstAddrToHashFilter/54 (Gmac_Ip_AddDstAddrToHashFilter) @065f97e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gmac_apxBases/72 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: GMAC_AddToHashTable/92 (1073741824 (estimated locally),1.00 per call) Gmac_Ip_ComputeCRC32/5 (1073741824 (estimated locally),1.00 per call) 
Gmac_Ip_SetHashOrPerfectFilter/53 (Gmac_Ip_SetHashOrPerfectFilter) @065f9540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gmac_apxBases/72 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Gmac_Ip_SetMulticastHashFilter/52 (Gmac_Ip_SetMulticastHashFilter) @065f92a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gmac_apxBases/72 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Gmac_Ip_SetUnicastHashFilter/51 (Gmac_Ip_SetUnicastHashFilter) @065f9000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gmac_apxBases/72 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Gmac_Ip_SetMulticastForwardAll/50 (Gmac_Ip_SetMulticastForwardAll) @065eeb60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gmac_apxBases/72 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Gmac_Ip_SetBroadcastForwardAll/49 (Gmac_Ip_SetBroadcastForwardAll) @065ee620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gmac_apxBases/72 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Gmac_Ip_GetChInterruptFlags/48 (Gmac_Ip_GetChInterruptFlags) @065ee0e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gmac_apxChBases/75 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Gmac_Ip_GetInterruptFlags/47 (Gmac_Ip_GetInterruptFlags) @065eed20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gmac_apxBases/72 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Gmac_Ip_GetMacAddr/46 (Gmac_Ip_GetMacAddr) @065eea80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gmac_apxBases/72 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Gmac_Ip_SetMacAddr/45 (Gmac_Ip_SetMacAddr) @065ee7e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gmac_apxBases/72 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: Gmac_Ip_Init/22 (354334802 (estimated locally),0.33 per call) 
  Calls: 
Gmac_Ip_MDIOWriteMMD/44 (Gmac_Ip_MDIOWriteMMD) @065ee540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gmac_apxBases/72 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: GMAC_WriteManagementFrame/91 (1073741824 (estimated locally),1.00 per call) 
Gmac_Ip_MDIOReadMMD/43 (Gmac_Ip_MDIOReadMMD) @065ee2a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gmac_apxBases/72 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: GMAC_WriteManagementFrame/91 (1073741824 (estimated locally),1.00 per call) 
Gmac_Ip_MDIOWrite/42 (Gmac_Ip_MDIOWrite) @065ee000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gmac_apxBases/72 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: GMAC_WriteManagementFrame/91 (1073741824 (estimated locally),1.00 per call) 
Gmac_Ip_MDIORead/41 (Gmac_Ip_MDIORead) @065de8c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gmac_apxBases/72 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: GMAC_WriteManagementFrame/91 (1073741824 (estimated locally),1.00 per call) 
Gmac_Ip_EnableMDIO/40 (Gmac_Ip_EnableMDIO) @065de380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gmac_apxBases/72 (read)Freq.7195/89 (read)CsrValues.7196/90 (read)
  Referring: 
  Availability: available
  Function flags: count:160524402 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Gmac_Ip_GetCounter/39 (Gmac_Ip_GetCounter) @065dea80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gmac_apxBases/72 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Gmac_Ip_GetTransmitStatus/38 (Gmac_Ip_GetTransmitStatus) @065de7e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gmac_apxBases/72 (read)Gmac_apxChBases/75 (read)
  Referring: 
  Availability: available
  Function flags: count:114863532 (estimated locally) body optimize_size
  Called by: 
  Calls: Gmac_Ip_GetTimestamp/15 (14114656 (estimated locally),0.12 per call) 
Gmac_Ip_IsFrameAvailable/37 (Gmac_Ip_IsFrameAvailable) @065de540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gmac_apxState/1 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Gmac_Ip_ProvideRxBuff/36 (Gmac_Ip_ProvideRxBuff) @065de2a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gmac_apxChBases/75 (read)Gmac_apxState/1 (read)Gmac_apxState/1 (read)Gmac_apxState/1 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Gmac_Ip_RestoreRxCtxtDescr/16 (268435456 (estimated locally),0.25 per call) 
Gmac_Ip_SetRxExternalBuffer/35 (Gmac_Ip_SetRxExternalBuffer) @065de000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gmac_apxChBases/75 (read)Gmac_apxState/1 (read)Gmac_aRxExternalBuffLength/88 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Gmac_Ip_ReadFrame/34 (Gmac_Ip_ReadFrame) @065c68c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gmac_apxChBases/75 (read)Gmac_apxState/1 (read)Gmac_apxState/1 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Gmac_Ip_ReadTimeStampInfo/6 (132944293 (estimated locally),0.12 per call) Gmac_Ip_GetPayloadType/20 (66472147 (estimated locally),0.06 per call) Cache_Ip_InvalidateByAddr/87 (242616785 (estimated locally),0.23 per call) 
Gmac_Ip_SendMultiBufferFrame/33 (Gmac_Ip_SendMultiBufferFrame) @065c6380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gmac_apxChBases/75 (read)
  Referring: 
  Availability: available
  Function flags: count:114863532 (estimated locally) body optimize_size
  Called by: 
  Calls: Cache_Ip_CleanByAddr/86 (344993248 (estimated locally),3.00 per call) 
Gmac_Ip_SendFrame/32 (Gmac_Ip_SendFrame) @065c6c40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gmac_apxChBases/75 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Cache_Ip_CleanByAddr/86 (781361926 (estimated locally),0.73 per call) 
Gmac_Ip_GetTxMultiBuff/31 (Gmac_Ip_GetTxMultiBuff) @065c67e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gmac_apxChBases/75 (read)Gmac_apxState/1 (read)
  Referring: 
  Availability: available
  Function flags: count:77159559 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Gmac_Ip_GetTxBuff/30 (Gmac_Ip_GetTxBuff) @065c6540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gmac_apxChBases/75 (read)Gmac_apxState/1 (read)Gmac_Ip_InstHasExternalTxBufferManagement/3 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Gmac_Ip_SetSpeed/29 (Gmac_Ip_SetSpeed) @065c62a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gmac_apxBases/72 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: GMAC_SetSpeed/85 (1073741824 (estimated locally),1.00 per call) 
Gmac_Ip_DisableController/28 (Gmac_Ip_DisableController) @065c6000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gmac_apxChBases/75 (read)Gmac_apxQueueBases/76 (read)Gmac_apxState/1 (read)Gmac_apxBases/72 (read)Gmac_apxChBases/75 (read)Gmac_apxState/1 (read)
  Referring: 
  Availability: available
  Function flags: count:357878150 (estimated locally) body optimize_size
  Called by: 
  Calls: Gmac_Ip_RestoreRxDescr/18 (59049895 (estimated locally),0.17 per call) Gmac_Ip_RestoreTxDescr/17 (59049895 (estimated locally),0.17 per call) Gmac_Ip_CheckMTLEmpty/19 (178939075 (estimated locally),0.50 per call) Gmac_Ip_CheckMTLEmpty/19 (357878150 (estimated locally),1.00 per call) 
Gmac_Ip_EnableController/27 (Gmac_Ip_EnableController) @06519c40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gmac_apxChBases/75 (read)Gmac_apxState/1 (read)Gmac_apxChBases/75 (read)Gmac_apxBases/72 (read)
  Referring: 
  Availability: available
  Function flags: count:357878150 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Gmac_Ip_SetPowerState/26 (Gmac_Ip_SetPowerState) @06519380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gmac_apxBases/72 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: GMAC_SetPowerState/84 (1073741824 (estimated locally),1.00 per call) 
Gmac_Ip_GetPowerState/25 (Gmac_Ip_GetPowerState) @06519e00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gmac_apxBases/72 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: GMAC_GetPowerState/83 (1073741824 (estimated locally),1.00 per call) 
Gmac_Ip_Deinit/24 (Gmac_Ip_Deinit) @06519b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gmac_apxBases/72 (read)Gmac_apxState/1 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Gmac_Ip_EnableTimeGateScheduling/23 (Gmac_Ip_EnableTimeGateScheduling) @065198c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gmac_apxBases/72 (read)
  Referring: 
  Availability: available
  Function flags: count:696142619 (estimated locally) body optimize_size
  Called by: 
  Calls: GMAC_TimeoutExpired/74 (1073741824 (estimated locally),1.54 per call) GMAC_StartTimeOut/73 (114863532 (estimated locally),0.16 per call) Gmac_Ip_ConfigTimeGateScheduling/9 (114863532 (estimated locally),0.16 per call) 
Gmac_Ip_Init/22 (Gmac_Ip_Init) @065192a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gmac_apxBases/72 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: Gmac_Ip_TxTimeAwareShaperInit.isra.0/100 (354334802 (estimated locally),0.33 per call) Gmac_Ip_InitStateStructure/12 (354334802 (estimated locally),0.33 per call) Gmac_Ip_InitMAC.isra.0/99 (354334802 (estimated locally),0.33 per call) Gmac_Ip_SetMacAddr/45 (354334802 (estimated locally),0.33 per call) Gmac_Ip_InitMTL/10 (354334802 (estimated locally),0.33 per call) Gmac_Ip_InitDMA/7 (1073741824 (estimated locally),1.00 per call) 
Gmac_Ip_GetPayloadType/20 (Gmac_Ip_GetPayloadType) @06507a80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Gmac_Ip_ReadFrame/34 (66472147 (estimated locally),0.06 per call) 
  Calls: 
Gmac_Ip_CheckMTLEmpty/19 (Gmac_Ip_CheckMTLEmpty) @06507540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Gmac_apxQueueBases/76 (read)Gmac_apxQueueBases/76 (read)
  Referring: 
  Availability: local
  Function flags: count:13759443 (estimated locally) body local optimize_size
  Called by: Gmac_Ip_DisableController/28 (178939075 (estimated locally),0.50 per call) Gmac_Ip_DisableController/28 (357878150 (estimated locally),1.00 per call) 
  Calls: GMAC_TimeoutExpired/74 (1073741824 (estimated locally),78.04 per call) GMAC_StartTimeOut/73 (114863532 (estimated locally),8.35 per call) 
Gmac_Ip_RestoreRxDescr/18 (Gmac_Ip_RestoreRxDescr) @06507ee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Gmac_apxChBases/75 (read)Gmac_apxState/1 (read)
  Referring: 
  Availability: local
  Function flags: count:59046942 (estimated locally) body local optimize_size
  Called by: Gmac_Ip_DisableController/28 (59049895 (estimated locally),0.17 per call) 
  Calls: 
Gmac_Ip_RestoreTxDescr/17 (Gmac_Ip_RestoreTxDescr) @06507c40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Gmac_apxChBases/75 (read)Gmac_apxState/1 (read)
  Referring: 
  Availability: local
  Function flags: count:59046942 (estimated locally) body local optimize_size
  Called by: Gmac_Ip_DisableController/28 (59049895 (estimated locally),0.17 per call) 
  Calls: 
Gmac_Ip_RestoreRxCtxtDescr/16 (Gmac_Ip_RestoreRxCtxtDescr) @065079a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Gmac_Ip_ProvideRxBuff/36 (268435456 (estimated locally),0.25 per call) 
  Calls: 
Gmac_Ip_GetTimestamp/15 (Gmac_Ip_GetTimestamp) @06507700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Gmac_Ip_GetTransmitStatus/38 (14114656 (estimated locally),0.12 per call) 
  Calls: 
Gmac_Ip_InitRxBD/14 (Gmac_Ip_InitRxBD) @06507460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Gmac_apxChBases/75 (read)
  Referring: 
  Availability: local
  Function flags: count:14598062 (estimated locally) body local optimize_size
  Called by: Gmac_Ip_InitDMA/7 (37904965 (estimated locally),0.33 per call) 
  Calls: 
Gmac_Ip_InitTxBD/13 (Gmac_Ip_InitTxBD) @064efc40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Gmac_apxChBases/75 (read)
  Referring: 
  Availability: local
  Function flags: count:14598062 (estimated locally) body local optimize_size
  Called by: Gmac_Ip_InitDMA/7 (37904965 (estimated locally),0.33 per call) 
  Calls: 
Gmac_Ip_InitStateStructure/12 (Gmac_Ip_InitStateStructure) @064efb60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Gmac_apxState/1 (write)
  Referring: 
  Availability: local
  Function flags: count:357878150 (estimated locally) body local optimize_size
  Called by: Gmac_Ip_Init/22 (354334802 (estimated locally),0.33 per call) 
  Calls: 
Gmac_Ip_InitMTL/10 (Gmac_Ip_InitMTL) @064ef540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Gmac_apxBases/72 (read)Gmac_apxQueueBases/76 (read)Gmac_apxQueueBases/76 (read)Gmac_apxQueueBases/76 (read)Gmac_apxQueueBases/76 (read)
  Referring: 
  Availability: local
  Function flags: count:118111601 (estimated locally) body local optimize_size
  Called by: Gmac_Ip_Init/22 (354334802 (estimated locally),0.33 per call) 
  Calls: GMAC_EnableRxQueue/82 (955630225 (estimated locally),8.09 per call) GMAC_SetRxQueueOperationMode/81 (955630225 (estimated locally),8.09 per call) GMAC_SetRxQueuesDmaChMap/80 (118111600 (estimated locally),1.00 per call) GMAC_SetTxQueueOperationMode/79 (955630218 (estimated locally),8.09 per call) GMAC_SetTxQueueCreditBasedShaper/78 (95191434 (estimated locally),0.81 per call) GMAC_SetTxQueueQuantumWeight/77 (95191434 (estimated locally),0.81 per call) GMAC_SetTxQueueQuantumWeight/77 (107221710 (estimated locally),0.91 per call) 
Gmac_Ip_ConfigTimeGateScheduling/9 (Gmac_Ip_ConfigTimeGateScheduling) @064ef2a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Gmac_Ip_TxTimeAwareShaperData/2 (read)Gmac_apxBases/72 (read)Gmac_Ip_TxTimeAwareShaperData/2 (read)Gmac_Ip_TxTimeAwareShaperData/2 (read)Gmac_Ip_TxTimeAwareShaperData/2 (read)Gmac_Ip_TxTimeAwareShaperData/2 (read)Gmac_apxBases/72 (read)Gmac_Ip_TxTimeAwareShaperData/2 (read)Gmac_Ip_TxTimeAwareShaperData/2 (read)Gmac_Ip_TxTimeAwareShaperData/2 (read)Gmac_Ip_TxTimeAwareShaperData/2 (read)Gmac_Ip_TxTimeAwareShaperData/2 (read)Gmac_Ip_TxTimeAwareShaperData/2 (read)Gmac_Ip_TxTimeAwareShaperData/2 (read)Gmac_Ip_TxTimeAwareShaperData/2 (read)
  Referring: 
  Availability: local
  Function flags: count:118111600 (estimated locally) body local optimize_size
  Called by: Gmac_Ip_EnableTimeGateScheduling/23 (114863532 (estimated locally),0.16 per call) 
  Calls: Gmac_Ip_WriteGateControlList/8 (118111601 (estimated locally),1.00 per call) Gmac_Ip_WriteGateControlList/8 (118111601 (estimated locally),1.00 per call) Gmac_Ip_WriteGateControlList/8 (118111601 (estimated locally),1.00 per call) Gmac_Ip_WriteGateControlList/8 (118111601 (estimated locally),1.00 per call) Gmac_Ip_WriteGateControlList/8 (118111601 (estimated locally),1.00 per call) Gmac_Ip_WriteGateControlList/8 (118111601 (estimated locally),1.00 per call) Gmac_Ip_WriteGateControlList/8 (955630223 (estimated locally),8.09 per call) 
Gmac_Ip_WriteGateControlList/8 (Gmac_Ip_WriteGateControlList) @064e0540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Gmac_apxBases/72 (read)
  Referring: 
  Availability: local
  Function flags: count:114863532 (estimated locally) body local optimize_size
  Called by: Gmac_Ip_ConfigTimeGateScheduling/9 (118111601 (estimated locally),1.00 per call) Gmac_Ip_ConfigTimeGateScheduling/9 (118111601 (estimated locally),1.00 per call) Gmac_Ip_ConfigTimeGateScheduling/9 (118111601 (estimated locally),1.00 per call) Gmac_Ip_ConfigTimeGateScheduling/9 (118111601 (estimated locally),1.00 per call) Gmac_Ip_ConfigTimeGateScheduling/9 (118111601 (estimated locally),1.00 per call) Gmac_Ip_ConfigTimeGateScheduling/9 (118111601 (estimated locally),1.00 per call) Gmac_Ip_ConfigTimeGateScheduling/9 (955630223 (estimated locally),8.09 per call) 
  Calls: GMAC_TimeoutExpired/74 (1014686025 (estimated locally),8.83 per call) GMAC_StartTimeOut/73 (114863532 (estimated locally),1.00 per call) 
Gmac_Ip_InitDMA/7 (Gmac_Ip_InitDMA) @064e0b60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Gmac_apxBases/72 (read)
  Referring: 
  Availability: local
  Function flags: count:114863532 (estimated locally) body local optimize_size
  Called by: Gmac_Ip_Init/22 (1073741824 (estimated locally),1.00 per call) 
  Calls: Gmac_Ip_InitRxBD/14 (37904965 (estimated locally),0.33 per call) Gmac_Ip_InitTxBD/13 (37904965 (estimated locally),0.33 per call) GMAC_TimeoutExpired/74 (1014686025 (estimated locally),8.83 per call) GMAC_StartTimeOut/73 (114863532 (estimated locally),1.00 per call) 
Gmac_Ip_ReadTimeStampInfo/6 (Gmac_Ip_ReadTimeStampInfo) @064e0700
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Gmac_apxBases/72 (read)Gmac_apxChBases/75 (read)Gmac_apxState/1 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: Gmac_Ip_ReadFrame/34 (132944293 (estimated locally),0.12 per call) 
  Calls: 
Gmac_Ip_ComputeCRC32/5 (Gmac_Ip_ComputeCRC32) @064e0460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:14744043 (estimated locally) body local optimize_size
  Called by: Gmac_Ip_RemoveVlanTagFromHashTable/63 (1073741824 (estimated locally),1.00 per call) Gmac_Ip_AddVlanTagToHashTable/62 (1073741824 (estimated locally),1.00 per call) Gmac_Ip_RemoveDstAddrFromHashFilter/55 (1073741824 (estimated locally),1.00 per call) Gmac_Ip_AddDstAddrToHashFilter/54 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Gmac_Ip_InstHasExternalTxBufferManagement/3 (Gmac_Ip_InstHasExternalTxBufferManagement) @06525438
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Gmac_Ip_GetTxBuff/30 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known
Gmac_Ip_TxTimeAwareShaperData/2 (Gmac_Ip_TxTimeAwareShaperData) @065253a8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Gmac_Ip_ConfigTimeGateScheduling/9 (read)Gmac_Ip_ConfigTimeGateScheduling/9 (read)Gmac_Ip_TxTimeAwareShaperInit.isra.0/100 (write)Gmac_Ip_TxTimeAwareShaperInit.isra.0/100 (write)Gmac_Ip_TxTimeAwareShaperInit.isra.0/100 (write)Gmac_Ip_TxTimeAwareShaperInit.isra.0/100 (write)Gmac_Ip_TxTimeAwareShaperInit.isra.0/100 (read)Gmac_Ip_TxTimeAwareShaperInit.isra.0/100 (write)Gmac_Ip_TxTimeAwareShaperInit.isra.0/100 (write)Gmac_Ip_TxTimeAwareShaperInit.isra.0/100 (write)Gmac_Ip_TxTimeAwareShaperInit.isra.0/100 (write)Gmac_Ip_TxTimeAwareShaperInit.isra.0/100 (write)Gmac_Ip_ConfigTimeGateScheduling/9 (read)Gmac_Ip_ConfigTimeGateScheduling/9 (read)Gmac_Ip_ConfigTimeGateScheduling/9 (read)Gmac_Ip_ConfigTimeGateScheduling/9 (read)Gmac_Ip_ConfigTimeGateScheduling/9 (read)Gmac_Ip_ConfigTimeGateScheduling/9 (read)Gmac_Ip_ConfigTimeGateScheduling/9 (read)Gmac_Ip_ConfigTimeGateScheduling/9 (read)Gmac_Ip_ConfigTimeGateScheduling/9 (read)Gmac_Ip_ConfigTimeGateScheduling/9 (read)Gmac_Ip_ConfigTimeGateScheduling/9 (read)
  Availability: available
  Varpool flags:
Gmac_apxState/1 (Gmac_apxState) @06525318
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: Gmac_Ip_IsFrameAvailable/37 (read)Gmac_Ip_RestoreTxDescr/17 (read)Gmac_Ip_ReadFrame/34 (read)Gmac_Ip_RestoreRxDescr/18 (read)Gmac_Ip_SetRxExternalBuffer/35 (read)Gmac_Ip_ProvideRxBuff/36 (read)Gmac_Ip_DisableController/28 (read)Gmac_Ip_Deinit/24 (write)Gmac_Ip_ReadTimeStampInfo/6 (read)Gmac_Ip_InitStateStructure/12 (write)Gmac_Ip_GetTxMultiBuff/31 (read)Gmac_Ip_ReadFrame/34 (read)Gmac_Ip_GetTxBuff/30 (read)Gmac_Ip_EnableController/27 (read)Gmac_Ip_DisableController/28 (read)Gmac_Ip_ProvideRxBuff/36 (read)Gmac_Ip_ProvideRxBuff/36 (read)Gmac_Ip_SetTxRingWeight/69 (read)
  Availability: available
  Varpool flags: initialized

;; Function Gmac_Ip_ComputeCRC32 (Gmac_Ip_ComputeCRC32, funcdef_no=1, decl_uid=6774, cgraph_uid=2, symbol_order=5)

Modification phase of node Gmac_Ip_ComputeCRC32/5
Adjusting mask for param 1 to 0x4
Setting value range of param 1 [2, 6]
Gmac_Ip_ComputeCRC32 (const uint8 * Mac, uint8 Size)
{
  uint32 j;
  uint32 i;
  uint32 Crc;
  const uint8 * _1;
  unsigned char _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  uint32 _15;

  <bb 2> [local count: 14744043]:
  # DEBUG BEGIN_STMT
  # DEBUG Crc => 4294967295
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG i => 0
  goto <bb 10>; [100.00%]

  <bb 3> [local count: 119292716]:
  # DEBUG BEGIN_STMT
  _1 = Mac_17(D) + i_10;
  _2 = *_1;
  _3 = (long unsigned int) _2;
  Crc_18 = _3 ^ Crc_9;
  # DEBUG Crc => Crc_18
  # DEBUG BEGIN_STMT
  # DEBUG j => 0
  goto <bb 8>; [100.00%]

  <bb 4> [local count: 954449108]:
  # DEBUG BEGIN_STMT
  _4 = Crc_8 & 1;
  if (_4 != 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 5> [local count: 477224554]:
  # DEBUG BEGIN_STMT
  _5 = Crc_8 >> 1;
  Crc_21 = _5 ^ 3988292384;
  # DEBUG Crc => Crc_21
  goto <bb 7>; [100.00%]

  <bb 6> [local count: 477224554]:
  # DEBUG BEGIN_STMT
  Crc_20 = Crc_8 >> 1;
  # DEBUG Crc => Crc_20

  <bb 7> [local count: 954449108]:
  # Crc_7 = PHI <Crc_21(5), Crc_20(6)>
  # DEBUG Crc => Crc_7
  # DEBUG BEGIN_STMT
  j_22 = j_11 + 1;
  # DEBUG j => j_22

  <bb 8> [local count: 1073741824]:
  # Crc_8 = PHI <Crc_18(3), Crc_7(7)>
  # j_11 = PHI <0(3), j_22(7)>
  # DEBUG j => j_11
  # DEBUG Crc => Crc_8
  # DEBUG BEGIN_STMT
  if (j_11 != 8)
    goto <bb 4>; [88.89%]
  else
    goto <bb 9>; [11.11%]

  <bb 9> [local count: 119292717]:
  # Crc_12 = PHI <Crc_8(8)>
  # DEBUG BEGIN_STMT
  i_19 = i_10 + 1;
  # DEBUG i => i_19

  <bb 10> [local count: 134036760]:
  # Crc_9 = PHI <4294967295(2), Crc_12(9)>
  # i_10 = PHI <0(2), i_19(9)>
  # DEBUG i => i_10
  # DEBUG Crc => Crc_9
  # DEBUG BEGIN_STMT
  _6 = (long unsigned int) Size_14(D);
  if (_6 > i_10)
    goto <bb 3>; [89.00%]
  else
    goto <bb 11>; [11.00%]

  <bb 11> [local count: 14744044]:
  # Crc_13 = PHI <Crc_9(10)>
  # DEBUG BEGIN_STMT
  _15 = ~Crc_13;
  return _15;

}



;; Function Gmac_Ip_WriteGateControlList (Gmac_Ip_WriteGateControlList, funcdef_no=4, decl_uid=6793, cgraph_uid=5, symbol_order=8)

Modification phase of node Gmac_Ip_WriteGateControlList/8
Setting value range of param 3 [0, -1]
Gmac_Ip_WriteGateControlList (uint8 Instance, uint16 AddrGateList, uint32 Data, boolean IsGCLA)
{
  uint8 u8ErrorNum;
  uint32 TimeoutTicks;
  uint32 ElapsedTime;
  uint32 StartTime;
  Gmac_Ip_StatusType Status;
  int _1;
  struct GMAC_Type * _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int TimeoutTicks.16_15;
  _Bool _16;
  _Bool _17;

  <bb 2> [local count: 114863532]:
  # DEBUG BEGIN_STMT
  # DEBUG Status => 3
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG u8ErrorNum => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_22(D);
  _2 = Gmac_apxBases[_1];
  _2->MTL_EST_GCL_DATA ={v} Data_24(D);
  # DEBUG BEGIN_STMT
  _3 = (long unsigned int) AddrGateList_26(D);
  _4 = _3 << 8;
  _5 = _4 & 65535;
  _2->MTL_EST_GCL_CONTROL ={v} _5;
  # DEBUG BEGIN_STMT
  if (IsGCLA_28(D) != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 3>; [50.00%]

  <bb 3> [local count: 57431766]:
  # DEBUG BEGIN_STMT
  _6 ={v} _2->MTL_EST_GCL_CONTROL;
  _7 = _6 | 4;
  _2->MTL_EST_GCL_CONTROL ={v} _7;
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 57431766]:
  # DEBUG BEGIN_STMT
  _8 ={v} _2->MTL_EST_GCL_CONTROL;
  _9 = _8 & 4294967291;
  _2->MTL_EST_GCL_CONTROL ={v} _9;

  <bb 5> [local count: 114863532]:
  # DEBUG BEGIN_STMT
  _10 ={v} _2->MTL_EST_GCL_CONTROL;
  _2->MTL_EST_GCL_CONTROL ={v} _10;
  # DEBUG BEGIN_STMT
  _11 ={v} _2->MTL_EST_GCL_CONTROL;
  _12 = _11 | 1;
  _2->MTL_EST_GCL_CONTROL ={v} _12;
  # DEBUG BEGIN_STMT
  GMAC_StartTimeOut (&StartTime, &ElapsedTime, &TimeoutTicks, 1000);

  <bb 6> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _13 ={v} _2->MTL_EST_GCL_CONTROL;
  _14 = _13 & 1;
  if (_14 == 0)
    goto <bb 8>; [5.50%]
  else
    goto <bb 7>; [94.50%]

  <bb 7> [local count: 1014686025]:
  # DEBUG BEGIN_STMT
  TimeoutTicks.16_15 = TimeoutTicks;
  _16 = GMAC_TimeoutExpired (&StartTime, &ElapsedTime, TimeoutTicks.16_15);
  if (_16 != 0)
    goto <bb 8>; [5.50%]
  else
    goto <bb 9>; [94.50%]

  <bb 9> [local count: 958878293]:
  goto <bb 6>; [100.00%]

  <bb 8> [local count: 114863532]:
  # Status_18 = PHI <0(6), 3(7)>
  # DEBUG Status => Status_18
  # DEBUG BEGIN_STMT
  _17 = Status_18 == 3;
  u8ErrorNum_35 = (uint8) _17;
  # DEBUG u8ErrorNum => u8ErrorNum_35
  # DEBUG BEGIN_STMT
  StartTime ={v} {CLOBBER};
  ElapsedTime ={v} {CLOBBER};
  TimeoutTicks ={v} {CLOBBER};
  return u8ErrorNum_35;

}



;; Function Gmac_Ip_CheckMTLEmpty (Gmac_Ip_CheckMTLEmpty, funcdef_no=15, decl_uid=6813, cgraph_uid=16, symbol_order=19)

Modification phase of node Gmac_Ip_CheckMTLEmpty/19
Setting value range of param 2 [0, -1]
Gmac_Ip_CheckMTLEmpty (uint8 Instance, uint16 NumQueues, boolean IsTransmit)
{
  uint16 i;
  boolean QueueEmpty;
  boolean TimeoutOccurred;
  uint32 TimeoutTicks;
  uint32 ElapsedTime;
  uint32 StartTime;
  int _1;
  int _2;
  struct Gmac_Ip_QueueType * _3;
  long unsigned int _4;
  long unsigned int _5;
  int _6;
  int _7;
  struct Gmac_Ip_QueueType * _8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int TimeoutTicks.17_11;
  Gmac_Ip_StatusType iftmp.19_16;

  <bb 2> [local count: 13759443]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG TimeoutOccurred => 0
  # DEBUG BEGIN_STMT
  # DEBUG i => 0
  goto <bb 10>; [100.00%]

  <bb 3> [local count: 114863532]:
  # DEBUG BEGIN_STMT
  GMAC_StartTimeOut (&StartTime, &ElapsedTime, &TimeoutTicks, 1000);

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (IsTransmit_22(D) != 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 5> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_23(D);
  _2 = (int) i_15;
  _3 = Gmac_apxQueueBases[_1][_2];
  _4 ={v} _3->MTL_TXQ_DEBUG;
  _5 = _4 & 16;
  QueueEmpty_25 = _5 == 0;
  # DEBUG QueueEmpty => QueueEmpty_25
  goto <bb 7>; [100.00%]

  <bb 6> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _6 = (int) Instance_23(D);
  _7 = (int) i_15;
  _8 = Gmac_apxQueueBases[_6][_7];
  _9 ={v} _8->MTL_RXQ_DEBUG;
  _10 = _9 & 48;
  QueueEmpty_24 = _10 == 0;
  # DEBUG QueueEmpty => QueueEmpty_24

  <bb 7> [local count: 1073741824]:
  # QueueEmpty_14 = PHI <QueueEmpty_25(5), QueueEmpty_24(6)>
  # DEBUG QueueEmpty => QueueEmpty_14
  # DEBUG BEGIN_STMT
  TimeoutTicks.17_11 = TimeoutTicks;
  TimeoutOccurred_27 = GMAC_TimeoutExpired (&StartTime, &ElapsedTime, TimeoutTicks.17_11);
  # DEBUG TimeoutOccurred => TimeoutOccurred_27
  # DEBUG BEGIN_STMT
  if (QueueEmpty_14 != 0)
    goto <bb 9>; [5.50%]
  else
    goto <bb 8>; [94.50%]

  <bb 8> [local count: 1014686025]:
  if (TimeoutOccurred_27 != 0)
    goto <bb 9>; [5.50%]
  else
    goto <bb 15>; [94.50%]

  <bb 15> [local count: 958878292]:
  goto <bb 4>; [100.00%]

  <bb 9> [local count: 114863532]:
  # TimeoutOccurred_29 = PHI <TimeoutOccurred_27(7), TimeoutOccurred_27(8)>
  # DEBUG BEGIN_STMT
  i_28 = i_15 + 1;
  # DEBUG i => i_28

  <bb 10> [local count: 128622975]:
  # TimeoutOccurred_13 = PHI <0(2), TimeoutOccurred_29(9)>
  # i_15 = PHI <0(2), i_28(9)>
  # DEBUG i => i_15
  # DEBUG TimeoutOccurred => TimeoutOccurred_13
  # DEBUG BEGIN_STMT
  if (i_15 < NumQueues_20(D))
    goto <bb 11>; [94.50%]
  else
    goto <bb 12>; [5.50%]

  <bb 11> [local count: 121548711]:
  if (TimeoutOccurred_13 != 0)
    goto <bb 12>; [5.50%]
  else
    goto <bb 3>; [94.50%]

  <bb 12> [local count: 13759443]:
  # TimeoutOccurred_12 = PHI <TimeoutOccurred_13(10), TimeoutOccurred_13(11)>
  # DEBUG BEGIN_STMT
  if (TimeoutOccurred_12 != 0)
    goto <bb 14>; [35.00%]
  else
    goto <bb 13>; [65.00%]

  <bb 13> [local count: 8943638]:

  <bb 14> [local count: 13759443]:
  # iftmp.19_16 = PHI <3(12), 0(13)>
  StartTime ={v} {CLOBBER};
  ElapsedTime ={v} {CLOBBER};
  TimeoutTicks ={v} {CLOBBER};
  return iftmp.19_16;

}



;; Function Gmac_Ip_EnableTimeGateScheduling (Gmac_Ip_EnableTimeGateScheduling, funcdef_no=19, decl_uid=6393, cgraph_uid=20, symbol_order=23)

Modification phase of node Gmac_Ip_EnableTimeGateScheduling/23
Gmac_Ip_EnableTimeGateScheduling (uint8 Instance, const boolean Enable)
{
  uint32 TimeoutTicks;
  uint32 ElapsedTime;
  uint32 StartTime;
  boolean TimeoutOccurred;
  Gmac_Ip_StatusType Status;
  int _1;
  struct GMAC_Type * _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int TimeoutTicks.13_9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _13;
  long unsigned int _14;

  <bb 2> [local count: 696142619]:
  # DEBUG BEGIN_STMT
  # DEBUG Status => 0
  # DEBUG BEGIN_STMT
  # DEBUG SwitchToSWList => 0
  # DEBUG BEGIN_STMT
  # DEBUG TimeoutOccurred => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_18(D);
  _2 = Gmac_apxBases[_1];
  _3 ={v} _2->MTL_EST_CONTROL;
  _4 = _3 & 1;
  if (_4 == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 11>; [50.00%]

  <bb 3> [local count: 348071309]:
  # DEBUG BEGIN_STMT
  if (Enable_20(D) != 0)
    goto <bb 4>; [33.00%]
  else
    goto <bb 13>; [67.00%]

  <bb 4> [local count: 114863532]:
  # DEBUG BEGIN_STMT
  Status_23 = Gmac_Ip_ConfigTimeGateScheduling (Instance_18(D));
  # DEBUG Status => Status_23
  # DEBUG BEGIN_STMT
  _5 ={v} _2->MTL_EST_CONTROL;
  _6 = _5 | 4099;
  _2->MTL_EST_CONTROL ={v} _6;
  # DEBUG BEGIN_STMT
  GMAC_StartTimeOut (&StartTime, &ElapsedTime, &TimeoutTicks, 1000);

  <bb 5> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _7 ={v} _2->MTL_EST_CONTROL;
  _8 = _7 & 2;
  # DEBUG SwitchToSWList => _8 == 0
  # DEBUG BEGIN_STMT
  TimeoutTicks.13_9 = TimeoutTicks;
  TimeoutOccurred_27 = GMAC_TimeoutExpired (&StartTime, &ElapsedTime, TimeoutTicks.13_9);
  # DEBUG TimeoutOccurred => TimeoutOccurred_27
  # DEBUG BEGIN_STMT
  if (_8 != 0)
    goto <bb 6>; [94.50%]
  else
    goto <bb 7>; [5.50%]

  <bb 6> [local count: 1014686025]:
  if (TimeoutOccurred_27 != 0)
    goto <bb 7>; [5.50%]
  else
    goto <bb 14>; [94.50%]

  <bb 14> [local count: 958878292]:
  goto <bb 5>; [100.00%]

  <bb 7> [local count: 114863532]:
  # TimeoutOccurred_12 = PHI <TimeoutOccurred_27(5), TimeoutOccurred_27(6)>
  # DEBUG BEGIN_STMT
  if (TimeoutOccurred_12 != 0)
    goto <bb 8>; [50.00%]
  else
    goto <bb 10>; [50.00%]

  <bb 8> [local count: 57431766]:
  if (Status_23 != 0)
    goto <bb 10>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 9> [local count: 28715883]:
  _10 ={v} _2->MTL_EST_STATUS;
  _11 = _10 & 2;
  if (_11 != 0)
    goto <bb 10>; [50.00%]
  else
    goto <bb 13>; [50.00%]

  <bb 10> [local count: 100505590]:
  # DEBUG BEGIN_STMT
  # DEBUG Status => 1
  goto <bb 13>; [100.00%]

  <bb 11> [local count: 348071309]:
  # DEBUG BEGIN_STMT
  if (Enable_20(D) != 0)
    goto <bb 13>; [50.00%]
  else
    goto <bb 12>; [50.00%]

  <bb 12> [local count: 174035655]:
  # DEBUG BEGIN_STMT
  _13 ={v} _2->MTL_EST_CONTROL;
  _14 = _13 & 4294967294;
  _2->MTL_EST_CONTROL ={v} _14;

  <bb 13> [local count: 696142619]:
  # Status_15 = PHI <0(9), 0(11), 0(12), 0(3), 1(10)>
  # DEBUG Status => Status_15
  # DEBUG BEGIN_STMT
  StartTime ={v} {CLOBBER};
  ElapsedTime ={v} {CLOBBER};
  TimeoutTicks ={v} {CLOBBER};
  return Status_15;

}



;; Function Gmac_Ip_Deinit (Gmac_Ip_Deinit, funcdef_no=20, decl_uid=6390, cgraph_uid=21, symbol_order=24)

Modification phase of node Gmac_Ip_Deinit/24
Gmac_Ip_Deinit (uint8 Instance)
{
  struct GMAC_Type * Base;
  int _1;
  long unsigned int _2;
  long unsigned int _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_4(D);
  Base_6 = Gmac_apxBases[_1];
  # DEBUG Base => Base_6
  # DEBUG BEGIN_STMT
  _2 ={v} Base_6->DMA_MODE;
  _3 = _2 | 1;
  Base_6->DMA_MODE ={v} _3;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  Gmac_apxState[_1] = 0B;
  return;

}



;; Function Gmac_Ip_GetPowerState (Gmac_Ip_GetPowerState, funcdef_no=21, decl_uid=6395, cgraph_uid=22, symbol_order=25)

Modification phase of node Gmac_Ip_GetPowerState/25
Gmac_Ip_GetPowerState (uint8 Instance)
{
  const struct GMAC_Type * Base;
  int _1;
  Gmac_Ip_PowerStateType _6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_2(D);
  Base_4 = Gmac_apxBases[_1];
  # DEBUG Base => Base_4
  # DEBUG BEGIN_STMT
  _6 = GMAC_GetPowerState (Base_4);
  return _6;

}



;; Function Gmac_Ip_SetPowerState (Gmac_Ip_SetPowerState, funcdef_no=22, decl_uid=6398, cgraph_uid=23, symbol_order=26)

Modification phase of node Gmac_Ip_SetPowerState/26
Gmac_Ip_SetPowerState (uint8 Instance, Gmac_Ip_PowerStateType PowerState)
{
  struct GMAC_Type * Base;
  int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_2(D);
  Base_4 = Gmac_apxBases[_1];
  # DEBUG Base => Base_4
  # DEBUG BEGIN_STMT
  GMAC_SetPowerState (Base_4, PowerState_5(D));
  return;

}



;; Function Gmac_Ip_EnableController (Gmac_Ip_EnableController, funcdef_no=23, decl_uid=6400, cgraph_uid=24, symbol_order=27)

Modification phase of node Gmac_Ip_EnableController/27
Gmac_Ip_EnableController (uint8 Instance)
{
  uint32 i;
  struct Gmac_Ip_ChannelType * _1;
  long unsigned int _2;
  long unsigned int _3;
  int _4;
  struct Gmac_Ip_StateType * _5;
  short unsigned int _6;
  long unsigned int _7;
  struct Gmac_Ip_ChannelType * _8;
  long unsigned int _9;
  long unsigned int _10;
  int _11;
  struct Gmac_Ip_StateType * _12;
  short unsigned int _13;
  long unsigned int _14;
  struct GMAC_Type * _15;
  long unsigned int _16;
  long unsigned int _17;

  <bb 2> [local count: 357878150]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG i => 0
  goto <bb 4>; [100.00%]

  <bb 3> [local count: 715863676]:
  # DEBUG BEGIN_STMT
  _1 = Gmac_apxChBases[_4][i_18];
  _2 ={v} _1->DMA_TX_CONTROL;
  _3 = _2 | 1;
  _1->DMA_TX_CONTROL ={v} _3;
  # DEBUG BEGIN_STMT
  i_28 = i_18 + 1;
  # DEBUG i => i_28

  <bb 4> [local count: 1073741824]:
  # i_18 = PHI <0(2), i_28(3)>
  # DEBUG i => i_18
  # DEBUG BEGIN_STMT
  _4 = (int) Instance_23(D);
  _5 = Gmac_apxState[_4];
  _6 = _5->TxRingCount;
  _7 = (long unsigned int) _6;
  if (_7 > i_18)
    goto <bb 3>; [66.67%]
  else
    goto <bb 5>; [33.33%]

  <bb 5> [local count: 357878150]:
  # _11 = PHI <_4(4)>
  # _12 = PHI <_5(4)>
  goto <bb 7>; [100.00%]

  <bb 6> [local count: 715863676]:
  # DEBUG BEGIN_STMT
  _8 = Gmac_apxChBases[_11][i_19];
  _9 ={v} _8->DMA_RX_CONTROL;
  _10 = _9 | 1;
  _8->DMA_RX_CONTROL ={v} _10;
  # DEBUG BEGIN_STMT
  i_26 = i_19 + 1;
  # DEBUG i => i_26

  <bb 7> [local count: 1073741824]:
  # i_19 = PHI <i_26(6), 0(5)>
  # DEBUG i => i_19
  # DEBUG BEGIN_STMT
  _13 = _12->RxRingCount;
  _14 = (long unsigned int) _13;
  if (_14 > i_19)
    goto <bb 6>; [66.67%]
  else
    goto <bb 8>; [33.33%]

  <bb 8> [local count: 357878150]:
  # DEBUG BEGIN_STMT
  _15 = Gmac_apxBases[_11];
  _16 ={v} _15->MAC_CONFIGURATION;
  _17 = _16 | 3;
  _15->MAC_CONFIGURATION ={v} _17;
  return;

}



;; Function Gmac_Ip_DisableController (Gmac_Ip_DisableController, funcdef_no=24, decl_uid=6402, cgraph_uid=25, symbol_order=28)

Modification phase of node Gmac_Ip_DisableController/28
Gmac_Ip_DisableController (uint8 Instance)
{
  uint32 i;
  Gmac_Ip_StatusType Status;
  struct Gmac_Ip_ChannelType * _1;
  long unsigned int _2;
  long unsigned int _3;
  struct Gmac_Ip_QueueType * _4;
  long unsigned int _5;
  long unsigned int _6;
  int _7;
  struct Gmac_Ip_StateType * _8;
  short unsigned int _9;
  long unsigned int _10;
  int _11;
  short unsigned int _12;
  short unsigned int _13;
  struct GMAC_Type * _14;
  long unsigned int _15;
  long unsigned int _16;
  struct Gmac_Ip_ChannelType * _17;
  long unsigned int _18;
  long unsigned int _19;
  long unsigned int _20;
  long unsigned int _21;
  struct Gmac_Ip_StateType * _22;
  short unsigned int _23;
  long unsigned int _24;

  <bb 2> [local count: 357878150]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG i => 0
  goto <bb 4>; [100.00%]

  <bb 3> [local count: 715863676]:
  # DEBUG BEGIN_STMT
  _1 = Gmac_apxChBases[_7][i_26];
  _2 ={v} _1->DMA_TX_CONTROL;
  _3 = _2 & 4294967294;
  _1->DMA_TX_CONTROL ={v} _3;
  # DEBUG BEGIN_STMT
  _4 = Gmac_apxQueueBases[_7][i_26];
  _5 ={v} _4->MTL_TXQ_OPERATION_MODE;
  _6 = _5 | 1;
  _4->MTL_TXQ_OPERATION_MODE ={v} _6;
  # DEBUG BEGIN_STMT
  i_45 = i_26 + 1;
  # DEBUG i => i_45

  <bb 4> [local count: 1073741824]:
  # i_26 = PHI <0(2), i_45(3)>
  # DEBUG i => i_26
  # DEBUG BEGIN_STMT
  _7 = (int) Instance_32(D);
  _8 = Gmac_apxState[_7];
  _9 = _8->TxRingCount;
  _10 = (long unsigned int) _9;
  if (_10 > i_26)
    goto <bb 3>; [66.67%]
  else
    goto <bb 5>; [33.33%]

  <bb 5> [local count: 357878150]:
  # _11 = PHI <_7(4)>
  # _12 = PHI <_9(4)>
  # DEBUG BEGIN_STMT
  Status_34 = Gmac_Ip_CheckMTLEmpty (Instance_32(D), _12, 1);
  # DEBUG Status => Status_34
  # DEBUG BEGIN_STMT
  if (Status_34 == 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 11>; [50.00%]

  <bb 6> [local count: 178939075]:
  # DEBUG BEGIN_STMT
  _14 = Gmac_apxBases[_11];
  _15 ={v} _14->MAC_CONFIGURATION;
  _16 = _15 & 4294967292;
  _14->MAC_CONFIGURATION ={v} _16;
  # DEBUG BEGIN_STMT
  # DEBUG i => 0
  goto <bb 8>; [100.00%]

  <bb 7> [local count: 357931838]:
  # DEBUG BEGIN_STMT
  _17 = Gmac_apxChBases[_11][i_27];
  _18 ={v} _17->DMA_RX_CONTROL;
  _19 = _18 & 4294967294;
  _17->DMA_RX_CONTROL ={v} _19;
  # DEBUG BEGIN_STMT
  _20 ={v} _17->DMA_RX_CONTROL;
  _21 = _20 | 2147483648;
  _17->DMA_RX_CONTROL ={v} _21;
  # DEBUG BEGIN_STMT
  i_42 = i_27 + 1;
  # DEBUG i => i_42

  <bb 8> [local count: 536870913]:
  # i_27 = PHI <0(6), i_42(7)>
  # DEBUG i => i_27
  # DEBUG BEGIN_STMT
  _22 = Gmac_apxState[_11];
  _23 = _22->RxRingCount;
  _24 = (long unsigned int) _23;
  if (_24 > i_27)
    goto <bb 7>; [66.67%]
  else
    goto <bb 9>; [33.33%]

  <bb 9> [local count: 178939075]:
  # _13 = PHI <_23(8)>
  # DEBUG BEGIN_STMT
  Status_37 = Gmac_Ip_CheckMTLEmpty (Instance_32(D), _13, 0);
  # DEBUG Status => Status_37
  # DEBUG BEGIN_STMT
  if (Status_37 == 0)
    goto <bb 10>; [33.00%]
  else
    goto <bb 11>; [67.00%]

  <bb 10> [local count: 59049895]:
  # DEBUG BEGIN_STMT
  Gmac_Ip_RestoreTxDescr (Instance_32(D));
  # DEBUG BEGIN_STMT
  Gmac_Ip_RestoreRxDescr (Instance_32(D));

  <bb 11> [local count: 357878150]:
  # Status_25 = PHI <Status_34(5), Status_37(9), 0(10)>
  # DEBUG Status => Status_25
  # DEBUG BEGIN_STMT
  return Status_25;

}



;; Function Gmac_Ip_SetSpeed (Gmac_Ip_SetSpeed, funcdef_no=25, decl_uid=6405, cgraph_uid=26, symbol_order=29)

Modification phase of node Gmac_Ip_SetSpeed/29
Gmac_Ip_SetSpeed (uint8 Instance, Gmac_Ip_SpeedType Speed)
{
  struct GMAC_Type * Base;
  int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_2(D);
  Base_4 = Gmac_apxBases[_1];
  # DEBUG Base => Base_4
  # DEBUG BEGIN_STMT
  GMAC_SetSpeed (Base_4, Speed_5(D));
  return;

}



;; Function Gmac_Ip_GetTxBuff (Gmac_Ip_GetTxBuff, funcdef_no=26, decl_uid=6410, cgraph_uid=27, symbol_order=30)

Modification phase of node Gmac_Ip_GetTxBuff/30
Gmac_Ip_GetTxBuff (uint8 Instance, uint8 Ring, struct Gmac_Ip_BufferType * Buff, uint16 * BuffId)
{
  Gmac_Ip_StatusType Status;
  struct Gmac_Ip_BufferDescriptorType * ListBd;
  const struct Gmac_Ip_ChannelType * ChBase;
  struct Gmac_Ip_BufferDescriptorType * Bd;
  int _1;
  int _2;
  struct Gmac_Ip_StateType * _3;
  long unsigned int _4;
  long unsigned int _5;
  signed int _6;
  long unsigned int _7;
  long unsigned int _8;
  short unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  short unsigned int _12;
  short unsigned int _13;
  _Bool _14;
  long unsigned int _15;
  uint8 * _16;
  short unsigned int _17;
  short unsigned int _18;
  long unsigned int _19;
  int _20;
  int _21;
  short unsigned int _22;
  struct Gmac_Ip_BufferDescriptorType * _23;
  long unsigned int _24;
  long unsigned int _25;
  sizetype _26;
  sizetype _27;
  struct Gmac_Ip_BufferDescriptorType * _28;
  long unsigned int _29;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG Status => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_33(D);
  _2 = (int) Ring_34(D);
  ChBase_36 = Gmac_apxChBases[_1][_2];
  # DEBUG ChBase => ChBase_36
  # DEBUG BEGIN_STMT
  _3 = Gmac_apxState[_1];
  Bd_37 = _3->TxCurrentDesc[_2];
  # DEBUG Bd => Bd_37
  # DEBUG BEGIN_STMT
  _4 ={v} ChBase_36->DMA_TXDESC_LIST_ADDRESS;
  ListBd_38 = (struct Gmac_Ip_BufferDescriptorType *) _4;
  # DEBUG ListBd => ListBd_38
  # DEBUG BEGIN_STMT
  _5 = Bd_37->Des3;
  _6 = (signed int) _5;
  if (_6 < 0)
    goto <bb 11>; [27.23%]
  else
    goto <bb 3>; [72.77%]

  <bb 3> [local count: 781361926]:
  _7 = Bd_37->Info1;
  _8 = _7 & 268435456;
  if (_8 != 0)
    goto <bb 11>; [35.00%]
  else
    goto <bb 4>; [65.00%]

  <bb 4> [local count: 507885251]:
  # DEBUG BEGIN_STMT
  _9 = Buff_39(D)->Length;
  _10 = (long unsigned int) _9;
  _11 = _7 & 16383;
  if (_10 > _11)
    goto <bb 5>; [35.00%]
  else
    goto <bb 6>; [65.00%]

  <bb 5> [local count: 177759838]:
  # DEBUG BEGIN_STMT
  # DEBUG Status => 2565
  # DEBUG BEGIN_STMT
  _12 = (short unsigned int) _7;
  _13 = _12 & 16383;
  Buff_39(D)->Length = _13;
  goto <bb 11>; [100.00%]

  <bb 6> [local count: 330125413]:
  # DEBUG BEGIN_STMT
  _14 = Gmac_Ip_InstHasExternalTxBufferManagement[_1];
  if (_14 != 0)
    goto <bb 11>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 7> [local count: 165062707]:
  # DEBUG BEGIN_STMT
  _15 = Bd_37->Des0;
  _16 = (uint8 *) _15;
  Buff_39(D)->Data = _16;
  # DEBUG BEGIN_STMT
  _17 = (short unsigned int) _7;
  _18 = _17 & 16383;
  Buff_39(D)->Length = _18;
  # DEBUG BEGIN_STMT
  _19 = _7 | 268435456;
  Bd_37->Info1 = _19;
  # DEBUG BEGIN_STMT
  if (BuffId_43(D) != 0B)
    goto <bb 8>; [70.00%]
  else
    goto <bb 9>; [30.00%]

  <bb 8> [local count: 115543895]:
  # DEBUG BEGIN_STMT
  _20 = Bd_37 - ListBd_38;
  _21 = _20 /[ex] 32;
  _22 = (short unsigned int) _21;
  *BuffId_43(D) = _22;

  <bb 9> [local count: 165062707]:
  # DEBUG BEGIN_STMT
  _23 = Bd_37 + 32;
  _3->TxCurrentDesc[_2] = _23;
  # DEBUG BEGIN_STMT
  _24 = (long unsigned int) _23;
  _25 ={v} ChBase_36->DMA_TXDESC_RING_LENGTH;
  _26 = _25 + 1;
  _27 = _26 * 32;
  _28 = ListBd_38 + _27;
  _29 = (long unsigned int) _28;
  if (_24 >= _29)
    goto <bb 10>; [50.00%]
  else
    goto <bb 11>; [50.00%]

  <bb 10> [local count: 82531353]:
  # DEBUG BEGIN_STMT
  _3->TxCurrentDesc[_2] = ListBd_38;

  <bb 11> [local count: 1073741824]:
  # Status_30 = PHI <2564(3), 2565(5), 0(6), 0(9), 0(10), 2564(2)>
  # DEBUG Status => Status_30
  # DEBUG BEGIN_STMT
  return Status_30;

}



;; Function Gmac_Ip_GetTxMultiBuff (Gmac_Ip_GetTxMultiBuff, funcdef_no=27, decl_uid=6427, cgraph_uid=28, symbol_order=31)

Modification phase of node Gmac_Ip_GetTxMultiBuff/31
Gmac_Ip_GetTxMultiBuff (uint8 Instance, uint8 ring, uint16 NumBuffers, const uint16 * BufferLength, uint16 * buffId)
{
  uint16 FreeBuffers;
  Gmac_Ip_StatusType Status;
  struct Gmac_Ip_BufferDescriptorType * ListBd;
  const struct Gmac_Ip_ChannelType * ChBase;
  struct Gmac_Ip_BufferDescriptorType * Bd;
  int _1;
  int _2;
  struct Gmac_Ip_StateType * _4;
  long unsigned int _6;
  long unsigned int _7;
  signed int _8;
  long unsigned int _9;
  long unsigned int _10;
  unsigned int _11;
  unsigned int _12;
  const uint16 * _13;
  short unsigned int _14;
  long unsigned int _15;
  long unsigned int _17;
  long unsigned int _19;
  sizetype _20;
  sizetype _21;
  struct Gmac_Ip_BufferDescriptorType * _22;
  long unsigned int _23;
  long unsigned int Bd.22_24;
  int _28;
  int _29;
  short unsigned int _30;

  <bb 2> [local count: 77159559]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG Status => 0
  # DEBUG BEGIN_STMT
  # DEBUG FreeBuffers => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_37(D);
  _2 = (int) ring_38(D);
  ChBase_40 = Gmac_apxChBases[_1][_2];
  # DEBUG ChBase => ChBase_40
  # DEBUG BEGIN_STMT
  _4 = Gmac_apxState[_1];
  Bd_41 = _4->TxCurrentDesc[_2];
  # DEBUG Bd => Bd_41
  # DEBUG BEGIN_STMT
  _6 ={v} ChBase_40->DMA_TXDESC_LIST_ADDRESS;
  ListBd_42 = (struct Gmac_Ip_BufferDescriptorType *) _6;
  # DEBUG ListBd => ListBd_42
  # DEBUG BEGIN_STMT
  goto <bb 15>; [100.00%]

  <bb 3> [local count: 996582264]:
  # DEBUG BEGIN_STMT
  _7 = Bd_31->Des3;
  _8 = (signed int) _7;
  if (_8 < 0)
    goto <bb 16>; [96.34%]
  else
    goto <bb 4>; [3.66%]

  <bb 16> [local count: 960107353]:
  goto <bb 10>; [100.00%]

  <bb 4> [local count: 36474911]:
  # Bd_27 = PHI <Bd_31(3)>
  # FreeBuffers_35 = PHI <FreeBuffers_33(3)>
  _9 = Bd_27->Info1;
  _10 = _9 & 268435456;
  if (_10 != 0)
    goto <bb 9>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 5> [local count: 18237455]:
  # DEBUG BEGIN_STMT
  _11 = (unsigned int) FreeBuffers_35;
  _12 = _11 * 2;
  _13 = BufferLength_44(D) + _12;
  _14 = *_13;
  _15 = (long unsigned int) _14;
  _17 = _9 & 16383;
  if (_15 > _17)
    goto <bb 9>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 6> [local count: 9118728]:
  # DEBUG BEGIN_STMT
  FreeBuffers_45 = FreeBuffers_35 + 1;
  # DEBUG FreeBuffers => FreeBuffers_45
  # DEBUG BEGIN_STMT
  Bd_46 = Bd_27 + 32;
  # DEBUG Bd => Bd_46
  # DEBUG BEGIN_STMT
  _19 ={v} ChBase_40->DMA_TXDESC_RING_LENGTH;
  _20 = _19 + 1;
  _21 = _20 * 32;
  _22 = ListBd_42 + _21;
  _23 = (long unsigned int) _22;
  Bd.22_24 = (long unsigned int) Bd_46;
  if (_23 <= Bd.22_24)
    goto <bb 7>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 7> [local count: 4559364]:
  # DEBUG BEGIN_STMT
  # DEBUG Bd => ListBd_42

  <bb 9> [local count: 36474911]:
  # Bd_26 = PHI <Bd_27(4), Bd_27(5), ListBd_42(7), Bd_46(6)>
  # Status_25 = PHI <2564(4), 2565(5), 0(7), 0(6)>
  # FreeBuffers_18 = PHI <FreeBuffers_35(4), FreeBuffers_35(5), FreeBuffers_45(7), FreeBuffers_45(6)>

  <bb 15> [local count: 113634470]:
  # Bd_3 = PHI <Bd_26(9), Bd_41(2)>
  # Status_5 = PHI <Status_25(9), 0(2)>
  # FreeBuffers_16 = PHI <FreeBuffers_18(9), 0(2)>

  <bb 10> [local count: 1073741824]:
  # Bd_31 = PHI <Bd_3(15), Bd_31(16)>
  # Status_32 = PHI <Status_5(15), 2564(16)>
  # FreeBuffers_33 = PHI <FreeBuffers_16(15), FreeBuffers_33(16)>
  # DEBUG FreeBuffers => FreeBuffers_33
  # DEBUG Status => Status_32
  # DEBUG Bd => Bd_31
  # DEBUG BEGIN_STMT
  if (FreeBuffers_33 < NumBuffers_43(D))
    goto <bb 11>; [96.34%]
  else
    goto <bb 12>; [3.66%]

  <bb 11> [local count: 1034442874]:
  if (Status_32 == 0)
    goto <bb 3>; [96.34%]
  else
    goto <bb 12>; [3.66%]

  <bb 12> [local count: 77159560]:
  # Status_49 = PHI <Status_32(10), Status_32(11)>
  # FreeBuffers_36 = PHI <FreeBuffers_33(10), FreeBuffers_33(11)>
  # DEBUG BEGIN_STMT
  if (FreeBuffers_36 == NumBuffers_43(D))
    goto <bb 13>; [34.00%]
  else
    goto <bb 14>; [66.00%]

  <bb 13> [local count: 26234250]:
  # DEBUG BEGIN_STMT
  _28 = Bd_41 - ListBd_42;
  _29 = _28 /[ex] 32;
  _30 = (short unsigned int) _29;
  *buffId_47(D) = _30;

  <bb 14> [local count: 77159560]:
  # DEBUG BEGIN_STMT
  return Status_49;

}



;; Function Gmac_Ip_SendFrame (Gmac_Ip_SendFrame, funcdef_no=28, decl_uid=6415, cgraph_uid=29, symbol_order=32)

Modification phase of node Gmac_Ip_SendFrame/32
Gmac_Ip_SendFrame (uint8 Instance, uint8 Ring, const struct Gmac_Ip_BufferType * Buff, const struct Gmac_Ip_TxOptionsType * Options)
{
  Std_ReturnType CacheStatus;
  Gmac_Ip_StatusType Status;
  struct Gmac_Ip_BufferDescriptorType * ListBd;
  struct Gmac_Ip_BufferDescriptorType * Bd;
  struct Gmac_Ip_ChannelType * Base;
  int _1;
  int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  signed int _6;
  uint8 * _7;
  long unsigned int _8;
  short unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  short unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  _Bool _15;
  long unsigned int _16;
  long unsigned int _17;
  <unnamed type> _18;
  long unsigned int _19;
  long unsigned int _20;
  long unsigned int _21;
  <unnamed type> _22;
  long unsigned int _23;
  long unsigned int _24;
  long unsigned int _25;
  long unsigned int _26;
  long unsigned int _27;
  long unsigned int _28;
  long unsigned int _29;
  uint8 * _30;
  long unsigned int _31;
  short unsigned int _32;
  long unsigned int _33;
  long unsigned int _34;
  sizetype _35;
  sizetype _36;
  struct Gmac_Ip_BufferDescriptorType * _37;
  long unsigned int _38;
  long unsigned int Bd.24_39;
  long unsigned int iftmp.25_40;
  struct Gmac_Ip_BufferDescriptorType * iftmp.23_42;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG Status => 0
  # DEBUG BEGIN_STMT
  # DEBUG CacheStatus => 1
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_46(D);
  _2 = (int) Ring_47(D);
  Base_49 = Gmac_apxChBases[_1][_2];
  # DEBUG Base => Base_49
  # DEBUG BEGIN_STMT
  _3 ={v} Base_49->DMA_TXDESC_TAIL_POINTER;
  Bd_50 = (struct Gmac_Ip_BufferDescriptorType *) _3;
  # DEBUG Bd => Bd_50
  # DEBUG BEGIN_STMT
  _4 ={v} Base_49->DMA_TXDESC_LIST_ADDRESS;
  ListBd_51 = (struct Gmac_Ip_BufferDescriptorType *) _4;
  # DEBUG ListBd => ListBd_51
  # DEBUG BEGIN_STMT
  _5 = Bd_50->Des3;
  _6 = (signed int) _5;
  if (_6 < 0)
    goto <bb 11>; [27.23%]
  else
    goto <bb 3>; [72.77%]

  <bb 3> [local count: 781361926]:
  # DEBUG BEGIN_STMT
  _7 = Buff_52(D)->Data;
  _8 = (long unsigned int) _7;
  Bd_50->Des0 = _8;
  # DEBUG BEGIN_STMT
  _9 = Buff_52(D)->Length;
  _10 = (long unsigned int) _9;
  _11 = _10 | 3221225472;
  Bd_50->Des2 = _11;
  # DEBUG BEGIN_STMT
  Bd_50->Info0 = _8;
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" DSB");
  # DEBUG BEGIN_STMT
  _12 = Buff_52(D)->Length;
  _13 = (long unsigned int) _12;
  _14 = _13 | 805306368;
  Bd_50->Des3 = _14;
  # DEBUG BEGIN_STMT
  if (Options_58(D) != 0B)
    goto <bb 4>; [70.00%]
  else
    goto <bb 7>; [30.00%]

  <bb 4> [local count: 546953349]:
  # DEBUG BEGIN_STMT
  _15 = Options_58(D)->NoInt;
  if (_15 != 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 5> [local count: 273476674]:
  # DEBUG BEGIN_STMT
  _16 = Bd_50->Des2;
  _17 = _16 & 2147483647;
  Bd_50->Des2 = _17;

  <bb 6> [local count: 546953349]:
  # DEBUG BEGIN_STMT
  _18 = Options_58(D)->CrcPadIns;
  _19 = (long unsigned int) _18;
  _20 = _19 << 26;
  _21 = _20 & 201326592;
  _22 = Options_58(D)->ChecksumIns;
  _23 = (long unsigned int) _22;
  _24 = _23 << 16;
  _25 = _24 & 196608;
  _26 = _21 | _25;
  _27 = _14 | _26;
  Bd_50->Des3 = _27;

  <bb 7> [local count: 781361926]:
  # DEBUG BEGIN_STMT
  _28 = Bd_50->Des3;
  _29 = _28 | 2147483648;
  Bd_50->Des3 = _29;
  # DEBUG BEGIN_STMT
  Bd_62 = Bd_50 + 32;
  # DEBUG Bd => Bd_62
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" DSB");
  # DEBUG BEGIN_STMT
  _30 = Buff_52(D)->Data;
  _31 = (long unsigned int) _30;
  _32 = Buff_52(D)->Length;
  _33 = (long unsigned int) _32;
  CacheStatus_65 = Cache_Ip_CleanByAddr (1, 4, 1, _31, _33);
  # DEBUG CacheStatus => CacheStatus_65
  # DEBUG BEGIN_STMT
  if (CacheStatus_65 == 1)
    goto <bb 11>; [21.72%]
  else
    goto <bb 8>; [78.28%]

  <bb 8> [local count: 611650116]:
  # DEBUG BEGIN_STMT
  _34 ={v} Base_49->DMA_TXDESC_RING_LENGTH;
  _35 = _34 + 1;
  _36 = _35 * 32;
  _37 = ListBd_51 + _36;
  _38 = (long unsigned int) _37;
  Bd.24_39 = (long unsigned int) Bd_62;
  if (_38 <= Bd.24_39)
    goto <bb 10>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 9> [local count: 305825058]:

  <bb 10> [local count: 611650116]:
  # iftmp.23_42 = PHI <ListBd_51(8), Bd_62(9)>
  iftmp.25_40 = (long unsigned int) iftmp.23_42;
  Base_49->DMA_TXDESC_TAIL_POINTER ={v} iftmp.25_40;

  <bb 11> [local count: 1073741824]:
  # Status_41 = PHI <2562(2), 5(7), 0(10)>
  # DEBUG Status => Status_41
  # DEBUG BEGIN_STMT
  return Status_41;

}



;; Function Gmac_Ip_SendMultiBufferFrame (Gmac_Ip_SendMultiBufferFrame, funcdef_no=29, decl_uid=6421, cgraph_uid=30, symbol_order=33)

Modification phase of node Gmac_Ip_SendMultiBufferFrame/33
Gmac_Ip_SendMultiBufferFrame (uint8 Instance, uint8 Ring, const struct Gmac_Ip_BufferType * Buffers, const struct Gmac_Ip_TxOptionsType * Options, uint32 NumBuffers)
{
  boolean DeAllocate;
  Std_ReturnType CacheStatus;
  uint32 RingLength;
  uint32 i;
  Gmac_Ip_StatusType Status;
  struct Gmac_Ip_BufferDescriptorType * LastBd;
  struct Gmac_Ip_BufferDescriptorType * ListBd;
  struct Gmac_Ip_BufferDescriptorType * Bd;
  struct Gmac_Ip_ChannelType * Base;
  int _1;
  int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  signed int _6;
  long unsigned int _7;
  const struct Gmac_Ip_BufferType * _8;
  uint8 * _9;
  long unsigned int _10;
  short unsigned int _13;
  long unsigned int _14;
  long unsigned int _16;
  sizetype _17;
  sizetype _18;
  struct Gmac_Ip_BufferDescriptorType * _19;
  long unsigned int _20;
  long unsigned int Bd.28_21;
  long unsigned int _22;
  _Bool _23;
  long unsigned int _24;
  long unsigned int _25;
  long unsigned int _26;
  long unsigned int _27;
  <unnamed type> _28;
  long unsigned int _29;
  long unsigned int _30;
  long unsigned int _31;
  <unnamed type> _32;
  long unsigned int _33;
  long unsigned int _34;
  long unsigned int _35;
  long unsigned int _36;
  long unsigned int _37;
  long unsigned int _38;
  long unsigned int _39;
  const struct Gmac_Ip_BufferType * _40;
  uint8 * _41;
  long unsigned int _42;
  short unsigned int _43;
  long unsigned int _44;
  long unsigned int Bd.30_45;
  long unsigned int Bd.32_46;
  long unsigned int _47;
  long unsigned int _48;
  long unsigned int _49;
  long unsigned int iftmp.26_60;
  struct Gmac_Ip_BufferDescriptorType * iftmp.27_61;
  long unsigned int iftmp.29_62;
  struct Gmac_Ip_BufferDescriptorType * iftmp.31_63;
  struct Gmac_Ip_BufferDescriptorType * iftmp.31_98;

  <bb 2> [local count: 114863532]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG Status => 0
  # DEBUG BEGIN_STMT
  # DEBUG i => 0
  # DEBUG BEGIN_STMT
  # DEBUG RingLength => 0
  # DEBUG BEGIN_STMT
  # DEBUG CacheStatus => 1
  # DEBUG BEGIN_STMT
  # DEBUG DeAllocate => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_71(D);
  _2 = (int) Ring_72(D);
  Base_74 = Gmac_apxChBases[_1][_2];
  # DEBUG Base => Base_74
  # DEBUG BEGIN_STMT
  _3 ={v} Base_74->DMA_TXDESC_TAIL_POINTER;
  Bd_75 = (struct Gmac_Ip_BufferDescriptorType *) _3;
  # DEBUG Bd => Bd_75
  # DEBUG BEGIN_STMT
  _4 ={v} Base_74->DMA_TXDESC_LIST_ADDRESS;
  ListBd_76 = (struct Gmac_Ip_BufferDescriptorType *) _4;
  # DEBUG ListBd => ListBd_76
  # DEBUG BEGIN_STMT
  RingLength_77 ={v} Base_74->DMA_TXDESC_RING_LENGTH;
  # DEBUG RingLength => RingLength_77
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG FirstBd => Bd_75
  # DEBUG BEGIN_STMT
  # DEBUG LastBd => Bd_75
  # DEBUG BEGIN_STMT
  goto <bb 9>; [100.00%]

  <bb 3> [local count: 1014686025]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _5 = Bd_50->Des3;
  _6 = (signed int) _5;
  if (_6 < 0)
    goto <bb 10>; [5.50%]
  else
    goto <bb 4>; [94.50%]

  <bb 4> [local count: 958878293]:
  # DEBUG BEGIN_STMT
  _7 = i_55 * 8;
  _8 = Buffers_81(D) + _7;
  _9 = _8->Data;
  _10 = (long unsigned int) _9;
  Bd_50->Des0 = _10;
  # DEBUG BEGIN_STMT
  _13 = _8->Length;
  _14 = (long unsigned int) _13;
  Bd_50->Des2 = _14;
  # DEBUG BEGIN_STMT
  Bd_50->Info0 = _10;
  # DEBUG BEGIN_STMT
  if (Bd_50 == Bd_75)
    goto <bb 6>; [30.00%]
  else
    goto <bb 5>; [70.00%]

  <bb 5> [local count: 671214806]:

  <bb 6> [local count: 958878293]:
  # iftmp.26_60 = PHI <0(4), 2147483648(5)>
  _16 = _14 | iftmp.26_60;
  Bd_50->Des3 = _16;
  # DEBUG BEGIN_STMT
  # DEBUG LastBd => Bd_50
  # DEBUG BEGIN_STMT
  Bd_86 = Bd_50 + 32;
  # DEBUG Bd => Bd_86
  # DEBUG BEGIN_STMT
  _17 = RingLength_77 + 1;
  _18 = _17 * 32;
  _19 = ListBd_76 + _18;
  _20 = (long unsigned int) _19;
  Bd.28_21 = (long unsigned int) Bd_86;
  if (_20 <= Bd.28_21)
    goto <bb 8>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 7> [local count: 479439146]:

  <bb 8> [local count: 958878292]:
  # iftmp.27_61 = PHI <ListBd_76(6), Bd_86(7)>
  # DEBUG Bd => iftmp.27_61
  # DEBUG BEGIN_STMT
  i_87 = i_55 + 1;
  # DEBUG i => i_87

  <bb 9> [local count: 1073741824]:
  # Bd_50 = PHI <Bd_75(2), iftmp.27_61(8)>
  # LastBd_52 = PHI <Bd_75(2), Bd_50(8)>
  # i_55 = PHI <0(2), i_87(8)>
  # DEBUG i => i_55
  # DEBUG LastBd => LastBd_52
  # DEBUG Bd => Bd_50
  # DEBUG BEGIN_STMT
  if (i_55 < NumBuffers_80(D))
    goto <bb 3>; [94.50%]
  else
    goto <bb 10>; [5.50%]

  <bb 10> [local count: 114863532]:
  # Status_53 = PHI <2562(3), 0(9)>
  # Bd_11 = PHI <Bd_50(3), Bd_50(9)>
  # LastBd_12 = PHI <LastBd_52(3), LastBd_52(9)>
  # i_15 = PHI <i_55(3), i_55(9)>
  # DEBUG Status => Status_53
  # DEBUG BEGIN_STMT
  if (i_15 == NumBuffers_80(D))
    goto <bb 12>; [34.00%]
  else
    goto <bb 24>; [66.00%]

  <bb 12> [local count: 39053601]:
  # DEBUG BEGIN_STMT
  _22 = LastBd_12->Des2;
  _23 = Options_88(D)->NoInt;
  if (_23 != 0)
    goto <bb 14>; [50.00%]
  else
    goto <bb 13>; [50.00%]

  <bb 13> [local count: 19526800]:

  <bb 14> [local count: 39053601]:
  # iftmp.29_62 = PHI <1073741824(12), 3221225472(13)>
  _24 = _22 | iftmp.29_62;
  LastBd_12->Des2 = _24;
  # DEBUG BEGIN_STMT
  _25 = LastBd_12->Des3;
  _26 = _25 | 268435456;
  LastBd_12->Des3 = _26;
  # DEBUG BEGIN_STMT
  _27 = Bd_75->Des3;
  _28 = Options_88(D)->CrcPadIns;
  _29 = (long unsigned int) _28;
  _30 = _29 << 26;
  _31 = _30 & 201326592;
  _32 = Options_88(D)->ChecksumIns;
  _33 = (long unsigned int) _32;
  _34 = _33 << 16;
  _35 = _34 & 196608;
  _36 = _31 | _35;
  _37 = _27 | _36;
  _38 = _37 | 2684354560;
  Bd_75->Des3 = _38;
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" DSB");
  # DEBUG BEGIN_STMT
  # DEBUG i => 0
  goto <bb 17>; [100.00%]

  <bb 15> [local count: 344993248]:
  # DEBUG BEGIN_STMT
  _39 = i_56 * 8;
  _40 = Buffers_81(D) + _39;
  _41 = _40->Data;
  _42 = (long unsigned int) _41;
  _43 = _40->Length;
  _44 = (long unsigned int) _43;
  CacheStatus_94 = Cache_Ip_CleanByAddr (1, 4, 1, _42, _44);
  # DEBUG CacheStatus => CacheStatus_94
  # DEBUG BEGIN_STMT
  if (CacheStatus_94 == 1)
    goto <bb 18>; [5.50%]
  else
    goto <bb 16>; [94.50%]

  <bb 16> [local count: 326018619]:
  # DEBUG BEGIN_STMT
  i_95 = i_56 + 1;
  # DEBUG i => i_95

  <bb 17> [local count: 365072219]:
  # i_56 = PHI <0(14), i_95(16)>
  # CacheStatus_57 = PHI <1(14), CacheStatus_94(16)>
  # DEBUG CacheStatus => CacheStatus_57
  # DEBUG i => i_56
  # DEBUG BEGIN_STMT
  if (i_56 < NumBuffers_80(D))
    goto <bb 15>; [94.50%]
  else
    goto <bb 18>; [5.50%]

  <bb 18> [local count: 39053601]:
  # CacheStatus_58 = PHI <CacheStatus_94(15), CacheStatus_57(17)>
  # DeAllocate_59 = PHI <1(15), 0(17)>
  # DEBUG DeAllocate => DeAllocate_59
  # DEBUG CacheStatus => CacheStatus_58
  # DEBUG BEGIN_STMT
  if (CacheStatus_58 == 1)
    goto <bb 20>; [34.00%]
  else
    goto <bb 19>; [66.00%]

  <bb 19> [local count: 25775376]:
  # DEBUG BEGIN_STMT
  Bd.30_45 = (long unsigned int) Bd_11;
  Base_74->DMA_TXDESC_TAIL_POINTER ={v} Bd.30_45;

  <bb 20> [local count: 39053601]:
  # Status_54 = PHI <Status_53(19), 5(18)>
  # DEBUG DeAllocate => DeAllocate_59
  # DEBUG Status => Status_54
  # DEBUG BEGIN_STMT
  if (DeAllocate_59 != 0)
    goto <bb 24>; [50.00%]
  else
    goto <bb 26>; [50.00%]

  <bb 21> [local count: 771360829]:
  # DEBUG BEGIN_STMT
  Bd_97 = Bd_51 + 4294967264;
  # DEBUG Bd => Bd_97
  # DEBUG BEGIN_STMT
  Bd.32_46 = (long unsigned int) Bd_97;
  if (_4 > Bd.32_46)
    goto <bb 22>; [50.00%]
  else
    goto <bb 23>; [50.00%]

  <bb 22> [local count: 385680414]:
  _47 = RingLength_77 * 32;
  iftmp.31_98 = ListBd_76 + _47;

  <bb 23> [local count: 771360829]:
  # iftmp.31_63 = PHI <iftmp.31_98(22), Bd_97(21)>
  # DEBUG Bd => iftmp.31_63
  # DEBUG BEGIN_STMT
  _48 = iftmp.31_63->Des3;
  _49 = _48 & 2147483647;
  iftmp.31_63->Des3 = _49;
  goto <bb 25>; [100.00%]

  <bb 24> [local count: 95336731]:
  # Status_78 = PHI <Status_54(20), Status_53(10)>
  # DEBUG DeAllocate => NULL
  # DEBUG Status => NULL

  <bb 25> [local count: 866697562]:
  # Bd_51 = PHI <Bd_11(24), iftmp.31_63(23)>
  # DEBUG Bd => Bd_51
  # DEBUG BEGIN_STMT
  if (Bd_51 != Bd_75)
    goto <bb 21>; [89.00%]
  else
    goto <bb 26>; [11.00%]

  <bb 26> [local count: 114863532]:
  # Status_79 = PHI <Status_54(20), Status_78(25)>
  # DEBUG BEGIN_STMT
  return Status_79;

}



;; Function Gmac_Ip_ReadFrame (Gmac_Ip_ReadFrame, funcdef_no=30, decl_uid=6432, cgraph_uid=31, symbol_order=34)

Modification phase of node Gmac_Ip_ReadFrame/34
Gmac_Ip_ReadFrame (uint8 Instance, uint8 Ring, struct Gmac_Ip_BufferType * Buff, struct Gmac_Ip_RxInfoType * Info)
{
  Std_ReturnType CacheStatus;
  Gmac_Ip_StatusType Status;
  struct Gmac_Ip_BufferDescriptorType * ListBd;
  struct Gmac_Ip_BufferDescriptorType * Bd;
  const struct Gmac_Ip_ChannelType * ChBase;
  int _1;
  int _2;
  struct Gmac_Ip_StateType * _3;
  long unsigned int _4;
  long unsigned int _5;
  signed int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  uint8 * _12;
  long unsigned int _13;
  short unsigned int _14;
  short unsigned int _15;
  int _16;
  long unsigned int _17;
  short unsigned int _18;
  int _19;
  int _20;
  short unsigned int _21;
  long unsigned int _22;
  long unsigned int _23;
  short unsigned int _24;
  long unsigned int _25;
  long unsigned int _26;
  long unsigned int _27;
  _Bool _28;
  long unsigned int _29;
  _Bool _30;
  long unsigned int _31;
  _Bool _32;
  long unsigned int _33;
  _Bool _34;
  long unsigned int _35;
  <unnamed type> _36;
  long unsigned int _37;
  long unsigned int _38;
  short unsigned int _39;
  long unsigned int _40;
  short unsigned int _41;
  struct Gmac_Ip_StateType * _42;
  struct Gmac_Ip_BufferDescriptorType * _43;
  struct Gmac_Ip_BufferDescriptorType * _44;
  long unsigned int _45;
  long unsigned int _46;
  sizetype _47;
  sizetype _48;
  struct Gmac_Ip_BufferDescriptorType * _49;
  long unsigned int _50;
  long unsigned int _57;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG Status => 0
  # DEBUG BEGIN_STMT
  # DEBUG CacheStatus => 1
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_58(D);
  _2 = (int) Ring_59(D);
  ChBase_61 = Gmac_apxChBases[_1][_2];
  # DEBUG ChBase => ChBase_61
  # DEBUG BEGIN_STMT
  _3 = Gmac_apxState[_1];
  Bd_62 = _3->RxCurrentDesc[_2];
  # DEBUG Bd => Bd_62
  # DEBUG BEGIN_STMT
  _4 ={v} ChBase_61->DMA_RXDESC_LIST_ADDRESS;
  ListBd_63 = (struct Gmac_Ip_BufferDescriptorType *) _4;
  # DEBUG ListBd => ListBd_63
  # DEBUG BEGIN_STMT
  _5 = Bd_62->Des3;
  _6 = (signed int) _5;
  if (_6 < 0)
    goto <bb 17>; [27.23%]
  else
    goto <bb 3>; [72.77%]

  <bb 3> [local count: 781361926]:
  _7 = Bd_62->Info1;
  _8 = _7 & 16777216;
  if (_8 != 0)
    goto <bb 17>; [35.00%]
  else
    goto <bb 4>; [65.00%]

  <bb 4> [local count: 507885251]:
  _9 = Bd_62->Info0;
  if (_9 == 0)
    goto <bb 17>; [52.23%]
  else
    goto <bb 5>; [47.77%]

  <bb 5> [local count: 242616785]:
  # DEBUG BEGIN_STMT
  _10 = _7 & 16383;
  CacheStatus_65 = Cache_Ip_InvalidateByAddr (1, 4, _9, _10);
  # DEBUG CacheStatus => CacheStatus_65
  # DEBUG BEGIN_STMT
  if (CacheStatus_65 == 1)
    goto <bb 17>; [21.72%]
  else
    goto <bb 6>; [78.28%]

  <bb 6> [local count: 189920419]:
  # DEBUG BEGIN_STMT
  _11 = Bd_62->Info0;
  _12 = (uint8 *) _11;
  Buff_66(D)->Data = _12;
  # DEBUG BEGIN_STMT
  _13 = Bd_62->Des3;
  _14 = (short unsigned int) _13;
  _15 = _14 & 32767;
  Buff_66(D)->Length = _15;
  # DEBUG BEGIN_STMT
  _16 = (int) _15;
  _17 = Bd_62->Info1;
  _18 = (short unsigned int) _17;
  _57 = _17 & 65535;
  _19 = (int) _57;
  _20 = _19 & 16383;
  if (_16 > _20)
    goto <bb 7>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 7> [local count: 94960209]:
  # DEBUG BEGIN_STMT
  _21 = _18 & 16383;
  Buff_66(D)->Length = _21;

  <bb 8> [local count: 189920419]:
  # DEBUG BEGIN_STMT
  Bd_62->Info0 = 0;
  # DEBUG BEGIN_STMT
  _22 = _17 | 16777216;
  Bd_62->Info1 = _22;
  # DEBUG BEGIN_STMT
  if (Info_72(D) != 0B)
    goto <bb 9>; [70.00%]
  else
    goto <bb 15>; [30.00%]

  <bb 9> [local count: 132944293]:
  # DEBUG BEGIN_STMT
  _23 = _13 & 33030144;
  Info_72(D)->ErrMask = _23;
  # DEBUG BEGIN_STMT
  _24 = Buff_66(D)->Length;
  Info_72(D)->PktLen = _24;
  # DEBUG BEGIN_STMT
  _25 = _13 & 67108864;
  if (_25 != 0)
    goto <bb 10>; [50.00%]
  else
    goto <bb 11>; [50.00%]

  <bb 10> [local count: 66472147]:
  # DEBUG BEGIN_STMT
  _26 = Bd_62->Des1;
  _27 = _26 & 8;
  _28 = _27 != 0;
  Info_72(D)->IpHeaderErr = _28;
  # DEBUG BEGIN_STMT
  _29 = _26 & 128;
  _30 = _29 != 0;
  Info_72(D)->IpPayloadErr = _30;
  # DEBUG BEGIN_STMT
  _31 = _26 & 16;
  _32 = _31 != 0;
  Info_72(D)->Ipv4 = _32;
  # DEBUG BEGIN_STMT
  _33 = _26 & 32;
  _34 = _33 != 0;
  Info_72(D)->Ipv6 = _34;
  # DEBUG BEGIN_STMT
  _35 = _26 & 7;
  _36 = Gmac_Ip_GetPayloadType (_35);
  Info_72(D)->PayloadType = _36;

  <bb 11> [local count: 132944293]:
  # DEBUG BEGIN_STMT
  _37 = _13 & 33554432;
  if (_37 != 0)
    goto <bb 12>; [50.00%]
  else
    goto <bb 13>; [50.00%]

  <bb 12> [local count: 66472147]:
  # DEBUG BEGIN_STMT
  _38 = Bd_62->Des0;
  _39 = (short unsigned int) _38;
  Info_72(D)->OuterVlanTag = _39;
  # DEBUG BEGIN_STMT
  _40 = _38 >> 16;
  _41 = (short unsigned int) _40;
  Info_72(D)->InnerVlanTag = _41;
  goto <bb 14>; [100.00%]

  <bb 13> [local count: 66472147]:
  # DEBUG BEGIN_STMT
  Info_72(D)->OuterVlanTag = 0;
  # DEBUG BEGIN_STMT
  Info_72(D)->InnerVlanTag = 0;

  <bb 14> [local count: 132944293]:
  # DEBUG BEGIN_STMT
  Gmac_Ip_ReadTimeStampInfo (Instance_58(D), Ring_59(D), Info_72(D));

  <bb 15> [local count: 189920419]:
  # DEBUG BEGIN_STMT
  _42 = Gmac_apxState[_1];
  _43 = _42->RxCurrentDesc[_2];
  _44 = _43 + 32;
  _42->RxCurrentDesc[_2] = _44;
  # DEBUG BEGIN_STMT
  _45 = (long unsigned int) _44;
  _46 ={v} ChBase_61->DMA_RXDESC_RING_LENGTH;
  _47 = _46 + 1;
  _48 = _47 * 32;
  _49 = ListBd_63 + _48;
  _50 = (long unsigned int) _49;
  if (_45 >= _50)
    goto <bb 16>; [50.00%]
  else
    goto <bb 17>; [50.00%]

  <bb 16> [local count: 94960209]:
  # DEBUG BEGIN_STMT
  _42->RxCurrentDesc[_2] = ListBd_63;

  <bb 17> [local count: 1073741824]:
  # Status_51 = PHI <2561(3), 5(5), 0(15), 0(16), 2561(2), 2561(4)>
  # DEBUG Status => Status_51
  # DEBUG BEGIN_STMT
  return Status_51;

}



;; Function Gmac_Ip_SetRxExternalBuffer (Gmac_Ip_SetRxExternalBuffer, funcdef_no=31, decl_uid=6448, cgraph_uid=32, symbol_order=35)

Modification phase of node Gmac_Ip_SetRxExternalBuffer/35
Gmac_Ip_SetRxExternalBuffer (uint8 Instance, uint8 Ring, const struct Gmac_Ip_BufferType * Buff)
{
  uint32 RingLength;
  struct Gmac_Ip_BufferDescriptorType * ListBd;
  struct Gmac_Ip_BufferDescriptorType * Bd;
  struct Gmac_Ip_ChannelType * Base;
  int _1;
  int _2;
  struct Gmac_Ip_StateType * _3;
  long unsigned int _4;
  long unsigned int _5;
  uint8 * _6;
  long unsigned int _7;
  short unsigned int _8;
  long unsigned int _9;
  struct Gmac_Ip_BufferDescriptorType * _10;
  long unsigned int _11;
  long unsigned int _12;
  struct Gmac_Ip_BufferDescriptorType * _13;
  long unsigned int _14;
  short unsigned int _32;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_16(D);
  _2 = (int) Ring_17(D);
  Base_19 = Gmac_apxChBases[_1][_2];
  # DEBUG Base => Base_19
  # DEBUG BEGIN_STMT
  _3 = Gmac_apxState[_1];
  Bd_20 = _3->RxAllocDesc[_2];
  # DEBUG Bd => Bd_20
  # DEBUG BEGIN_STMT
  _4 ={v} Base_19->DMA_RXDESC_LIST_ADDRESS;
  ListBd_21 = (struct Gmac_Ip_BufferDescriptorType *) _4;
  # DEBUG ListBd => ListBd_21
  # DEBUG BEGIN_STMT
  _5 ={v} Base_19->DMA_RXDESC_RING_LENGTH;
  RingLength_22 = _5 + 1;
  # DEBUG RingLength => RingLength_22
  # DEBUG BEGIN_STMT
  _6 = Buff_23(D)->Data;
  _7 = (long unsigned int) _6;
  Bd_20->Des0 = _7;
  # DEBUG BEGIN_STMT
  Bd_20->Des1 = 0;
  # DEBUG BEGIN_STMT
  Bd_20->Des2 = 0;
  # DEBUG BEGIN_STMT
  Bd_20->Info0 = _7;
  # DEBUG BEGIN_STMT
  _8 = Gmac_aRxExternalBuffLength[_1];
  _32 = _8 & 16383;
  _9 = (long unsigned int) _32;
  Bd_20->Info1 = _9;
  # DEBUG BEGIN_STMT
  Bd_20->Des3 = 3238002688;
  # DEBUG BEGIN_STMT
  _10 = Bd_20 + 32;
  _3->RxAllocDesc[_2] = _10;
  # DEBUG BEGIN_STMT
  _11 = (long unsigned int) _10;
  _12 = RingLength_22 * 32;
  _13 = ListBd_21 + _12;
  _14 = (long unsigned int) _13;
  if (_11 >= _14)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _3->RxAllocDesc[_2] = ListBd_21;

  <bb 4> [local count: 1073741824]:
  return;

}



;; Function Gmac_Ip_ProvideRxBuff (Gmac_Ip_ProvideRxBuff, funcdef_no=32, decl_uid=6436, cgraph_uid=33, symbol_order=36)

Modification phase of node Gmac_Ip_ProvideRxBuff/36
Gmac_Ip_ProvideRxBuff (uint8 Instance, uint8 Ring, const struct Gmac_Ip_BufferType * Buff)
{
  uint32 RingLength;
  uint32 TailPtr;
  struct Gmac_Ip_BufferDescriptorType * ListBd;
  struct Gmac_Ip_BufferDescriptorType * Bd;
  struct Gmac_Ip_ChannelType * Base;
  int _1;
  int _2;
  struct Gmac_Ip_StateType * _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  struct Gmac_Ip_BufferDescriptorType * _10;
  long unsigned int _11;
  long unsigned int _12;
  struct Gmac_Ip_BufferDescriptorType * _13;
  long unsigned int _14;
  _Bool _15;
  struct Gmac_Ip_StateType * _16;
  uint8 * _17;
  long unsigned int _18;
  long unsigned int _19;
  long unsigned int _20;
  struct Gmac_Ip_StateType * _21;
  struct Gmac_Ip_BufferDescriptorType * _22;
  struct Gmac_Ip_BufferDescriptorType * _23;
  long unsigned int _24;
  long unsigned int _25;
  struct Gmac_Ip_BufferDescriptorType * _26;
  long unsigned int _27;
  struct Gmac_Ip_BufferDescriptorType * iftmp.34_28;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_31(D);
  _2 = (int) Ring_32(D);
  Base_34 = Gmac_apxChBases[_1][_2];
  # DEBUG Base => Base_34
  # DEBUG BEGIN_STMT
  _3 = Gmac_apxState[_1];
  Bd_35 = _3->RxAllocDesc[_2];
  # DEBUG Bd => Bd_35
  # DEBUG BEGIN_STMT
  _4 ={v} Base_34->DMA_RXDESC_LIST_ADDRESS;
  ListBd_36 = (struct Gmac_Ip_BufferDescriptorType *) _4;
  # DEBUG ListBd => ListBd_36
  # DEBUG BEGIN_STMT
  TailPtr_37 ={v} Base_34->DMA_RXDESC_TAIL_POINTER;
  # DEBUG TailPtr => TailPtr_37
  # DEBUG BEGIN_STMT
  _5 ={v} Base_34->DMA_RXDESC_RING_LENGTH;
  RingLength_38 = _5 + 1;
  # DEBUG RingLength => RingLength_38
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _6 = Bd_35->Des1;
  _7 = _6 & 16384;
  if (_7 != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 3> [local count: 536870913]:
  _8 = Bd_35->Des3;
  _9 = _8 & 268435456;
  if (_9 != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 4> [local count: 268435456]:
  # DEBUG BEGIN_STMT
  _10 = Bd_35 + 32;
  _11 = (long unsigned int) _10;
  _12 = RingLength_38 * 32;
  _13 = ListBd_36 + _12;
  _14 = (long unsigned int) _13;
  if (_11 < _14)
    goto <bb 5>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 5> [local count: 134217728]:

  <bb 6> [local count: 268435456]:
  # iftmp.34_28 = PHI <_10(5), ListBd_36(4)>
  # DEBUG CtxtBd => iftmp.34_28
  # DEBUG BEGIN_STMT
  _15 = Gmac_Ip_RestoreRxCtxtDescr (iftmp.34_28);
  if (_15 != 0)
    goto <bb 7>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 7> [local count: 134217728]:
  # DEBUG BEGIN_STMT
  _16 = Gmac_apxState[_1];
  _16->RxAllocDesc[_2] = iftmp.34_28;

  <bb 8> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _17 = Buff_41(D)->Data;
  _18 = (long unsigned int) _17;
  Bd_35->Des0 = _18;
  # DEBUG BEGIN_STMT
  Bd_35->Des1 = 0;
  # DEBUG BEGIN_STMT
  Bd_35->Des2 = 0;
  # DEBUG BEGIN_STMT
  Bd_35->Info0 = _18;
  # DEBUG BEGIN_STMT
  _19 = Bd_35->Info1;
  _20 = _19 & 4278190079;
  Bd_35->Info1 = _20;
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" DSB");
  # DEBUG BEGIN_STMT
  Bd_35->Des3 = 3238002688;
  # DEBUG BEGIN_STMT
  _21 = Gmac_apxState[_1];
  _22 = _21->RxAllocDesc[_2];
  _23 = _22 + 32;
  _21->RxAllocDesc[_2] = _23;
  # DEBUG BEGIN_STMT
  _24 = (long unsigned int) _23;
  _25 = RingLength_38 * 32;
  _26 = ListBd_36 + _25;
  _27 = (long unsigned int) _26;
  if (_24 >= _27)
    goto <bb 9>; [50.00%]
  else
    goto <bb 10>; [50.00%]

  <bb 9> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _21->RxAllocDesc[_2] = ListBd_36;

  <bb 10> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  __asm__ __volatile__(" DSB");
  # DEBUG BEGIN_STMT
  Base_34->DMA_RXDESC_TAIL_POINTER ={v} TailPtr_37;
  return;

}



;; Function Gmac_Ip_IsFrameAvailable (Gmac_Ip_IsFrameAvailable, funcdef_no=33, decl_uid=6439, cgraph_uid=34, symbol_order=37)

Modification phase of node Gmac_Ip_IsFrameAvailable/37
Gmac_Ip_IsFrameAvailable (uint8 Instance, uint8 Ring)
{
  boolean IsFrameAvailable;
  const struct Gmac_Ip_BufferDescriptorType * Bd;
  int _1;
  struct Gmac_Ip_StateType * _2;
  int _3;
  long unsigned int _4;
  signed int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG IsFrameAvailable => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_10(D);
  _2 = Gmac_apxState[_1];
  _3 = (int) Ring_12(D);
  Bd_13 = _2->RxCurrentDesc[_3];
  # DEBUG Bd => Bd_13
  # DEBUG BEGIN_STMT
  _4 = Bd_13->Des3;
  _5 = (signed int) _4;
  if (_5 >= 0)
    goto <bb 3>; [59.00%]
  else
    goto <bb 6>; [41.00%]

  <bb 3> [local count: 633507677]:
  _6 = Bd_13->Info1;
  _7 = _6 & 16777216;
  if (_7 == 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 4> [local count: 316753838]:
  _8 = Bd_13->Info0;
  if (_8 != 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 5> [local count: 158376919]:
  # DEBUG BEGIN_STMT
  # DEBUG IsFrameAvailable => 1

  <bb 6> [local count: 1073741824]:
  # IsFrameAvailable_9 = PHI <0(2), 0(3), 0(4), 1(5)>
  # DEBUG IsFrameAvailable => IsFrameAvailable_9
  # DEBUG BEGIN_STMT
  return IsFrameAvailable_9;

}



;; Function Gmac_Ip_GetTransmitStatus (Gmac_Ip_GetTransmitStatus, funcdef_no=34, decl_uid=6444, cgraph_uid=35, symbol_order=38)

Modification phase of node Gmac_Ip_GetTransmitStatus/38
Gmac_Ip_GetTransmitStatus (uint8 Instance, uint8 Ring, const struct Gmac_Ip_BufferType * Buff, struct Gmac_Ip_TxInfoType * Info)
{
  uint32 RingLength;
  uint32 i;
  Gmac_Ip_StatusType Status;
  struct Gmac_Ip_BufferDescriptorType * Bd;
  struct Gmac_Ip_BufferDescriptorType * ListBd;
  const struct Gmac_Ip_ChannelType * ChBase;
  const struct GMAC_Type * Base;
  int _1;
  int _3;
  long unsigned int _4;
  long unsigned int _5;
  uint8 * _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  sizetype _11;
  sizetype _12;
  struct Gmac_Ip_BufferDescriptorType * _13;
  long unsigned int _14;
  long unsigned int Bd.35_15;
  long unsigned int _16;
  long unsigned int _17;
  signed int _18;
  long unsigned int _19;
  long unsigned int _20;
  signed int _21;
  long unsigned int _22;
  struct Gmac_Ip_TimestampType * _23;
  long unsigned int _24;
  long unsigned int _25;
  long unsigned int _26;

  <bb 2> [local count: 114863532]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG Status => 2563
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_37(D);
  Base_39 = Gmac_apxBases[_1];
  # DEBUG Base => Base_39
  # DEBUG BEGIN_STMT
  _3 = (int) Ring_40(D);
  ChBase_41 = Gmac_apxChBases[_1][_3];
  # DEBUG ChBase => ChBase_41
  # DEBUG BEGIN_STMT
  _4 ={v} ChBase_41->DMA_TXDESC_LIST_ADDRESS;
  ListBd_42 = (struct Gmac_Ip_BufferDescriptorType *) _4;
  # DEBUG ListBd => ListBd_42
  # DEBUG BEGIN_STMT
  # DEBUG Bd => ListBd_42
  # DEBUG BEGIN_STMT
  RingLength_43 ={v} ChBase_41->DMA_TXDESC_RING_LENGTH;
  # DEBUG RingLength => RingLength_43
  # DEBUG BEGIN_STMT
  # DEBUG i => 0
  goto <bb 16>; [100.00%]

  <bb 3> [local count: 1014686025]:
  # DEBUG BEGIN_STMT
  _5 = Bd_30->Info0;
  _6 = Buff_44(D)->Data;
  _7 = (long unsigned int) _6;
  if (_5 == _7)
    goto <bb 4>; [5.50%]
  else
    goto <bb 15>; [94.50%]

  <bb 4> [local count: 55807731]:
  # Bd_2 = PHI <Bd_30(3)>
  goto <bb 8>; [100.00%]

  <bb 5> [local count: 489437715]:
  # DEBUG BEGIN_STMT
  _8 = Bd_28->Info0;
  Bd_28->Des0 = _8;
  # DEBUG BEGIN_STMT
  Bd_28->Info0 = 0;
  # DEBUG BEGIN_STMT
  _9 = Bd_28->Info1;
  _10 = _9 & 4026531839;
  Bd_28->Info1 = _10;
  # DEBUG BEGIN_STMT
  Bd_50 = Bd_28 + 32;
  # DEBUG Bd => Bd_50
  # DEBUG BEGIN_STMT
  _11 = RingLength_43 + 1;
  _12 = _11 * 32;
  _13 = ListBd_42 + _12;
  _14 = (long unsigned int) _13;
  Bd.35_15 = (long unsigned int) Bd_50;
  if (_14 <= Bd.35_15)
    goto <bb 6>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 6> [local count: 244718857]:
  # DEBUG BEGIN_STMT
  # DEBUG Bd => ListBd_42

  <bb 7> [local count: 489437715]:
  # Bd_27 = PHI <Bd_50(5), ListBd_42(6)>
  # DEBUG Bd => Bd_27
  # DEBUG BEGIN_STMT
  if (Bd_2 == Bd_27)
    goto <bb 10>; [3.66%]
  else
    goto <bb 18>; [96.34%]

  <bb 18> [local count: 471524295]:

  <bb 8> [local count: 527332025]:
  # Bd_28 = PHI <Bd_2(4), Bd_27(18)>
  # DEBUG StartBd => NULL
  # DEBUG Bd => Bd_28
  # DEBUG BEGIN_STMT
  _16 = Bd_28->Des3;
  _17 = _16 & 268435456;
  if (_17 == 0)
    goto <bb 9>; [96.34%]
  else
    goto <bb 10>; [3.66%]

  <bb 9> [local count: 508031674]:
  _18 = (signed int) _16;
  if (_18 >= 0)
    goto <bb 5>; [96.34%]
  else
    goto <bb 10>; [3.66%]

  <bb 10> [local count: 55807732]:
  # Bd_29 = PHI <Bd_27(7), Bd_28(8), Bd_28(9)>
  # DEBUG Bd => Bd_29
  # DEBUG BEGIN_STMT
  _19 = Bd_29->Des3;
  _20 = _19 & 268435456;
  if (_20 != 0)
    goto <bb 11>; [65.00%]
  else
    goto <bb 17>; [35.00%]

  <bb 11> [local count: 36275026]:
  _21 = (signed int) _19;
  if (_21 >= 0)
    goto <bb 12>; [72.77%]
  else
    goto <bb 17>; [27.23%]

  <bb 12> [local count: 26397336]:
  # DEBUG BEGIN_STMT
  # DEBUG Status => 0
  # DEBUG BEGIN_STMT
  if (Info_51(D) != 0B)
    goto <bb 13>; [53.47%]
  else
    goto <bb 14>; [46.53%]

  <bb 13> [local count: 14114656]:
  # DEBUG BEGIN_STMT
  _22 = _19 & 32525;
  Info_51(D)->ErrMask = _22;
  # DEBUG BEGIN_STMT
  _23 = &Info_51(D)->Timestamp;
  Gmac_Ip_GetTimestamp (Base_39, Bd_29, _23);

  <bb 14> [local count: 26397336]:
  # DEBUG BEGIN_STMT
  _24 = Bd_29->Info0;
  Bd_29->Des0 = _24;
  # DEBUG BEGIN_STMT
  Bd_29->Info0 = 0;
  # DEBUG BEGIN_STMT
  _25 = Bd_29->Info1;
  _26 = _25 & 4026531839;
  Bd_29->Info1 = _26;
  goto <bb 17>; [100.00%]

  <bb 15> [local count: 958878293]:
  # DEBUG BEGIN_STMT
  Bd_45 = Bd_30 + 32;
  # DEBUG Bd => Bd_45
  # DEBUG BEGIN_STMT
  i_46 = i_32 + 1;
  # DEBUG i => i_46

  <bb 16> [local count: 1073741824]:
  # Bd_30 = PHI <ListBd_42(2), Bd_45(15)>
  # i_32 = PHI <0(2), i_46(15)>
  # DEBUG i => i_32
  # DEBUG Bd => Bd_30
  # DEBUG BEGIN_STMT
  if (i_32 <= RingLength_43)
    goto <bb 3>; [94.50%]
  else
    goto <bb 17>; [5.50%]

  <bb 17> [local count: 114863532]:
  # Status_31 = PHI <2(11), 2563(16), 0(14), 2(10)>
  # DEBUG Status => Status_31
  # DEBUG BEGIN_STMT
  return Status_31;

}



;; Function Gmac_Ip_GetCounter (Gmac_Ip_GetCounter, funcdef_no=35, decl_uid=6451, cgraph_uid=36, symbol_order=39)

Modification phase of node Gmac_Ip_GetCounter/39
Gmac_Ip_GetCounter (uint8 Instance, Gmac_Ip_CounterType Counter)
{
  volatile uint32[53] * Count_Reg;
  volatile uint32 CounterAddr;
  const struct GMAC_Type * Base;
  int _1;
  const uint32_t * _2;
  long unsigned int _3;
  long unsigned int CounterAddr.36_4;
  int _5;
  uint32 _12;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_6(D);
  Base_8 = Gmac_apxBases[_1];
  # DEBUG Base => Base_8
  # DEBUG BEGIN_STMT
  _2 = &Base_8->TX_OCTET_COUNT_GOOD_BAD;
  _3 = (long unsigned int) _2;
  CounterAddr ={v} _3;
  # DEBUG BEGIN_STMT
  CounterAddr.36_4 ={v} CounterAddr;
  Count_Reg_10 = (volatile uint32[53] *) CounterAddr.36_4;
  # DEBUG Count_Reg => Count_Reg_10
  # DEBUG BEGIN_STMT
  _5 = (int) Counter_11(D);
  _12 ={v} *Count_Reg_10[_5];
  return _12;

}



;; Function Gmac_Ip_EnableMDIO (Gmac_Ip_EnableMDIO, funcdef_no=36, decl_uid=6455, cgraph_uid=37, symbol_order=40)

Modification phase of node Gmac_Ip_EnableMDIO/40
Gmac_Ip_EnableMDIO (uint8 Instance, boolean MiiPreambleDisabled, uint32 ModuleClk)
{
  uint8 i;
  uint8 Csr;
  struct GMAC_Type * Base;
  static const uint8 CsrValues[9] = "\x02\x02\x03\x00\x01\x04\x05\x06\x07";
  static const uint32 Freq[9] = {20000000, 35000000, 60000000, 100000000, 150000000, 250000000, 300000000, 500000000, 800000000};
  int _1;
  int _2;
  long unsigned int _3;
  int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int iftmp.38_11;

  <bb 2> [local count: 160524402]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_12(D);
  Base_14 = Gmac_apxBases[_1];
  # DEBUG Base => Base_14
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG Csr => 0
  # DEBUG BEGIN_STMT
  # DEBUG i => 0
  goto <bb 6>; [100.00%]

  <bb 3> [local count: 966367643]:
  # DEBUG BEGIN_STMT
  _2 = (int) i_10;
  _3 = Freq[_2];
  if (_3 >= ModuleClk_15(D))
    goto <bb 4>; [5.50%]
  else
    goto <bb 5>; [94.50%]

  <bb 4> [local count: 53150220]:
  # _4 = PHI <_2(3)>
  # DEBUG BEGIN_STMT
  Csr_17 = CsrValues[_4];
  # DEBUG Csr => Csr_17
  # DEBUG BEGIN_STMT
  goto <bb 7>; [100.00%]

  <bb 5> [local count: 913217422]:
  # DEBUG BEGIN_STMT
  i_16 = i_10 + 1;
  # DEBUG i => i_16

  <bb 6> [local count: 1073741824]:
  # i_10 = PHI <0(2), i_16(5)>
  # DEBUG i => i_10
  # DEBUG BEGIN_STMT
  if (i_10 != 9)
    goto <bb 3>; [90.00%]
  else
    goto <bb 7>; [10.00%]

  <bb 7> [local count: 160524403]:
  # Csr_9 = PHI <Csr_17(4), 0(6)>
  # DEBUG Csr => Csr_9
  # DEBUG BEGIN_STMT
  if (MiiPreambleDisabled_18(D) != 0)
    goto <bb 9>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 8> [local count: 80262201]:

  <bb 9> [local count: 160524403]:
  # iftmp.38_11 = PHI <134217728(7), 0(8)>
  _5 = (long unsigned int) Csr_9;
  _6 = _5 << 8;
  _7 = _6 & 3840;
  _8 = _7 | iftmp.38_11;
  Base_14->MAC_MDIO_ADDRESS ={v} _8;
  return;

}



;; Function Gmac_Ip_MDIORead (Gmac_Ip_MDIORead, funcdef_no=37, decl_uid=6461, cgraph_uid=38, symbol_order=41)

Modification phase of node Gmac_Ip_MDIORead/41
Gmac_Ip_MDIORead (uint8 Instance, uint8 PhyAddr, uint8 PhyReg, uint16 * Data, uint32 TimeoutMs)
{
  struct Gmac_Ip_ManagementInfo ManageInfo;
  Gmac_Ip_StatusType Status;
  struct GMAC_Type * Base;
  int _1;
  short unsigned int _2;
  long unsigned int _3;
  long unsigned int _22;
  short unsigned int _23;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_5(D);
  Base_7 = Gmac_apxBases[_1];
  # DEBUG Base => Base_7
  # DEBUG BEGIN_STMT
  ManageInfo.PhysAddr = PhyAddr_8(D);
  # DEBUG BEGIN_STMT
  _2 = (short unsigned int) PhyReg_10(D);
  ManageInfo.PhysReg = _2;
  # DEBUG BEGIN_STMT
  ManageInfo.MmdAddr = 0;
  # DEBUG BEGIN_STMT
  ManageInfo.OpFrameType = 1;
  # DEBUG BEGIN_STMT
  ManageInfo.FrameData = 0;
  # DEBUG BEGIN_STMT
  ManageInfo.SupportedClause45 = 0;
  # DEBUG BEGIN_STMT
  _3 = TimeoutMs_16(D) * 1000;
  Status_18 = GMAC_WriteManagementFrame (Base_7, &ManageInfo, _3);
  # DEBUG Status => Status_18
  # DEBUG BEGIN_STMT
  if (Status_18 == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  # DEBUG Base => Base_7
  # DEBUG INLINE_ENTRY GMAC_ReadManagementFrameData
  # DEBUG BEGIN_STMT
  _22 ={v} MEM[(const struct GMAC_Type *)Base_7].MAC_MDIO_DATA;
  _23 = (short unsigned int) _22;
  # DEBUG Base => NULL
  *Data_19(D) = _23;

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  ManageInfo ={v} {CLOBBER};
  return Status_18;

}



;; Function Gmac_Ip_MDIOWrite (Gmac_Ip_MDIOWrite, funcdef_no=38, decl_uid=6467, cgraph_uid=39, symbol_order=42)

Modification phase of node Gmac_Ip_MDIOWrite/42
Gmac_Ip_MDIOWrite (uint8 Instance, uint8 PhyAddr, uint8 PhyReg, uint16 Data, uint32 TimeoutMs)
{
  struct Gmac_Ip_ManagementInfo ManageInfo;
  Gmac_Ip_StatusType Status;
  struct GMAC_Type * Base;
  int _1;
  short unsigned int _2;
  long unsigned int _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_4(D);
  Base_6 = Gmac_apxBases[_1];
  # DEBUG Base => Base_6
  # DEBUG BEGIN_STMT
  ManageInfo.PhysAddr = PhyAddr_7(D);
  # DEBUG BEGIN_STMT
  _2 = (short unsigned int) PhyReg_9(D);
  ManageInfo.PhysReg = _2;
  # DEBUG BEGIN_STMT
  ManageInfo.MmdAddr = 0;
  # DEBUG BEGIN_STMT
  ManageInfo.OpFrameType = 0;
  # DEBUG BEGIN_STMT
  ManageInfo.FrameData = Data_13(D);
  # DEBUG BEGIN_STMT
  ManageInfo.SupportedClause45 = 0;
  # DEBUG BEGIN_STMT
  _3 = TimeoutMs_16(D) * 1000;
  Status_18 = GMAC_WriteManagementFrame (Base_6, &ManageInfo, _3);
  # DEBUG Status => Status_18
  # DEBUG BEGIN_STMT
  ManageInfo ={v} {CLOBBER};
  return Status_18;

}



;; Function Gmac_Ip_MDIOReadMMD (Gmac_Ip_MDIOReadMMD, funcdef_no=39, decl_uid=6474, cgraph_uid=40, symbol_order=43)

Modification phase of node Gmac_Ip_MDIOReadMMD/43
Gmac_Ip_MDIOReadMMD (uint8 Instance, uint8 PhyAddr, uint8 Mmd, uint16 PhyReg, uint16 * Data, uint32 TimeoutMs)
{
  struct Gmac_Ip_ManagementInfo ManageInfo;
  Gmac_Ip_StatusType Status;
  struct GMAC_Type * Base;
  int _1;
  short unsigned int _2;
  long unsigned int _3;
  long unsigned int _23;
  short unsigned int _24;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_5(D);
  Base_7 = Gmac_apxBases[_1];
  # DEBUG Base => Base_7
  # DEBUG BEGIN_STMT
  ManageInfo.PhysAddr = PhyAddr_8(D);
  # DEBUG BEGIN_STMT
  ManageInfo.PhysReg = PhyReg_10(D);
  # DEBUG BEGIN_STMT
  _2 = (short unsigned int) Mmd_12(D);
  ManageInfo.MmdAddr = _2;
  # DEBUG BEGIN_STMT
  ManageInfo.OpFrameType = 1;
  # DEBUG BEGIN_STMT
  ManageInfo.FrameData = 0;
  # DEBUG BEGIN_STMT
  ManageInfo.SupportedClause45 = 1;
  # DEBUG BEGIN_STMT
  _3 = TimeoutMs_17(D) * 1000;
  Status_19 = GMAC_WriteManagementFrame (Base_7, &ManageInfo, _3);
  # DEBUG Status => Status_19
  # DEBUG BEGIN_STMT
  if (Status_19 == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  # DEBUG Base => Base_7
  # DEBUG INLINE_ENTRY GMAC_ReadManagementFrameData
  # DEBUG BEGIN_STMT
  _23 ={v} MEM[(const struct GMAC_Type *)Base_7].MAC_MDIO_DATA;
  _24 = (short unsigned int) _23;
  # DEBUG Base => NULL
  *Data_20(D) = _24;

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  ManageInfo ={v} {CLOBBER};
  return Status_19;

}



;; Function Gmac_Ip_MDIOWriteMMD (Gmac_Ip_MDIOWriteMMD, funcdef_no=40, decl_uid=6481, cgraph_uid=41, symbol_order=44)

Modification phase of node Gmac_Ip_MDIOWriteMMD/44
Gmac_Ip_MDIOWriteMMD (uint8 Instance, uint8 PhyAddr, uint8 Mmd, uint16 PhyReg, uint16 Data, uint32 TimeoutMs)
{
  struct Gmac_Ip_ManagementInfo ManageInfo;
  Gmac_Ip_StatusType Status;
  struct GMAC_Type * Base;
  int _1;
  short unsigned int _2;
  long unsigned int _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_4(D);
  Base_6 = Gmac_apxBases[_1];
  # DEBUG Base => Base_6
  # DEBUG BEGIN_STMT
  ManageInfo.PhysAddr = PhyAddr_7(D);
  # DEBUG BEGIN_STMT
  ManageInfo.PhysReg = PhyReg_9(D);
  # DEBUG BEGIN_STMT
  _2 = (short unsigned int) Mmd_11(D);
  ManageInfo.MmdAddr = _2;
  # DEBUG BEGIN_STMT
  ManageInfo.OpFrameType = 0;
  # DEBUG BEGIN_STMT
  ManageInfo.FrameData = Data_14(D);
  # DEBUG BEGIN_STMT
  ManageInfo.SupportedClause45 = 1;
  # DEBUG BEGIN_STMT
  _3 = TimeoutMs_17(D) * 1000;
  Status_19 = GMAC_WriteManagementFrame (Base_6, &ManageInfo, _3);
  # DEBUG Status => Status_19
  # DEBUG BEGIN_STMT
  ManageInfo ={v} {CLOBBER};
  return Status_19;

}



;; Function Gmac_Ip_SetMacAddr (Gmac_Ip_SetMacAddr, funcdef_no=41, decl_uid=6484, cgraph_uid=42, symbol_order=45)

Modification phase of node Gmac_Ip_SetMacAddr/45
Gmac_Ip_SetMacAddr (uint8 Instance, const uint8 * MacAddr)
{
  struct GMAC_Type * Base;
  uint32 Address;
  int _1;
  unsigned char _2;
  long unsigned int _3;
  long unsigned int _4;
  unsigned char _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  unsigned char _9;
  long unsigned int _10;
  long unsigned int _11;
  unsigned char _12;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int _15;
  unsigned char _16;
  long unsigned int _17;
  long unsigned int _18;
  long unsigned int _19;
  unsigned char _20;
  long unsigned int _21;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_22(D);
  Base_24 = Gmac_apxBases[_1];
  # DEBUG Base => Base_24
  # DEBUG BEGIN_STMT
  _2 = MEM[(const uint8 *)MacAddr_25(D) + 5B];
  _3 = (long unsigned int) _2;
  _4 = _3 << 8;
  _5 = MEM[(const uint8 *)MacAddr_25(D) + 4B];
  _6 = (long unsigned int) _5;
  _7 = _4 | _6;
  _8 = _7 | 2147483648;
  Base_24->MAC_ADDRESS0_HIGH ={v} _8;
  # DEBUG BEGIN_STMT
  _9 = MEM[(const uint8 *)MacAddr_25(D) + 3B];
  _10 = (long unsigned int) _9;
  _11 = _10 << 24;
  _12 = MEM[(const uint8 *)MacAddr_25(D) + 2B];
  _13 = (long unsigned int) _12;
  _14 = _13 << 16;
  _15 = _11 | _14;
  _16 = MEM[(const uint8 *)MacAddr_25(D) + 1B];
  _17 = (long unsigned int) _16;
  _18 = _17 << 8;
  _19 = _15 | _18;
  _20 = *MacAddr_25(D);
  _21 = (long unsigned int) _20;
  Address_27 = _19 | _21;
  # DEBUG Address => Address_27
  # DEBUG BEGIN_STMT
  Base_24->MAC_ADDRESS0_LOW ={v} Address_27;
  return;

}



;; Function Gmac_Ip_Init (Gmac_Ip_Init, funcdef_no=18, decl_uid=6388, cgraph_uid=19, symbol_order=22)

Modification phase of node Gmac_Ip_Init/22
Gmac_Ip_Init (uint8 Instance, const struct Gmac_CtrlConfigType * Config)
{
  Gmac_Ip_StatusType Status;
  struct GMAC_Type * Base;
  int _1;
  const uint8 * _2;
  const struct sGmac_Ip_ConfigType * _15;
  const struct sGmac_Ip_TxTimeAwareShaper * _16;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_4(D);
  Base_6 = Gmac_apxBases[_1];
  # DEBUG Base => Base_6
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  Status_9 = Gmac_Ip_InitDMA (Instance_4(D), Config_7(D));
  # DEBUG Status => Status_9
  # DEBUG BEGIN_STMT
  if (Status_9 == 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 4>; [67.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  Gmac_Ip_InitMTL (Instance_4(D), Config_7(D));
  # DEBUG BEGIN_STMT
  _2 = Config_7(D)->Gmac_pau8CtrlPhysAddr;
  Gmac_Ip_SetMacAddr (Instance_4(D), _2);
  # DEBUG BEGIN_STMT
  _15 = MEM[(const struct sGmac_Ip_ConfigType * *)Config_7(D) + 4B];
  # DEBUG D#1 => Config_7(D)
  Gmac_Ip_InitMAC.isra.0 (Base_6, _15);
  # DEBUG BEGIN_STMT
  Gmac_Ip_InitStateStructure (Instance_4(D), Config_7(D));
  # DEBUG BEGIN_STMT
  _16 = MEM[(const struct sGmac_Ip_TxTimeAwareShaper * *)Config_7(D) + 20B];
  # DEBUG D#2 => Config_7(D)
  Gmac_Ip_TxTimeAwareShaperInit.isra.0 (Instance_4(D), _16);

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return Status_9;

}



;; Function Gmac_Ip_GetMacAddr (Gmac_Ip_GetMacAddr, funcdef_no=42, decl_uid=6487, cgraph_uid=43, symbol_order=46)

Modification phase of node Gmac_Ip_GetMacAddr/46
Gmac_Ip_GetMacAddr (uint8 Instance, uint8 * MacAddr)
{
  uint32 Address;
  const struct GMAC_Type * Base;
  int _1;
  unsigned char _2;
  long unsigned int _3;
  unsigned char _4;
  long unsigned int _5;
  unsigned char _6;
  long unsigned int _7;
  unsigned char _8;
  long unsigned int _9;
  unsigned char _10;
  long unsigned int _11;
  unsigned char _12;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_13(D);
  Base_15 = Gmac_apxBases[_1];
  # DEBUG Base => Base_15
  # DEBUG BEGIN_STMT
  Address_16 ={v} Base_15->MAC_ADDRESS0_LOW;
  # DEBUG Address => Address_16
  # DEBUG BEGIN_STMT
  _2 = (unsigned char) Address_16;
  *MacAddr_17(D) = _2;
  # DEBUG BEGIN_STMT
  _3 = Address_16 >> 8;
  _4 = (unsigned char) _3;
  MEM[(uint8 *)MacAddr_17(D) + 1B] = _4;
  # DEBUG BEGIN_STMT
  _5 = Address_16 >> 16;
  _6 = (unsigned char) _5;
  MEM[(uint8 *)MacAddr_17(D) + 2B] = _6;
  # DEBUG BEGIN_STMT
  _7 = Address_16 >> 24;
  _8 = (unsigned char) _7;
  MEM[(uint8 *)MacAddr_17(D) + 3B] = _8;
  # DEBUG BEGIN_STMT
  _9 ={v} Base_15->MAC_ADDRESS0_HIGH;
  Address_22 = _9 & 65535;
  # DEBUG Address => Address_22
  # DEBUG BEGIN_STMT
  _10 = (unsigned char) Address_22;
  MEM[(uint8 *)MacAddr_17(D) + 4B] = _10;
  # DEBUG BEGIN_STMT
  _11 = Address_22 >> 8;
  _12 = (unsigned char) _11;
  MEM[(uint8 *)MacAddr_17(D) + 5B] = _12;
  return;

}



;; Function Gmac_Ip_GetInterruptFlags (Gmac_Ip_GetInterruptFlags, funcdef_no=43, decl_uid=6489, cgraph_uid=44, symbol_order=47)

Modification phase of node Gmac_Ip_GetInterruptFlags/47
Gmac_Ip_GetInterruptFlags (uint8 Instance)
{
  const struct GMAC_Type * Base;
  int _1;
  uint32 _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_2(D);
  Base_4 = Gmac_apxBases[_1];
  # DEBUG Base => Base_4
  # DEBUG BEGIN_STMT
  _5 ={v} Base_4->MAC_INTERRUPT_STATUS;
  return _5;

}



;; Function Gmac_Ip_GetChInterruptFlags (Gmac_Ip_GetChInterruptFlags, funcdef_no=44, decl_uid=6492, cgraph_uid=45, symbol_order=48)

Modification phase of node Gmac_Ip_GetChInterruptFlags/48
Gmac_Ip_GetChInterruptFlags (uint8 Instance, uint8 Channel)
{
  const struct Gmac_Ip_ChannelType * Base;
  int _1;
  int _2;
  uint32 _7;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_3(D);
  _2 = (int) Channel_4(D);
  Base_6 = Gmac_apxChBases[_1][_2];
  # DEBUG Base => Base_6
  # DEBUG BEGIN_STMT
  _7 ={v} Base_6->DMA_STATUS;
  return _7;

}



;; Function Gmac_Ip_SetBroadcastForwardAll (Gmac_Ip_SetBroadcastForwardAll, funcdef_no=45, decl_uid=6495, cgraph_uid=46, symbol_order=49)

Modification phase of node Gmac_Ip_SetBroadcastForwardAll/49
Gmac_Ip_SetBroadcastForwardAll (uint8 Instance, boolean Enable)
{
  struct GMAC_Type * Base;
  int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_11(D);
  Base_13 = Gmac_apxBases[_1];
  # DEBUG Base => Base_13
  # DEBUG BEGIN_STMT
  if (Enable_14(D) != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _2 ={v} Base_13->MAC_PACKET_FILTER;
  _3 = _2 & 4294967263;
  Base_13->MAC_PACKET_FILTER ={v} _3;
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _4 ={v} Base_13->MAC_PACKET_FILTER;
  _5 = _4 & 2147483647;
  Base_13->MAC_PACKET_FILTER ={v} _5;
  # DEBUG BEGIN_STMT
  _6 ={v} Base_13->MAC_PACKET_FILTER;
  _7 = _6 & 4294967294;
  Base_13->MAC_PACKET_FILTER ={v} _7;
  # DEBUG BEGIN_STMT
  _8 ={v} Base_13->MAC_PACKET_FILTER;
  _9 = _8 | 32;
  Base_13->MAC_PACKET_FILTER ={v} _9;

  <bb 5> [local count: 1073741824]:
  return;

}



;; Function Gmac_Ip_SetMulticastForwardAll (Gmac_Ip_SetMulticastForwardAll, funcdef_no=46, decl_uid=6498, cgraph_uid=47, symbol_order=50)

Modification phase of node Gmac_Ip_SetMulticastForwardAll/50
Gmac_Ip_SetMulticastForwardAll (uint8 Instance, boolean Enable)
{
  struct GMAC_Type * Base;
  int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_13(D);
  Base_15 = Gmac_apxBases[_1];
  # DEBUG Base => Base_15
  # DEBUG BEGIN_STMT
  if (Enable_16(D) != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _2 ={v} Base_15->MAC_PACKET_FILTER;
  _3 = _2 | 16;
  Base_15->MAC_PACKET_FILTER ={v} _3;
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _4 ={v} Base_15->MAC_PACKET_FILTER;
  _5 = _4 & 2147483647;
  Base_15->MAC_PACKET_FILTER ={v} _5;
  # DEBUG BEGIN_STMT
  _6 ={v} Base_15->MAC_PACKET_FILTER;
  _7 = _6 & 4294967294;
  Base_15->MAC_PACKET_FILTER ={v} _7;
  # DEBUG BEGIN_STMT
  _8 ={v} Base_15->MAC_PACKET_FILTER;
  _9 = _8 & 4294967279;
  Base_15->MAC_PACKET_FILTER ={v} _9;
  # DEBUG BEGIN_STMT
  _10 ={v} Base_15->MAC_PACKET_FILTER;
  _11 = _10 & 4294967291;
  Base_15->MAC_PACKET_FILTER ={v} _11;

  <bb 5> [local count: 1073741824]:
  return;

}



;; Function Gmac_Ip_SetUnicastHashFilter (Gmac_Ip_SetUnicastHashFilter, funcdef_no=47, decl_uid=6501, cgraph_uid=48, symbol_order=51)

Modification phase of node Gmac_Ip_SetUnicastHashFilter/51
Gmac_Ip_SetUnicastHashFilter (uint8 Instance, boolean Enable)
{
  struct GMAC_Type * Base;
  int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_11(D);
  Base_13 = Gmac_apxBases[_1];
  # DEBUG Base => Base_13
  # DEBUG BEGIN_STMT
  if (Enable_14(D) != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _2 ={v} Base_13->MAC_PACKET_FILTER;
  _3 = _2 & 2147483647;
  Base_13->MAC_PACKET_FILTER ={v} _3;
  # DEBUG BEGIN_STMT
  _4 ={v} Base_13->MAC_PACKET_FILTER;
  _5 = _4 & 4294967294;
  Base_13->MAC_PACKET_FILTER ={v} _5;
  # DEBUG BEGIN_STMT
  _6 ={v} Base_13->MAC_PACKET_FILTER;
  _7 = _6 | 2;
  Base_13->MAC_PACKET_FILTER ={v} _7;
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _8 ={v} Base_13->MAC_PACKET_FILTER;
  _9 = _8 & 4294967293;
  Base_13->MAC_PACKET_FILTER ={v} _9;

  <bb 5> [local count: 1073741824]:
  return;

}



;; Function Gmac_Ip_SetMulticastHashFilter (Gmac_Ip_SetMulticastHashFilter, funcdef_no=48, decl_uid=6504, cgraph_uid=49, symbol_order=52)

Modification phase of node Gmac_Ip_SetMulticastHashFilter/52
Gmac_Ip_SetMulticastHashFilter (uint8 Instance, boolean Enable)
{
  struct GMAC_Type * Base;
  int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_11(D);
  Base_13 = Gmac_apxBases[_1];
  # DEBUG Base => Base_13
  # DEBUG BEGIN_STMT
  if (Enable_14(D) != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _2 ={v} Base_13->MAC_PACKET_FILTER;
  _3 = _2 & 2147483647;
  Base_13->MAC_PACKET_FILTER ={v} _3;
  # DEBUG BEGIN_STMT
  _4 ={v} Base_13->MAC_PACKET_FILTER;
  _5 = _4 & 4294967294;
  Base_13->MAC_PACKET_FILTER ={v} _5;
  # DEBUG BEGIN_STMT
  _6 ={v} Base_13->MAC_PACKET_FILTER;
  _7 = _6 | 4;
  Base_13->MAC_PACKET_FILTER ={v} _7;
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _8 ={v} Base_13->MAC_PACKET_FILTER;
  _9 = _8 & 4294967291;
  Base_13->MAC_PACKET_FILTER ={v} _9;

  <bb 5> [local count: 1073741824]:
  return;

}



;; Function Gmac_Ip_SetHashOrPerfectFilter (Gmac_Ip_SetHashOrPerfectFilter, funcdef_no=49, decl_uid=6507, cgraph_uid=50, symbol_order=53)

Modification phase of node Gmac_Ip_SetHashOrPerfectFilter/53
Gmac_Ip_SetHashOrPerfectFilter (uint8 Instance, boolean Enable)
{
  struct GMAC_Type * Base;
  int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_11(D);
  Base_13 = Gmac_apxBases[_1];
  # DEBUG Base => Base_13
  # DEBUG BEGIN_STMT
  if (Enable_14(D) != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _2 ={v} Base_13->MAC_PACKET_FILTER;
  _3 = _2 & 2147483647;
  Base_13->MAC_PACKET_FILTER ={v} _3;
  # DEBUG BEGIN_STMT
  _4 ={v} Base_13->MAC_PACKET_FILTER;
  _5 = _4 & 4294967294;
  Base_13->MAC_PACKET_FILTER ={v} _5;
  # DEBUG BEGIN_STMT
  _6 ={v} Base_13->MAC_PACKET_FILTER;
  _7 = _6 | 1024;
  Base_13->MAC_PACKET_FILTER ={v} _7;
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _8 ={v} Base_13->MAC_PACKET_FILTER;
  _9 = _8 & 4294966271;
  Base_13->MAC_PACKET_FILTER ={v} _9;

  <bb 5> [local count: 1073741824]:
  return;

}



;; Function Gmac_Ip_AddDstAddrToHashFilter (Gmac_Ip_AddDstAddrToHashFilter, funcdef_no=50, decl_uid=6510, cgraph_uid=51, symbol_order=54)

Modification phase of node Gmac_Ip_AddDstAddrToHashFilter/54
Gmac_Ip_AddDstAddrToHashFilter (uint8 Instance, const uint8 * MacAddr)
{
  uint32 Crc;
  const struct GMAC_Type * Base;
  int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_2(D);
  Base_4 = Gmac_apxBases[_1];
  # DEBUG Base => Base_4
  # DEBUG BEGIN_STMT
  Crc_6 = Gmac_Ip_ComputeCRC32 (MacAddr_5(D), 6);
  # DEBUG Crc => Crc_6
  # DEBUG BEGIN_STMT
  GMAC_AddToHashTable (Base_4, Crc_6);
  return;

}



;; Function Gmac_Ip_RemoveDstAddrFromHashFilter (Gmac_Ip_RemoveDstAddrFromHashFilter, funcdef_no=51, decl_uid=6513, cgraph_uid=52, symbol_order=55)

Modification phase of node Gmac_Ip_RemoveDstAddrFromHashFilter/55
Gmac_Ip_RemoveDstAddrFromHashFilter (uint8 Instance, const uint8 * MacAddr)
{
  uint32 Crc;
  const struct GMAC_Type * Base;
  int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_2(D);
  Base_4 = Gmac_apxBases[_1];
  # DEBUG Base => Base_4
  # DEBUG BEGIN_STMT
  Crc_6 = Gmac_Ip_ComputeCRC32 (MacAddr_5(D), 6);
  # DEBUG Crc => Crc_6
  # DEBUG BEGIN_STMT
  GMAC_RemoveFromHashTable (Base_4, Crc_6);
  return;

}



;; Function Gmac_Ip_SetAddrPerfectFilter (Gmac_Ip_SetAddrPerfectFilter, funcdef_no=52, decl_uid=6519, cgraph_uid=53, symbol_order=56)

Modification phase of node Gmac_Ip_SetAddrPerfectFilter/56
Gmac_Ip_SetAddrPerfectFilter (uint8 Instance, const uint8 * MacAddr, const uint8 Mask, const Gmac_Ip_MacAddrFilterType AddrType, boolean Enable)
{
  struct GMAC_Type * Base;
  uint32 Address;
  int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  unsigned char _12;
  long unsigned int _13;
  long unsigned int _14;
  unsigned char _15;
  long unsigned int _16;
  long unsigned int _17;
  long unsigned int _18;
  long unsigned int _19;
  unsigned char _20;
  long unsigned int _21;
  long unsigned int _22;
  unsigned char _23;
  long unsigned int _24;
  long unsigned int _25;
  long unsigned int _26;
  unsigned char _27;
  long unsigned int _28;
  long unsigned int _29;
  long unsigned int _30;
  unsigned char _31;
  long unsigned int _32;
  long unsigned int _33;
  long unsigned int _34;
  long unsigned int _35;
  long unsigned int _36;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_40(D);
  Base_42 = Gmac_apxBases[_1];
  # DEBUG Base => Base_42
  # DEBUG BEGIN_STMT
  if (Enable_43(D) != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (AddrType_48(D) != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 4> [local count: 268435456]:
  # DEBUG BEGIN_STMT
  _2 ={v} Base_42->MAC_PACKET_FILTER;
  _3 = _2 | 512;
  Base_42->MAC_PACKET_FILTER ={v} _3;
  # DEBUG BEGIN_STMT
  if (AddrType_48(D) == 2)
    goto <bb 5>; [34.00%]
  else
    goto <bb 6>; [66.00%]

  <bb 5> [local count: 91268055]:
  # DEBUG BEGIN_STMT
  _4 ={v} Base_42->MAC_PACKET_FILTER;
  _5 = _4 | 256;
  Base_42->MAC_PACKET_FILTER ={v} _5;

  <bb 6> [local count: 268435456]:
  # DEBUG BEGIN_STMT
  Base_42->MAC_ADDRESS1_HIGH ={v} 1073741824;
  goto <bb 8>; [100.00%]

  <bb 7> [local count: 268435456]:
  # DEBUG BEGIN_STMT
  Base_42->MAC_ADDRESS1_HIGH ={v} 0;

  <bb 8> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _6 ={v} Base_42->MAC_ADDRESS1_HIGH;
  _7 = (long unsigned int) Mask_53(D);
  _8 = _7 << 24;
  _9 = _8 & 1056964608;
  _10 = _6 | _9;
  Base_42->MAC_ADDRESS1_HIGH ={v} _10;
  # DEBUG BEGIN_STMT
  _11 ={v} Base_42->MAC_ADDRESS1_HIGH;
  _12 = MEM[(const uint8 *)MacAddr_55(D) + 5B];
  _13 = (long unsigned int) _12;
  _14 = _13 << 8;
  _15 = MEM[(const uint8 *)MacAddr_55(D) + 4B];
  _16 = (long unsigned int) _15;
  _17 = _14 | _16;
  _18 = _11 | _17;
  _19 = _18 | 2147483648;
  Base_42->MAC_ADDRESS1_HIGH ={v} _19;
  # DEBUG BEGIN_STMT
  _20 = MEM[(const uint8 *)MacAddr_55(D) + 3B];
  _21 = (long unsigned int) _20;
  _22 = _21 << 24;
  _23 = MEM[(const uint8 *)MacAddr_55(D) + 2B];
  _24 = (long unsigned int) _23;
  _25 = _24 << 16;
  _26 = _22 | _25;
  _27 = MEM[(const uint8 *)MacAddr_55(D) + 1B];
  _28 = (long unsigned int) _27;
  _29 = _28 << 8;
  _30 = _26 | _29;
  _31 = *MacAddr_55(D);
  _32 = (long unsigned int) _31;
  Address_57 = _30 | _32;
  # DEBUG Address => Address_57
  # DEBUG BEGIN_STMT
  Base_42->MAC_ADDRESS1_LOW ={v} Address_57;
  goto <bb 10>; [100.00%]

  <bb 9> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  Base_42->MAC_ADDRESS1_HIGH ={v} 65535;
  # DEBUG BEGIN_STMT
  Base_42->MAC_ADDRESS1_LOW ={v} 4294967295;
  # DEBUG BEGIN_STMT
  _33 ={v} Base_42->MAC_PACKET_FILTER;
  _34 = _33 & 4294966783;
  Base_42->MAC_PACKET_FILTER ={v} _34;
  # DEBUG BEGIN_STMT
  _35 ={v} Base_42->MAC_PACKET_FILTER;
  _36 = _35 & 4294967039;
  Base_42->MAC_PACKET_FILTER ={v} _36;

  <bb 10> [local count: 1073741824]:
  return;

}



;; Function Gmac_Ip_SetArpOffloading (Gmac_Ip_SetArpOffloading, funcdef_no=53, decl_uid=6523, cgraph_uid=54, symbol_order=57)

Modification phase of node Gmac_Ip_SetArpOffloading/57
Gmac_Ip_SetArpOffloading (uint8 Instance, const uint8 * DstAddr, boolean Enable)
{
  uint32 Address;
  struct GMAC_Type * Base;
  int _1;
  long unsigned int _2;
  long unsigned int _3;
  unsigned char _4;
  long unsigned int _5;
  long unsigned int _6;
  unsigned char _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  unsigned char _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  unsigned char _15;
  long unsigned int _16;
  long unsigned int _17;
  long unsigned int _18;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_20(D);
  Base_22 = Gmac_apxBases[_1];
  # DEBUG Base => Base_22
  # DEBUG BEGIN_STMT
  if (Enable_23(D) != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 ={v} Base_22->MAC_CONFIGURATION;
  _3 = _2 | 2147483648;
  Base_22->MAC_CONFIGURATION ={v} _3;
  # DEBUG BEGIN_STMT
  _4 = *DstAddr_26(D);
  _5 = (long unsigned int) _4;
  _6 = _5 << 24;
  _7 = MEM[(const uint8 *)DstAddr_26(D) + 1B];
  _8 = (long unsigned int) _7;
  _9 = _8 << 16;
  _10 = _6 | _9;
  _11 = MEM[(const uint8 *)DstAddr_26(D) + 2B];
  _12 = (long unsigned int) _11;
  _13 = _12 << 8;
  _14 = _10 | _13;
  _15 = MEM[(const uint8 *)DstAddr_26(D) + 3B];
  _16 = (long unsigned int) _15;
  Address_27 = _14 | _16;
  # DEBUG Address => Address_27
  # DEBUG BEGIN_STMT
  Base_22->MAC_ARP_ADDRESS ={v} Address_27;
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _17 ={v} Base_22->MAC_CONFIGURATION;
  _18 = _17 & 2147483647;
  Base_22->MAC_CONFIGURATION ={v} _18;

  <bb 5> [local count: 1073741824]:
  return;

}



;; Function Gmac_Ip_EnableVlan (Gmac_Ip_EnableVlan, funcdef_no=54, decl_uid=6526, cgraph_uid=55, symbol_order=58)

Modification phase of node Gmac_Ip_EnableVlan/58
Gmac_Ip_EnableVlan (uint8 Instance, const struct Gmac_Ip_VlanConfigType * VlanConfig)
{
  struct GMAC_Type * Base;
  int _1;
  _Bool _2;
  _Bool _3;
  long unsigned int _4;
  <unnamed type> _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  <unnamed type> _10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int _15;
  <unnamed type> _16;
  long unsigned int _17;
  long unsigned int _18;
  long unsigned int _19;
  long unsigned int _20;
  long unsigned int _21;
  <unnamed type> _22;
  long unsigned int _23;
  long unsigned int _24;
  long unsigned int _25;
  long unsigned int iftmp.39_26;
  long unsigned int iftmp.40_27;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_29(D);
  Base_31 = Gmac_apxBases[_1];
  # DEBUG Base => Base_31
  # DEBUG BEGIN_STMT
  _2 = VlanConfig_32(D)->EnDoubleVlan;
  if (_2 != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 3>; [50.00%]

  <bb 3> [local count: 536870913]:

  <bb 4> [local count: 1073741824]:
  # iftmp.39_26 = PHI <67108864(2), 0(3)>
  _3 = VlanConfig_32(D)->EnSvlan;
  if (_3 != 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 5> [local count: 536870913]:

  <bb 6> [local count: 1073741824]:
  # iftmp.40_27 = PHI <262144(4), 0(5)>
  _4 = iftmp.39_26 | iftmp.40_27;
  _5 = VlanConfig_32(D)->InnerVlanStrip;
  _6 = (long unsigned int) _5;
  _7 = _6 << 28;
  _8 = _7 & 805306368;
  _9 = _4 | _8;
  _10 = VlanConfig_32(D)->OuterVlanStrip;
  _11 = (long unsigned int) _10;
  _12 = _11 << 21;
  _13 = _12 & 6291456;
  _14 = _9 | _13;
  _15 = _14 | 2164260864;
  Base_31->MAC_VLAN_TAG_CTRL ={v} _15;
  # DEBUG BEGIN_STMT
  _16 = VlanConfig_32(D)->OuterVlanIns;
  _17 = (long unsigned int) _16;
  _18 = _17 << 16;
  _19 = _18 | 262144;
  Base_31->MAC_VLAN_INCL ={v} _19;
  # DEBUG BEGIN_STMT
  if (_16 == 2)
    goto <bb 7>; [34.00%]
  else
    goto <bb 8>; [66.00%]

  <bb 7> [local count: 365072220]:
  # DEBUG BEGIN_STMT
  _20 ={v} Base_31->MAC_VLAN_INCL;
  _21 = _20 | 2097152;
  Base_31->MAC_VLAN_INCL ={v} _21;

  <bb 8> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _22 = VlanConfig_32(D)->InnerVlanIns;
  _23 = (long unsigned int) _22;
  _24 = _23 << 16;
  _25 = _24 | 262144;
  Base_31->MAC_INNER_VLAN_INCL ={v} _25;
  return;

}



;; Function Gmac_Ip_SetTxOuterVlanTagForInsertion (Gmac_Ip_SetTxOuterVlanTagForInsertion, funcdef_no=55, decl_uid=6531, cgraph_uid=56, symbol_order=59)

Modification phase of node Gmac_Ip_SetTxOuterVlanTagForInsertion/59
Gmac_Ip_SetTxOuterVlanTagForInsertion (uint8 Instance, uint8 Ring, Gmac_Ip_VlanType VlanType, uint16 VlanTag)
{
  uint32 TimeoutTicks;
  uint32 ElapsedTime;
  uint32 StartTime;
  Gmac_Ip_StatusType Status;
  struct GMAC_Type * Base;
  int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  signed int _6;
  long unsigned int _7;
  long unsigned int _8;
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
  long unsigned int _24;
  long unsigned int _25;
  signed int _26;
  long unsigned int TimeoutTicks.41_27;
  _Bool _28;

  <bb 2> [local count: 413413328]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG Status => 3
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_32(D);
  Base_34 = Gmac_apxBases[_1];
  # DEBUG Base => Base_34
  # DEBUG BEGIN_STMT
  _2 ={v} Base_34->MAC_VLAN_INCL;
  _3 = _2 >> 16;
  _4 = _3 & 3;
  if (_4 == 2)
    goto <bb 3>; [48.89%]
  else
    goto <bb 7>; [51.11%]

  <bb 3> [local count: 202117776]:
  # DEBUG BEGIN_STMT
  _5 ={v} Base_34->MAC_VLAN_INCL;
  _6 = (signed int) _5;
  if (_6 < 0)
    goto <bb 7>; [43.17%]
  else
    goto <bb 4>; [56.83%]

  <bb 4> [local count: 114863532]:
  # DEBUG BEGIN_STMT
  _7 ={v} Base_34->MAC_VLAN_INCL;
  _8 = _7 & 4278190079;
  Base_34->MAC_VLAN_INCL ={v} _8;
  # DEBUG BEGIN_STMT
  _9 ={v} Base_34->MAC_VLAN_INCL;
  _10 = (long unsigned int) Ring_36(D);
  _11 = _10 << 24;
  _12 = _9 | _11;
  Base_34->MAC_VLAN_INCL ={v} _12;
  # DEBUG BEGIN_STMT
  _13 ={v} Base_34->MAC_VLAN_INCL;
  _14 = _13 | 1073741824;
  Base_34->MAC_VLAN_INCL ={v} _14;
  # DEBUG BEGIN_STMT
  _15 ={v} Base_34->MAC_VLAN_INCL;
  _16 = _15 & 4294377472;
  Base_34->MAC_VLAN_INCL ={v} _16;
  # DEBUG BEGIN_STMT
  _17 ={v} Base_34->MAC_VLAN_INCL;
  _18 = (long unsigned int) VlanType_40(D);
  _19 = _18 << 19;
  _20 = (long unsigned int) VlanTag_41(D);
  _21 = _19 | _20;
  _22 = _17 | _21;
  Base_34->MAC_VLAN_INCL ={v} _22;
  # DEBUG BEGIN_STMT
  _23 ={v} Base_34->MAC_VLAN_INCL;
  _24 = _23 & 3221225471;
  Base_34->MAC_VLAN_INCL ={v} _24;
  # DEBUG BEGIN_STMT
  GMAC_StartTimeOut (&StartTime, &ElapsedTime, &TimeoutTicks, 1000);

  <bb 5> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _25 ={v} Base_34->MAC_VLAN_INCL;
  _26 = (signed int) _25;
  if (_26 >= 0)
    goto <bb 7>; [5.50%]
  else
    goto <bb 6>; [94.50%]

  <bb 6> [local count: 1014686024]:
  # DEBUG BEGIN_STMT
  TimeoutTicks.41_27 = TimeoutTicks;
  _28 = GMAC_TimeoutExpired (&StartTime, &ElapsedTime, TimeoutTicks.41_27);
  if (_28 != 0)
    goto <bb 7>; [5.50%]
  else
    goto <bb 8>; [94.50%]

  <bb 8> [local count: 958878292]:
  goto <bb 5>; [100.00%]

  <bb 7> [local count: 413413327]:
  # Status_29 = PHI <0(5), 4(2), 2(3), 3(6)>
  # DEBUG Status => Status_29
  # DEBUG BEGIN_STMT
  StartTime ={v} {CLOBBER};
  ElapsedTime ={v} {CLOBBER};
  TimeoutTicks ={v} {CLOBBER};
  return Status_29;

}



;; Function Gmac_Ip_SetTxOuterVlanTagForReplacement (Gmac_Ip_SetTxOuterVlanTagForReplacement, funcdef_no=56, decl_uid=6535, cgraph_uid=57, symbol_order=60)

Modification phase of node Gmac_Ip_SetTxOuterVlanTagForReplacement/60
Gmac_Ip_SetTxOuterVlanTagForReplacement (uint8 Instance, Gmac_Ip_VlanType VlanType, uint16 VlanTag)
{
  Gmac_Ip_StatusType Status;
  struct GMAC_Type * Base;
  int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG Status => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_15(D);
  Base_17 = Gmac_apxBases[_1];
  # DEBUG Base => Base_17
  # DEBUG BEGIN_STMT
  _2 ={v} Base_17->MAC_VLAN_INCL;
  _3 = _2 >> 16;
  _4 = _3 & 3;
  if (_4 == 3)
    goto <bb 3>; [48.89%]
  else
    goto <bb 4>; [51.11%]

  <bb 3> [local count: 524952378]:
  # DEBUG BEGIN_STMT
  _5 ={v} Base_17->MAC_VLAN_INCL;
  _6 = _5 & 4294377472;
  Base_17->MAC_VLAN_INCL ={v} _6;
  # DEBUG BEGIN_STMT
  _7 ={v} Base_17->MAC_VLAN_INCL;
  _8 = (long unsigned int) VlanType_19(D);
  _9 = _8 << 19;
  _10 = (long unsigned int) VlanTag_20(D);
  _11 = _9 | _10;
  _12 = _7 | _11;
  Base_17->MAC_VLAN_INCL ={v} _12;

  <bb 4> [local count: 1073741824]:
  # Status_13 = PHI <0(3), 4(2)>
  # DEBUG Status => Status_13
  # DEBUG BEGIN_STMT
  return Status_13;

}



;; Function Gmac_Ip_SetTxInnerVlanTag (Gmac_Ip_SetTxInnerVlanTag, funcdef_no=57, decl_uid=6539, cgraph_uid=58, symbol_order=61)

Modification phase of node Gmac_Ip_SetTxInnerVlanTag/61
Gmac_Ip_SetTxInnerVlanTag (uint8 Instance, Gmac_Ip_VlanType VlanType, uint16 VlanTag)
{
  struct GMAC_Type * Base;
  int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_10(D);
  Base_12 = Gmac_apxBases[_1];
  # DEBUG Base => Base_12
  # DEBUG BEGIN_STMT
  _2 ={v} Base_12->MAC_INNER_VLAN_INCL;
  _3 = _2 & 4294377472;
  Base_12->MAC_INNER_VLAN_INCL ={v} _3;
  # DEBUG BEGIN_STMT
  _4 ={v} Base_12->MAC_INNER_VLAN_INCL;
  _5 = (long unsigned int) VlanType_14(D);
  _6 = _5 << 19;
  _7 = (long unsigned int) VlanTag_15(D);
  _8 = _6 | _7;
  _9 = _4 | _8;
  Base_12->MAC_INNER_VLAN_INCL ={v} _9;
  return;

}



;; Function Gmac_Ip_AddVlanTagToHashTable (Gmac_Ip_AddVlanTagToHashTable, funcdef_no=58, decl_uid=6542, cgraph_uid=59, symbol_order=62)

Modification phase of node Gmac_Ip_AddVlanTagToHashTable/62
Gmac_Ip_AddVlanTagToHashTable (uint8 Instance, uint16 VlanTag)
{
  uint32 tag32;
  uint32 crc;
  struct GMAC_Type * Base;
  int _1;
  long unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_3(D);
  Base_5 = Gmac_apxBases[_1];
  # DEBUG Base => Base_5
  # DEBUG BEGIN_STMT
  _2 = (long unsigned int) VlanTag_6(D);
  tag32 = _2;
  # DEBUG BEGIN_STMT
  # DEBUG tag => &tag32
  # DEBUG BEGIN_STMT
  crc_8 = Gmac_Ip_ComputeCRC32 (&tag32, 2);
  # DEBUG crc => crc_8
  # DEBUG BEGIN_STMT
  GMAC_AddVlanToHashTable (Base_5, crc_8);
  tag32 ={v} {CLOBBER};
  return;

}



;; Function Gmac_Ip_RemoveVlanTagFromHashTable (Gmac_Ip_RemoveVlanTagFromHashTable, funcdef_no=59, decl_uid=6545, cgraph_uid=60, symbol_order=63)

Modification phase of node Gmac_Ip_RemoveVlanTagFromHashTable/63
Gmac_Ip_RemoveVlanTagFromHashTable (uint8 Instance, uint16 VlanTag)
{
  uint32 Tag32;
  uint32 Crc;
  struct GMAC_Type * Base;
  int _1;
  long unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_3(D);
  Base_5 = Gmac_apxBases[_1];
  # DEBUG Base => Base_5
  # DEBUG BEGIN_STMT
  _2 = (long unsigned int) VlanTag_6(D);
  Tag32 = _2;
  # DEBUG BEGIN_STMT
  # DEBUG Tag => &Tag32
  # DEBUG BEGIN_STMT
  Crc_8 = Gmac_Ip_ComputeCRC32 (&Tag32, 2);
  # DEBUG Crc => Crc_8
  # DEBUG BEGIN_STMT
  GMAC_RemoveVlanFromHashTable (Base_5, Crc_8);
  Tag32 ={v} {CLOBBER};
  return;

}



;; Function Gmac_Ip_InitSysTime (Gmac_Ip_InitSysTime, funcdef_no=60, decl_uid=6548, cgraph_uid=61, symbol_order=64)

Modification phase of node Gmac_Ip_InitSysTime/64
Gmac_Ip_InitSysTime (const uint8 Instance, const struct Gmac_Ip_SysTimeConfigType * SysTimeConfig)
{
  Gmac_Ip_StatusType Status;
  struct GMAC_Type * Base;
  uint32 TimestampADDENDValue;
  uint32 TimeoutTicks;
  uint32 ElapsedTime;
  uint32 StartTime;
  int _1;
  unsigned char _2;
  long unsigned int _3;
  long unsigned int _4;
  unsigned char _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  double _9;
  double _10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int _15;
  long unsigned int _16;
  long unsigned int TimeoutTicks.42_17;
  _Bool _18;
  long unsigned int _19;
  long unsigned int _20;
  struct Gmac_Ip_TimestampType * _21;
  short unsigned int _22;
  long unsigned int _23;
  long unsigned int _24;
  long unsigned int _25;
  long unsigned int _26;
  long unsigned int _27;
  long unsigned int _28;

  <bb 2> [local count: 114863532]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_32(D);
  Base_34 = Gmac_apxBases[_1];
  # DEBUG Base => Base_34
  # DEBUG BEGIN_STMT
  # DEBUG Status => 3
  # DEBUG BEGIN_STMT
  _2 = SysTimeConfig_35(D)->SubSecondInc;
  _3 = (long unsigned int) _2;
  _4 = _3 << 16;
  _5 = SysTimeConfig_35(D)->SubNanoSecondsInc;
  _6 = (long unsigned int) _5;
  _7 = _6 << 8;
  _8 = _4 | _7;
  Base_34->MAC_SUB_SECOND_INCREMENT ={v} _8;
  # DEBUG BEGIN_STMT
  _9 = SysTimeConfig_35(D)->MultiplyRatioCompensation;
  _10 = 4.294967296e+9 / _9;
  TimestampADDENDValue_37 = (uint32) _10;
  # DEBUG TimestampADDENDValue => TimestampADDENDValue_37
  # DEBUG BEGIN_STMT
  _11 ={v} Base_34->MAC_TIMESTAMP_ADDEND;
  _12 = _11 | TimestampADDENDValue_37;
  Base_34->MAC_TIMESTAMP_ADDEND ={v} _12;
  # DEBUG BEGIN_STMT
  _13 ={v} Base_34->MAC_TIMESTAMP_CONTROL;
  _14 = _13 | 32;
  Base_34->MAC_TIMESTAMP_CONTROL ={v} _14;
  # DEBUG BEGIN_STMT
  GMAC_StartTimeOut (&StartTime, &ElapsedTime, &TimeoutTicks, 1000);

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _15 ={v} Base_34->MAC_TIMESTAMP_CONTROL;
  _16 = _15 & 32;
  if (_16 == 0)
    goto <bb 5>; [5.50%]
  else
    goto <bb 4>; [94.50%]

  <bb 4> [local count: 1014686025]:
  # DEBUG BEGIN_STMT
  TimeoutTicks.42_17 = TimeoutTicks;
  _18 = GMAC_TimeoutExpired (&StartTime, &ElapsedTime, TimeoutTicks.42_17);
  if (_18 != 0)
    goto <bb 5>; [5.50%]
  else
    goto <bb 6>; [94.50%]

  <bb 6> [local count: 958878293]:
  goto <bb 3>; [100.00%]

  <bb 5> [local count: 114863532]:
  # Status_29 = PHI <0(3), 3(4)>
  # DEBUG Status => Status_29
  # DEBUG BEGIN_STMT
  Base_34->MAC_TIMESTAMP_CONTROL ={v} 769;
  # DEBUG BEGIN_STMT
  _19 ={v} Base_34->MAC_TIMESTAMP_CONTROL;
  _20 = _19 | 2;
  Base_34->MAC_TIMESTAMP_CONTROL ={v} _20;
  # DEBUG BEGIN_STMT
  _21 = SysTimeConfig_35(D)->InitialTimestamp;
  _22 = _21->secondsHi;
  _23 = (long unsigned int) _22;
  Base_34->MAC_SYSTEM_TIME_HIGHER_WORD_SECONDS ={v} _23;
  # DEBUG BEGIN_STMT
  _24 = _21->seconds;
  Base_34->MAC_SYSTEM_TIME_SECONDS_UPDATE ={v} _24;
  # DEBUG BEGIN_STMT
  _25 = _21->nanoseconds;
  _26 = _25 & 2147483647;
  Base_34->MAC_SYSTEM_TIME_NANOSECONDS_UPDATE ={v} _26;
  # DEBUG BEGIN_STMT
  _27 ={v} Base_34->MAC_TIMESTAMP_CONTROL;
  _28 = _27 | 4;
  Base_34->MAC_TIMESTAMP_CONTROL ={v} _28;
  # DEBUG BEGIN_STMT
  StartTime ={v} {CLOBBER};
  ElapsedTime ={v} {CLOBBER};
  TimeoutTicks ={v} {CLOBBER};
  return Status_29;

}



;; Function Gmac_Ip_SetSysTimeCorr (Gmac_Ip_SetSysTimeCorr, funcdef_no=61, decl_uid=6553, cgraph_uid=62, symbol_order=65)

Modification phase of node Gmac_Ip_SetSysTimeCorr/65
Gmac_Ip_SetSysTimeCorr (uint8 Instance, Gmac_Ip_SysTimeCorrOffsetType Offset, uint32 SecondsUpdate, uint32 NanoSecondsUpdate)
{
  uint32 TimeoutTicks;
  uint32 ElapsedTime;
  uint32 StartTime;
  Gmac_Ip_StatusType Status;
  uint32 Nanoseconds;
  uint32 seconds;
  struct GMAC_Type * Base;
  int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int TimeoutTicks.43_10;
  _Bool _11;

  <bb 2> [local count: 114863532]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG Status => 3
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_17(D);
  Base_19 = Gmac_apxBases[_1];
  # DEBUG Base => Base_19
  # DEBUG BEGIN_STMT
  if (Offset_20(D) != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 57431766]:
  # DEBUG BEGIN_STMT
  seconds_23 = -SecondsUpdate_21(D);
  # DEBUG seconds => seconds_23
  # DEBUG BEGIN_STMT
  Nanoseconds_24 = 1000000000 - NanoSecondsUpdate_22(D);
  # DEBUG Nanoseconds => Nanoseconds_24

  <bb 4> [local count: 114863532]:
  # seconds_12 = PHI <seconds_23(3), SecondsUpdate_21(D)(2)>
  # Nanoseconds_13 = PHI <Nanoseconds_24(3), NanoSecondsUpdate_22(D)(2)>
  # DEBUG Nanoseconds => Nanoseconds_13
  # DEBUG seconds => seconds_12
  # DEBUG BEGIN_STMT
  _2 = (long unsigned int) Offset_20(D);
  _3 = _2 << 31;
  _4 = Nanoseconds_13 & 2147483647;
  _5 = _3 | _4;
  Base_19->MAC_SYSTEM_TIME_NANOSECONDS_UPDATE ={v} _5;
  # DEBUG BEGIN_STMT
  Base_19->MAC_SYSTEM_TIME_SECONDS_UPDATE ={v} seconds_12;
  # DEBUG BEGIN_STMT
  _6 ={v} Base_19->MAC_TIMESTAMP_CONTROL;
  _7 = _6 | 8;
  Base_19->MAC_TIMESTAMP_CONTROL ={v} _7;
  # DEBUG BEGIN_STMT
  GMAC_StartTimeOut (&StartTime, &ElapsedTime, &TimeoutTicks, 1000);

  <bb 5> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _8 ={v} Base_19->MAC_TIMESTAMP_CONTROL;
  _9 = _8 & 8;
  if (_9 == 0)
    goto <bb 7>; [5.50%]
  else
    goto <bb 6>; [94.50%]

  <bb 6> [local count: 1014686025]:
  # DEBUG BEGIN_STMT
  TimeoutTicks.43_10 = TimeoutTicks;
  _11 = GMAC_TimeoutExpired (&StartTime, &ElapsedTime, TimeoutTicks.43_10);
  if (_11 != 0)
    goto <bb 7>; [5.50%]
  else
    goto <bb 8>; [94.50%]

  <bb 8> [local count: 958878293]:
  goto <bb 5>; [100.00%]

  <bb 7> [local count: 114863532]:
  # Status_14 = PHI <0(5), 3(6)>
  # DEBUG Status => Status_14
  # DEBUG BEGIN_STMT
  StartTime ={v} {CLOBBER};
  ElapsedTime ={v} {CLOBBER};
  TimeoutTicks ={v} {CLOBBER};
  return Status_14;

}



;; Function Gmac_Ip_SetRateRatioCorr (Gmac_Ip_SetRateRatioCorr, funcdef_no=62, decl_uid=6556, cgraph_uid=63, symbol_order=66)

Modification phase of node Gmac_Ip_SetRateRatioCorr/66
Gmac_Ip_SetRateRatioCorr (uint8 Instance, float64 RateRatio)
{
  uint32 TimeoutTicks;
  uint32 ElapsedTime;
  uint32 StartTime;
  Gmac_Ip_StatusType Status;
  struct GMAC_Type * Base;
  int _1;
  double _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int TimeoutTicks.44_8;
  _Bool _9;
  long unsigned int _10;
  long unsigned int _11;

  <bb 2> [local count: 114863532]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG Status => 3
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_15(D);
  Base_17 = Gmac_apxBases[_1];
  # DEBUG Base => Base_17
  # DEBUG BEGIN_STMT
  _2 = 4.294967296e+9 / RateRatio_18(D);
  _3 = (long unsigned int) _2;
  Base_17->MAC_TIMESTAMP_ADDEND ={v} _3;
  # DEBUG BEGIN_STMT
  _4 ={v} Base_17->MAC_TIMESTAMP_CONTROL;
  _5 = _4 | 32;
  Base_17->MAC_TIMESTAMP_CONTROL ={v} _5;
  # DEBUG BEGIN_STMT
  GMAC_StartTimeOut (&StartTime, &ElapsedTime, &TimeoutTicks, 1000);

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _6 ={v} Base_17->MAC_TIMESTAMP_CONTROL;
  _7 = _6 & 32;
  if (_7 == 0)
    goto <bb 5>; [5.50%]
  else
    goto <bb 4>; [94.50%]

  <bb 4> [local count: 1014686025]:
  # DEBUG BEGIN_STMT
  TimeoutTicks.44_8 = TimeoutTicks;
  _9 = GMAC_TimeoutExpired (&StartTime, &ElapsedTime, TimeoutTicks.44_8);
  if (_9 != 0)
    goto <bb 5>; [5.50%]
  else
    goto <bb 6>; [94.50%]

  <bb 6> [local count: 958878293]:
  goto <bb 3>; [100.00%]

  <bb 5> [local count: 114863532]:
  # Status_12 = PHI <0(3), 3(4)>
  # DEBUG Status => Status_12
  # DEBUG BEGIN_STMT
  _10 ={v} Base_17->MAC_TIMESTAMP_CONTROL;
  _11 = _10 | 2;
  Base_17->MAC_TIMESTAMP_CONTROL ={v} _11;
  # DEBUG BEGIN_STMT
  StartTime ={v} {CLOBBER};
  ElapsedTime ={v} {CLOBBER};
  TimeoutTicks ={v} {CLOBBER};
  return Status_12;

}



;; Function Gmac_Ip_GetSysTime (Gmac_Ip_GetSysTime, funcdef_no=63, decl_uid=6559, cgraph_uid=64, symbol_order=67)

Modification phase of node Gmac_Ip_GetSysTime/67
Gmac_Ip_GetSysTime (uint8 Instance, struct Gmac_Ip_TimestampType * Timestamp)
{
  const struct GMAC_Type * Base;
  int _1;
  long unsigned int _2;
  short unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_6(D);
  Base_8 = Gmac_apxBases[_1];
  # DEBUG Base => Base_8
  # DEBUG BEGIN_STMT
  _2 ={v} Base_8->MAC_SYSTEM_TIME_HIGHER_WORD_SECONDS;
  _3 = (short unsigned int) _2;
  Timestamp_9(D)->secondsHi = _3;
  # DEBUG BEGIN_STMT
  _4 ={v} Base_8->MAC_SYSTEM_TIME_SECONDS;
  Timestamp_9(D)->seconds = _4;
  # DEBUG BEGIN_STMT
  _5 ={v} Base_8->MAC_SYSTEM_TIME_NANOSECONDS;
  Timestamp_9(D)->nanoseconds = _5;
  return;

}



;; Function Gmac_Ip_SetTxSchedAlgo (Gmac_Ip_SetTxSchedAlgo, funcdef_no=64, decl_uid=6562, cgraph_uid=65, symbol_order=68)

Modification phase of node Gmac_Ip_SetTxSchedAlgo/68
Gmac_Ip_SetTxSchedAlgo (uint8 Instance, Gmac_Ip_TxSchedAlgoType SchedAlgo)
{
  struct GMAC_Type * Base;
  int _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_2(D);
  Base_4 = Gmac_apxBases[_1];
  # DEBUG Base => Base_4
  # DEBUG BEGIN_STMT
  GMAC_SetSchedAlg (Base_4, SchedAlgo_5(D));
  return;

}



;; Function Gmac_Ip_SetTxRingWeight (Gmac_Ip_SetTxRingWeight, funcdef_no=65, decl_uid=6566, cgraph_uid=66, symbol_order=69)

Modification phase of node Gmac_Ip_SetTxRingWeight/69
Gmac_Ip_SetTxRingWeight (uint8 Instance, uint8 Ring, uint32 Weight)
{
  int _1;
  struct Gmac_Ip_StateType * _2;
  short unsigned int _3;
  int _4;
  struct Gmac_Ip_QueueType * _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_7(D);
  _2 = Gmac_apxState[_1];
  _3 = _2->TxRingCount;
  if (_3 > 1)
    goto <bb 3>; [41.48%]
  else
    goto <bb 4>; [58.52%]

  <bb 3> [local count: 445388109]:
  # DEBUG BEGIN_STMT
  _4 = (int) Ring_9(D);
  _5 = Gmac_apxQueueBases[_1][_4];
  GMAC_SetTxQueueQuantumWeight (_5, Weight_10(D));

  <bb 4> [local count: 1073741824]:
  return;

}



;; Function Gmac_Ip_EnableTxStoreAndForward (Gmac_Ip_EnableTxStoreAndForward, funcdef_no=66, decl_uid=6569, cgraph_uid=67, symbol_order=70)

Modification phase of node Gmac_Ip_EnableTxStoreAndForward/70
Gmac_Ip_EnableTxStoreAndForward (uint8 Instance, uint8 Ring)
{
  int _1;
  int _2;
  struct Gmac_Ip_QueueType * _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_4(D);
  _2 = (int) Ring_5(D);
  _3 = Gmac_apxQueueBases[_1][_2];
  GMAC_SetTxStoreAndForward (_3);
  return;

}



;; Function Gmac_Ip_SetTxThreshold (Gmac_Ip_SetTxThreshold, funcdef_no=67, decl_uid=6573, cgraph_uid=68, symbol_order=71)

Modification phase of node Gmac_Ip_SetTxThreshold/71
Gmac_Ip_SetTxThreshold (uint8 Instance, uint8 Ring, Gmac_Ip_TxThresholdType ThresholdValue)
{
  int _1;
  int _2;
  struct Gmac_Ip_QueueType * _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_4(D);
  _2 = (int) Ring_5(D);
  _3 = Gmac_apxQueueBases[_1][_2];
  GMAC_SetTxThreshold (_3, ThresholdValue_7(D));
  return;

}


