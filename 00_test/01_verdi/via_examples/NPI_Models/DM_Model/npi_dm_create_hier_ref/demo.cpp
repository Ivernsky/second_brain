#include <stdio.h>
#include <stdlib.h>
#include "npi.h"
#include "npi_dm.h"

int main (int argc, char **argv)
{
  npi_init( argc, argv );
  npi_load_design( argc, argv );

  //-- DM operation --------------------------------------------------------------
  npiDmHandle c0  = npi_dm_create_constant( "0" );
  npiDmHandle top = npi_dm_module_by_name( "top" );
  npiDmHandle a   = npi_dm_handle_by_name( "a", top );
  
  // Create index operation [0]
  npiDmHandleArray handle_array;
  handle_array.size     = 1;
  handle_array.array[0] = c0;
  npiDmHandle index     = npi_dm_create_operation( npiDmOpIndex, handle_array );

  // Create ref top
  handle_array.size = 0;
  npiDmHandle ref1  = npi_dm_create_ref( top, handle_array );
  
  // Create ref a[0]
  handle_array.size     = 1;
  handle_array.array[0] = index;
  npiDmHandle ref2      = npi_dm_create_ref( a, handle_array );
  
  // Create hier ref top.a[0]
  handle_array.size     = 2;
  handle_array.array[0] = ref1;
  handle_array.array[1] = ref2;
  npiDmHandle hier_ref  = npi_dm_create_hier_ref( handle_array );

  // Assign
  npi_dm_make_assign_connection( top, hier_ref, c0 );

  // Write to directory "DM_LIB"
  npi_dm_write_text_mode( "DM_LIB" );
  //------------------------------------------------------------------------------

  npi_end();
  return 0;
}
