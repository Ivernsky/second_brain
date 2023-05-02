#include <stdio.h>
#include "npi.h"       // header for npi_init, npi_load_design, npi_end
#include "npi_text.h"  // header for npi text model

int main(int argc, char** argv)
{
  npi_init( argc, argv );
  npi_load_design( argc, argv );

  npiTextHandle file_hdl;
  npiTextHandle line_hdl;
  npiTextIter   line_iter;

  file_hdl = npi_text_file_by_name ( "example.v" );
  line_iter = npi_text_iter_start ( npiTextLine, file_hdl );
  line_hdl = npi_text_iter_next ( line_iter );
  line_hdl = npi_text_iter_next ( line_iter );
  int delete_line_return = npi_text_delete_line ( line_hdl );
  npi_text_iter_stop ( line_iter );
  printf( "%s", npi_text_property_str ( npiTextFileContent, file_hdl ) );

  npi_end();
  return delete_line_return;
}

