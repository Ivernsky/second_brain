#include <stdio.h>
#include "npi.h"       // must have for NPI programs
#include "npi_fsdb.h"  // header for NPI FSDB model

int main(int argc, char** argv)
{  
  const char* file_name = "demo.fsdb";
  const char* scope_name = "test.M1";
// call npi_init before using any APIs in the FSDB model
  npi_init(argc, argv);

  // open the FSDB file named "demo.fsdb"
  npiFsdbFileHandle fp = npi_fsdb_open( file_name );
  if ( !fp ) {
    printf("Failed to open FSDB file: %s.\n", file_name);
    return 1;
  }
  npiFsdbScopeHandle parent_scope;
  npiFsdbSigIter sig_iter;
npiFsdbSigHandle sig;
  npiFsdbScopeHandle scope = npi_fsdb_scope_by_name( fp, scope_name, NULL);
  if ( scope ) {
printf("== scope: %s ==\n", npi_fsdb_scope_property_str( npiFsdbScopeName, scope ) );
    if ( sig_iter = npi_fsdb_iter_sig( scope ) ) {
  while ( sig = npi_fsdb_iter_sig_next( sig_iter) ) {
    printf("sig: %s\n", npi_fsdb_sig_property_str( npiFsdbSigName, sig ) );
}
}
parent_scope = npi_fsdb_parent_scope( scope );
if ( parent_scope )
  printf("== parent scope: %s ==\n", npi_fsdb_scope_property_str( npiFsdbScopeName, parent_scope ) );
}
else {  
  printf("Failed to find scope: %s.\n", scope_name);
  }

  // close the FSDB file
  npi_fsdb_close( fp );
  return 0;
}

