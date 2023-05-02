# The command is :
#     novas -sv example.v -play main.tcl
 
proc get_and_print_value { hdl const_type } {
 
  set size [ npi_get -property npiSize -object $hdl ]
 
  if { [ npi_get -property npiSigned -object $hdl ] == 1 } {
    set sign_str "s" 
  } else { set sign_str "" }
 
  switch -- $const_type {
    npiDecConst {
      set value [ npi_get_value -format npiDecStrVal -object $hdl ]
      set value_str [format "%d'%sd%s" $size $sign_str $value]
    }
    npiRealConst {
      set value [ npi_get_value -format npiRealVal -object $hdl ]
      set value_str [format "%s" $value]
    }
    npiBinaryConst {
      set value [ npi_get_value -format npiBinStrVal -object $hdl ]
      set value_str [format "%d'%sb%s" $size $sign_str $value]
    }
    npiOctConst {
      set value [ npi_get_value -format npiOctStrVal -object $hdl ]
      set value_str [format "%d'%so%s" $size $sign_str $value]
    }
    npiHexConst {
      set value [ npi_get_value -format npiHexStrVal -object $hdl ]
      set value_str [format "%d'%sh%s" $size $sign_str $value]
    }
    npiStringConst {
      set value [ npi_get_value -format npiStringVal -object $hdl ]
      set value_str [format "\"%s\"" $value]
    }
    npiIntConst -
    default {
      set value [ npi_get_value -format npiIntVal -object $hdl ]
      set value_str [format "%s" $value]
    }
  }
  return $value_str
}
# ----------------------------------------------------------------------
# main
# ----------------------------------------------------------------------
 
set top_hdl [ npi_handle_by_name -name "top" -scope "" ]
set param_itr [ npi_iterate -type npiParameter -refHandle $top_hdl ]
if { $param_itr == "" } { debExit }
 
while { [ set param_hdl [ npi_scan -iterator $param_itr ] ] != "" } {
  set const_hdl   [ npi_handle -type npiExpr -refHandle $param_hdl ]
  if { [ npi_get_str -property npiType -object $const_hdl ] == "npiConstant" } {
    set const_type  [ npi_get_str -property npiConstType -object $const_hdl ]
  } else {
    set const_type "npiIntConst"
  }
  set hdl_name    [ npi_get_str -property npiName -object $param_hdl ]
  set value_str   [ get_and_print_value $param_hdl $const_type ]
  puts [ format "  %-15s = %s" $hdl_name $value_str ]
}
 
debExit
