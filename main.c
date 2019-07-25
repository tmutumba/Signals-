//
// Created by Tonny Mutumba on 2019-06-17.
//

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>

void sighup(int signum);
void sigint(int signum);
void sigquit(int signum);
void handler(int signum);

int main(){
    pid_t cpid = fork();
    int exitStatus;

    struct sigaction action;

    action.sa_handler = handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = SA_RESTART;

    assert(sigaction(SIGUSR1, &action, NULL) ==0);

    /* get child process */
    if (cpid < 0) {
        perror("fork failed\n");
        exit(-1);
    }
    else if(cpid == 0){
        exitStatus = execl("./child", "child", NULL);
        //perror("Function excel() failed\n");
        exit(exitStatus);

        /*while(1); forever loop */
    } else{
        assert(waitpid(cpid, &exitStatus, 0) !=-1);
    }
    return 0;

}

void handler(int signum){

    if(signum == 2) {
        signal(SIGUSR1, sighup);
    }
}

void sighup(int signum){
    assert(printf("Signal# %d, sighup\n", signum) !=0);

    signal(SIGUSR1, sigint);
}

void sigint(int signum){
    assert(printf("Signal# %d,  sigint\n", signum) !=0);

    signal(SIGUSR1, sigquit);
}

void sigquit(signum){
    assert(printf("Signal# %d,  sigquit\n", signum) !=0);

    signal(SIGUSR1, SIG_DFL);
}
