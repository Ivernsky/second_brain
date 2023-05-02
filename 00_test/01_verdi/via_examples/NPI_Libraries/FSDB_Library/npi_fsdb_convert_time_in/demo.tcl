source $env(NPIL1_PATH)/npi_L1.tcl

set fsdb_name "demoL1.fsdb"

set fsdb_file_hdl [npi_fsdb_open -name $fsdb_name]

set time_unit [::npi_L1::npi_fsdb_time_scale_unit $fsdb_file_hdl]
puts "Time scale of '$fsdb_name' = '$time_unit'"
set converted_time [::npi_L1::npi_fsdb_convert_time_in $fsdb_file_hdl 15000 "ps"]
puts "15000 ps = $converted_time X $time_unit"

npi_fsdb_close -file $fsdb_file_hdl
 
debExit

