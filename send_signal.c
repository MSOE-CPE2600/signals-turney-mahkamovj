/**
 * File: send_signal.c
 * Modified by: Jaffar Mahkamov
 * CPE 2600 - 111
 * Lab 10 Signals
 * Brief summary of program:
 * This program takes the PID of a target process (receiver) as a command-line argument.
 * It generates a random integer, prints it, and sends it to the receiver process using
 * the sigqueue() system call along with the SIGUSR1 signal.
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    if (argc != 2){
        fprintf(stderr, "Usage: %s <receiver_pid>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    pid_t target_pid = atoi(argv[1]);
    union sigval value;

    //seed random number generator
    srand(time(NULL));
    value.sival_int = rand() % 100;//  random number 0 to 99

    printf("Sending SIGUSR1 to PID %d with value %d\n", target_pid, value.sival_int);

    //send the signal with data
    if (sigqueue(target_pid, SIGUSR1, value) == -1){
        perror("sigqueue");
        exit(EXIT_FAILURE);
    }

    printf("Signal sent\n");
    return 0;
}
