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
 
    npiHandle var_hdl = npi_handle_by_name("top.r", NULL);
    if( var_hdl ) {
        //get the bit var handle for "top.r[4:3]"
        NPI_INT32 left = 4;
        NPI_INT32 right = 3;
        npiHandle slice_hdl = npi_handle_by_range(var_hdl, left, right);
        npiHandle parent_hdl;
        if (slice_hdl) {
          parent_hdl = npi_handle(npiParent, slice_hdl);
          printf("Get slice handle type %s and its range ", npi_get_str(npiType, slice_hdl));
          npiHandle left_hdl = npi_handle(npiLeftRange, slice_hdl);
          npiValue l_val;
          l_val.format = npiDecStrVal;
          npi_get_value(left_hdl, l_val);
          printf("[%s:", l_val.value.str);
          npiHandle right_hdl = npi_handle(npiRightRange, slice_hdl);
          npiValue r_val;
          r_val.format = npiDecStrVal;
          npi_get_value(right_hdl, r_val);
          printf("%s] ", r_val.value.str);
          printf("and its parent is %s\n", npi_get_str(npiFullName, parent_hdl));
          npi_release_handle(left_hdl);
          npi_release_handle(right_hdl);
          npi_release_handle(parent_hdl);
          npi_release_handle(slice_hdl);
        }
        npi_release_handle(var_hdl);
    }
 
    //end NPI
    npi_end();
    return 0;
}
