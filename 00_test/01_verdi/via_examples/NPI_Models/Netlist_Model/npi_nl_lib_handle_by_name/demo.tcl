#debImport "example.v"

# get lib handle by name and path
set hdlByNamePath [ npi_nl_lib_handle_by_name -name "demo" -path "./" ]
set name [npi_nl_get_str -property npiNlName -object $hdlByNamePath]
set libPath [npi_nl_get_str -property npiNlLibPath -object $hdlByNamePath]
puts "Lib: $name, Path: $libPath"

# get lib handle by name only, the first matched handle will be returned
set hdlByName [ npi_nl_lib_handle_by_name -name "demo" -path "" ]
set name [npi_nl_get_str -property npiNlName -object $hdlByName]
set libPath [npi_nl_get_str -property npiNlLibPath -object $hdlByName]
puts "Lib: $name, Path: $libPath"

debExit
