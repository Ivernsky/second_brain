proc dump_dl_res_vec_info { resListName } {
  upvar $resListName resList
  set listSize [ llength $resList ]

  for { set i 0 } { $i < $listSize } { incr i } {
    set res [ lindex $resList $i ]
    set src [ lindex $res 0 ]
    set dlList [ lindex $res 1 ]

    puts "[ ::npi_L1::npi_nl_ut_get_hdl_info $src ]"

    set dlSize [ llength $dlList ]
    for { set j 0 } { $j < $dlSize } { incr j } {
      set dlHdl [ lindex $dlList $j ]
      set dlInfo [ npi_util_nl_get_hdl_info $dlHdl ]
      puts "    $dlInfo"
    }
    puts ""
  }
}

proc driver_demo { hdl cb } {
  set resList {}
  puts "== [ ::npi_L1::npi_nl_ut_get_hdl_info $hdl ] ==\n"
  set size [ ::npi_L1::npi_nl_bit_trace_driver_by_hdl $hdl "resList" ]
  dump_dl_res_vec_info "resList"
  puts "== Total $size drivers ==\n"
}

source $env(NPIL1_PATH)/npi_L1.tcl
schSetPreference -detailLevel 100 -detailRTL on -detailMux on -recogFSM off -expandGenBlock on

#debImport "-sv" "example.v"

::npi_L1::npi_nl_hier_tree_trv_register_cb "npiNlDeclNet"  "driver_demo" ""
::npi_L1::npi_nl_hier_tree_trv_register_cb "npiNlPort"     "driver_demo" ""
::npi_L1::npi_nl_hier_tree_trv_register_cb "npiNlInstPort" "driver_demo" ""
::npi_L1::npi_nl_hier_tree_trv

debExit

