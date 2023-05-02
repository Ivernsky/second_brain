#include <stdio.h>
#include <stdlib.h>
#include "npi.h"
#include "npi_dm.h"

int main (int argc, char **argv)
{
  npi_init( argc, argv );
  npi_load_design( argc, argv );
  
  //-- DM operation --------------------------------------------------------------
  // Get interface named Itf
  npiDmHandle Itf = npi_dm_interface_by_name( "Itf" );
  printf( "Object name: %s\n", npi_dm_property_str( npiDmName, Itf ) );
  
  //------------------------------------------------------------------------------

  npi_end();
  return 0;
}
