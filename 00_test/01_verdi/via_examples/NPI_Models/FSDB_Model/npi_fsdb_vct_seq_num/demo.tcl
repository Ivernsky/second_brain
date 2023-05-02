
proc goto_time_and_get_seq_num { fsdbFile sigName targetTime } {
  set sig [npi_fsdb_sig_by_name -file $fsdbFile -name $sigName -scope ""]
  set vct [npi_fsdb_create_vct -sig $sig]
  npi_fsdb_goto_time -vct $vct -time $targetTime
  set vctTime [npi_fsdb_vct_time -vct $vct]
  set seqNum [npi_fsdb_vct_seq_num -vct $vct]
  puts "$sigName has vc at time $vctTime, seq num = $seqNum"
  npi_fsdb_release_vct -vct $vct
}

set fsdbFileName "demo.fsdb"
set fsdbFile [npi_fsdb_open -name $fsdbFileName]
set hasSeqNum [npi_fsdb_file_property -type npiFsdbFileHasSeqNum -file $fsdbFile]

if { $hasSeqNum != "" } {
  puts "Has Seq Num? $hasSeqNum"
} else {
  puts "Failed to get seq num property for file"
}

goto_time_and_get_seq_num $fsdbFile "test.clk" 1000
goto_time_and_get_seq_num $fsdbFile "test.D" 1000
goto_time_and_get_seq_num $fsdbFile "test.Q" 1000

npi_fsdb_close -file $fsdbFile
debExit
