/*
 * Filename: send_signal.c
 * Description: Sends SIGUSR1 to the given PID along with a random integer.
 * Author: Drew Malone <malone@msoe.edu>
 * Created: 11/10/25
 * Compile: make send_signal
 */

#include "send_signal.h"

int main(int argc, char *argv[])
{
    // parse inputs
    if (argc != 2) {
        printf("\e[31mERROR:\e[0m Input must be exactly 1 argument.\n");
        exit(EXIT_FAILURE);
    }
    pid_t pid = atoi(argv[1]);
    if (pid == 0) {
        printf("\e[31mERROR:\e[0m Error parsing PID. (sending a signal to PID 0 is not supported)\n");
        exit(EXIT_FAILURE);
    }

    // seed the random number generator
    srand(time(NULL));
    int num = rand();
    printf("Sending number %d...\n", num);

    // send signal
    union sigval val = {0};
    val.sival_int = num;
    sigqueue(pid, SIGUSR1, val);

    return EXIT_SUCCESS;
}
