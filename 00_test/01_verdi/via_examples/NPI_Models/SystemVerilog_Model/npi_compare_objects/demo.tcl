# The command is :
#     novas -sv example.v -play main.tcl
 
proc check_bit_sel_idx {lhs rhs} {
  if {$lhs == "" || $rhs == ""} {
    return 0
  }
 
  if {[npi_get_str -property npiType -object $lhs] != "npiBitSelect" ||
      [npi_get_str -property npiType -object $rhs] != "npiBitSelect"} {
    return 0
  }
 
  set itrL [npi_iterate -type npiIndex -refHandle $lhs]
  set itrR [npi_iterate -type npiIndex -refHandle $rhs]
  set idxL ""
  set idxR ""
  while {[set idxL [npi_scan -iterator $itrL]] != "" && [set idxR [npi_scan -iterator $itrR]] != ""} {
    set ret [npi_compare_objects -object1 $idxL -object2 $idxR]
    npi_release_handle -object $idxL
    npi_release_handle -object $idxR
    return $ret
  }
  return 0
}
 
proc check_stmt {hdl} {
  if {$hdl == "" || [npi_get_str -property npiType -object $hdl] != "npiAssignment"} {
    return
  }
  set lhs [npi_handle -type npiLhs -refHandle $hdl]
  set rhs [npi_handle -type npiRhs -refHandle $hdl]
 
  if {[check_bit_sel_idx $lhs $rhs] > 0} {
    puts "Lhs-index and rhs-index for line [npi_get -property npiLineNo -object $hdl] are the same"
    return
  }
 
  puts -nonewline "Lhs and rhs for line [npi_get -property npiLineNo -object $hdl] are "
  if {[npi_compare_objects -object1 $lhs -object2 $rhs] == 1} {
    puts "the same";
  } else {
    puts "different";
  }
  npi_release_handle -object $lhs
  npi_release_handle -object $rhs
}
 
proc trv_scope {hdl} {
  if {$hdl == ""} {
    return
  }
 
  set itr ""
  set stmt ""
  switch -- [npi_get_str -property npiType -object $hdl] {
    npiTask -
    npiFunction -
    npiNamedBegin -
    npiBegin -
    npiNamedFork -
    npiFork {
      set itr [npi_iterate -type npiStmt -refHandle $hdl]
      if {$itr != ""} {
        while {[set stmt [npi_scan -iterator $itr]] != ""} {
          check_stmt $stmt
          npi_release_handle -object $stmt
        }
      }
    }
    default {
    }
  }
 
  set itr [npi_iterate -type npiInternalScope -refHandle $hdl]
  if {$itr == ""} {
    return
  }
  while {[set sub_scp [npi_scan -iterator $itr]] != ""} {
    trv_scope $sub_scp
    npi_release_handle -object $sub_scp
  }
}
 
proc compare_both_side_for_assignment {} {
  set itr [npi_iterate -type npiInstance -refHandle ""]
  if {$itr == ""} {
    return
  }
  set top_inst ""
  while {[set top_inst [npi_scan -iterator $itr]] != ""} {
    trv_scope $top_inst
    npi_release_handle -object $top_inst
  }
}
 
compare_both_side_for_assignment
debExit
