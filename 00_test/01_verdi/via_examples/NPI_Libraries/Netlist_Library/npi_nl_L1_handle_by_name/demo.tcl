source $env(NPIL1_PATH)/npi_L1.tcl

#debImport "-sv" "example.v"

set fullHierName "top.m1.dout\[3:0\]"

set hdl [ ::npi_L1::npi_nl_L1_handle_by_name $fullHierName ]
::npi_L1::npi_nl_ut_dump_hdl_info $hdl "stdout"
set hdl [ ::npi_L1::npi_nl_L1_handle_by_name $fullHierName "npiNlNet" ]
::npi_L1::npi_nl_ut_dump_hdl_info $hdl "stdout"
set hdl [ ::npi_L1::npi_nl_L1_handle_by_name $fullHierName "npiNlPort" ]
::npi_L1::npi_nl_ut_dump_hdl_info $hdl "stdout"
set hdl [ ::npi_L1::npi_nl_L1_handle_by_name $fullHierName "npiNlInstPort" ]
::npi_L1::npi_nl_ut_dump_hdl_info $hdl "stdout"

debExit

