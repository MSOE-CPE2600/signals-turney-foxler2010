/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault
 * 
 * Compile with: make signal_segfault
 */

/**
 * Modified by: Drew Malone
 * 
 * Brief summary of modifications:
 * Created signal handler for SIGSEGV
 * 
 * This program is actually an infinite loop, as when the signal handler is done,
 * execution resumes by re-running the statement that initially generated the SIGSEGV signal.
 * Since nothing changes to prevent a segmentation fault from happening again, the same condition is
 * created over and over.
 */

#include "signal_segfault.h"

int main (int argc, char* argv[]) {
    // Create signal handler for SIGSEGV
    struct sigaction act = {0};
    act.sa_handler = sigsegv_handler;
    sigaction(SIGSEGV, &act, NULL);

    // Declare a null pointer
    int* i = NULL;

    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);

    printf("Finished printing i.\n");

    // Return to exit the program
    return 0;
}

void sigsegv_handler(int signum)
{
    printf("\e[31mERROR:\e[0m Segmentation fault was caught!\n");
}
