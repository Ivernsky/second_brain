  
# DM operation
set MOD       [npi_dm_module_by_name -name MOD]
set port_iter [npi_dm_iter_start -type npiDmPort -ref $MOD]

if { $port_iter != "" } {
  while { [ set port [npi_dm_iter_next -iter $port_iter ] ] != "" } {
    # Actions on port 
    puts "Object name: [npi_dm_property_str -type npiDmName -ref $port]"
  }
  npi_dm_iter_stop -iter $port_iter
}

debExit

