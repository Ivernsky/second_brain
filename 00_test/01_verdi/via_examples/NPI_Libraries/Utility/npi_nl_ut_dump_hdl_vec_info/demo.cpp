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

  nlHdlVec_t hdlVec;
  npiNlHandle instHdl = npi_nl_handle_by_name("top");
  npiNlHandle itr = npi_nl_iterate(npiNlNet, instHdl);
  npiNlHandle subHdl = NULL;
  while (subHdl = npi_nl_scan(itr))
    hdlVec.push_back(subHdl);
 
  // get the hdl information and print it  
  const char* hdlInfo = npi_nl_ut_get_hdl_info(instHdl);
  printf("%s\n", hdlInfo);
  // dump the handle information usin L1 API
  npi_nl_ut_dump_hdl_info(instHdl, stdout);
  // dump and release the handles in the hdl vector
  npi_nl_ut_dump_hdl_vec_info(hdlVec, stdout, true);

  npi_end();
  return 0;
}

#endif   /* ----- #ifndef DEMO_CPP  ----- */

