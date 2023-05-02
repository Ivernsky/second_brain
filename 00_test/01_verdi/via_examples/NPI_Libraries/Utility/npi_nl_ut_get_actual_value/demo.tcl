proc dump_value { hdl { isAll 0 } } {
  set sigFullName [ npi_nl_get_str -property npiNlFullName -object $hdl ]
  puts "Name: $sigFullName"
  puts "Actual isLiteral: [ ::npi_L1::npi_nl_ut_get_actual_is_literal $hdl ]"
  set value [ ::npi_L1::npi_nl_ut_get_actual_value $hdl  ]
  puts -nonewline "Actual value: "
  if {$value == ""} {
    puts -nonewline "(null)"
  }
  puts "$value"
  if { $isAll == 1} {
    set value [ ::npi_L1::npi_nl_ut_get_actual_value $hdl npiNlHexFormat ]
    puts -nonewline "Actual value(Hex): "
    if {$value == ""} {
      puts -nonewline "(null)"
    }
    puts "$value"
    set value [ ::npi_L1::npi_nl_ut_get_actual_value $hdl npiNlOctFormat ]
    puts -nonewline "Actual value(Oct): "
    if {$value == ""} {
      puts -nonewline "(null)"
    }
    puts "$value"
    set value [ ::npi_L1::npi_nl_ut_get_actual_value $hdl npiNlDecFormat ]
    puts -nonewline "Actual value(Dec): "
    if {$value == ""} {
      puts -nonewline "(null)"
    }
    puts "$value"
  }
  puts ""
}

viaSetupL1Apps

schSetPreference -detailRTL on -detailMux on -recogFSM off -expandGenBlock on
debImport "-sv" "example.v"

set hdlList {}

set sigHdl [ ::npi_L1::npi_nl_L1_handle_by_name "top.3'bx01" ]
dump_value $sigHdl

set sigHdl [ npi_nl_handle_by_range -object $sigHdl -left 0 -right 0 ]
dump_value $sigHdl

::npi_L1::npi_nl_get_equivalent_signal "top.b" "hdlList"
set sigHdl [ lindex $hdlList 0 ]
dump_value $sigHdl

::npi_L1::npi_nl_get_equivalent_signal "top.b\[6:3\]" "hdlList"
set sigHdl [ lindex $hdlList 0 ]
dump_value $sigHdl 1

::npi_L1::npi_nl_get_equivalent_signal "top.b\[3:1\]" "hdlList"
set sigHdl [ lindex $hdlList 0 ]
dump_value $sigHdl
debExit
