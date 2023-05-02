
############# dump task call info ###############
proc dump_task_call { target_hdl } {
  set fd [open result.log a]

  set scope_hdl [npi_dm_handle -type "npiDmScope" -ref $target_hdl]
  set scope_name [npi_dm_property_str -type "npiDmName" -ref $scope_hdl]
  puts $fd "scope = $scope_name"
  set task_call_type [npi_dm_property_str -type "npiDmType" -ref $target_hdl]
  puts $fd "type = $task_call_type"
  set task_call_name [npi_dm_property_str -type "npiDmName" -ref $target_hdl]
  puts $fd "name = $task_call_name"
  if { $task_call_type == "npiDmTaskCall" } {
    set task [npi_dm_handle -type "npiDmTask" -ref $target_hdl]
    set task_name [npi_dm_property_str -type "npiDmName" -ref $task]
    puts $fd "full task name = $task_name"
  }
  set arg_iter [npi_dm_iter_start -type "npiDmArgInst" -ref $target_hdl]
  set arg_counter 1
  while { "" != [set arg [npi_dm_iter_next -iter $arg_iter]] } {
    puts $fd "  argument $arg_counter"
    if { $task_call_type == "npiDmTaskCall" } {
      set formal [npi_dm_handle -type "npiDmFormal" -ref $arg]
      set formal_name ""
      if { "" != $formal } {
        set formal_name [npi_dm_property_str -type "npiDmName" -ref $formal]
      }
      puts -nonewline $fd "    formal_arg = $formal_name"
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
set m [npi_dm_handle_by_name -name "m" -scope ""]

set tf_iter [npi_dm_iter_start -type npiDmTaskFunc -ref $top]
while { "" != [set tf_hdl [npi_dm_iter_next -iter $tf_iter]] } {
  if { "npiDmTask" == [npi_dm_property_str -type npiDmType -ref $tf_hdl] } {
    if { "task1" == [npi_dm_property_str -type npiDmName -ref $tf_hdl] } {
      set task1_hdl $tf_hdl
    }
    if { "task2" == [npi_dm_property_str -type npiDmName -ref $tf_hdl] } {
      set task2_hdl $tf_hdl
    }
    if { "task3" == [npi_dm_property_str -type npiDmName -ref $tf_hdl] } {
      set task3_hdl $tf_hdl
    }
  }
}
set tf_iter [npi_dm_iter_start -type npiDmTaskFunc -ref $m]
while { "" != [set tf_hdl [npi_dm_iter_next -iter $tf_iter]] } {
  if { "npiDmTask" == [npi_dm_property_str -type npiDmType -ref $tf_hdl] } {
    if { "task1" == [npi_dm_property_str -type npiDmName -ref $tf_hdl] } {
      set m_task1_hdl $tf_hdl
    }
  }
}

set task1_arg1 [npi_dm_handle_by_name -name "f_a" -scope $task1_hdl]
set task1_arg2 [npi_dm_handle_by_name -name "f_b" -scope $task1_hdl]
set task2_arg1 [npi_dm_handle_by_name -name "x" -scope $task2_hdl]
set task2_arg2 [npi_dm_handle_by_name -name "y" -scope $task2_hdl]
set task2_arg3 [npi_dm_handle_by_name -name "z" -scope $task2_hdl]

set a [npi_dm_handle_by_name -name "a" -scope $top]
set b [npi_dm_handle_by_name -name "b" -scope $top]

############ prepare task1_call_1 argument instance #############
set task1_call_1_arg1 [npi_dm_create_argument_instance -formal $task1_arg1 -actual $a]
set task1_call_1_arg2 [npi_dm_create_argument_instance -formal $task1_arg2 -actual $b]
set arg_array_task1_call_1 [npi_dm_create_npiDmHandleArray -array_list "$task1_call_1_arg1 $task1_call_1_arg2"]

set task1_call_1 [npi_dm_create_task_call -scope $top -task $task1_hdl -array $arg_array_task1_call_1]

############ prepare task1_call_2 argument instance #############
set null_expr_array [npi_dm_create_npiDmHandleArray -array_list ""]
set null_op [npi_dm_create_operation -type "npiDmOpNull" -array $null_expr_array]
set task1_call_2_arg1 [npi_dm_create_argument_instance -formal $task1_arg1 -actual $null_op]
set task1_call_2_arg2 [npi_dm_create_argument_instance -formal $task1_arg2 -actual $b]
set arg_array_task1_call_2 [npi_dm_create_npiDmHandleArray -array_list "$task1_call_2_arg1 $task1_call_2_arg2"]

set task1_call_2 [npi_dm_create_task_call -scope $top -task $task1_hdl -array $arg_array_task1_call_2]

############ prepare task2_call_1 argument instance #############
set const_12 [npi_dm_create_constant -value "12"]
set const_null [npi_dm_create_constant -value "null"]
set task2_call_1_arg1 [npi_dm_create_argument_instance -formal $task2_arg1 -actual $null_op]
set task2_call_1_arg2 [npi_dm_create_argument_instance -formal $task2_arg2 -actual $const_12]
set task2_call_1_arg3 [npi_dm_create_argument_instance -formal $task2_arg3 -actual $const_null]
set arg_array_task2_call_1 [npi_dm_create_npiDmHandleArray -array_list "$task2_call_1_arg1 $task2_call_1_arg2 $task2_call_1_arg3"]

set task2_call_1 [npi_dm_create_task_call -scope $top -task $task2_hdl -array $arg_array_task2_call_1]

############ prepare task3_call_1 argument instance #############
set task3_call_1_arg1 [npi_dm_create_argument_instance -formal "" -actual $null_op]
set arg_array_task3_call_1 [npi_dm_create_npiDmHandleArray -array_list "$task3_call_1_arg1"]

set task3_call_1 [npi_dm_create_task_call -scope $top -task $task3_hdl -array $arg_array_task3_call_1]

############ prepare m_task1_call_1 argument instance #############
# create ref m
set m_task1_ref_m [npi_dm_create_ref -actual $m -array ""]
# create ref task1
set m_task1_ref_task1 [npi_dm_create_ref -actual $m_task1_hdl -array ""]
# create hier ref m.task1
set m_task1_hier_array [npi_dm_create_npiDmHandleArray -array_list "$m_task1_ref_m $m_task1_ref_task1"]
set m_task1_hier_1 [npi_dm_create_hier_ref -array $m_task1_hier_array]
set m_task1_call_1_arg1 [npi_dm_create_argument_instance -formal "" -actual $null_op]
set empty_expr_array [npi_dm_create_npiDmHandleArray -array_list "$m_task1_call_1_arg1"]

set m_task1_call_1 [npi_dm_create_task_call -scope $top -task $m_task1_hier_1 -array $empty_expr_array]

##########################################################
# task1_call_1 data
dump_task_call $task1_call_1
# task1_call_2 data
dump_task_call $task1_call_2
# task2_call_1 data
dump_task_call $task2_call_1
# task3_call_1 data
dump_task_call $task3_call_1
# m_task1_call_1 data
dump_task_call $m_task1_call_1

debExit

