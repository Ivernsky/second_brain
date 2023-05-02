source $env(NPIL1_PATH)/npi_L1.tcl
 
#debImport -sv example.v
 
proc cb_func_collect_obj { hdl cb } {
  upvar $cb pHdlList
  lappend pHdlList $hdl
  # set permanent to preserve the handle
  npi_set_permanent_handle -object $hdl
}

proc dump_handle_result { modHdlList portHdlList } {
  set modListLen [llength $modHdlList]
  for {set i 0} {$i < $modListLen} {incr i} {
    ::npi_L1::npi_sv_ut_dump_hdl_info [lindex $modHdlList $i] "stdout"
  }
  set portListLen [llength $portHdlList]
  for {set i 0} {$i < $portListLen} {incr i} {
    ::npi_L1::npi_sv_ut_dump_hdl_info [lindex $portHdlList $i] "stdout"
  }
  puts "Found $modListLen modules and $portListLen ports"
}
 
set modHdlList ""
set portHdlList ""
# register callback funcation and data
::npi_L1::npi_hier_tree_trv_register_cb "npiModule" "cb_func_collect_obj" "modHdlList"
::npi_L1::npi_hier_tree_trv_register_cb "npiPort" "cb_func_collect_obj" "portHdlList"
# traverse the design from scope "top"
::npi_L1::npi_hier_tree_trv "top"
# dump the result
dump_handle_result $modHdlList $portHdlList
 
# reset the callback function and traverse again
set modHdlList ""
set portHdlList ""
::npi_L1::npi_hier_tree_trv_reset_cb
::npi_L1::npi_hier_tree_trv "top"
# callback data is unchanged
dump_handle_result $modHdlList $portHdlList

# release all handles (including permanent handles) 
npi_release_all_handles

debExit

