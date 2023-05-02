
# DM Operation
set TOP [npi_dm_module_by_name -name "TOP"]
set i1  [npi_dm_handle_by_name -name "TOP.i0.i1" -scope ""]

npi_dm_move_instance -inst $i1 -dest_scope $TOP

# Write to directory "DM_LIB"
npi_dm_write_text_mode -dir DM_LIB

debExit

