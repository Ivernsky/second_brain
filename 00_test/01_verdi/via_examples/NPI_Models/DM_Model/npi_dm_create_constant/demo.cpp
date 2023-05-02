#include <stdio.h>
#include <stdlib.h>
#include "npi.h"
#include "npi_dm.h"

int main (int argc, char **argv)
{
  npi_init( argc, argv );
  npi_load_design( argc, argv );

  //-- DM operation --------------------------------------------------------------
  npiDmHandle c1 = npi_dm_create_constant( 3 );
  npiDmHandle c2 = npi_dm_create_constant( 3 );
  if ( c1 == c2 )
    printf( "c1 and c2 are the same object.\n" );

  // Use string as value input
  npiDmHandle c3 = npi_dm_create_constant( "32'd11" );
  npiDmHandle c4 = npi_dm_create_constant( "32'd11" );
  if ( c3 == c4 )
    printf( "c3 and c4 are the same object.\n" );

  // Other constant type examples
  // exponential constant
  npiDmHandle c5 = npi_dm_create_constant( "32e-10" );
  
  // fixed point constant
  npiDmHandle c6 = npi_dm_create_constant( "12.07" );
  
  // string constant
  npiDmHandle c7 = npi_dm_create_constant( "\"springsoft\"" );
  //------------------------------------------------------------------------------

  npi_end();
  return 0;
}

