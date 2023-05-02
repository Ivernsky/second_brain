source $env(NPIL1_PATH)/npi_L1.tcl

#debImport -sv example.v

::npi_L1::npi_find_signal_wildcard_dump {TOP.inst2[1]} {[a-v]*} "stdout"

debExit

