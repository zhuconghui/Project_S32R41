
IPA constant propagation start:
Determining dynamic type for call: do_memp_free_pool (_2, mem_5(D));
  Starting walk at: do_memp_free_pool (_2, mem_5(D));
  instance pointer: _2  Outer instance pointer: _2 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: do_memp_free_pool (_2, mem_5(D));
  Starting walk at: do_memp_free_pool (_2, mem_5(D));
  instance pointer: mem_5(D)  Outer instance pointer: mem_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: do_memp_free_pool (desc_3(D), mem_5(D));
  Starting walk at: do_memp_free_pool (desc_3(D), mem_5(D));
  instance pointer: desc_3(D)  Outer instance pointer: desc_3(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: do_memp_free_pool (desc_3(D), mem_5(D));
  Starting walk at: do_memp_free_pool (desc_3(D), mem_5(D));
  instance pointer: mem_5(D)  Outer instance pointer: mem_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: do_memp_free_pool.part.0 (desc_7(D), mem_5(D));
  Starting walk at: do_memp_free_pool.part.0 (desc_7(D), mem_5(D));
  instance pointer: desc_7(D)  Outer instance pointer: desc_7(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: do_memp_free_pool.part.0 (desc_7(D), mem_5(D));
  Starting walk at: do_memp_free_pool.part.0 (desc_7(D), mem_5(D));
  instance pointer: mem_5(D)  Outer instance pointer: mem_5(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: memp_8 = do_memp_malloc_pool (_2);
  Starting walk at: memp_8 = do_memp_malloc_pool (_2);
  instance pointer: _2  Outer instance pointer: _2 offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _5 = do_memp_malloc_pool (desc_2(D));
  Starting walk at: _5 = do_memp_malloc_pool (desc_2(D));
  instance pointer: desc_2(D)  Outer instance pointer: desc_2(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: _2 = do_memp_malloc_pool.part.0 (desc_16(D));
  Starting walk at: _2 = do_memp_malloc_pool.part.0 (desc_16(D));
  instance pointer: desc_16(D)  Outer instance pointer: desc_16(D) offset: 0 (bits) vtbl reference: 
Determining dynamic type for call: memp_init_pool (_2);
  Starting walk at: memp_init_pool (_2);
  instance pointer: _2  Outer instance pointer: _2 offset: 0 (bits) vtbl reference: 
  Function call may change dynamic type:memp_init_pool (_2);

IPA structures before propagation:

Jump functions:
  Jump functions of caller  do_memp_free_pool.part.0/72:
  Jump functions of caller  do_memp_malloc_pool.part.0/71:
  Jump functions of caller  memp_free/69:
    callsite  memp_free/69 -> do_memp_free_pool/67 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  memp_free_pool/68:
    callsite  memp_free_pool/68 -> do_memp_free_pool/67 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  do_memp_free_pool/67:
    callsite  do_memp_free_pool/67 -> do_memp_free_pool.part.0/72 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
       param 1: PASS THROUGH: 1, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  memp_malloc/66:
    callsite  memp_malloc/66 -> do_memp_malloc_pool/64 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  memp_malloc_pool/65:
    callsite  memp_malloc_pool/65 -> do_memp_malloc_pool/64 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  do_memp_malloc_pool/64:
    callsite  do_memp_malloc_pool/64 -> do_memp_malloc_pool.part.0/71 : 
       param 0: PASS THROUGH: 0, op nop_expr, agg_preserved
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  memp_init/63:
    callsite  memp_init/63 -> memp_init_pool/62 : 
       param 0: UNKNOWN
         value: 0x0, mask: 0xffffffff
         Unknown VR
  Jump functions of caller  memp_init_pool/62:

 Propagating constants:

Not considering memp_free for cloning; -fipa-cp-clone disabled.
Not considering memp_free_pool for cloning; -fipa-cp-clone disabled.
Not considering memp_malloc for cloning; -fipa-cp-clone disabled.
Not considering memp_malloc_pool for cloning; -fipa-cp-clone disabled.
Not considering memp_init for cloning; -fipa-cp-clone disabled.
Not considering memp_init_pool for cloning; -fipa-cp-clone disabled.

overall_size: 126, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: do_memp_free_pool.part.0/72:
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
  Node: do_memp_malloc_pool.part.0/71:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: memp_free/69:
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
  Node: memp_free_pool/68:
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
  Node: do_memp_free_pool/67:
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
  Node: memp_malloc/66:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: memp_malloc_pool/65:
    param [0]: BOTTOM
         ctxs: BOTTOM
         Bits unusable (BOTTOM)
         VARYING
        AGGS BOTTOM
  Node: do_memp_malloc_pool/64:
    param [0]: VARIABLE
         ctxs: VARIABLE
         Bits unusable (BOTTOM)
         VARYING
        AGGS VARIABLE
  Node: memp_init/63:
  Node: memp_init_pool/62:
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

do_memp_free_pool.part.0/72 (do_memp_free_pool.part.0) @06dcc9a0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: do_memp_free_pool/67 (107374 (estimated locally),0.50 per call) 
  Calls: 
do_memp_malloc_pool.part.0/71 (do_memp_malloc_pool.part.0) @06b188c0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly artificial
  References: 
  Referring: 
  Availability: local
  Function flags: count:1073741824 (estimated locally) first_run:1 body local split_part optimize_size
  Called by: do_memp_malloc_pool/64 (28485 (estimated locally),0.15 per call) 
  Calls: 
lwip_stats/70 (lwip_stats) @06d97510
  Type: variable
  Body removed by symtab_remove_unreachable_nodes
  Visibility: external public
  References: 
  Referring: memp_init/63 (write)
  Availability: not_available
  Varpool flags:
memp_free/69 (memp_free) @06d93e00
  Type: function definition analyzed
  Visibility: externally_visible public
  References: memp_pools/61 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741823 (estimated locally) body optimize_size
  Called by: 
  Calls: do_memp_free_pool/67 (489336361 (estimated locally),0.46 per call) 
memp_free_pool/68 (memp_free_pool) @06d93a80
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:357913 (estimated locally) body optimize_size
  Called by: 
  Calls: do_memp_free_pool/67 (172997 (estimated locally),0.48 per call) 
do_memp_free_pool/67 (do_memp_free_pool) @06d937e0
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:214748 (estimated locally) body local optimize_size
  Called by: memp_free/69 (489336361 (estimated locally),0.46 per call) memp_free_pool/68 (172997 (estimated locally),0.48 per call) 
  Calls: do_memp_free_pool.part.0/72 (107374 (estimated locally),0.50 per call) 
memp_malloc/66 (memp_malloc) @06d93540
  Type: function definition analyzed
  Visibility: externally_visible public
  References: memp_pools/61 (read)
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: do_memp_malloc_pool/64 (752370897 (estimated locally),0.70 per call) 
memp_malloc_pool/65 (memp_malloc_pool) @06d932a0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:230763 (estimated locally) body optimize_size
  Called by: 
  Calls: do_memp_malloc_pool/64 (123389 (estimated locally),0.53 per call) 
do_memp_malloc_pool/64 (do_memp_malloc_pool) @06d93000
  Type: function definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: 
  Availability: local
  Function flags: count:191173 (estimated locally) body local optimize_size
  Called by: memp_malloc/66 (752370897 (estimated locally),0.70 per call) memp_malloc_pool/65 (123389 (estimated locally),0.53 per call) 
  Calls: do_memp_malloc_pool.part.0/71 (28485 (estimated locally),0.15 per call) 
memp_init/63 (memp_init) @06d67ee0
  Type: function definition analyzed
  Visibility: externally_visible public
  References: memp_pools/61 (read)lwip_stats/70 (write)
  Referring: 
  Availability: available
  Function flags: count:67108864 (estimated locally) body optimize_size
  Called by: 
  Calls: memp_init_pool/62 (1006632961 (estimated locally),15.00 per call) 
memp_init_pool/62 (memp_init_pool) @06d67b60
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:118111600 (estimated locally) body optimize_size
  Called by: memp_init/63 (1006632961 (estimated locally),15.00 per call) 
  Calls: 
memp_pools/61 (memp_pools) @06d64900
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: memp_RAW_PCB/4 (addr)memp_UDP_PCB/8 (addr)memp_TCP_PCB/12 (addr)memp_TCP_PCB_LISTEN/16 (addr)memp_TCP_SEG/20 (addr)memp_REASSDATA/24 (addr)memp_FRAG_PBUF/28 (addr)memp_ARP_QUEUE/32 (addr)memp_IGMP_GROUP/36 (addr)memp_SYS_TIMEOUT/40 (addr)memp_ND6_QUEUE/44 (addr)memp_IP6_REASSDATA/48 (addr)memp_MLD6_GROUP/52 (addr)memp_PBUF/56 (addr)memp_PBUF_POOL/60 (addr)
  Referring: memp_malloc/66 (read)memp_init/63 (read)memp_free/69 (read)
  Availability: available
  Varpool flags: initialized read-only const-value-known
memp_PBUF_POOL/60 (memp_PBUF_POOL) @06d64870
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: memp_stats_PBUF_POOL/58 (addr)memp_memory_PBUF_POOL_base/57 (addr)memp_tab_PBUF_POOL/59 (addr)
  Referring: memp_pools/61 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
memp_tab_PBUF_POOL/59 (memp_tab_PBUF_POOL) @06d64798
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: memp_PBUF_POOL/60 (addr)
  Availability: available
  Varpool flags:
memp_stats_PBUF_POOL/58 (memp_stats_PBUF_POOL) @06d64708
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: memp_PBUF_POOL/60 (addr)
  Availability: available
  Varpool flags:
memp_memory_PBUF_POOL_base/57 (memp_memory_PBUF_POOL_base) @06d64678
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: memp_PBUF_POOL/60 (addr)
  Availability: available
  Varpool flags:
memp_PBUF/56 (memp_PBUF) @06d645a0
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: memp_stats_PBUF/54 (addr)memp_memory_PBUF_base/53 (addr)memp_tab_PBUF/55 (addr)
  Referring: memp_pools/61 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
memp_tab_PBUF/55 (memp_tab_PBUF) @06d644c8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: memp_PBUF/56 (addr)
  Availability: available
  Varpool flags:
memp_stats_PBUF/54 (memp_stats_PBUF) @06d64438
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: memp_PBUF/56 (addr)
  Availability: available
  Varpool flags:
memp_memory_PBUF_base/53 (memp_memory_PBUF_base) @06d643a8
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: memp_PBUF/56 (addr)
  Availability: available
  Varpool flags:
memp_MLD6_GROUP/52 (memp_MLD6_GROUP) @06d642d0
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: memp_stats_MLD6_GROUP/50 (addr)memp_memory_MLD6_GROUP_base/49 (addr)memp_tab_MLD6_GROUP/51 (addr)
  Referring: memp_pools/61 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
memp_tab_MLD6_GROUP/51 (memp_tab_MLD6_GROUP) @06d641f8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: memp_MLD6_GROUP/52 (addr)
  Availability: available
  Varpool flags:
memp_stats_MLD6_GROUP/50 (memp_stats_MLD6_GROUP) @06d64168
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: memp_MLD6_GROUP/52 (addr)
  Availability: available
  Varpool flags:
memp_memory_MLD6_GROUP_base/49 (memp_memory_MLD6_GROUP_base) @06d640d8
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: memp_MLD6_GROUP/52 (addr)
  Availability: available
  Varpool flags:
memp_IP6_REASSDATA/48 (memp_IP6_REASSDATA) @06d64000
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: memp_stats_IP6_REASSDATA/46 (addr)memp_memory_IP6_REASSDATA_base/45 (addr)memp_tab_IP6_REASSDATA/47 (addr)
  Referring: memp_pools/61 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
memp_tab_IP6_REASSDATA/47 (memp_tab_IP6_REASSDATA) @06d42ee8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: memp_IP6_REASSDATA/48 (addr)
  Availability: available
  Varpool flags:
memp_stats_IP6_REASSDATA/46 (memp_stats_IP6_REASSDATA) @06d42e58
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: memp_IP6_REASSDATA/48 (addr)
  Availability: available
  Varpool flags:
memp_memory_IP6_REASSDATA_base/45 (memp_memory_IP6_REASSDATA_base) @06d42dc8
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: memp_IP6_REASSDATA/48 (addr)
  Availability: available
  Varpool flags:
memp_ND6_QUEUE/44 (memp_ND6_QUEUE) @06d42cf0
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: memp_stats_ND6_QUEUE/42 (addr)memp_memory_ND6_QUEUE_base/41 (addr)memp_tab_ND6_QUEUE/43 (addr)
  Referring: memp_pools/61 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
memp_tab_ND6_QUEUE/43 (memp_tab_ND6_QUEUE) @06d42c18
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: memp_ND6_QUEUE/44 (addr)
  Availability: available
  Varpool flags:
memp_stats_ND6_QUEUE/42 (memp_stats_ND6_QUEUE) @06d42b88
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: memp_ND6_QUEUE/44 (addr)
  Availability: available
  Varpool flags:
memp_memory_ND6_QUEUE_base/41 (memp_memory_ND6_QUEUE_base) @06d42af8
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: memp_ND6_QUEUE/44 (addr)
  Availability: available
  Varpool flags:
memp_SYS_TIMEOUT/40 (memp_SYS_TIMEOUT) @06d42a20
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: memp_stats_SYS_TIMEOUT/38 (addr)memp_memory_SYS_TIMEOUT_base/37 (addr)memp_tab_SYS_TIMEOUT/39 (addr)
  Referring: memp_pools/61 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
memp_tab_SYS_TIMEOUT/39 (memp_tab_SYS_TIMEOUT) @06d42948
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: memp_SYS_TIMEOUT/40 (addr)
  Availability: available
  Varpool flags:
memp_stats_SYS_TIMEOUT/38 (memp_stats_SYS_TIMEOUT) @06d428b8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: memp_SYS_TIMEOUT/40 (addr)
  Availability: available
  Varpool flags:
memp_memory_SYS_TIMEOUT_base/37 (memp_memory_SYS_TIMEOUT_base) @06d42828
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: memp_SYS_TIMEOUT/40 (addr)
  Availability: available
  Varpool flags:
memp_IGMP_GROUP/36 (memp_IGMP_GROUP) @06d42750
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: memp_stats_IGMP_GROUP/34 (addr)memp_memory_IGMP_GROUP_base/33 (addr)memp_tab_IGMP_GROUP/35 (addr)
  Referring: memp_pools/61 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
memp_tab_IGMP_GROUP/35 (memp_tab_IGMP_GROUP) @06d42678
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: memp_IGMP_GROUP/36 (addr)
  Availability: available
  Varpool flags:
memp_stats_IGMP_GROUP/34 (memp_stats_IGMP_GROUP) @06d425e8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: memp_IGMP_GROUP/36 (addr)
  Availability: available
  Varpool flags:
memp_memory_IGMP_GROUP_base/33 (memp_memory_IGMP_GROUP_base) @06d42558
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: memp_IGMP_GROUP/36 (addr)
  Availability: available
  Varpool flags:
memp_ARP_QUEUE/32 (memp_ARP_QUEUE) @06d42480
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: memp_stats_ARP_QUEUE/30 (addr)memp_memory_ARP_QUEUE_base/29 (addr)memp_tab_ARP_QUEUE/31 (addr)
  Referring: memp_pools/61 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
memp_tab_ARP_QUEUE/31 (memp_tab_ARP_QUEUE) @06d423a8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: memp_ARP_QUEUE/32 (addr)
  Availability: available
  Varpool flags:
memp_stats_ARP_QUEUE/30 (memp_stats_ARP_QUEUE) @06d42318
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: memp_ARP_QUEUE/32 (addr)
  Availability: available
  Varpool flags:
memp_memory_ARP_QUEUE_base/29 (memp_memory_ARP_QUEUE_base) @06d42288
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: memp_ARP_QUEUE/32 (addr)
  Availability: available
  Varpool flags:
memp_FRAG_PBUF/28 (memp_FRAG_PBUF) @06d421b0
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: memp_stats_FRAG_PBUF/26 (addr)memp_memory_FRAG_PBUF_base/25 (addr)memp_tab_FRAG_PBUF/27 (addr)
  Referring: memp_pools/61 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
memp_tab_FRAG_PBUF/27 (memp_tab_FRAG_PBUF) @06d420d8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: memp_FRAG_PBUF/28 (addr)
  Availability: available
  Varpool flags:
memp_stats_FRAG_PBUF/26 (memp_stats_FRAG_PBUF) @06d42048
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: memp_FRAG_PBUF/28 (addr)
  Availability: available
  Varpool flags:
memp_memory_FRAG_PBUF_base/25 (memp_memory_FRAG_PBUF_base) @06d38f78
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: memp_FRAG_PBUF/28 (addr)
  Availability: available
  Varpool flags:
memp_REASSDATA/24 (memp_REASSDATA) @06d38ea0
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: memp_stats_REASSDATA/22 (addr)memp_memory_REASSDATA_base/21 (addr)memp_tab_REASSDATA/23 (addr)
  Referring: memp_pools/61 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
memp_tab_REASSDATA/23 (memp_tab_REASSDATA) @06d38dc8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: memp_REASSDATA/24 (addr)
  Availability: available
  Varpool flags:
memp_stats_REASSDATA/22 (memp_stats_REASSDATA) @06d38d38
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: memp_REASSDATA/24 (addr)
  Availability: available
  Varpool flags:
memp_memory_REASSDATA_base/21 (memp_memory_REASSDATA_base) @06d38ca8
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: memp_REASSDATA/24 (addr)
  Availability: available
  Varpool flags:
memp_TCP_SEG/20 (memp_TCP_SEG) @06d38bd0
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: memp_stats_TCP_SEG/18 (addr)memp_memory_TCP_SEG_base/17 (addr)memp_tab_TCP_SEG/19 (addr)
  Referring: memp_pools/61 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
memp_tab_TCP_SEG/19 (memp_tab_TCP_SEG) @06d38af8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: memp_TCP_SEG/20 (addr)
  Availability: available
  Varpool flags:
memp_stats_TCP_SEG/18 (memp_stats_TCP_SEG) @06d38a68
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: memp_TCP_SEG/20 (addr)
  Availability: available
  Varpool flags:
memp_memory_TCP_SEG_base/17 (memp_memory_TCP_SEG_base) @06d389d8
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: memp_TCP_SEG/20 (addr)
  Availability: available
  Varpool flags:
memp_TCP_PCB_LISTEN/16 (memp_TCP_PCB_LISTEN) @06d38900
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: memp_stats_TCP_PCB_LISTEN/14 (addr)memp_memory_TCP_PCB_LISTEN_base/13 (addr)memp_tab_TCP_PCB_LISTEN/15 (addr)
  Referring: memp_pools/61 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
memp_tab_TCP_PCB_LISTEN/15 (memp_tab_TCP_PCB_LISTEN) @06d38828
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: memp_TCP_PCB_LISTEN/16 (addr)
  Availability: available
  Varpool flags:
memp_stats_TCP_PCB_LISTEN/14 (memp_stats_TCP_PCB_LISTEN) @06d38798
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: memp_TCP_PCB_LISTEN/16 (addr)
  Availability: available
  Varpool flags:
memp_memory_TCP_PCB_LISTEN_base/13 (memp_memory_TCP_PCB_LISTEN_base) @06d38708
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: memp_TCP_PCB_LISTEN/16 (addr)
  Availability: available
  Varpool flags:
memp_TCP_PCB/12 (memp_TCP_PCB) @06d38630
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: memp_stats_TCP_PCB/10 (addr)memp_memory_TCP_PCB_base/9 (addr)memp_tab_TCP_PCB/11 (addr)
  Referring: memp_pools/61 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
memp_tab_TCP_PCB/11 (memp_tab_TCP_PCB) @06d38558
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: memp_TCP_PCB/12 (addr)
  Availability: available
  Varpool flags:
memp_stats_TCP_PCB/10 (memp_stats_TCP_PCB) @06d384c8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: memp_TCP_PCB/12 (addr)
  Availability: available
  Varpool flags:
memp_memory_TCP_PCB_base/9 (memp_memory_TCP_PCB_base) @06d38438
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: memp_TCP_PCB/12 (addr)
  Availability: available
  Varpool flags:
memp_UDP_PCB/8 (memp_UDP_PCB) @06d38360
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: memp_stats_UDP_PCB/6 (addr)memp_memory_UDP_PCB_base/5 (addr)memp_tab_UDP_PCB/7 (addr)
  Referring: memp_pools/61 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
memp_tab_UDP_PCB/7 (memp_tab_UDP_PCB) @06d38288
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: memp_UDP_PCB/8 (addr)
  Availability: available
  Varpool flags:
memp_stats_UDP_PCB/6 (memp_stats_UDP_PCB) @06d381f8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: memp_UDP_PCB/8 (addr)
  Availability: available
  Varpool flags:
memp_memory_UDP_PCB_base/5 (memp_memory_UDP_PCB_base) @06d38168
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: memp_UDP_PCB/8 (addr)
  Availability: available
  Varpool flags:
memp_RAW_PCB/4 (memp_RAW_PCB) @06d38090
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: memp_stats_RAW_PCB/2 (addr)memp_memory_RAW_PCB_base/1 (addr)memp_tab_RAW_PCB/3 (addr)
  Referring: memp_pools/61 (addr)
  Availability: available
  Varpool flags: initialized read-only const-value-known
memp_tab_RAW_PCB/3 (memp_tab_RAW_PCB) @06d29f78
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: memp_RAW_PCB/4 (addr)
  Availability: available
  Varpool flags:
memp_stats_RAW_PCB/2 (memp_stats_RAW_PCB) @06d29ee8
  Type: variable definition analyzed
  Visibility: prevailing_def_ironly
  References: 
  Referring: memp_RAW_PCB/4 (addr)
  Availability: available
  Varpool flags:
memp_memory_RAW_PCB_base/1 (memp_memory_RAW_PCB_base) @06d29e58
  Type: variable definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: memp_RAW_PCB/4 (addr)
  Availability: available
  Varpool flags:

;; Function do_memp_malloc_pool (do_memp_malloc_pool, funcdef_no=3, decl_uid=7949, cgraph_uid=4, symbol_order=64)

Modification phase of node do_memp_malloc_pool/64
do_memp_malloc_pool (const struct memp_desc * desc)
{
  struct memp * memp;
  struct memp * * _1;
  void * _2;
  struct memp * _3;
  unsigned int memp.1_4;
  unsigned int _5;
  struct stats_mem * _6;
  long unsigned int _7;
  long unsigned int _8;
  long unsigned int _11;
  void * _12;

  <bb 2> [local count: 191173]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = desc_16(D)->tab;
  memp_17 = *_1;
  # DEBUG memp => memp_17
  # DEBUG BEGIN_STMT
  if (memp_17 != 0B)
    goto <bb 3>; [85.10%]
  else
    goto <bb 8>; [14.90%]

  <bb 3> [local count: 162688]:
  # DEBUG BEGIN_STMT
  _3 = memp_17->next;
  *_1 = _3;
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  memp.1_4 = (unsigned int) memp_17;
  _5 = memp.1_4 & 15;
  if (_5 != 0)
    goto <bb 10>; [66.00%]
  else
    goto <bb 5>; [34.00%]

  <bb 10> [local count: 107374]:

  <bb 4> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 11> [local count: 1073741824]:
  goto <bb 4>; [100.00%]

  <bb 5> [local count: 55314]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _6 = desc_16(D)->stats;
  _7 = _6->used;
  _8 = _7 + 1;
  _6->used = _8;
  # DEBUG BEGIN_STMT
  _11 = _6->max;
  if (_8 > _11)
    goto <bb 6>; [50.00%]
  else
    goto <bb 7>; [50.00%]

  <bb 6> [local count: 27657]:
  # DEBUG BEGIN_STMT
  _6->max = _8;

  <bb 7> [local count: 55314]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  goto <bb 9>; [100.00%]

  <bb 8> [local count: 28485]:
  _2 = do_memp_malloc_pool.part.0 (desc_16(D));

  <bb 9> [local count: 83799]:
  # _12 = PHI <memp_17(7), _2(8)>
  return _12;

}



;; Function do_memp_free_pool (do_memp_free_pool, funcdef_no=6, decl_uid=7963, cgraph_uid=7, symbol_order=67)

Modification phase of node do_memp_free_pool/67
do_memp_free_pool (const struct memp_desc * desc, void * mem)
{
  unsigned int mem.2_1;
  unsigned int _2;

  <bb 2> [local count: 214748]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  mem.2_1 = (unsigned int) mem_5(D);
  _2 = mem.2_1 & 15;
  if (_2 != 0)
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
  do_memp_free_pool.part.0 (desc_7(D), mem_5(D));
  return;

}



;; Function memp_init_pool (memp_init_pool, funcdef_no=1, decl_uid=6255, cgraph_uid=2, symbol_order=62)

Modification phase of node memp_init_pool/62
memp_init_pool (const struct memp_desc * desc)
{
  struct memp * memp;
  int i;
  struct memp * * _1;
  u8_t * _2;
  unsigned int _3;
  unsigned int _4;
  unsigned int _5;
  struct memp * _6;
  short unsigned int _7;
  sizetype _8;
  short unsigned int _9;
  int _10;
  short unsigned int _11;
  struct stats_mem * _12;
  long unsigned int _13;

  <bb 2> [local count: 118111600]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = desc_18(D)->tab;
  *_1 = 0B;
  # DEBUG BEGIN_STMT
  _2 = desc_18(D)->base;
  _3 = (unsigned int) _2;
  _4 = _3 + 15;
  _5 = _4 & 4294967280;
  memp_20 = (struct memp *) _5;
  # DEBUG memp => memp_20
  # DEBUG BEGIN_STMT
  # DEBUG i => 0
  goto <bb 4>; [100.00%]

  <bb 3> [local count: 955630223]:
  # DEBUG BEGIN_STMT
  _6 = *_1;
  memp_15->next = _6;
  # DEBUG BEGIN_STMT
  *_1 = memp_15;
  # DEBUG BEGIN_STMT
  _7 = desc_18(D)->size;
  _8 = (sizetype) _7;
  memp_24 = memp_15 + _8;
  # DEBUG memp => memp_24
  # DEBUG BEGIN_STMT
  i_25 = i_14 + 1;
  # DEBUG i => i_25

  <bb 4> [local count: 1073741824]:
  # i_14 = PHI <0(2), i_25(3)>
  # memp_15 = PHI <memp_20(2), memp_24(3)>
  # DEBUG memp => memp_15
  # DEBUG i => i_14
  # DEBUG BEGIN_STMT
  _9 = desc_18(D)->num;
  _10 = (int) _9;
  if (_10 > i_14)
    goto <bb 3>; [89.00%]
  else
    goto <bb 5>; [11.00%]

  <bb 5> [local count: 118111601]:
  # _11 = PHI <_9(4)>
  # DEBUG BEGIN_STMT
  _12 = desc_18(D)->stats;
  _13 = (long unsigned int) _11;
  _12->avail = _13;
  return;

}



;; Function memp_init (memp_init, funcdef_no=2, decl_uid=6386, cgraph_uid=3, symbol_order=63)

Modification phase of node memp_init/63
memp_init ()
{
  u16_t i;
  int _1;
  const struct memp_desc * _2;
  struct stats_mem * _3;

  <bb 2> [local count: 67108864]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG i => 0
  goto <bb 4>; [100.00%]

  <bb 3> [local count: 1006632961]:
  # DEBUG BEGIN_STMT
  _1 = (int) i_4;
  _2 = memp_pools[_1];
  memp_init_pool (_2);
  # DEBUG BEGIN_STMT
  _3 = _2->stats;
  lwip_stats.memp[_1] = _3;
  # DEBUG BEGIN_STMT
  i_9 = i_4 + 1;
  # DEBUG i => i_9

  <bb 4> [local count: 1073741824]:
  # i_4 = PHI <0(2), i_9(3)>
  # DEBUG i => i_4
  # DEBUG BEGIN_STMT
  if (i_4 != 15)
    goto <bb 3>; [93.75%]
  else
    goto <bb 5>; [6.25%]

  <bb 5> [local count: 67108864]:
  return;

}



;; Function memp_malloc_pool (memp_malloc_pool, funcdef_no=4, decl_uid=6257, cgraph_uid=5, symbol_order=65)

Modification phase of node memp_malloc_pool/65
memp_malloc_pool (const struct memp_desc * desc)
{
  void * _5;

  <bb 2> [local count: 230763]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (desc_2(D) == 0B)
    goto <bb 5>; [46.53%]
  else
    goto <bb 4>; [53.47%]

  <bb 5> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 6> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 123389]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _5 = do_memp_malloc_pool (desc_2(D));
  return _5;

}



;; Function memp_malloc (memp_malloc, funcdef_no=5, decl_uid=6388, cgraph_uid=6, symbol_order=66)

Modification phase of node memp_malloc/66
memp_malloc (memp_t type)
{
  void * memp;
  int _1;
  const struct memp_desc * _2;
  void * _3;

  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (type_5(D) > 14)
    goto <bb 4>; [29.93%]
  else
    goto <bb 3>; [70.07%]

  <bb 3> [local count: 752370897]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  _1 = (int) type_5(D);
  _2 = memp_pools[_1];
  memp_8 = do_memp_malloc_pool (_2);
  # DEBUG memp => memp_8
  # DEBUG BEGIN_STMT

  <bb 4> [local count: 1073741824]:
  # _3 = PHI <0B(2), memp_8(3)>
  return _3;

}



;; Function memp_free_pool (memp_free_pool, funcdef_no=7, decl_uid=6260, cgraph_uid=8, symbol_order=68)

Modification phase of node memp_free_pool/68
memp_free_pool (const struct memp_desc * desc, void * mem)
{
  <bb 2> [local count: 357913]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (desc_3(D) == 0B)
    goto <bb 7>; [30.00%]
  else
    goto <bb 4>; [70.00%]

  <bb 7> [local count: 107374]:

  <bb 3> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  __asm__ __volatile__("BKPT #0
	");
  # DEBUG BEGIN_STMT

  <bb 8> [local count: 1073741824]:
  goto <bb 3>; [100.00%]

  <bb 4> [local count: 250539]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (mem_5(D) == 0B)
    goto <bb 6>; [30.95%]
  else
    goto <bb 5>; [69.05%]

  <bb 5> [local count: 172997]:
  # DEBUG BEGIN_STMT
  do_memp_free_pool (desc_3(D), mem_5(D));

  <bb 6> [local count: 250539]:
  return;

}



;; Function memp_free (memp_free, funcdef_no=8, decl_uid=6391, cgraph_uid=9, symbol_order=69)

Modification phase of node memp_free/69
memp_free (memp_t type, void * mem)
{
  int _1;
  const struct memp_desc * _2;

  <bb 2> [local count: 1073741823]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (type_4(D) > 14)
    goto <bb 5>; [34.00%]
  else
    goto <bb 3>; [66.00%]

  <bb 3> [local count: 708669604]:
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  if (mem_5(D) == 0B)
    goto <bb 5>; [30.95%]
  else
    goto <bb 4>; [69.05%]

  <bb 4> [local count: 489336361]:
  # DEBUG BEGIN_STMT
  _1 = (int) type_4(D);
  _2 = memp_pools[_1];
  do_memp_free_pool (_2, mem_5(D));

  <bb 5> [local count: 1073741824]:
  return;

}


