#include "npi_L1.h"
 
int main(int argc, char** argv)
{
  const char* const fsdbFileName = "demoL1.fsdb";

  npi_init(argc, argv);
  
  npiFsdbFileHandle fileHdl = npi_fsdb_open( fsdbFileName );
  if ( !fileHdl )
    return 1; 
  
  const char* timeUnit = npi_fsdb_time_scale_unit( fileHdl );
  printf("Time scale of '%s' = '%s'\n", fsdbFileName, timeUnit);

  npi_fsdb_close( fileHdl );
  npi_end();
  return 0;
}
 
