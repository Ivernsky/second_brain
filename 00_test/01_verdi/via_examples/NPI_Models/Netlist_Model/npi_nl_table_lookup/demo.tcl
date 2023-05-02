proc table_lookup { hdl inData } {
  set fullName [ npi_nl_get_str -property npiNlFullName -object $hdl ]
  puts "UDP output instport: $fullName"
  upvar $inData inDataList
  set no [ llength $inDataList ]
  for { set i 0 } { $i < $no } { incr i } {
    set inVal [ lindex $inDataList $i]
    set outStr [ npi_nl_table_lookup -inVal $inVal -object $hdl ]
    if { $outStr != "" } {
      puts "  in = $inVal, out = $outStr"
    } else {
      puts "  invalid input $inVal"
    }
  }
}


# configuration and import the design
schSetPreference -detailRTL on -detailMux on -recogFSM off -expandGenBlock on
#debImport "example.v"

set inData  { "00x"  "11x"  "1x0"  "x10"  "xxx"
              "1?0"  "0?0"  "?11"  "?01" "1111" };

set fullName  "top.mux"
set inst [ npi_nl_handle_by_name -name $fullName ]
set itr [ npi_nl_iterate -type npiNlLoad -refHandle $inst ]
while { [ set instport [ npi_nl_scan -iterator $itr ] ] != "" } {
  table_lookup $instport inData
  npi_nl_release_handle -object $instport
}

# below is the Verdi TCL command that will leave Novas executable
debExit

