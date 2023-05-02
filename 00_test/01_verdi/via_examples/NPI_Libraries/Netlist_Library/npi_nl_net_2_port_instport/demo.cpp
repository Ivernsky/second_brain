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

void act_net (npiNlHandle hdl, void *cb)
{
  hdlVec_t hdlVec;
  if (npi_nl_net_2_port_instport(hdl, hdlVec) != 0)
  {
    printf("npi_nl_net_2_port_instport:\n");
    npi_nl_ut_dump_hdl_info(hdl, stdout);
    npi_nl_ut_dump_hdl_vec_info(hdlVec, stdout);
    printf("\n");
  }
}

int main(int argc, char** argv)
{
  npi_init(argc, argv);
  npi_load_design(argc, argv);

  // register callback funcation and data
  npi_nl_hier_tree_trv_register_cb(npiNlDeclNet, act_net, NULL);
  npi_nl_hier_tree_trv_register_cb(npiNlConcatNet, act_net, NULL);
  npi_nl_hier_tree_trv_register_cb(npiNlSliceNet, act_net, NULL);
  // traverse the design from $root
  npi_nl_hier_tree_trv();

  npi_end();
  return 0;
}

#endif   /* ----- #ifndef DEMO_CPP  ----- */

