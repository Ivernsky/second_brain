#include "npi_L1.h"

int main(int argc, char** argv)
{
  const char* const fsdbFileName = "demoL1.fsdb";
  string sig1Name = "tb_CPUsystem.i_CPUsystem.i_CPU.i_CCU.MAselect"; 
  string sig2Name = "tb_CPUsystem.i_CPUsystem.addr"; 
  string sig3Name = "tb_CPUsystem.i_CPUsystem.i_CPU.i_CCU.MA"; 

  fsdbSigNameVec_t sigNameVec;
  sigNameVec.push_back( sig1Name ); 
  sigNameVec.push_back( sig2Name ); 
  sigNameVec.push_back( sig3Name );

  npiFsdbTime fsdbTime = 5000;

  npi_init(argc, argv);

  npiFsdbFileHandle fileHdl = npi_fsdb_open( fsdbFileName );
  if ( !fileHdl )
    return 1;

  fsdbValVec_t valueVec;

  if ( npi_fsdb_sig_vec_value_at( fileHdl, sigNameVec, fsdbTime, valueVec, npiFsdbBinStrVal ) ) {
    unsigned int i;
    for ( i = 0 ; i < 3 ; ++i )
      printf("%s is '%s' at time %-llu.\n", sigNameVec[i].c_str(), valueVec[i].c_str(), fsdbTime );
}
  npi_fsdb_close( fileHdl );
  npi_end();
  return 0;
}

