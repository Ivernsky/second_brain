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

#include "npi.h"
#include "npi_L1.h"

int main(int argc, char** argv)
{
  npi_init(argc, argv);
  npi_load_design(argc, argv);

  npi_mod_define_dump_inst("MOD", stdout);

  npi_end();
  return 0;
}

#endif   /* ----- #ifndef DEMO_CPP  ----- */

