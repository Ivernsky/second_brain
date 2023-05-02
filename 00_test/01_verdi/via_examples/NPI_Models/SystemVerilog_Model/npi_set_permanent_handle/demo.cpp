#include <stdio.h>
#include <string.h>
#include "npi.h"      // header for NPI
#include "npi_hdl.h" // header for NPI Language model
 
void release_test (npiHandle hdl)
{
  const NPI_BYTE8* type = npi_get_str(npiType, hdl);
  printf("Release object %s => ", type);
  if (npi_release_handle(hdl))
    printf("Success\n");
  else
    printf("Failure\n");
}
 
void permanent_test (npiHandle hdl)
{
  const NPI_BYTE8* type = npi_get_str(npiType, hdl);
  printf("Set permanent for object %s => ", type);
  if (npi_set_permanent_handle(hdl))
    printf("Success\n");
  else
    printf("Failure\n");
}
 
int main(int argc, char** argv)
{
  // initialize NPI process
  npi_init(argc, argv);
  // load design
  npi_load_design(argc, argv);
 
  npiHandle handle1 = npi_handle_by_name("top.a", NULL);
  npiHandle itr = npi_iterate(npiInstance, NULL);
 
  // set iterator object as permanent => failure
  permanent_test(itr);
  // release iterator object as permanent => success
  release_test(itr);
  // set net object as permanent => success
  permanent_test(handle1);
  // release net object as permanent => failure
  release_test(handle1);
 
  // release all handles, including permanent handles
  npi_release_all_handles();
  // net object is invalid
  if (npi_get(npiType, handle1) == npiUndefined)
    printf("All handles are released!\n");
 
  // end NPI process
  npi_end();
 
  return 0;
}
