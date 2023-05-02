# open the FSDB file named "demo.fsdb"
set file_name "demo.fsdb"
set sig_name "test.M1.A"
set file_hdl [npi_fsdb_open -name $file_name]

if { $file_hdl == "" } {
  puts "Failed to open FSDB: $file_name"
  debExit
}
set sig_hdl [npi_fsdb_sig_by_name -file $file_hdl -name $sig_name -scope ""]
if { $sig_hdl != "" } {
set vct_hdl [npi_fsdb_create_vct -sig $sig_hdl]
if { $vct_hdl != "" } {
  set max_time [npi_fsdb_max_time -file $file_hdl]
  npi_fsdb_goto_time -vct $vct_hdl -time $max_time
  set vct_time [npi_fsdb_vct_time -vct $vct_hdl]
  set vct_val [npi_fsdb_vct_value -vct $vct_hdl -format npiFsdbBinStrVal]
  puts "Time = $vct_time, value = $vct_val"

  while { [npi_fsdb_goto_prev -vct $vct_hdl] != 0 } {
       set vct_time [npi_fsdb_vct_time -vct $vct_hdl]
       set vct_val [npi_fsdb_vct_value -vct $vct_hdl -format npiFsdbBinStrVal]
       puts "Time = $vct_time, value = $vct_val"
  }
} else {
  puts "Failed to create vct for sig: $sig_name"
}
} else {
  puts "Failed to find sig: $sig_name"
}
# close the FSDB file
npi_fsdb_close -file $file_hdl

# below is the Verdi Tcl command that will leave Novas executable
debExit

