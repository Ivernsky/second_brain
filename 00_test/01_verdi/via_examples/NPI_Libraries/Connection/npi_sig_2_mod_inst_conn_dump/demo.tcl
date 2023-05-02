source $env(NPIL1_PATH)/npi_L1.tcl

schSetPreference -detailRTL on -detailMux on -recogFSM off -expandGenBlock on
#debImport -sv example.v

puts "Pass through assign"
::npi_L1::npi_sig_2_mod_inst_conn_dump "TOP.w1" "stdout"
puts "Do not pass through assign"
::npi_L1::npi_sig_2_mod_inst_conn_dump "TOP.w1" "stdout" "1"

puts ""

puts "Pass through assign, stop at port/instport"
::npi_L1::npi_sig_2_mod_inst_conn_dump "TOP.w1" "stdout" "0" "1"
puts "Do not pass through assign, stop at port/instport"
::npi_L1::npi_sig_2_mod_inst_conn_dump "TOP.w1" "stdout" "1" "1"

debExit

