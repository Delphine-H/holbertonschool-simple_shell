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
		return (strdup(array_tokens[0]));
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
			printf("No such file or directory\n");
		}
	}

	return (NULL);
}
