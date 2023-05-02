
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "npi.h"
#include "npi_L1.h"

using namespace std;

void eventCB(char* eventName, void* callbackData, char* callData)
{
  FILE* fp = (FILE*) callbackData;
  if( !fp )
    return;
  
  if( !callData ) 
    callData = "no calldata";
  printf("Event: \"%s\" - callData: \"%s\"\n", eventName, callData);
  fprintf(fp, "Event: \"%s\" - callData: \"%s\"\n", eventName, callData);
}

void eventCB2(char* eventName, void* callbackData, char* callData)
{
  FILE* fp = (FILE*) callbackData;
  if( !fp )
    return;
  
  if( !callData ) 
    callData = "no calldata";
  printf("Event2: \"%s\" - callData2: \"%s\"\n", eventName, callData);
  fprintf(fp, "Event2: \"%s\" - callData2: \"%s\"\n", eventName, callData);
}

int main(int argc, char** argv)
{
  FILE* fp = fopen("demo.log", "w");
  if( !fp ) {
    return 0;
  }
  
  npi_init(argc, argv);

  printf("======== DEMO NPI L1 : Communicate with Novas (BEGIN) ========\n");
  fprintf(fp, "======== DEMO NPI L1 : Communicate with Novas (BEGIN) ========\n");

  //
  // prepare novas executable and novas loading design options
  // in this example, invoke novas looks like (assume design files are under ./Design)
  //
  // novas -f run.f -path ./Design
  //
  char* novas_binary = "novas";
  int novas_argc = 4;
  char* novas_argv[] = {"-f", "run.f", "-path", "./Design"};

  // begin to communicate with novas
  npiCommNovasHandle novas_hdl = npi_communicate_novas_begin(novas_binary, novas_argc, novas_argv);
  printf("\nBegin to communicate with novas: novas -f run.f -path \"./Design\"\n");

  // check if novas is connected
  if( !npi_communicate_novas_is_connected(novas_hdl) ) {
    exit(0);
  }

  // add event callback
  npi_communicate_novas_add_event_callback(novas_hdl, (char*)"wvAddSignal", eventCB, (void*)fp/*cbData*/);
  npi_communicate_novas_add_event_callback(novas_hdl, (char*)"wvSelectSignal", eventCB2, (void*)fp/*cbData*/);

  static char str[512];

  // call novas command to create nWave window
  strcpy(str, "wvCreateWindow");
  printf("Call novas command: %s\n", str);
  npi_communicate_novas_call_command(novas_hdl, str);

  // call novas command to load FSDB
  strcpy(str, "wvOpenFile -win $_nWave2 ./Design/fulldump.fsdb");
  printf("Call novas command: %s\n", str);
  npi_communicate_novas_call_command(novas_hdl, str);

  // call novas command to add signals to nWave window
  strcpy(str, "wvAddSignal -win $_nWave2 \"/tb_CPUsystem/i_CPUsystem/i_CPU/i_ALUB/aluInB\\[7:0\\]\"");
  printf("Call novas command: %s\n", str);
  npi_communicate_novas_call_command(novas_hdl, str);

  strcpy(str, "wvAddSignal -win $_nWave2 \"/tb_CPUsystem/i_CPUsystem/i_CPU/i_ALUB/CarryMode\"");
  printf("Call novas command: %s\n", str);
  npi_communicate_novas_call_command(novas_hdl, str);

  // check events callback
  while(1) {
    usleep(200); //sleep 200ms
    npi_communicate_novas_check_for_events(novas_hdl);

    sleep(10);
    break;
  }

  // end of communicating with novas
  npi_communicate_novas_end(novas_hdl);

  printf("======== DEMO NPI L1 : Communicate with Novas (END) ========\n");
  fprintf(fp, "======== DEMO NPI L1 : Communicate with Novas (END) ========\n");
  npi_end();

  fclose(fp);
  return 0;
}


