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

  npiTextHandle line_20_hdl = npi_text_line_by_number(file_hdl, 20);
  printf("Line 20 at file example.v:\n");
  printf("==========================\n");
  printf("%s", npi_text_property_str(npiTextLineContent, line_20_hdl));
  printf("==========================\n");

  npiTextHandle prev_line_hdl = npi_text_prev_line(line_20_hdl);
  printf("\nPrevious line (line %d):\n", npi_text_property(npiTextLineNumber, prev_line_hdl));
  printf("==========================\n");
  printf("%s", npi_text_property_str(npiTextLineContent, prev_line_hdl));
  printf("==========================\n");
  
  npi_end();
  return 0;
}

