#include <stdio.h>
#include "npi.h"       // header for npi_init, npi_load_design, npi_end
#include "npi_text.h"  // header for npi text model

int main(int argc, char** argv)
{
  npi_init( argc, argv );
  npi_load_design( argc, argv );

  npiTextHandle file_hdl;
  file_hdl = npi_text_file_by_name ( "example.v" );
  printf( "%d\n", npi_text_property ( npiTextLineCount, file_hdl ) );

  npi_end();
  return 0;
}

