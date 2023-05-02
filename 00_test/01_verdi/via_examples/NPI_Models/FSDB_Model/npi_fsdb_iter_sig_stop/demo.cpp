#include <stdio.h>
#include "npi.h"       // must have for NPI programs
#include "npi_fsdb.h"  // header for NPI FSDB model

void npi_trv_sub_sig( npiFsdbSigHandle sig);

int main(int argc, char** argv)
{ 
// call npi_init before using any APIs in the FSDB model
  npi_init(argc, argv);

// open the FSDB file named "demo.fsdb"
  npiFsdbFileHandle fp = npi_fsdb_open( "demo.fsdb" );
  if ( !fp ) {
    printf("Failed to open FSDB file.\n");
    return 1;
  }

  // get signal handle by name 
  // declaration in Verilog: reg [7:0] a [0:1][0:2];
  npiFsdbSigHandle sig = npi_fsdb_sig_by_name( fp, "test.M1.a", NULL);
  if ( !sig ) {
    printf("Failed to find sig.\n");
    return 1;
}
  npiFsdbScopeHandle scope = npi_fsdb_sig_scope( sig );
  printf("== scope: %s ==\n", npi_fsdb_scope_property_str(npiFsdbScopeFullName, scope) );
  printf("sig: %s\n", npi_fsdb_sig_property_str( npiFsdbSigName, sig ) );
  npi_trv_sub_sig( sig );
  
  // close the FSDB file
  npi_fsdb_close( fp );
  return 0;
}

void npi_trv_sub_sig( npiFsdbSigHandle sig) {
  npiFsdbSigHandle sub_sig;
  int hasMember = 0;
if ( npi_fsdb_sig_property( npiFsdbSigHasMember, sig, &hasMember) && hasMember == 1 ) {
     npiFsdbSigIter sig_iter = npi_fsdb_iter_member( sig );
     // only iterate 1 member signal
     if ( sub_sig = npi_fsdb_iter_sig_next( sig_iter ) ) {
       printf("sig: %s\n", npi_fsdb_sig_property_str( npiFsdbSigName, sub_sig ) );
       npi_trv_sub_sig( sub_sig );
     }
     // free signal iterator manually
     npi_fsdb_iter_sig_stop( sig_iter );
  }
}

