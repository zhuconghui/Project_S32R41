
IPA constant propagation start:
Determining dynamic type for call: err_19 = _18 (p_1(D), arg_17(D));
  Starting walk at: err_19 = _18 (p_1(D), arg_17(D));
  instance pointer: p_1(D)  Outer instance pointer: p_1(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pbuf_realloc (p_1(D), _16);
  Function call may change dynamic type:_14 = pbuf_remove_header (p_1(D), 32);
Determining dynamic type for call: err_19 = _18 (p_1(D), arg_17(D));
  Starting walk at: err_19 = _18 (p_1(D), arg_17(D));
  instance pointer: arg_17(D)  Outer instance pointer: arg_17(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pbuf_realloc (p_1(D), _16);
  Function call may change dynamic type:_14 = pbuf_remove_header (p_1(D), 32);
Determining dynamic type for call: _7 = zepif_linkoutput.part.0 (netif_4(D), p_6(D));
  Starting walk at: _7 = zepif_linkoutput.part.0 (netif_4(D), p_6(D));
  instance pointer: netif_4(D)  Outer instance pointer: netif_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _7 = zepif_linkoutput.part.0 (netif_4(D), p_6(D));
  Starting walk at: _7 = zepif_linkoutput.part.0 (netif_4(D), p_6(D));
  instance pointer: p_6(D)  Outer instance pointer: p_6(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: zepif_udp_recv.part.0 (arg_3(D), p_7(D));
  Starting walk at: zepif_udp_recv.part.0 (arg_3(D), p_7(D));
  instance pointer: arg_3(D)  Outer instance pointer: arg_3(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: zepif_udp_recv.part.0 (arg_3(D), p_7(D));
  Starting walk at: zepif_udp_recv.part.0 (arg_3(D), p_7(D));
  instance pointer: p_7(D)  Outer instance pointer: p_7(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: zep_lowpan_timer.part.0 (arg_4(D));
  Starting walk at: zep_lowpan_timer.part.0 (arg_4(D));
  instance pointer: arg_4(D)  Outer instance pointer: arg_4(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:lowpan6_tmr ();

IPA structures before propagation:

Jump functions:
  Jump functions of caller  zepif_udp_recv.part.0/29:
    indirect aggregate callsite, calling param 0, offset 1408, by reference, for stmt err_19 = _18 (p_1(D), arg_17(D));
       param 0: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  zepif_linkoutput.part.0/28:
  Jump functions of caller  zep_lowpan_timer.part.0/27:
  Jump functions of caller  pbuf_realloc/26:
  Jump functions of caller  pbuf_remove_header/25:
  Jump functions of caller  pbuf_free/24:
  Jump functions of caller  udp_sendto/23:
  Jump functions of caller  pbuf_copy_partial_pbuf/22:
  Jump functions of caller  lwip_htonl/21:
  Jump functions of caller  lwip_htons/20:
  Jump functions of caller  pbuf_alloc/19:
  Jump functions of caller  lowpan6_tmr/18:
  Jump functions of caller  mem_free/17:
  Jump functions of caller  udp_remove/16:
  Jump functions of caller  sys_timeout/15:
  Jump functions of caller  lowpan6_if_init/14:
  Jump functions of caller  udp_recv/13:
  Jump functions of caller  udp_bind_netif/12:
  Jump functions of caller  udp_bind/11:
  Jump functions of caller  udp_new_ip_type/10:
  Jump functions of caller  memcpy/8:
  Jump functions of caller  memset/7:
  Jump functions of caller  mem_malloc/6:
  Jump functions of caller  zepif_init/5:
  Jump functions of caller  zepif_linkoutput/4:
    callsite  zepif_linkoutput/4 -> zepif_linkoutput.part.0/28 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  zepif_udp_recv/3:
    callsite  zepif_udp_recv/3 -> zepif_udp_recv.part.0/29 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 2, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  zep_lowpan_timer/2:
    callsite  zep_lowpan_timer/2 -> zep_lowpan_timer.part.0/27 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR

 Propagating constants:

Not considering zepif_init for cloning; -fipa-cp-clone disabled.
Not considering zepif_linkoutput for cloning; -fipa-cp-clone disabled.
Not considering zepif_udp_recv for cloning; -fipa-cp-clone disabled.
Not considering zep_lowpan_timer for cloning; -fipa-cp-clone disabled.

overall_size: 274, max_new_size: 11001
 - context independent values, size: 16, time_benefit: 2.000000

IPA lattices after all propagation:

Lattices:
  Node: zepif_udp_recv.part.0/29:
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
  Node: zepif_linkoutput.part.0/28:
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
  Node: zep_lowpan_timer.part.0/27:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: zepif_init/5:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: zepif_linkoutput/4:
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
  Node: zepif_udp_recv/3:
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
  Node: zep_lowpan_timer/2:
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

zepif_udp_recv.part.0/29 (zepif_udp_recv.part.0) @0559f9a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: zepif_udp_recv/3 (143652 (estimated locally),0.40 per call) 
  Calls: pbuf_remove_header/25 (7308155 (estimated locally),0.01 per call) pbuf_realloc/26 (3572226 (estimated locally),0.00 per call) pbuf_free/24 (1072527268 (estimated locally),1.00 per call) 
   Indirect call(3572226 (estimated locally),0.00 per call)  of param:0 loaded from aggregate passed by reference at offset 1408 (vptr maybe changed)
zepif_linkoutput.part.0/28 (zepif_linkoutput.part.0) @0559f2a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:155003 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: zepif_linkoutput/4 (155004 (estimated locally),0.49 per call) 
  Calls: pbuf_alloc/19 (24606 (estimated locally),0.16 per call) memset/7 (24382 (estimated locally),0.16 per call) lwip_htons/20 (24382 (estimated locally),0.16 per call) lwip_htonl/21 (24382 (estimated locally),0.16 per call) pbuf_copy_partial_pbuf/22 (24382 (estimated locally),0.16 per call) udp_sendto/23 (8046 (estimated locally),0.05 per call) pbuf_free/24 (24382 (estimated locally),0.16 per call) 
zep_lowpan_timer.part.0/27 (zep_lowpan_timer.part.0) @0538c8c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: zep_lowpan_timer/2 (addr)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: zep_lowpan_timer/2 (354334800 (estimated locally),0.33 per call) 
  Calls: sys_timeout/15 (1073741824 (estimated locally),1.00 per call) 
pbuf_realloc/26 (pbuf_realloc) @05588460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: zepif_udp_recv.part.0/29 (3572226 (estimated locally),0.00 per call) 
  Calls: 
pbuf_remove_header/25 (pbuf_remove_header) @05588380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: zepif_udp_recv.part.0/29 (7308155 (estimated locally),0.01 per call) 
  Calls: 
pbuf_free/24 (pbuf_free) @05588000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: zepif_udp_recv.part.0/29 (1072527268 (estimated locally),1.00 per call) zepif_linkoutput.part.0/28 (24382 (estimated locally),0.16 per call) 
  Calls: 
udp_sendto/23 (udp_sendto) @05552ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: zepif_linkoutput.part.0/28 (8046 (estimated locally),0.05 per call) 
  Calls: 
pbuf_copy_partial_pbuf/22 (pbuf_copy_partial_pbuf) @05552e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: zepif_linkoutput.part.0/28 (24382 (estimated locally),0.16 per call) 
  Calls: 
lwip_htonl/21 (lwip_htonl) @05552d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: zepif_linkoutput.part.0/28 (24382 (estimated locally),0.16 per call) 
  Calls: 
lwip_htons/20 (lwip_htons) @05552c40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: zepif_linkoutput.part.0/28 (24382 (estimated locally),0.16 per call) 
  Calls: 
pbuf_alloc/19 (pbuf_alloc) @05552b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: zepif_linkoutput.part.0/28 (24606 (estimated locally),0.16 per call) 
  Calls: 
lowpan6_tmr/18 (lowpan6_tmr) @055529a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: zep_lowpan_timer/2 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
mem_free/17 (mem_free) @055527e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: zepif_init/5 (157522 (estimated locally),0.44 per call) 
  Calls: 
udp_remove/16 (udp_remove) @05552700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: zepif_init/5 (84227 (estimated locally),0.24 per call) 
  Calls: 
sys_timeout/15 (sys_timeout) @05552540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: zepif_init/5 (3808 (estimated locally),0.01 per call) zep_lowpan_timer.part.0/27 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
lowpan6_if_init/14 (lowpan6_if_init) @05552460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: zepif_init/5 (113139 (estimated locally),0.32 per call) 
  Calls: 
udp_recv/13 (udp_recv) @05552380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: zepif_init/5 (113139 (estimated locally),0.32 per call) 
  Calls: 
udp_bind_netif/12 (udp_bind_netif) @055522a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: zepif_init/5 (60496 (estimated locally),0.17 per call) 
  Calls: 
udp_bind/11 (udp_bind) @055521c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: zepif_init/5 (171423 (estimated locally),0.48 per call) 
  Calls: 
udp_new_ip_type/10 (udp_new_ip_type) @055520e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: zepif_init/5 (248259 (estimated locally),0.69 per call) 
  Calls: 
ip_addr_broadcast/9 (ip_addr_broadcast) @0554f318
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: zepif_init/5 (addr)
  Availability: not_available
  Varpool flags: read-only
memcpy/8 (memcpy) @05552000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: zepif_init/5 (6171 (estimated locally),0.02 per call) zepif_init/5 (132744 (estimated locally),0.37 per call) 
  Calls: 
memset/7 (memset) @05538620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: zepif_init/5 (248259 (estimated locally),0.69 per call) zepif_linkoutput.part.0/28 (24382 (estimated locally),0.16 per call) 
  Calls: 
mem_malloc/6 (mem_malloc) @05538ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: zepif_init/5 (357913 (estimated locally),1.00 per call) 
  Calls: 
zepif_init/5 (zepif_init) @055388c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: ip_addr_broadcast/9 (addr)zepif_udp_recv/3 (addr)zepif_linkoutput/4 (addr)zep_lowpan_timer_running/1 (read)zep_lowpan_timer/2 (addr)zep_lowpan_timer_running/1 (write)
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: 
  Calls: mem_free/17 (157522 (estimated locally),0.44 per call) udp_remove/16 (84227 (estimated locally),0.24 per call) sys_timeout/15 (3808 (estimated locally),0.01 per call) memcpy/8 (6171 (estimated locally),0.02 per call) lowpan6_if_init/14 (113139 (estimated locally),0.32 per call) udp_recv/13 (113139 (estimated locally),0.32 per call) udp_bind_netif/12 (60496 (estimated locally),0.17 per call) udp_bind/11 (171423 (estimated locally),0.48 per call) udp_new_ip_type/10 (248259 (estimated locally),0.69 per call) memcpy/8 (132744 (estimated locally),0.37 per call) memset/7 (248259 (estimated locally),0.69 per call) mem_malloc/6 (357913 (estimated locally),1.00 per call) 
zepif_linkoutput/4 (zepif_linkoutput) @05538540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: zepif_init/5 (addr)
  Availability: available
  Function flags: count:316334 (estimated locally) body optimize_size
  Called by: 
  Calls: zepif_linkoutput.part.0/28 (155004 (estimated locally),0.49 per call) 
zepif_udp_recv/3 (zepif_udp_recv) @055382a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: zepif_init/5 (addr)
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: 
  Calls: zepif_udp_recv.part.0/29 (143652 (estimated locally),0.40 per call) 
zep_lowpan_timer/2 (zep_lowpan_timer) @05538000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: zep_lowpan_timer_running/1 (read)
  Referring: zep_lowpan_timer.part.0/27 (addr)zepif_init/5 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: zep_lowpan_timer.part.0/27 (354334800 (estimated locally),0.33 per call) lowpan6_tmr/18 (1073741824 (estimated locally),1.00 per call) 
zep_lowpan_timer_running/1 (zep_lowpan_timer_running) @05531e10
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: zep_lowpan_timer/2 (read)zepif_init/5 (read)zepif_init/5 (write)
  Availability: available
  Varpool flags:

;; Function zep_lowpan_timer (zep_lowpan_timer, funcdef_no=1, decl_uid=7230, cgraph_uid=2, symbol_order=2)

Modification phase of node zep_lowpan_timer/2
zep_lowpan_timer (void * arg)
{
  unsigned char zep_lowpan_timer_running.2_1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  lowpan6_tmr ();
  # DEBUG BEGIN_STMT
  zep_lowpan_timer_running.2_1 = zep_lowpan_timer_running;
  if (zep_lowpan_timer_running.2_1 != 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 4>; [67.00%]

  <bb 3> [local count: 354334800]:
  zep_lowpan_timer.part.0 (arg_4(D));

  <bb 4> [local count: 1073741824]:
  return;

}



;; Function zepif_linkoutput (zepif_linkoutput, funcdef_no=3, decl_uid=7247, cgraph_uid=4, symbol_order=4)

Modification phase of node zepif_linkoutput/4
zepif_linkoutput (struct netif * netif, struct pbuf * p)
{
  signed char _7;

  <bb 2> [local count: 316334]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (netif_4(D) == 0B)
    goto <bb 7>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 7> [local count: 94900]:

  <bb 3> [local count: 949002417]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 9> [local count: 949002417]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 221434]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (p_6(D) == 0B)
    goto <bb 8>; [30.00%]
  else
    goto <bb 6>; [70.00%]

  <bb 8> [local count: 66430]:

  <bb 5> [local count: 664301693]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 10> [local count: 664301693]:
  goto <bb 5>; [100.00%]

  <bb 6> [local count: 155004]:
  _7 = zepif_linkoutput.part.0 (netif_4(D), p_6(D));
  return _7;

}



;; Function zepif_udp_recv (zepif_udp_recv, funcdef_no=2, decl_uid=7237, cgraph_uid=3, symbol_order=3)

Modification phase of node zepif_udp_recv/3
zepif_udp_recv (void * arg, struct udp_pcb * pcb, struct pbuf * p, const struct ip_addr_t * addr, u16_t port)
{
  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG netif_lowpan6 => arg_3(D)
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (arg_3(D) == 0B)
    goto <bb 9>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 9> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 11> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (pcb_6(D) == 0B)
    goto <bb 10>; [30.00%]
  else
    goto <bb 6>; [70.00%]

  <bb 10> [local count: 75162]:

  <bb 5> [local count: 751619279]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 12> [local count: 751619279]:
  goto <bb 5>; [100.00%]

  <bb 6> [local count: 175378]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (p_7(D) == 0B)
    goto <bb 8>; [18.09%]
  else
    goto <bb 7>; [81.91%]

  <bb 7> [local count: 143652]:
  # DEBUG D#1 => pcb_6(D)
  # DEBUG D#2 => addr_4(D)
  # DEBUG D#3 => port_10(D)
  zepif_udp_recv.part.0 (arg_3(D), p_7(D));

  <bb 8> [local count: 175378]:
  return;

}



;; Function zepif_init (zepif_init, funcdef_no=4, decl_uid=7013, cgraph_uid=5, symbol_order=5)

Modification phase of node zepif_init/5
zepif_init (struct netif * netif)
{
  u8_t i;
  struct zepif_state * state;
  struct zepif_init * init_state;
  err_t err;
  err_t (*<T6aa>) (struct pbuf *, struct netif *) _1;
  struct zepif_init * _2;
  short unsigned int _3;
  short unsigned int _4;
  const struct ip_addr_t * _5;
  struct udp_pcb * _6;
  const struct ip_addr_t * _7;
  short unsigned int _8;
  const struct netif * _9;
  struct udp_pcb * _10;
  struct udp_pcb * _11;
  unsigned char _12;
  unsigned char _13;
  void * _14;
  u8_t[6] * _15;
  u8_t[6] * _16;
  int _17;
  unsigned char _18;
  unsigned char _19;
  unsigned char zep_lowpan_timer_running.1_20;
  struct udp_pcb * _21;
  err_t _24;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  init_state_40 = netif_39(D)->state;
  # DEBUG init_state => init_state_40
  # DEBUG BEGIN_STMT
  state_42 = mem_malloc (32);
  # DEBUG state => state_42
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = netif_39(D)->input;
  if (_1 == 0B)
    goto <bb 34>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 34> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 37> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (state_42 == 0B)
    goto <bb 33>; [0.91%]
  else
    goto <bb 5>; [99.09%]

  <bb 5> [local count: 248259]:
  # DEBUG BEGIN_STMT
  memset (state_42, 0, 32);
  # DEBUG BEGIN_STMT
  if (init_state_40 != 0B)
    goto <bb 6>; [53.47%]
  else
    goto <bb 7>; [46.53%]

  <bb 6> [local count: 132744]:
  # DEBUG BEGIN_STMT
  _2 = &state_42->init;
  memcpy (_2, init_state_40, 24);

  <bb 7> [local count: 248259]:
  # DEBUG BEGIN_STMT
  _3 = state_42->init.zep_src_udp_port;
  if (_3 == 0)
    goto <bb 8>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 8> [local count: 124130]:
  # DEBUG BEGIN_STMT
  state_42->init.zep_src_udp_port = 17754;

  <bb 9> [local count: 248259]:
  # DEBUG BEGIN_STMT
  _4 = state_42->init.zep_dst_udp_port;
  if (_4 == 0)
    goto <bb 10>; [50.00%]
  else
    goto <bb 11>; [50.00%]

  <bb 10> [local count: 124130]:
  # DEBUG BEGIN_STMT
  state_42->init.zep_dst_udp_port = 17754;

  <bb 11> [local count: 248259]:
  # DEBUG BEGIN_STMT
  _5 = state_42->init.zep_dst_ip_addr;
  if (_5 == 0B)
    goto <bb 12>; [30.00%]
  else
    goto <bb 13>; [70.00%]

  <bb 12> [local count: 74478]:
  # DEBUG BEGIN_STMT
  state_42->init.zep_dst_ip_addr = &ip_addr_broadcast;

  <bb 13> [local count: 248259]:
  # DEBUG BEGIN_STMT
  netif_39(D)->state = 0B;
  # DEBUG BEGIN_STMT
  _6 = udp_new_ip_type (46);
  state_42->pcb = _6;
  # DEBUG BEGIN_STMT
  if (_6 == 0B)
    goto <bb 14>; [30.95%]
  else
    goto <bb 15>; [69.05%]

  <bb 14> [local count: 76836]:
  # DEBUG BEGIN_STMT
  # DEBUG err => -1
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 30>; [100.00%]

  <bb 15> [local count: 171423]:
  # DEBUG BEGIN_STMT
  _7 = state_42->init.zep_src_ip_addr;
  _8 = state_42->init.zep_src_udp_port;
  err_52 = udp_bind (_6, _7, _8);
  # DEBUG err => err_52
  # DEBUG BEGIN_STMT
  if (err_52 != 0)
    goto <bb 16>; [34.00%]
  else
    goto <bb 17>; [66.00%]

  <bb 16> [local count: 58284]:
  # DEBUG BEGIN_STMT
  // predicted unlikely by goto predictor.
  goto <bb 30>; [100.00%]

  <bb 17> [local count: 113139]:
  # DEBUG BEGIN_STMT
  _9 = state_42->init.zep_netif;
  if (_9 != 0B)
    goto <bb 18>; [53.47%]
  else
    goto <bb 19>; [46.53%]

  <bb 18> [local count: 60496]:
  # DEBUG BEGIN_STMT
  _10 = state_42->pcb;
  udp_bind_netif (_10, _9);

  <bb 19> [local count: 113139]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _11 = state_42->pcb;
  _12 = _11->so_options;
  _13 = _12 | 32;
  _11->so_options = _13;
  # DEBUG BEGIN_STMT
  udp_recv (_11, zepif_udp_recv, netif_39(D));
  # DEBUG BEGIN_STMT
  err_57 = lowpan6_if_init (netif_39(D));
  # DEBUG err => err_57
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _14 = netif_39(D)->state;
  if (_14 != 0B)
    goto <bb 35>; [70.00%]
  else
    goto <bb 21>; [30.00%]

  <bb 35> [local count: 79197]:

  <bb 20> [local count: 791976223]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 38> [local count: 791976223]:
  goto <bb 20>; [100.00%]

  <bb 21> [local count: 33942]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (err_57 == 0)
    goto <bb 22>; [34.00%]
  else
    goto <bb 30>; [66.00%]

  <bb 22> [local count: 11540]:
  # DEBUG BEGIN_STMT
  netif_39(D)->state = state_42;
  # DEBUG BEGIN_STMT
  netif_39(D)->hwaddr_len = 6;
  # DEBUG BEGIN_STMT
  if (init_state_40 != 0B)
    goto <bb 23>; [53.47%]
  else
    goto <bb 36>; [46.53%]

  <bb 36> [local count: 5370]:
  goto <bb 25>; [100.00%]

  <bb 23> [local count: 6171]:
  # DEBUG BEGIN_STMT
  _15 = &netif_39(D)->hwaddr;
  _16 = &init_state_40->addr;
  memcpy (_15, _16, 6);
  goto <bb 27>; [100.00%]

  <bb 24> [local count: 32207]:
  # DEBUG BEGIN_STMT
  _17 = (int) i_23;
  netif_39(D)->hwaddr[_17] = i_23;
  # DEBUG BEGIN_STMT
  i_62 = i_23 + 1;
  # DEBUG i => i_62

  <bb 25> [local count: 37576]:
  # i_23 = PHI <i_62(24), 0(36)>
  # DEBUG i => i_23
  # DEBUG BEGIN_STMT
  if (i_23 != 6)
    goto <bb 24>; [85.71%]
  else
    goto <bb 26>; [14.29%]

  <bb 26> [local count: 5370]:
  # DEBUG BEGIN_STMT
  _18 = netif_39(D)->hwaddr[0];
  _19 = _18 & 252;
  netif_39(D)->hwaddr[0] = _19;

  <bb 27> [local count: 11540]:
  # DEBUG BEGIN_STMT
  netif_39(D)->linkoutput = zepif_linkoutput;
  # DEBUG BEGIN_STMT
  zep_lowpan_timer_running.1_20 = zep_lowpan_timer_running;
  if (zep_lowpan_timer_running.1_20 == 0)
    goto <bb 28>; [33.00%]
  else
    goto <bb 29>; [67.00%]

  <bb 28> [local count: 3808]:
  # DEBUG BEGIN_STMT
  sys_timeout (1000, zep_lowpan_timer, 0B);
  # DEBUG BEGIN_STMT
  zep_lowpan_timer_running = 1;

  <bb 29> [local count: 11540]:
  # DEBUG BEGIN_STMT
  goto <bb 33>; [100.00%]

  <bb 30> [local count: 157522]:
  # err_22 = PHI <-1(14), err_52(16), err_57(21)>
err_ret:
  # DEBUG err => err_22
  # DEBUG BEGIN_STMT
  _21 = state_42->pcb;
  if (_21 != 0B)
    goto <bb 31>; [53.47%]
  else
    goto <bb 32>; [46.53%]

  <bb 31> [local count: 84227]:
  # DEBUG BEGIN_STMT
  udp_remove (_21);

  <bb 32> [local count: 157522]:
  # DEBUG BEGIN_STMT
  mem_free (state_42);
  # DEBUG BEGIN_STMT

  <bb 33> [local count: 171342]:
  # _24 = PHI <-1(4), 0(29), err_22(32)>
  return _24;

}


