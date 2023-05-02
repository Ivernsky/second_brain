#include <stdio.h>
#include <stdlib.h>
#include "npi.h"
#include "npi_dm.h"

int main (int argc, char **argv)
{
  npi_init( argc, argv );
  npi_load_design( argc, argv );
  
  //-- DM operation --------------------------------------------------------------
  npiDmHandle i0 = npi_dm_handle_by_name( "TOP.i0", NULL );
  npiDmHandle PT = npi_dm_handle_by_name( "TOP.i0.PT", NULL );
  
  npiDmBasicDataType dt;
  dt.packed_dim = NULL;
  dt.signing    = npiDmSignUnsigned;
  dt.type       = npiDmDtBit;

  npi_dm_assign_type_parameter( i0, PT, &dt );
  
  // Write to directory "DM_LIB"
  npi_dm_write_text_mode( "DM_LIB" );
  //------------------------------------------------------------------------------

  npi_end();
  return 0;
}
