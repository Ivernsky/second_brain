proc dump_hdl { hdl } {
  if { $hdl == "" } { return }
  set type [ npi_nl_get_str -property npiNlType -object $hdl ]
  set fullName [ npi_nl_get_str -property npiNlFullName -object $hdl ]
  puts "Object $fullName ($type)"
}

proc iterate_object { type refHdl } {
  if { $refHdl == "" } { return }
  set itr [ npi_nl_iterate -type $type -refHandle $refHdl ]
  while { [ set subHdl [ npi_nl_scan -iterator $itr ] ] != "" } {
    dump_hdl $subHdl
      npi_nl_release_handle -object $subHdl
  }
}

# configuration and import the design
schSetPreference -detailRTL on -detailMux on -recogFSM off -expandGenBlock on
#debImport "-sv" "example.v"

# iterate top instances
set topInstItr [ npi_nl_iterate -type npiNlInst -refHandle ""]
while { [ set topInst [ npi_nl_scan -iterator $topInstItr ] ] != "" } {
  # iterate sub instances
  iterate_object npiNlInst $topInst
  # iterate nets
  iterate_object npiNlNet $topInst
  # iterate ports
  iterate_object npiNlPort $topInst
  npi_nl_release_handle -object $topInst
}
# below is the Verdi TCL command that will leave Novas executable
debExit

