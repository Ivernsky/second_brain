source $env(NPIL1_PATH)/npi_L1.tcl

#debImport -sv example.v

set hdlList {}
::npi_L1::npi_find_signal_regex {TOP.inst2[1]} {[0-9]$} hdlList
::npi_L1::npi_sv_ut_dump_hdl_vec_info "hdlList" "stdout"

debExit

