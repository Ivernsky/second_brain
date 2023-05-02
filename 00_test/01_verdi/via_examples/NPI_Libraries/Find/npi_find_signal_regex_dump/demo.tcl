source $env(NPIL1_PATH)/npi_L1.tcl

#debImport -sv example.v

::npi_L1::npi_find_signal_regex_dump {TOP.inst2[1]} {[0-9]$}  "stdout"

debExit

