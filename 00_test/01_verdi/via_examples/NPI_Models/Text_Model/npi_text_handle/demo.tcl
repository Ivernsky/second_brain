#debImport "example.v"

set file_hdl [ npi_text_file_by_name -name "example.v" ]
set file_hdl_handle_1 [ npi_text_handle -type "npiTextFile" -ref $file_hdl ]
set file_hdl_handle_2 [ npi_text_handle -type "npiTextLine" -ref $file_hdl ]
if { $file_hdl_handle_1 == "" } {
  puts "file_hdl_handle_1 is NULL"
}
if { $file_hdl_handle_2 == "" } {
  puts "file_hdl_handle_2 is NULL"
}

set line_iter [ npi_text_iter_start -type "npiTextLine" -ref $file_hdl ]
set line_hdl [ npi_text_iter_next -iter $line_iter ]
set line_hdl_handle_1 [ npi_text_handle -type "npiTextFile" -ref $line_hdl ]
set line_hdl_handle_2 [ npi_text_handle -type "npiTextLine" -ref $line_hdl ]
if { $line_hdl_handle_1 == $file_hdl } {
  puts "line_hdl_handle_1 is file_hdl"
}
if { $line_hdl_handle_2 == "" } {
  puts "line_hdl_handle_2 is NULL"
}

set word_iter [ npi_text_iter_start -type "npiTextWord" -ref $line_hdl ]
set word_hdl [ npi_text_iter_next -iter $word_iter ]
set word_hdl_handle_1 [ npi_text_handle -type "npiTextFile" -ref $word_hdl ]
set word_hdl_handle_2 [ npi_text_handle -type "npiTextLine" -ref $word_hdl ]
if { $word_hdl_handle_1 == "" } {
  puts "word_hdl_handle_1 is NULL"
}
if { $word_hdl_handle_2 == $line_hdl } {
  puts "word_hdl_handle_2 is line_hdl"
}

npi_text_iter_stop -iter $word_iter
npi_text_iter_stop -iter $line_iter

debExit
