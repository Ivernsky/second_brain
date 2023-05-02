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

  npiNlHandle hdl = NULL;
  FILE* fp = NULL;
  NPI_BYTE8 hdlNameStr[1024];
  NPI_INT32 intVal = npiNlUndefined;
  int strLen = 0;

  if ((fp = fopen("demo.list", "r")) == NULL)
  {
    printf("Can not open the file!\n");
    npi_end();
    return 1;
  }

  while (fgets (hdlNameStr, sizeof(hdlNameStr), fp))
  {
    // remove the last '\n' character
    strLen = strlen(hdlNameStr);
    if (hdlNameStr[strLen-1] == '\n')
      hdlNameStr[strLen-1] = '\0';
    // find the handle by name
    if ((hdl = npi_nl_handle_by_name(hdlNameStr)) == NULL)
      continue;
    // dump the handle according to its  type
    switch (npi_nl_get(npiNlType, hdl))
    {
      case npiNlInst:
        printf("Instance object %s is found, ", npi_nl_get_str(npiNlFullName, hdl));
        printf("instance type is \"%s\".\n", npi_nl_get_str(npiNlInstType, hdl));
        // other actions .....
        break;
      case npiNlDeclNet:
        printf("Net object \"%s\" is found, ", npi_nl_get_str(npiNlFullName, hdl));
        printf("size is %d.\n", npi_nl_get(npiNlSize, hdl));
        // other actions .....
        break;
      default:
        break;
      }
    npi_nl_release_handle(hdl);
  }
  fclose(fp);

  // end NPI process
  npi_end();

  return 0;
}


#endif   /* ----- #ifndef DEMO_CPP  ----- */

