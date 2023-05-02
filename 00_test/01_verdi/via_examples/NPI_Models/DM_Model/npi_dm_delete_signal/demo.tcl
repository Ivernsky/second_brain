
# DM Operation
set a [npi_dm_handle_by_name -name "MOD.a" -scope ""]

npi_dm_delete_signal -signal $a

# Write to directory "DM_LIB"
npi_dm_write_text_mode -dir DM_LIB

debExit

