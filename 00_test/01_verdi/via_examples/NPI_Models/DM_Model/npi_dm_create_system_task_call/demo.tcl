#debImport -sv input.v

############# dump task call info ###############
proc dump_task_call { target_hdl } {
  set fd [open create_task_call.log a]

  set scope_hdl [npi_dm_handle -type "npiDmScope" -ref $target_hdl]
  set scope_name [npi_dm_property_str -type "npiDmName" -ref $scope_hdl]
  puts $fd "scope = $scope_name"
  set task_call_type [npi_dm_property_str -type "npiDmType" -ref $target_hdl]
  puts $fd "type = $task_call_type"
  set task_call_name [npi_dm_property_str -type "npiDmName" -ref $target_hdl]
  puts $fd "name = $task_call_name"

  set arg_iter [npi_dm_iter_start -type "npiDmArgInst" -ref $target_hdl]
  set arg_counter 1
  while { "" != [set arg [npi_dm_iter_next -iter $arg_iter]] } {
    puts $fd "  argument $arg_counter"
    if { $task_call_type == "npiDmTaskCall" } {
      set formal [npi_dm_handle -type "npiDmFormal" -ref $arg]
      set formal_name [npi_dm_property_str -type "npiDmName" -ref $formal]
      puts $fd "    formal_arg = $formal_name"
    }
    set actual [npi_dm_handle -type "npiDmActual" -ref $arg]
    set actual_name [npi_dm_property_str -type "npiDmName" -ref $actual]
    puts $fd "    actual_arg = $actual_name"
    set arg_counter [expr $arg_counter+1]
  }
  npi_dm_iter_stop -iter $arg_iter

  close $fd
}
############# end of dumpping task call info ###############

set top [npi_dm_handle_by_name -name "top" -scope ""]
set c1 [npi_dm_create_constant -value "\"%f\""]
set arg1 [npi_dm_create_argument_instance -formal "" -actual $c1]
set pi [npi_dm_handle_by_name -name "pi" -scope $top]
set arg2 [npi_dm_create_argument_instance -formal "" -actual $pi]
set arg_array [npi_dm_create_npiDmHandleArray -array_list "$arg1 $arg2"]

set sys_task_call [npi_dm_create_system_task_call -scope $top -name "\$display" -array $arg_array]
dump_task_call $sys_task_call

debExit
