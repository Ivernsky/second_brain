source $env(NPIL1_PATH)/npi_L1.tcl

schSetPreference -detailRTL on -detailMux on -recogFSM off -expandGenBlock on
#debImport -sv example.v

puts "Pass through assign, do not pass through module"
::npi_L1::npi_nl_trace_driver_dump "TOP.w3" "stdout" 0 0
puts "Pass through assign and module"
::npi_L1::npi_nl_trace_driver_dump "TOP.w3" "stdout" 0 1
puts "Do not pass through assign, pass through module"
::npi_L1::npi_nl_trace_driver_dump "TOP.w3" "stdout" 1 1
puts "Do not pass through assign and module"
::npi_L1::npi_nl_trace_driver_dump "TOP.w3" "stdout" 1 0

debExit

