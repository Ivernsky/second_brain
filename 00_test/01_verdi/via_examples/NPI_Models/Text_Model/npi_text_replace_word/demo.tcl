
set file_hdl [ npi_text_file_by_name -name "example.v" ]
set line_iter [ npi_text_iter_start -type "npiTextLine" -ref $file_hdl ]
set line_hdl [ npi_text_iter_next -iter $line_iter ]
set line_hdl [ npi_text_iter_next -iter $line_iter ]
set line_hdl [ npi_text_iter_next -iter $line_iter ]
set line_hdl [ npi_text_iter_next -iter $line_iter ]
set line_hdl [ npi_text_iter_next -iter $line_iter ]
set line_hdl [ npi_text_iter_next -iter $line_iter ]
set word_iter [ npi_text_iter_start -type "npiTextWord" -ref $line_hdl ]
set word_hdl [ npi_text_iter_next -iter $word_iter ]
set word_hdl [ npi_text_iter_next -iter $word_iter ]
set word_hdl [ npi_text_iter_next -iter $word_iter ]
set word_hdl [ npi_text_iter_next -iter $word_iter ]
set replaced_word [ npi_text_replace_word -ref $word_hdl -word "AND_g1" ]
npi_text_iter_stop -iter $word_iter
npi_text_iter_stop -iter $line_iter
set result_line [ npi_text_property_str -type "npiTextLineContent" -ref $line_hdl ]
puts -nonewline $result_line

debExit
