source $env(NPIL1_PATH)/npi_L1.tcl

#debImport -sv example.v

set strList {"\[^]\]$"}
::npi_L1::npi_find_inst_regex_dump "" "strList" "stdout"
#::npi_L1::npi_find_inst_regex_dump "" "\[^\\\]\]\$" "stdout"

debExit

