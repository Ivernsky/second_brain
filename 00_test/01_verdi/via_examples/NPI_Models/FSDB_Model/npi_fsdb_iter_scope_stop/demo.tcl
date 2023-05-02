# open the FSDB file named "demo.fsdb"
set file_name "demo.fsdb"
set file_hdl [npi_fsdb_open -name $file_name]
     
     if { $file_hdl != "" } {
if { [set scope_iter [npi_fsdb_iter_top_scope -file $file_hdl]] != "" } {
    #only want to iterate 1 top scope
if { [set scope [npi_fsdb_iter_scope_next -iter $scope_iter]] != "" } {
      set scope_name [npi_fsdb_scope_property_str -scope $scope -type npiFsdbScopeFullName]
      puts "== scope: $scope_name =="
    }
    #free the iterator manually
    npi_fsdb_iter_scope_stop -iter scope_iter
}
} else {
  puts "Failed to open FSDB: $file_name"
  debExit
}

# close the FSDB file
npi_fsdb_close -file $file_hdl

# below is the Verdi Tcl command that will leave Novas executable
debExit

