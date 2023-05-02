#include <stdio.h>
#include "npi.h"       // must have for NPI programs
#include "npi_fsdb.h"  // header for NPI FSDB model

void display_value_in_diff_format (npiFsdbVctHandle vch);

int main(int argc, char** argv)
{
// call npi_init before using any APIs in the FSDB model
  npi_init(argc, argv);

// open the FSDB file named "demo.fsdb"
  npiFsdbFileHandle fp = npi_fsdb_open( "demo.fsdb" );
  if ( !fp ) {
    printf("Failed to open FSDB file.\n");
    return 1;
  }

  // get signal handle by name 
  npiFsdbSigHandle sig = npi_fsdb_sig_by_name( fp, "test.M1.A", NULL);
  npiFsdbVctHandle vch = npi_fsdb_create_vct(sig);
  npi_fsdb_goto_time( vch, 10000 );
  
  // Reg1 declaration in Verilog: reg [3:0] Reg1;
// Reg1 value @ time 10: Reg1 = 4'b1111;
printf("==A==\n"); 
  display_value_in_diff_format( vch );

  sig = npi_fsdb_sig_by_name( fp, "test.M1.RS1", NULL);
  vch = npi_fsdb_create_vct(sig);
  npi_fsdb_goto_time( vch, 10000 );
  // RS1 declaration in Verilog: struct { real R; reg [3:0] B; } RS1;
  // RS1 value @ time 10: RS1 = '{ 12.34, 4'b01xx }; 
printf("==RS1==\n"); 
display_value_in_diff_format( vch );
 
  npi_fsdb_close( fp );
}

void display_value_in_diff_format (npiFsdbVctHandle vch) {
  npiFsdbValue val;
val.format = npiFsdbBinStrVal;
if ( npi_fsdb_vct_value( vch, &val ) )
printf("value in binary str: %s\n", val.value.str);
val.format = npiFsdbOctStrVal;
if ( npi_fsdb_vct_value( vch, &val ) )
printf("value in octal str: %s\n", val.value.str);
val.format = npiFsdbDecStrVal;
if ( npi_fsdb_vct_value( vch, &val ) )
printf("value in dec str: %s\n", val.value.str);
val.format = npiFsdbHexStrVal;
if ( npi_fsdb_vct_value( vch, &val ) )
printf("value in hex str: %s\n", val.value.str);
val.format = npiFsdbSintVal;
if ( npi_fsdb_vct_value( vch, &val ) )
printf("value in signed integer: %d\n", val.value.sint);
val.format = npiFsdbUintVal;
if ( npi_fsdb_vct_value( vch, &val ) )
printf("value in unsigned signed integer: %u\n", val.value.uint);
val.format = npiFsdbRealVal;
if ( npi_fsdb_vct_value( vch, &val ) )
printf("value in real: %E\n", val.value.real);
}

