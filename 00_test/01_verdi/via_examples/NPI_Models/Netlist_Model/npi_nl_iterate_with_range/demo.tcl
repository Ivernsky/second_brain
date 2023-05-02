proc traverse_net_hdl_with_range { netHdl } {
  if { $netHdl == "" } { return }
  # get the range of net
  set left [ npi_nl_get -property npiNlLeft -object $netHdl ]
  set right [ npi_nl_get -property npiNlRight -object $netHdl ]
  set low  [ expr {$left <= $right} ? $left : $right ]
  set high  [ expr {$left <= $right} ? $right : $left ]

  for { set i $low } { $i <= $high } { incr i 1 } {
  # find the connectivity for each bit
    if { [ set itr [ npi_nl_iterate_with_range -type npiNlConnectivity -refHandle $netHdl -left $i -right $i] ] != ""} {
      puts "Find connectivity of [ npi_nl_get_str -property npiNlFullName -object $netHdl ] with range \[$i:$i\]"
        while { [ set subHdl [ npi_nl_scan -iterator $itr ] ] != "" } {
          puts "  [npi_nl_get_str -property npiNlFullName -object $subHdl ]"
            npi_nl_release_handle -object $subHdl
        }
    }
  }
} 

# configuration and import the design
schSetPreference -detailRTL on -detailMux on -recogFSM off -expandGenBlock on
#debImport "-sv" "example.v"

# get the net handle called top.a
set fullName "top.a"
set netHdl [ npi_nl_handle_by_name -name $fullName ]
traverse_net_hdl_with_range $netHdl
npi_nl_release_handle -object $netHdl

# below is the Verdi TCL command that will leave Novas executable
debExit
