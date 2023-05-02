#include <stdio.h>
#include <stdlib.h>
#include "npi.h"
#include "npi_dm.h"

int main (int argc, char **argv)
{
  npi_init( argc, argv );
  npi_load_design( argc, argv );
  
  //-- DM operation --------------------------------------------------------------
  npiDmHandle i0 = npi_dm_handle_by_name( "top.i0", NULL );
  npiDmHandle P = npi_dm_handle_by_name( "top.i0.P", NULL );
  
  npiDmHandle param_inst = npi_dm_param_instance( i0, P );
  printf( "Object name: %s\n", npi_dm_property_str( npiDmName, param_inst ) );
  //------------------------------------------------------------------------------

  npi_end();
  return 0;
}
