#include "main.h"

/**
 * _get_token - function that splits a string and returns an array of each
 * word of the string.
 * @buffer: string to split
 * Return: an array of each word
*/

char **_get_token(char *buffer)
{
	int max_tokens = 15;
	char *token;
	char **array_tokens = NULL;
	int argCount = 0;

	array_tokens = malloc(max_tokens * sizeof(char *));

	if (array_tokens == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}

	token = strtok(buffer, " \t\n");
	while (token != NULL && argCount < max_tokens - 1)
	{
		array_tokens[argCount] = strdup(token);
		if (array_tokens[argCount] == NULL)
		{
			perror("Memory allocation failed");
			exit(EXIT_FAILURE);
		}

		argCount++;

		token = strtok(NULL, " \t\n"); /* get the next token */
	}
	array_tokens[argCount] = NULL;

	return (array_tokens);
}
