proc npi_pw_dumo_obj { hdl } {
  set name [ npi_pw_property_str -type npiPwFullName -ref $hdl ]
  set type [ npi_pw_property_str -type npiPwType -ref $hdl ]
  set lineNo [ npi_pw_property -type npiPwLineNo -ref $hdl ]
  puts "$name\($type\) at line $lineNo"
}

proc npi_pw_demo {} {
  # design top
  puts "Design top: [ npi_pw_design_top ]"
  
  # get power domain by name
  set pdSrc [ npi_pw_power_domain_by_name -name "tb/PD_SRC" ]
  npi_pw_dumo_obj $pdSrc

  # iterate supply nets
  set iter [ npi_pw_iter_start -type "npiPwSupplyNet" -ref $pdSrc ]
  while { [ set net [ npi_pw_iter_next -iter $iter ] ] != "" } {
    npi_pw_dumo_obj $net
  }
  npi_pw_iter_stop -iter $iter

  # get supply set handle
  set isoHandle [ npi_pw_handle -ref $pdSrc -type "npiPwIsoSetHandle" ]
  set supplySet [ npi_pw_handle -ref $isoHandle -type "npiPwAssocSupplySet" ]
  npi_pw_dumo_obj $supplySet

  return 0;
}

npi_pw_demo
debExit
