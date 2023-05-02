
#debImport "example.v"
set fp [ open "demo.list" "r" ]
if { $fp == "" } {
  puts "Can not open the file!"
}
while { [ gets $fp hdlNameStr ] >= 0 } {
# find the handle by name
  set hdl [ npi_nl_handle_by_name -name $hdlNameStr ]
  if { $hdl == "" } {
    continue
  }
  # dump the handle according to its type
  set type [ npi_nl_get_str -property npiNlType -object $hdl ]
  switch -- $type {
    "npiNlInst"    {
      set fullName [ npi_nl_get_str -property npiNlFullName -object $hdl ]
      set instType [ npi_nl_get_str -property npiNlInstType -object $hdl ]
      puts "Instance object \"$fullName\" is found, instance type is $instType."
    }
    "npiNlDeclNet" {
      set fullName [ npi_nl_get_str -property npiNlFullName -object $hdl ]
      set size [ npi_nl_get -property npiNlSize -object $hdl ]
      puts "Net object \"$fullName\" is found, size is $size."
    }
    default        { }
  }
  npi_nl_release_handle -object $hdl
}
close $fp
debExit
