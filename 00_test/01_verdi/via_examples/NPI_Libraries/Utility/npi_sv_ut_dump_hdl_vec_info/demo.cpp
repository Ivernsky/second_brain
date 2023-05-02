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

  hdlVec_t hdlVec;
  npiHandle instHdl = npi_handle_by_name("top", NULL);
  npiHandle itr = npi_iterate(npiNet, instHdl);
  npiHandle subHdl = NULL;
  while (subHdl = npi_scan(itr))
    hdlVec.push_back(subHdl);
 
  // get the hdl information and print it  
  const char* hdlInfo = npi_sv_ut_get_hdl_info(instHdl);
  printf("%s\n", hdlInfo);
  // dump the handle information usin L1 API
  npi_sv_ut_dump_hdl_info(instHdl, stdout);
  // dump and release the handles in the hdl vector
  npi_sv_ut_dump_hdl_vec_info(hdlVec, stdout, true);

  npi_end();
  return 0;
}

#endif   /* ----- #ifndef DEMO_CPP  ----- */

