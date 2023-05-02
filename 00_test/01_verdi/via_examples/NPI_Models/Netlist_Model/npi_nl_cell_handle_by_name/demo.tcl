#debImport "example.v"

# get lib handle by name and path
set libHdl [ npi_nl_lib_handle_by_name -name "demo" -path "./" ]

# get cell by name and lib
set dlyHdl [ npi_nl_cell_handle_by_name -name "dly" -libHandle  $libHdl ]
set name [npi_nl_get_str -property npiNlName -object $dlyHdl]
set cellType [npi_nl_get_str -property npiNlCellType -object $dlyHdl]
puts "Cell: $name, Cell Type: $cellType"

# get cell handle by name only, the first matched handle will be returned
set fdHdl [ npi_nl_cell_handle_by_name -name "FD1" -libHandle  $libHdl ]
set name [npi_nl_get_str -property npiNlName -object $fdHdl]
set cellType [npi_nl_get_str -property npiNlCellType -object $fdHdl]
puts "Cell: $name, Cell Type: $cellType"

debExit
