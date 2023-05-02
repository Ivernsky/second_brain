
set file_iter [ npi_text_iter_start -type "npiTextFile" -ref "" ]
while { "" != [ set file_hdl [ npi_text_iter_next -iter $file_iter ] ] } {
  set file_name [ npi_text_property_str -type "npiTextFileName" -ref $file_hdl ]
  puts $file_name
}
npi_text_iter_stop -iter $file_iter

debExit
