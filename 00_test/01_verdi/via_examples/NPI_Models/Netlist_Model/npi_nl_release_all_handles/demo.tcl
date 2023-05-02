proc release_test { hdl } {
  set type [ npi_nl_get_str -property npiNlType -object $hdl ]
  puts -nonewline "Release object $type => "
  if { [ npi_nl_release_handle -object $hdl ] == 1 } {
    puts "Success"
  }  else {
    puts "Failure"
  }
}

proc permanent_test { hdl } {
  set type [ npi_nl_get_str -property npiNlType -object $hdl ]
  puts -nonewline "Set permanent for object $type => "
  if { [ npi_nl_set_permanent_handle -object $hdl ] == 1 } {
    puts "Success"
  }  else {
    puts "Failure"
  }
}

# import the design
#debImport "example.v"

set itr [ npi_nl_iterate -type npiNlInst -refHandle "" ]
set netHdl [ npi_nl_handle_by_name -name "top.a" ]

# set iterator object as permanent => failure
permanent_test $itr
# release iterator object as permanent => success
release_test $itr
# set net object as permanent => success
permanent_test $netHdl
# release net object as permanent => failure
release_test $netHdl

# release all handles, including permanent handles
npi_nl_release_all_handles
# net object is invalid
if { [npi_nl_get_str -property npiNlType -object $netHdl ] == "" } {
  puts "All handles are released!"
} 

# below is the Verdi TCL command that will leave Novas executable
debExit

