
# Get module named TOP
set TOP [npi_dm_handle_by_name -name "TOP" -scope ""]
puts "Object name: [npi_dm_property_str -type npiDmName -ref $TOP]"
  
# Get instance named i0 in TOP module ( TOP.b )
set i0 [npi_dm_handle_by_name -name "i0" -scope $TOP ]
puts "Object name: [npi_dm_property_str -type npiDmName -ref $i0]"
  
# Get net named ndm_net in TOP module ( TOP.c )
set ndm_net [npi_dm_handle_by_name -name "TOP.ndm_net" -scope ""]
puts "Object name: [npi_dm_property_str -type npiDmName -ref $ndm_net]"

debExit

