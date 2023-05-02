/* ==========================================================================
 *       Filename:  demo.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/17/11 10:28:27 CST
 *       Revision:  none
 *        Company:  Springsoft
 * ========================================================================== */

#ifndef  DEMO_CPP
#define  DEMO_CPP

#include <stdio.h>
#include <string.h>
#include "npi.h"      // header for NPI
#include "npi_nl.h"   // header for NPI Netlist L0

void dump_hdl ( npiNlHandle hdl )
{
  if (hdl == NULL)
    return;
  printf("Object %s", npi_nl_get_str(npiNlFullName, hdl));
  printf(" (%s)\n", npi_nl_get_str(npiNlType, hdl));
}

void iterate_object ( NPI_INT32 type, npiNlHandle refHdl ) 
{
  if (refHdl == NULL)
    return;
  npiNlHandle itr = npi_nl_iterate(type, refHdl);
  npiNlHandle subHdl = NULL;
  while (subHdl = npi_nl_scan(itr))
  {
    dump_hdl(subHdl);
    npi_nl_release_handle(subHdl);
  }
}

int main(int argc, char** argv)
{
  // initialize NPI process
  npi_init(argc, argv);
  // load design
  npi_load_design(argc, argv);

  // iterate top instances
  npiNlHandle topInstItr = npi_nl_iterate(npiNlInst, NULL);
  npiNlHandle topInst = NULL;
  while (topInst = npi_nl_scan(topInstItr))
  {
    // iterate sub instances
    iterate_object(npiNlInst, topInst);
    // iterate nets
    iterate_object(npiNlNet, topInst);
    // iterate ports
    iterate_object(npiNlPort, topInst);
    npi_nl_release_handle(topInst);
  }

  // end NPI process
  npi_end();

  return 0;
}

#endif   /* ----- #ifndef DEMO_CPP  ----- */

