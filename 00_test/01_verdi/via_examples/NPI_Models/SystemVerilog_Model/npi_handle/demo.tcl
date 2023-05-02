# The command is :
#     novas -sv example.v -play main.tcl
 
# get the module instance handle for "TEST.dut"
set mod_hdl [ npi_handle_by_name -name "TEST.dut" -scope "" ]
if { $mod_hdl != "" } {
 
    set mod_name [npi_get_str -property npiFullName -object $mod_hdl]
    puts "Module: $mod_name"
 
    # get the scope of the module handle "TEST.dut", by using 1-to-1 method npi_handle
    set scope [npi_handle -type npiScope -refHandle $mod_hdl]
    puts "  The module is in scope: [npi_get_str -property npiFullName -object $scope]"
}
 
# leave novas
debExit
