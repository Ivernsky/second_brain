set file_name "demo.fsdb"
set sigA_name "test.M1.A"
set sigB_name "test.M1.B"

# open the FSDB file
set file_hdl [npi_fsdb_open -name $file_name]
if { $file_hdl != "" } {

# get signal handle by name
  set sigA_hdl [npi_fsdb_sig_by_name -file $file_hdl -name $sigA_name -scope ""]
  set sigB_hdl [npi_fsdb_sig_by_name -file $file_hdl -name $sigB_name -scope ""]

# Add sigA and sigB to the signal list
  npi_fsdb_add_to_sig_list -file $file_hdl -sig $sigA_hdl
  npi_fsdb_add_to_sig_list -file $file_hdl -sig $sigB_hdl

#load value changes of sigA and sigB between 10000 and 50000 into memory
  npi_fsdb_load_vc_by_range -file $file_hdl -start 10000 -end 50000  

#reset signal list
  npi_fsdb_reset_sig_list -file $file_hdl

  if { $sigA_hdl != "" } {

# create signal handle
    set vct_hdl [npi_fsdb_create_vct -sig $sigA_hdl]

# find VC between time 20000 and 50000 
    if { [ npi_fsdb_goto_time -vct $vct_hdl -time 50000 ] == 1 } {
      while { [npi_fsdb_goto_prev -vct $vct_hdl] == 1 } {
        set vct_time [npi_fsdb_vct_time -vct $vct_hdl]
        if { $vct_time >= 2000 } {
          puts "Time $vct_time, sigA has VC."
} else {
  break;
}
      }
}
       }

# close the FSDB file
npi_fsdb_close -file $file_hdl
}

# below is the Verdi Tcl command that will leave Novas executable
debExit

