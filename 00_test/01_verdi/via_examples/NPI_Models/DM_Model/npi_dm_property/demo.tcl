  
# DM operation
set TOP [npi_dm_module_by_name -name "TOP"]
set MOD [npi_dm_module_by_name -name "MOD"]

puts "Property top module of TOP: [npi_dm_property -type npiDmTopModule -ref $TOP]"
puts "Property top module of MOD: [npi_dm_property -type npiDmTopModule -ref $MOD]"

debExit

