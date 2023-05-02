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
  printf("Pass through assign, do not pass through module\n");
  npi_nl_trace_load("TOP.w1", hdlVec, 0, 0);
  npi_nl_ut_dump_hdl_vec_info(hdlVec, stdout);
  printf("Pass through assign and module\n");
  npi_nl_trace_load("TOP.w1", hdlVec, 0, 1);
  npi_nl_ut_dump_hdl_vec_info(hdlVec, stdout);
  printf("Do not pass through assign, pass through module\n");
  npi_nl_trace_load("TOP.w1", hdlVec, 1, 1);
  npi_nl_ut_dump_hdl_vec_info(hdlVec, stdout);
  printf("Do not pass through assign and module\n");
  npi_nl_trace_load("TOP.w1", hdlVec, 1, 1);
  npi_nl_ut_dump_hdl_vec_info(hdlVec, stdout);

  npi_end();
  return 0;
}

#endif   /* ----- #ifndef DEMO_CPP  ----- */

