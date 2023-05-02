source $env(NPIL1_PATH)/npi_L1.tcl

schSetPreference -detailRTL on -detailMux on -recogFSM off -expandGenBlock on
#debImport -sv example.v

set hdl [ ::npi_L1::npi_nl_sig_handle_by_name "TOP.w1" ]
set hdlList {}
puts "Pass through assign, do not pass through module"
::npi_L1::npi_nl_trace_load_by_hdl $hdl "hdlList" 0 0
::npi_L1::npi_nl_ut_dump_hdl_vec_info "hdlList" "stdout"
puts "Pass through assign and module"
::npi_L1::npi_nl_trace_load_by_hdl $hdl "hdlList" 0 1
::npi_L1::npi_nl_ut_dump_hdl_vec_info "hdlList" "stdout"
puts "Do not pass through assign, pass through module"
::npi_L1::npi_nl_trace_load_by_hdl $hdl "hdlList" 1 1
::npi_L1::npi_nl_ut_dump_hdl_vec_info "hdlList" "stdout"
puts "Do not pass through assign and module"
::npi_L1::npi_nl_trace_load_by_hdl $hdl "hdlList" 1 0
::npi_L1::npi_nl_ut_dump_hdl_vec_info "hdlList" "stdout"

debExit

