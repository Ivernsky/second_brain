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

int main(int argc, char** argv)
{
  npi_init(argc, argv);
  npi_load_design(argc, argv);

  npiNlHandle hdl = npi_nl_sig_handle_by_name("TOP.w3");
  printf("Pass through assign\n");
  npi_nl_dump_equivalent_signal_by_hdl(hdl, stdout);
  printf("Do not pass through assign\n");
  npi_nl_dump_equivalent_signal_by_hdl(hdl, stdout, 1);

  npi_end();
  return 0;
}

#endif   /* ----- #ifndef DEMO_CPP  ----- */

