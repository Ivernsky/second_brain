# Generate object npiDmHandleArray which contains two range handles
set npiPRange1 [npi_dm_create_range -left 7 -right 0]
set npiPRange2 [npi_dm_create_range -left 4 -right 0]
set npiPArray  [npi_dm_create_npiDmHandleArray -array_list "$npiPRange1 $npiPRange2"]

# Delete object npiDmHandleArray
npi_dm_delete_npiDmHandleArray -array $npiPArray
