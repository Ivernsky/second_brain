
puts ""

set file_hdl [npi_text_file_by_name -name "example.v"]
if { $file_hdl == "" } {
    debExit
}

set line_it [npi_text_iter_start -type npiTextLine -ref $file_hdl]
while { "" != [set line_hdl [npi_text_iter_next -iter $line_it]] } {
    set word_it [npi_text_iter_start -type npiTextWord -ref $line_hdl]
    while { "" != [set word_hdl [npi_text_iter_next -iter $word_it]] } {
        set word_attr [npi_text_property_str -type "npiTextWordAttribute" -ref $word_hdl]
        if { $word_attr == "npiTextIncludeFile" } {
            set inc_file_hdl [npi_text_file_by_include_word -ref $word_hdl]

            set line_no [npi_text_property -type "npiTextLineNumber" -ref $line_hdl]
            set word_name [npi_text_property_str -type "npiTextWordName" -ref $word_hdl]
            set inc_file_name [npi_text_property_str -type "npiTextFileName" -ref $inc_file_hdl]
            set inc_file_elab_name [npi_text_property_str -type "npiTextFileElabName" -ref $inc_file_hdl]
            puts "At example.v, line $line_no, the include word $word_name points to the include file: $inc_file_name ($inc_file_elab_name)"
        }
    }
}
npi_text_iter_stop -iter $line_it

debExit

