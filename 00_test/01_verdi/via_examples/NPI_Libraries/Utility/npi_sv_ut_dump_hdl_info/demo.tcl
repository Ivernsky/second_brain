source $env(NPIL1_PATH)/npi_L1.tcl

#debImport -sv example.v

set hdlList {}
set instHdl [ npi_handle_by_name -name "top" -scope "" ]
set itr [ npi_iterate -type npiNet -refHandle $instHdl ]
while { [ set subHdl [ npi_scan -iterator $itr ]] != "" } {
  lappend hdlList $subHdl
}

# get the hdl information and print it
set hdlInfo [ ::npi_L1::npi_sv_ut_get_hdl_info $instHdl ]
puts "$hdlInfo"
# dump the handle information usin L1 API
::npi_L1::npi_sv_ut_dump_hdl_info $instHdl "stdout"
# dump and release the handles in the hdl vector
::npi_L1::npi_sv_ut_dump_hdl_vec_info "hdlList" "stdout" 1

debExit

