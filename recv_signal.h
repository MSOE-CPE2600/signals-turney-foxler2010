/*
 * Filename: recv_signal.h
 * Description: Header file for recv_signal.c
 * Author: Drew Malone <malonea@msoe.edu>
 * Created: 11/10/25
 * Compile with: make recv_signal
 */

#define _POSIX_C_SOURCE 200809L

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

void sigusr1_handler(int sig, siginfo_t *info, void *ucontext);
