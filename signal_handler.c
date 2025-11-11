
/**
 * Modified by:Jaffar Mahkamov
 * 
 * CPE 2600 - 111
 * Lab 10 Signals
 * Brief summary of modifications:
 * This program registers a signal handler for SIGINT using the signal() system call.
 */


#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Signal handler for SIGINT - prints a message and exits
 */
void handle_signal() {
    printf("Received a signal\n");
}

int main() {

    // Register for the signal
    signal(SIGINT, handle_signal);

    // Wait until a signal is received
    while(1) {
        printf("Sleeping\n");
        sleep(1);
    }

    return 0;
}