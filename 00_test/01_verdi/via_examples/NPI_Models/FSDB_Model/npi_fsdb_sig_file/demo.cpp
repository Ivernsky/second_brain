#include <stdio.h>
#include "npi.h"       // must have for NPI programs
#include "npi_fsdb.h"  // header for NPI FSDB model

int main(int argc, char** argv)
{
  const char* file_name = "demo.fsdb";
  const char* sig_name = "test.M1.a";
// call npi_init before using any APIs in the FSDB model
  npi_init(argc, argv);

// open the FSDB file named "demo.fsdb"
  npiFsdbFileHandle fp = npi_fsdb_open( file_name );
  if ( !fp ) {
    printf("Failed to open FSDB: %s.\n", file_name);
    return 1;
  }
  npiFsdbScopeHandle scope = NULL;
  npiFsdbFileHandle fpFromScope = NULL;
  npiFsdbFileHandle fpFromSig = NULL;

  npiFsdbSigHandle sig = npi_fsdb_sig_by_name( fp, sig_name, NULL);
  if ( sig ) {
    scope = npi_fsdb_sig_scope( sig );
    fpFromScope = npi_fsdb_scope_file( scope );
    fpFromSig = npi_fsdb_sig_file( sig );
    if ( fp != fpFromScope || fp != fpFromSig )
      printf("Error. Incorrect file handle from sig/scope.\n");
    printf("scope: %s\n", npi_fsdb_scope_property_str( npiFsdbScopeFullName, scope) );
    printf("sig: %s\n", npi_fsdb_sig_property_str( npiFsdbSigName, sig ) );
  }
  else
    printf("Failed to find sig: %s.\n", sig_name);

  // close the FSDB file
  npi_fsdb_close( fp );
  return 0;
}

