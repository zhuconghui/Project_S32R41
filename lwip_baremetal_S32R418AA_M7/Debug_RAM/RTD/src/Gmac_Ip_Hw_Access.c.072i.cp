
IPA constant propagation start:
Determining dynamic type for call: GMAC_StartTimeOut (&StartTime, &ElapsedTime, &TimeoutTicks, TimeoutUs_48(D));
  Starting walk at: GMAC_StartTimeOut (&StartTime, &ElapsedTime, &TimeoutTicks, TimeoutUs_48(D));
  instance pointer: &StartTime  Outer instance pointer: StartTime offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: GMAC_StartTimeOut (&StartTime, &ElapsedTime, &TimeoutTicks, TimeoutUs_48(D));
  Starting walk at: GMAC_StartTimeOut (&StartTime, &ElapsedTime, &TimeoutTicks, TimeoutUs_48(D));
  instance pointer: &ElapsedTime  Outer instance pointer: ElapsedTime offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: GMAC_StartTimeOut (&StartTime, &ElapsedTime, &TimeoutTicks, TimeoutUs_48(D));
  Starting walk at: GMAC_StartTimeOut (&StartTime, &ElapsedTime, &TimeoutTicks, TimeoutUs_48(D));
  instance pointer: &TimeoutTicks  Outer instance pointer: TimeoutTicks offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _32 = GMAC_TimeoutExpired (&StartTime, &ElapsedTime, TimeoutTicks.3_31);
  Starting walk at: _32 = GMAC_TimeoutExpired (&StartTime, &ElapsedTime, TimeoutTicks.3_31);
  instance pointer: &StartTime  Outer instance pointer: StartTime offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:GMAC_StartTimeOut (&StartTime, &ElapsedTime, &TimeoutTicks, TimeoutUs_48(D));
  Function call may change dynamic type:_32 = GMAC_TimeoutExpired (&StartTime, &ElapsedTime, TimeoutTicks.3_31);
Determining dynamic type for call: _32 = GMAC_TimeoutExpired (&StartTime, &ElapsedTime, TimeoutTicks.3_31);
  Starting walk at: _32 = GMAC_TimeoutExpired (&StartTime, &ElapsedTime, TimeoutTicks.3_31);
  instance pointer: &ElapsedTime  Outer instance pointer: ElapsedTime offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:GMAC_StartTimeOut (&StartTime, &ElapsedTime, &TimeoutTicks, TimeoutUs_48(D));
  Function call may change dynamic type:_32 = GMAC_TimeoutExpired (&StartTime, &ElapsedTime, TimeoutTicks.3_31);

IPA structures before propagation:

Jump functions:
  Jump functions of caller  OsIf_GetElapsed/30:
  Jump functions of caller  OsIf_MicrosToTicks/29:
  Jump functions of caller  OsIf_GetCounter/28:
  Jump functions of caller  GMAC_SetRxQueuesDmaChMap/27:
  Jump functions of caller  GMAC_SetRxQueueOperationMode/26:
  Jump functions of caller  GMAC_EnableRxQueue/25:
  Jump functions of caller  GMAC_SetTxThreshold/24:
  Jump functions of caller  GMAC_SetTxStoreAndForward/23:
  Jump functions of caller  GMAC_SetTxQueueOperationMode/22:
  Jump functions of caller  GMAC_SetTxQueueCreditBasedShaper/21:
  Jump functions of caller  GMAC_SetTxQueueQuantumWeight/20:
  Jump functions of caller  GMAC_SetSchedAlg/19:
  Jump functions of caller  GMAC_SetSpeed/18:
  Jump functions of caller  GMAC_SetPowerState/17:
  Jump functions of caller  GMAC_GetPowerState/16:
  Jump functions of caller  GMAC_RemoveVlanFromHashTable/15:
    callsite  GMAC_RemoveVlanFromHashTable/15 -> REV_BITS_32/4 : 
       param 0: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  GMAC_AddVlanToHashTable/14:
    callsite  GMAC_AddVlanToHashTable/14 -> REV_BITS_32/4 : 
       param 0: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  GMAC_RemoveFromHashTable/13:
    callsite  GMAC_RemoveFromHashTable/13 -> REV_BITS_32/4 : 
       param 0: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  GMAC_AddToHashTable/12:
    callsite  GMAC_AddToHashTable/12 -> REV_BITS_32/4 : 
       param 0: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  GMAC_TxIRQHandler/11:
    indirect simple callsite, calling param -1, offset 0, for stmt _6 (Instance_8(D), Channel_9(D));
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  GMAC_RxIRQHandler/10:
    indirect simple callsite, calling param -1, offset 0, for stmt _6 (Instance_8(D), Channel_9(D));
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  GMAC_CommonIRQHandler/9:
    callsite  GMAC_CommonIRQHandler/9 -> GMAC_MACIRQHandler/5 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
    indirect simple callsite, calling param -1, offset 0, for stmt _17 (Instance_31(D), _18);
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
    indirect simple callsite, calling param -1, offset 0, for stmt _11 (Instance_31(D), _12);
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  GMAC_WriteManagementFrame/8:
    callsite  GMAC_WriteManagementFrame/8 -> GMAC_TimeoutExpired/7 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  GMAC_WriteManagementFrame/8 -> GMAC_StartTimeOut/6 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 3: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  GMAC_TimeoutExpired/7:
  Jump functions of caller  GMAC_StartTimeOut/6:
  Jump functions of caller  GMAC_MACIRQHandler/5:
    indirect simple callsite, calling param -1, offset 0, for stmt _5 (Instance_11(D));
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  REV_BITS_32/4:

 Propagating constants:

Not considering GMAC_SetRxQueuesDmaChMap for cloning; -fipa-cp-clone disabled.
Not considering GMAC_SetRxQueueOperationMode for cloning; -fipa-cp-clone disabled.
Not considering GMAC_EnableRxQueue for cloning; -fipa-cp-clone disabled.
Not considering GMAC_SetTxThreshold for cloning; -fipa-cp-clone disabled.
Not considering GMAC_SetTxStoreAndForward for cloning; -fipa-cp-clone disabled.
Not considering GMAC_SetTxQueueOperationMode for cloning; -fipa-cp-clone disabled.
Not considering GMAC_SetTxQueueCreditBasedShaper for cloning; -fipa-cp-clone disabled.
Not considering GMAC_SetTxQueueQuantumWeight for cloning; -fipa-cp-clone disabled.
Not considering GMAC_SetSchedAlg for cloning; -fipa-cp-clone disabled.
Not considering GMAC_SetSpeed for cloning; -fipa-cp-clone disabled.
Not considering GMAC_SetPowerState for cloning; -fipa-cp-clone disabled.
Not considering GMAC_GetPowerState for cloning; -fipa-cp-clone disabled.
Not considering GMAC_RemoveVlanFromHashTable for cloning; -fipa-cp-clone disabled.
Not considering GMAC_AddVlanToHashTable for cloning; -fipa-cp-clone disabled.
Not considering GMAC_RemoveFromHashTable for cloning; -fipa-cp-clone disabled.
Not considering GMAC_AddToHashTable for cloning; -fipa-cp-clone disabled.
Not considering GMAC_TxIRQHandler for cloning; -fipa-cp-clone disabled.
Not considering GMAC_RxIRQHandler for cloning; -fipa-cp-clone disabled.
Not considering GMAC_CommonIRQHandler for cloning; -fipa-cp-clone disabled.
Not considering GMAC_WriteManagementFrame for cloning; -fipa-cp-clone disabled.
Not considering GMAC_TimeoutExpired for cloning; -fipa-cp-clone disabled.
Not considering GMAC_StartTimeOut for cloning; -fipa-cp-clone disabled.

overall_size: 472, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: GMAC_SetRxQueuesDmaChMap/27:
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
  Node: GMAC_SetRxQueueOperationMode/26:
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
  Node: GMAC_EnableRxQueue/25:
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
  Node: GMAC_SetTxThreshold/24:
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
  Node: GMAC_SetTxStoreAndForward/23:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: GMAC_SetTxQueueOperationMode/22:
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
  Node: GMAC_SetTxQueueCreditBasedShaper/21:
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
  Node: GMAC_SetTxQueueQuantumWeight/20:
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
  Node: GMAC_SetSchedAlg/19:
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
  Node: GMAC_SetSpeed/18:
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
  Node: GMAC_SetPowerState/17:
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
  Node: GMAC_GetPowerState/16:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: GMAC_RemoveVlanFromHashTable/15:
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
  Node: GMAC_AddVlanToHashTable/14:
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
  Node: GMAC_RemoveFromHashTable/13:
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
  Node: GMAC_AddToHashTable/12:
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
  Node: GMAC_TxIRQHandler/11:
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
  Node: GMAC_RxIRQHandler/10:
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
  Node: GMAC_CommonIRQHandler/9:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: GMAC_WriteManagementFrame/8:
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
  Node: GMAC_TimeoutExpired/7:
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
  Node: GMAC_StartTimeOut/6:
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
  Node: GMAC_MACIRQHandler/5:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: REV_BITS_32/4:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE

IPA decision stage:


IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

Gmac_apxState/31 (Gmac_apxState) @0642b678
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: GMAC_CommonIRQHandler/9 (read)GMAC_RxIRQHandler/10 (read)GMAC_MACIRQHandler/5 (read)GMAC_CommonIRQHandler/9 (read)GMAC_TxIRQHandler/11 (read)
  Availability: not_available
  Varpool flags:
OsIf_GetElapsed/30 (OsIf_GetElapsed) @06422460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: GMAC_TimeoutExpired/7 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
OsIf_MicrosToTicks/29 (OsIf_MicrosToTicks) @064222a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: GMAC_StartTimeOut/6 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
OsIf_GetCounter/28 (OsIf_GetCounter) @064221c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: GMAC_StartTimeOut/6 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
GMAC_SetRxQueuesDmaChMap/27 (GMAC_SetRxQueuesDmaChMap) @0641e700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
GMAC_SetRxQueueOperationMode/26 (GMAC_SetRxQueueOperationMode) @0641eb60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
GMAC_EnableRxQueue/25 (GMAC_EnableRxQueue) @0641e8c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
GMAC_SetTxThreshold/24 (GMAC_SetTxThreshold) @0641e620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
GMAC_SetTxStoreAndForward/23 (GMAC_SetTxStoreAndForward) @0641e2a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
GMAC_SetTxQueueOperationMode/22 (GMAC_SetTxQueueOperationMode) @0641e000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
GMAC_SetTxQueueCreditBasedShaper/21 (GMAC_SetTxQueueCreditBasedShaper) @064047e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
GMAC_SetTxQueueQuantumWeight/20 (GMAC_SetTxQueueQuantumWeight) @064042a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
GMAC_SetSchedAlg/19 (GMAC_SetSchedAlg) @06404ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
GMAC_SetSpeed/18 (GMAC_SetSpeed) @06404c40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
GMAC_SetPowerState/17 (GMAC_SetPowerState) @064049a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: 
  Calls: 
GMAC_GetPowerState/16 (GMAC_GetPowerState) @06404700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
GMAC_RemoveVlanFromHashTable/15 (GMAC_RemoveVlanFromHashTable) @06404460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: REV_BITS_32/4 (1073741824 (estimated locally),1.00 per call) 
GMAC_AddVlanToHashTable/14 (GMAC_AddVlanToHashTable) @064041c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: REV_BITS_32/4 (1073741824 (estimated locally),1.00 per call) 
GMAC_RemoveFromHashTable/13 (GMAC_RemoveFromHashTable) @06394e00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: REV_BITS_32/4 (1073741824 (estimated locally),1.00 per call) 
GMAC_AddToHashTable/12 (GMAC_AddToHashTable) @063948c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: REV_BITS_32/4 (1073741824 (estimated locally),1.00 per call) 
GMAC_TxIRQHandler/11 (GMAC_TxIRQHandler) @063940e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gmac_apxChBases/2 (read)Gmac_apxState/31 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
   Indirect call(131533373 (estimated locally),0.12 per call) 
GMAC_RxIRQHandler/10 (GMAC_RxIRQHandler) @06394d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gmac_apxChBases/2 (read)Gmac_apxState/31 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
   Indirect call(131533373 (estimated locally),0.12 per call) 
GMAC_CommonIRQHandler/9 (GMAC_CommonIRQHandler) @06394a80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: Gmac_apxBases/1 (read)Gmac_apxChBases/2 (read)Gmac_apxState/31 (read)Gmac_apxState/31 (read)
  Referring: 
  Availability: available
  Function flags: count:118111599 (estimated locally) body optimize_size
  Called by: 
  Calls: GMAC_MACIRQHandler/5 (118111599 (estimated locally),1.00 per call) 
   Indirect call(334470578 (estimated locally),2.83 per call) 
   Indirect call(334470576 (estimated locally),2.83 per call) 
GMAC_WriteManagementFrame/8 (GMAC_WriteManagementFrame) @063947e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:114863532 (estimated locally) body optimize_size
  Called by: 
  Calls: GMAC_TimeoutExpired/7 (1014686025 (estimated locally),8.83 per call) GMAC_StartTimeOut/6 (114863532 (estimated locally),1.00 per call) 
GMAC_TimeoutExpired/7 (GMAC_TimeoutExpired) @063942a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: GMAC_WriteManagementFrame/8 (1014686025 (estimated locally),8.83 per call) 
  Calls: OsIf_GetElapsed/30 (1073741824 (estimated locally),1.00 per call) 
GMAC_StartTimeOut/6 (GMAC_StartTimeOut) @06394000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: GMAC_WriteManagementFrame/8 (114863532 (estimated locally),1.00 per call) 
  Calls: OsIf_MicrosToTicks/29 (1073741824 (estimated locally),1.00 per call) OsIf_GetCounter/28 (1073741824 (estimated locally),1.00 per call) 
GMAC_MACIRQHandler/5 (GMAC_MACIRQHandler) @062dee00
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: Gmac_apxBases/1 (read)Gmac_apxState/31 (read)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: GMAC_CommonIRQHandler/9 (118111599 (estimated locally),1.00 per call) 
  Calls: 
   Indirect call(375809639 (estimated locally),0.35 per call) 
REV_BITS_32/4 (REV_BITS_32) @062deb60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: GMAC_RemoveVlanFromHashTable/15 (1073741824 (estimated locally),1.00 per call) GMAC_AddVlanToHashTable/14 (1073741824 (estimated locally),1.00 per call) GMAC_RemoveFromHashTable/13 (1073741824 (estimated locally),1.00 per call) GMAC_AddToHashTable/12 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Gmac_apxQueueBases/3 (Gmac_apxQueueBases) @062dce10
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Varpool flags: initialized read-only const-value-known
Gmac_apxChBases/2 (Gmac_apxChBases) @062dcdc8
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: GMAC_CommonIRQHandler/9 (read)GMAC_RxIRQHandler/10 (read)GMAC_TxIRQHandler/11 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known
Gmac_apxBases/1 (Gmac_apxBases) @062dcd80
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: GMAC_MACIRQHandler/5 (read)GMAC_CommonIRQHandler/9 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known

;; Function REV_BITS_32 (REV_BITS_32, funcdef_no=1, decl_uid=6684, cgraph_uid=2, symbol_order=4)

Modification phase of node REV_BITS_32/4
REV_BITS_32 (uint32 value)
{
  uint32 v;
  long unsigned int _1;
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
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int _15;
  long unsigned int _16;
  uint32 _22;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG v => value_17(D)
  # DEBUG BEGIN_STMT
  _1 = value_17(D) >> 1;
  _2 = _1 & 1431655765;
  _3 = value_17(D) << 1;
  _4 = _3 & 2863311530;
  v_18 = _2 | _4;
  # DEBUG v => v_18
  # DEBUG BEGIN_STMT
  _5 = v_18 >> 2;
  _6 = _5 & 858993459;
  _7 = v_18 << 2;
  _8 = _7 & 3435973836;
  v_19 = _6 | _8;
  # DEBUG v => v_19
  # DEBUG BEGIN_STMT
  _9 = v_19 >> 4;
  _10 = _9 & 252645135;
  _11 = v_19 << 4;
  _12 = _11 & 4042322160;
  v_20 = _10 | _12;
  # DEBUG v => v_20
  # DEBUG BEGIN_STMT
  _13 = v_20 >> 8;
  _14 = _13 & 16711935;
  _15 = v_20 << 8;
  _16 = _15 & 4278255360;
  v_21 = _14 | _16;
  # DEBUG v => v_21
  # DEBUG BEGIN_STMT
  _22 = v_21 r>> 16;
  return _22;

}



;; Function GMAC_StartTimeOut (GMAC_StartTimeOut, funcdef_no=3, decl_uid=6594, cgraph_uid=4, symbol_order=6)

Modification phase of node GMAC_StartTimeOut/6
GMAC_StartTimeOut (uint32 * StartTimeOut, uint32 * ElapsedTimeOut, uint32 * TimeoutTicksOut, uint32 TimeoutUs)
{
  long unsigned int _1;
  long unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = OsIf_GetCounter (0);
  *StartTimeOut_5(D) = _1;
  # DEBUG BEGIN_STMT
  *ElapsedTimeOut_7(D) = 0;
  # DEBUG BEGIN_STMT
  _2 = OsIf_MicrosToTicks (TimeoutUs_9(D), 0);
  *TimeoutTicksOut_11(D) = _2;
  return;

}



;; Function GMAC_TimeoutExpired (GMAC_TimeoutExpired, funcdef_no=4, decl_uid=6598, cgraph_uid=5, symbol_order=7)

Modification phase of node GMAC_TimeoutExpired/7
GMAC_TimeoutExpired (uint32 * StartTimeInOut, uint32 * ElapsedTimeInOut, uint32 TimeoutTicks)
{
  boolean RetVal;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _7;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG RetVal => 0
  # DEBUG BEGIN_STMT
  _7 = OsIf_GetElapsed (StartTimeInOut_5(D), 0);
  _1 = *ElapsedTimeInOut_8(D);
  _2 = _1 + _7;
  *ElapsedTimeInOut_8(D) = _2;
  # DEBUG BEGIN_STMT
  if (_2 >= TimeoutTicks_10(D))
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  # DEBUG RetVal => 1

  <bb 4> [local count: 1073741824]:
  # RetVal_3 = PHI <0(2), 1(3)>
  # DEBUG RetVal => RetVal_3
  # DEBUG BEGIN_STMT
  return RetVal_3;

}



;; Function GMAC_WriteManagementFrame (GMAC_WriteManagementFrame, funcdef_no=5, decl_uid=6614, cgraph_uid=6, symbol_order=8)

Modification phase of node GMAC_WriteManagementFrame/8
GMAC_WriteManagementFrame (struct GMAC_Type * Base, const struct Gmac_Ip_ManagementInfo * ManageInfo, uint32 TimeoutUs)
{
  uint32 TimeoutTicks;
  uint32 ElapsedTime;
  uint32 StartTime;
  Gmac_Ip_StatusType Status;
  long unsigned int _1;
  long unsigned int _2;
  _Bool _3;
  short unsigned int _4;
  long unsigned int _5;
  short unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  <unnamed type> _10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  unsigned char _15;
  long unsigned int _16;
  long unsigned int _17;
  long unsigned int _18;
  long unsigned int _19;
  short unsigned int _20;
  long unsigned int _21;
  long unsigned int _22;
  short unsigned int _23;
  long unsigned int _24;
  long unsigned int _25;
  long unsigned int _26;
  long unsigned int _27;
  long unsigned int _28;
  long unsigned int _29;
  long unsigned int _30;
  long unsigned int TimeoutTicks.3_31;
  _Bool _32;
  long unsigned int iftmp.0_34;
  long unsigned int iftmp.1_35;
  long unsigned int iftmp.2_36;
  long unsigned int iftmp.0_43;
  long unsigned int iftmp.2_45;
  long unsigned int iftmp.2_46;

  <bb 2> [local count: 114863532]:
  # DEBUG BEGIN_STMT
  # DEBUG Status => 3
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 ={v} Base_40(D)->MAC_MDIO_ADDRESS;
  _2 = _1 & 4227923953;
  Base_40(D)->MAC_MDIO_ADDRESS ={v} _2;
  # DEBUG BEGIN_STMT
  _3 = ManageInfo_42(D)->SupportedClause45;
  if (_3 != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 57431766]:
  _4 = ManageInfo_42(D)->PhysReg;
  _5 = (long unsigned int) _4;
  iftmp.0_43 = _5 << 16;

  <bb 4> [local count: 114863532]:
  # iftmp.0_34 = PHI <iftmp.0_43(3), 0(2)>
  _6 = ManageInfo_42(D)->FrameData;
  _7 = (long unsigned int) _6;
  _8 = _7 | iftmp.0_34;
  Base_40(D)->MAC_MDIO_DATA ={v} _8;
  # DEBUG BEGIN_STMT
  _9 ={v} Base_40(D)->MAC_MDIO_ADDRESS;
  if (_3 != 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 5> [local count: 57431766]:

  <bb 6> [local count: 114863532]:
  # iftmp.1_35 = PHI <2(4), 0(5)>
  _10 = ManageInfo_42(D)->OpFrameType;
  _11 = (long unsigned int) _10;
  _12 = _11 << 3;
  _13 = _12 & 8;
  _14 = _13 | iftmp.1_35;
  _15 = ManageInfo_42(D)->PhysAddr;
  _16 = (long unsigned int) _15;
  _17 = _16 << 21;
  _18 = _17 & 65011712;
  _19 = _14 | _18;
  if (_3 != 0)
    goto <bb 7>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 7> [local count: 57431766]:
  _20 = ManageInfo_42(D)->MmdAddr;
  _21 = (long unsigned int) _20;
  _22 = _21 << 16;
  iftmp.2_46 = _22 & 2031616;
  goto <bb 9>; [100.00%]

  <bb 8> [local count: 57431766]:
  _23 = ManageInfo_42(D)->PhysReg;
  _24 = (long unsigned int) _23;
  _25 = _24 << 16;
  iftmp.2_45 = _25 & 2031616;

  <bb 9> [local count: 114863532]:
  # iftmp.2_36 = PHI <iftmp.2_46(7), iftmp.2_45(8)>
  _26 = _19 | iftmp.2_36;
  _27 = _9 | _26;
  _28 = _27 | 5;
  Base_40(D)->MAC_MDIO_ADDRESS ={v} _28;
  # DEBUG BEGIN_STMT
  GMAC_StartTimeOut (&StartTime, &ElapsedTime, &TimeoutTicks, TimeoutUs_48(D));

  <bb 10> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _29 ={v} Base_40(D)->MAC_MDIO_ADDRESS;
  _30 = _29 & 1;
  if (_30 == 0)
    goto <bb 12>; [5.50%]
  else
    goto <bb 11>; [94.50%]

  <bb 11> [local count: 1014686025]:
  # DEBUG BEGIN_STMT
  TimeoutTicks.3_31 = TimeoutTicks;
  _32 = GMAC_TimeoutExpired (&StartTime, &ElapsedTime, TimeoutTicks.3_31);
  if (_32 != 0)
    goto <bb 12>; [5.50%]
  else
    goto <bb 13>; [94.50%]

  <bb 13> [local count: 958878293]:
  goto <bb 10>; [100.00%]

  <bb 12> [local count: 114863532]:
  # Status_33 = PHI <0(10), 3(11)>
  # DEBUG Status => Status_33
  # DEBUG BEGIN_STMT
  StartTime ={v} {CLOBBER};
  ElapsedTime ={v} {CLOBBER};
  TimeoutTicks ={v} {CLOBBER};
  return Status_33;

}



;; Function GMAC_CommonIRQHandler (GMAC_CommonIRQHandler, funcdef_no=6, decl_uid=6619, cgraph_uid=7, symbol_order=9)

Modification phase of node GMAC_CommonIRQHandler/9
GMAC_CommonIRQHandler (uint8 Instance)
{
  struct Gmac_Ip_ChannelType * ChBase;
  uint8 TxInterruptStatus[2];
  uint8 RxInterruptStatus[2];
  uint32 Flags;
  uint16 i;
  const struct GMAC_Type * Base;
  int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  int _6;
  long unsigned int _7;
  long unsigned int _8;
  int _9;
  unsigned char _10;
  void (*<T547>) (const uint8, const uint8) _11;
  unsigned char _12;
  struct Gmac_Ip_StateType * _13;
  short unsigned int _14;
  int _15;
  unsigned char _16;
  void (*<T547>) (const uint8, const uint8) _17;
  unsigned char _18;
  struct Gmac_Ip_StateType * _19;
  short unsigned int _20;
  long unsigned int vol.4_46;

  <bb 2> [local count: 118111599]:
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_31(D);
  Base_33 = Gmac_apxBases[_1];
  # DEBUG Base => Base_33
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  RxInterruptStatus = "\x00";
  # DEBUG BEGIN_STMT
  TxInterruptStatus = "\x00";
  # DEBUG BEGIN_STMT
  GMAC_MACIRQHandler (Instance_31(D));
  # DEBUG BEGIN_STMT
  # DEBUG i => 0
  goto <bb 9>; [100.00%]

  <bb 3> [local count: 236258635]:
  # DEBUG BEGIN_STMT
  _2 ={v} Base_33->DMA_INTERRUPT_STATUS;
  _3 = (long unsigned int) i_21;
  _4 = _2 >> _3;
  _5 = _4 & 1;
  if (_5 != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 4> [local count: 118129318]:
  # DEBUG BEGIN_STMT
  _6 = (int) i_21;
  ChBase_43 = Gmac_apxChBases[_1][_6];
  # DEBUG ChBase => ChBase_43
  # DEBUG BEGIN_STMT
  Flags_44 ={v} ChBase_43->DMA_STATUS;
  # DEBUG Flags => Flags_44
  # DEBUG BEGIN_STMT
  ChBase_43->DMA_STATUS ={v} Flags_44;
  # DEBUG BEGIN_STMT
  vol.4_46 ={v} ChBase_43->DMA_STATUS;
  # DEBUG BEGIN_STMT
  _7 = Flags_44 & 3673024;
  if (_7 != 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 5> [local count: 59064659]:
  # DEBUG BEGIN_STMT
  RxInterruptStatus[_6] = 1;

  <bb 6> [local count: 118129318]:
  # DEBUG BEGIN_STMT
  _8 = Flags_44 & 459783;
  if (_8 != 0)
    goto <bb 7>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 7> [local count: 59064659]:
  # DEBUG BEGIN_STMT
  TxInterruptStatus[_6] = 1;

  <bb 8> [local count: 236258636]:
  # DEBUG BEGIN_STMT
  i_49 = i_21 + 1;
  # DEBUG i => i_49

  <bb 9> [local count: 354370235]:
  # i_21 = PHI <0(2), i_49(8)>
  # DEBUG i => i_21
  # DEBUG BEGIN_STMT
  if (i_21 != 2)
    goto <bb 3>; [66.67%]
  else
    goto <bb 22>; [33.33%]

  <bb 22> [local count: 118111599]:
  goto <bb 14>; [100.00%]

  <bb 10> [local count: 955630219]:
  # DEBUG BEGIN_STMT
  _9 = (int) i_22;
  _10 = RxInterruptStatus[_9];
  if (_10 != 0)
    goto <bb 11>; [50.00%]
  else
    goto <bb 13>; [50.00%]

  <bb 11> [local count: 477815109]:
  # DEBUG BEGIN_STMT
  _11 = _13->RxChCallback[_9];
  if (_11 != 0B)
    goto <bb 12>; [70.00%]
  else
    goto <bb 13>; [30.00%]

  <bb 12> [local count: 334470576]:
  # DEBUG BEGIN_STMT
  _12 = (unsigned char) i_22;
  _11 (Instance_31(D), _12);

  <bb 13> [local count: 955630219]:
  # DEBUG BEGIN_STMT
  i_42 = i_22 + 1;
  # DEBUG i => i_42

  <bb 14> [local count: 1073741819]:
  # i_22 = PHI <i_42(13), 0(22)>
  # DEBUG i => i_22
  # DEBUG BEGIN_STMT
  _13 = Gmac_apxState[_1];
  _14 = _13->RxRingCount;
  if (_14 > i_22)
    goto <bb 10>; [89.00%]
  else
    goto <bb 21>; [11.00%]

  <bb 21> [local count: 118111600]:
  goto <bb 19>; [100.00%]

  <bb 15> [local count: 955630224]:
  # DEBUG BEGIN_STMT
  _15 = (int) i_23;
  _16 = TxInterruptStatus[_15];
  if (_16 != 0)
    goto <bb 16>; [50.00%]
  else
    goto <bb 18>; [50.00%]

  <bb 16> [local count: 477815112]:
  # DEBUG BEGIN_STMT
  _17 = _19->TxChCallback[_15];
  if (_17 != 0B)
    goto <bb 17>; [70.00%]
  else
    goto <bb 18>; [30.00%]

  <bb 17> [local count: 334470578]:
  # DEBUG BEGIN_STMT
  _18 = (unsigned char) i_23;
  _17 (Instance_31(D), _18);

  <bb 18> [local count: 955630224]:
  # DEBUG BEGIN_STMT
  i_40 = i_23 + 1;
  # DEBUG i => i_40

  <bb 19> [local count: 1073741824]:
  # i_23 = PHI <i_40(18), 0(21)>
  # DEBUG i => i_23
  # DEBUG BEGIN_STMT
  _19 = Gmac_apxState[_1];
  _20 = _19->TxRingCount;
  if (_20 > i_23)
    goto <bb 15>; [89.00%]
  else
    goto <bb 20>; [11.00%]

  <bb 20> [local count: 118111601]:
  RxInterruptStatus ={v} {CLOBBER};
  TxInterruptStatus ={v} {CLOBBER};
  return;

}



;; Function GMAC_RxIRQHandler (GMAC_RxIRQHandler, funcdef_no=7, decl_uid=6622, cgraph_uid=8, symbol_order=10)

Modification phase of node GMAC_RxIRQHandler/10
GMAC_RxIRQHandler (uint8 Instance, uint8 Channel)
{
  uint32 IrqEnFlags;
  uint32 StatusFlags;
  struct Gmac_Ip_ChannelType * ChBase;
  int _1;
  int _2;
  struct Gmac_Ip_StateType * _3;
  long unsigned int _4;
  long unsigned int _5;
  void (*<T547>) (const uint8, const uint8) _6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_8(D);
  _2 = (int) Channel_9(D);
  ChBase_11 = Gmac_apxChBases[_1][_2];
  # DEBUG ChBase => ChBase_11
  # DEBUG BEGIN_STMT
  StatusFlags_12 ={v} ChBase_11->DMA_STATUS;
  # DEBUG StatusFlags => StatusFlags_12
  # DEBUG BEGIN_STMT
  IrqEnFlags_13 ={v} ChBase_11->DMA_INTERRUPT_ENABLE;
  # DEBUG IrqEnFlags => IrqEnFlags_13
  # DEBUG BEGIN_STMT
  _3 = Gmac_apxState[_1];
  if (_3 != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 7>; [30.00%]

  <bb 3> [local count: 751619278]:
  # DEBUG BEGIN_STMT
  _4 = IrqEnFlags_13 & 64;
  if (_4 != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 4> [local count: 375809639]:
  _5 = StatusFlags_12 & 64;
  if (_5 != 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 5> [local count: 187904819]:
  # DEBUG BEGIN_STMT
  ChBase_11->DMA_STATUS ={v} 64;
  # DEBUG BEGIN_STMT
  _6 = _3->RxChCallback[_2];
  if (_6 != 0B)
    goto <bb 6>; [70.00%]
  else
    goto <bb 8>; [30.00%]

  <bb 6> [local count: 131533373]:
  # DEBUG BEGIN_STMT
  _6 (Instance_8(D), Channel_9(D));
  goto <bb 8>; [100.00%]

  <bb 7> [local count: 322122547]:
  # DEBUG BEGIN_STMT
  ChBase_11->DMA_STATUS ={v} 64;

  <bb 8> [local count: 1073741824]:
  return;

}



;; Function GMAC_TxIRQHandler (GMAC_TxIRQHandler, funcdef_no=8, decl_uid=6625, cgraph_uid=9, symbol_order=11)

Modification phase of node GMAC_TxIRQHandler/11
GMAC_TxIRQHandler (uint8 Instance, uint8 Channel)
{
  uint32 IrqEnFlags;
  uint32 StatusFlags;
  struct Gmac_Ip_ChannelType * ChBase;
  int _1;
  int _2;
  struct Gmac_Ip_StateType * _3;
  long unsigned int _4;
  long unsigned int _5;
  void (*<T547>) (const uint8, const uint8) _6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = (int) Instance_8(D);
  _2 = (int) Channel_9(D);
  ChBase_11 = Gmac_apxChBases[_1][_2];
  # DEBUG ChBase => ChBase_11
  # DEBUG BEGIN_STMT
  StatusFlags_12 ={v} ChBase_11->DMA_STATUS;
  # DEBUG StatusFlags => StatusFlags_12
  # DEBUG BEGIN_STMT
  IrqEnFlags_13 ={v} ChBase_11->DMA_INTERRUPT_ENABLE;
  # DEBUG IrqEnFlags => IrqEnFlags_13
  # DEBUG BEGIN_STMT
  _3 = Gmac_apxState[_1];
  if (_3 != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 7>; [30.00%]

  <bb 3> [local count: 751619278]:
  # DEBUG BEGIN_STMT
  _4 = IrqEnFlags_13 & 1;
  if (_4 != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 4> [local count: 375809639]:
  _5 = StatusFlags_12 & 1;
  if (_5 != 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 5> [local count: 187904819]:
  # DEBUG BEGIN_STMT
  ChBase_11->DMA_STATUS ={v} 1;
  # DEBUG BEGIN_STMT
  _6 = _3->TxChCallback[_2];
  if (_6 != 0B)
    goto <bb 6>; [70.00%]
  else
    goto <bb 8>; [30.00%]

  <bb 6> [local count: 131533373]:
  # DEBUG BEGIN_STMT
  _6 (Instance_8(D), Channel_9(D));
  goto <bb 8>; [100.00%]

  <bb 7> [local count: 322122547]:
  # DEBUG BEGIN_STMT
  ChBase_11->DMA_STATUS ={v} 1;

  <bb 8> [local count: 1073741824]:
  return;

}



;; Function GMAC_AddToHashTable (GMAC_AddToHashTable, funcdef_no=9, decl_uid=6601, cgraph_uid=10, symbol_order=12)

Modification phase of node GMAC_AddToHashTable/12
GMAC_AddToHashTable (const struct GMAC_Type * Base, uint32 Crc)
{
  volatile uint32[2] * Hash_table;
  volatile uint32 HashBaseAddr;
  uint32 Hash_bit;
  const uint32_t * _1;
  long unsigned int _2;
  long unsigned int HashBaseAddr.11_3;
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
  _1 = &Base_10(D)->MAC_HASH_TABLE_REG0;
  _2 = (long unsigned int) _1;
  HashBaseAddr ={v} _2;
  # DEBUG BEGIN_STMT
  HashBaseAddr.11_3 ={v} HashBaseAddr;
  Hash_table_13 = (volatile uint32[2] *) HashBaseAddr.11_3;
  # DEBUG Hash_table => Hash_table_13
  # DEBUG BEGIN_STMT
  _4 = REV_BITS_32 (Crc_14(D));
  _5 = _4 >> 31;
  # DEBUG Index => _5
  # DEBUG BEGIN_STMT
  _6 = _4 >> 26;
  _7 = _6 & 31;
  Hash_bit_15 = 1 << _7;
  # DEBUG Hash_bit => Hash_bit_15
  # DEBUG BEGIN_STMT
  _8 ={v} *Hash_table_13[_5];
  _9 = _8 | Hash_bit_15;
  *Hash_table_13[_5] ={v} _9;
  return;

}



;; Function GMAC_RemoveFromHashTable (GMAC_RemoveFromHashTable, funcdef_no=10, decl_uid=6604, cgraph_uid=11, symbol_order=13)

Modification phase of node GMAC_RemoveFromHashTable/13
GMAC_RemoveFromHashTable (const struct GMAC_Type * Base, uint32 Crc)
{
  volatile uint32[2] * Hash_table;
  volatile uint32 HashBaseAddr;
  uint32 Hash_bit;
  const uint32_t * _1;
  long unsigned int _2;
  long unsigned int HashBaseAddr.12_3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = &Base_11(D)->MAC_HASH_TABLE_REG0;
  _2 = (long unsigned int) _1;
  HashBaseAddr ={v} _2;
  # DEBUG BEGIN_STMT
  HashBaseAddr.12_3 ={v} HashBaseAddr;
  Hash_table_14 = (volatile uint32[2] *) HashBaseAddr.12_3;
  # DEBUG Hash_table => Hash_table_14
  # DEBUG BEGIN_STMT
  _4 = REV_BITS_32 (Crc_15(D));
  _5 = _4 >> 31;
  # DEBUG Index => _5
  # DEBUG BEGIN_STMT
  _6 = _4 >> 26;
  _7 = _6 & 31;
  Hash_bit_16 = 1 << _7;
  # DEBUG Hash_bit => Hash_bit_16
  # DEBUG BEGIN_STMT
  _8 ={v} *Hash_table_14[_5];
  _9 = ~Hash_bit_16;
  _10 = _8 & _9;
  *Hash_table_14[_5] ={v} _10;
  return;

}



;; Function GMAC_AddVlanToHashTable (GMAC_AddVlanToHashTable, funcdef_no=11, decl_uid=6607, cgraph_uid=12, symbol_order=14)

Modification phase of node GMAC_AddVlanToHashTable/14
GMAC_AddVlanToHashTable (struct GMAC_Type * Base, uint32 Crc)
{
  uint32 Index;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = REV_BITS_32 (Crc_10(D));
  _2 = _1 >> 28;
  # DEBUG Index => _2
  # DEBUG BEGIN_STMT
  _3 ={v} Base_11(D)->MAC_VLAN_TAG_DATA;
  _4 = _3 & 131072;
  if (_4 == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  Index_12 = _2 + 4294967295;
  # DEBUG Index => Index_12

  <bb 4> [local count: 1073741824]:
  # Index_8 = PHI <_2(2), Index_12(3)>
  # DEBUG Index => Index_8
  # DEBUG BEGIN_STMT
  _5 ={v} Base_11(D)->MAC_VLAN_HASH_TABLE;
  _6 = 1 << Index_8;
  _7 = _5 | _6;
  Base_11(D)->MAC_VLAN_HASH_TABLE ={v} _7;
  return;

}



;; Function GMAC_RemoveVlanFromHashTable (GMAC_RemoveVlanFromHashTable, funcdef_no=12, decl_uid=6610, cgraph_uid=13, symbol_order=15)

Modification phase of node GMAC_RemoveVlanFromHashTable/15
GMAC_RemoveVlanFromHashTable (struct GMAC_Type * Base, uint32 Crc)
{
  uint32 Index;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = REV_BITS_32 (Crc_11(D));
  _2 = _1 >> 28;
  # DEBUG Index => _2
  # DEBUG BEGIN_STMT
  _3 ={v} Base_12(D)->MAC_VLAN_TAG_DATA;
  _4 = _3 & 131072;
  if (_4 == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  Index_13 = _2 + 4294967295;
  # DEBUG Index => Index_13

  <bb 4> [local count: 1073741824]:
  # Index_9 = PHI <_2(2), Index_13(3)>
  # DEBUG Index => Index_9
  # DEBUG BEGIN_STMT
  _5 ={v} Base_12(D)->MAC_VLAN_HASH_TABLE;
  _6 = 1 << Index_9;
  _7 = ~_6;
  _8 = _5 & _7;
  Base_12(D)->MAC_VLAN_HASH_TABLE ={v} _8;
  return;

}



;; Function GMAC_GetPowerState (GMAC_GetPowerState, funcdef_no=13, decl_uid=6627, cgraph_uid=14, symbol_order=16)

Modification phase of node GMAC_GetPowerState/16
GMAC_GetPowerState (const struct GMAC_Type * Base)
{
  Gmac_Ip_PowerStateType PowerState;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG PowerState => 3
  # DEBUG BEGIN_STMT
  _1 ={v} Base_11(D)->DMA_MODE;
  _2 = _1 & 1;
  if (_2 != 0)
    goto <bb 7>; [35.00%]
  else
    goto <bb 3>; [65.00%]

  <bb 3> [local count: 697932186]:
  # DEBUG BEGIN_STMT
  _3 ={v} Base_11(D)->MAC_PMT_CONTROL_STATUS;
  _4 = _3 & 1;
  if (_4 != 0)
    goto <bb 7>; [35.00%]
  else
    goto <bb 4>; [65.00%]

  <bb 4> [local count: 453655921]:
  # DEBUG BEGIN_STMT
  _5 ={v} Base_11(D)->MAC_CONFIGURATION;
  _6 = _5 & 3;
  if (_6 != 0)
    goto <bb 7>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 5> [local count: 226827960]:
  # DEBUG BEGIN_STMT
  _7 ={v} Base_11(D)->MAC_CONFIGURATION;
  _8 = _7 & 3;
  if (_8 == 0)
    goto <bb 6>; [65.00%]
  else
    goto <bb 7>; [35.00%]

  <bb 6> [local count: 147438174]:
  # DEBUG BEGIN_STMT
  # DEBUG PowerState => 0

  <bb 7> [local count: 1073741824]:
  # PowerState_9 = PHI <3(2), 2(3), 1(4), 3(5), 0(6)>
  # DEBUG PowerState => PowerState_9
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return PowerState_9;

}



;; Function GMAC_SetPowerState (GMAC_SetPowerState, funcdef_no=14, decl_uid=6630, cgraph_uid=15, symbol_order=17)

Modification phase of node GMAC_SetPowerState/17
GMAC_SetPowerState (struct GMAC_Type * Base, Gmac_Ip_PowerStateType PowerState)
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
  long unsigned int _10;
  long unsigned int _11;
  long unsigned int _12;
  long unsigned int _13;
  long unsigned int _14;
  long unsigned int _15;
  long unsigned int _16;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  switch (PowerState_18(D)) <default: <L6> [20.00%], case 0: <L0> [20.00%], case 1: <L1> [20.00%], case 2: <L2> [20.00%], case 3: <L3> [20.00%]>

  <bb 3> [local count: 214748364]:
<L0>:
  # DEBUG BEGIN_STMT
  _1 ={v} Base_20(D)->MAC_PMT_CONTROL_STATUS;
  _2 = _1 & 4294967294;
  Base_20(D)->MAC_PMT_CONTROL_STATUS ={v} _2;
  # DEBUG BEGIN_STMT
  _3 ={v} Base_20(D)->MAC_CONFIGURATION;
  _4 = _3 & 4294967292;
  Base_20(D)->MAC_CONFIGURATION ={v} _4;
  # DEBUG BEGIN_STMT
  goto <bb 7>; [100.00%]

  <bb 4> [local count: 214748364]:
<L1>:
  # DEBUG BEGIN_STMT
  _5 ={v} Base_20(D)->MAC_PMT_CONTROL_STATUS;
  _6 = _5 & 4294967294;
  Base_20(D)->MAC_PMT_CONTROL_STATUS ={v} _6;
  # DEBUG BEGIN_STMT
  _7 ={v} Base_20(D)->MAC_CONFIGURATION;
  _8 = _7 | 3;
  Base_20(D)->MAC_CONFIGURATION ={v} _8;
  # DEBUG BEGIN_STMT
  goto <bb 7>; [100.00%]

  <bb 5> [local count: 214748364]:
<L2>:
  # DEBUG BEGIN_STMT
  _9 ={v} Base_20(D)->MAC_PMT_CONTROL_STATUS;
  _10 = _9 | 516;
  Base_20(D)->MAC_PMT_CONTROL_STATUS ={v} _10;
  # DEBUG BEGIN_STMT
  _11 ={v} Base_20(D)->MAC_PMT_CONTROL_STATUS;
  _12 = _11 | 1;
  Base_20(D)->MAC_PMT_CONTROL_STATUS ={v} _12;
  # DEBUG BEGIN_STMT
  _13 ={v} Base_20(D)->MAC_PMT_CONTROL_STATUS;
  _14 = _13 | 1024;
  Base_20(D)->MAC_PMT_CONTROL_STATUS ={v} _14;
  # DEBUG BEGIN_STMT
  goto <bb 7>; [100.00%]

  <bb 6> [local count: 214748364]:
<L3>:
  # DEBUG BEGIN_STMT
  _15 ={v} Base_20(D)->DMA_MODE;
  _16 = _15 | 1;
  Base_20(D)->DMA_MODE ={v} _16;
  # DEBUG BEGIN_STMT

  <bb 7> [local count: 1073741824]:
<L6>:
  return;

}



;; Function GMAC_SetSpeed (GMAC_SetSpeed, funcdef_no=15, decl_uid=6633, cgraph_uid=16, symbol_order=18)

Modification phase of node GMAC_SetSpeed/18
GMAC_SetSpeed (struct GMAC_Type * Base, Gmac_Ip_SpeedType Speed)
{
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  if (Speed_10(D) == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _1 ={v} Base_12(D)->MAC_CONFIGURATION;
  _2 = _1 & 4294918143;
  Base_12(D)->MAC_CONFIGURATION ={v} _2;
  goto <bb 8>; [100.00%]

  <bb 4> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  if (Speed_10(D) == 3)
    goto <bb 5>; [34.00%]
  else
    goto <bb 6>; [66.00%]

  <bb 5> [local count: 182536110]:
  # DEBUG BEGIN_STMT
  _3 ={v} Base_12(D)->MAC_CONFIGURATION;
  _4 = _3 | 49152;
  Base_12(D)->MAC_CONFIGURATION ={v} _4;
  goto <bb 8>; [100.00%]

  <bb 6> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  if (Speed_10(D) == 2)
    goto <bb 7>; [34.00%]
  else
    goto <bb 8>; [66.00%]

  <bb 7> [local count: 120473833]:
  # DEBUG BEGIN_STMT
  _5 ={v} Base_12(D)->MAC_CONFIGURATION;
  _6 = _5 | 32768;
  Base_12(D)->MAC_CONFIGURATION ={v} _6;
  # DEBUG BEGIN_STMT
  _7 ={v} Base_12(D)->MAC_CONFIGURATION;
  _8 = _7 & 4294950911;
  Base_12(D)->MAC_CONFIGURATION ={v} _8;

  <bb 8> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function GMAC_SetSchedAlg (GMAC_SetSchedAlg, funcdef_no=16, decl_uid=6636, cgraph_uid=17, symbol_order=19)

Modification phase of node GMAC_SetSchedAlg/19
GMAC_SetSchedAlg (struct GMAC_Type * Base, Gmac_Ip_TxSchedAlgoType SchedAlgo)
{
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  if (SchedAlgo_6(D) == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _1 ={v} Base_8(D)->MTL_OPERATION_MODE;
  _2 = _1 & 4294967199;
  Base_8(D)->MTL_OPERATION_MODE ={v} _2;
  goto <bb 6>; [100.00%]

  <bb 4> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  if (SchedAlgo_6(D) == 3)
    goto <bb 5>; [34.00%]
  else
    goto <bb 6>; [66.00%]

  <bb 5> [local count: 182536110]:
  # DEBUG BEGIN_STMT
  _3 ={v} Base_8(D)->MTL_OPERATION_MODE;
  _4 = _3 | 96;
  Base_8(D)->MTL_OPERATION_MODE ={v} _4;

  <bb 6> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function GMAC_SetTxQueueQuantumWeight (GMAC_SetTxQueueQuantumWeight, funcdef_no=17, decl_uid=6639, cgraph_uid=18, symbol_order=20)

Modification phase of node GMAC_SetTxQueueQuantumWeight/20
GMAC_SetTxQueueQuantumWeight (struct Gmac_Ip_QueueType * QueueBase, uint32 Weight)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  QueueBase_2(D)->MTL_TXQ_QUANTUM_WEIGHT ={v} Weight_3(D);
  return;

}



;; Function GMAC_SetTxQueueCreditBasedShaper (GMAC_SetTxQueueCreditBasedShaper, funcdef_no=18, decl_uid=6644, cgraph_uid=19, symbol_order=21)

Modification phase of node GMAC_SetTxQueueCreditBasedShaper/21
GMAC_SetTxQueueCreditBasedShaper (struct Gmac_Ip_QueueType * QueueBase, uint32 SendSlopeCredit, uint32 HighCredit, sint32 LowCredit)
{
  long unsigned int LowCredit.13_1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  QueueBase_3(D)->MTL_TXQ_SENDSLOPECREDIT ={v} SendSlopeCredit_4(D);
  # DEBUG BEGIN_STMT
  QueueBase_3(D)->MTL_TXQ_HICREDIT ={v} HighCredit_6(D);
  # DEBUG BEGIN_STMT
  LowCredit.13_1 = (long unsigned int) LowCredit_8(D);
  QueueBase_3(D)->MTL_TXQ_LOCREDIT ={v} LowCredit.13_1;
  return;

}



;; Function GMAC_SetTxQueueOperationMode (GMAC_SetTxQueueOperationMode, funcdef_no=19, decl_uid=6648, cgraph_uid=20, symbol_order=22)

Modification phase of node GMAC_SetTxQueueOperationMode/22
GMAC_SetTxQueueOperationMode (struct Gmac_Ip_QueueType * QueueBase, Gmac_Ip_OperationModeType QueueMode, uint32 QueueSize)
{
  uint32 BlockNum;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int iftmp.14_8;
  long unsigned int iftmp.14_11;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  BlockNum_10 = QueueSize_9(D) >> 8;
  # DEBUG BlockNum => BlockNum_10
  # DEBUG BEGIN_STMT
  if (QueueSize_9(D) > 255)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  iftmp.14_11 = BlockNum_10 + 4294967295;

  <bb 4> [local count: 1073741824]:
  # iftmp.14_8 = PHI <iftmp.14_11(3), 0(2)>
  # DEBUG BlockNum => iftmp.14_8
  # DEBUG BEGIN_STMT
  _1 = (long unsigned int) QueueMode_12(D);
  _2 = _1 << 2;
  _3 = _2 & 12;
  _4 = iftmp.14_8 << 16;
  _5 = _4 & 2031616;
  _6 = _3 | _5;
  _7 = _6 | 2;
  QueueBase_14(D)->MTL_TXQ_OPERATION_MODE ={v} _7;
  return;

}



;; Function GMAC_SetTxStoreAndForward (GMAC_SetTxStoreAndForward, funcdef_no=20, decl_uid=6650, cgraph_uid=21, symbol_order=23)

Modification phase of node GMAC_SetTxStoreAndForward/23
GMAC_SetTxStoreAndForward (struct Gmac_Ip_QueueType * QueueBase)
{
  long unsigned int _1;
  long unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 ={v} QueueBase_4(D)->MTL_TXQ_OPERATION_MODE;
  _2 = _1 | 2;
  QueueBase_4(D)->MTL_TXQ_OPERATION_MODE ={v} _2;
  return;

}



;; Function GMAC_SetTxThreshold (GMAC_SetTxThreshold, funcdef_no=21, decl_uid=6653, cgraph_uid=22, symbol_order=24)

Modification phase of node GMAC_SetTxThreshold/24
GMAC_SetTxThreshold (struct Gmac_Ip_QueueType * QueueBase, Gmac_Ip_TxThresholdType ThresholdValue)
{
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  long unsigned int _5;
  long unsigned int _6;
  long unsigned int _7;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 ={v} QueueBase_9(D)->MTL_TXQ_OPERATION_MODE;
  _2 = _1 & 4294967181;
  QueueBase_9(D)->MTL_TXQ_OPERATION_MODE ={v} _2;
  # DEBUG BEGIN_STMT
  _3 ={v} QueueBase_9(D)->MTL_TXQ_OPERATION_MODE;
  _4 = (long unsigned int) ThresholdValue_11(D);
  _5 = _4 << 4;
  _6 = _5 & 112;
  _7 = _3 | _6;
  QueueBase_9(D)->MTL_TXQ_OPERATION_MODE ={v} _7;
  return;

}



;; Function GMAC_EnableRxQueue (GMAC_EnableRxQueue, funcdef_no=22, decl_uid=6657, cgraph_uid=23, symbol_order=25)

Modification phase of node GMAC_EnableRxQueue/25
GMAC_EnableRxQueue (struct GMAC_Type * Base, uint8 PriorityMask, uint8 QueueNum)
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
  long unsigned int _10;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 ={v} Base_12(D)->MAC_RXQ_CTRL2;
  _2 = (long unsigned int) PriorityMask_13(D);
  _3 = (long unsigned int) QueueNum_14(D);
  _4 = _3 * 8;
  _5 = _2 << _4;
  _6 = _1 | _5;
  Base_12(D)->MAC_RXQ_CTRL2 ={v} _6;
  # DEBUG BEGIN_STMT
  _7 ={v} Base_12(D)->MAC_RXQ_CTRL0;
  _8 = _3 * 2;
  _9 = 2 << _8;
  _10 = _7 | _9;
  Base_12(D)->MAC_RXQ_CTRL0 ={v} _10;
  return;

}



;; Function GMAC_SetRxQueueOperationMode (GMAC_SetRxQueueOperationMode, funcdef_no=23, decl_uid=6660, cgraph_uid=24, symbol_order=26)

Modification phase of node GMAC_SetRxQueueOperationMode/26
GMAC_SetRxQueueOperationMode (struct Gmac_Ip_QueueType * QueueBase, uint32 QueueSize)
{
  uint32 BlockNum;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int iftmp.15_3;
  long unsigned int iftmp.15_6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  BlockNum_5 = QueueSize_4(D) >> 8;
  # DEBUG BlockNum => BlockNum_5
  # DEBUG BEGIN_STMT
  if (QueueSize_4(D) > 255)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  iftmp.15_6 = BlockNum_5 + 4294967295;

  <bb 4> [local count: 1073741824]:
  # iftmp.15_3 = PHI <iftmp.15_6(3), 0(2)>
  # DEBUG BlockNum => iftmp.15_3
  # DEBUG BEGIN_STMT
  _1 = iftmp.15_3 << 20;
  _2 = _1 & 32505856;
  QueueBase_8(D)->MTL_RXQ_OPERATION_MODE ={v} _2;
  return;

}



;; Function GMAC_SetRxQueuesDmaChMap (GMAC_SetRxQueuesDmaChMap, funcdef_no=24, decl_uid=6663, cgraph_uid=25, symbol_order=27)

Modification phase of node GMAC_SetRxQueuesDmaChMap/27
GMAC_SetRxQueuesDmaChMap (struct GMAC_Type * Base, uint8 QueuesNum)
{
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  if (QueuesNum_6(D) != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _1 ={v} Base_8(D)->MTL_RXQ_DMA_MAP0;
  Base_8(D)->MTL_RXQ_DMA_MAP0 ={v} _1;

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  if (QueuesNum_6(D) > 1)
    goto <bb 5>; [59.00%]
  else
    goto <bb 6>; [41.00%]

  <bb 5> [local count: 633507677]:
  # DEBUG BEGIN_STMT
  _2 ={v} Base_8(D)->MTL_RXQ_DMA_MAP0;
  _3 = _2 | 256;
  Base_8(D)->MTL_RXQ_DMA_MAP0 ={v} _3;

  <bb 6> [local count: 1073741824]:
  return;

}


