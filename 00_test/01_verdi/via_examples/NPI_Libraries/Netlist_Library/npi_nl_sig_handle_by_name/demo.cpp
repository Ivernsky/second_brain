/* ==========================================================================
 *       Filename:  demo.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/17/11 10:37:52 CST
 *       Revision:  none
 *        Company:  Springsoft
 * ========================================================================== */

#ifndef  DEMO_CPP
#define  DEMO_CPP

#include "npi.h"     // header file for NPI L0
#include "npi_L1.h"  // header file for NPI L1

int main (int argc, char** argv)
{
  // initialize NPI process
  npi_init(argc, argv);
  // load design
  npi_load_design(argc, argv);

  // setup the character string for sigName
  int i = 0;
  char* sigName[] = { 
    "top.a",
    "top.b[1]",
    "top.c[21:20]",
    "top.u1.Z[1:0]",
    "top.u1.A[31]",
    "top.u1.B[16:15]" };

  npiNlHandle sigHdl = NULL;
  for (i = 0; i < 6; i++)
  {
    sigHdl = npi_nl_sig_handle_by_name(sigName[i]);
    npi_nl_ut_dump_hdl_info(sigHdl, stdout);
    npi_nl_release_handle(sigHdl);
  }

  // end NPI process
  npi_end();

  return 0;
}


#endif   /* ----- #ifndef DEMO_C  ----- */

