/* ==========================================================================
 *       Filename:  demo.cpp
 *    Description:  
 *        Version:  1.0
 *        Created:  12/09/14 15:42:01 CST
 *       Revision:  none
 *        Company:  Synopsys, Inc.
 * ========================================================================== */

#ifndef  _DEMO_CPP_
#define  _DEMO_CPP_

#include <stdio.h>
#include <stdlib.h>
#include "npi.h"      // header for NPI
#include "npi_pw.h"   // header for NPI Power L0

extern "C" {
  extern int npi_pw_demo( int argc, char** argv );
}

void npi_pw_dump_obj( npiPwHandle hdl )
{
  printf( "%s", npi_pw_property_str( npiPwFullName, hdl ) );
  printf( "(%s)", npi_pw_property_str( npiPwType, hdl ) );
  printf( " at line %d\n", npi_pw_property( npiPwLineNo, hdl ) );
}

int npi_pw_demo( int argc, char** argv )
{
  // design top
  printf( "Design top: %s\n", npi_pw_design_top() );

  // get power domain by name
  npiPwHandle pdSrc = npi_pw_power_domain_by_name( "tb/PD_SRC" );
  npi_pw_dump_obj( pdSrc );

  // iterate supply nets
  npiPwIter iter = npi_pw_iter_start( npiPwSupplyNet, pdSrc );
  npiPwHandle net = NULL;

  while ( ( net = npi_pw_iter_next( iter ) ) != NULL )
    npi_pw_dump_obj( net );
  npi_pw_iter_stop( iter );

  // get supply set handle
  npiPwHandle isoHandle = npi_pw_handle( npiPwIsoSetHandle, pdSrc );
  npiPwHandle supplySet = npi_pw_handle( npiPwAssocSupplySet, isoHandle );
  npi_pw_dump_obj( supplySet );

  return 0;
}

#endif   /* ----- #ifndef _DEMO_CPP_  ----- */

