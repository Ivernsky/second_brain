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
  npiDmHandle i1  = npi_dm_handle_by_name( "TOP.i0.i1", NULL );

  npi_dm_move_instance( i1, TOP );

  // Write to directory "DM_LIB"
  npi_dm_write_text_mode( "DM_LIB" );
  //------------------------------------------------------------------------------

  npi_end();
  return 0;
}
