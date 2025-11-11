/**
 * File: signal_alarm.c
 * Modified by: Jaffar Mahkamov
 * CPE 2600 - 111
 * Lab 10 Signals
 *
 * Brief summary of program:
 * This program demonstrates how the operating system can send a signal to a process
 * using the alarm() system call. The program sets a timer for 5 seconds, and when
 * the time expires, the OS sends a SIGALRM signal to the process. A signal handler
 * is installed to print a message when SIGALRM is received.
 */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

//signal handler for SIGALRM 
void handle_alarm(int sig){
    (void)sig; // unused parameter
    printf("Alarm signal received\n");
}

int main() {
    //register the signal handler for SIGALRM
    if (signal(SIGALRM, handle_alarm) == SIG_ERR){
        perror("signal");
        exit(EXIT_FAILURE);
    }

    printf("Setting alarm for 5 seconds...\n");
    alarm(5); //schedule the SIGALRM signal after 5 sec

    // Wait indefinitely 
    printf("Waiting...\n");
    pause(); 

    printf("Program closing\n");
    return 0;
}
