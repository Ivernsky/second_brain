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
 
        //iterate the port of "TEST.dut"
       npiHandle port_hdl;
       int port_size;
       char* port_name;
       char* port_dir;
       int i = 0;
 
       npiHandle port_it = npi_iterate(npiPort, mod_hdl);
       while( (port_hdl = npi_scan(port_it)) != NULL ) {
           //get the int/bool property and string property of port_hdl
           port_size = npi_get(npiSize, port_hdl);
           port_name = (char*) npi_get_str(npiName, port_hdl);
           port_dir  = (char*) npi_get_str(npiDirection, port_hdl);
           printf("    %d) Port = %s (%s Size=%d)\n", i++, port_name, port_dir, port_size);
 
           //release port_hdl since it is useless below
           npi_release_handle(port_hdl);
       }
    }
 
    //end NPI
    npi_end();
    return 0;
}
