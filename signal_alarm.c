/*
 * Filename: signal_alarm.c
 * Description: Program that sets an alarm for 5 seconds after it is called.
 * Author: Drew Malone <malonea@msoe.edu>
 * Created: 11/4/25
 * Compile with: make signal_alarm
 */

#define _POSIX_C_SOURCE 200809L
#define ALARM_DURATION 5

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "signal_alarm.h"

int main(int argc, char *argv[])
{
    struct sigaction *act = calloc(1, sizeof(struct sigaction));
    act->sa_flags = SA_SIGINFO;
    // TODO sa_handler || sa_sigaction = my signal_handler() function
    sigaction(SIGALRM, act, NULL);
    alarm(ALARM_DURATION);
    int i = 0;
    while(1) {
        sleep(1);
        i++;
        printf("Waited for %ds...", i);
    }
    return EXIT_FAILURE;
}

int signal_handler()
{
    printf("Alarm signal received!");
    exit(EXIT_SUCCESS);
}