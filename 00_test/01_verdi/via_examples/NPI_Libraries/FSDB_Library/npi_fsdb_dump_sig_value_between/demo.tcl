source $env(NPIL1_PATH)/npi_L1.tcl

set fsdb_name "demoL1.fsdb"
set sig_name "tb_CPUsystem.i_CPUsystem.i_CPU.i_CCU.MAselect"
set begin_time 5000
set end_time 6000

set fsdb_file_hdl [npi_fsdb_open -name $fsdb_name]
set output_file [ open "vc.txt" "w" ]

::npi_L1::npi_fsdb_dump_sig_value_between $fsdb_file_hdl $sig_name $begin_time $end_time npiFsdbBinStrVal $output_file

close $output_file

npi_fsdb_close -file $fsdb_file_hdl
debExit

