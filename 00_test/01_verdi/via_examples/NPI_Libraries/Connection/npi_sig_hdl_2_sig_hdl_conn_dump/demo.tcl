source $env(NPIL1_PATH)/npi_L1.tcl

schSetPreference -detailRTL on -detailMux on -recogFSM off -expandGenBlock on
#debImport -sv example.v

set hdl1 [ ::npi_L1::npi_nl_sig_handle_by_name "TOP.w4" ]
set hdl2 [ ::npi_L1::npi_nl_sig_handle_by_name "TOP.w5" ]

puts "Pass through assign"
if { [::npi_L1::npi_sig_hdl_2_sig_hdl_conn_dump $hdl1 $hdl2 "stdout"] == 0 } {
  puts "Not connected"
}

puts "Do not pass through assign"
if { [::npi_L1::npi_sig_hdl_2_sig_hdl_conn_dump $hdl1 $hdl2 "stdout" "1"] == 0 } {
  puts "Not connected"
}

debExit

