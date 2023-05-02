#debImport "example.v"

set file_hdl [ npi_text_file_by_name -name "example.v" ]
set line_iter [ npi_text_iter_start -type "npiTextLine" -ref $file_hdl ]
set line_hdl [ npi_text_iter_next -iter $line_iter ]
set line_hdl [ npi_text_iter_next -iter $line_iter ]
set word_iter [ npi_text_iter_start -type "npiTextWord" -ref $line_hdl ]
while { "" != [ set word_hdl [ npi_text_iter_next -iter $word_iter ] ] } {
  if { ";" == [ npi_text_property_str -type "npiTextWordName" -ref $word_hdl ] } {
    set inserted_word_hdl [ npi_text_insert_word_after -ref $word_hdl -word " //inputs" ]
  }
}
npi_text_iter_stop -iter $word_iter
npi_text_iter_stop -iter $line_iter
set result_line [ npi_text_property_str -type "npiTextLineContent" -ref $line_hdl ]
puts -nonewline $result_line

debExit
