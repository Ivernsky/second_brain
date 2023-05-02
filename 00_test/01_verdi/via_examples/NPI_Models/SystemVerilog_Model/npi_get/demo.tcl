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
 
    # iterate the port of "TEST.dut"
    set i 0
    set port_it [npi_iterate -type npiPort -refHandle $mod_hdl]
    while { [set port_hdl [npi_scan -iterator $port_it]] != "" } {
 
       # get the int/bool property and string property of port_hdl
       set port_size [npi_get -property npiSize -object $port_hdl]
       set port_name [npi_get_str -property npiName -object $port_hdl]
       set port_dir  [npi_get_str -property npiDirection -object $port_hdl]
 
       puts "    $i) Port = $port_name ($port_dir Size=$port_size)"
       set i [expr $i + 1]
 
       # release port_hdl since it is useless below
       npi_release_handle -object $port_hdl
    }
}
 
# leave novas
debExit
