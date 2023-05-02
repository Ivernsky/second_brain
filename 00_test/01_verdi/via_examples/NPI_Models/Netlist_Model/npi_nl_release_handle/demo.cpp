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

void release_hdl (npiNlHandle hdl)
{
  if (hdl == NULL)
    return;
  const NPI_BYTE8* type = npi_nl_get_str(npiNlType, hdl);
  printf("Release %s: ", type);
  if (strcmp(type, "npiNlIterator") != 0)
    printf("%s", npi_nl_get_str(npiNlFullName, hdl));
  printf(" => ");

  if (npi_nl_release_handle(hdl) == 1)
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

  npiNlHandle net1 = npi_nl_handle_by_name("top.a");
  npiNlHandle inst1 = npi_nl_handle(npiNlInst, net1);
  npiNlHandle net2 = npi_nl_handle_by_name("top.b");
  npiNlHandle inst2 = npi_nl_handle(npiNlInst, net2);

  // release top.a which is referenced once => success
  release_hdl(net1);
  // release top.b which is referenced once => success
  release_hdl(net2);
  // release top which is referenced twice => failure
  release_hdl(inst1);
  // release top which is referenced once => success
  release_hdl(inst2);

  // end NPI process
  npi_end();

  return 0;
}

#endif   /* ----- #ifndef DEMO_C  ----- */

