#include <stdio.h>
#include <stdlib.h>
#include "npi.h"
#include "npi_dm.h"

int main (int argc, char **argv)
{
  npi_init( argc, argv );
  npi_load_design( argc, argv );
  
  //-- DM operation --------------------------------------------------------------
  npiDmHandle MOD  = npi_dm_module_by_name( "MOD" );
  npiDmHandle inst = npi_dm_handle_by_name( "TOP.ndm_instance", NULL );
  npiDmHandle port = npi_dm_port_by_name( "a", MOD );
  npi_dm_delete_port_connection( inst, port );

  // Write to directory "DM_LIB"
  npi_dm_write_text_mode( "DM_LIB" );
  //------------------------------------------------------------------------------

  npi_end();
  return 0;
}
