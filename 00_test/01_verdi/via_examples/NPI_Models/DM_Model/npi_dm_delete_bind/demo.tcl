#debImport -sv input.v 

set top [npi_dm_module_by_name -name "top"]
set iter [npi_dm_iter_start -type npiDmBind -ref $top]
if { $iter != "" } {
  set bind [npi_dm_iter_next -iter $iter]
  while { $bind != "" } {
    npi_dm_delete_bind -bind $bind
    set bind [npi_dm_iter_next -iter $iter]
  }
}

npi_dm_write_text_mode -dir "DM_LIB"


debExit
