/* ==========================================================================
 *       Filename:  demo.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/17/11 10:14:52 CST
 *       Revision:  none
 *        Company:  Springsoft
 * ========================================================================== */

#ifndef  DEMO_CPP
#define  DEMO_CPP

#include <stdio.h>
#include <string.h>
#include "npi.h"      // header for NPI
#include "npi_nl.h"   // header for NPI Netlist L0

void traverse_net_hdl_with_range (npiNlHandle netHdl)
{
  if (netHdl == NULL)
    return;
  // get the range of net
  int left = npi_nl_get(npiNlLeft, netHdl);
  int right = npi_nl_get(npiNlRight, netHdl);
  int low = (left <= right) ? left : right;
  int high= (left <= right) ? right : left;
  int i;
  npiNlHandle itr = NULL, subHdl = NULL;

  for (i = low; i <= high; i++)
  {
    // find the connectivity for each bit
    if (itr = npi_nl_iterate_with_range(npiNlConnectivity, netHdl, i, i))
    {
      printf("Find connectivity of %s with range [%d:%d]\n", npi_nl_get_str(npiNlFullName, netHdl), i, i);
      while (subHdl = npi_nl_scan(itr))
      {
        printf("  %s\n", npi_nl_get_str(npiNlFullName, subHdl));
        npi_nl_release_handle(subHdl);
      }
    }
  }
}

int main(int argc, char** argv)
{
  // initialize NPI process
  npi_init(argc, argv);
  // load design
  npi_load_design(argc, argv);

  NPI_BYTE8* fullName = "top.a"; // get the net handle called top.a
  npiNlHandle netHdl = npi_nl_handle_by_name(fullName);
  traverse_net_hdl_with_range(netHdl);
  npi_nl_release_handle(netHdl);
  // end NPI process
  npi_end();

  return 0;
}

#endif   /* ----- #ifndef DEMO_C  ----- */

