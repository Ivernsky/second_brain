
#include "stdlib.h"
#include "npi.h"
#include "npi_dm.h"

int main (int argc, char **argv)
{
  npi_init( argc, argv );
  npi_load_design( argc, argv );
 
  // -- DM operation ---------------------------------------------------------
  npiDmHandle top = npi_dm_module_by_name( "top" );
  npiDmHandle ET  = npi_dm_add_enum_typespec( top, "ET", NULL, NULL, NULL );
  npi_dm_add_enum_member( ET, "A", npi_dm_create_constant(1) );
  npi_dm_add_enum_member( ET, "B", NULL );

  npi_dm_write_text_mode( "DM_LIB" );

  npi_end();
}
