#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

int _printlineTyped(void);
void exec_command(char **tokens);
char *get_the_location(char *command);
char **process_command(char *lineptr);
int exit_shell(char *command);
void printenv(char **environ);

#endif
