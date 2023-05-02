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

  nlHdlVec_t hdlVec;
  npi_sig_2_fanOut_reg_conn("TOP.wtmp", hdlVec);
  npi_nl_ut_dump_hdl_vec_info(hdlVec, stdout);
  npi_sig_2_fanOut_reg_conn("TOP.wtmp", hdlVec, true);
  npi_nl_ut_dump_hdl_vec_info(hdlVec, stdout);

  npi_end();
  return 0;
}

#endif   /* ----- #ifndef DEMO_CPP  ----- */

