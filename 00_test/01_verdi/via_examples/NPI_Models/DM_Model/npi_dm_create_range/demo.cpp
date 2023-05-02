#include <stdio.h>
#include <stdlib.h>
#include "npi.h"
#include "npi_dm.h"

int main (int argc, char **argv)
{
  npi_init( argc, argv );
  npi_load_design( argc, argv );
  
  //-- DM operation --------------------------------------------------------------
  npiDmHandle range_hdl1 = npi_dm_create_range( 7, 0 );
  npiDmHandle range_hdl2 = npi_dm_create_range( 7, 0 );
  if ( range_hdl1 == range_hdl2 )
    printf( "range_hdl1 and range_hdl2 are the same object.\n" );
    
  // Use handle as range input
  npiDmHandle c3 = npi_dm_create_constant( 3 );
  npiDmHandle c0 = npi_dm_create_constant( 0 );
  npiDmHandle range_hdl3 = npi_dm_create_range( c3, c0 );
  //------------------------------------------------------------------------------

  npi_end();
  return 0;
}
