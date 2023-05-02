#debImport "example.v"

set file_hdl [ npi_text_file_by_name -name "example.v" ]
set line_iter [ npi_text_iter_start -type "npiTextLine" -ref $file_hdl ]
set line_hdl [ npi_text_iter_next -iter $line_iter ]
set line_hdl [ npi_text_iter_next -iter $line_iter ]
set delete_result [ npi_text_delete_line -ref $line_hdl ]
set result_file [ npi_text_property_str -type "npiTextFileContent" -ref $file_hdl ]
puts -nonewline $result_file

debExit
