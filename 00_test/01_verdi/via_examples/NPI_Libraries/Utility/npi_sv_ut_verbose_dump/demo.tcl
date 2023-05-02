source $env(NPIL1_PATH)/npi_L1.tcl

#debImport -sv example.v

set instHdl [ npi_handle_by_name -name "top" -scope "" ]
::npi_L1::npi_sv_ut_verbose_dump $instHdl "stdout"

debExit

