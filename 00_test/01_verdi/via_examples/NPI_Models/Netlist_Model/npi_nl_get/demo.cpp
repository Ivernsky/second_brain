/* ==========================================================================
 *       Filename:  demo.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  11/16/11 18:04:15 CST
 *       Revision:  none
 *        Company:  Springsoft
 * ========================================================================== */

#ifndef  DEMO_CPP
#define  DEMO_CPP

#include <stdio.h>
#include <string.h>
#include "npi.h"      // header for NPI
#include "npi_nl.h"   // header for NPI Netlist L0

void dump_inst (npiNlHandle instHdl)
{
  if (instHdl == NULL)
    return;
  NPI_INT32 intVal;
  const NPI_BYTE8* strVal;

  strVal = npi_nl_get_str(npiNlFullName, instHdl);
  printf("Instance %s\n", strVal);

  intVal = npi_nl_get(npiNlType, instHdl);
  strVal = npi_nl_get_str(npiNlType, instHdl);
  printf("  npiNlType property = %d (%s)\n", intVal, strVal);

  intVal = npi_nl_get(npiNlInstType, instHdl);
  strVal = npi_nl_get_str(npiNlInstType, instHdl);
  printf("  npiNlInstType property = %d (%s)\n", intVal, strVal);

  intVal = npi_nl_get(npiNlCellType, instHdl);
  strVal = npi_nl_get_str(npiNlCellType, instHdl);
  printf("  npiNlCellType property = %d (%s)\n", intVal, strVal);
}

int main(int argc, char** argv)
{
  // initialize NPI process
  npi_init(argc, argv);
  // load design
  npi_load_design(argc, argv);

  NPI_BYTE8* fullName = "top";
  npiNlHandle inst;
  npiNlHandle topInst = npi_nl_handle_by_name(fullName);
  dump_inst(topInst);

  // iterate sub instances from top
  npiNlHandle instItr = npi_nl_iterate(npiNlInst, topInst);
  while (inst = npi_nl_scan(instItr))
  {
    dump_inst(inst);
    npi_nl_release_handle(inst);
  }
  npi_nl_release_handle(topInst);

  // end NPI process
  npi_end();

  return 0;
}
    
#endif   /* ----- #ifndef DEMO_CPP  ----- */

