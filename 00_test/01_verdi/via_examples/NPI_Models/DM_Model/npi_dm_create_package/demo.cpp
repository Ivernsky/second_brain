#include <stdio.h>
#include <stdlib.h>
#include "npi.h"
#include "npi_dm.h"

int main (int argc, char **argv)
{
  npi_init( argc, argv );
  npi_load_design( argc, argv );

  //-- DM operation --------------------------------------------------------------
  npi_dm_create_package( "ndm_package1", "ndm_package1.sv" );
  npi_dm_create_package( "ndm_package2", "ndm_package2.sv" );

  // Write to directory "DM_LIB"
  npi_dm_write_text_mode( "DM_LIB" );
  //------------------------------------------------------------------------------

  npi_end();
  return 0;
}
