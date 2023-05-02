# source npi_L1.tcl from path NPIL1_PATH
source $env(NPIL1_PATH)/npi_L1.tcl

## import the design from the file list (debImport is a Verdi TCL command)
schSetPreference -detailRTL on -detailMux on -recogFSM off -expandGenBlock on
#debImport "-sv" "example.v"

# setup the string for handles' nl_names
set scopeHierName "top.i_ff"
set instNlName "flipflop:Always1#Always0:11:16:Reg"
set portNlName "din"
set instportNlName "ARL_reset"
set netNlName "1'b1"

# find handles by nl_names
set instHdl [ ::npi_L1::npi_nl_inst_handle_by_nl_name $scopeHierName $instNlName ]
set portHdl [ ::npi_L1::npi_nl_port_handle_by_nl_name $scopeHierName $portNlName ]
set instportHdl [ ::npi_L1::npi_nl_instport_handle_by_nl_name $scopeHierName $instNlName $instportNlName ]
set netHdl [ ::npi_L1::npi_nl_net_handle_by_nl_name $scopeHierName $netNlName ]

# dump handles
::npi_L1::npi_nl_ut_dump_hdl_info $instHdl "stdout"
::npi_L1::npi_nl_ut_dump_hdl_info $portHdl "stdout"
::npi_L1::npi_nl_ut_dump_hdl_info $instportHdl "stdout"
::npi_L1::npi_nl_ut_dump_hdl_info $netHdl "stdout"

# below is the Verdi TCL command that will leave Novas executable
debExit

