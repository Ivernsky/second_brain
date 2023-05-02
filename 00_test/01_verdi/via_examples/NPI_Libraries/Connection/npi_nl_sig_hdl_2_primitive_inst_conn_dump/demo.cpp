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

  npiNlHandle hdl = npi_nl_sig_handle_by_name("TOP.w5");
  printf("Pass through assign\n");
  npi_nl_sig_hdl_2_primitive_inst_conn_dump(hdl, stdout);
  printf("Do not pass through assign\n");
  npi_nl_sig_hdl_2_primitive_inst_conn_dump(hdl, stdout, 1);

  printf("\n");

  printf("Pass through assign, stop at instport\n");
  npi_nl_sig_hdl_2_primitive_inst_conn_dump(hdl, stdout, 0, true);
  printf("Do not pass through assign, stop at instport\n");
  npi_nl_sig_hdl_2_primitive_inst_conn_dump(hdl, stdout, 1, true);

  npi_end();
  return 0;
}

#endif   /* ----- #ifndef DEMO_CPP  ----- */

