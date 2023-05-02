#debImport example.v

set file_hdl [ npi_text_file_by_name -name "example.v" ]
set line_count [ npi_text_property -type "npiTextLineCount" -ref $file_hdl ]
puts $line_count

debExit
