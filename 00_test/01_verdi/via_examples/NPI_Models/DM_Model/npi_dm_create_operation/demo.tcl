# Load Design
#debImport input.v

# DM Operation
set TOP [npi_dm_module_by_name -name "TOP"]
set w1  [npi_dm_handle_by_name -name "w1" -scope $TOP]
set w2  [npi_dm_handle_by_name -name "w2" -scope $TOP]
set w3  [npi_dm_handle_by_name -name "w3" -scope $TOP]

set expr_ary [npi_dm_create_npiDmHandleArray -array_list "$w2 $w3"]
set opr [npi_dm_create_operation -type "npiDmOpConcat" -array $expr_ary]

npi_dm_make_assign_connection -scope $TOP -lhs $w1 -rhs $opr

set w4 [npi_dm_handle_by_name -name "w4" -scope $TOP]
set c0 [npi_dm_create_constant -value 3]
set index_expr_ary [npi_dm_create_npiDmHandleArray -array_list "$c0"]
set index_opr [npi_dm_create_operation -type "npiDmOpIndex" -array $index_expr_ary]

set c1_0 [npi_dm_create_constant -value 5]
set c1_1 [npi_dm_create_constant -value 2]
set slice_expr_ary [npi_dm_create_npiDmHandleArray -array_list "$c1_0 $c1_1"]
set slice_opr [npi_dm_create_operation -type "npiDmOpSlice" -array $slice_expr_ary]

set select_expr_ary [npi_dm_create_npiDmHandleArray -array_list "$w4 $index_opr $slice_opr"]
set select_opr [npi_dm_create_operation -type "npiDmOpSelect" -array $select_expr_ary]

set ws [npi_dm_handle_by_name -name "ws" -scope $TOP]
npi_dm_make_assign_connection -scope $TOP -lhs $ws -rhs $select_opr

# Write to directory "DM_LIB"
npi_dm_write_text_mode -dir DM_LIB

debExit

