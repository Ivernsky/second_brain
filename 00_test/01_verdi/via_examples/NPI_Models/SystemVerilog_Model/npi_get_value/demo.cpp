#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
#include "npi.h"
#include "npi_hdl.h"
#define MAX_STRING_LENGTH 1024
 
// ----------------------------------------------------------------------
char* get_and_print_value(const npiHandle hdl, const NPI_INT32 const_type)
{
  static npiValue value;
  static NPI_BYTE8 value_str[MAX_STRING_LENGTH], sign_str[MAX_STRING_LENGTH];
  static NPI_INT32 size = npi_get(npiSize, hdl);
  if(npi_get(npiSigned, hdl)==1)
    sign_str[0] = 's';
 
  switch(const_type) {
    case npiDecConst:
      value.format = npiDecStrVal;
      npi_get_value(hdl, value);
      snprintf(value_str, MAX_STRING_LENGTH-1, "%d'%sd%s", size, sign_str, value.value.str);
      break;
    case npiRealConst:
      value.format = npiRealVal;
      npi_get_value(hdl, value);
      snprintf(value_str, MAX_STRING_LENGTH-1, "%f", value.value.real);
      break;
    case npiBinaryConst:
      value.format = npiBinStrVal;
      npi_get_value(hdl, value);
      snprintf(value_str, MAX_STRING_LENGTH-1, "%d'%sb%s", size, sign_str, value.value.str);
      break;
    case npiOctConst:
      value.format = npiOctStrVal;
      npi_get_value(hdl, value);
      snprintf(value_str, MAX_STRING_LENGTH-1, "%d'%so%s", size, sign_str, value.value.str);
      break;
    case npiHexConst:
      value.format = npiHexStrVal;
      npi_get_value(hdl, value);
      snprintf(value_str, MAX_STRING_LENGTH-1, "%d'%sh%s", size, sign_str, value.value.str);
      break;
    case npiStringConst:
      value.format = npiStringVal;
      npi_get_value(hdl, value);
      snprintf(value_str, MAX_STRING_LENGTH-1, "\"%s\"", value.value.str);
      break;
    case npiIntConst:
    default:
      value.format = npiIntVal;
      npi_get_value(hdl, value);
      snprintf(value_str, MAX_STRING_LENGTH-1, "%d", value.value.integer);
      break;
  }
  return value_str;
}
// ----------------------------------------------------------------------
int main (int argc, char **argv)
{
  npi_init(argc , argv );
  npi_load_design( argc, argv );
 
  NPI_BYTE8 hdl_name[MAX_STRING_LENGTH], value_str[MAX_STRING_LENGTH];
 
  npiHandle top_hdl = npi_handle_by_name("top", NULL );
  npiHandle param_itr = npi_iterate(npiParameter, top_hdl);
  npiHandle param_hdl = NULL, const_hdl = NULL;
 
  while((param_hdl = npi_scan(param_itr))) {
    const_hdl = npi_handle(npiExpr, param_hdl);
    snprintf(value_str, MAX_STRING_LENGTH-1, "%s", get_and_print_value(param_hdl, npi_get(npiConstType, const_hdl)));
    snprintf(hdl_name,  MAX_STRING_LENGTH-1, "%s", npi_get_str(npiName, param_hdl));
    printf("  %-15s = %s\n",  hdl_name, value_str);
  }
 
  npi_end();
 
  return 0;
}
