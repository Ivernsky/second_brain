source $env(NPIL1_PATH)/npi_L1.tcl

schSetPreference -detailRTL on -detailMux on -recogFSM off -expandGenBlock on
#debImport -sv example.v

set hdl [ ::npi_L1::npi_nl_sig_handle_by_name "TOP.wtmp" ]
::npi_L1::npi_nl_sig_hdl_2_reg_conn_dump $hdl "stdout"
::npi_L1::npi_nl_sig_hdl_2_reg_conn_dump $hdl "stdout" 1

debExit

