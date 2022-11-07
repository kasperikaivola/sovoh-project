#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <assert.h>
#include <time.h>

#include "morse.h"

static int sigpipe = 0;

//signal handler
static void sig_usr(int signo) {
    char ret = signo;
    //write the signal to pipe containing previous received signals
    write(sigpipe, &ret, 1);
}

int main(int argc, char **argv) {
    pid_t childPid;
    int ifd, ofd;
    ifd = atoi(argv[1]);
    ofd = atoi(argv[2]);

    childPid = fork();
    if (childPid == -1) {
        perror("<parent> Fork failed");
        return -1;
    }
    if (childPid == 0) {
        //Child process
        pid_t ppid = getppid();
        //this function reads the input char-by-char and calls function signalMorse to send the signals
        readMorse(ifd, ppid);
        close(ifd);
        close(ofd);
        exit(123);
    }
    else {
        //parent process
        struct sigaction sig;

        int pipefd[2];

        assert(pipe(pipefd) == 0);
        sigpipe = pipefd[1];
        sigemptyset(&sig.sa_mask);
        sig.sa_flags = 0;
        sig.sa_handler = sig_usr;
        assert((sigaction(SIGUSR1, &sig, NULL)) == 0);
        assert((sigaction(SIGUSR2, &sig, NULL)) == 0);
        assert((sigaction(SIGALRM, &sig, NULL)) == 0);
        assert((sigaction(SIGCHLD, &sig, NULL)) == 0);
        // init decoder
        struct MorseDecoder dec = initDecoder(ofd);
        nanosleep((const struct timespec[]){{0, 10000000L}}, NULL);
        kill(childPid, SIGUSR1);
        for (;;) {
            char received;
            //read 1 signal from pipe
            int res = read(pipefd[0], &received, 1);
            //When read is interrupted by a signal, it will return -1 and errno is EINTR.
            if (res == 1) {
                if (received == SIGUSR1) {
                    //printf("received SIGUSR1: %d\n", received);
                    //exit(123);
                    //break;
                    processMorse(&dec, received);
                } else if (received == SIGUSR2) {
                    //printf("received SIGUSR2\n");
                    //break;
                    processMorse(&dec, received);
                } else if (received == SIGALRM) {
                    processMorse(&dec, received);
                } else if (received == SIGCHLD) {
                    break;
                    //exit(0);
                }
                kill(childPid, SIGUSR1);
            }
        }
        close(pipefd[0]);
        close(pipefd[1]);
    }
}
