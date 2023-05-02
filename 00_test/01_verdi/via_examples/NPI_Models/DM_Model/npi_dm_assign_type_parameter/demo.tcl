
set i0 [npi_dm_handle_by_name -name "TOP.i0" -scope ""]
set PT [npi_dm_handle_by_name -name "TOP.i0.PT" -scope ""]
set dt [npi_dm_create_npiDmBasicDataType -type npiDmDtBit -packed_dim "" -sign npiDmSignUnsigned]

npi_dm_assign_type_parameter -inst $i0 -param $PT -data_type $dt

npi_dm_write_text_mode -dir DM_LIB

debExit
