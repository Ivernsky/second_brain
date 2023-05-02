source $env(NPIL1_PATH)/npi_L1.tcl

schSetPreference -detailRTL on -detailMux on -recogFSM off -expandGenBlock on
#debImport -sv example.v

set hdl [ ::npi_L1::npi_nl_sig_handle_by_name "TOP.w3" ]
puts "Pass through assign"
::npi_L1::npi_nl_dump_equivalent_signal_by_hdl $hdl "stdout"
puts "Do not pass through assign"
::npi_L1::npi_nl_dump_equivalent_signal_by_hdl $hdl "stdout" 1

debExit
