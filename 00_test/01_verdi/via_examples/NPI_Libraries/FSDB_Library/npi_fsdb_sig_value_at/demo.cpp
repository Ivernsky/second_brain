#include "npi_L1.h"

int main(int argc, char** argv)
{
  const char* const fsdbFileName = "demoL1.fsdb";
  const char* const sigName = "tb_CPUsystem.i_CPUsystem.i_CPU.i_CCU.MAselect";
  npiFsdbTime fsdbTime = 5000;

  npi_init(argc, argv);

  npiFsdbFileHandle fileHdl = npi_fsdb_open( fsdbFileName );
  if ( !fileHdl )
    return 1;

  string value;

  if ( npi_fsdb_sig_value_at( fileHdl, sigName, fsdbTime, value, npiFsdbBinStrVal ) )
    printf("%s is '%s' at time %-llu.\n", sigName, value.c_str(), fsdbTime );
  npi_fsdb_close( fileHdl );
  npi_end();
  return 0;
}

