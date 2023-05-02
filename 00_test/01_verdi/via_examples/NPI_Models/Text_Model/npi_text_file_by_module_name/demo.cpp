#include <stdio.h>
#include "npi.h"       // header for npi_init, npi_load_design, npi_end
#include "npi_text.h"  // header for npi text model

int main(int argc, char** argv)
{
  npi_init( argc, argv );
  npi_load_design( argc, argv );
  printf("\n");
  
  npiTextHandle file_hdl;
  file_hdl = npi_text_file_by_module_name ( "AAA" );
  printf( "Module AAA in the file: %s (%s)\n", 
        npi_text_property_str ( npiTextFileName, file_hdl ),
        npi_text_property_str ( npiTextFileElabName, file_hdl ) );

  file_hdl = npi_text_file_by_module_name ( "BBB" );
  printf( "Module BBB in the file: %s (%s)\n", 
        npi_text_property_str ( npiTextFileName, file_hdl ),
        npi_text_property_str ( npiTextFileElabName, file_hdl ) );

  file_hdl = npi_text_file_by_module_name ( "CCC" );
  printf( "Module CCC in the file: %s (%s)\n", 
        npi_text_property_str ( npiTextFileName, file_hdl ),
        npi_text_property_str ( npiTextFileElabName, file_hdl ) );

  npi_end();
  return 0;
}

