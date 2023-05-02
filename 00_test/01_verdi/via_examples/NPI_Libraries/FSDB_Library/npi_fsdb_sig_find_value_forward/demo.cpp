#include "npi_L1.h"

int main(int argc, char** argv)
{
  const char* const fsdbFileName = "demoL1.fsdb";
  const char* const sigName = "tb_CPUsystem.i_CPUsystem.addr";
  const char* const value = "22";
  npiFsdbTime fsdbTime = 5000;

  npi_init(argc, argv);

  npiFsdbFileHandle fileHdl = npi_fsdb_open( fsdbFileName );
  if ( !fileHdl )
    return 1;

  npiFsdbTime vcTime;

  if ( npi_fsdb_sig_find_value_forward( fileHdl, sigName, value, fsdbTime, vcTime, npiFsdbHexStrVal ) )
    printf("%s is '%s' at time %-llu.\n", sigName, value, vcTime );
  else
    printf("Failed to find %s when forward searching from %-llu.\n", value, fsdbTime );
  npi_fsdb_close( fileHdl );
  npi_end();
  return 0;
}

