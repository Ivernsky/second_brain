source $env(NPIL1_PATH)/npi_L1.tcl

schSetPreference -detailRTL on -detailMux on -recogFSM off -expandGenBlock on
#debImport -sv example.v

set instHdl [ npi_nl_handle_by_name -name "top" ]
::npi_L1::npi_nl_ut_verbose_dump $instHdl "stdout"

debExit

