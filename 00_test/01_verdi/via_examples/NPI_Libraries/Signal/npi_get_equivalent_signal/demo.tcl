source $env(NPIL1_PATH)/npi_L1.tcl

schSetPreference -detailRTL on -detailMux on -recogFSM off -expandGenBlock on
#debImport -sv example.v

set hdlList {}
puts "Pass through assign"
::npi_L1::npi_get_equivalent_signal "TOP.w3" "hdlList"
::npi_L1::npi_nl_ut_dump_hdl_vec_info "hdlList" "stdout"
puts "Do not pass through assign"
::npi_L1::npi_get_equivalent_signal "TOP.w3" "hdlList" 1
::npi_L1::npi_nl_ut_dump_hdl_vec_info "hdlList" "stdout"

debExit

