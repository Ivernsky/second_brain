
# DM Operation
set top [npi_dm_handle_by_name -name "top" -scope ""]

set a [npi_dm_handle_by_name -name "a" -scope $top]
set call_1_arg1 [npi_dm_create_argument_instance -formal "" -actual $a]
set call_1_arg_array [npi_dm_create_npiDmHandleArray -array_list "$call_1_arg1"]
set sys_tf_call_1 [npi_dm_create_system_function_call -scope $top -name "\$bits" -array $call_1_arg_array]

set null_expr_array [npi_dm_create_npiDmHandleArray -array_list ""]
set null_op [npi_dm_create_operation -type "npiDmOpNull" -array "$null_expr_array"]
set call_2_arg1 [npi_dm_create_argument_instance -formal "" -actual $null_op]
set call_2_arg_array [npi_dm_create_npiDmHandleArray -array_list "$call_2_arg1"]
set sys_tf_call_2 [npi_dm_create_system_function_call -scope $top -name "\$bits" -array $call_2_arg_array]

set c [npi_dm_handle_by_name -name "c" -scope $top]

set assign [npi_dm_make_assign_connection -scope $top -lhs $c -rhs $sys_tf_call_1]
set assign [npi_dm_make_assign_connection -scope $top -lhs $c -rhs $sys_tf_call_2]

# Write to directory "DM_LIB"
npi_dm_write_text_mode -dir DM_LIB

debExit

