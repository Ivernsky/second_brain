#include <stdio.h>
#include <stdlib.h>
#include "npi.h"
#include "npi_dm.h"

int main (int argc, char **argv)
{
  npi_init( argc, argv );
  npi_load_design( argc, argv );
  
  //-- DM operation --------------------------------------------------------------
  npiDmHandle top  = npi_dm_module_by_name( "top" );
  npiDmIter   iter = npi_dm_iter_start( npiDmBind, top );
  npiDmHandle bind = npi_dm_iter_next( iter );
  
  npi_dm_delete_bind( bind );


  // Write to directory "DM_LIB"
  npi_dm_write_text_mode( "DM_LIB" );
  //------------------------------------------------------------------------------

  npi_end();
  return 0;
}
