#ifndef shell_h
#define shell_h

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdbool.h>

#define MAX_STR 150

void print_func(const char *str);
void accept_input(void);
void prompt(void);
void execute_process(void);

#endif
