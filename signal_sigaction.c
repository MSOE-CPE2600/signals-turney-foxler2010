/*
 * Filename: signal_sigaction.c
 * Description: Demo of sigaction() system call,
 *              and getting info from signals
 * Author: Drew Malone <malonea@msoe.edu>
 * Created: 11/10/25
 * Compile with: make signal_sigaction
 */

#include "signal_sigaction.h"

int main(int argc, char *argv[])
{
    struct sigaction act = {0};
    act.sa_flags = SA_SIGINFO;
    act.sa_sigaction = sigusr1_handler;
    sigaction(SIGUSR1, &act, NULL);

    while (1) {
        // wait for SIGUSR1 signal
        // it can be sent with the command:
        //     kill -SIGUSR1 pid
        // where "pid" is the PID of this program
    }

    return EXIT_FAILURE;
}

void sigusr1_handler(int sig, siginfo_t *info, void *ucontext)
{
    printf("SIGUSR1 recieved from PID %d.\n", info->si_pid);
    exit(EXIT_SUCCESS);
}
