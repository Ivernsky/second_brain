
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "npi.h"
#include "npi_L1.h"

using namespace std;

void abortCB(void* cbData)
{
  printf("Socket connection is broken...\n");
}

int main(int argc, char** argv)
{
  FILE* fp = fopen("demo.log", "w");
  if( !fp )
    return 0;
  
  npi_init(argc, argv);

  // 1. get free port
  int port = npi_socket_client_get_free_port();
  if( !npi_socket_client_is_port_free(port) ) {
    printf("Error. Fail to get a free port.\n");
    return 1;
  }

  // 2. invoke novas executable
  pid_t pid = fork();
  if( pid<0 ) {
    printf("Error. Fail to fork a process to invoke Novas.\n");
    return 1;
  }

  if(pid == 0) { //child process
    // the argument argc and argv will be the options of Novas executable 
    // to invoke Novas with a port, we need to run Novas by the commands below:
    //
    // novas -serverPort <free_port> <original_novas_load_design_options>
    int new_argc = argc + 3;
    char** new_argv = (char**) malloc(sizeof(char*)*new_argc);

    // set the argument : novas -serverPort <free_port>
    new_argv[0] = "novas";
    new_argv[1] = "-serverPort";

    static char buf[256];
    sprintf(buf, "%d", port);
    new_argv[2] = buf;

    // keep original novas load design options except argv[0], which is the executable name
    for(int i=1; i<argc; i++) {
      new_argv[2+i] = argv[i];
    }

    // final argument must be NULL
    new_argv[new_argc-1] = 0;

    // invoke novas with server port
    if( !execvp(new_argv[0], new_argv) ) {
      printf("Error. Fail to invoke Novas.\n");
    }
    return 1;
  }

  // 3. connect novas by npiSocketClient handle
  npiSocketClient socket_client_hdl = npi_socket_client_construct();
  if( !npi_socket_client_connect(socket_client_hdl, port, NULL/*Local host*/, 60/*timeout*/) ) {
    npi_socket_client_destroy(socket_client_hdl);
    printf("Error. Fail to connect Novas.\n");
    return 1;
  }

  char* err_msg;
  int is_conn = npi_socket_client_check_connect(socket_client_hdl, &err_msg);
  if( is_conn ) {
    printf("Novas is connected\n");
    fprintf(fp, "Novas is connected\n");
  }
  else {
    return 1;
  }

  //set the abort callback function if the connection is broken
  npi_socket_client_set_abort_callback(socket_client_hdl, abortCB, NULL/*cbData*/);

  // 4. call novas command by npiSocketClient handle
  //     assume the name of FSDB is "fulldump.fsdb", and locates in ./Design
  //     assume the FSDB contains the signal "/tb_CPUsystem/i_CPUsystem/i_CPU/i_ALUB/aluInA[7:0]"
  static char str[512];
  char* ret_str; //unused here

  // novas TCL command: load FSDB & create nWave window
  strcpy(str, "wvCreateWindow");
  npi_socket_client_call_command(socket_client_hdl, str, 1/*async*/, &ret_str);

  strcpy(str, "wvOpenFile -win $_nWave2 ./Design/fulldump.fsdb");
  npi_socket_client_call_command(socket_client_hdl, str, 1/*async*/, &ret_str);

  // novas TCL command: add signal to nWave
  strcpy(str, "wvAddSignal -win $_nWave2 \"/tb_CPUsystem/i_CPUsystem/i_CPU/i_ALUB/aluInA\\[7:0\\]\"");
  npi_socket_client_call_command(socket_client_hdl, str, 1/*async*/, &ret_str);

  // novas TCL command: close novas
  strcpy(str, "wvDumpAU -signal");
  npi_socket_client_call_command(socket_client_hdl, str, 1/*async*/, &ret_str);  

  // novas TCL command: close novas
  strcpy(str, "debExit");
  npi_socket_client_call_command(socket_client_hdl, str, 1/*async*/, &ret_str);  

  // 5. destroy npiSocketClient handle
  npi_socket_client_destroy(socket_client_hdl);

  npi_end();
  
  fclose(fp);
  return 0;
}


