/*
 * Filename: recv_signal.c
 * Description: Signal reciever that prints out the integer sent with the signal.
 * Author: Drew Malone <malonea@msoe.edu>
 * Created: 11/10/25
 * Compile with: make recv_signal
 */

#include "recv_signal.h"

int main(int argc, char *argv[])
{
    struct sigaction act = {0};
    act.sa_flags = SA_SIGINFO;
    act.sa_sigaction = sigusr1_handler;
    sigaction(SIGUSR1, &act, NULL);

    while (1) {
        // wait for SIGUSR1 signal
        // it is sent by the send_signal program (source is send_signal.c)
    }

    return EXIT_FAILURE;
}

void sigusr1_handler(int sig, siginfo_t *info, void *ucontext)
{
    printf("SIGUSR1 recieved from PID %d.\n", info->si_pid);
    printf("The number sent with the signal is %d.\n", info->si_value.sival_int);
    exit(EXIT_SUCCESS);
}
