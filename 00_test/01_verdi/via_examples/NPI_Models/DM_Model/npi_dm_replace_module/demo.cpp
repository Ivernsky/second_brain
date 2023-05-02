#include <stdio.h>
#include <stdlib.h>
#include "npi.h"
#include "npi_dm.h"

int main (int argc, char **argv)
{
  npi_init( argc, argv );
  npi_load_design( argc, argv );
  
  //-- DM operation --------------------------------------------------------------
  npiDmHandle MOD2 = npi_dm_module_by_name( "MOD2" );
  npiDmHandle i0   = npi_dm_handle_by_name( "TOP.i0", NULL );

  npi_dm_replace_module( i0, MOD2 );

  // Write to directory "DM_LIB"
  npi_dm_write_text_mode( "DM_LIB" );
  //------------------------------------------------------------------------------

  npi_end();
  return 0;
}
