/* ==========================================================================
 *       Filename:  demo.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/17/11 09:40:29 CST
 *       Revision:  none
 *        Company:  Springsoft
 * ========================================================================== */

#ifndef  DEMO_CPP
#define  DEMO_CPP

#include <stdio.h>
#include <string.h>
#include "npi.h"      // header for NPI
#include "npi_nl.h"   // header for NPI Netlist L0


int main(int argc, char** argv)
{
  // initialize NPI process
  npi_init(argc, argv);
  // load design
  npi_load_design(argc, argv);

  // get lib handle by name and path
  npiNlHandle libHdl = npi_nl_lib_handle_by_name("demo", "./");

  // get cell by name and lib
  npiNlHandle dlyHdl = npi_nl_cell_handle_by_name("dly", libHdl);
  printf("Cell: %s, ", npi_nl_get_str(npiNlName, dlyHdl));
  printf("Cell Type: %s\n", npi_nl_get_str(npiNlCellType, dlyHdl));
  
  // get cell by name only, the first matched handle will be returned
  npiNlHandle fdHdl = npi_nl_cell_handle_by_name("FD1", NULL);
  printf("Cell: %s, ", npi_nl_get_str(npiNlName, fdHdl));
  printf("Cell Type: %s\n", npi_nl_get_str(npiNlCellType, fdHdl));

  // end NPI process
  npi_end();

  return 0;
}


#endif   /* ----- #ifndef DEMO_CPP  ----- */

