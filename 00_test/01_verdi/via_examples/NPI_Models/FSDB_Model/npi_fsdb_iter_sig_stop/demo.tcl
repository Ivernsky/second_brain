# traverse member signals
proc npi_trv_sub_sig { sig } {
  if { [npi_fsdb_sig_property -sig $sig -type npiFsdbSigHasMember] == 1} {
    set sig_iter [npi_fsdb_iter_member -sig $sig]
    #only iterate 1 member signal
    if { [set sub_sig [npi_fsdb_iter_sig_next -iter $sig_iter]] != ""} {
       set sig_name [npi_fsdb_sig_property_str -sig $sub_sig -type npiFsdbSigName]
puts "sig: $sig_name"
npi_trv_sub_sig $sub_sig
    }
    #free signal iterator manually
    npi_fsdb_iter_sig_stop -iter sig_iter
  }
}
# open the FSDB file named "demo.fsdb"
set file_name "demo.fsdb"
set file_hdl [npi_fsdb_open -name $file_name]

#get signal handle by name 
#declaration in Verilog: reg [7:0] a [0:1][0:2];
     set sig [npi_fsdb_sig_by_name -file $file_hdl -name {test.M1.a} -scope ""]
     if { $sig == "" } {
       puts "Failed to find signal"
       debExit
     }
     set scope [npi_fsdb_sig_scope -sig $sig]
     set scope_name [npi_fsdb_scope_property_str -scope $scope -type npiFsdbScopeFullName]
     puts "== scope: $scope_name =="
     set sig_name [npi_fsdb_sig_property_str -sig $sig -type npiFsdbSigName]
     puts "sig: $sig_name"
     npi_trv_sub_sig $sig

# close the FSDB file
npi_fsdb_close -file $file_hdl

# below is the Verdi Tcl command that will leave Novas executable
debExit

