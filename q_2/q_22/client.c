#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void main(int argc, char **argv) {
    if (argc != 4) {
        printf("You have to provide, pid of the server, what kind of signal to send and how many signals to send\n");
        return 0;
    }

    pid_t pid = atoi(argv[1]);
    int signalToSend = atoi(argv[2]);
    int AmountOfSignals = atoi(argv[3]);

    while(AmountOfSignals > 0) {
        if (kill(pid, signalToSend)) {
            printf("Kill has failed to send signal!\n");
        } else {
            printf("Kill succeefully sent signal!\n"); 
        }
        AmountOfSignals--;
    }

    return 0;
}