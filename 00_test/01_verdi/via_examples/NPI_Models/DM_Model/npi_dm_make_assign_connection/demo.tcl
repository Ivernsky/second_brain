
# DM Operation
set MOD [npi_dm_module_by_name -name "MOD"]
set a   [npi_dm_handle_by_name -name "a" -scope $MOD]
set b   [npi_dm_handle_by_name -name "b" -scope $MOD]

set assign [npi_dm_make_assign_connection -scope $MOD -lhs $a -rhs $b]

# Write to directory "DM_LIB"
npi_dm_write_text_mode -dir DM_LIB

debExit

