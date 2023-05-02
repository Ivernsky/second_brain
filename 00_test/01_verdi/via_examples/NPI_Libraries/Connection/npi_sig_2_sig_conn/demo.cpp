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

  nlHdlVec_t hdlVec;
  
  printf("Pass through assign\n");
  if (npi_sig_2_sig_conn("TOP.w4", "TOP.w5", hdlVec))
    npi_nl_ut_dump_hdl_vec_info(hdlVec, stdout);
  else 
    printf("Not connected\n");
  
  printf("Do not pass through assign\n");
  if (npi_sig_2_sig_conn("TOP.w4", "TOP.w5", hdlVec, 1))
    npi_nl_ut_dump_hdl_vec_info(hdlVec, stdout);
  else 
    printf("Not connected\n");
  
  npi_end();
  return 0;
}

#endif   /* ----- #ifndef DEMO_CPP  ----- */

