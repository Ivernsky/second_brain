#include <stdio.h>
#include "npi.h"       // header for npi_init, npi_load_design, npi_end
#include "npi_text.h"  // header for npi text model

int main(int argc, char** argv)
{
  npi_init( argc, argv );
  npi_load_design( argc, argv );
  printf("\n");
  
  npiTextHandle file_hdl;
  file_hdl = npi_text_file_by_name ( "example.v" );
  if( !file_hdl ) {
    return 1;
  }

  npiTextHandle line_19_hdl = npi_text_line_by_number(file_hdl, 19);
  printf("Line 19 at file example.v:\n");
  printf("==========================\n");
  printf("%s", npi_text_property_str(npiTextLineContent, line_19_hdl));
  printf("==========================\n");

  npi_end();
  return 0;
}

