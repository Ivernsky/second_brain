/* ==========================================================================
 *       Filename:  demo.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  04/10/13 11:54:32 CST
 *       Revision:  none
 *        Company:  Synopsys, Inc.
 * ========================================================================== */

#ifndef  DEMO_CPP
#define  DEMO_CPP

#include "npi.h"
#include "npi_L1.h"

int expr_cb (npiHandle hdl, void* cbData)
{
  int* cnt = (int*) cbData;
  if (npi_get(npiType, hdl) != npiOperation)
    return 0;
  if (npi_get(npiOpType, hdl) == npiAddOp)
    (*cnt)++;
  return 1;
}

int main(int argc, char** argv)
{
  npi_init(argc, argv);
  npi_load_design(argc, argv);

  npiHandle varHdl = npi_handle_by_name("top.a", NULL);
  npiHandle exprHdl = npi_handle(npiExpr, varHdl);
 
  int addOpCnt = 0;
  npi_expr_trv_register_cb(expr_cb, &addOpCnt);
  npi_expr_trv(exprHdl);
  printf("Add op cnt = %d\n", addOpCnt);
  
  // reset
  addOpCnt = 0;
  npi_expr_trv_reset_cb();
  npi_expr_trv(exprHdl);
  printf("Add op cnt = %d\n", addOpCnt);

  npi_end();
  return 0;
}

#endif   /* ----- #ifndef DEMO_CPP  ----- */

