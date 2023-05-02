proc driver_demo { hdl cb } {
  puts "== [ ::npi_L1::npi_nl_ut_get_hdl_info $hdl ] ==\n"
  set size [ ::npi_L1::npi_nl_bit_trace_driver_by_hdl_dump $hdl "stdout" ]
  puts "== Total $size drivers ==\n"
}

source $env(NPIL1_PATH)/npi_L1.tcl
schSetPreference -detailLevel 100 -detailRTL on -detailMux on -recogFSM off -expandGenBlock on

#debImport "-sv" "example.v"

::npi_L1::npi_nl_hier_tree_trv_register_cb "npiNlDeclNet"  "driver_demo" ""
::npi_L1::npi_nl_hier_tree_trv_register_cb "npiNlPort"     "driver_demo" ""
::npi_L1::npi_nl_hier_tree_trv_register_cb "npiNlInstPort" "driver_demo" ""
::npi_L1::npi_nl_hier_tree_trv

debExit

