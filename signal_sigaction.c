/**
 * Modified by: Jaffar Mahkamov
 * CPE 2600 - 111
 * Lab 10 Signals
 *
 * Brief summary of program:
 * This program registers a signal handler for SIGUSR1 using the sigaction system call.
 * When the signal is received, the handler prints the process ID (PID) of the sender.
 * The program then waits indefinitely, allowing SIGUSR1 signals to be sent to it.
 *
 */

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>


void handle_sigusr1(int sig, siginfo_t *info, void *context) {
    (void)context;  // unused parameter
    printf("Received SIGUSR1 from process with PID: %d\n", info->si_pid);
}

int main() {
    struct sigaction sa;

    sigemptyset(&sa.sa_mask);
    sa.sa_flags =SA_SIGINFO;//enables additional signal info
    sa.sa_sigaction = handle_sigusr1;

    // Register the handler for SIGUSR1
    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    printf("Process running with PID: %d\n", getpid());
    printf("Waiting for SIGUSR1...\n");

    // Infinite loop waiting for signals
    while (1) {
        pause();  // Suspend until a signal is caught
    }

    return 0;
}
