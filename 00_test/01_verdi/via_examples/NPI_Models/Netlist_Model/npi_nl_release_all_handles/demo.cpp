/* ==========================================================================
 *       Filename:  demo.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/17/11 10:34:49 CST
 *       Revision:  none
 *        Company:  Springsoft
 * ========================================================================== */

#ifndef  DEMO_C
#define  DEMO_C

#include <stdio.h>
#include <string.h>
#include "npi.h"      // header for NPI
#include "npi_nl.h"   // header for NPI Netlist L0

void release_test (npiNlHandle hdl)
{
  const NPI_BYTE8* type = npi_nl_get_str(npiNlType, hdl);
  printf("Release object %s => ", type);
  if (npi_nl_release_handle(hdl))
    printf("Success\n");
  else
    printf("Failure\n");
}

void permanent_test (npiNlHandle hdl)
{
  const NPI_BYTE8* type = npi_nl_get_str(npiNlType, hdl);
  printf("Set permanent for object %s => ", type);
  if (npi_nl_set_permanent_handle(hdl))
    printf("Success\n");
  else
    printf("Failure\n");
}

int main(int argc, char** argv)
{
  // initialize NPI process
  npi_init(argc, argv);
  // load design
  npi_load_design(argc, argv);

  npiNlHandle itr = npi_nl_iterate(npiNlInst, NULL);
  npiNlHandle netHdl = npi_nl_handle_by_name("top.a");

  // set iterator object as permanent => failure
  permanent_test(itr);
  // release iterator object as permanent => success
  release_test(itr);
  // set net object as permanent => success
  permanent_test(netHdl); 
  // release net object as permanent => failure
  release_test(netHdl);

  // release all handles, including permanent handles
  npi_nl_release_all_handles();
  // net object is invalid
  if (npi_nl_get(npiNlType, netHdl) == npiNlUndefined)
    printf("All handles are released!\n");

  // end NPI process
  npi_end();

  return 0;
}

#endif   /* ----- #ifndef DEMO_C  ----- */

