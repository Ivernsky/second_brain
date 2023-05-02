
# DM Operation
set MOD [npi_dm_module_by_name -name MOD]
set iter [npi_dm_iter_start -type npiDmContAssign -ref $MOD]

if { $iter != "" } {
  while { [ set cont_assign [npi_dm_iter_next -iter $iter ] ] != "" } {
    npi_dm_delete_assign_connection -cont_assign $cont_assign
  }
  npi_dm_iter_stop -iter $iter
}

# Write to directory "DM_LIB"
npi_dm_write_text_mode -dir DM_LIB

debExit
