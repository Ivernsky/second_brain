source $env(NPIL1_PATH)/npi_L1.tcl

#debImport -sv example.v

set hdl [ ::npi_L1::npi_get_signal_define_typespec "TOP.w1\[2:1\]" ]
::npi_L1::npi_sv_ut_dump_hdl_info $hdl "stdout"

debExit

