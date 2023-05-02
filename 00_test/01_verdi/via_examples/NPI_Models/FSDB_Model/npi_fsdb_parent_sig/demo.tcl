# open the FSDB file named "demo.fsdb"
set file_name "demo.fsdb"
set sig_name {test.M1.a[0][0][0]}
set file_hdl [npi_fsdb_open -name $file_name]
     
     if { $file_hdl != "" } {
       if { [set sig [npi_fsdb_sig_by_name -file $file_hdl -name $sig_name -scope ""]] != "" } {
          set sigName [npi_fsdb_sig_property_str -type npiFsdbSigName -sig $sig]
          puts "sig: $sigName"
          while { [set sig [npi_fsdb_parent_sig -sig $sig]] != ""} {
set sigName [npi_fsdb_sig_property_str -type npiFsdbSigName -sig $sig]
             puts "parent sig: $sigName"
}
} else {
  puts "Failed to find sig: $sig_name"
}
# close the FSDB file
npi_fsdb_close -file $file_hdl
     } else {
       puts "Failed to open FSDB: $file_name"
}

# below is the Verdi Tcl command that will leave Novas executable
debExit

