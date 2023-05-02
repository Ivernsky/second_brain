#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "npi.h"
#include "npi_dm.h"

int main (int argc, char **argv)
{
  npi_init( argc, argv );
  npi_load_design( argc, argv );
  
  //-- DM operation --------------------------------------------------------------
  npiDmHandle top = npi_dm_module_by_name( "top" );
  npiDmHandle P1  = npi_dm_handle_by_name( "P1", top );
  npiDmHandle P2  = npi_dm_handle_by_name( "P2", top );
  npiDmHandle P3  = npi_dm_add_parameter( top, "P3", NULL, NULL, P2 );
  npiDmHandle P4  = npi_dm_add_parameter( top, "P4", NULL, NULL, npi_dm_create_constant(4) );
  
  // Write to directory "DM_LIB"
  npi_dm_write_text_mode( "DM_LIB" );
  //------------------------------------------------------------------------------

  npi_end();
  return 0;
}
