#debImport "example.v"

set file_hdl [ npi_text_file_by_name -name "example.v" ]
puts "file string property: "
puts "  file absolute name:"
puts -nonewline "    "
puts [ npi_text_property_str -type "npiTextFileFullName" -ref $file_hdl ]
puts "  file name:"
puts -nonewline "    "
puts [ npi_text_property_str -type "npiTextFileName" -ref $file_hdl ]
puts "  file content:"
puts [ npi_text_property_str -type "npiTextFileContent" -ref $file_hdl ]
set line_iter [ npi_text_iter_start -type "npiTextLine" -ref $file_hdl ]
set line_hdl [ npi_text_iter_next -iter $line_iter ]
puts "line string property: "
puts "  line content:"
puts [ npi_text_property_str -type "npiTextLineContent" -ref $line_hdl ]
set word_iter [ npi_text_iter_start -type "npiTextWord" -ref $line_hdl ]
set word_hdl [ npi_text_iter_next -iter $word_iter ]
puts "word string property: "
puts -nonewline "  word name: "
puts [ npi_text_property_str -type "npiTextWordName" -ref $word_hdl ]
puts -nonewline "  word attribute: "
puts [ npi_text_property_str -type "npiTextWordAttribute" -ref $word_hdl ]
npi_text_iter_stop -iter $word_iter
npi_text_iter_stop -iter $line_iter

debExit
