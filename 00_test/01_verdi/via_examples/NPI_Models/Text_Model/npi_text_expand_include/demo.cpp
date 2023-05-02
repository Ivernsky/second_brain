#include <stdio.h>
#include <string.h>
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
  int           expand_result;

  file_hdl = npi_text_file_by_name ( "expand_include.v" );
  line_iter = npi_text_iter_start ( npiTextLine, file_hdl );
  line_hdl = npi_text_iter_next ( line_iter );
  word_iter = npi_text_iter_start ( npiTextWord, line_hdl );

  while ( NULL != ( word_hdl = npi_text_iter_next( word_iter ) ) ) {
    if ( 0 == strcmp ( npi_text_property_str ( npiTextWordAttribute, word_hdl ), "npiTextIncludeFile" ) ) {
      expand_result = npi_text_expand_include ( word_hdl );
    }
  }
  npi_text_iter_stop( word_iter );
  npi_text_iter_stop( line_iter );

  printf( "%s", npi_text_property_str ( npiTextFileContent, file_hdl ) );

  npi_end();
  return expand_result;
}
