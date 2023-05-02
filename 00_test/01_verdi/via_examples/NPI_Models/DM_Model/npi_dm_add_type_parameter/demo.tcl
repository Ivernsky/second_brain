
# DM Operation
set top  [npi_dm_module_by_name -name "top"]
set rng  [npi_dm_create_range -left 1 -right 0]
set pdim [npi_dm_create_npiDmHandleArray -array_list "$rng"]
set dt   [npi_dm_create_npiDmBasicDataType -type npiDmDtBit -sign npiDmSignNone -packed_dim $pdim]
set PT   [npi_dm_add_type_parameter -scope $top -name "PT" -default $dt]

# Write to directory "DM_LIB"
npi_dm_write_text_mode -dir DM_LIB

debExit

