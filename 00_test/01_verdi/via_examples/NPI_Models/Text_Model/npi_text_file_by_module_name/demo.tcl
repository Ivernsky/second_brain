
puts ""

set file_hdl [npi_text_file_by_module_name -name "AAA"]
if { $file_hdl != "" } {
    set fn [npi_text_property_str -type "npiTextFileName" -ref $file_hdl]
    set fn_elab [npi_text_property_str -type "npiTextFileElabName" -ref $file_hdl]
    puts "Module AAA in the file: $fn $fn_elab"
}

set file_hdl [npi_text_file_by_module_name -name "BBB"]
if { $file_hdl != "" } {
    set fn [npi_text_property_str -type "npiTextFileName" -ref $file_hdl]
    set fn_elab [npi_text_property_str -type "npiTextFileElabName" -ref $file_hdl]
    puts "Module BBB in the file: $fn $fn_elab"
}

set file_hdl [npi_text_file_by_module_name -name "CCC"]
if { $file_hdl != "" } {
    set fn [npi_text_property_str -type "npiTextFileName" -ref $file_hdl]
    set fn_elab [npi_text_property_str -type "npiTextFileElabName" -ref $file_hdl]
    puts "Module CCC in the file: $fn $fn_elab"
}

debExit

