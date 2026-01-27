
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_18/29:
  Jump functions of caller  hwAcc_ArmCoreMx_DataCacheCleanByAddr/28:
  Jump functions of caller  hwAcc_ArmCoreMx_InstructionCacheCleanByAddr/27:
  Jump functions of caller  SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_18/26:
  Jump functions of caller  SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_17/25:
  Jump functions of caller  hwAcc_ArmCoreMx_DataCacheInvalidateByAddr/24:
  Jump functions of caller  hwAcc_ArmCoreMx_InstructionCacheInvalidateByAddr/23:
  Jump functions of caller  SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_17/22:
  Jump functions of caller  SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_16/21:
  Jump functions of caller  hwAcc_ArmCoreMx_DataCacheClean/20:
  Jump functions of caller  hwAcc_ArmCoreMx_InstructionCacheClean/19:
  Jump functions of caller  SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_16/18:
  Jump functions of caller  SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_15/17:
  Jump functions of caller  hwAcc_ArmCoreMx_DataCacheInvalidate/16:
  Jump functions of caller  hwAcc_ArmCoreMx_InstructionCacheInvalidate/15:
  Jump functions of caller  SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_15/14:
  Jump functions of caller  SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_14/13:
  Jump functions of caller  hwAcc_ArmCoreMx_DataCacheDisable/12:
  Jump functions of caller  hwAcc_ArmCoreMx_InstructionCacheDisable/11:
  Jump functions of caller  SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_14/10:
  Jump functions of caller  SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_13/9:
  Jump functions of caller  hwAcc_ArmCoreMx_DataCacheEnable/8:
  Jump functions of caller  hwAcc_ArmCoreMx_InstructionCacheEnable/7:
  Jump functions of caller  SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_13/6:
  Jump functions of caller  Cache_Ip_CleanByAddr/5:
  Jump functions of caller  Cache_Ip_InvalidateByAddr/4:
  Jump functions of caller  Cache_Ip_Clean/3:
  Jump functions of caller  Cache_Ip_Invalidate/2:
  Jump functions of caller  Cache_Ip_Disable/1:
  Jump functions of caller  Cache_Ip_Enable/0:

 Propagating constants:

Not considering Cache_Ip_CleanByAddr for cloning; -fipa-cp-clone disabled.
Not considering Cache_Ip_InvalidateByAddr for cloning; -fipa-cp-clone disabled.
Not considering Cache_Ip_Clean for cloning; -fipa-cp-clone disabled.
Not considering Cache_Ip_Invalidate for cloning; -fipa-cp-clone disabled.
Not considering Cache_Ip_Disable for cloning; -fipa-cp-clone disabled.
Not considering Cache_Ip_Enable for cloning; -fipa-cp-clone disabled.

overall_size: 90, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: Cache_Ip_CleanByAddr/5:
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
  Node: Cache_Ip_InvalidateByAddr/4:
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
  Node: Cache_Ip_Clean/3:
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
  Node: Cache_Ip_Invalidate/2:
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
  Node: Cache_Ip_Disable/1:
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
  Node: Cache_Ip_Enable/0:
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

IPA decision stage:


IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_18/29 (SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_18) @060aae00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Cache_Ip_CleanByAddr/5 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
hwAcc_ArmCoreMx_DataCacheCleanByAddr/28 (hwAcc_ArmCoreMx_DataCacheCleanByAddr) @060aad20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Cache_Ip_CleanByAddr/5 (58935156 (estimated locally),0.05 per call) 
  Calls: 
hwAcc_ArmCoreMx_InstructionCacheCleanByAddr/27 (hwAcc_ArmCoreMx_InstructionCacheCleanByAddr) @060aac40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Cache_Ip_CleanByAddr/5 (73890617 (estimated locally),0.07 per call) 
  Calls: 
SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_18/26 (SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_18) @060aab60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Cache_Ip_CleanByAddr/5 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_17/25 (SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_17) @060aa9a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Cache_Ip_InvalidateByAddr/4 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
hwAcc_ArmCoreMx_DataCacheInvalidateByAddr/24 (hwAcc_ArmCoreMx_DataCacheInvalidateByAddr) @060aa8c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Cache_Ip_InvalidateByAddr/4 (58935156 (estimated locally),0.05 per call) 
  Calls: 
hwAcc_ArmCoreMx_InstructionCacheInvalidateByAddr/23 (hwAcc_ArmCoreMx_InstructionCacheInvalidateByAddr) @060aa7e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Cache_Ip_InvalidateByAddr/4 (73890617 (estimated locally),0.07 per call) 
  Calls: 
SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_17/22 (SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_17) @060aa700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Cache_Ip_InvalidateByAddr/4 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_16/21 (SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_16) @060aa540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Cache_Ip_Clean/3 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
hwAcc_ArmCoreMx_DataCacheClean/20 (hwAcc_ArmCoreMx_DataCacheClean) @060aa460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Cache_Ip_Clean/3 (58935156 (estimated locally),0.05 per call) 
  Calls: 
hwAcc_ArmCoreMx_InstructionCacheClean/19 (hwAcc_ArmCoreMx_InstructionCacheClean) @060aa380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Cache_Ip_Clean/3 (73890617 (estimated locally),0.07 per call) 
  Calls: 
SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_16/18 (SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_16) @060aa2a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Cache_Ip_Clean/3 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_15/17 (SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_15) @060aa0e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Cache_Ip_Invalidate/2 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
hwAcc_ArmCoreMx_DataCacheInvalidate/16 (hwAcc_ArmCoreMx_DataCacheInvalidate) @060aa000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Cache_Ip_Invalidate/2 (58935156 (estimated locally),0.05 per call) 
  Calls: 
hwAcc_ArmCoreMx_InstructionCacheInvalidate/15 (hwAcc_ArmCoreMx_InstructionCacheInvalidate) @060a5000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Cache_Ip_Invalidate/2 (73890617 (estimated locally),0.07 per call) 
  Calls: 
SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_15/14 (SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_15) @060a5ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Cache_Ip_Invalidate/2 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_14/13 (SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_14) @060a5d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Cache_Ip_Disable/1 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
hwAcc_ArmCoreMx_DataCacheDisable/12 (hwAcc_ArmCoreMx_DataCacheDisable) @060a5c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Cache_Ip_Disable/1 (58935156 (estimated locally),0.05 per call) 
  Calls: 
hwAcc_ArmCoreMx_InstructionCacheDisable/11 (hwAcc_ArmCoreMx_InstructionCacheDisable) @060a5b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Cache_Ip_Disable/1 (73890617 (estimated locally),0.07 per call) 
  Calls: 
SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_14/10 (SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_14) @060a5a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Cache_Ip_Disable/1 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_13/9 (SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_13) @060a58c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Cache_Ip_Enable/0 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
hwAcc_ArmCoreMx_DataCacheEnable/8 (hwAcc_ArmCoreMx_DataCacheEnable) @060a57e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Cache_Ip_Enable/0 (58935156 (estimated locally),0.05 per call) 
  Calls: 
hwAcc_ArmCoreMx_InstructionCacheEnable/7 (hwAcc_ArmCoreMx_InstructionCacheEnable) @060a5700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Cache_Ip_Enable/0 (73890617 (estimated locally),0.07 per call) 
  Calls: 
SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_13/6 (SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_13) @060a5620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Cache_Ip_Enable/0 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Cache_Ip_CleanByAddr/5 (Cache_Ip_CleanByAddr) @060a51c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_18/29 (1073741824 (estimated locally),1.00 per call) hwAcc_ArmCoreMx_DataCacheCleanByAddr/28 (58935156 (estimated locally),0.05 per call) hwAcc_ArmCoreMx_InstructionCacheCleanByAddr/27 (73890617 (estimated locally),0.07 per call) SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_18/26 (1073741824 (estimated locally),1.00 per call) 
Cache_Ip_InvalidateByAddr/4 (Cache_Ip_InvalidateByAddr) @05f94ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_17/25 (1073741824 (estimated locally),1.00 per call) hwAcc_ArmCoreMx_DataCacheInvalidateByAddr/24 (58935156 (estimated locally),0.05 per call) hwAcc_ArmCoreMx_InstructionCacheInvalidateByAddr/23 (73890617 (estimated locally),0.07 per call) SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_17/22 (1073741824 (estimated locally),1.00 per call) 
Cache_Ip_Clean/3 (Cache_Ip_Clean) @05f949a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_16/21 (1073741824 (estimated locally),1.00 per call) hwAcc_ArmCoreMx_DataCacheClean/20 (58935156 (estimated locally),0.05 per call) hwAcc_ArmCoreMx_InstructionCacheClean/19 (73890617 (estimated locally),0.07 per call) SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_16/18 (1073741824 (estimated locally),1.00 per call) 
Cache_Ip_Invalidate/2 (Cache_Ip_Invalidate) @05f94e00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_15/17 (1073741824 (estimated locally),1.00 per call) hwAcc_ArmCoreMx_DataCacheInvalidate/16 (58935156 (estimated locally),0.05 per call) hwAcc_ArmCoreMx_InstructionCacheInvalidate/15 (73890617 (estimated locally),0.07 per call) SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_15/14 (1073741824 (estimated locally),1.00 per call) 
Cache_Ip_Disable/1 (Cache_Ip_Disable) @05f94b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_14/13 (1073741824 (estimated locally),1.00 per call) hwAcc_ArmCoreMx_DataCacheDisable/12 (58935156 (estimated locally),0.05 per call) hwAcc_ArmCoreMx_InstructionCacheDisable/11 (73890617 (estimated locally),0.07 per call) SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_14/10 (1073741824 (estimated locally),1.00 per call) 
Cache_Ip_Enable/0 (Cache_Ip_Enable) @05f948c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_13/9 (1073741824 (estimated locally),1.00 per call) hwAcc_ArmCoreMx_DataCacheEnable/8 (58935156 (estimated locally),0.05 per call) hwAcc_ArmCoreMx_InstructionCacheEnable/7 (73890617 (estimated locally),0.07 per call) SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_13/6 (1073741824 (estimated locally),1.00 per call) 

;; Function Cache_Ip_Enable (Cache_Ip_Enable, funcdef_no=0, decl_uid=5633, cgraph_uid=1, symbol_order=0)

Modification phase of node Cache_Ip_Enable/0
Cache_Ip_Enable (const Cache_Ip_Type CacheType, const Cache_Ip_BusType BusType)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG Status => 0
  # DEBUG BEGIN_STMT
  SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_13 ();
  # DEBUG BEGIN_STMT
  if (CacheType_4(D) == 1)
    goto <bb 3>; [34.00%]
  else
    goto <bb 7>; [66.00%]

  <bb 3> [local count: 365072220]:
<L0>:
  # DEBUG BEGIN_STMT
  if (BusType_5(D) == 3)
    goto <bb 4>; [20.24%]
  else
    goto <bb 5>; [79.76%]

  <bb 4> [local count: 73890617]:
  # DEBUG BEGIN_STMT
  hwAcc_ArmCoreMx_InstructionCacheEnable ();
  goto <bb 7>; [100.00%]

  <bb 5> [local count: 291181603]:
  # DEBUG BEGIN_STMT
  if (BusType_5(D) == 4)
    goto <bb 6>; [20.24%]
  else
    goto <bb 7>; [79.76%]

  <bb 6> [local count: 58935156]:
  # DEBUG BEGIN_STMT
  hwAcc_ArmCoreMx_DataCacheEnable ();

  <bb 7> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_13 ();
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function Cache_Ip_Disable (Cache_Ip_Disable, funcdef_no=1, decl_uid=5636, cgraph_uid=2, symbol_order=1)

Modification phase of node Cache_Ip_Disable/1
Cache_Ip_Disable (const Cache_Ip_Type CacheType, const Cache_Ip_BusType BusType)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG Status => 0
  # DEBUG BEGIN_STMT
  SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_14 ();
  # DEBUG BEGIN_STMT
  if (CacheType_4(D) == 1)
    goto <bb 3>; [34.00%]
  else
    goto <bb 7>; [66.00%]

  <bb 3> [local count: 365072220]:
<L0>:
  # DEBUG BEGIN_STMT
  if (BusType_5(D) == 3)
    goto <bb 4>; [20.24%]
  else
    goto <bb 5>; [79.76%]

  <bb 4> [local count: 73890617]:
  # DEBUG BEGIN_STMT
  hwAcc_ArmCoreMx_InstructionCacheDisable ();
  goto <bb 7>; [100.00%]

  <bb 5> [local count: 291181603]:
  # DEBUG BEGIN_STMT
  if (BusType_5(D) == 4)
    goto <bb 6>; [20.24%]
  else
    goto <bb 7>; [79.76%]

  <bb 6> [local count: 58935156]:
  # DEBUG BEGIN_STMT
  hwAcc_ArmCoreMx_DataCacheDisable ();

  <bb 7> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_14 ();
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function Cache_Ip_Invalidate (Cache_Ip_Invalidate, funcdef_no=2, decl_uid=5639, cgraph_uid=3, symbol_order=2)

Modification phase of node Cache_Ip_Invalidate/2
Cache_Ip_Invalidate (const Cache_Ip_Type CacheType, const Cache_Ip_BusType BusType)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG Status => 0
  # DEBUG BEGIN_STMT
  SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_15 ();
  # DEBUG BEGIN_STMT
  if (CacheType_4(D) == 1)
    goto <bb 3>; [34.00%]
  else
    goto <bb 7>; [66.00%]

  <bb 3> [local count: 365072220]:
<L0>:
  # DEBUG BEGIN_STMT
  if (BusType_5(D) == 3)
    goto <bb 4>; [20.24%]
  else
    goto <bb 5>; [79.76%]

  <bb 4> [local count: 73890617]:
  # DEBUG BEGIN_STMT
  hwAcc_ArmCoreMx_InstructionCacheInvalidate ();
  goto <bb 7>; [100.00%]

  <bb 5> [local count: 291181603]:
  # DEBUG BEGIN_STMT
  if (BusType_5(D) == 4)
    goto <bb 6>; [20.24%]
  else
    goto <bb 7>; [79.76%]

  <bb 6> [local count: 58935156]:
  # DEBUG BEGIN_STMT
  hwAcc_ArmCoreMx_DataCacheInvalidate ();

  <bb 7> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_15 ();
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function Cache_Ip_Clean (Cache_Ip_Clean, funcdef_no=3, decl_uid=5643, cgraph_uid=4, symbol_order=3)

Modification phase of node Cache_Ip_Clean/3
Cache_Ip_Clean (const Cache_Ip_Type CacheType, const Cache_Ip_BusType BusType, const boolean EnInvalidate)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG Status => 0
  # DEBUG BEGIN_STMT
  SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_16 ();
  # DEBUG BEGIN_STMT
  if (CacheType_4(D) == 1)
    goto <bb 3>; [34.00%]
  else
    goto <bb 7>; [66.00%]

  <bb 3> [local count: 365072220]:
<L0>:
  # DEBUG BEGIN_STMT
  if (BusType_5(D) == 3)
    goto <bb 4>; [20.24%]
  else
    goto <bb 5>; [79.76%]

  <bb 4> [local count: 73890617]:
  # DEBUG BEGIN_STMT
  hwAcc_ArmCoreMx_InstructionCacheClean (EnInvalidate_6(D));
  goto <bb 7>; [100.00%]

  <bb 5> [local count: 291181603]:
  # DEBUG BEGIN_STMT
  if (BusType_5(D) == 4)
    goto <bb 6>; [20.24%]
  else
    goto <bb 7>; [79.76%]

  <bb 6> [local count: 58935156]:
  # DEBUG BEGIN_STMT
  hwAcc_ArmCoreMx_DataCacheClean (EnInvalidate_6(D));

  <bb 7> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_16 ();
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function Cache_Ip_InvalidateByAddr (Cache_Ip_InvalidateByAddr, funcdef_no=4, decl_uid=5648, cgraph_uid=5, symbol_order=4)

Modification phase of node Cache_Ip_InvalidateByAddr/4
Cache_Ip_InvalidateByAddr (const Cache_Ip_Type CacheType, const Cache_Ip_BusType BusType, const uint32 Addr, const uint32 Length)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG Status => 0
  # DEBUG BEGIN_STMT
  SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_17 ();
  # DEBUG BEGIN_STMT
  if (CacheType_4(D) == 1)
    goto <bb 3>; [34.00%]
  else
    goto <bb 7>; [66.00%]

  <bb 3> [local count: 365072220]:
<L0>:
  # DEBUG BEGIN_STMT
  if (BusType_5(D) == 3)
    goto <bb 4>; [20.24%]
  else
    goto <bb 5>; [79.76%]

  <bb 4> [local count: 73890617]:
  # DEBUG BEGIN_STMT
  hwAcc_ArmCoreMx_InstructionCacheInvalidateByAddr (Addr_6(D), Length_7(D));
  goto <bb 7>; [100.00%]

  <bb 5> [local count: 291181603]:
  # DEBUG BEGIN_STMT
  if (BusType_5(D) == 4)
    goto <bb 6>; [20.24%]
  else
    goto <bb 7>; [79.76%]

  <bb 6> [local count: 58935156]:
  # DEBUG BEGIN_STMT
  hwAcc_ArmCoreMx_DataCacheInvalidateByAddr (Addr_6(D), Length_7(D));

  <bb 7> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_17 ();
  # DEBUG BEGIN_STMT
  return 0;

}



;; Function Cache_Ip_CleanByAddr (Cache_Ip_CleanByAddr, funcdef_no=5, decl_uid=5654, cgraph_uid=6, symbol_order=5)

Modification phase of node Cache_Ip_CleanByAddr/5
Cache_Ip_CleanByAddr (const Cache_Ip_Type CacheType, const Cache_Ip_BusType BusType, const boolean EnInvalidate, const uint32 Addr, const uint32 Length)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG Status => 0
  # DEBUG BEGIN_STMT
  SchM_Enter_Mcl_MCL_EXCLUSIVE_AREA_18 ();
  # DEBUG BEGIN_STMT
  if (CacheType_4(D) == 1)
    goto <bb 3>; [34.00%]
  else
    goto <bb 7>; [66.00%]

  <bb 3> [local count: 365072220]:
<L0>:
  # DEBUG BEGIN_STMT
  if (BusType_5(D) == 3)
    goto <bb 4>; [20.24%]
  else
    goto <bb 5>; [79.76%]

  <bb 4> [local count: 73890617]:
  # DEBUG BEGIN_STMT
  hwAcc_ArmCoreMx_InstructionCacheCleanByAddr (EnInvalidate_6(D), Addr_7(D), Length_8(D));
  goto <bb 7>; [100.00%]

  <bb 5> [local count: 291181603]:
  # DEBUG BEGIN_STMT
  if (BusType_5(D) == 4)
    goto <bb 6>; [20.24%]
  else
    goto <bb 7>; [79.76%]

  <bb 6> [local count: 58935156]:
  # DEBUG BEGIN_STMT
  hwAcc_ArmCoreMx_DataCacheCleanByAddr (EnInvalidate_6(D), Addr_7(D), Length_8(D));

  <bb 7> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  SchM_Exit_Mcl_MCL_EXCLUSIVE_AREA_18 ();
  # DEBUG BEGIN_STMT
  return 0;

}


