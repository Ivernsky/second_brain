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

void table_lookup (npiNlHandle hdl, char** inData, unsigned int no)
{
  const NPI_BYTE8* fullName = npi_nl_get_str(npiNlFullName, hdl);
  printf("UDP output instport: %s\n", fullName);

  const NPI_BYTE8* outStr = NULL;
  unsigned int i = 0;  
  for (i = 0; i < no; i++)
  {
    outStr = npi_nl_table_lookup(inData[i], hdl);
    if (outStr != NULL)
      printf("  in = %s, out = %s\n", inData[i], outStr);
    else
      printf("  invalid input %s\n", inData[i]);
  }
}

int main(int argc, char** argv)
{
  // initialize NPI process
  npi_init(argc, argv);
  // load design
  npi_load_design(argc, argv);

  // only allows [0, 1, x, z]
  char* inData[] = { "00x", "11x", "1x0", "x10", "xxx",
                     "1?0", "0?0", "?11", "?01", "1111" /*invalid input*/};
  int no = sizeof(inData)/sizeof(*inData);
  
  NPI_BYTE8* fullName = "top.mux";
  npiNlHandle inst = npi_nl_handle_by_name(fullName);
  // iterate load instports
  npiNlHandle itr = npi_nl_iterate(npiNlLoad, inst);
  npiNlHandle instport = NULL;
  while ((instport = npi_nl_scan(itr)) != NULL)
  {
    table_lookup(instport, inData, no);
    npi_nl_release_handle(instport);
  }
  npi_nl_release_handle(inst);

  // end NPI process
  npi_end();
  return 0;
}


#endif   /* ----- #ifndef DEMO_CPP  ----- */

