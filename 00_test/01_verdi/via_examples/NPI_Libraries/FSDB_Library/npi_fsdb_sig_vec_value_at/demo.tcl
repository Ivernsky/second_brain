source $env(NPIL1_PATH)/npi_L1.tcl

set fsdb_name "demoL1.fsdb"
set sig_name_list [list tb_CPUsystem.i_CPUsystem.i_CPU.i_CCU.MAselect tb_CPUsystem.i_CPUsystem.addr tb_CPUsystem.i_CPUsystem.i_CPU.i_CCU.MA]

set fsdb_time 5000

set fsdb_file_hdl [npi_fsdb_open -name $fsdb_name]

if { [::npi_L1::npi_fsdb_sig_vec_value_at $fsdb_file_hdl "sig_name_list" $fsdb_time npiFsdbBinStrVal "value_list"] == 1 } {
  for { set i 0 } { $i < 3 } { incr i } {
    set sig_name [lindex $sig_name_list $i]
    set sig_val [lindex $value_list $i]
    puts "$sig_name is '$sig_val' at time $fsdb_time"
  }
}
npi_fsdb_close -file $fsdb_file_hdl

debExit

