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
  printf ( "file integer property: \n" );
  printf ( "  line count = %d\n", npi_text_property ( npiTextLineCount, file_hdl ) );
  line_iter = npi_text_iter_start ( npiTextLine, file_hdl );
  line_hdl = npi_text_iter_next ( line_iter );
  printf ( "line integer property: \n" );
  printf ( "  line index number = %d\n", npi_text_property ( npiTextLineNumber, line_hdl ) );
  printf ( "  word count = %d\n", npi_text_property ( npiTextWordCount, line_hdl ) );
  word_iter = npi_text_iter_start ( npiTextWord, line_hdl );
  word_hdl = npi_text_iter_next ( word_iter );
  printf ( "word integer property: \n" );
  printf ( "  word index number = %d\n", npi_text_property ( npiTextWordNumber, word_hdl ) );
  printf ( "  word attribute = %d\n", npi_text_property ( npiTextWordAttribute, word_hdl ) );
  npi_text_iter_stop ( word_iter );
  npi_text_iter_stop ( line_iter );

  npi_end();
  return 0;
}
