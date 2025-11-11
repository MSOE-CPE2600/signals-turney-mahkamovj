
/**
 * File: signal_segfault.c
 * Modified by: Jaffar Mahkamov
 * CPE 2600 - 111
 * Lab 10 Signals
 * 
 * Brief summary of modifications:
 * Added signal handling for segmentation faults.
 */


#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handle_sigsegv(){
    printf("Caught segmentation fault\n");
    
}

int main (int argc, char* argv[]) {

    // Register signal handler for segmentation fault
    signal(SIGSEGV, handle_sigsegv);
    // Declare a null pointer
    int* i = NULL;

    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);

    // Return to exit the program
    return 0;
}