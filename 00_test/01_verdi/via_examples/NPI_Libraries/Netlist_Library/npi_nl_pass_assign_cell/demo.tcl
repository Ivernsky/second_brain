source $env(NPIL1_PATH)/npi_L1.tcl

schSetPreference -detailRTL on -detailMux on -recogFSM off -expandGenBlock on
#debImport -sv example.v

proc act_inst { hdl cb } {
  if { [ npi_nl_get_str -property npiNlCellType -object $hdl ] != "npiNlAssignCell" } {
    return
  }
  puts -nonewline "Found npiNlAssignCell:\n  "
  ::npi_L1::npi_nl_ut_dump_hdl_info $hdl "stdout"
  
  set itr [ npi_nl_iterate -type npiNlInstPort -refHandle $hdl ]
  while { [ set subHdl1 [ npi_nl_scan -iterator $itr ] ] != "" } {
    set subHdl2 [ ::npi_L1::npi_nl_pass_assign_cell $subHdl1 ]
    puts -nonewline "From instport:\n  "
    ::npi_L1::npi_nl_ut_dump_hdl_info $subHdl1 "stdout"
    puts -nonewline "To instport:\n  "
    ::npi_L1::npi_nl_ut_dump_hdl_info $subHdl2 "stdout"
  }
}

# register callback funcation and data
::npi_L1::npi_nl_hier_tree_trv_register_cb "npiNlInst" "act_inst" ""
# traverse the design from $root
::npi_L1::npi_nl_hier_tree_trv ""

debExit
