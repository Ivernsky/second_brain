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
  npiNlHandle hdlArr [HDL_ARR_SIZE];
  int hdlNo;
} hdlStats;

void cb_func_collect_obj (npiNlHandle hdl, void *cb)
{
  hdlStats* stats = (hdlStats*)cb;
  stats->hdlArr[stats->hdlNo++] = hdl;
  npi_nl_set_permanent_handle(hdl); // set permanent to preserve the handle
}

void dump_handle_result(hdlStats &instHdlStats, hdlStats &portHdlStats)
{
  int i;
  for (i=0; i<instHdlStats.hdlNo; i++)
    npi_nl_ut_dump_hdl_info(instHdlStats.hdlArr[i], stdout);
  for (i=0; i<portHdlStats.hdlNo; i++)
    npi_nl_ut_dump_hdl_info(portHdlStats.hdlArr[i], stdout);
  printf("Found %d instances and %d ports\n", instHdlStats.hdlNo, portHdlStats.hdlNo);
}

int main(int argc, char** argv)
{
  npi_init(argc, argv);
  npi_load_design(argc, argv);
 
  hdlStats instHdlStats;
  instHdlStats.hdlNo = 0;
  hdlStats portHdlStats;
  portHdlStats.hdlNo = 0;
  // register callback funcation and data
  npi_nl_hier_tree_trv_register_cb(npiNlInst, cb_func_collect_obj, &instHdlStats);
  npi_nl_hier_tree_trv_register_cb(npiNlPort, cb_func_collect_obj, &portHdlStats);
  // traverse the design from scope "top"
  npi_nl_hier_tree_trv("top");
  // dump the result
  dump_handle_result(instHdlStats, portHdlStats);

  // reset the callback function and traverse again
  instHdlStats.hdlNo = 0;
  portHdlStats.hdlNo = 0;
  npi_nl_hier_tree_trv_reset_cb();
  npi_nl_hier_tree_trv("top");
  // callback data is unchanged
  dump_handle_result(instHdlStats, portHdlStats);

  // release all handles (including permanent handles)
  npi_nl_release_all_handles();
 
  npi_end();
  return 0;
}

#endif   /* ----- #ifndef DEMO_CPP  ----- */

