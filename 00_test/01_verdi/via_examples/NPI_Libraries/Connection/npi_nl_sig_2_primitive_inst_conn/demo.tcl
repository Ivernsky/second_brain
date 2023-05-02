source $env(NPIL1_PATH)/npi_L1.tcl

schSetPreference -detailRTL on -detailMux on -recogFSM off -expandGenBlock on
#debImport -sv example.v

set hdlList {}
puts "Pass through assign"
::npi_L1::npi_nl_sig_2_primitive_inst_conn "TOP.w5" "hdlList"
::npi_L1::npi_nl_ut_dump_hdl_vec_info "hdlList" "stdout"
puts "Do not pass through assign"
::npi_L1::npi_nl_sig_2_primitive_inst_conn "TOP.w5" "hdlList" "1"
::npi_L1::npi_nl_ut_dump_hdl_vec_info "hdlList" "stdout"

puts ""

puts "Pass through assign, stop at instport"
::npi_L1::npi_nl_sig_2_primitive_inst_conn "TOP.w5" "hdlList" "0" "1"
::npi_L1::npi_nl_ut_dump_hdl_vec_info "hdlList" "stdout"
puts "Do not pass through assign, stop at instport"
::npi_L1::npi_nl_sig_2_primitive_inst_conn "TOP.w5" "hdlList" "1" "1"
::npi_L1::npi_nl_ut_dump_hdl_vec_info "hdlList" "stdout"

debExit

