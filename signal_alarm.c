/*
 * Filename: signal_alarm.c
 * Description: Program that sets an alarm for 5 seconds after it is called.
 * Author: Drew Malone <malonea@msoe.edu>
 * Created: 11/4/25
 * Compile with: make signal_alarm
 */

#include "signal_alarm.h"

int main(int argc, char *argv[])
{
    struct sigaction act = {0};
    act.sa_handler = &signal_handler;
    sigaction(SIGALRM, &act, NULL);
    alarm(ALARM_DURATION);
    int i = 0;
    while(1) {
        sleep(1);
        i++;
        printf("Waited for %ds...\n", i);
    }
    return EXIT_FAILURE;
}

void signal_handler(int signum)
{
    printf("Alarm signal received!\n");
    exit(EXIT_SUCCESS);
}