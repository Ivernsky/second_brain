# display procedure
proc display_value_in_diff_format {vct_hdl} {
if { [set value [npi_fsdb_vct_value -vct $vct_hdl -format npiFsdbBinStrVal] ] != ""} {
    puts "value in binary str: $value"
}
if {[set value [npi_fsdb_vct_value -vct $vct_hdl -format npiFsdbOctStrVal] ] != ""} {
    puts "value in octal str: $value"
}
if {[set value [npi_fsdb_vct_value -vct $vct_hdl -format npiFsdbDecStrVal] ] != ""} {
    puts "value in dec str: $value"
}
if {[set value [npi_fsdb_vct_value -vct $vct_hdl -format npiFsdbHexStrVal] ] != ""} {
    puts "value in hex str: $value"
}
if {[set value [npi_fsdb_vct_value -vct $vct_hdl -format npiFsdbSintVal] ] != ""} {
    puts "value in signed integer: $value"
}
if {[set value [npi_fsdb_vct_value -vct $vct_hdl -format npiFsdbUintVal] ] != ""} {
    puts "value in unsigned integer: $value"
}
if {[set value [npi_fsdb_vct_value -vct $vct_hdl -format npiFsdbRealVal] ] != ""} {
    puts "value in real: $value"
}
}
 
# open the FSDB file named "demo.fsdb"
set file_name "demo.fsdb"
set file_hdl [npi_fsdb_open -name $file_name]

if { $file_hdl == "" } {
  puts "Failed to open FSDB: $file_name"
  debExit
}
set sig_hdl [npi_fsdb_sig_by_name -file $file_hdl -name "test.M1.A" -scope ""]
set vct_hdl [npi_fsdb_create_vct -sig $sig_hdl]
npi_fsdb_goto_time -vct $vct_hdl -time 10000

#Reg1 declaration in Verilog: reg [3:0] A;
#Reg1 value @ time 10000: A = 4'b1111;
puts "==A=="
display_value_in_diff_format $vct_hdl

set sig_hdl [npi_fsdb_sig_by_name -file $file_hdl -name "test.M1.RS1" -scope ""]
set vct_hdl [npi_fsdb_create_vct -sig $sig_hdl]
npi_fsdb_goto_time -vct $vct_hdl -time 10000

#RS1 declaration in Verilog: struct { real R; reg [3:0] B; } RS1;
#RS1 value @ time 10000: RS1 = '{ 12.34, 4'b01xx }; 
puts "==RS1=="
display_value_in_diff_format $vct_hdl

# close the FSDB file
npi_fsdb_close -file $file_hdl

# below is the Verdi Tcl command that will leave Novas executable
debExit

