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
  npiDmHandle P1 = npi_dm_handle_by_name( "TOP.P1", NULL );
  npiDmHandle P2 = npi_dm_handle_by_name( "TOP.i0.P2", NULL );
  
  npi_dm_assign_parameter( i0, P2, P1 );
  
  // Write to directory "DM_LIB"
  npi_dm_write_text_mode( "DM_LIB" );
  //------------------------------------------------------------------------------

  npi_end();
  return 0;
}
