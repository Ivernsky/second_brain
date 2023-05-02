# The command is :
#     novas -sv example.v -play main.tcl
 
# get the module instance handle for "TEST.dut"
set mod_hdl [ npi_handle_by_name -name "TEST.dut" -scope "" ]
if { $mod_hdl != "" } {
    puts "The fullname of the handle is: [npi_get_str -property npiFullName -object $mod_hdl]"
    puts "The type of the handle is: [npi_get_str -property npiType -object $mod_hdl]"
}
 
puts ""
# get the variable handle with simple name "count" in the scope of $mod_hdl
set var_hdl [ npi_handle_by_name -name "count" -scope $mod_hdl ]
if { $var_hdl != "" } {
    puts "The fullname of the handle is: [npi_get_str -property npiFullName -object $var_hdl]"
    puts "The type of the handle is: [npi_get_str -property npiType -object $var_hdl]"
}
 
# leave novas
debExit
