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

void act_inst (npiNlHandle hdl, void *cb)
{
  if (npi_nl_get(npiNlCellType, hdl) != npiNlAssignCell)
    return;
  printf("Found npiNlAssignCell:\n  ");
  npi_nl_ut_dump_hdl_info(hdl, stdout);
  
  npiNlHandle itr = NULL, subHdl1 = NULL, subHdl2 = NULL;
  itr = npi_nl_iterate(npiNlInstPort, hdl);
  while (subHdl1 = npi_nl_scan(itr))
  {
    subHdl2 = npi_nl_pass_assign_cell(subHdl1);
    printf("From instport:\n  ");
    npi_nl_ut_dump_hdl_info(subHdl1, stdout);
    printf("To instport:\n  ");
    npi_nl_ut_dump_hdl_info(subHdl2, stdout);
  }
}

int main(int argc, char** argv)
{
  npi_init(argc, argv);
  npi_load_design(argc, argv);

  // register callback funcation and data
  npi_nl_hier_tree_trv_register_cb(npiNlInst, act_inst, NULL);
  // traverse the design from $root
  npi_nl_hier_tree_trv();

  npi_end();
  return 0;
}

#endif   /* ----- #ifndef DEMO_CPP  ----- */

