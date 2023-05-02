proc display_connected_objects { port } {
  if { $port == "" } { return }

  puts "Port [ npi_nl_get_str -property npiNlFullName -object $port ]"
  if { [ set net [ npi_nl_handle -type npiNlNet -refHandle $port ]] != "" } {
    puts "  Connect to net: [ npi_nl_get_str -property npiNlFullName -object $net ]"
    npi_nl_release_handle -object $net
  }
  if { [ set instport [ npi_nl_handle -type npiNlInstPort -refHandle $port ]] != "" } {
    puts "  Connect to instport: [ npi_nl_get_str -property npiNlFullName -object $instport ]"
    npi_nl_release_handle -object $instport
  }
}

# configuration and import the design
schSetPreference -detailRTL on -detailMux on -recogFSM off -expandGenBlock on
#debImport "-sv" "example.v"

set fullName  "tb.t1"
set inst [ npi_nl_handle_by_name -name $fullName ]
set portItr [ npi_nl_iterate -type npiNlPort -refHandle $inst ]
while { [ set port [ npi_nl_scan -iterator $portItr ] ] != "" } {
  display_connected_objects $port
  npi_nl_release_handle -object $port
}

# below is the Verdi TCL command that will leave Novas executable
debExit

