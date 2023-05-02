#debImport "expand_macro.v"

set ret_flag 0
set macro_flag 1
set file_hdl [ npi_text_file_by_name -name "expand_macro.v" ]
set line_iter [ npi_text_iter_start -type "npiTextLine" -ref $file_hdl ]
set line_hdl [ npi_text_iter_next -iter $line_iter ]
set line_hdl [ npi_text_iter_next -iter $line_iter ]
set line_hdl [ npi_text_iter_next -iter $line_iter ]
set line_hdl [ npi_text_iter_next -iter $line_iter ]
set line_hdl [ npi_text_iter_next -iter $line_iter ]
set line_hdl [ npi_text_iter_next -iter $line_iter ]
set word_iter [ npi_text_iter_start -type "npiTextWord" -ref $line_hdl ]

while { "" != [ set word_hdl [ npi_text_iter_next -iter $word_iter ] ] && $macro_flag == 1 } {
  if { "npiTextMacroName" == [ npi_text_property_str -type "npiTextWordAttribute" -ref $word_hdl ] } {
    set ret_flag [ npi_text_expand_macro -ref $word_hdl ]
    set macro_flag 0
  }
}
npi_text_iter_stop -iter $word_iter
npi_text_iter_stop -iter $line_iter

if { 0 != $ret_flag || "" != $file_hdl } {
  puts -nonewline [ npi_text_property_str -type "npiTextFileContent" -ref $file_hdl ]
}

debExit
