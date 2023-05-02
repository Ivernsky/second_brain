set mod [npi_dm_module_by_name -name "test"]
if { $mod != "" } {
  set modName [npi_dm_property_str -type npiDmName -ref $mod]
  set varIter [npi_dm_iter_start -type npiDmParameter -ref $mod]
  while { [set var [npi_dm_iter_next -iter $varIter] ] != "" } {
    set varName [npi_dm_property_str -type npiDmName -ref $var]
    set rightExpr [npi_dm_handle -type npiDmExpr -ref $var]
    if { $rightExpr ne "" } { 
      set constType [npi_dm_property_str -type npiDmConstType -ref $rightExpr]
      if { $constType ne "" } {
        switch -- $constType {
          npiDmConstDec {
            set value [npi_dm_get_value -format npiDmDecStrVal -ref $rightExpr]
            puts [format "%-15s = %s" $varName $value]
          }
          npiDmConstReal {
            set value [npi_dm_get_value -format npiDmRealVal -ref $rightExpr]
            puts [format "%-15s = %s" $varName $value]
          }
          npiDmConstBin {
            set value [npi_dm_get_value -format npiDmBinStrVal -ref $rightExpr]
            puts [format "%-15s = %s" $varName $value]
          }
          npiDmConstOct {
            set value [npi_dm_get_value -format npiDmOctStrVal -ref $rightExpr]
            puts [format "%-15s = %s" $varName $value]
          }
          npiDmConstHex {
            set value [npi_dm_get_value -format npiDmHexStrVal -ref $rightExpr]
            puts [format "%-15s = %s" $varName $value]
          }
          npiDmConstInt {
            set value [npi_dm_get_value -format npiDmIntVal -ref $rightExpr]
            puts [format "%-15s = %s" $varName $value]
          }
          npiDmConstUnbounded {
            set value [npi_dm_get_value -format npiDmBinStrVal -ref $rightExpr]
            puts [format "%-15s = '%s" $varName $value]
          }
          npiDmConstString {
            set value [npi_dm_get_value -format npiDmStringVal -ref $rightExpr]
            puts [format "%-15s = %s" $varName $value]
          }
          default {
            puts [format "%-15s is unsupport type." $varName]
          }
        }
      }
    }
  }
}
debExit
