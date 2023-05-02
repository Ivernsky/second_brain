#include <stdio.h>
#include <stdlib.h>
#include "npi.h"
#include "npi_dm.h"

int main (int argc, char **argv)
{
  npi_init( argc, argv );
  npi_load_design( argc, argv );
  
  //-- DM operation --------------------------------------------------------------
  npiDmHandle MOD       = npi_dm_module_by_name( "MOD" );
  npiDmIter   port_iter = npi_dm_iter_start( npiDmPort, MOD );
  
  npiDmHandle port;
  while ( port = npi_dm_iter_next( port_iter ) )
  {
    // Actions on port 
    printf( "Object name: %s\n", npi_dm_property_str( npiDmName, port ) );
  }
  npi_dm_iter_stop( port_iter );
  
  //------------------------------------------------------------------------------

  npi_end();
  return 0;
}
