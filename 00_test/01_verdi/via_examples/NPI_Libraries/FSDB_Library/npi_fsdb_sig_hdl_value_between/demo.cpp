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
 
  npiFsdbSigHandle sig = npi_fsdb_sig_by_name( fileHdl, sigName, NULL);

  fsdbTimeValPairVec_t vcVec;

  printf("%s between %-llu ~ %-llu:\n", sigName, beginTime, endTime );
  if ( npi_fsdb_sig_hdl_value_between( sig, beginTime, endTime, vcVec, npiFsdbBinStrVal ) ) {
fsdbTimeValPairVec_t::iterator pos;
for ( pos = vcVec.begin() ; pos != vcVec.end() ; ++pos )
  printf("At time %-llu, value = '%s'\n", pos->first, (pos->second).c_str() );
}
  
npi_fsdb_close( fileHdl );
  npi_end();
  return 0;
}

