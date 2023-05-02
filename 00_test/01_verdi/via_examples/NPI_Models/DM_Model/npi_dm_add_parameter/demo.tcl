# DM Operation
set c4  [npi_dm_create_constant -value 4]
set top [npi_dm_module_by_name -name "top"]
set P1  [npi_dm_handle_by_name -name "P1" -scope $top]
set P2  [npi_dm_handle_by_name -name "P2" -scope $top]
set P3  [npi_dm_add_parameter -scope $top -name "P3" -data_type "" -unpacked_dim "" -default $P2]
set P4  [npi_dm_add_parameter -scope $top -name "P4" -data_type "" -unpacked_dim "" -default $c4]

# Write to directory "DM_LIB"
npi_dm_write_text_mode -dir DM_LIB

debExit

