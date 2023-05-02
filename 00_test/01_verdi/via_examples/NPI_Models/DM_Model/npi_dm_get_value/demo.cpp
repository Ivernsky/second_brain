#include "stdio.h"
#include "npi.h"
#include "npi_dm.h"

void print_const_value( const npiDmHandle constHdl );

int main( int argc, char** argv ) {
  if ( !npi_init( argc, argv ) )
    return 1;
  if ( !npi_load_design( argc, argv ) )
    return 1;

  npiDmHandle mod = npi_dm_module_by_name( "test" );
  if ( mod ) {
    npiDmIter iter = npi_dm_iter_start( npiDmParameter, mod );
    npiDmHandle var;
    while( var = npi_dm_iter_next( iter ) ) {
      npiDmHandle rightExpr = npi_dm_handle( npiDmExpr, var );
      if ( rightExpr ) {
        printf("%-15s ", npi_dm_property_str( npiDmName, var ) );
        print_const_value( rightExpr );
      }
    }
  }
  return 0;
}

void print_const_value( const npiDmHandle constHdl ) {
  int dmType = npi_dm_property( npiDmType, constHdl );
  if ( npiDmConstant != dmType ) {// not a constant object
    printf("is not a pure const value on the right-hand side.\n");
    return;
  }
  int constType = npi_dm_property( npiDmConstType, constHdl );
  static npiDmValue value;
  switch( constType ) {
    case npiDmConstDec:
      value.format = npiDmDecStrVal;
      if ( npi_dm_get_value( constHdl, &value ) )
        printf("%s (DecStr).", value.value.str );
      break;
    case npiDmConstReal:
      value.format = npiDmRealVal;
      if ( npi_dm_get_value( constHdl, &value ) )
        printf("%E (Real).", value.value.real );
      break;
    case npiDmConstBin:
      value.format = npiDmBinStrVal;
      if ( npi_dm_get_value( constHdl, &value ) )
        printf("%s (BinStr).", value.value.str );
      break;
    case npiDmConstOct:
      value.format = npiDmOctStrVal;
      if ( npi_dm_get_value( constHdl, &value ) )
        printf("%s (OctStr).", value.value.str );
      break;
    case npiDmConstHex:
      value.format = npiDmHexStrVal;
      if ( npi_dm_get_value( constHdl, &value ) )
        printf("%s (HexStr).", value.value.str );
      break;
    case npiDmConstInt:
      value.format = npiDmIntVal;
      if ( npi_dm_get_value( constHdl, &value ) )
        printf("%d (Int).", value.value.integer );
      break;
    case npiDmConstUnbounded:
      value.format = npiDmBinStrVal;
      if ( npi_dm_get_value( constHdl, &value ) )
        printf("'%s (Unbounded).", value.value.str );
      break;
    case npiDmConstString:
      value.format = npiDmStringVal;
      if ( npi_dm_get_value( constHdl, &value ) )
        printf("\"%s\" (String).", value.value.str );
      break;
    Default:
      printf("[unsupport type.]");
  }
  printf("\n");
}
