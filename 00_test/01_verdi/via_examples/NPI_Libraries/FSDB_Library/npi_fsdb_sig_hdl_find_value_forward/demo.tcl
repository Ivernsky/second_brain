source $env(NPIL1_PATH)/npi_L1.tcl

set fsdb_name "demoL1.fsdb"
set sig_name "tb_CPUsystem.i_CPUsystem.addr"
set vc_value "22"
set fsdb_time 5000

set fsdb_file_hdl [npi_fsdb_open -name $fsdb_name]
set sig_hdl [npi_fsdb_sig_by_name -file $fsdb_file_hdl -name $sig_name -scope ""]
set vc_time ""

if { [::npi_L1::npi_fsdb_sig_hdl_find_value_forward $sig_hdl $fsdb_time $vc_value npiFsdbHexStrVal vc_time] == 1 } {
  puts "$sig_name is '$vc_value' at time $vc_time."
} else {
  puts "Failed to find %s when forward searching from $fsdb_time."
}
npi_fsdb_close -file $fsdb_file_hdl

debExit 

