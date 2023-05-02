source $env(NPIL1_PATH)/npi_L1.tcl

#debImport -sv example.v

::npi_L1::npi_find_inst_with_def_regex_dump "" "T" "stdout"

debExit

