#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

extern char **environ;

char **_get_token(char *buffer);
void free_tokens(char **array_tokens);
int execute_command(char **array_tokens);
char *get_command_path(const char *command);
char *check_if_full_path(char **array_tokens);
void exit_shell(char *buffer, char **array_tokens);
void print_env(void);

#endif
