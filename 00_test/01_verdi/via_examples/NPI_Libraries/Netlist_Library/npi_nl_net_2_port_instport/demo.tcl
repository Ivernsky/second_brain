source $env(NPIL1_PATH)/npi_L1.tcl

schSetPreference -detailRTL on -detailMux on -recogFSM off -expandGenBlock on
#debImport -sv example.v

proc act_net { hdl cb } {
  set hdlList {}
  if { [ ::npi_L1::npi_nl_net_2_port_instport $hdl "hdlList" ] != 0 } {
    puts "npi_nl_net_2_port_instport:"
    ::npi_L1::npi_nl_ut_dump_hdl_info $hdl "stdout"
    ::npi_L1::npi_nl_ut_dump_hdl_vec_info "hdlList" "stdout"
    puts ""
  }
}

# register callback funcation and data
::npi_L1::npi_nl_hier_tree_trv_register_cb "npiNlDeclNet" "act_net" ""
::npi_L1::npi_nl_hier_tree_trv_register_cb "npiNlConcatNet" "act_net" ""
::npi_L1::npi_nl_hier_tree_trv_register_cb "npiNlSliceNet" "act_net" ""
# traverse the design from $root
::npi_L1::npi_nl_hier_tree_trv ""

debExit
