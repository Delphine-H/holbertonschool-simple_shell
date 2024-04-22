#include "main.h"

/**
 * check_if_full_path - function that check if command is full path
 * and return full path
 * @array_tokens: command to check
 * Return: full path
*/

char *check_if_full_path(char **array_tokens)
{
	char *command_path;

	if (access(array_tokens[0], X_OK) == 0)
	{
		return (array_tokens[0]);
	}
	else
	{
		command_path = get_command_path(array_tokens[0]);
		if (command_path)
		{
			return (command_path);
		}
		else
		{
			printf("Command not found: %s\n", array_tokens[0]);
			exit(EXIT_FAILURE);
		}
	}

	return (NULL);
}
