#include <stdio.h>
#include "npi.h"       // must have for NPI programs
#include "npi_fsdb.h"  // header for NPI FSDB model

int main(int argc, char** argv)
{  
  const char* file_name = "demo.fsdb";
// call npi_init before using any APIs in the FSDB model
  npi_init(argc, argv);

  // open the FSDB file named "demo.fsdb"
  npiFsdbFileHandle fp = npi_fsdb_open( file_name );
  if ( !fp ) {
    printf("Failed to open FSDB: %s.\n", file_name);
    return 1;
  } 

  npiFsdbScopeIter scopeIter;
  npiFsdbScopeHandle scope;

  if ( scopeIter = npi_fsdb_iter_top_scope( fp ) ) {
    // only want to iter 1 top scope
    if ( scope = npi_fsdb_iter_scope_next( scopeIter ) )
      printf("== scope: %s ==\n", npi_fsdb_scope_property_str( npiFsdbScopeFullName, scope ) );
// free iterator manually
      npi_fsdb_iter_scope_stop( scopeIter );
  }

  // close the FSDB file
  npi_fsdb_close( fp );
  return 0;
}

