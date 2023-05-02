source $env(NPIL1_PATH)/npi_L1.tcl

#debImport -sv example.v

set sigHdl [ npi_handle_by_name -name "TOP.w1\[2:1\]" -scope "" ]
set hdl [ ::npi_L1::npi_get_signal_define_typespec_by_hdl $sigHdl ]
::npi_L1::npi_sv_ut_dump_hdl_info $hdl "stdout"

debExit

