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
  if( !file_hdl )
    return 1;

  npiTextWordAttributeType word_attr;
  npiTextHandle inc_file_hdl;
  npiTextHandle line_hdl;
  npiTextHandle word_hdl;
  npiTextIter line_it;
  npiTextIter word_it;

  line_it = npi_text_iter_start(npiTextLine, file_hdl);
  while( NULL != (line_hdl = npi_text_iter_next(line_it)) ) {
    word_it = npi_text_iter_start(npiTextWord, line_hdl);
    while( NULL != (word_hdl = npi_text_iter_next(word_it)) ) {
      word_attr = (npiTextWordAttributeType) npi_text_property(npiTextWordAttribute, word_hdl);
      if( word_attr == npiTextIncludeFile ) {
	inc_file_hdl = npi_text_file_by_include_word(word_hdl);
	
	int line_no = npi_text_property(npiTextLineNumber, line_hdl);
	const char* word_name = npi_text_property_str(npiTextWordName, word_hdl);
	const char* inc_file_name = npi_text_property_str(npiTextFileName, inc_file_hdl);
	const char* inc_file_elab_name = npi_text_property_str(npiTextFileElabName, inc_file_hdl);
	printf("At example.v, line %d, the include word %s points to the include file: %s (%s)\n",
                line_no, word_name, inc_file_name, inc_file_elab_name);
      }
    }
    npi_text_iter_stop(word_it);
  }
  npi_text_iter_stop(line_it);

  npi_end();
  return 0;
}

