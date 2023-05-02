#include "stdio.h"
#include "npi.h"
#include "npi_fsdb.h"
#include <string>
#include <list>

using namespace std;

class vc_elm_t {
  public:
    vc_elm_t( const char* sigName, npiFsdbTime vctTime, npiFsdbSeqNum seqNum, const char* val ):
    m_sigName( sigName ),
    m_vctTime( vctTime ),
    m_seqNum( seqNum ), 
    m_vctVal( val )
    {}
    npiFsdbTime get_vct_time() const { return m_vctTime; }
    npiFsdbTime get_seq_num() const { return m_seqNum; }
    void show_vc();
    friend bool operator<( const vc_elm_t &elm1, const vc_elm_t &elm2 );
  
  private:
    const char*      m_sigName;
    npiFsdbTime      m_vctTime;
    npiFsdbSeqNum    m_seqNum;
    string           m_vctVal;
};

void vc_elm_t::show_vc() {
  printf("%s change to %s at time %-llu (seqNum:%-d)\n", m_sigName, m_vctVal.c_str(), m_vctTime, m_seqNum );
}

bool operator<( const vc_elm_t &elm1, const vc_elm_t &elm2 ) {
  if ( elm1.get_vct_time() < elm2.get_vct_time() )
    return true;
  else if ( elm1.get_vct_time() == elm2.get_vct_time() ) {
    if ( elm1.get_seq_num() < elm2.get_seq_num() )
      return true;
    else
      return false;
  }
  else
    return false;
}

bool compare_seq ( vc_elm_t elm1, vc_elm_t elm2 ) {
  if ( elm1 < elm2 )
    return true;
  else
    return false;
}

void record_vc( const char* sigName, npiFsdbVctHandle vct, list<vc_elm_t> &vcList ) {
  if ( !vct )
    return;
  npiFsdbTime time;
  if ( !npi_fsdb_vct_time( vct, &time ) )
    return;
  npiFsdbSeqNum seqNum;
  if ( !npi_fsdb_vct_seq_num( vct, &seqNum ) )
    return;
  npiFsdbValue val;
  val.format = npiFsdbBinStrVal;
  if ( !npi_fsdb_vct_value( vct, &val ) )
    return;
  vc_elm_t vcElm( sigName, time, seqNum, val.value.str );
  vcList.push_back( vcElm );
}

void record_vc_for_sig( npiFsdbFileHandle file, const char* sigName, list<vc_elm_t> &vcList ) {
  if ( !file || !sigName )
    return;
  npiFsdbSigHandle sig = npi_fsdb_sig_by_name( file, sigName, NULL );
  if ( !sig )
    return;
  npiFsdbVctHandle vct = npi_fsdb_create_vct( sig );
  if ( !vct )
    return;
  if ( !npi_fsdb_goto_first( vct ) )
    return;
  record_vc( sigName, vct, vcList );
  while ( npi_fsdb_goto_next( vct ) )
    record_vc( sigName, vct, vcList );
  npi_fsdb_release_vct( vct );
}

int main(int argc, char** argv)
{
  const char* file_name = "demo.fsdb";
  const char* sig_name_A = "test.clk";
  const char* sig_name_B = "test.D";
  const char* sig_name_C = "test.Q";
  // call npi_init before using any APIs in the FSDB model
  npi_init(argc, argv);

  // open the FSDB file named "demo.fsdb"
  npiFsdbFileHandle fp = npi_fsdb_open( file_name );
  if ( !fp ) {
    printf("Failed to open FSDB: %s.\n", file_name);
    return 1;
  }

  int hasSeqNum;
  if ( npi_fsdb_file_property( npiFsdbFileHasSeqNum, fp, &hasSeqNum ) ) {
    printf("Has Seq Num? %d\n", hasSeqNum);
  }
  else {
    printf("Failed to get seq num property from file\n");
  }

  list<vc_elm_t> vcList;
  record_vc_for_sig( fp, sig_name_A, vcList );
  record_vc_for_sig( fp, sig_name_B, vcList );
  record_vc_for_sig( fp, sig_name_C, vcList );
  vcList.sort( compare_seq );
  list<vc_elm_t>::iterator it;
  for ( it = vcList.begin() ; it != vcList.end(); ++it )
    it->show_vc();
  npi_fsdb_close( fp );
  return 0;
}

