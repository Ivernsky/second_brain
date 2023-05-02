#debImport "example.v"

set file_hdl [ npi_text_file_by_name -name "example.v" ]
puts "file integer property: "
puts -nonewline "  line count = "
puts [ npi_text_property -type "npiTextLineCount" -ref $file_hdl ]
set line_iter [ npi_text_iter_start -type "npiTextLine" -ref $file_hdl ]
set line_hdl [ npi_text_iter_next -iter $line_iter ]
puts "line integer property: "
puts -nonewline "  line index number = "
puts [ npi_text_property -type "npiTextLineNumber" -ref $line_hdl ]
puts -nonewline "  word count = "
puts [ npi_text_property -type "npiTextWordCount" -ref $line_hdl ]
set word_iter [ npi_text_iter_start -type "npiTextWord" -ref $line_hdl ]
set word_hdl [ npi_text_iter_next -iter $word_iter ]
puts "word integer property: "
puts -nonewline "  word index number = "
puts [ npi_text_property -type "npiTextWordNumber" -ref $word_hdl ]
puts -nonewline "  word attribute = "
puts [ npi_text_property -type "npiTextWordAttribute" -ref $word_hdl ]
npi_text_iter_stop -iter $word_iter
npi_text_iter_stop -iter $line_iter

debExit
