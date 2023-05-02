#include <stdio.h>
#include "npi.h"       // must have for NPI programs
#include "npi_fsdb.h"  // header for NPI FSDB model

int main(int argc, char** argv)
{
  npiFsdbTime minTime, maxTime;

// call npi_init before using any APIs in the FSDB model
  npi_init(argc, argv);

  // open the FSDB file named "demo.fsdb"
  npiFsdbFileHandle fp = npi_fsdb_open( "demo.fsdb" );
  if ( !fp ) {
    printf("Failed to open FSDB file.\n");
    return 1;
  }

  // get target signals and add to the signal list
  npiFsdbSigHandle sigA = npi_fsdb_sig_by_name( fp, "test.M1.A", NULL );
  if ( sigA ) {
    npi_fsdb_add_to_sig_list( fp, sigA );
}
else
  printf("Failed to find signal A.\n");

  npiFsdbSigHandle sigB = npi_fsdb_sig_by_name( fp, "test.M1.B", NULL );
  if ( sigB )  
    npi_fsdb_add_to_sig_list( fp, sigB);
else 
  printf("Failed to find signal B.\n");
  
  // load value changes of sigA and sigB between 1000 and 5000 into memory
  npi_fsdb_load_vc_by_range( fp, 10000, 50000);
  npi_fsdb_reset_sig_list( fp );
       
       npiFsdbTime currTime;
       npiFsdbVctHandle vctA = npi_fsdb_create_vct( sigA );
       
// find VC between time 20000 and 50000
       if ( npi_fsdb_goto_time( vctA, 50000 ) ) {
         while( npi_fsdb_goto_prev( vctA ) ) {
           npi_fsdb_vct_time( vctA, &currTime );
           if ( currTime >= 20000 )
             printf("Time %llu, sigA has VC\n", currTime);
           else
             break;
}
}

  // close the FSDB file
  npi_fsdb_close( fp );
  return 0;
}

