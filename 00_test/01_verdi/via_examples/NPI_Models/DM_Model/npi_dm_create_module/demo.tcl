
# DM Operation
npi_dm_create_module -name ndm_module1 -file ndm_module1.sv
npi_dm_create_module -name ndm_module2 -file ndm_module2.sv

# Write to directory "DM_LIB"
npi_dm_write_text_mode -dir DM_LIB

debExit

