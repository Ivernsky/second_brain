
# DM Operation
set a [npi_dm_handle_by_name -name "TOP.a" -scope ""]
npi_dm_rename_object -handle $a -name "c"

# Write to directory "DM_LIB"
npi_dm_write_text_mode -dir DM_LIB

debExit

