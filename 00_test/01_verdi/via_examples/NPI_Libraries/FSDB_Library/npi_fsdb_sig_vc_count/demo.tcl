source $env(NPIL1_PATH)/npi_L1.tcl

set fsdb_name "demoL1.fsdb"
set sig_name "tb_CPUsystem.i_CPUsystem.addr"
set begin_time 5000
set end_time 6000

set fsdb_file_hdl [npi_fsdb_open -name $fsdb_name]

if { [set vc_count [::npi_L1::npi_fsdb_sig_vc_count $fsdb_file_hdl $sig_name $begin_time $end_time] ] != "" } {
  puts "$sig_name has '$vc_count' value changes between $begin_time ~ $end_time."
}
npi_fsdb_close -file $fsdb_file_hdl

debExit 

