
# DM Operation
set P  [npi_dm_handle_by_name -name "TOP.i0.P" -scope ""]
set PT [npi_dm_handle_by_name -name "TOP.i0.PT" -scope ""]

npi_dm_delete_parameter -param $P
npi_dm_delete_parameter -param $PT

# Write to directory "DM_LIB"
npi_dm_write_text_mode -dir DM_LIB

debExit

