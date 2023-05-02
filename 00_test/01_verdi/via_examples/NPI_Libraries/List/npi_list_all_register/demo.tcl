schSetPreference -detailRTL on -detailMux on -recogFSM off -expandGenBlock on
source $env(NPIL1_PATH)/npi_L1.tcl

#debImport -sv example.v

::npi_L1::npi_list_all_register "TOP" stdout

debExit

