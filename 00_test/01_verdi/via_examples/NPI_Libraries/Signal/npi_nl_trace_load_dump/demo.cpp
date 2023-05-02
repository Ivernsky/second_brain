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
  
  printf("Pass through assign, do not pass through module\n");
  npi_nl_trace_load_dump("TOP.w1", stdout, 0, 0);
  printf("Pass through assign and module\n");
  npi_nl_trace_load_dump("TOP.w1", stdout, 0, 1);
  printf("Do not pass through assign, pass through module\n");
  npi_nl_trace_load_dump("TOP.w1", stdout, 1, 1);
  printf("Do not pass through assign and module\n");
  npi_nl_trace_load_dump("TOP.w1", stdout, 1, 0);

  npi_end();
  return 0;
}

#endif   /* ----- #ifndef DEMO_CPP  ----- */

