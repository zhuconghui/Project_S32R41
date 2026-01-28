
IPA constant propagation start:
Determining dynamic type for call: a_10 = pbuf_get_at (q_9, _8);
  Starting walk at: a_10 = pbuf_get_at (q_9, _8);
  instance pointer: q_9  Outer instance pointer: q_9 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:a_10 = pbuf_get_at (q_9, _8);
Determining dynamic type for call: _9 (p_1);
  Starting walk at: _9 (p_1);
  instance pointer: p_1  Outer instance pointer: p_1 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:_9 (p_1);
  Function call may change dynamic type:memp_free (14, p_1);
  Function call may change dynamic type:memp_free (13, p_1);
  Function call may change dynamic type:mem_free (p_1);
Determining dynamic type for call: _6 = pbuf_remove_header (p_5(D), _4);
  Starting walk at: _6 = pbuf_remove_header (p_5(D), _4);
  instance pointer: p_5(D)  Outer instance pointer: p_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _11 = pbuf_memfind (p_8(D), substr_6(D), _3, 0);
  Starting walk at: _11 = pbuf_memfind (p_8(D), substr_6(D), _3, 0);
  instance pointer: p_8(D)  Outer instance pointer: p_8(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _11 = pbuf_memfind (p_8(D), substr_6(D), _3, 0);
  Starting walk at: _11 = pbuf_memfind (p_8(D), substr_6(D), _3, 0);
  instance pointer: substr_6(D)  Outer instance pointer: substr_6(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: plus_18 = pbuf_memcmp (p_12(D), i_7, mem_16(D), mem_len_13(D));
  Starting walk at: plus_18 = pbuf_memcmp (p_12(D), i_7, mem_16(D), mem_len_13(D));
  instance pointer: p_12(D)  Outer instance pointer: p_12(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:plus_18 = pbuf_memcmp (p_12(D), i_7, mem_16(D), mem_len_13(D));
Determining dynamic type for call: plus_18 = pbuf_memcmp (p_12(D), i_7, mem_16(D), mem_len_13(D));
  Starting walk at: plus_18 = pbuf_memcmp (p_12(D), i_7, mem_16(D), mem_len_13(D));
  instance pointer: mem_16(D)  Outer instance pointer: mem_16(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:plus_18 = pbuf_memcmp (p_12(D), i_7, mem_16(D), mem_len_13(D));
Determining dynamic type for call: _11 = pbuf_memcmp.part.0 (p_10(D), offset_9(D), s2_16(D), n_13(D));
  Starting walk at: _11 = pbuf_memcmp.part.0 (p_10(D), offset_9(D), s2_16(D), n_13(D));
  instance pointer: p_10(D)  Outer instance pointer: p_10(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _11 = pbuf_memcmp.part.0 (p_10(D), offset_9(D), s2_16(D), n_13(D));
  Starting walk at: _11 = pbuf_memcmp.part.0 (p_10(D), offset_9(D), s2_16(D), n_13(D));
  instance pointer: s2_16(D)  Outer instance pointer: s2_16(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: out_13 = pbuf_skip_const (p_8(D), offset_9(D), &q_idx);
  Starting walk at: out_13 = pbuf_skip_const (p_8(D), offset_9(D), &q_idx);
  instance pointer: p_8(D)  Outer instance pointer: p_8(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: out_13 = pbuf_skip_const (p_8(D), offset_9(D), &q_idx);
  Starting walk at: out_13 = pbuf_skip_const (p_8(D), offset_9(D), &q_idx);
  instance pointer: &q_idx  Outer instance pointer: q_idx offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: q_12 = pbuf_skip_const (p_9(D), offset_10(D), &q_idx);
  Starting walk at: q_12 = pbuf_skip_const (p_9(D), offset_10(D), &q_idx);
  instance pointer: p_9(D)  Outer instance pointer: p_9(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: q_12 = pbuf_skip_const (p_9(D), offset_10(D), &q_idx);
  Starting walk at: q_12 = pbuf_skip_const (p_9(D), offset_10(D), &q_idx);
  instance pointer: &q_idx  Outer instance pointer: q_idx offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: ret_6 = pbuf_try_get_at (p_3(D), offset_4(D));
  Starting walk at: ret_6 = pbuf_try_get_at (p_3(D), offset_4(D));
  instance pointer: p_3(D)  Outer instance pointer: p_3(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: err_12 = pbuf_copy (q_10, p_6(D));
  Starting walk at: err_12 = pbuf_copy (q_10, p_6(D));
  instance pointer: q_10  Outer instance pointer: q_10 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:q_10 = pbuf_alloc (layer_7(D), _1, type_8(D));
Determining dynamic type for call: err_12 = pbuf_copy (q_10, p_6(D));
  Starting walk at: err_12 = pbuf_copy (q_10, p_6(D));
  instance pointer: p_6(D)  Outer instance pointer: p_6(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:q_10 = pbuf_alloc (layer_7(D), _1, type_8(D));
Determining dynamic type for call: q_8 = pbuf_clone (layer_6(D), 640, p_5(D));
  Starting walk at: q_8 = pbuf_clone (layer_6(D), 640, p_5(D));
  instance pointer: p_5(D)  Outer instance pointer: p_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pbuf_free (p_5(D));
  Starting walk at: pbuf_free (p_5(D));
  instance pointer: p_5(D)  Outer instance pointer: p_5(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:q_8 = pbuf_clone (layer_6(D), 640, p_5(D));
Determining dynamic type for call: out_32 = pbuf_skip_const (buf_20(D), offset_21(D), &target_offset);
  Starting walk at: out_32 = pbuf_skip_const (buf_20(D), offset_21(D), &target_offset);
  instance pointer: buf_20(D)  Outer instance pointer: buf_20(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: out_32 = pbuf_skip_const (buf_20(D), offset_21(D), &target_offset);
  Starting walk at: out_32 = pbuf_skip_const (buf_20(D), offset_21(D), &target_offset);
  instance pointer: &target_offset  Outer instance pointer: target_offset offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _29 = pbuf_take (_14, src_ptr_27, remaining_len_26);
  Starting walk at: _29 = pbuf_take (_14, src_ptr_27, remaining_len_26);
  instance pointer: _14  Outer instance pointer: _14 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:memcpy (_12, dataptr_23(D), _13);
  Function call may change dynamic type:out_32 = pbuf_skip_const (buf_20(D), offset_21(D), &target_offset);
Determining dynamic type for call: _29 = pbuf_take (_14, src_ptr_27, remaining_len_26);
  Starting walk at: _29 = pbuf_take (_14, src_ptr_27, remaining_len_26);
  instance pointer: src_ptr_27  Outer instance pointer: src_ptr_27 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:memcpy (_12, dataptr_23(D), _13);
  Function call may change dynamic type:out_32 = pbuf_skip_const (buf_20(D), offset_21(D), &target_offset);
Determining dynamic type for call: out_6 = pbuf_skip_const (in_2(D), in_offset_3(D), out_offset_4(D));
  Starting walk at: out_6 = pbuf_skip_const (in_2(D), in_offset_3(D), out_offset_4(D));
  instance pointer: in_2(D)  Outer instance pointer: in_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: out_6 = pbuf_skip_const (in_2(D), in_offset_3(D), out_offset_4(D));
  Starting walk at: out_6 = pbuf_skip_const (in_2(D), in_offset_3(D), out_offset_4(D));
  instance pointer: out_offset_4(D)  Outer instance pointer: out_offset_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: q_20 = pbuf_skip_const (p_13(D), offset_18(D), &out_offset);
  Starting walk at: q_20 = pbuf_skip_const (p_13(D), offset_18(D), &out_offset);
  instance pointer: p_13(D)  Outer instance pointer: p_13(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: q_20 = pbuf_skip_const (p_13(D), offset_18(D), &out_offset);
  Starting walk at: q_20 = pbuf_skip_const (p_13(D), offset_18(D), &out_offset);
  instance pointer: &out_offset  Outer instance pointer: out_offset offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _10 = pbuf_copy_partial (q_20, buffer_14(D), len_15(D), out_offset.3_4);
  Starting walk at: _10 = pbuf_copy_partial (q_20, buffer_14(D), len_15(D), out_offset.3_4);
  instance pointer: q_20  Outer instance pointer: q_20 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:q_20 = pbuf_skip_const (p_13(D), offset_18(D), &out_offset);
Determining dynamic type for call: _10 = pbuf_copy_partial (q_20, buffer_14(D), len_15(D), out_offset.3_4);
  Starting walk at: _10 = pbuf_copy_partial (q_20, buffer_14(D), len_15(D), out_offset.3_4);
  instance pointer: buffer_14(D)  Outer instance pointer: buffer_14(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:q_20 = pbuf_skip_const (p_13(D), offset_18(D), &out_offset);
Determining dynamic type for call: _6 = pbuf_copy_partial.part.0 (buf_9(D), dataptr_10(D), len_11(D), offset_12(D));
  Starting walk at: _6 = pbuf_copy_partial.part.0 (buf_9(D), dataptr_10(D), len_11(D), offset_12(D));
  instance pointer: buf_9(D)  Outer instance pointer: buf_9(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _6 = pbuf_copy_partial.part.0 (buf_9(D), dataptr_10(D), len_11(D), offset_12(D));
  Starting walk at: _6 = pbuf_copy_partial.part.0 (buf_9(D), dataptr_10(D), len_11(D), offset_12(D));
  instance pointer: dataptr_10(D)  Outer instance pointer: dataptr_10(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _8 = pbuf_copy_partial_pbuf (p_to_6(D), p_from_4(D), _1, 0);
  Starting walk at: _8 = pbuf_copy_partial_pbuf (p_to_6(D), p_from_4(D), _1, 0);
  instance pointer: p_to_6(D)  Outer instance pointer: p_to_6(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _8 = pbuf_copy_partial_pbuf (p_to_6(D), p_from_4(D), _1, 0);
  Starting walk at: _8 = pbuf_copy_partial_pbuf (p_to_6(D), p_from_4(D), _1, 0);
  instance pointer: p_from_4(D)  Outer instance pointer: p_from_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: tail_gone_23 = pbuf_free (q_18);
  Starting walk at: tail_gone_23 = pbuf_free (q_18);
  instance pointer: q_18  Outer instance pointer: q_18 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pbuf_cat (h_2(D), t_3(D));
  Starting walk at: pbuf_cat (h_2(D), t_3(D));
  instance pointer: h_2(D)  Outer instance pointer: h_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pbuf_cat (h_2(D), t_3(D));
  Starting walk at: pbuf_cat (h_2(D), t_3(D));
  instance pointer: t_3(D)  Outer instance pointer: t_3(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pbuf_ref (t_3(D));
  Starting walk at: pbuf_ref (t_3(D));
  instance pointer: t_3(D)  Outer instance pointer: t_3(D) offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pbuf_cat (h_2(D), t_3(D));
Determining dynamic type for call: pbuf_cat.part.0 (h_4(D), t_5(D));
  Starting walk at: pbuf_cat.part.0 (h_4(D), t_5(D));
  instance pointer: h_4(D)  Outer instance pointer: h_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pbuf_cat.part.0 (h_4(D), t_5(D));
  Starting walk at: pbuf_cat.part.0 (h_4(D), t_5(D));
  instance pointer: t_5(D)  Outer instance pointer: t_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: count_1 = pbuf_free.part.0 (p_7(D));
  Starting walk at: count_1 = pbuf_free.part.0 (p_7(D));
  instance pointer: p_7(D)  Outer instance pointer: p_7(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pbuf_remove_header (p_11, _3);
  Starting walk at: pbuf_remove_header (p_11, _3);
  instance pointer: p_11  Outer instance pointer: p_4 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pbuf_free (p_4);
Determining dynamic type for call: pbuf_free (p_4);
  Starting walk at: pbuf_free (p_4);
  instance pointer: p_4  Outer instance pointer: p_4 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:pbuf_free (p_4);
Determining dynamic type for call: _5 = pbuf_header_impl (p_2(D), header_size_increment_3(D), 1);
  Starting walk at: _5 = pbuf_header_impl (p_2(D), header_size_increment_3(D), 1);
  instance pointer: p_2(D)  Outer instance pointer: p_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _5 = pbuf_header_impl (p_2(D), header_size_increment_3(D), 0);
  Starting walk at: _5 = pbuf_header_impl (p_2(D), header_size_increment_3(D), 0);
  instance pointer: p_2(D)  Outer instance pointer: p_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _8 = pbuf_add_header_impl (p_5(D), _1, force_6(D));
  Starting walk at: _8 = pbuf_add_header_impl (p_5(D), _1, force_6(D));
  instance pointer: p_5(D)  Outer instance pointer: p_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _9 = pbuf_header_impl.part.0 (p_5(D), header_size_increment_3(D));
  Starting walk at: _9 = pbuf_header_impl.part.0 (p_5(D), header_size_increment_3(D));
  instance pointer: p_5(D)  Outer instance pointer: p_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _1 = pbuf_remove_header.part.0 (p_5(D), header_size_decrement_7(D));
  Starting walk at: _1 = pbuf_remove_header.part.0 (p_5(D), header_size_decrement_7(D));
  instance pointer: p_5(D)  Outer instance pointer: p_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _5 = pbuf_add_header_impl (p_2(D), header_size_increment_3(D), 1);
  Starting walk at: _5 = pbuf_add_header_impl (p_2(D), header_size_increment_3(D), 1);
  instance pointer: p_2(D)  Outer instance pointer: p_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _5 = pbuf_add_header_impl (p_2(D), header_size_increment_3(D), 0);
  Starting walk at: _5 = pbuf_add_header_impl (p_2(D), header_size_increment_3(D), 0);
  instance pointer: p_2(D)  Outer instance pointer: p_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _7 = pbuf_add_header_impl.part.0 (p_4(D), header_size_increment_6(D), force_8(D));
  Starting walk at: _7 = pbuf_add_header_impl.part.0 (p_4(D), header_size_increment_6(D), force_8(D));
  instance pointer: p_4(D)  Outer instance pointer: p_4(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pbuf_free (_15);
  Starting walk at: pbuf_free (_15);
  instance pointer: _15  Outer instance pointer: _15 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:q_32 = mem_trim (q_7, _13);
Determining dynamic type for call: _7 = pbuf_alloc_reference.part.0 (payload_5(D), length_6(D), type_2(D));
  Starting walk at: _7 = pbuf_alloc_reference.part.0 (payload_5(D), length_6(D), type_2(D));
  instance pointer: payload_5(D)  Outer instance pointer: payload_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: pbuf_free (p_32);
  Starting walk at: pbuf_free (p_32);
  instance pointer: p_32  Outer instance pointer: p_24 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:q_45 = memp_malloc (14);
  Function call may change dynamic type:q_45 = memp_malloc (14);
Determining dynamic type for call: p_51 = pbuf_alloc_reference (0B, length_39(D), type_37(D));
  Starting walk at: p_51 = pbuf_alloc_reference (0B, length_39(D), type_37(D));
  instance pointer: 0B  Outer instance pointer: 0B offset: 0 (bits) vtbl reference: 

IPA structures before propagation:

Jump functions:
  Jump functions of caller  pbuf_memcmp.part.0/55:
    callsite  pbuf_memcmp.part.0/55 -> pbuf_get_at/30 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
  Jump functions of caller  pbuf_copy_partial.part.0/52:
  Jump functions of caller  pbuf_cat.part.0/51:
  Jump functions of caller  pbuf_free.part.0/49:
    indirect simple callsite, calling param -1, offset 0, for stmt _9 (p_1);
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pbuf_header_impl.part.0/48:
    callsite  pbuf_header_impl.part.0/48 -> pbuf_remove_header/9 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffff
         VR  [1, 32768]
  Jump functions of caller  pbuf_remove_header.part.0/47:
  Jump functions of caller  pbuf_alloc_reference.part.0/45:
  Jump functions of caller  pbuf_add_header_impl.part.0/43:
  Jump functions of caller  strlen/42:
  Jump functions of caller  memcpy/41:
  Jump functions of caller  mem_free/40:
  Jump functions of caller  memp_free/39:
  Jump functions of caller  mem_trim/38:
  Jump functions of caller  mem_malloc/37:
  Jump functions of caller  memp_malloc/36:
  Jump functions of caller  pbuf_strstr/35:
    callsite  pbuf_strstr/35 -> pbuf_memfind/34 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffff
         VR  [0, -2]
       param 3: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  pbuf_memfind/34:
    callsite  pbuf_memfind/34 -> pbuf_memcmp/33 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
  Jump functions of caller  pbuf_memcmp/33:
    callsite  pbuf_memcmp/33 -> pbuf_memcmp.part.0/55 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 3: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
  Jump functions of caller  pbuf_put_at/32:
    callsite  pbuf_put_at/32 -> pbuf_skip_const/24 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffe
         VR  ~[0, 0]
  Jump functions of caller  pbuf_try_get_at/31:
    callsite  pbuf_try_get_at/31 -> pbuf_skip_const/24 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffe
         VR  ~[0, 0]
  Jump functions of caller  pbuf_get_at/30:
    callsite  pbuf_get_at/30 -> pbuf_try_get_at/31 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
  Jump functions of caller  pbuf_clone/29:
    callsite  pbuf_clone/29 -> pbuf_copy/20 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pbuf_clone/29 -> pbuf_alloc/2 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
  Jump functions of caller  pbuf_coalesce/28:
    callsite  pbuf_coalesce/28 -> pbuf_free/14 : 
       param 0: PASS THROUGH: 0, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pbuf_coalesce/28 -> pbuf_clone/29 : 
       param 0: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
       param 1: CONST: 640
         value: 0x280, mask: 0x0
         Unknown VR
       param 2: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pbuf_take_at/27:
    callsite  pbuf_take_at/27 -> pbuf_take/26 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 2: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
    callsite  pbuf_take_at/27 -> pbuf_skip_const/24 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffe
         VR  ~[0, 0]
  Jump functions of caller  pbuf_take/26:
  Jump functions of caller  pbuf_skip/25:
    callsite  pbuf_skip/25 -> pbuf_skip_const/24 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pbuf_skip_const/24:
  Jump functions of caller  pbuf_get_contiguous/23:
    callsite  pbuf_get_contiguous/23 -> pbuf_copy_partial/22 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 3: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
    callsite  pbuf_get_contiguous/23 -> pbuf_skip_const/24 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 4, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xfffffffe
         VR  ~[0, 0]
  Jump functions of caller  pbuf_copy_partial/22:
    callsite  pbuf_copy_partial/22 -> pbuf_copy_partial.part.0/52 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 3: PASS THROUGH: 3, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
  Jump functions of caller  pbuf_copy_partial_pbuf/21:
  Jump functions of caller  pbuf_copy/20:
    callsite  pbuf_copy/20 -> pbuf_copy_partial_pbuf/21 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: UNKNOWN
         value: 0x0, mask: 0xffff
         Unknown VR
       param 3: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  pbuf_dechain/19:
    callsite  pbuf_dechain/19 -> pbuf_free/14 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pbuf_chain/18:
    callsite  pbuf_chain/18 -> pbuf_ref/16 : 
       param 0: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pbuf_chain/18 -> pbuf_cat/17 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pbuf_cat/17:
    callsite  pbuf_cat/17 -> pbuf_cat.part.0/51 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pbuf_ref/16:
  Jump functions of caller  pbuf_clen/15:
  Jump functions of caller  pbuf_free/14:
    callsite  pbuf_free/14 -> pbuf_free.part.0/49 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pbuf_free_header/13:
    callsite  pbuf_free_header/13 -> pbuf_remove_header/9 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         VR  ~[0, 0]
       param 1: UNKNOWN
         value: 0x0, mask: 0xffff
         VR  [1, 65535]
    callsite  pbuf_free_header/13 -> pbuf_free/14 : 
       param 0: UNKNOWN
         Aggregate passed by reference:
           offset: 0, cst: 0B
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pbuf_header_force/12:
    callsite  pbuf_header_force/12 -> pbuf_header_impl/10 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
         Unknown VR
       param 2: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
  Jump functions of caller  pbuf_header/11:
    callsite  pbuf_header/11 -> pbuf_header_impl/10 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  pbuf_header_impl/10:
    callsite  pbuf_header_impl/10 -> pbuf_add_header_impl/6 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: UNKNOWN
         value: 0x0, mask: 0x7fff
         VR  [0, 32767]
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
    callsite  pbuf_header_impl/10 -> pbuf_header_impl.part.0/48 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff
         Unknown VR
  Jump functions of caller  pbuf_remove_header/9:
    callsite  pbuf_remove_header/9 -> pbuf_remove_header.part.0/47 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pbuf_add_header_force/8:
    callsite  pbuf_add_header_force/8 -> pbuf_add_header_impl/6 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: CONST: 1
         value: 0x1, mask: 0x0
         Unknown VR
  Jump functions of caller  pbuf_add_header/7:
    callsite  pbuf_add_header/7 -> pbuf_add_header_impl/6 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: CONST: 0
         value: 0x0, mask: 0x0
         Unknown VR
  Jump functions of caller  pbuf_add_header_impl/6:
    callsite  pbuf_add_header_impl/6 -> pbuf_add_header_impl.part.0/43 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xff
         Unknown VR
  Jump functions of caller  pbuf_realloc/5:
    callsite  pbuf_realloc/5 -> pbuf_free/14 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  pbuf_alloced_custom/4:
  Jump functions of caller  pbuf_alloc_reference/3:
    callsite  pbuf_alloc_reference/3 -> pbuf_alloc_reference.part.0/45 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
  Jump functions of caller  pbuf_alloc/2:
    callsite  pbuf_alloc/2 -> pbuf_free/14 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
    callsite  pbuf_alloc/2 -> pbuf_alloc_reference/3 : 
       param 0: CONST: 0B
         value: 0x0, mask: 0xfffffff8
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR
       param 2: PASS THROUGH: 2, op nop_expr
         value: 0x0, mask: 0xffff
         Unknown VR

 Propagating constants:

Not considering pbuf_strstr for cloning; -fipa-cp-clone disabled.
Not considering pbuf_memfind for cloning; -fipa-cp-clone disabled.
Not considering pbuf_memcmp for cloning; -fipa-cp-clone disabled.
Not considering pbuf_put_at for cloning; -fipa-cp-clone disabled.
Not considering pbuf_try_get_at for cloning; -fipa-cp-clone disabled.
Not considering pbuf_get_at for cloning; -fipa-cp-clone disabled.
Not considering pbuf_clone for cloning; -fipa-cp-clone disabled.
Not considering pbuf_coalesce for cloning; -fipa-cp-clone disabled.
Not considering pbuf_take_at for cloning; -fipa-cp-clone disabled.
Not considering pbuf_take for cloning; -fipa-cp-clone disabled.
Not considering pbuf_skip for cloning; -fipa-cp-clone disabled.
Not considering pbuf_get_contiguous for cloning; -fipa-cp-clone disabled.
Not considering pbuf_copy_partial for cloning; -fipa-cp-clone disabled.
Not considering pbuf_copy_partial_pbuf for cloning; -fipa-cp-clone disabled.
Not considering pbuf_copy for cloning; -fipa-cp-clone disabled.
Not considering pbuf_dechain for cloning; -fipa-cp-clone disabled.
Not considering pbuf_chain for cloning; -fipa-cp-clone disabled.
Not considering pbuf_cat for cloning; -fipa-cp-clone disabled.
Not considering pbuf_ref for cloning; -fipa-cp-clone disabled.
Not considering pbuf_clen for cloning; -fipa-cp-clone disabled.
Not considering pbuf_free for cloning; -fipa-cp-clone disabled.
Not considering pbuf_free_header for cloning; -fipa-cp-clone disabled.
Not considering pbuf_header_force for cloning; -fipa-cp-clone disabled.
Not considering pbuf_header for cloning; -fipa-cp-clone disabled.
Not considering pbuf_remove_header for cloning; -fipa-cp-clone disabled.
Not considering pbuf_add_header_force for cloning; -fipa-cp-clone disabled.
Not considering pbuf_add_header for cloning; -fipa-cp-clone disabled.
Not considering pbuf_realloc for cloning; -fipa-cp-clone disabled.
Not considering pbuf_alloced_custom for cloning; -fipa-cp-clone disabled.
Not considering pbuf_alloc_reference for cloning; -fipa-cp-clone disabled.
Not considering pbuf_alloc for cloning; -fipa-cp-clone disabled.

overall_size: 869, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: pbuf_memcmp.part.0/55:
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
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pbuf_copy_partial.part.0/52:
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
    param [3]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pbuf_cat.part.0/51:
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
  Node: pbuf_free.part.0/49:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: pbuf_header_impl.part.0/48:
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
  Node: pbuf_remove_header.part.0/47:
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
  Node: pbuf_alloc_reference.part.0/45:
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
  Node: pbuf_add_header_impl.part.0/43:
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
    param [2]: 0 [loc_time: 1, loc_size: 21, prop_time: 0, prop_size: 0]
               1 [loc_time: 1, loc_size: 24, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x1, mask = 0x1
         u8_t [0, 1]
        AGGS VARIABLE
  Node: pbuf_strstr/35:
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
  Node: pbuf_memfind/34:
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
  Node: pbuf_memcmp/33:
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
  Node: pbuf_put_at/32:
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
  Node: pbuf_try_get_at/31:
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
  Node: pbuf_get_at/30:
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
  Node: pbuf_clone/29:
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
  Node: pbuf_coalesce/28:
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
  Node: pbuf_take_at/27:
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
  Node: pbuf_take/26:
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
  Node: pbuf_skip/25:
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
  Node: pbuf_skip_const/24:
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
  Node: pbuf_get_contiguous/23:
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
  Node: pbuf_copy_partial/22:
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
  Node: pbuf_copy_partial_pbuf/21:
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
  Node: pbuf_copy/20:
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
  Node: pbuf_dechain/19:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pbuf_chain/18:
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
  Node: pbuf_cat/17:
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
  Node: pbuf_ref/16:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pbuf_clen/15:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pbuf_free/14:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: pbuf_free_header/13:
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
  Node: pbuf_header_force/12:
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
  Node: pbuf_header/11:
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
  Node: pbuf_header_impl/10:
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
    param [2]: 0 [loc_time: 1, loc_size: 14, prop_time: 0, prop_size: 0]
               1 [loc_time: 1, loc_size: 14, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x1, mask = 0x1
         u8_t [0, 1]
        AGGS VARIABLE
  Node: pbuf_remove_header/9:
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
  Node: pbuf_add_header_force/8:
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
  Node: pbuf_add_header/7:
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
  Node: pbuf_add_header_impl/6:
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
    param [2]: 1 [loc_time: 1, loc_size: 16, prop_time: 0, prop_size: 0]
               0 [loc_time: 1, loc_size: 16, prop_time: 0, prop_size: 0]
         ctxs: VARIABLE
         Bits: value = 0x1, mask = 0x1
         u8_t [0, 1]
        AGGS VARIABLE
  Node: pbuf_realloc/5:
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
  Node: pbuf_alloced_custom/4:
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
  Node: pbuf_alloc_reference/3:
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
  Node: pbuf_alloc/2:
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

Propagated bits info for function pbuf_add_header_impl.part.0/43:
 param 2: value = 0x1, mask = 0x1
Propagated bits info for function pbuf_header_impl/10:
 param 2: value = 0x1, mask = 0x1
Propagated bits info for function pbuf_add_header_impl/6:
 param 2: value = 0x1, mask = 0x1

IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

pbuf_memcmp.part.0/55 (pbuf_memcmp.part.0) @063bdc40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:114863532 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: pbuf_memcmp/33 (114863532 (estimated locally),0.78 per call) 
  Calls: pbuf_get_at/30 (1014686020 (estimated locally),8.83 per call) 
pbuf_copy_partial.part.0/52 (pbuf_copy_partial.part.0) @061b4000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:114863532 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: pbuf_copy_partial/22 (114863532 (estimated locally),0.67 per call) 
  Calls: memcpy/41 (637654064 (estimated locally),5.55 per call) 
pbuf_cat.part.0/51 (pbuf_cat.part.0) @063bd1c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:162688 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: pbuf_cat/17 (162688 (estimated locally),0.67 per call) 
  Calls: 
pbuf_free.part.0/49 (pbuf_free.part.0) @063acc40
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:406193 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: pbuf_free/14 (250539 (estimated locally),0.70 per call) 
  Calls: memp_free/39 (472427 (estimated locally),1.16 per call) memp_free/39 (376808 (estimated locally),0.93 per call) mem_free/40 (1452223 (estimated locally),3.58 per call) 
   Indirect call(2282775 (estimated locally),5.62 per call) 
pbuf_header_impl.part.0/48 (pbuf_header_impl.part.0) @063acee0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: pbuf_header_impl/10 (440234144 (estimated locally),0.41 per call) 
  Calls: pbuf_remove_header/9 (1073741824 (estimated locally),1.00 per call) 
pbuf_remove_header.part.0/47 (pbuf_remove_header.part.0) @063ac540
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: pbuf_remove_header/9 (109135 (estimated locally),0.30 per call) 
  Calls: 
pbuf_alloc_reference.part.0/45 (pbuf_alloc_reference.part.0) @06299e00
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: pbuf_alloc_reference/3 (96598 (estimated locally),0.47 per call) 
  Calls: memp_malloc/36 (1073741824 (estimated locally),1.00 per call) 
pbuf_add_header_impl.part.0/43 (pbuf_add_header_impl.part.0) @0603b8c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741823 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: pbuf_add_header_impl/6 (109135 (estimated locally),0.30 per call) 
  Calls: 
strlen/42 (strlen) @062718c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pbuf_strstr/35 (657280122 (estimated locally),0.61 per call) 
  Calls: 
memcpy/41 (memcpy) @06253a80
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pbuf_take_at/27 (107374 (estimated locally),0.49 per call) pbuf_take/26 (1844881 (estimated locally),8.19 per call) pbuf_copy_partial.part.0/52 (637654064 (estimated locally),5.55 per call) pbuf_copy_partial_pbuf/21 (5368700 (estimated locally),13.40 per call) 
  Calls: 
mem_free/40 (mem_free) @062531c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pbuf_free.part.0/49 (1452223 (estimated locally),3.58 per call) 
  Calls: 
memp_free/39 (memp_free) @062530e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pbuf_free.part.0/49 (472427 (estimated locally),1.16 per call) pbuf_free.part.0/49 (376808 (estimated locally),0.93 per call) 
  Calls: 
mem_trim/38 (mem_trim) @0621c620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pbuf_realloc/5 (9258 (estimated locally),0.03 per call) 
  Calls: 
mem_malloc/37 (mem_malloc) @0621c0e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pbuf_alloc/2 (62161 (estimated locally),0.14 per call) 
  Calls: 
memp_malloc/36 (memp_malloc) @0621c000
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: pbuf_alloc/2 (1003730 (estimated locally),2.34 per call) pbuf_alloc_reference.part.0/45 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pbuf_strstr/35 (pbuf_strstr) @061fbee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pbuf_memfind/34 (420462094 (estimated locally),0.39 per call) strlen/42 (657280122 (estimated locally),0.61 per call) 
pbuf_memfind/34 (pbuf_memfind) @061fbc40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:176713126 (estimated locally) body optimize_size
  Called by: pbuf_strstr/35 (420462094 (estimated locally),0.39 per call) 
  Calls: pbuf_memcmp/33 (1014686024 (estimated locally),5.74 per call) 
pbuf_memcmp/33 (pbuf_memcmp) @061fb9a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:146734200 (estimated locally) body optimize_size
  Called by: pbuf_memfind/34 (1014686024 (estimated locally),5.74 per call) 
  Calls: pbuf_memcmp.part.0/55 (114863532 (estimated locally),0.78 per call) 
pbuf_put_at/32 (pbuf_put_at) @061fb700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: 
  Calls: pbuf_skip_const/24 (1073741823 (estimated locally),1.00 per call) 
pbuf_try_get_at/31 (pbuf_try_get_at) @061fb460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pbuf_get_at/30 (1073741824 (estimated locally),1.00 per call) 
  Calls: pbuf_skip_const/24 (1073741824 (estimated locally),1.00 per call) 
pbuf_get_at/30 (pbuf_get_at) @061fb1c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pbuf_memcmp.part.0/55 (1014686020 (estimated locally),8.83 per call) 
  Calls: pbuf_try_get_at/31 (1073741824 (estimated locally),1.00 per call) 
pbuf_clone/29 (pbuf_clone) @061eec40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:254049 (estimated locally) body optimize_size
  Called by: pbuf_coalesce/28 (741418730 (estimated locally),0.69 per call) 
  Calls: pbuf_copy/20 (214748 (estimated locally),0.85 per call) pbuf_alloc/2 (254049 (estimated locally),1.00 per call) 
pbuf_coalesce/28 (pbuf_coalesce) @061ee2a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pbuf_free/14 (511949632 (estimated locally),0.48 per call) pbuf_clone/29 (741418730 (estimated locally),0.69 per call) 
pbuf_take_at/27 (pbuf_take_at) @061eeee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:221054 (estimated locally) body optimize_size
  Called by: 
  Calls: pbuf_take/26 (35433 (estimated locally),0.16 per call) memcpy/41 (107374 (estimated locally),0.49 per call) pbuf_skip_const/24 (221054 (estimated locally),1.00 per call) 
pbuf_take/26 (pbuf_take) @061eeb60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:225343 (estimated locally) body optimize_size
  Called by: pbuf_take_at/27 (35433 (estimated locally),0.16 per call) 
  Calls: memcpy/41 (1844881 (estimated locally),8.19 per call) 
pbuf_skip/25 (pbuf_skip) @061ee7e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pbuf_skip_const/24 (1073741824 (estimated locally),1.00 per call) 
pbuf_skip_const/24 (pbuf_skip_const) @061ee460
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:114863532 (estimated locally) body local optimize_size
  Called by: pbuf_put_at/32 (1073741823 (estimated locally),1.00 per call) pbuf_try_get_at/31 (1073741824 (estimated locally),1.00 per call) pbuf_take_at/27 (221054 (estimated locally),1.00 per call) pbuf_skip/25 (1073741824 (estimated locally),1.00 per call) pbuf_get_contiguous/23 (633074433 (estimated locally),0.59 per call) 
  Calls: 
pbuf_get_contiguous/23 (pbuf_get_contiguous) @061ee1c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pbuf_copy_partial/22 (263339212 (estimated locally),0.25 per call) pbuf_skip_const/24 (633074433 (estimated locally),0.59 per call) 
pbuf_copy_partial/22 (pbuf_copy_partial) @061dce00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:171201796 (estimated locally) body optimize_size
  Called by: pbuf_get_contiguous/23 (263339212 (estimated locally),0.25 per call) 
  Calls: pbuf_copy_partial.part.0/52 (114863532 (estimated locally),0.67 per call) 
pbuf_copy_partial_pbuf/21 (pbuf_copy_partial_pbuf) @061dc8c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:400722 (estimated locally) body optimize_size
  Called by: pbuf_copy/20 (1063970774 (estimated locally),0.99 per call) 
  Calls: memcpy/41 (5368700 (estimated locally),13.40 per call) 
pbuf_copy/20 (pbuf_copy) @061dc0e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: pbuf_clone/29 (214748 (estimated locally),0.85 per call) 
  Calls: pbuf_copy_partial_pbuf/21 (1063970774 (estimated locally),0.99 per call) 
pbuf_dechain/19 (pbuf_dechain) @061dcd20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:192316 (estimated locally) body optimize_size
  Called by: 
  Calls: pbuf_free/14 (27247 (estimated locally),0.14 per call) 
pbuf_chain/18 (pbuf_chain) @061dca80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pbuf_ref/16 (1073741824 (estimated locally),1.00 per call) pbuf_cat/17 (1073741824 (estimated locally),1.00 per call) 
pbuf_cat/17 (pbuf_cat) @061dc7e0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:242483 (estimated locally) body optimize_size
  Called by: pbuf_chain/18 (1073741824 (estimated locally),1.00 per call) 
  Calls: pbuf_cat.part.0/51 (162688 (estimated locally),0.67 per call) 
pbuf_ref/16 (pbuf_ref) @061dc540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:306783 (estimated locally) body optimize_size
  Called by: pbuf_chain/18 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
pbuf_clen/15 (pbuf_clen) @061dc2a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:118111600 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pbuf_free/14 (pbuf_free) @061dc000
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: pbuf_coalesce/28 (511949632 (estimated locally),0.48 per call) pbuf_dechain/19 (27247 (estimated locally),0.14 per call) pbuf_free_header/13 (960107354 (estimated locally),8.45 per call) pbuf_realloc/5 (43973 (estimated locally),0.12 per call) pbuf_alloc/2 (29518 (estimated locally),0.07 per call) 
  Calls: pbuf_free.part.0/49 (250539 (estimated locally),0.70 per call) 
pbuf_free_header/13 (pbuf_free_header) @061d12a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:113634470 (estimated locally) body optimize_size
  Called by: 
  Calls: pbuf_remove_header/9 (36474911 (estimated locally),0.32 per call) pbuf_free/14 (960107354 (estimated locally),8.45 per call) 
pbuf_header_force/12 (pbuf_header_force) @061d1ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pbuf_header_impl/10 (1073741824 (estimated locally),1.00 per call) 
pbuf_header/11 (pbuf_header) @061d1c40
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pbuf_header_impl/10 (1073741824 (estimated locally),1.00 per call) 
pbuf_header_impl/10 (pbuf_header_impl) @061d19a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) body local optimize_size
  Called by: pbuf_header_force/12 (1073741824 (estimated locally),1.00 per call) pbuf_header/11 (1073741824 (estimated locally),1.00 per call) 
  Calls: pbuf_add_header_impl/6 (633507677 (estimated locally),0.59 per call) pbuf_header_impl.part.0/48 (440234144 (estimated locally),0.41 per call) 
pbuf_remove_header/9 (pbuf_remove_header) @061d1700
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: pbuf_free_header/13 (36474911 (estimated locally),0.32 per call) pbuf_header_impl.part.0/48 (1073741824 (estimated locally),1.00 per call) 
  Calls: pbuf_remove_header.part.0/47 (109135 (estimated locally),0.30 per call) 
pbuf_add_header_force/8 (pbuf_add_header_force) @061d1460
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pbuf_add_header_impl/6 (1073741824 (estimated locally),1.00 per call) 
pbuf_add_header/7 (pbuf_add_header) @061d11c0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: pbuf_add_header_impl/6 (1073741824 (estimated locally),1.00 per call) 
pbuf_add_header_impl/6 (pbuf_add_header_impl) @061c1b60
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:357913 (estimated locally) body local optimize_size
  Called by: pbuf_header_impl/10 (633507677 (estimated locally),0.59 per call) pbuf_add_header_force/8 (1073741824 (estimated locally),1.00 per call) pbuf_add_header/7 (1073741824 (estimated locally),1.00 per call) 
  Calls: pbuf_add_header_impl.part.0/43 (109135 (estimated locally),0.30 per call) 
pbuf_realloc/5 (pbuf_realloc) @061c1e00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: 
  Calls: pbuf_free/14 (43973 (estimated locally),0.12 per call) mem_trim/38 (9258 (estimated locally),0.03 per call) 
pbuf_alloced_custom/4 (pbuf_alloced_custom) @061c1a80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: 
pbuf_alloc_reference/3 (pbuf_alloc_reference) @061c1620
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:203972 (estimated locally) body optimize_size
  Called by: pbuf_alloc/2 (107374 (estimated locally),0.25 per call) 
  Calls: pbuf_alloc_reference.part.0/45 (96598 (estimated locally),0.47 per call) 
pbuf_alloc/2 (pbuf_alloc) @061c1380
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:429496 (estimated locally) body optimize_size
  Called by: pbuf_clone/29 (254049 (estimated locally),1.00 per call) 
  Calls: mem_malloc/37 (62161 (estimated locally),0.14 per call) pbuf_free/14 (29518 (estimated locally),0.07 per call) memp_malloc/36 (1003730 (estimated locally),2.34 per call) pbuf_alloc_reference/3 (107374 (estimated locally),0.25 per call) 

;; Function pbuf_skip_const (pbuf_skip_const, funcdef_no=24, decl_uid=6907, cgraph_uid=25, symbol_order=24)

Modification phase of node pbuf_skip_const/24
pbuf_skip_const (const struct pbuf * in, u16_t in_offset, u16_t * out_offset)
{
  const struct pbuf * q;
  u16_t offset_left;
  short unsigned int _2;

  <bb 2> [local count: 114863532]:
  # DEBUG BEGIN_STMT
  # DEBUG offset_left => in_offset_6(D)
  # DEBUG BEGIN_STMT
  # DEBUG q => in_7(D)
  # DEBUG BEGIN_STMT
  goto <bb 4>; [100.00%]

  <bb 3> [local count: 958878293]:
  # DEBUG BEGIN_STMT
  offset_left_9 = offset_left_3 - _2;
  # DEBUG offset_left => offset_left_9
  # DEBUG BEGIN_STMT
  q_10 = q_4->next;
  # DEBUG q => q_10

  <bb 4> [local count: 1073741824]:
  # offset_left_3 = PHI <in_offset_6(D)(2), offset_left_9(3)>
  # q_4 = PHI <in_7(D)(2), q_10(3)>
  # DEBUG q => q_4
  # DEBUG offset_left => offset_left_3
  # DEBUG BEGIN_STMT
  if (q_4 != 0B)
    goto <bb 5>; [94.50%]
  else
    goto <bb 6>; [5.50%]

  <bb 5> [local count: 1014686025]:
  _2 = q_4->len;
  if (_2 <= offset_left_3)
    goto <bb 3>; [94.50%]
  else
    goto <bb 6>; [5.50%]

  <bb 6> [local count: 114863532]:
  # offset_left_1 = PHI <offset_left_3(4), offset_left_3(5)>
  # q_13 = PHI <q_4(4), q_4(5)>
  # DEBUG BEGIN_STMT
  if (out_offset_11(D) != 0B)
    goto <bb 7>; [70.00%]
  else
    goto <bb 8>; [30.00%]

  <bb 7> [local count: 80404472]:
  # DEBUG BEGIN_STMT
  *out_offset_11(D) = offset_left_1;

  <bb 8> [local count: 114863532]:
  # DEBUG BEGIN_STMT
  return q_13;

}



;; Function pbuf_add_header_impl (pbuf_add_header_impl, funcdef_no=6, decl_uid=6974, cgraph_uid=7, symbol_order=6)

Modification phase of node pbuf_add_header_impl/6
Adjusting mask for param 2 to 0x1
Setting value range of param 2 [0, 1]
pbuf_add_header_impl (struct pbuf * p, size_t header_size_increment, u8_t force)
{
  u8_t _2;
  unsigned char _7;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (p_4(D) == 0B)
    goto <bb 8>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 8> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 9> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (header_size_increment_6(D) > 65535)
    goto <bb 7>; [34.00%]
  else
    goto <bb 5>; [66.00%]

  <bb 5> [local count: 165356]:
  # DEBUG BEGIN_STMT
  if (header_size_increment_6(D) == 0)
    goto <bb 7>; [34.00%]
  else
    goto <bb 6>; [66.00%]

  <bb 6> [local count: 109135]:
  _7 = pbuf_add_header_impl.part.0 (p_4(D), header_size_increment_6(D), force_8(D));

  <bb 7> [local count: 250539]:
  # _2 = PHI <1(4), 0(5), _7(6)>
  return _2;

}



;; Function pbuf_alloc_reference (pbuf_alloc_reference, funcdef_no=3, decl_uid=6272, cgraph_uid=4, symbol_order=3)

Modification phase of node pbuf_alloc_reference/3
pbuf_alloc_reference (void * payload, u16_t length, pbuf_type type)
{
  struct pbuf * _7;

  <bb 2> [local count: 203972]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (type_2(D) != 65)
    goto <bb 3>; [79.76%]
  else
    goto <bb 5>; [20.24%]

  <bb 3> [local count: 162688]:
  if (type_2(D) != 1)
    goto <bb 6>; [66.00%]
  else
    goto <bb 5>; [34.00%]

  <bb 6> [local count: 107374]:

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 7> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 96598]:
  _7 = pbuf_alloc_reference.part.0 (payload_5(D), length_6(D), type_2(D));
  return _7;

}



;; Function pbuf_alloced_custom (pbuf_alloced_custom, funcdef_no=4, decl_uid=6279, cgraph_uid=5, symbol_order=4)

Modification phase of node pbuf_alloced_custom/4
pbuf_alloced_custom (pbuf_layer l, u16_t length, pbuf_type type, struct pbuf_custom * p, void * payload_mem, u16_t payload_mem_len)
{
  void * payload;
  unsigned int _1;
  unsigned int _2;
  unsigned int _3;
  unsigned int _4;
  unsigned int _5;
  unsigned int _6;
  struct pbuf * _7;
  struct pbuf * _9;
  unsigned char _19;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG offset => (u16_t) l_11(D)
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (unsigned int) l_11(D);
  _2 = _1 + 15;
  _3 = _2 & 4294967280;
  _4 = (unsigned int) length_12(D);
  _5 = _3 + _4;
  _6 = (unsigned int) payload_mem_len_13(D);
  if (_5 > _6)
    goto <bb 6>; [17.38%]
  else
    goto <bb 3>; [82.62%]

  <bb 3> [local count: 887125496]:
  # DEBUG BEGIN_STMT
  if (payload_mem_14(D) != 0B)
    goto <bb 4>; [70.00%]
  else
    goto <bb 5>; [30.00%]

  <bb 4> [local count: 620987848]:
  # DEBUG BEGIN_STMT
  payload_15 = payload_mem_14(D) + _3;
  # DEBUG payload => payload_15

  <bb 5> [local count: 887125496]:
  # payload_8 = PHI <payload_15(4), 0B(3)>
  # DEBUG payload => payload_8
  # DEBUG BEGIN_STMT
  _7 = &p_16(D)->pbuf;
  # DEBUG p => _7
  # DEBUG payload => payload_8
  # DEBUG tot_len => length_12(D)
  # DEBUG len => length_12(D)
  # DEBUG type => type_18(D)
  # DEBUG flags => 2
  # DEBUG INLINE_ENTRY pbuf_init_alloced_pbuf
  # DEBUG BEGIN_STMT
  MEM[(struct pbuf *)p_16(D)].next = 0B;
  # DEBUG BEGIN_STMT
  MEM[(struct pbuf *)p_16(D)].payload = payload_8;
  # DEBUG BEGIN_STMT
  MEM[(struct pbuf *)p_16(D)].tot_len = length_12(D);
  # DEBUG BEGIN_STMT
  MEM[(struct pbuf *)p_16(D)].len = length_12(D);
  # DEBUG BEGIN_STMT
  _19 = (unsigned char) type_18(D);
  MEM[(struct pbuf *)p_16(D)].type_internal = _19;
  # DEBUG BEGIN_STMT
  MEM[(struct pbuf *)p_16(D)].flags = 2;
  # DEBUG BEGIN_STMT
  MEM[(struct pbuf *)p_16(D)].ref = 1;
  # DEBUG BEGIN_STMT
  MEM[(struct pbuf *)p_16(D)].if_idx = 0;
  # DEBUG p => NULL
  # DEBUG payload => NULL
  # DEBUG tot_len => NULL
  # DEBUG len => NULL
  # DEBUG type => NULL
  # DEBUG flags => NULL
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
  # _9 = PHI <0B(2), _7(5)>
  return _9;

}



;; Function pbuf_add_header (pbuf_add_header, funcdef_no=7, decl_uid=6291, cgraph_uid=8, symbol_order=7)

Modification phase of node pbuf_add_header/7
pbuf_add_header (struct pbuf * p, size_t header_size_increment)
{
  u8_t _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _5 = pbuf_add_header_impl (p_2(D), header_size_increment_3(D), 0);
  return _5;

}



;; Function pbuf_add_header_force (pbuf_add_header_force, funcdef_no=8, decl_uid=6294, cgraph_uid=9, symbol_order=8)

Modification phase of node pbuf_add_header_force/8
pbuf_add_header_force (struct pbuf * p, size_t header_size_increment)
{
  u8_t _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _5 = pbuf_add_header_impl (p_2(D), header_size_increment_3(D), 1);
  return _5;

}



;; Function pbuf_remove_header (pbuf_remove_header, funcdef_no=9, decl_uid=6297, cgraph_uid=10, symbol_order=9)

Modification phase of node pbuf_remove_header/9
pbuf_remove_header (struct pbuf * p, size_t header_size_decrement)
{
  unsigned char _1;
  u8_t _3;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (p_5(D) == 0B)
    goto <bb 8>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 8> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 9> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (header_size_decrement_7(D) > 65535)
    goto <bb 7>; [34.00%]
  else
    goto <bb 5>; [66.00%]

  <bb 5> [local count: 165356]:
  # DEBUG BEGIN_STMT
  if (header_size_decrement_7(D) == 0)
    goto <bb 7>; [34.00%]
  else
    goto <bb 6>; [66.00%]

  <bb 6> [local count: 109135]:
  _1 = pbuf_remove_header.part.0 (p_5(D), header_size_decrement_7(D));

  <bb 7> [local count: 250539]:
  # _3 = PHI <1(4), 0(5), _1(6)>
  return _3;

}



;; Function pbuf_header (pbuf_header, funcdef_no=11, decl_uid=6285, cgraph_uid=12, symbol_order=11)

Modification phase of node pbuf_header/11
pbuf_header (struct pbuf * p, s16_t header_size_increment)
{
  u8_t _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _5 = pbuf_header_impl (p_2(D), header_size_increment_3(D), 0);
  return _5;

}



;; Function pbuf_header_force (pbuf_header_force, funcdef_no=12, decl_uid=6288, cgraph_uid=13, symbol_order=12)

Modification phase of node pbuf_header_force/12
pbuf_header_force (struct pbuf * p, s16_t header_size_increment)
{
  u8_t _5;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  _5 = pbuf_header_impl (p_2(D), header_size_increment_3(D), 1);
  return _5;

}



;; Function pbuf_free (pbuf_free, funcdef_no=14, decl_uid=6304, cgraph_uid=15, symbol_order=14)

Modification phase of node pbuf_free/14
pbuf_free (struct pbuf * p)
{
  u8_t count;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (p_7(D) == 0B)
    goto <bb 5>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 5> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 250539]:
  # p_3 = PHI <p_7(D)(2)>
  # count_4 = PHI <0(2)>
  count_1 = pbuf_free.part.0 (p_7(D));
  # DEBUG count => NULL
  # DEBUG p => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  return count_1;

}



;; Function pbuf_alloc (pbuf_alloc, funcdef_no=2, decl_uid=6268, cgraph_uid=3, symbol_order=2)

Modification phase of node pbuf_alloc/2
pbuf_alloc (pbuf_layer layer, u16_t length, pbuf_type type)
{
  mem_size_t alloc_len;
  mem_size_t payload_len;
  u16_t qlen;
  u16_t rem_len;
  struct pbuf * last;
  struct pbuf * q;
  u16_t offset;
  struct pbuf * p;
  short unsigned int _1;
  short unsigned int _2;
  short unsigned int _3;
  sizetype _4;
  sizetype _5;
  void * _6;
  unsigned int _7;
  unsigned int _8;
  unsigned int _9;
  void * _10;
  unsigned int _11;
  unsigned int _12;
  unsigned int _13;
  unsigned int _14;
  unsigned int _15;
  unsigned int _16;
  sizetype _17;
  void * _18;
  unsigned int _19;
  unsigned int _20;
  unsigned int _21;
  void * _22;
  struct pbuf * _28;
  unsigned char _53;
  unsigned char _54;

  <bb 2> [local count: 429496]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  offset_36 = (u16_t) layer_35(D);
  # DEBUG offset => offset_36
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  switch (type_37(D)) <default: <L41> [25.00%], case 1: <L0> [25.00%], case 65: <L0> [25.00%], case 386: <L42> [25.00%], case 640: <L18> [25.00%]>

  <bb 17> [local count: 107374]:
<L41>:
  goto <bb 15>; [100.00%]

  <bb 3> [local count: 107374]:
<L0>:
  # DEBUG BEGIN_STMT
  p_51 = pbuf_alloc_reference (0B, length_39(D), type_37(D));
  # DEBUG p => p_51
  # DEBUG BEGIN_STMT
  goto <bb 16>; [100.00%]

  <bb 18> [local count: 107374]:
<L42>:

  <bb 4> [local count: 1003730]:
  # p_23 = PHI <0B(18), p_24(20)>
  # offset_25 = PHI <offset_36(18), 0(20)>
  # last_26 = PHI <0B(18), q_45(20)>
  # rem_len_27 = PHI <length_39(D)(18), rem_len_48(20)>
<L34>:
  # DEBUG rem_len => rem_len_27
  # DEBUG last => last_26
  # DEBUG offset => offset_25
  # DEBUG p => p_23
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  q_45 = memp_malloc (14);
  # DEBUG q => q_45
  # DEBUG BEGIN_STMT
  if (q_45 == 0B)
    goto <bb 5>; [5.50%]
  else
    goto <bb 8>; [94.50%]

  <bb 5> [local count: 55205]:
  # p_32 = PHI <p_23(4)>
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (p_32 != 0B)
    goto <bb 6>; [53.47%]
  else
    goto <bb 7>; [46.53%]

  <bb 6> [local count: 29518]:
  # DEBUG BEGIN_STMT
  pbuf_free (p_32);

  <bb 7> [local count: 55205]:
  # DEBUG BEGIN_STMT
  goto <bb 16>; [100.00%]

  <bb 8> [local count: 948525]:
  # DEBUG BEGIN_STMT
  _1 = offset_25 + 15;
  _2 = _1 & 65520;
  _3 = 1536 - _2;
  qlen_46 = MIN_EXPR <_3, rem_len_27>;
  # DEBUG qlen => qlen_46
  # DEBUG BEGIN_STMT
  _4 = (sizetype) offset_25;
  _5 = _4 + 32;
  _6 = q_45 + _5;
  _7 = (unsigned int) _6;
  _8 = _7 + 15;
  _9 = _8 & 4294967280;
  _10 = (void *) _9;
  # DEBUG p => q_45
  # DEBUG payload => _10
  # DEBUG tot_len => rem_len_27
  # DEBUG len => qlen_46
  # DEBUG type => type_37(D)
  # DEBUG flags => 0
  # DEBUG INLINE_ENTRY pbuf_init_alloced_pbuf
  # DEBUG BEGIN_STMT
  q_45->next = 0B;
  # DEBUG BEGIN_STMT
  q_45->payload = _10;
  # DEBUG BEGIN_STMT
  q_45->tot_len = rem_len_27;
  # DEBUG BEGIN_STMT
  q_45->len = qlen_46;
  # DEBUG BEGIN_STMT
  _53 = (unsigned char) type_37(D);
  q_45->type_internal = _53;
  # DEBUG BEGIN_STMT
  q_45->flags = 0;
  # DEBUG BEGIN_STMT
  q_45->ref = 1;
  # DEBUG BEGIN_STMT
  q_45->if_idx = 0;
  # DEBUG p => NULL
  # DEBUG payload => NULL
  # DEBUG tot_len => NULL
  # DEBUG len => NULL
  # DEBUG type => NULL
  # DEBUG flags => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (p_23 == 0B)
    goto <bb 10>; [30.00%]
  else
    goto <bb 9>; [70.00%]

  <bb 9> [local count: 663967]:
  # DEBUG BEGIN_STMT
  last_26->next = q_45;

  <bb 10> [local count: 948525]:
  # p_24 = PHI <q_45(8), p_23(9)>
  # DEBUG p => p_24
  # DEBUG BEGIN_STMT
  # DEBUG last => q_45
  # DEBUG BEGIN_STMT
  rem_len_48 = rem_len_27 - qlen_46;
  # DEBUG rem_len => rem_len_48
  # DEBUG BEGIN_STMT
  # DEBUG offset => 0
  # DEBUG BEGIN_STMT
  if (rem_len_48 != 0)
    goto <bb 20>; [94.50%]
  else
    goto <bb 16>; [5.50%]

  <bb 20> [local count: 896356]:
  goto <bb 4>; [100.00%]

  <bb 11> [local count: 107374]:
<L18>:
  # DEBUG BEGIN_STMT
  _11 = (unsigned int) layer_35(D);
  _12 = _11 + 15;
  _13 = _12 & 4294967280;
  _14 = (unsigned int) length_39(D);
  _15 = _14 + 15;
  _16 = _15 & 4294967280;
  payload_len_40 = _13 + _16;
  # DEBUG payload_len => payload_len_40
  # DEBUG BEGIN_STMT
  alloc_len_41 = payload_len_40 + 32;
  # DEBUG alloc_len => alloc_len_41
  # DEBUG BEGIN_STMT
  if (_16 > payload_len_40)
    goto <bb 16>; [17.38%]
  else
    goto <bb 12>; [82.62%]

  <bb 12> [local count: 88712]:
  if (_16 > alloc_len_41)
    goto <bb 16>; [29.93%]
  else
    goto <bb 13>; [70.07%]

  <bb 13> [local count: 62161]:
  # DEBUG BEGIN_STMT
  p_43 = mem_malloc (alloc_len_41);
  # DEBUG p => p_43
  # DEBUG BEGIN_STMT
  if (p_43 == 0B)
    goto <bb 16>; [8.27%]
  else
    goto <bb 14>; [91.73%]

  <bb 14> [local count: 57020]:
  # DEBUG BEGIN_STMT
  _17 = _11 + 32;
  _18 = p_43 + _17;
  _19 = (unsigned int) _18;
  _20 = _19 + 15;
  _21 = _20 & 4294967280;
  _22 = (void *) _21;
  # DEBUG p => p_43
  # DEBUG payload => _22
  # DEBUG tot_len => length_39(D)
  # DEBUG len => length_39(D)
  # DEBUG type => type_37(D)
  # DEBUG flags => 0
  # DEBUG INLINE_ENTRY pbuf_init_alloced_pbuf
  # DEBUG BEGIN_STMT
  p_43->next = 0B;
  # DEBUG BEGIN_STMT
  p_43->payload = _22;
  # DEBUG BEGIN_STMT
  p_43->tot_len = length_39(D);
  # DEBUG BEGIN_STMT
  p_43->len = length_39(D);
  # DEBUG BEGIN_STMT
  _54 = (unsigned char) type_37(D);
  p_43->type_internal = _54;
  # DEBUG BEGIN_STMT
  p_43->flags = 0;
  # DEBUG BEGIN_STMT
  p_43->ref = 1;
  # DEBUG BEGIN_STMT
  p_43->if_idx = 0;
  # DEBUG p => NULL
  # DEBUG payload => NULL
  # DEBUG tot_len => NULL
  # DEBUG len => NULL
  # DEBUG type => NULL
  # DEBUG flags => NULL
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 16>; [100.00%]

  <bb 19> [local count: 1073741824]:

  <bb 15> [local count: 1073741824]:
<L33>:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT
  goto <bb 19>; [100.00%]

  <bb 16> [local count: 322122]:
  # _28 = PHI <0B(7), 0B(12), 0B(13), p_24(10), p_51(3), p_43(14), 0B(11)>
  # DEBUG p => NULL
  return _28;

}



;; Function pbuf_realloc (pbuf_realloc, funcdef_no=5, decl_uid=6282, cgraph_uid=6, symbol_order=5)

Modification phase of node pbuf_realloc/5
pbuf_realloc (struct pbuf * p, u16_t new_len)
{
  u16_t rem_len;
  struct pbuf * q;
  short unsigned int _1;
  short unsigned int _2;
  short unsigned int _3;
  short unsigned int _4;
  short unsigned int _5;
  unsigned char _6;
  unsigned char _8;
  void * _9;
  int _10;
  int _11;
  int _12;
  long unsigned int _13;
  struct pbuf * _15;
  unsigned char _29;
  unsigned char _30;
  short unsigned int _43;

  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (p_26(D) == 0B)
    goto <bb 17>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 17> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 21> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = p_26(D)->tot_len;
  if (_1 <= new_len_28(D))
    goto <bb 16>; [34.00%]
  else
    goto <bb 20>; [66.00%]

  <bb 5> [local count: 1460728]:
  # DEBUG BEGIN_STMT
  rem_len_38 = rem_len_18 - _5;
  # DEBUG rem_len => rem_len_38
  # DEBUG BEGIN_STMT
  _3 = q_16->tot_len;
  _43 = new_len_28(D) - _1;
  _4 = _3 + _43;
  q_16->tot_len = _4;
  # DEBUG BEGIN_STMT
  q_40 = q_16->next;
  # DEBUG q => q_40
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (q_40 == 0B)
    goto <bb 18>; [5.50%]
  else
    goto <bb 24>; [94.50%]

  <bb 24> [local count: 1380388]:
  goto <bb 7>; [100.00%]

  <bb 18> [local count: 80340]:

  <bb 6> [local count: 803401787]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 22> [local count: 803401787]:
  goto <bb 6>; [100.00%]

  <bb 20> [local count: 165356]:

  <bb 7> [local count: 1545744]:
  # q_16 = PHI <p_26(D)(20), q_40(24)>
  # rem_len_18 = PHI <new_len_28(D)(20), rem_len_38(24)>
  # DEBUG shrink => NULL
  # DEBUG rem_len => NULL
  # DEBUG q => NULL
  # DEBUG rem_len => rem_len_18
  # DEBUG q => q_16
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _5 = q_16->len;
  if (_5 < rem_len_18)
    goto <bb 5>; [94.50%]
  else
    goto <bb 8>; [5.50%]

  <bb 8> [local count: 85016]:
  # _2 = PHI <_5(7)>
  # q_7 = PHI <q_16(7)>
  # rem_len_14 = PHI <rem_len_18(7)>
  # DEBUG BEGIN_STMT
  _6 = q_7->type_internal;
  _29 = _6 & 15;
  if (_29 == 0)
    goto <bb 9>; [50.00%]
  else
    goto <bb 13>; [50.00%]

  <bb 9> [local count: 42508]:
  if (_2 != rem_len_14)
    goto <bb 10>; [66.00%]
  else
    goto <bb 13>; [34.00%]

  <bb 10> [local count: 28055]:
  _8 = q_7->flags;
  _30 = _8 & 2;
  if (_30 == 0)
    goto <bb 11>; [33.00%]
  else
    goto <bb 13>; [67.00%]

  <bb 11> [local count: 9258]:
  # DEBUG BEGIN_STMT
  _9 = q_7->payload;
  _10 = _9 - q_7;
  _11 = (int) rem_len_14;
  _12 = _10 + _11;
  _13 = (long unsigned int) _12;
  q_32 = mem_trim (q_7, _13);
  # DEBUG q => q_32
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (q_32 == 0B)
    goto <bb 19>; [30.00%]
  else
    goto <bb 13>; [70.00%]

  <bb 19> [local count: 2777]:

  <bb 12> [local count: 27774747]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 23> [local count: 27774747]:
  goto <bb 12>; [100.00%]

  <bb 13> [local count: 82238]:
  # q_17 = PHI <q_7(8), q_7(9), q_7(10), q_32(11)>
  # DEBUG q => q_17
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  q_17->len = rem_len_14;
  # DEBUG BEGIN_STMT
  q_17->tot_len = rem_len_14;
  # DEBUG BEGIN_STMT
  _15 = q_17->next;
  if (_15 != 0B)
    goto <bb 14>; [53.47%]
  else
    goto <bb 15>; [46.53%]

  <bb 14> [local count: 43973]:
  # DEBUG BEGIN_STMT
  pbuf_free (_15);

  <bb 15> [local count: 82238]:
  # DEBUG BEGIN_STMT
  q_17->next = 0B;

  <bb 16> [local count: 167422]:
  return;

}



;; Function pbuf_free_header (pbuf_free_header, funcdef_no=13, decl_uid=6300, cgraph_uid=14, symbol_order=13)

Modification phase of node pbuf_free_header/13
pbuf_free_header (struct pbuf * q, u16_t size)
{
  u16_t free_left;
  struct pbuf * p;
  short unsigned int _1;
  unsigned int _3;

  <bb 2> [local count: 113634470]:
  # DEBUG BEGIN_STMT
  # DEBUG p => q_7(D)
  # DEBUG BEGIN_STMT
  # DEBUG free_left => size_8(D)
  # DEBUG BEGIN_STMT
  goto <bb 6>; [100.00%]

  <bb 3> [local count: 996582265]:
  # DEBUG BEGIN_STMT
  _1 = p_4->len;
  if (_1 <= free_left_5)
    goto <bb 4>; [96.34%]
  else
    goto <bb 5>; [3.66%]

  <bb 4> [local count: 960107354]:
  # DEBUG BEGIN_STMT
  # DEBUG f => p_4
  # DEBUG BEGIN_STMT
  free_left_12 = free_left_5 - _1;
  # DEBUG free_left => free_left_12
  # DEBUG BEGIN_STMT
  p_13 = p_4->next;
  # DEBUG p => p_13
  # DEBUG BEGIN_STMT
  p_4->next = 0B;
  # DEBUG BEGIN_STMT
  pbuf_free (p_4);
  goto <bb 6>; [100.00%]

  <bb 5> [local count: 36474911]:
  # p_11 = PHI <p_4(3)>
  # free_left_16 = PHI <free_left_5(3)>
  # DEBUG BEGIN_STMT
  _3 = (unsigned int) free_left_16;
  pbuf_remove_header (p_11, _3);
  # DEBUG BEGIN_STMT
  # DEBUG free_left => 0
  # DEBUG p => p_11
  # DEBUG BEGIN_STMT
  goto <bb 8>; [100.00%]

  <bb 6> [local count: 1073741824]:
  # p_4 = PHI <q_7(D)(2), p_13(4)>
  # free_left_5 = PHI <size_8(D)(2), free_left_12(4)>
  # DEBUG free_left => free_left_5
  # DEBUG p => p_4
  # DEBUG BEGIN_STMT
  if (free_left_5 != 0)
    goto <bb 7>; [96.34%]
  else
    goto <bb 8>; [3.66%]

  <bb 7> [local count: 1034442874]:
  if (p_4 != 0B)
    goto <bb 3>; [96.34%]
  else
    goto <bb 8>; [3.66%]

  <bb 8> [local count: 113634471]:
  # p_2 = PHI <p_4(6), p_4(7), p_11(5)>
  # DEBUG BEGIN_STMT
  return p_2;

}



;; Function pbuf_clen (pbuf_clen, funcdef_no=15, decl_uid=6306, cgraph_uid=16, symbol_order=15)

Modification phase of node pbuf_clen/15
pbuf_clen (const struct pbuf * p)
{
  u16_t len;

  <bb 2> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG len => 0
  # DEBUG BEGIN_STMT
  goto <bb 4>; [100.00%]

  <bb 3> [local count: 955630223]:
  # DEBUG BEGIN_STMT
  len_6 = len_2 + 1;
  # DEBUG len => len_6
  # DEBUG BEGIN_STMT
  p_7 = p_1->next;
  # DEBUG p => p_7

  <bb 4> [local count: 1073741824]:
  # p_1 = PHI <p_3(D)(2), p_7(3)>
  # len_2 = PHI <0(2), len_6(3)>
  # DEBUG len => len_2
  # DEBUG p => p_1
  # DEBUG BEGIN_STMT
  if (p_1 != 0B)
    goto <bb 3>; [89.00%]
  else
    goto <bb 5>; [11.00%]

  <bb 5> [local count: 118111601]:
  # len_4 = PHI <len_2(4)>
  # DEBUG BEGIN_STMT
  return len_4;

}



;; Function pbuf_ref (pbuf_ref, funcdef_no=16, decl_uid=6302, cgraph_uid=17, symbol_order=16)

Modification phase of node pbuf_ref/16
pbuf_ref (struct pbuf * p)
{
  unsigned char _1;
  unsigned char _2;

  <bb 2> [local count: 306783]:
  # DEBUG BEGIN_STMT
  if (p_5(D) != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 5>; [30.00%]

  <bb 3> [local count: 214748]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = p_5(D)->ref;
  _2 = _1 + 1;
  p_5(D)->ref = _2;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (_2 == 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 6> [local count: 107374]:

  <bb 4> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 7> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 199409]:
  # DEBUG BEGIN_STMT
  return;

}



;; Function pbuf_cat (pbuf_cat, funcdef_no=17, decl_uid=6309, cgraph_uid=18, symbol_order=17)

Modification phase of node pbuf_cat/17
pbuf_cat (struct pbuf * h, struct pbuf * t)
{
  struct pbuf * p;

  <bb 2> [local count: 242483]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (h_4(D) == 0B)
    goto <bb 5>; [18.09%]
  else
    goto <bb 3>; [81.91%]

  <bb 3> [local count: 198618]:
  if (t_5(D) == 0B)
    goto <bb 5>; [18.09%]
  else
    goto <bb 4>; [81.91%]

  <bb 4> [local count: 162688]:
  # p_2 = PHI <h_4(D)(3)>
  pbuf_cat.part.0 (h_4(D), t_5(D));

  <bb 5> [local count: 135109]:
  return;

}



;; Function pbuf_chain (pbuf_chain, funcdef_no=18, decl_uid=6312, cgraph_uid=19, symbol_order=18)

Modification phase of node pbuf_chain/18
pbuf_chain (struct pbuf * h, struct pbuf * t)
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  pbuf_cat (h_2(D), t_3(D));
  # DEBUG BEGIN_STMT
  pbuf_ref (t_3(D));
  # DEBUG BEGIN_STMT
  return;

}



;; Function pbuf_dechain (pbuf_dechain, funcdef_no=19, decl_uid=6314, cgraph_uid=20, symbol_order=19)

Modification phase of node pbuf_dechain/19
pbuf_dechain (struct pbuf * p)
{
  u8_t tail_gone;
  struct pbuf * q;
  short unsigned int _1;
  int _2;
  short unsigned int _3;
  int _4;
  short unsigned int _5;
  int _6;
  int _7;
  short unsigned int _8;
  short unsigned int _9;
  short unsigned int _10;
  struct pbuf * iftmp.1_12;

  <bb 2> [local count: 192316]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG tail_gone => 1
  # DEBUG BEGIN_STMT
  q_18 = p_17(D)->next;
  # DEBUG q => q_18
  # DEBUG BEGIN_STMT
  if (q_18 != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 6>; [30.00%]

  <bb 3> [local count: 134621]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = q_18->tot_len;
  _2 = (int) _1;
  _3 = p_17(D)->tot_len;
  _4 = (int) _3;
  _5 = p_17(D)->len;
  _6 = (int) _5;
  _7 = _4 - _6;
  if (_2 != _7)
    goto <bb 11>; [79.76%]
  else
    goto <bb 5>; [20.24%]

  <bb 11> [local count: 107374]:

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 13> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 27247]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _8 = _3 - _5;
  q_18->tot_len = _8;
  # DEBUG BEGIN_STMT
  p_17(D)->next = 0B;
  # DEBUG BEGIN_STMT
  p_17(D)->tot_len = _5;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  tail_gone_23 = pbuf_free (q_18);
  # DEBUG tail_gone => tail_gone_23
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 84942]:
  # tail_gone_11 = PHI <1(2), tail_gone_23(5)>
  # DEBUG tail_gone => tail_gone_11
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _9 = p_17(D)->tot_len;
  _10 = p_17(D)->len;
  if (_9 != _10)
    goto <bb 12>; [66.00%]
  else
    goto <bb 8>; [34.00%]

  <bb 12> [local count: 56062]:

  <bb 7> [local count: 560619699]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 14> [local count: 560619699]:
  goto <bb 7>; [100.00%]

  <bb 8> [local count: 28880]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (tail_gone_11 == 0)
    goto <bb 10>; [71.00%]
  else
    goto <bb 9>; [29.00%]

  <bb 9> [local count: 8375]:

  <bb 10> [local count: 28880]:
  # iftmp.1_12 = PHI <q_18(8), 0B(9)>
  return iftmp.1_12;

}



;; Function pbuf_copy_partial_pbuf (pbuf_copy_partial_pbuf, funcdef_no=21, decl_uid=6322, cgraph_uid=22, symbol_order=21)

Modification phase of node pbuf_copy_partial_pbuf/21
pbuf_copy_partial_pbuf (struct pbuf * p_to, const struct pbuf * p_from, u16_t copy_len, u16_t offset)
{
  size_t len_calc;
  size_t offset_from;
  size_t offset_to;
  short unsigned int _1;
  short unsigned int _2;
  int _3;
  int _4;
  int _5;
  int _6;
  short unsigned int _7;
  unsigned int _8;
  unsigned int _9;
  short unsigned int _10;
  unsigned int _11;
  unsigned int _12;
  unsigned int _14;
  void * _15;
  void * _16;
  void * _17;
  const void * _18;
  unsigned int _19;
  short unsigned int _20;
  unsigned int _21;
  short unsigned int _22;
  unsigned int _23;
  short unsigned int _24;
  short unsigned int _25;
  struct pbuf * _26;
  short unsigned int _27;
  short unsigned int _28;
  struct pbuf * _29;
  err_t _39;
  short unsigned int iftmp.2_40;
  short unsigned int iftmp.2_51;

  <bb 2> [local count: 400722]:
  # DEBUG BEGIN_STMT
  offset_to_46 = (size_t) offset_45(D);
  # DEBUG offset_to => offset_to_46
  # DEBUG offset_from => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (p_from_47(D) == 0B)
    goto <bb 25>; [0.45%]
  else
    goto <bb 3>; [99.55%]

  <bb 3> [local count: 398919]:
  _1 = p_from_47(D)->tot_len;
  if (_1 < copy_len_49(D))
    goto <bb 25>; [1.04%]
  else
    goto <bb 4>; [98.96%]

  <bb 4> [local count: 394770]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (p_to_50(D) == 0B)
    goto <bb 25>; [0.45%]
  else
    goto <bb 5>; [99.55%]

  <bb 5> [local count: 392994]:
  _2 = p_to_50(D)->tot_len;
  _3 = (int) _2;
  _4 = (int) offset_45(D);
  _5 = (int) copy_len_49(D);
  _6 = _4 + _5;
  if (_3 < _6)
    goto <bb 25>; [1.04%]
  else
    goto <bb 28>; [98.96%]

  <bb 28> [local count: 388907]:

  <bb 6> [local count: 5368700]:
  # p_to_30 = PHI <p_to_50(D)(28), p_to_31(31)>
  # p_from_32 = PHI <p_from_47(D)(28), p_from_33(31)>
  # copy_len_34 = PHI <copy_len_49(D)(28), copy_len_55(31)>
  # offset_to_35 = PHI <offset_to_46(28), offset_to_36(31)>
  # offset_from_37 = PHI <0(28), offset_from_38(31)>
  # DEBUG offset_from => offset_from_37
  # DEBUG offset_to => offset_to_35
  # DEBUG copy_len => copy_len_34
  # DEBUG p_from => p_from_32
  # DEBUG p_to => p_to_30
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _7 = p_to_30->len;
  _8 = (unsigned int) _7;
  _9 = _8 - offset_to_35;
  _10 = p_from_32->len;
  _11 = (unsigned int) _10;
  _12 = _11 - offset_from_37;
  len_calc_13 = MIN_EXPR <_9, _12>;
  # DEBUG len_calc => len_calc_13
  # DEBUG BEGIN_STMT
  _14 = (unsigned int) copy_len_34;
  if (len_calc_13 <= _14)
    goto <bb 7>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 7> [local count: 2684350]:
  iftmp.2_51 = (short unsigned int) len_calc_13;

  <bb 8> [local count: 5368700]:
  # iftmp.2_40 = PHI <iftmp.2_51(7), copy_len_34(6)>
  # DEBUG len => iftmp.2_40
  # DEBUG BEGIN_STMT
  _15 = p_to_30->payload;
  _16 = _15 + offset_to_35;
  _17 = p_from_32->payload;
  _18 = _17 + offset_from_37;
  _19 = (unsigned int) iftmp.2_40;
  memcpy (_16, _18, _19);
  # DEBUG BEGIN_STMT
  offset_to_53 = _19 + offset_to_35;
  # DEBUG offset_to => offset_to_53
  # DEBUG BEGIN_STMT
  offset_from_54 = _19 + offset_from_37;
  # DEBUG offset_from => offset_from_54
  # DEBUG BEGIN_STMT
  copy_len_55 = copy_len_34 - iftmp.2_40;
  # DEBUG copy_len => copy_len_55
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _20 = p_to_30->len;
  _21 = (unsigned int) _20;
  if (_21 < offset_to_53)
    goto <bb 26>; [2.00%]
  else
    goto <bb 10>; [98.00%]

  <bb 26> [local count: 107374]:

  <bb 9> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 29> [local count: 1073741824]:
  goto <bb 9>; [100.00%]

  <bb 10> [local count: 5261326]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _22 = p_from_32->len;
  _23 = (unsigned int) _22;
  if (_23 < offset_from_54)
    goto <bb 27>; [2.00%]
  else
    goto <bb 12>; [98.00%]

  <bb 27> [local count: 105227]:

  <bb 11> [local count: 1052266990]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 30> [local count: 1052266990]:
  goto <bb 11>; [100.00%]

  <bb 12> [local count: 5156099]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (_23 <= offset_from_54)
    goto <bb 13>; [50.00%]
  else
    goto <bb 15>; [50.00%]

  <bb 13> [local count: 2578050]:
  # DEBUG BEGIN_STMT
  # DEBUG offset_from => 0
  # DEBUG BEGIN_STMT
  p_from_56 = p_from_32->next;
  # DEBUG p_from => p_from_56
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (p_from_56 == 0B)
    goto <bb 14>; [30.00%]
  else
    goto <bb 15>; [70.00%]

  <bb 14> [local count: 773415]:
  if (copy_len_55 != 0)
    goto <bb 25>; [2.00%]
  else
    goto <bb 15>; [98.00%]

  <bb 15> [local count: 5140631]:
  # p_from_33 = PHI <p_from_32(12), p_from_56(13), 0B(14)>
  # offset_from_38 = PHI <offset_from_54(12), 0(13), 0(14)>
  # DEBUG offset_from => offset_from_38
  # DEBUG p_from => p_from_33
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (_21 == offset_to_53)
    goto <bb 16>; [34.00%]
  else
    goto <bb 18>; [66.00%]

  <bb 16> [local count: 1747815]:
  # DEBUG BEGIN_STMT
  # DEBUG offset_to => 0
  # DEBUG BEGIN_STMT
  p_to_57 = p_to_30->next;
  # DEBUG p_to => p_to_57
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (p_to_57 == 0B)
    goto <bb 17>; [30.00%]
  else
    goto <bb 18>; [70.00%]

  <bb 17> [local count: 524344]:
  if (copy_len_55 != 0)
    goto <bb 25>; [2.00%]
  else
    goto <bb 18>; [98.00%]

  <bb 18> [local count: 5130144]:
  # p_to_31 = PHI <p_to_30(15), p_to_57(16), 0B(17)>
  # offset_to_36 = PHI <offset_to_53(15), 0(16), 0(17)>
  # DEBUG offset_to => offset_to_36
  # DEBUG p_to => p_to_31
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (p_from_33 != 0B)
    goto <bb 19>; [70.00%]
  else
    goto <bb 21>; [30.00%]

  <bb 19> [local count: 3591101]:
  _24 = p_from_33->len;
  _25 = p_from_33->tot_len;
  if (_24 == _25)
    goto <bb 20>; [34.00%]
  else
    goto <bb 21>; [66.00%]

  <bb 20> [local count: 1220974]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _26 = p_from_33->next;
  if (_26 != 0B)
    goto <bb 25>; [2.00%]
  else
    goto <bb 21>; [98.00%]

  <bb 21> [local count: 5105725]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (p_to_31 != 0B)
    goto <bb 22>; [70.00%]
  else
    goto <bb 24>; [30.00%]

  <bb 22> [local count: 3574007]:
  _27 = p_to_31->len;
  _28 = p_to_31->tot_len;
  if (_27 == _28)
    goto <bb 23>; [34.00%]
  else
    goto <bb 24>; [66.00%]

  <bb 23> [local count: 1215163]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _29 = p_to_31->next;
  if (_29 != 0B)
    goto <bb 25>; [2.00%]
  else
    goto <bb 24>; [98.00%]

  <bb 24> [local count: 5081422]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (copy_len_55 != 0)
    goto <bb 31>; [98.00%]
  else
    goto <bb 25>; [2.00%]

  <bb 31> [local count: 4979794]:
  goto <bb 6>; [100.00%]

  <bb 25> [local count: 188122]:
  # _39 = PHI <-16(3), -16(5), -16(14), -16(17), -6(20), -6(23), 0(24), -16(2), -16(4)>
  return _39;

}



;; Function pbuf_copy (pbuf_copy, funcdef_no=20, decl_uid=6317, cgraph_uid=21, symbol_order=20)

Modification phase of node pbuf_copy/20
pbuf_copy (struct pbuf * p_to, const struct pbuf * p_from)
{
  short unsigned int _1;
  err_t _2;
  err_t _8;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (p_from_4(D) == 0B)
    goto <bb 4>; [0.91%]
  else
    goto <bb 3>; [99.09%]

  <bb 3> [local count: 1063970774]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = p_from_4(D)->tot_len;
  _8 = pbuf_copy_partial_pbuf (p_to_6(D), p_from_4(D), _1, 0);

  <bb 4> [local count: 1073741824]:
  # _2 = PHI <-16(2), _8(3)>
  return _2;

}



;; Function pbuf_copy_partial (pbuf_copy_partial, funcdef_no=22, decl_uid=6327, cgraph_uid=23, symbol_order=22)

Modification phase of node pbuf_copy_partial/22
pbuf_copy_partial (const struct pbuf * buf, void * dataptr, u16_t len, u16_t offset)
{
  u16_t left;
  const struct pbuf * p;
  short unsigned int _6;
  u16_t _7;

  <bb 2> [local count: 171201796]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG left => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG copied_total => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (buf_9(D) == 0B)
    goto <bb 5>; [18.09%]
  else
    goto <bb 3>; [81.91%]

  <bb 3> [local count: 140231391]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (dataptr_10(D) == 0B)
    goto <bb 5>; [18.09%]
  else
    goto <bb 4>; [81.91%]

  <bb 4> [local count: 114863532]:
  # len_2 = PHI <len_11(D)(3)>
  # offset_3 = PHI <offset_12(D)(3)>
  # p_4 = PHI <buf_9(D)(3)>
  # left_5 = PHI <0(3)>
  _6 = pbuf_copy_partial.part.0 (buf_9(D), dataptr_10(D), len_11(D), offset_12(D));

  <bb 5> [local count: 171201795]:
  # _7 = PHI <0(2), 0(3), _6(4)>
  return _7;

}



;; Function pbuf_get_contiguous (pbuf_get_contiguous, funcdef_no=23, decl_uid=6333, cgraph_uid=24, symbol_order=23)

Modification phase of node pbuf_get_contiguous/23
pbuf_get_contiguous (const struct pbuf * p, void * buffer, size_t bufsize, u16_t len, u16_t offset)
{
  u16_t out_offset;
  const struct pbuf * q;
  unsigned int _1;
  short unsigned int _2;
  int _3;
  short unsigned int out_offset.3_4;
  int _5;
  int _6;
  int _7;
  void * _8;
  sizetype _9;
  short unsigned int _10;
  void * _11;
  void * _22;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (p_13(D) == 0B)
    goto <bb 10>; [8.27%]
  else
    goto <bb 3>; [91.73%]

  <bb 3> [local count: 984943376]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (buffer_14(D) == 0B)
    goto <bb 10>; [8.27%]
  else
    goto <bb 4>; [91.73%]

  <bb 4> [local count: 903488559]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (unsigned int) len_15(D);
  if (_1 > bufsize_16(D))
    goto <bb 10>; [29.93%]
  else
    goto <bb 5>; [70.07%]

  <bb 5> [local count: 633074433]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  q_20 = pbuf_skip_const (p_13(D), offset_18(D), &out_offset);
  # DEBUG q => q_20
  # DEBUG BEGIN_STMT
  if (q_20 != 0B)
    goto <bb 6>; [85.10%]
  else
    goto <bb 10>; [14.90%]

  <bb 6> [local count: 538746343]:
  # DEBUG BEGIN_STMT
  _2 = q_20->len;
  _3 = (int) _2;
  out_offset.3_4 = out_offset;
  _5 = (int) out_offset.3_4;
  _6 = (int) len_15(D);
  _7 = _5 + _6;
  if (_3 >= _7)
    goto <bb 7>; [51.12%]
  else
    goto <bb 8>; [48.88%]

  <bb 7> [local count: 275407130]:
  # DEBUG BEGIN_STMT
  _8 = q_20->payload;
  _9 = (sizetype) out_offset.3_4;
  _22 = _8 + _9;
  goto <bb 10>; [100.00%]

  <bb 8> [local count: 263339212]:
  # DEBUG BEGIN_STMT
  _10 = pbuf_copy_partial (q_20, buffer_14(D), len_15(D), out_offset.3_4);
  if (_10 != len_15(D))
    goto <bb 10>; [44.22%]
  else
    goto <bb 9>; [55.78%]

  <bb 9> [local count: 146890613]:
  # DEBUG BEGIN_STMT

  <bb 10> [local count: 1073741824]:
  # _11 = PHI <0B(2), 0B(3), 0B(4), _22(7), 0B(8), buffer_14(D)(9), 0B(5)>
  out_offset ={v} {CLOBBER};
  return _11;

}



;; Function pbuf_skip (pbuf_skip, funcdef_no=25, decl_uid=6346, cgraph_uid=26, symbol_order=25)

Modification phase of node pbuf_skip/25
pbuf_skip (struct pbuf * in, u16_t in_offset, u16_t * out_offset)
{
  const struct pbuf * out;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  out_6 = pbuf_skip_const (in_2(D), in_offset_3(D), out_offset_4(D));
  # DEBUG out => out_6
  # DEBUG BEGIN_STMT
  return out_6;

}



;; Function pbuf_take (pbuf_take, funcdef_no=26, decl_uid=6337, cgraph_uid=27, symbol_order=26)

Modification phase of node pbuf_take/26
pbuf_take (struct pbuf * buf, const void * dataptr, u16_t len)
{
  size_t copied_total;
  size_t total_copy_len;
  size_t buf_copy_len;
  struct pbuf * p;
  short unsigned int _1;
  short unsigned int _3;
  unsigned int _4;
  void * _5;
  const void * _6;
  err_t _10;

  <bb 2> [local count: 225343]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  total_copy_len_16 = (size_t) len_15(D);
  # DEBUG total_copy_len => total_copy_len_16
  # DEBUG BEGIN_STMT
  # DEBUG copied_total => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (buf_17(D) == 0B)
    goto <bb 11>; [0.45%]
  else
    goto <bb 3>; [99.55%]

  <bb 3> [local count: 224329]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (dataptr_18(D) == 0B)
    goto <bb 11>; [0.45%]
  else
    goto <bb 4>; [99.55%]

  <bb 4> [local count: 223320]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = buf_17(D)->tot_len;
  if (_1 < len_15(D))
    goto <bb 11>; [1.04%]
  else
    goto <bb 14>; [98.96%]

  <bb 14> [local count: 220997]:
  goto <bb 8>; [100.00%]

  <bb 5> [local count: 1952255]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (p_7 == 0B)
    goto <bb 12>; [5.50%]
  else
    goto <bb 7>; [94.50%]

  <bb 12> [local count: 107374]:

  <bb 6> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 15> [local count: 1073741824]:
  goto <bb 6>; [100.00%]

  <bb 7> [local count: 1844881]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG buf_copy_len => total_copy_len_8
  # DEBUG BEGIN_STMT
  _3 = p_7->len;
  _4 = (unsigned int) _3;
  buf_copy_len_26 = MIN_EXPR <_4, total_copy_len_8>;
  # DEBUG buf_copy_len => buf_copy_len_26
  # DEBUG BEGIN_STMT
  _5 = p_7->payload;
  _6 = dataptr_18(D) + copied_total_9;
  memcpy (_5, _6, buf_copy_len_26);
  # DEBUG BEGIN_STMT
  total_copy_len_22 = total_copy_len_8 - buf_copy_len_26;
  # DEBUG total_copy_len => total_copy_len_22
  # DEBUG BEGIN_STMT
  copied_total_23 = copied_total_9 + buf_copy_len_26;
  # DEBUG copied_total => copied_total_23
  # DEBUG BEGIN_STMT
  p_24 = p_7->next;
  # DEBUG p => p_24

  <bb 8> [local count: 2065878]:
  # p_7 = PHI <p_24(7), buf_17(D)(14)>
  # total_copy_len_8 = PHI <total_copy_len_22(7), total_copy_len_16(14)>
  # copied_total_9 = PHI <copied_total_23(7), 0(14)>
  # DEBUG copied_total => copied_total_9
  # DEBUG total_copy_len => total_copy_len_8
  # DEBUG p => p_7
  # DEBUG BEGIN_STMT
  if (total_copy_len_8 != 0)
    goto <bb 5>; [94.50%]
  else
    goto <bb 9>; [5.50%]

  <bb 9> [local count: 113623]:
  # copied_total_2 = PHI <copied_total_9(8)>
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (copied_total_2 != total_copy_len_16)
    goto <bb 13>; [66.00%]
  else
    goto <bb 11>; [34.00%]

  <bb 13> [local count: 74991]:

  <bb 10> [local count: 749914927]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 16> [local count: 749914927]:
  goto <bb 10>; [100.00%]

  <bb 11> [local count: 42978]:
  # _10 = PHI <-16(2), -16(3), -1(4), 0(9)>
  return _10;

}



;; Function pbuf_take_at (pbuf_take_at, funcdef_no=27, decl_uid=6342, cgraph_uid=28, symbol_order=27)

Modification phase of node pbuf_take_at/27
pbuf_take_at (struct pbuf * buf, const void * dataptr, u16_t len, u16_t offset)
{
  const struct pbuf * out;
  const u8_t * src_ptr;
  u16_t remaining_len;
  u16_t target_offset;
  short unsigned int _1;
  int _2;
  short unsigned int target_offset.6_3;
  int _4;
  int _5;
  int _6;
  short unsigned int _7;
  int _8;
  int _9;
  void * _10;
  sizetype _11;
  void * _12;
  unsigned int _13;
  struct pbuf * _14;
  short unsigned int iftmp.8_15;
  err_t _16;
  short unsigned int iftmp.8_24;
  err_t _29;

  <bb 2> [local count: 221054]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG in => buf_20(D)
  # DEBUG in_offset => offset_21(D)
  # DEBUG out_offset => &target_offset
  # DEBUG INLINE_ENTRY pbuf_skip
  # DEBUG BEGIN_STMT
  out_32 = pbuf_skip_const (buf_20(D), offset_21(D), &target_offset);
  # DEBUG out => out_32
  # DEBUG BEGIN_STMT
  # DEBUG in => NULL
  # DEBUG in_offset => NULL
  # DEBUG out_offset => NULL
  # DEBUG out => NULL
  # DEBUG q => out_32
  # DEBUG BEGIN_STMT
  if (out_32 != 0B)
    goto <bb 3>; [99.13%]
  else
    goto <bb 10>; [0.87%]

  <bb 3> [local count: 219131]:
  _1 = MEM[(struct pbuf *)out_32].tot_len;
  _2 = (int) _1;
  target_offset.6_3 = target_offset;
  _4 = (int) target_offset.6_3;
  _5 = (int) len_22(D);
  _6 = _4 + _5;
  if (_2 >= _6)
    goto <bb 4>; [98.00%]
  else
    goto <bb 10>; [2.00%]

  <bb 4> [local count: 214748]:
  # DEBUG BEGIN_STMT
  # DEBUG remaining_len => len_22(D)
  # DEBUG BEGIN_STMT
  # DEBUG src_ptr => dataptr_23(D)
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _7 = MEM[(struct pbuf *)out_32].len;
  if (target_offset.6_3 >= _7)
    goto <bb 11>; [50.00%]
  else
    goto <bb 6>; [50.00%]

  <bb 11> [local count: 107374]:

  <bb 5> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 12> [local count: 1073741824]:
  goto <bb 5>; [100.00%]

  <bb 6> [local count: 107374]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _8 = (int) _7;
  _9 = _8 - _4;
  if (_5 > _9)
    goto <bb 7>; [50.00%]
  else
    goto <bb 8>; [50.00%]

  <bb 7> [local count: 53687]:
  iftmp.8_24 = _7 - target_offset.6_3;

  <bb 8> [local count: 107374]:
  # iftmp.8_15 = PHI <iftmp.8_24(7), len_22(D)(6)>
  # DEBUG first_copy_len => iftmp.8_15
  # DEBUG BEGIN_STMT
  _10 = MEM[(struct pbuf *)out_32].payload;
  _11 = (sizetype) target_offset.6_3;
  _12 = _10 + _11;
  _13 = (unsigned int) iftmp.8_15;
  memcpy (_12, dataptr_23(D), _13);
  # DEBUG BEGIN_STMT
  remaining_len_26 = len_22(D) - iftmp.8_15;
  # DEBUG remaining_len => remaining_len_26
  # DEBUG BEGIN_STMT
  src_ptr_27 = dataptr_23(D) + _13;
  # DEBUG src_ptr => src_ptr_27
  # DEBUG BEGIN_STMT
  if (remaining_len_26 != 0)
    goto <bb 9>; [33.00%]
  else
    goto <bb 10>; [67.00%]

  <bb 9> [local count: 35433]:
  # DEBUG BEGIN_STMT
  _14 = MEM[(struct pbuf *)out_32].next;
  _29 = pbuf_take (_14, src_ptr_27, remaining_len_26);

  <bb 10> [local count: 113680]:
  # _16 = PHI <_29(9), 0(8), -1(3), -1(2)>
  target_offset ={v} {CLOBBER};
  return _16;

}



;; Function pbuf_clone (pbuf_clone, funcdef_no=29, decl_uid=6353, cgraph_uid=30, symbol_order=29)

Modification phase of node pbuf_clone/29
pbuf_clone (pbuf_layer layer, pbuf_type type, struct pbuf * p)
{
  err_t err;
  struct pbuf * q;
  short unsigned int _1;
  struct pbuf * _2;

  <bb 2> [local count: 254049]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = p_6(D)->tot_len;
  q_10 = pbuf_alloc (layer_7(D), _1, type_8(D));
  # DEBUG q => q_10
  # DEBUG BEGIN_STMT
  if (q_10 == 0B)
    goto <bb 5>; [15.47%]
  else
    goto <bb 3>; [84.53%]

  <bb 3> [local count: 214748]:
  # DEBUG BEGIN_STMT
  err_12 = pbuf_copy (q_10, p_6(D));
  # DEBUG err => err_12
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (err_12 != 0)
    goto <bb 6>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 6> [local count: 107374]:

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 7> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 146675]:
  # _2 = PHI <0B(2), q_10(3)>
  return _2;

}



;; Function pbuf_coalesce (pbuf_coalesce, funcdef_no=28, decl_uid=6349, cgraph_uid=29, symbol_order=28)

Modification phase of node pbuf_coalesce/28
pbuf_coalesce (struct pbuf * p, pbuf_layer layer)
{
  struct pbuf * q;
  struct pbuf * _1;
  struct pbuf * _2;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = p_5(D)->next;
  if (_1 == 0B)
    goto <bb 5>; [30.95%]
  else
    goto <bb 3>; [69.05%]

  <bb 3> [local count: 741418730]:
  # DEBUG BEGIN_STMT
  q_8 = pbuf_clone (layer_6(D), 640, p_5(D));
  # DEBUG q => q_8
  # DEBUG BEGIN_STMT
  if (q_8 == 0B)
    goto <bb 5>; [30.95%]
  else
    goto <bb 4>; [69.05%]

  <bb 4> [local count: 511949632]:
  # DEBUG BEGIN_STMT
  pbuf_free (p_5(D));
  # DEBUG BEGIN_STMT

  <bb 5> [local count: 1073741824]:
  # _2 = PHI <p_5(D)(2), p_5(D)(3), q_8(4)>
  return _2;

}



;; Function pbuf_try_get_at (pbuf_try_get_at, funcdef_no=31, decl_uid=6359, cgraph_uid=32, symbol_order=31)

Modification phase of node pbuf_try_get_at/31
pbuf_try_get_at (const struct pbuf * p, u16_t offset)
{
  const struct pbuf * q;
  u16_t q_idx;
  short unsigned int _1;
  short unsigned int q_idx.12_2;
  void * _3;
  sizetype _4;
  u8_t * _5;
  unsigned char _6;
  int _7;
  int _13;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  q_12 = pbuf_skip_const (p_9(D), offset_10(D), &q_idx);
  # DEBUG q => q_12
  # DEBUG BEGIN_STMT
  if (q_12 != 0B)
    goto <bb 3>; [99.13%]
  else
    goto <bb 5>; [0.87%]

  <bb 3> [local count: 1064400271]:
  _1 = q_12->len;
  q_idx.12_2 = q_idx;
  if (_1 > q_idx.12_2)
    goto <bb 4>; [96.19%]
  else
    goto <bb 5>; [3.81%]

  <bb 4> [local count: 1023846620]:
  # DEBUG BEGIN_STMT
  _3 = q_12->payload;
  _4 = (sizetype) q_idx.12_2;
  _5 = _3 + _4;
  _6 = *_5;
  _13 = (int) _6;

  <bb 5> [local count: 1073741824]:
  # _7 = PHI <_13(4), -1(3), -1(2)>
  q_idx ={v} {CLOBBER};
  return _7;

}



;; Function pbuf_get_at (pbuf_get_at, funcdef_no=30, decl_uid=6356, cgraph_uid=31, symbol_order=30)

Modification phase of node pbuf_get_at/30
pbuf_get_at (const struct pbuf * p, u16_t offset)
{
  int ret;
  u8_t _1;
  int _7;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  ret_6 = pbuf_try_get_at (p_3(D), offset_4(D));
  # DEBUG ret => ret_6
  # DEBUG BEGIN_STMT
  _7 = MAX_EXPR <ret_6, 0>;
  _1 = (u8_t) _7;
  return _1;

}



;; Function pbuf_put_at (pbuf_put_at, funcdef_no=32, decl_uid=6363, cgraph_uid=33, symbol_order=32)

Modification phase of node pbuf_put_at/32
pbuf_put_at (struct pbuf * p, u16_t offset, u8_t data)
{
  const struct pbuf * out;
  u16_t q_idx;
  short unsigned int _1;
  short unsigned int q_idx.14_2;
  void * _3;
  sizetype _4;
  u8_t * _5;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG in => p_8(D)
  # DEBUG in_offset => offset_9(D)
  # DEBUG out_offset => &q_idx
  # DEBUG INLINE_ENTRY pbuf_skip
  # DEBUG BEGIN_STMT
  out_13 = pbuf_skip_const (p_8(D), offset_9(D), &q_idx);
  # DEBUG out => out_13
  # DEBUG BEGIN_STMT
  # DEBUG in => NULL
  # DEBUG in_offset => NULL
  # DEBUG out_offset => NULL
  # DEBUG out => NULL
  # DEBUG q => out_13
  # DEBUG BEGIN_STMT
  if (out_13 != 0B)
    goto <bb 3>; [70.00%]
  else
    goto <bb 5>; [30.00%]

  <bb 3> [local count: 751619277]:
  _1 = MEM[(struct pbuf *)out_13].len;
  q_idx.14_2 = q_idx;
  if (_1 > q_idx.14_2)
    goto <bb 4>; [50.00%]
  else
    goto <bb 5>; [50.00%]

  <bb 4> [local count: 375809638]:
  # DEBUG BEGIN_STMT
  _3 = MEM[(struct pbuf *)out_13].payload;
  _4 = (sizetype) q_idx.14_2;
  _5 = _3 + _4;
  *_5 = data_10(D);

  <bb 5> [local count: 1073741824]:
  q_idx ={v} {CLOBBER};
  return;

}



;; Function pbuf_memcmp (pbuf_memcmp, funcdef_no=33, decl_uid=6368, cgraph_uid=34, symbol_order=33)

Modification phase of node pbuf_memcmp/33
pbuf_memcmp (const struct pbuf * p, u16_t offset, const void * s2, u16_t n)
{
  const struct pbuf * q;
  u16_t start;
  short unsigned int _1;
  int _2;
  int _3;
  int _4;
  int _5;
  u16_t _8;
  short unsigned int _11;

  <bb 2> [local count: 146734200]:
  # DEBUG BEGIN_STMT
  # DEBUG start => offset_9(D)
  # DEBUG BEGIN_STMT
  # DEBUG q => p_10(D)
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = p_10(D)->tot_len;
  _2 = (int) _1;
  _3 = (int) offset_9(D);
  _4 = (int) n_13(D);
  _5 = _3 + _4;
  if (_2 < _5)
    goto <bb 4>; [21.72%]
  else
    goto <bb 3>; [78.28%]

  <bb 3> [local count: 114863532]:
  # start_6 = PHI <offset_9(D)(2)>
  # q_7 = PHI <p_10(D)(2)>
  _11 = pbuf_memcmp.part.0 (p_10(D), offset_9(D), s2_16(D), n_13(D));

  <bb 4> [local count: 146734200]:
  # _8 = PHI <65535(2), _11(3)>
  return _8;

}



;; Function pbuf_memfind (pbuf_memfind, funcdef_no=34, decl_uid=6373, cgraph_uid=35, symbol_order=34)

Modification phase of node pbuf_memfind/34
pbuf_memfind (const struct pbuf * p, const void * mem, u16_t mem_len, u16_t start_offset)
{
  u16_t plus;
  u16_t max_cmp_start;
  u16_t i;
  short unsigned int _1;
  int _3;
  int _4;
  int _5;
  int _6;
  u16_t _8;

  <bb 2> [local count: 176713126]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = p_12(D)->tot_len;
  max_cmp_start_14 = _1 - mem_len_13(D);
  # DEBUG max_cmp_start => max_cmp_start_14
  # DEBUG BEGIN_STMT
  _3 = (int) _1;
  _4 = (int) mem_len_13(D);
  _5 = (int) start_offset_15(D);
  _6 = _4 + _5;
  if (_3 >= _6)
    goto <bb 8>; [65.00%]
  else
    goto <bb 7>; [35.00%]

  <bb 8> [local count: 114863532]:
  goto <bb 6>; [100.00%]

  <bb 3> [local count: 1014686024]:
  # DEBUG BEGIN_STMT
  plus_18 = pbuf_memcmp (p_12(D), i_7, mem_16(D), mem_len_13(D));
  # DEBUG plus => plus_18
  # DEBUG BEGIN_STMT
  if (plus_18 == 0)
    goto <bb 4>; [5.50%]
  else
    goto <bb 5>; [94.50%]

  <bb 4> [local count: 55807731]:
  # i_2 = PHI <i_7(3)>
  # DEBUG BEGIN_STMT
  goto <bb 7>; [100.00%]

  <bb 5> [local count: 958878292]:
  # DEBUG BEGIN_STMT
  i_19 = i_7 + 1;
  # DEBUG i => i_19

  <bb 6> [local count: 1073741824]:
  # i_7 = PHI <i_19(5), start_offset_15(D)(8)>
  # DEBUG i => i_7
  # DEBUG BEGIN_STMT
  if (i_7 <= max_cmp_start_14)
    goto <bb 3>; [94.50%]
  else
    goto <bb 7>; [5.50%]

  <bb 7> [local count: 176713126]:
  # _8 = PHI <i_2(4), 65535(6), 65535(2)>
  return _8;

}



;; Function pbuf_strstr (pbuf_strstr, funcdef_no=35, decl_uid=6376, cgraph_uid=36, symbol_order=35)

Modification phase of node pbuf_strstr/35
pbuf_strstr (const struct pbuf * p, const char * substr)
{
  size_t substr_len;
  char _1;
  short unsigned int _2;
  short unsigned int _3;
  u16_t _4;
  u16_t _11;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (substr_6(D) == 0B)
    goto <bb 7>; [10.63%]
  else
    goto <bb 3>; [89.37%]

  <bb 3> [local count: 959603069]:
  _1 = *substr_6(D);
  if (_1 == 0)
    goto <bb 7>; [21.72%]
  else
    goto <bb 4>; [78.28%]

  <bb 4> [local count: 751177282]:
  _2 = p_8(D)->tot_len;
  if (_2 == 65535)
    goto <bb 7>; [12.50%]
  else
    goto <bb 5>; [87.50%]

  <bb 5> [local count: 657280122]:
  # DEBUG BEGIN_STMT
  substr_len_9 = strlen (substr_6(D));
  # DEBUG substr_len => substr_len_9
  # DEBUG BEGIN_STMT
  if (substr_len_9 > 65534)
    goto <bb 7>; [36.03%]
  else
    goto <bb 6>; [63.97%]

  <bb 6> [local count: 420462094]:
  # DEBUG BEGIN_STMT
  _3 = (short unsigned int) substr_len_9;
  _11 = pbuf_memfind (p_8(D), substr_6(D), _3, 0);

  <bb 7> [local count: 1073741824]:
  # _4 = PHI <65535(3), 65535(5), _11(6), 65535(2), 65535(4)>
  return _4;

}


