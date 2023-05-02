source $env(NPIL1_PATH)/npi_L1.tcl

schSetPreference -detailRTL on -detailMux on -recogFSM off -expandGenBlock on
#debImport -sv example.v

proc cb_func_collect_obj { hdl cb } {
  upvar $cb pHdlList
  lappend pHdlList $hdl
  # set permanent to preserve the handle
  npi_nl_set_permanent_handle -object $hdl
}

proc dump_handle_result { instHdlList portHdlList } {
  set instListLen [llength $instHdlList]
  for {set i 0} {$i < $instListLen} {incr i} {
    ::npi_L1::npi_nl_ut_dump_hdl_info [lindex $instHdlList $i] "stdout"
  }
  set portListLen [llength $portHdlList]
  for {set i 0} {$i < $portListLen} {incr i} {
    ::npi_L1::npi_nl_ut_dump_hdl_info [lindex $portHdlList $i] "stdout"
  }
  puts "Found $instListLen instances and $portListLen ports"
}

set instHdlList ""
set portHdlList ""
# register callback funcation and data
::npi_L1::npi_nl_hier_tree_trv_register_cb "npiNlInst" "cb_func_collect_obj" "instHdlList"
::npi_L1::npi_nl_hier_tree_trv_register_cb "npiNlPort" "cb_func_collect_obj" "portHdlList"
# traverse the design from scope "top"
::npi_L1::npi_nl_hier_tree_trv "top"
# dump the result
dump_handle_result $instHdlList $portHdlList

# reset the callback function and traverse again
set instHdlList ""
set portHdlList ""
::npi_L1::npi_nl_hier_tree_trv_reset_cb
::npi_L1::npi_nl_hier_tree_trv "top"
# callback data is unchanged
dump_handle_result $instHdlList $portHdlList

# release all handles (including permanent handles)
npi_nl_release_all_handles

debExit
