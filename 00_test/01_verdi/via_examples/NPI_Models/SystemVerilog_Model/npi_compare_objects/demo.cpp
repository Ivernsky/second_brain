#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
#include "npi.h"
#include "npi_hdl.h"
 
//------------------------------------------------------------------------------
int check_bit_sel_idx(npiHandle lhs, npiHandle rhs)
{
  if (!lhs || !rhs)
    return 0;
 
  if (npi_get(npiType, lhs) != npiBitSelect || npi_get(npiType, rhs) != npiBitSelect)
    return 0;
 
  npiHandle idxL, idxR;
  npiHandle itrL = npi_iterate(npiIndex, lhs);
  npiHandle itrR = npi_iterate(npiIndex, rhs);
  while ((idxL = npi_scan(itrL)) && (idxR = npi_scan(itrR))) {
    int ret = npi_compare_objects(idxL, idxR);
    npi_release_handle(idxL);
    npi_release_handle(idxR);
    return ret;
  }
  return 0;
}
//------------------------------------------------------------------------------
void check_stmt(npiHandle hdl)
{
  if (!hdl || npi_get(npiType, hdl) != npiAssignment)
    return;
 
  npiHandle lhs = npi_handle(npiLhs, hdl);
  npiHandle rhs = npi_handle(npiRhs, hdl);
 
  if (check_bit_sel_idx(lhs, rhs) > 0) {
    printf("Lhs-index and rhs-index for line %d are the same\n", npi_get(npiLineNo, hdl));
    return;
  }
 
  printf("Lhs and rhs for line %d are ", npi_get(npiLineNo, hdl));
  if (npi_get(npiType, lhs) == npiBitSelect && npi_get(npiType, rhs) == npiBitSelect) {
    npiHandle idxL = npi_handle(npiIndex, lhs);
    npiHandle idxR = npi_handle(npiIndex, rhs);
    if (npi_compare_objects(idxL, idxR) == 1)
      printf("the same\n");
    else
      printf("different\n");
    npi_release_handle(idxL);
    npi_release_handle(idxR);
    npi_release_handle(lhs);
    npi_release_handle(rhs);
    return;
  }
  if (npi_compare_objects(lhs, rhs) == 1)
    printf("the same\n");
  else
    printf("different\n");
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
