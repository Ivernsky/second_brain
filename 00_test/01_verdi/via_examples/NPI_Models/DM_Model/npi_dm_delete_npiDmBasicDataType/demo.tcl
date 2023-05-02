## Generate object npiDmHandleArray
set npiPRange1 [npi_dm_create_range -left 7 -right 0]
set npiPRange2 [npi_dm_create_range -left 4 -right 0]
set npiPArray  [npi_dm_create_npiDmHandleArray -array_list $npiPRange1 $npiPRange2]
 
## Generate object npiDmBasicDataType
set npiDataType [npi_dm_create_npiDmBasicDataType -type npiDmDtLogic -sign npiDmSignNone -packed_dim $npiPArray]

npi_dm_delete_npiDmBasicDataType -data_type $npiDataType

