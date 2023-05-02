source $env(NPIL1_PATH)/npi_L1.tcl

set fsdb_name "demoL1.fsdb"
set scope_name "tb_CPUsystem.i_BJsource"

set fsdb_file_hdl [npi_fsdb_open -name $fsdb_name]
set output_file_hdl [open "sig_list.txt" "w"]

puts $output_file_hdl "===== Dump declared signals: ====="
::npi_L1::npi_fsdb_hier_tree_dump_sig $fsdb_file_hdl $output_file_hdl $scope_name 0
puts $output_file_hdl "===== End of dump declared signals ====="

puts $output_file_hdl "===== Dump decalred + member signals: ====="
::npi_L1::npi_fsdb_hier_tree_dump_sig $fsdb_file_hdl $output_file_hdl $scope_name 1
puts $output_file_hdl "===== End of dump declared + member signals ====="

close $output_file_hdl
npi_fsdb_close -file $fsdb_file_hdl
 
debExit

