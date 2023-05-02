source $env(NPIL1_PATH)/npi_L1.tcl

schSetPreference -detailRTL on -detailMux on -recogFSM off -expandGenBlock on
#debImport -sv example.v

set hdl [ ::npi_L1::npi_nl_sig_handle_by_name "TOP.w3" ]
set hdlList {}
puts "Pass through assign"
::npi_L1::npi_nl_get_equivalent_signal_by_hdl $hdl "hdlList"
::npi_L1::npi_nl_ut_dump_hdl_vec_info "hdlList" "stdout"
puts "Do not pass through assign"
::npi_L1::npi_nl_get_equivalent_signal_by_hdl $hdl "hdlList" 1
::npi_L1::npi_nl_ut_dump_hdl_vec_info "hdlList" "stdout"

debExit

