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
  printf ( "file string property: \n" );
  printf ( "  file full name:\n    %s\n", npi_text_property_str ( npiTextFileFullName, file_hdl ) );
  printf ( "  file name:\n    %s\n", npi_text_property_str ( npiTextFileName, file_hdl ) );
  printf ( "  file content:\n%s", npi_text_property_str ( npiTextFileContent, file_hdl ) );

  line_iter = npi_text_iter_start ( npiTextLine, file_hdl );
  line_hdl = npi_text_iter_next ( line_iter );
  printf ( "\nline string property: \n" );
  printf ( "  line content:\n%s", npi_text_property_str ( npiTextLineContent, line_hdl ) );

  word_iter = npi_text_iter_start ( npiTextWord, line_hdl );
  word_hdl = npi_text_iter_next ( word_iter );
  printf ( "\nword string property: \n" );
  printf ( "  word name = %s\n", npi_text_property_str ( npiTextWordName, word_hdl ) );
  printf ( "  word attribute = %s\n", npi_text_property_str ( npiTextWordAttribute, word_hdl ) );

  npi_text_iter_stop ( word_iter );
  npi_text_iter_stop ( line_iter );

  npi_end();
  return 0;
}
