#include "stdlib.h"
#include "npi.h"
#include "npi_dm.h"

int main (int argc, char **argv)
{
  npi_init( argc, argv );
  npi_load_design( argc, argv );

  // -- DM operation ---------------------------------------------------------
  npiDmHandle top = npi_dm_module_by_name( "top" );

  // Add union typespec
  npiDmHandle UT  = npi_dm_add_union_typespec( top, "UT", 1, npiDmSignSigned, NULL, NULL );
  
  npiDmBasicDataType dt;
  dt.packed_dim = NULL;
  dt.signing    = npiDmSignNone;
  dt.type       = npiDmDtBit;

  // Add union member
  npi_dm_add_su_member( UT, "a", &dt, NULL );
  npi_dm_add_su_member( UT, "b", &dt, NULL );

  npi_dm_write_text_mode( "DM_LIB" );
  
  npi_end();
}

