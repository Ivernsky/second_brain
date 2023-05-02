source $env(NPIL1_PATH)/npi_L1.tcl

schSetPreference -detailRTL on -detailMux on -recogFSM off -expandGenBlock on
#debImport -sv example.v

set hdl1 [ ::npi_L1::npi_nl_sig_handle_by_name "TOP.w4" ]
set hdl2 [ ::npi_L1::npi_nl_sig_handle_by_name "TOP.w5" ]
set hdlList {}

puts "Pass through assign"
if { [::npi_L1::npi_sig_hdl_2_sig_hdl_conn $hdl1 $hdl2 "hdlList"] != 0 } {
  ::npi_L1::npi_nl_ut_dump_hdl_vec_info "hdlList" "stdout"
} else {
  puts "Not connected"
}

puts "Do not pass through assign"
if { [::npi_L1::npi_sig_hdl_2_sig_hdl_conn $hdl1 $hdl2 "hdlList" "1"] != 0 } {
  ::npi_L1::npi_nl_ut_dump_hdl_vec_info "hdlList" "stdout"
} else {
  puts "Not connected"
}

debExit

