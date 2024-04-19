#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;


int _printlineTyped(void);
int startShell(void);
char **process_command(char *lineptr);
void exec_command(char **tokens);
int exit_shell(char *command);
void printenv(char **environ);
char *get_the_location(char *command);

#endif
