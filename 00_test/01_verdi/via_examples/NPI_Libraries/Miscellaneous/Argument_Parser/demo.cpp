
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
  if( !fp ) {
    return 0;
  }
  
  npi_init(argc, argv);

  int my_argc = 8;
  char* my_argv[] = {"mycmd", "-A", "a1", "a2", "a3", "-B", "b2", "b3"};

  // construct npiArg handle
  npiArg arg = npi_arg_construct(my_argc, my_argv);
  fprintf(fp, "npiArg: argc = %d, number_attr = %d\n", npi_arg_get_argc(arg), npi_arg_number_attr(arg));

  // test if attribute "-A" exist
  if( npi_arg_has_attr(arg, "-A") ) {
    fprintf(fp, "npiArg: has attribute \"-A\"");
    fprintf(fp, "    attribute number of value = %d\n", npi_arg_attr_number_value(arg, "-A"));

    // test if the value "a2", "a4" exist in the  attribute "-A"
    fprintf(fp, "    has attribute value \"a2\" ? %s\n", npi_arg_attr_has_value(arg, "-A", "a2")?"TRUE":"FALSE");
    fprintf(fp, "    has attribute value \"a4\" ? %s\n", npi_arg_attr_has_value(arg, "-A", "a4")?"TRUE":"FALSE");

    // dump all values by the position
    for(int i=0; i<npi_arg_attr_number_value(arg, "-A"); i++) {
      fprintf(fp, "    attribute value at pos %d: %s\n", i, npi_arg_attr_get_value(arg, "-A", i+1));
    }
  }

  // test if attribute "-C" exist
  if( npi_arg_has_attr(arg, "-C") ) {
    fprintf(fp, "npiArg: has attribute \"-C\"");
  }
  else {
    fprintf(fp, "npiArg: No attribute \"-C\"\n");
  }

  // remove the attribute "-B"
  fprintf(fp, "npiArg: remove the attr \"-B\"...\n");
  npi_arg_remove_attr(arg, "-B");

  // remove the value at position 2 of attribute "-A"
  fprintf(fp, "npiArg: remove the attr \"-A\" at position 2...\n");
  npi_arg_attr_remove_value(arg, "-A", 2);

  // add the attribute "-C" and values "c1 c2 c3"
  fprintf(fp, "npiArg: add the attr \"-C c1 c2 c3\"...\n");
  npi_arg_add_attr(arg, "-C");
  npi_arg_attr_append_value(arg, "-C", "c1");
  npi_arg_attr_append_value(arg, "-C", "c2");
  npi_arg_attr_append_value(arg, "-C", "c3");

  // dump new_argc and new_argv 
  // (note: the memory of new_argv is allocated by npiArg; 
  //          we suggest user has one copy for new_argv)
  char** new_argv = npi_arg_get_argv(arg);
  int new_argc = npi_arg_get_argc(arg);
  fprintf(fp, "npiArg: new argc = %d\n", new_argc);
  for(int i=0; i<new_argc; i++) {
    fprintf(fp, "npiArg: new argv(%d) = %s\n", i, new_argv[i]);
  }

  fprintf(fp, "npiArg: ...remove the attr \"-C c1\" (keep c2 c3)...\n");
  npi_arg_remove_attr(arg, "-C", 1/*number*/);
  new_argv = npi_arg_get_argv(arg);
  new_argc = npi_arg_get_argc(arg);
  fprintf(fp, "npiArg: new argc = %d\n", new_argc);
  for(int i=0; i<new_argc; i++) {
    fprintf(fp, "npiArg: new argv(%d) = %s\n", i, new_argv[i]);
  }


  // destroy the npiArg handle
  npi_arg_destroy(arg);

  npi_end();
  fclose(fp);
  return 0;
}

#endif   /* ----- #ifndef DEMO_CPP  ----- */

