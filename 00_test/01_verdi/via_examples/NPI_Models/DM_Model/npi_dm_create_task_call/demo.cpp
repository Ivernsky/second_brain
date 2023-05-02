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

  if ( strcmp( task_call_type, "npiDmTaskCall" ) == 0 )
  {
    npiDmHandle task = npi_dm_handle( npiDmTask, task_call );
    char* task_name = (char*)npi_dm_property_str( npiDmName, task );
    printf( "full task name = %s\n", task_name );
  }

  npiDmIter arg_iter = npi_dm_iter_start( npiDmArgInst, task_call );
  int arg_counter = 1;
  npiDmHandle arg = NULL;
  while ( NULL != ( arg = npi_dm_iter_next( arg_iter ) ) )
  {
    printf( "  argument %i\n", arg_counter );
    if ( strcmp( task_call_type, "npiDmTaskCall" ) == 0 )
    {
      npiDmHandle formal = npi_dm_handle( npiDmFormal, arg );
      char* formal_name = "";
      if ( NULL != formal )
        formal_name = (char*)npi_dm_property_str( npiDmName, formal );
      printf( "    formal_arg = %s", formal_name );
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
  npiDmHandle m = npi_dm_module_by_name( "m" );

  npiDmIter tf_iter = npi_dm_iter_start( npiDmTaskFunc, top );
  npiDmHandle tf_hdl = NULL;
  npiDmHandle task1_hdl = NULL;
  npiDmHandle task2_hdl = NULL;
  npiDmHandle task3_hdl = NULL;
  while ( NULL != (tf_hdl = npi_dm_iter_next( tf_iter ) ) )
  {
    if ( npiDmTask == npi_dm_property( npiDmType, tf_hdl ) )
    {
      if ( strcmp( "task1", npi_dm_property_str( npiDmName, tf_hdl ) ) == 0 )
        task1_hdl = tf_hdl;
      if ( strcmp( "task2", npi_dm_property_str( npiDmName, tf_hdl ) ) == 0 )
        task2_hdl = tf_hdl;
      if ( strcmp( "task3", npi_dm_property_str( npiDmName, tf_hdl ) ) == 0 )
        task3_hdl = tf_hdl;
    }
  }

  npiDmHandle m_task1_hdl = NULL;
  tf_iter = npi_dm_iter_start( npiDmTaskFunc, m );
  while ( NULL != (tf_hdl = npi_dm_iter_next( tf_iter ) ) )
  {
    if ( npiDmTask == npi_dm_property( npiDmType, tf_hdl ) )
    {
      if ( strcmp( "task1", npi_dm_property_str( npiDmName, tf_hdl ) ) == 0 )
        m_task1_hdl = tf_hdl;
    }
  }
  npi_dm_iter_stop( tf_iter );

  npiDmHandle task1_arg1 = npi_dm_handle_by_name( "f_a", task1_hdl );
  npiDmHandle task1_arg2 = npi_dm_handle_by_name( "f_b", task1_hdl );

  npiDmHandle task2_arg1 = npi_dm_handle_by_name( "x", task2_hdl );
  npiDmHandle task2_arg2 = npi_dm_handle_by_name( "y", task2_hdl );
  npiDmHandle task2_arg3 = npi_dm_handle_by_name( "z", task2_hdl );

  npiDmHandle a = npi_dm_handle_by_name( "a", top );
  npiDmHandle b = npi_dm_handle_by_name( "b", top );
  npiDmHandle c = npi_dm_handle_by_name( "c", top );
  npiDmHandle d = npi_dm_handle_by_name( "d", top );

//////////// prepare task_call_1 argument instance /////////////
  npiDmHandle task1_call_1_arg1 = npi_dm_create_argument_instance ( task1_arg1, a );
  npiDmHandle task1_call_1_arg2 = npi_dm_create_argument_instance ( task1_arg2, b );
  npiDmHandleArray arg_array_task1_call_1;
  arg_array_task1_call_1.size = 2;
  arg_array_task1_call_1.array[0] = task1_call_1_arg1;
  arg_array_task1_call_1.array[1] = task1_call_1_arg2;
////////////////////////////////////////////////////////////////////

  npiDmHandle task_call_1 = npi_dm_create_task_call( top, task1_hdl, arg_array_task1_call_1 );

//////////// prepare task_call_2 argument instance /////////////

  npiDmHandleArray empty_array;
  empty_array.size = 0;
  npiDmHandle null_op = npi_dm_create_operation( npiDmOpNull, empty_array );
  npiDmHandle task1_call_2_arg1 = npi_dm_create_argument_instance ( task1_arg1, null_op );
  npiDmHandle task1_call_2_arg2 = npi_dm_create_argument_instance ( task1_arg2, b );
  npiDmHandleArray arg_array_task1_call_2;
  arg_array_task1_call_2.size = 2;
  arg_array_task1_call_2.array[0] = task1_call_2_arg1;
  arg_array_task1_call_2.array[1] = task1_call_2_arg2;
////////////////////////////////////////////////////////////////////

  npiDmHandle task_call_2 = npi_dm_create_task_call( top, task1_hdl, arg_array_task1_call_2 );

//////////// prepare task_call_3 argument instance /////////////
  npiDmHandle const_12 = npi_dm_create_constant( 12 );
  npiDmHandle const_null = npi_dm_create_constant( "null" );
  npiDmHandle task2_call_1_arg1 = npi_dm_create_argument_instance ( task2_arg1, null_op );
  npiDmHandle task2_call_1_arg2 = npi_dm_create_argument_instance ( task2_arg2, const_12 );
  npiDmHandle task2_call_1_arg3 = npi_dm_create_argument_instance ( task2_arg3, const_null );
  npiDmHandleArray arg_array_task2_call_1;
  arg_array_task2_call_1.size = 3;
  arg_array_task2_call_1.array[0] = task2_call_1_arg1;
  arg_array_task2_call_1.array[1] = task2_call_1_arg2;
  arg_array_task2_call_1.array[2] = task2_call_1_arg3;
////////////////////////////////////////////////////////////////////

  npiDmHandle task_call_3 = npi_dm_create_task_call( top, task2_hdl, arg_array_task2_call_1 );

//////////// prepare task_call_4 argument instance /////////////
  npiDmHandle task3_call_1_arg1 = npi_dm_create_argument_instance ( NULL, null_op );
  npiDmHandleArray empty_arg_array;
  empty_arg_array.size = 1;
  empty_arg_array.array[0] = task3_call_1_arg1;
////////////////////////////////////////////////////////////////////

  npiDmHandle task_call_4 = npi_dm_create_task_call( top, task3_hdl, empty_arg_array );

//////////// prepare task_call_5 argument instance /////////////
  npiDmHandle m_task1_ref_m = npi_dm_create_ref( m, empty_array );
  npiDmHandle m_task1_ref_task1 = npi_dm_create_ref( m_task1_hdl, empty_array );
  npiDmHandleArray m_task1_hier_array;
  m_task1_hier_array.size = 2;
  m_task1_hier_array.array[0] = m_task1_ref_m;
  m_task1_hier_array.array[1] = m_task1_ref_task1;
  npiDmHandle m_task1_hier_1 = npi_dm_create_hier_ref( m_task1_hier_array );

  npiDmHandle m_task1_call_1_arg1 = npi_dm_create_argument_instance ( NULL, null_op );
  npiDmHandleArray empty_arg_array_2;
  empty_arg_array_2.size = 1;
  empty_arg_array_2.array[0] = m_task1_call_1_arg1;
////////////////////////////////////////////////////////////////////

  npiDmHandle task_call_5 = npi_dm_create_task_call( top, m_task1_hier_1, empty_arg_array_2 );

  dump_task_call( task_call_1 );
  dump_task_call( task_call_2 );
  dump_task_call( task_call_3 );
  dump_task_call( task_call_4 );
  dump_task_call( task_call_5 );

  npi_end();
  return 0;
}

