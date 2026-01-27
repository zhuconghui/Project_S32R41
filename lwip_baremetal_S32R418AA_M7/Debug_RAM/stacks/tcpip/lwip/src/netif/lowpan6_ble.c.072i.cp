
IPA constant propagation start:
Determining dynamic type for call: _5 = rfc7668_compress (netif_2(D), q_3(D));
  Starting walk at: _5 = rfc7668_compress (netif_2(D), q_3(D));
  instance pointer: netif_2(D)  Outer instance pointer: netif_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _5 = rfc7668_compress (netif_2(D), q_3(D));
  Starting walk at: _5 = rfc7668_compress (netif_2(D), q_3(D));
  instance pointer: q_3(D)  Outer instance pointer: q_3(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: err_44 = _24 (netif_30(D), p_frag_33);
  Starting walk at: err_44 = _24 (netif_30(D), p_frag_33);
  instance pointer: netif_30(D)  Outer instance pointer: netif_30(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pbuf_copy_partial (p_31(D), _17, remaining_len_38, 0);
  Function call may change dynamic type:pbuf_remove_header (p_31(D), _14);
  Function call may change dynamic type:err_36 = lowpan6_compress_headers (netif_30(D), _7, _9, buffer_34, _10, &lowpan6_header_len, &hidden_header_len, &rfc7668_context, &rfc7668_local_addr, &rfc7668_peer_addr);
  Function call may change dynamic type:p_frag_33 = pbuf_alloc (0, _2, 640);
Determining dynamic type for call: err_44 = _24 (netif_30(D), p_frag_33);
  Starting walk at: err_44 = _24 (netif_30(D), p_frag_33);
  instance pointer: p_frag_33  Outer instance pointer: p_frag_33 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pbuf_copy_partial (p_31(D), _17, remaining_len_38, 0);
  Function call may change dynamic type:pbuf_remove_header (p_31(D), _14);
  Function call may change dynamic type:err_36 = lowpan6_compress_headers (netif_30(D), _7, _9, buffer_34, _10, &lowpan6_header_len, &hidden_header_len, &rfc7668_context, &rfc7668_local_addr, &rfc7668_peer_addr);
  Function call may change dynamic type:p_frag_33 = pbuf_alloc (0, _2, 640);
Determining dynamic type for call: _6 = rfc7668_set_addr (&rfc7668_peer_addr, peer_addr_2(D), peer_addr_len_3(D), 1, is_public_addr_4(D));
  Starting walk at: _6 = rfc7668_set_addr (&rfc7668_peer_addr, peer_addr_2(D), peer_addr_len_3(D), 1, is_public_addr_4(D));
  instance pointer: &rfc7668_peer_addr  Outer instance pointer: rfc7668_peer_addr offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _6 = rfc7668_set_addr (&rfc7668_peer_addr, peer_addr_2(D), peer_addr_len_3(D), 1, is_public_addr_4(D));
  Starting walk at: _6 = rfc7668_set_addr (&rfc7668_peer_addr, peer_addr_2(D), peer_addr_len_3(D), 1, is_public_addr_4(D));
  instance pointer: peer_addr_2(D)  Outer instance pointer: peer_addr_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _5 = rfc7668_set_addr (&rfc7668_peer_addr, peer_addr_2(D), peer_addr_len_3(D), 0, 0);
  Starting walk at: _5 = rfc7668_set_addr (&rfc7668_peer_addr, peer_addr_2(D), peer_addr_len_3(D), 0, 0);
  instance pointer: &rfc7668_peer_addr  Outer instance pointer: rfc7668_peer_addr offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _5 = rfc7668_set_addr (&rfc7668_peer_addr, peer_addr_2(D), peer_addr_len_3(D), 0, 0);
  Starting walk at: _5 = rfc7668_set_addr (&rfc7668_peer_addr, peer_addr_2(D), peer_addr_len_3(D), 0, 0);
  instance pointer: peer_addr_2(D)  Outer instance pointer: peer_addr_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _6 = rfc7668_set_addr (&rfc7668_local_addr, local_addr_2(D), local_addr_len_3(D), 1, is_public_addr_4(D));
  Starting walk at: _6 = rfc7668_set_addr (&rfc7668_local_addr, local_addr_2(D), local_addr_len_3(D), 1, is_public_addr_4(D));
  instance pointer: &rfc7668_local_addr  Outer instance pointer: rfc7668_local_addr offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _6 = rfc7668_set_addr (&rfc7668_local_addr, local_addr_2(D), local_addr_len_3(D), 1, is_public_addr_4(D));
  Starting walk at: _6 = rfc7668_set_addr (&rfc7668_local_addr, local_addr_2(D), local_addr_len_3(D), 1, is_public_addr_4(D));
  instance pointer: local_addr_2(D)  Outer instance pointer: local_addr_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _5 = rfc7668_set_addr (&rfc7668_local_addr, local_addr_2(D), local_addr_len_3(D), 0, 0);
  Starting walk at: _5 = rfc7668_set_addr (&rfc7668_local_addr, local_addr_2(D), local_addr_len_3(D), 0, 0);
  instance pointer: &rfc7668_local_addr  Outer instance pointer: rfc7668_local_addr offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _5 = rfc7668_set_addr (&rfc7668_local_addr, local_addr_2(D), local_addr_len_3(D), 0, 0);
  Starting walk at: _5 = rfc7668_set_addr (&rfc7668_local_addr, local_addr_2(D), local_addr_len_3(D), 0, 0);
  instance pointer: local_addr_2(D)  Outer instance pointer: local_addr_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _3 = rfc7668_set_addr.part.0 (addr_5(D), in_addr_4(D));
  Starting walk at: _3 = rfc7668_set_addr.part.0 (addr_5(D), in_addr_4(D));
  instance pointer: addr_5(D)  Outer instance pointer: addr_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _3 = rfc7668_set_addr.part.0 (addr_5(D), in_addr_4(D));
  Starting walk at: _3 = rfc7668_set_addr.part.0 (addr_5(D), in_addr_4(D));
  instance pointer: in_addr_4(D)  Outer instance pointer: in_addr_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ble_addr_to_eui64 (_1, in_addr_4(D), is_public_addr_11(D));
  Starting walk at: ble_addr_to_eui64 (_1, in_addr_4(D), is_public_addr_11(D));
  instance pointer: _1  Outer instance pointer: addr_5(D) offset: 8 (bits) vtbl reference: 
Determining dynamic type for call: ble_addr_to_eui64 (_1, in_addr_4(D), is_public_addr_11(D));
  Starting walk at: ble_addr_to_eui64 (_1, in_addr_4(D), is_public_addr_11(D));
  instance pointer: in_addr_4(D)  Outer instance pointer: in_addr_4(D) offset: 0 (bits) vtbl reference: 

IPA structures before propagation:

Jump functions:
  Jump functions of caller  rfc7668_set_addr.part.0/24:
  Jump functions of caller  ip6_input/23:
  Jump functions of caller  lowpan6_decompress/22:
  Jump functions of caller  pbuf_copy_partial/21:
  Jump functions of caller  pbuf_remove_header/20:
  Jump functions of caller  pbuf_free/19:
  Jump functions of caller  lowpan6_compress_headers/18:
  Jump functions of caller  pbuf_alloc/17:
  Jump functions of caller  memcpy/16:
  Jump functions of caller  rfc7668_if_init/15:
  Jump functions of caller  rfc7668_input/14:
  Jump functions of caller  rfc7668_output/13:
    callsite  rfc7668_output/13 -> rfc7668_compress/11 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  rfc7668_set_context/12:
  Jump functions of caller  rfc7668_compress/11:
    indirect aggregate callsite, calling param 0, offset 1472, by reference, for stmt err_44 = _24 (netif_30(D), p_frag_33);
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  rfc7668_set_peer_addr_mac48/10:
    callsite  rfc7668_set_peer_addr_mac48/10 -> rfc7668_set_addr/6 : 
       param 0: CONST: &rfc7668_peer_addr
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 4: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
         Unknown VR
  Jump functions of caller  rfc7668_set_peer_addr_eui64/9:
    callsite  rfc7668_set_peer_addr_eui64/9 -> rfc7668_set_addr/6 : 
       param 0: CONST: &rfc7668_peer_addr
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 4: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  rfc7668_set_local_addr_mac48/8:
    callsite  rfc7668_set_local_addr_mac48/8 -> rfc7668_set_addr/6 : 
       param 0: CONST: &rfc7668_local_addr
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
       param 4: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
         Unknown VR
  Jump functions of caller  rfc7668_set_local_addr_eui64/7:
    callsite  rfc7668_set_local_addr_eui64/7 -> rfc7668_set_addr/6 : 
       param 0: CONST: &rfc7668_local_addr
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
       param 4: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  rfc7668_set_addr/6:
    callsite  rfc7668_set_addr/6 -> rfc7668_set_addr.part.0/24 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  rfc7668_set_addr/6 -> ble_addr_to_eui64/4 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 4, op nop_expr
         value: 0x0, mask: 0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
         Unknown VR
  Jump functions of caller  eui64_to_ble_addr/5:
  Jump functions of caller  ble_addr_to_eui64/4:

 Propagating constants:

Not considering rfc7668_if_init for cloning; -fipa-cp-clone disabled.
Not considering rfc7668_input for cloning; -fipa-cp-clone disabled.
Not considering rfc7668_output for cloning; -fipa-cp-clone disabled.
Not considering rfc7668_set_context for cloning; -fipa-cp-clone disabled.
Not considering rfc7668_set_peer_addr_mac48 for cloning; -fipa-cp-clone disabled.
Not considering rfc7668_set_peer_addr_eui64 for cloning; -fipa-cp-clone disabled.
Not considering rfc7668_set_local_addr_mac48 for cloning; -fipa-cp-clone disabled.
Not considering rfc7668_set_local_addr_eui64 for cloning; -fipa-cp-clone disabled.
Not considering eui64_to_ble_addr for cloning; -fipa-cp-clone disabled.
Not considering ble_addr_to_eui64 for cloning; -fipa-cp-clone disabled.

overall_size: 276, max_new_size: 11001
 - context independent values, size: 7, time_benefit: 1.000000
 - context independent values, size: 10, time_benefit: 1.000000
 - context independent values, size: 10, time_benefit: 1.000000
 - context independent values, size: 10, time_benefit: 1.000000
 - context independent values, size: 10, time_benefit: 1.000000

IPA lattices after all propagation:

Lattices:
  Node: rfc7668_set_addr.part.0/24:
    param [0]: &rfc7668_peer_addr [loc_time: 1, loc_size: 8, prop_time: 0, prop_size: 0]
               &rfc7668_local_addr [loc_time: 1, loc_size: 8, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct lowpan6_link_addr * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: rfc7668_if_init/15:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: rfc7668_input/14:
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
  Node: rfc7668_output/13:
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
  Node: rfc7668_set_context/12:
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
  Node: rfc7668_compress/11:
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
  Node: rfc7668_set_peer_addr_mac48/10:
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
  Node: rfc7668_set_peer_addr_eui64/9:
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
  Node: rfc7668_set_local_addr_mac48/8:
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
  Node: rfc7668_set_local_addr_eui64/7:
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
  Node: rfc7668_set_addr/6:
    param [0]: &rfc7668_local_addr [loc_time: 2, loc_size: 20, prop_time: 0, prop_size: 0]
               &rfc7668_peer_addr [loc_time: 2, loc_size: 20, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         struct lowpan6_link_addr * ~[0B, 0B]
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
    param [3]: 0 [loc_time: 2, loc_size: 13, prop_time: 0, prop_size: 0]
               1 [loc_time: 2, loc_size: 14, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x1, mask = 0x1
         int [0, 1]
        AGGS VARIABLE
    param [4]: VARIABLE
               0 [loc_time: 1, loc_size: 22, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: eui64_to_ble_addr/5:
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
  Node: ble_addr_to_eui64/4:
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

Propagated bits info for function rfc7668_set_addr/6:
 param 3: value = 0x1, mask = 0x1

IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

rfc7668_set_addr.part.0/24 (rfc7668_set_addr.part.0) @06afe8c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: rfc7668_set_addr/6 (510874356 (estimated locally),0.48 per call) 
  Calls: memcpy/16 (1073741824 (estimated locally),1.00 per call) 
ip6_input/23 (ip6_input) @06cf47e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: rfc7668_input/14 (568070715 (estimated locally),0.53 per call) 
  Calls: 
lowpan6_decompress/22 (lowpan6_decompress) @06cf4700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: rfc7668_input/14 (428208240 (estimated locally),0.40 per call) 
  Calls: 
pbuf_copy_partial/21 (pbuf_copy_partial) @06cf4540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: rfc7668_compress/11 (16409 (estimated locally),0.07 per call) 
  Calls: 
pbuf_remove_header/20 (pbuf_remove_header) @06cf4460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: rfc7668_input/14 (217325345 (estimated locally),0.20 per call) rfc7668_compress/11 (16409 (estimated locally),0.07 per call) 
  Calls: 
pbuf_free/19 (pbuf_free) @06cf4380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: rfc7668_input/14 (428208240 (estimated locally),0.40 per call) rfc7668_compress/11 (16409 (estimated locally),0.07 per call) rfc7668_compress/11 (8453 (estimated locally),0.04 per call) 
  Calls: 
lowpan6_compress_headers/18 (lowpan6_compress_headers) @06cf42a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: rfc7668_compress/11 (24862 (estimated locally),0.11 per call) 
  Calls: 
pbuf_alloc/17 (pbuf_alloc) @06cf41c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: rfc7668_compress/11 (123389 (estimated locally),0.53 per call) 
  Calls: 
memcpy/16 (memcpy) @06cb59a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: eui64_to_ble_addr/5 (1073741824 (estimated locally),1.00 per call) eui64_to_ble_addr/5 (1073741824 (estimated locally),1.00 per call) rfc7668_set_addr.part.0/24 (1073741824 (estimated locally),1.00 per call) ble_addr_to_eui64/4 (1073741824 (estimated locally),1.00 per call) ble_addr_to_eui64/4 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
rfc7668_if_init/15 (rfc7668_if_init) @06cb5540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: rfc7668_output/13 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
rfc7668_input/14 (rfc7668_input) @06cb52a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: rfc7668_context/1 (addr)rfc7668_peer_addr/3 (addr)rfc7668_local_addr/2 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: ip6_input/23 (568070715 (estimated locally),0.53 per call) pbuf_free/19 (428208240 (estimated locally),0.40 per call) lowpan6_decompress/22 (428208240 (estimated locally),0.40 per call) pbuf_remove_header/20 (217325345 (estimated locally),0.20 per call) 
rfc7668_output/13 (rfc7668_output) @06ca62a0
  Type: function definition analyzed
  Visibility: externally_visible public
  Address is taken.
  References: 
  Referring: rfc7668_if_init/15 (addr)
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: rfc7668_compress/11 (1073741824 (estimated locally),1.00 per call) 
rfc7668_set_context/12 (rfc7668_set_context) @06ca6ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: rfc7668_context/1 (write)rfc7668_context/1 (write)rfc7668_context/1 (write)rfc7668_context/1 (write)rfc7668_context/1 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
rfc7668_compress/11 (rfc7668_compress) @06ca6c40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: rfc7668_context/1 (addr)rfc7668_local_addr/2 (addr)rfc7668_peer_addr/3 (addr)
  Referring: 
  Availability: local
  Function flags: count:230763 (estimated locally) body local optimize_size
  Called by: rfc7668_output/13 (1073741824 (estimated locally),1.00 per call) 
  Calls: pbuf_free/19 (16409 (estimated locally),0.07 per call) pbuf_copy_partial/21 (16409 (estimated locally),0.07 per call) pbuf_remove_header/20 (16409 (estimated locally),0.07 per call) pbuf_free/19 (8453 (estimated locally),0.04 per call) lowpan6_compress_headers/18 (24862 (estimated locally),0.11 per call) pbuf_alloc/17 (123389 (estimated locally),0.53 per call) 
   Indirect call(16409 (estimated locally),0.07 per call)  of param:0 loaded from aggregate passed by reference at offset 1472 (vptr maybe changed)
rfc7668_set_peer_addr_mac48/10 (rfc7668_set_peer_addr_mac48) @06ca6700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: rfc7668_peer_addr/3 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: rfc7668_set_addr/6 (1073741824 (estimated locally),1.00 per call) 
rfc7668_set_peer_addr_eui64/9 (rfc7668_set_peer_addr_eui64) @06ca6460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: rfc7668_peer_addr/3 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: rfc7668_set_addr/6 (1073741824 (estimated locally),1.00 per call) 
rfc7668_set_local_addr_mac48/8 (rfc7668_set_local_addr_mac48) @06ca61c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: rfc7668_local_addr/2 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: rfc7668_set_addr/6 (1073741824 (estimated locally),1.00 per call) 
rfc7668_set_local_addr_eui64/7 (rfc7668_set_local_addr_eui64) @06ca1a80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: rfc7668_local_addr/2 (addr)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: rfc7668_set_addr/6 (1073741824 (estimated locally),1.00 per call) 
rfc7668_set_addr/6 (rfc7668_set_addr) @06ca1ee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741823 (estimated locally) body local optimize_size
  Called by: rfc7668_set_peer_addr_mac48/10 (1073741824 (estimated locally),1.00 per call) rfc7668_set_peer_addr_eui64/9 (1073741824 (estimated locally),1.00 per call) rfc7668_set_local_addr_mac48/8 (1073741824 (estimated locally),1.00 per call) rfc7668_set_local_addr_eui64/7 (1073741824 (estimated locally),1.00 per call) 
  Calls: rfc7668_set_addr.part.0/24 (510874356 (estimated locally),0.48 per call) ble_addr_to_eui64/4 (510874357 (estimated locally),0.48 per call) 
eui64_to_ble_addr/5 (eui64_to_ble_addr) @06ca1c40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: memcpy/16 (1073741824 (estimated locally),1.00 per call) memcpy/16 (1073741824 (estimated locally),1.00 per call) 
ble_addr_to_eui64/4 (ble_addr_to_eui64) @06ca19a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: rfc7668_set_addr/6 (510874357 (estimated locally),0.48 per call) 
  Calls: memcpy/16 (1073741824 (estimated locally),1.00 per call) memcpy/16 (1073741824 (estimated locally),1.00 per call) 
rfc7668_peer_addr/3 (rfc7668_peer_addr) @06ca2708
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: rfc7668_set_peer_addr_mac48/10 (addr)rfc7668_compress/11 (addr)rfc7668_set_peer_addr_eui64/9 (addr)rfc7668_input/14 (addr)
  Availability: available
  Varpool flags:
rfc7668_local_addr/2 (rfc7668_local_addr) @06ca2678
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: rfc7668_set_local_addr_mac48/8 (addr)rfc7668_compress/11 (addr)rfc7668_set_local_addr_eui64/7 (addr)rfc7668_input/14 (addr)
  Availability: available
  Varpool flags:
rfc7668_context/1 (rfc7668_context) @06ca25e8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: rfc7668_set_context/12 (write)rfc7668_compress/11 (addr)rfc7668_set_context/12 (write)rfc7668_set_context/12 (write)rfc7668_set_context/12 (write)rfc7668_set_context/12 (write)rfc7668_input/14 (addr)
  Availability: available
  Varpool flags:

;; Function rfc7668_output (rfc7668_output, funcdef_no=10, decl_uid=6982, cgraph_uid=11, symbol_order=13)

Modification phase of node rfc7668_output/13
rfc7668_output (struct netif * netif, struct pbuf * q, const struct ip6_addr_t * ip6addr)
{
  err_t _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _5 = rfc7668_compress (netif_2(D), q_3(D));
  return _5;

}



;; Function ble_addr_to_eui64 (ble_addr_to_eui64, funcdef_no=1, decl_uid=7012, cgraph_uid=2, symbol_order=4)

Modification phase of node ble_addr_to_eui64/4
ble_addr_to_eui64 (uint8_t * dst, const uint8_t * src, int public_addr)
{
  uint8_t * _1;
  const uint8_t * _2;
  unsigned char _3;
  unsigned char _4;
  unsigned char _5;
  unsigned char _6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  memcpy (dst_9(D), src_10(D), 3);
  # DEBUG BEGIN_STMT
  MEM[(uint8_t *)dst_9(D) + 3B] = 255;
  # DEBUG BEGIN_STMT
  MEM[(uint8_t *)dst_9(D) + 4B] = 254;
  # DEBUG BEGIN_STMT
  _1 = dst_9(D) + 5;
  _2 = src_10(D) + 3;
  memcpy (_1, _2, 3);
  # DEBUG BEGIN_STMT
  if (public_addr_15(D) != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _3 = *dst_9(D);
  _4 = _3 & 253;
  *dst_9(D) = _4;
  goto <bb 5>; [100.00%]

  <bb 4> [local count: 536870913]:
  # DEBUG BEGIN_STMT
  _5 = *dst_9(D);
  _6 = _5 | 2;
  *dst_9(D) = _6;

  <bb 5> [local count: 1073741824]:
  return;

}



;; Function eui64_to_ble_addr (eui64_to_ble_addr, funcdef_no=2, decl_uid=7015, cgraph_uid=3, symbol_order=5)

Modification phase of node eui64_to_ble_addr/5
eui64_to_ble_addr (uint8_t * dst, const uint8_t * src)
{
  uint8_t * _1;
  const uint8_t * _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  memcpy (dst_4(D), src_5(D), 3);
  # DEBUG BEGIN_STMT
  _1 = dst_4(D) + 3;
  _2 = src_5(D) + 5;
  memcpy (_1, _2, 3);
  return;

}



;; Function rfc7668_set_local_addr_eui64 (rfc7668_set_local_addr_eui64, funcdef_no=4, decl_uid=6989, cgraph_uid=5, symbol_order=7)

Modification phase of node rfc7668_set_local_addr_eui64/7
rfc7668_set_local_addr_eui64 (struct netif * netif, const u8_t * local_addr, size_t local_addr_len)
{
  err_t _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _5 = rfc7668_set_addr (&rfc7668_local_addr, local_addr_2(D), local_addr_len_3(D), 0, 0);
  return _5;

}



;; Function rfc7668_set_local_addr_mac48 (rfc7668_set_local_addr_mac48, funcdef_no=5, decl_uid=6994, cgraph_uid=6, symbol_order=8)

Modification phase of node rfc7668_set_local_addr_mac48/8
rfc7668_set_local_addr_mac48 (struct netif * netif, const u8_t * local_addr, size_t local_addr_len, int is_public_addr)
{
  err_t _6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _6 = rfc7668_set_addr (&rfc7668_local_addr, local_addr_2(D), local_addr_len_3(D), 1, is_public_addr_4(D));
  return _6;

}



;; Function rfc7668_set_peer_addr_eui64 (rfc7668_set_peer_addr_eui64, funcdef_no=6, decl_uid=6998, cgraph_uid=7, symbol_order=9)

Modification phase of node rfc7668_set_peer_addr_eui64/9
rfc7668_set_peer_addr_eui64 (struct netif * netif, const u8_t * peer_addr, size_t peer_addr_len)
{
  err_t _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _5 = rfc7668_set_addr (&rfc7668_peer_addr, peer_addr_2(D), peer_addr_len_3(D), 0, 0);
  return _5;

}



;; Function rfc7668_set_peer_addr_mac48 (rfc7668_set_peer_addr_mac48, funcdef_no=7, decl_uid=7003, cgraph_uid=8, symbol_order=10)

Modification phase of node rfc7668_set_peer_addr_mac48/10
rfc7668_set_peer_addr_mac48 (struct netif * netif, const u8_t * peer_addr, size_t peer_addr_len, int is_public_addr)
{
  err_t _6;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _6 = rfc7668_set_addr (&rfc7668_peer_addr, peer_addr_2(D), peer_addr_len_3(D), 1, is_public_addr_4(D));
  return _6;

}



;; Function rfc7668_set_context (rfc7668_set_context, funcdef_no=9, decl_uid=7006, cgraph_uid=10, symbol_order=12)

Modification phase of node rfc7668_set_context/12
rfc7668_set_context (u8_t idx, const struct ip6_addr_t * context)
{
  int _1;
  err_t _2;
  const long unsigned int iftmp.0_3;
  const long unsigned int iftmp.1_4;
  const long unsigned int iftmp.2_5;
  const long unsigned int iftmp.3_6;
  u8_t iftmp.4_7;
  const long unsigned int iftmp.0_12;
  const long unsigned int iftmp.1_14;
  const long unsigned int iftmp.2_16;
  const long unsigned int iftmp.3_18;
  u8_t iftmp.4_20;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  if (idx_9(D) > 9)
    goto <bb 14>; [1.04%]
  else
    goto <bb 3>; [98.96%]

  <bb 3> [local count: 1062574910]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (context_10(D) != 0B)
    goto <bb 4>; [70.00%]
  else
    goto <bb 5>; [30.00%]

  <bb 4> [local count: 743802437]:
  iftmp.0_12 = context_10(D)->addr[0];

  <bb 5> [local count: 1062574910]:
  # iftmp.0_3 = PHI <iftmp.0_12(4), 0(3)>
  _1 = (int) idx_9(D);
  rfc7668_context[_1].addr[0] = iftmp.0_3;
  # DEBUG BEGIN_STMT
  if (context_10(D) != 0B)
    goto <bb 6>; [70.00%]
  else
    goto <bb 7>; [30.00%]

  <bb 6> [local count: 743802437]:
  iftmp.1_14 = context_10(D)->addr[1];

  <bb 7> [local count: 1062574910]:
  # iftmp.1_4 = PHI <iftmp.1_14(6), 0(5)>
  rfc7668_context[_1].addr[1] = iftmp.1_4;
  # DEBUG BEGIN_STMT
  if (context_10(D) != 0B)
    goto <bb 8>; [70.00%]
  else
    goto <bb 9>; [30.00%]

  <bb 8> [local count: 743802437]:
  iftmp.2_16 = context_10(D)->addr[2];

  <bb 9> [local count: 1062574910]:
  # iftmp.2_5 = PHI <iftmp.2_16(8), 0(7)>
  rfc7668_context[_1].addr[2] = iftmp.2_5;
  # DEBUG BEGIN_STMT
  if (context_10(D) != 0B)
    goto <bb 10>; [70.00%]
  else
    goto <bb 11>; [30.00%]

  <bb 10> [local count: 743802437]:
  iftmp.3_18 = context_10(D)->addr[3];

  <bb 11> [local count: 1062574910]:
  # iftmp.3_6 = PHI <iftmp.3_18(10), 0(9)>
  rfc7668_context[_1].addr[3] = iftmp.3_6;
  # DEBUG BEGIN_STMT
  if (context_10(D) != 0B)
    goto <bb 12>; [70.00%]
  else
    goto <bb 13>; [30.00%]

  <bb 12> [local count: 743802437]:
  iftmp.4_20 = context_10(D)->zone;

  <bb 13> [local count: 1062574910]:
  # iftmp.4_7 = PHI <iftmp.4_20(12), 0(11)>
  rfc7668_context[_1].zone = iftmp.4_7;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT

  <bb 14> [local count: 1073741824]:
  # _2 = PHI <-16(2), 0(13)>
  return _2;

}



;; Function rfc7668_input (rfc7668_input, funcdef_no=11, decl_uid=6985, cgraph_uid=12, symbol_order=14)

Modification phase of node rfc7668_input/14
rfc7668_input (struct pbuf * p, struct netif * netif)
{
  u8_t * puc;
  long unsigned int _1;
  short unsigned int _2;
  long unsigned int _3;
  long unsigned int _4;
  unsigned char _5;
  long unsigned int _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _9;
  long unsigned int _10;
  long unsigned int _11;
  err_t _13;
  unsigned char _23;
  err_t _30;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = netif_17(D)->mib2_counters.ifinoctets;
  _2 = p_18(D)->tot_len;
  _3 = (long unsigned int) _2;
  _4 = _1 + _3;
  netif_17(D)->mib2_counters.ifinoctets = _4;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  puc_20 = p_18(D)->payload;
  # DEBUG puc => puc_20
  # DEBUG BEGIN_STMT
  _5 = *puc_20;
  if (_5 == 65)
    goto <bb 3>; [20.24%]
  else
    goto <bb 4>; [79.76%]

  <bb 3> [local count: 217325345]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pbuf_remove_header (p_18(D), 1);
  goto <bb 8>; [100.00%]

  <bb 4> [local count: 856416480]:
  # DEBUG BEGIN_STMT
  _23 = _5 & 224;
  if (_23 == 96)
    goto <bb 5>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 5> [local count: 428208240]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  p_25 = lowpan6_decompress (p_18(D), 0, &rfc7668_context, &rfc7668_peer_addr, &rfc7668_local_addr);
  # DEBUG p => p_25
  # DEBUG BEGIN_STMT
  if (p_25 == 0B)
    goto <bb 6>; [18.09%]
  else
    goto <bb 8>; [81.91%]

  <bb 6> [local count: 77462871]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _6 = netif_17(D)->mib2_counters.ifindiscards;
  _7 = _6 + 1;
  netif_17(D)->mib2_counters.ifindiscards = _7;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 9>; [100.00%]

  <bb 7> [local count: 428208240]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _8 = netif_17(D)->mib2_counters.ifindiscards;
  _9 = _8 + 1;
  netif_17(D)->mib2_counters.ifindiscards = _9;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  pbuf_free (p_18(D));
  # DEBUG BEGIN_STMT
  goto <bb 9>; [100.00%]

  <bb 8> [local count: 568070715]:
  # p_12 = PHI <p_18(D)(3), p_25(5)>
  # DEBUG p => p_12
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _10 = netif_17(D)->mib2_counters.ifinucastpkts;
  _11 = _10 + 1;
  netif_17(D)->mib2_counters.ifinucastpkts = _11;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _30 = ip6_input (p_12, netif_17(D));

  <bb 9> [local count: 1073741824]:
  # _13 = PHI <0(6), 0(7), _30(8)>
  return _13;

}



;; Function rfc7668_if_init (rfc7668_if_init, funcdef_no=12, decl_uid=7008, cgraph_uid=13, symbol_order=15)

Modification phase of node rfc7668_if_init/15
rfc7668_if_init (struct netif * netif)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  netif_2(D)->name[0] = 98;
  # DEBUG BEGIN_STMT
  netif_2(D)->name[1] = 116;
  # DEBUG BEGIN_STMT
  netif_2(D)->output_ip6 = rfc7668_output;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  netif_2(D)->link_type = 1;
  # DEBUG BEGIN_STMT
  netif_2(D)->link_speed = 0;
  # DEBUG BEGIN_STMT
  netif_2(D)->ts = 0;
  # DEBUG BEGIN_STMT
  netif_2(D)->mib2_counters.ifinoctets = 0;
  # DEBUG BEGIN_STMT
  netif_2(D)->mib2_counters.ifinucastpkts = 0;
  # DEBUG BEGIN_STMT
  netif_2(D)->mib2_counters.ifinnucastpkts = 0;
  # DEBUG BEGIN_STMT
  netif_2(D)->mib2_counters.ifindiscards = 0;
  # DEBUG BEGIN_STMT
  netif_2(D)->mib2_counters.ifinerrors = 0;
  # DEBUG BEGIN_STMT
  netif_2(D)->mib2_counters.ifinunknownprotos = 0;
  # DEBUG BEGIN_STMT
  netif_2(D)->mib2_counters.ifoutoctets = 0;
  # DEBUG BEGIN_STMT
  netif_2(D)->mib2_counters.ifoutucastpkts = 0;
  # DEBUG BEGIN_STMT
  netif_2(D)->mib2_counters.ifoutnucastpkts = 0;
  # DEBUG BEGIN_STMT
  netif_2(D)->mib2_counters.ifoutdiscards = 0;
  # DEBUG BEGIN_STMT
  netif_2(D)->mib2_counters.ifouterrors = 0;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  netif_2(D)->mtu = 1280;
  # DEBUG BEGIN_STMT
  netif_2(D)->flags = 0;
  # DEBUG BEGIN_STMT
  return 0;

}


