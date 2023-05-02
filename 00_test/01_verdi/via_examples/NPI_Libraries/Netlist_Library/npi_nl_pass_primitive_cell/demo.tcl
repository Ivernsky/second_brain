source $env(NPIL1_PATH)/npi_L1.tcl

proc test_npi_nl_pass_primitive_cell { sigName } {
  set hdlList {}
  set sigHdl [ ::npi_L1::npi_nl_sig_handle_by_name $sigName ]
  set itr [ npi_nl_iterate -type npiNlConnectivity -refHandle $sigHdl ]
  
  while { [ set pinHdl [ npi_nl_scan -iterator $itr ] ] != "" } {
    if { [ ::npi_L1::npi_nl_pass_primitive_cell $pinHdl "hdlList" ] != 0 } {
      puts "From"
      ::npi_L1::npi_nl_ut_dump_hdl_info $pinHdl "stdout"
      puts "To"
      ::npi_L1::npi_nl_ut_dump_hdl_vec_info "hdlList" "stdout" "1"
    }
    npi_nl_release_handle -object $pinHdl
  }
  npi_nl_release_handle -object $sigHdl
  puts ""
}


schSetPreference -detailRTL on -detailMux on -recogFSM off -expandGenBlock on
#debImport "-sv" "example.v"

# '|' does support bit-level tracing
test_npi_nl_pass_primitive_cell "top.a\[2:1\]"
# '+' doesn't support bit-level tracing
test_npi_nl_pass_primitive_cell "top.d\[2:1\]"

debExit

