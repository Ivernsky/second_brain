source $env(NPIL1_PATH)/npi_L1.tcl

set fsdb_name "demoL1.fsdb"
set scope_name "tb_CPUsystem.i_CPUsystem.i_CPU"

set fsdb_file_hdl [npi_fsdb_open -name $fsdb_name]
set output_file_hdl [open "scope_tree.txt" "w"]

puts $output_file_hdl "===== Dump from root scope: ====="
::npi_L1::npi_fsdb_hier_tree_dump_scope $fsdb_file_hdl $output_file_hdl
puts $output_file_hdl "===== End of dump from root scope ====="

puts $output_file_hdl "===== Dump from sub scope '$scope_name': ====="
::npi_L1::npi_fsdb_hier_tree_dump_scope $fsdb_file_hdl $output_file_hdl $scope_name
puts $output_file_hdl "===== End of dump from sub scope ====="

close $output_file_hdl
npi_fsdb_close -file $fsdb_file_hdl
 
debExit

