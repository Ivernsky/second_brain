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

void driver_load_demo (npiNlHandle hdl, void *cb)
{
  nlHdlVec_t hdlVec;
  
  printf("== %s ==\n",  npi_nl_ut_get_hdl_info(hdl));
  printf("Drivers:\n");
  npi_nl_trace_driver_by_hdl2(hdl, hdlVec/*O*/);
  npi_nl_ut_dump_hdl_vec_info(hdlVec/*IO*/, stdout, true/*isRelease*/);
  printf("Loads:\n");
  npi_nl_trace_load_by_hdl2(hdl, hdlVec/*O*/);
  npi_nl_ut_dump_hdl_vec_info(hdlVec/*IO*/, stdout, true/*isRelease*/);
}

int main (int argc, char** argv)
{
  npi_init(argc, argv);
  npi_load_design(argc, argv);

  npi_nl_hier_tree_trv_register_cb(npiNlDeclNet,  driver_load_demo, NULL);
  npi_nl_hier_tree_trv_register_cb(npiNlPort,     driver_load_demo, NULL);
  npi_nl_hier_tree_trv_register_cb(npiNlInstPort, driver_load_demo, NULL);
  npi_nl_hier_tree_trv();

  npi_end();
  return 0;
}

#endif   /* ----- #ifndef DEMO_CPP  ----- */

