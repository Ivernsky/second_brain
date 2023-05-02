
set top [npi_dm_module_by_name -name "top"]
set UT  [npi_dm_add_union_typespec -scope $top \
                                    -name "UT" \
                                    -packed 1 \
                                    -sign npiDmSignSigned \
                                    -packed_dim   "" \
				    -unpacked_dim ""]


set dt [npi_dm_create_npiDmBasicDataType -type npiDmDtBit -sign npiDmSignNone -packed_dim ""]
npi_dm_add_su_member -typespec $UT -name "a" -data_type $dt -unpacked_dim ""
npi_dm_add_su_member -typespec $UT -name "b" -data_type $dt -unpacked_dim ""

npi_dm_write_text_mode -dir DM_LIB

debExit
