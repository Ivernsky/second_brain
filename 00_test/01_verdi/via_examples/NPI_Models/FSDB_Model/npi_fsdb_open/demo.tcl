# open the FSDB file named "demo.fsdb"
set file_name "demo.fsdb"
if { [set file_hdl [npi_fsdb_open -name $file_name]] != "" } {
  set min_time [npi_fsdb_min_time -file $file_hdl]
  set max_time [npi_fsdb_max_time -file $file_hdl]
  set scale_unit [npi_fsdb_file_property_str -file $file_hdl -type npiFsdbFileScaleUnit]
  puts "Time range: $min_time ~ $max_time"
  puts "Scale unit: $scale_unit"
# close the FSDB file
  npi_fsdb_close -file $file_hdl
} else {
  puts "Failed to open FSDB file."
}

# below is the Verdi Tcl command that will leave Novas executable
debExit

