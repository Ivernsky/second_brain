#include <stdio.h>
#include <stdlib.h>
#include "npi.h"
#include "npi_dm.h"
 
int main (int argc, char **argv)
{
  npi_init( argc, argv );
  npi_load_design( argc, argv );
 
  //-- DM operation --------------------------------------------------------------
  npiDmHandle TOP = npi_dm_module_by_name( "TOP" );
  npiDmHandle w1 = npi_dm_handle_by_name( "w1", TOP );
  npiDmHandle w2 = npi_dm_handle_by_name( "w2", TOP );
  npiDmHandle w3 = npi_dm_handle_by_name( "w3", TOP );
 
  npiDmHandleArray expr_ary;
  expr_ary.size = 2;
  expr_ary.array[0] = w2;
  expr_ary.array[1] = w3;
 
  npiDmHandle opr = npi_dm_create_operation( npiDmOpConcat, expr_ary );
  npi_dm_make_assign_connection( TOP, w1, opr );
 
  npiDmHandle w4 = npi_dm_handle_by_name( "w4", TOP );
  npiDmHandle c0 = npi_dm_create_constant( "3" );
  npiDmHandleArray index_expr_ary;
  index_expr_ary.size = 1;
  index_expr_ary.array[0] = c0;
  npiDmHandle index_opr = npi_dm_create_operation( npiDmOpIndex, index_expr_ary );
 
  npiDmHandle c1_0 = npi_dm_create_constant( "5" );
  npiDmHandle c1_1 = npi_dm_create_constant( "2" );
  npiDmHandleArray slice_expr_ary;
  slice_expr_ary.size = 2;
  slice_expr_ary.array[0] = c1_0;
  slice_expr_ary.array[1] = c1_1;
  npiDmHandle slice_opr = npi_dm_create_operation( npiDmOpSlice, slice_expr_ary );
 
  npiDmHandleArray select_expr_ary;
  select_expr_ary.size = 3;
  select_expr_ary.array[0] = w4;
  select_expr_ary.array[1] = index_opr;
  select_expr_ary.array[2] = slice_opr;
  npiDmHandle select_opr = npi_dm_create_operation( npiDmOpSelect, select_expr_ary );
 
  npiDmHandle ws = npi_dm_handle_by_name( "ws", TOP );
  npi_dm_make_assign_connection( TOP, ws, select_opr );
 
  // Write to directory "DM_LIB"
  npi_dm_write_text_mode( "DM_LIB" );
  //------------------------------------------------------------------------------
 
  npi_end();
  return 0;
}
