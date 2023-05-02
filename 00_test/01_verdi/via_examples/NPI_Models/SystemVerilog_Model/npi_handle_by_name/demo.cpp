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
 
    printf("\n");
    //get the module instance handle for "TEST.dut"
    npiHandle mod_hdl = npi_handle_by_name("TEST.dut", NULL);
    if( mod_hdl ) {
        printf("The fullname of the handle is: %s\n", npi_get_str(npiFullName, mod_hdl));
        printf("The type of the handle is: %s\n", npi_get_str(npiType, mod_hdl));
    }
 
    printf("\n");
    //get the variable handle with simple name "count" in the scope of mod_hdl
    npiHandle var_hdl = npi_handle_by_name("count", mod_hdl);
    if( var_hdl ) {
        printf("The fullname of the handle is: %s\n", npi_get_str(npiFullName, var_hdl));
        printf("The type of the handle is: %s\n", npi_get_str(npiType, var_hdl));
    }
 
    //end NPI
    npi_end();
    return 0;
}
