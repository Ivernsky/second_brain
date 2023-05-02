
# DM Operation
set MOD  [npi_dm_module_by_name -name MOD]
set port [npi_dm_port_by_name -name "a" -scope $MOD]

npi_dm_delete_port -port $port

# Write to directory "DM_LIB"
npi_dm_write_text_mode -dir DM_LIB

debExit

