
puts ""

set file_hdl [npi_text_file_by_name -name "example.v"]
if { $file_hdl != "" } {
    set line_19_hdl [npi_text_line_by_number -ref $file_hdl -number 19]
    if { $line_19_hdl != "" } {
        puts "Line 19 at file example.v"
        puts "========================="
        puts -nonewline "[npi_text_property_str -type npiTextLineContent -ref $line_19_hdl]"
        puts "========================="
    }
}

debExit

