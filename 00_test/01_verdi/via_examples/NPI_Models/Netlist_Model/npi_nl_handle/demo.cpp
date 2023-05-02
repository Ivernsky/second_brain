/* ==========================================================================
 *       Filename:  demo.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/17/11 09:33:10 CST
 *       Revision:  none
 *        Company:  Springsoft
 * ========================================================================== */

#ifndef  DEMO_CPP
#define  DEMO_CPP

#include <stdio.h>
#include <string.h>
#include "npi.h"      // header for NPI
#include "npi_nl.h"   // header for NPI Netlist L0

void display_connected_objects(npiNlHandle port)
{
  npiNlHandle net, instport;
  if (port == NULL)
    return;
  printf("Port %s\n", npi_nl_get_str(npiNlFullName, port));
  if ((net = npi_nl_handle(npiNlNet, port)) != NULL)
  {
    printf("  Connect to net: %s\n", npi_nl_get_str(npiNlFullName, net));
    npi_nl_release_handle(net);
  }
  if ((instport = npi_nl_handle(npiNlInstPort, port)) != NULL)
  {
    printf("  Connect to instport: %s\n", npi_nl_get_str(npiNlFullName, instport));
    npi_nl_release_handle(instport);
  }
}

int main(int argc, char** argv)
{
  // initialize NPI process
  npi_init(argc, argv);
  // load design
  npi_load_design(argc, argv);

  NPI_BYTE8* fullName = "tb.t1";
  npiNlHandle inst = npi_nl_handle_by_name(fullName);

  // iterate ports from instance top
  npiNlHandle portItr = npi_nl_iterate(npiNlPort, inst);
  npiNlHandle port = NULL;
  while (port = npi_nl_scan(portItr))
  {
    display_connected_objects(port);
    npi_nl_release_handle(port);
  }

  // end NPI process
  npi_end();

  return 0;
}


#endif   /* ----- #ifndef DEMO_CPP  ----- */

