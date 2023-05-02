#include <stdio.h>
#include "npi.h"
#include "npi_hdl.h"
 
//Assume the executable name is "main.exe", the command looks like
//    main.exe -sv example.v
int main(int argc, char** argv)
{
    //initialize NPI and load design example.v
    npi_init(argc, argv);
    npi_load_design(argc, argv);
 
    npiHandle select_hdl;
    NPI_INT32 idx;
    //get the var bit handle for "top.r[1]"
    npiHandle var_hdl = npi_handle_by_name("top.r", NULL);
    if( var_hdl ) {
        idx = 1;
        select_hdl = npi_handle_by_index(var_hdl, idx);
        if (select_hdl) {
          printf("Get member %s ", npi_get_str(npiFullName, select_hdl));
          printf("by object %s and index %d\n", npi_get_str(npiFullName, var_hdl), idx);
        }
    }
 
    //get the module handle for "top.mArr[0]"
    npiHandle arr_hdl = npi_handle_by_name("top.mArr", NULL);
    if( arr_hdl ) {
        idx = 0;
        select_hdl = npi_handle_by_index(arr_hdl, idx);
        if (select_hdl) {
          printf("Get member %s ", npi_get_str(npiFullName, select_hdl));
          printf("by object %s and index %d\n", npi_get_str(npiFullName, arr_hdl), idx);
        }
    }
 
    //end NPI
    npi_end();
    return 0;
}
