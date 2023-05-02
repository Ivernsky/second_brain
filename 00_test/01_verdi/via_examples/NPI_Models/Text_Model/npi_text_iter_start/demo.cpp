#include <stdio.h>
#include "npi.h"       // header for npi_init, npi_load_design, npi_end
#include "npi_text.h"  // header for npi text model

int main(int argc, char** argv)
{
  npi_init( argc, argv );
  npi_load_design( argc, argv );

  const char*   file_name;
  npiTextHandle file_hdl;
  npiTextIter   file_iter;
 
  file_iter = npi_text_iter_start ( npiTextFile, NULL );
  while ( NULL != ( file_hdl = npi_text_iter_next ( file_iter ) ) ) {
    file_name = npi_text_property_str ( npiTextFileName, file_hdl );
    printf ( "%s\n", file_name );
  }
  npi_text_iter_stop ( file_iter );

  npi_end();
  return 0;
}

