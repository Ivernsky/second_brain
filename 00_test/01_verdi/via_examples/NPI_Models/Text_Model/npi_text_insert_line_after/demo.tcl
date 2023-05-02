#debImport "example.v"

set file_hdl [ npi_text_file_by_name -name "example.v" ]
set line_iter [ npi_text_iter_start -type "npiTextLine" -ref $file_hdl ]
set line_hdl [ npi_text_iter_next -iter $line_iter ]
set line_hdl [ npi_text_iter_next -iter $line_iter ]
set line_hdl [ npi_text_iter_next -iter $line_iter ]
set inserted_line_hdl [ npi_text_insert_line_after -ref $line_hdl -content "  wire c;" ]
set result_file [ npi_text_property_str -type "npiTextFileContent" -ref $file_hdl ]
puts -nonewline $result_file

debExit
