# Load Design
#debImport input.v
 
# DM Operation
set c1 [npi_dm_create_constant -value 3]
set c2 [npi_dm_create_constant -value 3]
 
if { [string equal $c1 $c2] } {
  puts "c1 and c2 are the same object."
}
 
set c3 [npi_dm_create_constant -value 32d11]
set c4 [npi_dm_create_constant -value 32d11]
 
if { [string equal $c3 $c4] } {
  puts "c3 and c4 are the same object."
}
 
## Other constant type examples
## exponential constant
set c5 [npi_dm_create_constant -value "32e-10"]
## fixed point constant
set c6 [npi_dm_create_constant -value "12.07"]
## string constant
set c7 [npi_dm_create_constant -value "\"springsoft\""]
 
 
debExit
