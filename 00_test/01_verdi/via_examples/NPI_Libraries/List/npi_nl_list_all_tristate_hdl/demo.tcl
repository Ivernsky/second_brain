schSetPreference -detailRTL on -detailMux on -recogFSM off -expandGenBlock on
source $env(NPIL1_PATH)/npi_L1.tcl

#debImport -sv example.v

set hdlList {}
::npi_L1::npi_nl_list_all_tristate_hdl "TOP" "hdlList"
::npi_L1::npi_nl_ut_dump_hdl_vec_info "hdlList" "stdout"

debExit

