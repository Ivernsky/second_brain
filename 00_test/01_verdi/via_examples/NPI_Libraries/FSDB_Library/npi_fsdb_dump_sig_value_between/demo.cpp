#include "npi_L1.h"

int main(int argc, char** argv)
{
  const char* const fsdbFileName = "demoL1.fsdb";
  const char* const sigName = "tb_CPUsystem.i_CPUsystem.i_CPU.i_CCU.MAselect";
  npiFsdbTime beginTime = 5000;
  npiFsdbTime endTime = 6000;

  npi_init(argc, argv);

  npiFsdbFileHandle fileHdl = npi_fsdb_open( fsdbFileName );
  if ( !fileHdl )
    return 1;

  FILE* fp = fopen("vc.txt", "w");
  if ( !fp )
    return 1;
  
  npi_fsdb_dump_sig_value_between( fileHdl, sigName, beginTime, endTime, fp, npiFsdbBinStrVal );
  
  if ( fp )
    fclose( fp );
npi_fsdb_close( fileHdl );
  npi_end();
  return 0;
}

