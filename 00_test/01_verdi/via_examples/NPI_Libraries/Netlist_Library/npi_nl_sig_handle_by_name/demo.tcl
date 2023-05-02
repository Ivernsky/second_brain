# source npi_L1.tcl from path NPIL1_PATH
source $env(NPIL1_PATH)/npi_L1.tcl

## import the design from the file list (debImport is a Verdi TCL command)
schSetPreference -detailRTL on -detailMux on -recogFSM off -expandGenBlock on
#debImport "-sv" "example.v" "-v" "lib.v"

set sigNameList { 
  "top.a"
  "top.b[1]"
  "top.c[21:20]"
  "top.u1.Z[1:0]"
  "top.u1.A[31]"
  "top.u1.B[16:15]" 
}

for { set i 0 } { $i < 6 } { incr i } {
  set sigName [ lindex $sigNameList $i ]
  set sigHdl [ ::npi_L1::npi_nl_sig_handle_by_name $sigName ]
  ::npi_L1::npi_nl_ut_dump_hdl_info $sigHdl "stdout"
  npi_nl_release_handle -object $sigHdl
}

# below is the Verdi TCL command that will leave Novas executable
debExit

