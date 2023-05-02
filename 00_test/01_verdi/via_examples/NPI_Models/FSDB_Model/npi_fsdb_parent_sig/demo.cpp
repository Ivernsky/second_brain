#include <stdio.h>
#include "npi.h"       // must have for NPI programs
#include "npi_fsdb.h"  // header for NPI FSDB model

int main(int argc, char** argv)
{  
  const char* file_name = "demo.fsdb";
  const char* sig_name = "test.M1.a[0][0][0]";
// call npi_init before using any APIs in the FSDB model
  npi_init(argc, argv);

  // open the FSDB file named "demo.fsdb"
  npiFsdbFileHandle fp = npi_fsdb_open( file_name );
  if ( !fp ) {
    printf("Failed to open FSDB: %s.\n", file_name);
    return 1;
  }

  npiFsdbSigHandle sig = npi_fsdb_sig_by_name( fp, sig_name, NULL);
  if ( sig ) {
printf("sig:       %s\n", npi_fsdb_sig_property_str( npiFsdbSigName, sig ) );
while ( sig = npi_fsdb_parent_sig( sig ) )
  printf("parent sig:%s\n", npi_fsdb_sig_property_str( npiFsdbSigName, sig ) );
}
else {
  printf("Failed to find sig: %s.\n", sig_name);
} 

  // close the FSDB file
  npi_fsdb_close( fp );
  npi_end();
  return 0;
}

