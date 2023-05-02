#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
#include "npi.h"
#include "npi_hdl.h"
 
//------------------------------------------------------------------------------
void check_stmt(npiHandle hdl)
{
  if (!hdl || npi_get(npiType, hdl) != npiAssignment)
    return;
 
  npiHandle lhs = npi_handle(npiLhs, hdl);
  npiHandle rhs = npi_handle(npiRhs, hdl);
 
  printf("Lhs and rhs for line %d ", npi_get(npiLineNo, hdl));
  if (npi_objects_overlap(lhs, rhs) == 1)
    printf("overlap\n");
  else
    printf("do not overlap\n");
  npi_release_handle(lhs);
  npi_release_handle(rhs);
}
//------------------------------------------------------------------------------
void trv_scope(npiHandle hdl)
{
  if (!hdl)
    return;
 
  npiHandle itr;
  npiHandle stmt;
  switch (npi_get(npiType, hdl)) {
    case npiTask:
    case npiFunction:
    case npiNamedBegin:
    case npiBegin:
    case npiNamedFork:
    case npiFork:
      itr = npi_iterate(npiStmt, hdl);
      while (stmt = npi_scan(itr)) {
        check_stmt(stmt);
        npi_release_handle(stmt);
      }
      break;
    default:
      break;
  }
 
  itr = npi_iterate(npiInternalScope, hdl);
  npiHandle sub_scp;
  while (sub_scp = npi_scan(itr)) {
    trv_scope(sub_scp);
    npi_release_handle(sub_scp);
  }
}
//------------------------------------------------------------------------------
void compare_both_side_for_assignment()
{
  npiHandle top_itr = npi_iterate(npiInstance, NULL);
  npiHandle top_inst;
  while (top_inst = npi_scan(top_itr)) {
    trv_scope(top_inst);
    npi_release_handle(top_inst);
  }
}
//------------------------------------------------------------------------------
int main (int argc, char **argv)
{
  // -- initialization -------------------------------------------------------
  npi_init( argc, argv );
  npi_load_design( argc, argv );
 
  compare_both_side_for_assignment();
 
  // -- end --------------------------------------------------------------------
  npi_end();
 
  return 0;
}
