/*
 * Filename: signal_sigaction.h
 * Description: Header file for signal_sigaction.c
 * Author: Drew Malone <malonea@msoe.edu>
 * Created: 11/10/25
 * Compile with: make signal_sigaction
 */

#define _POSIX_C_SOURCE 200809L

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

void sigusr1_handler(int sig, siginfo_t *info, void *ucontext);
