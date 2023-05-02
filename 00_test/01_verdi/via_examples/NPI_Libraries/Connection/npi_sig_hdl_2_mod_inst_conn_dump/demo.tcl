source $env(NPIL1_PATH)/npi_L1.tcl

schSetPreference -detailRTL on -detailMux on -recogFSM off -expandGenBlock on
#debImport -sv example.v

set hdl [ ::npi_L1::npi_nl_sig_handle_by_name "TOP.w1" ]
puts "Pass through assign"
::npi_L1::npi_sig_hdl_2_mod_inst_conn_dump $hdl "stdout"
puts "Do not pass through assign"
::npi_L1::npi_sig_hdl_2_mod_inst_conn_dump $hdl "stdout" "1"

puts ""

puts "Pass through assign, stop at port/instport"
::npi_L1::npi_sig_hdl_2_mod_inst_conn_dump $hdl "stdout" "0" "1"
puts "Do not pass through assign, stop at port/instport"
::npi_L1::npi_sig_hdl_2_mod_inst_conn_dump $hdl "stdout" "1" "1"

debExit

