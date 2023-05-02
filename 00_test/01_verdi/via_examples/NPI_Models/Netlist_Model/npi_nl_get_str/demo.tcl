proc dump_inst { instHdl } {
  if { $instHdl == ""} { return }

  set strVal [ npi_nl_get_str -property npiNlFullName -object $instHdl ]
  puts "Instance $strVal"

  set intVal [ npi_nl_get -property npiNlType -object $instHdl ]
  set strVal [ npi_nl_get_str -property npiNlType -object $instHdl ]
  puts "  npiNlType property = $intVal ($strVal)"

  set intVal [ npi_nl_get -property npiNlInstType -object $instHdl ]
  set strVal [ npi_nl_get_str -property npiNlInstType -object $instHdl ]
  puts "  npiNlInstType property = $intVal ($strVal)"

  set intVal [ npi_nl_get -property npiNlCellType -object $instHdl ]
  set strVal [ npi_nl_get_str -property npiNlCellType -object $instHdl ]
  puts "  npiNlCellType property = $intVal ($strVal)"
}

# configuration and import the design
schSetPreference -detailRTL on -detailMux on -recogFSM off -expandGenBlock on
#debImport "example.v"

set fullName "top"
set topInst [ npi_nl_handle_by_name -name $fullName ]
dump_inst $topInst

# iterate sub instances from top
set instItr [ npi_nl_iterate -type npiNlInst -refHandle $topInst ]
while { [ set inst [ npi_nl_scan -iterator $instItr ] ] != "" } {
  dump_inst $inst
  npi_nl_release_handle -object $inst
}
npi_nl_release_handle -object $topInst

# below is the Verdi TCL command that will leave Novas executable
debExit

