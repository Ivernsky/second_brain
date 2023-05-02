source $env(NPIL1_PATH)/npi_L1.tcl

schSetPreference -detailRTL on -detailMux on -recogFSM off -expandGenBlock on
#debImport -sv example.v

puts "Pass through assign"
if { [::npi_L1::npi_sig_2_sig_conn_dump "TOP.w4" "TOP.w5" "stdout"] == 0 } {
  puts "Not connected"
}

puts "Do not pass through assign"
if { [::npi_L1::npi_sig_2_sig_conn_dump "TOP.w4" "TOP.w5" "stdout" "1"] == 0 } {
  puts "Not connected"
}

debExit

