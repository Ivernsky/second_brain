source $env(NPIL1_PATH)/npi_L1.tcl

schSetPreference -detailRTL on -detailMux on -recogFSM off -expandGenBlock on
#debImport -sv example.v

set hdl [ ::npi_L1::npi_nl_sig_handle_by_name "TOP.wtmp"]
set hdlList {}
::npi_L1::npi_nl_sig_hdl_2_fanIn_reg_conn $hdl "hdlList"
::npi_L1::npi_nl_ut_dump_hdl_vec_info "hdlList" "stdout"
::npi_L1::npi_nl_sig_hdl_2_fanIn_reg_conn $hdl "hdlList" 1
::npi_L1::npi_nl_ut_dump_hdl_vec_info "hdlList" "stdout"

debExit

