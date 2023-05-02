proc display_sliced_objects { hdl } {
  set type [ npi_nl_get_str -property npiNlType -object $hdl ]
  if { $type == "npiNlInst" } { return }
  set left [ npi_nl_get -property npiNlLeft -object $hdl ]
  set right [ npi_nl_get -property npiNlRight -object $hdl ]
  set index [ expr { $left < $right } ? $left : $right ]
  set max [ expr { $left < $right } ? $right : $left ]

  for { } { $index <= $max } { incr index } {
    set hdlByIndex [ npi_nl_handle_by_index -index $index -object $hdl ]
    set fullName [ npi_nl_get_str -property npiNlFullName -object $hdlByIndex ]
    puts "Handle $fullName by index $index is obtained"
    npi_nl_release_handle -object $hdlByIndex
  }
}

# configuration and import the design
schSetPreference -detailRTL on -detailMux on -recogFSM off -expandGenBlock on
#debImport "-sv" "example.v"

set fullName  "test.out"
set net [ npi_nl_handle_by_name -name $fullName ]
display_sliced_objects $net
npi_nl_release_handle -object $net

# below is the Verdi TCL command that will leave Novas executable
debExit

