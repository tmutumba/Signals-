#include <stdio.h>
#include <signal.h>
#include <assert.h>
#include <unistd.h>
#include <stdlib.h>


int main() {

    pid_t ppid = getppid();

    printf("\nPARENT: sending SIGHUP\n\n");
    assert(kill(ppid, SIGUSR1) != -1);
    sleep (3);

    printf("\nPARENT: sending SIGINT\n\n");
    assert(kill(ppid, SIGUSR1) != -1);
    sleep (3);

    printf("\nPARENT: sending SIGQUIT\n\n");
    assert(kill(ppid, SIGUSR1) != -1);
    sleep (3);

    return (0);
}