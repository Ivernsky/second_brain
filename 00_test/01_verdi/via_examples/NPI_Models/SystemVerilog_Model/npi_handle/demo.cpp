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
        printf("Module: %s\n", npi_get_str(npiFullName, mod_hdl));
 
       //get the scope of the module handle "TEST.dut", by using 1-to-1 method npi_handle()
       npiHandle scope = npi_handle(npiScope, mod_hdl);
       printf("  The module is in scope: %s\n", npi_get_str(npiFullName, scope));
    }
 
    //end NPI
    npi_end();
    return 0;
}
