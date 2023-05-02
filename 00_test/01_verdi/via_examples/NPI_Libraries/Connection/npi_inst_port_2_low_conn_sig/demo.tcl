source $env(NPIL1_PATH)/npi_L1.tcl

#debImport -sv example.v

set port2sigList {}
::npi_L1::npi_inst_port_2_low_conn_sig "TOP.inst" "port2sigList"

set numbetOfPort [ llength $port2sigList ]
for { set i 0 } { $i < $numbetOfPort } { incr i } {
  set port2SigPair [ lindex $port2sigList $i ]
  set portHdl [ lindex $port2SigPair 0 ]
  set sigHdlList [ lindex $port2SigPair 1 ]
  ::npi_L1::npi_sv_ut_dump_hdl_info $portHdl "stdout"
  ::npi_L1::npi_sv_ut_dump_hdl_vec_info "sigHdlList" "stdout"
}

debExit
