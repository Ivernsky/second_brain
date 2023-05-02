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

  hdl2hdlVecPairVec_t portSigPairVec;
  hdl2hdlVecPairVec_t::iterator it;

  npi_inst_port_2_high_conn_sig("TOP.inst", portSigPairVec);
  for (it = portSigPairVec.begin(); it != portSigPairVec.end(); it++)
  {
    npi_sv_ut_dump_hdl_info((*it).first, stdout);
    npi_release_handle((*it).first);
    npi_sv_ut_dump_hdl_vec_info((*it).second/*IO*/, stdout);
  }

  npi_end();
  return 0;
}

#endif   /* ----- #ifndef DEMO_CPP  ----- */

