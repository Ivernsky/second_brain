/* ==========================================================================
 *       Filename:  demo.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/17/11 09:52:39 CST
 *       Revision:  none
 *        Company:  Springsoft
 * ========================================================================== */

#ifndef  DEMO_CPP
#define  DEMO_CPP

#include <stdio.h>
#include <string.h>
#include "npi.h"      // header for NPI
#include "npi_nl.h"   // header for NPI Netlist L0

void display_sliced_objects(npiNlHandle hdl)
{
  NPI_INT32 type = npi_nl_get(npiNlType, hdl);
  if ( type == npiNlInst )
    return;
  NPI_INT32 left = npi_nl_get(npiNlLeft, hdl);
  NPI_INT32 right = npi_nl_get(npiNlRight, hdl);
  NPI_INT32 lb = left, rb = right;
  NPI_INT32 lincr = (left > right) ? -1 : 1;
  NPI_INT32 rincr = (left > right) ? 1 : -1;
  npiNlHandle hdlByRange = NULL;
  
  printf("Right range is fixed\n");
  for (lb = left; lb != right; lb += lincr)
  {
    hdlByRange = npi_nl_handle_by_range(hdl, lb, right);
    printf("Handle %s by range [%d:%d] is obtained\n",
            npi_nl_get_str(npiNlFullName, hdlByRange), lb, right);
    npi_nl_release_handle(hdlByRange);
  }

  printf("Left range is fixed\n");
  for (rb = right; rb != left; rb += rincr)
  {
    hdlByRange = npi_nl_handle_by_range(hdl, left, rb);
    printf("Handle %s by range [%d:%d] is obtained\n",
            npi_nl_get_str(npiNlFullName, hdlByRange), left, rb);
    npi_nl_release_handle(hdlByRange);
  }
}

int main(int argc, char** argv)
{
  // initialize NPI process
  npi_init(argc, argv);
  // load design
  npi_load_design(argc, argv);

  NPI_BYTE8* fullName = "test.out";
  npiNlHandle net = npi_nl_handle_by_name(fullName);

  display_sliced_objects(net);
  npi_nl_release_handle(net);

  // end NPI process
  npi_end();

  return 0;
}


#endif   /* ----- #ifndef DEMO_CPP  ----- */

