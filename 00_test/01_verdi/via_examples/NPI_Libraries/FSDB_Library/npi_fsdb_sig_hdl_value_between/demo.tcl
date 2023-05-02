source $env(NPIL1_PATH)/npi_L1.tcl

set fsdb_name "demoL1.fsdb"
set sig_name "tb_CPUsystem.i_CPUsystem.i_CPU.i_CCU.MAselect"
set begin_time 5000
set end_time 6000

set fsdb_file_hdl [npi_fsdb_open -name $fsdb_name]
set sig_hdl [npi_fsdb_sig_by_name -file $fsdb_file_hdl -name $sig_name -scope ""]

if {[::npi_L1::npi_fsdb_sig_hdl_value_between $sig_hdl $begin_time $end_time npiFsdbBinStrVal "vc_array"] == 1 } {
  puts "$sig_name between $begin_time ~ $end_time:"
  set tok [array startsearch vc_array]
  while { [array anymore vc_array $tok] } {
    set key [array nextelement vc_array $tok]
    lappend key_list $key
  }
  set key_list [lsort -integer $key_list]
  foreach key $key_list {
    puts "At time $key, Value = $vc_array($key)"
  }
}

npi_fsdb_close -file $fsdb_file_hdl
debExit

