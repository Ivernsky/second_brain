source $env(NPIL1_PATH)/npi_L1.tcl

schSetPreference -detailRTL on -detailMux on -recogFSM off -expandGenBlock on
#debImport -sv example.v

set hdl [ ::npi_L1::npi_nl_sig_handle_by_name "TOP.w3" ]
puts "Pass through assign, do not pass through module"
::npi_L1::npi_nl_trace_driver_by_hdl_dump $hdl "stdout" 0 0
puts "Pass through assign and module"
::npi_L1::npi_nl_trace_driver_by_hdl_dump $hdl "stdout" 0 1
puts "Do not pass through assign, pass through module"
::npi_L1::npi_nl_trace_driver_by_hdl_dump $hdl "stdout" 1 1
puts "Do not pass through assign and module"
::npi_L1::npi_nl_trace_driver_by_hdl_dump $hdl "stdout" 1 0

debExit

