source $env(NPIL1_PATH)/npi_L1.tcl

#debImport -sv example.v

set hdlList {}
::npi_L1::npi_find_inst_with_def_regex "" "T" hdlList
::npi_L1::npi_sv_ut_dump_hdl_vec_info "hdlList" "stdout"

debExit

