#include "npi_L1.h"

int main(int argc, char** argv)
{
  const char* const fsdbFileName = "demoL1.fsdb";
  const char* const sigName = "tb_CPUsystem.i_CPUsystem.addr";
  npiFsdbTime fsdbTime = 5000;

  npi_init(argc, argv);

  npiFsdbFileHandle fileHdl = npi_fsdb_open( fsdbFileName );
  if ( !fileHdl )
    return 1;
  
  npiFsdbSigHandle sigHdl = npi_fsdb_sig_by_name( fileHdl, sigName, NULL );
  fsdbTimeValPair_t tvPair;

  if ( npi_fsdb_sig_hdl_find_x_backward( sigHdl, fsdbTime, tvPair ) )
    printf("%s is '%s' at time %-llu.\n", sigName, (tvPair.second).c_str(), tvPair.first );
  else
    printf("%s has no x when backward searching from %-llu.\n", sigName, fsdbTime );
  npi_fsdb_close( fileHdl );
  npi_end();
  return 0;
}
 

