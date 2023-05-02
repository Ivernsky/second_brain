proc dump_hdl { hdl isFull } {
  if { $isFull == 1 } {
    set prop "npiNlFullName"
  } else {
    set prop "npiNlName"
  }
  puts "Name: [ npi_nl_get_str -property $prop -object $hdl ]"

  set nameList {}
  set size [ ::npi_L1::npi_nl_ut_get_actual_name_vec $hdl "nameList" $isFull ]
  for { set i 0 } { $i < $size } { incr i } {
    puts "Actual name: [ lindex $nameList $i ]"
  }
  puts ""
}

source $env(NPIL1_PATH)/npi_L1.tcl

#debImport "-sv" "example.v"

set netHdl [ ::npi_L1::npi_nl_L1_handle_by_name "top.w\[2:1\]" ]
dump_hdl $netHdl 0

set hdlList {}
set size [ ::npi_L1::npi_get_equivalent_signal_by_hdl $netHdl "hdlList" ]
for { set i 0 } { $i < $size } { incr i } {
  dump_hdl [ lindex $hdlList $i ] 1
}

debExit

