# open the FSDB file named "demo.fsdb"
set file_name "demo.fsdb"
set file_hdl [npi_fsdb_open -name $file_name]
set sig_name "test.M1.a"
     
     if { $file_hdl != "" } {
#get signal handle by name 
#declaration in Verilog: reg [7:0] a [0:1][0:2];
       if { [set sig [npi_fsdb_sig_by_name -file $file_hdl -name $sig_name -scope ""] ] != "" } {
         set scope [npi_fsdb_sig_scope -sig $sig]
set file_from_scope [npi_fsdb_scope_file -scope $scope]
         
if { $file_hdl ne $file_from_scope } {
           puts "Incorrect file handle from scope"
}
         set file_from_sig [npi_fsdb_sig_file -sig $sig]
if { $file_hdl ne $file_from_sig } {
           puts "Incorrect file handle from sig"
}

         set scope_name [npi_fsdb_scope_property_str -scope $scope -type npiFsdbScopeFullName]
         puts "scope: $scope_name"
         set sig_name [npi_fsdb_sig_property_str -sig $sig -type npiFsdbSigName]
         puts "sig: $sig_name"
       } else {
         puts "Failed to find sig: $sig_name.\n"
       }

# close the FSDB file
npi_fsdb_close -file $file_hdl
     } else {
       puts "Failed to open FSDB: $file_name"
     }

# below is the Verdi Tcl command that will leave Novas executable
debExit

