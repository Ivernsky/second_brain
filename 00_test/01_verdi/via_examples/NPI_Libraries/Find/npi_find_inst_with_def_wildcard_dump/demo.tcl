source $env(NPIL1_PATH)/npi_L1.tcl

#debImport -sv example.v

::npi_L1::npi_find_inst_with_def_wildcard_dump "" "*D" "stdout"

debExit

