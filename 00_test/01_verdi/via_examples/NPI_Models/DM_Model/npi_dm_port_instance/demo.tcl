
set a [npi_dm_port_by_name -name "a" -scope [npi_dm_module_by_name -name "m"]]
set i0 [npi_dm_handle_by_name -name "top.i0" -scope ""]

set port_inst  [npi_dm_port_instance -inst $i0 -port $a]
puts "Object name: [npi_dm_property_str -type npiDmName -ref $port_inst]"

debExit

