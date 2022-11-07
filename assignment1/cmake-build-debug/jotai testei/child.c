//
// Created by kaspe on 15.10.2022.
//
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <string.h>
int transmissionDone = 0;
char* ret = "asf";
void sigHandler(int sig) {
    if(sig == SIGUSR1) {
        //signal(sig,SIG_IGN);
        //strcat(ret,"-");
        printf("Child: - received\n");
        kill(getppid(),SIGUSR1);
    }
    else if(sig == SIGUSR2) {
        //signal(sig,SIG_IGN);
        //strcat(ret,".");
        printf("Child: . received\n");
        kill(getppid(),SIGUSR1);;
    }
    else if(sig == SIGINT) transmissionDone=1;
}

int main(int argc,char **argv) {
    signal(SIGUSR1,sigHandler);
    signal(SIGUSR2,sigHandler);
    signal(SIGINT,sigHandler);
    printf("Child: pid=%d\n",getpid());
    //sleep(1);
    int ofd;
    ofd = open(argv[1],O_WRONLY|O_CREAT|O_TRUNC,0666);
    if (ofd < 0) {
        fprintf(stderr,"Creating output file failed\n");
        return -1;
    }
    while(!transmissionDone);
    sleep(1);
    printf("Cool: \n");
    printf("Child: Transmission done\n");
    return 0;
}
