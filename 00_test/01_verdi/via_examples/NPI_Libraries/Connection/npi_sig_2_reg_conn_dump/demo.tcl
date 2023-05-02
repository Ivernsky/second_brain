source $env(NPIL1_PATH)/npi_L1.tcl

schSetPreference -detailRTL on -detailMux on -recogFSM off -expandGenBlock on
#debImport -sv example.v

::npi_L1::npi_sig_2_reg_conn_dump "TOP.wtmp" "stdout"
::npi_L1::npi_sig_2_reg_conn_dump "TOP.wtmp" "stdout" 1

debExit

