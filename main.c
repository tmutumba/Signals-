#include <stdio.h>
#include <signal.h>
#include <assert.h>
#include <unistd.h>
#include <stdlib.h>

void handler(int signum){
    assert(printf("signal %d got it\n", signum) == 0);
}

int main() {
    
    struct sigaction action;

    int ppid = getppid();

    assert(printf("ok, i can't make it (%d)\n", ppid));

    action.sa_handler = handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = SA_RESTART;
    assert(sigaction(SIGUSR1, &action, NULL) == 0);

    printf("can't make it\n");
    return (0);

}