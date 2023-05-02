#include <stdio.h>
#include <stdlib.h>
#include "npi.h"
#include "npi_dm.h"

int main (int argc, char **argv)
{
  npi_init( argc, argv );
  npi_load_design( argc, argv );

  //-- DM operation --------------------------------------------------------------
  npiDmHandle top = npi_dm_module_by_name( "top" );
  npiDmHandle a = npi_dm_handle_by_name( "a", top );
  npiDmHandle c = npi_dm_handle_by_name( "c", top );

  npiDmHandle call_1_arg_1 = npi_dm_create_argument_instance( NULL, a );
  npiDmHandleArray call_1_arg_array;
  call_1_arg_array.size = 1;
  call_1_arg_array.array[0] = call_1_arg_1;
  npiDmHandle sys_funccall_1 = npi_dm_create_system_function_call( top, "$bits", call_1_arg_array );

  npiDmHandleArray empty_array;
  empty_array.size = 0;
  npiDmHandle null_op = npi_dm_create_operation( npiDmOpNull, empty_array );
  npiDmHandle call_2_arg_1 = npi_dm_create_argument_instance( NULL, null_op );
  npiDmHandleArray call_2_arg_array;
  call_2_arg_array.size = 1;
  call_2_arg_array.array[0] = call_2_arg_1;
  npiDmHandle sys_funccall_2 = npi_dm_create_system_function_call( top, "$bits", call_2_arg_array );

  npi_dm_make_assign_connection( top, c, sys_funccall_1 );
  npi_dm_make_assign_connection( top, c, sys_funccall_2 );

  // Write to directory "DM_LIB"
  npi_dm_write_text_mode( "DM_LIB" );
  //------------------------------------------------------------------------------

  npi_end();
  return 0;
}

