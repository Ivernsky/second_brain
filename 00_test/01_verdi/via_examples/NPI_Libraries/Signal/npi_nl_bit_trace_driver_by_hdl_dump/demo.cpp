/* ==========================================================================
 *       Filename:  demo.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  04/30/13 11:51:08 CST
 *       Revision:  none
 *        Company:  Synopsys, Inc.
 * ========================================================================== */

#ifndef  DEMO_CPP
#define  DEMO_CPP

#include "npi.h"     // header file for NPI L0
#include "npi_L1.h"  // header file for NPI L1

void driver_demo (npiNlHandle hdl, void *cb)
{
  printf("== %s ==\n\n",  npi_nl_ut_get_hdl_info(hdl));
  unsigned int size = npi_nl_bit_trace_driver_by_hdl_dump(hdl, stdout);
  printf("== Total %u drivers ==\n\n", size);
}

int main (int argc, char** argv)
{
  npi_init(argc, argv);
  npi_load_design(argc, argv);

  npi_nl_hier_tree_trv_register_cb(npiNlDeclNet,  driver_demo, NULL);
  npi_nl_hier_tree_trv_register_cb(npiNlPort,     driver_demo, NULL);
  npi_nl_hier_tree_trv_register_cb(npiNlInstPort, driver_demo, NULL);
  npi_nl_hier_tree_trv();

  npi_end();
  return 0;
}

#endif   /* ----- #ifndef DEMO_CPP  ----- */

