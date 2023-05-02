
# DM Operation
set top [npi_dm_module_by_name -name "TOP"]
set mod [npi_dm_module_by_name -name "MOD"]
set i0  [npi_dm_handle_by_name -name "i0" -scope $top]
set i1  [npi_dm_add_instance -inst_def $mod -name "i1" -dest_scope $top]
set i2  [npi_dm_add_instance -inst_def $mod -name "i2" -dest_scope $top]
set pa  [npi_dm_port_by_name -name "a" -scope $mod]
set pb  [npi_dm_port_by_name -name "b" -scope $mod]
set a   [npi_dm_handle_by_name -name "a" -scope $top]
set b   [npi_dm_handle_by_name -name "b" -scope $top]

npi_dm_make_port_connection -inst $i1 -port $pa -expr $a
npi_dm_make_port_connection -inst $i1 -port $pb -expr $b
npi_dm_make_port_connection -inst $i2 -port $pa -expr $a 
npi_dm_make_port_connection -inst $i2 -port $pb -expr $b

npi_dm_sync_format -target $i1 -source $i0
npi_dm_write_text_mode -dir "DM_LIB"

debExit

