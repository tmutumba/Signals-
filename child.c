//
// Created by Tonny Mutumba on 2019-06-17.
//

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void sighup();
void sigint();
void sigquit();

int main(){
    pid_t cpid;
    pid_t ppid;

    /* get child process */
    if ((cpid = fork()) < 0){
        perror("fork");
        exit(1);
    }

    if (cpid == 0){

        while(1); /* forever loop */
    }

    else{
        /* parent */

        signal(SIGUSR1, sighup);

        ppid = getppid();

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
}

void sighup(){
    printf("Are you coming to pick me up!\n");

    signal(SIGUSR1, sigint);
}

void sigint(){
    printf("Please answer me!\n");

    signal(SIGUSR1, sigquit);
}

void sigquit(){
    printf("Thank you for nothing.\n");

    signal(SIGUSR1, SIG_DFL);
}
