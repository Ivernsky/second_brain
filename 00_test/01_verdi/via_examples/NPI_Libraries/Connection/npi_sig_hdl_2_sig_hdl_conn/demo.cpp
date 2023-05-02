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

  npiNlHandle hdl1 = npi_nl_sig_handle_by_name("TOP.w4");
  npiNlHandle hdl2 = npi_nl_sig_handle_by_name("TOP.w5");
  nlHdlVec_t hdlVec;
  printf("Pass through assign\n");
  if (npi_sig_hdl_2_sig_hdl_conn(hdl1, hdl2, hdlVec))
    npi_nl_ut_dump_hdl_vec_info(hdlVec, stdout);
  else
    printf("Not connected\n");

  printf("Do not pass through assign\n");
  if (npi_sig_hdl_2_sig_hdl_conn(hdl1, hdl2, hdlVec, 1))
    npi_nl_ut_dump_hdl_vec_info(hdlVec, stdout);
  else
    printf("Not connected\n");
  
  npi_end();
  return 0;
}

#endif   /* ----- #ifndef DEMO_CPP  ----- */

