proc release_hdl { hdl } {
  if { $hdl == "" } { return }
  set type [ npi_nl_get_str -property npiNlType -object $hdl ]
  puts -nonewline "Release $type: "
  if { $type != "npiNlIterator" } {
    puts -nonewline "[ npi_nl_get_str -property npiNlFullName -object $hdl ]"
  }
  puts -nonewline "=> "

  if { [ npi_nl_release_handle -object $hdl ] == 1 } {
    puts "Success"
  }  else {
    puts "Failure"
  }
}

# import the design
#debImport "example.v"

set net1 [ npi_nl_handle_by_name -name "top.a" ]
set inst1 [ npi_nl_handle -type npiNlInst -refHandle $net1 ]
set net2 [ npi_nl_handle_by_name -name "top.b" ]
set inst2 [ npi_nl_handle -type npiNlInst -refHandle $net1 ]

# release top.a which is referenced once => success
release_hdl $net1
# release top.b which is referenced once => success
release_hdl $net2
# release top which is referenced twice => failure
release_hdl $inst1
# release top which is referenced once => success
release_hdl $inst2

# below is the Verdi TCL command that will leave Novas executable
debExit

