source $env(NPIL1_PATH)/npi_L1.tcl

schSetPreference -detailRTL on -detailMux on -recogFSM off -expandGenBlock on
#debImport -sv example.v

proc act_port_instport { hdl cb } {
  if { [ set netHdl [ ::npi_L1::npi_nl_port_instport_2_net $hdl ] ] != "" } {
    puts "npi_nl_port_instport_2_net:"
    ::npi_L1::npi_nl_ut_dump_hdl_info $hdl "stdout"
    ::npi_L1::npi_nl_ut_dump_hdl_info $netHdl "stdout"
    puts ""
  }
}

# register callback funcation and data
::npi_L1::npi_nl_hier_tree_trv_register_cb "npiNlPort" "act_port_instport" ""
::npi_L1::npi_nl_hier_tree_trv_register_cb "npiNlInstPort" "act_port_instport" ""
# traverse the design from $root
::npi_L1::npi_nl_hier_tree_trv ""

debExit
