//
// Created by kaspe on 15.10.2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#define BLOCKSIZE 4096
int waitForChild = 1;
void sigHandler(int sig) {
    if(sig == SIGUSR1) {
        printf("Parent: Child sent SIGUSR1\n");
        waitForChild=0;
    }
    else if(sig == SIGUSR2) {
        printf("Parent: Child sent SIGUSR2\n");
        waitForChild=0;
    }
}

int main(int argc,char **argv) {
    signal(SIGUSR1,sigHandler);
    signal(SIGUSR2,sigHandler);
    int ifd, ofd;

    // Quick and dirty command line parsing
    if (argc == 2) { // Only input file, output stdout
        ofd = STDOUT_FILENO;
        if (strcmp(argv[1],"-") == 0) {
            ifd = STDIN_FILENO;
        } else {
            ifd = open(argv[1],O_RDONLY);
            if (ifd < 0) {
                fprintf(stderr,"Opening input file failed\n");
                return -1;
            }
        }
    }

    else if (argc == 3) { // Both input and output file given
        if (strcmp(argv[1],"-") == 0) {
            ifd = STDIN_FILENO;
        } else {
            ifd = open(argv[1],O_RDONLY);
            if (ifd < 0) {
                fprintf(stderr,"Opening input file failed\n");
                return -1;
            }
        }
        if (strcmp(argv[2],"-") == 0) {
            ofd = STDOUT_FILENO;
        } else {
            ofd = open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,0666);
            if (ofd < 0) {
                fprintf(stderr,"Creating output file failed\n");
                return -1;
            }
        }
    } else {
        fprintf(stderr,"Usage: %s [input|-] [output|-]\n",argv[0]);
        return -1;
    }
    //Create child process
    printf("Parent: pid=%d\n",getpid());
    sleep(1);
    pid_t childPid = fork();
    sleep(1);
    if(childPid<0) {
        perror("Couldn't create child process\n");
        exit(-1);
    }
    if(childPid>0) { //child process started
        char *args[]={"./Assignment1-child", "output-child.txt", NULL};
        int exec = execvp(args[0],args); //replace child process execution
        if(exec == -1) {
            perror("Execvp failed\n");
            exit(-1);
        }
    }

    // Allocate buffer
    char *buf = malloc(BLOCKSIZE);
    if (buf == NULL) return -1;
    while (1) {
        int s;
        s = read(ifd,buf,BLOCKSIZE); //read next BLOCKSIZE amount of data
        if (s < 0) return -1;
        if (s == 0) break; // input closed
        int r = 0;
        //sleep(1);
        /*while (r < s) {
            int t = write(ofd,buf+r,s-r);
            kill(childPid,SIGUSR1);
            while(waitForChild);
            printf("Parent: Got confirmation\n");
            //sleep(1);
            if (t < 0) {
                return -1;
            }
            r += t;
        }*/
        for(int i=0;buf[i];i++) {
            kill(childPid,SIGUSR1);
            while(waitForChild);
            waitForChild=0;
        }
    }
    printf("Parent: done\n");
    kill(childPid,SIGINT);
    free(buf);
    close(ifd);
    close(ofd);

    return 0;
}
