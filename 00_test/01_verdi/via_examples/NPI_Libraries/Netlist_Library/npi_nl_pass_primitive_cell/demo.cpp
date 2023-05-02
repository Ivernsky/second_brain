/* ==========================================================================
 *       Filename:  demo.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  05/22/13 15:47:28 CST
 *       Revision:  none
 *        Company:  Synopsys, Inc.
 * ========================================================================== */

#ifndef  DEMO_CPP
#define  DEMO_CPP

#include "npi.h"     // header file for NPI L0
#include "npi_L1.h"  // header file for NPI L1

void test_npi_nl_pass_primitive_cell (char* sigName)
{
  nlHdlVec_t hdlVec;
  npiNlHandle sigHdl = npi_nl_sig_handle_by_name(sigName);
  npiNlHandle itr = npi_nl_iterate(npiNlConnectivity, sigHdl);
  npiNlHandle pinHdl = NULL;
  
  while ((pinHdl = npi_nl_scan(itr)) != NULL)
  {
    if (npi_nl_pass_primitive_cell(pinHdl, hdlVec/*O*/) != 0)
    { 
      printf("From\n");
      npi_nl_ut_dump_hdl_info(pinHdl, stdout);
      printf("To\n");
      npi_nl_ut_dump_hdl_vec_info(hdlVec, stdout, 1);
    }
    npi_nl_release_handle(pinHdl);
  }
  npi_nl_release_handle(sigHdl);
  printf("\n");
}


int main (int argc, char** argv)
{
  npi_init(argc, argv);
  npi_load_design(argc, argv);

  // '|' does support bit-level tracing
  test_npi_nl_pass_primitive_cell("top.a[2:1]");
  // '+' doesn't support bit-level tracing 
  test_npi_nl_pass_primitive_cell("top.d[2:1]");

  npi_end();
  return 0;
}

#endif   /* ----- #ifndef DEMO_CPP  ----- */

