# Load Design
#debImport input.v

# DM Operation
npi_dm_create_package -name ndm_package1 -file ndm_package1.sv
npi_dm_create_package -name ndm_package2 -file ndm_package2.sv

# Write to directory "DM_LIB"
npi_dm_write_text_mode -dir DM_LIB

debExit

