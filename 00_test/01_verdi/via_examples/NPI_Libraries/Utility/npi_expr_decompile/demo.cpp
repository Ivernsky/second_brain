/* ==========================================================================
 *       Filename:  demo.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  04/10/13 11:53:40 CST
 *       Revision:  none
 *        Company:  Synopsys, Inc.
 * ========================================================================== */

#ifndef  DEMO_CPP
#define  DEMO_CPP

#include "npi.h"
#include "npi_L1.h"

int main(int argc, char** argv)
{
  npi_init(argc, argv);
  npi_load_design(argc, argv);

  npiHandle varHdl = npi_handle_by_name("top.a", NULL);
  npiHandle exprHdl = npi_handle(npiExpr, varHdl);
 
  printf("%s\n", npi_expr_decompile(exprHdl));

  npi_end();
  return 0;
}

#endif   /* ----- #ifndef DEMO_CPP  ----- */

