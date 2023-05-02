
# DM Operation
set top [npi_dm_handle_by_name -name "top" -scope ""]
set m [npi_dm_handle_by_name -name "m" -scope ""]

set tf_iter [npi_dm_iter_start -type npiDmTaskFunc -ref $top]
while { "" != [set tf_hdl [npi_dm_iter_next -iter $tf_iter]] } {
  if { "npiDmFunction" == [npi_dm_property_str -type npiDmType -ref $tf_hdl] } {
    if { "func1" == [npi_dm_property_str -type npiDmName -ref $tf_hdl] } {
      set func1_hdl $tf_hdl
    }
    if { "func2" == [npi_dm_property_str -type npiDmName -ref $tf_hdl] } {
      set func2_hdl $tf_hdl
    }
    if { "func3" == [npi_dm_property_str -type npiDmName -ref $tf_hdl] } {
      set func3_hdl $tf_hdl
    }
  }
}
set tf_iter [npi_dm_iter_start -type npiDmTaskFunc -ref $m]
while { "" != [set tf_hdl [npi_dm_iter_next -iter $tf_iter]] } {
  if { "npiDmFunction" == [npi_dm_property_str -type npiDmType -ref $tf_hdl] } {
    if { "func1" == [npi_dm_property_str -type npiDmName -ref $tf_hdl] } {
      set m_func1_hdl $tf_hdl
    }
  }
}

npi_dm_iter_stop -iter $tf_iter

set func1_arg1 [npi_dm_handle_by_name -name "f_a" -scope $func1_hdl]
set func1_arg2 [npi_dm_handle_by_name -name "f_b" -scope $func1_hdl]

set func2_arg1 [npi_dm_handle_by_name -name "x" -scope $func2_hdl]
set func2_arg2 [npi_dm_handle_by_name -name "y" -scope $func2_hdl]
set func2_arg3 [npi_dm_handle_by_name -name "z" -scope $func2_hdl]


set a [npi_dm_handle_by_name -name "a" -scope $top]
set b [npi_dm_handle_by_name -name "b" -scope $top]
set c [npi_dm_handle_by_name -name "c" -scope $top]
set d [npi_dm_handle_by_name -name "d" -scope $top]


############ prepare function_call_1 argument instance #############
set func1_call_1_arg1 [npi_dm_create_argument_instance -formal $func1_arg1 -actual $a]
set func1_call_1_arg2 [npi_dm_create_argument_instance -formal $func1_arg2 -actual $b]
set arg_array_func1_call_1 [npi_dm_create_npiDmHandleArray -array_list "$func1_call_1_arg1 $func1_call_1_arg2"]
##########################################################

set function_call_1 [npi_dm_create_function_call -scope $top -function $func1_hdl -array $arg_array_func1_call_1]

############ prepare function_call_2 argument instance #############
set null_expr_array [npi_dm_create_npiDmHandleArray -array_list ""]
set null_op [npi_dm_create_operation -type "npiDmOpNull" -array $null_expr_array]
set func1_call_2_arg1 [npi_dm_create_argument_instance -formal $func1_arg1 -actual $null_op]
set func1_call_2_arg2 [npi_dm_create_argument_instance -formal $func1_arg2 -actual $b]
set arg_array_func1_call_2 [npi_dm_create_npiDmHandleArray -array_list "$func1_call_2_arg1 $func1_call_2_arg2"]
##########################################################

set function_call_2 [npi_dm_create_function_call -scope $top -function $func1_hdl -array $arg_array_func1_call_2]

############ prepare function_call_3 argument instance #############
set const_12 [npi_dm_create_constant -value "12"]
set const_null [npi_dm_create_constant -value "null"]
set func2_call_1_arg1 [npi_dm_create_argument_instance -formal $func2_arg1 -actual $null_op]
set func2_call_1_arg2 [npi_dm_create_argument_instance -formal $func2_arg2 -actual $const_12]
set func2_call_1_arg3 [npi_dm_create_argument_instance -formal $func2_arg3 -actual $const_null]
set arg_array_func2_call_1 [npi_dm_create_npiDmHandleArray -array_list "$func2_call_1_arg1 $func2_call_1_arg2 $func2_call_1_arg3"]
##########################################################

set function_call_3 [npi_dm_create_function_call -scope $top -function $func2_hdl -array $arg_array_func2_call_1]

############ prepare function_call_4 argument instance #############
set func3_call_1_arg1 [npi_dm_create_argument_instance -formal "" -actual $null_op]
set empty_expr_array [npi_dm_create_npiDmHandleArray -array_list "$func3_call_1_arg1"]
##########################################################

set function_call_4 [npi_dm_create_function_call -scope $top -function $func3_hdl -array $empty_expr_array]

############ prepare function_call_5 argument instance #############
# create ref m
set m_func1_ref_m [npi_dm_create_ref -actual $m -array ""]
# create ref func1
set m_func1_ref_func1 [npi_dm_create_ref -actual $m_func1_hdl -array ""]
# create hier ref m.func1
set m_func1_hier_array [npi_dm_create_npiDmHandleArray -array_list "$m_func1_ref_m $m_func1_ref_func1"]
set m_func1_hier_1 [npi_dm_create_hier_ref -array $m_func1_hier_array]
set m_func1_call_1_arg1 [npi_dm_create_argument_instance -formal "" -actual $null_op]
set empty_expr_array [npi_dm_create_npiDmHandleArray -array_list "$m_func1_call_1_arg1"]
##########################################################

set function_call_5 [npi_dm_create_function_call -scope $top -function $m_func1_hier_1 -array $empty_expr_array]

set assign_1 [npi_dm_make_assign_connection -scope $top -lhs $c -rhs $function_call_1]
set assign_2 [npi_dm_make_assign_connection -scope $top -lhs $c -rhs $function_call_2]
set assign_3 [npi_dm_make_assign_connection -scope $top -lhs $d -rhs $function_call_3]
set assign_4 [npi_dm_make_assign_connection -scope $top -lhs $c -rhs $function_call_4]
set assign_5 [npi_dm_make_assign_connection -scope $top -lhs $c -rhs $function_call_5]

# Write to directory "DM_LIB"
npi_dm_write_text_mode -dir DM_LIB

debExit

