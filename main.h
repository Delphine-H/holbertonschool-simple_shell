#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


char **_get_token(char *buffer);
void free_tokens(char **array_tokens);

#endif

