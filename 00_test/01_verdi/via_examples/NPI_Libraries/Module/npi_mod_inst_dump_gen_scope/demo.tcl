source $env(NPIL1_PATH)/npi_L1.tcl

#debImport -sv example.v

::npi_L1::npi_mod_inst_dump_gen_scope "TOP" "stdout"

debExit

