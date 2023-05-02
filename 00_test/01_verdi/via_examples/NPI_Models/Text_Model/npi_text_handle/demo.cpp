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
  npiTextHandle file_hdl_handle_1, file_hdl_handle_2;
  npiTextHandle line_hdl_handle_1, line_hdl_handle_2;
  npiTextHandle word_hdl_handle_1, word_hdl_handle_2;
  npiTextIter   line_iter;
  npiTextIter   word_iter;

  file_hdl = npi_text_file_by_name ( "example.v" );
  file_hdl_handle_1 = npi_text_handle ( npiTextFile, file_hdl );
  if ( file_hdl_handle_1 == NULL )
    printf ( "file_hdl_handle_1 is NULL\n" );

  file_hdl_handle_2 = npi_text_handle( npiTextLine, file_hdl );
  if ( file_hdl_handle_2 == NULL )
    printf ( "file_hdl_handle_2 is NULL\n" );

  line_iter = npi_text_iter_start ( npiTextLine, file_hdl );
  line_hdl = npi_text_iter_next ( line_iter );
  line_hdl_handle_1 = npi_text_handle( npiTextFile, line_hdl );
  if ( line_hdl_handle_1 == file_hdl )
    printf ( "line_hdl_handle_1 is file_hdl\n" );

  line_hdl_handle_2 = npi_text_handle( npiTextLine, line_hdl );
  if ( file_hdl_handle_2 == NULL )
    printf ( "line_hdl_handle_2 is NULL\n" );

  word_iter = npi_text_iter_start ( npiTextWord, line_hdl );
  word_hdl = npi_text_iter_next ( word_iter );
  word_hdl_handle_1 = npi_text_handle( npiTextFile, word_hdl );
  if ( word_hdl_handle_1 == NULL )
    printf ( "word_hdl_handle_1 is NULL\n" );

  word_hdl_handle_2 = npi_text_handle( npiTextLine, word_hdl );
  if ( word_hdl_handle_2 == line_hdl )
    printf ( "word_hdl_handle_2 is line_hdl\n" );

  npi_text_iter_stop ( word_iter );
  npi_text_iter_stop ( line_iter );

  npi_end();
  return 0;
}

