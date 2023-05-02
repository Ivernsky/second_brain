#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "npi.h"
#include "npi_dm.h"

int main (int argc, char **argv)
{
  npi_init( argc, argv );
  npi_load_design( argc, argv );
  
  //-- DM operation --------------------------------------------------------------
  npiDmHandle        top = npi_dm_module_by_name( "top" );
  npiDmBasicDataType dt;
  npiDmHandleArray   ary;

  ary.size      = 1;
  ary.array[0]  = npi_dm_create_range( 1, 0 );
  dt.packed_dim = &ary;
  dt.signing    = npiDmSignNone;
  dt.type       = npiDmDtBit;

  npiDmHandle PT = npi_dm_add_type_parameter( top, "PT", &dt );
  
  // Write to directory "DM_LIB"
  npi_dm_write_text_mode( "DM_LIB" );
  //------------------------------------------------------------------------------

  npi_end();
  return 0;
}
