source $env(NPIL1_PATH)/npi_L1.tcl

schSetPreference -detailRTL on -detailMux on -recogFSM off -expandGenBlock on
#debImport -sv example.v

puts "Pass through assign"
::npi_L1::npi_nl_dump_equivalent_signal "TOP.w3" "stdout"
puts "Do not pass through assign"
::npi_L1::npi_nl_dump_equivalent_signal "TOP.w3" "stdout" 1

debExit

