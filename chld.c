#include <stdio.h>
#include <signal.h>
#include <assert.h>
#include <unistd.h>
#include <stdlib.h>


int main() {

    pid_t ppid = getppid();

    printf("\nPARENT: sending SIGHUP\n\n");
    kill(ppid, SIGUSR1);
    sleep (3);

    printf("\nPARENT: sending SIGINT\n\n");
    kill(ppid, SIGUSR1);
    sleep (3);

    printf("\nPARENT: sending SIGQUIT\n\n");
    kill(ppid, SIGUSR1);
    sleep (3);
}