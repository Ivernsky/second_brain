source $env(NPIL1_PATH)/npi_L1.tcl

#debImport -sv example.v

::npi_L1::npi_dump_signal_define_typespec "TOP.w1\[2:1\]" "stdout"

debExit

