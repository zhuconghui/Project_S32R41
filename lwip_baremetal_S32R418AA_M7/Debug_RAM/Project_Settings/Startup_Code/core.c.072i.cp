
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  NVIC_SetPriorityGrouping/17:
  Jump functions of caller  NVIC_EnableIRQ/16:
  Jump functions of caller  NVIC_SetPriority/15:
  Jump functions of caller  NVIC_DisableIRQ/14:
  Jump functions of caller  Core_Cache_Init/13:
  Jump functions of caller  Core_MPU_Init/11:
  Jump functions of caller  Core_FPU_Init/9:
  Jump functions of caller  Core_IC_Init/7:
  Jump functions of caller  Core_registerIsrHandler/5:
  Jump functions of caller  Core_clearPendingIsrSource/4:
  Jump functions of caller  Core_enableIsrSource/3:
  Jump functions of caller  Core_disableIsrSource/2:

 Propagating constants:

Not considering Core_Cache_Init for cloning; -fipa-cp-clone disabled.
Not considering Core_MPU_Init for cloning; -fipa-cp-clone disabled.
Not considering Core_FPU_Init for cloning; -fipa-cp-clone disabled.
Not considering Core_IC_Init for cloning; -fipa-cp-clone disabled.
Not considering Core_registerIsrHandler for cloning; -fipa-cp-clone disabled.
Not considering Core_clearPendingIsrSource for cloning; -fipa-cp-clone disabled.
Not considering Core_enableIsrSource for cloning; -fipa-cp-clone disabled.
Not considering Core_disableIsrSource for cloning; -fipa-cp-clone disabled.

overall_size: 96, max_new_size: 11001
 - context independent values, size: 3, time_benefit: 1.000000

IPA lattices after all propagation:

Lattices:
  Node: Core_Cache_Init/13:
  Node: Core_MPU_Init/11:
  Node: Core_FPU_Init/9:
  Node: Core_IC_Init/7:
  Node: Core_registerIsrHandler/5:
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
  Node: Core_clearPendingIsrSource/4:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: Core_enableIsrSource/3:
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
  Node: Core_disableIsrSource/2:
    param [0]: BOTTOM
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

NVIC_SetPriorityGrouping/17 (NVIC_SetPriorityGrouping) @05fe87e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Core_IC_Init/7 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
NVIC_EnableIRQ/16 (NVIC_EnableIRQ) @05fe8460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Core_enableIsrSource/3 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
NVIC_SetPriority/15 (NVIC_SetPriority) @05fe8380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Core_enableIsrSource/3 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
NVIC_DisableIRQ/14 (NVIC_DisableIRQ) @05fe1b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: Core_disableIsrSource/2 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
Core_Cache_Init/13 (Core_Cache_Init) @05fe1a80
  Type: function definition analyzed
  Visibility: externally_visible public section:.systeminit
  References: 
  Referring: 
  Availability: available
  Function flags: count:12992276 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Core_MPU_Init/11 (Core_MPU_Init) @05fe1540
  Type: function definition analyzed
  Visibility: externally_visible public section:.systeminit
  References: rbar/0 (read)rasr/1 (read)
  Referring: 
  Availability: available
  Function flags: count:97603132 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Core_FPU_Init/9 (Core_FPU_Init) @05fe1ee0
  Type: function definition analyzed
  Visibility: externally_visible public section:.systeminit
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Core_IC_Init/7 (Core_IC_Init) @05fe1c40
  Type: function definition analyzed
  Visibility: externally_visible public section:.systeminit
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: NVIC_SetPriorityGrouping/17 (1073741824 (estimated locally),1.00 per call) 
Core_registerIsrHandler/5 (Core_registerIsrHandler) @05fe19a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Core_clearPendingIsrSource/4 (Core_clearPendingIsrSource) @05fe1700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
Core_enableIsrSource/3 (Core_enableIsrSource) @05fe1460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: NVIC_EnableIRQ/16 (1073741824 (estimated locally),1.00 per call) NVIC_SetPriority/15 (1073741824 (estimated locally),1.00 per call) 
Core_disableIsrSource/2 (Core_disableIsrSource) @05fe11c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: NVIC_DisableIRQ/14 (1073741824 (estimated locally),1.00 per call) 
rasr/1 (rasr) @05fbd3a8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Core_MPU_Init/11 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known
rbar/0 (rbar) @05fbd318
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: Core_MPU_Init/11 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known

;; Function Core_disableIsrSource (Core_disableIsrSource, funcdef_no=0, decl_uid=5463, cgraph_uid=1, symbol_order=2)

Modification phase of node Core_disableIsrSource/2
Core_disableIsrSource (uint16 id)
{
  unsigned char _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = (unsigned char) id_2(D);
  NVIC_DisableIRQ (_1);
  return;

}



;; Function Core_enableIsrSource (Core_enableIsrSource, funcdef_no=1, decl_uid=5466, cgraph_uid=2, symbol_order=3)

Modification phase of node Core_enableIsrSource/3
Core_enableIsrSource (uint16 id, uint8 prio)
{
  unsigned char _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = (unsigned char) id_2(D);
  NVIC_SetPriority (_1, prio_4(D));
  # DEBUG BEGIN_STMT
  NVIC_EnableIRQ (_1);
  return;

}



;; Function Core_clearPendingIsrSource (Core_clearPendingIsrSource, funcdef_no=2, decl_uid=5468, cgraph_uid=3, symbol_order=4)

Modification phase of node Core_clearPendingIsrSource/4
Core_clearPendingIsrSource (uint16 id)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function Core_registerIsrHandler (Core_registerIsrHandler, funcdef_no=3, decl_uid=5472, cgraph_uid=4, symbol_order=5)

Modification phase of node Core_registerIsrHandler/5
Core_registerIsrHandler (uint16 irq_id, void (*<T4a3>) (void) isr_handler)
{
  long unsigned int _1;
  int _2;
  int _3;
  int _4;
  long unsigned int _5;
  long unsigned int _6;
  volatile uint32 * _7;
  long unsigned int isr_handler.0_8;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(volatile uint32 *)3758157064B];
  _2 = (int) irq_id_10(D);
  _3 = _2 + 16;
  _4 = _3 << 2;
  _5 = (long unsigned int) _4;
  _6 = _1 + _5;
  _7 = (volatile uint32 *) _6;
  isr_handler.0_8 = (long unsigned int) isr_handler_11(D);
  *_7 ={v} isr_handler.0_8;
  return;

}



;; Function Core_IC_Init (Core_IC_Init, funcdef_no=4, decl_uid=5444, cgraph_uid=6, symbol_order=7)

Modification phase of node Core_IC_Init/7
__attribute__((section (".systeminit")))
Core_IC_Init ()
{
  long unsigned int _1;
  long unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  NVIC_SetPriorityGrouping (0);
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct S32_SCB_Type *)3758153728B].CCR;
  _2 = _1 | 1;
  MEM[(struct S32_SCB_Type *)3758153728B].CCR ={v} _2;
  # DEBUG BEGIN_STMT
  MEM[(struct S32_SCB_Type *)3758153728B].SHPR3 ={v} 0;
  return;

}



;; Function Core_FPU_Init (Core_FPU_Init, funcdef_no=5, decl_uid=5446, cgraph_uid=8, symbol_order=9)

Modification phase of node Core_FPU_Init/9
__attribute__((section (".systeminit")))
Core_FPU_Init ()
{
  long unsigned int _1;
  long unsigned int _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 ={v} MEM[(struct S32_SCB_Type *)3758153728B].CPACR;
  _2 = _1 | 15728640;
  MEM[(struct S32_SCB_Type *)3758153728B].CPACR ={v} _2;
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("dsb");
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("isb");
  return;

}



;; Function Core_MPU_Init (Core_MPU_Init, funcdef_no=6, decl_uid=5448, cgraph_uid=10, symbol_order=11)

Modification phase of node Core_MPU_Init/11
__attribute__((section (".systeminit")))
Core_MPU_Init ()
{
  uint32 regionNum;
  long unsigned int _1;
  long unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;

  <bb 2> [local count: 97603132]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("dsb");
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("isb");
  # DEBUG BEGIN_STMT
  # DEBUG regionNum => 0
  goto <bb 4>; [100.00%]

  <bb 3> [local count: 976138694]:
  # DEBUG BEGIN_STMT
  MEM[(struct S32_MPU_Type *)3758153728B].RNR ={v} regionNum_5;
  # DEBUG BEGIN_STMT
  _1 = rbar[regionNum_5];
  MEM[(struct S32_MPU_Type *)3758153728B].RBAR ={v} _1;
  # DEBUG BEGIN_STMT
  _2 = rasr[regionNum_5];
  MEM[(struct S32_MPU_Type *)3758153728B].RASR ={v} _2;
  # DEBUG BEGIN_STMT
  regionNum_16 = regionNum_5 + 1;
  # DEBUG regionNum => regionNum_16

  <bb 4> [local count: 1073741824]:
  # regionNum_5 = PHI <0(2), regionNum_16(3)>
  # DEBUG regionNum => regionNum_5
  # DEBUG BEGIN_STMT
  if (regionNum_5 != 10)
    goto <bb 3>; [90.91%]
  else
    goto <bb 5>; [9.09%]

  <bb 5> [local count: 97603132]:
  # DEBUG BEGIN_STMT
  _3 ={v} MEM[(struct S32_MPU_Type *)3758153728B].CTRL;
  _4 = _3 | 1;
  MEM[(struct S32_MPU_Type *)3758153728B].CTRL ={v} _4;
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("dsb");
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("isb");
  return;

}



;; Function Core_Cache_Init (Core_Cache_Init, funcdef_no=7, decl_uid=5450, cgraph_uid=12, symbol_order=13)

Modification phase of node Core_Cache_Init/13
__attribute__((section (".systeminit")))
Core_Cache_Init ()
{
  uint32 ways;
  uint32 sets;
  uint32 ccsidr;
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

  <bb 2> [local count: 12992276]:
  # DEBUG BEGIN_STMT
  # DEBUG ccsidr => 0
  # DEBUG BEGIN_STMT
  # DEBUG sets => 0
  # DEBUG BEGIN_STMT
  # DEBUG ways => 0
  # DEBUG BEGIN_STMT
  MEM[(struct S32_SCB_Type *)3758153728B].CSSELR ={v} 0;
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("dsb");
  # DEBUG BEGIN_STMT
  ccsidr_18 ={v} MEM[(struct S32_SCB_Type *)3758153728B].CCSIDR;
  # DEBUG ccsidr => ccsidr_18
  # DEBUG BEGIN_STMT
  _1 = ccsidr_18 >> 13;
  sets_19 = _1 & 32767;
  # DEBUG sets => sets_19

  <bb 3> [local count: 118111600]:
  # sets_11 = PHI <sets_19(2), sets_23(7)>
  # DEBUG sets => sets_11
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = ccsidr_18 >> 3;
  ways_20 = _2 & 1023;
  # DEBUG ways => ways_20

  <bb 4> [local count: 1073741824]:
  # ways_12 = PHI <ways_20(3), ways_22(8)>
  # DEBUG ways => ways_12
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = sets_11 << 5;
  _4 = _3 & 16352;
  _5 = ways_12 << 30;
  _6 = _4 | _5;
  MEM[(struct S32_SCB_Type *)3758153728B].DCISW ={v} _6;
  # DEBUG BEGIN_STMT
  ways_22 = ways_12 + 4294967295;
  # DEBUG ways => ways_22
  if (ways_12 != 0)
    goto <bb 8>; [89.00%]
  else
    goto <bb 5>; [11.00%]

  <bb 8> [local count: 955630224]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 118111601]:
  # DEBUG BEGIN_STMT
  sets_23 = sets_11 + 4294967295;
  # DEBUG sets => sets_23
  if (sets_11 != 0)
    goto <bb 7>; [89.00%]
  else
    goto <bb 6>; [11.00%]

  <bb 7> [local count: 105119325]:
  goto <bb 3>; [100.00%]

  <bb 6> [local count: 12992276]:
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("dsb");
  # DEBUG BEGIN_STMT
  _7 ={v} MEM[(struct S32_SCB_Type *)3758153728B].CCR;
  _8 = _7 | 65536;
  MEM[(struct S32_SCB_Type *)3758153728B].CCR ={v} _8;
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("dsb");
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("isb");
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("dsb");
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("isb");
  # DEBUG BEGIN_STMT
  MEM[(struct S32_SCB_Type *)3758153728B].ICIALLU ={v} 0;
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("dsb");
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("isb");
  # DEBUG BEGIN_STMT
  _9 ={v} MEM[(struct S32_SCB_Type *)3758153728B].CCR;
  _10 = _9 | 131072;
  MEM[(struct S32_SCB_Type *)3758153728B].CCR ={v} _10;
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("dsb");
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("isb");
  return;

}


