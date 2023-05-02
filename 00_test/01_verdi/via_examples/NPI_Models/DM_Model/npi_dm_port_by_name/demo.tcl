
# Get module named MOD 
set MOD [npi_dm_module_by_name -name "MOD"]
  
# Get port named b in MOD
set port_b [npi_dm_port_by_name -name "b" -scope $MOD]
puts "Object name: [npi_dm_property_str -type npiDmName -ref $port_b]"

debExit

