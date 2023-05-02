/* ==========================================================================
 *       Filename:  demo.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  02/21/12 15:10:46 CST
 *       Revision:  none
 *        Company:  Springsoft
 * ========================================================================== */

#ifndef  DEMO_CPP
#define  DEMO_CPP

#include "npi.h"
#include "npi_L1.h"

void cb_func_obj_count (npiNlHandle hdl, void *cb)
{
  int* pCnt = (int*)cb;
  (*pCnt)++;
  npi_nl_ut_dump_hdl_info(hdl, stdout);
}

void cb_find_reg (npiNlHandle hdl, void *cb)
{
  if (npi_nl_get(npiNlCellType, hdl) == npiNlFlipFlopCell)
    npi_nl_ut_dump_hdl_info(hdl, stdout);
}

int main(int argc, char** argv)
{
  npi_init(argc, argv);
  npi_load_design(argc, argv);

  int instCnt = 0, portCnt = 0;
  // register callback funcation and data
  npi_nl_hier_tree_trv_register_cb(npiNlInst, cb_func_obj_count, &instCnt);
  npi_nl_hier_tree_trv_register_cb(npiNlPort, cb_func_obj_count, &portCnt);
  // traverse the design from scope "top"
  npi_nl_hier_tree_trv("top");
  // dump the result
  printf("Found %d instances and %d ports\n", instCnt, portCnt);
  
  // reset the callback function and traverse again
  instCnt = 0;
  portCnt = 0;
  npi_nl_hier_tree_trv_reset_cb();
  npi_nl_hier_tree_trv("top");
  // callback data is unchanged
  printf("Found %d instances and %d ports\n", instCnt, portCnt);

  npi_end();
  return 0;
}

#endif   /* ----- #ifndef DEMO_CPP  ----- */

