# invoke NPI Libraries
#source $env(NPIL1_PATH)/npi_L1.tcl
source /software/synopsys/Verdi3_L-2016.06-1/share/NPI/L1/TCL/npi_L1.tcl
# source $VERDI_HOME/share/NPI/L1/TCL/npi_L1.tcl
# dump file name and line number of the module definition “MOD”
# into the file “output.log”
set file_handle [open "output.log" "w"]
::npi_L1::npi_mod_define_dump_fileName_lineNo MOD $file_handle
close $file_handle
# leaving Novas
puts "ok"
debExit
