source $env(NPIL1_PATH)/npi_L1.tcl

#debImport -sv example.v

set hdlList {}
::npi_L1::npi_mod_inst_get_instance_in_gen_scope "TOP" "hdlList"
::npi_L1::npi_sv_ut_dump_hdl_vec_info "hdlList" "stdout"

debExit

