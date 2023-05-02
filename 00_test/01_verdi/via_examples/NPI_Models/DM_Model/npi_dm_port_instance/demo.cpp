#include <stdio.h>
#include <stdlib.h>
#include "npi.h"
#include "npi_dm.h"

int main (int argc, char **argv)
{
  npi_init( argc, argv );
  npi_load_design( argc, argv );
  
  //-- DM operation --------------------------------------------------------------
  npiDmHandle a = npi_dm_port_by_name( "a", npi_dm_module_by_name( "m" ));
  npiDmHandle i0 = npi_dm_handle_by_name( "top.i0", NULL );
  
  npiDmHandle port_inst = npi_dm_port_instance( i0, a );
  printf( "Object name: %s\n", npi_dm_property_str( npiDmName, port_inst ) );
  //------------------------------------------------------------------------------

  npi_end();
  return 0;
}
