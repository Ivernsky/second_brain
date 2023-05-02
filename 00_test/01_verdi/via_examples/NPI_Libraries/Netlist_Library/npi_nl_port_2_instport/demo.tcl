source $env(NPIL1_PATH)/npi_L1.tcl

schSetPreference -detailRTL on -detailMux on -recogFSM off -expandGenBlock on
#debImport -sv example.v

proc act_port { hdl cb } {
  if { [ set instportHdl [ ::npi_L1::npi_nl_port_2_instport $hdl ] ] != "" } {
    puts "npi_nl_port_2_instport:"
    ::npi_L1::npi_nl_ut_dump_hdl_info $hdl "stdout"
    ::npi_L1::npi_nl_ut_dump_hdl_info $instportHdl "stdout"
    puts ""
  }
}

# register callback funcation and data
::npi_L1::npi_nl_hier_tree_trv_register_cb "npiNlPort" "act_port" ""
# traverse the design from $root
::npi_L1::npi_nl_hier_tree_trv ""

debExit
