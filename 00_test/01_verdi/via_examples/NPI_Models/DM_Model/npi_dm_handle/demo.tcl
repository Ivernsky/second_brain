
# DM operation
set inst_i0 [npi_dm_handle_by_name -name "TOP.i0" -scope ""]
set def_i0  [npi_dm_handle -type npiDmDefine -ref $inst_i0]

puts "Object name: [npi_dm_property_str -type npiDmName -ref $def_i0]"

debExit

