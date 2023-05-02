#include <stdio.h>
#include <stdlib.h>
#include "npi.h"
#include "npi_dm.h"

int main (int argc, char **argv)
{
  npi_init( argc, argv );
  npi_load_design( argc, argv );
  
  //-- DM operation --------------------------------------------------------------
  npiDmHandle inst_i0 = npi_dm_handle_by_name( "TOP.i0", NULL );
  npiDmHandle def_i0  = npi_dm_handle( npiDmDefine, inst_i0 );

  printf( "Object name: %s\n", npi_dm_property_str( npiDmName, def_i0 ) );
  
  //------------------------------------------------------------------------------

  npi_end();
  return 0;
}
