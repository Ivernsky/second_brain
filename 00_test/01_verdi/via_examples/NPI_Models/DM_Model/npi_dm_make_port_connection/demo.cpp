#include <stdio.h>
#include <stdlib.h>
#include "npi.h"
#include "npi_dm.h"
 
int main (int argc, char **argv)
{
  npi_init( argc, argv );
  npi_load_design( argc, argv );
 
  //-- DM operation --------------------------------------------------------------
  npiDmHandle inst1 = npi_dm_handle_by_name( "TOP.inst1", NULL );
  npiDmHandle MOD   = npi_dm_handle( npiDmDefine, inst1 );
 
  npiDmHandle port, conn[2];
  conn[0] = npi_dm_handle_by_name( "TOP.w1", NULL );
  conn[1] = npi_dm_handle_by_name( "TOP.w2", NULL );
 
  int i = 0;
  npiDmIter iter = npi_dm_iter_start( npiDmPort, MOD );
  while ( port = npi_dm_iter_next( iter ) )
  {
    npi_dm_make_port_connection( inst1, port, conn[i] );
    i++;
  }
  npi_dm_iter_stop( iter );
 
  // Write to directory "DM_LIB"
  npi_dm_write_text_mode( "DM_LIB" );
  //------------------------------------------------------------------------------
 
  npi_end();
  return 0;
}
