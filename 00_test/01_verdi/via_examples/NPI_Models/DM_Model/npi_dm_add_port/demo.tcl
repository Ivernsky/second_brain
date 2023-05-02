
# DM Operation
set mod [npi_dm_module_by_name -name MOD]

# Add port
npi_dm_add_port -scope $mod -name a -dir npiDmDirInput
npi_dm_add_port -scope $mod -name b -dir npiDmDirOutput

# Write to directory "DM_LIB"
npi_dm_write_text_mode -dir DM_LIB

debExit

