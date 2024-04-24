#include "main.h"

/**
 * exit_shell - function that free memory and exit
 * @buffer: pointer to the buffer to free memory
 * @array_tokens: pointer to array_tokens to free memory
*/
void exit_shell(char *buffer, char **array_tokens)
{
	free(buffer);
	free_tokens(array_tokens);
	exit(EXIT_SUCCESS);
}

/**
 * print_env - function that print env
 * @buffer: pointer to the buffer to free memory
 * @array_tokens: pointer to array_tokens to free memory
*/
void print_env(void)
{
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}
