source $env(NPIL1_PATH)/npi_L1.tcl

#debImport -sv example.v

::npi_L1::npi_inst_port_2_low_conn_sig_dump "TOP.inst" "stdout"

debExit
