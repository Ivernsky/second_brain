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
 
#define HDL_ARR_SIZE 64
typedef struct {
  npiHandle hdlArr [HDL_ARR_SIZE];
  int hdlNo;
} hdlStats;

void cb_func_collect_obj (npiHandle hdl, void *cb)
{
  hdlStats* stats = (hdlStats*)cb;
  stats->hdlArr[stats->hdlNo++] = hdl;
  npi_set_permanent_handle(hdl); // set permanent to preserve the handle
}

void dump_handle_result(hdlStats &modHdlStats, hdlStats &portHdlStats)
{
  int i;
  for (i=0; i<modHdlStats.hdlNo; i++)
    npi_sv_ut_dump_hdl_info(modHdlStats.hdlArr[i], stdout);
  for (i=0; i<portHdlStats.hdlNo; i++)
    npi_sv_ut_dump_hdl_info(portHdlStats.hdlArr[i], stdout);
  printf("Found %d modules and %d ports\n", modHdlStats.hdlNo, portHdlStats.hdlNo);
}

int main(int argc, char** argv)
{
  npi_init(argc, argv);
  npi_load_design(argc, argv);
 
  hdlStats modHdlStats;
  modHdlStats.hdlNo = 0;
  hdlStats portHdlStats;
  portHdlStats.hdlNo = 0;
  // register callback funcation and data
  npi_hier_tree_trv_register_cb(npiModule, cb_func_collect_obj, &modHdlStats);
  npi_hier_tree_trv_register_cb(npiPort, cb_func_collect_obj, &portHdlStats);
  // traverse the design from scope "top"
  npi_hier_tree_trv("top");
  // dump the result
  dump_handle_result(modHdlStats, portHdlStats);

  // reset the callback function and traverse again
  modHdlStats.hdlNo = 0;
  portHdlStats.hdlNo = 0;
  npi_hier_tree_trv_reset_cb();
  npi_hier_tree_trv("top");
  // dump the result
  dump_handle_result(modHdlStats, portHdlStats);

  // release all handles (including permanent handles)
  npi_release_all_handles();
 
  npi_end();
  return 0;
}

#endif   /* ----- #ifndef DEMO_CPP  ----- */

