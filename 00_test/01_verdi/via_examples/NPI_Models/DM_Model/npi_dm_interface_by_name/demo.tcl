
# Get interface named Itf
set Itf [npi_dm_interface_by_name -name "Itf"]
puts "Object name: [npi_dm_property_str -type npiDmName -ref $Itf]"
  
debExit

