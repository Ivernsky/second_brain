source $env(NPIL1_PATH)/npi_L1.tcl

schSetPreference -detailRTL on -detailMux on -recogFSM off -expandGenBlock on
#debImport -sv example.v

proc act_instport { hdl cb } {
  if { [ set portHdl [ ::npi_L1::npi_nl_instport_2_port $hdl ] ] != "" } {
    puts "npi_nl_instport_2_port:"
    ::npi_L1::npi_nl_ut_dump_hdl_info $hdl "stdout"
    ::npi_L1::npi_nl_ut_dump_hdl_info $portHdl "stdout"
    puts ""
  }
}

# register callback funcation and data
::npi_L1::npi_nl_hier_tree_trv_register_cb "npiNlInstPort" "act_instport" ""
# traverse the design from $root
::npi_L1::npi_nl_hier_tree_trv ""

debExit
