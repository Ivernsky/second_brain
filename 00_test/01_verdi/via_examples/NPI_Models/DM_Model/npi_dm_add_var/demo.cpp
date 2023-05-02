#include <stdio.h>
#include <stdlib.h>
#include "npi.h"
#include "npi_dm.h"

int main(int argc, char **argv)
{
  npi_init( argc, argv );
  npi_load_design( argc, argv );

  //-- DM operation --------------------------------------------------------------
  npiDmHandle MOD = npi_dm_module_by_name( "MOD" );

  // "bit [7:0] ndm_var [255:0];"
  // prepare range
  npiDmHandle range_7_to_0   = npi_dm_create_range( 7, 0 );
  npiDmHandle range_255_to_0 = npi_dm_create_range( 255, 0 );

  // prepare packed dimension
  npiDmHandleArray packed_dim;
  packed_dim.size     = 1;
  packed_dim.array[0] = range_7_to_0;

  // prepare date type
  npiDmBasicDataType data_type;
  data_type.type       = npiDmDtBit;
  data_type.signing    = npiDmSignNone;
  data_type.packed_dim = &packed_dim;

  // prepare unpacked dimension
  npiDmHandleArray unpacked_dim;
  unpacked_dim.size     = 1;
  unpacked_dim.array[0] = range_255_to_0;

  // Add varible
  npiDmHandle ndm_var = npi_dm_add_var( MOD, "ndm_var", &data_type, &unpacked_dim );

  // Write to directory "DM_LIB"
  npi_dm_write_text_mode( "DM_LIB" );
  //------------------------------------------------------------------------------

  npi_end();
  return 0;
}

