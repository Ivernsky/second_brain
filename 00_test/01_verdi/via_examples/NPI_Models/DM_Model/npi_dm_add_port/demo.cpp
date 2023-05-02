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
  npiDmHandle ndm_port_a = npi_dm_add_port( MOD, "a", npiDmDirInput );
  npiDmHandle ndm_port_b = npi_dm_add_port( MOD, "b", npiDmDirOutput );

  // Write to directory "DM_LIB"
  npi_dm_write_text_mode( "DM_LIB" );
  //------------------------------------------------------------------------------

  npi_end();
  return 0;
}
