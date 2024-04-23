#include "main.h"

/**
 * execute_command - execute a command if it exists
 * @command: command to execute
 * @array_tokens: array of command and arguments
 *
 * Return: 1 on success, 0 on failure
 */

int execute_command(char **array_tokens)
{
	pid_t pid;
	int status; /* Variable to store child process status */
	char *command_path;

	command_path = check_if_full_path(array_tokens);

	if (command_path == NULL)
	{
		return (0);
	}
	else
	{
	pid = fork();
	if (pid == 0) /* Child process */
	{
		if (execve(command_path, array_tokens, NULL) == -1)
		{
			exit(EXIT_FAILURE);
		}
		return (1);
	}
	else if (pid < 0)
	{
		perror("Fork failed ");
		exit(EXIT_FAILURE);
	}
	else /* Parent process */
	{
		waitpid(pid, &status, 0); /* Wait for child to finish */
		free(command_path);
		return (1);
	}
	}

	return (0);
}
