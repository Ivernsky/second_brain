source $env(NPIL1_PATH)/npi_L1.tcl

#debImport -sv example.v

set hdl [ npi_handle_by_name -name "TOP.w1\[2:1\]" -scope "" ]
::npi_L1::npi_dump_signal_define_typespec_by_hdl $hdl "stdout"

debExit

