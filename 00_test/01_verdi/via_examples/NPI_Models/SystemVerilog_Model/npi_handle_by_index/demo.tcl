# The command is :
#     novas -sv example.v -play main.tcl
 
# get the var bit handle for "top.r[1]"
set var_hdl [ npi_handle_by_name -name "top.r" -scope "" ]
if { $var_hdl != "" } {
    set idx 1
    set select_hdl [ npi_handle_by_index -object $var_hdl -index $idx ]
    puts -nonewline "Get member [npi_get_str -property npiFullName -object $select_hdl] "
puts "by object [npi_get_str -property npiFullName -object $var_hdl] and index $idx"
}
 
# get the module handle for "top.mArr[0]"
set arr_hdl [ npi_handle_by_name -name "top.mArr" -scope "" ]
if { $arr_hdl != "" } {
    set idx 0
    set select_hdl [ npi_handle_by_index -object $arr_hdl -index $idx ]
    puts -nonewline "Get member [npi_get_str -property npiFullName -object $select_hdl] "
puts "by object [npi_get_str -property npiFullName -object $arr_hdl] and index $idx"
}
 
# leave novas
debExit
