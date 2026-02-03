
IPA constant propagation start:
Determining dynamic type for call: _22 (netif_30(D), &ip6_allnodes_ll, 1);
  Starting walk at: _22 (netif_30(D), &ip6_allnodes_ll, 1);
  instance pointer: netif_30(D)  Outer instance pointer: netif_30(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_20 = bridgeif_fdb_init (_19);
  Function call may change dynamic type:memcpy (_11, _12, 6);
  Function call may change dynamic type:br_37 = mem_calloc (1, alloc_len_sizet_35);
  Function call may change dynamic type:_3 = netif_alloc_client_data_id ();
Determining dynamic type for call: _22 (netif_30(D), &ip6_allnodes_ll, 1);
  Starting walk at: _22 (netif_30(D), &ip6_allnodes_ll, 1);
  instance pointer: &ip6_allnodes_ll  Outer instance pointer: ip6_allnodes_ll offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_20 = bridgeif_fdb_init (_19);
  Function call may change dynamic type:br_37 = mem_calloc (1, alloc_len_sizet_35);
  Function call may change dynamic type:_3 = netif_alloc_client_data_id ();
Determining dynamic type for call: _13 = bridgeif_is_local_mac (_3, dst_27);
  Starting walk at: _13 = bridgeif_is_local_mac (_3, dst_27);
  instance pointer: _3  Outer instance pointer: _3 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:bridgeif_fdb_update_src (_6, src_28, _7);
Determining dynamic type for call: _13 = bridgeif_is_local_mac (_3, dst_27);
  Starting walk at: _13 = bridgeif_is_local_mac (_3, dst_27);
  instance pointer: dst_27  Outer instance pointer: dst_27 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:bridgeif_fdb_update_src (_6, src_28, _7);
Determining dynamic type for call: dstports_32 = bridgeif_find_dst_ports (_3, dst_27);
  Starting walk at: dstports_32 = bridgeif_find_dst_ports (_3, dst_27);
  instance pointer: _3  Outer instance pointer: _3 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_13 = bridgeif_is_local_mac (_3, dst_27);
  Function call may change dynamic type:bridgeif_fdb_update_src (_6, src_28, _7);
Determining dynamic type for call: dstports_32 = bridgeif_find_dst_ports (_3, dst_27);
  Starting walk at: dstports_32 = bridgeif_find_dst_ports (_3, dst_27);
  instance pointer: dst_27  Outer instance pointer: dst_27 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_13 = bridgeif_is_local_mac (_3, dst_27);
  Function call may change dynamic type:bridgeif_fdb_update_src (_6, src_28, _7);
Determining dynamic type for call: bridgeif_send_to_ports (_3, p_21(D), dstports_32);
  Starting walk at: bridgeif_send_to_ports (_3, p_21(D), dstports_32);
  instance pointer: _3  Outer instance pointer: _3 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:dstports_32 = bridgeif_find_dst_ports (_3, dst_27);
  Function call may change dynamic type:_13 = bridgeif_is_local_mac (_3, dst_27);
  Function call may change dynamic type:bridgeif_fdb_update_src (_6, src_28, _7);
Determining dynamic type for call: bridgeif_send_to_ports (_3, p_21(D), dstports_32);
  Starting walk at: bridgeif_send_to_ports (_3, p_21(D), dstports_32);
  instance pointer: p_21(D)  Outer instance pointer: p_21(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:dstports_32 = bridgeif_find_dst_ports (_3, dst_27);
  Function call may change dynamic type:_13 = bridgeif_is_local_mac (_3, dst_27);
  Function call may change dynamic type:bridgeif_fdb_update_src (_6, src_28, _7);
Determining dynamic type for call: _37 = _15 (p_21(D), _14);
  Starting walk at: _37 = _15 (p_21(D), _14);
  instance pointer: p_21(D)  Outer instance pointer: p_21(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_13 = bridgeif_is_local_mac (_3, dst_27);
  Function call may change dynamic type:bridgeif_fdb_update_src (_6, src_28, _7);
Determining dynamic type for call: _37 = _15 (p_21(D), _14);
  Starting walk at: _37 = _15 (p_21(D), _14);
  instance pointer: _14  Outer instance pointer: _14 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_13 = bridgeif_is_local_mac (_3, dst_27);
  Function call may change dynamic type:bridgeif_fdb_update_src (_6, src_28, _7);
Determining dynamic type for call: dstports_39 = bridgeif_find_dst_ports (_3, dst_27);
  Starting walk at: dstports_39 = bridgeif_find_dst_ports (_3, dst_27);
  instance pointer: _3  Outer instance pointer: _3 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:bridgeif_fdb_update_src (_6, src_28, _7);
Determining dynamic type for call: dstports_39 = bridgeif_find_dst_ports (_3, dst_27);
  Starting walk at: dstports_39 = bridgeif_find_dst_ports (_3, dst_27);
  instance pointer: dst_27  Outer instance pointer: dst_27 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:bridgeif_fdb_update_src (_6, src_28, _7);
Determining dynamic type for call: bridgeif_send_to_ports (_3, p_21(D), dstports_39);
  Starting walk at: bridgeif_send_to_ports (_3, p_21(D), dstports_39);
  instance pointer: _3  Outer instance pointer: _3 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:dstports_39 = bridgeif_find_dst_ports (_3, dst_27);
  Function call may change dynamic type:bridgeif_fdb_update_src (_6, src_28, _7);
Determining dynamic type for call: bridgeif_send_to_ports (_3, p_21(D), dstports_39);
  Starting walk at: bridgeif_send_to_ports (_3, p_21(D), dstports_39);
  instance pointer: p_21(D)  Outer instance pointer: p_21(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:dstports_39 = bridgeif_find_dst_ports (_3, dst_27);
  Function call may change dynamic type:bridgeif_fdb_update_src (_6, src_28, _7);
Determining dynamic type for call: _12 = _11 (p_21(D), _10);
  Starting walk at: _12 = _11 (p_21(D), _10);
  instance pointer: p_21(D)  Outer instance pointer: p_21(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:bridgeif_send_to_ports (_3, p_21(D), dstports_39);
  Function call may change dynamic type:dstports_39 = bridgeif_find_dst_ports (_3, dst_27);
  Function call may change dynamic type:bridgeif_fdb_update_src (_6, src_28, _7);
Determining dynamic type for call: _12 = _11 (p_21(D), _10);
  Starting walk at: _12 = _11 (p_21(D), _10);
  instance pointer: _10  Outer instance pointer: _10 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:bridgeif_send_to_ports (_3, p_21(D), dstports_39);
  Function call may change dynamic type:dstports_39 = bridgeif_find_dst_ports (_3, dst_27);
  Function call may change dynamic type:bridgeif_fdb_update_src (_6, src_28, _7);
Determining dynamic type for call: dstports_20 = bridgeif_find_dst_ports (br_16, dst_18);
  Starting walk at: dstports_20 = bridgeif_find_dst_ports (br_16, dst_18);
  instance pointer: br_16  Outer instance pointer: br_16 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: dstports_20 = bridgeif_find_dst_ports (br_16, dst_18);
  Starting walk at: dstports_20 = bridgeif_find_dst_ports (br_16, dst_18);
  instance pointer: dst_18  Outer instance pointer: dst_18 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: err_22 = bridgeif_send_to_ports (br_16, p_17(D), dstports_20);
  Starting walk at: err_22 = bridgeif_send_to_ports (br_16, p_17(D), dstports_20);
  instance pointer: br_16  Outer instance pointer: br_16 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:dstports_20 = bridgeif_find_dst_ports (br_16, dst_18);
Determining dynamic type for call: err_22 = bridgeif_send_to_ports (br_16, p_17(D), dstports_20);
  Starting walk at: err_22 = bridgeif_send_to_ports (br_16, p_17(D), dstports_20);
  instance pointer: p_17(D)  Outer instance pointer: p_17(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:dstports_20 = bridgeif_find_dst_ports (br_16, dst_18);
Determining dynamic type for call: err_17 = bridgeif_send_to_port (br_14(D), p_15(D), i_5);
  Starting walk at: err_17 = bridgeif_send_to_port (br_14(D), p_15(D), i_5);
  instance pointer: br_14(D)  Outer instance pointer: br_14(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:lev_11 = sys_arch_protect ();
  Function call may change dynamic type:err_17 = bridgeif_send_to_port (br_14(D), p_15(D), i_5);
Determining dynamic type for call: err_17 = bridgeif_send_to_port (br_14(D), p_15(D), i_5);
  Starting walk at: err_17 = bridgeif_send_to_port (br_14(D), p_15(D), i_5);
  instance pointer: p_15(D)  Outer instance pointer: p_15(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:lev_11 = sys_arch_protect ();
  Function call may change dynamic type:err_17 = bridgeif_send_to_port (br_14(D), p_15(D), i_5);
Determining dynamic type for call: _24 = _6 (portif_21, p_22(D));
  Starting walk at: _24 = _6 (portif_21, p_22(D));
  instance pointer: portif_21  Outer instance pointer: portif_21 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _24 = _6 (portif_21, p_22(D));
  Starting walk at: _24 = _6 (portif_21, p_22(D));
  instance pointer: p_22(D)  Outer instance pointer: p_22(D) offset: 0 (bits) vtbl reference: 

IPA structures before propagation:

Jump functions:
  Jump functions of caller  pbuf_free/26:
  Jump functions of caller  bridgeif_fdb_update_src/25:
  Jump functions of caller  bridgeif_fdb_get_dst_ports/24:
  Jump functions of caller  ethip6_output/22:
  Jump functions of caller  etharp_output/21:
  Jump functions of caller  mem_free/20:
  Jump functions of caller  bridgeif_fdb_init/19:
  Jump functions of caller  mem_calloc/18:
  Jump functions of caller  netif_alloc_client_data_id/17:
  Jump functions of caller  memset/16:
  Jump functions of caller  memcmp/15:
  Jump functions of caller  sys_arch_unprotect/14:
  Jump functions of caller  memcpy/13:
  Jump functions of caller  sys_arch_protect/12:
  Jump functions of caller  bridgeif_add_port/11:
  Jump functions of caller  bridgeif_init/10:
    indirect aggregate callsite, calling param 0, offset 2304, by reference, for stmt _22 (netif_30(D), &ip6_allnodes_ll, 1);
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         Aggregate passed by reference:
           offset: 0, cst: 767
           offset: 32, cst: 0
           offset: 64, cst: 0
           offset: 96, cst: 16777216
           offset: 128, cst: 0
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
  Jump functions of caller  bridgeif_input/9:
    callsite  bridgeif_input/9 -> bridgeif_send_to_ports/7 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  bridgeif_input/9 -> bridgeif_find_dst_ports/4 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  bridgeif_input/9 -> bridgeif_is_local_mac/5 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  bridgeif_input/9 -> bridgeif_send_to_ports/7 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  bridgeif_input/9 -> bridgeif_find_dst_ports/4 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    indirect simple callsite, calling param -1, offset 0, for stmt _37 = _15 (p_21(D), _14);
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    indirect simple callsite, calling param -1, offset 0, for stmt _12 = _11 (p_21(D), _10);
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  bridgeif_output/8:
    callsite  bridgeif_output/8 -> bridgeif_send_to_ports/7 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  bridgeif_output/8 -> bridgeif_find_dst_ports/4 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  bridgeif_send_to_ports/7:
    callsite  bridgeif_send_to_ports/7 -> bridgeif_send_to_port/6 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0x7
         VR  [0, 7]
  Jump functions of caller  bridgeif_send_to_port/6:
    indirect simple callsite, calling param -1, offset 0, for stmt _24 = _6 (portif_21, p_22(D));
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  bridgeif_is_local_mac/5:
  Jump functions of caller  bridgeif_find_dst_ports/4:
  Jump functions of caller  bridgeif_fdb_remove/3:
  Jump functions of caller  bridgeif_fdb_add/2:

 Propagating constants:

Not considering bridgeif_add_port for cloning; -fipa-cp-clone disabled.
Not considering bridgeif_init for cloning; -fipa-cp-clone disabled.
Not considering bridgeif_input for cloning; -fipa-cp-clone disabled.
Not considering bridgeif_output for cloning; -fipa-cp-clone disabled.
Not considering bridgeif_fdb_remove for cloning; -fipa-cp-clone disabled.
Not considering bridgeif_fdb_add for cloning; -fipa-cp-clone disabled.

overall_size: 460, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: bridgeif_add_port/11:
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
  Node: bridgeif_init/10:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: bridgeif_input/9:
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
  Node: bridgeif_output/8:
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
  Node: bridgeif_send_to_ports/7:
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
  Node: bridgeif_send_to_port/6:
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
         Bits: value = 0x0, mask = 0x7
         u8_t [0, 7]
        AGGS VARIABLE
  Node: bridgeif_is_local_mac/5:
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
  Node: bridgeif_find_dst_ports/4:
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
  Node: bridgeif_fdb_remove/3:
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
  Node: bridgeif_fdb_add/2:
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

IPA decision stage:

Propagated bits info for function bridgeif_send_to_port/6:
 param 2: value = 0x0, mask = 0x7

IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

pbuf_free/26 (pbuf_free) @062349a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: bridgeif_input/9 (54322 (estimated locally),0.15 per call) bridgeif_input/9 (35175 (estimated locally),0.10 per call) bridgeif_input/9 (16376 (estimated locally),0.05 per call) 
  Calls: 
bridgeif_fdb_update_src/25 (bridgeif_fdb_update_src) @062348c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: bridgeif_input/9 (82306 (estimated locally),0.23 per call) 
  Calls: 
bridgeif_fdb_get_dst_ports/24 (bridgeif_fdb_get_dst_ports) @06234380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: bridgeif_find_dst_ports/4 (46228881 (estimated locally),0.53 per call) 
  Calls: 
lwip_stats/23 (lwip_stats) @062333a8
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: bridgeif_output/8 (read)bridgeif_output/8 (write)
  Availability: not_available
  Varpool flags:
ethip6_output/22 (ethip6_output) @062340e0
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: bridgeif_init/10 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
etharp_output/21 (etharp_output) @06234000
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: bridgeif_init/10 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
mem_free/20 (mem_free) @061f0000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: bridgeif_init/10 (181 (estimated locally),0.00 per call) 
  Calls: 
bridgeif_fdb_init/19 (bridgeif_fdb_init) @061f0ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: bridgeif_init/10 (40144 (estimated locally),0.11 per call) 
  Calls: 
mem_calloc/18 (mem_calloc) @061f0e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: bridgeif_init/10 (40512 (estimated locally),0.11 per call) 
  Calls: 
netif_alloc_client_data_id/17 (netif_alloc_client_data_id) @061f0d20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: bridgeif_init/10 (35496 (estimated locally),0.10 per call) 
  Calls: 
memset/16 (memset) @061f0a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: bridgeif_fdb_remove/3 (39593 (estimated locally),0.12 per call) 
  Calls: 
memcmp/15 (memcmp) @061f09a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: bridgeif_fdb_remove/3 (719880 (estimated locally),2.18 per call) bridgeif_find_dst_ports/4 (507343012 (estimated locally),5.83 per call) bridgeif_is_local_mac/5 (710280216 (estimated locally),3.54 per call) bridgeif_is_local_mac/5 (200738981 (estimated locally),1.00 per call) 
  Calls: 
sys_arch_unprotect/14 (sys_arch_unprotect) @061f07e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: bridgeif_fdb_remove/3 (83796 (estimated locally),0.25 per call) bridgeif_fdb_remove/3 (39593 (estimated locally),0.12 per call) bridgeif_fdb_add/2 (63439 (estimated locally),0.19 per call) bridgeif_fdb_add/2 (59950 (estimated locally),0.18 per call) bridgeif_find_dst_ports/4 (46228881 (estimated locally),0.53 per call) bridgeif_find_dst_ports/4 (12826920 (estimated locally),0.15 per call) bridgeif_find_dst_ports/4 (27903866 (estimated locally),0.32 per call) bridgeif_is_local_mac/5 (59055800 (estimated locally),0.29 per call) bridgeif_is_local_mac/5 (39065412 (estimated locally),0.19 per call) bridgeif_send_to_ports/7 (134217728 (estimated locally),1.00 per call) 
  Calls: 
memcpy/13 (memcpy) @061f0700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: bridgeif_init/10 (39963 (estimated locally),0.11 per call) bridgeif_init/10 (40144 (estimated locally),0.11 per call) bridgeif_fdb_add/2 (59950 (estimated locally),0.18 per call) 
  Calls: 
sys_arch_protect/12 (sys_arch_protect) @061f0620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: bridgeif_fdb_remove/3 (123389 (estimated locally),0.37 per call) bridgeif_fdb_add/2 (123389 (estimated locally),0.37 per call) bridgeif_find_dst_ports/4 (86959666 (estimated locally),1.00 per call) bridgeif_is_local_mac/5 (98121214 (estimated locally),0.49 per call) bridgeif_send_to_ports/7 (134217728 (estimated locally),1.00 per call) 
  Calls: 
bridgeif_add_port/11 (bridgeif_add_port) @061f01c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: bridgeif_input/9 (addr)bridgeif_netif_client_id/1 (read)
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: 
  Calls: 
bridgeif_init/10 (bridgeif_init) @061d8d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: bridgeif_netif_client_id/1 (read)bridgeif_netif_client_id/1 (write)etharp_output/21 (addr)ethip6_output/22 (addr)bridgeif_output/8 (addr)
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: 
  Calls: memcpy/13 (39963 (estimated locally),0.11 per call) mem_free/20 (181 (estimated locally),0.00 per call) bridgeif_fdb_init/19 (40144 (estimated locally),0.11 per call) memcpy/13 (40144 (estimated locally),0.11 per call) mem_calloc/18 (40512 (estimated locally),0.11 per call) netif_alloc_client_data_id/17 (35496 (estimated locally),0.10 per call) 
   Indirect call(27974 (estimated locally),0.08 per call)  of param:0 loaded from aggregate passed by reference at offset 2304 (vptr maybe changed)
bridgeif_input/9 (bridgeif_input) @061d8c40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: bridgeif_netif_client_id/1 (read)
  Referring: bridgeif_add_port/11 (addr)
  Availability: available
  Function flags: count:361156 (estimated locally) body optimize_size
  Called by: 
  Calls: pbuf_free/26 (54322 (estimated locally),0.15 per call) bridgeif_send_to_ports/7 (54322 (estimated locally),0.15 per call) bridgeif_find_dst_ports/4 (54322 (estimated locally),0.15 per call) bridgeif_is_local_mac/5 (164612 (estimated locally),0.46 per call) pbuf_free/26 (35175 (estimated locally),0.10 per call) pbuf_free/26 (16376 (estimated locally),0.05 per call) bridgeif_send_to_ports/7 (84800 (estimated locally),0.23 per call) bridgeif_find_dst_ports/4 (84800 (estimated locally),0.23 per call) bridgeif_fdb_update_src/25 (82306 (estimated locally),0.23 per call) 
   Indirect call(110290 (estimated locally),0.31 per call) 
   Indirect call(49625 (estimated locally),0.14 per call) 
bridgeif_output/8 (bridgeif_output) @061d89a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: lwip_stats/23 (read)lwip_stats/23 (write)
  Referring: bridgeif_init/10 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: bridgeif_send_to_ports/7 (1073741824 (estimated locally),1.00 per call) bridgeif_find_dst_ports/4 (1073741824 (estimated locally),1.00 per call) 
bridgeif_send_to_ports/7 (bridgeif_send_to_ports) @061d8460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:134217728 (estimated locally) body local optimize_size
  Called by: bridgeif_input/9 (54322 (estimated locally),0.15 per call) bridgeif_input/9 (84800 (estimated locally),0.23 per call) bridgeif_output/8 (1073741824 (estimated locally),1.00 per call) 
  Calls: sys_arch_unprotect/14 (134217728 (estimated locally),1.00 per call) bridgeif_send_to_port/6 (310042952 (estimated locally),2.31 per call) sys_arch_protect/12 (134217728 (estimated locally),1.00 per call) 
bridgeif_send_to_port/6 (bridgeif_send_to_port) @061d81c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:325376 (estimated locally) body local optimize_size
  Called by: bridgeif_send_to_ports/7 (310042952 (estimated locally),2.31 per call) 
  Calls: 
   Indirect call(8944 (estimated locally),0.03 per call) 
bridgeif_is_local_mac/5 (bridgeif_is_local_mac) @061cc620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:200738981 (estimated locally) body local optimize_size
  Called by: bridgeif_input/9 (164612 (estimated locally),0.46 per call) 
  Calls: sys_arch_unprotect/14 (59055800 (estimated locally),0.29 per call) sys_arch_unprotect/14 (39065412 (estimated locally),0.19 per call) memcmp/15 (710280216 (estimated locally),3.54 per call) sys_arch_protect/12 (98121214 (estimated locally),0.49 per call) memcmp/15 (200738981 (estimated locally),1.00 per call) 
bridgeif_find_dst_ports/4 (bridgeif_find_dst_ports) @061ccd20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:86959666 (estimated locally) body local optimize_size
  Called by: bridgeif_input/9 (54322 (estimated locally),0.15 per call) bridgeif_input/9 (84800 (estimated locally),0.23 per call) bridgeif_output/8 (1073741824 (estimated locally),1.00 per call) 
  Calls: bridgeif_fdb_get_dst_ports/24 (46228881 (estimated locally),0.53 per call) sys_arch_unprotect/14 (46228881 (estimated locally),0.53 per call) sys_arch_unprotect/14 (12826920 (estimated locally),0.15 per call) sys_arch_unprotect/14 (27903866 (estimated locally),0.32 per call) memcmp/15 (507343012 (estimated locally),5.83 per call) sys_arch_protect/12 (86959666 (estimated locally),1.00 per call) 
bridgeif_fdb_remove/3 (bridgeif_fdb_remove) @061cca80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:329661 (estimated locally) body optimize_size
  Called by: 
  Calls: sys_arch_unprotect/14 (83796 (estimated locally),0.25 per call) sys_arch_unprotect/14 (39593 (estimated locally),0.12 per call) memset/16 (39593 (estimated locally),0.12 per call) memcmp/15 (719880 (estimated locally),2.18 per call) sys_arch_protect/12 (123389 (estimated locally),0.37 per call) 
bridgeif_fdb_add/2 (bridgeif_fdb_add) @061cc7e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:329661 (estimated locally) body optimize_size
  Called by: 
  Calls: sys_arch_unprotect/14 (63439 (estimated locally),0.19 per call) sys_arch_unprotect/14 (59950 (estimated locally),0.18 per call) memcpy/13 (59950 (estimated locally),0.18 per call) sys_arch_protect/12 (123389 (estimated locally),0.37 per call) 
bridgeif_netif_client_id/1 (bridgeif_netif_client_id) @061c7948
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: bridgeif_input/9 (read)bridgeif_init/10 (write)bridgeif_init/10 (read)bridgeif_add_port/11 (read)
  Availability: available
  Varpool flags: initialized

;; Function bridgeif_send_to_ports (bridgeif_send_to_ports, funcdef_no=6, decl_uid=7281, cgraph_uid=7, symbol_order=7)

Modification phase of node bridgeif_send_to_ports/7
bridgeif_send_to_ports (struct bridgeif_private_t * br, struct pbuf * p, bridgeif_portmask_t dstports)
{
  sys_prot_t lev;
  bridgeif_portmask_t mask;
  u8_t i;
  err_t ret_err;
  err_t err;
  unsigned char _1;

  <bb 2> [local count: 134217728]:
  # DEBUG BEGIN_STMT
  # DEBUG ret_err => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG mask => 1
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  lev_11 = sys_arch_protect ();
  # DEBUG lev => lev_11
  # DEBUG BEGIN_STMT
  # DEBUG i => 0
  goto <bb 7>; [100.00%]

  <bb 3> [local count: 939524097]:
  # DEBUG BEGIN_STMT
  _1 = mask_6 & dstports_13(D);
  if (_1 != 0)
    goto <bb 4>; [33.00%]
  else
    goto <bb 6>; [67.00%]

  <bb 4> [local count: 310042952]:
  # DEBUG BEGIN_STMT
  err_17 = bridgeif_send_to_port (br_14(D), p_15(D), i_5);
  # DEBUG err => err_17
  # DEBUG BEGIN_STMT
  if (err_17 != 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 5> [local count: 155021476]:
  # DEBUG BEGIN_STMT
  # DEBUG ret_err => err_17

  <bb 6> [local count: 939524097]:
  # ret_err_3 = PHI <ret_err_4(3), ret_err_4(4), err_17(5)>
  # DEBUG ret_err => ret_err_3
  # DEBUG BEGIN_STMT
  i_18 = i_5 + 1;
  # DEBUG i => i_18
  mask_19 = mask_6 << 1;
  # DEBUG mask => mask_19

  <bb 7> [local count: 1073741824]:
  # ret_err_4 = PHI <0(2), ret_err_3(6)>
  # i_5 = PHI <0(2), i_18(6)>
  # mask_6 = PHI <1(2), mask_19(6)>
  # DEBUG mask => mask_6
  # DEBUG i => i_5
  # DEBUG ret_err => ret_err_4
  # DEBUG BEGIN_STMT
  if (i_5 != 7)
    goto <bb 3>; [87.50%]
  else
    goto <bb 8>; [12.50%]

  <bb 8> [local count: 134217728]:
  # ret_err_2 = PHI <ret_err_4(7)>
  # DEBUG BEGIN_STMT
  sys_arch_unprotect (lev_11);
  # DEBUG BEGIN_STMT
  return ret_err_2;

}



;; Function bridgeif_find_dst_ports (bridgeif_find_dst_ports, funcdef_no=3, decl_uid=7253, cgraph_uid=4, symbol_order=4)

Modification phase of node bridgeif_find_dst_ports/4
bridgeif_find_dst_ports (struct bridgeif_private_t * br, struct eth_addr * dst_addr)
{
  bridgeif_portmask_t ret;
  sys_prot_t lev;
  int i;
  struct bridgeif_fdb_static_entry_t * _1;
  unsigned int i.11_2;
  unsigned int _3;
  struct bridgeif_fdb_static_entry_t * _4;
  unsigned char _5;
  struct bridgeif_fdb_static_entry_t * _6;
  struct eth_addr * _7;
  int _8;
  short unsigned int _9;
  int _10;
  unsigned char _11;
  void * _12;
  bridgeif_portmask_t _14;
  unsigned char _19;
  bridgeif_portmask_t _24;

  <bb 2> [local count: 86959666]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  lev_18 = sys_arch_protect ();
  # DEBUG lev => lev_18
  # DEBUG BEGIN_STMT
  # DEBUG i => 0
  goto <bb 7>; [100.00%]

  <bb 3> [local count: 1014686025]:
  # DEBUG BEGIN_STMT
  _1 = br_20(D)->fdbs;
  i.11_2 = (unsigned int) i_13;
  _3 = i.11_2 * 8;
  _4 = _1 + _3;
  _5 = _4->used;
  if (_5 != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 4> [local count: 507343012]:
  # DEBUG BEGIN_STMT
  _7 = &_4->addr;
  _8 = memcmp (_7, dst_addr_21(D), 6);
  if (_8 == 0)
    goto <bb 5>; [5.50%]
  else
    goto <bb 6>; [94.50%]

  <bb 5> [local count: 27903866]:
  # _6 = PHI <_4(4)>
  # DEBUG BEGIN_STMT
  ret_26 = _6->dst_ports;
  # DEBUG ret => ret_26
  # DEBUG BEGIN_STMT
  sys_arch_unprotect (lev_18);
  # DEBUG BEGIN_STMT
  goto <bb 11>; [100.00%]

  <bb 6> [local count: 986782159]:
  # DEBUG BEGIN_STMT
  i_28 = i_13 + 1;
  # DEBUG i => i_28

  <bb 7> [local count: 1073741824]:
  # i_13 = PHI <0(2), i_28(6)>
  # DEBUG i => i_13
  # DEBUG BEGIN_STMT
  _9 = br_20(D)->max_fdbs_entries;
  _10 = (int) _9;
  if (_10 > i_13)
    goto <bb 3>; [94.50%]
  else
    goto <bb 8>; [5.50%]

  <bb 8> [local count: 59055800]:
  # DEBUG BEGIN_STMT
  _11 = dst_addr_21(D)->addr[0];
  _19 = _11 & 1;
  if (_19 != 0)
    goto <bb 9>; [21.72%]
  else
    goto <bb 10>; [78.28%]

  <bb 9> [local count: 12826920]:
  # DEBUG BEGIN_STMT
  sys_arch_unprotect (lev_18);
  # DEBUG BEGIN_STMT
  goto <bb 11>; [100.00%]

  <bb 10> [local count: 46228881]:
  # DEBUG BEGIN_STMT
  sys_arch_unprotect (lev_18);
  # DEBUG BEGIN_STMT
  _12 = br_20(D)->fdbd;
  _24 = bridgeif_fdb_get_dst_ports (_12, dst_addr_21(D));

  <bb 11> [local count: 86959666]:
  # _14 = PHI <ret_26(5), 255(9), _24(10)>
  return _14;

}



;; Function bridgeif_output (bridgeif_output, funcdef_no=7, decl_uid=7293, cgraph_uid=8, symbol_order=8)

Modification phase of node bridgeif_output/8
bridgeif_output (struct netif * netif, struct pbuf * p)
{
  bridgeif_portmask_t dstports;
  struct eth_addr * dst;
  struct bridgeif_private_t * br;
  err_t err;
  long unsigned int _1;
  short unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  void * _5;
  unsigned char _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  short unsigned int _11;
  short unsigned int _12;
  unsigned char _27;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  br_16 = netif_15(D)->state;
  # DEBUG br => br_16
  # DEBUG BEGIN_STMT
  dst_18 = p_17(D)->payload;
  # DEBUG dst => dst_18
  # DEBUG BEGIN_STMT
  dstports_20 = bridgeif_find_dst_ports (br_16, dst_18);
  # DEBUG dstports => dstports_20
  # DEBUG BEGIN_STMT
  err_22 = bridgeif_send_to_ports (br_16, p_17(D), dstports_20);
  # DEBUG err => err_22
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = netif_15(D)->mib2_counters.ifoutoctets;
  _2 = p_17(D)->tot_len;
  _3 = (long unsigned int) _2;
  _4 = _1 + _3;
  netif_15(D)->mib2_counters.ifoutoctets = _4;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _5 = p_17(D)->payload;
  _6 = MEM[(u8_t *)_5];
  _27 = _6 & 1;
  if (_27 != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _7 = netif_15(D)->mib2_counters.ifoutnucastpkts;
  _8 = _7 + 1;
  netif_15(D)->mib2_counters.ifoutnucastpkts = _8;
  # DEBUG BEGIN_STMT
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _9 = netif_15(D)->mib2_counters.ifoutucastpkts;
  _10 = _9 + 1;
  netif_15(D)->mib2_counters.ifoutucastpkts = _10;

  <bb 5> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _11 = lwip_stats.link.xmit;
  _12 = _11 + 1;
  lwip_stats.link.xmit = _12;
  # DEBUG BEGIN_STMT
  return err_22;

}



;; Function bridgeif_input (bridgeif_input, funcdef_no=8, decl_uid=7301, cgraph_uid=9, symbol_order=9)

Modification phase of node bridgeif_input/9
bridgeif_input (struct pbuf * p, struct netif * netif)
{
  struct bridgeif_port_t * port;
  struct eth_addr * dst;
  struct eth_addr * src;
  bridgeif_portmask_t dstports;
  u8_t rx_idx;
  unsigned char bridgeif_netif_client_id.16_1;
  int _2;
  struct bridgeif_private_s * _3;
  unsigned char _4;
  unsigned char _5;
  void * _6;
  unsigned char _7;
  unsigned char _8;
  signed char dstports.17_9;
  struct netif * _10;
  err_t (*<T6c9>) (struct pbuf *, struct netif *) _11;
  signed char _12;
  int _13;
  struct netif * _14;
  err_t (*<T6c9>) (struct pbuf *, struct netif *) _15;
  err_t _16;
  unsigned char _35;
  err_t _37;
  unsigned char _44;

  <bb 2> [local count: 361156]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (p_21(D) == 0B)
    goto <bb 18>; [0.45%]
  else
    goto <bb 3>; [99.55%]

  <bb 3> [local count: 359531]:
  if (netif_22(D) == 0B)
    goto <bb 18>; [0.45%]
  else
    goto <bb 4>; [99.55%]

  <bb 4> [local count: 357913]:
  # DEBUG BEGIN_STMT
  bridgeif_netif_client_id.16_1 = bridgeif_netif_client_id;
  _2 = (int) bridgeif_netif_client_id.16_1;
  port_24 = netif_22(D)->client_data[_2];
  # DEBUG port => port_24
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (port_24 == 0B)
    goto <bb 19>; [30.00%]
  else
    goto <bb 6>; [70.00%]

  <bb 19> [local count: 107374]:

  <bb 5> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 20> [local count: 1073741824]:
  goto <bb 5>; [100.00%]

  <bb 6> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _3 = port_24->bridge;
  if (_3 == 0B)
    goto <bb 18>; [0.45%]
  else
    goto <bb 7>; [99.55%]

  <bb 7> [local count: 249412]:
  # DEBUG BEGIN_STMT
  # DEBUG br => _3
  # DEBUG BEGIN_STMT
  _4 = netif_22(D)->num;
  rx_idx_25 = _4 + 1;
  # DEBUG rx_idx => rx_idx_25
  # DEBUG BEGIN_STMT
  p_21(D)->if_idx = rx_idx_25;
  # DEBUG BEGIN_STMT
  dst_27 = p_21(D)->payload;
  # DEBUG dst => dst_27
  # DEBUG BEGIN_STMT
  src_28 = dst_27 + 6;
  # DEBUG src => src_28
  # DEBUG BEGIN_STMT
  _5 = MEM[(struct eth_addr *)dst_27 + 6B].addr[0];
  _35 = _5 & 1;
  if (_35 == 0)
    goto <bb 8>; [33.00%]
  else
    goto <bb 9>; [67.00%]

  <bb 8> [local count: 82306]:
  # DEBUG BEGIN_STMT
  _6 = MEM[(struct bridgeif_private_t *)_3].fdbd;
  _7 = port_24->port_num;
  bridgeif_fdb_update_src (_6, src_28, _7);

  <bb 9> [local count: 249412]:
  # DEBUG BEGIN_STMT
  _8 = dst_27->addr[0];
  _44 = _8 & 1;
  if (_44 != 0)
    goto <bb 10>; [34.00%]
  else
    goto <bb 15>; [66.00%]

  <bb 10> [local count: 84800]:
  # DEBUG BEGIN_STMT
  dstports_39 = bridgeif_find_dst_ports (_3, dst_27);
  # DEBUG dstports => dstports_39
  # DEBUG BEGIN_STMT
  bridgeif_send_to_ports (_3, p_21(D), dstports_39);
  # DEBUG BEGIN_STMT
  dstports.17_9 = (signed char) dstports_39;
  if (dstports.17_9 < 0)
    goto <bb 11>; [58.52%]
  else
    goto <bb 13>; [41.48%]

  <bb 11> [local count: 49625]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _10 = MEM[(struct bridgeif_private_t *)_3].netif;
  _11 = _10->input;
  _12 = _11 (p_21(D), _10);
  if (_12 != 0)
    goto <bb 12>; [33.00%]
  else
    goto <bb 14>; [67.00%]

  <bb 12> [local count: 16376]:
  # DEBUG BEGIN_STMT
  pbuf_free (p_21(D));
  goto <bb 14>; [100.00%]

  <bb 13> [local count: 35175]:
  # DEBUG BEGIN_STMT
  pbuf_free (p_21(D));

  <bb 14> [local count: 84800]:
  # DEBUG BEGIN_STMT
  goto <bb 18>; [100.00%]

  <bb 15> [local count: 164612]:
  # DEBUG BEGIN_STMT
  _13 = bridgeif_is_local_mac (_3, dst_27);
  if (_13 != 0)
    goto <bb 16>; [67.00%]
  else
    goto <bb 17>; [33.00%]

  <bb 16> [local count: 110290]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _14 = MEM[(struct bridgeif_private_t *)_3].netif;
  _15 = _14->input;
  _37 = _15 (p_21(D), _14);
  goto <bb 18>; [100.00%]

  <bb 17> [local count: 54322]:
  # DEBUG BEGIN_STMT
  dstports_32 = bridgeif_find_dst_ports (_3, dst_27);
  # DEBUG dstports => dstports_32
  # DEBUG BEGIN_STMT
  bridgeif_send_to_ports (_3, p_21(D), dstports_32);
  # DEBUG BEGIN_STMT
  pbuf_free (p_21(D));
  # DEBUG BEGIN_STMT

  <bb 18> [local count: 253782]:
  # _16 = PHI <-6(3), -6(6), 0(14), _37(16), 0(17), -6(2)>
  return _16;

}



;; Function bridgeif_fdb_add (bridgeif_fdb_add, funcdef_no=1, decl_uid=6276, cgraph_uid=2, symbol_order=2)

Modification phase of node bridgeif_fdb_add/2
bridgeif_fdb_add (struct netif * bridgeif, const struct eth_addr * addr, bridgeif_portmask_t ports)
{
  sys_prot_t lev;
  struct bridgeif_private_t * br;
  int i;
  struct bridgeif_fdb_static_entry_t * _1;
  unsigned int i.0_2;
  unsigned int _3;
  struct bridgeif_fdb_static_entry_t * _4;
  unsigned char _5;
  struct bridgeif_fdb_static_entry_t * _6;
  struct eth_addr * _7;
  short unsigned int _8;
  int _9;
  err_t _11;

  <bb 2> [local count: 329661]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (bridgeif_15(D) == 0B)
    goto <bb 13>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 13> [local count: 98898]:

  <bb 3> [local count: 988985746]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 15> [local count: 988985746]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 230763]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  br_17 = bridgeif_15(D)->state;
  # DEBUG br => br_17
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (br_17 == 0B)
    goto <bb 14>; [46.53%]
  else
    goto <bb 6>; [53.47%]

  <bb 14> [local count: 107374]:

  <bb 5> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 16> [local count: 1073741824]:
  goto <bb 5>; [100.00%]

  <bb 6> [local count: 123389]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  lev_19 = sys_arch_protect ();
  # DEBUG lev => lev_19
  # DEBUG BEGIN_STMT
  # DEBUG i => 0
  goto <bb 10>; [100.00%]

  <bb 7> [local count: 1089998]:
  # DEBUG BEGIN_STMT
  _1 = br_17->fdbs;
  i.0_2 = (unsigned int) i_10;
  _3 = i.0_2 * 8;
  _4 = _1 + _3;
  _5 = _4->used;
  if (_5 == 0)
    goto <bb 8>; [5.50%]
  else
    goto <bb 9>; [94.50%]

  <bb 8> [local count: 59950]:
  # _6 = PHI <_4(7)>
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _6->used = 1;
  # DEBUG BEGIN_STMT
  _6->dst_ports = ports_22(D);
  # DEBUG BEGIN_STMT
  _7 = &_6->addr;
  memcpy (_7, addr_24(D), 6);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  sys_arch_unprotect (lev_19);
  # DEBUG BEGIN_STMT
  goto <bb 12>; [100.00%]

  <bb 9> [local count: 1030048]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  i_27 = i_10 + 1;
  # DEBUG i => i_27

  <bb 10> [local count: 1153437]:
  # i_10 = PHI <0(6), i_27(9)>
  # DEBUG i => i_10
  # DEBUG BEGIN_STMT
  _8 = br_17->max_fdbs_entries;
  _9 = (int) _8;
  if (_9 > i_10)
    goto <bb 7>; [94.50%]
  else
    goto <bb 11>; [5.50%]

  <bb 11> [local count: 63439]:
  # DEBUG BEGIN_STMT
  sys_arch_unprotect (lev_19);
  # DEBUG BEGIN_STMT

  <bb 12> [local count: 123389]:
  # _11 = PHI <0(8), -1(11)>
  return _11;

}



;; Function bridgeif_fdb_remove (bridgeif_fdb_remove, funcdef_no=2, decl_uid=6279, cgraph_uid=3, symbol_order=3)

Modification phase of node bridgeif_fdb_remove/3
bridgeif_fdb_remove (struct netif * bridgeif, const struct eth_addr * addr)
{
  sys_prot_t lev;
  struct bridgeif_private_t * br;
  int i;
  struct bridgeif_fdb_static_entry_t * _1;
  unsigned int i.5_2;
  unsigned int _3;
  struct bridgeif_fdb_static_entry_t * _4;
  unsigned char _5;
  struct bridgeif_fdb_static_entry_t * _6;
  struct eth_addr * _7;
  int _8;
  short unsigned int _9;
  int _10;
  err_t _12;

  <bb 2> [local count: 329661]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (bridgeif_16(D) == 0B)
    goto <bb 14>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 14> [local count: 98898]:

  <bb 3> [local count: 988985746]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 16> [local count: 988985746]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 230763]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  br_18 = bridgeif_16(D)->state;
  # DEBUG br => br_18
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (br_18 == 0B)
    goto <bb 15>; [46.53%]
  else
    goto <bb 6>; [53.47%]

  <bb 15> [local count: 107374]:

  <bb 5> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 17> [local count: 1073741824]:
  goto <bb 5>; [100.00%]

  <bb 6> [local count: 123389]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  lev_20 = sys_arch_protect ();
  # DEBUG lev => lev_20
  # DEBUG BEGIN_STMT
  # DEBUG i => 0
  goto <bb 11>; [100.00%]

  <bb 7> [local count: 1439760]:
  # DEBUG BEGIN_STMT
  _1 = br_18->fdbs;
  i.5_2 = (unsigned int) i_11;
  _3 = i.5_2 * 8;
  _4 = _1 + _3;
  _5 = _4->used;
  if (_5 != 0)
    goto <bb 8>; [50.00%]
  else
    goto <bb 10>; [50.00%]

  <bb 8> [local count: 719880]:
  _7 = &_4->addr;
  _8 = memcmp (_7, addr_22(D), 6);
  if (_8 == 0)
    goto <bb 9>; [5.50%]
  else
    goto <bb 10>; [94.50%]

  <bb 9> [local count: 39593]:
  # _6 = PHI <_4(8)>
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  memset (_6, 0, 8);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  sys_arch_unprotect (lev_20);
  # DEBUG BEGIN_STMT
  goto <bb 13>; [100.00%]

  <bb 10> [local count: 1400167]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  i_25 = i_11 + 1;
  # DEBUG i => i_25

  <bb 11> [local count: 1523555]:
  # i_11 = PHI <0(6), i_25(10)>
  # DEBUG i => i_11
  # DEBUG BEGIN_STMT
  _9 = br_18->max_fdbs_entries;
  _10 = (int) _9;
  if (_10 > i_11)
    goto <bb 7>; [94.50%]
  else
    goto <bb 12>; [5.50%]

  <bb 12> [local count: 83796]:
  # DEBUG BEGIN_STMT
  sys_arch_unprotect (lev_20);
  # DEBUG BEGIN_STMT

  <bb 13> [local count: 123389]:
  # _12 = PHI <0(9), -6(12)>
  return _12;

}



;; Function bridgeif_init (bridgeif_init, funcdef_no=9, decl_uid=6269, cgraph_uid=10, symbol_order=10)

Modification phase of node bridgeif_init/10
bridgeif_init (struct netif * netif)
{
  struct ip6_addr_t ip6_allnodes_ll;
  size_t alloc_len_sizet;
  struct bridgeif_private_t * br;
  struct bridgeif_initdata_t * init_data;
  err_t (*<T6c9>) (struct pbuf *, struct netif *) _1;
  unsigned char bridgeif_netif_client_id.10_2;
  unsigned char _3;
  unsigned char _4;
  unsigned int _5;
  unsigned int _6;
  short unsigned int _7;
  unsigned int _8;
  unsigned int _9;
  unsigned int _10;
  struct eth_addr * _11;
  struct eth_addr * _12;
  unsigned char _13;
  struct bridgeif_private_t * _14;
  short unsigned int _15;
  unsigned int _16;
  unsigned int _17;
  struct bridgeif_fdb_static_entry_t * _18;
  short unsigned int _19;
  void * _20;
  u8_t[6] * _21;
  err_t (*<T6e5>) (struct netif *, const struct ip6_addr_t *, netif_mac_filter_action) _22;
  err_t _23;
  sizetype _79;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (netif_30(D) == 0B)
    goto <bb 18>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 18> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 22> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = netif_30(D)->input;
  if (_1 == 0B)
    goto <bb 19>; [30.00%]
  else
    goto <bb 6>; [70.00%]

  <bb 19> [local count: 75162]:

  <bb 5> [local count: 751619279]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 23> [local count: 751619279]:
  goto <bb 5>; [100.00%]

  <bb 6> [local count: 175378]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  bridgeif_netif_client_id.10_2 = bridgeif_netif_client_id;
  if (bridgeif_netif_client_id.10_2 == 255)
    goto <bb 7>; [20.24%]
  else
    goto <bb 8>; [79.76%]

  <bb 7> [local count: 35496]:
  # DEBUG BEGIN_STMT
  _3 = netif_alloc_client_data_id ();
  bridgeif_netif_client_id = _3;

  <bb 8> [local count: 175378]:
  # DEBUG BEGIN_STMT
  init_data_34 = netif_30(D)->state;
  # DEBUG init_data => init_data_34
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (init_data_34 == 0B)
    goto <bb 20>; [30.00%]
  else
    goto <bb 10>; [70.00%]

  <bb 20> [local count: 52613]:

  <bb 9> [local count: 526133495]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 24> [local count: 526133495]:
  goto <bb 9>; [100.00%]

  <bb 10> [local count: 122764]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _4 = init_data_34->max_ports;
  if (_4 > 7)
    goto <bb 21>; [67.00%]
  else
    goto <bb 12>; [33.00%]

  <bb 21> [local count: 82252]:

  <bb 11> [local count: 822522030]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 25> [local count: 822522030]:
  goto <bb 11>; [100.00%]

  <bb 12> [local count: 40512]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _5 = (unsigned int) _4;
  _6 = _5 * 12;
  _7 = init_data_34->max_fdb_static_entries;
  _8 = (unsigned int) _7;
  _9 = _8 * 8;
  _10 = _6 + _9;
  alloc_len_sizet_35 = _10 + 32;
  # DEBUG alloc_len_sizet => alloc_len_sizet_35
  # DEBUG BEGIN_STMT
  # DEBUG alloc_len => alloc_len_sizet_35
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  br_37 = mem_calloc (1, alloc_len_sizet_35);
  # DEBUG br => br_37
  # DEBUG BEGIN_STMT
  if (br_37 == 0B)
    goto <bb 17>; [0.91%]
  else
    goto <bb 13>; [99.09%]

  <bb 13> [local count: 40144]:
  # DEBUG BEGIN_STMT
  _11 = &br_37->ethaddr;
  _12 = &init_data_34->ethaddr;
  memcpy (_11, _12, 6);
  # DEBUG BEGIN_STMT
  br_37->netif = netif_30(D);
  # DEBUG BEGIN_STMT
  _13 = init_data_34->max_ports;
  br_37->max_ports = _13;
  # DEBUG BEGIN_STMT
  _14 = br_37 + 32;
  br_37->ports = _14;
  # DEBUG BEGIN_STMT
  _15 = init_data_34->max_fdb_static_entries;
  br_37->max_fdbs_entries = _15;
  # DEBUG BEGIN_STMT
  _16 = (unsigned int) _13;
  _17 = _16 * 12;
  _79 = _17 + 32;
  _18 = br_37 + _79;
  br_37->fdbs = _18;
  # DEBUG BEGIN_STMT
  _19 = init_data_34->max_fdb_dynamic_entries;
  br_37->max_fdbd_entries = _19;
  # DEBUG BEGIN_STMT
  _20 = bridgeif_fdb_init (_19);
  br_37->fdbd = _20;
  # DEBUG BEGIN_STMT
  if (_20 == 0B)
    goto <bb 14>; [0.45%]
  else
    goto <bb 15>; [99.55%]

  <bb 14> [local count: 181]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  mem_free (br_37);
  # DEBUG BEGIN_STMT
  goto <bb 17>; [100.00%]

  <bb 15> [local count: 39963]:
  # DEBUG BEGIN_STMT
  netif_30(D)->hostname = "lwip";
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  netif_30(D)->link_type = 6;
  # DEBUG BEGIN_STMT
  netif_30(D)->link_speed = 0;
  # DEBUG BEGIN_STMT
  netif_30(D)->ts = 0;
  # DEBUG BEGIN_STMT
  netif_30(D)->mib2_counters.ifinoctets = 0;
  # DEBUG BEGIN_STMT
  netif_30(D)->mib2_counters.ifinucastpkts = 0;
  # DEBUG BEGIN_STMT
  netif_30(D)->mib2_counters.ifinnucastpkts = 0;
  # DEBUG BEGIN_STMT
  netif_30(D)->mib2_counters.ifindiscards = 0;
  # DEBUG BEGIN_STMT
  netif_30(D)->mib2_counters.ifinerrors = 0;
  # DEBUG BEGIN_STMT
  netif_30(D)->mib2_counters.ifinunknownprotos = 0;
  # DEBUG BEGIN_STMT
  netif_30(D)->mib2_counters.ifoutoctets = 0;
  # DEBUG BEGIN_STMT
  netif_30(D)->mib2_counters.ifoutucastpkts = 0;
  # DEBUG BEGIN_STMT
  netif_30(D)->mib2_counters.ifoutnucastpkts = 0;
  # DEBUG BEGIN_STMT
  netif_30(D)->mib2_counters.ifoutdiscards = 0;
  # DEBUG BEGIN_STMT
  netif_30(D)->mib2_counters.ifouterrors = 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  netif_30(D)->state = br_37;
  # DEBUG BEGIN_STMT
  netif_30(D)->name[0] = 98;
  # DEBUG BEGIN_STMT
  netif_30(D)->name[1] = 114;
  # DEBUG BEGIN_STMT
  netif_30(D)->output = etharp_output;
  # DEBUG BEGIN_STMT
  netif_30(D)->output_ip6 = ethip6_output;
  # DEBUG BEGIN_STMT
  netif_30(D)->linkoutput = bridgeif_output;
  # DEBUG BEGIN_STMT
  netif_30(D)->hwaddr_len = 6;
  # DEBUG BEGIN_STMT
  _21 = &netif_30(D)->hwaddr;
  memcpy (_21, _11, 6);
  # DEBUG BEGIN_STMT
  netif_30(D)->mtu = 1500;
  # DEBUG BEGIN_STMT
  netif_30(D)->flags = 126;
  # DEBUG BEGIN_STMT
  _22 = netif_30(D)->mld_mac_filter;
  if (_22 != 0B)
    goto <bb 16>; [70.00%]
  else
    goto <bb 17>; [30.00%]

  <bb 16> [local count: 27974]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  ip6_allnodes_ll.addr[0] = 767;
  # DEBUG BEGIN_STMT
  ip6_allnodes_ll.addr[1] = 0;
  # DEBUG BEGIN_STMT
  ip6_allnodes_ll.addr[2] = 0;
  # DEBUG BEGIN_STMT
  ip6_allnodes_ll.addr[3] = 16777216;
  # DEBUG BEGIN_STMT
  ip6_allnodes_ll.zone = 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _22 (netif_30(D), &ip6_allnodes_ll, 1);
  ip6_allnodes_ll ={v} {CLOBBER};

  <bb 17> [local count: 40512]:
  # _23 = PHI <-1(12), -1(14), 0(16), 0(15)>
  return _23;

}



;; Function bridgeif_add_port (bridgeif_add_port, funcdef_no=10, decl_uid=6272, cgraph_uid=11, symbol_order=11)

Modification phase of node bridgeif_add_port/11
bridgeif_add_port (struct netif * bridgeif, struct netif * portif)
{
  struct bridgeif_port_t * port;
  void * _1;
  unsigned char _2;
  unsigned char _3;
  unsigned char _4;
  struct bridgeif_port_t * _5;
  unsigned int _6;
  unsigned int _7;
  unsigned char _8;
  unsigned char _9;
  unsigned char bridgeif_netif_client_id.15_10;
  int _11;
  unsigned char _12;
  err_t _13;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (bridgeif_18(D) == 0B)
    goto <bb 12>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 12> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 15> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = bridgeif_18(D)->state;
  if (_1 == 0B)
    goto <bb 13>; [30.00%]
  else
    goto <bb 6>; [70.00%]

  <bb 13> [local count: 75162]:

  <bb 5> [local count: 751619279]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 16> [local count: 751619279]:
  goto <bb 5>; [100.00%]

  <bb 6> [local count: 175378]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (portif_20(D) == 0B)
    goto <bb 14>; [30.00%]
  else
    goto <bb 8>; [70.00%]

  <bb 14> [local count: 52613]:

  <bb 7> [local count: 526133495]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 17> [local count: 526133495]:
  goto <bb 7>; [100.00%]

  <bb 8> [local count: 122764]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _2 = portif_20(D)->flags;
  _8 = _2 & 24;
  if (_8 != 24)
    goto <bb 11>; [2.00%]
  else
    goto <bb 9>; [98.00%]

  <bb 9> [local count: 120309]:
  # DEBUG BEGIN_STMT
  # DEBUG br => _1
  # DEBUG BEGIN_STMT
  _3 = MEM[(struct bridgeif_private_t *)_1].num_ports;
  _4 = MEM[(struct bridgeif_private_t *)_1].max_ports;
  if (_3 >= _4)
    goto <bb 11>; [1.04%]
  else
    goto <bb 10>; [98.96%]

  <bb 10> [local count: 119058]:
  # DEBUG BEGIN_STMT
  _5 = MEM[(struct bridgeif_private_t *)_1].ports;
  _6 = (unsigned int) _3;
  _7 = _6 * 12;
  port_21 = _5 + _7;
  # DEBUG port => port_21
  # DEBUG BEGIN_STMT
  port_21->port_netif = portif_20(D);
  # DEBUG BEGIN_STMT
  port_21->port_num = _3;
  # DEBUG BEGIN_STMT
  port_21->bridge = _1;
  # DEBUG BEGIN_STMT
  _9 = _3 + 1;
  MEM[(struct bridgeif_private_t *)_1].num_ports = _9;
  # DEBUG BEGIN_STMT
  portif_20(D)->input = bridgeif_input;
  # DEBUG BEGIN_STMT
  bridgeif_netif_client_id.15_10 = bridgeif_netif_client_id;
  _11 = (int) bridgeif_netif_client_id.15_10;
  portif_20(D)->client_data[_11] = port_21;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _12 = _2 & 247;
  portif_20(D)->flags = _12;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 11> [local count: 122764]:
  # _13 = PHI <-6(8), -6(9), 0(10)>
  return _13;

}


