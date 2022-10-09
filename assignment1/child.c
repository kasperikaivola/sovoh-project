#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>
#include "lib.h"

int childReceive = 0;

void childSigHandler(int sig) {
    printf("Child: Signal %d received\n",sig);
    if(sig == SIGUSR1) childReceive = 66;
    else if(sig == SIGINT) {
      printf("Child: Ctrl-C pressed, exiting...\n");
      exit(0);
    }
}

int main(int argc,char **argv) {
    signal(SIGUSR1,childSigHandler);
    signal(SIGINT,childSigHandler);
    FILE *fp;
    fp = fopen("childlog.txt", "a");
    pid_t pid = getpid(); //get current pid
    printf("Child: Hello from child process execvp, pid: %d\n",pid);
    fprintf(fp,"Child: Hello from child process execvp, pid: %d\n",pid);
    int parentPID = atoi(argv[1]);
    printf("Child: parentPID: %d\n", parentPID);
    kill(parentPID, SIGUSR2);
    //wait(NULL);
    pause();
    printf("Child: Got signal %d\n", childReceive);
    fprintf(fp,"Child: Got signal %d\n", childReceive);
    printf("Child: Child finished, exiting...\n");
    fprintf(fp,"Child: Child finished, exiting...\n");
    fclose(fp); //close log file
    return 0;
}
