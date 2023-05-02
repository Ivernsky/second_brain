#include <stdio.h>
#include <stdlib.h>
#include "npi.h"
#include "npi_dm.h"

int main (int argc, char **argv)
{
  npi_init( argc, argv );
  npi_load_design( argc, argv );
  
  //-- DM operation --------------------------------------------------------------
  npiDmHandle MOD = npi_dm_module_by_name( "MOD" );
  npiDmHandle TOP = npi_dm_module_by_name( "TOP" );

  npiDmHandle inst2 = npi_dm_add_instance( MOD, "inst2", TOP );

  npiDmHandleArray unpacked_dim;
  unpacked_dim.size     = 1;
  unpacked_dim.array[0] = npi_dm_create_range( 1, 0 );
  npiDmHandle inst3     = npi_dm_add_instance( MOD, "inst3", &unpacked_dim, TOP );

  // Write to directory "DM_LIB"
  npi_dm_write_text_mode( "DM_LIB" );
  //------------------------------------------------------------------------------

  npi_end();
  return 0;
}
