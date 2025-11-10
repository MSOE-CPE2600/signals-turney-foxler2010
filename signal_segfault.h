/*
 * Filename: signal_segfault.h
 * Description: Header file for signal_segfault.c
 * Author: Drew Malone <malonea@msoe.edu>
 * Created: 11/10/25
 * Compile with: make signal_segfault
 */

#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <signal.h>

void sigsegv_handler(int signum);
