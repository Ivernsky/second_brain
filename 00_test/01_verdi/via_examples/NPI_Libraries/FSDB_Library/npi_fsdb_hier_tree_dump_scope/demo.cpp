#include "npi_L1.h"
 
int main(int argc, char** argv)
{
  const char* const fsdbFileName = "demoL1.fsdb";
  const char* const scopeName = "tb_CPUsystem.i_CPUsystem.i_CPU";

  npi_init(argc, argv);
  
  npiFsdbFileHandle fileHdl = npi_fsdb_open( fsdbFileName );
  if ( !fileHdl )
    return 1; 
  
  FILE* fp = fopen("scope_tree.txt", "w");
  if ( !fp )
    return 1;

  fprintf( fp, "===== Dump from root scope: =====\n" );
  npi_fsdb_hier_tree_dump_scope( fileHdl, fp );
  fprintf( fp, "===== End of dump from root scope =====\n" );
  
  fprintf( fp, "===== Dump from sub scope '%s': =====\n", scopeName );
  npi_fsdb_hier_tree_dump_scope( fileHdl, fp, scopeName );
  fprintf( fp, "===== End of dump from sub scope =====\n" );

  npi_fsdb_close( fileHdl );
  fclose( fp );
  npi_end();
  return 0;
}
 
