
# DM Operation
set MOD  [npi_dm_module_by_name -name MOD]
set inst [npi_dm_handle_by_name -name "TOP.ndm_instance" -scope ""]
set port [npi_dm_port_by_name -name "a" -scope $MOD]

npi_dm_delete_port_connection -inst $inst -port $port

# Write to directory "DM_LIB"
npi_dm_write_text_mode -dir DM_LIB

debExit

