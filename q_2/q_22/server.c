#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int sigusr1 = 0;
int sigint = 0;

void handlerUsr1(int sig) {
    if (sig == SIGUSR1) {
        sigusr1++;
    }
}

void handlerInt(int sig) {
    if (sig == SIGINT) {
        sigint++;
    }
}

void main(int argc, char **argv) {
    if (signal(SIGUSR1, handlerUsr1)) {
        printf("Failed to set handler for SIGUSR1\n");
        return ;
    }
    if (signal(SIGINT, handlerInt)) {
        printf("Failed to set handler for SIGINT\n");
        return ;
    }
    printf("Server will wait until it receives signals, press any key to stop\n");
    getc(stdin);
    printf("%d signals of type SIGUSR1 sent\n", sigusr1);
    printf("%d signals of type SIGINT sent\n", sigint);
    return ;
}