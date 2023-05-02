source $env(NPIL1_PATH)/npi_L1.tcl

schSetPreference -detailRTL on -detailMux on -recogFSM off -expandGenBlock on
#debImport -sv example.v

set hdlList {}

puts "Pass through assign"
if { [ ::npi_L1::npi_sig_2_sig_conn "TOP.w4" "TOP.w5" "hdlList" ]  != 0 } {
  ::npi_L1::npi_nl_ut_dump_hdl_vec_info "hdlList" "stdout"
} else {
  puts "Not connected"
}

puts "Do not pass through assign"
if { [ ::npi_L1::npi_sig_2_sig_conn "TOP.w4" "TOP.w5" "hdlList" "1" ]  != 0 } {
  ::npi_L1::npi_nl_ut_dump_hdl_vec_info "hdlList" "stdout"
} else {
  puts "Not connected"
}


debExit

