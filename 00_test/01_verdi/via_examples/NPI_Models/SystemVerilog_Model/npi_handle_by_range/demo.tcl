# The command is :
#     novas -sv example.v -play main.tcl
 
# get the var bit handle for "top.r[1]"
set var_hdl [ npi_handle_by_name -name "top.r" -scope "" ]
if { $var_hdl != "" } {
    set left 4
    set right 3
    set slice_hdl [ npi_handle_by_range -object $var_hdl -left $left -right $right ]
    if {$slice_hdl != ""} {
       set parent_hdl [ npi_handle -type npiParent -refHandle $slice_hdl ]
       set left_hdl [npi_handle -type npiLeftRange -refHandle $slice_hdl]
       set right_hdl [npi_handle -type npiRightRange -refHandle $slice_hdl]
       puts -nonewline "Get slice handle type [npi_get_str -property npiType -object $slice_hdl] and its range "
       puts -nonewline "\[[ npi_get_value -format npiDecStrVal -object $left_hdl ]:"
       puts -nonewline "[ npi_get_value -format npiDecStrVal -object $right_hdl ]\] "
       puts "and its parent is [npi_get_str -property npiFullName -object $parent_hdl]"
    }
}
 
# leave novas
debExit
