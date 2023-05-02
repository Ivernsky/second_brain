/* ==========================================================================
 *       Filename:  demo.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  02/21/12 15:10:46 CST
 *       Revision:  none
 *        Company:  Springsoft
 * ========================================================================== */

#ifndef  DEMO_CPP
#define  DEMO_CPP

#include <stdio.h>
#include "npi.h"  
#include "npi_L1.h"

int main(int argc, char** argv)
{
  FILE* fp = fopen("demo.log", "w");
  if( !fp )
    return 0;
  
  npi_init(argc, argv);
  
  // construct an npiUSN handle for a string : "System.TOP.i_CPU.i_ALUB"
  char* hier_name = "System.TOP.i_CPU.i_ALUB";
  char delimiter = '.';
  npiUSN usn_hdl = npi_usn_construct(hier_name, delimiter);

  // iterate every scopes and print to stdout
  fprintf(fp, "== Dump the scope information ==\n");
  int scope_num = npi_usn_number(usn_hdl);
  for (int i=0; i<scope_num; i++) {
    fprintf(fp, "Scope(%d) = \"%s\"\n", i, npi_usn_scope_name_at(usn_hdl, i));
  }

  // remove the last scope
  npi_usn_pop_back(usn_hdl);  // Hierarchy becomes: "System.TOP.i_CPU"

  // get the last scope
  char* last_scope = npi_usn_back(usn_hdl);
  fprintf(fp, "Last scope = %s\n", last_scope); //Last scope = i_CPU

  // add the last scope "i_CCU.i_MODE"
  npi_usn_push_back(usn_hdl, "i_CCU");  // Hierarchy becomes: "System.TOP.i_CPU.i_CCU"
  npi_usn_push_back(usn_hdl, "i_MODE");  // Hierarchy becomes: "System.TOP.i_CPU.i_CCU.i_MODE"

  // get the middle scope i_CPU.i_CCU : from scope 2 to scope 3
  char* middle_name = npi_usn_middle_name(usn_hdl, 2, 3);
  fprintf(fp, "Middle name = \"%s\"\n", middle_name); // Middle name: "i_CPU.i_CCU"¨

  // change the delimiter from '.' to '/'
  npi_usn_set_delimiter(usn_hdl,  '/');
  fprintf(fp, "Current delimiter is %c\n", npi_usn_delimiter(usn_hdl));

  // print the full hierarchy name
  char* full_name = npi_usn_hierarchy_name(usn_hdl);
  fprintf(fp, "After scope manipulation, now hierarchy is: \"%s\"\n", full_name);

  // remove all scopes
  while( !npi_usn_is_empty(usn_hdl) ) {
    npi_usn_pop_back(usn_hdl);
  }
  
  // destroy the npiUSN handle
  npi_usn_destroy(usn_hdl);

  npi_end();

  fclose(fp);
  return 0;
}


#endif   /* ----- #ifndef DEMO_CPP  ----- */

