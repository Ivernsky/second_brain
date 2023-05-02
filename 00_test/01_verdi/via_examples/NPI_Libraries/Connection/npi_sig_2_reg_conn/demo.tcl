source $env(NPIL1_PATH)/npi_L1.tcl

schSetPreference -detailRTL on -detailMux on -recogFSM off -expandGenBlock on
#debImport -sv example.v

set hdlList {}
::npi_L1::npi_sig_2_reg_conn "TOP.wtmp" "hdlList"
::npi_L1::npi_nl_ut_dump_hdl_vec_info "hdlList" "stdout"
::npi_L1::npi_sig_2_reg_conn "TOP.wtmp" "hdlList" 1
::npi_L1::npi_nl_ut_dump_hdl_vec_info "hdlList" "stdout"

debExit

