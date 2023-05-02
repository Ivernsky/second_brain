
# DM Operation
set MOD2 [npi_dm_module_by_name -name "MOD2"]
set i0   [npi_dm_handle_by_name -name "TOP.i0" -scope ""]

npi_dm_replace_module -inst $i0 -module $MOD2

# Write to directory "DM_LIB"
npi_dm_write_text_mode -dir DM_LIB

debExit

