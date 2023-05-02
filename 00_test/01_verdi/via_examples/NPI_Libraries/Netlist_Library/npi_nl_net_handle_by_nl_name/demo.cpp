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
  // initialize NPI process
  npi_init(argc, argv);
  // load design
  npi_load_design(argc, argv);

  // setup the character string for handles' nl_names
  char* scopeHierName = "top.i_ff";
  char* instNlName = "flipflop:Always1#Always0:11:16:Reg";
  char* portNlName = "din";
  char* instportNlName = "ARL_reset";
  char* netNlName = "1'b1";

  // find handles by nl_names
  npiNlHandle instHdl = npi_nl_inst_handle_by_nl_name(scopeHierName, instNlName);
  npiNlHandle portHdl = npi_nl_port_handle_by_nl_name(scopeHierName, portNlName);
  npiNlHandle instportHdl = npi_nl_instport_handle_by_nl_name(scopeHierName, instNlName, instportNlName);
  npiNlHandle netHdl = npi_nl_net_handle_by_nl_name(scopeHierName, netNlName);
  
  // dump handles
  npi_nl_ut_dump_hdl_info(instHdl, stdout);
  npi_nl_ut_dump_hdl_info(portHdl, stdout);
  npi_nl_ut_dump_hdl_info(instportHdl, stdout);
  npi_nl_ut_dump_hdl_info(netHdl, stdout);

  npi_end();
  return 0;
}

#endif   /* ----- #ifndef DEMO_CPP  ----- */

