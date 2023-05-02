 
# DM Operation
set inst1 [npi_dm_handle_by_name -name "TOP.inst1" -scope ""]
set MOD   [npi_dm_handle -type npiDmDefine -ref $inst1]
 
set conn [list]
lappend conn [npi_dm_handle_by_name -name  "TOP.w1" -scope ""]
lappend conn [npi_dm_handle_by_name -name  "TOP.w2" -scope ""]
 
set i 0
set port_iter [npi_dm_iter_start -type npiDmPort -ref $MOD]
if { $port_iter != "" } {
  while { [ set port [npi_dm_iter_next -iter $port_iter ] ] != "" } {
    npi_dm_make_port_connection -inst $inst1 -port $port -expr [lindex $conn $i];
    set i [expr $i+1]
  }
  npi_dm_iter_stop -iter $port_iter
}
 
# Write to directory "DM_LIB"
npi_dm_write_text_mode -dir DM_LIB
 
debExit
