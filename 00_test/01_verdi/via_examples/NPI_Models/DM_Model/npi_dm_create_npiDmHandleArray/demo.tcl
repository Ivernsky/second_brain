
# DM Operation
# bit [7:0] ndm_var [255:0]"

set mod [npi_dm_module_by_name -name MOD]

# prepare range
set range_7_to_0   [npi_dm_create_range -left 7 -right 0]
set range_255_to_0 [npi_dm_create_range -left 255 -right 0]

# prepare packed dimension
set packed_dim [npi_dm_create_npiDmHandleArray -array_list $range_7_to_0]

# prepare date type
set data_type [npi_dm_create_npiDmBasicDataType -type npiDmDtDefault -sign npiDmSignNone -packed_dim $packed_dim]

# prepare unpacked dimension
set unpacked_dim [npi_dm_create_npiDmHandleArray -array_list $range_255_to_0]

# Add varible
npi_dm_add_var -scope $mod -name ndm_var -data_type $data_type -unpacked_dim $unpacked_dim

# Write to directory "DM_LIB"
npi_dm_write_text_mode -dir DM_LIB

debExit

