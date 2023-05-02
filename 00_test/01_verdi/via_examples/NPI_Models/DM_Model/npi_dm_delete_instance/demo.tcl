
# DM Operation
set MOD [npi_dm_module_by_name -name MOD]
set ndm_instance [npi_dm_handle_by_name -name "TOP.ndm_instance" -scope ""]

npi_dm_delete_instance -inst $ndm_instance

# Write to directory "DM_LIB"
npi_dm_write_text_mode -dir DM_LIB

debExit

