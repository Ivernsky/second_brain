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

  npiNlHandle hdl = npi_nl_sig_handle_by_name("TOP.w1");
  nlHdlVec_t hdlVec;
  printf("Pass through assign\n");
  npi_sig_hdl_2_mod_inst_conn(hdl, hdlVec);
  npi_nl_ut_dump_hdl_vec_info(hdlVec, stdout);
  printf("Do not pass through assign\n");
  npi_sig_hdl_2_mod_inst_conn(hdl, hdlVec, 1);
  npi_nl_ut_dump_hdl_vec_info(hdlVec, stdout);

  printf("\n");

  printf("Pass through assign, stop at port/instport\n");
  npi_sig_hdl_2_mod_inst_conn(hdl, hdlVec, 0, true);
  npi_nl_ut_dump_hdl_vec_info(hdlVec, stdout);
  printf("Do not pass through assign, stop at port/instport\n");
  npi_sig_hdl_2_mod_inst_conn(hdl, hdlVec, 1, true);
  npi_nl_ut_dump_hdl_vec_info(hdlVec, stdout);

  npi_end();
  return 0;
}

#endif   /* ----- #ifndef DEMO_CPP  ----- */

