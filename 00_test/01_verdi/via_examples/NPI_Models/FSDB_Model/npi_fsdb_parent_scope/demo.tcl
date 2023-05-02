# open the FSDB file named "demo.fsdb"
set file_name "demo.fsdb"
set scope_name "test.M1"
if { [set file_hdl [npi_fsdb_open -name $file_name] ] != "" } {
       if { [set scope [npi_fsdb_scope_by_name -file $file_hdl -name $scope_name -scope ""]] != "" } {
         set scope_name [npi_fsdb_scope_property_str -scope $scope -type npiFsdbScopeName]
puts "==scope: $scope_name =="
set sig_iter [npi_fsdb_iter_sig -scope $scope]
while { [set sig_hdl [npi_fsdb_iter_sig_next -iter $sig_iter]] != ""} {
    set sig_name [npi_fsdb_sig_property_str -sig $sig_hdl -type npiFsdbSigName]
puts "sig: $sig_name"
}
set parent_scope [npi_fsdb_parent_scope -scope $scope]
set scope_name [npi_fsdb_scope_property_str -scope $parent_scope -type npiFsdbScopeName]
puts "== parent scope: $scope_name =="
       } else {
         puts "Failed to find scope: $scope_name"
       }
# close the FSDB file
npi_fsdb_close -file $file_hdl
 
     } else {
       puts "Failed to open FSDB: $file_name"
     }

# below is the Verdi Tcl command that will leave Novas executable
debExit

