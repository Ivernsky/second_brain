source $env(NPIL1_PATH)/npi_L1.tcl

#debImport -sv example.v

::npi_L1::npi_find_inst_wildcard_dump "" "*\\\[2\\\]" "stdout"

debExit

