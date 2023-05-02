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

void dump_hdl (npiNlHandle hdl, bool isFull)
{
  NPI_INT32 prop = (isFull) ? npiNlFullName : npiNlName;
  printf("Name: %s\n", npi_nl_get_str(prop, hdl));
  printf("First actual name: %s\n", npi_nl_ut_get_actual_name(hdl, isFull));
  printf("\n");
}

int main (int argc, char** argv)
{
  npi_init(argc, argv);
  npi_load_design(argc, argv);

  npiNlHandle netHdl = npi_nl_L1_handle_by_name("top.w[2:1]");
  dump_hdl(netHdl, false);
  
  nlHdlVec_t hdlVec;
  int i, size = npi_get_equivalent_signal_by_hdl(netHdl, hdlVec);
  for (i = 0; i < size; i++)
    dump_hdl(hdlVec[i], true);
  
  npi_end();

  return 0;
}

#endif   /* ----- #ifndef DEMO_CPP  ----- */

