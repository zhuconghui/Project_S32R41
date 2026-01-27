
IPA constant propagation start:

IPA structures before propagation:

Jump functions:
  Jump functions of caller  sys_timeouts_init/10:
  Jump functions of caller  dns_init/9:
  Jump functions of caller  igmp_init/8:
  Jump functions of caller  tcp_init/7:
  Jump functions of caller  udp_init/6:
  Jump functions of caller  netif_init/5:
  Jump functions of caller  memp_init/4:
  Jump functions of caller  mem_init/3:
  Jump functions of caller  stats_init/2:
  Jump functions of caller  lwip_init/1:

 Propagating constants:

Not considering lwip_init for cloning; -fipa-cp-clone disabled.

overall_size: 12, max_new_size: 11001

IPA lattices after all propagation:

Lattices:
  Node: lwip_init/1:

IPA decision stage:


IPA constant propagation end

Reclaiming functions:
Reclaiming variables:
Clearing address taken flags:
Symbol table:

sys_timeouts_init/10 (sys_timeouts_init) @06e707e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: lwip_init/1 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
dns_init/9 (dns_init) @06e70700
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: lwip_init/1 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
igmp_init/8 (igmp_init) @06e70620
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: lwip_init/1 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
tcp_init/7 (tcp_init) @06e70540
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: lwip_init/1 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
udp_init/6 (udp_init) @06e70460
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: lwip_init/1 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
netif_init/5 (netif_init) @06e70380
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: lwip_init/1 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
memp_init/4 (memp_init) @06e702a0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: lwip_init/1 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
mem_init/3 (mem_init) @06e701c0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: lwip_init/1 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
stats_init/2 (stats_init) @06e700e0
  Type: function
  Visibility: external public
  References: 
  Referring: 
  Availability: not_available
  Function flags: optimize_size
  Called by: lwip_init/1 (1073741824 (estimated locally),1.00 per call) 
  Calls: 
lwip_init/1 (lwip_init) @06e5fd20
  Type: function definition analyzed
  Visibility: externally_visible public
  References: 
  Referring: 
  Availability: available
  Function flags: count:1073741824 (estimated locally) body optimize_size
  Called by: 
  Calls: sys_timeouts_init/10 (1073741824 (estimated locally),1.00 per call) dns_init/9 (1073741824 (estimated locally),1.00 per call) igmp_init/8 (1073741824 (estimated locally),1.00 per call) tcp_init/7 (1073741824 (estimated locally),1.00 per call) udp_init/6 (1073741824 (estimated locally),1.00 per call) netif_init/5 (1073741824 (estimated locally),1.00 per call) memp_init/4 (1073741824 (estimated locally),1.00 per call) mem_init/3 (1073741824 (estimated locally),1.00 per call) stats_init/2 (1073741824 (estimated locally),1.00 per call) 

;; Function lwip_init (lwip_init, funcdef_no=1, decl_uid=6215, cgraph_uid=2, symbol_order=1)

Modification phase of node lwip_init/1
lwip_init ()
{
  <bb 2> [local count: 1073741824]:
  # DEBUG BEGIN_STMT
  # DEBUG a => 0
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  stats_init ();
  # DEBUG BEGIN_STMT
  mem_init ();
  # DEBUG BEGIN_STMT
  memp_init ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  netif_init ();
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  # DEBUG BEGIN_STMT
  udp_init ();
  # DEBUG BEGIN_STMT
  tcp_init ();
  # DEBUG BEGIN_STMT
  igmp_init ();
  # DEBUG BEGIN_STMT
  dns_init ();
  # DEBUG BEGIN_STMT
  sys_timeouts_init ();
  # DEBUG D#1 => {CLOBBER}
  # DEBUG a => D#1
  return;

}


