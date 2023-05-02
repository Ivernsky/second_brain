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

void act_instport (npiNlHandle hdl, void *cb)
{
  npiNlHandle portHdl = NULL;
  if ((portHdl = npi_nl_instport_2_port(hdl)) != NULL)
  {
    printf("npi_nl_instport_2_port:\n");
    npi_nl_ut_dump_hdl_info(hdl, stdout);
    npi_nl_ut_dump_hdl_info(portHdl, stdout);
    printf("\n");
  }
}

int main(int argc, char** argv)
{
  npi_init(argc, argv);
  npi_load_design(argc, argv);

  // register callback funcation and data
  npi_nl_hier_tree_trv_register_cb(npiNlInstPort, act_instport, NULL);
  // traverse the design from $root
  npi_nl_hier_tree_trv();

  npi_end();
  return 0;
}

#endif   /* ----- #ifndef DEMO_CPP  ----- */

