#include "stdlib.h"
#include "npi.h"
#include "npi_dm.h"

int main (int argc, char **argv)
{
  npi_init( argc, argv );
  npi_load_design( argc, argv );

  // -- DM operation ---------------------------------------------------------
  npiDmHandle top = npi_dm_module_by_name( "top" );
  npiDmHandle T1  = npi_dm_handle_by_name( "T1", top );
  
  // typedef bit signed NT1;
  npiDmBasicDataType dt;
  dt.packed_dim = NULL;
  dt.signing    = npiDmSignSigned;
  dt.type       = npiDmDtBit;
  npiDmHandle NT1 = npi_dm_add_simple_typespec( top, "NT1", &dt, NULL );

  // typedef T1 NT2;
  dt.signing  = npiDmSignNone;
  dt.type     = npiDmDtTypespec;
  dt.typespec = T1;
  npiDmHandle NT2 = npi_dm_add_simple_typespec( top, "NT2", &dt, NULL );

  npi_dm_write_text_mode( "DM_LIB" );
  
  npi_end();
}

