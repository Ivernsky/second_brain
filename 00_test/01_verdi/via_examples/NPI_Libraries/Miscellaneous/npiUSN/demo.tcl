set FP [open "demo.log" "w"]

# construct an npiUSN handle for a string : "System.TOP.i_CPU.i_ALUB"
set hier_name "System.TOP.i_CPU.i_ALUB"
set delimiter "."
set usn_hdl [npi_usn_construct -fullname $hier_name -delimiter $delimiter]

# iterate every scopes and print to stdout
puts $FP "== Dump the scope information =="
set scope_num [npi_usn_number -handle $usn_hdl]
for {set i 0} {$i<$scope_num} {incr i} {
  puts $FP "Scope($i) = \"[npi_usn_scope_name_at -handle $usn_hdl -position $i]\""
}

# remove the last scope
npi_usn_pop_back -handle $usn_hdl  ;# Hierarchy becomes: "System.TOP.i_CPU"

# get the last scope
set last_scope [npi_usn_back -handle $usn_hdl]
puts $FP "Last scope = $last_scope" ;# last_scope = i_CPU

# add the last scope "i_CCU.i_MODE"
npi_usn_push_back -handle $usn_hdl -scope "i_CCU"  ;# Hierarchy becomes: "System.TOP.i_CPU.i_CCU"
npi_usn_push_back -handle $usn_hdl -scope "i_MODE"  ;# Hierarchy becomes: "System.TOP.i_CPU.i_CCU.i_MODE"

# get the middle scope i_CPU.i_CCU : from scope 2 to scope 3
set middle_name [npi_usn_middle_name -handle $usn_hdl -from 2 -to 3]
puts $FP "Middle name = \"$middle_name\"" ;# Middle name: "i_CPU.i_CCU"

# change the delimiter from '.' to '/'
npi_usn_set_delimiter -handle $usn_hdl -delimiter "/"
puts $FP "Current delimiter is [npi_usn_delimiter -handle $usn_hdl]"

# print the full hierarchy name
set full_name [npi_usn_hierarchy_name -handle $usn_hdl]
puts $FP "After scope manipulation, now hierarchy is: \"$full_name\""

# remove all scopes
while { [npi_usn_is_empty -handle $usn_hdl] == 0 } {
  npi_usn_pop_back -handle $usn_hdl
}

# destroy the npiUSN handle
npi_usn_destroy -handle $usn_hdl

close $FP

# below is the Verdi TCL command that will leave Novas executable
debExit

