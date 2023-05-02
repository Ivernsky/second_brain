#include <stdio.h>
#include <stdlib.h>
#include "npi.h"
#include "npi_dm.h"
#include <string.h>

int main (int argc, char **argv)
{
  npi_init( argc, argv );
  npi_load_design( argc, argv );

  //-- DM operation --------------------------------------------------------------
  npiDmHandle top = npi_dm_module_by_name( "top" );
  npiDmHandle m = npi_dm_module_by_name( "m" );

  npiDmIter tf_iter = npi_dm_iter_start( npiDmTaskFunc, top );
  npiDmHandle tf_hdl = NULL;
  npiDmHandle func1_hdl = NULL;
  npiDmHandle func2_hdl = NULL;
  npiDmHandle func3_hdl = NULL;
  while ( NULL != (tf_hdl = npi_dm_iter_next( tf_iter ) ) )
  {
    if ( npiDmFunction == npi_dm_property( npiDmType, tf_hdl ) )
    {
      if ( strcmp( "func1", npi_dm_property_str( npiDmName, tf_hdl ) ) == 0 )
        func1_hdl = tf_hdl;
      if ( strcmp( "func2", npi_dm_property_str( npiDmName, tf_hdl ) ) == 0 )
        func2_hdl = tf_hdl;
      if ( strcmp( "func3", npi_dm_property_str( npiDmName, tf_hdl ) ) == 0 )
        func3_hdl = tf_hdl;
    }
  }

  npiDmHandle m_func1_hdl = NULL;
  tf_iter = npi_dm_iter_start( npiDmTaskFunc, m );
  while ( NULL != (tf_hdl = npi_dm_iter_next( tf_iter ) ) )
  {
    if ( npiDmFunction == npi_dm_property( npiDmType, tf_hdl ) )
    {
      if ( strcmp( "func1", npi_dm_property_str( npiDmName, tf_hdl ) ) == 0 )
        m_func1_hdl = tf_hdl;
    }
  }
  npi_dm_iter_stop( tf_iter );

  npiDmHandle func1_arg1 = npi_dm_handle_by_name( "f_a", func1_hdl );
  npiDmHandle func1_arg2 = npi_dm_handle_by_name( "f_b", func1_hdl );

  npiDmHandle func2_arg1 = npi_dm_handle_by_name( "x", func2_hdl );
  npiDmHandle func2_arg2 = npi_dm_handle_by_name( "y", func2_hdl );
  npiDmHandle func2_arg3 = npi_dm_handle_by_name( "z", func2_hdl );

  npiDmHandle a = npi_dm_handle_by_name( "a", top );
  npiDmHandle b = npi_dm_handle_by_name( "b", top );
  npiDmHandle c = npi_dm_handle_by_name( "c", top );
  npiDmHandle d = npi_dm_handle_by_name( "d", top );

//////////// prepare function_call_1 argument instance /////////////
  npiDmHandle func1_call_1_arg1 = npi_dm_create_argument_instance ( func1_arg1, a );
  npiDmHandle func1_call_1_arg2 = npi_dm_create_argument_instance ( func1_arg2, b );
  npiDmHandleArray arg_array_func1_call_1;
  arg_array_func1_call_1.size = 2;
  arg_array_func1_call_1.array[0] = func1_call_1_arg1;
  arg_array_func1_call_1.array[1] = func1_call_1_arg2;
//////////////////////////////////////////////////////////

  npiDmHandle function_call_1 = npi_dm_create_function_call( top, func1_hdl, arg_array_func1_call_1 );

//////////// prepare function_call_2 argument instance /////////////
  npiDmHandleArray empty_array;
  empty_array.size = 0;
  npiDmHandle null_op = npi_dm_create_operation( npiDmOpNull, empty_array );
  npiDmHandle func1_call_2_arg1 = npi_dm_create_argument_instance ( func1_arg1, null_op );
  npiDmHandle func1_call_2_arg2 = npi_dm_create_argument_instance ( func1_arg2, b );
  npiDmHandleArray arg_array_func1_call_2;
  arg_array_func1_call_2.size = 2;
  arg_array_func1_call_2.array[0] = func1_call_2_arg1;
  arg_array_func1_call_2.array[1] = func1_call_2_arg2;
//////////////////////////////////////////////////////////

  npiDmHandle function_call_2 = npi_dm_create_function_call( top, func1_hdl, arg_array_func1_call_2 );

//////////// prepare function_call_3 argument instance /////////////
  npiDmHandle const_12 = npi_dm_create_constant( 12 );
  npiDmHandle const_null = npi_dm_create_constant( "null" );
  npiDmHandle func2_call_1_arg1 = npi_dm_create_argument_instance ( func2_arg1, null_op );
  npiDmHandle func2_call_1_arg2 = npi_dm_create_argument_instance ( func2_arg2, const_12 );
  npiDmHandle func2_call_1_arg3 = npi_dm_create_argument_instance ( func2_arg3, const_null );
  npiDmHandleArray arg_array_func2_call_1;
  arg_array_func2_call_1.size = 3;
  arg_array_func2_call_1.array[0] = func2_call_1_arg1;
  arg_array_func2_call_1.array[1] = func2_call_1_arg2;
  arg_array_func2_call_1.array[2] = func2_call_1_arg3;
//////////////////////////////////////////////////////////

  npiDmHandle function_call_3 = npi_dm_create_function_call( top, func2_hdl, arg_array_func2_call_1 );

//////////// prepare function_call_4 argument instance /////////////
  npiDmHandle func3_call_1_arg1 = npi_dm_create_argument_instance ( NULL, null_op );
  npiDmHandleArray empty_arg_array;
  empty_arg_array.size = 1;
  empty_arg_array.array[0] = func3_call_1_arg1;
//////////////////////////////////////////////////////////

  npiDmHandle function_call_4 = npi_dm_create_function_call( top, func3_hdl, empty_arg_array );

//////////// prepare function_call_5 argument instance /////////////
  npiDmHandle m_func1_ref_m = npi_dm_create_ref( m, empty_array );
  npiDmHandle m_func1_ref_func1 = npi_dm_create_ref( m_func1_hdl, empty_array );
  npiDmHandleArray m_func1_hier_array;
  m_func1_hier_array.size = 2;
  m_func1_hier_array.array[0] = m_func1_ref_m;
  m_func1_hier_array.array[1] = m_func1_ref_func1;
  npiDmHandle m_func1_hier_1 = npi_dm_create_hier_ref( m_func1_hier_array );

  npiDmHandle m_func1_call_1_arg1 = npi_dm_create_argument_instance ( NULL, null_op );
  npiDmHandleArray empty_arg_array_2;
  empty_arg_array_2.size = 1;
  empty_arg_array_2.array[0] = m_func1_call_1_arg1;
//////////////////////////////////////////////////////////

  npiDmHandle function_call_5 = npi_dm_create_function_call( top, m_func1_hier_1, empty_arg_array_2 );

  npi_dm_make_assign_connection( top, c, function_call_1 );
  npi_dm_make_assign_connection( top, c, function_call_2 );
  npi_dm_make_assign_connection( top, d, function_call_3 );
  npi_dm_make_assign_connection( top, c, function_call_4 );
  npi_dm_make_assign_connection( top, c, function_call_5 );

  // Write to directory "DM_LIB"
  npi_dm_write_text_mode( "DM_LIB" );
  //------------------------------------------------------------------------------

  npi_end();
  return 0;
}

