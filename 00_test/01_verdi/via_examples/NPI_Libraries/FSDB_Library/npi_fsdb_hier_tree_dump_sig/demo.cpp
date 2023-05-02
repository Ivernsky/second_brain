#include "npi_L1.h"
 
int main(int argc, char** argv)
{
  const char* const fsdbFileName = "demoL1.fsdb";
  const char* const scopeName = "tb_CPUsystem.i_BJsource";

  npi_init(argc, argv);
  
  npiFsdbFileHandle fileHdl = npi_fsdb_open( fsdbFileName );
  if ( !fileHdl )
    return 1; 
  
  FILE* fp = fopen("sig_list.txt", "w");
  if ( !fp )
    return 1;

  fprintf( fp, "===== Dump declared signals: =====\n" );
  npi_fsdb_hier_tree_dump_sig( fileHdl, fp, scopeName );
  fprintf( fp, "===== End of dump declared signals =====\n" );
  
  fprintf( fp, "===== Dump decalred + member signals: =====\n" );
  npi_fsdb_hier_tree_dump_sig( fileHdl, fp, scopeName, 1 );
  fprintf( fp, "===== End of dump declared + member signals =====\n" );

  npi_fsdb_close( fileHdl );
  fclose( fp );
  npi_end();
  return 0;
}
 
