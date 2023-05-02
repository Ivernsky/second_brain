#include <stdio.h>
#include "npi.h"       // header for npi_init, npi_load_design, npi_end
#include "npi_text.h"  // header for npi text model

int main(int argc, char** argv)
{
  npi_init( argc, argv );
  npi_load_design( argc, argv );

  npiTextHandle file_hdl;
  npiTextHandle line_hdl;
  npiTextHandle word_hdl;
  npiTextIter   line_iter;
  npiTextIter   word_iter;
 
  file_hdl = npi_text_file_by_name ( "example.v" );
  line_iter = npi_text_iter_start ( npiTextLine, file_hdl );
  line_hdl = npi_text_iter_next ( line_iter );
  line_hdl = npi_text_iter_next ( line_iter );
  word_iter = npi_text_iter_start ( npiTextWord, line_hdl );
  while( ( word_hdl = npi_text_iter_next( word_iter ) ) != NULL ) {
  }
  printf ( "stop word_iter = %d\n", npi_text_iter_stop ( word_iter ) );
  printf ( "stop line_iter = %d\n", npi_text_iter_stop ( line_iter ) );

  npi_end();
  return 0;
}

