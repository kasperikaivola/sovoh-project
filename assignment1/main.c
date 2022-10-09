#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>
#include "lib.h" //own library for simplified log functions etc.

int parentReceive = 0;

void parentSigHandler(int sig) {
    printf("Parent: Signal %d received\n", sig);
    if(sig == SIGUSR2) parentReceive = 33;
    else if(sig == SIGINT) {
      printf("Parent: Ctrl-C pressed, exiting...\n");
      exit(0);
    }
}

int main(int argc,char **argv) {
  signal(SIGUSR2,parentSigHandler);
  signal(SIGINT,parentSigHandler);
  FILE *fp;
  fp = fopen("parentlog.txt", "a");
  int pid = getpid(); //get current pid
  fprintf(fp, "Parent: Got current pid, %d\n", pid);
  printf("Parent: Got current pid, %d\n", pid);
  char input_str[100];
  pid_t childPid = fork(); //create child process
  char * pidchar = malloc(6);
  sprintf(pidchar, "%d", childPid);
  scanf("%s", input_str); //read input
  if(childPid<0) {
    perror("Couldn't create child process\n");
    exit(-1);
  }
  if(childPid>0) { //child process started
    //printf("Parent: Start child process...\n");
    //fprintf(fp, "Parent: child process started\n");
    char *args[]={"./child", pidchar, NULL};
    int exec = execvp(args[0],args); //replace child process execution
    if(exec == -1) {
      perror("Execvp failed\n");
      exit(-1);
    }
    //wait(NULL); //wait for child
  }
  //pause();
  printf("Parent: Got signal %d\n", parentReceive);
  kill(childPid, SIGUSR1);
  //wait(NULL);
  printf("Parent: child pid: %d\n",childPid);
  printf("Parent: Parent process after child started\n");
  fprintf(fp,"Parent: Parent process after child started\n");
  printf("Parent: input_str: %s\n", input_str);
  fprintf(fp,"Parent: input_str: %s\n", input_str);
  printf("Parent: Parent finished, exiting...\n");
  fprintf(fp, "Parent: Parent finished, exiting...\n");
  printf("Parent: Got signal %d\n",parentReceive);
  fprintf(fp, "Parent: Got signal %d\n",parentReceive);
  fclose(fp); //close log file
  free(pidchar);
  return 0;
}

