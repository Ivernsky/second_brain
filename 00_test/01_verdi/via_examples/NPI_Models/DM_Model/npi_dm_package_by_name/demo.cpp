#include <stdio.h>
#include <stdlib.h>
#include "npi.h"
#include "npi_dm.h"

int main (int argc, char **argv)
{
  npi_init( argc, argv );
  npi_load_design( argc, argv );
  
  //-- DM operation --------------------------------------------------------------
  // Get package named pkg 
  npiDmHandle pkg = npi_dm_package_by_name( "pkg" );
  printf( "Object name: %s\n", npi_dm_property_str( npiDmName, pkg ) );  
  //------------------------------------------------------------------------------

  npi_end();
  return 0;
}
