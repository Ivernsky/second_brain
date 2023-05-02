#include <stdio.h>
#include <stdlib.h>
#include "npi.h"
#include "npi_dm.h"

int main (int argc, char **argv)
{
  npi_init( argc, argv );
  npi_load_design( argc, argv );
  
  //-- DM operation --------------------------------------------------------------
  npiDmHandle top = npi_dm_module_by_name( "TOP" );
  npiDmHandle mod = npi_dm_module_by_name( "MOD" );
  npiDmHandle i0  = npi_dm_handle_by_name( "i0", top );
  npiDmHandle i1  = npi_dm_add_instance( mod, "i1", top );
  npiDmHandle i2  = npi_dm_add_instance( mod, "i2", top );
  npiDmHandle pa  = npi_dm_port_by_name( "a", mod );
  npiDmHandle pb  = npi_dm_port_by_name( "b", mod );
  npiDmHandle a   = npi_dm_handle_by_name( "a", top );
  npiDmHandle b   = npi_dm_handle_by_name( "b", top );
  
  npi_dm_make_port_connection( i1, pa, a );
  npi_dm_make_port_connection( i1, pb, b );
  npi_dm_make_port_connection( i2, pa, a );
  npi_dm_make_port_connection( i2, pb, b );

  npi_dm_sync_format( i1, i0 );
  npi_dm_write_text_mode( "DM_LIB" );
  //------------------------------------------------------------------------------

  npi_end();
  return 0;
}
