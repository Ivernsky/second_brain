
# DM Operation
set TOP [npi_dm_handle_by_name -name "TOP" -scope ""]
npi_dm_add_net -scope $TOP -name "a" -data_type "" -unpacked_dim ""

npi_dm_write_text_mode -dir "DM_LIB"

debExit

