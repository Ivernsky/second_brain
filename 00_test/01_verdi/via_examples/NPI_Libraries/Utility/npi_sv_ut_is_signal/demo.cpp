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

void signal_check(npiHandle hdl)
{
  if (npi_sv_ut_is_signal(hdl))
    printf("Signal => ");
  else
    printf("Not a signal => ");
  npi_sv_ut_dump_hdl_info(hdl, stdout);
}

int main(int argc, char** argv)
{
  npi_init(argc, argv);
  npi_load_design(argc, argv);

  hdlVec_t hdlVec;
  npiHandle instHdl = npi_handle_by_name("top", NULL);
  npiHandle itr = npi_iterate(npiContAssign, instHdl);
  npiHandle subHdl = NULL, lhsHdl = NULL, rhsHdl = NULL;
  
  while (subHdl = npi_scan(itr))
  {
    lhsHdl = npi_handle(npiLhs, subHdl);
    rhsHdl = npi_handle(npiRhs, subHdl);
    signal_check(lhsHdl);
    signal_check(rhsHdl);
    npi_release_handle(lhsHdl);
    npi_release_handle(rhsHdl);
    npi_release_handle(subHdl);
  }

  npi_end();
  return 0;
}

#endif   /* ----- #ifndef DEMO_CPP  ----- */

