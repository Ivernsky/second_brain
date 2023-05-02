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

void cb_func_obj_count (npiHandle hdl, void *cb)
{
  int* pCnt = (int*)cb;
  (*pCnt)++;
  npi_sv_ut_dump_hdl_info(hdl, stdout);
}

int main(int argc, char** argv)
{
  npi_init(argc, argv);
  npi_load_design(argc, argv);

  int modCnt = 0, portCnt = 0;
  // register callback funcation and data
  npi_hier_tree_trv_register_cb(npiModule, cb_func_obj_count, &modCnt);
  npi_hier_tree_trv_register_cb(npiPort, cb_func_obj_count, &portCnt);
  // traverse the design from scope "top"
  npi_hier_tree_trv("top");
  // dump the result
  printf("Found %d modules and %d ports\n", modCnt, portCnt);
  
  // reset the callback function and traverse again
  modCnt = 0;
  portCnt = 0;
  npi_hier_tree_trv_reset_cb();
  npi_hier_tree_trv("top");
  // callback data is unchanged
  printf("Found %d modules and %d ports\n", modCnt, portCnt);

  npi_end();
  return 0;
}

#endif   /* ----- #ifndef DEMO_CPP  ----- */

