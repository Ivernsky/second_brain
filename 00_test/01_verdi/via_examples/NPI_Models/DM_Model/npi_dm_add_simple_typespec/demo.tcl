
set top [npi_dm_module_by_name -name "top"]
set T1  [npi_dm_handle_by_name -name "T1" -scope $top]

set dt  [npi_dm_create_npiDmBasicDataType -type npiDmDtBit -sign npiDmSignSigned -packed_dim ""]
set NT1 [npi_dm_add_simple_typespec -scope $top -name "NT1" -data_type $dt -unpacked_dim ""]
npi_dm_delete_npiDmBasicDataType -data_type $dt

set dt  [npi_dm_create_npiDmBasicDataType -type npiDmDtTypespec -sign npiDmSignNone -packed_dim "" -typespec $T1]
set NT2 [npi_dm_add_simple_typespec -scope $top -name "NT2" -data_type $dt -unpacked_dim ""]
npi_dm_delete_npiDmBasicDataType -data_type $dt

npi_dm_write_text_mode -dir DM_LIB

debExit
