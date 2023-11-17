#ifndef MAINSHELL_H
#define MAINSHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
void prompt(void);
void printer(const char *text);
void reader(char *command, size_t length);
void executer(const char *command);
void exec_arg(const char *command);
void exec_path(const char *command);
void my_exit(void);
#endif
