
IPA constant propagation start:
Determining dynamic type for call: _2 = snmp_vb_enumerator_get_next.part.0 (enumerator_6(D), varbind_8(D));
  Starting walk at: _2 = snmp_vb_enumerator_get_next.part.0 (enumerator_6(D), varbind_8(D));
  instance pointer: enumerator_6(D)  Outer instance pointer: enumerator_6(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _2 = snmp_vb_enumerator_get_next.part.0 (enumerator_6(D), varbind_8(D));
  Starting walk at: _2 = snmp_vb_enumerator_get_next.part.0 (enumerator_6(D), varbind_8(D));
  instance pointer: varbind_8(D)  Outer instance pointer: varbind_8(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: snmp_vb_enumerator_init (&inbound_varbind_enumerator, _1, _2, _3);
  Starting walk at: snmp_vb_enumerator_init (&inbound_varbind_enumerator, _1, _2, _3);
  instance pointer: &inbound_varbind_enumerator  Outer instance pointer: inbound_varbind_enumerator offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: snmp_vb_enumerator_init (&inbound_varbind_enumerator, _1, _2, _3);
  Starting walk at: snmp_vb_enumerator_init (&inbound_varbind_enumerator, _1, _2, _3);
  instance pointer: _1  Outer instance pointer: _1 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _7 = snmp_vb_enumerator_get_next (&inbound_varbind_enumerator, &vb);
  Starting walk at: _7 = snmp_vb_enumerator_get_next (&inbound_varbind_enumerator, &vb);
  instance pointer: &inbound_varbind_enumerator  Outer instance pointer: inbound_varbind_enumerator offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:snmp_vb_enumerator_init (&inbound_varbind_enumerator, _1, _2, _3);
  Function call may change dynamic type:snmp_write_callback.14_4 (&vb.oid.id, _5, snmp_write_callback_arg.15_6);
  Function call may change dynamic type:_7 = snmp_vb_enumerator_get_next (&inbound_varbind_enumerator, &vb);
Determining dynamic type for call: _7 = snmp_vb_enumerator_get_next (&inbound_varbind_enumerator, &vb);
  Starting walk at: _7 = snmp_vb_enumerator_get_next (&inbound_varbind_enumerator, &vb);
  instance pointer: &vb  Outer instance pointer: vb offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:snmp_vb_enumerator_init (&inbound_varbind_enumerator, _1, _2, _3);
  Function call may change dynamic type:snmp_write_callback.14_4 (&vb.oid.id, _5, snmp_write_callback_arg.15_6);
  Function call may change dynamic type:_7 = snmp_vb_enumerator_get_next (&inbound_varbind_enumerator, &vb);
Determining dynamic type for call: snmp_write_callback.14_4 (&vb.oid.id, _5, snmp_write_callback_arg.15_6);
  Starting walk at: snmp_write_callback.14_4 (&vb.oid.id, _5, snmp_write_callback_arg.15_6);
  instance pointer: &vb.oid.id  Outer instance pointer: vb offset: 96 (bits) vtbl reference: 
  Function call may change dynamic type:_7 = snmp_vb_enumerator_get_next (&inbound_varbind_enumerator, &vb);
  Function call may change dynamic type:snmp_vb_enumerator_init (&inbound_varbind_enumerator, _1, _2, _3);
  Function call may change dynamic type:snmp_write_callback.14_4 (&vb.oid.id, _5, snmp_write_callback_arg.15_6);
  Function call may change dynamic type:_7 = snmp_vb_enumerator_get_next (&inbound_varbind_enumerator, &vb);
Determining dynamic type for call: snmp_write_callback.14_4 (&vb.oid.id, _5, snmp_write_callback_arg.15_6);
  Starting walk at: snmp_write_callback.14_4 (&vb.oid.id, _5, snmp_write_callback_arg.15_6);
  instance pointer: snmp_write_callback_arg.15_6  Outer instance pointer: snmp_write_callback_arg.15_6 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_7 = snmp_vb_enumerator_get_next (&inbound_varbind_enumerator, &vb);
  Function call may change dynamic type:snmp_vb_enumerator_init (&inbound_varbind_enumerator, _1, _2, _3);
  Function call may change dynamic type:snmp_write_callback.14_4 (&vb.oid.id, _5, snmp_write_callback_arg.15_6);
  Function call may change dynamic type:_7 = snmp_vb_enumerator_get_next (&inbound_varbind_enumerator, &vb);
Determining dynamic type for call: err_46 = snmp_varbind_length (varbind_44(D), &len);
  Starting walk at: err_46 = snmp_varbind_length (varbind_44(D), &len);
  instance pointer: varbind_44(D)  Outer instance pointer: varbind_44(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: err_46 = snmp_varbind_length (varbind_44(D), &len);
  Starting walk at: err_46 = snmp_varbind_length (varbind_44(D), &len);
  instance pointer: &len  Outer instance pointer: len offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: snmp_vb_enumerator_init (_179, _180, _176, _178);
  Starting walk at: snmp_vb_enumerator_init (_179, _180, _176, _178);
  instance pointer: _179  Outer instance pointer: request_189(D) offset: 416 (bits) vtbl reference: 
  Function call may change dynamic type:_168 = snmp_asn1_dec_tlv (&pbuf_stream, &tlv);
  Function call may change dynamic type:_157 = snmp_asn1_dec_s32t (&pbuf_stream, _150, _156);
  Function call may change dynamic type:_139 = snmp_asn1_dec_tlv (&pbuf_stream, &tlv);
  Function call may change dynamic type:_129 = snmp_asn1_dec_s32t (&pbuf_stream, _122, _128);
  Function call may change dynamic type:_111 = snmp_asn1_dec_tlv (&pbuf_stream, &tlv);
  Function call may change dynamic type:_108 = snmp_asn1_dec_s32t (&pbuf_stream, _102, _107);
  Function call may change dynamic type:_91 = snmp_asn1_dec_tlv (&pbuf_stream, &tlv);
  Function call may change dynamic type:_62 = snmp_asn1_dec_tlv (&pbuf_stream, &tlv);
  Function call may change dynamic type:snmp_pbuf_stream_seek (&pbuf_stream, _57);
  Function call may change dynamic type:err_200 = snmp_asn1_dec_raw (&pbuf_stream, _49, _54, _55, 8);
  Function call may change dynamic type:_38 = snmp_asn1_dec_tlv (&pbuf_stream, &tlv);
  Function call may change dynamic type:_30 = snmp_asn1_dec_s32t (&pbuf_stream, _25, &s32_value);
  Function call may change dynamic type:_14 = snmp_asn1_dec_tlv (&pbuf_stream, &tlv);
  Function call may change dynamic type:_6 = snmp_asn1_dec_tlv (&pbuf_stream, &tlv);
  Function call may change dynamic type:_3 = snmp_pbuf_stream_init (&pbuf_stream, _1, 0, _2);
  Function call may change dynamic type:_133 = snmp_asn1_dec_s32t (&pbuf_stream, _122, &s32_value);
  Function call may change dynamic type:_162 = snmp_asn1_dec_s32t (&pbuf_stream, _150, _161);
Determining dynamic type for call: snmp_vb_enumerator_init (_179, _180, _176, _178);
  Starting walk at: snmp_vb_enumerator_init (_179, _180, _176, _178);
  instance pointer: _180  Outer instance pointer: _180 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_168 = snmp_asn1_dec_tlv (&pbuf_stream, &tlv);
  Function call may change dynamic type:_157 = snmp_asn1_dec_s32t (&pbuf_stream, _150, _156);
  Function call may change dynamic type:_139 = snmp_asn1_dec_tlv (&pbuf_stream, &tlv);
  Function call may change dynamic type:_129 = snmp_asn1_dec_s32t (&pbuf_stream, _122, _128);
  Function call may change dynamic type:_111 = snmp_asn1_dec_tlv (&pbuf_stream, &tlv);
  Function call may change dynamic type:_108 = snmp_asn1_dec_s32t (&pbuf_stream, _102, _107);
  Function call may change dynamic type:_91 = snmp_asn1_dec_tlv (&pbuf_stream, &tlv);
  Function call may change dynamic type:_62 = snmp_asn1_dec_tlv (&pbuf_stream, &tlv);
  Function call may change dynamic type:snmp_pbuf_stream_seek (&pbuf_stream, _57);
  Function call may change dynamic type:err_200 = snmp_asn1_dec_raw (&pbuf_stream, _49, _54, _55, 8);
  Function call may change dynamic type:_38 = snmp_asn1_dec_tlv (&pbuf_stream, &tlv);
  Function call may change dynamic type:_30 = snmp_asn1_dec_s32t (&pbuf_stream, _25, &s32_value);
  Function call may change dynamic type:_14 = snmp_asn1_dec_tlv (&pbuf_stream, &tlv);
  Function call may change dynamic type:_6 = snmp_asn1_dec_tlv (&pbuf_stream, &tlv);
  Function call may change dynamic type:_3 = snmp_pbuf_stream_init (&pbuf_stream, _1, 0, _2);
  Function call may change dynamic type:_133 = snmp_asn1_dec_s32t (&pbuf_stream, _122, &s32_value);
  Function call may change dynamic type:_162 = snmp_asn1_dec_s32t (&pbuf_stream, _150, _161);
Determining dynamic type for call: err_47 = snmp_vb_enumerator_get_next (_2, &vb);
  Starting walk at: err_47 = snmp_vb_enumerator_get_next (_2, &vb);
  instance pointer: _2  Outer instance pointer: request_43(D) offset: 416 (bits) vtbl reference: 
  Function call may change dynamic type:_4 = snmp_get_node_instance_from_oid (&vb.oid.id, _3, &node_instance);
  Function call may change dynamic type:err_47 = snmp_vb_enumerator_get_next (_2, &vb);
  Function call may change dynamic type:_15 = _11 (&node_instance, _13, _14);
  Function call may change dynamic type:_17 (&node_instance);
Determining dynamic type for call: err_47 = snmp_vb_enumerator_get_next (_2, &vb);
  Starting walk at: err_47 = snmp_vb_enumerator_get_next (_2, &vb);
  instance pointer: &vb  Outer instance pointer: vb offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_4 = snmp_get_node_instance_from_oid (&vb.oid.id, _3, &node_instance);
  Function call may change dynamic type:err_47 = snmp_vb_enumerator_get_next (_2, &vb);
  Function call may change dynamic type:_15 = _11 (&node_instance, _13, _14);
  Function call may change dynamic type:_17 (&node_instance);
Determining dynamic type for call: _15 = _11 (&node_instance, _13, _14);
  Starting walk at: _15 = _11 (&node_instance, _13, _14);
  instance pointer: &node_instance  Outer instance pointer: node_instance offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_4 = snmp_get_node_instance_from_oid (&vb.oid.id, _3, &node_instance);
  Function call may change dynamic type:memset (&node_instance, 0, 248);
  Function call may change dynamic type:err_47 = snmp_vb_enumerator_get_next (_2, &vb);
  Function call may change dynamic type:_4 = snmp_get_node_instance_from_oid (&vb.oid.id, _3, &node_instance);
  Function call may change dynamic type:memset (&node_instance, 0, 248);
  Function call may change dynamic type:err_47 = snmp_vb_enumerator_get_next (_2, &vb);
  Function call may change dynamic type:_15 = _11 (&node_instance, _13, _14);
  Function call may change dynamic type:_17 (&node_instance);
Determining dynamic type for call: _15 = _11 (&node_instance, _13, _14);
  Starting walk at: _15 = _11 (&node_instance, _13, _14);
  instance pointer: _14  Outer instance pointer: _14 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_4 = snmp_get_node_instance_from_oid (&vb.oid.id, _3, &node_instance);
  Function call may change dynamic type:memset (&node_instance, 0, 248);
  Function call may change dynamic type:err_47 = snmp_vb_enumerator_get_next (_2, &vb);
  Function call may change dynamic type:_4 = snmp_get_node_instance_from_oid (&vb.oid.id, _3, &node_instance);
  Function call may change dynamic type:memset (&node_instance, 0, 248);
  Function call may change dynamic type:err_47 = snmp_vb_enumerator_get_next (_2, &vb);
  Function call may change dynamic type:_15 = _11 (&node_instance, _13, _14);
  Function call may change dynamic type:_17 (&node_instance);
Determining dynamic type for call: _17 (&node_instance);
  Starting walk at: _17 (&node_instance);
  instance pointer: &node_instance  Outer instance pointer: node_instance offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_4 = snmp_get_node_instance_from_oid (&vb.oid.id, _3, &node_instance);
  Function call may change dynamic type:memset (&node_instance, 0, 248);
  Function call may change dynamic type:err_47 = snmp_vb_enumerator_get_next (_2, &vb);
  Function call may change dynamic type:_15 = _11 (&node_instance, _13, _14);
  Function call may change dynamic type:_17 (&node_instance);
Determining dynamic type for call: snmp_vb_enumerator_init (_20, _21, _22, _23);
  Starting walk at: snmp_vb_enumerator_init (_20, _21, _22, _23);
  instance pointer: _20  Outer instance pointer: request_43(D) offset: 416 (bits) vtbl reference: 
  Function call may change dynamic type:err_47 = snmp_vb_enumerator_get_next (_2, &vb);
  Function call may change dynamic type:_4 = snmp_get_node_instance_from_oid (&vb.oid.id, _3, &node_instance);
  Function call may change dynamic type:_15 = _11 (&node_instance, _13, _14);
  Function call may change dynamic type:_17 (&node_instance);
Determining dynamic type for call: snmp_vb_enumerator_init (_20, _21, _22, _23);
  Starting walk at: snmp_vb_enumerator_init (_20, _21, _22, _23);
  instance pointer: _21  Outer instance pointer: _21 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_47 = snmp_vb_enumerator_get_next (_2, &vb);
  Function call may change dynamic type:_4 = snmp_get_node_instance_from_oid (&vb.oid.id, _3, &node_instance);
  Function call may change dynamic type:memset (&node_instance, 0, 248);
  Function call may change dynamic type:_15 = _11 (&node_instance, _13, _14);
  Function call may change dynamic type:_17 (&node_instance);
Determining dynamic type for call: err_62 = snmp_vb_enumerator_get_next (_20, &vb);
  Starting walk at: err_62 = snmp_vb_enumerator_get_next (_20, &vb);
  instance pointer: _20  Outer instance pointer: request_43(D) offset: 416 (bits) vtbl reference: 
  Function call may change dynamic type:_25 = snmp_get_node_instance_from_oid (&vb.oid.id, _24, &node_instance);
  Function call may change dynamic type:err_62 = snmp_vb_enumerator_get_next (_20, &vb);
  Function call may change dynamic type:snmp_vb_enumerator_init (_20, _21, _22, _23);
  Function call may change dynamic type:err_47 = snmp_vb_enumerator_get_next (_2, &vb);
  Function call may change dynamic type:_4 = snmp_get_node_instance_from_oid (&vb.oid.id, _3, &node_instance);
  Function call may change dynamic type:_15 = _11 (&node_instance, _13, _14);
  Function call may change dynamic type:_17 (&node_instance);
  Function call may change dynamic type:_30 = _27 (&node_instance, _28, _29);
  Function call may change dynamic type:_32 (&node_instance);
Determining dynamic type for call: err_62 = snmp_vb_enumerator_get_next (_20, &vb);
  Starting walk at: err_62 = snmp_vb_enumerator_get_next (_20, &vb);
  instance pointer: &vb  Outer instance pointer: vb offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_25 = snmp_get_node_instance_from_oid (&vb.oid.id, _24, &node_instance);
  Function call may change dynamic type:err_62 = snmp_vb_enumerator_get_next (_20, &vb);
  Function call may change dynamic type:snmp_vb_enumerator_init (_20, _21, _22, _23);
  Function call may change dynamic type:err_47 = snmp_vb_enumerator_get_next (_2, &vb);
  Function call may change dynamic type:_4 = snmp_get_node_instance_from_oid (&vb.oid.id, _3, &node_instance);
  Function call may change dynamic type:_15 = _11 (&node_instance, _13, _14);
  Function call may change dynamic type:_17 (&node_instance);
  Function call may change dynamic type:_30 = _27 (&node_instance, _28, _29);
  Function call may change dynamic type:_32 (&node_instance);
Determining dynamic type for call: _30 = _27 (&node_instance, _28, _29);
  Starting walk at: _30 = _27 (&node_instance, _28, _29);
  instance pointer: &node_instance  Outer instance pointer: node_instance offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_25 = snmp_get_node_instance_from_oid (&vb.oid.id, _24, &node_instance);
  Function call may change dynamic type:memset (&node_instance, 0, 248);
  Function call may change dynamic type:err_62 = snmp_vb_enumerator_get_next (_20, &vb);
  Function call may change dynamic type:_25 = snmp_get_node_instance_from_oid (&vb.oid.id, _24, &node_instance);
  Function call may change dynamic type:memset (&node_instance, 0, 248);
  Function call may change dynamic type:err_62 = snmp_vb_enumerator_get_next (_20, &vb);
  Function call may change dynamic type:snmp_vb_enumerator_init (_20, _21, _22, _23);
  Function call may change dynamic type:err_47 = snmp_vb_enumerator_get_next (_2, &vb);
  Function call may change dynamic type:_4 = snmp_get_node_instance_from_oid (&vb.oid.id, _3, &node_instance);
  Function call may change dynamic type:_15 = _11 (&node_instance, _13, _14);
  Function call may change dynamic type:_17 (&node_instance);
  Function call may change dynamic type:_30 = _27 (&node_instance, _28, _29);
  Function call may change dynamic type:_32 (&node_instance);
Determining dynamic type for call: _30 = _27 (&node_instance, _28, _29);
  Starting walk at: _30 = _27 (&node_instance, _28, _29);
  instance pointer: _29  Outer instance pointer: _29 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_25 = snmp_get_node_instance_from_oid (&vb.oid.id, _24, &node_instance);
  Function call may change dynamic type:memset (&node_instance, 0, 248);
  Function call may change dynamic type:err_62 = snmp_vb_enumerator_get_next (_20, &vb);
  Function call may change dynamic type:_25 = snmp_get_node_instance_from_oid (&vb.oid.id, _24, &node_instance);
  Function call may change dynamic type:memset (&node_instance, 0, 248);
  Function call may change dynamic type:err_62 = snmp_vb_enumerator_get_next (_20, &vb);
  Function call may change dynamic type:snmp_vb_enumerator_init (_20, _21, _22, _23);
  Function call may change dynamic type:err_47 = snmp_vb_enumerator_get_next (_2, &vb);
  Function call may change dynamic type:_4 = snmp_get_node_instance_from_oid (&vb.oid.id, _3, &node_instance);
  Function call may change dynamic type:memset (&node_instance, 0, 248);
  Function call may change dynamic type:_15 = _11 (&node_instance, _13, _14);
  Function call may change dynamic type:_17 (&node_instance);
  Function call may change dynamic type:_30 = _27 (&node_instance, _28, _29);
  Function call may change dynamic type:_32 (&node_instance);
Determining dynamic type for call: _32 (&node_instance);
  Starting walk at: _32 (&node_instance);
  instance pointer: &node_instance  Outer instance pointer: node_instance offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_30 = _27 (&node_instance, _28, _29);
  Function call may change dynamic type:_25 = snmp_get_node_instance_from_oid (&vb.oid.id, _24, &node_instance);
  Function call may change dynamic type:memset (&node_instance, 0, 248);
  Function call may change dynamic type:err_62 = snmp_vb_enumerator_get_next (_20, &vb);
  Function call may change dynamic type:_32 (&node_instance);
  Function call may change dynamic type:snmp_vb_enumerator_init (_20, _21, _22, _23);
  Function call may change dynamic type:err_47 = snmp_vb_enumerator_get_next (_2, &vb);
  Function call may change dynamic type:_4 = snmp_get_node_instance_from_oid (&vb.oid.id, _3, &node_instance);
  Function call may change dynamic type:_15 = _11 (&node_instance, _13, _14);
  Function call may change dynamic type:_17 (&node_instance);
Determining dynamic type for call: err_49 = snmp_vb_enumerator_get_next (_3, &vb);
  Starting walk at: err_49 = snmp_vb_enumerator_get_next (_3, &vb);
  instance pointer: _3  Outer instance pointer: request_41(D) offset: 416 (bits) vtbl reference: 
  Function call may change dynamic type:err_49 = snmp_vb_enumerator_get_next (_3, &vb);
  Function call may change dynamic type:snmp_process_varbind (request_41(D), &vb, 1);
Determining dynamic type for call: err_49 = snmp_vb_enumerator_get_next (_3, &vb);
  Starting walk at: err_49 = snmp_vb_enumerator_get_next (_3, &vb);
  instance pointer: &vb  Outer instance pointer: vb offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_49 = snmp_vb_enumerator_get_next (_3, &vb);
  Function call may change dynamic type:snmp_process_varbind (request_41(D), &vb, 1);
Determining dynamic type for call: snmp_process_varbind (request_41(D), &vb, 1);
  Starting walk at: snmp_process_varbind (request_41(D), &vb, 1);
  instance pointer: request_41(D)  Outer instance pointer: request_41(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_49 = snmp_vb_enumerator_get_next (_3, &vb);
  Function call may change dynamic type:err_49 = snmp_vb_enumerator_get_next (_3, &vb);
  Function call may change dynamic type:snmp_process_varbind (request_41(D), &vb, 1);
Determining dynamic type for call: snmp_process_varbind (request_41(D), &vb, 1);
  Starting walk at: snmp_process_varbind (request_41(D), &vb, 1);
  instance pointer: &vb  Outer instance pointer: vb offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_49 = snmp_vb_enumerator_get_next (_3, &vb);
  Function call may change dynamic type:err_49 = snmp_vb_enumerator_get_next (_3, &vb);
  Function call may change dynamic type:snmp_process_varbind (request_41(D), &vb, 1);
Determining dynamic type for call: snmp_vb_enumerator_init (&repetition_varbind_enumerator, _7, repetition_offset_31, _9);
  Starting walk at: snmp_vb_enumerator_init (&repetition_varbind_enumerator, _7, repetition_offset_31, _9);
  instance pointer: &repetition_varbind_enumerator  Outer instance pointer: repetition_varbind_enumerator offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_49 = snmp_vb_enumerator_get_next (_3, &vb);
  Function call may change dynamic type:snmp_process_varbind (request_41(D), &vb, 1);
  Function call may change dynamic type:err_59 = snmp_vb_enumerator_get_next (&repetition_varbind_enumerator, &vb);
  Function call may change dynamic type:snmp_process_varbind (request_41(D), &vb, 1);
  Function call may change dynamic type:snmp_vb_enumerator_init (&repetition_varbind_enumerator, _7, repetition_offset_31, _9);
Determining dynamic type for call: snmp_vb_enumerator_init (&repetition_varbind_enumerator, _7, repetition_offset_31, _9);
  Starting walk at: snmp_vb_enumerator_init (&repetition_varbind_enumerator, _7, repetition_offset_31, _9);
  instance pointer: _7  Outer instance pointer: _7 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_49 = snmp_vb_enumerator_get_next (_3, &vb);
  Function call may change dynamic type:snmp_process_varbind (request_41(D), &vb, 1);
  Function call may change dynamic type:err_59 = snmp_vb_enumerator_get_next (&repetition_varbind_enumerator, &vb);
  Function call may change dynamic type:snmp_process_varbind (request_41(D), &vb, 1);
  Function call may change dynamic type:snmp_vb_enumerator_init (&repetition_varbind_enumerator, _7, repetition_offset_31, _9);
Determining dynamic type for call: err_59 = snmp_vb_enumerator_get_next (&repetition_varbind_enumerator, &vb);
  Starting walk at: err_59 = snmp_vb_enumerator_get_next (&repetition_varbind_enumerator, &vb);
  instance pointer: &repetition_varbind_enumerator  Outer instance pointer: repetition_varbind_enumerator offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:snmp_process_varbind (request_41(D), &vb, 1);
  Function call may change dynamic type:err_59 = snmp_vb_enumerator_get_next (&repetition_varbind_enumerator, &vb);
  Function call may change dynamic type:snmp_vb_enumerator_init (&repetition_varbind_enumerator, _7, repetition_offset_31, _9);
  Function call may change dynamic type:err_49 = snmp_vb_enumerator_get_next (_3, &vb);
  Function call may change dynamic type:snmp_process_varbind (request_41(D), &vb, 1);
Determining dynamic type for call: err_59 = snmp_vb_enumerator_get_next (&repetition_varbind_enumerator, &vb);
  Starting walk at: err_59 = snmp_vb_enumerator_get_next (&repetition_varbind_enumerator, &vb);
  instance pointer: &vb  Outer instance pointer: vb offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:snmp_process_varbind (request_41(D), &vb, 1);
  Function call may change dynamic type:err_59 = snmp_vb_enumerator_get_next (&repetition_varbind_enumerator, &vb);
  Function call may change dynamic type:snmp_vb_enumerator_init (&repetition_varbind_enumerator, _7, repetition_offset_31, _9);
  Function call may change dynamic type:err_49 = snmp_vb_enumerator_get_next (_3, &vb);
  Function call may change dynamic type:snmp_process_varbind (request_41(D), &vb, 1);
Determining dynamic type for call: snmp_process_varbind (request_41(D), &vb, 1);
  Starting walk at: snmp_process_varbind (request_41(D), &vb, 1);
  instance pointer: request_41(D)  Outer instance pointer: request_41(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_59 = snmp_vb_enumerator_get_next (&repetition_varbind_enumerator, &vb);
  Function call may change dynamic type:snmp_process_varbind (request_41(D), &vb, 1);
  Function call may change dynamic type:err_59 = snmp_vb_enumerator_get_next (&repetition_varbind_enumerator, &vb);
  Function call may change dynamic type:snmp_vb_enumerator_init (&repetition_varbind_enumerator, _7, repetition_offset_31, _9);
  Function call may change dynamic type:err_49 = snmp_vb_enumerator_get_next (_3, &vb);
  Function call may change dynamic type:snmp_process_varbind (request_41(D), &vb, 1);
Determining dynamic type for call: snmp_process_varbind (request_41(D), &vb, 1);
  Starting walk at: snmp_process_varbind (request_41(D), &vb, 1);
  instance pointer: &vb  Outer instance pointer: vb offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_59 = snmp_vb_enumerator_get_next (&repetition_varbind_enumerator, &vb);
  Function call may change dynamic type:snmp_process_varbind (request_41(D), &vb, 1);
  Function call may change dynamic type:err_59 = snmp_vb_enumerator_get_next (&repetition_varbind_enumerator, &vb);
  Function call may change dynamic type:snmp_vb_enumerator_init (&repetition_varbind_enumerator, _7, repetition_offset_31, _9);
  Function call may change dynamic type:err_49 = snmp_vb_enumerator_get_next (_3, &vb);
  Function call may change dynamic type:snmp_process_varbind (request_41(D), &vb, 1);
Determining dynamic type for call: err_13 = snmp_vb_enumerator_get_next (_2, &vb);
  Starting walk at: err_13 = snmp_vb_enumerator_get_next (_2, &vb);
  instance pointer: _2  Outer instance pointer: request_9(D) offset: 416 (bits) vtbl reference: 
  Function call may change dynamic type:err_13 = snmp_vb_enumerator_get_next (_2, &vb);
  Function call may change dynamic type:snmp_process_varbind (request_9(D), &vb, 1);
Determining dynamic type for call: err_13 = snmp_vb_enumerator_get_next (_2, &vb);
  Starting walk at: err_13 = snmp_vb_enumerator_get_next (_2, &vb);
  instance pointer: &vb  Outer instance pointer: vb offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_13 = snmp_vb_enumerator_get_next (_2, &vb);
  Function call may change dynamic type:snmp_process_varbind (request_9(D), &vb, 1);
Determining dynamic type for call: snmp_process_varbind (request_9(D), &vb, 1);
  Starting walk at: snmp_process_varbind (request_9(D), &vb, 1);
  instance pointer: request_9(D)  Outer instance pointer: request_9(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_13 = snmp_vb_enumerator_get_next (_2, &vb);
  Function call may change dynamic type:err_13 = snmp_vb_enumerator_get_next (_2, &vb);
  Function call may change dynamic type:snmp_process_varbind (request_9(D), &vb, 1);
Determining dynamic type for call: snmp_process_varbind (request_9(D), &vb, 1);
  Starting walk at: snmp_process_varbind (request_9(D), &vb, 1);
  instance pointer: &vb  Outer instance pointer: vb offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_13 = snmp_vb_enumerator_get_next (_2, &vb);
  Function call may change dynamic type:err_13 = snmp_vb_enumerator_get_next (_2, &vb);
  Function call may change dynamic type:snmp_process_varbind (request_9(D), &vb, 1);
Determining dynamic type for call: err_13 = snmp_vb_enumerator_get_next (_2, &vb);
  Starting walk at: err_13 = snmp_vb_enumerator_get_next (_2, &vb);
  instance pointer: _2  Outer instance pointer: request_9(D) offset: 416 (bits) vtbl reference: 
  Function call may change dynamic type:err_13 = snmp_vb_enumerator_get_next (_2, &vb);
  Function call may change dynamic type:snmp_process_varbind (request_9(D), &vb, 0);
Determining dynamic type for call: err_13 = snmp_vb_enumerator_get_next (_2, &vb);
  Starting walk at: err_13 = snmp_vb_enumerator_get_next (_2, &vb);
  instance pointer: &vb  Outer instance pointer: vb offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_13 = snmp_vb_enumerator_get_next (_2, &vb);
  Function call may change dynamic type:snmp_process_varbind (request_9(D), &vb, 0);
Determining dynamic type for call: snmp_process_varbind (request_9(D), &vb, 0);
  Starting walk at: snmp_process_varbind (request_9(D), &vb, 0);
  instance pointer: request_9(D)  Outer instance pointer: request_9(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_13 = snmp_vb_enumerator_get_next (_2, &vb);
  Function call may change dynamic type:err_13 = snmp_vb_enumerator_get_next (_2, &vb);
  Function call may change dynamic type:snmp_process_varbind (request_9(D), &vb, 0);
Determining dynamic type for call: snmp_process_varbind (request_9(D), &vb, 0);
  Starting walk at: snmp_process_varbind (request_9(D), &vb, 0);
  instance pointer: &vb  Outer instance pointer: vb offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_13 = snmp_vb_enumerator_get_next (_2, &vb);
  Function call may change dynamic type:err_13 = snmp_vb_enumerator_get_next (_2, &vb);
  Function call may change dynamic type:snmp_process_varbind (request_9(D), &vb, 0);
Determining dynamic type for call: _11 = snmp_msg_getnext_validate_node_inst (&node_instance, request_39(D));
  Starting walk at: _11 = snmp_msg_getnext_validate_node_inst (&node_instance, request_39(D));
  instance pointer: &node_instance  Outer instance pointer: node_instance offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_9 = snmp_get_node_instance_from_oid (_7, _8, &node_instance);
  Function call may change dynamic type:memset (&node_instance, 0, 248);
Determining dynamic type for call: _11 = snmp_msg_getnext_validate_node_inst (&node_instance, request_39(D));
  Starting walk at: _11 = snmp_msg_getnext_validate_node_inst (&node_instance, request_39(D));
  instance pointer: request_39(D)  Outer instance pointer: request_39(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_9 = snmp_get_node_instance_from_oid (_7, _8, &node_instance);
Determining dynamic type for call: _13 (&node_instance);
  Starting walk at: _13 (&node_instance);
  instance pointer: &node_instance  Outer instance pointer: node_instance offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_9 = snmp_get_node_instance_from_oid (_7, _8, &node_instance);
  Function call may change dynamic type:memset (&node_instance, 0, 248);
Determining dynamic type for call: len_48 = _21 (&node_instance, _22);
  Starting walk at: len_48 = _21 (&node_instance, _22);
  instance pointer: &node_instance  Outer instance pointer: node_instance offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_3 = snmp_get_next_node_instance_from_oid (_1, _2, snmp_msg_getnext_validate_node_inst, request_39(D), &result_oid, &node_instance);
  Function call may change dynamic type:memset (&node_instance, 0, 248);
  Function call may change dynamic type:snmp_oid_assign (_5, &result_oid.id, _6);
  Function call may change dynamic type:_9 = snmp_get_node_instance_from_oid (_7, _8, &node_instance);
  Function call may change dynamic type:_13 (&node_instance);
Determining dynamic type for call: len_48 = _21 (&node_instance, _22);
  Starting walk at: len_48 = _21 (&node_instance, _22);
  instance pointer: _22  Outer instance pointer: _22 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_3 = snmp_get_next_node_instance_from_oid (_1, _2, snmp_msg_getnext_validate_node_inst, request_39(D), &result_oid, &node_instance);
  Function call may change dynamic type:memset (&node_instance, 0, 248);
  Function call may change dynamic type:snmp_oid_assign (_5, &result_oid.id, _6);
  Function call may change dynamic type:_9 = snmp_get_node_instance_from_oid (_7, _8, &node_instance);
  Function call may change dynamic type:_13 (&node_instance);
Determining dynamic type for call: err_53 = snmp_append_outbound_varbind (_27, vb_37(D));
  Starting walk at: err_53 = snmp_append_outbound_varbind (_27, vb_37(D));
  instance pointer: _27  Outer instance pointer: request_39(D) offset: 608 (bits) vtbl reference: 
  Function call may change dynamic type:len_48 = _21 (&node_instance, _22);
  Function call may change dynamic type:_3 = snmp_get_next_node_instance_from_oid (_1, _2, snmp_msg_getnext_validate_node_inst, request_39(D), &result_oid, &node_instance);
  Function call may change dynamic type:snmp_oid_assign (_5, &result_oid.id, _6);
  Function call may change dynamic type:_9 = snmp_get_node_instance_from_oid (_7, _8, &node_instance);
  Function call may change dynamic type:_13 (&node_instance);
Determining dynamic type for call: err_53 = snmp_append_outbound_varbind (_27, vb_37(D));
  Starting walk at: err_53 = snmp_append_outbound_varbind (_27, vb_37(D));
  instance pointer: vb_37(D)  Outer instance pointer: vb_37(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:len_48 = _21 (&node_instance, _22);
  Function call may change dynamic type:_3 = snmp_get_next_node_instance_from_oid (_1, _2, snmp_msg_getnext_validate_node_inst, request_39(D), &result_oid, &node_instance);
  Function call may change dynamic type:snmp_oid_assign (_5, &result_oid.id, _6);
  Function call may change dynamic type:_9 = snmp_get_node_instance_from_oid (_7, _8, &node_instance);
  Function call may change dynamic type:_13 (&node_instance);
Determining dynamic type for call: _28 (&node_instance);
  Starting walk at: _28 (&node_instance);
  instance pointer: &node_instance  Outer instance pointer: node_instance offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_53 = snmp_append_outbound_varbind (_27, vb_37(D));
  Function call may change dynamic type:len_48 = _21 (&node_instance, _22);
  Function call may change dynamic type:_3 = snmp_get_next_node_instance_from_oid (_1, _2, snmp_msg_getnext_validate_node_inst, request_39(D), &result_oid, &node_instance);
  Function call may change dynamic type:memset (&node_instance, 0, 248);
  Function call may change dynamic type:snmp_oid_assign (_5, &result_oid.id, _6);
  Function call may change dynamic type:_9 = snmp_get_node_instance_from_oid (_7, _8, &node_instance);
  Function call may change dynamic type:_13 (&node_instance);
Determining dynamic type for call: err_62 = snmp_append_outbound_varbind (_20, vb_37(D));
  Starting walk at: err_62 = snmp_append_outbound_varbind (_20, vb_37(D));
  instance pointer: _20  Outer instance pointer: request_39(D) offset: 608 (bits) vtbl reference: 
  Function call may change dynamic type:_3 = snmp_get_next_node_instance_from_oid (_1, _2, snmp_msg_getnext_validate_node_inst, request_39(D), &result_oid, &node_instance);
  Function call may change dynamic type:snmp_oid_assign (_5, &result_oid.id, _6);
  Function call may change dynamic type:_9 = snmp_get_node_instance_from_oid (_7, _8, &node_instance);
  Function call may change dynamic type:_13 (&node_instance);
Determining dynamic type for call: err_62 = snmp_append_outbound_varbind (_20, vb_37(D));
  Starting walk at: err_62 = snmp_append_outbound_varbind (_20, vb_37(D));
  instance pointer: vb_37(D)  Outer instance pointer: vb_37(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_3 = snmp_get_next_node_instance_from_oid (_1, _2, snmp_msg_getnext_validate_node_inst, request_39(D), &result_oid, &node_instance);
  Function call may change dynamic type:snmp_oid_assign (_5, &result_oid.id, _6);
  Function call may change dynamic type:_9 = snmp_get_node_instance_from_oid (_7, _8, &node_instance);
  Function call may change dynamic type:_13 (&node_instance);
Determining dynamic type for call: _2 = snmp_msg_getnext_validate_node_inst.part.0 (node_instance_6(D), validate_arg_7(D));
  Starting walk at: _2 = snmp_msg_getnext_validate_node_inst.part.0 (node_instance_6(D), validate_arg_7(D));
  instance pointer: node_instance_6(D)  Outer instance pointer: node_instance_6(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _2 = snmp_msg_getnext_validate_node_inst.part.0 (node_instance_6(D), validate_arg_7(D));
  Starting walk at: _2 = snmp_msg_getnext_validate_node_inst.part.0 (node_instance_6(D), validate_arg_7(D));
  instance pointer: validate_arg_7(D)  Outer instance pointer: validate_arg_7(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: err_29 = snmp_parse_inbound_frame (&request);
  Starting walk at: err_29 = snmp_parse_inbound_frame (&request);
  instance pointer: &request  Outer instance pointer: request offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:memset (&request, 0, 292);
Determining dynamic type for call: err_31 = snmp_prepare_outbound_frame (&request);
  Starting walk at: err_31 = snmp_prepare_outbound_frame (&request);
  instance pointer: &request  Outer instance pointer: request offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_29 = snmp_parse_inbound_frame (&request);
  Function call may change dynamic type:memset (&request, 0, 292);
Determining dynamic type for call: err_33 = snmp_process_set_request (&request);
  Starting walk at: err_33 = snmp_process_set_request (&request);
  instance pointer: &request  Outer instance pointer: request offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_31 = snmp_prepare_outbound_frame (&request);
  Function call may change dynamic type:err_29 = snmp_parse_inbound_frame (&request);
  Function call may change dynamic type:memset (&request, 0, 292);
Determining dynamic type for call: err_35 = snmp_process_getbulk_request (&request);
  Starting walk at: err_35 = snmp_process_getbulk_request (&request);
  instance pointer: &request  Outer instance pointer: request offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_31 = snmp_prepare_outbound_frame (&request);
  Function call may change dynamic type:err_29 = snmp_parse_inbound_frame (&request);
  Function call may change dynamic type:memset (&request, 0, 292);
Determining dynamic type for call: err_37 = snmp_process_getnext_request (&request);
  Starting walk at: err_37 = snmp_process_getnext_request (&request);
  instance pointer: &request  Outer instance pointer: request offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_31 = snmp_prepare_outbound_frame (&request);
  Function call may change dynamic type:err_29 = snmp_parse_inbound_frame (&request);
  Function call may change dynamic type:memset (&request, 0, 292);
Determining dynamic type for call: err_39 = snmp_process_get_request (&request);
  Starting walk at: err_39 = snmp_process_get_request (&request);
  instance pointer: &request  Outer instance pointer: request offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_31 = snmp_prepare_outbound_frame (&request);
  Function call may change dynamic type:err_29 = snmp_parse_inbound_frame (&request);
  Function call may change dynamic type:memset (&request, 0, 292);
Determining dynamic type for call: err_41 = snmp_complete_outbound_frame (&request);
  Starting walk at: err_41 = snmp_complete_outbound_frame (&request);
  instance pointer: &request  Outer instance pointer: request offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:err_31 = snmp_prepare_outbound_frame (&request);
  Function call may change dynamic type:err_29 = snmp_parse_inbound_frame (&request);
  Function call may change dynamic type:memset (&request, 0, 292);
  Function call may change dynamic type:err_39 = snmp_process_get_request (&request);
  Function call may change dynamic type:err_37 = snmp_process_getnext_request (&request);
  Function call may change dynamic type:err_35 = snmp_process_getbulk_request (&request);
  Function call may change dynamic type:err_33 = snmp_process_set_request (&request);
Determining dynamic type for call: snmp_execute_write_callbacks (&request);
  Starting walk at: snmp_execute_write_callbacks (&request);
  instance pointer: &request  Outer instance pointer: request offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:snmp_sendto (_5, _6, _7, _8);
  Function call may change dynamic type:err_41 = snmp_complete_outbound_frame (&request);
  Function call may change dynamic type:err_31 = snmp_prepare_outbound_frame (&request);
  Function call may change dynamic type:err_29 = snmp_parse_inbound_frame (&request);
  Function call may change dynamic type:memset (&request, 0, 292);
  Function call may change dynamic type:err_39 = snmp_process_get_request (&request);
  Function call may change dynamic type:err_37 = snmp_process_getnext_request (&request);
  Function call may change dynamic type:err_35 = snmp_process_getbulk_request (&request);
  Function call may change dynamic type:err_33 = snmp_process_set_request (&request);

IPA structures before propagation:

Jump functions:
  Jump functions of caller  snmp_vb_enumerator_get_next.part.0/63:
  Jump functions of caller  snmp_msg_getnext_validate_node_inst.part.0/62:
  Jump functions of caller  snmp_asn1_dec_u64t/61:
  Jump functions of caller  snmp_asn1_dec_u32t/60:
  Jump functions of caller  snmp_asn1_dec_oid/59:
  Jump functions of caller  snmp_asn1_enc_u64t/58:
  Jump functions of caller  snmp_asn1_enc_u32t/57:
  Jump functions of caller  snmp_asn1_enc_oid/56:
  Jump functions of caller  snmp_asn1_enc_u64t_cnt/55:
  Jump functions of caller  snmp_asn1_enc_u32t_cnt/54:
  Jump functions of caller  snmp_asn1_enc_length_cnt/53:
  Jump functions of caller  snmp_asn1_enc_oid_cnt/52:
  Jump functions of caller  pbuf_realloc/51:
  Jump functions of caller  snmp_pbuf_stream_seek_abs/50:
  Jump functions of caller  snmp_pbuf_stream_writeto/49:
  Jump functions of caller  snmp_get_node_instance_from_oid/48:
  Jump functions of caller  snmp_oid_assign/47:
  Jump functions of caller  snmp_get_next_node_instance_from_oid/46:
  Jump functions of caller  snmp_pbuf_stream_write/45:
  Jump functions of caller  snmp_asn1_enc_raw/44:
  Jump functions of caller  snmp_asn1_enc_s32t/43:
  Jump functions of caller  snmp_asn1_enc_s32t_cnt/42:
  Jump functions of caller  snmp_ans1_enc_tlv/41:
  Jump functions of caller  pbuf_alloc/40:
  Jump functions of caller  strncmp/39:
  Jump functions of caller  snmp_authfail_trap/38:
  Jump functions of caller  snmp_pbuf_stream_seek/37:
  Jump functions of caller  snmp_asn1_dec_raw/36:
  Jump functions of caller  snmp_asn1_dec_s32t/35:
  Jump functions of caller  snmp_asn1_dec_tlv/34:
  Jump functions of caller  snmp_pbuf_stream_init/33:
  Jump functions of caller  pbuf_free/32:
  Jump functions of caller  snmp_sendto/31:
  Jump functions of caller  memset/29:
  Jump functions of caller  strlen/28:
  Jump functions of caller  snmp_vb_enumerator_get_next/27:
    callsite  snmp_vb_enumerator_get_next/27 -> snmp_vb_enumerator_get_next.part.0/63 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  snmp_vb_enumerator_init/26:
  Jump functions of caller  snmp_execute_write_callbacks/25:
    callsite  snmp_execute_write_callbacks/25 -> snmp_vb_enumerator_get_next/27 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  snmp_execute_write_callbacks/25 -> snmp_vb_enumerator_init/26 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
    indirect simple callsite, calling param -1, offset 0, for stmt snmp_write_callback.14_4 (&vb.oid.id, _5, snmp_write_callback_arg.15_6);
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  snmp_complete_outbound_frame/24:
  Jump functions of caller  snmp_append_outbound_varbind/23:
    callsite  snmp_append_outbound_varbind/23 -> snmp_varbind_length/22 : 
       param 0: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  snmp_varbind_length/22:
  Jump functions of caller  snmp_prepare_outbound_frame/21:
  Jump functions of caller  snmp_parse_inbound_frame/20:
    callsite  snmp_parse_inbound_frame/20 -> snmp_vb_enumerator_init/26 : 
       param 0: ANCESTOR: 0, offset 416
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
  Jump functions of caller  snmp_process_set_request/19:
    callsite  snmp_process_set_request/19 -> snmp_vb_enumerator_get_next/27 : 
       param 0: ANCESTOR: 0, offset 416
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  snmp_process_set_request/19 -> snmp_vb_enumerator_init/26 : 
       param 0: ANCESTOR: 0, offset 416
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
    callsite  snmp_process_set_request/19 -> snmp_vb_enumerator_get_next/27 : 
       param 0: ANCESTOR: 0, offset 416
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    indirect simple callsite, calling param -1, offset 0, for stmt _32 (&node_instance);
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffff8
         VR  ~[0, 0]
    indirect simple callsite, calling param -1, offset 0, for stmt _30 = _27 (&node_instance, _28, _29);
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffff8
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    indirect simple callsite, calling param -1, offset 0, for stmt _17 (&node_instance);
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffff8
         VR  ~[0, 0]
    indirect simple callsite, calling param -1, offset 0, for stmt _15 = _11 (&node_instance, _13, _14);
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffff8
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  snmp_process_getbulk_request/18:
    callsite  snmp_process_getbulk_request/18 -> snmp_process_varbind/15 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
    callsite  snmp_process_getbulk_request/18 -> snmp_vb_enumerator_get_next/27 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: UNKNOWN
         Aggregate passed by reference:
           offset: 1728, cst: 0B
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  snmp_process_getbulk_request/18 -> snmp_vb_enumerator_init/26 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffff
         VR  [1, -1]
    callsite  snmp_process_getbulk_request/18 -> snmp_process_varbind/15 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
    callsite  snmp_process_getbulk_request/18 -> snmp_vb_enumerator_get_next/27 : 
       param 0: ANCESTOR: 0, offset 416
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  snmp_process_getnext_request/17:
    callsite  snmp_process_getnext_request/17 -> snmp_process_varbind/15 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
    callsite  snmp_process_getnext_request/17 -> snmp_vb_enumerator_get_next/27 : 
       param 0: ANCESTOR: 0, offset 416
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  snmp_process_get_request/16:
    callsite  snmp_process_get_request/16 -> snmp_process_varbind/15 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
    callsite  snmp_process_get_request/16 -> snmp_vb_enumerator_get_next/27 : 
       param 0: ANCESTOR: 0, offset 416
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  snmp_process_varbind/15:
    callsite  snmp_process_varbind/15 -> snmp_append_outbound_varbind/23 : 
       param 0: ANCESTOR: 0, offset 608
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  snmp_process_varbind/15 -> snmp_append_outbound_varbind/23 : 
       param 0: ANCESTOR: 0, offset 608
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: PASS THROUGH: 1, op nop_expr
         Aggregate passed by reference:
           offset: 1712, cst: 0
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  snmp_process_varbind/15 -> snmp_msg_getnext_validate_node_inst/14 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffff8
         VR  ~[0, 0]
       param 1: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    indirect simple callsite, calling param -1, offset 0, for stmt _28 (&node_instance);
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffff8
         VR  ~[0, 0]
    indirect simple callsite, calling param -1, offset 0, for stmt len_48 = _21 (&node_instance, _22);
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffff8
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    indirect simple callsite, calling param -1, offset 0, for stmt _13 (&node_instance);
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffff8
         VR  ~[0, 0]
  Jump functions of caller  snmp_msg_getnext_validate_node_inst/14:
    callsite  snmp_msg_getnext_validate_node_inst/14 -> snmp_msg_getnext_validate_node_inst.part.0/62 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  snmp_receive/13:
    callsite  snmp_receive/13 -> snmp_execute_write_callbacks/25 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  snmp_receive/13 -> snmp_complete_outbound_frame/24 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  snmp_receive/13 -> snmp_process_set_request/19 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  snmp_receive/13 -> snmp_process_getbulk_request/18 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  snmp_receive/13 -> snmp_process_getnext_request/17 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  snmp_receive/13 -> snmp_process_get_request/16 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  snmp_receive/13 -> snmp_prepare_outbound_frame/21 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
    callsite  snmp_receive/13 -> snmp_parse_inbound_frame/20 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xfffffffc
         VR  ~[0, 0]
  Jump functions of caller  snmp_set_write_callback/12:
  Jump functions of caller  snmp_set_community_trap/11:
  Jump functions of caller  snmp_set_community_write/10:
  Jump functions of caller  snmp_get_community_trap/9:
  Jump functions of caller  snmp_get_community_write/8:
  Jump functions of caller  snmp_set_community/7:
  Jump functions of caller  snmp_get_community/6:

 Propagating constants:

Not considering snmp_vb_enumerator_get_next for cloning; -fipa-cp-clone disabled.
Not considering snmp_vb_enumerator_init for cloning; -fipa-cp-clone disabled.
Not considering snmp_append_outbound_varbind for cloning; -fipa-cp-clone disabled.
Not considering snmp_varbind_length for cloning; -fipa-cp-clone disabled.
Not considering snmp_msg_getnext_validate_node_inst for cloning; -fipa-cp-clone disabled.
Not considering snmp_receive for cloning; -fipa-cp-clone disabled.
Not considering snmp_set_write_callback for cloning; -fipa-cp-clone disabled.
Not considering snmp_set_community_trap for cloning; -fipa-cp-clone disabled.
Not considering snmp_set_community_write for cloning; -fipa-cp-clone disabled.
Not considering snmp_get_community_trap for cloning; -fipa-cp-clone disabled.
Not considering snmp_get_community_write for cloning; -fipa-cp-clone disabled.
Not considering snmp_set_community for cloning; -fipa-cp-clone disabled.
Not considering snmp_get_community for cloning; -fipa-cp-clone disabled.

overall_size: 1796, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: snmp_vb_enumerator_get_next.part.0/63:
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
  Node: snmp_msg_getnext_validate_node_inst.part.0/62:
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
  Node: snmp_vb_enumerator_get_next/27:
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
  Node: snmp_vb_enumerator_init/26:
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
  Node: snmp_execute_write_callbacks/25:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct snmp_request * ~[0B, 0B]
        AGGS VARIABLE
  Node: snmp_complete_outbound_frame/24:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct snmp_request * ~[0B, 0B]
        AGGS VARIABLE
  Node: snmp_append_outbound_varbind/23:
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
  Node: snmp_varbind_length/22:
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
  Node: snmp_prepare_outbound_frame/21:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct snmp_request * ~[0B, 0B]
        AGGS VARIABLE
  Node: snmp_parse_inbound_frame/20:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct snmp_request * ~[0B, 0B]
        AGGS VARIABLE
  Node: snmp_process_set_request/19:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct snmp_request * ~[0B, 0B]
        AGGS VARIABLE
  Node: snmp_process_getbulk_request/18:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct snmp_request * ~[0B, 0B]
        AGGS VARIABLE
  Node: snmp_process_getnext_request/17:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct snmp_request * ~[0B, 0B]
        AGGS VARIABLE
  Node: snmp_process_get_request/16:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct snmp_request * ~[0B, 0B]
        AGGS VARIABLE
  Node: snmp_process_varbind/15:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct snmp_request * ~[0B, 0B]
        AGGS VARIABLE
    param [1]: VARIABLE
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0xfffffffc
         struct snmp_varbind * ~[0B, 0B]
        AGGS VARIABLE
    param [2]: 1 [loc_time: 3, loc_size: 86, prop_time: 0, prop_size: 0]
               0 [loc_time: 3, loc_size: 92, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x0, mask = 0x1
         u8_t [0, 1]
        AGGS VARIABLE
  Node: snmp_msg_getnext_validate_node_inst/14:
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
  Node: snmp_receive/13:
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
  Node: snmp_set_write_callback/12:
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
  Node: snmp_set_community_trap/11:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: snmp_set_community_write/10:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: snmp_get_community_trap/9:
  Node: snmp_get_community_write/8:
  Node: snmp_set_community/7:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: snmp_get_community/6:

IPA decision stage:

Propagated bits info for function snmp_execute_write_callbacks/25:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function snmp_complete_outbound_frame/24:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function snmp_prepare_outbound_frame/21:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function snmp_parse_inbound_frame/20:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function snmp_process_set_request/19:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function snmp_process_getbulk_request/18:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function snmp_process_getnext_request/17:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function snmp_process_get_request/16:
 param 0: value = 0x0, mask = 0xfffffffc
Propagated bits info for function snmp_process_varbind/15:
 param 0: value = 0x0, mask = 0xfffffffc
 param 1: value = 0x0, mask = 0xfffffffc
 param 2: value = 0x0, mask = 0x1

IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

snmp_vb_enumerator_get_next.part.0/63 (snmp_vb_enumerator_get_next.part.0) @06eff380
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: snmp_vb_enumerator_get_next/27 (524845000 (estimated locally),0.49 per call) 
  Calls: snmp_asn1_dec_tlv/34 (1073741824 (estimated locally),1.00 per call) snmp_asn1_dec_tlv/34 (349494539 (estimated locally),0.33 per call) snmp_asn1_dec_oid/59 (89049551 (estimated locally),0.08 per call) snmp_asn1_dec_tlv/34 (56964998 (estimated locally),0.05 per call) snmp_asn1_dec_s32t/35 (2341830 (estimated locally),0.00 per call) snmp_asn1_dec_u32t/60 (2341830 (estimated locally),0.00 per call) snmp_asn1_dec_raw/36 (2341830 (estimated locally),0.00 per call) snmp_asn1_dec_oid/59 (2341830 (estimated locally),0.00 per call) snmp_asn1_dec_raw/36 (1118692 (estimated locally),0.00 per call) snmp_asn1_dec_u64t/61 (2341830 (estimated locally),0.00 per call) snmp_pbuf_stream_seek/37 (3954763 (estimated locally),0.00 per call) 
snmp_msg_getnext_validate_node_inst.part.0/62 (snmp_msg_getnext_validate_node_inst.part.0) @06b9c8c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: snmp_msg_getnext_validate_node_inst/14 (751177284 (estimated locally),0.70 per call) 
  Calls: 
snmp_asn1_dec_u64t/61 (snmp_asn1_dec_u64t) @06ee3000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: snmp_vb_enumerator_get_next.part.0/63 (2341830 (estimated locally),0.00 per call) 
  Calls: 
snmp_asn1_dec_u32t/60 (snmp_asn1_dec_u32t) @06e9e000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: snmp_vb_enumerator_get_next.part.0/63 (2341830 (estimated locally),0.00 per call) 
  Calls: 
snmp_asn1_dec_oid/59 (snmp_asn1_dec_oid) @06e9eee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: snmp_vb_enumerator_get_next.part.0/63 (89049551 (estimated locally),0.08 per call) snmp_vb_enumerator_get_next.part.0/63 (2341830 (estimated locally),0.00 per call) 
  Calls: 
snmp_asn1_enc_u64t/58 (snmp_asn1_enc_u64t) @06e9ed20
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: snmp_append_outbound_varbind/23 (107374 (estimated locally),0.03 per call) 
  Calls: 
snmp_asn1_enc_u32t/57 (snmp_asn1_enc_u32t) @06e9ec40
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: snmp_append_outbound_varbind/23 (107374 (estimated locally),0.03 per call) 
  Calls: 
snmp_asn1_enc_oid/56 (snmp_asn1_enc_oid) @06e9eb60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: snmp_append_outbound_varbind/23 (107374 (estimated locally),0.03 per call) snmp_append_outbound_varbind/23 (1984413 (estimated locally),0.62 per call) 
  Calls: 
snmp_asn1_enc_u64t_cnt/55 (snmp_asn1_enc_u64t_cnt) @06e9e7e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: snmp_varbind_length/22 (36829959 (estimated locally),0.03 per call) 
  Calls: 
snmp_asn1_enc_u32t_cnt/54 (snmp_asn1_enc_u32t_cnt) @06e9e700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: snmp_varbind_length/22 (36829959 (estimated locally),0.03 per call) 
  Calls: 
snmp_asn1_enc_length_cnt/53 (snmp_asn1_enc_length_cnt) @06e9e620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: snmp_varbind_length/22 (991647301 (estimated locally),0.92 per call) snmp_varbind_length/22 (991647301 (estimated locally),0.92 per call) snmp_varbind_length/22 (1073661301 (estimated locally),1.00 per call) 
  Calls: 
snmp_asn1_enc_oid_cnt/52 (snmp_asn1_enc_oid_cnt) @06e9e540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: snmp_varbind_length/22 (37554898 (estimated locally),0.03 per call) snmp_varbind_length/22 (1073661301 (estimated locally),1.00 per call) 
  Calls: 
pbuf_realloc/51 (pbuf_realloc) @06e9e0e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: snmp_complete_outbound_frame/24 (499369211 (estimated locally),0.47 per call) 
  Calls: 
snmp_pbuf_stream_seek_abs/50 (snmp_pbuf_stream_seek_abs) @06e71e00
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: snmp_complete_outbound_frame/24 (520915957 (estimated locally),0.49 per call) snmp_complete_outbound_frame/24 (155362296 (estimated locally),0.14 per call) snmp_complete_outbound_frame/24 (305376225 (estimated locally),0.28 per call) snmp_complete_outbound_frame/24 (994655859 (estimated locally),0.93 per call) 
  Calls: 
snmp_pbuf_stream_writeto/49 (snmp_pbuf_stream_writeto) @06e71ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: snmp_complete_outbound_frame/24 (571173774 (estimated locally),0.53 per call) 
  Calls: 
snmp_get_node_instance_from_oid/48 (snmp_get_node_instance_from_oid) @06e71620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: snmp_process_set_request/19 (74087331 (estimated locally),0.92 per call) snmp_process_set_request/19 (341366148 (estimated locally),4.23 per call) snmp_process_varbind/15 (271627 (estimated locally),0.50 per call) 
  Calls: 
snmp_oid_assign/47 (snmp_oid_assign) @06e71540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: snmp_process_varbind/15 (89637 (estimated locally),0.17 per call) 
  Calls: 
snmp_get_next_node_instance_from_oid/46 (snmp_get_next_node_instance_from_oid) @06e71460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: snmp_process_varbind/15 (271627 (estimated locally),0.50 per call) 
  Calls: 
snmp_pbuf_stream_write/45 (snmp_pbuf_stream_write) @06e71000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: snmp_prepare_outbound_frame/21 (843387683 (estimated locally),0.79 per call) snmp_prepare_outbound_frame/21 (879778112 (estimated locally),0.82 per call) 
  Calls: 
snmp_asn1_enc_raw/44 (snmp_asn1_enc_raw) @06e34700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: snmp_append_outbound_varbind/23 (107374 (estimated locally),0.03 per call) snmp_append_outbound_varbind/23 (317251 (estimated locally),0.10 per call) snmp_prepare_outbound_frame/21 (977772684 (estimated locally),0.91 per call) 
  Calls: 
snmp_asn1_enc_s32t/43 (snmp_asn1_enc_s32t) @06e34380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: snmp_append_outbound_varbind/23 (107374 (estimated locally),0.03 per call) snmp_complete_outbound_frame/24 (75941090 (estimated locally),0.07 per call) snmp_complete_outbound_frame/24 (298993862 (estimated locally),0.28 per call) snmp_prepare_outbound_frame/21 (917738713 (estimated locally),0.85 per call) snmp_prepare_outbound_frame/21 (1019961548 (estimated locally),0.95 per call) 
  Calls: 
snmp_asn1_enc_s32t_cnt/42 (snmp_asn1_enc_s32t_cnt) @06e342a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: snmp_varbind_length/22 (36829959 (estimated locally),0.03 per call) snmp_complete_outbound_frame/24 (470794837 (estimated locally),0.44 per call) snmp_complete_outbound_frame/24 (318033978 (estimated locally),0.30 per call) snmp_prepare_outbound_frame/21 (937328887 (estimated locally),0.87 per call) snmp_prepare_outbound_frame/21 (1041733785 (estimated locally),0.97 per call) 
  Calls: 
snmp_ans1_enc_tlv/41 (snmp_ans1_enc_tlv) @06e341c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: snmp_append_outbound_varbind/23 (1942938 (estimated locally),0.61 per call) snmp_append_outbound_varbind/23 (2026772 (estimated locally),0.63 per call) snmp_append_outbound_varbind/23 (2070036 (estimated locally),0.65 per call) snmp_complete_outbound_frame/24 (510028813 (estimated locally),0.48 per call) snmp_complete_outbound_frame/24 (973867551 (estimated locally),0.91 per call) snmp_complete_outbound_frame/24 (1015887917 (estimated locally),0.95 per call) snmp_prepare_outbound_frame/21 (825760880 (estimated locally),0.77 per call) snmp_prepare_outbound_frame/21 (861390750 (estimated locally),0.80 per call) snmp_prepare_outbound_frame/21 (898557974 (estimated locally),0.84 per call) snmp_prepare_outbound_frame/21 (937328887 (estimated locally),0.87 per call) snmp_prepare_outbound_frame/21 (957337235 (estimated locally),0.89 per call) snmp_prepare_outbound_frame/21 (998644352 (estimated locally),0.93 per call) snmp_prepare_outbound_frame/21 (1041733785 (estimated locally),0.97 per call) snmp_prepare_outbound_frame/21 (1063970774 (estimated locally),0.99 per call) 
  Calls: 
pbuf_alloc/40 (pbuf_alloc) @06e34ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: snmp_prepare_outbound_frame/21 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
strncmp/39 (strncmp) @06e34b60
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: snmp_parse_inbound_frame/20 (436749988 (estimated locally),0.41 per call) snmp_parse_inbound_frame/20 (112496209 (estimated locally),0.10 per call) 
  Calls: 
snmp_authfail_trap/38 (snmp_authfail_trap) @06e34a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: snmp_parse_inbound_frame/20 (2271100 (estimated locally),0.00 per call) snmp_parse_inbound_frame/20 (584980 (estimated locally),0.00 per call) snmp_parse_inbound_frame/20 (3459048 (estimated locally),0.00 per call) 
  Calls: 
snmp_pbuf_stream_seek/37 (snmp_pbuf_stream_seek) @06e349a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: snmp_vb_enumerator_get_next.part.0/63 (3954763 (estimated locally),0.00 per call) snmp_parse_inbound_frame/20 (173741069 (estimated locally),0.16 per call) 
  Calls: 
snmp_asn1_dec_raw/36 (snmp_asn1_dec_raw) @06e348c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: snmp_vb_enumerator_get_next.part.0/63 (2341830 (estimated locally),0.00 per call) snmp_vb_enumerator_get_next.part.0/63 (1118692 (estimated locally),0.00 per call) snmp_parse_inbound_frame/20 (858404492 (estimated locally),0.80 per call) 
  Calls: 
snmp_asn1_dec_s32t/35 (snmp_asn1_dec_s32t) @06e347e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: snmp_vb_enumerator_get_next.part.0/63 (2341830 (estimated locally),0.00 per call) snmp_parse_inbound_frame/20 (370642981 (estimated locally),0.35 per call) snmp_parse_inbound_frame/20 (190937293 (estimated locally),0.18 per call) snmp_parse_inbound_frame/20 (391727072 (estimated locally),0.36 per call) snmp_parse_inbound_frame/20 (201798795 (estimated locally),0.19 per call) snmp_parse_inbound_frame/20 (629663930 (estimated locally),0.59 per call) snmp_parse_inbound_frame/20 (935562282 (estimated locally),0.87 per call) 
  Calls: 
snmp_asn1_dec_tlv/34 (snmp_asn1_dec_tlv) @06e34620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: snmp_vb_enumerator_get_next.part.0/63 (1073741824 (estimated locally),1.00 per call) snmp_vb_enumerator_get_next.part.0/63 (349494539 (estimated locally),0.33 per call) snmp_vb_enumerator_get_next.part.0/63 (56964998 (estimated locally),0.05 per call) snmp_parse_inbound_frame/20 (551925242 (estimated locally),0.51 per call) snmp_parse_inbound_frame/20 (583321605 (estimated locally),0.54 per call) snmp_parse_inbound_frame/20 (616503954 (estimated locally),0.57 per call) snmp_parse_inbound_frame/20 (658886327 (estimated locally),0.61 per call) snmp_parse_inbound_frame/20 (851283992 (estimated locally),0.79 per call) snmp_parse_inbound_frame/20 (898242628 (estimated locally),0.84 per call) snmp_parse_inbound_frame/20 (978981274 (estimated locally),0.91 per call) snmp_parse_inbound_frame/20 (1051300621 (estimated locally),0.98 per call) 
  Calls: 
snmp_pbuf_stream_init/33 (snmp_pbuf_stream_init) @06e34540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: snmp_parse_inbound_frame/20 (1073741824 (estimated locally),1.00 per call) snmp_vb_enumerator_init/26 (1073741824 (estimated locally),1.00 per call) snmp_complete_outbound_frame/24 (1037573197 (estimated locally),0.97 per call) snmp_complete_outbound_frame/24 (583366126 (estimated locally),0.54 per call) snmp_complete_outbound_frame/24 (595818738 (estimated locally),0.55 per call) snmp_prepare_outbound_frame/21 (1063970774 (estimated locally),0.99 per call) 
  Calls: 
pbuf_free/32 (pbuf_free) @06e340e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: snmp_receive/13 (189462819 (estimated locally),0.18 per call) 
  Calls: 
snmp_sendto/31 (snmp_sendto) @06e34000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: snmp_receive/13 (19293530 (estimated locally),0.02 per call) 
  Calls: 
snmp_stats/30 (snmp_stats) @06e2dc60
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: snmp_parse_inbound_frame/20 (read)snmp_parse_inbound_frame/20 (write)snmp_parse_inbound_frame/20 (read)snmp_parse_inbound_frame/20 (write)snmp_parse_inbound_frame/20 (read)snmp_parse_inbound_frame/20 (write)snmp_parse_inbound_frame/20 (read)snmp_parse_inbound_frame/20 (write)snmp_parse_inbound_frame/20 (read)snmp_parse_inbound_frame/20 (write)snmp_parse_inbound_frame/20 (read)snmp_parse_inbound_frame/20 (write)snmp_parse_inbound_frame/20 (read)snmp_parse_inbound_frame/20 (write)snmp_parse_inbound_frame/20 (read)snmp_parse_inbound_frame/20 (write)snmp_parse_inbound_frame/20 (read)snmp_parse_inbound_frame/20 (write)snmp_parse_inbound_frame/20 (read)snmp_parse_inbound_frame/20 (write)snmp_parse_inbound_frame/20 (read)snmp_parse_inbound_frame/20 (write)snmp_parse_inbound_frame/20 (read)snmp_parse_inbound_frame/20 (write)snmp_parse_inbound_frame/20 (read)snmp_parse_inbound_frame/20 (write)snmp_parse_inbound_frame/20 (read)snmp_parse_inbound_frame/20 (write)snmp_parse_inbound_frame/20 (read)snmp_parse_inbound_frame/20 (write)snmp_vb_enumerator_get_next.part.0/63 (read)snmp_vb_enumerator_get_next.part.0/63 (write)snmp_complete_outbound_frame/24 (read)snmp_complete_outbound_frame/24 (write)snmp_complete_outbound_frame/24 (read)snmp_complete_outbound_frame/24 (write)snmp_complete_outbound_frame/24 (read)snmp_complete_outbound_frame/24 (write)snmp_complete_outbound_frame/24 (read)snmp_complete_outbound_frame/24 (write)snmp_complete_outbound_frame/24 (read)snmp_complete_outbound_frame/24 (write)snmp_complete_outbound_frame/24 (read)snmp_complete_outbound_frame/24 (write)snmp_complete_outbound_frame/24 (read)snmp_complete_outbound_frame/24 (write)snmp_complete_outbound_frame/24 (read)snmp_complete_outbound_frame/24 (write)snmp_parse_inbound_frame/20 (read)snmp_parse_inbound_frame/20 (write)snmp_parse_inbound_frame/20 (read)snmp_parse_inbound_frame/20 (write)snmp_parse_inbound_frame/20 (read)snmp_parse_inbound_frame/20 (write)snmp_parse_inbound_frame/20 (read)snmp_parse_inbound_frame/20 (write)snmp_parse_inbound_frame/20 (read)snmp_parse_inbound_frame/20 (write)snmp_parse_inbound_frame/20 (read)snmp_parse_inbound_frame/20 (write)snmp_parse_inbound_frame/20 (read)snmp_parse_inbound_frame/20 (write)snmp_parse_inbound_frame/20 (read)snmp_parse_inbound_frame/20 (write)snmp_parse_inbound_frame/20 (read)snmp_parse_inbound_frame/20 (write)snmp_parse_inbound_frame/20 (read)snmp_parse_inbound_frame/20 (write)snmp_parse_inbound_frame/20 (read)snmp_parse_inbound_frame/20 (write)snmp_parse_inbound_frame/20 (read)snmp_parse_inbound_frame/20 (write)snmp_parse_inbound_frame/20 (read)snmp_parse_inbound_frame/20 (write)snmp_parse_inbound_frame/20 (read)snmp_parse_inbound_frame/20 (write)snmp_parse_inbound_frame/20 (read)snmp_parse_inbound_frame/20 (write)snmp_parse_inbound_frame/20 (read)snmp_parse_inbound_frame/20 (write)snmp_parse_inbound_frame/20 (read)snmp_parse_inbound_frame/20 (write)snmp_parse_inbound_frame/20 (read)snmp_parse_inbound_frame/20 (write)snmp_parse_inbound_frame/20 (read)snmp_parse_inbound_frame/20 (write)snmp_parse_inbound_frame/20 (read)snmp_parse_inbound_frame/20 (write)snmp_parse_inbound_frame/20 (read)snmp_parse_inbound_frame/20 (write)snmp_parse_inbound_frame/20 (read)snmp_parse_inbound_frame/20 (write)snmp_parse_inbound_frame/20 (read)snmp_parse_inbound_frame/20 (write)snmp_vb_enumerator_get_next.part.0/63 (read)snmp_vb_enumerator_get_next.part.0/63 (write)snmp_vb_enumerator_get_next.part.0/63 (read)snmp_vb_enumerator_get_next.part.0/63 (write)snmp_vb_enumerator_get_next.part.0/63 (read)snmp_vb_enumerator_get_next.part.0/63 (write)snmp_vb_enumerator_get_next.part.0/63 (read)snmp_vb_enumerator_get_next.part.0/63 (write)snmp_vb_enumerator_get_next.part.0/63 (read)snmp_vb_enumerator_get_next.part.0/63 (write)snmp_vb_enumerator_get_next.part.0/63 (read)snmp_vb_enumerator_get_next.part.0/63 (write)snmp_vb_enumerator_get_next.part.0/63 (read)snmp_vb_enumerator_get_next.part.0/63 (write)snmp_vb_enumerator_get_next.part.0/63 (read)snmp_vb_enumerator_get_next.part.0/63 (write)snmp_vb_enumerator_get_next.part.0/63 (read)snmp_vb_enumerator_get_next.part.0/63 (write)snmp_vb_enumerator_get_next.part.0/63 (read)snmp_vb_enumerator_get_next.part.0/63 (write)snmp_vb_enumerator_get_next.part.0/63 (read)snmp_vb_enumerator_get_next.part.0/63 (write)snmp_vb_enumerator_get_next.part.0/63 (read)snmp_vb_enumerator_get_next.part.0/63 (write)snmp_vb_enumerator_get_next.part.0/63 (read)snmp_vb_enumerator_get_next.part.0/63 (write)snmp_vb_enumerator_get_next.part.0/63 (read)snmp_vb_enumerator_get_next.part.0/63 (write)snmp_receive/13 (read)snmp_receive/13 (write)
  Availability: not_available
  Varpool flags:
memset/29 (memset) @06e02ee0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: snmp_receive/13 (1073741823 (estimated locally),1.00 per call) snmp_process_set_request/19 (74087331 (estimated locally),0.92 per call) snmp_process_set_request/19 (341366148 (estimated locally),4.23 per call) snmp_process_varbind/15 (543253 (estimated locally),1.00 per call) 
  Calls: 
strlen/28 (strlen) @06e027e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: snmp_set_community_trap/11 (214748 (estimated locally),1.00 per call) snmp_set_community_write/10 (214748 (estimated locally),0.70 per call) snmp_set_community/7 (214748 (estimated locally),1.00 per call) 
  Calls: 
snmp_vb_enumerator_get_next/27 (snmp_vb_enumerator_get_next) @06e022a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: snmp_execute_write_callbacks/25 (1073741824 (estimated locally),9.09 per call) snmp_process_set_request/19 (224507064 (estimated locally),2.78 per call) snmp_process_set_request/19 (1034442875 (estimated locally),12.80 per call) snmp_process_getbulk_request/18 (1014686025 (estimated locally),76.80 per call) snmp_process_getbulk_request/18 (129750444 (estimated locally),9.82 per call) snmp_process_getnext_request/17 (1034442874 (estimated locally),13.53 per call) snmp_process_get_request/16 (1034442874 (estimated locally),13.53 per call) 
  Calls: snmp_vb_enumerator_get_next.part.0/63 (524845000 (estimated locally),0.49 per call) 
snmp_vb_enumerator_init/26 (snmp_vb_enumerator_init) @06dc28c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: snmp_execute_write_callbacks/25 (118111600 (estimated locally),1.00 per call) snmp_process_set_request/19 (21339634 (estimated locally),0.26 per call) snmp_process_getbulk_request/18 (96446982 (estimated locally),7.30 per call) snmp_parse_inbound_frame/20 (524074548 (estimated locally),0.49 per call) 
  Calls: snmp_pbuf_stream_init/33 (1073741824 (estimated locally),1.00 per call) 
snmp_execute_write_callbacks/25 (snmp_execute_write_callbacks) @06dc2620
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: snmp_write_callback/4 (read)snmp_write_callback_arg/5 (read)
  Referring: 
  Availability: local
  Function flags: count:118111600 (estimated locally) body local optimize_size
  Called by: snmp_receive/13 (1753763 (estimated locally),0.00 per call) 
  Calls: snmp_vb_enumerator_get_next/27 (1073741824 (estimated locally),9.09 per call) snmp_vb_enumerator_init/26 (118111600 (estimated locally),1.00 per call) 
   Indirect call(955630223 (estimated locally),8.09 per call) 
snmp_complete_outbound_frame/24 (snmp_complete_outbound_frame) @06dc2380
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: snmp_receive/13 (58465242 (estimated locally),0.05 per call) 
  Calls: pbuf_realloc/51 (499369211 (estimated locally),0.47 per call) snmp_ans1_enc_tlv/41 (510028813 (estimated locally),0.48 per call) snmp_pbuf_stream_seek_abs/50 (520915957 (estimated locally),0.49 per call) snmp_asn1_enc_s32t/43 (75941090 (estimated locally),0.07 per call) snmp_pbuf_stream_seek_abs/50 (155362296 (estimated locally),0.14 per call) snmp_asn1_enc_s32t_cnt/42 (470794837 (estimated locally),0.44 per call) snmp_asn1_enc_s32t/43 (298993862 (estimated locally),0.28 per call) snmp_pbuf_stream_seek_abs/50 (305376225 (estimated locally),0.28 per call) snmp_asn1_enc_s32t_cnt/42 (318033978 (estimated locally),0.30 per call) snmp_ans1_enc_tlv/41 (973867551 (estimated locally),0.91 per call) snmp_pbuf_stream_seek_abs/50 (994655859 (estimated locally),0.93 per call) snmp_ans1_enc_tlv/41 (1015887917 (estimated locally),0.95 per call) snmp_pbuf_stream_init/33 (1037573197 (estimated locally),0.97 per call) snmp_pbuf_stream_writeto/49 (571173774 (estimated locally),0.53 per call) snmp_pbuf_stream_init/33 (583366126 (estimated locally),0.54 per call) snmp_pbuf_stream_init/33 (595818738 (estimated locally),0.55 per call) 
snmp_append_outbound_varbind/23 (snmp_append_outbound_varbind) @06db0700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:3203369 (estimated locally) body optimize_size
  Called by: snmp_process_varbind/15 (52886 (estimated locally),0.10 per call) snmp_process_varbind/15 (64319 (estimated locally),0.12 per call) 
  Calls: snmp_asn1_enc_u64t/58 (107374 (estimated locally),0.03 per call) snmp_asn1_enc_oid/56 (107374 (estimated locally),0.03 per call) snmp_asn1_enc_raw/44 (107374 (estimated locally),0.03 per call) snmp_asn1_enc_u32t/57 (107374 (estimated locally),0.03 per call) snmp_asn1_enc_s32t/43 (107374 (estimated locally),0.03 per call) snmp_asn1_enc_raw/44 (317251 (estimated locally),0.10 per call) snmp_ans1_enc_tlv/41 (1942938 (estimated locally),0.61 per call) snmp_asn1_enc_oid/56 (1984413 (estimated locally),0.62 per call) snmp_ans1_enc_tlv/41 (2026772 (estimated locally),0.63 per call) snmp_ans1_enc_tlv/41 (2070036 (estimated locally),0.65 per call) snmp_varbind_length/22 (3203369 (estimated locally),1.00 per call) 
snmp_varbind_length/22 (snmp_varbind_length) @06d698c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073661301 (estimated locally) body optimize_size
  Called by: snmp_append_outbound_varbind/23 (3203369 (estimated locally),1.00 per call) 
  Calls: snmp_asn1_enc_length_cnt/53 (991647301 (estimated locally),0.92 per call) snmp_asn1_enc_length_cnt/53 (991647301 (estimated locally),0.92 per call) snmp_asn1_enc_u64t_cnt/55 (36829959 (estimated locally),0.03 per call) snmp_asn1_enc_oid_cnt/52 (37554898 (estimated locally),0.03 per call) snmp_asn1_enc_u32t_cnt/54 (36829959 (estimated locally),0.03 per call) snmp_asn1_enc_s32t_cnt/42 (36829959 (estimated locally),0.03 per call) snmp_asn1_enc_length_cnt/53 (1073661301 (estimated locally),1.00 per call) snmp_asn1_enc_oid_cnt/52 (1073661301 (estimated locally),1.00 per call) 
snmp_prepare_outbound_frame/21 (snmp_prepare_outbound_frame) @06d69d20
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: snmp_receive/13 (354334802 (estimated locally),0.33 per call) 
  Calls: snmp_ans1_enc_tlv/41 (825760880 (estimated locally),0.77 per call) snmp_pbuf_stream_write/45 (843387683 (estimated locally),0.79 per call) snmp_ans1_enc_tlv/41 (861390750 (estimated locally),0.80 per call) snmp_pbuf_stream_write/45 (879778112 (estimated locally),0.82 per call) snmp_ans1_enc_tlv/41 (898557974 (estimated locally),0.84 per call) snmp_asn1_enc_s32t/43 (917738713 (estimated locally),0.85 per call) snmp_ans1_enc_tlv/41 (937328887 (estimated locally),0.87 per call) snmp_asn1_enc_s32t_cnt/42 (937328887 (estimated locally),0.87 per call) snmp_ans1_enc_tlv/41 (957337235 (estimated locally),0.89 per call) snmp_asn1_enc_raw/44 (977772684 (estimated locally),0.91 per call) snmp_ans1_enc_tlv/41 (998644352 (estimated locally),0.93 per call) snmp_asn1_enc_s32t/43 (1019961548 (estimated locally),0.95 per call) snmp_ans1_enc_tlv/41 (1041733785 (estimated locally),0.97 per call) snmp_asn1_enc_s32t_cnt/42 (1041733785 (estimated locally),0.97 per call) snmp_ans1_enc_tlv/41 (1063970774 (estimated locally),0.99 per call) snmp_pbuf_stream_init/33 (1063970774 (estimated locally),0.99 per call) pbuf_alloc/40 (1073741824 (estimated locally),1.00 per call) 
snmp_parse_inbound_frame/20 (snmp_parse_inbound_frame) @06d697e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)snmp_community_write/2 (read)snmp_stats/30 (read)snmp_stats/30 (write)snmp_community/1 (read)snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)snmp_stats/30 (read)snmp_stats/30 (write)
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: snmp_receive/13 (1073741823 (estimated locally),1.00 per call) 
  Calls: snmp_vb_enumerator_init/26 (524074548 (estimated locally),0.49 per call) snmp_asn1_dec_tlv/34 (551925242 (estimated locally),0.51 per call) snmp_asn1_dec_s32t/35 (370642981 (estimated locally),0.35 per call) snmp_asn1_dec_s32t/35 (190937293 (estimated locally),0.18 per call) snmp_asn1_dec_tlv/34 (583321605 (estimated locally),0.54 per call) snmp_asn1_dec_s32t/35 (391727072 (estimated locally),0.36 per call) snmp_asn1_dec_s32t/35 (201798795 (estimated locally),0.19 per call) snmp_asn1_dec_tlv/34 (616503954 (estimated locally),0.57 per call) snmp_asn1_dec_s32t/35 (629663930 (estimated locally),0.59 per call) snmp_asn1_dec_tlv/34 (658886327 (estimated locally),0.61 per call) snmp_authfail_trap/38 (2271100 (estimated locally),0.00 per call) strncmp/39 (436749988 (estimated locally),0.41 per call) snmp_authfail_trap/38 (584980 (estimated locally),0.00 per call) strncmp/39 (112496209 (estimated locally),0.10 per call) snmp_authfail_trap/38 (3459048 (estimated locally),0.00 per call) snmp_asn1_dec_tlv/34 (851283992 (estimated locally),0.79 per call) snmp_pbuf_stream_seek/37 (173741069 (estimated locally),0.16 per call) snmp_asn1_dec_raw/36 (858404492 (estimated locally),0.80 per call) snmp_asn1_dec_tlv/34 (898242628 (estimated locally),0.84 per call) snmp_asn1_dec_s32t/35 (935562282 (estimated locally),0.87 per call) snmp_asn1_dec_tlv/34 (978981274 (estimated locally),0.91 per call) snmp_asn1_dec_tlv/34 (1051300621 (estimated locally),0.98 per call) snmp_pbuf_stream_init/33 (1073741824 (estimated locally),1.00 per call) 
snmp_process_set_request/19 (snmp_process_set_request) @06d552a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:80794764 (estimated locally) body local optimize_size
  Called by: snmp_receive/13 (7642042 (estimated locally),0.01 per call) 
  Calls: snmp_get_node_instance_from_oid/48 (74087331 (estimated locally),0.92 per call) memset/29 (74087331 (estimated locally),0.92 per call) snmp_vb_enumerator_get_next/27 (224507064 (estimated locally),2.78 per call) snmp_vb_enumerator_init/26 (21339634 (estimated locally),0.26 per call) snmp_get_node_instance_from_oid/48 (341366148 (estimated locally),4.23 per call) memset/29 (341366148 (estimated locally),4.23 per call) snmp_vb_enumerator_get_next/27 (1034442875 (estimated locally),12.80 per call) 
   Indirect call(25930566 (estimated locally),0.32 per call) 
   Indirect call(37043666 (estimated locally),0.46 per call) 
   Indirect call(119478152 (estimated locally),1.48 per call) 
   Indirect call(14217900 (estimated locally),0.18 per call) 
snmp_process_getbulk_request/18 (snmp_process_getbulk_request) @06d55000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:13211584 (estimated locally) body local optimize_size
  Called by: snmp_receive/13 (9581296 (estimated locally),0.01 per call) 
  Calls: snmp_process_varbind/15 (334846388 (estimated locally),25.34 per call) snmp_vb_enumerator_get_next/27 (1014686025 (estimated locally),76.80 per call) snmp_vb_enumerator_init/26 (96446982 (estimated locally),7.30 per call) snmp_process_varbind/15 (12418484 (estimated locally),0.94 per call) snmp_vb_enumerator_get_next/27 (129750444 (estimated locally),9.82 per call) 
snmp_process_getnext_request/17 (snmp_process_getnext_request) @06d3bc40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:76466712 (estimated locally) body local optimize_size
  Called by: snmp_receive/13 (12012658 (estimated locally),0.01 per call) 
  Calls: snmp_process_varbind/15 (104685619 (estimated locally),1.37 per call) snmp_vb_enumerator_get_next/27 (1034442874 (estimated locally),13.53 per call) 
snmp_process_get_request/16 (snmp_process_get_request) @06d3be00
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:76466712 (estimated locally) body local optimize_size
  Called by: snmp_receive/13 (29232621 (estimated locally),0.03 per call) 
  Calls: snmp_process_varbind/15 (104685619 (estimated locally),1.37 per call) snmp_vb_enumerator_get_next/27 (1034442874 (estimated locally),13.53 per call) 
snmp_process_varbind/15 (snmp_process_varbind) @06d3bb60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: snmp_msg_getnext_validate_node_inst/14 (addr)
  Referring: 
  Availability: local
  Function flags: count:543253 (estimated locally) body local optimize_size
  Called by: snmp_process_getbulk_request/18 (334846388 (estimated locally),25.34 per call) snmp_process_getbulk_request/18 (12418484 (estimated locally),0.94 per call) snmp_process_getnext_request/17 (104685619 (estimated locally),1.37 per call) snmp_process_get_request/16 (104685619 (estimated locally),1.37 per call) 
  Calls: snmp_append_outbound_varbind/23 (52886 (estimated locally),0.10 per call) snmp_append_outbound_varbind/23 (64319 (estimated locally),0.12 per call) snmp_msg_getnext_validate_node_inst/14 (135813 (estimated locally),0.25 per call) snmp_get_node_instance_from_oid/48 (271627 (estimated locally),0.50 per call) snmp_oid_assign/47 (89637 (estimated locally),0.17 per call) snmp_get_next_node_instance_from_oid/46 (271627 (estimated locally),0.50 per call) memset/29 (543253 (estimated locally),1.00 per call) 
   Indirect call(114977 (estimated locally),0.21 per call) 
   Indirect call(271627 (estimated locally),0.50 per call) 
   Indirect call(47535 (estimated locally),0.09 per call) 
snmp_msg_getnext_validate_node_inst/14 (snmp_msg_getnext_validate_node_inst) @06d3b7e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  Address is taken.
  References: 
  Referring: snmp_process_varbind/15 (addr)
  Availability: available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: snmp_process_varbind/15 (135813 (estimated locally),0.25 per call) 
  Calls: snmp_msg_getnext_validate_node_inst.part.0/62 (751177284 (estimated locally),0.70 per call) 
snmp_receive/13 (snmp_receive) @06d3b540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: snmp_stats/30 (read)snmp_stats/30 (write)snmp_write_callback/4 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: 
  Calls: pbuf_free/32 (189462819 (estimated locally),0.18 per call) snmp_execute_write_callbacks/25 (1753763 (estimated locally),0.00 per call) snmp_sendto/31 (19293530 (estimated locally),0.02 per call) snmp_complete_outbound_frame/24 (58465242 (estimated locally),0.05 per call) snmp_process_set_request/19 (7642042 (estimated locally),0.01 per call) snmp_process_getbulk_request/18 (9581296 (estimated locally),0.01 per call) snmp_process_getnext_request/17 (12012658 (estimated locally),0.01 per call) snmp_process_get_request/16 (29232621 (estimated locally),0.03 per call) snmp_prepare_outbound_frame/21 (354334802 (estimated locally),0.33 per call) snmp_parse_inbound_frame/20 (1073741823 (estimated locally),1.00 per call) memset/29 (1073741823 (estimated locally),1.00 per call) 
snmp_set_write_callback/12 (snmp_set_write_callback) @06d321c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: snmp_write_callback/4 (write)snmp_write_callback_arg/5 (write)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
snmp_set_community_trap/11 (snmp_set_community_trap) @06d32d20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: snmp_community_trap/3 (write)
  Referring: 
  Availability: available
  Function flags: count:214748 (estimated locally) body optimize_size
  Called by: 
  Calls: strlen/28 (214748 (estimated locally),1.00 per call) 
snmp_set_community_write/10 (snmp_set_community_write) @06d329a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: snmp_community_write/2 (write)
  Referring: 
  Availability: available
  Function flags: count:306783 (estimated locally) body optimize_size
  Called by: 
  Calls: strlen/28 (214748 (estimated locally),0.70 per call) 
snmp_get_community_trap/9 (snmp_get_community_trap) @06d32620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: snmp_community_trap/3 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
snmp_get_community_write/8 (snmp_get_community_write) @06d32380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: snmp_community_write/2 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
snmp_set_community/7 (snmp_set_community) @06d320e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: snmp_community/1 (write)
  Referring: 
  Availability: available
  Function flags: count:214748 (estimated locally) body optimize_size
  Called by: 
  Calls: strlen/28 (214748 (estimated locally),1.00 per call) 
snmp_get_community/6 (snmp_get_community) @06d2bee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: snmp_community/1 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
snmp_write_callback_arg/5 (snmp_write_callback_arg) @06d2f948
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: snmp_set_write_callback/12 (write)snmp_execute_write_callbacks/25 (read)
  Availability: available
  Varpool flags: initialized
snmp_write_callback/4 (snmp_write_callback) @06d2f8b8
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: snmp_execute_write_callbacks/25 (read)snmp_set_write_callback/12 (write)snmp_receive/13 (read)
  Availability: available
  Varpool flags: initialized
snmp_community_trap/3 (snmp_community_trap) @06d2f828
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: snmp_get_community_trap/9 (read)snmp_set_community_trap/11 (write)
  Availability: available
  Varpool flags: initialized
snmp_community_write/2 (snmp_community_write) @06d2f798
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: snmp_get_community_write/8 (read)snmp_set_community_write/10 (write)snmp_parse_inbound_frame/20 (read)
  Availability: available
  Varpool flags: initialized
snmp_community/1 (snmp_community) @06d2f750
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: snmp_get_community/6 (read)snmp_set_community/7 (write)snmp_parse_inbound_frame/20 (read)
  Availability: available
  Varpool flags: initialized

;; Function snmp_msg_getnext_validate_node_inst (snmp_msg_getnext_validate_node_inst, funcdef_no=9, decl_uid=7272, cgraph_uid=10, symbol_order=14)

Modification phase of node snmp_msg_getnext_validate_node_inst/14
snmp_msg_getnext_validate_node_inst (struct snmp_node_instance * node_instance, void * validate_arg)
{
  <unnamed type> _1;
  unsigned char _2;
  s16_t (*<T64c>) (struct snmp_node_instance *, void *) _3;
  u8_t _4;
  <unnamed type> _8;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  _1 = node_instance_6(D)->access;
  _8 = _1 & 1;
  if (_8 == 0)
    goto <bb 5>; [21.72%]
  else
    goto <bb 3>; [78.28%]

  <bb 3> [local count: 840525099]:
  _3 = node_instance_6(D)->get_value;
  if (_3 == 0B)
    goto <bb 5>; [10.63%]
  else
    goto <bb 4>; [89.37%]

  <bb 4> [local count: 751177284]:
  _2 = snmp_msg_getnext_validate_node_inst.part.0 (node_instance_6(D), validate_arg_7(D));

  <bb 5> [local count: 1073741824]:
  # _4 = PHI <241(3), _2(4), 241(2)>
  return _4;

}



;; Function snmp_get_community (snmp_get_community, funcdef_no=1, decl_uid=6588, cgraph_uid=2, symbol_order=6)

Modification phase of node snmp_get_community/6
snmp_get_community ()
{
  const char * _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _2 = snmp_community;
  return _2;

}



;; Function snmp_set_community (snmp_set_community, funcdef_no=2, decl_uid=6594, cgraph_uid=3, symbol_order=7)

Modification phase of node snmp_set_community/7
snmp_set_community (const char * const community)
{
  unsigned int _1;

  <bb 2> [local count: 214748]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = strlen (community_4(D));
  if (_1 > 8)
    goto <bb 5>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 5> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 107374]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  snmp_community = community_4(D);
  return;

}



;; Function snmp_get_community_write (snmp_get_community_write, funcdef_no=3, decl_uid=6590, cgraph_uid=4, symbol_order=8)

Modification phase of node snmp_get_community_write/8
snmp_get_community_write ()
{
  const char * _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _2 = snmp_community_write;
  return _2;

}



;; Function snmp_get_community_trap (snmp_get_community_trap, funcdef_no=4, decl_uid=6592, cgraph_uid=5, symbol_order=9)

Modification phase of node snmp_get_community_trap/9
snmp_get_community_trap ()
{
  const char * _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _2 = snmp_community_trap;
  return _2;

}



;; Function snmp_set_community_write (snmp_set_community_write, funcdef_no=5, decl_uid=6596, cgraph_uid=6, symbol_order=10)

Modification phase of node snmp_set_community_write/10
snmp_set_community_write (const char * const community)
{
  unsigned int _1;

  <bb 2> [local count: 306783]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (community_4(D) == 0B)
    goto <bb 7>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 7> [local count: 92035]:

  <bb 3> [local count: 920350133]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 9> [local count: 920350133]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 214748]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = strlen (community_4(D));
  if (_1 > 8)
    goto <bb 8>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 8> [local count: 107374]:

  <bb 5> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 10> [local count: 1073741824]:
  goto <bb 5>; [100.00%]

  <bb 6> [local count: 107374]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  snmp_community_write = community_4(D);
  return;

}



;; Function snmp_set_community_trap (snmp_set_community_trap, funcdef_no=6, decl_uid=6598, cgraph_uid=7, symbol_order=11)

Modification phase of node snmp_set_community_trap/11
snmp_set_community_trap (const char * const community)
{
  unsigned int _1;

  <bb 2> [local count: 214748]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = strlen (community_4(D));
  if (_1 > 8)
    goto <bb 5>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 5> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 107374]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  snmp_community_trap = community_4(D);
  return;

}



;; Function snmp_set_write_callback (snmp_set_write_callback, funcdef_no=7, decl_uid=6609, cgraph_uid=8, symbol_order=12)

Modification phase of node snmp_set_write_callback/12
snmp_set_write_callback (void (*snmp_write_callback_fct) (const u32_t *, u8_t, void *) write_callback, void * callback_arg)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  snmp_write_callback = write_callback_2(D);
  # DEBUG BEGIN_STMT
  snmp_write_callback_arg = callback_arg_4(D);
  return;

}



;; Function snmp_varbind_length (snmp_varbind_length, funcdef_no=17, decl_uid=6851, cgraph_uid=18, symbol_order=22)

Modification phase of node snmp_varbind_length/22
snmp_varbind_length (struct snmp_varbind * varbind, struct snmp_varbind_len * len)
{
  u32_t[50] * _1;
  unsigned char _2;
  short unsigned int _3;
  u16_t * _4;
  short unsigned int _5;
  u8_t * _6;
  short unsigned int _7;
  short unsigned int _8;
  unsigned char _9;
  void * _10;
  long int _11;
  u16_t * _12;
  void * _13;
  long unsigned int _14;
  u16_t * _15;
  void * _16;
  short unsigned int _17;
  u16_t * _18;
  void * _19;
  long long unsigned int _20;
  u16_t * _21;
  short unsigned int _22;
  u8_t * _23;
  unsigned char _24;
  short unsigned int _25;
  short unsigned int _26;
  short unsigned int _27;
  unsigned char _28;
  short unsigned int _29;
  short unsigned int _30;
  short unsigned int _31;
  short unsigned int _32;
  short unsigned int _33;
  u8_t * _34;
  err_t _35;
  short unsigned int _44;
  short unsigned int _46;

  <bb 2> [local count: 1073661301]:
  # DEBUG BEGIN_STMT
  _1 = &varbind_38(D)->oid.id;
  _2 = varbind_38(D)->oid.len;
  _3 = (short unsigned int) _2;
  _4 = &len_40(D)->oid_value_len;
  snmp_asn1_enc_oid_cnt (_1, _3, _4);
  # DEBUG BEGIN_STMT
  _5 = len_40(D)->oid_value_len;
  _6 = &len_40(D)->oid_len_len;
  snmp_asn1_enc_length_cnt (_5, _6);
  # DEBUG BEGIN_STMT
  _7 = varbind_38(D)->value_len;
  if (_7 == 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 4>; [50.00%]

  <bb 3> [local count: 536830650]:
  # DEBUG BEGIN_STMT
  len_40(D)->value_value_len = 0;
  goto <bb 16>; [100.00%]

  <bb 4> [local count: 536830650]:
  # DEBUG BEGIN_STMT
  _44 = _7 & 16384;
  if (_44 != 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 5> [local count: 268415325]:
  # DEBUG BEGIN_STMT
  _8 = _7 & 49151;
  len_40(D)->value_value_len = _8;
  goto <bb 16>; [100.00%]

  <bb 6> [local count: 268415325]:
  # DEBUG BEGIN_STMT
  _9 = varbind_38(D)->type;
  switch (_9) <default: <L30> [28.57%], case 2: <L4> [14.29%], case 4: <L12> [14.29%], case 6: <L18> [14.29%], case 64: <L12> [14.29%], case 65 ... 67: <L7> [14.29%], case 68: <L12> [14.29%], case 70: <L21> [14.29%]>

  <bb 7> [local count: 38356550]:
<L4>:
  # DEBUG BEGIN_STMT
  if (_7 != 4)
    goto <bb 17>; [3.98%]
  else
    goto <bb 8>; [96.02%]

  <bb 8> [local count: 36829959]:
  # DEBUG BEGIN_STMT
  _10 = varbind_38(D)->value;
  _11 = MEM[(s32_t *)_10];
  _12 = &len_40(D)->value_value_len;
  snmp_asn1_enc_s32t_cnt (_11, _12);
  # DEBUG BEGIN_STMT
  goto <bb 16>; [100.00%]

  <bb 9> [local count: 38356550]:
<L7>:
  # DEBUG BEGIN_STMT
  if (_7 != 4)
    goto <bb 17>; [3.98%]
  else
    goto <bb 10>; [96.02%]

  <bb 10> [local count: 36829959]:
  # DEBUG BEGIN_STMT
  _13 = varbind_38(D)->value;
  _14 = MEM[(u32_t *)_13];
  _15 = &len_40(D)->value_value_len;
  snmp_asn1_enc_u32t_cnt (_14, _15);
  # DEBUG BEGIN_STMT
  goto <bb 16>; [100.00%]

  <bb 11> [local count: 38356550]:
<L12>:
  # DEBUG BEGIN_STMT
  len_40(D)->value_value_len = _7;
  # DEBUG BEGIN_STMT
  goto <bb 16>; [100.00%]

  <bb 12> [local count: 38356550]:
<L18>:
  # DEBUG BEGIN_STMT
  _46 = _7 & 3;
  if (_46 != 0)
    goto <bb 17>; [2.09%]
  else
    goto <bb 13>; [97.91%]

  <bb 13> [local count: 37554898]:
  # DEBUG BEGIN_STMT
  _16 = varbind_38(D)->value;
  _17 = _7 >> 2;
  _18 = &len_40(D)->value_value_len;
  snmp_asn1_enc_oid_cnt (_16, _17, _18);
  # DEBUG BEGIN_STMT
  goto <bb 16>; [100.00%]

  <bb 14> [local count: 38356550]:
<L21>:
  # DEBUG BEGIN_STMT
  if (_7 != 8)
    goto <bb 17>; [3.98%]
  else
    goto <bb 15>; [96.02%]

  <bb 15> [local count: 36829959]:
  # DEBUG BEGIN_STMT
  _19 = varbind_38(D)->value;
  _20 = MEM[(u64_t *)_19];
  _21 = &len_40(D)->value_value_len;
  snmp_asn1_enc_u64t_cnt (_20, _21);
  # DEBUG BEGIN_STMT

  <bb 16> [local count: 991647301]:
  # DEBUG BEGIN_STMT
  _22 = len_40(D)->value_value_len;
  _23 = &len_40(D)->value_len_len;
  snmp_asn1_enc_length_cnt (_22, _23);
  # DEBUG BEGIN_STMT
  _24 = len_40(D)->oid_len_len;
  _25 = (short unsigned int) _24;
  _26 = len_40(D)->oid_value_len;
  _27 = _25 + _26;
  _28 = len_40(D)->value_len_len;
  _29 = (short unsigned int) _28;
  _30 = _27 + _29;
  _31 = len_40(D)->value_value_len;
  _32 = _30 + _31;
  _33 = _32 + 2;
  len_40(D)->vb_value_len = _33;
  # DEBUG BEGIN_STMT
  _34 = &len_40(D)->vb_len_len;
  snmp_asn1_enc_length_cnt (_33, _34);
  # DEBUG BEGIN_STMT

  <bb 17> [local count: 1073741824]:
  # _35 = PHI <-6(7), -6(9), -6(6), -6(12), -6(14), 0(16)>
<L30>:
  return _35;

}



;; Function snmp_append_outbound_varbind (snmp_append_outbound_varbind, funcdef_no=18, decl_uid=6854, cgraph_uid=19, symbol_order=23)

Modification phase of node snmp_append_outbound_varbind/23
snmp_append_outbound_varbind (struct snmp_pbuf_stream * pbuf_stream, struct snmp_varbind * varbind)
{
  err_t err;
  struct snmp_varbind_len len;
  struct snmp_asn1_tlv tlv;
  unsigned char _1;
  int _2;
  int _3;
  short unsigned int _4;
  int _5;
  int _6;
  short unsigned int _7;
  int _8;
  signed char _9;
  unsigned char _10;
  short unsigned int _11;
  signed char _12;
  u32_t[50] * _13;
  unsigned char _14;
  short unsigned int _15;
  signed char _16;
  unsigned char _17;
  unsigned char _18;
  short unsigned int _19;
  signed char _20;
  short unsigned int _21;
  short unsigned int _22;
  void * _23;
  signed char _24;
  unsigned char _25;
  void * _26;
  long int _27;
  signed char _28;
  void * _29;
  long unsigned int _30;
  signed char _31;
  void * _32;
  signed char _33;
  void * _34;
  short unsigned int _35;
  signed char _36;
  void * _37;
  long long unsigned int _38;
  signed char _39;
  err_t _40;
  short unsigned int _65;

  <bb 2> [local count: 3203369]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  err_46 = snmp_varbind_length (varbind_44(D), &len);
  # DEBUG err => err_46
  # DEBUG BEGIN_STMT
  if (err_46 != 0)
    goto <bb 24>; [34.00%]
  else
    goto <bb 3>; [66.00%]

  <bb 3> [local count: 2114223]:
  # DEBUG BEGIN_STMT
  _1 = len.vb_len_len;
  _2 = (int) _1;
  _3 = _2 + 1;
  _4 = len.vb_value_len;
  _5 = (int) _4;
  _6 = _3 + _5;
  _7 = pbuf_stream_47(D)->length;
  _8 = (int) _7;
  if (_6 > _8)
    goto <bb 24>; [2.09%]
  else
    goto <bb 4>; [97.91%]

  <bb 4> [local count: 2070036]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  tlv.type = 48;
  # DEBUG BEGIN_STMT
  tlv.type_len = 0;
  # DEBUG BEGIN_STMT
  tlv.length_len = _1;
  # DEBUG BEGIN_STMT
  tlv.value_len = _4;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _9 = snmp_ans1_enc_tlv (pbuf_stream_47(D), &tlv);
  if (_9 != 0)
    goto <bb 24>; [2.09%]
  else
    goto <bb 5>; [97.91%]

  <bb 5> [local count: 2026772]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  tlv.type = 6;
  # DEBUG BEGIN_STMT
  tlv.type_len = 0;
  # DEBUG BEGIN_STMT
  _10 = len.oid_len_len;
  tlv.length_len = _10;
  # DEBUG BEGIN_STMT
  _11 = len.oid_value_len;
  tlv.value_len = _11;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _12 = snmp_ans1_enc_tlv (pbuf_stream_47(D), &tlv);
  if (_12 != 0)
    goto <bb 24>; [2.09%]
  else
    goto <bb 6>; [97.91%]

  <bb 6> [local count: 1984413]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _13 = &varbind_44(D)->oid.id;
  _14 = varbind_44(D)->oid.len;
  _15 = (short unsigned int) _14;
  _16 = snmp_asn1_enc_oid (pbuf_stream_47(D), _13, _15);
  if (_16 != 0)
    goto <bb 24>; [2.09%]
  else
    goto <bb 7>; [97.91%]

  <bb 7> [local count: 1942938]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _17 = varbind_44(D)->type;
  tlv.type = _17;
  # DEBUG BEGIN_STMT
  tlv.type_len = 0;
  # DEBUG BEGIN_STMT
  _18 = len.value_len_len;
  tlv.length_len = _18;
  # DEBUG BEGIN_STMT
  _19 = len.value_value_len;
  tlv.value_len = _19;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _20 = snmp_ans1_enc_tlv (pbuf_stream_47(D), &tlv);
  if (_20 != 0)
    goto <bb 24>; [1.04%]
  else
    goto <bb 8>; [98.96%]

  <bb 8> [local count: 1922732]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _21 = len.value_value_len;
  if (_21 != 0)
    goto <bb 9>; [50.00%]
  else
    goto <bb 24>; [50.00%]

  <bb 9> [local count: 961366]:
  # DEBUG BEGIN_STMT
  _22 = varbind_44(D)->value_len;
  _65 = _22 & 16384;
  if (_65 != 0)
    goto <bb 10>; [33.00%]
  else
    goto <bb 12>; [67.00%]

  <bb 10> [local count: 317251]:
  # DEBUG BEGIN_STMT
  _23 = varbind_44(D)->value;
  _24 = snmp_asn1_enc_raw (pbuf_stream_47(D), _23, _21);
  if (_24 != 0)
    goto <bb 11>; [1.04%]
  else
    goto <bb 24>; [98.96%]

  <bb 11> [local count: 3299]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 24>; [100.00%]

  <bb 12> [local count: 644115]:
  # DEBUG BEGIN_STMT
  _25 = varbind_44(D)->type;
  switch (_25) <default: <L49> [16.67%], case 2: <L17> [16.67%], case 4: <L25> [16.67%], case 6: <L30> [16.67%], case 64: <L25> [16.67%], case 65 ... 67: <L20> [16.67%], case 68: <L25> [16.67%], case 70: <L33> [16.67%]>

  <bb 25> [local count: 107352]:
<L49>:
  goto <bb 23>; [100.00%]

  <bb 13> [local count: 107374]:
<L17>:
  # DEBUG BEGIN_STMT
  _26 = varbind_44(D)->value;
  _27 = MEM[(s32_t *)_26];
  _28 = snmp_asn1_enc_s32t (pbuf_stream_47(D), _21, _27);
  if (_28 != 0)
    goto <bb 14>; [1.04%]
  else
    goto <bb 24>; [98.96%]

  <bb 14> [local count: 1117]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 24>; [100.00%]

  <bb 15> [local count: 107374]:
<L20>:
  # DEBUG BEGIN_STMT
  _29 = varbind_44(D)->value;
  _30 = MEM[(u32_t *)_29];
  _31 = snmp_asn1_enc_u32t (pbuf_stream_47(D), _21, _30);
  if (_31 != 0)
    goto <bb 16>; [1.04%]
  else
    goto <bb 24>; [98.96%]

  <bb 16> [local count: 1117]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 24>; [100.00%]

  <bb 17> [local count: 107374]:
<L25>:
  # DEBUG BEGIN_STMT
  _32 = varbind_44(D)->value;
  _33 = snmp_asn1_enc_raw (pbuf_stream_47(D), _32, _21);
  if (_33 != 0)
    goto <bb 18>; [1.04%]
  else
    goto <bb 24>; [98.96%]

  <bb 18> [local count: 1117]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 24>; [100.00%]

  <bb 19> [local count: 107374]:
<L30>:
  # DEBUG BEGIN_STMT
  _34 = varbind_44(D)->value;
  _35 = _22 >> 2;
  _36 = snmp_asn1_enc_oid (pbuf_stream_47(D), _34, _35);
  if (_36 != 0)
    goto <bb 20>; [1.04%]
  else
    goto <bb 24>; [98.96%]

  <bb 20> [local count: 1117]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 24>; [100.00%]

  <bb 21> [local count: 107374]:
<L33>:
  # DEBUG BEGIN_STMT
  _37 = varbind_44(D)->value;
  _38 = MEM[(u64_t *)_37];
  _39 = snmp_asn1_enc_u64t (pbuf_stream_47(D), _21, _38);
  if (_39 != 0)
    goto <bb 22>; [1.04%]
  else
    goto <bb 24>; [98.96%]

  <bb 22> [local count: 1117]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 24>; [100.00%]

  <bb 26> [local count: 1073741824]:

  <bb 23> [local count: 1073741824]:
<L45>:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT
  goto <bb 26>; [100.00%]

  <bb 24> [local count: 3096123]:
  # _40 = PHI <err_46(2), -2(3), -16(4), -16(5), -16(6), -16(7), -16(11), -16(14), -16(16), -16(18), -16(20), -16(22), 0(10), 0(8), 0(21), 0(19), 0(17), 0(15), 0(13)>
  tlv ={v} {CLOBBER};
  len ={v} {CLOBBER};
  return _40;

}



;; Function snmp_process_varbind (snmp_process_varbind, funcdef_no=10, decl_uid=7277, cgraph_uid=11, symbol_order=15)

Modification phase of node snmp_process_varbind/15
Adjusting mask for param 0 to 0xfffffffc
Adjusting align: 4, misalign: 0
Adjusting mask for param 1 to 0xfffffffc
Adjusting align: 4, misalign: 0
Adjusting mask for param 2 to 0x1
Setting nonnull for 0
Setting nonnull for 1
Setting value range of param 2 [0, 1]
snmp_process_varbind (struct snmp_request * request, struct snmp_varbind * vb, u8_t get_next)
{
  s16_t len;
  struct snmp_obj_id result_oid;
  struct snmp_node_instance node_instance;
  err_t err;
  u32_t[50] * _1;
  unsigned char _2;
  unsigned char _3;
  long int _4;
  struct snmp_obj_id * _5;
  unsigned char _6;
  u32_t[50] * _7;
  unsigned char _8;
  unsigned char _9;
  long int _10;
  unsigned char _11;
  long int _12;
  void (*<T656>) (struct snmp_node_instance *) _13;
  long int _14;
  unsigned char _15;
  signed char _16;
  signed char _17;
  signed char _18;
  unsigned char _19;
  struct snmp_pbuf_stream * _20;
  s16_t (*<T64c>) (struct snmp_node_instance *, void *) _21;
  void * _22;
  short unsigned int len.9_23;
  unsigned char _24;
  unsigned int _25;
  unsigned int _26;
  struct snmp_pbuf_stream * _27;
  void (*<T656>) (struct snmp_node_instance *) _28;

  <bb 2> [local count: 543253]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  memset (&node_instance, 0, 248);
  # DEBUG BEGIN_STMT
  if (get_next_36(D) != 0)
    goto <bb 3>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 3> [local count: 271627]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = &vb_37(D)->oid.id;
  _2 = vb_37(D)->oid.len;
  _3 = snmp_get_next_node_instance_from_oid (_1, _2, snmp_msg_getnext_validate_node_inst, request_39(D), &result_oid, &node_instance);
  _4 = (long int) _3;
  request_39(D)->error_status = _4;
  # DEBUG BEGIN_STMT
  if (_4 == 0)
    goto <bb 4>; [33.00%]
  else
    goto <bb 5>; [67.00%]

  <bb 4> [local count: 89637]:
  # DEBUG BEGIN_STMT
  _5 = &vb_37(D)->oid;
  _6 = result_oid.len;
  snmp_oid_assign (_5, &result_oid.id, _6);

  <bb 5> [local count: 271627]:
  result_oid ={v} {CLOBBER};
  goto <bb 10>; [100.00%]

  <bb 6> [local count: 271627]:
  # DEBUG BEGIN_STMT
  _7 = &vb_37(D)->oid.id;
  _8 = vb_37(D)->oid.len;
  _9 = snmp_get_node_instance_from_oid (_7, _8, &node_instance);
  _10 = (long int) _9;
  request_39(D)->error_status = _10;
  # DEBUG BEGIN_STMT
  if (_10 == 0)
    goto <bb 7>; [50.00%]
  else
    goto <bb 10>; [50.00%]

  <bb 7> [local count: 135813]:
  # DEBUG BEGIN_STMT
  _11 = snmp_msg_getnext_validate_node_inst (&node_instance, request_39(D));
  _12 = (long int) _11;
  request_39(D)->error_status = _12;
  # DEBUG BEGIN_STMT
  if (_12 != 0)
    goto <bb 8>; [50.00%]
  else
    goto <bb 10>; [50.00%]

  <bb 8> [local count: 67907]:
  # DEBUG BEGIN_STMT
  _13 = node_instance.release_instance;
  if (_13 != 0B)
    goto <bb 9>; [70.00%]
  else
    goto <bb 10>; [30.00%]

  <bb 9> [local count: 47535]:
  # DEBUG BEGIN_STMT
  _13 (&node_instance);

  <bb 10> [local count: 543253]:
  # DEBUG BEGIN_STMT
  _14 = request_39(D)->error_status;
  if (_14 != 0)
    goto <bb 11>; [50.00%]
  else
    goto <bb 20>; [50.00%]

  <bb 11> [local count: 271627]:
  # DEBUG BEGIN_STMT
  if (_14 > 239)
    goto <bb 12>; [50.00%]
  else
    goto <bb 19>; [50.00%]

  <bb 12> [local count: 135813]:
  # DEBUG BEGIN_STMT
  _15 = request_39(D)->version;
  if (_15 == 1)
    goto <bb 14>; [20.24%]
  else
    goto <bb 13>; [79.76%]

  <bb 13> [local count: 108325]:
  if (_15 == 3)
    goto <bb 14>; [34.00%]
  else
    goto <bb 30>; [66.00%]

  <bb 14> [local count: 64319]:
  # DEBUG BEGIN_STMT
  _16 = (signed char) _14;
  _17 = _16 & 15;
  _18 = _17 | -128;
  _19 = (unsigned char) _18;
  vb_37(D)->type = _19;
  # DEBUG BEGIN_STMT
  vb_37(D)->value_len = 0;
  # DEBUG BEGIN_STMT
  _20 = &request_39(D)->outbound_pbuf_stream;
  err_62 = snmp_append_outbound_varbind (_20, vb_37(D));
  # DEBUG err => err_62
  # DEBUG BEGIN_STMT
  if (err_62 == 0)
    goto <bb 15>; [50.00%]
  else
    goto <bb 16>; [50.00%]

  <bb 15> [local count: 32160]:
  # DEBUG BEGIN_STMT
  request_39(D)->error_status = 0;
  goto <bb 30>; [100.00%]

  <bb 16> [local count: 32160]:
  # DEBUG BEGIN_STMT
  if (err_62 == -2)
    goto <bb 17>; [34.00%]
  else
    goto <bb 18>; [66.00%]

  <bb 17> [local count: 10934]:
  # DEBUG BEGIN_STMT
  request_39(D)->error_status = 1;
  goto <bb 30>; [100.00%]

  <bb 18> [local count: 21225]:
  # DEBUG BEGIN_STMT
  request_39(D)->error_status = 5;
  goto <bb 30>; [100.00%]

  <bb 19> [local count: 135813]:
  # DEBUG BEGIN_STMT
  request_39(D)->error_status = 5;
  goto <bb 30>; [100.00%]

  <bb 20> [local count: 271627]:
  # DEBUG BEGIN_STMT
  _21 = node_instance.get_value;
  _22 = vb_37(D)->value;
  len_48 = _21 (&node_instance, _22);
  # DEBUG len => len_48
  # DEBUG BEGIN_STMT
  if (len_48 >= 0)
    goto <bb 21>; [59.00%]
  else
    goto <bb 27>; [41.00%]

  <bb 21> [local count: 160260]:
  # DEBUG BEGIN_STMT
  len.9_23 = (short unsigned int) len_48;
  vb_37(D)->value_len = len.9_23;
  # DEBUG BEGIN_STMT
  _24 = node_instance.asn1_type;
  vb_37(D)->type = _24;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _25 = (unsigned int) len.9_23;
  _26 = _25 & 4294950911;
  if (_26 > 200)
    goto <bb 31>; [67.00%]
  else
    goto <bb 23>; [33.00%]

  <bb 31> [local count: 107374]:

  <bb 22> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 32> [local count: 1073741824]:
  goto <bb 22>; [100.00%]

  <bb 23> [local count: 52886]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _27 = &request_39(D)->outbound_pbuf_stream;
  err_53 = snmp_append_outbound_varbind (_27, vb_37(D));
  # DEBUG err => err_53
  # DEBUG BEGIN_STMT
  if (err_53 == -2)
    goto <bb 24>; [34.00%]
  else
    goto <bb 25>; [66.00%]

  <bb 24> [local count: 17981]:
  # DEBUG BEGIN_STMT
  request_39(D)->error_status = 1;
  goto <bb 28>; [100.00%]

  <bb 25> [local count: 34905]:
  # DEBUG BEGIN_STMT
  if (err_53 != 0)
    goto <bb 26>; [50.00%]
  else
    goto <bb 28>; [50.00%]

  <bb 26> [local count: 17452]:
  # DEBUG BEGIN_STMT
  request_39(D)->error_status = 5;
  goto <bb 28>; [100.00%]

  <bb 27> [local count: 111367]:
  # DEBUG BEGIN_STMT
  request_39(D)->error_status = 5;

  <bb 28> [local count: 164253]:
  # DEBUG BEGIN_STMT
  _28 = node_instance.release_instance;
  if (_28 != 0B)
    goto <bb 29>; [70.00%]
  else
    goto <bb 30>; [30.00%]

  <bb 29> [local count: 114977]:
  # DEBUG BEGIN_STMT
  _28 (&node_instance);

  <bb 30> [local count: 435879]:
  node_instance ={v} {CLOBBER};
  return;

}



;; Function snmp_vb_enumerator_init (snmp_vb_enumerator_init, funcdef_no=21, decl_uid=6795, cgraph_uid=22, symbol_order=26)

Modification phase of node snmp_vb_enumerator_init/26
snmp_vb_enumerator_init (struct snmp_varbind_enumerator * enumerator, struct pbuf * p, u16_t offset, u16_t length)
{
  struct snmp_pbuf_stream * _1;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _1 = &enumerator_2(D)->pbuf_stream;
  snmp_pbuf_stream_init (_1, p_4(D), offset_5(D), length_6(D));
  # DEBUG BEGIN_STMT
  enumerator_2(D)->varbind_count = 0;
  return;

}



;; Function snmp_vb_enumerator_get_next (snmp_vb_enumerator_get_next, funcdef_no=22, decl_uid=6798, cgraph_uid=23, symbol_order=27)

Modification phase of node snmp_vb_enumerator_get_next/27
snmp_vb_enumerator_get_next (struct snmp_varbind_enumerator * enumerator, struct snmp_varbind * varbind)
{
  short unsigned int _1;
  <unnamed type> _2;
  snmp_vb_enumerator_err_t _3;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = enumerator_6(D)->pbuf_stream.length;
  if (_1 == 0)
    goto <bb 4>; [51.12%]
  else
    goto <bb 3>; [48.88%]

  <bb 3> [local count: 524845000]:
  _2 = snmp_vb_enumerator_get_next.part.0 (enumerator_6(D), varbind_8(D));

  <bb 4> [local count: 1073741824]:
  # _3 = PHI <1(2), _2(3)>
  return _3;

}



;; Function snmp_receive (snmp_receive, funcdef_no=8, decl_uid=6839, cgraph_uid=9, symbol_order=13)

Modification phase of node snmp_receive/13
snmp_receive (void * handle, struct pbuf * p, const struct ip_addr_t * source_ip, u16_t port)
{
  struct snmp_request request;
  err_t err;
  long unsigned int _1;
  long unsigned int _2;
  long int _3;
  unsigned char _4;
  void * _5;
  struct pbuf * _6;
  const struct ip_addr_t * _7;
  short unsigned int _8;
  unsigned char _9;
  long int _10;
  void (*<T6bc>) (const u32_t *, u8_t, void *) snmp_write_callback.0_11;
  struct pbuf * _12;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  memset (&request, 0, 292);
  # DEBUG BEGIN_STMT
  request.handle = handle_19(D);
  # DEBUG BEGIN_STMT
  request.source_ip = source_ip_21(D);
  # DEBUG BEGIN_STMT
  request.source_port = port_23(D);
  # DEBUG BEGIN_STMT
  request.inbound_pbuf = p_25(D);
  # DEBUG BEGIN_STMT
  _1 = snmp_stats.inpkts;
  _2 = _1 + 1;
  snmp_stats.inpkts = _2;
  # DEBUG BEGIN_STMT
  err_29 = snmp_parse_inbound_frame (&request);
  # DEBUG err => err_29
  # DEBUG BEGIN_STMT
  if (err_29 == 0)
    goto <bb 3>; [33.00%]
  else
    goto <bb 21>; [67.00%]

  <bb 3> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  err_31 = snmp_prepare_outbound_frame (&request);
  # DEBUG err => err_31
  # DEBUG BEGIN_STMT
  if (err_31 == 0)
    goto <bb 4>; [50.00%]
  else
    goto <bb 19>; [50.00%]

  <bb 4> [local count: 177167401]:
  # DEBUG BEGIN_STMT
  _3 = request.error_status;
  if (_3 == 0)
    goto <bb 5>; [50.00%]
  else
    goto <bb 13>; [50.00%]

  <bb 5> [local count: 88583700]:
  # DEBUG BEGIN_STMT
  _4 = request.request_type;
  if (_4 == 0)
    goto <bb 6>; [33.00%]
  else
    goto <bb 7>; [67.00%]

  <bb 6> [local count: 29232621]:
  # DEBUG BEGIN_STMT
  err_39 = snmp_process_get_request (&request);
  # DEBUG err => err_39
  goto <bb 13>; [100.00%]

  <bb 7> [local count: 59351079]:
  # DEBUG BEGIN_STMT
  if (_4 == 1)
    goto <bb 8>; [20.24%]
  else
    goto <bb 9>; [79.76%]

  <bb 8> [local count: 12012658]:
  # DEBUG BEGIN_STMT
  err_37 = snmp_process_getnext_request (&request);
  # DEBUG err => err_37
  goto <bb 13>; [100.00%]

  <bb 9> [local count: 47338421]:
  # DEBUG BEGIN_STMT
  if (_4 == 5)
    goto <bb 10>; [20.24%]
  else
    goto <bb 11>; [79.76%]

  <bb 10> [local count: 9581296]:
  # DEBUG BEGIN_STMT
  err_35 = snmp_process_getbulk_request (&request);
  # DEBUG err => err_35
  goto <bb 13>; [100.00%]

  <bb 11> [local count: 37757124]:
  # DEBUG BEGIN_STMT
  if (_4 == 3)
    goto <bb 12>; [20.24%]
  else
    goto <bb 13>; [79.76%]

  <bb 12> [local count: 7642042]:
  # DEBUG BEGIN_STMT
  err_33 = snmp_process_set_request (&request);
  # DEBUG err => err_33

  <bb 13> [local count: 177167401]:
  # err_13 = PHI <0(4), err_39(6), err_37(8), err_35(10), 0(11), err_33(12)>
  # DEBUG err => err_13
  # DEBUG BEGIN_STMT
  if (err_13 == 0)
    goto <bb 14>; [33.00%]
  else
    goto <bb 19>; [67.00%]

  <bb 14> [local count: 58465242]:
  # DEBUG BEGIN_STMT
  err_41 = snmp_complete_outbound_frame (&request);
  # DEBUG err => err_41
  # DEBUG BEGIN_STMT
  if (err_41 == 0)
    goto <bb 15>; [33.00%]
  else
    goto <bb 19>; [67.00%]

  <bb 15> [local count: 19293530]:
  # DEBUG BEGIN_STMT
  _5 = request.handle;
  _6 = request.outbound_pbuf;
  _7 = request.source_ip;
  _8 = request.source_port;
  snmp_sendto (_5, _6, _7, _8);
  # DEBUG err => NULL
  # DEBUG BEGIN_STMT
  _9 = request.request_type;
  if (_9 == 3)
    goto <bb 16>; [34.00%]
  else
    goto <bb 19>; [66.00%]

  <bb 16> [local count: 6559800]:
  _10 = request.error_status;
  if (_10 == 0)
    goto <bb 17>; [50.00%]
  else
    goto <bb 19>; [50.00%]

  <bb 17> [local count: 3279900]:
  snmp_write_callback.0_11 = snmp_write_callback;
  if (snmp_write_callback.0_11 != 0B)
    goto <bb 18>; [53.47%]
  else
    goto <bb 19>; [46.53%]

  <bb 18> [local count: 1753763]:
  # DEBUG BEGIN_STMT
  snmp_execute_write_callbacks (&request);

  <bb 19> [local count: 354334802]:
  # DEBUG BEGIN_STMT
  _12 = request.outbound_pbuf;
  if (_12 != 0B)
    goto <bb 20>; [53.47%]
  else
    goto <bb 21>; [46.53%]

  <bb 20> [local count: 189462819]:
  # DEBUG BEGIN_STMT
  pbuf_free (_12);

  <bb 21> [local count: 1073741824]:
  request ={v} {CLOBBER};
  return;

}


