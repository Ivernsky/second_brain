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

void dump_dl_res_vec_info (const nlDLResVec_t& resVec)
{
  nlDLResVec_t::const_iterator it;
  nlHdlVec_t::const_iterator hit;

  for (it = resVec.begin(); it != resVec.end(); it++)
  {
    const nlDLRes_t& res = (*it);
    printf("%s\n", npi_nl_ut_get_hdl_info(res.src));

    for (hit = res.dlVec.begin(); hit != res.dlVec.end(); hit++)
      printf("    %s\n", npi_nl_ut_get_hdl_info((*hit)));
    printf("\n");
  }
}

void driver_demo (npiNlHandle hdl, void *cb)
{
  printf("== %s ==\n\n",  npi_nl_ut_get_hdl_info(hdl));
  nlDLResVec_t resVec;
  unsigned int size = npi_nl_bit_trace_driver_by_hdl(hdl, resVec/*O*/);
  dump_dl_res_vec_info(resVec);
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

