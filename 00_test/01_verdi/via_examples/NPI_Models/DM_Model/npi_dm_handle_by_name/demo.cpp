#include <stdio.h>
#include <stdlib.h>
#include "npi.h"
#include "npi_dm.h"

int main (int argc, char **argv)
{
  npi_init( argc, argv );
  npi_load_design( argc, argv );
  
  //-- DM operation --------------------------------------------------------------
  // Get module named TOP
  npiDmHandle TOP = npi_dm_handle_by_name( "TOP", NULL );
  printf( "Object name: %s\n", npi_dm_property_str( npiDmName, TOP ) );
  
  // Get instance named i0 in TOP module ( TOP.b )
  npiDmHandle i0 = npi_dm_handle_by_name( "i0", TOP );
  printf( "Object name: %s\n", npi_dm_property_str( npiDmName, i0 ) );
  
  // Get net named ndm_net in TOP module ( TOP.c )
  npiDmHandle ndm_net = npi_dm_handle_by_name( "TOP.ndm_net", NULL );
  printf( "Object name: %s\n", npi_dm_property_str( npiDmName, ndm_net ) );
  
  //------------------------------------------------------------------------------

  npi_end();
  return 0;
}
