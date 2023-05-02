source $env(NPIL1_PATH)/npi_L1.tcl

#debImport -sv example.v

set hdlList {}
set strList {"\[^]\]$"}
::npi_L1::npi_find_inst_regex "" "strList" "hdlList"
#::npi_L1::npi_find_inst_regex "" "\[^\\\]\]\$" hdlList 
::npi_L1::npi_sv_ut_dump_hdl_vec_info "hdlList" "stdout"

debExit

