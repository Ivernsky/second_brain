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
  npiDmHandle TOP = npi_dm_module_by_name( "TOP" );
  printf( "Object name: %s\n", npi_dm_property_str( npiDmName, TOP ) );
  
  // Get module named MOD
  npiDmHandle MOD = npi_dm_module_by_name( "MOD" );
  printf( "Object name: %s\n", npi_dm_property_str( npiDmName, MOD ) );
  
  //------------------------------------------------------------------------------

  npi_end();
  return 0;
}
