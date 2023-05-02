#include <stdio.h>
#include <stdlib.h>
#include "npi.h"
#include "npi_dm.h"
#include <string.h>

void dump_task_call( npiDmHandle task_call )
{
  npiDmHandle scope_hdl = npi_dm_handle( npiDmScope, task_call );
  char* scope_name = (char*)npi_dm_property_str( npiDmName, scope_hdl );
  printf( "scope = %s\n", scope_name );

  char* task_call_type = (char*)npi_dm_property_str( npiDmType, task_call );
  printf( "type = %s\n", task_call_type );

  char* task_call_name = (char*)npi_dm_property_str( npiDmName, task_call );
  printf( "name = %s\n", task_call_name );

  npiDmIter arg_iter = npi_dm_iter_start( npiDmArgInst, task_call );
  int arg_counter = 1;
  npiDmHandle arg = NULL;
  while( NULL != ( arg = npi_dm_iter_next( arg_iter ) ) )
  {
    printf( "  argument %i\n", arg_counter );
    if( strcmp( task_call_type, "npiDmTaskCall" ) == 0 )
    {
      npiDmHandle formal = npi_dm_handle( npiDmFormal, arg );
      char* formal_name = (char*)npi_dm_property_str( npiDmName, formal );
      printf( "    formal_arg = %s\n", formal_name );
    }
    npiDmHandle actual = npi_dm_handle( npiDmActual, arg );
    char* actual_name = (char*)npi_dm_property_str( npiDmName, actual );
    printf( "    actual_arg = %s\n", actual_name );
    arg_counter++;
  }
  npi_dm_iter_stop( arg_iter );
}

int main (int argc, char **argv)
{
  npi_init( argc, argv );
  npi_load_design( argc, argv );

  //-- DM operation --------------------------------------------------------------
  npiDmHandle top = npi_dm_module_by_name( "top" );
  npiDmHandle c1 = npi_dm_create_constant( "\"%f\"" );
  npiDmHandle arg1 = npi_dm_create_argument_instance( NULL, c1 );
  npiDmHandle pi = npi_dm_handle_by_name( "pi", top );
  npiDmHandle arg2 = npi_dm_create_argument_instance( NULL, pi );
  npiDmHandleArray arg_array;
  arg_array.size = 2;
  arg_array.array[0] = arg1;
  arg_array.array[1] = arg2;
  npiDmHandle sys_taskcall = npi_dm_create_system_task_call( top, "$display", arg_array );

  dump_task_call( sys_taskcall );
  //------------------------------------------------------------------------------

  npi_end();
  return 0;
}

