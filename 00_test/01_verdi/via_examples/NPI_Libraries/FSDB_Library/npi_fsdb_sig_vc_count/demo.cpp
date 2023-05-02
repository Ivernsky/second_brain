#include "npi_L1.h"

int main(int argc, char** argv)
{
  const char* const fsdbFileName = "demoL1.fsdb";
  const char* const sigName = "tb_CPUsystem.i_CPUsystem.addr";
  npiFsdbTime beginTime = 5000;
  npiFsdbTime endTime = 6000;

  npi_init(argc, argv);

  npiFsdbFileHandle fileHdl = npi_fsdb_open( fsdbFileName );
  if ( !fileHdl )
    return 1;
   
  signed long long vcCount;
  

  if ( -1 != ( vcCount = npi_fsdb_sig_vc_count( fileHdl, sigName, beginTime, endTime ) ) )
    printf("%s has '%-lld' value changes between %-llu ~ %-llu.\n", sigName, vcCount, beginTime, endTime );

  npi_fsdb_close( fileHdl );
  npi_end();
  return 0;
}

