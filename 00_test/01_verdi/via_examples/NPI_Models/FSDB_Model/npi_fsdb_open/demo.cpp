#include <stdio.h>
#include "npi.h"       // must have for NPI programs
#include "npi_fsdb.h"  // header for NPI FSDB model

int main(int argc, char** argv)
{
  npiFsdbTime minTime, maxTime, currTime;

  // call npi_init before using any APIs in the FSDB model
  npi_init(argc, argv);

  // open the FSDB file named "demo.fsdb"
  npiFsdbFileHandle fp = npi_fsdb_open( "demo.fsdb" );
  if ( !fp ) {
    printf("Failed to open FSDB file.\n");
    return 1;
  }
  else { // print time information of the FSDB file
    npi_fsdb_min_time( fp, &minTime );
    npi_fsdb_max_time( fp, &maxTime );
    printf("Time range: %llu ~ %llu\n", minTime, maxTime );
    printf("Scale unit: %s\n", npi_fsdb_file_property_str( npiFsdbFileScaleUnit, fp) );
  }
  
  // close the FSDB file
  npi_fsdb_close( fp );
  return 0;
}

