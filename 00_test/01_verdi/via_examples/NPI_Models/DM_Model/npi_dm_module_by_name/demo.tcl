
# Get module named TOP
set TOP [npi_dm_module_by_name -name "TOP"]
puts "Object name: [npi_dm_property_str -type npiDmName -ref $TOP]"
  
# Get module named MOD
set MOD [npi_dm_module_by_name -name "MOD"]
puts "Object name: [npi_dm_property_str -type npiDmName -ref $MOD]"

debExit

