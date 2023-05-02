#include <stdio.h>
#include <stdlib.h>
#include "npi.h"
#include "npi_dm.h"

int main (int argc, char **argv)
{
  npi_init( argc, argv );
  npi_load_design( argc, argv );
  
  //-- DM operation --------------------------------------------------------------
  npiDmHandle TOP = npi_dm_module_by_name( "TOP" );
  npiDmHandle MOD = npi_dm_module_by_name( "MOD" );

  printf( "Property top module of TOP: %d\n", npi_dm_property( npiDmTopModule, TOP ) );
  printf( "Property top module of MOD: %d\n", npi_dm_property( npiDmTopModule, MOD ) );
  //------------------------------------------------------------------------------

  npi_end();
  return 0;
}
