source $env(NPIL1_PATH)/npi_L1.tcl

#debImport -sv example.v

proc cb_func_obj_count { hdl cb } {
  upvar $cb pCnt
  incr pCnt
  ::npi_L1::npi_sv_ut_dump_hdl_info $hdl "stdout"
}

set cd_list ""
set modCnt 0
set portCnt 0
# register callback funcation and data
::npi_L1::npi_hier_tree_trv_register_cb "npiModule" "cb_func_obj_count" "modCnt"
::npi_L1::npi_hier_tree_trv_register_cb "npiPort" "cb_func_obj_count" "portCnt"
# traverse the design from scope "top"
::npi_L1::npi_hier_tree_trv "top"
# dump the result
puts "Found $modCnt modules and $portCnt ports"

# reset the callback function and traverse again
set modCnt 0
set portCnt 0
::npi_L1::npi_hier_tree_trv_reset_cb
::npi_L1::npi_hier_tree_trv "top"
# callback data is unchanged
puts "Found $modCnt modules and $portCnt ports"

debExit
