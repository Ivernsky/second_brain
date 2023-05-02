source $env(NPIL1_PATH)/npi_L1.tcl

debImport -sv example.v

set file_handle [open "hier_tree.txt" "w"]
::npi_L1::npi_hier_tree_dump_txt "TOP" "$file_handle"
close $file_handle

debExit

