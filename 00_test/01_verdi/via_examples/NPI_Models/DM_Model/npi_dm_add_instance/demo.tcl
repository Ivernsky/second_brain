
# DM Operation
set npiTop [npi_dm_module_by_name -name TOP]
set npiMod [npi_dm_module_by_name -name MOD]
set unpacked_dim [npi_dm_create_npiDmHandleArray -array_list [npi_dm_create_range -left 1 -right 0]]

npi_dm_add_instance -inst_def $npiMod -name inst2 -dest_scope $npiTop
npi_dm_add_instance -inst_def $npiMod -name inst3 -unpacked_dim $unpacked_dim -dest_scope $npiTop

# Write to directory "DM_LIB"
npi_dm_write_text_mode -dir DM_LIB

debExit

