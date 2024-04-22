#include "main.h"

/**
 * get_command_path - find the full path of a command
 * @command: command to search for
 *
 * Return: full path of the command if found, NULL otherwise
 */
char *get_command_path(const char *command)
{
	char *path = getenv("PATH"); /* Get the PATH environment variable */
	char *path_copy = strdup(path); /* Duplicate the PATH string */
	char *token, *full_path;

	if (!path_copy)
	{
		perror("strdup");
		return (NULL);
	}

	/* Loop through each directory in PATH */
	token = strtok(path_copy, ":");
	while (token)
	{
		/* Construct full path */
		full_path = malloc(strlen(token) + strlen(command) + 2);
		if (!full_path)
		{
			perror("memory allocation fail");
			free(path_copy);
			return (NULL);
		}
		sprintf(full_path, "%s/%s", token, command);

		/* Check if file exists and is executable */
		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}

		free(full_path);
		token = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL); /* Command not found */
}
