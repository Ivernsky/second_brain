proc display_sliced_objects { hdl } {
  set type [ npi_nl_get_str -property npiNlType -object $hdl ]
  if { $type == "npiNlInst" } { return }
  set left [ npi_nl_get -property npiNlLeft -object $hdl ]
  set right [ npi_nl_get -property npiNlRight -object $hdl ]
  set lincr [ expr { $left > $right } ? -1 : 1 ]
  set rincr [ expr { $left > $right } ? 1 : -1 ]
  
  puts "Right range is fixed"
  for { set lb $left} { $lb != $right } { set lb [ expr { $lb + $lincr } ] } {
    set hdlByRange [ npi_nl_handle_by_range -left $lb -right $right -object $hdl ]
    set fullName [ npi_nl_get_str -property npiNlFullName -object $hdlByRange ]
    puts "Handle $fullName by range \[$lb:$right\] is obtained"
    npi_nl_release_handle -object $hdlByRange
  }
  
  puts "Left range is fixed"
  for { set rb $right} { $rb != $left } { set rb [ expr { $rb + $rincr } ] } {
    set hdlByRange [ npi_nl_handle_by_range -left $left -right $rb -object $hdl ]
    set fullName [ npi_nl_get_str -property npiNlFullName -object $hdlByRange ]
    puts "Handle $fullName by range \[$left:$rb\] is obtained"
    npi_nl_release_handle -object $hdlByRange
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

