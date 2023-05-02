# Load Design
#debImport -sv input.sv

# DM Operation
set c0  [npi_dm_create_constant -value 0]
set top [npi_dm_module_by_name -name top]
set a   [npi_dm_handle_by_name -name a -scope $top]

# Create index operation [0]
set handle_array [npi_dm_create_npiDmHandleArray -array_list "$c0"]
set index        [npi_dm_create_operation -type npiDmOpIndex -array $handle_array]
npi_dm_delete_npiDmHandleArray -array $handle_array

# Create ref top
set ref1 [npi_dm_create_ref -actual $top -array ""]

# Create ref a[0]
set handle_array [npi_dm_create_npiDmHandleArray -array_list "$index"]
set ref2 [npi_dm_create_ref -actual $a -array $handle_array]
npi_dm_delete_npiDmHandleArray -array $handle_array

# Create hier ref top.a[0]
set handle_array [npi_dm_create_npiDmHandleArray -array_list "$ref1 $ref2"]
set hier_ref [npi_dm_create_hier_ref -array $handle_array]
npi_dm_delete_npiDmHandleArray -array $handle_array

# Assign
npi_dm_make_assign_connection -scope $top -lhs $hier_ref -rhs $c0

# Write to directory "DM_LIB"
npi_dm_write_text_mode -dir DM_LIB

debExit

