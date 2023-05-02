source $env(NPIL1_PATH)/npi_L1.tcl

set fsdb_name "demoL1.fsdb"
set sig1_name tb_CPUsystem.i_CPUsystem.i_CPU.i_CCU.MAselect 
set sig2_name tb_CPUsystem.i_CPUsystem.addr 
set sig3_name tb_CPUsystem.i_CPUsystem.i_CPU.i_CCU.MA

set fsdb_time 5000

set fsdb_file_hdl [npi_fsdb_open -name $fsdb_name]
set sig1 [npi_fsdb_sig_by_name -file $fsdb_file_hdl -name $sig1_name -scope ""]
set sig2 [npi_fsdb_sig_by_name -file $fsdb_file_hdl -name $sig2_name -scope ""]
set sig3 [npi_fsdb_sig_by_name -file $fsdb_file_hdl -name $sig3_name -scope ""]

set sig_list [list $sig1 $sig2 $sig3]

if { [::npi_L1::npi_fsdb_sig_hdl_vec_value_at "sig_list" $fsdb_time npiFsdbBinStrVal "value_list"] == 1 } {
    set sig_val [lindex $value_list 0]
    puts "$sig1_name is '$sig_val' at time $fsdb_time"
set sig_val [lindex $value_list 1]
    puts "$sig2_name is '$sig_val' at time $fsdb_time"
set sig_val [lindex $value_list 2]
    puts "$sig3_name is '$sig_val' at time $fsdb_time"
}
npi_fsdb_close -file $fsdb_file_hdl

debExit

