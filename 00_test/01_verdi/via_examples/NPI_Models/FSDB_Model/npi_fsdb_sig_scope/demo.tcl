# traverse member signals
proc npi_trv_sub_sig { sig } {
  if { [npi_fsdb_sig_property -sig $sig -type npiFsdbSigHasMember] == 1} {
    set sig_iter [npi_fsdb_iter_member -sig $sig]
    while { [set sub_sig [npi_fsdb_iter_sig_next -iter $sig_iter]] != ""} {
       set sig_name [npi_fsdb_sig_property_str -sig $sub_sig -type npiFsdbSigName]
puts "sig: $sig_name"
npi_trv_sub_sig $sub_sig 
    }
  }
}
# open the FSDB file named "demo.fsdb"
set file_name "demo.fsdb"
set file_hdl [npi_fsdb_open -name $file_name]
set sig_name "test.M1.a"
     
     if { $file_hdl != "" } {
#get signal handle by name 
#declaration in Verilog: reg [7:0] a [0:1][0:2];
       if { [set sig [npi_fsdb_sig_by_name -file $file_hdl -name $sig_name -scope ""] ] != "" } {
         set scope [npi_fsdb_sig_scope -sig $sig]
         set scope_name [npi_fsdb_scope_property_str -scope $scope -type npiFsdbScopeFullName]
         puts "== scope: $scope_name =="
         set sig_name [npi_fsdb_sig_property_str -sig $sig -type npiFsdbSigName]
         puts "sig: $sig_name"
         npi_trv_sub_sig $sig
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

