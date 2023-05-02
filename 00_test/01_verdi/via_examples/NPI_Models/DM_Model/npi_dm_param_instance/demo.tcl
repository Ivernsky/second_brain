
set i0 [npi_dm_handle_by_name -name "top.i0" -scope ""]
set P [npi_dm_handle_by_name -name "top.i0.P" -scope ""]

set param_inst  [npi_dm_param_instance -inst $i0 -param $P]
puts "Object name: [npi_dm_property_str -type npiDmName -ref $param_inst]"

debExit

