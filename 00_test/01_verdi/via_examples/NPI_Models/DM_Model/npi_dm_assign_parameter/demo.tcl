

# DM Operation
set i0 [npi_dm_handle_by_name -name "TOP.i0" -scope ""]
set P1 [npi_dm_handle_by_name -name "TOP.P1" -scope ""]
set P2 [npi_dm_handle_by_name -name "TOP.i0.P2" -scope ""]

npi_dm_assign_parameter -inst $i0 -param $P2 -expr $P1

# Write to directory "DM_LIB"
npi_dm_write_text_mode -dir DM_LIB

debExit

