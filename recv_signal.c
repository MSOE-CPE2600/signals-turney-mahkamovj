/**
 * File: recv_signal.c
 * Modified by: Jaffar Mahkamov
 * CPE 2600 - 111
 * Lab 10 Signals
 *
 * Brief summary of program:
 * This program installs a SIGUSR1 handler using sigaction with SA_SIGINFO enabled.
 * When a signal is received, it prints the sending process’s PID and the integer value
 * sent along with the signal using sigqueue from another program.
 */

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

//signal handler for SIGUSR1 that prints sender PID and sent integer value
void handle_sigusr1(int sig, siginfo_t *info, void *context){
    (void)sig;
    (void)context;

    printf("\nreceived SIGUSR1 from PID: %d\n", info->si_pid);
    printf("received value: %d\n", info->si_value.sival_int);
}

int main(){
    struct sigaction sa;

    // Set up sigaction struct
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = handle_sigusr1;

    //register handler
    if (sigaction(SIGUSR1, &sa, NULL) == -1){
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    printf("Receiver running with PID: %d\n", getpid());
    printf("Waiting for SIGUSR1 with data...\n");

    // Wait  for signals
    while (1){
        pause();
    }

    return 0;
}
