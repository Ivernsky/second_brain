
# Get package named pkg
set pkg [npi_dm_package_by_name -name "pkg"]
puts "Object name: [npi_dm_property_str -type npiDmName -ref $pkg]"

debExit

