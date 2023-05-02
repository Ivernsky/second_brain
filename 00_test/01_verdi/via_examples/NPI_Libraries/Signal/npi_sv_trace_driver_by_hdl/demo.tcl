source $env(NPIL1_PATH)/npi_L1.tcl

#debImport -sv example.v

set hdl [ npi_handle_by_name -name "top.b" -scope "" ]
set hdlList {}
::npi_L1::npi_sv_trace_driver_by_hdl $hdl "hdlList"
::npi_L1::npi_sv_ut_dump_hdl_vec_info "hdlList" "stdout"

debExit

