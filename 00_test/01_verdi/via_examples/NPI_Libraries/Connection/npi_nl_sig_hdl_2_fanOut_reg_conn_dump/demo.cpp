/* ==========================================================================
 *       Filename:  demo.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  02/21/12 15:10:46 CST
 *       Revision:  none
 *        Company:  Synopsys, Inc.
 * ========================================================================== */

#ifndef  DEMO_CPP
#define  DEMO_CPP

#include "npi.h"
#include "npi_L1.h"

int main(int argc, char** argv)
{
  npi_init(argc, argv);
  npi_load_design(argc, argv);

  npiNlHandle hdl = npi_nl_sig_handle_by_name("TOP.wtmp");
  npi_nl_sig_hdl_2_fanOut_reg_conn_dump(hdl, stdout);
  npi_nl_sig_hdl_2_fanOut_reg_conn_dump(hdl, stdout, true);

  npi_end();
  return 0;
}

#endif   /* ----- #ifndef DEMO_CPP  ----- */

