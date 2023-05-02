#include "npi_L1.h"

int main(int argc, char** argv)
{
  const char* const fsdbFileName = "demoL1.fsdb";
  const char* const sig1Name = "tb_CPUsystem.i_CPUsystem.i_CPU.i_CCU.MAselect"; 
  const char* const sig2Name = "tb_CPUsystem.i_CPUsystem.addr"; 
  const char* const sig3Name = "tb_CPUsystem.i_CPUsystem.i_CPU.i_CCU.MA"; 
  npiFsdbTime fsdbTime = 5000;

  npi_init(argc, argv);

  npiFsdbFileHandle fileHdl = npi_fsdb_open( fsdbFileName );
  if ( !fileHdl )
    return 1;

  npiFsdbSigHandle sig1 = npi_fsdb_sig_by_name( fileHdl, sig1Name, NULL); 
  npiFsdbSigHandle sig2 = npi_fsdb_sig_by_name( fileHdl, sig2Name, NULL); 
  npiFsdbSigHandle sig3 = npi_fsdb_sig_by_name( fileHdl, sig3Name, NULL);

  fsdbSigVec_t sigVec;
  sigVec.push_back( sig1 ); 
  sigVec.push_back( sig2 ); 
  sigVec.push_back( sig3 );

  fsdbValVec_t valueVec;

  if ( npi_fsdb_sig_hdl_vec_value_at( sigVec, fsdbTime, valueVec, npiFsdbBinStrVal ) ) {
    printf("%s is '%s' at time %-llu.\n", sig1Name, valueVec[0].c_str(), fsdbTime ); 
    printf("%s is '%s' at time %-llu.\n", sig2Name, valueVec[1].c_str(), fsdbTime ); 
    printf("%s is '%s' at time %-llu.\n", sig3Name, valueVec[2].c_str(), fsdbTime );
}

  npi_fsdb_close( fileHdl );
  npi_end();
  return 0;
}

