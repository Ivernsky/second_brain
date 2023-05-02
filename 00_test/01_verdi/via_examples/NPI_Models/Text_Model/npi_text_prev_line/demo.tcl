
puts ""

set file_hdl [npi_text_file_by_name -name "example.v"]
if { $file_hdl != "" } {
    set line_20_hdl [npi_text_line_by_number -ref $file_hdl -number 20]
    if { $line_20_hdl != "" } {
        puts "Line 20 at file example.v"
        puts "========================="
        puts -nonewline "[npi_text_property_str -type npiTextLineContent -ref $line_20_hdl]"
        puts "=========================\n"

        set prev_line_hdl [npi_text_prev_line -ref $line_20_hdl]
        puts "Previous line (line [npi_text_property -type npiTextLineNumber -ref $prev_line_hdl])"
        puts "========================="
        puts -nonewline "[npi_text_property_str -type npiTextLineContent -ref $prev_line_hdl]"
        puts "========================="
    }
}

debExit

