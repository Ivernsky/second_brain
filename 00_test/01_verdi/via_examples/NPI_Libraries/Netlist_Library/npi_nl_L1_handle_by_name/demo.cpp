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

int main (int argc, char** argv)
{
  npi_init(argc, argv);
  npi_load_design(argc, argv);

  npiNlHandle hdl = NULL;
  const char* fullHierName = "top.m1.dout[3:0]";
    
  hdl = npi_nl_L1_handle_by_name(fullHierName);
  npi_nl_ut_dump_hdl_info(hdl, stdout);
  hdl = npi_nl_L1_handle_by_name(fullHierName, npiNlNet);
  npi_nl_ut_dump_hdl_info(hdl, stdout);
  hdl = npi_nl_L1_handle_by_name(fullHierName, npiNlPort);
  npi_nl_ut_dump_hdl_info(hdl, stdout);
  hdl = npi_nl_L1_handle_by_name(fullHierName, npiNlInstPort);
  npi_nl_ut_dump_hdl_info(hdl, stdout);

  npi_end();

  return 0;
}

#endif   /* ----- #ifndef DEMO_CPP  ----- */

