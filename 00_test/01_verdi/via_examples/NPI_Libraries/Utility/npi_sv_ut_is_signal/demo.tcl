proc signal_check { hdl } {
  if { [ ::npi_L1::npi_sv_ut_is_signal $hdl ] == 1 } {
    puts -nonewline "Signal => "
  } else {
    puts -nonewline "Not a signal => "
  }
  ::npi_L1::npi_sv_ut_dump_hdl_info $hdl "stdout"
}


source $env(NPIL1_PATH)/npi_L1.tcl

#debImport -sv example.v

set instHdl [ npi_handle_by_name -name "top" -scope "" ]
set itr [ npi_iterate -type npiContAssign -refHandle $instHdl ]
while { [ set subHdl [ npi_scan -iterator $itr ]] != "" } {
  set lhsHdl [ npi_handle -type npiLhs -refHandle $subHdl ]
  set rhsHdl [ npi_handle -type npiRhs -refHandle $subHdl ]
  signal_check $lhsHdl
  signal_check $rhsHdl
  npi_release_handle -object $lhsHdl
  npi_release_handle -object $rhsHdl
  npi_release_handle -object $subHdl
}

debExit
