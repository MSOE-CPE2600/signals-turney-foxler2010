/*
 * Filename: signal_alarm.h
 * Description: Header file for signal_alarm.c
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

void signal_handler(int signum);
