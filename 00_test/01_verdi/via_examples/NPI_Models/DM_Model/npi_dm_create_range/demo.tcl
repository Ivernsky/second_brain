
# DM Operation
set range_hdl1 [npi_dm_create_range -left 7 -right 0]
set range_hdl2 [npi_dm_create_range -left 7 -right 0]

if { [string equal $range_hdl1 $range_hdl2] } {
  puts "range_hdl1 and range_hdl2 are the same object."
}

# Use handle as range input
set c3 [npi_dm_create_constant -value 3]
set c0 [npi_dm_create_constant -value 0]
set range_hdl3 [npi_dm_create_range -left $c3 -right $c0 -handle]

debExit

