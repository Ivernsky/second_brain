
set top [npi_dm_module_by_name -name "top"]
set ET  [npi_dm_add_enum_typespec -scope $top -name "ET" -base_data_type "" -packed_dim "" -unpacked_dim ""]
npi_dm_add_enum_member -typespec $ET -name "A" -expr [npi_dm_create_constant -value 1]
npi_dm_add_enum_member -typespec $ET -name "B" -expr ""

npi_dm_write_text_mode -dir DM_LIB

debExit
