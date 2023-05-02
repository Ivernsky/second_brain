source $env(NPIL1_PATH)/npi_L1.tcl

schSetPreference -detailRTL on -detailMux on -recogFSM off -expandGenBlock on
#debImport -sv example.v

set hdl [ ::npi_L1::npi_nl_sig_handle_by_name "TOP.w5"]
set hdlList {}
puts "Pass through assign"
::npi_L1::npi_sig_hdl_2_primitive_inst_conn $hdl" "hdlList"
::npi_L1::npi_nl_ut_dump_hdl_vec_info "hdlList" "stdout"
puts "Do not pass through assign"
::npi_L1::npi_sig_hdl_2_primitive_inst_conn $hdl" "hdlList" "1"
::npi_L1::npi_nl_ut_dump_hdl_vec_info "hdlList" "stdout"

puts ""

puts "Pass through assign, stop at instport"
::npi_L1::npi_sig_hdl_2_primitive_inst_conn $hdl" "hdlList" "0" "1"
::npi_L1::npi_nl_ut_dump_hdl_vec_info "hdlList" "stdout"
puts "Do not pass through assign, stop at instport"
::npi_L1::npi_sig_hdl_2_primitive_inst_conn $hdl" "hdlList" "1" "1"
::npi_L1::npi_nl_ut_dump_hdl_vec_info "hdlList" "stdout"

debExit

