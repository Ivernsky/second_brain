/* ==========================================================================
 *       Filename:  demo.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  04/17/15 15:47:28 CST
 *       Revision:  none
 *        Company:  Synopsys, Inc.
 * ========================================================================== */
#ifndef  DEMO_CPP
#define  DEMO_CPP

#include "npi.h"     // header file for NPI L0
#include "npi_L1.h"  // header file for NPI L1

void dump_value (npiNlHandle hdl, bool isAll = false)
{
  string sigFullName = npi_nl_get_str(npiNlFullName, hdl);
  printf("Name: %s\n", sigFullName.c_str());
  printf("Actual isLiteral: %d\n", npi_nl_ut_get_actual_is_literal(hdl));
  printf("Actual value: %s\n", npi_nl_ut_get_actual_value(hdl));
  if (isAll)
  {
    printf("Actual value(Hex): %s\n", npi_nl_ut_get_actual_value(hdl, npiNlHexFormat));
    printf("Actual value(Oct): %s\n", npi_nl_ut_get_actual_value(hdl, npiNlOctFormat));
    printf("Actual value(Dec): %s\n", npi_nl_ut_get_actual_value(hdl, npiNlDecFormat));
  }
  printf("\n");
}

int main (int argc, char** argv)
{
  // initialize NPI process
  npi_init(argc, argv);
  // load design
  npi_load_design(argc, argv);
  
  npiNlHandle sigHdl = NULL;
  nlHdlVec_t hdlVec;

  sigHdl = npi_nl_L1_handle_by_name((char*)"top.3'bx01");
  dump_value(sigHdl);

  sigHdl = npi_nl_handle_by_range(sigHdl, 0, 0);
  dump_value(sigHdl);

  npi_nl_get_equivalent_signal((char*)"top.b", hdlVec);
  sigHdl = hdlVec[0];
  dump_value(sigHdl);
  
  npi_nl_get_equivalent_signal((char*)"top.b[6:3]", hdlVec);
  sigHdl = hdlVec[0];
  dump_value(sigHdl, true);

  npi_nl_get_equivalent_signal((char*)"top.b[3:1]", hdlVec);
  sigHdl = hdlVec[0];
  dump_value(sigHdl);
  
  // end NPI process
  npi_end();
  return 0;
}
#endif
