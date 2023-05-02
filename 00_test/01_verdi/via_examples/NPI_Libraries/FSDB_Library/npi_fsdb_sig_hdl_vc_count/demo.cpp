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
  
  npiFsdbSigHandle sig = npi_fsdb_sig_by_name( fileHdl, sigName, NULL );
  signed long long vcCount;
  

  if ( -1 != ( vcCount = npi_fsdb_sig_hdl_vc_count( sig, beginTime, endTime ) ) )
    printf("%s has '%-lld' value changes between %-llu ~ %-llu.\n", sigName, vcCount, beginTime, endTime );

  npi_fsdb_close( fileHdl );
  npi_end();
  return 0;
}

