source $env(NPIL1_PATH)/npi_L1.tcl

set fsdb_name "demoL1.fsdb"
set sig_name "tb_CPUsystem.i_CPUsystem.i_CPU.i_CCU.MAselect"
set fsdb_time 5000

set fsdb_file_hdl [npi_fsdb_open -name $fsdb_name]

set value [::npi_L1::npi_fsdb_sig_value_at $fsdb_file_hdl $sig_name $fsdb_time npiFsdbBinStrVal]
puts "$sig_name is '$value' at time $fsdb_time."

npi_fsdb_close -file $fsdb_file_hdl

debExit

