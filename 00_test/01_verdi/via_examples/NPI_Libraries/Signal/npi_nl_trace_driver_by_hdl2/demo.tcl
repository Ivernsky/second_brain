proc driver_load_demo { hdl cb } {
  set hdlList {}
  
  puts "== [ ::npi_L1::npi_nl_ut_get_hdl_info $hdl ] =="
  puts "Drivers:"
  ::npi_L1::npi_nl_trace_driver_by_hdl2 $hdl "hdlList"
  ::npi_L1::npi_nl_ut_dump_hdl_vec_info "hdlList" "stdout" 1
  puts "Loads:"
  ::npi_L1::npi_nl_trace_load_by_hdl2 $hdl "hdlList"
  ::npi_L1::npi_nl_ut_dump_hdl_vec_info "hdlList" "stdout" 1
}

source $env(NPIL1_PATH)/npi_L1.tcl
schSetPreference -detailLevel 100 -detailRTL on -detailMux on -recogFSM off -expandGenBlock on

#debImport "-sv" "example.v"

::npi_L1::npi_nl_hier_tree_trv_register_cb "npiNlDeclNet"  "driver_load_demo" ""
::npi_L1::npi_nl_hier_tree_trv_register_cb "npiNlPort"     "driver_load_demo" ""
::npi_L1::npi_nl_hier_tree_trv_register_cb "npiNlInstPort" "driver_load_demo" ""
::npi_L1::npi_nl_hier_tree_trv

debExit

