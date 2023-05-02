source $env(NPIL1_PATH)/npi_L1.tcl

schSetPreference -detailRTL on -detailMux on -recogFSM off -expandGenBlock on
#debImport -sv example.v

proc cb_func_obj_count { hdl cb } {
  upvar $cb pCnt
  incr pCnt
  ::npi_L1::npi_nl_ut_dump_hdl_info $hdl "stdout"
}

set cd_list ""
set instCnt 0
set portCnt 0
# register callback funcation and data
::npi_L1::npi_nl_hier_tree_trv_register_cb "npiNlInst" "cb_func_obj_count" "instCnt"
::npi_L1::npi_nl_hier_tree_trv_register_cb "npiNlPort" "cb_func_obj_count" "portCnt"
# traverse the design from scope "top"
::npi_L1::npi_nl_hier_tree_trv "top"
# dump the result
puts "Found $instCnt modules and $portCnt ports"

# reset the callback function and traverse again
set instCnt 0
set portCnt 0
::npi_L1::npi_nl_hier_tree_trv_reset_cb
::npi_L1::npi_nl_hier_tree_trv "top"
# callback data is unchanged
puts "Found $instCnt modules and $portCnt ports"

debExit
