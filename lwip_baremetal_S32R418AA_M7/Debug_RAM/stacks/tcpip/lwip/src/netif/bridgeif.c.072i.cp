
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
Determining dynamic type for call: dstports_31 = bridgeif_find_dst_ports (_3, dst_27);
  Starting walk at: dstports_31 = bridgeif_find_dst_ports (_3, dst_27);
  instance pointer: _3  Outer instance pointer: _3 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:bridgeif_fdb_update_src (_6, src_28, _7);
Determining dynamic type for call: dstports_31 = bridgeif_find_dst_ports (_3, dst_27);
  Starting walk at: dstports_31 = bridgeif_find_dst_ports (_3, dst_27);
  instance pointer: dst_27  Outer instance pointer: dst_27 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:bridgeif_fdb_update_src (_6, src_28, _7);
Determining dynamic type for call: bridgeif_send_to_ports (_3, p_21(D), dstports_31);
  Starting walk at: bridgeif_send_to_ports (_3, p_21(D), dstports_31);
  instance pointer: _3  Outer instance pointer: _3 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:dstports_31 = bridgeif_find_dst_ports (_3, dst_27);
  Function call may change dynamic type:bridgeif_fdb_update_src (_6, src_28, _7);
Determining dynamic type for call: bridgeif_send_to_ports (_3, p_21(D), dstports_31);
  Starting walk at: bridgeif_send_to_ports (_3, p_21(D), dstports_31);
  instance pointer: p_21(D)  Outer instance pointer: p_21(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:dstports_31 = bridgeif_find_dst_ports (_3, dst_27);
  Function call may change dynamic type:bridgeif_fdb_update_src (_6, src_28, _7);
Determining dynamic type for call: _36 = _15 (p_21(D), _14);
  Starting walk at: _36 = _15 (p_21(D), _14);
  instance pointer: p_21(D)  Outer instance pointer: p_21(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:bridgeif_fdb_update_src (_6, src_28, _7);
Determining dynamic type for call: _36 = _15 (p_21(D), _14);
  Starting walk at: _36 = _15 (p_21(D), _14);
  instance pointer: _14  Outer instance pointer: _14 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:bridgeif_fdb_update_src (_6, src_28, _7);
Determining dynamic type for call: dstports_38 = bridgeif_find_dst_ports (_3, dst_27);
  Starting walk at: dstports_38 = bridgeif_find_dst_ports (_3, dst_27);
  instance pointer: _3  Outer instance pointer: _3 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:bridgeif_fdb_update_src (_6, src_28, _7);
Determining dynamic type for call: dstports_38 = bridgeif_find_dst_ports (_3, dst_27);
  Starting walk at: dstports_38 = bridgeif_find_dst_ports (_3, dst_27);
  instance pointer: dst_27  Outer instance pointer: dst_27 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:bridgeif_fdb_update_src (_6, src_28, _7);
Determining dynamic type for call: bridgeif_send_to_ports (_3, p_21(D), dstports_38);
  Starting walk at: bridgeif_send_to_ports (_3, p_21(D), dstports_38);
  instance pointer: _3  Outer instance pointer: _3 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:dstports_38 = bridgeif_find_dst_ports (_3, dst_27);
  Function call may change dynamic type:bridgeif_fdb_update_src (_6, src_28, _7);
Determining dynamic type for call: bridgeif_send_to_ports (_3, p_21(D), dstports_38);
  Starting walk at: bridgeif_send_to_ports (_3, p_21(D), dstports_38);
  instance pointer: p_21(D)  Outer instance pointer: p_21(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:dstports_38 = bridgeif_find_dst_ports (_3, dst_27);
  Function call may change dynamic type:bridgeif_fdb_update_src (_6, src_28, _7);
Determining dynamic type for call: _12 = _11 (p_21(D), _10);
  Starting walk at: _12 = _11 (p_21(D), _10);
  instance pointer: p_21(D)  Outer instance pointer: p_21(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:bridgeif_send_to_ports (_3, p_21(D), dstports_38);
  Function call may change dynamic type:dstports_38 = bridgeif_find_dst_ports (_3, dst_27);
  Function call may change dynamic type:bridgeif_fdb_update_src (_6, src_28, _7);
Determining dynamic type for call: _12 = _11 (p_21(D), _10);
  Starting walk at: _12 = _11 (p_21(D), _10);
  instance pointer: _10  Outer instance pointer: _10 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:bridgeif_send_to_ports (_3, p_21(D), dstports_38);
  Function call may change dynamic type:dstports_38 = bridgeif_find_dst_ports (_3, dst_27);
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
Determining dynamic type for call: err_14 = bridgeif_send_to_port (br_11(D), p_12(D), i_5);
  Starting walk at: err_14 = bridgeif_send_to_port (br_11(D), p_12(D), i_5);
  instance pointer: br_11(D)  Outer instance pointer: br_11(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_14 = bridgeif_send_to_port (br_11(D), p_12(D), i_5);
Determining dynamic type for call: err_14 = bridgeif_send_to_port (br_11(D), p_12(D), i_5);
  Starting walk at: err_14 = bridgeif_send_to_port (br_11(D), p_12(D), i_5);
  instance pointer: p_12(D)  Outer instance pointer: p_12(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_14 = bridgeif_send_to_port (br_11(D), p_12(D), i_5);
Determining dynamic type for call: _24 = _6 (portif_21, p_22(D));
  Starting walk at: _24 = _6 (portif_21, p_22(D));
  instance pointer: portif_21  Outer instance pointer: portif_21 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _24 = _6 (portif_21, p_22(D));
  Starting walk at: _24 = _6 (portif_21, p_22(D));
  instance pointer: p_22(D)  Outer instance pointer: p_22(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _13 = bridgeif_find_dst_ports.part.0 (br_19(D), dst_addr_20(D));
  Starting walk at: _13 = bridgeif_find_dst_ports.part.0 (br_19(D), dst_addr_20(D));
  instance pointer: br_19(D)  Outer instance pointer: br_19(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _13 = bridgeif_find_dst_ports.part.0 (br_19(D), dst_addr_20(D));
  Starting walk at: _13 = bridgeif_find_dst_ports.part.0 (br_19(D), dst_addr_20(D));
  instance pointer: dst_addr_20(D)  Outer instance pointer: dst_addr_20(D) offset: 0 (bits) vtbl reference: 

IPA structures before propagation:

Jump functions:
  Jump functions of caller  bridgeif_find_dst_ports.part.0/25:
  Jump functions of caller  pbuf_free/24:
  Jump functions of caller  bridgeif_fdb_update_src/23:
  Jump functions of caller  bridgeif_fdb_get_dst_ports/22:
  Jump functions of caller  ethip6_output/20:
  Jump functions of caller  etharp_output/19:
  Jump functions of caller  mem_free/18:
  Jump functions of caller  bridgeif_fdb_init/17:
  Jump functions of caller  mem_calloc/16:
  Jump functions of caller  netif_alloc_client_data_id/15:
  Jump functions of caller  memset/14:
  Jump functions of caller  memcmp/13:
  Jump functions of caller  memcpy/12:
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
    indirect simple callsite, calling param -1, offset 0, for stmt _36 = _15 (p_21(D), _14);
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
    callsite  bridgeif_find_dst_ports/4 -> bridgeif_find_dst_ports.part.0/25 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  bridgeif_fdb_remove/3:
  Jump functions of caller  bridgeif_fdb_add/2:

 Propagating constants:

Not considering bridgeif_add_port for cloning; -fipa-cp-clone disabled.
Not considering bridgeif_init for cloning; -fipa-cp-clone disabled.
Not considering bridgeif_input for cloning; -fipa-cp-clone disabled.
Not considering bridgeif_output for cloning; -fipa-cp-clone disabled.
Not considering bridgeif_fdb_remove for cloning; -fipa-cp-clone disabled.
Not considering bridgeif_fdb_add for cloning; -fipa-cp-clone disabled.

overall_size: 437, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: bridgeif_find_dst_ports.part.0/25:
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

bridgeif_find_dst_ports.part.0/25 (bridgeif_find_dst_ports.part.0) @06ca28c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: bridgeif_find_dst_ports/4 (37777995 (estimated locally),0.43 per call) 
  Calls: bridgeif_fdb_get_dst_ports/22 (1073741824 (estimated locally),1.00 per call) 
pbuf_free/24 (pbuf_free) @06eb6620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: bridgeif_input/9 (65647 (estimated locally),0.18 per call) bridgeif_input/9 (20940 (estimated locally),0.06 per call) bridgeif_input/9 (9749 (estimated locally),0.03 per call) 
  Calls: 
bridgeif_fdb_update_src/23 (bridgeif_fdb_update_src) @06eb6540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: bridgeif_input/9 (82306 (estimated locally),0.23 per call) 
  Calls: 
bridgeif_fdb_get_dst_ports/22 (bridgeif_fdb_get_dst_ports) @06eb6000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: bridgeif_find_dst_ports.part.0/25 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
lwip_stats/21 (lwip_stats) @06eb0168
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: bridgeif_output/8 (read)bridgeif_output/8 (write)
  Availability: not_available
  Varpool flags:
ethip6_output/20 (ethip6_output) @06e6ed20
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: bridgeif_init/10 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
etharp_output/19 (etharp_output) @06e6ec40
  Type: function
  Visibility: external public
  Address is taken.
  References: 
  Referring: bridgeif_init/10 (addr)
  Availability: not_available
  Function flags: optimize_size
  Called by: 
  Calls: 
mem_free/18 (mem_free) @06e6eb60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: bridgeif_init/10 (181 (estimated locally),0.00 per call) 
  Calls: 
bridgeif_fdb_init/17 (bridgeif_fdb_init) @06e6ea80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: bridgeif_init/10 (40144 (estimated locally),0.11 per call) 
  Calls: 
mem_calloc/16 (mem_calloc) @06e6e9a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: bridgeif_init/10 (40512 (estimated locally),0.11 per call) 
  Calls: 
netif_alloc_client_data_id/15 (netif_alloc_client_data_id) @06e6e8c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: bridgeif_init/10 (35496 (estimated locally),0.10 per call) 
  Calls: 
memset/14 (memset) @06e6e620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: bridgeif_fdb_remove/3 (56276 (estimated locally),0.16 per call) 
  Calls: 
memcmp/13 (memcmp) @06e6e540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: bridgeif_fdb_remove/3 (1023194 (estimated locally),2.86 per call) bridgeif_find_dst_ports/4 (507343012 (estimated locally),5.83 per call) bridgeif_is_local_mac/5 (710280218 (estimated locally),4.78 per call) bridgeif_is_local_mac/5 (148668506 (estimated locally),1.00 per call) 
  Calls: 
memcpy/12 (memcpy) @06e6e380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: bridgeif_init/10 (39963 (estimated locally),0.11 per call) bridgeif_init/10 (40144 (estimated locally),0.11 per call) bridgeif_fdb_add/2 (85209 (estimated locally),0.24 per call) 
  Calls: 
bridgeif_add_port/11 (bridgeif_add_port) @06e56ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: bridgeif_input/9 (addr)bridgeif_netif_client_id/1 (read)
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: 
  Calls: 
bridgeif_init/10 (bridgeif_init) @06e56e00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: bridgeif_netif_client_id/1 (read)bridgeif_netif_client_id/1 (write)etharp_output/19 (addr)ethip6_output/20 (addr)bridgeif_output/8 (addr)
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: 
  Calls: memcpy/12 (39963 (estimated locally),0.11 per call) mem_free/18 (181 (estimated locally),0.00 per call) bridgeif_fdb_init/17 (40144 (estimated locally),0.11 per call) memcpy/12 (40144 (estimated locally),0.11 per call) mem_calloc/16 (40512 (estimated locally),0.11 per call) netif_alloc_client_data_id/15 (35496 (estimated locally),0.10 per call) 
   Indirect call(27974 (estimated locally),0.08 per call)  of param:0 loaded from aggregate passed by reference at offset 2304 (vptr maybe changed)
bridgeif_input/9 (bridgeif_input) @06e56a80
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: bridgeif_netif_client_id/1 (read)
  Referring: bridgeif_add_port/11 (addr)
  Availability: available
  Function flags: count:361156 (estimated locally) body optimize_size
  Called by: 
  Calls: pbuf_free/24 (65647 (estimated locally),0.18 per call) bridgeif_send_to_ports/7 (65647 (estimated locally),0.18 per call) bridgeif_find_dst_ports/4 (65647 (estimated locally),0.18 per call) bridgeif_is_local_mac/5 (198931 (estimated locally),0.55 per call) pbuf_free/24 (20940 (estimated locally),0.06 per call) pbuf_free/24 (9749 (estimated locally),0.03 per call) bridgeif_send_to_ports/7 (50481 (estimated locally),0.14 per call) bridgeif_find_dst_ports/4 (50481 (estimated locally),0.14 per call) bridgeif_fdb_update_src/23 (82306 (estimated locally),0.23 per call) 
   Indirect call(133284 (estimated locally),0.37 per call) 
   Indirect call(29541 (estimated locally),0.08 per call) 
bridgeif_output/8 (bridgeif_output) @06e567e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: lwip_stats/21 (read)lwip_stats/21 (write)
  Referring: bridgeif_init/10 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: bridgeif_send_to_ports/7 (1073741824 (estimated locally),1.00 per call) bridgeif_find_dst_ports/4 (1073741824 (estimated locally),1.00 per call) 
bridgeif_send_to_ports/7 (bridgeif_send_to_ports) @06e562a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:134217728 (estimated locally) body local optimize_size
  Called by: bridgeif_input/9 (65647 (estimated locally),0.18 per call) bridgeif_input/9 (50481 (estimated locally),0.14 per call) bridgeif_output/8 (1073741824 (estimated locally),1.00 per call) 
  Calls: bridgeif_send_to_port/6 (310042952 (estimated locally),2.31 per call) 
bridgeif_send_to_port/6 (bridgeif_send_to_port) @06e56000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:325376 (estimated locally) body local optimize_size
  Called by: bridgeif_send_to_ports/7 (310042952 (estimated locally),2.31 per call) 
  Calls: 
   Indirect call(8944 (estimated locally),0.03 per call) 
bridgeif_is_local_mac/5 (bridgeif_is_local_mac) @06e4be00
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:148668506 (estimated locally) body local optimize_size
  Called by: bridgeif_input/9 (198931 (estimated locally),0.55 per call) 
  Calls: memcmp/13 (710280218 (estimated locally),4.78 per call) memcmp/13 (148668506 (estimated locally),1.00 per call) 
bridgeif_find_dst_ports/4 (bridgeif_find_dst_ports) @06e4bb60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:86959666 (estimated locally) body local optimize_size
  Called by: bridgeif_input/9 (65647 (estimated locally),0.18 per call) bridgeif_input/9 (50481 (estimated locally),0.14 per call) bridgeif_output/8 (1073741824 (estimated locally),1.00 per call) 
  Calls: bridgeif_find_dst_ports.part.0/25 (37777995 (estimated locally),0.43 per call) memcmp/13 (507343012 (estimated locally),5.83 per call) 
bridgeif_fdb_remove/3 (bridgeif_fdb_remove) @06e4b8c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: 
  Calls: memset/14 (56276 (estimated locally),0.16 per call) memcmp/13 (1023194 (estimated locally),2.86 per call) 
bridgeif_fdb_add/2 (bridgeif_fdb_add) @06e4b620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: 
  Calls: memcpy/12 (85209 (estimated locally),0.24 per call) 
bridgeif_netif_client_id/1 (bridgeif_netif_client_id) @06e46948
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: bridgeif_input/9 (read)bridgeif_init/10 (write)bridgeif_init/10 (read)bridgeif_add_port/11 (read)
  Availability: available
  Varpool flags: initialized

;; Function bridgeif_send_to_ports (bridgeif_send_to_ports, funcdef_no=6, decl_uid=7273, cgraph_uid=7, symbol_order=7)

Modification phase of node bridgeif_send_to_ports/7
bridgeif_send_to_ports (struct bridgeif_private_t * br, struct pbuf * p, bridgeif_portmask_t dstports)
{
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
  # DEBUG BEGIN_STMT
  # DEBUG i => 0
  goto <bb 7>; [100.00%]

  <bb 3> [local count: 939524097]:
  # DEBUG BEGIN_STMT
  _1 = mask_6 & dstports_10(D);
  if (_1 != 0)
    goto <bb 4>; [33.00%]
  else
    goto <bb 6>; [67.00%]

  <bb 4> [local count: 310042952]:
  # DEBUG BEGIN_STMT
  err_14 = bridgeif_send_to_port (br_11(D), p_12(D), i_5);
  # DEBUG err => err_14
  # DEBUG BEGIN_STMT
  if (err_14 != 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 5> [local count: 155021476]:
  # DEBUG BEGIN_STMT
  # DEBUG ret_err => err_14

  <bb 6> [local count: 939524097]:
  # ret_err_3 = PHI <ret_err_4(3), ret_err_4(4), err_14(5)>
  # DEBUG ret_err => ret_err_3
  # DEBUG BEGIN_STMT
  i_15 = i_5 + 1;
  # DEBUG i => i_15
  mask_16 = mask_6 << 1;
  # DEBUG mask => mask_16

  <bb 7> [local count: 1073741824]:
  # ret_err_4 = PHI <0(2), ret_err_3(6)>
  # i_5 = PHI <0(2), i_15(6)>
  # mask_6 = PHI <1(2), mask_16(6)>
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
  # DEBUG BEGIN_STMT
  return ret_err_2;

}



;; Function bridgeif_find_dst_ports (bridgeif_find_dst_ports, funcdef_no=3, decl_uid=7247, cgraph_uid=4, symbol_order=4)

Modification phase of node bridgeif_find_dst_ports/4
bridgeif_find_dst_ports (struct bridgeif_private_t * br, struct eth_addr * dst_addr)
{
  bridgeif_portmask_t ret;
  int i;
  struct bridgeif_fdb_static_entry_t * _1;
  unsigned int i.11_2;
  unsigned int _3;
  struct bridgeif_fdb_static_entry_t * _4;
  unsigned char _5;
  struct bridgeif_fdb_static_entry_t * _6;
  struct eth_addr * _8;
  int _9;
  short unsigned int _10;
  int _11;
  unsigned char _12;
  unsigned char _13;
  bridgeif_portmask_t _16;
  unsigned char _17;

  <bb 2> [local count: 86959666]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG i => 0
  goto <bb 7>; [100.00%]

  <bb 3> [local count: 1014686025]:
  # DEBUG BEGIN_STMT
  _1 = br_19(D)->fdbs;
  i.11_2 = (unsigned int) i_15;
  _3 = i.11_2 * 8;
  _4 = _1 + _3;
  _5 = _4->used;
  if (_5 != 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 4> [local count: 507343012]:
  # DEBUG BEGIN_STMT
  _8 = &_4->addr;
  _9 = memcmp (_8, dst_addr_20(D), 6);
  if (_9 == 0)
    goto <bb 5>; [5.50%]
  else
    goto <bb 6>; [94.50%]

  <bb 5> [local count: 27903866]:
  # _6 = PHI <_4(4)>
  # DEBUG BEGIN_STMT
  ret_21 = _6->dst_ports;
  # DEBUG ret => ret_21
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 10>; [100.00%]

  <bb 6> [local count: 986782159]:
  # DEBUG BEGIN_STMT
  i_22 = i_15 + 1;
  # DEBUG i => i_22

  <bb 7> [local count: 1073741824]:
  # i_15 = PHI <0(2), i_22(6)>
  # DEBUG i => i_15
  # DEBUG BEGIN_STMT
  _10 = br_19(D)->max_fdbs_entries;
  _11 = (int) _10;
  if (_11 > i_15)
    goto <bb 3>; [94.50%]
  else
    goto <bb 8>; [5.50%]

  <bb 8> [local count: 59055800]:
  # DEBUG BEGIN_STMT
  _12 = dst_addr_20(D)->addr[0];
  _17 = _12 & 1;
  if (_17 != 0)
    goto <bb 10>; [36.03%]
  else
    goto <bb 9>; [63.97%]

  <bb 9> [local count: 37777995]:
  _13 = bridgeif_find_dst_ports.part.0 (br_19(D), dst_addr_20(D));

  <bb 10> [local count: 86959666]:
  # _16 = PHI <ret_21(5), 255(8), _13(9)>
  return _16;

}



;; Function bridgeif_output (bridgeif_output, funcdef_no=7, decl_uid=7284, cgraph_uid=8, symbol_order=8)

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



;; Function bridgeif_input (bridgeif_input, funcdef_no=8, decl_uid=7292, cgraph_uid=9, symbol_order=9)

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
  err_t (*<T6c7>) (struct pbuf *, struct netif *) _11;
  signed char _12;
  int _13;
  struct netif * _14;
  err_t (*<T6c7>) (struct pbuf *, struct netif *) _15;
  err_t _16;
  unsigned char _34;
  err_t _36;
  unsigned char _43;

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
  _34 = _5 & 1;
  if (_34 == 0)
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
  _43 = _8 & 1;
  if (_43 != 0)
    goto <bb 10>; [20.24%]
  else
    goto <bb 15>; [79.76%]

  <bb 10> [local count: 50481]:
  # DEBUG BEGIN_STMT
  dstports_38 = bridgeif_find_dst_ports (_3, dst_27);
  # DEBUG dstports => dstports_38
  # DEBUG BEGIN_STMT
  bridgeif_send_to_ports (_3, p_21(D), dstports_38);
  # DEBUG BEGIN_STMT
  dstports.17_9 = (signed char) dstports_38;
  if (dstports.17_9 < 0)
    goto <bb 11>; [58.52%]
  else
    goto <bb 13>; [41.48%]

  <bb 11> [local count: 29541]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _10 = MEM[(struct bridgeif_private_t *)_3].netif;
  _11 = _10->input;
  _12 = _11 (p_21(D), _10);
  if (_12 != 0)
    goto <bb 12>; [33.00%]
  else
    goto <bb 14>; [67.00%]

  <bb 12> [local count: 9749]:
  # DEBUG BEGIN_STMT
  pbuf_free (p_21(D));
  goto <bb 14>; [100.00%]

  <bb 13> [local count: 20940]:
  # DEBUG BEGIN_STMT
  pbuf_free (p_21(D));

  <bb 14> [local count: 50481]:
  # DEBUG BEGIN_STMT
  goto <bb 18>; [100.00%]

  <bb 15> [local count: 198931]:
  # DEBUG BEGIN_STMT
  _13 = bridgeif_is_local_mac (_3, dst_27);
  if (_13 != 0)
    goto <bb 16>; [67.00%]
  else
    goto <bb 17>; [33.00%]

  <bb 16> [local count: 133284]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _14 = MEM[(struct bridgeif_private_t *)_3].netif;
  _15 = _14->input;
  _36 = _15 (p_21(D), _14);
  goto <bb 18>; [100.00%]

  <bb 17> [local count: 65647]:
  # DEBUG BEGIN_STMT
  dstports_31 = bridgeif_find_dst_ports (_3, dst_27);
  # DEBUG dstports => dstports_31
  # DEBUG BEGIN_STMT
  bridgeif_send_to_ports (_3, p_21(D), dstports_31);
  # DEBUG BEGIN_STMT
  pbuf_free (p_21(D));
  # DEBUG BEGIN_STMT

  <bb 18> [local count: 253782]:
  # _16 = PHI <-6(3), -6(6), 0(14), _36(16), 0(17), -6(2)>
  return _16;

}



;; Function bridgeif_fdb_add (bridgeif_fdb_add, funcdef_no=1, decl_uid=6276, cgraph_uid=2, symbol_order=2)

Modification phase of node bridgeif_fdb_add/2
bridgeif_fdb_add (struct netif * bridgeif, const struct eth_addr * addr, bridgeif_portmask_t ports)
{
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

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (bridgeif_15(D) == 0B)
    goto <bb 11>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 11> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 14> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  br_17 = bridgeif_15(D)->state;
  # DEBUG br => br_17
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (br_17 == 0B)
    goto <bb 12>; [30.00%]
  else
    goto <bb 13>; [70.00%]

  <bb 13> [local count: 175377]:
  goto <bb 9>; [100.00%]

  <bb 12> [local count: 75162]:

  <bb 5> [local count: 751619279]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 15> [local count: 751619279]:
  goto <bb 5>; [100.00%]

  <bb 6> [local count: 1549257]:
  # DEBUG BEGIN_STMT
  _1 = br_17->fdbs;
  i.0_2 = (unsigned int) i_10;
  _3 = i.0_2 * 8;
  _4 = _1 + _3;
  _5 = _4->used;
  if (_5 == 0)
    goto <bb 7>; [5.50%]
  else
    goto <bb 8>; [94.50%]

  <bb 7> [local count: 85209]:
  # _6 = PHI <_4(6)>
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _6->used = 1;
  # DEBUG BEGIN_STMT
  _6->dst_ports = ports_19(D);
  # DEBUG BEGIN_STMT
  _7 = &_6->addr;
  memcpy (_7, addr_21(D), 6);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 10>; [100.00%]

  <bb 8> [local count: 1464048]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  i_23 = i_10 + 1;
  # DEBUG i => i_23

  <bb 9> [local count: 1639425]:
  # i_10 = PHI <i_23(8), 0(13)>
  # DEBUG i => i_10
  # DEBUG BEGIN_STMT
  _8 = br_17->max_fdbs_entries;
  _9 = (int) _8;
  if (_9 > i_10)
    goto <bb 6>; [94.50%]
  else
    goto <bb 10>; [5.50%]

  <bb 10> [local count: 175378]:
  # _11 = PHI <0(7), -1(9)>
  return _11;

}



;; Function bridgeif_fdb_remove (bridgeif_fdb_remove, funcdef_no=2, decl_uid=6279, cgraph_uid=3, symbol_order=3)

Modification phase of node bridgeif_fdb_remove/3
bridgeif_fdb_remove (struct netif * bridgeif, const struct eth_addr * addr)
{
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

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (bridgeif_16(D) == 0B)
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
  br_18 = bridgeif_16(D)->state;
  # DEBUG br => br_18
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (br_18 == 0B)
    goto <bb 13>; [30.00%]
  else
    goto <bb 14>; [70.00%]

  <bb 14> [local count: 175377]:
  goto <bb 10>; [100.00%]

  <bb 13> [local count: 75162]:

  <bb 5> [local count: 751619279]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 16> [local count: 751619279]:
  goto <bb 5>; [100.00%]

  <bb 6> [local count: 2046387]:
  # DEBUG BEGIN_STMT
  _1 = br_18->fdbs;
  i.5_2 = (unsigned int) i_11;
  _3 = i.5_2 * 8;
  _4 = _1 + _3;
  _5 = _4->used;
  if (_5 != 0)
    goto <bb 7>; [50.00%]
  else
    goto <bb 9>; [50.00%]

  <bb 7> [local count: 1023194]:
  _7 = &_4->addr;
  _8 = memcmp (_7, addr_19(D), 6);
  if (_8 == 0)
    goto <bb 8>; [5.50%]
  else
    goto <bb 9>; [94.50%]

  <bb 8> [local count: 56276]:
  # _6 = PHI <_4(7)>
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  memset (_6, 0, 8);
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 11>; [100.00%]

  <bb 9> [local count: 1990111]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  i_21 = i_11 + 1;
  # DEBUG i => i_21

  <bb 10> [local count: 2165489]:
  # i_11 = PHI <i_21(9), 0(14)>
  # DEBUG i => i_11
  # DEBUG BEGIN_STMT
  _9 = br_18->max_fdbs_entries;
  _10 = (int) _9;
  if (_10 > i_11)
    goto <bb 6>; [94.50%]
  else
    goto <bb 11>; [5.50%]

  <bb 11> [local count: 175378]:
  # _12 = PHI <0(8), -6(10)>
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
  err_t (*<T6c7>) (struct pbuf *, struct netif *) _1;
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
  err_t (*<T6e3>) (struct netif *, const struct ip6_addr_t *, netif_mac_filter_action) _22;
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


