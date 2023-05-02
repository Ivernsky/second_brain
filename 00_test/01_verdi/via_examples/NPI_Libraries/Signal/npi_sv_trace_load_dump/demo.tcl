source $env(NPIL1_PATH)/npi_L1.tcl

#debImport -sv example.v

::npi_L1::npi_sv_trace_load_dump "top.b" "stdout"

debExit

