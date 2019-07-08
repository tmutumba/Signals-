//
// Created by Tonny Mutumba on 2019-06-17.
//

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>

void sighup();
void sigint();
void sigquit();
void handler(int signum);

int main(){
    pid_t cpid;

    struct sigaction action;

    action.sa_handler = handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = SA_RESTART;

    /* get child process */
    if ((cpid = fork()) < 0){
        perror("fork failed\n");
        exit(1);
    }
    else if(cpid == 0){

        while(1); /* forever loop */
    }
    return 0;

}

void handler(int signum){

    if(signum == 2) {
        signal(SIGUSR1, sighup);
    }
}

void sighup(){
    assert(printf("Will you be here!\n") !=0);

    signal(SIGUSR1, sigint);
}

void sigint(){
    assert(printf("Soon!\n") !=0);

    signal(SIGUSR1, sigquit);
}

void sigquit(){
    assert(printf("Thank you.\n") !=0);

    signal(SIGUSR1, SIG_DFL);
}
